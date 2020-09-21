---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7D44\u307F\u5408\u308F\u305B"
    links: []
  bundledCode: "#line 1 \"src/Math/Combination.hpp\"\n/**\n * @title \u7D44\u307F\u5408\
    \u308F\u305B\n * @category \u6570\u5B66\n */\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n\ntemplate <class Modint>\nstruct\
    \ Combination {\n  static vector<Modint> _fact, _finv, _inv;\n  static void init(int\
    \ sz) {\n    int n = min(2 * sz, Modint::modulo() - 1);\n    _fact.resize(n +\
    \ 1), _finv.resize(n + 1), _inv.resize(n + 1);\n    for (int i = 0; i <= n; ++i)\
    \ _fact[i] = i ? Modint(i) * _fact[i - 1] : 1;\n    _finv[n] = _fact[n].inverse();\n\
    \    for (int i = n; i; --i) _finv[i - 1] = Modint(i) * _finv[i];\n    for (int\
    \ i = 1; i <= n; ++i) _inv[i] = _finv[i] * _fact[i - 1];\n  }\n  static Modint\
    \ inverse(int n) { return _inv[n]; }\n  static Modint fact(int n, bool inv = 0)\
    \ { return inv ? _finv[n] : _fact[n]; }\n  static Modint nPr(int n, int r) {\n\
    \    if (n < r || r < 0) return Modint(0);\n    return _fact[n] * _finv[n - r];\n\
    \  }\n  static Modint nCr(int n, int r) { return nPr(n, r) * _finv[r]; }\n  static\
    \ Modint nHr(int n, int r) { return !r ? Modint(1) : nCr(n + r - 1, r); }\n  static\
    \ size_t size() { return _inv.size(); }\n};\ntemplate <class Modint>\nvector<Modint>\
    \ Combination<Modint>::_fact;\ntemplate <class Modint>\nvector<Modint> Combination<Modint>::_finv;\n\
    template <class Modint>\nvector<Modint> Combination<Modint>::_inv;\n"
  code: "/**\n * @title \u7D44\u307F\u5408\u308F\u305B\n * @category \u6570\u5B66\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\ntemplate <class Modint>\nstruct Combination {\n  static vector<Modint>\
    \ _fact, _finv, _inv;\n  static void init(int sz) {\n    int n = min(2 * sz, Modint::modulo()\
    \ - 1);\n    _fact.resize(n + 1), _finv.resize(n + 1), _inv.resize(n + 1);\n \
    \   for (int i = 0; i <= n; ++i) _fact[i] = i ? Modint(i) * _fact[i - 1] : 1;\n\
    \    _finv[n] = _fact[n].inverse();\n    for (int i = n; i; --i) _finv[i - 1]\
    \ = Modint(i) * _finv[i];\n    for (int i = 1; i <= n; ++i) _inv[i] = _finv[i]\
    \ * _fact[i - 1];\n  }\n  static Modint inverse(int n) { return _inv[n]; }\n \
    \ static Modint fact(int n, bool inv = 0) { return inv ? _finv[n] : _fact[n];\
    \ }\n  static Modint nPr(int n, int r) {\n    if (n < r || r < 0) return Modint(0);\n\
    \    return _fact[n] * _finv[n - r];\n  }\n  static Modint nCr(int n, int r) {\
    \ return nPr(n, r) * _finv[r]; }\n  static Modint nHr(int n, int r) { return !r\
    \ ? Modint(1) : nCr(n + r - 1, r); }\n  static size_t size() { return _inv.size();\
    \ }\n};\ntemplate <class Modint>\nvector<Modint> Combination<Modint>::_fact;\n\
    template <class Modint>\nvector<Modint> Combination<Modint>::_finv;\ntemplate\
    \ <class Modint>\nvector<Modint> Combination<Modint>::_inv;"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Combination.hpp
  requiredBy: []
  timestamp: '2020-08-11 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
documentation_of: src/Math/Combination.hpp
layout: document
redirect_from:
- /library/src/Math/Combination.hpp
- /library/src/Math/Combination.hpp.html
title: "\u7D44\u307F\u5408\u308F\u305B"
---
