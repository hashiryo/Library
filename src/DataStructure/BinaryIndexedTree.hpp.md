---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.BIT.test.cpp
    title: test/yosupo/point_add_range_sum.BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.mo.test.cpp
    title: test/yosupo/static_range_inversions_query.mo.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.BIT.test.cpp
    title: test/yukicoder/649.BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/738.BIT.test.cpp
    title: test/yukicoder/738.BIT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BinaryIndexedTree.hpp\"\n#include <algorithm>\n\
    #include <vector>\ntemplate <typename T> class BinaryIndexedTree {\n std::vector<T>\
    \ dat;\npublic:\n BinaryIndexedTree(int n): dat(n + 1, T()) {}\n BinaryIndexedTree(int\
    \ n, T a): BinaryIndexedTree(std::vector<T>(n, a)) {}\n BinaryIndexedTree(const\
    \ std::vector<T>& y): dat(y.size() + 1, 0) {\n  for (int i= y.size(); i--;) dat[i\
    \ + 1]= y[i];\n  for (int i= 1, e= dat.size(), j; i < e; ++i)\n   if ((j= i +\
    \ (i & -i)) < e) dat[j]+= dat[i];\n }\n void add(int i, T a= 1) {\n  for (++i;\
    \ i < (int)dat.size(); i+= i & -i) dat[i]+= a;\n }\n T sum(int i) const {  //\
    \ sum [0,i)\n  T s= 0;\n  for (; i; i&= i - 1) s+= dat[i];\n  return s;\n }\n\
    \ T sum(int l, int r) const { return sum(r) - sum(l); }  // sum [l,r)\n T operator[](int\
    \ k) const { return sum(k + 1) - sum(k); }\n int find(T k) const {  // min { i\
    \ : sum(i+1) > k } -> kth element(0-indexed)\n  int i= 0;\n  for (int p= 1 <<\
    \ (std::__lg(dat.size() - 1) + 1), e= dat.size(); p; p>>= 1)\n   if (i + p < e\
    \ && dat[i + p] <= k) k-= dat[i+= p];\n  return i + 1 == (int)dat.size() ? -1\
    \ : i;  // -1 -> no solutions\n }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\ntemplate <typename\
    \ T> class BinaryIndexedTree {\n std::vector<T> dat;\npublic:\n BinaryIndexedTree(int\
    \ n): dat(n + 1, T()) {}\n BinaryIndexedTree(int n, T a): BinaryIndexedTree(std::vector<T>(n,\
    \ a)) {}\n BinaryIndexedTree(const std::vector<T>& y): dat(y.size() + 1, 0) {\n\
    \  for (int i= y.size(); i--;) dat[i + 1]= y[i];\n  for (int i= 1, e= dat.size(),\
    \ j; i < e; ++i)\n   if ((j= i + (i & -i)) < e) dat[j]+= dat[i];\n }\n void add(int\
    \ i, T a= 1) {\n  for (++i; i < (int)dat.size(); i+= i & -i) dat[i]+= a;\n }\n\
    \ T sum(int i) const {  // sum [0,i)\n  T s= 0;\n  for (; i; i&= i - 1) s+= dat[i];\n\
    \  return s;\n }\n T sum(int l, int r) const { return sum(r) - sum(l); }  // sum\
    \ [l,r)\n T operator[](int k) const { return sum(k + 1) - sum(k); }\n int find(T\
    \ k) const {  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n  int i=\
    \ 0;\n  for (int p= 1 << (std::__lg(dat.size() - 1) + 1), e= dat.size(); p; p>>=\
    \ 1)\n   if (i + p < e && dat[i + p] <= k) k-= dat[i+= p];\n  return i + 1 ==\
    \ (int)dat.size() ? -1 : i;  // -1 -> no solutions\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-01-21 16:53:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/738.BIT.test.cpp
  - test/yukicoder/649.BIT.test.cpp
  - test/yukicoder/1270.test.cpp
  - test/yosupo/point_add_range_sum.BIT.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree.hpp
layout: document
title: Binary-Indexed-Tree
---
0-indexed
## 計算量
$\mathcal{O}(\log N)$
