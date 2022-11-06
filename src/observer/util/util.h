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
// Created by wangyunlai on 2022/9/28
//

#pragma once

#include <string>
#include <sstream>
#include "common/log/log.h"
#include <vector>
#include "sql/parser/parse_defs.h"

std::string double2string(double v);
bool string_like(const char *s1, const char *s2);
std::string date_to_string(int date);
std::string custom_round(double val, int digit);
std::string custom_round(char *, int digit);
std::string custom_date_format(char* date, char* pattern);
void strip_quote(std::string& p);
MapFuncType transform_aggr_to_func_type(AggreType aggr);

// 拉屎了！
class TempMapFuncObject {
  public:
   TempMapFuncObject() = default;
   TempMapFuncObject(RelAttr& attr);
   int argc = 0;
   char* arg = nullptr;
   MapFuncType type = MapFuncType::M_ID;
   std::string print() {
     std::stringstream ss;
     ss << "argc=" << argc << ";" << "type=" << type << '\n';
     return ss.str();
   }
};

std::vector<char*> make_args(RelAttr& attr);

std::vector<char*> make_args(RelAttr& attr);

float to_float(std::string s);