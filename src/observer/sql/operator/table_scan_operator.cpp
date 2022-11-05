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
// Created by WangYunlai on 2021/6/9.
//

#include "sql/operator/table_scan_operator.h"
#include "sql/executor/execute_stage.h"
#include "storage/common/table.h"
#include "rc.h"
#include <vector>

RC TableScanOperator::open()
{
  if (table_) {
    RC rc = table_->get_record_scanner(record_scanner_);
    if (rc == RC::SUCCESS) {
      tuple_.set_schema(table_, table_->table_meta().field_metas());
    }
    return rc;
  }
  return RC::SUCCESS;
}

RC TableScanOperator::next()
{
  if (table_) {
    if (!record_scanner_.has_next()) {
      return RC::RECORD_EOF;
    }

    RC rc = record_scanner_.next(current_record_);
    return rc;
  }
  std::vector<TupleSet> &group = pre_->groups_[0];
  if (pre_idx_ >= group.size()) {
    return RC::RECORD_EOF;
  }
  int len = group[pre_idx_].data().size();
  char *data = new char[len];
  memcpy(data, group[pre_idx_].data().c_str(),len);
  current_record_.set_data(data);
  return RC::SUCCESS;
}

RC TableScanOperator::close()
{
  if (table_) {
    return record_scanner_.close_scan();
  }
  return RC::SUCCESS;
}

Tuple * TableScanOperator::current_tuple()
{
  tuple_.set_record(&current_record_);
  return &tuple_;
}
// RC TableScanOperator::tuple_cell_spec_at(int index, TupleCellSpec &spec) const
// {
//   return tuple_.cell_spec_at(index, spec);
// }
