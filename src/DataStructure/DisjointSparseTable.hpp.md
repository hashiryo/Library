---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
    title: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Disjoint-Sparse-Table
    links: []
  bundledCode: "#line 1 \"src/DataStructure/DisjointSparseTable.hpp\"\n/**\n * @title\
    \ Disjoint-Sparse-Table\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ f\u306F\u7D50\u5408\u5247\u3092\u307F\u305F\u3059\u4E8C\u9805\u6F14\u7B97\n\
    \ * @brief \u69CB\u7BC9 O(n log n)\n * @brief query O(1)\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\ntemplate <class T>\n\
    struct DisjointSparseTable {\n  vector<vector<T>> ys;\n  using F = function<T(T,\
    \ T)>;\n  const F f;\n  DisjointSparseTable(vector<T> xs, F f_) : f(f_) {\n  \
    \  int n = 1;\n    while (n <= xs.size()) n *= 2;\n    xs.resize(n);\n    ys.push_back(xs);\n\
    \    for (int h = 1;; ++h) {\n      int range = (2 << h), half = range / 2;\n\
    \      if (range > n) break;\n      ys.push_back(xs);\n      for (int i = half;\
    \ i < n; i += range) {\n        for (int j = i - 2; j >= i - half; --j)\n    \
    \      ys[h][j] = f(ys[h][j], ys[h][j + 1]);\n        for (int j = i + 1; j <\
    \ min(n, i + half); ++j)\n          ys[h][j] = f(ys[h][j - 1], ys[h][j]);\n  \
    \    }\n    }\n  }\n  T query(int i, int j) {  // [i, j)\n    if (i == --j) return\
    \ ys[0][i];\n    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(i ^ j);\n\
    \    return f(ys[h][i], ys[h][j]);\n  }\n};\n"
  code: "/**\n * @title Disjoint-Sparse-Table\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief f\u306F\u7D50\u5408\u5247\u3092\u307F\u305F\u3059\u4E8C\u9805\
    \u6F14\u7B97\n * @brief \u69CB\u7BC9 O(n log n)\n * @brief query O(1)\n */\n\n\
    #ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \ntemplate <class T>\nstruct DisjointSparseTable {\n  vector<vector<T>> ys;\n\
    \  using F = function<T(T, T)>;\n  const F f;\n  DisjointSparseTable(vector<T>\
    \ xs, F f_) : f(f_) {\n    int n = 1;\n    while (n <= xs.size()) n *= 2;\n  \
    \  xs.resize(n);\n    ys.push_back(xs);\n    for (int h = 1;; ++h) {\n      int\
    \ range = (2 << h), half = range / 2;\n      if (range > n) break;\n      ys.push_back(xs);\n\
    \      for (int i = half; i < n; i += range) {\n        for (int j = i - 2; j\
    \ >= i - half; --j)\n          ys[h][j] = f(ys[h][j], ys[h][j + 1]);\n       \
    \ for (int j = i + 1; j < min(n, i + half); ++j)\n          ys[h][j] = f(ys[h][j\
    \ - 1], ys[h][j]);\n      }\n    }\n  }\n  T query(int i, int j) {  // [i, j)\n\
    \    if (i == --j) return ys[0][i];\n    int h = sizeof(int) * __CHAR_BIT__ -\
    \ 1 - __builtin_clz(i ^ j);\n    return f(ys[h][i], ys[h][j]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2020-08-11 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2644.test.cpp
  - test/aoj/DSL_3_D.disjointsparsetable.test.cpp
documentation_of: src/DataStructure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/src/DataStructure/DisjointSparseTable.hpp
- /library/src/DataStructure/DisjointSparseTable.hpp.html
title: Disjoint-Sparse-Table
---
