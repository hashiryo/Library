---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/FFT/fps_sqrt.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 sqrt"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_FPS.test.cpp
    title: test/yosupo/sqrt_of_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.test.cpp
    title: test/yukicoder/1080.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u5E73\u65B9\u6839 $\\mathbb{F}_p$"
    links: []
  bundledCode: "#line 2 \"src/Math/mod_sqrt.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u5E73\u65B9\u6839 $\\mathbb{F}_p$\n * @category \u6570\u5B66\n * O(log\
    \ p)\n */\n\n// BEGIN CUT HERE\n\nconstexpr std::int64_t sqrt(std::uint64_t a,\
    \ std::uint64_t p) {\n  if ((a %= p) <= 1 || p == 2) return a;\n  using u64 =\
    \ std::uint64_t;\n  auto pow = [&p](u64 x, u64 k) {\n    for (u64 ret = 1;; x\
    \ = (__uint128_t)x * x % p)\n      if (k & 1 ? ret = (__uint128_t)ret * x % p\
    \ : 0; !(k >>= 1)) return ret;\n  };\n  u64 e = (p - 1) >> 1, b = 0, D = p - a,\
    \ ret = 1, r2 = 0, b2 = 1;\n  if (pow(a, e) != 1) return -1;  // no solution\n\
    \  while (pow(D, e) == 1) D -= p & -((D += (b++ << 1) | 1) >= p);\n  auto mult\
    \ = [&D, &p](u64 &u1, u64 &u2, u64 v1, u64 v2) {\n    u64 tmp = ((__uint128_t)u1\
    \ * v1 + (__uint128_t)u2 * v2 % p * D) % p;\n    u2 = ((__uint128_t)u1 * v2 +\
    \ (__uint128_t)u2 * v1) % p;\n    u1 = tmp - (p & -(tmp >= p)), u2 -= p & -(u2\
    \ >= p);\n  };\n  for (++e;; mult(b, b2, b, b2)) {\n    if (e & 1) mult(ret, r2,\
    \ b, b2);\n    if (!(e >>= 1)) return std::min(ret, p - ret);\n  }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u5E73\u65B9\u6839\
    \ $\\mathbb{F}_p$\n * @category \u6570\u5B66\n * O(log p)\n */\n\n// BEGIN CUT\
    \ HERE\n\nconstexpr std::int64_t sqrt(std::uint64_t a, std::uint64_t p) {\n  if\
    \ ((a %= p) <= 1 || p == 2) return a;\n  using u64 = std::uint64_t;\n  auto pow\
    \ = [&p](u64 x, u64 k) {\n    for (u64 ret = 1;; x = (__uint128_t)x * x % p)\n\
    \      if (k & 1 ? ret = (__uint128_t)ret * x % p : 0; !(k >>= 1)) return ret;\n\
    \  };\n  u64 e = (p - 1) >> 1, b = 0, D = p - a, ret = 1, r2 = 0, b2 = 1;\n  if\
    \ (pow(a, e) != 1) return -1;  // no solution\n  while (pow(D, e) == 1) D -= p\
    \ & -((D += (b++ << 1) | 1) >= p);\n  auto mult = [&D, &p](u64 &u1, u64 &u2, u64\
    \ v1, u64 v2) {\n    u64 tmp = ((__uint128_t)u1 * v1 + (__uint128_t)u2 * v2 %\
    \ p * D) % p;\n    u2 = ((__uint128_t)u1 * v2 + (__uint128_t)u2 * v1) % p;\n \
    \   u1 = tmp - (p & -(tmp >= p)), u2 -= p & -(u2 >= p);\n  };\n  for (++e;; mult(b,\
    \ b2, b, b2)) {\n    if (e & 1) mult(ret, r2, b, b2);\n    if (!(e >>= 1)) return\
    \ std::min(ret, p - ret);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/mod_sqrt.hpp
  requiredBy:
  - src/FFT/fps_sqrt.hpp
  timestamp: '2022-09-20 01:41:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/sqrt_of_FPS.test.cpp
  - test/yukicoder/1080.test.cpp
documentation_of: src/Math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/src/Math/mod_sqrt.hpp
- /library/src/Math/mod_sqrt.hpp.html
title: "\u5E73\u65B9\u6839 $\\mathbb{F}_p$"
---
