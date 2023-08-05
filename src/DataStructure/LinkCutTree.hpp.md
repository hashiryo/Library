---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.Patricia.test.cpp
    title: test/aoj/2270.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.LCT.test.cpp
    title: test/aoj/2450.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.DynSeg.test.cpp
    title: test/atcoder/abc133_f.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.Patricia.test.cpp
    title: test/atcoder/abc133_f.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.PerArr.test.cpp
    title: test/atcoder/abc133_f.PerArr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.LCT.test.cpp
    title: test/yosupo/lca.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.LCT.test.cpp
    title: test/yukicoder/235.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.LCT.test.cpp
    title: test/yukicoder/529.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/650.LCT.test.cpp
    title: test/yukicoder/650.LCT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LinkCutTree.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#include <string>\n#include <cstddef>\n#include <cassert>\n\
    #line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n#define HAS_CHECK(member,\
    \ Dummy) \\\n template <class tClass> struct has_##member { \\\n  template <class\
    \ U, Dummy> static std::true_type check(U *); \\\n  static std::false_type check(...);\
    \ \\\n  static tClass *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
    \ \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n\
    #line 8 \"src/DataStructure/LinkCutTree.hpp\"\ntemplate <typename M= void> class\
    \ LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n HAS_MEMBER(composition);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L> static constexpr bool semigroup_v=\
    \ std::conjunction_v<has_T<L>, has_op<L>>;\n template <class L> static constexpr\
    \ bool dual_v= std::conjunction_v<has_T<L>, has_E<L>, has_mapping<L>, has_composition<L>>;\n\
    \ using node_id= std::int_least32_t;\n template <class U= std::nullptr_t, class\
    \ F= std::nullptr_t> struct Node_B {\n  using T= U;\n  using E= F;\n  node_id\
    \ ch[2]= {-1, -1}, par= -1;\n  bool rev_flg;\n };\n template <class D, bool sg,\
    \ bool du> struct Node_D: Node_B<> {};\n template <class D> struct Node_D<D, 1,\
    \ 0>: Node_B<typename M::T> {\n  typename M::T val, sum, rsum;\n };\n template\
    \ <class D> struct Node_D<D, 0, 1>: Node_B<typename M::T, typename M::E> {\n \
    \ typename M::T val;\n  typename M::E lazy;\n  bool lazy_flg;\n };\n template\
    \ <class D> struct Node_D<D, 1, 1>: Node_B<typename M::T, typename M::E> {\n \
    \ typename M::T val, sum, rsum;\n  typename M::E lazy;\n  bool lazy_flg;\n };\n\
    \ using Node= Node_D<void, semigroup_v<M>, dual_v<M>>;\n using T= typename Node::T;\n\
    \ using E= typename Node::E;\n inline int dir(node_id i) {\n  if (ns[i].par !=\
    \ -1) {\n   if (ns[ns[i].par].ch[0] == i) return 0;\n   if (ns[ns[i].par].ch[1]\
    \ == i) return 1;\n  }\n  return 2;\n }\n inline void rot(node_id i) {\n  node_id\
    \ p= ns[i].par;\n  int d= dir(i);\n  if ((ns[p].ch[d]= ns[i].ch[!d]) != -1) ns[ns[p].ch[d]].par=\
    \ p;\n  ns[i].ch[!d]= p, ns[i].par= ns[p].par;\n  if ((d= dir(p)) < 2) ns[ns[p].par].ch[d]=\
    \ i;\n  ns[p].par= i;\n  if constexpr (semigroup_v<M>) pushup(p);\n }\n inline\
    \ void splay(node_id i) {\n  eval(i);\n  node_id p= ns[i].par, pp;\n  for (int\
    \ d= dir(i), c; d < 2; rot(i), d= dir(i), p= ns[i].par) {\n   if (c= dir(p), pp=\
    \ ns[p].par; c < 2) eval(pp), eval(p), eval(i), rot(d == c ? p : i);\n   else\
    \ eval(p), eval(i);\n  }\n  if constexpr (semigroup_v<M>) pushup(i);\n }\n inline\
    \ void pushup(node_id i) {\n  ns[i].rsum= ns[i].sum= ns[i].val;\n  if (ns[i].ch[0]\
    \ != -1) ns[i].sum= M::op(ns[ns[i].ch[0]].sum, ns[i].sum), ns[i].rsum= M::op(ns[i].rsum,\
    \ ns[ns[i].ch[0]].rsum);\n  if (ns[i].ch[1] != -1) ns[i].sum= M::op(ns[i].sum,\
    \ ns[ns[i].ch[1]].sum), ns[i].rsum= M::op(ns[ns[i].ch[1]].rsum, ns[i].rsum);\n\
    \ }\n inline void propagate(node_id i, const E &x) {\n  if (i == -1) return;\n\
    \  M::mapping(ns[i].val, x), ns[i].lazy_flg ? (M::composition(ns[i].lazy, x),\
    \ x) : ns[i].lazy= x;\n  if constexpr (semigroup_v<M>) M::mapping(ns[i].sum, x),\
    \ M::mapping(ns[i].rsum, x);\n  ns[i].lazy_flg= true;\n }\n inline void toggle(node_id\
    \ i) {\n  if (i == -1) return;\n  std::swap(ns[i].ch[0], ns[i].ch[1]);\n  if constexpr\
    \ (semigroup_v<M>) std::swap(ns[i].sum, ns[i].rsum);\n  ns[i].rev_flg= !ns[i].rev_flg;\n\
    \ }\n inline void eval(node_id i) {\n  if (ns[i].rev_flg) toggle(ns[i].ch[0]),\
    \ toggle(ns[i].ch[1]), ns[i].rev_flg= false;\n  if constexpr (dual_v<M>)\n   if\
    \ (ns[i].lazy_flg) propagate(ns[i].ch[0], ns[i].lazy), propagate(ns[i].ch[1],\
    \ ns[i].lazy), ns[i].lazy_flg= false;\n }\n inline node_id expose(node_id i) {\n\
    \  node_id r= -1;\n  for (node_id p= i; p != -1; r= p, p= ns[p].par) {\n   splay(p),\
    \ ns[p].ch[1]= r;\n   if constexpr (semigroup_v<M>) pushup(p);\n  }\n  return\
    \ splay(i), r;\n }\n std::vector<Node> ns;\npublic:\n LinkCutTree(std::size_t\
    \ n): ns(n) {}\n LinkCutTree(std::size_t n, T val): ns(n) {\n  for (int i= n;\
    \ i--;) ns[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), eval(k);\
    \ }\n void link(int c, int p) {\n  evert(c), expose(p), assert(ns[c].par == -1),\
    \ ns[p].ch[1]= c, ns[c].par= p;\n  if constexpr (semigroup_v<M>) pushup(p);\n\
    \ }\n void cut(int c, int p) {\n  evert(p), expose(c), assert(ns[c].ch[0] == p),\
    \ ns[c].ch[0]= ns[p].par= -1;\n  if constexpr (semigroup_v<M>) pushup(c);\n }\n\
    \ int root(int x) {\n  for (expose(x);; x= ns[x].ch[0])\n   if (eval(x); ns[x].ch[0]\
    \ == -1) return splay(x), x;\n }\n int parent(int x) {\n  if (expose(x), x= ns[x].ch[0];\
    \ x == -1) return -1;\n  for (;; x= ns[x].ch[1])\n   if (eval(x); ns[x].ch[1]\
    \ == -1) return splay(x), x;\n }\n int lca(int x, int y) { return x == y ? x :\
    \ (expose(x), y= expose(y), ns[x].par == -1) ? -1 : y; }\n const T &operator[](int\
    \ k) { return get(k); }\n const T &get(int k) {\n  static_assert(semigroup_v<M>\
    \ || dual_v<M>, \"\\\"get\\\" is not available\\n\");\n  return expose(k), ns[k].val;\n\
    \ }\n void set(int k, T v) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\
    \"set\\\" is not available\\n\");\n  expose(k), ns[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) pushup(k);\n }\n T fold(int a, int b) {  // [a,b] closed section\n\
    \  static_assert(semigroup_v<M>, \"\\\"fold\\\" is not available\\n\");\n  return\
    \ a == b ? get(a) : (evert(a), expose(b), assert(ns[a].par != -1), ns[b].sum);\n\
    \ }\n void apply(int a, int b, E v) {  // [a,b] closed section\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\\n\");\n  evert(a), expose(b), assert(a ==\
    \ b || ns[a].par != -1), propagate(b, v), eval(b);\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M> || dual_v<M>) ret+=\
    \ \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"\
    fold\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n\
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <string>\n\
    #include <cstddef>\n#include <cassert>\n#include \"src/Internal/HAS_CHECK.hpp\"\
    \ntemplate <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n\
    \ HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L>\
    \ static constexpr bool semigroup_v= std::conjunction_v<has_T<L>, has_op<L>>;\n\
    \ template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n using node_id= std::int_least32_t;\n\
    \ template <class U= std::nullptr_t, class F= std::nullptr_t> struct Node_B {\n\
    \  using T= U;\n  using E= F;\n  node_id ch[2]= {-1, -1}, par= -1;\n  bool rev_flg;\n\
    \ };\n template <class D, bool sg, bool du> struct Node_D: Node_B<> {};\n template\
    \ <class D> struct Node_D<D, 1, 0>: Node_B<typename M::T> {\n  typename M::T val,\
    \ sum, rsum;\n };\n template <class D> struct Node_D<D, 0, 1>: Node_B<typename\
    \ M::T, typename M::E> {\n  typename M::T val;\n  typename M::E lazy;\n  bool\
    \ lazy_flg;\n };\n template <class D> struct Node_D<D, 1, 1>: Node_B<typename\
    \ M::T, typename M::E> {\n  typename M::T val, sum, rsum;\n  typename M::E lazy;\n\
    \  bool lazy_flg;\n };\n using Node= Node_D<void, semigroup_v<M>, dual_v<M>>;\n\
    \ using T= typename Node::T;\n using E= typename Node::E;\n inline int dir(node_id\
    \ i) {\n  if (ns[i].par != -1) {\n   if (ns[ns[i].par].ch[0] == i) return 0;\n\
    \   if (ns[ns[i].par].ch[1] == i) return 1;\n  }\n  return 2;\n }\n inline void\
    \ rot(node_id i) {\n  node_id p= ns[i].par;\n  int d= dir(i);\n  if ((ns[p].ch[d]=\
    \ ns[i].ch[!d]) != -1) ns[ns[p].ch[d]].par= p;\n  ns[i].ch[!d]= p, ns[i].par=\
    \ ns[p].par;\n  if ((d= dir(p)) < 2) ns[ns[p].par].ch[d]= i;\n  ns[p].par= i;\n\
    \  if constexpr (semigroup_v<M>) pushup(p);\n }\n inline void splay(node_id i)\
    \ {\n  eval(i);\n  node_id p= ns[i].par, pp;\n  for (int d= dir(i), c; d < 2;\
    \ rot(i), d= dir(i), p= ns[i].par) {\n   if (c= dir(p), pp= ns[p].par; c < 2)\
    \ eval(pp), eval(p), eval(i), rot(d == c ? p : i);\n   else eval(p), eval(i);\n\
    \  }\n  if constexpr (semigroup_v<M>) pushup(i);\n }\n inline void pushup(node_id\
    \ i) {\n  ns[i].rsum= ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum=\
    \ M::op(ns[ns[i].ch[0]].sum, ns[i].sum), ns[i].rsum= M::op(ns[i].rsum, ns[ns[i].ch[0]].rsum);\n\
    \  if (ns[i].ch[1] != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum), ns[i].rsum=\
    \ M::op(ns[ns[i].ch[1]].rsum, ns[i].rsum);\n }\n inline void propagate(node_id\
    \ i, const E &x) {\n  if (i == -1) return;\n  M::mapping(ns[i].val, x), ns[i].lazy_flg\
    \ ? (M::composition(ns[i].lazy, x), x) : ns[i].lazy= x;\n  if constexpr (semigroup_v<M>)\
    \ M::mapping(ns[i].sum, x), M::mapping(ns[i].rsum, x);\n  ns[i].lazy_flg= true;\n\
    \ }\n inline void toggle(node_id i) {\n  if (i == -1) return;\n  std::swap(ns[i].ch[0],\
    \ ns[i].ch[1]);\n  if constexpr (semigroup_v<M>) std::swap(ns[i].sum, ns[i].rsum);\n\
    \  ns[i].rev_flg= !ns[i].rev_flg;\n }\n inline void eval(node_id i) {\n  if (ns[i].rev_flg)\
    \ toggle(ns[i].ch[0]), toggle(ns[i].ch[1]), ns[i].rev_flg= false;\n  if constexpr\
    \ (dual_v<M>)\n   if (ns[i].lazy_flg) propagate(ns[i].ch[0], ns[i].lazy), propagate(ns[i].ch[1],\
    \ ns[i].lazy), ns[i].lazy_flg= false;\n }\n inline node_id expose(node_id i) {\n\
    \  node_id r= -1;\n  for (node_id p= i; p != -1; r= p, p= ns[p].par) {\n   splay(p),\
    \ ns[p].ch[1]= r;\n   if constexpr (semigroup_v<M>) pushup(p);\n  }\n  return\
    \ splay(i), r;\n }\n std::vector<Node> ns;\npublic:\n LinkCutTree(std::size_t\
    \ n): ns(n) {}\n LinkCutTree(std::size_t n, T val): ns(n) {\n  for (int i= n;\
    \ i--;) ns[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), eval(k);\
    \ }\n void link(int c, int p) {\n  evert(c), expose(p), assert(ns[c].par == -1),\
    \ ns[p].ch[1]= c, ns[c].par= p;\n  if constexpr (semigroup_v<M>) pushup(p);\n\
    \ }\n void cut(int c, int p) {\n  evert(p), expose(c), assert(ns[c].ch[0] == p),\
    \ ns[c].ch[0]= ns[p].par= -1;\n  if constexpr (semigroup_v<M>) pushup(c);\n }\n\
    \ int root(int x) {\n  for (expose(x);; x= ns[x].ch[0])\n   if (eval(x); ns[x].ch[0]\
    \ == -1) return splay(x), x;\n }\n int parent(int x) {\n  if (expose(x), x= ns[x].ch[0];\
    \ x == -1) return -1;\n  for (;; x= ns[x].ch[1])\n   if (eval(x); ns[x].ch[1]\
    \ == -1) return splay(x), x;\n }\n int lca(int x, int y) { return x == y ? x :\
    \ (expose(x), y= expose(y), ns[x].par == -1) ? -1 : y; }\n const T &operator[](int\
    \ k) { return get(k); }\n const T &get(int k) {\n  static_assert(semigroup_v<M>\
    \ || dual_v<M>, \"\\\"get\\\" is not available\\n\");\n  return expose(k), ns[k].val;\n\
    \ }\n void set(int k, T v) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\
    \"set\\\" is not available\\n\");\n  expose(k), ns[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) pushup(k);\n }\n T fold(int a, int b) {  // [a,b] closed section\n\
    \  static_assert(semigroup_v<M>, \"\\\"fold\\\" is not available\\n\");\n  return\
    \ a == b ? get(a) : (evert(a), expose(b), assert(ns[a].par != -1), ns[b].sum);\n\
    \ }\n void apply(int a, int b, E v) {  // [a,b] closed section\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\\n\");\n  evert(a), expose(b), assert(a ==\
    \ b || ns[a].par != -1), propagate(b, v), eval(b);\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M> || dual_v<M>) ret+=\
    \ \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"\
    fold\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n\
    \ }\n};"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2023-03-01 11:27:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - test/yosupo/lca.LCT.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - test/yukicoder/529.LCT.test.cpp
  - test/yukicoder/650.LCT.test.cpp
  - test/yukicoder/235.LCT.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/2270.Patricia.test.cpp
  - test/aoj/2450.LCT.test.cpp
  - test/atcoder/abc133_f.Patricia.test.cpp
  - test/atcoder/abc133_f.PerArr.test.cpp
  - test/atcoder/abc133_f.DynSeg.test.cpp
documentation_of: src/DataStructure/LinkCutTree.hpp
layout: document
title: Link-Cut-Tree
---
単位元は必要なし（遅延側も）\
各ノードが部分木のサイズを保持していないのでmapping関数では引数としてsizeを渡せない
## 計算量
$\mathcal{O}(\log n)$