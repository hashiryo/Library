---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModIntExp.hpp
    title: "\u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt"
  - icon: ':heavy_check_mark:'
    path: src/Math/tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3 $H_4(a,b) = a\\upuparrows b\
      \ = a^{a^{\\cdot^{\\cdot^{a}}}}$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_e.test.cpp
    title: test/atcoder/abc228_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3030.test.cpp
    title: test/yukicoder/3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 2 \"src/Math/is_prime.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log N)\n\
    \ * constexpr \u3067\u547C\u3079\u308B\n */\n\n// BEGIN CUT HERE\nconstexpr std::uint16_t\
    \ bsf(std::uint64_t n) {\n  constexpr std::uint8_t convert[64] = {\n      0, \
    \ 1,  2,  53, 3,  7,  54, 27, 4,  38, 41, 8,  34, 55, 48, 28,\n      62, 5,  39,\
    \ 46, 44, 42, 22, 9,  24, 35, 59, 56, 49, 18, 29, 11,\n      63, 52, 6,  26, 37,\
    \ 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,\n      51, 25, 36, 32, 60, 20, 57,\
    \ 16, 50, 31, 19, 15, 30, 14, 13, 12};\n  return convert[(n & ~(n - 1)) * 157587932685088877\
    \ >> 58];\n}\nconstexpr std::uint64_t mul(std::uint64_t x, std::uint64_t y, std::uint64_t\
    \ m) {\n  return (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t... args>\n\
    constexpr bool miller_rabin(std::uint64_t n) {\n  const std::uint64_t s = bsf(n\
    \ - 1), d = n >> s;\n  for (auto a : {args...}) {\n    std::uint64_t b = a % n,\
    \ p = 1, i = s;\n    for (std::uint64_t k = d, x = b;; x = mul(x, x, n))\n   \
    \   if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1)) break;\n    while (p != 1 &&\
    \ p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i != s) return\
    \ false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t n) {\n\
    \  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX) return\
    \ miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022>(n);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u7D20\u6570\u5224\
    \u5B9A\n * @category \u6570\u5B66\n *  O(log N)\n * constexpr \u3067\u547C\u3079\
    \u308B\n */\n\n// BEGIN CUT HERE\nconstexpr std::uint16_t bsf(std::uint64_t n)\
    \ {\n  constexpr std::uint8_t convert[64] = {\n      0,  1,  2,  53, 3,  7,  54,\
    \ 27, 4,  38, 41, 8,  34, 55, 48, 28,\n      62, 5,  39, 46, 44, 42, 22, 9,  24,\
    \ 35, 59, 56, 49, 18, 29, 11,\n      63, 52, 6,  26, 37, 40, 33, 47, 61, 45, 43,\
    \ 21, 23, 58, 17, 10,\n      51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30,\
    \ 14, 13, 12};\n  return convert[(n & ~(n - 1)) * 157587932685088877 >> 58];\n\
    }\nconstexpr std::uint64_t mul(std::uint64_t x, std::uint64_t y, std::uint64_t\
    \ m) {\n  return (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t... args>\n\
    constexpr bool miller_rabin(std::uint64_t n) {\n  const std::uint64_t s = bsf(n\
    \ - 1), d = n >> s;\n  for (auto a : {args...}) {\n    std::uint64_t b = a % n,\
    \ p = 1, i = s;\n    for (std::uint64_t k = d, x = b;; x = mul(x, x, n))\n   \
    \   if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1)) break;\n    while (p != 1 &&\
    \ p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i != s) return\
    \ false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t n) {\n\
    \  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX) return\
    \ miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022>(n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/is_prime.hpp
  requiredBy:
  - src/Math/ModIntExp.hpp
  - src/Math/Factors.hpp
  - src/Math/tetration.hpp
  timestamp: '2022-07-04 14:16:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3030.test.cpp
  - test/yosupo/tetration_mod.test.cpp
  - test/yosupo/factorize.test.cpp
  - test/aoj/NTL_1_D.test.cpp
  - test/atcoder/abc228_e.test.cpp
documentation_of: src/Math/is_prime.hpp
layout: document
redirect_from:
- /library/src/Math/is_prime.hpp
- /library/src/Math/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
