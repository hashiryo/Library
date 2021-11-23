---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.DynSeg.test.cpp
    title: test/aoj/2270.DynSeg.test.cpp
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
  - icon: ':x:'
    path: test/atcoder/abc133_f.Patricia.test.cpp
    title: test/atcoder/abc133_f.Patricia.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.PerArr.test.cpp
    title: test/atcoder/abc133_f.PerArr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.LCT.test.cpp
    title: test/yosupo/lca.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.LCT.test.cpp
    title: test/yukicoder/235.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.LCT.test.cpp
    title: test/yukicoder/529.LCT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Link-Cut-Tree
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LinkCutTree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Link-Cut-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ @brief O(logN)\n * \u5358\u4F4D\u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\u9045\
    \u5EF6\u5074\u3082\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\
    \u30B5\u30A4\u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\u306A\u3044\u306E\u3067\
    mapping\u95A2\u6570\u3067\u306F\u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\
    \u306A\u3044\n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)   \
    \                           \\\n  template <class T>                         \
    \                 \\\n  struct has_##member {                                \
    \       \\\n    template <class U, Dummy>                                 \\\n\
    \    static std::true_type check(U *);                         \\\n    static\
    \ std::false_type check(...);                        \\\n    static T *mClass;\
    \                                         \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename M = void>\nclass LinkCutTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n  template <class\
    \ L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t,\
    \ class F = std::nullptr_t>\n  struct Node_B {\n    using T = U;\n    using E\
    \ = F;\n    tDerived *ch[2], *par;\n    bool rev_flg;\n  };\n  template <bool\
    \ sg_, bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<sg_,\
    \ du_, tEnable>> {};\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<Node_D<sg_, du_>, typename\
    \ M::T> {\n    typename M::T val, sum, rsum;\n  };\n  template <bool sg_, bool\
    \ du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>\n  \
    \    : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  template <bool\
    \ sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && du_>>\n\
    \      : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val, sum, rsum;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value>;\n  using T = typename Node::T;\n\
    \  using E = typename Node::E;\n  inline int dir(Node *&t) {\n    if (t->par)\
    \ {\n      if (t->par->ch[0] == t) return 0;\n      if (t->par->ch[1] == t) return\
    \ 1;\n    }\n    return 2;\n  }\n  inline void rot(Node *t) {\n    Node *p = t->par;\n\
    \    int d = dir(t);\n    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n   \
    \ t->ch[!d] = p;\n    if constexpr (semigroup<M>::value) pushup(p), pushup(t);\n\
    \    t->par = p->par;\n    if ((d = dir(p)) < 2) {\n      p->par->ch[d] = t;\n\
    \      if constexpr (semigroup<M>::value) pushup(t->par);\n    }\n    p->par =\
    \ t;\n  }\n  inline void splay(Node *t) {\n    eval(t);\n    for (int t_d = dir(t),\
    \ p_d; t_d < 2; rot(t), t_d = dir(t)) {\n      if ((p_d = dir(t->par)) < 2) eval(t->par->par);\n\
    \      eval(t->par), eval(t);\n      if (p_d < 2) rot(t_d == p_d ? t->par : t);\n\
    \    }\n  }\n  inline void pushup(Node *t) {\n    t->rsum = t->sum = t->val;\n\
    \    if (t->ch[0])\n      t->sum = M::op(t->ch[0]->sum, t->sum),\n      t->rsum\
    \ = M::op(t->rsum, t->ch[0]->rsum);\n    if (t->ch[1])\n      t->sum = M::op(t->sum,\
    \ t->ch[1]->sum),\n      t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n  }\n  inline\
    \ void propagate(Node *t, const E &x) {\n    if (!t) return;\n    t->lazy = t->lazy_flg\
    \ ? M::composition(t->lazy, x) : x;\n    t->val = M::mapping(t->val, x);\n   \
    \ if constexpr (semigroup<M>::value)\n      t->sum = M::mapping(t->sum, x), t->rsum\
    \ = M::mapping(t->rsum, x);\n    t->lazy_flg = true;\n  }\n  inline void toggle(Node\
    \ *t) {\n    if (!t) return;\n    std::swap(t->ch[0], t->ch[1]);\n    if constexpr\
    \ (semigroup<M>::value) std::swap(t->sum, t->rsum);\n    t->rev_flg = !t->rev_flg;\n\
    \  }\n  inline void eval(Node *t) {\n    if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]),\
    \ t->rev_flg = false;\n    if constexpr (dual<M>::value)\n      if (t->lazy_flg)\n\
    \        propagate(t->ch[0], t->lazy), propagate(t->ch[1], t->lazy),\n       \
    \     t->lazy_flg = false;\n  }\n  inline Node *expose(Node *t) {\n    Node *r\
    \ = nullptr;\n    for (Node *p = t; p; r = p, p = p->par) {\n      splay(p), p->ch[1]\
    \ = r;\n      if constexpr (semigroup<M>::value) pushup(p);\n    }\n    return\
    \ splay(t), r;\n  }\n  std::vector<Node> ns;\n\n public:\n  LinkCutTree(std::size_t\
    \ n) : ns(n) {}\n  LinkCutTree(std::size_t n, T val) : ns(n) {\n    for (std::size_t\
    \ i = n; i--;) ns[i].val = val;\n  }\n  void evert(std::size_t k) { expose(&ns[k]),\
    \ toggle(&ns[k]), eval(&ns[k]); }\n  void link(std::size_t c, std::size_t p) {\n\
    \    evert(c), expose(&ns[p]);\n    assert(!ns[c].par);\n    ns[p].ch[1] = &ns[c],\
    \ ns[c].par = &ns[p];\n    if constexpr (semigroup<M>::value) pushup(&ns[p]);\n\
    \  }\n  void cut(std::size_t c, std::size_t p) {\n    evert(p), expose(&ns[c]);\n\
    \    assert(ns[c].ch[0] == &ns[p]);\n    ns[c].ch[0] = ns[c].ch[0]->par = nullptr;\n\
    \    if constexpr (semigroup<M>::value) pushup(&ns[c]);\n  }\n  int par(std::size_t\
    \ x) {\n    expose(&ns[x]);\n    Node *t = ns[x].ch[0];\n    if (!t) return -1;\n\
    \    while (t->ch[1]) eval(t), t = t->ch[1];\n    return splay(t), t - &ns[0];\n\
    \  }\n  int lca(std::size_t x, std::size_t y) {\n    if (x == y) return x;\n \
    \   expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n    return ns[x].par ? u -\
    \ &ns[0] : -1;\n  }\n  const T &operator[](std::size_t k) { return get(k); }\n\
    \  const T &get(std::size_t k) {\n    static_assert(semigroup<M>::value || dual<M>::value,\n\
    \                  \"\\\"get\\\" is not available\\n\");\n    return expose(&ns[k]),\
    \ ns[k].val;\n  }\n  void set(std::size_t k, T v) {\n    static_assert(semigroup<M>::value\
    \ || dual<M>::value,\n                  \"\\\"set\\\" is not available\\n\");\n\
    \    expose(&ns[k]), ns[k].val = v;\n    if constexpr (semigroup<M>::value) pushup(&ns[k]);\n\
    \  }\n  T fold(std::size_t a, std::size_t b) {  // [a,b] closed section\n    static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return evert(a), expose(&ns[b]),\
    \ ns[b].sum;\n  }\n  void apply(std::size_t a, std::size_t b, E v) {  // [a,b]\
    \ closed section\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    evert(a), expose(&ns[b]), propagate(&ns[b], v), eval(&ns[b]);\n  }\n\
    \  static std::string which_available() {\n    std::string ret = \"\";\n    if\
    \ constexpr (semigroup<M>::value || dual<M>::value)\n      ret += \"\\\"set\\\"\
    \ \\\"get\\\" \";\n    if constexpr (semigroup<M>::value) ret += \"\\\"fold\\\"\
    \ \";\n    if constexpr (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return\
    \ ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Link-Cut-Tree\n *\
    \ @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n * \u5358\u4F4D\
    \u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\u9045\u5EF6\u5074\u3082\uFF09\n * \u5404\
    \u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u4FDD\
    \u6301\u3057\u3066\u3044\u306A\u3044\u306E\u3067mapping\u95A2\u6570\u3067\u306F\
    \u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u306A\u3044\n */\n\n// BEGIN\
    \ CUT HERE\n\n#define HAS_CHECK(member, Dummy)                              \\\
    \n  template <class T>                                          \\\n  struct has_##member\
    \ {                                       \\\n    template <class U, Dummy>  \
    \                               \\\n    static std::true_type check(U *);    \
    \                     \\\n    static std::false_type check(...);             \
    \           \\\n    static T *mClass;                                        \
    \ \\\n    static const bool value = decltype(check(mClass))::value; \\\n  };\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\ntemplate\
    \ <typename M = void>\nclass LinkCutTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n  template <class\
    \ L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t,\
    \ class F = std::nullptr_t>\n  struct Node_B {\n    using T = U;\n    using E\
    \ = F;\n    tDerived *ch[2], *par;\n    bool rev_flg;\n  };\n  template <bool\
    \ sg_, bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<sg_,\
    \ du_, tEnable>> {};\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<Node_D<sg_, du_>, typename\
    \ M::T> {\n    typename M::T val, sum, rsum;\n  };\n  template <bool sg_, bool\
    \ du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>\n  \
    \    : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  template <bool\
    \ sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && du_>>\n\
    \      : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val, sum, rsum;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value>;\n  using T = typename Node::T;\n\
    \  using E = typename Node::E;\n  inline int dir(Node *&t) {\n    if (t->par)\
    \ {\n      if (t->par->ch[0] == t) return 0;\n      if (t->par->ch[1] == t) return\
    \ 1;\n    }\n    return 2;\n  }\n  inline void rot(Node *t) {\n    Node *p = t->par;\n\
    \    int d = dir(t);\n    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n   \
    \ t->ch[!d] = p;\n    if constexpr (semigroup<M>::value) pushup(p), pushup(t);\n\
    \    t->par = p->par;\n    if ((d = dir(p)) < 2) {\n      p->par->ch[d] = t;\n\
    \      if constexpr (semigroup<M>::value) pushup(t->par);\n    }\n    p->par =\
    \ t;\n  }\n  inline void splay(Node *t) {\n    eval(t);\n    for (int t_d = dir(t),\
    \ p_d; t_d < 2; rot(t), t_d = dir(t)) {\n      if ((p_d = dir(t->par)) < 2) eval(t->par->par);\n\
    \      eval(t->par), eval(t);\n      if (p_d < 2) rot(t_d == p_d ? t->par : t);\n\
    \    }\n  }\n  inline void pushup(Node *t) {\n    t->rsum = t->sum = t->val;\n\
    \    if (t->ch[0])\n      t->sum = M::op(t->ch[0]->sum, t->sum),\n      t->rsum\
    \ = M::op(t->rsum, t->ch[0]->rsum);\n    if (t->ch[1])\n      t->sum = M::op(t->sum,\
    \ t->ch[1]->sum),\n      t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n  }\n  inline\
    \ void propagate(Node *t, const E &x) {\n    if (!t) return;\n    t->lazy = t->lazy_flg\
    \ ? M::composition(t->lazy, x) : x;\n    t->val = M::mapping(t->val, x);\n   \
    \ if constexpr (semigroup<M>::value)\n      t->sum = M::mapping(t->sum, x), t->rsum\
    \ = M::mapping(t->rsum, x);\n    t->lazy_flg = true;\n  }\n  inline void toggle(Node\
    \ *t) {\n    if (!t) return;\n    std::swap(t->ch[0], t->ch[1]);\n    if constexpr\
    \ (semigroup<M>::value) std::swap(t->sum, t->rsum);\n    t->rev_flg = !t->rev_flg;\n\
    \  }\n  inline void eval(Node *t) {\n    if (t->rev_flg) toggle(t->ch[0]), toggle(t->ch[1]),\
    \ t->rev_flg = false;\n    if constexpr (dual<M>::value)\n      if (t->lazy_flg)\n\
    \        propagate(t->ch[0], t->lazy), propagate(t->ch[1], t->lazy),\n       \
    \     t->lazy_flg = false;\n  }\n  inline Node *expose(Node *t) {\n    Node *r\
    \ = nullptr;\n    for (Node *p = t; p; r = p, p = p->par) {\n      splay(p), p->ch[1]\
    \ = r;\n      if constexpr (semigroup<M>::value) pushup(p);\n    }\n    return\
    \ splay(t), r;\n  }\n  std::vector<Node> ns;\n\n public:\n  LinkCutTree(std::size_t\
    \ n) : ns(n) {}\n  LinkCutTree(std::size_t n, T val) : ns(n) {\n    for (std::size_t\
    \ i = n; i--;) ns[i].val = val;\n  }\n  void evert(std::size_t k) { expose(&ns[k]),\
    \ toggle(&ns[k]), eval(&ns[k]); }\n  void link(std::size_t c, std::size_t p) {\n\
    \    evert(c), expose(&ns[p]);\n    assert(!ns[c].par);\n    ns[p].ch[1] = &ns[c],\
    \ ns[c].par = &ns[p];\n    if constexpr (semigroup<M>::value) pushup(&ns[p]);\n\
    \  }\n  void cut(std::size_t c, std::size_t p) {\n    evert(p), expose(&ns[c]);\n\
    \    assert(ns[c].ch[0] == &ns[p]);\n    ns[c].ch[0] = ns[c].ch[0]->par = nullptr;\n\
    \    if constexpr (semigroup<M>::value) pushup(&ns[c]);\n  }\n  int par(std::size_t\
    \ x) {\n    expose(&ns[x]);\n    Node *t = ns[x].ch[0];\n    if (!t) return -1;\n\
    \    while (t->ch[1]) eval(t), t = t->ch[1];\n    return splay(t), t - &ns[0];\n\
    \  }\n  int lca(std::size_t x, std::size_t y) {\n    if (x == y) return x;\n \
    \   expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n    return ns[x].par ? u -\
    \ &ns[0] : -1;\n  }\n  const T &operator[](std::size_t k) { return get(k); }\n\
    \  const T &get(std::size_t k) {\n    static_assert(semigroup<M>::value || dual<M>::value,\n\
    \                  \"\\\"get\\\" is not available\\n\");\n    return expose(&ns[k]),\
    \ ns[k].val;\n  }\n  void set(std::size_t k, T v) {\n    static_assert(semigroup<M>::value\
    \ || dual<M>::value,\n                  \"\\\"set\\\" is not available\\n\");\n\
    \    expose(&ns[k]), ns[k].val = v;\n    if constexpr (semigroup<M>::value) pushup(&ns[k]);\n\
    \  }\n  T fold(std::size_t a, std::size_t b) {  // [a,b] closed section\n    static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return evert(a), expose(&ns[b]),\
    \ ns[b].sum;\n  }\n  void apply(std::size_t a, std::size_t b, E v) {  // [a,b]\
    \ closed section\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    evert(a), expose(&ns[b]), propagate(&ns[b], v), eval(&ns[b]);\n  }\n\
    \  static std::string which_available() {\n    std::string ret = \"\";\n    if\
    \ constexpr (semigroup<M>::value || dual<M>::value)\n      ret += \"\\\"set\\\"\
    \ \\\"get\\\" \";\n    if constexpr (semigroup<M>::value) ret += \"\\\"fold\\\"\
    \ \";\n    if constexpr (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return\
    \ ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LinkCutTree.hpp
  requiredBy: []
  timestamp: '2021-11-22 16:08:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/529.LCT.test.cpp
  - test/yukicoder/235.LCT.test.cpp
  - test/aoj/2270.Patricia.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/2270.DynSeg.test.cpp
  - test/aoj/2450.LCT.test.cpp
  - test/atcoder/abc133_f.Patricia.test.cpp
  - test/atcoder/abc133_f.DynSeg.test.cpp
  - test/atcoder/abc133_f.PerArr.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp
  - test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  - test/yosupo/lca.LCT.test.cpp
documentation_of: src/DataStructure/LinkCutTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LinkCutTree.hpp
- /library/src/DataStructure/LinkCutTree.hpp.html
title: Link-Cut-Tree
---
