/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/expr/expression.h"
#include "sql/executor/execute_stage.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"
#include "storage/common/db.h"
#include "storage/common/field_meta.h"
#include "storage/common/table.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		      Condition *conditions, int condition_num,
		      FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		       const RelAttr &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name)) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(std::string(attr.relation_name));
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name);
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name);
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name);
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
                                  Condition &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;
  
  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  // str check
  if (comp == STR_LIKE || comp == STR_NOT_LIKE) {
    if (!condition.left_is_attr || condition.right_is_attr) {
      LOG_INFO("left is not an attribute");
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr 1");
      return rc;
    }
    if (!(field->type() == AttrType::CHARS && condition.right_value.type == AttrType::CHARS)) {
      LOG_INFO("not all chars");
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

  // type checks
  if (condition.left_is_attr && !condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    // only check dates, and don't check null
    if (!Stmt::check_type(condition.right_value.type, field->type())) {
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  } else if (!condition.left_is_attr && condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    if (!Stmt::check_type(condition.left_value.type, field->type())) {
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

  Expression *left = nullptr;
  Expression *right = nullptr;
  if (condition.left_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    left = new FieldExpr(table, field);
  } else {
    if (condition.left_value.type == DATES && *(int *)condition.left_value.data == -1) {
      return RC::INVALID_ARGUMENT;
    }
    if (condition.left_value.type == SELECTS) {
      Pretable *res = ExecuteStage::Selects_to_pretable(db, &condition.left_value);
      if (res == nullptr) {
        return RC::INTERNAL;
      }
      if (!res->valid_operation(comp)) {
        LOG_INFO("select have 0 or more than 1 values");
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      left = new ValueExpr(res);
    } else if (condition.left_value.type == VALUELIST) {
      Pretable *res = new Pretable(condition.left_value.value_list);
      left = new ValueExpr(res);
    } else {
      left = new ValueExpr(condition.left_value);
    }
  }

  if (condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      delete left;
      return rc;
    }
    right = new FieldExpr(table, field);
  } else {
    if (condition.right_value.type == DATES && *(int *)condition.right_value.data == -1) {
      return RC::INVALID_ARGUMENT;
    }
    if (condition.right_value.type == SELECTS) {
      Pretable *res = ExecuteStage::Selects_to_pretable(db, &condition.right_value);
      if (res == nullptr) {
        return RC::INTERNAL;
      }
      if (!res->valid_operation(comp)) {
        LOG_INFO("select have 0 or more than 1 values");
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      right = new ValueExpr(res);
    } else if (condition.right_value.type == VALUELIST) {
      Pretable *res = new Pretable(condition.right_value.value_list);
      right = new ValueExpr(res);
    } else {
      right = new ValueExpr(condition.right_value);
    }
  }

  filter_unit = new FilterUnit;
  filter_unit->set_comp(comp);
  filter_unit->set_left(left);
  filter_unit->set_right(right);

  // 检查两个类型是否能够比较
  return rc;
}
