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
// Created by Meiyi & Longda on 2021/4/13.
//

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/lang/defer.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/expr/tuple_cell.h"
#include "sql/operator/table_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "storage/index/index.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/record/record.h"
#include "storage/trx/trx.h"
#include "storage/clog/clog.h"

using namespace common;

//RC create_selection_executor(
//   Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag)
{}

//! Destructor
ExecuteStage::~ExecuteStage()
{}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag)
{
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties()
{
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize()
{
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup()
{
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::handle_request(common::StageEvent *event)
{
  SQLStageEvent *sql_event = static_cast<SQLStageEvent *>(event);
  SessionEvent *session_event = sql_event->session_event();
  Stmt *stmt = sql_event->stmt();
  Session *session = session_event->session();
  Query *sql = sql_event->query();

  if (stmt != nullptr) {
    switch (stmt->type()) {
    case StmtType::SELECT: {
      do_select2(sql_event);
    } break;
    case StmtType::INSERT: {
      do_insert(sql_event);
    } break;
    case StmtType::UPDATE: {
      do_update(sql_event);
    } break;
    case StmtType::DELETE: {
      do_delete(sql_event);
    } break;
    default: {
      LOG_WARN("should not happen. please implenment");
    } break;
    }
  } else {
    switch (sql->flag) {
    case SCF_HELP: {
      do_help(sql_event);
    } break;
    case SCF_CREATE_TABLE: {
      do_create_table(sql_event);
    } break;
    case SCF_CREATE_INDEX: {
      do_create_index(sql_event);
    } break;
    case SCF_SHOW_INDEX: {
      do_show_index(sql_event);
    } break;
    case SCF_SHOW_TABLES: {
      do_show_tables(sql_event);
    } break;
    case SCF_DESC_TABLE: {
      do_desc_table(sql_event);
    } break;
    case SCF_UPDATE: {
      do_update_table(sql_event);
    } break;
    case SCF_DROP_TABLE: {
      do_drop_table(sql_event);
    } break;
    case SCF_DROP_INDEX:
    case SCF_LOAD_DATA: {
      default_storage_stage_->handle_event(event);
    } break;
    case SCF_SYNC: {
      /*
      RC rc = DefaultHandler::get_default().sync();
      session_event->set_response(strrc(rc));
      */
    } break;
    case SCF_BEGIN: {
      do_begin(sql_event);
      /*
      session_event->set_response("SUCCESS\n");
      */
    } break;
    case SCF_COMMIT: {
      do_commit(sql_event);
      /*
      Trx *trx = session->current_trx();
      RC rc = trx->commit();
      session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      */
    } break;
    case SCF_CLOG_SYNC: {
      do_clog_sync(sql_event);
    }
    case SCF_ROLLBACK: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->rollback();
      session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
    } break;
    case SCF_EXIT: {
      // do nothing
      const char *response = "Unsupported\n";
      session_event->set_response(response);
    } break;
    default: {
      LOG_ERROR("Unsupported command=%d\n", sql->flag);
    }
    }
  }
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right)
{
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}

void print_tuple_header(std::ostream &os, const ProjectOperator &oper)
{
  const int cell_num = oper.tuple_cell_num();
  const TupleCellSpec *cell_spec = nullptr;
  for (int i = 0; i < cell_num; i++) {
    oper.tuple_cell_spec_at(i, cell_spec);
    if (i != 0) {
      os << " | ";
    }

    if (cell_spec->alias()) {
      os << cell_spec->alias();
    }
  }

  if (cell_num > 0) {
    os << '\n';
  }
}
void tuple_to_string(std::ostream &os, const Tuple &tuple)
{
  TupleCell cell;
  RC rc = RC::SUCCESS;
  bool first_field = true;
  for (int i = 0; i < tuple.cell_num(); i++) {
    rc = tuple.cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
      break;
    }

    if (!first_field) {
      os << " | ";
    } else {
      first_field = false;
    }
    cell.to_string(os);
  }
}

IndexScanOperator *try_to_create_index_scan_operator(FilterStmt *filter_stmt)
{
  const std::vector<FilterUnit *> &filter_units = filter_stmt->filter_units();
  if (filter_units.empty() ) {
    return nullptr;
  }

  // 在所有过滤条件中，找到字段与值做比较的条件，然后判断字段是否可以使用索引
  // 如果是多列索引，这里的处理需要更复杂。
  // 这里的查找规则是比较简单的，就是尽量找到使用相等比较的索引
  // 如果没有就找范围比较的，但是直接排除不等比较的索引查询. (你知道为什么?)
  const FilterUnit *better_filter = nullptr;
  for (const FilterUnit * filter_unit : filter_units) {
    if (filter_unit->comp() == NOT_EQUAL) {
      continue;
    }

    Expression *left = filter_unit->left();
    Expression *right = filter_unit->right();
    if (left->type() == ExprType::FIELD && right->type() == ExprType::VALUE) {
    } else if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
    }
    FieldExpr &left_field_expr = *(FieldExpr *)left;
    const Field &field = left_field_expr.field();
    const Table *table = field.table();
    Index *index = table->find_index_by_field(field.field_name());
    if (index != nullptr) {
      if (better_filter == nullptr) {
        better_filter = filter_unit;
      } else if (filter_unit->comp() == EQUAL_TO) {
        better_filter = filter_unit;
    	break;
      }
    }
  }

  if (better_filter == nullptr) {
    return nullptr;
  }

  Expression *left = better_filter->left();
  Expression *right = better_filter->right();
  CompOp comp = better_filter->comp();
  if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
    std::swap(left, right);
    switch (comp) {
    case EQUAL_TO:    { comp = EQUAL_TO; }    break;
    case LESS_EQUAL:  { comp = GREAT_THAN; }  break;
    case NOT_EQUAL:   { comp = NOT_EQUAL; }   break;
    case LESS_THAN:   { comp = GREAT_EQUAL; } break;
    case GREAT_EQUAL: { comp = LESS_THAN; }   break;
    case GREAT_THAN:  { comp = LESS_EQUAL; }  break;
    default: {
    	LOG_WARN("should not happen");
    }
    }
  }


  FieldExpr &left_field_expr = *(FieldExpr *)left;
  const Field &field = left_field_expr.field();
  const Table *table = field.table();
  Index *index = table->find_index_by_field(field.field_name());
  assert(index != nullptr);

  ValueExpr &right_value_expr = *(ValueExpr *)right;
  TupleCell value;
  right_value_expr.get_tuple_cell(value);

  const TupleCell *left_cell = nullptr;
  const TupleCell *right_cell = nullptr;
  bool left_inclusive = false;
  bool right_inclusive = false;

  switch (comp) {
  case EQUAL_TO: {
    left_cell = &value;
    right_cell = &value;
    left_inclusive = true;
    right_inclusive = true;
  } break;

  case LESS_EQUAL: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = true;
  } break;

  case LESS_THAN: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = false;
  } break;

  case GREAT_EQUAL: {
    left_cell = &value;
    left_inclusive = true;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  case GREAT_THAN: {
    left_cell = &value;
    left_inclusive = false;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  default: {
    LOG_WARN("should not happen. comp=%d", comp);
  } break;
  }

  IndexScanOperator *oper = new IndexScanOperator(table, index,
       left_cell, left_inclusive, right_cell, right_inclusive);

  LOG_INFO("use index for scan: %s in table %s", index->index_meta().name(), table->name());
  return oper;
}

