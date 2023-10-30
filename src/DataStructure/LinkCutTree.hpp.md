---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
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
  - icon: ':x:'
    path: test/atcoder/abc133_f.DynSeg.test.cpp
    title: test/atcoder/abc133_f.DynSeg.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc133_f.Patricia.test.cpp
    title: test/atcoder/abc133_f.Patricia.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc133_f.PerArr.test.cpp
    title: test/atcoder/abc133_f.PerArr.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/lca.LCT.test.cpp
    title: test/yosupo/lca.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.LCT.test.cpp
    title: test/yukicoder/235.LCT.test.cpp
  - icon: ':x:'
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
    #line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n#define MEMBER_MACRO(member,\
    \ Dummy, name, type1, type2, last) \\\n template <class tClass> struct name##member\
    \ { \\\n  template <class U, Dummy> static type1 check(U *); \\\n  static type2\
    \ check(...); \\\n  static tClass *mClass; \\\n  last; \\\n };\n#define HAS_CHECK(member,\
    \ Dummy) MEMBER_MACRO(member, Dummy, has_, std::true_type, std::false_type, static\
    \ const bool value= decltype(check(mClass))::value)\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#define HOGE_OR(member, name, type2) \\\n\
    \ MEMBER_MACRO(member, class dummy= typename U::member, name, typename U::member,\
    \ type2, using type= decltype(check(mClass))) \\\n template <class tClass> using\
    \ name##member##_t= typename name##member<tClass>::type;\n#define NULLPTR_OR(member)\
    \ HOGE_OR(member, nullptr_or_, std::nullptr_t);\n#define MYSELF_OR(member) HOGE_OR(member,\
    \ myself_or_, tClass);\n#line 8 \"src/DataStructure/LinkCutTree.hpp\"\ntemplate\
    \ <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mp);\n\
    \ HAS_MEMBER(cp);\n HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(T);\n NULLPTR_OR(E);\n\
    \ template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n struct Node_B {\n  int ch[2]= {-1, -1}, par=\
    \ -1;\n  bool rev_flg;\n };\n template <class D, bool sg, bool du> struct Node_D:\
    \ Node_B {};\n template <class D> struct Node_D<D, 1, 0>: Node_B {\n  typename\
    \ M::T val, sum, rsum;\n };\n template <class D> struct Node_D<D, 0, 1>: Node_B\
    \ {\n  typename M::T val;\n  typename M::E laz;\n  bool laz_flg;\n };\n template\
    \ <class D> struct Node_D<D, 1, 1>: Node_B {\n  typename M::T val, sum, rsum;\n\
    \  typename M::E laz;\n  bool laz_flg;\n };\n using Node= Node_D<void, semigroup_v<M>,\
    \ dual_v<M>>;\n using T= nullptr_or_T_t<M>;\n using E= nullptr_or_E_t<M>;\n inline\
    \ int dir(int i) {\n  if (ns[i].par != -1) {\n   if (ns[ns[i].par].ch[0] == i)\
    \ return 0;\n   if (ns[ns[i].par].ch[1] == i) return 1;\n  }\n  return 2;\n }\n\
    \ inline void rot(int i) {\n  int p= ns[i].par;\n  int d= dir(i);\n  if ((ns[p].ch[d]=\
    \ ns[i].ch[!d]) != -1) ns[ns[p].ch[d]].par= p;\n  ns[i].ch[!d]= p, ns[i].par=\
    \ ns[p].par;\n  if ((d= dir(p)) < 2) ns[ns[p].par].ch[d]= i;\n  ns[p].par= i;\n\
    \  if constexpr (semigroup_v<M>) update(p);\n }\n inline void splay(int i) {\n\
    \  push(i);\n  int p= ns[i].par, pp;\n  for (int d= dir(i), c; d < 2; rot(i),\
    \ d= dir(i), p= ns[i].par) {\n   if (c= dir(p), pp= ns[p].par; c < 2) push(pp),\
    \ push(p), push(i), rot(d == c ? p : i);\n   else push(p), push(i);\n  }\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n inline void update(int i) {\n  ns[i].rsum=\
    \ ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum= M::op(ns[ns[i].ch[0]].sum,\
    \ ns[i].sum), ns[i].rsum= M::op(ns[i].rsum, ns[ns[i].ch[0]].rsum);\n  if (ns[i].ch[1]\
    \ != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum), ns[i].rsum= M::op(ns[ns[i].ch[1]].rsum,\
    \ ns[i].rsum);\n }\n inline void propagate(int i, const E &x) {\n  if (i == -1)\
    \ return;\n  if (ns[i].laz_flg) M::cp(ns[i].laz, x);\n  else ns[i].laz= x;\n \
    \ if constexpr (semigroup_v<M>) M::mp(ns[i].sum, x), M::mp(ns[i].rsum, x);\n \
    \ M::mp(ns[i].val, x), ns[i].laz_flg= true;\n }\n inline void toggle(int i) {\n\
    \  if (i == -1) return;\n  std::swap(ns[i].ch[0], ns[i].ch[1]);\n  if constexpr\
    \ (semigroup_v<M>) std::swap(ns[i].sum, ns[i].rsum);\n  ns[i].rev_flg= !ns[i].rev_flg;\n\
    \ }\n inline void push(int i) {\n  if (ns[i].rev_flg) toggle(ns[i].ch[0]), toggle(ns[i].ch[1]),\
    \ ns[i].rev_flg= false;\n  if constexpr (dual_v<M>)\n   if (ns[i].laz_flg) propagate(ns[i].ch[0],\
    \ ns[i].laz), propagate(ns[i].ch[1], ns[i].laz), ns[i].laz_flg= false;\n }\n inline\
    \ int expose(int i) {\n  int r= -1;\n  for (int p= i; p != -1; r= p, p= ns[p].par)\
    \ {\n   splay(p), ns[p].ch[1]= r;\n   if constexpr (semigroup_v<M>) update(p);\n\
    \  }\n  return splay(i), r;\n }\n std::vector<Node> ns;\npublic:\n LinkCutTree(size_t\
    \ n): ns(n) {}\n LinkCutTree(size_t n, T val): ns(n) {\n  for (int i= n; i--;)\
    \ ns[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), push(k); }\n\
    \ void link(int c, int p) {\n  evert(c), expose(p), assert(ns[c].par == -1), ns[p].ch[1]=\
    \ c, ns[c].par= p;\n  if constexpr (semigroup_v<M>) update(p);\n }\n void cut(int\
    \ c, int p) {\n  evert(p), expose(c), assert(ns[c].ch[0] == p), ns[c].ch[0]= ns[p].par=\
    \ -1;\n  if constexpr (semigroup_v<M>) update(c);\n }\n int root(int x) {\n  for\
    \ (expose(x);; x= ns[x].ch[0])\n   if (push(x); ns[x].ch[0] == -1) return splay(x),\
    \ x;\n }\n int parent(int x) {\n  if (expose(x), x= ns[x].ch[0]; x == -1) return\
    \ -1;\n  for (;; x= ns[x].ch[1])\n   if (push(x); ns[x].ch[1] == -1) return splay(x),\
    \ x;\n }\n int lca(int x, int y) { return x == y ? x : (expose(x), y= expose(y),\
    \ ns[x].par == -1) ? -1 : y; }\n const T &operator[](int k) { return get(k); }\n\
    \ const T &get(int k) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"get\\\
    \" is not available\\n\");\n  return expose(k), ns[k].val;\n }\n void set(int\
    \ k, T v) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"set\\\" is not\
    \ available\\n\");\n  expose(k), ns[k].val= v;\n  if constexpr (semigroup_v<M>)\
    \ update(k);\n }\n T fold(int a, int b) {  // [a,b] closed section\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return a == b ? get(a) : (evert(a),\
    \ expose(b), assert(ns[a].par != -1), ns[b].sum);\n }\n void apply(int a, int\
    \ b, E v) {  // [a,b] closed section\n  static_assert(dual_v<M>, \"\\\"apply\\\
    \" is not available\\n\");\n  evert(a), expose(b), assert(a == b || ns[a].par\
    \ != -1), propagate(b, v), push(b);\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M> || dual_v<M>) ret+=\
    \ \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"\
    fold\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n\
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <string>\n\
    #include <cstddef>\n#include <cassert>\n#include \"src/Internal/HAS_CHECK.hpp\"\
    \ntemplate <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mp);\n\
    \ HAS_MEMBER(cp);\n HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(T);\n NULLPTR_OR(E);\n\
    \ template <class L> static constexpr bool semigroup_v= std::conjunction_v<has_T<L>,\
    \ has_op<L>>;\n template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>,\
    \ has_E<L>, has_mp<L>, has_cp<L>>;\n struct Node_B {\n  int ch[2]= {-1, -1}, par=\
    \ -1;\n  bool rev_flg;\n };\n template <class D, bool sg, bool du> struct Node_D:\
    \ Node_B {};\n template <class D> struct Node_D<D, 1, 0>: Node_B {\n  typename\
    \ M::T val, sum, rsum;\n };\n template <class D> struct Node_D<D, 0, 1>: Node_B\
    \ {\n  typename M::T val;\n  typename M::E laz;\n  bool laz_flg;\n };\n template\
    \ <class D> struct Node_D<D, 1, 1>: Node_B {\n  typename M::T val, sum, rsum;\n\
    \  typename M::E laz;\n  bool laz_flg;\n };\n using Node= Node_D<void, semigroup_v<M>,\
    \ dual_v<M>>;\n using T= nullptr_or_T_t<M>;\n using E= nullptr_or_E_t<M>;\n inline\
    \ int dir(int i) {\n  if (ns[i].par != -1) {\n   if (ns[ns[i].par].ch[0] == i)\
    \ return 0;\n   if (ns[ns[i].par].ch[1] == i) return 1;\n  }\n  return 2;\n }\n\
    \ inline void rot(int i) {\n  int p= ns[i].par;\n  int d= dir(i);\n  if ((ns[p].ch[d]=\
    \ ns[i].ch[!d]) != -1) ns[ns[p].ch[d]].par= p;\n  ns[i].ch[!d]= p, ns[i].par=\
    \ ns[p].par;\n  if ((d= dir(p)) < 2) ns[ns[p].par].ch[d]= i;\n  ns[p].par= i;\n\
    \  if constexpr (semigroup_v<M>) update(p);\n }\n inline void splay(int i) {\n\
    \  push(i);\n  int p= ns[i].par, pp;\n  for (int d= dir(i), c; d < 2; rot(i),\
    \ d= dir(i), p= ns[i].par) {\n   if (c= dir(p), pp= ns[p].par; c < 2) push(pp),\
    \ push(p), push(i), rot(d == c ? p : i);\n   else push(p), push(i);\n  }\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n inline void update(int i) {\n  ns[i].rsum=\
    \ ns[i].sum= ns[i].val;\n  if (ns[i].ch[0] != -1) ns[i].sum= M::op(ns[ns[i].ch[0]].sum,\
    \ ns[i].sum), ns[i].rsum= M::op(ns[i].rsum, ns[ns[i].ch[0]].rsum);\n  if (ns[i].ch[1]\
    \ != -1) ns[i].sum= M::op(ns[i].sum, ns[ns[i].ch[1]].sum), ns[i].rsum= M::op(ns[ns[i].ch[1]].rsum,\
    \ ns[i].rsum);\n }\n inline void propagate(int i, const E &x) {\n  if (i == -1)\
    \ return;\n  if (ns[i].laz_flg) M::cp(ns[i].laz, x);\n  else ns[i].laz= x;\n \
    \ if constexpr (semigroup_v<M>) M::mp(ns[i].sum, x), M::mp(ns[i].rsum, x);\n \
    \ M::mp(ns[i].val, x), ns[i].laz_flg= true;\n }\n inline void toggle(int i) {\n\
    \  if (i == -1) return;\n  std::swap(ns[i].ch[0], ns[i].ch[1]);\n  if constexpr\
    \ (semigroup_v<M>) std::swap(ns[i].sum, ns[i].rsum);\n  ns[i].rev_flg= !ns[i].rev_flg;\n\
    \ }\n inline void push(int i) {\n  if (ns[i].rev_flg) toggle(ns[i].ch[0]), toggle(ns[i].ch[1]),\
    \ ns[i].rev_flg= false;\n  if constexpr (dual_v<M>)\n   if (ns[i].laz_flg) propagate(ns[i].ch[0],\
    \ ns[i].laz), propagate(ns[i].ch[1], ns[i].laz), ns[i].laz_flg= false;\n }\n inline\
    \ int expose(int i) {\n  int r= -1;\n  for (int p= i; p != -1; r= p, p= ns[p].par)\
    \ {\n   splay(p), ns[p].ch[1]= r;\n   if constexpr (semigroup_v<M>) update(p);\n\
    \  }\n  return splay(i), r;\n }\n std::vector<Node> ns;\npublic:\n LinkCutTree(size_t\
    \ n): ns(n) {}\n LinkCutTree(size_t n, T val): ns(n) {\n  for (int i= n; i--;)\
    \ ns[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), push(k); }\n\
    \ void link(int c, int p) {\n  evert(c), expose(p), assert(ns[c].par == -1), ns[p].ch[1]=\
    \ c, ns[c].par= p;\n  if constexpr (semigroup_v<M>) update(p);\n }\n void cut(int\
    \ c, int p) {\n  evert(p), expose(c), assert(ns[c].ch[0] == p), ns[c].ch[0]= ns[p].par=\
    \ -1;\n  if constexpr (semigroup_v<M>) update(c);\n }\n int root(int x) {\n  for\
    \ (expose(x);; x= ns[x].ch[0])\n   if (push(x); ns[x].ch[0] == -1) return splay(x),\
    \ x;\n }\n int parent(int x) {\n  if (expose(x), x= ns[x].ch[0]; x == -1) return\
    \ -1;\n  for (;; x= ns[x].ch[1])\n   if (push(x); ns[x].ch[1] == -1) return splay(x),\
    \ x;\n }\n int lca(int x, int y) { return x == y ? x : (expose(x), y= expose(y),\
    \ ns[x].par == -1) ? -1 : y; }\n const T &operator[](int k) { return get(k); }\n\
    \ const T &get(int k) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"get\\\
    \" is not available\\n\");\n  return expose(k), ns[k].val;\n }\n void set(int\
    \ k, T v) {\n  static_assert(semigroup_v<M> || dual_v<M>, \"\\\"set\\\" is not\
    \ available\\n\");\n  expose(k), ns[k].val= v;\n  if constexpr (semigroup_v<M>)\
    \ update(k);\n }\n T fold(int a, int b) {  // [a,b] closed section\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return a == b ? get(a) : (evert(a),\
    \ expose(b), assert(ns[a].par != -1), ns[b].sum);\n }\n void apply(int a, int\
    \ b, E v) {  // [a,b] closed section\n  static_assert(dual_v<M>, \"\\\"apply\\\
    \" is not available\\n\");\n  evert(a), expose(b), assert(a == b || ns[a].par\
    \ != -1), propagate(b, v), push(b);\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M> || dual_v<M>) ret+=\
    \ \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup_v<M>) ret+= \"\\\"\
    fold\\\" \";\n  if constexpr (dual_v<M>) ret+= \"\\\"apply\\\" \";\n  return ret;\n\
    \ }\n};"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2023-10-30 14:53:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2450.LCT.test.cpp
  - test/aoj/2270.Patricia.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - test/yosupo/lca.LCT.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - test/yukicoder/529.LCT.test.cpp
  - test/yukicoder/235.LCT.test.cpp
  - test/yukicoder/650.LCT.test.cpp
  - test/atcoder/abc133_f.PerArr.test.cpp
  - test/atcoder/abc133_f.Patricia.test.cpp
  - test/atcoder/abc133_f.DynSeg.test.cpp
documentation_of: src/DataStructure/LinkCutTree.hpp
layout: document
title: Link-Cut-Tree
---
単位元は必要なし（遅延側も）\
各ノードが部分木のサイズを保持していないのでmapping関数では引数としてsizeを渡せない
## 計算量
$\mathcal{O}(\log n)$