---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':x:'
    path: src/Graph/MinimumSpanningTree_Kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/DataStructure/UnionFind.hpp\"\n/**\n * @title\
    \ Union-Find\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief unite(x,y)\
    \ x \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3068 y \u304C\u5165\u3063\
    \u3066\u3044\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\uFF0E\n * @brief\
    \ same(x,y) x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5165\u3063\u3066\u3044\
    \u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\uFF0E\n * @brief\
    \ O(\u03B1(N))\n */\n\n// BEGIN CUT HERE\n\nstruct UnionFind {\n  std::vector<int>\
    \ par;\n  UnionFind(int size) : par(size, -1) {}\n  bool unite(int u, int v) {\n\
    \    if ((u = root(u)) == (v = root(v))) return false;\n    if (par[u] > par[v])\
    \ swap(u, v);\n    par[u] += par[v], par[v] = u;\n    return true;\n  }\n  bool\
    \ same(int u, int v) { return root(u) == root(v); }\n  int root(int u) { return\
    \ par[u] < 0 ? u : par[u] = root(par[u]); }\n  int size(int u) { return -par[root(u)];\
    \ }\n};\n#line 4 \"src/Graph/MinimumSpanningTree_Kruskal.hpp\"\n/**\n * @title\
    \ \u6700\u5C0F\u5168\u57DF\u6728(Kruskal)\n * @category \u30B0\u30E9\u30D5\n *\
    \  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\
    \u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\u7528\u3059\u308B\u8FBA}\n */\n\n\
    // BEGIN CUT HERE\n\ntemplate <typename cost_t>\nstruct MinimumSpanningTree_Kruskal\
    \ {\n  struct Edge {\n    int u, v, id;\n    cost_t cost;\n    bool operator<(const\
    \ Edge &rhs) const { return this->cost < rhs.cost; }\n  };\n\n private:\n  int\
    \ n;\n\n public:\n  std::vector<Edge> edges;\n\n public:\n  MinimumSpanningTree_Kruskal(int\
    \ n) : n(n) {}\n  void add_edge(int u, int v, cost_t cost) {\n    edges.emplace_back(Edge{u,\
    \ v, (int)edges.size(), cost});\n  }\n  std::pair<cost_t, std::vector<Edge>> get_MST()\
    \ {\n    UnionFind uf(n);\n    sort(begin(edges), end(edges));\n    cost_t total\
    \ = cost_t();\n    std::vector<Edge> es;\n    for (auto &e : edges)\n      if\
    \ (uf.unite(e.u, e.v)) {\n        es.emplace_back(e);\n        total += e.cost;\n\
    \      }\n    return {total, es};\n  }\n};\n#line 6 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, M;\n  cin >> N >> M;\n  MinimumSpanningTree_Kruskal<int> graph(N);\n\
    \  for (int i = 0; i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n\
    \    graph.add_edge(s, t, w);\n  }\n  cout << graph.get_MST().first << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind.hpp\"\n#include\
    \ \"src/Graph/MinimumSpanningTree_Kruskal.hpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int N, M;\n  cin\
    \ >> N >> M;\n  MinimumSpanningTree_Kruskal<int> graph(N);\n  for (int i = 0;\
    \ i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n    graph.add_edge(s,\
    \ t, w);\n  }\n  cout << graph.get_MST().first << endl;\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/Graph/MinimumSpanningTree_Kruskal.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp.html
title: test/aoj/GRL_2_A.kruskal.test.cpp
---
