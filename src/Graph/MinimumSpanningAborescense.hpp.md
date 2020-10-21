---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Graph/MinimumSpanningAborescense.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\n * @category \u30B0\
    \u30E9\u30D5\n *  Chu-Liu/Edmonds\n *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\
    \u57DF\u6728\u306E\u30B3\u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\
    \u7528\u3059\u308B\u8FBA}\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"src/DataStructure/UnionFind.hpp\"\
    \n#include \"src/DataStructure/SkewHeap.hpp\"\n#undef call_from_test\n#endif\n\
    \ntemplate <typename cost_t>\nstruct MinimumSpanningAborescense {\n  struct Edge\
    \ {\n    int src, dst, id;\n    cost_t cost;\n    bool operator>(const Edge &r)\
    \ const { return this->cost > r.cost; }\n  };\n  struct Op_Edge_add {\n    using\
    \ E = cost_t;\n    static E ei() { return 0; }\n    static Edge g(const Edge &l,\
    \ const E &r) {\n      return Edge({l.src, l.dst, l.id, l.cost + r});\n    }\n\
    \    static E h(const E &l, const E &r) { return l + r; }\n  };\n  using Heap\
    \ = SkewHeap<Edge, greater<Edge>, Op_Edge_add>;\n\n private:\n  int n;\n\n public:\n\
    \  vector<Edge> edges;\n\n public:\n  MinimumSpanningAborescense(int n) : n(n)\
    \ {}\n  void add_edge(int src, int dst, cost_t cost) {\n    edges.emplace_back(Edge{src,\
    \ dst, (int)edges.size(), cost});\n  }\n  pair<cost_t, vector<Edge>> get_MSA(int\
    \ root) {\n    UnionFind uf(n);\n    vector<Heap> heap(n);\n    for (auto &e :\
    \ edges) heap[e.dst].push(e);\n    cost_t score = 0;\n    int m = edges.size();\n\
    \    vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n), usede(m);\n\
    \    seen[root] = root;\n    for (int s = 0; s < n; ++s) {\n      vector<int>\
    \ path, ch;\n      int cyc = 0;\n      for (int u = s; seen[u] < 0;) {\n     \
    \   path.push_back(u);\n        seen[u] = s;\n        if (heap[u].empty()) return\
    \ {-1, vector<Edge>()};\n        Edge min_e = heap[u].top();\n        score +=\
    \ min_e.cost;\n        heap[u].add(-min_e.cost);\n        heap[u].pop();\n   \
    \     ei.push_back(min_e.id);\n        if (leaf[min_e.dst] == -1) leaf[min_e.dst]\
    \ = min_e.id;\n        while (cyc) {\n          paredge[ch.back()] = min_e.id;\n\
    \          ch.pop_back();\n          cyc--;\n        }\n        ch.push_back(min_e.id);\n\
    \        int v = uf.root(min_e.src);\n        if (seen[v] == s) {\n          Heap\
    \ new_heap;\n          while (1) {\n            int w = path.back();\n       \
    \     path.pop_back();\n            new_heap.merge(heap[w]);\n            cyc++;\n\
    \            if (!uf.unite(v, w)) break;\n          }\n          heap[uf.root(v)]\
    \ = new_heap;\n          seen[uf.root(v)] = -1;\n        }\n        u = uf.root(v);\n\
    \      }\n    }\n    reverse(ei.begin(), ei.end());\n    vector<Edge> es;\n  \
    \  for (auto i : ei) {\n      if (usede[i]) continue;\n      es.emplace_back(edges[i]);\n\
    \      int x = leaf[edges[i].dst];\n      while (x != i) {\n        usede[x] =\
    \ 1;\n        x = paredge[x];\n      }\n    }\n    return {score, es};\n  }\n\
    };"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/DataStructure/SkewHeap.hpp
  isVerificationFile: false
  path: src/Graph/MinimumSpanningAborescense.hpp
  requiredBy: []
  timestamp: '2020-08-19 16:25:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2647.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/Graph/MinimumSpanningAborescense.hpp
layout: document
redirect_from:
- /library/src/Graph/MinimumSpanningAborescense.hpp
- /library/src/Graph/MinimumSpanningAborescense.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
---