void reorder_fields(std::vector<Field> &fields)
{
  if (fields[0].aggr_type() != A_NO) {
    std::vector<Field> tp;
    for (int i = fields.size()-1; i >= 0; i--) {
      tp.push_back(fields[i]);
    }
    fields.swap(tp);
    return;
  }
}


RC ExecuteStage::do_select2(SQLStageEvent *sql_event)
{
  SelectStmt *select_stmt = (SelectStmt *)(sql_event->stmt());
  SessionEvent *session_event = sql_event->session_event();
  FilterStmt *filter_stmt = select_stmt->filter_stmt();

  std::vector<Pretable*> pretables;

  RC rc = RC::SUCCESS;

  for (int i = 0; i < select_stmt->tables().size(); i++) {
    Pretable *pre = new Pretable;
    rc = pre->init(select_stmt->tables()[i], filter_stmt);
    if (rc != RC::RECORD_EOF) {
      delete pre;
      for (auto &t : pretables)
        delete t;
      return rc;
    }
    pretables.push_back(pre);
  }

  // no relevant field or something
  if (pretables.empty()) {
    LOG_ERROR("No table or No relevant condition");
    return RC::INTERNAL;
  }

  Pretable *res = pretables[0];
  auto iter = std::next(pretables.begin());
  while (iter != pretables.end()) {
    rc = res->join(*iter, filter_stmt);
    delete *iter;
    iter = pretables.erase(iter);
    if (rc != RC::SUCCESS) {
      while (iter != pretables.end()) {
        delete *iter;
        iter = pretables.erase(iter);
      }
      LOG_ERROR("join fails");
      return rc;
    }
  }

  std::stringstream ss;
  rc = RC::SUCCESS;
  reorder_fields(select_stmt->query_fields());
  print_fields(ss, select_stmt->query_fields(), select_stmt->tables().size() > 1);
  if (select_stmt->aggregate_num() > 0) {
    rc = res->aggregate(select_stmt->query_fields());
  } else {
    res->filter_fields(select_stmt->query_fields());
  }
  if (rc != RC::SUCCESS) {
    LOG_ERROR("aggregate error");
    session_event->set_response("FAILURE\n");
    return rc;
  }
  res->print(ss);

  session_event->set_response(ss.str());
  return rc;
}


