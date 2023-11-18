---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
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
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SkewHeap.hpp\"\n#include <functional>\n\
    #include <algorithm>\n#include <cstddef>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\
    \n#include <type_traits>\n#define MEMBER_MACRO(member, Dummy, name, type1, type2,\
    \ last) \\\n template <class tClass> struct name##member { \\\n  template <class\
    \ U, Dummy> static type1 check(U *); \\\n  static type2 check(...); \\\n  static\
    \ tClass *mClass; \\\n  last; \\\n }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member,\
    \ Dummy, has_, std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 6 \"src/DataStructure/SkewHeap.hpp\"\
    \ntemplate <typename T, typename Compare= std::less<T>, typename M= void> struct\
    \ SkewHeap {\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n\
    \ template <class L> using dual= std::conjunction<has_E<L>, has_mp<L>, has_cp<L>>;\n\
    \ template <class tDerived> struct Node_B {\n  T key;\n  tDerived *ch[2];\n };\n\
    \ template <bool du_, typename tEnable= void> struct Node_D: Node_B<Node_D<du_>>\
    \ {};\n template <bool du_> struct Node_D<du_, typename std::enable_if_t<du_>>:\
    \ Node_B<Node_D<du_>> {\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n\
    \ using Node= Node_D<dual<M>::value>;\n using E= nullptr_or_E_t<M>;\n Node *root;\n\
    \ static inline void propagate(Node *&t, const E &x) {\n  if (!t) return;\n  t->lazy_flg\
    \ ? (M::cp(t->lazy, x), x) : (t->lazy= x);\n  M::mp(t->key, x), t->lazy_flg= true;\n\
    \ }\n static inline void push(Node *t) {\n  if (t->lazy_flg) propagate(t->ch[0],\
    \ t->lazy), propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n }\n Node *merge(Node\
    \ *a, Node *b) {\n  if (!a || !b) return a ? a : b;\n  if (Compare()(a->key, b->key))\
    \ std::swap(a, b);\n  if constexpr (dual<M>::value) push(a);\n  return std::swap(a->ch[0],\
    \ a->ch[1]= merge(b, a->ch[1])), a;\n }\npublic:\n /* max heap */ SkewHeap():\
    \ root(nullptr) {}\n void push(T key) { root= merge(root, new Node{key}); }\n\
    \ T pop() {\n  T ret= root->key;\n  if constexpr (dual<M>::value) push(root);\n\
    \  return root= merge(root->ch[0], root->ch[1]), ret;\n }\n T top() { return root->key;\
    \ }\n bool empty() { return !root; }\n void apply(E v) {\n  static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n  propagate(root, v);\n }\n SkewHeap\
    \ &operator+=(SkewHeap r) { return root= merge(root, r.root), *this; }\n SkewHeap\
    \ operator+(SkewHeap r) { return SkewHeap(*this)+= r; }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <algorithm>\n#include <cstddef>\n\
    #include \"src/Internal/HAS_CHECK.hpp\"\ntemplate <typename T, typename Compare=\
    \ std::less<T>, typename M= void> struct SkewHeap {\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n\
    \ HAS_TYPE(E);\n NULLPTR_OR(E);\n template <class L> using dual= std::conjunction<has_E<L>,\
    \ has_mp<L>, has_cp<L>>;\n template <class tDerived> struct Node_B {\n  T key;\n\
    \  tDerived *ch[2];\n };\n template <bool du_, typename tEnable= void> struct\
    \ Node_D: Node_B<Node_D<du_>> {};\n template <bool du_> struct Node_D<du_, typename\
    \ std::enable_if_t<du_>>: Node_B<Node_D<du_>> {\n  typename M::E lazy;\n  bool\
    \ lazy_flg= false;\n };\n using Node= Node_D<dual<M>::value>;\n using E= nullptr_or_E_t<M>;\n\
    \ Node *root;\n static inline void propagate(Node *&t, const E &x) {\n  if (!t)\
    \ return;\n  t->lazy_flg ? (M::cp(t->lazy, x), x) : (t->lazy= x);\n  M::mp(t->key,\
    \ x), t->lazy_flg= true;\n }\n static inline void push(Node *t) {\n  if (t->lazy_flg)\
    \ propagate(t->ch[0], t->lazy), propagate(t->ch[1], t->lazy), t->lazy_flg= false;\n\
    \ }\n Node *merge(Node *a, Node *b) {\n  if (!a || !b) return a ? a : b;\n  if\
    \ (Compare()(a->key, b->key)) std::swap(a, b);\n  if constexpr (dual<M>::value)\
    \ push(a);\n  return std::swap(a->ch[0], a->ch[1]= merge(b, a->ch[1])), a;\n }\n\
    public:\n /* max heap */ SkewHeap(): root(nullptr) {}\n void push(T key) { root=\
    \ merge(root, new Node{key}); }\n T pop() {\n  T ret= root->key;\n  if constexpr\
    \ (dual<M>::value) push(root);\n  return root= merge(root->ch[0], root->ch[1]),\
    \ ret;\n }\n T top() { return root->key; }\n bool empty() { return !root; }\n\
    \ void apply(E v) {\n  static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n  propagate(root, v);\n }\n SkewHeap &operator+=(SkewHeap r) { return root=\
    \ merge(root, r.root), *this; }\n SkewHeap operator+(SkewHeap r) { return SkewHeap(*this)+=\
    \ r; }\n};"
  dependsOn:
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: false
  path: src/DataStructure/SkewHeap.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  timestamp: '2023-11-02 17:27:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/directedmst.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/ALDS1_9_C.SkewHeap.test.cpp
  - test/aoj/GRL_2_B.test.cpp
documentation_of: src/DataStructure/SkewHeap.hpp
layout: document
title: Skew-Heap
---
マージできるヒープ \
apply(v): 全体に作用素vを適用
## 計算量
top: $\mathcal{O}(1)$, pop, push, merge: $\mathcal{O}(\log N)$