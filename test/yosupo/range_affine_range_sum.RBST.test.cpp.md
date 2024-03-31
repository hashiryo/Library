---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/RandomizedBinarySearchTree.hpp
    title: Splay-Tree
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/detection_idiom.hpp
    title: detection idiom
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Misc/rng.hpp
    title: "\u7591\u4F3C\u4E71\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.RBST.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n// apply,\
    \ fold \u306E verify\n\n#include <iostream>\n#line 2 \"src/DataStructure/RandomizedBinarySearchTree.hpp\"\
    \n#include <vector>\n#include <string>\n#include <array>\n#include <utility>\n\
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
    \ rng() % (r - l); }\n#line 10 \"src/DataStructure/RandomizedBinarySearchTree.hpp\"\
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
    \ v;\n  }\n }\n static inline T fold(np t, size_t a, size_t b) {\n  if (!a &&\
    \ b == t->size()) return t->sum;\n  if constexpr (dual_v<M>) push_prop(t);\n \
    \ if constexpr (reversible) push_tog(t);\n  size_t l= t->l ? t->l->size() : 0,\
    \ k= l + 1;\n  if (b < k) return fold(t->l, a, b);\n  if (a > l) return fold(t->r,\
    \ a - k, b - k);\n  T ret= t->val;\n  if (a < l) ret= M::op(fold(t->l, a, l),\
    \ ret);\n  if (b > k) ret= M::op(ret, fold(t->r, 0, b - k));\n  return ret;\n\
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
    \ (semigroup_v<M>) ret+= \"\\\"at\\\" \";\n  else ret+= \"\\\"fold\\\" \";\n \
    \ if constexpr (!semigroup_v<M> || !commute_v<M>) ret+= \"\\\"mul\\\" \";\n  if\
    \ constexpr (!dual_v<M>) ret+= \"\\\"apply\\\" \";\n  if constexpr (!reversible)\
    \ ret+= \"\\\"reverse\\\" \";\n  return ret;\n }\n RBST &operator+=(RBST r) {\
    \ return rt= merge(rt, r.rt), *this; }\n RBST operator+(RBST r) const { return\
    \ RBST(*this)+= r; }\n std::pair<RBST, RBST> split(size_t k) {\n  assert(k <=\
    \ size());\n  auto [l, r]= split(rt, k);\n  return {np_to_rbst(l), np_to_rbst(r)};\n\
    \ }\n std::tuple<SplayTree, SplayTree, SplayTree> split3(size_t a, size_t b) {\n\
    \  assert(a < b), assert(b <= size());\n  auto [tmp, r]= split(rt, b);\n  auto\
    \ [l, c]= split(tmp, a);\n  return {np_to_rbst(l), np_to_rbst(c), np_to_rbst(r)};\n\
    \ }\n void push_back(const T &v) {\n  np t= new Node{v};\n  update(t), rt= merge(rt,\
    \ t);\n }\n void push_front(const T &v) {\n  np t= new Node{v};\n  update(t),\
    \ rt= merge(t, rt);\n }\n void insert(size_t k, const T &v) {\n  auto [l, r]=\
    \ split(rt, k);\n  rt= new Node{v}, update(rt), rt= merge(merge(l, rt), r);\n\
    \ }\n T pop_back() {\n  auto [l, t]= split(rt, size() - 1);\n  return rt= l, t->val;\n\
    \ }\n T pop_front() {\n  auto [t, r]= split(rt, 1);\n  return rt= r, t->val;\n\
    \ }\n T erase(size_t k) { return assert(k < size()), erase(rt, k); }\n void set(size_t\
    \ k, const T &val) { set_val(rt, k, val); }\n void mul(size_t k, const T &val)\
    \ {\n  static_assert(semigroup_v<M> && commute_v<M>, \"\\\"mul\\\" is not available\\\
    n\");\n  mul_val(rt, k, val);\n }\n T get(size_t k) { return get_val(rt, k); }\n\
    \ T &at(size_t k) {\n  static_assert(!semigroup_v<M>, \"\\\"at\\\" is not available\\\
    n\");\n  return at_val(rt, k);\n }\n template <class L= M> std::enable_if_t<semigroup_v<L>,\
    \ T> operator[](size_t k) { return get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>,\
    \ T> &operator[](size_t k) { return at(k); }\n T fold(size_t a, size_t b) {\n\
    \  static_assert(semigroup_v<M>, \"\\\"fold\\\" is not available\\n\");\n  return\
    \ fold(rt, a, b);\n }\n void apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>,\
    \ \"\\\"apply\\\" is not available\\n\");\n  apply(rt, a, b, x);\n }\n void reverse()\
    \ {\n  static_assert(reversible, \"\\\"reverse\\\" is not available\\n\");\n \
    \ toggle(rt);\n }\n void reverse(size_t a, size_t b) {\n  static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\\n\");\n  assert(a < b), assert(b <= size());\n\
    \  auto [tmp, r]= split(rt, b);\n  auto [l, c]= split(tmp, a);\n  toggle(c), rt=\
    \ merge(merge(l, c), r);\n }\n};\n#line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class\
    \ Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 8 \"test/yosupo/range_affine_range_sum.RBST.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static T op(const T &l, const\
    \ T &r) { return l + r; }\n static void mp(T &v, const E &f, std::size_t sz) {\
    \ v= f.first * v + f.second * sz; }\n static void cp(E &pre, const E &suf) { pre=\
    \ {suf.first * pre.first, suf.first * pre.second + suf.second}; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >>\
    \ Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >> v[i];\n RandomizedBinarySearchTree<RaffineQ_RsumQ>\
    \ rbst(v, v + N);\n while (Q--) {\n  bool op;\n  int l, r;\n  cin >> op >> l >>\
    \ r;\n  if (op) {\n   cout << rbst.fold(l, r) << '\\n';\n  } else {\n   Mint b,\
    \ c;\n   cin >> b >> c;\n   rbst.apply(l, r, {b, c});\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n// apply, fold \u306E verify\n\n#include <iostream>\n#include \"src/DataStructure/RandomizedBinarySearchTree.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint= ModInt<998244353>;\n\
    struct RaffineQ_RsumQ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static\
    \ T op(const T &l, const T &r) { return l + r; }\n static void mp(T &v, const\
    \ E &f, std::size_t sz) { v= f.first * v + f.second * sz; }\n static void cp(E\
    \ &pre, const E &suf) { pre= {suf.first * pre.first, suf.first * pre.second +\
    \ suf.second}; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >>\
    \ v[i];\n RandomizedBinarySearchTree<RaffineQ_RsumQ> rbst(v, v + N);\n while (Q--)\
    \ {\n  bool op;\n  int l, r;\n  cin >> op >> l >> r;\n  if (op) {\n   cout <<\
    \ rbst.fold(l, r) << '\\n';\n  } else {\n   Mint b, c;\n   cin >> b >> c;\n  \
    \ rbst.apply(l, r, {b, c});\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/RandomizedBinarySearchTree.hpp
  - src/Internal/detection_idiom.hpp
  - src/Misc/rng.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.RBST.test.cpp
  requiredBy: []
  timestamp: '2024-03-31 14:30:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.RBST.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.RBST.test.cpp
- /verify/test/yosupo/range_affine_range_sum.RBST.test.cpp.html
title: test/yosupo/range_affine_range_sum.RBST.test.cpp
---