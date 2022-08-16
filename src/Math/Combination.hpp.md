---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D44\u307F\u5408\u308F\u305B"
    links: []
  bundledCode: "#line 2 \"src/Math/Combination.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u7D44\u307F\u5408\u308F\u305B\n * @category \u6570\u5B66\n */\n\n\
    // BEGIN CUT HERE\n\ntemplate <class mint, std::size_t LIM = (1 << 24)>\nstruct\
    \ Combination {\n private:\n  static inline mint _fact[LIM] = {1}, _finv[LIM]\
    \ = {1};\n  static inline int lim = 1;\n  static inline void set(int sz) {\n \
    \   if (lim > sz) return;\n    for (int i = lim; i <= sz; i++) _fact[i] = _fact[i\
    \ - 1] * i;\n    _finv[sz] = mint(1) / _fact[sz];\n    for (int i = sz; i >= lim;\
    \ i--) _finv[i - 1] = _finv[i] * i;\n    lim = sz + 1;\n  }\n\n public:\n  static\
    \ inline mint fact(int n) { return set(n), n < 0 ? mint(0) : _fact[n]; }\n  static\
    \ inline mint finv(int n) { return set(n), n < 0 ? mint(0) : _finv[n]; }\n  static\
    \ mint nPr(int n, int r) { return fact(n) * finv(n - r); }\n  static mint nCr(int\
    \ n, int r) { return nPr(n, r) * finv(r); }\n  static mint nHr(int n, int r) {\
    \ return !r ? mint(1) : nCr(n + r - 1, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u7D44\u307F\u5408\
    \u308F\u305B\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <class mint, std::size_t LIM = (1 << 24)>\nstruct Combination {\n private:\n\
    \  static inline mint _fact[LIM] = {1}, _finv[LIM] = {1};\n  static inline int\
    \ lim = 1;\n  static inline void set(int sz) {\n    if (lim > sz) return;\n  \
    \  for (int i = lim; i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n    _finv[sz]\
    \ = mint(1) / _fact[sz];\n    for (int i = sz; i >= lim; i--) _finv[i - 1] = _finv[i]\
    \ * i;\n    lim = sz + 1;\n  }\n\n public:\n  static inline mint fact(int n) {\
    \ return set(n), n < 0 ? mint(0) : _fact[n]; }\n  static inline mint finv(int\
    \ n) { return set(n), n < 0 ? mint(0) : _finv[n]; }\n  static mint nPr(int n,\
    \ int r) { return fact(n) * finv(n - r); }\n  static mint nCr(int n, int r) {\
    \ return nPr(n, r) * finv(r); }\n  static mint nHr(int n, int r) { return !r ?\
    \ mint(1) : nCr(n + r - 1, r); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combination.hpp
  requiredBy: []
  timestamp: '2022-06-16 15:13:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
documentation_of: src/Math/Combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combination.hpp
- /library/src/Math/Combination.hpp.html
title: "\u7D44\u307F\u5408\u308F\u305B"
---
