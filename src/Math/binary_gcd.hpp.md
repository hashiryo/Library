---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/BinomialCoefficient.hpp
    title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':heavy_check_mark:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt_Exp.hpp
    title: "\u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt"
  - icon: ':question:'
    path: src/Math/Rational.hpp
    title: "\u6709\u7406\u6570 $\\mathbb{Q}$"
  - icon: ':heavy_check_mark:'
    path: src/Math/mod_kth_root.hpp
    title: "k\u4E57\u6839 ($\\mathbb{F}_p$)"
  - icon: ':heavy_check_mark:'
    path: src/Math/mod_tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3 $a\\upuparrows b$ ($\\mathbb{Z}/m\\\
      mathbb{Z}$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0350.test.cpp
    title: test/aoj/0350.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1242.rational.test.cpp
    title: test/aoj/1242.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2003.rational.test.cpp
    title: test/aoj/2003.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2009.rational.test.cpp
    title: test/aoj/2009.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2159.rational.test.cpp
    title: test/aoj/2159.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_e.test.cpp
    title: test/atcoder/abc228_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/constexpr_binary_gcd.test.cpp
    title: test/unit_test/constexpr_binary_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/constexpr_factors.test.cpp
    title: test/unit_test/constexpr_factors.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/constexpr_mod_tetration.test.cpp
    title: test/unit_test/constexpr_mod_tetration.test.cpp
  - icon: ':x:'
    path: test/unit_test/constexpr_rational.test.cpp
    title: test/unit_test/constexpr_rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial_coefficient.test.cpp
    title: test/yosupo/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_root_mod.test.cpp
    title: test/yosupo/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/primitive_root.test.cpp
    title: test/yosupo/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1501.test.cpp
    title: test/yukicoder/1501.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/binary_gcd.hpp\"\n#include <type_traits>\n#include\
    \ <algorithm>\ntemplate <class Int> constexpr int bsf(Int a) {\n if constexpr\
    \ (sizeof(Int) == 16) {\n  uint64_t lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n } else if constexpr (sizeof(Int) == 8) return\
    \ __builtin_ctzll(a);\n else return __builtin_ctz(a);\n}\ntemplate <class Int>\
    \ constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0 || b == 0) return a +\
    \ b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int\
    \ d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n\
    \ }\n return a << std::min(n, m);\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <algorithm>\ntemplate <class\
    \ Int> constexpr int bsf(Int a) {\n if constexpr (sizeof(Int) == 16) {\n  uint64_t\
    \ lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a\
    \ >> 64);\n } else if constexpr (sizeof(Int) == 8) return __builtin_ctzll(a);\n\
    \ else return __builtin_ctz(a);\n}\ntemplate <class Int> constexpr Int binary_gcd(Int\
    \ a, Int b) {\n if (a == 0 || b == 0) return a + b;\n int n= bsf(a), m= bsf(b),\
    \ s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int d= a - b;\n  bool f= a > b;\n\
    \  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n }\n return a << std::min(n,\
    \ m);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/binary_gcd.hpp
  requiredBy:
  - src/Math/ModInt_Exp.hpp
  - src/Math/Factors.hpp
  - src/Math/Rational.hpp
  - src/Math/mod_tetration.hpp
  - src/Math/mod_kth_root.hpp
  - src/Math/BinomialCoefficient.hpp
  timestamp: '2023-08-06 00:46:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2009.rational.test.cpp
  - test/aoj/2003.rational.test.cpp
  - test/aoj/NTL_1_D.test.cpp
  - test/aoj/0350.test.cpp
  - test/aoj/2159.rational.test.cpp
  - test/aoj/1242.rational.test.cpp
  - test/yosupo/kth_root_mod.test.cpp
  - test/yosupo/tetration_mod.test.cpp
  - test/yosupo/primitive_root.test.cpp
  - test/yosupo/factorize.test.cpp
  - test/yosupo/binomial_coefficient.test.cpp
  - test/yukicoder/1501.test.cpp
  - test/atcoder/abc228_e.test.cpp
  - test/unit_test/constexpr_rational.test.cpp
  - test/unit_test/constexpr_mod_tetration.test.cpp
  - test/unit_test/constexpr_binary_gcd.test.cpp
  - test/unit_test/constexpr_factors.test.cpp
documentation_of: src/Math/binary_gcd.hpp
layout: document
title: Binary GCD
---

除算の代わりにシフト演算と引き算を使う速い互除法. \
constexpr で呼べる.

|名前|概要|
|---|---|
|`binary_gcd(a,b)`| 整数 $a,b$ の最大公約数を返す. |