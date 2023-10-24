---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2893.test.cpp
    title: test/aoj/2893.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
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
  bundledCode: "#line 2 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\n#include\
    \ <unordered_set>\n#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <vector>\n\
    #include <algorithm>\nclass UnionFind {\n std::vector<int> par;\npublic:\n UnionFind(int\
    \ n): par(n, -1) {}\n bool unite(int u, int v) {\n  if ((u= root(u)) == (v= root(v)))\
    \ return false;\n  if (par[u] > par[v]) std::swap(u, v);\n  return par[u]+= par[v],\
    \ par[v]= u, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) { return par[u] < 0 ? u : par[u]= root(par[u]); }\n int\
    \ size(int u) { return -par[root(u)]; }\n};\n#line 4 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\
    \nclass IncrementalBridgeConnectivity {\n UnionFind cc, bcc;\n std::vector<int>\
    \ bbf;\n inline int parent(int v) { return bbf[v] < 0 ? -1 : bcc.root(bbf[v]);\
    \ }\n int lca(int u, int v) {\n  for (std::unordered_set<int> reached;; std::swap(u,\
    \ v))\n   if (u != -1) {\n    if (!reached.insert(u).second) return u;\n    u=\
    \ parent(u);\n   }\n }\n void condense_path(int u, int v) {\n  for (int n; !bcc.same(u,\
    \ v);) n= parent(u), bbf[u]= bbf[v], bcc.unite(u, v), u= n;\n }\npublic:\n IncrementalBridgeConnectivity(int\
    \ n): cc(n), bcc(n), bbf(n, -1) {}\n int represent(int v) { return bcc.root(v);\
    \ }\n bool two_edge_connected(int u, int v) { return bcc.same(u, v); }\n bool\
    \ connected(int u, int v) { return cc.same(u, v); }\n void add_edge(int u, int\
    \ v) {\n  if (int w; cc.same(u= bcc.root(u), v= bcc.root(v))) w= lca(u, v), condense_path(u,\
    \ w), condense_path(v, w);\n  else {\n   if (cc.size(u) > cc.size(v)) std::swap(u,\
    \ v);\n   for (cc.unite(u, v); u != -1;) w= parent(u), bbf[u]= v, v= u, u= w;\n\
    \  }\n }\n};\n"
  code: "#pragma once\n#include <unordered_set>\n#include \"src/DataStructure/UnionFind.hpp\"\
    \nclass IncrementalBridgeConnectivity {\n UnionFind cc, bcc;\n std::vector<int>\
    \ bbf;\n inline int parent(int v) { return bbf[v] < 0 ? -1 : bcc.root(bbf[v]);\
    \ }\n int lca(int u, int v) {\n  for (std::unordered_set<int> reached;; std::swap(u,\
    \ v))\n   if (u != -1) {\n    if (!reached.insert(u).second) return u;\n    u=\
    \ parent(u);\n   }\n }\n void condense_path(int u, int v) {\n  for (int n; !bcc.same(u,\
    \ v);) n= parent(u), bbf[u]= bbf[v], bcc.unite(u, v), u= n;\n }\npublic:\n IncrementalBridgeConnectivity(int\
    \ n): cc(n), bcc(n), bbf(n, -1) {}\n int represent(int v) { return bcc.root(v);\
    \ }\n bool two_edge_connected(int u, int v) { return bcc.same(u, v); }\n bool\
    \ connected(int u, int v) { return cc.same(u, v); }\n void add_edge(int u, int\
    \ v) {\n  if (int w; cc.same(u= bcc.root(u), v= bcc.root(v))) w= lca(u, v), condense_path(u,\
    \ w), condense_path(v, w);\n  else {\n   if (cc.size(u) > cc.size(v)) std::swap(u,\
    \ v);\n   for (cc.unite(u, v); u != -1;) w= parent(u), bbf[u]= v, v= u, u= w;\n\
    \  }\n }\n};"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: src/Graph/IncrementalBridgeConnectivity.hpp
  requiredBy: []
  timestamp: '2023-01-21 15:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/529.LCT.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/2893.test.cpp
documentation_of: src/Graph/IncrementalBridgeConnectivity.hpp
layout: document
title: "Incremental-Bridge-Connectivity (2\u8FBA\u9023\u7D50\u6210\u5206)"
---
## 問題例
[AtCoder Regular Contest 039 D - 旅行会社高橋君](https://atcoder.jp/contests/arc039/tasks/arc039_d)
## 参考
[https://scrapbox.io/data-structures/Incremental_Bridge-Connectivity](https://scrapbox.io/data-structures/Incremental_Bridge-Connectivity)