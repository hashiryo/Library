---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc018_c.test.cpp
    title: test/atcoder/agc018_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "L\u51F8\u95A2\u6570\u6700\u5C0F\u5316(\u30B9\u30B1\u30FC\u30EA\
      \u30F3\u30B0\u6CD5)"
    links:
    - https://opt-cp.com/agc018c-lconvex/#toc11
  bundledCode: "#line 2 \"src/Algorithm/min_Lconvex.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title L\u51F8\u95A2\u6570\u6700\u5C0F\u5316(\u30B9\u30B1\u30FC\u30EA\u30F3\
    \u30B0\u6CD5)\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(2^n n^2\
    \ log (K/n)) * EVAL\n * @see https://opt-cp.com/agc018c-lconvex/#toc11\n */\n\n\
    // BEGIN CUT HERE\n\ntemplate <typename TD, typename TR, class F>\nstd::pair<TR,\
    \ std::vector<TD>> min_Lconvex(const F &f, std::vector<TD> x,\n              \
    \                             TD alpha) {\n  TR f0 = f(x), f1 = f0, fS;\n  for\
    \ (int n = x.size(); alpha; f0 == f1 ? alpha >>= 1 : f0 = f1) {\n    std::vector<TD>\
    \ x0{x};\n    for (int S = 1; S < (1 << n) - 1; S++) {\n      std::vector<TD>\
    \ xS{x0};\n      for (int i = 0; i < n; i++)\n        if ((S >> i) & 1) xS[i]\
    \ += alpha;\n      if ((fS = f(xS)) < f1) f1 = fS, x = std::move(xS);\n    }\n\
    \  }\n  return {f1, std::move(x)};\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title L\u51F8\u95A2\u6570\
    \u6700\u5C0F\u5316(\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\u6CD5)\n * @category \u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(2^n n^2 log (K/n)) * EVAL\n * @see https://opt-cp.com/agc018c-lconvex/#toc11\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename TD, typename TR, class F>\nstd::pair<TR,\
    \ std::vector<TD>> min_Lconvex(const F &f, std::vector<TD> x,\n              \
    \                             TD alpha) {\n  TR f0 = f(x), f1 = f0, fS;\n  for\
    \ (int n = x.size(); alpha; f0 == f1 ? alpha >>= 1 : f0 = f1) {\n    std::vector<TD>\
    \ x0{x};\n    for (int S = 1; S < (1 << n) - 1; S++) {\n      std::vector<TD>\
    \ xS{x0};\n      for (int i = 0; i < n; i++)\n        if ((S >> i) & 1) xS[i]\
    \ += alpha;\n      if ((fS = f(xS)) < f1) f1 = fS, x = std::move(xS);\n    }\n\
    \  }\n  return {f1, std::move(x)};\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Algorithm/min_Lconvex.hpp
  requiredBy: []
  timestamp: '2021-12-05 20:13:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/agc018_c.test.cpp
documentation_of: src/Algorithm/min_Lconvex.hpp
layout: document
redirect_from:
- /library/src/Algorithm/min_Lconvex.hpp
- /library/src/Algorithm/min_Lconvex.hpp.html
title: "L\u51F8\u95A2\u6570\u6700\u5C0F\u5316(\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\
  \u6CD5)"
---
