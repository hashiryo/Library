---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/detection_idiom.hpp
    title: detection idiom
  - icon: ':question:'
    path: src/Misc/rng.hpp
    title: "\u7591\u4F3C\u4E71\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.RBST.test.cpp
    title: test/aoj/1508.RBST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_2_D.RBST.test.cpp
    title: test/aoj/ITP2_2_D.RBST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_A.RBST.test.cpp
    title: test/aoj/ITP2_4_A.RBST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_B.RBST.test.cpp
    title: test/aoj/ITP2_4_B.RBST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_C.RBST.test.cpp
    title: test/aoj/ITP2_4_C.RBST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.RBST.test.cpp
    title: test/atcoder/abc256_f.RBST.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc153_b.RBST.test.cpp
    title: test/atcoder/arc153_b.RBST.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.RBST.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.RBST.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.RBST.test.cpp
    title: test/yosupo/range_affine_range_sum.RBST.test.cpp
  - icon: ':x:'
    path: test/yukicoder/396.RBST.test.cpp
    title: test/yukicoder/396.RBST.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/RandomizedBinarySearchTree.hpp\"\n#include\
    \ <vector>\n#include <string>\n#include <array>\n#include <tuple>\n#include <utility>\n\
    #include <cstddef>\n#include <cassert>\n#line 2 \"src/Internal/detection_idiom.hpp\"\
    \n#include <type_traits>\n#define _DETECT_BOOL(name, ...) \\\n template <class,\
    \ class= void> struct name: std::false_type {}; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>>: std::true_type {}; \\\n template <class T>\
    \ static constexpr bool name##_v= name<T>::value\n#define _DETECT_TYPE(name, type1,\
    \ type2, ...) \\\n template <class T, class= void> struct name { \\\n  using type=\
    \ type2; \\\n }; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>\
    \ { \\\n  using type= type1; \\\n }\n#line 2 \"src/Misc/rng.hpp\"\n#include <random>\n\
    #include <cstdint>\nuint64_t rng() {\n static uint64_t x= 10150724397891781847ULL\
    \ * std::random_device{}();\n return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t\
    \ lim) { return rng() % lim; }\nint64_t rng(int64_t l, int64_t r) { return l +\
    \ rng() % (r - l); }\n#line 11 \"src/DataStructure/RandomizedBinarySearchTree.hpp\"\
    \ntemplate <class M, bool reversible= false> class RandomizedBinarySearchTree\
    \ {\n _DETECT_BOOL(semigroup, typename T::T, decltype(&T::op));\n _DETECT_BOOL(dual,\
    \ typename T::T, typename T::E, decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute,\
    \ typename T::commute);\n _DETECT_TYPE(nullptr_or_E, typename T::E, std::nullptr_t,\
    \ typename T::E);\n _DETECT_TYPE(myself_or_T, typename T::T, T, typename T::T);\n\
    \ using T= typename myself_or_T<M>::type;\n using E= typename nullptr_or_E<M>::type;\n\
    \ using RBST= RandomizedBinarySearchTree;\n template <class D> struct NodeB {\n\
    \  T val;\n  D *l, *r;\n  size_t sz;\n };\n template <class D, bool du> struct\
    \ NodeD: NodeB<D> {};\n template <class D> struct NodeD<D, 1>: NodeB<D> {\n  E\
    \ laz;\n };\n template <class D, bool sg, bool rev, bool com> struct NodeS: NodeD<D,\
    \ dual_v<M>> {};\n template <class D, bool rev, bool com> struct NodeS<D, 1, rev,\
    \ com>: NodeD<D, dual_v<M>> {\n  T sum;\n };\n template <class D> struct NodeS<D,\
    \ 1, 1, 0>: NodeD<D, dual_v<M>> {\n  T sum, rsum;\n };\n struct Node: NodeS<Node,\
    \ semigroup_v<M>, reversible, commute_v<M>> {\n  size_t size() const {\n   if\
    \ constexpr (dual_v<M> || reversible) return this->sz & 0x3fffffff;\n   else return\
    \ this->sz;\n  }\n };\n using np= Node *;\n np rt;\n template <bool sz= 1> static\
    \ inline void update(np t) {\n  if constexpr (sz) t->sz= 1;\n  if constexpr (semigroup_v<M>)\
    \ {\n   t->sum= t->val;\n   if constexpr (reversible && !commute_v<M>) t->rsum=\
    \ t->sum;\n  }\n  if (t->l) {\n   if constexpr (sz) t->sz+= t->l->size();\n  \
    \ if constexpr (semigroup_v<M>) {\n    t->sum= M::op(t->l->sum, t->sum);\n   \
    \ if constexpr (reversible && !commute_v<M>) t->rsum= M::op(t->rsum, t->l->rsum);\n\
    \   }\n  }\n  if (t->r) {\n   if constexpr (sz) t->sz+= t->r->size();\n   if constexpr\
    \ (semigroup_v<M>) {\n    t->sum= M::op(t->sum, t->r->sum);\n    if constexpr\
    \ (reversible && !commute_v<M>) t->rsum= M::op(t->r->rsum, t->rsum);\n   }\n \
    \ }\n }\n static inline void propagate(np t, const E &x) {\n  if (!t) return;\n\
    \  if (t->sz >> 31) M::cp(t->laz, x);\n  else t->laz= x;\n  if constexpr (semigroup_v<M>)\
    \ {\n   M::mp(t->sum, x, t->size());\n   if constexpr (reversible && !commute_v<M>)\
    \ M::mp(t->rsum, x, t->size());\n  }\n  M::mp(t->val, x, 1), t->sz|= 0x80000000;\n\
    \ }\n static inline void toggle(np t) {\n  if (!t) return;\n  if constexpr (semigroup_v<M>\
    \ && !commute_v<M>) std::swap(t->sum, t->rsum);\n  std::swap(t->l, t->r), t->sz^=\
    \ 0x40000000;\n }\n static inline void push_prop(np t) {\n  if (t->sz >> 31) propagate(t->l,\
    \ t->laz), propagate(t->r, t->laz), t->sz^= 0x80000000;\n }\n static inline void\
    \ push_tog(np t) {\n  if (t->sz & 0x40000000) toggle(t->l), toggle(t->r), t->sz^=\
    \ 0x40000000;\n }\n template <class S> static inline np build(size_t bg, size_t\
    \ ed, const S &val) {\n  if (bg == ed) return nullptr;\n  size_t mid= bg + (ed\
    \ - bg) / 2;\n  np t;\n  if constexpr (std::is_same_v<S, T>) t= new Node{val};\n\
    \  else t= new Node{val[mid]};\n  return t->l= build(bg, mid, val), t->r= build(mid\
    \ + 1, ed, val), update(t), t;\n }\n static inline void dump(typename std::vector<T>::iterator\
    \ itr, np t) {\n  if (!t) return;\n  if constexpr (dual_v<M>) push_prop(t);\n\
    \  if constexpr (reversible) push_tog(t);\n  size_t sz= t->l ? t->l->size() :\
    \ 0;\n  *(itr + sz)= t->val, dump(itr, t->l), dump(itr + sz + 1, t->r);\n }\n\
    \ static inline np merge(np l, np r) {\n  if (!l) return r;\n  if (!r) return\
    \ l;\n  if (size_t lsz= l->size(), rsz= r->size(); rng(lsz + rsz) < lsz) {\n \
    \  if constexpr (dual_v<M>) push_prop(l);\n   if constexpr (reversible) push_tog(l);\n\
    \   return l->r= merge(l->r, r), update(l), l;\n  } else {\n   if constexpr (dual_v<M>)\
    \ push_prop(r);\n   if constexpr (reversible) push_tog(r);\n   return r->l= merge(l,\
    \ r->l), update(r), r;\n  }\n }\n static inline std::pair<np, np> split(np t,\
    \ size_t k) {\n  if (!t) return {nullptr, nullptr};\n  if constexpr (dual_v<M>)\
    \ push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  if (size_t sz= t->l\
    \ ? t->l->size() : 0; k <= sz) {\n   auto [l, r]= split(t->l, k);\n   t->l= r,\
    \ update(t);\n   return {l, t};\n  } else {\n   auto [l, r]= split(t->r, k - sz\
    \ - 1);\n   t->r= l, update(t);\n   return {t, r};\n  }\n }\n static inline T\
    \ erase(np &t, size_t k) {\n  if constexpr (dual_v<M>) push_prop(t);\n  if constexpr\
    \ (reversible) push_tog(t);\n  size_t sz= t->l ? t->l->size() : 0;\n  if (k ==\
    \ sz) {\n   T v= t->val;\n   return t= merge(t->l, t->r), v;\n  } else {\n   T\
    \ v= k < sz ? erase(t->l, k) : erase(t->r, k - sz - 1);\n   return update(t),\
    \ v;\n  }\n }\n static inline T prod(np t, size_t a, size_t b) {\n  if (!a &&\
    \ b == t->size()) return t->sum;\n  if constexpr (dual_v<M>) push_prop(t);\n \
    \ if constexpr (reversible) push_tog(t);\n  size_t l= t->l ? t->l->size() : 0,\
    \ k= l + 1;\n  if (b < k) return prod(t->l, a, b);\n  if (a > l) return prod(t->r,\
    \ a - k, b - k);\n  T ret= t->val;\n  if (a < l) ret= M::op(prod(t->l, a, l),\
    \ ret);\n  if (b > k) ret= M::op(ret, prod(t->r, 0, b - k));\n  return ret;\n\
    \ }\n static inline void apply(np t, size_t a, size_t b, const E &x) {\n  if (!a\
    \ && b == t->size()) return propagate(t, x);\n  if constexpr (reversible) push_tog(t);\n\
    \  push_prop(t);\n  size_t l= t->l ? t->l->size() : 0, k= l + 1;\n  if (b < k)\
    \ apply(t->l, a, b, x);\n  else if (a > l) apply(t->r, a - k, b - k, x);\n  else\
    \ {\n   M::mp(t->val, x, 1);\n   if (a < l) apply(t->l, a, l, x);\n   if (b >\
    \ k) apply(t->r, 0, b - k, x);\n  }\n  if constexpr (semigroup_v<M>) update<0>(t);\n\
    \ }\n static inline void set_val(np t, size_t k, const T &v) {\n  if constexpr\
    \ (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  size_t\
    \ l= t->l ? t->l->size() : 0;\n  if (k < l) set_val(t->l, k, v);\n  else if (k\
    \ > l) set_val(t->r, k - l - 1, v);\n  else t->val= v;\n  if constexpr (semigroup_v<M>)\
    \ update<0>(t);\n }\n static inline void mul_val(np t, size_t k, const T &v) {\n\
    \  if constexpr (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n\
    \  size_t l= t->l ? t->l->size() : 0;\n  if (k < l) mul_val(t->l, k, v);\n  else\
    \ if (k > l) mul_val(t->r, k - l - 1, v);\n  else t->val= M::op(t->val, v);\n\
    \  update<0>(t);\n }\n static inline T get_val(np t, size_t k) {\n  if constexpr\
    \ (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  size_t\
    \ l= t->l ? t->l->size() : 0;\n  if (k < l) return get_val(t->l, k);\n  if (k\
    \ > l) return get_val(t->r, k - l - 1);\n  return t->val;\n }\n static inline\
    \ T &at_val(np t, size_t k) {\n  if constexpr (dual_v<M>) push_prop(t);\n  if\
    \ constexpr (reversible) push_tog(t);\n  size_t l= t->l ? t->l->size() : 0;\n\
    \  if (k < l) return at_val(t->l, k);\n  if (k > l) return at_val(t->r, k - l\
    \ - 1);\n  return t->val;\n }\n static inline RBST np_to_rbst(np t) {\n  RBST\
    \ ret;\n  return ret.rt= t, ret;\n }\npublic:\n RandomizedBinarySearchTree():\
    \ rt(nullptr) {}\n RandomizedBinarySearchTree(size_t n, T val= T()): rt(n ? build(0,\
    \ n, val) : nullptr) {}\n RandomizedBinarySearchTree(const T *bg, const T *ed):\
    \ rt(bg == ed ? nullptr : build(0, ed - bg, bg)) {}\n RandomizedBinarySearchTree(const\
    \ std::vector<T> &ar): RandomizedBinarySearchTree(ar.data(), ar.data() + ar.size())\
    \ {}\n size_t size() const { return rt ? rt->size() : 0; }\n void clear() { rt=\
    \ nullptr; }\n std::vector<T> dump() {\n  if (!rt) return std::vector<T>();\n\
    \  std::vector<T> ret(size());\n  return dump(ret.begin(), rt), ret;\n }\n static\
    \ std::string which_unavailable() {\n  std::string ret= \"\";\n  if constexpr\
    \ (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"prod\\\" \";\n \
    \ if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\" \";\n  if\
    \ constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (!reversible)\
    \ ret+= \"\\\"reverse\\\" \";\n  return ret;\n }\n RBST &operator+=(RBST r) {\
    \ return rt= merge(rt, r.rt), *this; }\n RBST operator+(RBST r) const { return\
    \ RBST(*this)+= r; }\n std::pair<RBST, RBST> split(size_t k) {\n  assert(k <=\
    \ size());\n  auto [l, r]= split(rt, k);\n  return {np_to_rbst(l), np_to_rbst(r)};\n\
    \ }\n std::tuple<RBST, RBST, RBST> split3(size_t a, size_t b) {\n  assert(a <\
    \ b), assert(b <= size());\n  auto [tmp, r]= split(rt, b);\n  auto [l, c]= split(tmp,\
    \ a);\n  return {np_to_rbst(l), np_to_rbst(c), np_to_rbst(r)};\n }\n void push_back(const\
    \ T &v) {\n  np t= new Node{v};\n  update(t), rt= merge(rt, t);\n }\n void push_front(const\
    \ T &v) {\n  np t= new Node{v};\n  update(t), rt= merge(t, rt);\n }\n void insert(size_t\
    \ k, const T &v) {\n  auto [l, r]= split(rt, k);\n  rt= new Node{v}, update(rt),\
    \ rt= merge(merge(l, rt), r);\n }\n T pop_back() {\n  auto [l, t]= split(rt, size()\
    \ - 1);\n  return rt= l, t->val;\n }\n T pop_front() {\n  auto [t, r]= split(rt,\
    \ 1);\n  return rt= r, t->val;\n }\n T erase(size_t k) { return assert(k < size()),\
    \ erase(rt, k); }\n void set(size_t k, const T &val) { set_val(rt, k, val); }\n\
    \ void mul(size_t k, const T &val) {\n  static_assert(semigroup_v<M> && commute_v<M>,\
    \ \"\\\"mul\\\" is not available\\n\");\n  mul_val(rt, k, val);\n }\n T get(size_t\
    \ k) { return get_val(rt, k); }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(rt, k);\n }\n template\
    \ <class L= M> std::enable_if_t<semigroup_v<L>, T> operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n T prod(size_t a, size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"prod\\\" is not available\\n\");\n  return prod(rt, a, b);\n }\n void\
    \ apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(rt, a, b, x);\n }\n void reverse() {\n  static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\\n\");\n  toggle(rt);\n }\n void reverse(size_t\
    \ a, size_t b) {\n  static_assert(reversible, \"\\\"reverse\\\" is not available\\\
    n\");\n  assert(a < b), assert(b <= size());\n  auto [tmp, r]= split(rt, b);\n\
    \  auto [l, c]= split(tmp, a);\n  toggle(c), rt= merge(merge(l, c), r);\n }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <array>\n#include\
    \ <tuple>\n#include <utility>\n#include <cstddef>\n#include <cassert>\n#include\
    \ \"src/Internal/detection_idiom.hpp\"\n#include \"src/Misc/rng.hpp\"\ntemplate\
    \ <class M, bool reversible= false> class RandomizedBinarySearchTree {\n _DETECT_BOOL(semigroup,\
    \ typename T::T, decltype(&T::op));\n _DETECT_BOOL(dual, typename T::T, typename\
    \ T::E, decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute, typename\
    \ T::commute);\n _DETECT_TYPE(nullptr_or_E, typename T::E, std::nullptr_t, typename\
    \ T::E);\n _DETECT_TYPE(myself_or_T, typename T::T, T, typename T::T);\n using\
    \ T= typename myself_or_T<M>::type;\n using E= typename nullptr_or_E<M>::type;\n\
    \ using RBST= RandomizedBinarySearchTree;\n template <class D> struct NodeB {\n\
    \  T val;\n  D *l, *r;\n  size_t sz;\n };\n template <class D, bool du> struct\
    \ NodeD: NodeB<D> {};\n template <class D> struct NodeD<D, 1>: NodeB<D> {\n  E\
    \ laz;\n };\n template <class D, bool sg, bool rev, bool com> struct NodeS: NodeD<D,\
    \ dual_v<M>> {};\n template <class D, bool rev, bool com> struct NodeS<D, 1, rev,\
    \ com>: NodeD<D, dual_v<M>> {\n  T sum;\n };\n template <class D> struct NodeS<D,\
    \ 1, 1, 0>: NodeD<D, dual_v<M>> {\n  T sum, rsum;\n };\n struct Node: NodeS<Node,\
    \ semigroup_v<M>, reversible, commute_v<M>> {\n  size_t size() const {\n   if\
    \ constexpr (dual_v<M> || reversible) return this->sz & 0x3fffffff;\n   else return\
    \ this->sz;\n  }\n };\n using np= Node *;\n np rt;\n template <bool sz= 1> static\
    \ inline void update(np t) {\n  if constexpr (sz) t->sz= 1;\n  if constexpr (semigroup_v<M>)\
    \ {\n   t->sum= t->val;\n   if constexpr (reversible && !commute_v<M>) t->rsum=\
    \ t->sum;\n  }\n  if (t->l) {\n   if constexpr (sz) t->sz+= t->l->size();\n  \
    \ if constexpr (semigroup_v<M>) {\n    t->sum= M::op(t->l->sum, t->sum);\n   \
    \ if constexpr (reversible && !commute_v<M>) t->rsum= M::op(t->rsum, t->l->rsum);\n\
    \   }\n  }\n  if (t->r) {\n   if constexpr (sz) t->sz+= t->r->size();\n   if constexpr\
    \ (semigroup_v<M>) {\n    t->sum= M::op(t->sum, t->r->sum);\n    if constexpr\
    \ (reversible && !commute_v<M>) t->rsum= M::op(t->r->rsum, t->rsum);\n   }\n \
    \ }\n }\n static inline void propagate(np t, const E &x) {\n  if (!t) return;\n\
    \  if (t->sz >> 31) M::cp(t->laz, x);\n  else t->laz= x;\n  if constexpr (semigroup_v<M>)\
    \ {\n   M::mp(t->sum, x, t->size());\n   if constexpr (reversible && !commute_v<M>)\
    \ M::mp(t->rsum, x, t->size());\n  }\n  M::mp(t->val, x, 1), t->sz|= 0x80000000;\n\
    \ }\n static inline void toggle(np t) {\n  if (!t) return;\n  if constexpr (semigroup_v<M>\
    \ && !commute_v<M>) std::swap(t->sum, t->rsum);\n  std::swap(t->l, t->r), t->sz^=\
    \ 0x40000000;\n }\n static inline void push_prop(np t) {\n  if (t->sz >> 31) propagate(t->l,\
    \ t->laz), propagate(t->r, t->laz), t->sz^= 0x80000000;\n }\n static inline void\
    \ push_tog(np t) {\n  if (t->sz & 0x40000000) toggle(t->l), toggle(t->r), t->sz^=\
    \ 0x40000000;\n }\n template <class S> static inline np build(size_t bg, size_t\
    \ ed, const S &val) {\n  if (bg == ed) return nullptr;\n  size_t mid= bg + (ed\
    \ - bg) / 2;\n  np t;\n  if constexpr (std::is_same_v<S, T>) t= new Node{val};\n\
    \  else t= new Node{val[mid]};\n  return t->l= build(bg, mid, val), t->r= build(mid\
    \ + 1, ed, val), update(t), t;\n }\n static inline void dump(typename std::vector<T>::iterator\
    \ itr, np t) {\n  if (!t) return;\n  if constexpr (dual_v<M>) push_prop(t);\n\
    \  if constexpr (reversible) push_tog(t);\n  size_t sz= t->l ? t->l->size() :\
    \ 0;\n  *(itr + sz)= t->val, dump(itr, t->l), dump(itr + sz + 1, t->r);\n }\n\
    \ static inline np merge(np l, np r) {\n  if (!l) return r;\n  if (!r) return\
    \ l;\n  if (size_t lsz= l->size(), rsz= r->size(); rng(lsz + rsz) < lsz) {\n \
    \  if constexpr (dual_v<M>) push_prop(l);\n   if constexpr (reversible) push_tog(l);\n\
    \   return l->r= merge(l->r, r), update(l), l;\n  } else {\n   if constexpr (dual_v<M>)\
    \ push_prop(r);\n   if constexpr (reversible) push_tog(r);\n   return r->l= merge(l,\
    \ r->l), update(r), r;\n  }\n }\n static inline std::pair<np, np> split(np t,\
    \ size_t k) {\n  if (!t) return {nullptr, nullptr};\n  if constexpr (dual_v<M>)\
    \ push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  if (size_t sz= t->l\
    \ ? t->l->size() : 0; k <= sz) {\n   auto [l, r]= split(t->l, k);\n   t->l= r,\
    \ update(t);\n   return {l, t};\n  } else {\n   auto [l, r]= split(t->r, k - sz\
    \ - 1);\n   t->r= l, update(t);\n   return {t, r};\n  }\n }\n static inline T\
    \ erase(np &t, size_t k) {\n  if constexpr (dual_v<M>) push_prop(t);\n  if constexpr\
    \ (reversible) push_tog(t);\n  size_t sz= t->l ? t->l->size() : 0;\n  if (k ==\
    \ sz) {\n   T v= t->val;\n   return t= merge(t->l, t->r), v;\n  } else {\n   T\
    \ v= k < sz ? erase(t->l, k) : erase(t->r, k - sz - 1);\n   return update(t),\
    \ v;\n  }\n }\n static inline T prod(np t, size_t a, size_t b) {\n  if (!a &&\
    \ b == t->size()) return t->sum;\n  if constexpr (dual_v<M>) push_prop(t);\n \
    \ if constexpr (reversible) push_tog(t);\n  size_t l= t->l ? t->l->size() : 0,\
    \ k= l + 1;\n  if (b < k) return prod(t->l, a, b);\n  if (a > l) return prod(t->r,\
    \ a - k, b - k);\n  T ret= t->val;\n  if (a < l) ret= M::op(prod(t->l, a, l),\
    \ ret);\n  if (b > k) ret= M::op(ret, prod(t->r, 0, b - k));\n  return ret;\n\
    \ }\n static inline void apply(np t, size_t a, size_t b, const E &x) {\n  if (!a\
    \ && b == t->size()) return propagate(t, x);\n  if constexpr (reversible) push_tog(t);\n\
    \  push_prop(t);\n  size_t l= t->l ? t->l->size() : 0, k= l + 1;\n  if (b < k)\
    \ apply(t->l, a, b, x);\n  else if (a > l) apply(t->r, a - k, b - k, x);\n  else\
    \ {\n   M::mp(t->val, x, 1);\n   if (a < l) apply(t->l, a, l, x);\n   if (b >\
    \ k) apply(t->r, 0, b - k, x);\n  }\n  if constexpr (semigroup_v<M>) update<0>(t);\n\
    \ }\n static inline void set_val(np t, size_t k, const T &v) {\n  if constexpr\
    \ (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  size_t\
    \ l= t->l ? t->l->size() : 0;\n  if (k < l) set_val(t->l, k, v);\n  else if (k\
    \ > l) set_val(t->r, k - l - 1, v);\n  else t->val= v;\n  if constexpr (semigroup_v<M>)\
    \ update<0>(t);\n }\n static inline void mul_val(np t, size_t k, const T &v) {\n\
    \  if constexpr (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n\
    \  size_t l= t->l ? t->l->size() : 0;\n  if (k < l) mul_val(t->l, k, v);\n  else\
    \ if (k > l) mul_val(t->r, k - l - 1, v);\n  else t->val= M::op(t->val, v);\n\
    \  update<0>(t);\n }\n static inline T get_val(np t, size_t k) {\n  if constexpr\
    \ (dual_v<M>) push_prop(t);\n  if constexpr (reversible) push_tog(t);\n  size_t\
    \ l= t->l ? t->l->size() : 0;\n  if (k < l) return get_val(t->l, k);\n  if (k\
    \ > l) return get_val(t->r, k - l - 1);\n  return t->val;\n }\n static inline\
    \ T &at_val(np t, size_t k) {\n  if constexpr (dual_v<M>) push_prop(t);\n  if\
    \ constexpr (reversible) push_tog(t);\n  size_t l= t->l ? t->l->size() : 0;\n\
    \  if (k < l) return at_val(t->l, k);\n  if (k > l) return at_val(t->r, k - l\
    \ - 1);\n  return t->val;\n }\n static inline RBST np_to_rbst(np t) {\n  RBST\
    \ ret;\n  return ret.rt= t, ret;\n }\npublic:\n RandomizedBinarySearchTree():\
    \ rt(nullptr) {}\n RandomizedBinarySearchTree(size_t n, T val= T()): rt(n ? build(0,\
    \ n, val) : nullptr) {}\n RandomizedBinarySearchTree(const T *bg, const T *ed):\
    \ rt(bg == ed ? nullptr : build(0, ed - bg, bg)) {}\n RandomizedBinarySearchTree(const\
    \ std::vector<T> &ar): RandomizedBinarySearchTree(ar.data(), ar.data() + ar.size())\
    \ {}\n size_t size() const { return rt ? rt->size() : 0; }\n void clear() { rt=\
    \ nullptr; }\n std::vector<T> dump() {\n  if (!rt) return std::vector<T>();\n\
    \  std::vector<T> ret(size());\n  return dump(ret.begin(), rt), ret;\n }\n static\
    \ std::string which_unavailable() {\n  std::string ret= \"\";\n  if constexpr\
    \ (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"prod\\\" \";\n \
    \ if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\" \";\n  if\
    \ constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (!reversible)\
    \ ret+= \"\\\"reverse\\\" \";\n  return ret;\n }\n RBST &operator+=(RBST r) {\
    \ return rt= merge(rt, r.rt), *this; }\n RBST operator+(RBST r) const { return\
    \ RBST(*this)+= r; }\n std::pair<RBST, RBST> split(size_t k) {\n  assert(k <=\
    \ size());\n  auto [l, r]= split(rt, k);\n  return {np_to_rbst(l), np_to_rbst(r)};\n\
    \ }\n std::tuple<RBST, RBST, RBST> split3(size_t a, size_t b) {\n  assert(a <\
    \ b), assert(b <= size());\n  auto [tmp, r]= split(rt, b);\n  auto [l, c]= split(tmp,\
    \ a);\n  return {np_to_rbst(l), np_to_rbst(c), np_to_rbst(r)};\n }\n void push_back(const\
    \ T &v) {\n  np t= new Node{v};\n  update(t), rt= merge(rt, t);\n }\n void push_front(const\
    \ T &v) {\n  np t= new Node{v};\n  update(t), rt= merge(t, rt);\n }\n void insert(size_t\
    \ k, const T &v) {\n  auto [l, r]= split(rt, k);\n  rt= new Node{v}, update(rt),\
    \ rt= merge(merge(l, rt), r);\n }\n T pop_back() {\n  auto [l, t]= split(rt, size()\
    \ - 1);\n  return rt= l, t->val;\n }\n T pop_front() {\n  auto [t, r]= split(rt,\
    \ 1);\n  return rt= r, t->val;\n }\n T erase(size_t k) { return assert(k < size()),\
    \ erase(rt, k); }\n void set(size_t k, const T &val) { set_val(rt, k, val); }\n\
    \ void mul(size_t k, const T &val) {\n  static_assert(semigroup_v<M> && commute_v<M>,\
    \ \"\\\"mul\\\" is not available\\n\");\n  mul_val(rt, k, val);\n }\n T get(size_t\
    \ k) { return get_val(rt, k); }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(rt, k);\n }\n template\
    \ <class L= M> std::enable_if_t<semigroup_v<L>, T> operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n T prod(size_t a, size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"prod\\\" is not available\\n\");\n  return prod(rt, a, b);\n }\n void\
    \ apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(rt, a, b, x);\n }\n void reverse() {\n  static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\\n\");\n  toggle(rt);\n }\n void reverse(size_t\
    \ a, size_t b) {\n  static_assert(reversible, \"\\\"reverse\\\" is not available\\\
    n\");\n  assert(a < b), assert(b <= size());\n  auto [tmp, r]= split(rt, b);\n\
    \  auto [l, c]= split(tmp, a);\n  toggle(c), rt= merge(merge(l, c), r);\n }\n\
    };"
  dependsOn:
  - src/Internal/detection_idiom.hpp
  - src/Misc/rng.hpp
  isVerificationFile: false
  path: src/DataStructure/RandomizedBinarySearchTree.hpp
  requiredBy: []
  timestamp: '2024-04-13 13:36:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/396.RBST.test.cpp
  - test/atcoder/abc256_f.RBST.test.cpp
  - test/atcoder/arc153_b.RBST.test.cpp
  - test/yosupo/dynamic_sequence_range_affine_range_sum.RBST.test.cpp
  - test/yosupo/range_affine_range_sum.RBST.test.cpp
  - test/aoj/1508.RBST.test.cpp
  - test/aoj/ITP2_4_C.RBST.test.cpp
  - test/aoj/ITP2_4_A.RBST.test.cpp
  - test/aoj/ITP2_2_D.RBST.test.cpp
  - test/aoj/ITP2_4_B.RBST.test.cpp
documentation_of: src/DataStructure/RandomizedBinarySearchTree.hpp
layout: document
title: Splay-Tree
---
単位元は必要なし（遅延側も）\
各ノードが部分木のサイズを保持しているのでmapping関数では引数としてsizeを渡せる
## 計算量
$\mathcal{O}(\log N)$

## 問題例
[CODE FESTIVAL 2014 エキシビション B - カッコつけ](https://atcoder.jp/contests/code-festival-2014-exhibition/tasks/code_festival_exhibition_b) (insert, erase, fold)\
[SoundHound Programming Contest 2018 Masters Tournament 本戦 (Open) E - Hash Swapping](https://atcoder.jp/contests/soundhound2018-summer-final-open/tasks/soundhound2018_summer_final_e) (split3, fold)