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
// Created by WangYunlai on 2022/6/27.
//

#include "common/log/log.h"
#include "sql/expr/expression.h"
#include "sql/executor/execute_stage.h"
#include "sql/expr/tuple.h"
#include "sql/expr/tuple_cell.h"
#include "util/util.h"
#include "sql/operator/predicate_operator.h"
#include "sql/parser/parse_defs.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

RC PredicateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open();
}

RC PredicateOperator::next()
{
  RC rc = RC::SUCCESS;
  Operator *oper = children_[0];
  
  while (RC::SUCCESS == (rc = oper->next())) {
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }

    if (do_predicate(static_cast<RowTuple &>(*tuple), &rc)) {
      return rc;
    }
  }
  return rc;
}

RC PredicateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

Tuple * PredicateOperator::current_tuple()
{
  return children_[0]->current_tuple();
}

std::unordered_map<std::string, std::unordered_map<std::string, TupleCell>> make_context(RowTuple &tuple)
{
  const Table *t = tuple.table();
  std::unordered_map<std::string, std::unordered_map<std::string, TupleCell>> context;
  for (int i = 0; i < tuple.cell_num(); i++) {
    TupleCell cell;
    tuple.cell_at(i, cell);
    context[t->name()][t->table_meta().field(i)->name()] = cell;
  }
  return context;
}

void append_to_context(TableContext &dst_context, TableContext &src_context){
  for(auto &context_record: src_context){
    dst_context[context_record.first] = context_record.second;
  }
}

bool PredicateOperator::execute_filter_unit(const FilterUnit *filter_unit, RowTuple &tuple, TableContext &original_context, RC *rc){
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    TupleCell left_cell;
    TupleCell right_cell;

    LOG_INFO("original context size: %d\n", original_context.size());

    CompOp comp = filter_unit->comp();

    if (left_expr->type() == ExprType::VALUE) {
      ValueExpr *val_expr = dynamic_cast<ValueExpr *>(left_expr);
      if (val_expr->is_selects()) {
        auto context = make_context(tuple);
        append_to_context(context, original_context);
        Pretable* res = ExecuteStage::Selects_to_pretable(
            db_, val_expr->selects(), context, rc);
        if (*rc != RC::SUCCESS) {
          return true;
        }
        if (comp == VALUE_IN || comp == VALUE_NOT_IN ||
            comp == VALUE_EXISTS || comp == VALUE_NOT_EXISTS) {
          if (res->fields_.size() > 1) {
            *rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
            return true;
          }
          val_expr->set_pretable(res);
        } else {
          *rc = res->assign_row_to_value(left_cell);
          if (*rc != RC::SUCCESS) {
            return true;
          }
        }
      } else {
        LOG_INFO("test1");
        left_expr->get_value(tuple, left_cell);
      }
    } else {
      LOG_INFO("test2");
      left_expr->get_value(tuple, left_cell);
      LOG_INFO("test3");
    }

    LOG_INFO("haha1");

    if (right_expr->type() == ExprType::VALUE) {
      ValueExpr *val_expr = dynamic_cast<ValueExpr *>(right_expr);
      if (val_expr->is_selects()) {
        auto context = make_context(tuple);
        append_to_context(context, original_context);
        Pretable *res = ExecuteStage::Selects_to_pretable(db_, val_expr->selects(), context, rc);
        if (*rc != RC::SUCCESS) {
          return true;
        }
        if (comp == VALUE_IN || comp == VALUE_NOT_IN ||
            comp == VALUE_EXISTS || comp == VALUE_NOT_EXISTS) {
          if (res->fields_.size() > 1) {
            *rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
            return true;
          }
          val_expr->set_pretable(res);
        } else {
          *rc = res->assign_row_to_value(right_cell);
          if (*rc != RC::SUCCESS) {
            return true;
          }
        }
      } else {
        right_expr->get_value(tuple, right_cell);
      }
    } else {
      right_expr->get_value(tuple, right_cell);
    }

    LOG_INFO("haha2");

    // NULL COMPARE
    // TODO: type check
    bool filter_result = false;
    if (comp == VALUE_IN) {
      ValueExpr *right_value_expr = dynamic_cast<ValueExpr*>(right_expr);
      filter_result =  right_value_expr->pretable()->in(left_cell);
    } else if (comp == VALUE_NOT_IN) {
      ValueExpr *right_value_expr = dynamic_cast<ValueExpr*>(right_expr);
      filter_result = right_value_expr->pretable()->not_in(left_cell);
    } else if (comp == VALUE_EXISTS) {
      ValueExpr *right_value_expr = dynamic_cast<ValueExpr*>(right_expr);
      filter_result = right_value_expr->pretable()->tuple_num() > 0;
    } else if (comp == VALUE_NOT_EXISTS) {
      ValueExpr *right_value_expr = dynamic_cast<ValueExpr*>(right_expr);
      filter_result = right_value_expr->pretable()->tuple_num() == 0;
    } else if (left_cell.attr_type() == UNDEFINED || right_cell.attr_type() == UNDEFINED) {
      return false;
    } else if (left_cell.attr_type() == AttrType::NULLS && right_cell.attr_type() == AttrType::NULLS &&
        comp == IS_EQUAL) {
      filter_result = true;
    } else if (left_cell.attr_type() != AttrType::NULLS && right_cell.attr_type() == AttrType::NULLS &&
               comp == IS_NOT_EQUAL) {
      filter_result = true;
    } else if (left_cell.attr_type() == AttrType::NULLS || right_cell.attr_type() == AttrType::NULLS) {
      return false;
    } else if (comp == STR_LIKE) {
      filter_result = string_like(left_cell.data(), right_cell.data());
    } else if (comp == STR_NOT_LIKE) {
      filter_result = !string_like(left_cell.data(), right_cell.data());
    } else {
      const int compare = left_cell.compare(right_cell);
      switch (comp) {
        case EQUAL_TO: {
          filter_result = (0 == compare);
        } break;
        case LESS_EQUAL: {
          filter_result = (compare <= 0);
        } break;
        case NOT_EQUAL: {
          filter_result = (compare != 0);
        } break;
        case LESS_THAN: {
          filter_result = (compare < 0);
        } break;
        case GREAT_EQUAL: {
          filter_result = (compare >= 0);
        } break;
        case GREAT_THAN: {
          filter_result = (compare > 0);
        } break;
        default: {
          LOG_WARN("invalid compare type: %d", comp);
        } break;
      }
    }

    LOG_INFO("haha3");
    return filter_result;
}

bool PredicateOperator::do_predicate(RowTuple &tuple, RC *rc)
{
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    return true;
  }

  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    auto res = execute_filter_unit(filter_unit, tuple, filter_stmt_->context, rc);
    if (*rc != RC::SUCCESS) {
      return true;
    }
    // TODO check rc
    if(filter_stmt_->is_or){
      if(res){
        return true;
      }
    }else{
      if(!res){
        return false;
      }
    }
  }
  return true;
}

// int PredicateOperator::tuple_cell_num() const
// {
//   return children_[0]->tuple_cell_num();
// }
// RC PredicateOperator::tuple_cell_spec_at(int index, TupleCellSpec &spec) const
// {
//   return children_[0]->tuple_cell_spec_at(index, spec);
// }
