---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  - icon: ':question:'
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
  - icon: ':x:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
    links: []
  bundledCode: "#line 2 \"src/Graph/MinimumSpanningAborescense.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/UnionFind.hpp\"\n/**\n * @title Union-Find\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief unite(x,y) x \u304C\u5165\u3063\u3066\
    \u3044\u308B\u96C6\u5408\u3068 y \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\
    \u3092\u4F75\u5408\u3059\u308B\uFF0E\n * @brief same(x,y) x \u3068 y \u304C\u540C\
    \u3058\u96C6\u5408\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\uFF0E\n * @brief O(\u03B1(N))\n */\n\n// BEGIN\
    \ CUT HERE\n\nstruct UnionFind {\n  std::vector<int> par;\n  UnionFind(int size)\
    \ : par(size, -1) {}\n  bool unite(int u, int v) {\n    if ((u = root(u)) == (v\
    \ = root(v))) return false;\n    if (par[u] > par[v]) std::swap(u, v);\n    par[u]\
    \ += par[v], par[v] = u;\n    return true;\n  }\n  bool same(int u, int v) { return\
    \ root(u) == root(v); }\n  int root(int u) { return par[u] < 0 ? u : par[u] =\
    \ root(par[u]); }\n  int size(int u) { return -par[root(u)]; }\n};\n#line 3 \"\
    src/DataStructure/SkewHeap.hpp\"\n/**\n * @title Skew-Heap\n * @category \u30C7\
    \u30FC\u30BF\u69CB\u9020\n * @brief \u30DE\u30FC\u30B8\u3067\u304D\u308B\u30D2\
    \u30FC\u30D7\n * @brief top: O(1), pop, push, merge: O(logN)\n * @brief apply(v):\
    \ \u5168\u4F53\u306B\u4F5C\u7528\u7D20v\u3092\u9069\u7528\n */\n\n// BEGIN CUT\
    \ HERE\n\n#define HAS_CHECK(member, Dummy)                              \\\n \
    \ template <class tClass>                                     \\\n  struct has_##member\
    \ {                                       \\\n    template <class U, Dummy>  \
    \                               \\\n    static std::true_type check(U *);    \
    \                     \\\n    static std::false_type check(...);             \
    \           \\\n    static tClass *mClass;                                   \
    \ \\\n    static const bool value = decltype(check(mClass))::value; \\\n  };\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\ntemplate\
    \ <typename T, typename Compare = std::less<T>, typename M = void>\nstruct SkewHeap\
    \ {\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(E);\n  template\
    \ <class L>\n  using dual = std::conjunction<has_E<L>, has_mapping<L>, has_composition<L>>;\n\
    \  template <class tDerived, class U = std::nullptr_t>\n  struct Node_B {\n  \
    \  using E = U;\n    T key;\n    tDerived *ch[2];\n  };\n  template <bool du_,\
    \ typename tEnable = void>\n  struct Node_D : Node_B<Node_D<du_>> {};\n  template\
    \ <bool du_>\n  struct Node_D<du_, typename std::enable_if_t<du_>>\n      : Node_B<Node_D<du_>,\
    \ typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n  };\n\
    \  using Node = Node_D<dual<M>::value>;\n  using E = typename Node::E;\n  Node\
    \ *root;\n  static inline void propagate(Node *&t, const E &x) {\n    if (!t)\
    \ return;\n    t->lazy_flg ? (M::composition(t->lazy, x), x) : (t->lazy = x);\n\
    \    M::mapping(t->key, x), t->lazy_flg = true;\n  }\n  static inline void eval(Node\
    \ *t) {\n    if (t->lazy_flg)\n      propagate(t->ch[0], t->lazy), propagate(t->ch[1],\
    \ t->lazy),\n          t->lazy_flg = false;\n  }\n  Node *merge(Node *a, Node\
    \ *b) {\n    if (!a || !b) return a ? a : b;\n    if (Compare()(a->key, b->key))\
    \ std::swap(a, b);\n    if constexpr (dual<M>::value) eval(a);\n    return std::swap(a->ch[0],\
    \ a->ch[1] = merge(b, a->ch[1])), a;\n  }\n\n public:\n  /* max heap */\n  SkewHeap()\
    \ : root(nullptr) {}\n  void push(T key) { root = merge(root, new Node{key});\
    \ }\n  T pop() {\n    T ret = root->key;\n    if constexpr (dual<M>::value) eval(root);\n\
    \    return root = merge(root->ch[0], root->ch[1]), ret;\n  }\n  T top() { return\
    \ root->key; }\n  bool empty() { return !root; }\n  void apply(E v) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n    propagate(root, v);\n  }\n  SkewHeap\
    \ &operator+=(SkewHeap r) { return root = merge(root, r.root), *this; }\n  SkewHeap\
    \ operator+(SkewHeap r) { return SkewHeap(*this) += r; }\n};\n#line 5 \"src/Graph/MinimumSpanningAborescense.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\n * @category \u30B0\
    \u30E9\u30D5\n *  Chu-Liu/Edmonds\n *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\
    \u57DF\u6728\u306E\u30B3\u30B9\u30C8\u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\
    \u7528\u3059\u308B\u8FBA}\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename cost_t>\n\
    class MinimumSpanningAborescense {\n  struct Edge {\n    std::size_t src, dst,\
    \ id;\n    cost_t cost;\n    bool operator>(const Edge &r) const { return this->cost\
    \ > r.cost; }\n  };\n  struct Op_Edge_add {\n    using E = cost_t;\n    static\
    \ void mapping(Edge &l, const E &r) { l.cost += r; }\n    static void composition(E\
    \ &l, const E &r) { l += r; }\n  };\n  std::size_t n;\n  std::vector<Edge> edges;\n\
    \n public:\n  MinimumSpanningAborescense(std::size_t n) : n(n) {}\n  void add_edge(std::size_t\
    \ src, std::size_t dst, cost_t cost) {\n    edges.emplace_back(Edge{src, dst,\
    \ edges.size(), cost});\n  }\n  std::pair<cost_t, std::vector<Edge>> get_MSA(int\
    \ root) {\n    UnionFind uf(n);\n    std::vector<SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add>> h(n);\n    std::vector<Edge> es;\n    for (auto &e : edges) h[e.dst].push(e);\n\
    \    cost_t score = 0;\n    std::size_t m = edges.size(), s = 0, u = s, cyc =\
    \ 0, v;\n    std::vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n),\
    \ usede(m);\n    for (seen[root] = root; s < n; u = ++s, cyc = 0)\n      for (std::vector<int>\
    \ p, ch; seen[u] < 0; u = uf.root(v)) {\n        if (p.push_back(u), seen[u] =\
    \ s; h[u].empty()) return {-1, es};\n        Edge min_e = h[u].pop();\n      \
    \  score += min_e.cost, h[u].apply(-min_e.cost), ei.push_back(min_e.id);\n   \
    \     if (leaf[min_e.dst] == -1) leaf[min_e.dst] = min_e.id;\n        for (; cyc;\
    \ cyc--) paredge[ch.back()] = min_e.id, ch.pop_back();\n        if (ch.push_back(min_e.id);\
    \ seen[v = uf.root(min_e.src)] != s) continue;\n        SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add> new_h;\n        for (int w;;) {\n          new_h += h[w = p.back()];\n\
    \          if (p.pop_back(), cyc++; !uf.unite(v, w)) break;\n        }\n     \
    \   h[uf.root(v)] = new_h, seen[uf.root(v)] = -1;\n      }\n    for (auto it =\
    \ ei.rbegin(); it != ei.rend(); it++) {\n      if (usede[*it]) continue;\n   \
    \   es.emplace_back(edges[*it]);\n      for (int x = leaf[edges[*it].dst]; x !=\
    \ *it; x = paredge[x]) usede[x] = 1;\n    }\n    return {score, es};\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind.hpp\"\
    \n#include \"src/DataStructure/SkewHeap.hpp\"\n/**\n * @title \u6700\u5C0F\u5168\
    \u57DF\u6709\u5411\u6728\n * @category \u30B0\u30E9\u30D5\n *  Chu-Liu/Edmonds\n\
    \ *  O(E log V)\n *  \u8FD4\u308A\u5024:{\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\
    \u7DCF\u548C,\u5168\u57DF\u6728\u306B\u4F7F\u7528\u3059\u308B\u8FBA}\n */\n\n\
    // BEGIN CUT HERE\n\ntemplate <typename cost_t>\nclass MinimumSpanningAborescense\
    \ {\n  struct Edge {\n    std::size_t src, dst, id;\n    cost_t cost;\n    bool\
    \ operator>(const Edge &r) const { return this->cost > r.cost; }\n  };\n  struct\
    \ Op_Edge_add {\n    using E = cost_t;\n    static void mapping(Edge &l, const\
    \ E &r) { l.cost += r; }\n    static void composition(E &l, const E &r) { l +=\
    \ r; }\n  };\n  std::size_t n;\n  std::vector<Edge> edges;\n\n public:\n  MinimumSpanningAborescense(std::size_t\
    \ n) : n(n) {}\n  void add_edge(std::size_t src, std::size_t dst, cost_t cost)\
    \ {\n    edges.emplace_back(Edge{src, dst, edges.size(), cost});\n  }\n  std::pair<cost_t,\
    \ std::vector<Edge>> get_MSA(int root) {\n    UnionFind uf(n);\n    std::vector<SkewHeap<Edge,\
    \ std::greater<Edge>, Op_Edge_add>> h(n);\n    std::vector<Edge> es;\n    for\
    \ (auto &e : edges) h[e.dst].push(e);\n    cost_t score = 0;\n    std::size_t\
    \ m = edges.size(), s = 0, u = s, cyc = 0, v;\n    std::vector<int> seen(n, -1),\
    \ paredge(m), ei, leaf(n, -1), par(n), usede(m);\n    for (seen[root] = root;\
    \ s < n; u = ++s, cyc = 0)\n      for (std::vector<int> p, ch; seen[u] < 0; u\
    \ = uf.root(v)) {\n        if (p.push_back(u), seen[u] = s; h[u].empty()) return\
    \ {-1, es};\n        Edge min_e = h[u].pop();\n        score += min_e.cost, h[u].apply(-min_e.cost),\
    \ ei.push_back(min_e.id);\n        if (leaf[min_e.dst] == -1) leaf[min_e.dst]\
    \ = min_e.id;\n        for (; cyc; cyc--) paredge[ch.back()] = min_e.id, ch.pop_back();\n\
    \        if (ch.push_back(min_e.id); seen[v = uf.root(min_e.src)] != s) continue;\n\
    \        SkewHeap<Edge, std::greater<Edge>, Op_Edge_add> new_h;\n        for (int\
    \ w;;) {\n          new_h += h[w = p.back()];\n          if (p.pop_back(), cyc++;\
    \ !uf.unite(v, w)) break;\n        }\n        h[uf.root(v)] = new_h, seen[uf.root(v)]\
    \ = -1;\n      }\n    for (auto it = ei.rbegin(); it != ei.rend(); it++) {\n \
    \     if (usede[*it]) continue;\n      es.emplace_back(edges[*it]);\n      for\
    \ (int x = leaf[edges[*it].dst]; x != *it; x = paredge[x]) usede[x] = 1;\n   \
    \ }\n    return {score, es};\n  }\n};"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/DataStructure/SkewHeap.hpp
  isVerificationFile: false
  path: src/Graph/MinimumSpanningAborescense.hpp
  requiredBy: []
  timestamp: '2022-11-18 21:48:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2647.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/Graph/MinimumSpanningAborescense.hpp
layout: document
redirect_from:
- /library/src/Graph/MinimumSpanningAborescense.hpp
- /library/src/Graph/MinimumSpanningAborescense.hpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
---
