---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
    title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc256_f.SegDual.test.cpp
    title: test/atcoder/abc256_f.SegDual.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Dual.hpp\"\n#include <bits/stdc++.h>\n\
    template <typename M> struct SegmentTree_Dual {\n using T= typename M::T;\n using\
    \ E= typename M::E;\n SegmentTree_Dual() {}\n SegmentTree_Dual(int n_, T v1= T()):\
    \ n(n_), height(ceil(log2(n))), val(n, v1), laz(n * 2, {E(), false}) {}\n SegmentTree_Dual(const\
    \ std::vector<T> &v): n(v.size()), height(ceil(log2(n))), val(v), laz(n * 2, {E(),\
    \ false}) {}\n void apply(int a, int b, E x) {\n  a+= n, b+= n;\n  for (int i=\
    \ height; i >= 1; i--)\n   if (((a >> i) << i) != a) eval(a >> i);\n  for (int\
    \ i= height; i >= 1; i--)\n   if (((b >> i) << i) != b) eval((b - 1) >> i);\n\
    \  for (int l= a, r= b; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) propagate(l++,\
    \ x);\n   if (r & 1) propagate(--r, x);\n  }\n }\n void set(int k, T x) {\n  for\
    \ (int i= height; i; i--) eval((k + n) >> i);\n  val[k]= x, laz[k + n].flg= false;\n\
    \ }\n T operator[](const int k) {\n  for (int i= height; i; i--) eval((k + n)\
    \ >> i);\n  if (laz[k + n].flg) M::mapping(val[k], laz[k + n].val), laz[k + n].flg=\
    \ false;\n  return val[k];\n }\nprivate:\n const int n, height;\n struct Lazy\
    \ {\n  E val;\n  bool flg;\n };\n std::vector<T> val;\n std::vector<Lazy> laz;\n\
    \ inline void eval(int k) {\n  if (!laz[k].flg) return;\n  propagate(k << 1 |\
    \ 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n  laz[k].flg= false;\n }\n\
    \ inline void propagate(int k, const E &x) {\n  laz[k].flg ? (M::composition(laz[k].val,\
    \ x), x) : laz[k].val= x;\n  laz[k].flg= true;\n }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <typename M> struct SegmentTree_Dual\
    \ {\n using T= typename M::T;\n using E= typename M::E;\n SegmentTree_Dual() {}\n\
    \ SegmentTree_Dual(int n_, T v1= T()): n(n_), height(ceil(log2(n))), val(n, v1),\
    \ laz(n * 2, {E(), false}) {}\n SegmentTree_Dual(const std::vector<T> &v): n(v.size()),\
    \ height(ceil(log2(n))), val(v), laz(n * 2, {E(), false}) {}\n void apply(int\
    \ a, int b, E x) {\n  a+= n, b+= n;\n  for (int i= height; i >= 1; i--)\n   if\
    \ (((a >> i) << i) != a) eval(a >> i);\n  for (int i= height; i >= 1; i--)\n \
    \  if (((b >> i) << i) != b) eval((b - 1) >> i);\n  for (int l= a, r= b; l < r;\
    \ l>>= 1, r>>= 1) {\n   if (l & 1) propagate(l++, x);\n   if (r & 1) propagate(--r,\
    \ x);\n  }\n }\n void set(int k, T x) {\n  for (int i= height; i; i--) eval((k\
    \ + n) >> i);\n  val[k]= x, laz[k + n].flg= false;\n }\n T operator[](const int\
    \ k) {\n  for (int i= height; i; i--) eval((k + n) >> i);\n  if (laz[k + n].flg)\
    \ M::mapping(val[k], laz[k + n].val), laz[k + n].flg= false;\n  return val[k];\n\
    \ }\nprivate:\n const int n, height;\n struct Lazy {\n  E val;\n  bool flg;\n\
    \ };\n std::vector<T> val;\n std::vector<Lazy> laz;\n inline void eval(int k)\
    \ {\n  if (!laz[k].flg) return;\n  propagate(k << 1 | 0, laz[k].val), propagate(k\
    \ << 1 | 1, laz[k].val);\n  laz[k].flg= false;\n }\n inline void propagate(int\
    \ k, const E &x) {\n  laz[k].flg ? (M::composition(laz[k].val, x), x) : laz[k].val=\
    \ x;\n  laz[k].flg= true;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Dual.hpp
  requiredBy: []
  timestamp: '2023-01-01 00:16:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  - test/atcoder/abc256_f.SegDual.test.cpp
documentation_of: src/DataStructure/SegmentTree_Dual.hpp
layout: document
title: "Segment-Tree(\u53CC\u5BFE)"
---
## 計算量
$\mathcal{O}(\log N)$