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
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069"
    links: []
  bundledCode: "#line 2 \"src/Math/Combination.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u4E8C\u9805\u4FC2\u6570\u306A\u3069\n * @category \u6570\u5B66\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <class mint>\nstruct Combination {\n private:\n\
    \  static inline std::vector<mint> fc = {1}, iv = {1};\n  static inline void set(int\
    \ sz) {\n    int lim = fc.size(), i;\n    if (lim > sz) return;\n    for (fc.resize(sz\
    \ + 1), iv.resize(sz + 1), i = lim; i <= sz; i++)\n      fc[i] = fc[i - 1] * i;\n\
    \    for (iv[sz] = mint(1) / fc[sz], i = sz; i >= lim; i--)\n      iv[i - 1] =\
    \ iv[i] * i;\n  }\n\n public:\n  static inline mint fact(int n) { return set(n),\
    \ n < 0 ? mint(0) : fc[n]; }\n  static inline mint finv(int n) { return set(n),\
    \ n < 0 ? mint(0) : iv[n]; }\n  static mint nPr(int n, int r) { return fact(n)\
    \ * finv(n - r); }\n  static mint nCr(int n, int r) { return nPr(n, r) * finv(r);\
    \ }\n  static mint nHr(int n, int r) { return !r ? mint(1) : nCr(n + r - 1, r);\
    \ }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u4E8C\u9805\u4FC2\
    \u6570\u306A\u3069\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <class mint>\nstruct Combination {\n private:\n  static inline std::vector<mint>\
    \ fc = {1}, iv = {1};\n  static inline void set(int sz) {\n    int lim = fc.size(),\
    \ i;\n    if (lim > sz) return;\n    for (fc.resize(sz + 1), iv.resize(sz + 1),\
    \ i = lim; i <= sz; i++)\n      fc[i] = fc[i - 1] * i;\n    for (iv[sz] = mint(1)\
    \ / fc[sz], i = sz; i >= lim; i--)\n      iv[i - 1] = iv[i] * i;\n  }\n\n public:\n\
    \  static inline mint fact(int n) { return set(n), n < 0 ? mint(0) : fc[n]; }\n\
    \  static inline mint finv(int n) { return set(n), n < 0 ? mint(0) : iv[n]; }\n\
    \  static mint nPr(int n, int r) { return fact(n) * finv(n - r); }\n  static mint\
    \ nCr(int n, int r) { return nPr(n, r) * finv(r); }\n  static mint nHr(int n,\
    \ int r) { return !r ? mint(1) : nCr(n + r - 1, r); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combination.hpp
  requiredBy: []
  timestamp: '2022-11-06 00:20:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: src/Math/Combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combination.hpp
- /library/src/Math/Combination.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069"
---
