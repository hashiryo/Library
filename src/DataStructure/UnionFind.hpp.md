---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningTree_Kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Union-Find
    links: []
  bundledCode: "#line 1 \"src/DataStructure/UnionFind.hpp\"\n/**\n * @title Union-Find\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief unite(x,y) x \u304C\u5165\
    \u3063\u3066\u3044\u308B\u96C6\u5408\u3068 y \u304C\u5165\u3063\u3066\u3044\u308B\
    \u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\uFF0E\n * @brief same(x,y) x \u3068\
    \ y \u304C\u540C\u3058\u96C6\u5408\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\uFF0E\n * @brief O(\u03B1(N))\n */\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \nstruct UnionFind {\n  vector<int> par;\n  UnionFind(int size) : par(size, -1)\
    \ {}\n  bool unite(int u, int v) {\n    if ((u = root(u)) == (v = root(v))) return\
    \ false;\n    if (par[u] > par[v]) swap(u, v);\n    par[u] += par[v], par[v] =\
    \ u;\n    return true;\n  }\n  bool same(int u, int v) { return root(u) == root(v);\
    \ }\n  int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }\n  int\
    \ size(int u) { return -par[root(u)]; }\n};\n"
  code: "/**\n * @title Union-Find\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @brief unite(x,y) x \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3068\
    \ y \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\
    \uFF0E\n * @brief same(x,y) x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5165\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \uFF0E\n * @brief O(\u03B1(N))\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\nstruct UnionFind {\n  vector<int> par;\n  UnionFind(int\
    \ size) : par(size, -1) {}\n  bool unite(int u, int v) {\n    if ((u = root(u))\
    \ == (v = root(v))) return false;\n    if (par[u] > par[v]) swap(u, v);\n    par[u]\
    \ += par[v], par[v] = u;\n    return true;\n  }\n  bool same(int u, int v) { return\
    \ root(u) == root(v); }\n  int root(int u) { return par[u] < 0 ? u : par[u] =\
    \ root(par[u]); }\n  int size(int u) { return -par[root(u)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  - src/Graph/MinimumSpanningTree_Kruskal.hpp
  timestamp: '2020-08-11 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/0342.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind.hpp
- /library/src/DataStructure/UnionFind.hpp.html
title: Union-Find
---
