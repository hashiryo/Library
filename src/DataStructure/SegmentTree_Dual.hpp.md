---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc256_f.SegDual.cpp
    title: test/atcoder/abc256_f.SegDual.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
    title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Segment-Tree(\u53CC\u5BFE)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Dual.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct SegmentTree_Dual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n      : n(n_),\n\
    \        height(ceil(log2(n))),\n        val(n, v1),\n        laz(n * 2),\n  \
    \      laz_flg(n * 2, false) {}\n  SegmentTree_Dual(const std::vector<T> &v)\n\
    \      : n(v.size()),\n        height(ceil(log2(n))),\n        val(v),\n     \
    \   laz(n * 2),\n        laz_flg(n * 2, false) {}\n  void apply(int a, int b,\
    \ E x) {\n    a += n, b += n;\n    for (int i = height; i >= 1; i--)\n      if\
    \ (((a >> i) << i) != a) eval(a >> i);\n    for (int i = height; i >= 1; i--)\n\
    \      if (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l = a, r =\
    \ b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n      if\
    \ (r & 1) propagate(--r, x);\n    }\n  }\n  void set(int k, T x) {\n    for (int\
    \ i = height; i; i--) eval((k + n) >> i);\n    val[k] = x, laz_flg[k + n] = false;\n\
    \  }\n  T operator[](const int k) {\n    for (int i = height; i; i--) eval(k >>\
    \ i);\n    if (laz_flg[k + n])\n      val[k] = M::mapping(val[k], laz[k + n]),\
    \ laz_flg[k + n] = false;\n    return val[k];\n  }\n\n private:\n  const int n,\
    \ height;\n  std::vector<T> val;\n  std::vector<E> laz;\n  std::vector<char> laz_flg;\n\
    \  inline void eval(int k) {\n    if (!laz_flg[k]) return;\n    propagate(k <<\
    \ 1 | 0, laz[k]), propagate(k << 1 | 1, laz[k]);\n    laz_flg[k] = false;\n  }\n\
    \  inline void propagate(int k, const E &x) {\n    laz[k] = laz_flg[k] ? M::composition(laz[k],\
    \ x) : x, laz_flg[k] = true;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree(\u53CC\
    \u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree_Dual {\n  using\
    \ T = typename M::T;\n  using E = typename M::E;\n  SegmentTree_Dual() {}\n  SegmentTree_Dual(int\
    \ n_, T v1 = T())\n      : n(n_),\n        height(ceil(log2(n))),\n        val(n,\
    \ v1),\n        laz(n * 2),\n        laz_flg(n * 2, false) {}\n  SegmentTree_Dual(const\
    \ std::vector<T> &v)\n      : n(v.size()),\n        height(ceil(log2(n))),\n \
    \       val(v),\n        laz(n * 2),\n        laz_flg(n * 2, false) {}\n  void\
    \ apply(int a, int b, E x) {\n    a += n, b += n;\n    for (int i = height; i\
    \ >= 1; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n    for (int i =\
    \ height; i >= 1; i--)\n      if (((b >> i) << i) != b) eval((b - 1) >> i);\n\
    \    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++,\
    \ x);\n      if (r & 1) propagate(--r, x);\n    }\n  }\n  void set(int k, T x)\
    \ {\n    for (int i = height; i; i--) eval((k + n) >> i);\n    val[k] = x, laz_flg[k\
    \ + n] = false;\n  }\n  T operator[](const int k) {\n    for (int i = height;\
    \ i; i--) eval(k >> i);\n    if (laz_flg[k + n])\n      val[k] = M::mapping(val[k],\
    \ laz[k + n]), laz_flg[k + n] = false;\n    return val[k];\n  }\n\n private:\n\
    \  const int n, height;\n  std::vector<T> val;\n  std::vector<E> laz;\n  std::vector<char>\
    \ laz_flg;\n  inline void eval(int k) {\n    if (!laz_flg[k]) return;\n    propagate(k\
    \ << 1 | 0, laz[k]), propagate(k << 1 | 1, laz[k]);\n    laz_flg[k] = false;\n\
    \  }\n  inline void propagate(int k, const E &x) {\n    laz[k] = laz_flg[k] ?\
    \ M::composition(laz[k], x) : x, laz_flg[k] = true;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Dual.hpp
  requiredBy:
  - test/atcoder/abc256_f.SegDual.cpp
  timestamp: '2022-06-19 22:48:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_D.SegTree_Dual.test.cpp
documentation_of: src/DataStructure/SegmentTree_Dual.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Dual.hpp
- /library/src/DataStructure/SegmentTree_Dual.hpp.html
title: "Segment-Tree(\u53CC\u5BFE)"
---
