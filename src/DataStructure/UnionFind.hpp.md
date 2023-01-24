---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/IncrementalBridgeConnectivity.hpp
    title: "Incremental-Bridge-Connectivity (2\u8FBA\u9023\u7D50\u6210\u5206)"
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
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
    path: test/aoj/2893.test.cpp
    title: test/aoj/2893.test.cpp
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
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.LCT.test.cpp
    title: test/yukicoder/529.LCT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\nclass UnionFind {\n std::vector<int> par;\npublic:\n UnionFind(int\
    \ n): par(n, -1) {}\n bool unite(int u, int v) {\n  if ((u= root(u)) == (v= root(v)))\
    \ return false;\n  if (par[u] > par[v]) std::swap(u, v);\n  return par[u]+= par[v],\
    \ par[v]= u, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) { return par[u] < 0 ? u : par[u]= root(par[u]); }\n int\
    \ size(int u) { return -par[root(u)]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nclass UnionFind {\n\
    \ std::vector<int> par;\npublic:\n UnionFind(int n): par(n, -1) {}\n bool unite(int\
    \ u, int v) {\n  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u]\
    \ > par[v]) std::swap(u, v);\n  return par[u]+= par[v], par[v]= u, true;\n }\n\
    \ bool same(int u, int v) { return root(u) == root(v); }\n int root(int u) { return\
    \ par[u] < 0 ? u : par[u]= root(par[u]); }\n int size(int u) { return -par[root(u)];\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  - src/Graph/IncrementalBridgeConnectivity.hpp
  timestamp: '2023-01-21 15:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/2893.test.cpp
  - test/aoj/0342.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/yosupo/directedmst.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/yukicoder/529.LCT.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
title: Union-Find
---
 - `unite(x,y)` x が入っている集合と y が入っている集合を併合する．
 - `same(x,y)` x と y が同じ集合に入っているかどうかを判定する．

## 計算量
$\mathcal{O}(\alpha(N))$
