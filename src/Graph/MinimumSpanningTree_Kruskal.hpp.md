---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
    links: []
  bundledCode: "#line 2 \"src/Graph/MinimumSpanningTree_Kruskal.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/UnionFind.hpp\"\nstruct UnionFind {\n std::vector<int>\
    \ par;\n UnionFind(int size): par(size, -1) {}\n bool unite(int u, int v) {\n\
    \  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u,\
    \ v);\n  return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u, int v)\
    \ { return root(u) == root(v); }\n int root(int u) { return par[u] < 0 ? u : par[u]=\
    \ root(par[u]); }\n int size(int u) { return -par[root(u)]; }\n};\n#line 4 \"\
    src/Graph/MinimumSpanningTree_Kruskal.hpp\"\n/**\n * @title \u6700\u5C0F\u5168\
    \u57DF\u6728(Kruskal)\n * @category \u30B0\u30E9\u30D5\n *  O(E log V)\n *  \u8FD4\
    \u308A\u5024:{\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\
    \u6728\u306B\u4F7F\u7528\u3059\u308B\u8FBA}\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename cost_t>\nstruct MinimumSpanningTree_Kruskal {\n  struct Edge {\n \
    \   int u, v, id;\n    cost_t cost;\n    bool operator<(const Edge &rhs) const\
    \ { return this->cost < rhs.cost; }\n  };\n\n private:\n  int n;\n\n public:\n\
    \  std::vector<Edge> edges;\n\n public:\n  MinimumSpanningTree_Kruskal(int n)\
    \ : n(n) {}\n  void add_edge(int u, int v, cost_t cost) {\n    edges.emplace_back(Edge{u,\
    \ v, (int)edges.size(), cost});\n  }\n  std::pair<cost_t, std::vector<Edge>> get_MST()\
    \ {\n    UnionFind uf(n);\n    sort(begin(edges), end(edges));\n    cost_t total\
    \ = cost_t();\n    std::vector<Edge> es;\n    for (auto &e : edges)\n      if\
    \ (uf.unite(e.u, e.v)) {\n        es.emplace_back(e);\n        total += e.cost;\n\
    \      }\n    return {total, es};\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u5168\u57DF\u6728(Kruskal)\n * @category \u30B0\u30E9\
    \u30D5\n *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\u7528\u3059\u308B\u8FBA\
    }\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename cost_t>\nstruct MinimumSpanningTree_Kruskal\
    \ {\n  struct Edge {\n    int u, v, id;\n    cost_t cost;\n    bool operator<(const\
    \ Edge &rhs) const { return this->cost < rhs.cost; }\n  };\n\n private:\n  int\
    \ n;\n\n public:\n  std::vector<Edge> edges;\n\n public:\n  MinimumSpanningTree_Kruskal(int\
    \ n) : n(n) {}\n  void add_edge(int u, int v, cost_t cost) {\n    edges.emplace_back(Edge{u,\
    \ v, (int)edges.size(), cost});\n  }\n  std::pair<cost_t, std::vector<Edge>> get_MST()\
    \ {\n    UnionFind uf(n);\n    sort(begin(edges), end(edges));\n    cost_t total\
    \ = cost_t();\n    std::vector<Edge> es;\n    for (auto &e : edges)\n      if\
    \ (uf.unite(e.u, e.v)) {\n        es.emplace_back(e);\n        total += e.cost;\n\
    \      }\n    return {total, es};\n  }\n};"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: src/Graph/MinimumSpanningTree_Kruskal.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:54:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0342.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
documentation_of: src/Graph/MinimumSpanningTree_Kruskal.hpp
layout: document
redirect_from:
- /library/src/Graph/MinimumSpanningTree_Kruskal.hpp
- /library/src/Graph/MinimumSpanningTree_Kruskal.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
---
