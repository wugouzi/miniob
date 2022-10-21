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

#pragma once

#include "rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/stmt.h"
#include "storage/common/field_meta.h"
#include <vector>

class FieldMeta;
class FilterStmt;
class Db;
class Table;


class UpdateStmt : public Stmt
{
public:

  UpdateStmt() = default;

  StmtType type() const override { return StmtType::UPDATE; }

public:
  static RC create(Db *db, Updates &update_sql, Stmt *&stmt);

public:
  Table *table() const {return table_;}
  int attr_num() const { return values_.size(); }
  Value *value(int i) { return values_[i]; }
  std::vector<Value *> &values() { return values_; }
  std::vector<const FieldMeta *> &metas() { return attr_metas_; }
  const FieldMeta *attr_meta(int i) const { return attr_metas_[i]; }
  const Condition *conditions() const { return conditions_; }
  int condition_num() const { return condition_num_; }

private:
  Table *table_ = nullptr;
  std::vector<Value *> values_;
  std::vector<const FieldMeta *> attr_metas_;
  Condition *conditions_;
  int condition_num_;
  // Value *value_ = nullptr;
  // const FieldMeta *attr_meta_ = nullptr;
  // FilterStmt *filter_stmt_ = nullptr;
};

