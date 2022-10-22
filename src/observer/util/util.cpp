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

#include <string.h>
#include <vector>
#include "util/util.h"

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


bool string_like(const char *s1, const char *s2)
{
  int n = strlen(s1), m = strlen(s2);
  auto match = [&](char a, char b) {
    return a == b || a == '_' || b == '_';
  };
  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s2[j-1] == '%') {
        dp[i][j] = dp[i-1][j] || dp[i][j-1];
      } else {
        if (match(s2[j-1], s1[i-1])) {
          dp[i][j] = dp[i-1][j-1];
        } else {
          dp[i][j] = false;
        }
      }
    }
  }
  return dp[n][m];
}
