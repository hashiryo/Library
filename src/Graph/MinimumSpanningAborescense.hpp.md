---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
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
    \ size(int u) { return -par[root(u)]; }\n};\n#line 2 \"src/DataStructure/SkewHeap.hpp\"\
    \n#include <functional>\n#line 4 \"src/DataStructure/SkewHeap.hpp\"\n#include\
    \ <cstddef>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 6 \"src/DataStructure/SkewHeap.hpp\"\
    \ntemplate <typename T, typename Compare= std::less<T>, typename M= void> struct\
    \ SkewHeap {\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n HAS_TYPE(E);\n\
    \ template <class L> using dual= std::conjunction<has_E<L>, has_mapping<L>, has_composition<L>>;\n\
    \ template <class tDerived, class U= std::nullptr_t> struct Node_B {\n  using\
    \ E= U;\n  T key;\n  tDerived *ch[2];\n };\n template <bool du_, typename tEnable=\
    \ void> struct Node_D: Node_B<Node_D<du_>> {};\n template <bool du_> struct Node_D<du_,\
    \ typename std::enable_if_t<du_>>: Node_B<Node_D<du_>, typename M::E> {\n  typename\
    \ M::E lazy;\n  bool lazy_flg= false;\n };\n using Node= Node_D<dual<M>::value>;\n\
    \ using E= typename Node::E;\n Node *root;\n static inline void propagate(Node\
    \ *&t, const E &x) {\n  if (!t) return;\n  t->lazy_flg ? (M::composition(t->lazy,\
    \ x), x) : (t->lazy= x);\n  M::mapping(t->key, x), t->lazy_flg= true;\n }\n static\
    \ inline void eval(Node *t) {\n  if (t->lazy_flg) propagate(t->ch[0], t->lazy),\
    \ propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n }\n Node *merge(Node *a,\
    \ Node *b) {\n  if (!a || !b) return a ? a : b;\n  if (Compare()(a->key, b->key))\
    \ std::swap(a, b);\n  if constexpr (dual<M>::value) eval(a);\n  return std::swap(a->ch[0],\
    \ a->ch[1]= merge(b, a->ch[1])), a;\n }\npublic:\n /* max heap */ SkewHeap():\
    \ root(nullptr) {}\n void push(T key) { root= merge(root, new Node{key}); }\n\
    \ T pop() {\n  T ret= root->key;\n  if constexpr (dual<M>::value) eval(root);\n\
    \  return root= merge(root->ch[0], root->ch[1]), ret;\n }\n T top() { return root->key;\
    \ }\n bool empty() { return !root; }\n void apply(E v) {\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n  propagate(root, v);\n }\n SkewHeap\
    \ &operator+=(SkewHeap r) { return root= merge(root, r.root), *this; }\n SkewHeap\
    \ operator+(SkewHeap r) { return SkewHeap(*this)+= r; }\n};\n#line 4 \"src/Graph/MinimumSpanningAborescense.hpp\"\
    \ntemplate <typename cost_t> class MinimumSpanningAborescense {\n struct Edge\
    \ {\n  std::size_t src, dst, id;\n  cost_t cost;\n  bool operator>(const Edge\
    \ &r) const { return this->cost > r.cost; }\n };\n struct Op_Edge_add {\n  using\
    \ E= cost_t;\n  static void mapping(Edge &l, const E &r) { l.cost+= r; }\n  static\
    \ void composition(E &l, const E &r) { l+= r; }\n };\n std::size_t n;\n std::vector<Edge>\
    \ edges;\npublic:\n MinimumSpanningAborescense(std::size_t n): n(n) {}\n void\
    \ add_edge(std::size_t src, std::size_t dst, cost_t cost) { edges.emplace_back(Edge{src,\
    \ dst, edges.size(), cost}); }\n std::pair<cost_t, std::vector<Edge>> get_MSA(int\
    \ root) {\n  UnionFind uf(n);\n  std::vector<SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add>> h(n);\n  std::vector<Edge> es;\n  for (auto &e: edges) h[e.dst].push(e);\n\
    \  cost_t score= 0;\n  std::size_t m= edges.size(), s= 0, u= s, cyc= 0, v;\n \
    \ std::vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n), usede(m);\n\
    \  for (seen[root]= root; s < n; u= ++s, cyc= 0)\n   for (std::vector<int> p,\
    \ ch; seen[u] < 0; u= uf.root(v)) {\n    if (p.push_back(u), seen[u]= s; h[u].empty())\
    \ return {-1, es};\n    Edge min_e= h[u].pop();\n    score+= min_e.cost, h[u].apply(-min_e.cost),\
    \ ei.push_back(min_e.id);\n    if (leaf[min_e.dst] == -1) leaf[min_e.dst]= min_e.id;\n\
    \    for (; cyc; cyc--) paredge[ch.back()]= min_e.id, ch.pop_back();\n    if (ch.push_back(min_e.id);\
    \ seen[v= uf.root(min_e.src)] != s) continue;\n    SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add> new_h;\n    for (int w;;) {\n     new_h+= h[w= p.back()];\n   \
    \  if (p.pop_back(), cyc++; !uf.unite(v, w)) break;\n    }\n    h[uf.root(v)]=\
    \ new_h, seen[uf.root(v)]= -1;\n   }\n  for (auto it= ei.rbegin(); it != ei.rend();\
    \ it++) {\n   if (usede[*it]) continue;\n   es.emplace_back(edges[*it]);\n   for\
    \ (int x= leaf[edges[*it].dst]; x != *it; x= paredge[x]) usede[x]= 1;\n  }\n \
    \ return {score, es};\n }\n};\n"
  code: "#pragma once\n#include \"src/DataStructure/UnionFind.hpp\"\n#include \"src/DataStructure/SkewHeap.hpp\"\
    \ntemplate <typename cost_t> class MinimumSpanningAborescense {\n struct Edge\
    \ {\n  std::size_t src, dst, id;\n  cost_t cost;\n  bool operator>(const Edge\
    \ &r) const { return this->cost > r.cost; }\n };\n struct Op_Edge_add {\n  using\
    \ E= cost_t;\n  static void mapping(Edge &l, const E &r) { l.cost+= r; }\n  static\
    \ void composition(E &l, const E &r) { l+= r; }\n };\n std::size_t n;\n std::vector<Edge>\
    \ edges;\npublic:\n MinimumSpanningAborescense(std::size_t n): n(n) {}\n void\
    \ add_edge(std::size_t src, std::size_t dst, cost_t cost) { edges.emplace_back(Edge{src,\
    \ dst, edges.size(), cost}); }\n std::pair<cost_t, std::vector<Edge>> get_MSA(int\
    \ root) {\n  UnionFind uf(n);\n  std::vector<SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add>> h(n);\n  std::vector<Edge> es;\n  for (auto &e: edges) h[e.dst].push(e);\n\
    \  cost_t score= 0;\n  std::size_t m= edges.size(), s= 0, u= s, cyc= 0, v;\n \
    \ std::vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n), usede(m);\n\
    \  for (seen[root]= root; s < n; u= ++s, cyc= 0)\n   for (std::vector<int> p,\
    \ ch; seen[u] < 0; u= uf.root(v)) {\n    if (p.push_back(u), seen[u]= s; h[u].empty())\
    \ return {-1, es};\n    Edge min_e= h[u].pop();\n    score+= min_e.cost, h[u].apply(-min_e.cost),\
    \ ei.push_back(min_e.id);\n    if (leaf[min_e.dst] == -1) leaf[min_e.dst]= min_e.id;\n\
    \    for (; cyc; cyc--) paredge[ch.back()]= min_e.id, ch.pop_back();\n    if (ch.push_back(min_e.id);\
    \ seen[v= uf.root(min_e.src)] != s) continue;\n    SkewHeap<Edge, std::greater<Edge>,\
    \ Op_Edge_add> new_h;\n    for (int w;;) {\n     new_h+= h[w= p.back()];\n   \
    \  if (p.pop_back(), cyc++; !uf.unite(v, w)) break;\n    }\n    h[uf.root(v)]=\
    \ new_h, seen[uf.root(v)]= -1;\n   }\n  for (auto it= ei.rbegin(); it != ei.rend();\
    \ it++) {\n   if (usede[*it]) continue;\n   es.emplace_back(edges[*it]);\n   for\
    \ (int x= leaf[edges[*it].dst]; x != *it; x= paredge[x]) usede[x]= 1;\n  }\n \
    \ return {score, es};\n }\n};"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/DataStructure/SkewHeap.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/Graph/MinimumSpanningAborescense.hpp
  requiredBy: []
  timestamp: '2023-01-21 15:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/directedmst.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2647.test.cpp
documentation_of: src/Graph/MinimumSpanningAborescense.hpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
---
Chu-Liu/Edmonds \
返り値:{全域木のコスト総和,全域木に使用する辺}
## 計算量
$\mathcal{O}(E \log V)$