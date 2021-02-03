---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"test/yosupo/directedmst.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/UnionFind.hpp\"\n/**\n\
    \ * @title Union-Find\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ unite(x,y) x \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3068 y \u304C\
    \u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\uFF0E\
    \n * @brief same(x,y) x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5165\u3063\
    \u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\uFF0E\
    \n * @brief O(\u03B1(N))\n */\n\n// BEGIN CUT HERE\n\nstruct UnionFind {\n  std::vector<int>\
    \ par;\n  UnionFind(int size) : par(size, -1) {}\n  bool unite(int u, int v) {\n\
    \    if ((u = root(u)) == (v = root(v))) return false;\n    if (par[u] > par[v])\
    \ std::swap(u, v);\n    par[u] += par[v], par[v] = u;\n    return true;\n  }\n\
    \  bool same(int u, int v) { return root(u) == root(v); }\n  int root(int u) {\
    \ return par[u] < 0 ? u : par[u] = root(par[u]); }\n  int size(int u) { return\
    \ -par[root(u)]; }\n};\n#line 3 \"src/DataStructure/SkewHeap.hpp\"\n/**\n * @title\
    \ Skew-Heap\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u30DE\u30FC\
    \u30B8\u3067\u304D\u308B\u30D2\u30FC\u30D7\n * @brief top: O(1), pop, push, merge:\
    \ O(logN)\n * @brief add(v): \u5168\u4F53\u306B\u4F5C\u7528\u7D20v\u3092\u9069\
    \u7528\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nstruct Op_RaddQ {\n\
    \  using E = T;\n  static E ei() { return 0; }\n  static T g(const T &l, const\
    \ E &r) { return l + r; }\n  static E h(const E &l, const E &r) { return l + r;\
    \ }\n};\n\ntemplate <typename T, typename Compare = std::less<T>,\n          typename\
    \ Op = Op_RaddQ<T>>\nstruct SkewHeap {\n  using E = typename Op::E;\n  struct\
    \ Node {\n    Node *ch[2];\n    T key;\n    E lazy;\n    Node() {}\n    Node(T\
    \ k, E laz) : ch{nullptr, nullptr}, key(k), lazy(laz) {}\n  } * root;\n\n private:\n\
    \  void propagate(Node *a) {\n    if (a->lazy != Op::ei()) {\n      a->key = Op::g(a->key,\
    \ a->lazy);\n      if (a->ch[0]) a->ch[0]->lazy = Op::h(a->ch[0]->lazy, a->lazy);\n\
    \      if (a->ch[1]) a->ch[1]->lazy = Op::h(a->ch[1]->lazy, a->lazy);\n      a->lazy\
    \ = Op::ei();\n    }\n  }\n  Node *merge(Node *a, Node *b) {\n    if (!a || !b)\
    \ return a ? a : b;\n    propagate(a);\n    propagate(b);\n    if (Compare()(a->key,\
    \ b->key)) std::swap(a, b);\n    a->ch[1] = merge(b, a->ch[1]);\n    std::swap(a->ch[0],\
    \ a->ch[1]);\n    return a;\n  }\n\n public:\n  /* max heap */\n  SkewHeap() :\
    \ root(nullptr) {}\n  void push(T key) {\n    Node *n = new Node(key, Op::ei());\n\
    \    root = merge(root, n);\n  }\n  T pop() {\n    propagate(root);\n    T ret\
    \ = root->key;\n    Node *temp = root;\n    root = merge(root->ch[0], root->ch[1]);\n\
    \    delete temp;\n    return ret;\n  }\n  T top() {\n    propagate(root);\n \
    \   return root->key;\n  }\n  bool empty() { return !root; }\n  void add(E v)\
    \ { root->lazy = Op::h(root->lazy, v); }\n  void merge(SkewHeap x) { root = merge(root,\
    \ x.root); }\n};\n#line 5 \"src/Graph/MinimumSpanningAborescense.hpp\"\n/**\n\
    \ * @title \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\n * @category \u30B0\u30E9\
    \u30D5\n *  Chu-Liu/Edmonds\n *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\u57DF\
    \u6728\u306E\u30B3\u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\u7528\
    \u3059\u308B\u8FBA}\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename cost_t>\n\
    struct MinimumSpanningAborescense {\n  struct Edge {\n    int src, dst, id;\n\
    \    cost_t cost;\n    bool operator>(const Edge &r) const { return this->cost\
    \ > r.cost; }\n  };\n  struct Op_Edge_add {\n    using E = cost_t;\n    static\
    \ E ei() { return 0; }\n    static Edge g(const Edge &l, const E &r) {\n     \
    \ return Edge({l.src, l.dst, l.id, l.cost + r});\n    }\n    static E h(const\
    \ E &l, const E &r) { return l + r; }\n  };\n  using Heap = SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add>;\n\n private:\n  int n;\n\n public:\n  std::vector<Edge> edges;\n\
    \n public:\n  MinimumSpanningAborescense(int n) : n(n) {}\n  void add_edge(int\
    \ src, int dst, cost_t cost) {\n    edges.emplace_back(Edge{src, dst, (int)edges.size(),\
    \ cost});\n  }\n  std::pair<cost_t, std::vector<Edge>> get_MSA(int root) {\n \
    \   UnionFind uf(n);\n    std::vector<Heap> heap(n);\n    for (auto &e : edges)\
    \ heap[e.dst].push(e);\n    cost_t score = 0;\n    int m = edges.size();\n   \
    \ std::vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n), usede(m);\n\
    \    seen[root] = root;\n    for (int s = 0; s < n; ++s) {\n      std::vector<int>\
    \ path, ch;\n      int cyc = 0;\n      for (int u = s; seen[u] < 0;) {\n     \
    \   path.push_back(u);\n        seen[u] = s;\n        if (heap[u].empty()) return\
    \ {-1, std::vector<Edge>()};\n        Edge min_e = heap[u].top();\n        score\
    \ += min_e.cost;\n        heap[u].add(-min_e.cost);\n        heap[u].pop();\n\
    \        ei.push_back(min_e.id);\n        if (leaf[min_e.dst] == -1) leaf[min_e.dst]\
    \ = min_e.id;\n        while (cyc) {\n          paredge[ch.back()] = min_e.id;\n\
    \          ch.pop_back();\n          cyc--;\n        }\n        ch.push_back(min_e.id);\n\
    \        int v = uf.root(min_e.src);\n        if (seen[v] == s) {\n          Heap\
    \ new_heap;\n          while (1) {\n            int w = path.back();\n       \
    \     path.pop_back();\n            new_heap.merge(heap[w]);\n            cyc++;\n\
    \            if (!uf.unite(v, w)) break;\n          }\n          heap[uf.root(v)]\
    \ = new_heap;\n          seen[uf.root(v)] = -1;\n        }\n        u = uf.root(v);\n\
    \      }\n    }\n    reverse(ei.begin(), ei.end());\n    std::vector<Edge> es;\n\
    \    for (auto i : ei) {\n      if (usede[i]) continue;\n      es.emplace_back(edges[i]);\n\
    \      int x = leaf[edges[i].dst];\n      while (x != i) {\n        usede[x] =\
    \ 1;\n        x = paredge[x];\n      }\n    }\n    return {score, es};\n  }\n\
    };\n#line 6 \"test/yosupo/directedmst.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M, r;\n  cin >>\
    \ N >> M >> r;\n  MinimumSpanningAborescense<long long> graph(N);\n  for (int\
    \ i = 0; i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n    graph.add_edge(s,\
    \ t, w);\n  }\n  auto ans = graph.get_MSA(r);\n  vector<int> par(N);\n  iota(par.begin(),\
    \ par.end(), 0);\n  for (auto e : ans.second) par[e.dst] = e.src;\n  cout << ans.first\
    \ << endl;\n  for (int i = 0; i < N; i++) cout << (i ? \" \" : \"\") << par[i];\n\
    \  cout << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind.hpp\"\n#include \"src/DataStructure/SkewHeap.hpp\"\
    \n#include \"src/Graph/MinimumSpanningAborescense.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M, r;\n\
    \  cin >> N >> M >> r;\n  MinimumSpanningAborescense<long long> graph(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n    graph.add_edge(s,\
    \ t, w);\n  }\n  auto ans = graph.get_MSA(r);\n  vector<int> par(N);\n  iota(par.begin(),\
    \ par.end(), 0);\n  for (auto e : ans.second) par[e.dst] = e.src;\n  cout << ans.first\
    \ << endl;\n  for (int i = 0; i < N; i++) cout << (i ? \" \" : \"\") << par[i];\n\
    \  cout << endl;\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/DataStructure/SkewHeap.hpp
  - src/Graph/MinimumSpanningAborescense.hpp
  isVerificationFile: true
  path: test/yosupo/directedmst.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 12:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/directedmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/directedmst.test.cpp
- /verify/test/yosupo/directedmst.test.cpp.html
title: test/yosupo/directedmst.test.cpp
---