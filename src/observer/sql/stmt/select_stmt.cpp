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
#include "rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include "storage/common/field_meta.h"
#include "storage/common/table.h"
#include <cstddef>
#include <iostream>
#include <limits>
#include <ostream>
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
    field_metas.push_back(Field(table, table_meta.field(i)->copy()));
  }
}

RC check_attr(RelAttr &attr, std::unordered_map<std::string, Table *> &table_map, std::vector<Table *> &tables)
{
  Table *table = nullptr;
  if (attr.relation_name != nullptr) {
    if (table_map.count(attr.relation_name) == 0) {
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    table = table_map[attr.relation_name];
  } else {
    if (tables.size() > 1) {
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    table = tables[0];
    attr.relation_name = const_cast<char *>(table->name());
  }
  const FieldMeta *meta = table->table_meta().field(attr.attribute_name);
  if (meta == nullptr && !attr.print_attr) {
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }
  return RC::SUCCESS;
}

void print_space(int indent)
{
  for (int i = 0; i < indent; i++) {
    std::cout << " ";
  }
}

void print_attr(Selects *selects, int indent)
{
  print_space(indent + 2);
  std::cout << "ATTR: ";
  for (size_t i = 0; i < selects->attr_num; i++) {
    RelAttr &attr = selects->attributes[i];
    std::cout << "[ table: " << (attr.relation_name == nullptr ? "" : attr.relation_name)
              << ", attribute: " << attr.attribute_name
              << ", type: " << attr.type << "], ";
  }
  std::cout << std::endl;
}

void print_relation(Selects *selects, int indent)
{
  print_space(indent + 2);
  std::cout << "RELATION: ";
  for (size_t i = 0; i < selects->relation_num; i++) {
    std::cout << selects->relations[i].relation_name << ", ";
  }
  std::cout << std::endl;
}

void print_select(Selects *selects, int indent);

void print_condition(Condition &cond, int indent)
{
  print_space(indent);
  if (cond.left_is_attr) {
    std::cout << "Attr: " << (cond.left_attr.relation_name == nullptr ? "" : cond.left_attr.relation_name)
              << ", " << cond.left_attr.attribute_name;
  } else {
    Value &val = cond.left_value;
    if (val.type == SELECTS) {
      print_select(val.select, indent);
    } else {
      std::cout << "Value: type " << val.type;
    }
  }
  std::cout << std::endl;
  print_space(indent);
  std::cout << " COMP: " << cond.comp << std::endl;
  print_space(indent);
  if (cond.right_is_attr) {
    std::cout << "Attr: " << (cond.right_attr.relation_name == nullptr ? "" : cond.right_attr.relation_name)
              << ", " << cond.right_attr.attribute_name;
  } else {
    Value &val = cond.right_value;
    if (val.type == SELECTS) {
      print_select(val.select, indent);
    } else {
      std::cout << "Value: type " << val.type;
    }
  }
  std::cout << std::endl;
}

void print_conditions(Selects *selects, int indent)
{
  print_space(indent + 2);
  std::cout << "CONDITIONS: " << std::endl;
  for (size_t i = 0; i < selects->condition_num; i++) {
    print_condition(selects->conditions[i], indent + 4);
  }
}

void print_select(Selects *selects, int indent)
{
  std::cout << "SELECTS: " << std::endl;
  print_attr(selects, indent);
  print_relation(selects, indent);
  print_conditions(selects, indent);
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
      order_by_field.field_meta = field_meta->copy();
      order_by_fields.push_back(order_by_field);
    } else {
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
  }
  return RC::SUCCESS;
}
RC SelectStmt::create(Db *db, Selects *select_sql, Stmt *&stmt)
{
  std::unordered_map<std::string, std::unordered_map<std::string, TupleCell>> tmp;
  return create(db, select_sql, stmt, tmp);
}

// every field's fieldmeta is a copy since we will change offset later
RC SelectStmt::create(Db *db, Selects *select_sql, Stmt *&stmt,
                      std::unordered_map<std::string, std::unordered_map<std::string, TupleCell>> &context)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  print_select(select_sql, 0);

  /*
  if (select_sql->aggregate_num > 0 && select_sql->attr_num != select_sql->aggregate_num) {
    LOG_WARN("different number of aggregates");
    return RC::INVALID_ARGUMENT;
  }
  */

  // treat having condition attr as extra attr
  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  // alias -> table name
  std::unordered_map<std::string, std::string> table_alias_map;
  // alias -> attr name
  std::unordered_map<std::string, std::string> attr_alias_map;

  // we can use table_alias_map to find the name of table;

  for (size_t i = 0; i < select_sql->relation_num; i++) {
    const char *table_name = select_sql->relations[i].relation_name;
    const char *table_alias = select_sql->relations[i].alias;
    if (table_map.count(table_name) > 0) {
      continue;
    }
    if (table_alias != nullptr) {
      if (table_alias_map.count(table_alias) > 0) {
        LOG_ERROR("conflict alias");
        return RC::INVALID_ARGUMENT;
      }
      table_alias_map[table_alias] = table_name;
    }

    if (table_map.count(table_name) > 0) {
      continue;
    }
    // table_alias_map[table_name] = table_name;
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

  for (size_t i = 0; i < select_sql->relation_num; i++) {
    const char *alias = select_sql->relations[i].alias;
    if (alias != nullptr) {
      table_map[alias] = table_map[select_sql->relations[i].relation_name];
    }
  }
  
  // collect query fields in `select` statement
  std::vector<Field> query_fields;
  std::vector<RelAttr> attrs;
  for (int i = select_sql->attr_num - 1; i >= 0; i--) {
    attrs.push_back(select_sql->attributes[i]);
  }
  for (size_t i = 0; i < select_sql->having_num; i++) {
    Condition &cond = select_sql->having_conditions[i];
    if (cond.left_is_attr) {
      attrs.push_back(cond.left_attr);
    }
    if (cond.right_is_attr) {
      attrs.push_back(cond.right_attr);
    }
  }
  int query_num = 0;
  for (int i = 0; i < attrs.size(); i++) {
    // const RelAttr &relation_attr = select_sql->attributes[i];
    const RelAttr &relation_attr = attrs[i];
    if (relation_attr.type == AggreType::A_FAILURE) {
      return RC::SCHEMA_FIELD_NAME_ILLEGAL;
    }

    if (common::is_blank(relation_attr.relation_name) && 0 == strcmp(relation_attr.attribute_name, "*")) {
      if (relation_attr.alias != nullptr) {
        return RC::INVALID_ARGUMENT;
      }
      if (relation_attr.type == AggreType::A_NO) {
        for (Table *table : tables) {
          wildcard_fields(table, query_fields);
        }
      }
      else {
        if (relation_attr.type != AggreType::A_COUNT) {
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
        FieldMeta *meta = new FieldMeta;
        meta->init(relation_attr.attribute_name, INTS, 0, 5, true, false);
        Field field(tables[0], meta);
        // field.set_aggr_str(relation_attr.attribute_name);
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
        if (relation_attr.alias != nullptr) {
          return RC::INVALID_ARGUMENT;
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
            meta->init(relation_attr.attribute_name, CHARS, 0, sizeof(relation_attr.attribute_name) + 2, true, false);
            Field field(table, meta);
            field.set_print_table();
            field.set_aggr(relation_attr.type);
            field.set_alias(relation_attr.alias);
            // field.set_aggr_str(relation_attr.attribute_name);
            query_fields.push_back(field);
          } else {
            Field field(table, field_meta->copy());
            if (relation_attr.type != A_NO) {
              field.set_aggr(relation_attr.type);
              field.set_print_table();
              if (relation_attr.type == A_AVG) {
                field.meta()->set_type(FLOATS);
              }
            }
            field.set_alias(relation_attr.alias);
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
        meta->init(relation_attr.attribute_name, CHARS, 0, sizeof(relation_attr.attribute_name) + 2, true, false);
        Field field(table, meta);
        // field.set_table(tables[0]);
        field.set_aggr(relation_attr.type);
        field.set_alias(relation_attr.alias);
        // field.set_aggr_str(relation_attr.attribute_name);
        query_fields.push_back(field);
      } else {
        Field field(table, field_meta->copy());
        if (relation_attr.type != A_NO) {
          field.set_aggr(relation_attr.type);
          if (relation_attr.type == A_AVG) {
            field.meta()->set_type(FLOATS);
          }
        }
        field.set_alias(relation_attr.alias);
        query_fields.push_back(field);
      }
    }
    if (i < select_sql->attr_num) {
      query_num = query_fields.size();
    }
  }

  // check group by attrs
  std::vector<Field> groupby_fields;
  std::unordered_map<std::string, std::unordered_map<std::string, bool>> mp;
  for (int i = select_sql->groupby_num - 1; i >= 0; i--) {
    RelAttr &attr = select_sql->groupby_attrs[i];
    Table *table = nullptr;
    if (attr.relation_name == nullptr) {
      if (tables.size() > 1) {
        LOG_ERROR("no table id in multi tables");
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      table = tables[0];
      attr.relation_name = const_cast<char *>(table->name());
    } else {
      auto iter = table_map.find(attr.relation_name);
      if (iter == table_map.end()) {
        LOG_ERROR("no such table %s", attr.relation_name);
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      table = iter->second;
    }
    const FieldMeta *field_meta = table->table_meta().field(attr.attribute_name);
    if (field_meta == nullptr) {
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    mp[attr.relation_name][attr.attribute_name] = true;
    groupby_fields.push_back(Field(table, field_meta->copy()));
  }

  // check non-permit attr
  if (select_sql->aggregate_num > 0) {
    for (auto &field : query_fields) {
      if (field.aggr_type() == A_NO && !mp[field.table_name()][field.metac()->name()]) {
        return RC::SCHEMA_FIELD_NOT_EXIST;
      }
    }
  }

  // check having conditions
  // and extra aggregation need to be computed also
  // std::vector<Field> having_fields;
  for (size_t i = 0; i < select_sql->having_num; i++) {
    Condition &cond = select_sql->having_conditions[i];
    RC rc = RC::SUCCESS;
    if (cond.left_is_attr) {
      rc = check_attr(cond.left_attr, table_map, tables);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    if (cond.right_is_attr) {
      rc = check_attr(cond.right_attr, table_map, tables);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, default_table, &table_map,
                             select_sql->conditions, select_sql->condition_num, filter_stmt,
                             context);

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

  // set table alias
  // one extra case, two table with different alias
  for (auto &iter : table_alias_map) {
    Table *table = table_map[iter.second];
    table->set_alias(iter.first);
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->tables_.swap(tables);
  select_stmt->groupby_fields_.swap(groupby_fields);
  select_stmt->having_conditions_ = select_sql->having_conditions;
  select_stmt->having_condition_num_ = select_sql->having_num;
  select_stmt->query_num_ = query_num;
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->aggregate_num_ = select_sql->aggregate_num;
  select_stmt->order_by_fields_ = order_by_fields;
  stmt = select_stmt;
  return RC::SUCCESS;
}
