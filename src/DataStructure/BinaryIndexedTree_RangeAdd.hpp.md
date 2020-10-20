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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n/**\n\
    \ * @title Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * O(logN)\n * 0-indexed\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\ntemplate <typename T>\n\
    struct BinaryIndexedTree_RangeAdd {\n  vector<T> dat1;\n  vector<T> dat2;\n  BinaryIndexedTree_RangeAdd(int\
    \ n) : dat1(n + 1, T(0)), dat2(n + 1, T(0)) {}\n  void add_range(int l, int r,\
    \ T w) {  // add w [l,r)\n    for (int k = l + 1; k < (int)dat1.size(); k += k\
    \ & -k) dat1[k] -= w * l;\n    for (int k = r + 1; k < (int)dat1.size(); k +=\
    \ k & -k) dat1[k] += w * r;\n    for (int k = l + 1; k < (int)dat2.size(); k +=\
    \ k & -k) dat2[k] += w;\n    for (int k = r + 1; k < (int)dat2.size(); k += k\
    \ & -k) dat2[k] -= w;\n  }\n  T sum(int x) {  // sum [0,x)\n    T s = 0;\n   \
    \ for (int k = x; k > 0; k &= k - 1) s += dat1[k];\n    for (int k = x; k > 0;\
    \ k &= k - 1) s += dat2[k] * x;\n    return s;\n  }\n  // sum [l,r)\n  T sum(int\
    \ l, int r) { return sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k\
    \ + 1) - sum(k); }\n};\n"
  code: "/**\n * @title Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n * 0-indexed\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\ntemplate <typename T>\n\
    struct BinaryIndexedTree_RangeAdd {\n  vector<T> dat1;\n  vector<T> dat2;\n  BinaryIndexedTree_RangeAdd(int\
    \ n) : dat1(n + 1, T(0)), dat2(n + 1, T(0)) {}\n  void add_range(int l, int r,\
    \ T w) {  // add w [l,r)\n    for (int k = l + 1; k < (int)dat1.size(); k += k\
    \ & -k) dat1[k] -= w * l;\n    for (int k = r + 1; k < (int)dat1.size(); k +=\
    \ k & -k) dat1[k] += w * r;\n    for (int k = l + 1; k < (int)dat2.size(); k +=\
    \ k & -k) dat2[k] += w;\n    for (int k = r + 1; k < (int)dat2.size(); k += k\
    \ & -k) dat2[k] -= w;\n  }\n  T sum(int x) {  // sum [0,x)\n    T s = 0;\n   \
    \ for (int k = x; k > 0; k &= k - 1) s += dat1[k];\n    for (int k = x; k > 0;\
    \ k &= k - 1) s += dat2[k] * x;\n    return s;\n  }\n  // sum [l,r)\n  T sum(int\
    \ l, int r) { return sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k\
    \ + 1) - sum(k); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2667.HLD.test.cpp
  - test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
documentation_of: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
layout: document
redirect_from:
- /library/src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
- /library/src/DataStructure/BinaryIndexedTree_RangeAdd.hpp.html
title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
---
