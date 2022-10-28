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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include "storage/common/field.h"
#include "storage/common/field_meta.h"
#include "storage/common/table.h"
#include "storage/common/table_meta.h"
#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(Field(table, table_meta.field(i)));
  }
}

static RC extract_from_order_by_clause(
    std::vector<Table*> &tables,
    std::unordered_map<std::string, Table*>& table_map,
    OrderByRelAttr* order_by_rel_attr,
    int order_by_num,
    std::vector<OrderByField>& order_by_fields) {
  for (int i = order_by_num - 1; i >= 0; i--) {
    auto& order_by_attr = order_by_rel_attr[i];
    // use first table by default
    Table* table = nullptr;
    if(!common::is_blank(order_by_attr.attr.relation_name)){
      table = table_map[order_by_attr.attr.relation_name];
    } else if(tables.size() > 0){
      table = tables[0];
    }
    if(table){
      const FieldMeta* field_meta = table->table_meta().field(order_by_attr.attr.attribute_name);
      if(!field_meta){
        return RC::SCHEMA_FIELD_MISSING;
      }
      OrderByField order_by_field;
      order_by_field.is_desc = order_by_attr.is_desc;
      order_by_field.table = table;
      order_by_field.field_meta = field_meta;
      order_by_fields.push_back(order_by_field);
    } else {
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
  }
  return RC::SUCCESS;
}
RC SelectStmt::create(Db *db, Selects *select_sql, Stmt *&stmt)
{
  std::unordered_set<Table *> tp;
  return create(db, select_sql, stmt, tp);
}

RC check_field_and_name(std::unordered_map<std::string, Table *>table_map, Table *default_table,
                          const char *relation_name, const char *attribute_name)
{
  Table *table = nullptr;
  if (relation_name == nullptr) {
    table = default_table;
  } else {
    if (table_map.count(relation_name) == 0) {
      LOG_ERROR("having: no table %s", relation_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
    table = table_map[relation_name];
  }
  const FieldMeta *meta = table->table_meta().field(attribute_name);
  if (meta == nullptr) {
    LOG_ERROR("having: no attr %s", attribute_name);
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  return RC::SUCCESS;
}

RC SelectStmt::create(Db *db, Selects *select_sql, Stmt *&stmt, std::unordered_set<Table *> &parent_tables)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // // TODO: check
  // if (select_sql->aggregate_num > 0 && select_sql->attr_num != select_sql->aggregate_num) {
  //   LOG_WARN("different number of aggregates");
  //   return RC::INVALID_ARGUMENT;
  // }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  for (size_t i = 0; i < select_sql->relation_num; i++) {
    const char *table_name = select_sql->relations[i];
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table*>(table_name, table));
  }
  
  // collect query fields in `select` statement
  std::vector<Field> query_fields;
  for (int i = select_sql->attr_num - 1; i >= 0; i--) {
    const RelAttr &relation_attr = select_sql->attributes[i];

    if (relation_attr.type == AggreType::A_FAILURE) {
      return RC::SCHEMA_FIELD_NAME_ILLEGAL;
    }

    if (common::is_blank(relation_attr.relation_name) && 0 == strcmp(relation_attr.attribute_name, "*")) {
      if (relation_attr.type == AggreType::A_NO) {
        for (Table *table : tables) {
          wildcard_fields(table, query_fields);
        }
      }
      else {
        FieldMeta *field_meta = new FieldMeta;
        field_meta->init(relation_attr.attribute_name, CHARS, 0, 5, true, false);

        // field.set_aggr_str(relation_attr.attribute_name);
        Field field(tables[0], field_meta);
        field.set_aggr(relation_attr.type);
        query_fields.push_back(field);
      }
    } else if (!common::is_blank(relation_attr.relation_name)) { // TODO
      const char *table_name = relation_attr.relation_name;
      const char *field_name = relation_attr.attribute_name;
      if (0 == strcmp(field_name, "*") && relation_attr.type != AggreType::A_NO) {
        return RC::SCHEMA_FIELD_NAME_ILLEGAL;
      }

      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        for (Table *table : tables) {
          wildcard_fields(table, query_fields);
        }
      } else {
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          wildcard_fields(table, query_fields);
        } else {
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta && !relation_attr.print_attr) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

          if (relation_attr.print_attr) {
            FieldMeta *meta = new FieldMeta;
            meta->init(relation_attr.attribute_name, CHARS, 0, strlen(relation_attr.attribute_name) + 2, true, false);
            Field field;
            field.set_print_table();
            field.set_table(table);
            field.set_aggr(relation_attr.type);
            field.set_aggr_str(relation_attr.attribute_name);
            query_fields.push_back(field);
          } else {
            Field field(table, field_meta);
            if (relation_attr.type != A_NO) {
              field.set_aggr(relation_attr.type);
              field.set_print_table();
            }
            query_fields.push_back(field);
          }
        }
      }
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
      if (nullptr == field_meta && !relation_attr.print_attr) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      if (relation_attr.print_attr) {
        FieldMeta *meta = new FieldMeta;
        meta->init(relation_attr.attribute_name, CHARS, 0, strlen(relation_attr.attribute_name) + 2, true, false);
        Field field(table, meta);
        field.set_aggr(relation_attr.type);
        // field.set_aggr_str(relation_attr.attribute_name);
        query_fields.push_back(field);
      } else {
        Field field(table, field_meta);
        if (relation_attr.type != A_NO) {
          field.set_aggr(relation_attr.type);
        }
        query_fields.push_back(field);
      }
    }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  for (Table *table : parent_tables) {
    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table*>(table->name(), table));
  }

  // create filter statement in `where` statement
  // and check conditions
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, default_table, &table_map,
           select_sql->conditions, select_sql->condition_num, filter_stmt);


  // check groupby fields and cache fields
  std::vector<Field> groupby_fields;
  std::unordered_map<std::string, std::unordered_map<std::string, bool>> groupby_map;
  for (int i = select_sql->groupby_num - 1; i >= 0; i--) {
    RelAttr &attr = select_sql->groupby_attrs[i];
    Table *table = nullptr;
    if (attr.relation_name == nullptr) {
      table = default_table;
    } else {
      if (table_map.count(attr.relation_name) == 0) {
        LOG_ERROR("having: no table %s", attr.relation_name);
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      table = table_map[attr.relation_name];
    }
    const FieldMeta *meta = table->table_meta().field(attr.attribute_name);
    if (meta == nullptr) {
      LOG_ERROR("having: no attr %s", attr.attribute_name);
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    Field field(table, meta);
    field.set_aggr(attr.type);
    groupby_fields.push_back(field);
    groupby_map[table->name()][meta->name()] = true;
  }

  // check aggregate attrs, normal attr should be in group by
  if (select_sql->aggregate_num > 0) {
    for (size_t i = 0; i < select_sql->attr_num; i++) {
      RelAttr &attr = select_sql->attributes[i];
      if (attr.type == A_NO && !groupby_map[attr.relation_name][attr.attribute_name]) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }

  // check having conditions
  for (int i = 0; i < select_sql->having_num; i++) {
    Condition &condition = select_sql->having_conditions[i];
    if (condition.left_is_attr) {
      RelAttr &attr = condition.left_attr;
      if (attr.type == A_FAILURE) {
        return RC::GENERIC_ERROR;
      }
      rc = check_field_and_name(table_map, default_table, attr.relation_name, attr.attribute_name);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    if (condition.right_is_attr) {
      RelAttr &attr = condition.right_attr;
      if (attr.type == A_FAILURE) {
        return RC::GENERIC_ERROR;
      }
      rc = check_field_and_name(table_map, default_table, attr.relation_name, attr.attribute_name);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
  }
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  std::vector<OrderByField> order_by_fields;
  rc = extract_from_order_by_clause(tables, table_map, select_sql->order_fields, select_sql->order_by_num, order_by_fields);

  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot handle order by clause");
    return rc;
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->tables_.swap(tables);
  select_stmt->groupby_fields_.swap(groupby_fields);
  select_stmt->having_conditions_ = select_sql->having_conditions;
  select_stmt->having_condition_num_ = select_sql->having_num;
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->aggregate_num_ = select_sql->aggregate_num;
  select_stmt->order_by_fields_ = order_by_fields;
  stmt = select_stmt;
  return RC::SUCCESS;
}
