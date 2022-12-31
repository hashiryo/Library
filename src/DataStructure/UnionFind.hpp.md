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
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <bits/stdc++.h>\n\
    struct UnionFind {\n std::vector<int> par;\n UnionFind(int size): par(size, -1)\
    \ {}\n bool unite(int u, int v) {\n  if ((u= root(u)) == (v= root(v))) return\
    \ false;\n  if (par[u] > par[v]) std::swap(u, v);\n  return par[u]+= par[v], par[v]=\
    \ u, true;\n }\n bool same(int u, int v) { return root(u) == root(v); }\n int\
    \ root(int u) { return par[u] < 0 ? u : par[u]= root(par[u]); }\n int size(int\
    \ u) { return -par[root(u)]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nstruct UnionFind {\n std::vector<int>\
    \ par;\n UnionFind(int size): par(size, -1) {}\n bool unite(int u, int v) {\n\
    \  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u,\
    \ v);\n  return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u, int v)\
    \ { return root(u) == root(v); }\n int root(int u) { return par[u] < 0 ? u : par[u]=\
    \ root(par[u]); }\n int size(int u) { return -par[root(u)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  - src/Graph/MinimumSpanningTree_Kruskal.hpp
  timestamp: '2022-12-31 22:54:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0342.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
title: Union-Find
---
 * `unite(x,y)` x が入っている集合と y が入っている集合を併合する．
 * `same(x,y)` x と y が同じ集合に入っているかどうかを判定する．
## 計算量
$\mathcal{O}(\alpha(N))$
