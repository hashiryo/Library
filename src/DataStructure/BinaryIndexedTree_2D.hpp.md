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
    template <typename T> struct BinaryIndexedTree_2D {\n const int h, w;\n std::vector<T>\
    \ dat;\n BinaryIndexedTree_2D(int H, int W): h(H + 1), w(W + 1), dat(h * w, T())\
    \ {}\n void add(int y, int x, T v) {\n  for (int i= y; i < h; i+= i & -i)\n  \
    \ for (int j= x, I= i * w; j < w; j+= j & -j) dat[I + j]+= v;\n }\n T sum(int\
    \ y, int x) const {  // sum (0,y] * (0,x]\n  T ret= 0;\n  for (int i= y; i; i-=\
    \ i & -i)\n   for (int j= x, I= i * w; j; j-= j & -j) ret+= dat[I + j];\n  return\
    \ ret;\n }\n T sum(int sy, int sx, int ty, int tx) const {  // sum (sy,ty] * (sx,tx]\n\
    \  return sum(ty, tx) - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);\n }\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T> struct BinaryIndexedTree_2D\
    \ {\n const int h, w;\n std::vector<T> dat;\n BinaryIndexedTree_2D(int H, int\
    \ W): h(H + 1), w(W + 1), dat(h * w, T()) {}\n void add(int y, int x, T v) {\n\
    \  for (int i= y; i < h; i+= i & -i)\n   for (int j= x, I= i * w; j < w; j+= j\
    \ & -j) dat[I + j]+= v;\n }\n T sum(int y, int x) const {  // sum (0,y] * (0,x]\n\
    \  T ret= 0;\n  for (int i= y; i; i-= i & -i)\n   for (int j= x, I= i * w; j;\
    \ j-= j & -j) ret+= dat[I + j];\n  return ret;\n }\n T sum(int sy, int sx, int\
    \ ty, int tx) const {  // sum (sy,ty] * (sx,tx]\n  return sum(ty, tx) - sum(ty,\
    \ sx) - sum(sy, tx) + sum(sy, sx);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree_2D.hpp
  requiredBy: []
  timestamp: '2023-02-10 14:46:13+09:00'
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
