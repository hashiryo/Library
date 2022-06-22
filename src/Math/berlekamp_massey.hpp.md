---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':question:'
    path: src/LinearAlgebra/SparseSquareMatrix.hpp
    title: "\u758E\u884C\u5217"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Berlekamp-Massey
    links:
    - https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c
  bundledCode: "#line 2 \"src/Math/berlekamp_massey.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Berlekamp-Massey\n * @category \u6570\u5B66\n * \u6570\u5217\u306E\
    \u6700\u521D\u306EN\u9805\u304B\u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\
    \u6210\u3059\u308BN/2\u6B21\u4EE5\u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\
    \u5316\u5F0F\u3092\u6C42\u3081\u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n//\
    \ https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\n\
    // BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] *\
    \ a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  std::vector<K>\
    \ c(n), b(n), tmp;\n  K x = 1, y, coef;\n  const K Z = 0;\n  for (c[0] = b[0]\
    \ = 1, i = 0, j; i < n; ++i) {\n    for (++m, y = a[i], j = 1; j <= d; ++j) y\
    \ += c[j] * a[i - j];\n    if (y == Z) continue;\n    for (tmp = c, coef = y /\
    \ x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n    if (2 * d > i) continue;\n\
    \    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n  c.resize(d + 1), c.erase(c.begin());\n\
    \  for (auto &x : c) x = -x;\n  return c;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Berlekamp-Massey\n\
    \ * @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1]\
    \ * a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  std::vector<K>\
    \ c(n), b(n), tmp;\n  K x = 1, y, coef;\n  const K Z = 0;\n  for (c[0] = b[0]\
    \ = 1, i = 0, j; i < n; ++i) {\n    for (++m, y = a[i], j = 1; j <= d; ++j) y\
    \ += c[j] * a[i - j];\n    if (y == Z) continue;\n    for (tmp = c, coef = y /\
    \ x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n    if (2 * d > i) continue;\n\
    \    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n  c.resize(d + 1), c.erase(c.begin());\n\
    \  for (auto &x : c) x = -x;\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/berlekamp_massey.hpp
  requiredBy:
  - src/LinearAlgebra/MinimalPolynomial.hpp
  - src/LinearAlgebra/SparseSquareMatrix.hpp
  timestamp: '2022-06-21 23:05:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yosupo/find_linear_recurrence.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
documentation_of: src/Math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/Math/berlekamp_massey.hpp
- /library/src/Math/berlekamp_massey.hpp.html
title: Berlekamp-Massey
---
