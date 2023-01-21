---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.BIT_2D.test.cpp
    title: test/aoj/2842.BIT_2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BinaryIndexedTree_2D.hpp\"\n#include <vector>\n\
    template <typename T> struct BinaryIndexedTree_2D {\n std::vector<std::vector<T>>\
    \ dat;\n BinaryIndexedTree_2D(int H, int W): dat(std::vector(H + 1, std::vector(W\
    \ + 1, T()))) {}\n void add(int y, int x, T v) {\n  for (int i= y, e= dat.size();\
    \ i < e; i+= i & -i)\n   for (int j= x, f= dat[i].size(); j < f; j+= j & -j) dat[i][j]+=\
    \ v;\n }\n T sum(int y, int x) const {  // sum (0,y] * (0,x]\n  T ret= 0;\n  for\
    \ (int i= y; i; i-= i & -i)\n   for (int j= x; j; j-= j & -j) ret+= dat[i][j];\n\
    \  return ret;\n }\n T sum(int sy, int sx, int ty, int tx) const {  // sum (sy,ty]\
    \ * (sx,tx]\n  return sum(ty, tx) - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);\n\
    \ }\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T> struct BinaryIndexedTree_2D\
    \ {\n std::vector<std::vector<T>> dat;\n BinaryIndexedTree_2D(int H, int W): dat(std::vector(H\
    \ + 1, std::vector(W + 1, T()))) {}\n void add(int y, int x, T v) {\n  for (int\
    \ i= y, e= dat.size(); i < e; i+= i & -i)\n   for (int j= x, f= dat[i].size();\
    \ j < f; j+= j & -j) dat[i][j]+= v;\n }\n T sum(int y, int x) const {  // sum\
    \ (0,y] * (0,x]\n  T ret= 0;\n  for (int i= y; i; i-= i & -i)\n   for (int j=\
    \ x; j; j-= j & -j) ret+= dat[i][j];\n  return ret;\n }\n T sum(int sy, int sx,\
    \ int ty, int tx) const {  // sum (sy,ty] * (sx,tx]\n  return sum(ty, tx) - sum(ty,\
    \ sx) - sum(sy, tx) + sum(sy, sx);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree_2D.hpp
  requiredBy: []
  timestamp: '2023-01-21 19:30:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842.BIT_2D.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree_2D.hpp
layout: document
title: "Binary-Indexed-Tree(2\u6B21\u5143)"
---
1-indexed
## 計算量
$\mathcal{O}(\log HW)$
