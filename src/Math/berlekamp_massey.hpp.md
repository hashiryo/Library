---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':x:'
    path: src/LinearAlgebra/SparseSquareMatrix.hpp
    title: "\u758E\u884C\u5217"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/berlekamp_massey.hpp\"\n#include <bits/stdc++.h>\n\
    // a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] * a[n-d]\n// return c\n\
    template <class K> std::vector<K> berlekamp_massey(const std::vector<K> &a) {\n\
    \ std::size_t n= a.size(), d= 0, m= 0, i, j;\n if (n == 0) return {};\n std::vector<K>\
    \ c(n), b(n), tmp;\n K x= 1, y, coef;\n const K Z= 0;\n for (c[0]= b[0]= 1, i=\
    \ 0, j; i < n; ++i) {\n  for (++m, y= a[i], j= 1; j <= d; ++j) y+= c[j] * a[i\
    \ - j];\n  if (y == Z) continue;\n  for (tmp= c, coef= y / x, j= m; j < n; ++j)\
    \ c[j]-= coef * b[j - m];\n  if (2 * d > i) continue;\n  d= i + 1 - d, b= tmp,\
    \ x= y, m= 0;\n }\n c.resize(d + 1), c.erase(c.begin());\n for (auto &x: c) x=\
    \ -x;\n return c;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n// a[n] = c[0] * a[n-1] + c[1] *\
    \ a[n-2] + ... + c[d-1] * a[n-d]\n// return c\ntemplate <class K> std::vector<K>\
    \ berlekamp_massey(const std::vector<K> &a) {\n std::size_t n= a.size(), d= 0,\
    \ m= 0, i, j;\n if (n == 0) return {};\n std::vector<K> c(n), b(n), tmp;\n K x=\
    \ 1, y, coef;\n const K Z= 0;\n for (c[0]= b[0]= 1, i= 0, j; i < n; ++i) {\n \
    \ for (++m, y= a[i], j= 1; j <= d; ++j) y+= c[j] * a[i - j];\n  if (y == Z) continue;\n\
    \  for (tmp= c, coef= y / x, j= m; j < n; ++j) c[j]-= coef * b[j - m];\n  if (2\
    \ * d > i) continue;\n  d= i + 1 - d, b= tmp, x= y, m= 0;\n }\n c.resize(d + 1),\
    \ c.erase(c.begin());\n for (auto &x: c) x= -x;\n return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/berlekamp_massey.hpp
  requiredBy:
  - src/LinearAlgebra/MinimalPolynomial.hpp
  - src/LinearAlgebra/SparseSquareMatrix.hpp
  timestamp: '2022-12-31 19:53:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2397.SparseMat.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yosupo/find_linear_recurrence.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
documentation_of: src/Math/berlekamp_massey.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
数列の最初のN項から、その数列を生成する$N/2$次以下の最小の線形漸化式を求める

## 計算量
 $\mathcal{O}(N^2) $

## 問題例
[天下一プログラマーコンテスト2015予選B C - 擬二等辺三角形](https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c)