RC ExecuteStage::do_select(SQLStageEvent *sql_event)
{
  SelectStmt *select_stmt = (SelectStmt *)(sql_event->stmt());
  SessionEvent *session_event = sql_event->session_event();
  RC rc = RC::SUCCESS;
  if (select_stmt->tables().size() != 1) {
    LOG_WARN("select more than 1 tables is not supported");
    rc = RC::UNIMPLENMENT;
    return rc;
  }

  Operator *scan_oper = try_to_create_index_scan_operator(select_stmt->filter_stmt());
  if (nullptr == scan_oper) {
    scan_oper = new TableScanOperator(select_stmt->tables()[0]);
  }

  DEFER([&] () {delete scan_oper;});

  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta());
  }
  rc = project_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }

  std::stringstream ss;
  print_tuple_header(ss, project_oper);
  while ((rc = project_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple * tuple = project_oper.current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    tuple_to_string(ss, *tuple);
    ss << std::endl;
  }

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    project_oper.close();
  } else {
    rc = project_oper.close();
  }
  session_event->set_response(ss.str());
  return rc;
}

RC ExecuteStage::do_help(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const char *response = "show tables;\n"
                         "desc `table name`;\n"
                         "create table `table name` (`column name` `column type`, ...);\n"
                         "create index `index name` on `table` (`column`);\n"
                         "insert into `table` values(`value1`,`value2`);\n"
                         "update `table` set column=value [where `column`=`value`];\n"
                         "delete from `table` [where `column`=`value`];\n"
                         "select [ * | `columns` ] from `table`;\n";
  session_event->set_response(response);
  return RC::SUCCESS;
}

RC ExecuteStage::do_create_table(SQLStageEvent *sql_event)
{
  const CreateTable &create_table = sql_event->query()->sstr.create_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(create_table.relation_name,
			create_table.attribute_count, create_table.attributes);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}
