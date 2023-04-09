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
    path: test/atcoder/abc160_f.test.cpp
    title: test/atcoder/abc160_f.test.cpp
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
    links: []
  bundledCode: "#line 2 \"src/Math/Combination.hpp\"\ntemplate <class mint, std::size_t\
    \ LIM= (1 << 24)> class Combination {\n static inline mint _fact[LIM], _finv[LIM];\n\
    \ static inline int lim= 0;\n static inline void set(int sz) {\n  if (lim > sz)\
    \ return;\n  if (lim == 0) _fact[0]= 1, _finv[0]= 1, lim= 1;\n  for (int i= lim;\
    \ i <= sz; i++) _fact[i]= _fact[i - 1] * i;\n  _finv[sz]= mint(1) / _fact[sz];\n\
    \  for (int i= sz; i >= lim; i--) _finv[i - 1]= _finv[i] * i;\n  lim= sz + 1;\n\
    \ }\npublic:\n static inline mint fact(int n) { return set(n), n < 0 ? mint(0)\
    \ : _fact[n]; }\n static inline mint finv(int n) { return set(n), n < 0 ? mint(0)\
    \ : _finv[n]; }\n static mint nPr(int n, int r) { return fact(n) * finv(n - r);\
    \ }\n static mint nCr(int n, int r) { return nPr(n, r) * finv(r); }\n static mint\
    \ nHr(int n, int r) { return !r ? mint(1) : nCr(n + r - 1, r); }\n};\n"
  code: "#pragma once\ntemplate <class mint, std::size_t LIM= (1 << 24)> class Combination\
    \ {\n static inline mint _fact[LIM], _finv[LIM];\n static inline int lim= 0;\n\
    \ static inline void set(int sz) {\n  if (lim > sz) return;\n  if (lim == 0) _fact[0]=\
    \ 1, _finv[0]= 1, lim= 1;\n  for (int i= lim; i <= sz; i++) _fact[i]= _fact[i\
    \ - 1] * i;\n  _finv[sz]= mint(1) / _fact[sz];\n  for (int i= sz; i >= lim; i--)\
    \ _finv[i - 1]= _finv[i] * i;\n  lim= sz + 1;\n }\npublic:\n static inline mint\
    \ fact(int n) { return set(n), n < 0 ? mint(0) : _fact[n]; }\n static inline mint\
    \ finv(int n) { return set(n), n < 0 ? mint(0) : _finv[n]; }\n static mint nPr(int\
    \ n, int r) { return fact(n) * finv(n - r); }\n static mint nCr(int n, int r)\
    \ { return nPr(n, r) * finv(r); }\n static mint nHr(int n, int r) { return !r\
    \ ? mint(1) : nCr(n + r - 1, r); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combination.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:28:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc160_f.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
documentation_of: src/Math/Combination.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069 (\u968E\u4E57\u524D\u8A08\u7B97) ($\\\
  mathbb{F}_p$)"
---
