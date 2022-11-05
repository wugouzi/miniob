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
// Created by WangYunlai on 2022/6/7.
//

#pragma once

#include <iostream>
#include <cstring>
#include <util/util.h>
#include <common/log/log.h>
#include "sql/parser/parse_defs.h"
#include "storage/common/table.h"
#include "storage/common/field_meta.h"


class TupleCell
{
public: 
  TupleCell() = default;
  
  TupleCell(FieldMeta *meta, char *data)
    : TupleCell(meta->type(), data)
  {}
  TupleCell(AttrType attr_type, char *data)
    : attr_type_(attr_type), data_(data)
  {}

  void set_type(AttrType type) { this->attr_type_ = type; }
  void set_length(int length) { this->length_ = length; }
  void set_data(char *data) { this->data_ = data; }
  void set_data(const char *data) { this->set_data(const_cast<char *>(data)); }

  RC apply_func(TempMapFuncObject obj) {
    LOG_WARN("apply_func tempmap %s", obj.print().c_str());
    std::vector<char*> args;
    if (obj.argc) {
      args.push_back(obj.arg);
    }
    return apply_func(obj.type, args);
  }

  RC apply_func(MapFuncType func, std::vector<char*> extra_args) {
    LOG_WARN("cao");
    switch (func) {
      case MapFuncType::M_ID:
        break;
      case MapFuncType::M_LENGTH: {
        if (attr_type_ == AttrType::CHARS) {
          auto data = new char[5];
          auto s = std::string(data_);
          strip_quote(s);
          auto len = s.size();
          memcpy(data, &len, sizeof(int));
          set_data(data);
          set_type(AttrType::INTS);
          set_length(5);
        } else {
          return RC::INTERNAL;
        }
        break;
      }
      case MapFuncType::M_DATE_FORMAT: {
        if (attr_type_ == AttrType::DATES) {
          char* date_value = data_;
          char* pattern = "";
          if (extra_args.size() == 1) {
            pattern = extra_args[0];
          } else {
            LOG_ERROR("date_format argument number error");
            return RC::INTERNAL;
          }
          auto res = custom_date_format(date_value, pattern);
          auto data = strdup(res.c_str());
          set_data(data);
          set_type(AttrType::CHARS);
          set_length(strlen(data)+1);
        } else {
          return RC::INTERNAL;
        }
        break;
      }
      case MapFuncType::M_ROUND: {
        float f;
        if(attr_type_ == AttrType::CHARS){
          std::stringstream ss;
          ss << data_;
          ss >> f;
          attr_type_ = AttrType::FLOATS;
        }else if(attr_type_ == AttrType::FLOATS){
          f = *reinterpret_cast<float*>(data_);
        }
        if (attr_type_ == AttrType::FLOATS) {
          int digit = 0;
          if (extra_args.size()) {
            auto arg1 = extra_args[0];
            digit = static_cast<int>((long long)arg1);
          }
          auto res = custom_round(f, digit);
          auto data = strdup(res.c_str());
          set_data(data);
          set_type(AttrType::CHARS);
          set_length(res.size()+1);
        } else {
          return RC::INTERNAL;
        }
        break;
      }
      default: {
        return RC::INTERNAL;
      }
    }
    LOG_INFO("apply_func returning\n");
    return RC::SUCCESS;
  }

  TupleCell copy() {
    auto res = TupleCell();
    auto new_data = new char[length_];
    memcpy(new_data, data_, length_);
    res.set_data(new_data);
    res.set_length(length_);
    res.set_type(attr_type_);
    return res;
  }

  void to_string(std::ostream &os) const;

  int compare(const TupleCell &other) const;

  const char *data() const
  {
    return data_;
  }

  char *get_data()
  {
    return data_;
  }

  int length() const { return length_; }

  AttrType attr_type() const
  {
    return attr_type_;
  }

private:
  AttrType attr_type_ = UNDEFINED;
  int length_ = -1;
  char *data_ = nullptr; // real data. no need to move to field_meta.offset
};
