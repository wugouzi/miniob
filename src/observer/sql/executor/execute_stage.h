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

#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/seda/stage.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple.h"
#include "storage/common/table.h"
#include "storage/common/field.h"
#include <string>
#include <utility>
#include <vector>
#include "rc.h"

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
  RC do_create_index(SQLStageEvent *sql_event);
  RC do_show_tables(SQLStageEvent *sql_event);
  RC do_desc_table(SQLStageEvent *sql_event);
  RC do_select(SQLStageEvent *sql_event);
  RC do_insert(SQLStageEvent *sql_event);
  RC do_delete(SQLStageEvent *sql_event);
  RC do_begin(SQLStageEvent *sql_event);
  RC do_commit(SQLStageEvent *sql_event);
  RC do_clog_sync(SQLStageEvent *sql_event);
  RC do_drop_table(SQLStageEvent *sql_event);
  RC do_update_table(SQLStageEvent *sql_event);
  RC value_check(const int &value_num, const Value *values) const;
  void print_fields(std::stringstream &ss, const std::vector<Field> &fields, bool multi);

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

  void push(const std::pair<Table*, FieldMeta> &p, const TupleCell &cell);

  const TupleCell &get_cell(int idx);
  const std::pair<Table *, FieldMeta> &get_meta(int idx);
  int index(const Field &field) const;
  void reverse();

 private:
  int table_num_ = 0;
  std::vector<std::pair<Table*, FieldMeta>> metas_;
  std::vector<TupleCell> cells_;
};


// TODO: save the aggregates info
// TODO: let Pretable to save the meta info
class Pretable {
 public:
  Pretable() = default;
  Pretable(Pretable&& t);
  Pretable& operator=(Pretable&& t);
  // ~Pretable() = default;


  RC init(Table *table, FilterStmt *filter);
  RC join(Pretable *pre2, FilterStmt *filter);
  void print(std::stringstream &os);
  void filter_fields(const std::vector<Field> &fields);
  RC aggregate(const std::vector<Field> fields);
  RC aggregate_max(int idx, TupleCell *res);
  RC aggregate_min(int idx, TupleCell *res);
  RC aggregate_avg(int idx, TupleCell *res);
  RC aggregate_count(int idx, TupleCell *res);
  const FieldMeta *field(const Field &field) const;


  std::vector<TupleSet>::iterator begin() { return tuples_.begin(); }
  std::vector<TupleSet>::iterator end() { return tuples_.end(); }

  std::vector<TupleSet> tuples_;
  std::vector<Table*> tables_;
};


#endif  //__OBSERVER_SQL_EXECUTE_STAGE_H__
