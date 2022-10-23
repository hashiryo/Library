---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
    title: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
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
    document_title: Skew-Heap
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SkewHeap.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Skew-Heap\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ \u30DE\u30FC\u30B8\u3067\u304D\u308B\u30D2\u30FC\u30D7\n * @brief top: O(1),\
    \ pop, push, merge: O(logN)\n * @brief apply(v): \u5168\u4F53\u306B\u4F5C\u7528\
    \u7D20v\u3092\u9069\u7528\n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member,\
    \ Dummy)                              \\\n  template <class tClass>          \
    \                           \\\n  struct has_##member {                      \
    \                 \\\n    template <class U, Dummy>                          \
    \       \\\n    static std::true_type check(U *);                         \\\n\
    \    static std::false_type check(...);                        \\\n    static\
    \ tClass *mClass;                                    \\\n    static const bool\
    \ value = decltype(check(mClass))::value; \\\n  };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy = typename U::member)\n\ntemplate <typename T, typename Compare\
    \ = std::less<T>, typename M = void>\nstruct SkewHeap {\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition);\n  HAS_TYPE(E);\n  template <class L>\n  using dual\
    \ = std::conjunction<has_E<L>, has_mapping<L>, has_composition<L>>;\n  template\
    \ <class tDerived, class U = std::nullptr_t>\n  struct Node_B {\n    using E =\
    \ U;\n    T key;\n    tDerived *ch[2];\n  };\n  template <bool du_, typename tEnable\
    \ = void>\n  struct Node_D : Node_B<Node_D<du_>> {};\n  template <bool du_>\n\
    \  struct Node_D<du_, typename std::enable_if_t<du_>>\n      : Node_B<Node_D<du_>,\
    \ typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n  };\n\
    \  using Node = Node_D<dual<M>::value>;\n  using E = typename Node::E;\n  Node\
    \ *root;\n  static inline void propagate(Node *&t, const E &x) {\n    if (!t)\
    \ return;\n    t->lazy = t->lazy_flg ? M::composition(t->lazy, x) : x;\n    t->key\
    \ = M::mapping(t->key, x), t->lazy_flg = true;\n  }\n  static inline void eval(Node\
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
    \ operator+(SkewHeap r) { return SkewHeap(*this) += r; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Skew-Heap\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u30DE\u30FC\u30B8\u3067\u304D\u308B\
    \u30D2\u30FC\u30D7\n * @brief top: O(1), pop, push, merge: O(logN)\n * @brief\
    \ apply(v): \u5168\u4F53\u306B\u4F5C\u7528\u7D20v\u3092\u9069\u7528\n */\n\n//\
    \ BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)                         \
    \     \\\n  template <class tClass>                                     \\\n \
    \ struct has_##member {                                       \\\n    template\
    \ <class U, Dummy>                                 \\\n    static std::true_type\
    \ check(U *);                         \\\n    static std::false_type check(...);\
    \                        \\\n    static tClass *mClass;                      \
    \              \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename T, typename Compare = std::less<T>, typename M = void>\n\
    struct SkewHeap {\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(E);\n\
    \  template <class L>\n  using dual = std::conjunction<has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t>\n\
    \  struct Node_B {\n    using E = U;\n    T key;\n    tDerived *ch[2];\n  };\n\
    \  template <bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<du_>>\
    \ {};\n  template <bool du_>\n  struct Node_D<du_, typename std::enable_if_t<du_>>\n\
    \      : Node_B<Node_D<du_>, typename M::E> {\n    typename M::E lazy;\n    bool\
    \ lazy_flg = false;\n  };\n  using Node = Node_D<dual<M>::value>;\n  using E =\
    \ typename Node::E;\n  Node *root;\n  static inline void propagate(Node *&t, const\
    \ E &x) {\n    if (!t) return;\n    t->lazy = t->lazy_flg ? M::composition(t->lazy,\
    \ x) : x;\n    t->key = M::mapping(t->key, x), t->lazy_flg = true;\n  }\n  static\
    \ inline void eval(Node *t) {\n    if (t->lazy_flg)\n      propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy),\n          t->lazy_flg = false;\n  }\n\
    \  Node *merge(Node *a, Node *b) {\n    if (!a || !b) return a ? a : b;\n    if\
    \ (Compare()(a->key, b->key)) std::swap(a, b);\n    if constexpr (dual<M>::value)\
    \ eval(a);\n    return std::swap(a->ch[0], a->ch[1] = merge(b, a->ch[1])), a;\n\
    \  }\n\n public:\n  /* max heap */\n  SkewHeap() : root(nullptr) {}\n  void push(T\
    \ key) { root = merge(root, new Node{key}); }\n  T pop() {\n    T ret = root->key;\n\
    \    if constexpr (dual<M>::value) eval(root);\n    return root = merge(root->ch[0],\
    \ root->ch[1]), ret;\n  }\n  T top() { return root->key; }\n  bool empty() { return\
    \ !root; }\n  void apply(E v) {\n    static_assert(dual<M>::value, \"\\\"apply\\\
    \" is not available\\n\");\n    propagate(root, v);\n  }\n  SkewHeap &operator+=(SkewHeap\
    \ r) { return root = merge(root, r.root), *this; }\n  SkewHeap operator+(SkewHeap\
    \ r) { return SkewHeap(*this) += r; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SkewHeap.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  timestamp: '2021-11-23 16:32:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2647.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/ALDS1_9_C.SkewHeap.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/DataStructure/SkewHeap.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SkewHeap.hpp
- /library/src/DataStructure/SkewHeap.hpp.html
title: Skew-Heap
---
