---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Graph/MinimumSpanningTree_Kruskal.hpp: line 13: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u6700\u5C0F\u5168\u57DF\u6728(Kruskal)\n * @category \u30B0\
    \u30E9\u30D5\n *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\u57DF\u6728\u306E\
    \u30B3\u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\u7528\u3059\u308B\
    \u8FBA}\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"src/DataStructure/UnionFind.hpp\"\
    \n#undef call_from_test\n#endif\n\ntemplate <typename cost_t>\nstruct MinimumSpanningTree_Kruskal\
    \ {\n  struct Edge {\n    int u, v, id;\n    cost_t cost;\n    bool operator<(const\
    \ Edge &rhs) const { return this->cost < rhs.cost; }\n  };\n\n private:\n  int\
    \ n;\n\n public:\n  vector<Edge> edges;\n\n public:\n  MinimumSpanningTree_Kruskal(int\
    \ n) : n(n) {}\n  void add_edge(int u, int v, cost_t cost) {\n    edges.emplace_back(Edge{u,\
    \ v, (int)edges.size(), cost});\n  }\n  pair<cost_t, vector<Edge>> get_MST() {\n\
    \    UnionFind uf(n);\n    sort(begin(edges), end(edges));\n    cost_t total =\
    \ cost_t();\n    vector<Edge> es;\n    for (auto &e : edges)\n      if (uf.unite(e.u,\
    \ e.v)) {\n        es.emplace_back(e);\n        total += e.cost;\n      }\n  \
    \  return {total, es};\n  }\n};"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: src/Graph/MinimumSpanningTree_Kruskal.hpp
  requiredBy: []
  timestamp: '2020-08-19 15:34:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/0342.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
documentation_of: src/Graph/MinimumSpanningTree_Kruskal.hpp
layout: document
redirect_from:
- /library/src/Graph/MinimumSpanningTree_Kruskal.hpp
- /library/src/Graph/MinimumSpanningTree_Kruskal.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
---
