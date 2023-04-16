---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.MinPoly.test.cpp
    title: test/aoj/2397.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/berlekamp_massey.hpp\"\n#include <vector>\n// a[n]\
    \ = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] * a[n-d]\n// return c\ntemplate\
    \ <class K> std::vector<K> berlekamp_massey(const std::vector<K> &a) {\n size_t\
    \ n= a.size(), d= 0, m= 0, i, j;\n if (n == 0) return {};\n std::vector<K> c(n),\
    \ b(n), tmp;\n K x= 1, y, coef;\n const K Z= 0;\n for (c[0]= b[0]= 1, i= 0, j;\
    \ i < n; ++i) {\n  for (++m, y= a[i], j= 1; j <= d; ++j) y+= c[j] * a[i - j];\n\
    \  if (y == Z) continue;\n  for (tmp= c, coef= y / x, j= m; j < n; ++j) c[j]-=\
    \ coef * b[j - m];\n  if (2 * d > i) continue;\n  d= i + 1 - d, b= tmp, x= y,\
    \ m= 0;\n }\n c.resize(d + 1), c.erase(c.begin());\n for (auto &x: c) x= -x;\n\
    \ return c;\n}\n"
  code: "#pragma once\n#include <vector>\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2]\
    \ + ... + c[d-1] * a[n-d]\n// return c\ntemplate <class K> std::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n size_t n= a.size(), d= 0, m= 0, i, j;\n if (n == 0) return\
    \ {};\n std::vector<K> c(n), b(n), tmp;\n K x= 1, y, coef;\n const K Z= 0;\n for\
    \ (c[0]= b[0]= 1, i= 0, j; i < n; ++i) {\n  for (++m, y= a[i], j= 1; j <= d; ++j)\
    \ y+= c[j] * a[i - j];\n  if (y == Z) continue;\n  for (tmp= c, coef= y / x, j=\
    \ m; j < n; ++j) c[j]-= coef * b[j - m];\n  if (2 * d > i) continue;\n  d= i +\
    \ 1 - d, b= tmp, x= y, m= 0;\n }\n c.resize(d + 1), c.erase(c.begin());\n for\
    \ (auto &x: c) x= -x;\n return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/berlekamp_massey.hpp
  requiredBy:
  - src/LinearAlgebra/MinimalPolynomial.hpp
  timestamp: '2023-03-12 20:26:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/find_linear_recurrence.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
documentation_of: src/Math/berlekamp_massey.hpp
layout: document
title: Berlekamp-Massey
---
数列$\lbrace a_i\rbrace$の最初の $n$ 項 $\lbrace a_i\rbrace_{i=0}^{n-1}$から、その数列を生成する最小の線形漸化式
$$
a_i = c_0 a_{i-1} + c_1 a_{i-2} + \cdots + c_{d-1}a_{i-d}
$$
を求める. ( $d\le n/2$ )

## 計算量
 $\mathcal{O}(n^2) $

## 問題例
[天下一プログラマーコンテスト2015予選B C - 擬二等辺三角形](https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c)