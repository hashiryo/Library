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
    document_title: "Binary-Indexed-Tree(2\u6B21\u5143)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BinaryIndexedTree_2D.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Binary-Indexed-Tree(2\u6B21\u5143)\n * @category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * O(logHW)\n * 1-indexed\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename T>\nstruct BinaryIndexedTree_2D {\n  using vT = std::vector<T>;\n\
    \  std::vector<vT> dat;\n  BinaryIndexedTree_2D(int H, int W)\n      : dat(std::vector<vT>(H\
    \ + 1, vT(W + 1, T(0)))) {}\n  void add(int y, int x, T v) {\n    for (int i =\
    \ y; i < (int)dat.size(); i += i & -i)\n      for (int j = x; j < (int)dat[i].size();\
    \ j += j & -j) dat[i][j] += v;\n  }\n  T sum(int y, int x) {  // sum (0,y] * (0,x]\n\
    \    T ret = 0;\n    for (int i = y; i > 0; i -= i & -i)\n      for (int j = x;\
    \ j > 0; j -= j & -j) ret += dat[i][j];\n    return ret;\n  }\n  T sum(int sy,\
    \ int sx, int ty, int tx) {  // sum (sy,ty] * (sx,tx]\n    return sum(ty, tx)\
    \ - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Binary-Indexed-Tree(2\u6B21\
    \u5143)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logHW)\n * 1-indexed\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nstruct BinaryIndexedTree_2D\
    \ {\n  using vT = std::vector<T>;\n  std::vector<vT> dat;\n  BinaryIndexedTree_2D(int\
    \ H, int W)\n      : dat(std::vector<vT>(H + 1, vT(W + 1, T(0)))) {}\n  void add(int\
    \ y, int x, T v) {\n    for (int i = y; i < (int)dat.size(); i += i & -i)\n  \
    \    for (int j = x; j < (int)dat[i].size(); j += j & -j) dat[i][j] += v;\n  }\n\
    \  T sum(int y, int x) {  // sum (0,y] * (0,x]\n    T ret = 0;\n    for (int i\
    \ = y; i > 0; i -= i & -i)\n      for (int j = x; j > 0; j -= j & -j) ret += dat[i][j];\n\
    \    return ret;\n  }\n  T sum(int sy, int sx, int ty, int tx) {  // sum (sy,ty]\
    \ * (sx,tx]\n    return sum(ty, tx) - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree_2D.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842.BIT_2D.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree_2D.hpp
layout: document
redirect_from:
- /library/src/DataStructure/BinaryIndexedTree_2D.hpp
- /library/src/DataStructure/BinaryIndexedTree_2D.hpp.html
title: "Binary-Indexed-Tree(2\u6B21\u5143)"
---
