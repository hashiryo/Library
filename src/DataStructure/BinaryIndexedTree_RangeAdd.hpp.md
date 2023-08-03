---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.HLD.test.cpp
    title: test/aoj/2667.HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
    title: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc234_g.test.cpp
    title: test/atcoder/abc234_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc115_e.test.cpp
    title: test/atcoder/arc115_e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n#include\
    \ <vector>\ntemplate <typename T> class BinaryIndexedTree_RangeAdd {\n std::vector<T>\
    \ dat1, dat2;\npublic:\n BinaryIndexedTree_RangeAdd(int n): dat1(n + 1, T()),\
    \ dat2(n + 1, T()) {}\n void add_range(int l, int r, T w) {  // add w [l,r)\n\
    \  int n= dat1.size();\n  for (int k= l + 1; k < n; k+= k & -k) dat1[k]-= w *\
    \ l;\n  for (int k= r + 1; k < n; k+= k & -k) dat1[k]+= w * r;\n  for (int k=\
    \ l + 1; k < n; k+= k & -k) dat2[k]+= w;\n  for (int k= r + 1; k < n; k+= k &\
    \ -k) dat2[k]-= w;\n }\n T sum(int x) const {  // sum [0,x)\n  T s= 0;\n  for\
    \ (int k= x; k; k&= k - 1) s+= dat2[k];\n  s*= x;\n  for (int k= x; k; k&= k -\
    \ 1) s+= dat1[k];\n  return s;\n }\n T sum(int l, int r) const { return sum(r)\
    \ - sum(l); }  // sum [l,r)\n T operator[](size_t k) const { return sum(k + 1)\
    \ - sum(k); }\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T> class BinaryIndexedTree_RangeAdd\
    \ {\n std::vector<T> dat1, dat2;\npublic:\n BinaryIndexedTree_RangeAdd(int n):\
    \ dat1(n + 1, T()), dat2(n + 1, T()) {}\n void add_range(int l, int r, T w) {\
    \  // add w [l,r)\n  int n= dat1.size();\n  for (int k= l + 1; k < n; k+= k &\
    \ -k) dat1[k]-= w * l;\n  for (int k= r + 1; k < n; k+= k & -k) dat1[k]+= w *\
    \ r;\n  for (int k= l + 1; k < n; k+= k & -k) dat2[k]+= w;\n  for (int k= r +\
    \ 1; k < n; k+= k & -k) dat2[k]-= w;\n }\n T sum(int x) const {  // sum [0,x)\n\
    \  T s= 0;\n  for (int k= x; k; k&= k - 1) s+= dat2[k];\n  s*= x;\n  for (int\
    \ k= x; k; k&= k - 1) s+= dat1[k];\n  return s;\n }\n T sum(int l, int r) const\
    \ { return sum(r) - sum(l); }  // sum [l,r)\n T operator[](size_t k) const { return\
    \ sum(k + 1) - sum(k); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  requiredBy: []
  timestamp: '2023-02-10 13:10:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/arc115_e.test.cpp
  - test/atcoder/abc234_g.test.cpp
  - test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
  - test/aoj/2667.HLD.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
layout: document
title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
---
0-indexed
## 計算量
$\mathcal{O}(\log N)$
