---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/detection_idiom.hpp
    title: detection idiom
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2450.LCT.test.cpp
    title: test/aoj/2450.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT.test.cpp
    title: test/aoj/2559.LCT.test.cpp
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
    path: test/yosupo/vertex_add_path_sum.LCT.test.cpp
    title: test/yosupo/vertex_add_path_sum.LCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.LCT.test.cpp
    title: test/yosupo/vertex_set_path_composite.LCT.test.cpp
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
    #line 2 \"src/Internal/detection_idiom.hpp\"\n#include <type_traits>\n#define\
    \ _DETECT_BOOL(name, ...) \\\n template <class, class= void> struct name: std::false_type\
    \ {}; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>: std::true_type\
    \ {}; \\\n template <class T> static constexpr bool name##_v= name<T>::value\n\
    #define _DETECT_TYPE(name, type1, type2, ...) \\\n template <class T, class= void>\
    \ struct name { \\\n  using type= type2; \\\n }; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>> { \\\n  using type= type1; \\\n }\n#line 8\
    \ \"src/DataStructure/LinkCutTree.hpp\"\ntemplate <class M= void> class LinkCutTree\
    \ {\n _DETECT_BOOL(semigroup, typename T::T, decltype(&T::op));\n _DETECT_BOOL(dual,\
    \ typename T::T, typename T::E, decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute,\
    \ typename T::commute);\n _DETECT_TYPE(myself_or_T, typename T::T, T, typename\
    \ T::T);\n _DETECT_TYPE(nullptr_or_E, typename T::E, std::nullptr_t, typename\
    \ T::E);\n using T= std::conditional_t<std::is_void_v<M>, std::nullptr_t, typename\
    \ myself_or_T<M>::type>;\n using E= typename nullptr_or_E<M>::type;\n struct NodeB\
    \ {\n  int ch[2]= {-1, -1}, par= -1;\n  bool revf= 0;\n };\n template <class D,\
    \ class A> struct NodeV: NodeB {\n  T val;\n };\n template <class D> struct NodeV<D,\
    \ void>: NodeB {};\n template <class D, bool du> struct NodeD: NodeV<D, M> {};\n\
    \ template <class D> struct NodeD<D, 1>: NodeV<D, M> {\n  E laz;\n  bool lazf=\
    \ 0;\n };\n template <class D, bool sg, bool com> struct NodeS: NodeD<D, dual_v<M>>\
    \ {};\n template <class D> struct NodeS<D, 1, 1>: NodeD<D, dual_v<M>> {\n  T sum;\n\
    \ };\n template <class D> struct NodeS<D, 1, 0>: NodeD<D, dual_v<M>> {\n  T sum,\
    \ rsum;\n };\n using Node= NodeS<void, semigroup_v<M>, commute_v<M>>;\n std::vector<Node>\
    \ n;\n inline void update(int i) {\n  n[i].sum= n[i].val;\n  if constexpr (!commute_v<M>)\
    \ n[i].rsum= n[i].val;\n  if (int l= n[i].ch[0]; l != -1) {\n   n[i].sum= M::op(n[l].sum,\
    \ n[i].sum);\n   if constexpr (!commute_v<M>) n[i].rsum= M::op(n[i].rsum, n[l].rsum);\n\
    \  }\n  if (int r= n[i].ch[1]; r != -1) {\n   n[i].sum= M::op(n[i].sum, n[r].sum);\n\
    \   if constexpr (!commute_v<M>) n[i].rsum= M::op(n[r].rsum, n[i].rsum);\n  }\n\
    \ }\n inline void propagate(int i, const E &x) {\n  if (i == -1) return;\n  if\
    \ (n[i].lazf) M::cp(n[i].laz, x);\n  else n[i].laz= x;\n  if constexpr (semigroup_v<M>)\
    \ {\n   M::mp(n[i].sum, x);\n   if constexpr (!commute_v<M>) M::mp(n[i].rsum,\
    \ x);\n  }\n  M::mp(n[i].val, x), n[i].lazf= 1;\n }\n inline void toggle(int i)\
    \ {\n  if (i == -1) return;\n  std::swap(n[i].ch[0], n[i].ch[1]);\n  if constexpr\
    \ (semigroup_v<M> && !commute_v<M>) std::swap(n[i].sum, n[i].rsum);\n  n[i].revf^=\
    \ 1;\n }\n inline void push(int i) {\n  if (n[i].revf) toggle(n[i].ch[0]), toggle(n[i].ch[1]),\
    \ n[i].revf= 0;\n  if constexpr (dual_v<M>)\n   if (n[i].lazf) propagate(n[i].ch[0],\
    \ n[i].laz), propagate(n[i].ch[1], n[i].laz), n[i].lazf= 0;\n }\n inline int dir(int\
    \ i) {\n  if (int p= n[i].par; p != -1) {\n   if (n[p].ch[0] == i) return 0;\n\
    \   if (n[p].ch[1] == i) return 1;\n  }\n  return 2;\n }\n inline void rot(int\
    \ i) {\n  int p= n[i].par, d= n[p].ch[1] == i;\n  if (int c= n[p].ch[d]= std::exchange(n[i].ch[!d],\
    \ p); c != -1) n[c].par= p;\n  if (d= dir(p); d < 2) n[n[p].par].ch[d]= i;\n \
    \ n[i].par= std::exchange(n[p].par, i);\n  if constexpr (semigroup_v<M>) update(p);\n\
    \ }\n inline void splay(int i) {\n  push(i);\n  for (int d; d= dir(i), d < 2;\
    \ rot(i))\n   if (int p= n[i].par, c= dir(p), pp= n[p].par; c < 2) push(pp), push(p),\
    \ push(i), rot(d == c ? p : i);\n   else push(p), push(i);\n  if constexpr (semigroup_v<M>)\
    \ update(i);\n }\n inline int expose(int i) {\n  int r= -1;\n  for (int p= i;\
    \ p != -1; r= p, p= n[p].par) {\n   splay(p), n[p].ch[1]= r;\n   if constexpr\
    \ (semigroup_v<M>) update(p);\n  }\n  return splay(i), r;\n }\npublic:\n LinkCutTree(size_t\
    \ sz): n(sz) {}\n LinkCutTree(size_t sz, T val): n(sz) {\n  for (int i= sz; i--;)\
    \ n[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), push(k); }\n\
    \ void link(int c, int p) {\n  evert(c), expose(p), assert(n[c].par == -1), n[p].ch[1]=\
    \ c, n[c].par= p;\n  if constexpr (semigroup_v<M>) update(p);\n }\n void cut(int\
    \ c, int p) {\n  evert(c), expose(p), assert(n[c].ch[0] == p), n[c].ch[0]= n[p].par=\
    \ -1;\n  if constexpr (semigroup_v<M>) update(c);\n }\n int root(int x) {\n  for\
    \ (expose(x);; x= n[x].ch[0])\n   if (push(x), n[x].ch[0] == -1) return splay(x),\
    \ x;\n }\n int parent(int x) {\n  if (expose(x), x= n[x].ch[0]; x == -1) return\
    \ -1;\n  for (;; x= n[x].ch[1])\n   if (push(x), n[x].ch[1] == -1) return splay(x),\
    \ x;\n }\n int lca(int x, int y) { return x == y ? x : (expose(x), y= expose(y),\
    \ n[x].par == -1) ? -1 : y; }\n const T &get(int k) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"get\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n T\
    \ &at(int k) {\n  static_assert(!std::is_void_v<M> && !semigroup_v<M>, \"\\\"\
    at\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n template <class\
    \ L= M> const std::enable_if_t<semigroup_v<L>, T> &operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n void set(int k, const T &v) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"set\\\" is not available\\n\");\n  expose(k), n[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) update(k);\n }\n void mul(int k, const T &v) {\n  static_assert(semigroup_v<M>\
    \ && commute_v<M>, \"\\\"mul\\\" is not available\\n\");\n  expose(k), n[k].val=\
    \ M::op(n[k].val, v), update(k);\n }\n // [a,b] closed section\n T prod(int a,\
    \ int b) {\n  static_assert(semigroup_v<M>, \"\\\"prod\\\" is not available\\\
    n\");\n  return a == b ? get(a) : (evert(a), expose(b), assert(n[a].par != -1),\
    \ n[b].sum);\n }\n // [a,b] closed section\n void apply(int a, int b, const E\
    \ &v) {\n  static_assert(dual_v<M>, \"\\\"apply\\\" is not available\\n\");\n\
    \  evert(a), expose(b), assert(a == b || n[a].par != -1), propagate(b, v), push(b);\n\
    \ }\n static std::string which_unavailable() {\n  std::string ret= \"\";\n  if\
    \ constexpr (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"prod\\\
    \" \";\n  if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\"\
    \ \";\n  if constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (std::is_void_v<M>)\
    \ ret+= \"\\\"get\\\" \\\"set\\\" \";\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <string>\n\
    #include <cstddef>\n#include <cassert>\n#include \"src/Internal/detection_idiom.hpp\"\
    \ntemplate <class M= void> class LinkCutTree {\n _DETECT_BOOL(semigroup, typename\
    \ T::T, decltype(&T::op));\n _DETECT_BOOL(dual, typename T::T, typename T::E,\
    \ decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute, typename T::commute);\n\
    \ _DETECT_TYPE(myself_or_T, typename T::T, T, typename T::T);\n _DETECT_TYPE(nullptr_or_E,\
    \ typename T::E, std::nullptr_t, typename T::E);\n using T= std::conditional_t<std::is_void_v<M>,\
    \ std::nullptr_t, typename myself_or_T<M>::type>;\n using E= typename nullptr_or_E<M>::type;\n\
    \ struct NodeB {\n  int ch[2]= {-1, -1}, par= -1;\n  bool revf= 0;\n };\n template\
    \ <class D, class A> struct NodeV: NodeB {\n  T val;\n };\n template <class D>\
    \ struct NodeV<D, void>: NodeB {};\n template <class D, bool du> struct NodeD:\
    \ NodeV<D, M> {};\n template <class D> struct NodeD<D, 1>: NodeV<D, M> {\n  E\
    \ laz;\n  bool lazf= 0;\n };\n template <class D, bool sg, bool com> struct NodeS:\
    \ NodeD<D, dual_v<M>> {};\n template <class D> struct NodeS<D, 1, 1>: NodeD<D,\
    \ dual_v<M>> {\n  T sum;\n };\n template <class D> struct NodeS<D, 1, 0>: NodeD<D,\
    \ dual_v<M>> {\n  T sum, rsum;\n };\n using Node= NodeS<void, semigroup_v<M>,\
    \ commute_v<M>>;\n std::vector<Node> n;\n inline void update(int i) {\n  n[i].sum=\
    \ n[i].val;\n  if constexpr (!commute_v<M>) n[i].rsum= n[i].val;\n  if (int l=\
    \ n[i].ch[0]; l != -1) {\n   n[i].sum= M::op(n[l].sum, n[i].sum);\n   if constexpr\
    \ (!commute_v<M>) n[i].rsum= M::op(n[i].rsum, n[l].rsum);\n  }\n  if (int r= n[i].ch[1];\
    \ r != -1) {\n   n[i].sum= M::op(n[i].sum, n[r].sum);\n   if constexpr (!commute_v<M>)\
    \ n[i].rsum= M::op(n[r].rsum, n[i].rsum);\n  }\n }\n inline void propagate(int\
    \ i, const E &x) {\n  if (i == -1) return;\n  if (n[i].lazf) M::cp(n[i].laz, x);\n\
    \  else n[i].laz= x;\n  if constexpr (semigroup_v<M>) {\n   M::mp(n[i].sum, x);\n\
    \   if constexpr (!commute_v<M>) M::mp(n[i].rsum, x);\n  }\n  M::mp(n[i].val,\
    \ x), n[i].lazf= 1;\n }\n inline void toggle(int i) {\n  if (i == -1) return;\n\
    \  std::swap(n[i].ch[0], n[i].ch[1]);\n  if constexpr (semigroup_v<M> && !commute_v<M>)\
    \ std::swap(n[i].sum, n[i].rsum);\n  n[i].revf^= 1;\n }\n inline void push(int\
    \ i) {\n  if (n[i].revf) toggle(n[i].ch[0]), toggle(n[i].ch[1]), n[i].revf= 0;\n\
    \  if constexpr (dual_v<M>)\n   if (n[i].lazf) propagate(n[i].ch[0], n[i].laz),\
    \ propagate(n[i].ch[1], n[i].laz), n[i].lazf= 0;\n }\n inline int dir(int i) {\n\
    \  if (int p= n[i].par; p != -1) {\n   if (n[p].ch[0] == i) return 0;\n   if (n[p].ch[1]\
    \ == i) return 1;\n  }\n  return 2;\n }\n inline void rot(int i) {\n  int p= n[i].par,\
    \ d= n[p].ch[1] == i;\n  if (int c= n[p].ch[d]= std::exchange(n[i].ch[!d], p);\
    \ c != -1) n[c].par= p;\n  if (d= dir(p); d < 2) n[n[p].par].ch[d]= i;\n  n[i].par=\
    \ std::exchange(n[p].par, i);\n  if constexpr (semigroup_v<M>) update(p);\n }\n\
    \ inline void splay(int i) {\n  push(i);\n  for (int d; d= dir(i), d < 2; rot(i))\n\
    \   if (int p= n[i].par, c= dir(p), pp= n[p].par; c < 2) push(pp), push(p), push(i),\
    \ rot(d == c ? p : i);\n   else push(p), push(i);\n  if constexpr (semigroup_v<M>)\
    \ update(i);\n }\n inline int expose(int i) {\n  int r= -1;\n  for (int p= i;\
    \ p != -1; r= p, p= n[p].par) {\n   splay(p), n[p].ch[1]= r;\n   if constexpr\
    \ (semigroup_v<M>) update(p);\n  }\n  return splay(i), r;\n }\npublic:\n LinkCutTree(size_t\
    \ sz): n(sz) {}\n LinkCutTree(size_t sz, T val): n(sz) {\n  for (int i= sz; i--;)\
    \ n[i].val= val;\n }\n void evert(int k) { expose(k), toggle(k), push(k); }\n\
    \ void link(int c, int p) {\n  evert(c), expose(p), assert(n[c].par == -1), n[p].ch[1]=\
    \ c, n[c].par= p;\n  if constexpr (semigroup_v<M>) update(p);\n }\n void cut(int\
    \ c, int p) {\n  evert(c), expose(p), assert(n[c].ch[0] == p), n[c].ch[0]= n[p].par=\
    \ -1;\n  if constexpr (semigroup_v<M>) update(c);\n }\n int root(int x) {\n  for\
    \ (expose(x);; x= n[x].ch[0])\n   if (push(x), n[x].ch[0] == -1) return splay(x),\
    \ x;\n }\n int parent(int x) {\n  if (expose(x), x= n[x].ch[0]; x == -1) return\
    \ -1;\n  for (;; x= n[x].ch[1])\n   if (push(x), n[x].ch[1] == -1) return splay(x),\
    \ x;\n }\n int lca(int x, int y) { return x == y ? x : (expose(x), y= expose(y),\
    \ n[x].par == -1) ? -1 : y; }\n const T &get(int k) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"get\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n T\
    \ &at(int k) {\n  static_assert(!std::is_void_v<M> && !semigroup_v<M>, \"\\\"\
    at\\\" is not available\\n\");\n  return expose(k), n[k].val;\n }\n template <class\
    \ L= M> const std::enable_if_t<semigroup_v<L>, T> &operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n void set(int k, const T &v) {\n  static_assert(!std::is_void_v<M>,\
    \ \"\\\"set\\\" is not available\\n\");\n  expose(k), n[k].val= v;\n  if constexpr\
    \ (semigroup_v<M>) update(k);\n }\n void mul(int k, const T &v) {\n  static_assert(semigroup_v<M>\
    \ && commute_v<M>, \"\\\"mul\\\" is not available\\n\");\n  expose(k), n[k].val=\
    \ M::op(n[k].val, v), update(k);\n }\n // [a,b] closed section\n T prod(int a,\
    \ int b) {\n  static_assert(semigroup_v<M>, \"\\\"prod\\\" is not available\\\
    n\");\n  return a == b ? get(a) : (evert(a), expose(b), assert(n[a].par != -1),\
    \ n[b].sum);\n }\n // [a,b] closed section\n void apply(int a, int b, const E\
    \ &v) {\n  static_assert(dual_v<M>, \"\\\"apply\\\" is not available\\n\");\n\
    \  evert(a), expose(b), assert(a == b || n[a].par != -1), propagate(b, v), push(b);\n\
    \ }\n static std::string which_unavailable() {\n  std::string ret= \"\";\n  if\
    \ constexpr (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"prod\\\
    \" \";\n  if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\"\
    \ \";\n  if constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (std::is_void_v<M>)\
    \ ret+= \"\\\"get\\\" \\\"set\\\" \";\n  return ret;\n }\n};"
  dependsOn:
  - src/Internal/detection_idiom.hpp
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/529.LCT.test.cpp
  - test/yukicoder/650.LCT.test.cpp
  - test/yukicoder/235.LCT.test.cpp
  - test/yosupo/vertex_set_path_composite.LCT.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - test/yosupo/lca.LCT.test.cpp
  - test/yosupo/vertex_add_path_sum.LCT.test.cpp
  - test/aoj/2559.LCT.test.cpp
  - test/aoj/2450.LCT.test.cpp
documentation_of: src/DataStructure/LinkCutTree.hpp
layout: document
title: Link-Cut-Tree
---
単位元は必要なし（遅延側も）\
各ノードが部分木のサイズを保持していないのでmapping関数では引数としてsizeを渡せない
## 計算量
$\mathcal{O}(\log n)$