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
// Created by Wangyunlai on 2022/07/05.
//

#pragma once

#include <string>
#include <sstream>
#include "util/util.h"
#include <defs.h>
#include "storage/common/table.h"
#include "storage/common/field_meta.h"
#include "sql/expr/tuple_cell.h"

class Field
{
public:
  Field() = default;
  Field(const Table *table, const FieldMeta *field) : table_(table), field_(field)
  {}

  const Table *table() const { return table_; }
  FieldMeta *meta() { return const_cast<FieldMeta *>(field_); }
  const FieldMeta *metac() const { return field_; }
  FieldMeta meta_copy() const { return *field_; }

  void set_attr_type(AttrType typ) { this->meta()->set_type(typ); }

  AttrType attr_type() const
  {
    return field_->type();
  }

  const char* table_name() const { return table_ ? table_->name() : ""; }
  const char *field_name() const { return field_->name(); }

  void set_table(const Table *table)
  {
    this->table_ = table;
  }
  void set_field(const FieldMeta *field)
  {
    this->field_ = field;
  }

  bool has_table() const { return table_ != nullptr; }

  MapFuncType map_func_type_ = MapFuncType::M_ID;
  char* func_args = nullptr;
  // 不包括第一个参数的argc
  int func_argc = 0;

  // 临时hack，只会有至多一个参数
  std::vector<char*> get_func_args() {
    std::vector<char *> res;
    if(func_argc){
      res.push_back(func_args);
    }
    return res;
  }

  RC evaluate_as_const_expression(TupleCell &cell) const {
    if (this->map_func_type_ != MapFuncType::M_ID) {
      auto arg1 = this->field_name();
      if (this->map_func_type_ == MapFuncType::M_LENGTH) {
        if (arg1 && arg1[0] == '\'') {
          cell.set_data(arg1);
          cell.set_length(strlen(arg1) + 1);
          cell.set_type(AttrType::CHARS);
          auto t = TempMapFuncObject();
          t.argc = this->func_argc;
          t.arg = this->func_args;
          t.type = this->map_func_type_;
          cell.apply_func(t);
          return RC::SUCCESS;
        }
      } else if (this->map_func_type_ == MapFuncType::M_ROUND) {
        if (arg1 && '0' <= arg1[0] && arg1[0] <= '9') {
          // auto f = std::stod(arg1);
          auto data = strdup(arg1);
          // memcpy(data, &f, sizeof(float));
          cell.set_data(data);
          cell.set_length(strlen(arg1) + 1);
          cell.set_type(AttrType::CHARS);
          auto t = TempMapFuncObject();
          t.argc = this->func_argc;
          t.arg = this->func_args;
          t.type = this->map_func_type_;
          // custom_round(argc)
          cell.apply_func(t);
          return RC::SUCCESS;
        }
      } else if (this->map_func_type_ == MapFuncType::M_DATE_FORMAT) {
        if (arg1 && arg1[0] == '\'') {
          auto data = strdup(arg1);
          cell.set_data(data);
          cell.set_length(strlen(arg1) + 1);
          cell.set_type(AttrType::CHARS);
          auto t = TempMapFuncObject();
          t.argc = this->func_argc;
          t.arg = this->func_args;
          t.type = this->map_func_type_;
          cell.apply_func(t);
          return RC::SUCCESS;
        }
      }
    }
    return RC::INTERNAL;
  }

  bool fix_aggr_map(){
    if(aggr_type_ == AggreType::A_LENGTH){
      map_func_type_ = MapFuncType::M_LENGTH;
    }else if(aggr_type_ == AggreType::A_ROUND){
      map_func_type_ = MapFuncType::M_ROUND;
    }else if(aggr_type_ == AggreType::A_DATE_FORMAT){
      map_func_type_ = MapFuncType::M_DATE_FORMAT;
    }else{
      return false;
    }
    aggr_type_ = AggreType::A_NO;
    return true;
  }

  void set_aggr(AggreType type) {
    aggr_type_ = type;
    // const_cast<FieldMeta *>(field_)->set_aggr_type(type);
  }
  const std::string &aggr_str() const { return aggr_str_; }
  void set_aggr_str(std::string cnt) { aggr_str_ = cnt; }
  AggreType aggr_type() const { return aggr_type_; }
  void set_table(Table *table) { table_ = table; }
  bool has_field() const { return field_ != nullptr; }
  void set_print_table() { print_table_ = true; }
  bool should_print_table() const { return print_table_; }
  void set_alias(const char *alias) {
    if (alias != nullptr) {
      alias_ = alias;
    }
  }
  const std::string &alias() const { return alias_; }
  bool has_alias() const { return alias_.size() > 0; }
private:
  std::string alias_;
  const Table *table_ = nullptr;
  const FieldMeta *field_ = nullptr;
  AggreType aggr_type_ = A_NO;
  std::string aggr_str_;
  // for count(1), avg(1.111)
  bool print_table_ = false;
};
