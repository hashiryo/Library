---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  - icon: ':x:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':x:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u884C\u5217(mod2)"
    links:
    - https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d
  bundledCode: "#line 2 \"src/Math/Matrix_mod2.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u884C\u5217(mod2)\n * @category \u6570\u5B66\n *  Gauss_Jordan(A,B)\
    \ \u62E1\u5927\u4FC2\u6570\u884C\u5217\u306B\u5BFE\u3059\u308B\u30AC\u30A6\u30B9\
    \u30B8\u30E7\u30EB\u30C0\u30F3\u6CD5\n *  linear_equations \u8FD4\u308A\u5024\
    \ {\u89E3\u306E\u3046\u3061\u306E\u4E00\u3064,\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\
    \u30D9\u30AF\u30C8\u30EB}\n */\n// verify\u7528:\n// https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d\n\
    \n// BEGIN CUT HERE\n\nstruct Matrix_mod2 {\n private:\n  std::vector<std::vector<short>>\
    \ a;\n\n public:\n  Matrix_mod2() {}\n  Matrix_mod2(std::size_t n, std::size_t\
    \ m) : a(n, std::vector<short>(m, 0)) {}\n  Matrix_mod2(std::size_t n) : Matrix_mod2(n,\
    \ n) {}\n  inline const std::vector<short> &operator[](std::size_t k) const {\n\
    \    return a[k];\n  }\n  inline std::vector<short> &operator[](std::size_t k)\
    \ { return a[k]; }\n  std::size_t height() const { return a.size(); }\n  std::size_t\
    \ width() const { return a[0].size(); }\n  static Matrix_mod2 diag(std::vector<int>\
    \ v) {\n    Matrix_mod2 mat(v.size());\n    for (std::size_t i = 0; i < v.size();\
    \ i++) mat[i][i] = v[i];\n    return mat;\n  }\n  static Matrix_mod2 I(std::size_t\
    \ n) { return diag(std::vector<int>(n, 1)); }\n  Matrix_mod2 operator+(const Matrix_mod2\
    \ &b) const {\n    std::size_t n = height(), m = width();\n    Matrix_mod2 c(n,\
    \ m);\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0;\
    \ j < m; j++) c[i][j] = (*this)[i][j] ^ b[i][j];\n    return c;\n  }\n  Matrix_mod2\
    \ operator*(const Matrix_mod2 &b) const {\n    if (width() <= 64) return mul<64>(b);\n\
    \    if (width() <= 2600) return mul<2600>(b);\n    return mul<100010>(b);\n \
    \ }\n  Matrix_mod2 &operator+=(const Matrix_mod2 &b) { return *this = (*this)\
    \ + b; }\n  Matrix_mod2 &operator*=(const Matrix_mod2 &b) { return *this = (*this)\
    \ * b; }\n  Matrix_mod2 pow(uint64_t e) const {\n    Matrix_mod2 ret = I(height());\n\
    \    for (Matrix_mod2 base = *this; e; e >>= 1, base *= base)\n      if (e & 1)\
    \ ret *= base;\n    return ret;\n  }\n  bool operator==(const Matrix_mod2 &b)\
    \ const { return a == b.a; }\n\n  static std::pair<Matrix_mod2, Matrix_mod2> Gauss_Jordan(\n\
    \      const Matrix_mod2 &a, const Matrix_mod2 &b) {\n    if (a.width() + b.width()\
    \ <= 64) return gauss_jordan_content<64>(a, b);\n    if (a.width() + b.width()\
    \ <= 2600) return gauss_jordan_content<2600>(a, b);\n    return gauss_jordan_content<100010>(a,\
    \ b);\n  }\n  static std::pair<std::vector<int>, std::vector<std::vector<int>>>\n\
    \  linear_equations(const Matrix_mod2 &a, const std::vector<int> &b) {\n    std::size_t\
    \ n = a.height(), m = a.width();\n    Matrix_mod2 B(n, 1);\n    for (std::size_t\
    \ i = 0; i < n; i++) B[i][0] = b[i];\n    auto p = Gauss_Jordan(a, B);\n    std::vector<int>\
    \ jdx(n, -1), idx(m, -1);\n    for (std::size_t i = 0, j; i < n; i++) {\n    \
    \  for (j = 0; j < m; j++)\n        if (p.first[i][j]) {\n          jdx[i] = j,\
    \ idx[j] = i;\n          break;\n        }\n      if (j == m && p.second[i][0])\n\
    \        return std::make_pair(std::vector<int>(),\n                         \
    \     std::vector<std::vector<int>>());  // no solutions\n    }\n    std::vector<int>\
    \ c(m);\n    std::vector<std::vector<int>> d;\n    for (std::size_t j = 0; j <\
    \ m; j++) {\n      if (idx[j] != -1)\n        c[j] = p.second[idx[j]][0];\n  \
    \    else {\n        std::vector<int> v(m);\n        v[j] = 1;\n        for (std::size_t\
    \ i = 0; i < n; i++)\n          if (jdx[i] != -1) v[jdx[i]] = p.first[i][j];\n\
    \        d.push_back(v);\n      }\n    }\n    return std::make_pair(c, d);\n \
    \ }\n  int rank() const {\n    std::size_t n = height(), m = width();\n    Matrix_mod2\
    \ b(n, 0);\n    Matrix_mod2 p = Gauss_Jordan(*this, b).first;\n    for (std::size_t\
    \ i = 0, j; i < n; i++) {\n      for (j = 0; j < m; j++)\n        if (p[i][j]\
    \ != 0) break;\n      if (j == m) return i;\n    }\n    return n;\n  }\n\n private:\n\
    \  template <std::size_t SIZE>\n  Matrix_mod2 mul(const Matrix_mod2 &b) const\
    \ {\n    std::size_t n = height(), m = width(), l = b.width();\n    assert(m ==\
    \ b.height());\n    std::vector<std::bitset<SIZE>> tb(l);\n    for (std::size_t\
    \ i = 0; i < l; ++i)\n      for (std::size_t j = 0; j < m; ++j) tb[i][j] = b[j][i];\n\
    \    Matrix_mod2 c(n, l);\n    for (std::size_t i = 0; i < n; i++) {\n      std::bitset<SIZE>\
    \ abit;\n      for (std::size_t k = 0; k < m; k++) abit[k] = (*this)[i][k];\n\
    \      for (std::size_t j = 0; j < l; j++)\n        c[i][j] = ((abit & tb[j]).count()\
    \ & 1);\n    }\n    return c;\n  }\n\n  template <std::size_t SIZE>\n  static\
    \ std::pair<Matrix_mod2, Matrix_mod2> gauss_jordan_content(\n      const Matrix_mod2\
    \ &a, const Matrix_mod2 &b) {\n    std::size_t n = a.height(), m = a.width(),\
    \ l = b.width();\n    std::vector<std::bitset<SIZE>> c(n);\n    for (std::size_t\
    \ i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m; j++) c[i][j] = a[i][j];\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < l;\
    \ j++) c[i][j + m] = b[i][j];\n    for (std::size_t j = 0, d = 0; j < m && d <\
    \ n; j++) {\n      int p = d;\n      for (std::size_t i = d + 1; i < n; i++)\n\
    \        if (c[i][j]) p = i;\n      if (!c[p][j]) continue;\n      std::swap(c[p],\
    \ c[d]);\n      for (std::size_t i = 0; i < n; i++)\n        if (i != d && c[i][j])\
    \ c[i] ^= c[d];\n      d++;\n    }\n    Matrix_mod2 reta(n, m), retb(n, l);\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) reta[i][j] = c[i][j];\n    for (std::size_t i = 0; i < n; i++)\n      for\
    \ (std::size_t j = 0; j < l; j++) retb[i][j] = c[i][j + m];\n    return std::make_pair(reta,\
    \ retb);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u884C\u5217(mod2)\n\
    \ * @category \u6570\u5B66\n *  Gauss_Jordan(A,B) \u62E1\u5927\u4FC2\u6570\u884C\
    \u5217\u306B\u5BFE\u3059\u308B\u30AC\u30A6\u30B9\u30B8\u30E7\u30EB\u30C0\u30F3\
    \u6CD5\n *  linear_equations \u8FD4\u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\
    \u4E00\u3064,\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\
    // verify\u7528:\n// https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d\n\
    \n// BEGIN CUT HERE\n\nstruct Matrix_mod2 {\n private:\n  std::vector<std::vector<short>>\
    \ a;\n\n public:\n  Matrix_mod2() {}\n  Matrix_mod2(std::size_t n, std::size_t\
    \ m) : a(n, std::vector<short>(m, 0)) {}\n  Matrix_mod2(std::size_t n) : Matrix_mod2(n,\
    \ n) {}\n  inline const std::vector<short> &operator[](std::size_t k) const {\n\
    \    return a[k];\n  }\n  inline std::vector<short> &operator[](std::size_t k)\
    \ { return a[k]; }\n  std::size_t height() const { return a.size(); }\n  std::size_t\
    \ width() const { return a[0].size(); }\n  static Matrix_mod2 diag(std::vector<int>\
    \ v) {\n    Matrix_mod2 mat(v.size());\n    for (std::size_t i = 0; i < v.size();\
    \ i++) mat[i][i] = v[i];\n    return mat;\n  }\n  static Matrix_mod2 I(std::size_t\
    \ n) { return diag(std::vector<int>(n, 1)); }\n  Matrix_mod2 operator+(const Matrix_mod2\
    \ &b) const {\n    std::size_t n = height(), m = width();\n    Matrix_mod2 c(n,\
    \ m);\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0;\
    \ j < m; j++) c[i][j] = (*this)[i][j] ^ b[i][j];\n    return c;\n  }\n  Matrix_mod2\
    \ operator*(const Matrix_mod2 &b) const {\n    if (width() <= 64) return mul<64>(b);\n\
    \    if (width() <= 2600) return mul<2600>(b);\n    return mul<100010>(b);\n \
    \ }\n  Matrix_mod2 &operator+=(const Matrix_mod2 &b) { return *this = (*this)\
    \ + b; }\n  Matrix_mod2 &operator*=(const Matrix_mod2 &b) { return *this = (*this)\
    \ * b; }\n  Matrix_mod2 pow(uint64_t e) const {\n    Matrix_mod2 ret = I(height());\n\
    \    for (Matrix_mod2 base = *this; e; e >>= 1, base *= base)\n      if (e & 1)\
    \ ret *= base;\n    return ret;\n  }\n  bool operator==(const Matrix_mod2 &b)\
    \ const { return a == b.a; }\n\n  static std::pair<Matrix_mod2, Matrix_mod2> Gauss_Jordan(\n\
    \      const Matrix_mod2 &a, const Matrix_mod2 &b) {\n    if (a.width() + b.width()\
    \ <= 64) return gauss_jordan_content<64>(a, b);\n    if (a.width() + b.width()\
    \ <= 2600) return gauss_jordan_content<2600>(a, b);\n    return gauss_jordan_content<100010>(a,\
    \ b);\n  }\n  static std::pair<std::vector<int>, std::vector<std::vector<int>>>\n\
    \  linear_equations(const Matrix_mod2 &a, const std::vector<int> &b) {\n    std::size_t\
    \ n = a.height(), m = a.width();\n    Matrix_mod2 B(n, 1);\n    for (std::size_t\
    \ i = 0; i < n; i++) B[i][0] = b[i];\n    auto p = Gauss_Jordan(a, B);\n    std::vector<int>\
    \ jdx(n, -1), idx(m, -1);\n    for (std::size_t i = 0, j; i < n; i++) {\n    \
    \  for (j = 0; j < m; j++)\n        if (p.first[i][j]) {\n          jdx[i] = j,\
    \ idx[j] = i;\n          break;\n        }\n      if (j == m && p.second[i][0])\n\
    \        return std::make_pair(std::vector<int>(),\n                         \
    \     std::vector<std::vector<int>>());  // no solutions\n    }\n    std::vector<int>\
    \ c(m);\n    std::vector<std::vector<int>> d;\n    for (std::size_t j = 0; j <\
    \ m; j++) {\n      if (idx[j] != -1)\n        c[j] = p.second[idx[j]][0];\n  \
    \    else {\n        std::vector<int> v(m);\n        v[j] = 1;\n        for (std::size_t\
    \ i = 0; i < n; i++)\n          if (jdx[i] != -1) v[jdx[i]] = p.first[i][j];\n\
    \        d.push_back(v);\n      }\n    }\n    return std::make_pair(c, d);\n \
    \ }\n  int rank() const {\n    std::size_t n = height(), m = width();\n    Matrix_mod2\
    \ b(n, 0);\n    Matrix_mod2 p = Gauss_Jordan(*this, b).first;\n    for (std::size_t\
    \ i = 0, j; i < n; i++) {\n      for (j = 0; j < m; j++)\n        if (p[i][j]\
    \ != 0) break;\n      if (j == m) return i;\n    }\n    return n;\n  }\n\n private:\n\
    \  template <std::size_t SIZE>\n  Matrix_mod2 mul(const Matrix_mod2 &b) const\
    \ {\n    std::size_t n = height(), m = width(), l = b.width();\n    assert(m ==\
    \ b.height());\n    std::vector<std::bitset<SIZE>> tb(l);\n    for (std::size_t\
    \ i = 0; i < l; ++i)\n      for (std::size_t j = 0; j < m; ++j) tb[i][j] = b[j][i];\n\
    \    Matrix_mod2 c(n, l);\n    for (std::size_t i = 0; i < n; i++) {\n      std::bitset<SIZE>\
    \ abit;\n      for (std::size_t k = 0; k < m; k++) abit[k] = (*this)[i][k];\n\
    \      for (std::size_t j = 0; j < l; j++)\n        c[i][j] = ((abit & tb[j]).count()\
    \ & 1);\n    }\n    return c;\n  }\n\n  template <std::size_t SIZE>\n  static\
    \ std::pair<Matrix_mod2, Matrix_mod2> gauss_jordan_content(\n      const Matrix_mod2\
    \ &a, const Matrix_mod2 &b) {\n    std::size_t n = a.height(), m = a.width(),\
    \ l = b.width();\n    std::vector<std::bitset<SIZE>> c(n);\n    for (std::size_t\
    \ i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m; j++) c[i][j] = a[i][j];\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < l;\
    \ j++) c[i][j + m] = b[i][j];\n    for (std::size_t j = 0, d = 0; j < m && d <\
    \ n; j++) {\n      int p = d;\n      for (std::size_t i = d + 1; i < n; i++)\n\
    \        if (c[i][j]) p = i;\n      if (!c[p][j]) continue;\n      std::swap(c[p],\
    \ c[d]);\n      for (std::size_t i = 0; i < n; i++)\n        if (i != d && c[i][j])\
    \ c[i] ^= c[d];\n      d++;\n    }\n    Matrix_mod2 reta(n, m), retb(n, l);\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) reta[i][j] = c[i][j];\n    for (std::size_t i = 0; i < n; i++)\n      for\
    \ (std::size_t j = 0; j < l; j++) retb[i][j] = c[i][j + m];\n    return std::make_pair(reta,\
    \ retb);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Matrix_mod2.hpp
  requiredBy: []
  timestamp: '2020-10-24 14:33:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/803.test.cpp
  - test/yukicoder/184.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/2624.test.cpp
documentation_of: src/Math/Matrix_mod2.hpp
layout: document
redirect_from:
- /library/src/Math/Matrix_mod2.hpp
- /library/src/Math/Matrix_mod2.hpp.html
title: "\u884C\u5217(mod2)"
---
