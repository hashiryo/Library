---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':heavy_check_mark:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.LCT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include <iostream>\n#line 2 \"src/DataStructure/LinkCutTree.hpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#include <string>\n#include <cstddef>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include <type_traits>\n\
    #define HAS_CHECK(member, Dummy) \\\n template <class tClass> struct has_##member\
    \ { \\\n  template <class U, Dummy> static std::true_type check(U *); \\\n  static\
    \ std::false_type check(...); \\\n  static tClass *mClass; \\\n  static const\
    \ bool value= decltype(check(mClass))::value; \\\n };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy= (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy= typename U::member)\n#line 8 \"src/DataStructure/LinkCutTree.hpp\"\
    \ntemplate <typename M= void> class LinkCutTree {\n HAS_MEMBER(op);\n HAS_MEMBER(mapping);\n\
    \ HAS_MEMBER(composition);\n HAS_TYPE(T);\n HAS_TYPE(E);\n template <class L>\
    \ using semigroup= std::conjunction<has_T<L>, has_op<L>>;\n template <class L>\
    \ using dual= std::conjunction<has_T<L>, has_E<L>, has_mapping<L>, has_composition<L>>;\n\
    \ template <class tDerived, class U= std::nullptr_t, class F= std::nullptr_t>\
    \ struct Node_B {\n  using T= U;\n  using E= F;\n  tDerived *ch[2], *par;\n  bool\
    \ rev_flg;\n };\n template <bool sg_, bool du_, typename tEnable= void> struct\
    \ Node_D: Node_B<Node_D<sg_, du_, tEnable>> {};\n template <bool sg_, bool du_>\
    \ struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && !du_>>: Node_B<Node_D<sg_,\
    \ du_>, typename M::T> { typename M::T val, sum, rsum; };\n template <bool sg_,\
    \ bool du_> struct Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>: Node_B<Node_D<sg_,\
    \ du_>, typename M::T, typename M::E> {\n  typename M::T val;\n  typename M::E\
    \ lazy;\n  bool lazy_flg;\n };\n template <bool sg_, bool du_> struct Node_D<sg_,\
    \ du_, typename std::enable_if_t<sg_ && du_>>: Node_B<Node_D<sg_, du_>, typename\
    \ M::T, typename M::E> {\n  typename M::T val, sum, rsum;\n  typename M::E lazy;\n\
    \  bool lazy_flg;\n };\n using Node= Node_D<semigroup<M>::value, dual<M>::value>;\n\
    \ using T= typename Node::T;\n using E= typename Node::E;\n static inline int\
    \ dir(Node *&t) {\n  if (t->par) {\n   if (t->par->ch[0] == t) return 0;\n   if\
    \ (t->par->ch[1] == t) return 1;\n  }\n  return 2;\n }\n static inline void rot(Node\
    \ *t) {\n  Node *p= t->par;\n  int d= dir(t);\n  if ((p->ch[d]= t->ch[!d])) p->ch[d]->par=\
    \ p;\n  t->ch[!d]= p;\n  if constexpr (semigroup<M>::value) pushup(p), pushup(t);\n\
    \  t->par= p->par;\n  if ((d= dir(p)) < 2) {\n   p->par->ch[d]= t;\n   if constexpr\
    \ (semigroup<M>::value) pushup(t->par);\n  }\n  p->par= t;\n }\n static inline\
    \ void splay(Node *t) {\n  eval(t);\n  for (int t_d= dir(t), p_d; t_d < 2; rot(t),\
    \ t_d= dir(t)) {\n   if ((p_d= dir(t->par)) < 2) eval(t->par->par);\n   eval(t->par),\
    \ eval(t);\n   if (p_d < 2) rot(t_d == p_d ? t->par : t);\n  }\n }\n static inline\
    \ void pushup(Node *t) {\n  t->rsum= t->sum= t->val;\n  if (t->ch[0]) t->sum=\
    \ M::op(t->ch[0]->sum, t->sum), t->rsum= M::op(t->rsum, t->ch[0]->rsum);\n  if\
    \ (t->ch[1]) t->sum= M::op(t->sum, t->ch[1]->sum), t->rsum= M::op(t->ch[1]->rsum,\
    \ t->rsum);\n }\n static inline void propagate(Node *t, const E &x) {\n  if (!t)\
    \ return;\n  t->lazy_flg ? (M::composition(t->lazy, x), x) : t->lazy= x;\n  M::mapping(t->val,\
    \ x);\n  if constexpr (semigroup<M>::value) M::mapping(t->sum, x), M::mapping(t->rsum,\
    \ x);\n  t->lazy_flg= true;\n }\n static inline void toggle(Node *t) {\n  if (!t)\
    \ return;\n  std::swap(t->ch[0], t->ch[1]);\n  if constexpr (semigroup<M>::value)\
    \ std::swap(t->sum, t->rsum);\n  t->rev_flg= !t->rev_flg;\n }\n static inline\
    \ void eval(Node *t) {\n  if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]),\
    \ t->rev_flg= false;\n  if constexpr (dual<M>::value)\n   if (t->lazy_flg) propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n }\n static inline\
    \ Node *expose(Node *t) {\n  Node *r= nullptr;\n  for (Node *p= t; p; r= p, p=\
    \ p->par) {\n   splay(p), p->ch[1]= r;\n   if constexpr (semigroup<M>::value)\
    \ pushup(p);\n  }\n  return splay(t), r;\n }\n std::vector<Node> ns;\npublic:\n\
    \ LinkCutTree(std::size_t n): ns(n) {}\n LinkCutTree(std::size_t n, T val): ns(n)\
    \ {\n  for (std::size_t i= n; i--;) ns[i].val= val;\n }\n void evert(std::size_t\
    \ k) { expose(&ns[k]), toggle(&ns[k]), eval(&ns[k]); }\n void link(std::size_t\
    \ c, std::size_t p) {\n  evert(c), expose(&ns[p]), assert(!ns[c].par), ns[p].ch[1]=\
    \ &ns[c], ns[c].par= &ns[p];\n  if constexpr (semigroup<M>::value) pushup(&ns[p]);\n\
    \ }\n void cut(std::size_t c, std::size_t p) {\n  evert(p), expose(&ns[c]), assert(ns[c].ch[0]\
    \ == &ns[p]), ns[c].ch[0]= ns[c].ch[0]->par= nullptr;\n  if constexpr (semigroup<M>::value)\
    \ pushup(&ns[c]);\n }\n int par(std::size_t x) {\n  expose(&ns[x]);\n  Node *t=\
    \ ns[x].ch[0];\n  if (!t) return -1;\n  while (t->ch[1]) eval(t), t= t->ch[1];\n\
    \  return splay(t), t - &ns[0];\n }\n int lca(std::size_t x, std::size_t y) {\n\
    \  if (x == y) return x;\n  expose(&ns[x]);\n  Node *u= expose(&ns[y]);\n  return\
    \ ns[x].par ? u - &ns[0] : -1;\n }\n const T &operator[](std::size_t k) { return\
    \ get(k); }\n const T &get(std::size_t k) {\n  static_assert(semigroup<M>::value\
    \ || dual<M>::value, \"\\\"get\\\" is not available\\n\");\n  return expose(&ns[k]),\
    \ ns[k].val;\n }\n void set(std::size_t k, T v) {\n  static_assert(semigroup<M>::value\
    \ || dual<M>::value, \"\\\"set\\\" is not available\\n\");\n  expose(&ns[k]),\
    \ ns[k].val= v;\n  if constexpr (semigroup<M>::value) pushup(&ns[k]);\n }\n T\
    \ fold(std::size_t a, std::size_t b) {  // [a,b] closed section\n  static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n  if (a == b) return get(a);\n  return\
    \ evert(a), expose(&ns[b]), assert(ns[a].par), ns[b].sum;\n }\n void apply(std::size_t\
    \ a, std::size_t b, E v) {  // [a,b] closed section\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n  evert(a), expose(&ns[b]), assert(a\
    \ == b || ns[a].par), propagate(&ns[b], v), eval(&ns[b]);\n }\n static std::string\
    \ which_available() {\n  std::string ret= \"\";\n  if constexpr (semigroup<M>::value\
    \ || dual<M>::value) ret+= \"\\\"set\\\" \\\"get\\\" \";\n  if constexpr (semigroup<M>::value)\
    \ ret+= \"\\\"fold\\\" \";\n  if constexpr (dual<M>::value) ret+= \"\\\"apply\\\
    \" \";\n  return ret;\n }\n};\n#line 4 \"test/yosupo/lca.LCT.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N, Q;\n cin >> N >> Q;\n LinkCutTree lct(N);\n for (int i= 1; i < N; i++) {\n\
    \  int p;\n  cin >> p;\n  lct.link(i, p);\n }\n lct.evert(0);\n while (Q--) {\n\
    \  int u, v;\n  cin >> u >> v;\n  cout << lct.lca(u, v) << '\\n';\n }\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    #include \"src/DataStructure/LinkCutTree.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >> Q;\n LinkCutTree\
    \ lct(N);\n for (int i= 1; i < N; i++) {\n  int p;\n  cin >> p;\n  lct.link(i,\
    \ p);\n }\n lct.evert(0);\n while (Q--) {\n  int u, v;\n  cin >> u >> v;\n  cout\
    \ << lct.lca(u, v) << '\\n';\n }\n return 0;\n}\n"
  dependsOn:
  - src/DataStructure/LinkCutTree.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/yosupo/lca.LCT.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 00:50:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.LCT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.LCT.test.cpp
- /verify/test/yosupo/lca.LCT.test.cpp.html
title: test/yosupo/lca.LCT.test.cpp
---
