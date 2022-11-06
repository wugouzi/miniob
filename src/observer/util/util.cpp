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

#include "util/util.h"
#include <cstring>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <sql/parser/parse_defs.h>

std::string double2string(double v)
{
  char buf[256];
  snprintf(buf, sizeof(buf), "%.2f", v);
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
      
  }
  if (buf[len - 1] == '.') {
    len--;
  }

  return std::string(buf, len);
}

std::string date_to_string(int date)
{
  std::string y = std::to_string(date / 10000);
  std::string m = std::to_string((date % 10000) / 100);
  std::string d = std::to_string(date % 100);
  for (size_t i = 0; i < 4-y.size(); i++) {
    y = '0'+y;
  }
  for (size_t i = 0; i < 2-m.size(); i++) {
    m = '0'+m;
  }
  for (size_t i = 0; i < 2-d.size(); i++) {
    d = '0'+d;
  }
  return y + '-' + m + '-' +d;
}



bool string_like(const char *s1, const char *s2)
{
  int n = strlen(s1), m = strlen(s2);
  auto match = [&](int i, int j) {
    if (i == 0 || j == 0) return false;
    return s1[i-1] == s2[j-1] || s2[j-1] == '_';
  };
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
  dp[0][0] = true;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s2[j-1] == '%') {
        dp[i][j] |= dp[i][j-1];
        if (i > 0) {
          dp[i][j] |= dp[i-1][j];
        }
      } else {
        if (match(i, j)) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = false;
        }
      }
    }
  }
  return dp[n][m];
}

double my_round(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::round(value * multiplier) / multiplier;
}


std::string custom_round(char *s, int digit){
  double d;
  std::stringstream tmp;
  tmp << s;
  tmp >> d;
  return custom_round(d, digit);
}

std::string custom_round(double val, int digit){
  std::stringstream tmp;
  tmp << std::setprecision(digit) << std::fixed << my_round(val, digit);
  std::string res;
  tmp >> res;
  return res;
}

std::string append_day_suffix(std::string day) {
  auto last_c = day.back();
  if (last_c == '1') {
    return day + "st";
  } else if (last_c == '2') {
    return day + "ed";
  } else if (last_c == '3') {
    return day + "rd";
  } else {
    return day + "th";
  }
}

// from https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
std::string ReplaceAll(std::string str,
                       const std::string& from,
                       const std::string& to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos +=
        to.length();
  }
  return str;
}

void strip_quote(std::string& p){
  // strip leading & tailing quotes
  if (!p.empty() && p.back() == '\'') {
    p.erase(p.end() - 1);
  }
  if (!p.empty() && p.front() == '\'') {
    p.erase(0, 1);
  }
}

std::string custom_date_format(char *date, char* pattern) {
  int value = *(int*)date;
  auto y = (value / 10000);
  auto m = ((value % 10000) / 100);
  auto d = (value % 100);
  auto p = std::string(pattern);
  strip_quote(p);
  std::stringstream ss;
  tm t;
  strptime(date_to_string(value).c_str(), "%Y-%m-%\d", &t);
  // %Y	年，4 位，如2022
  // %y	年，2 位，如22
  // %M	月名，英文，如January
  p = ReplaceAll(p, "%M", "%B");
  // %m	月号，数字，如06、12
  // %D	月的一天，带英文后缀，如21st、28th
  p = ReplaceAll(p, "%D", append_day_suffix(std::to_string(d)));
  // %d	月的一天，数字，如09、30
  ss << std::put_time(&t, p.c_str());
  return ss.str();
}

MapFuncType transform_aggr_to_func_type(AggreType aggr){
  switch (aggr) {
    case AggreType::A_LENGTH:
      return MapFuncType::M_LENGTH;
      break;
    case AggreType::A_DATE_FORMAT:
      return MapFuncType::M_DATE_FORMAT;
      break;
    case AggreType::A_ROUND:
      return MapFuncType::M_ROUND;
      break;
    default:
      break;
  }
  return MapFuncType::M_ID;
}

TempMapFuncObject::TempMapFuncObject(RelAttr &attr) {
  arg = attr.args[0];
  argc = attr.argc;
  type = transform_aggr_to_func_type(attr.type);
}

std::vector<char*> make_args(RelAttr& attr) {
  if (attr.argc) {
    return {attr.args[0]};
  }
  return {};
}

float to_float(std::string s)
{
  std::stringstream ss;
  ss << s;
  double res;
  ss >> res;
  return res;
}