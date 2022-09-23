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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.BIT.test.cpp
    title: test/yukicoder/649.BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/738.BIT.test.cpp
    title: test/yukicoder/738.BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary-Indexed-Tree
    links: []
  bundledCode: "#line 2 \"src/DataStructure/BinaryIndexedTree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Binary-Indexed-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n *  O(logN)\n *  0-indexed\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\n\
    struct BinaryIndexedTree {\n  std::vector<T> dat;\n  BinaryIndexedTree(int n)\
    \ : dat(n + 1, T(0)) {}\n  BinaryIndexedTree(int n, T a) : BinaryIndexedTree(std::vector<T>(n,\
    \ a)) {}\n  BinaryIndexedTree(std::vector<T> y) : dat(y.size() + 1, 0) {\n   \
    \ for (size_t i = 0; i < y.size(); ++i) dat[i + 1] = y[i];\n    for (int i = 1;\
    \ i < (int)dat.size(); ++i)\n      if (i + (i & -i) < (int)dat.size()) dat[i +\
    \ (i & -i)] += dat[i];\n  }\n  void add(int i, T a = 1) {\n    for (++i; i < (int)dat.size();\
    \ i += i & -i) dat[i] += a;\n  }\n  T sum(int i) {  // sum [0,i)\n    T s = 0;\n\
    \    for (; i > 0; i &= i - 1) s += dat[i];\n    return s;\n  }\n  // sum [l,r)\n\
    \  T sum(int l, int r) { return sum(r) - sum(l); }\n  T operator[](size_t k) {\
    \ return sum(k + 1) - sum(k); }\n  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n\
    \  int find(T k) const {\n    int i = 0;\n    for (int p = 1 << (std::__lg(dat.size()\
    \ - 1) + 1); p > 0; p >>= 1)\n      if (i + p < (int)dat.size() && dat[i + p]\
    \ <= k) k -= dat[i += p];\n    return i + 1 == (int)dat.size() ? -1 : i;  // -1\
    \ -> no solutions\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Binary-Indexed-Tree\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *  O(logN)\n *  0-indexed\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  std::vector<T>\
    \ dat;\n  BinaryIndexedTree(int n) : dat(n + 1, T(0)) {}\n  BinaryIndexedTree(int\
    \ n, T a) : BinaryIndexedTree(std::vector<T>(n, a)) {}\n  BinaryIndexedTree(std::vector<T>\
    \ y) : dat(y.size() + 1, 0) {\n    for (size_t i = 0; i < y.size(); ++i) dat[i\
    \ + 1] = y[i];\n    for (int i = 1; i < (int)dat.size(); ++i)\n      if (i + (i\
    \ & -i) < (int)dat.size()) dat[i + (i & -i)] += dat[i];\n  }\n  void add(int i,\
    \ T a = 1) {\n    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;\n \
    \ }\n  T sum(int i) {  // sum [0,i)\n    T s = 0;\n    for (; i > 0; i &= i -\
    \ 1) s += dat[i];\n    return s;\n  }\n  // sum [l,r)\n  T sum(int l, int r) {\
    \ return sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k + 1) - sum(k);\
    \ }\n  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n  int find(T k)\
    \ const {\n    int i = 0;\n    for (int p = 1 << (std::__lg(dat.size() - 1) +\
    \ 1); p > 0; p >>= 1)\n      if (i + p < (int)dat.size() && dat[i + p] <= k) k\
    \ -= dat[i += p];\n    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no\
    \ solutions\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2020-11-07 15:26:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/738.BIT.test.cpp
  - test/yukicoder/649.BIT.test.cpp
  - test/yosupo/point_add_range_sum.BIT.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/BinaryIndexedTree.hpp
- /library/src/DataStructure/BinaryIndexedTree.hpp.html
title: Binary-Indexed-Tree
---
