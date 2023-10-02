---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Geometry/min_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186"
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  _extendedVerifiedWith:
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
    path: test/aoj/2614.rollinghash.test.cpp
    title: test/aoj/2614.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.rollinghash.test.cpp
    title: test/aoj/2711.rollinghash.test.cpp
  - icon: ':x:'
    path: test/aoj/3034.test.cpp
    title: test/aoj/3034.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/z_algorithm.rollinghash.test.cpp
    title: test/yosupo/z_algorithm.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/rng.hpp\"\n#include <random>\nuint64_t rng() {\n\
    \ static uint64_t x= 10150724397891781847ULL * std::random_device{}();\n return\
    \ x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t lim) { return rng() % lim;\
    \ }\nint64_t rng(int64_t l, int64_t r) { return l + rng() % (r - l); }\n"
  code: "#pragma once\n#include <random>\nuint64_t rng() {\n static uint64_t x= 10150724397891781847ULL\
    \ * std::random_device{}();\n return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t\
    \ lim) { return rng() % lim; }\nint64_t rng(int64_t l, int64_t r) { return l +\
    \ rng() % (r - l); }"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/rng.hpp
  requiredBy:
  - src/Geometry/min_enclosing_circle.hpp
  - src/LinearAlgebra/MinimalPolynomial.hpp
  timestamp: '2023-03-12 01:58:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2711.rollinghash.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/aoj/2614.rollinghash.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - test/aoj/3034.test.cpp
  - test/yosupo/z_algorithm.rollinghash.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yukicoder/310.test.cpp
documentation_of: src/Misc/rng.hpp
layout: document
title: "\u7591\u4F3C\u4E71\u6570"
---
## 参考
[https://ja.wikipedia.org/wiki/Xorshift](https://ja.wikipedia.org/wiki/Xorshift)