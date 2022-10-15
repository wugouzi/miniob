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
// Created by Longda on 2021/4/13.
//

#ifndef __OBSERVER_SQL_EXECUTE_STAGE_H__
#define __OBSERVER_SQL_EXECUTE_STAGE_H__

#include "common/seda/stage.h"
#include "sql/expr/tuple_cell.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple.h"
#include "sql/operator/table_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "rc.h"
#include "storage/common/field.h"
#include "storage/common/field_meta.h"
#include "storage/common/table.h"
#include <cstddef>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class SQLStageEvent;
class SessionEvent;
class SelectStmt;

class ExecuteStage : public common::Stage {
public:
  ~ExecuteStage();
  static Stage *make_stage(const std::string &tag);

protected:
  // common function
  ExecuteStage(const char *tag);
  bool set_properties() override;

  bool initialize() override;
  void cleanup() override;
  void handle_event(common::StageEvent *event) override;
  void callback_event(common::StageEvent *event, common::CallbackContext *context) override;

  void handle_request(common::StageEvent *event);
  RC do_help(SQLStageEvent *session_event);
  RC do_create_table(SQLStageEvent *sql_event);
  RC do_update_table(SQLStageEvent *sql_event);
  RC do_create_index(SQLStageEvent *sql_event);
  RC do_drop_table(SQLStageEvent *sql_event);
  RC do_show_tables(SQLStageEvent *sql_event);
  RC do_desc_table(SQLStageEvent *sql_event);
  RC do_select(SQLStageEvent *sql_event);
  RC do_select2(SQLStageEvent *sql_event);
  RC do_insert(SQLStageEvent *sql_event);
  RC do_delete(SQLStageEvent *sql_event);

protected:
private:
  Stage *default_storage_stage_ = nullptr;
  Stage *mem_storage_stage_ = nullptr;
};


// TODO: check that we only need field name and table name
class TupleSet {
 public:
  TupleSet() = default;
  int table_num();
  TupleSet(const Tuple *t, Table *table);
  TupleSet(const TupleSet *t);
  TupleSet *copy() const;
  void combine(const TupleSet *t2);
  TupleSet *generate_combine(const TupleSet *t2) const;
  void filter_fields(const std::vector<Field> &fields);
  const std::vector<TupleCell> &cells() const;

  const FieldMeta &meta(int idx) const;

 private:
  int table_num_ = 0;
  std::vector<std::pair<Table*, FieldMeta>> metas_;
  std::vector<TupleCell> cells_;
};

class Pretable {
 public:
  Pretable() = default;
  Pretable(Pretable&& t);
  Pretable& operator=(Pretable&& t);
  // ~Pretable() = default;


  RC init(Table *table, FilterStmt *filter);
  RC join(Pretable *pre2, FilterStmt *filter);
  void print(std::stringstream &os, const std::vector<Field> &fields);
  void print_fields(std::stringstream &ss, const std::vector<Field> &fields);
  const FieldMeta *field(const Field &field) const;


  std::vector<TupleSet>::iterator begin() { return tuples_.begin(); }
  std::vector<TupleSet>::iterator end() { return tuples_.end(); }

  std::vector<TupleSet> tuples_;
  std::vector<Table*> tables_;
};

// class TupleSetIterator {
// public:
//   TupleSetIterator(TupleSet *t, int i) : tuple_set_(t), idx_(i) {}

//   TupleSetIterator &operator++() {

//     return *this;
//   }

//   TupleCell *operator*() {
//     TupleCell *cell = new TupleCell();
//     const FieldMeta &meta = *tuple_set_->meta(field_idx_);
//     cell->set_type(meta.type());
//     cell->set_length(meta.len());
//     cell->set_data()
//   }


//  private:
//   int field_idx_ = 0;
//   TupleSet *tuple_set_ = nullptr;
// }

#endif  //__OBSERVER_SQL_EXECUTE_STAGE_H__