RC ExecuteStage::do_drop_table(SQLStageEvent *sql_event)
{
  const DropTable &drop_table = sql_event->query()->sstr.drop_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->drop_table(drop_table.relation_name);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_create_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const CreateIndex &create_index = sql_event->query()->sstr.create_index;
  Table *table = db->find_table(create_index.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  RC rc = table->create_index(nullptr, create_index.index_name, create_index.attribute_name, create_index.unique);
  sql_event->session_event()->set_response(rc == RC::SUCCESS ? "SUCCESS\n" : "FAILURE\n");
  return rc;
}

RC ExecuteStage::do_show_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const ShowIndex &show_index = sql_event->query()->sstr.show_index;
  Table *table = db->find_table(show_index.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::stringstream ss;
  table->show_index(ss);
  return RC::SUCCESS;
}

RC ExecuteStage::do_show_tables(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  std::vector<std::string> all_tables;
  db->all_tables(all_tables);
  if (all_tables.empty()) {
    session_event->set_response("No table\n");
  } else {
    std::stringstream ss;
    for (const auto &table : all_tables) {
      ss << table << std::endl;
    }
    session_event->set_response(ss.str().c_str());
  }
  return RC::SUCCESS;
}

RC ExecuteStage::do_desc_table(SQLStageEvent *sql_event)
{
  Query *query = sql_event->query();
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = query->sstr.desc_table.relation_name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;
  if (table != nullptr) {
    table->table_meta().desc(ss);
  } else {
    ss << "No such table: " << table_name << std::endl;
  }
  sql_event->session_event()->set_response(ss.str().c_str());
  return RC::SUCCESS;
}

bool check_attr_in_table(Table *table, const RelAttr &attr)
{
  if (attr.relation_name != nullptr && strcmp(table->name(), attr.relation_name) != 0) {
    return false;
  }
  return table->table_meta().field(attr.attribute_name) != nullptr;
}

RC check_updates(Db *db, const Updates &updates)
{
  const char *table_name = updates.relation_name;
  int condition_num = updates.condition_num;
  const Condition *conditions = updates.conditions;
  const char *attr_name = updates.attribute_name;
  const Value *value = &updates.value;
  Table *table = db->find_table(table_name);
  if (table == nullptr) {
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  if (value->type == DATES && *(int *)value->data == -1) {
    return RC::RECORD_INVALID_KEY;
  }

  const TableMeta &meta = table->table_meta();
  const FieldMeta *fmeta = meta.field(attr_name);
  if (fmeta == nullptr) {
    return RC::SCHEMA_FIELD_MISSING;
  }
  if (fmeta->type() != value->type) {
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  for (int i = 0; i < condition_num; i++) {
    const Condition &c = conditions[i];
    if (!c.left_is_attr && !c.right_is_attr) {
      return RC::INVALID_ARGUMENT;
    }
    if (c.left_is_attr) {
      if (!check_attr_in_table(table, c.left_attr)) {
        return RC::SCHEMA_FIELD_NAME_ILLEGAL;
      }
      if (c.right_value.type == DATES && *(int*)c.right_value.data == -1) {
        return RC::INVALID_ARGUMENT;
      }
      printf("%d\n", c.right_value.type);
      if (c.right_value.type != meta.field(c.left_attr.attribute_name)->type()) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    } else {
      if (!check_attr_in_table(table, c.right_attr)) {
        return RC::SCHEMA_FIELD_NAME_ILLEGAL;
      }
      if (c.left_value.type == DATES && *(int*)c.left_value.data == -1) {
        return RC::INVALID_ARGUMENT;
      }
      if (c.left_value.type != meta.field(c.right_attr.attribute_name)->type()) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }
  return RC::SUCCESS;
}

RC ExecuteStage::do_update_table(SQLStageEvent *sql_event)
{
  const Updates &updates = sql_event->query()->sstr.update;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = check_updates(db, updates);
  if (rc == RC::SUCCESS) {
    rc = db->update_table(updates.relation_name, updates.attribute_name, &updates.value,
                           updates.condition_num, updates.conditions);
  }

  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }

  // TODO: CLOG
  return rc;
}

RC ExecuteStage::value_check(const int &value_num, const Value *values) const
{
  for (int i = 0; i < value_num; i++) {
    if (values[i].type == DATES && *(const int*)values[i].data == -1) {
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }
  return RC::SUCCESS;
}

RC ExecuteStage::do_update(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  // Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  // CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  UpdateStmt *update_stmt = (UpdateStmt *)stmt;
  Table *table = update_stmt->table();

  Operator *scan_oper = try_to_create_index_scan_operator(update_stmt->filter_stmt());
  if (nullptr == scan_oper) {
    scan_oper = new TableScanOperator(update_stmt->table());
  }

  DEFER([&] () {delete scan_oper;});

  PredicateOperator pred_oper(update_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);

  RC rc = pred_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }

  const FieldMeta *field = update_stmt->attr_meta();
  Value *value = update_stmt->value();
  while ((rc = pred_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    RowTuple *tuple = dynamic_cast<RowTuple*>(pred_oper.current_tuple());
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }
    Record record = tuple->record();
    if (trx == nullptr || trx->is_visible(table, &record)) {
      // prepare data
      size_t copy_len = field->len();
      if (field->type() == CHARS) {
        const size_t data_len = strlen((const char *)value->data);
        if (copy_len > data_len) {
          copy_len = data_len + 1;
        }
      }
      memcpy(record.data() + field->offset(), value->data, copy_len);

      // update
      rc = table->update_record(trx, &record);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to update");
        return rc;
      }
    }
  }

  // TODO: CLOG

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    pred_oper.close();
  } else {
    rc = pred_oper.close();
  }
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_insert(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  InsertStmt *insert_stmt = (InsertStmt *)stmt;
  Table *table = insert_stmt->table();

  // RC rc = table->insert_record(trx, insert_stmt->value_amount(), insert_stmt->values());
  RC rc = table->insert_records(trx, insert_stmt->valuelist_amount(), insert_stmt->valuelists());
  if (rc == RC::SUCCESS) {
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      } 

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    } else {
      session_event->set_response("SUCCESS\n");
    }
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_delete(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  DeleteStmt *delete_stmt = (DeleteStmt *)stmt;
  TableScanOperator scan_oper(delete_stmt->table());
  PredicateOperator pred_oper(delete_stmt->filter_stmt());
  pred_oper.add_child(&scan_oper);
  DeleteOperator delete_oper(delete_stmt, trx);
  delete_oper.add_child(&pred_oper);

  RC rc = delete_oper.open();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      } 

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_begin(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(true);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_BEGIN, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

RC ExecuteStage::do_commit(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(false);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  trx->next_current_id();

  return rc;
}

RC ExecuteStage::do_clog_sync(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();

  rc = clog_manager->clog_sync();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

TupleSet::TupleSet(const Tuple *t, Table *table) {
  table_num_ = 1;
  data_ = std::string(t->get_record().data(), table->table_meta().record_size());
  for (const FieldMeta &meta : *table->table_meta().field_metas()) {
    metas_.emplace_back(table, meta);
  }
  for (int i = 0; i < t->cell_num(); i++) {
    TupleCell cell;
    t->cell_at(i, cell);
    cells_.push_back(cell);
  }
}

TupleSet::TupleSet(const TupleSet *t) {
  cells_ = t->cells_;
  metas_ = t->metas_;
  table_num_ = t->table_num_;
  data_ = t->data_;
}

TupleSet *TupleSet::copy() const {
  return new TupleSet(this);
}

// void TupleSet::combine(const TupleSet *t2) {
//   table_num_ += t2->table_num_;
//   for (auto meta : metas_)
//     metas_.push_back(meta);
//   for (auto cell : t2->cells_)
//     cells_.push_back(cell);
// }

TupleSet *TupleSet::generate_combine(const TupleSet *t2) {
  TupleSet *res = this->copy();
  res->table_num_ += t2->table_num_;
  res->data_ += t2->data();
  int off = 0;
  for (auto &meta : res->metas_) {
    off += meta.second.len();
  }
  for (auto meta : t2->metas_) {
    meta.second.set_offset(off + meta.second.offset());
    res->metas_.push_back(meta);
  }
  for (auto cell : t2->cells_) {
    res->cells_.push_back(cell);
  }
  return res;
}

void TupleSet::filter_fields(const std::vector<Field> &fields) {
  std::unordered_map<std::string, std::unordered_map<std::string, int>> mp;
  std::vector<std::pair<Table*, FieldMeta>> metas(fields.size());
  std::vector<TupleCell> cells(fields.size());
  for (int i = 0; i < fields.size(); i++) {
    mp[fields[i].table_name()][fields[i].field_name()] = i+1;
  }

  table_num_ = mp.size();

  for (int i = 0; i < metas_.size(); i++) {
    auto &p = metas_[i];
    int j = mp[p.first->name()][p.second.name()];
    if (j > 0) {
      cells[j-1] = cells_[i];
      metas[j-1] = metas_[i];
    }
  }

  cells_.swap(cells);
  metas_.swap(metas);
}

// used for aggregate, and they have 4 bytes
void TupleSet::push(const std::pair<Table*, FieldMeta> &p, const TupleCell &cell)
{
  metas_.push_back(p);
  metas_.back().second.set_offset(4 + metas_.back().second.offset());
  cells_.push_back(cell);
  data_ += std::string(cell.data(), cell.length());
}

int TupleSet::index(const Field &field) const
{
  if (!field.has_table() || !field.has_field()) {
    return -1;
  }
  for (int i = 0; i < metas_.size(); i++) {
    if (strcmp(metas_[i].first->name(), field.table_name()) == 0 &&
        strcmp(metas_[i].second.name(), field.field_name()) == 0) {
      return i;
    }
  }
  return -1;
}

const TupleCell &TupleSet::get_cell(int idx)
{
  return cells_[idx];
}
const std::pair<Table *, FieldMeta> &TupleSet::get_meta(int idx)
{
  if (idx == -1) {
    return metas_[0];
  }
  return metas_[idx];
}

int TupleSet::get_offset(const char *table_name, const char *field_name) const
{
  for (auto &meta : metas_) {
    if (strcmp(table_name, meta.first->name()) == 0 &&
        strcmp(field_name, meta.second.name()) == 0) {
      return meta.second.offset();
    }
  }
  return -1;
}

const FieldMeta &TupleSet::meta(int idx) const {
  return metas_[idx].second;
}

const std::vector<TupleCell> &TupleSet::cells() const {
  return cells_;
}

// filter table with table-specific conditions
FilterStmt *get_sub_filter(Table *table, FilterStmt *old_filter)
{
  FilterStmt *filter = new FilterStmt();
  for (FilterUnit *unit : old_filter->filter_units()) {
    Expression *left = unit->left();
    Expression *right = unit->right();
    if (left->type() == ExprType::FIELD && right->type() == ExprType::FIELD) {
      continue;
    }
    if (left->type() == ExprType::VALUE && right->type() == ExprType::VALUE) {
      filter->push(unit);
      continue;
    }
    if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
    }
    FieldExpr &left_field_expr = *(FieldExpr *)left;
    if (strcmp(table->name(), left_field_expr.table_name()) != 0 ||
        table->table_meta().field(left_field_expr.field_name()) == nullptr) {
      continue;
    }
    filter->push(unit);
  }
  return filter;
}

Pretable::Pretable(Pretable&& t)
    :tuples_(std::move(t.tuples_)),
     tables_(std::move(t.tables_))
{

}
Pretable& Pretable::operator=(Pretable&& t)
{
  tuples_ = std::move(t.tuples_);
  tables_ = std::move(t.tables_);
  return *this;
}

// TODO: delete filters
RC Pretable::init(Table *table, FilterStmt *old_filter)
{
  // TODO: check how to use index scan
  FilterStmt *filter = get_sub_filter(table, old_filter);
  tables_.push_back(table);

  Operator *scan_oper = new TableScanOperator(table);
  DEFER([&] () {delete scan_oper;});

  // first get a subset of filter
  PredicateOperator pred_oper(filter);
  pred_oper.add_child(scan_oper);

  RC rc = RC::SUCCESS;
  rc = pred_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }
  while ((rc = pred_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple = pred_oper.current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }
    tuples_.push_back(new TupleSet(tuple, table));
  }
  // delete filter;

  return rc;
}

const FieldMeta *Pretable::field(const Field &field) const {
  for (auto table : tables_) {
    if (strcmp(table->name(), field.table_name()) == 0) {
      const FieldMeta *tp = table->table_meta().field(field.field_name());
      if (tp != nullptr) {
        return tp;
      }
    }
  }
  return nullptr;
}

RC Pretable::aggregate_max(int idx, TupleCell *res)
{
  *res = tuples_[0].get_cell(idx);
  for (TupleSet &tuple : tuples_) {
    const TupleCell &cell = tuple.get_cell(idx);
    int comp = cell.compare(*res);
    if (comp > 0) {
      *res = cell;
    }
  }
  return RC::SUCCESS;
}

RC Pretable::aggregate_min(int idx, TupleCell *res)
{
  *res = tuples_[0].get_cell(idx);
  for (TupleSet &tuple : tuples_) {
    const TupleCell &cell = tuple.get_cell(idx);
    int comp = res->compare(cell);
    if (comp > 0) {
      *res = cell;
    }
  }
  return RC::SUCCESS;
}

RC Pretable::aggregate_sum(int idx, TupleCell *res)
{
  float ans = 0;
  AttrType type = UNDEFINED;
  for (TupleSet &tuple : tuples_) {
    const TupleCell &cell = tuple.get_cell(idx);
    type = cell.attr_type();
    switch (cell.attr_type()) {
      case INTS: {
        ans += *(int *)cell.data();
      } break;
      case FLOATS: {
        ans += *(float *)cell.data();
      } break;
      case CHARS: {
        ans += Stmt::char_to_float(cell.data());
      }
      case DATES:
      default: {
        return RC::INTERNAL;
      }
    }
  }
  res->set_type(type);
  res->set_length(sizeof(float));
  if (type == INTS) {
    int *a = new int();
    *a = ans;
    res->set_data((char *)a);
  } else if (type == FLOATS || type == CHARS) {
    float *a = new float();
    *a = ans;
    res->set_data((char *)a);
  }
  return RC::SUCCESS;
}

RC Pretable::aggregate_avg(int idx, TupleCell *res)
{
  float *ans = (float *)malloc(sizeof(float));
  *ans = 0;
  for (TupleSet &tuple : tuples_) {
    const TupleCell &cell = tuple.get_cell(idx);
    switch (cell.attr_type()) {
      case INTS: {
        *ans += *(int *)cell.data();
      } break;
      case FLOATS: {
        *ans += *(float *)cell.data();
      } break;
      case CHARS: {
        *ans += Stmt::char_to_float(cell.data());
      } break;
      case DATES:
      default: {
        return RC::INTERNAL;
      }
    }
  }
  res->set_type(FLOATS);
  res->set_length(sizeof(float));
  *ans = *ans / tuples_.size();
  // TODO: dangerous
  res->set_data((char *)ans);
  return RC::SUCCESS;
  // float *ans = new float();
  // *ans = 0;
  // for (TupleSet &tuple : tuples_) {
  //   const TupleCell &cell = tuple.get_cell(idx);
  //   switch (cell.attr_type()) {
  //     case INTS: {
  //       *ans += *(int *)cell.data();
  //     } break;
  //     case FLOATS: {
  //       *ans += *(float *)cell.data();
  //     } break;
  //     case DATES: case CHARS:
  //     default: {
  //       return RC::INTERNAL;
  //     }
  //   }
  // }
  // res->set_type(FLOATS);
  // res->set_length(sizeof(float));
  // *ans = *ans / tuples_.size();
  // // TODO: dangerous
  // res->set_data((char *)ans);
  // return RC::SUCCESS;
}

// TODO: invisible
RC Pretable::aggregate_count(int idx, TupleCell *res)
{
  int *ans = new int();
  *ans = tuples_.size();

  res->set_type(INTS);
  res->set_length(sizeof(int));
  res->set_data((char *)ans);
  return RC::SUCCESS;
}



RC Pretable::aggregate(const std::vector<Field> fields)
{
  if (tuples_.size() == 0) {
    return RC::SUCCESS;
  }
  TupleSet res;
  RC rc = RC::SUCCESS;
  for (const auto &field : fields) {
    int idx = tuples_[0].index(field);
    TupleCell cell;
    if (idx == -1 && field.aggr_type() != AggreType::A_COUNT) {
      cell.set_type(AttrType::CHARS);
      const std::string &s = field.aggr_str();
      cell.set_length(s.size());
      cell.set_data(strdup(s.c_str()));
    } else {
      switch (field.aggr_type()) {
        case A_NO:
          res.push(tuples_[0].get_meta(idx), tuples_[0].get_cell(idx));
          continue;
          break;
        case A_MAX:
          rc = aggregate_max(idx, &cell);
          break;
        case A_MIN:
          rc = aggregate_min(idx, &cell);
          break;
        case A_AVG:
          rc = aggregate_avg(idx, &cell);
          break;
        case A_COUNT:
          rc = aggregate_count(idx, &cell);break;
        case A_SUM:
          rc = aggregate_sum(idx, &cell); break;
        case A_FAILURE:
          return RC::SCHEMA_FIELD_REDUNDAN;
      }
      if (rc != SUCCESS) {
        LOG_ERROR("wrong wrong wrong");
        return rc;
      }
    }

    res.push(tuples_[0].get_meta(idx), cell);
  }
  tuples_.clear();
  tuples_.push_back(res);
  return RC::SUCCESS;
}



// if table is null, then it's this table, else its table outside
ConDesc Pretable::make_cond_desc(Expression *expr, Pretable *t2)
{
  ConDesc desc;
  if (expr->type() == ExprType::FIELD) {
    desc.is_attr = true;
    FieldExpr *field_expr = dynamic_cast<FieldExpr*>(expr);
    desc.attr_length = field_expr->field().meta()->len();
    if (field(field_expr->field()) != nullptr) {
      desc.attr_offset = tuples_[0].get_offset(field_expr->table_name(), field_expr->field_name());
    } else {
      desc.attr_offset = tuples_[0].size() + t2->tuples_[0].get_offset(field_expr->table_name(), field_expr->field_name());
    }

  } else {
    desc.is_attr = false;
    ValueExpr *value_expr = dynamic_cast<ValueExpr*>(expr);
    desc.value = value_expr->get_data();
  }
  return desc;
}

// combine two tupleset -> record, then filter
CompositeConditionFilter *Pretable::make_cond_filter(std::vector<FilterUnit*> &units, Pretable *t2)
{
  int n = units.size();
  if (n == 0) {
    return nullptr;
  }
  ConditionFilter **filters = new ConditionFilter*[n];

  for (int i = 0; i < n; i++) {
    ConDesc left = make_cond_desc(units[i]->left(), t2);
    ConDesc right = make_cond_desc(units[i]->right(), t2);
    AttrType left_type, right_type;
    if (units[i]->left()->type() == ExprType::FIELD) {
      left_type = dynamic_cast<FieldExpr*>(units[i]->left())->field().attr_type();
    } else {
      left_type = dynamic_cast<ValueExpr*>(units[i]->left())->get_type();
    }
    if (units[i]->right()->type() == ExprType::FIELD) {
      right_type = dynamic_cast<FieldExpr*>(units[i]->right())->field().attr_type();
    } else {
      right_type = dynamic_cast<ValueExpr*>(units[i]->right())->get_type();
    }

    // incomparable type is checked in filter stmt
    filters[i] = new DefaultConditionFilter();
    dynamic_cast<DefaultConditionFilter*>(filters[i])->init(left, right, left_type, right_type, units[i]->comp());
  }
  CompositeConditionFilter *ans = new CompositeConditionFilter();

  ans->init((const ConditionFilter**)filters, n);
  return ans;
}

RC Pretable::join(Pretable *pre2, FilterStmt *filter)
{
  std::vector<FilterUnit*> units;

  for (FilterUnit *unit : filter->filter_units()) {
    Expression *left = unit->left();
    Expression *right = unit->right();
    if (left->type() == ExprType::VALUE || right->type() == ExprType::VALUE) {
      continue;
    } // TODO: NEED TO SWAP
    FieldExpr *left_field_expr = dynamic_cast<FieldExpr*>(left);
    FieldExpr *right_field_expr = dynamic_cast<FieldExpr*>(right);
    if (this->field(left_field_expr->field()) != nullptr &&
        pre2->field(right_field_expr->field()) != nullptr) {
      units.push_back(unit);
    } else if (this->field(right_field_expr->field()) != nullptr &&
               pre2->field(left_field_expr->field()) != nullptr) {
      units.push_back(unit);
    }
  }

  if (pre2->tuples_.size() == 0 || tuples_.size() == 0) {
    tuples_.clear();
    return RC::SUCCESS;
  }

  CompositeConditionFilter *cond_filter = make_cond_filter(units, pre2);

  std::vector<TupleSet> res;
  if (cond_filter != nullptr) {
    for (TupleSet &t1 : tuples_) {
      for (TupleSet &t2 : pre2->tuples_) {
        TupleSet *tuple = t1.generate_combine(&t2);
        Record rec;
        char *buf = new char[tuple->data().size()];
        memcpy(buf, tuple->data().c_str(), tuple->data().size());
        rec.set_data(buf);
        if (cond_filter->filter(rec)) {
          res.push_back(*tuple);
        }
      }
    }
  } else {
    for (TupleSet &t1 : tuples_) {
      for (TupleSet &t2 : pre2->tuples_) {
        res.push_back(*t1.generate_combine(&t2));
      }
    }
  }

  // need to write hash functions to support hash join

  // // hash join
  // if (left_field != nullptr && right_field != nullptr) {
  //   std::unordered_map<std::string, class _Tp>
  // } else {
  //   // nested loop join

  // }
  for (Table *t : pre2->tables_) {
    tables_.push_back(t);
  }
  tuples_.swap(res);
  return RC::SUCCESS;
}

std::string aggr_to_string(AggreType type) {
  switch (type) {
    case A_MAX:
      return "max";
    case A_MIN:
      return "min";
    case A_AVG:
      return "avg";
    case A_COUNT:
      return "count";
    case A_SUM:
      return "sum";
    default:
      return "";
  }
}


// TODO: ALIAS
void ExecuteStage::print_fields(std::stringstream &ss, const std::vector<Field> &fields, bool multi) {
  bool first = true;
  for (auto &field : fields) {
    ss << (first ? "" : " | ");
    first = false;
    std::string tp = field.has_field() ? field.field_name() : field.aggr_str();
    if (field.should_print_table() ||
        (multi && field.has_table())) {
      tp = field.table_name() + ("." + tp);
    }
    if (field.aggr_type() != A_NO) {
      tp = aggr_to_string(field.aggr_type()) + '(' + tp + ')';
    }
    ss << tp;
  }

  if (!first) {
    ss << '\n';
  }
  // bool is_aggr = false;
  // for (const auto &field : fields) {
  //   if (field.aggr_type() != AggreType::A_NO) {
  //     is_aggr = true;
  //     break;
  //   }
  // }
  // bool first = true;
  // if (is_aggr) {
  //   for (int i = fields.size() - 1; i >= 0; i--) {
  //     ss << (first ? "" : " | ");
  //     first = false;
  //     std::string tp = fields[i].has_table() ? fields[i].field_name() : fields[i].count_str();
  //     if (multi && fields[i].has_table()) {
  //       tp = fields[i].table_name() + ("." + tp);
  //     }
  //     tp = fields[i].aggr_name() + '(' + tp + ')';
  //     ss << tp;
  //   }
  // } else {
  //   int idx = 0;
  //   std::string s;
  //   if (multi) {
  //     idx = fields.size()-1;
  //     while (idx >= 0 && fields[idx].table_name() != s) {
  //       idx--;
  //     }
  //     idx++;
  //   }
  //   int last_idx = fields.size();
  //   while (1) {
  //     for (int i = idx; i < last_idx; i++) {
  //       ss << (first ? "" : " | ");
  //       first = false;
  //       std::string tp = fields[i].field_name();
  //       if (multi && fields[i].has_table()) {
  //         tp = fields[i].table_name() + ("." + tp);
  //       }
  //       ss << tp;
  //     }
  //     last_idx = idx;
  //     idx--;
  //     if (idx < 0) {
  //       break;
  //     }
  //     s = fields[idx].table_name();
  //     while (idx >= 0 && (!fields[idx].has_table() || s == fields[idx].table_name())) {
  //       idx--;
  //     }
  //     idx++;
  //   }
  // }

}

void Pretable::filter_fields(const std::vector<Field> &fields) {
  for (auto &tuple : tuples_) {
      tuple.filter_fields(fields);
  }
}

void Pretable::print(std::stringstream &ss)
{
  for (const TupleSet &tuple : tuples_) {
    bool first = true;
    for (const TupleCell &cell : tuple.cells()) {
      if (!first) {
        ss << " | ";
      } else {
        first = false;
      }
      cell.to_string(ss);
    }
    ss << '\n';
  }
}
