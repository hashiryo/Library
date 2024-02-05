---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/min_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186"
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0322.RH.test.cpp
    title: test/aoj/0322.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.MinPoly.test.cpp
    title: test/aoj/2397.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.RH.test.cpp
    title: test/aoj/2614.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.RH.test.cpp
    title: test/aoj/2711.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2763.RH.test.cpp
    title: test/aoj/2763.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034.test.cpp
    title: test/aoj/3034.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.RH.test.cpp
    title: test/aoj/ALDS1_14_B.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc135_f.RH.test.cpp
    title: test/atcoder/abc135_f.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc141_e.RH.test.cpp
    title: test/atcoder/abc141_e.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc150_f.RH.Nimber.test.cpp
    title: test/atcoder/abc150_f.RH.Nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc272_f.RH.test.cpp
    title: test/atcoder/abc272_f.RH.test.cpp
  - icon: ':x:'
    path: test/atcoder/agc047_b.RH.test.cpp
    title: test/atcoder/agc047_b.RH.test.cpp
  - icon: ':x:'
    path: test/yosupo/enumerate_palindromes.RH.test.cpp
    title: test/yosupo/enumerate_palindromes.RH.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/z_algorithm.RH.test.cpp
    title: test/yosupo/z_algorithm.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2332.RH.test.cpp
    title: test/yukicoder/2332.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2454.RH.test.cpp
    title: test/yukicoder/2454.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  - icon: ':x:'
    path: test/yukicoder/599.RH.test.cpp
    title: test/yukicoder/599.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/765.RH.test.cpp
    title: test/yukicoder/765.RH.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/rng.hpp\"\n#include <random>\n#include <cstdint>\n\
    uint64_t rng() {\n static uint64_t x= 10150724397891781847ULL * std::random_device{}();\n\
    \ return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t lim) { return rng()\
    \ % lim; }\nint64_t rng(int64_t l, int64_t r) { return l + rng() % (r - l); }\n"
  code: "#pragma once\n#include <random>\n#include <cstdint>\nuint64_t rng() {\n static\
    \ uint64_t x= 10150724397891781847ULL * std::random_device{}();\n return x^= x\
    \ << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t lim) { return rng() % lim; }\nint64_t\
    \ rng(int64_t l, int64_t r) { return l + rng() % (r - l); }"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/rng.hpp
  requiredBy:
  - src/Geometry/min_enclosing_circle.hpp
  - src/LinearAlgebra/MinimalPolynomial.hpp
  timestamp: '2023-11-17 11:57:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yukicoder/310.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
  - test/yukicoder/2332.RH.test.cpp
  - test/yukicoder/2454.RH.test.cpp
  - test/yukicoder/765.RH.test.cpp
  - test/yukicoder/599.RH.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
  - test/aoj/ALDS1_14_B.RH.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/2711.RH.test.cpp
  - test/aoj/2614.RH.test.cpp
  - test/aoj/2763.RH.test.cpp
  - test/aoj/0322.RH.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/aoj/3034.test.cpp
  - test/aoj/0355.test.cpp
  - test/atcoder/abc150_f.RH.Nimber.test.cpp
  - test/atcoder/abc135_f.RH.test.cpp
  - test/atcoder/abc272_f.RH.test.cpp
  - test/atcoder/agc047_b.RH.test.cpp
  - test/atcoder/abc141_e.RH.test.cpp
  - test/yosupo/z_algorithm.RH.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/enumerate_palindromes.RH.test.cpp
documentation_of: src/Misc/rng.hpp
layout: document
title: "\u7591\u4F3C\u4E71\u6570"
---
## 参考
[https://ja.wikipedia.org/wiki/Xorshift](https://ja.wikipedia.org/wiki/Xorshift)