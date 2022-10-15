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
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <memory>
#include <vector>

#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple_cell.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"

class Table;

class TupleCellSpec
{
public:
  TupleCellSpec() = default;
  TupleCellSpec(Expression *expr) : expression_(expr)
  {}

  ~TupleCellSpec()
  {
    if (expression_) {
      delete expression_;
      expression_ = nullptr;
    }
  }

  void set_alias(const char *alias)
  {
    this->alias_ = alias;
  }
  const char *alias() const
  {
    return alias_;
  }

  Expression *expression() const
  {
    return expression_;
  }

private:
  const char *alias_ = nullptr;
  Expression *expression_ = nullptr;
};

class Tuple
{
public:
  Tuple() = default;
  virtual ~Tuple() = default;

  virtual int cell_num() const = 0; 
  virtual RC  cell_at(int index, TupleCell &cell) const = 0;
  virtual RC  find_cell(const Field &field, TupleCell &cell) const = 0;
  virtual RC  cell_spec_at(int index, const TupleCellSpec *&spec) const = 0;
};

class RowTuple : public Tuple
{
public:
  RowTuple() = default;
  virtual ~RowTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }

  void set_record(Record *record)
  {
    this->record_ = record;
  }

  void set_schema(const Table *table, const std::vector<FieldMeta> *fields)
  {
    table_ = table;
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new TupleCellSpec(new FieldExpr(table, &field)));
    }
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    const TupleCellSpec *spec = speces_[index];
    FieldExpr *field_expr = (FieldExpr *)spec->expression();
    const FieldMeta *field_meta = field_expr->field().meta();
    cell.set_type(field_meta->type());
    cell.set_data(this->record_->data() + field_meta->offset());
    cell.set_length(field_meta->len());
    return RC::SUCCESS;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    const char *table_name = field.table_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    const char *field_name = field.field_name();
    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr * field_expr = (const FieldExpr *)speces_[i]->expression();
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
        return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }

  Record &record()
  {
    return *record_;
  }

  const Record &record() const
  {
    return *record_;
  }
private:
  Record *record_ = nullptr;
  const Table *table_ = nullptr;
  std::vector<TupleCellSpec *> speces_;
};

class ProjectTuple : public Tuple
{
public:
  ProjectTuple() = default;
  virtual ~ProjectTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }

  void set_tuple(Tuple *tuple)
  {
    this->tuple_ = tuple;
  }

  void add_cell_spec(TupleCellSpec *spec)
  {
    speces_.push_back(spec);
  }
  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::GENERIC_ERROR;
    }
    if (tuple_ == nullptr) {
      return RC::GENERIC_ERROR;
    }

    const TupleCellSpec *spec = speces_[index];
    return spec->expression()->get_value(*tuple_, cell);
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    return tuple_->find_cell(field, cell);
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
private:
  std::vector<TupleCellSpec *> speces_;
  Tuple *tuple_ = nullptr;
};

// class CompositeTuple : public Tuple
// {
// public:
//   CompositeTuple() = default;
//   ~CompositeTuple() {
//     for (Tuple *t : tuples_) {
//       delete t;
//     }
//   }

//   int tuple_num() {
//     return tuple_num_;
//   }

//   CompositeTuple(const Tuple *t) {
//     tuples_.push_back(t->copy());
//     tuple_num_ = 1;
//     cell_num_ = t->cell_num();
//   }

//   CompositeTuple(const CompositeTuple *t) {
//     cell_num_ = t->cell_num_;
//     tuples_ = t->tuples_;
//     tuple_num_ = t->tuple_num_;
//   }

//   int cell_num() const override {
//     return cell_num_;
//   }

//   void add_tuple(Tuple *tuple) {
//     tuples_.push_back(tuple);
//     cell_num_ += tuple->cell_num();
//     tuple_num_++;
//   }

//   CompositeTuple *copy() const override {
//     return new CompositeTuple(this);
//   }

//   CompositeTuple *generate_combine(const CompositeTuple *t2) const {
//     CompositeTuple *res = this->copy();
//     for (const Tuple *t : t2->tuples_) {
//       res->add_tuple(t->copy());
//     }
//     return res;
//   }

//   const std::vector<Tuple *> tuples() {
//     return tuples_;
//   }

//   RC cell_at(int index, TupleCell &cell) const override {
//     if (index < 0 || index >= cell_num_) {
//       LOG_WARN("invalid argument. index=%d", index);
//       return RC::INVALID_ARGUMENT;
//     }
//     RC rc = RC::SUCCESS;
//     for (const Tuple *t : tuples_) {
//       if (index >= t->cell_num()) {
//         index -= t->cell_num();
//         continue;
//       }
//       rc = t->cell_at(index, cell);
//       break;
//     }
//     return rc;
//   }

//   RC find_cell(const Field &field, TupleCell &cell) const override {
//     RC rc = RC::SUCCESS;
//     for (const Tuple *t : tuples_) {
//       if ((rc = t->find_cell(field, cell)) == RC::SUCCESS) {
//         return rc;
//       }
//     }
//     return RC::NOTFOUND;
//   }

//   RC cell_spec_at(int index, const TupleCellSpec *&spec) const override {
//     RC rc = RC::SUCCESS;
//     for (const Tuple *t : tuples_) {
//       if ((rc = t->cell_spec_at(index, spec)) == RC::SUCCESS) {
//         return rc;
//       }
//       index -= t->cell_num();
//     }
//     return RC::NOTFOUND;
//   }
// private:
//   int tuple_num_ = 0;
//   int cell_num_ = 0;
//   std::vector<Tuple *> tuples_;
// };
