---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/WeightBalancedTree.hpp
    title: Weight-Balanced-Tree
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
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.WBT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n// \u9045\
    \u5EF6\u4F1D\u642C\u306Everify\n\n#include <iostream>\n#line 2 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \n#include <vector>\n#include <array>\n#include <string>\n#include <tuple>\n#include\
    \ <cstddef>\n#include <cassert>\n#line 2 \"src/Internal/detection_idiom.hpp\"\n\
    #include <type_traits>\n#define _DETECT_BOOL(name, ...) \\\n template <class,\
    \ class= void> struct name: std::false_type {}; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>>: std::true_type {}; \\\n template <class T>\
    \ static constexpr bool name##_v= name<T>::value\n#define _DETECT_TYPE(name, type1,\
    \ type2, ...) \\\n template <class T, class= void> struct name { \\\n  using type=\
    \ type2; \\\n }; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>\
    \ { \\\n  using type= type1; \\\n }\n#line 9 \"src/DataStructure/WeightBalancedTree.hpp\"\
    \nnamespace wbt_internal {\n#ifdef __LOCAL\nstatic constexpr size_t __LEAF_SIZE=\
    \ 1 << 15;\n#else\nstatic constexpr size_t __LEAF_SIZE= 1 << 20;\n#endif\n}\n\
    template <class M, bool reversible= false, bool persistent= false, size_t LEAF_SIZE=\
    \ wbt_internal::__LEAF_SIZE> class WeightBalancedTree {\n _DETECT_BOOL(semigroup,\
    \ typename T::T, decltype(&T::op));\n _DETECT_BOOL(dual, typename T::T, typename\
    \ T::E, decltype(&T::mp), decltype(&T::cp));\n _DETECT_BOOL(commute, typename\
    \ T::commute);\n _DETECT_TYPE(nullptr_or_E, typename T::E, std::nullptr_t, typename\
    \ T::E);\n _DETECT_TYPE(myself_or_T, typename T::T, T, typename T::T);\n struct\
    \ NodeMB {\n  std::array<int, 2> ch;\n  size_t sz= 0;\n };\n template <class D,\
    \ bool du> struct NodeMD: NodeMB {};\n template <class D> struct NodeMD<D, 1>:\
    \ NodeMB {\n  typename M::E laz;\n };\n template <class D, bool sg, bool rev,\
    \ bool com> struct NodeMS: NodeMD<D, dual_v<M>> {\n  typename M::T sum;\n };\n\
    \ template <class D, bool rev, bool com> struct NodeMS<D, 0, rev, com>: NodeMD<D,\
    \ dual_v<M>> {};\n template <class D> struct NodeMS<D, 1, 1, 0>: NodeMD<D, dual_v<M>>\
    \ {\n  typename M::T sum, rsum;\n };\n using NodeM= NodeMS<void, semigroup_v<M>,\
    \ reversible, commute_v<M>>;\n using T= typename myself_or_T<M>::type;\n using\
    \ E= typename nullptr_or_E<M>::type;\n using WBT= WeightBalancedTree;\n static\
    \ inline int nmi= 1, nli= 1;\n static constexpr size_t M_SIZE= LEAF_SIZE * 10;\n\
    \ static constexpr size_t L_SIZE= persistent && (dual_v<M> || reversible) ? LEAF_SIZE\
    \ * 10 : LEAF_SIZE;\n static inline NodeM nm[M_SIZE];\n static inline T nl[L_SIZE];\n\
    \ int root;\n static inline size_t msize(int i) noexcept {\n  if constexpr (dual_v<M>\
    \ || reversible) return nm[i].sz & 0x3fffffff;\n  else return nm[i].sz;\n }\n\
    \ static inline size_t size(int i) noexcept { return i < 0 ? 1 : msize(i); }\n\
    \ static inline T sum(int i) noexcept { return i < 0 ? nl[-i] : nm[i].sum; }\n\
    \ static inline T rsum(int i) noexcept { return i < 0 ? nl[-i] : nm[i].rsum; }\n\
    \ static inline void update(int i) noexcept {\n  auto t= nm + i;\n  auto [l, r]=\
    \ t->ch;\n  if constexpr (dual_v<M> || reversible) t->sz= (size(l) + size(r))\
    \ | (t->sz & 0xc0000000);\n  else t->sz= size(l) + size(r);\n  if constexpr (semigroup_v<M>)\
    \ {\n   t->sum= M::op(sum(l), sum(r));\n   if constexpr (reversible && !commute_v<M>)\
    \ t->rsum= M::op(rsum(r), rsum(l));\n  }\n }\n static inline void propagate(int\
    \ &i, const E &x) noexcept {\n  if constexpr (persistent) nm[nmi]= nm[i], i= nmi++;\n\
    \  auto t= nm + i;\n  if (t->sz >> 31) M::cp(t->laz, x);\n  else t->laz= x;\n\
    \  if constexpr (semigroup_v<M>) {\n   M::mp(t->sum, x, t->sz & 0x3fffffff);\n\
    \   if constexpr (reversible && !commute_v<M>) M::mp(t->rsum, x, t->sz & 0x3fffffff);\n\
    \  }\n  t->sz|= 0x80000000;\n }\n static inline void push_prop(int i) noexcept\
    \ {\n  if (auto t= nm + i; t->sz >> 31) {\n   auto &[l, r]= t->ch;\n   if (l <\
    \ 0) {\n    if constexpr (persistent) nl[nli]= nl[-l], l= -nli++;\n    M::mp(nl[-l],\
    \ t->laz, 1);\n   } else propagate(l, t->laz);\n   if (r < 0) {\n    if constexpr\
    \ (persistent) nl[nli]= nl[-r], r= -nli++;\n    M::mp(nl[-r], t->laz, 1);\n  \
    \ } else propagate(r, t->laz);\n   t->sz^= 0x80000000;\n  }\n }\n static inline\
    \ void toggle(int &i) noexcept {\n  if constexpr (persistent) nm[nmi]= nm[i],\
    \ i= nmi++;\n  auto t= nm + i;\n  std::swap(t->ch[0], t->ch[1]);\n  if constexpr\
    \ (semigroup_v<M> && !commute_v<M>) std::swap(t->sum, t->rsum);\n  t->sz^= 0x40000000;\n\
    \ }\n static inline void push_tog(int i) noexcept {\n  if (auto t= nm + i; t->sz\
    \ & 0x40000000) {\n   auto &[l, r]= t->ch;\n   if (l > 0) toggle(l);\n   if (r\
    \ > 0) toggle(r);\n   t->sz^= 0x40000000;\n  }\n }\n template <bool b> static\
    \ inline int helper(std::array<int, 2> &m) noexcept {\n  if constexpr (dual_v<M>)\
    \ push_prop(m[b]);\n  if constexpr (reversible) push_tog(m[b]);\n  int c;\n  if\
    \ constexpr (b) c= _merge({m[0], nm[m[1]].ch[0]});\n  else c= _merge({nm[m[0]].ch[1],\
    \ m[1]});\n  if constexpr (persistent) nm[nmi]= nm[m[b]], m[b]= nmi++;\n  if (size(nm[m[b]].ch[b])\
    \ * 4 >= msize(c)) return nm[m[b]].ch[!b]= c, update(m[b]), m[b];\n  return nm[m[b]].ch[!b]=\
    \ nm[c].ch[b], update(nm[c].ch[b]= m[b]), update(c), c;\n }\n static inline int\
    \ _merge(std::array<int, 2> m) noexcept {\n  int lsz= size(m[0]), rsz= size(m[1]);\n\
    \  if (lsz > rsz * 4) return helper<0>(m);\n  if (rsz > lsz * 4) return helper<1>(m);\n\
    \  return nm[nmi]= NodeM{m[0], m[1]}, update(nmi), nmi++;\n }\n static inline\
    \ int merge(int l, int r) noexcept { return !l ? r : !r ? l : _merge({l, r});\
    \ }\n static inline std::pair<int, int> _split(int i, size_t k) noexcept {\n \
    \ if constexpr (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n\
    \  auto t= nm + i;\n  auto [l, r]= t->ch;\n  if (size_t lsz= size(l); k == lsz)\
    \ return {l, r};\n  else if (k < lsz) {\n   auto [ll, lr]= _split(l, k);\n   return\
    \ {ll, _merge({lr, r})};\n  } else {\n   auto [rl, rr]= _split(r, k - lsz);\n\
    \   return {_merge({l, rl}), rr};\n  }\n }\n static inline std::pair<int, int>\
    \ split(int i, size_t k) noexcept {\n  if (k == 0) return {0, i};\n  if (k >=\
    \ size(i)) return {i, 0};\n  return _split(i, k);\n }\n template <class S> int\
    \ build(size_t l, size_t r, const S &bg) noexcept {\n  if (r - l == 1) {\n   if\
    \ constexpr (std::is_same_v<S, T>) return nl[nli]= bg, -nli++;\n   else return\
    \ nl[nli]= *(bg + l), -nli++;\n  }\n  size_t m= (l + r) / 2;\n  return nm[nmi]=\
    \ NodeM{build(l, m, bg), build(m, r, bg)}, update(nmi), nmi++;\n }\n void dump(int\
    \ i, typename std::vector<T>::iterator it) noexcept {\n  if (i < 0) *it= nl[-i];\n\
    \  else {\n   if constexpr (dual_v<M>) push_prop(i);\n   if constexpr (reversible)\
    \ push_tog(i);\n   dump(nm[i].ch[0], it), dump(nm[i].ch[1], it + size(nm[i].ch[0]));\n\
    \  }\n }\n T fold(int i, size_t l, size_t r) noexcept {\n  if (i < 0) return nl[-i];\n\
    \  if (l <= 0 && msize(i) <= r) return nm[i].sum;\n  if constexpr (dual_v<M>)\
    \ push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  auto [n0, n1]= nm[i].ch;\n\
    \  size_t lsz= size(n0);\n  if (r <= lsz) return fold(n0, l, r);\n  if (lsz <=\
    \ l) return fold(n1, l - lsz, r - lsz);\n  return M::op(fold(n0, l, lsz), fold(n1,\
    \ 0, r - lsz));\n }\n void apply(int &i, size_t l, size_t r, const E &x) noexcept\
    \ {\n  if (i < 0) {\n   if constexpr (persistent) nl[nli]= nl[-i], i= -nli++;\n\
    \   M::mp(nl[-i], x, 1);\n   return;\n  }\n  if (l <= 0 && msize(i) <= r) return\
    \ propagate(i, x);\n  if constexpr (reversible) push_tog(i);\n  push_prop(i);\n\
    \  if constexpr (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[n0, n1]= nm[i].ch;\n\
    \  size_t lsz= size(n0);\n  if (r <= lsz) apply(n0, l, r, x);\n  else if (lsz\
    \ <= l) apply(n1, l - lsz, r - lsz, x);\n  else apply(n0, l, lsz, x), apply(n1,\
    \ 0, r - lsz, x);\n  if constexpr (semigroup_v<M>) update(i);\n }\n void set_val(int\
    \ &i, size_t k, const T &x) noexcept {\n  if (i < 0) {\n   if constexpr (persistent)\
    \ nl[nli]= x, i= -nli++;\n   else nl[-i]= x;\n   return;\n  }\n  if constexpr\
    \ (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr\
    \ (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[l, r]= nm[i].ch;\n  size_t\
    \ lsz= size(l);\n  lsz > k ? set_val(l, k, x) : set_val(r, k - lsz, x);\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n void mul_val(int &i, size_t k, const\
    \ T &x) noexcept {\n  if (i < 0) {\n   if constexpr (persistent) nl[nli]= M::op(nl[-i],\
    \ x), i= -nli++;\n   else nl[-i]= M::op(nl[-i], x);\n   return;\n  }\n  if constexpr\
    \ (dual_v<M>) push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr\
    \ (persistent) nm[nmi]= nm[i], i= nmi++;\n  auto &[l, r]= nm[i].ch;\n  size_t\
    \ lsz= size(l);\n  lsz > k ? mul_val(l, k, x) : mul_val(r, k - lsz, x);\n  if\
    \ constexpr (semigroup_v<M>) update(i);\n }\n T get_val(int i, size_t k) noexcept\
    \ {\n  if (i < 0) return nl[-i];\n  if constexpr (dual_v<M>) push_prop(i);\n \
    \ if constexpr (reversible) push_tog(i);\n  auto [l, r]= nm[i].ch;\n  size_t lsz=\
    \ size(l);\n  return lsz > k ? get_val(l, k) : get_val(r, k - lsz);\n }\n T &at_val(int\
    \ i, size_t k) noexcept {\n  if (i < 0) {\n   if constexpr (persistent) return\
    \ nl[nli++]= nl[-i];\n   else return nl[-i];\n  }\n  if constexpr (dual_v<M>)\
    \ push_prop(i);\n  if constexpr (reversible) push_tog(i);\n  if constexpr (persistent)\
    \ nm[nmi]= nm[i], i= nmi++;\n  auto [l, r]= nm[i].ch;\n  size_t lsz= size(l);\n\
    \  return lsz > k ? at_val(l, k) : at_val(r, k - lsz);\n }\n static WBT id_to_wbt(int\
    \ t) noexcept {\n  WBT ret;\n  return ret.root= t, ret;\n }\npublic:\n WeightBalancedTree():\
    \ root(0) {}\n WeightBalancedTree(size_t n, T val= T()): root(n ? build(0, n,\
    \ val) : 0) {}\n WeightBalancedTree(const T *bg, const T *ed): root(bg == ed ?\
    \ 0 : build(0, ed - bg, bg)) {}\n WeightBalancedTree(const std::vector<T> &ar):\
    \ WeightBalancedTree(ar.data(), ar.data() + ar.size()){};\n WBT &operator+=(WBT\
    \ rhs) { return root= merge(root, rhs.root), *this; }\n WBT operator+(WBT rhs)\
    \ { return WBT(*this)+= rhs; }\n std::pair<WBT, WBT> split(size_t k) {\n  assert(root);\n\
    \  auto [l, r]= split(root, k);\n  return {id_to_wbt(l), id_to_wbt(r)};\n }\n\
    \ std::tuple<WBT, WBT, WBT> split3(size_t a, size_t b) {\n  assert(root), assert(a\
    \ <= b);\n  auto [tmp, r]= split(root, b);\n  auto [l, c]= split(tmp, a);\n  return\
    \ {id_to_wbt(l), id_to_wbt(c), id_to_wbt(r)};\n }\n size_t size() const { return\
    \ root ? size(root) : 0; }\n void insert(size_t k, T val) {\n  auto [l, r]= split(root,\
    \ k);\n  nl[nli]= val, root= merge(merge(l, -nli++), r);\n }\n void push_back(T\
    \ val) { nl[nli]= val, root= merge(root, -nli++); }\n void push_front(T val) {\
    \ nl[nli]= val, root= merge(-nli++, root); }\n T erase(size_t k) {\n  assert(k\
    \ < size());\n  auto [l, tmp]= split(root, k);\n  auto [t, r]= split(tmp, 1);\n\
    \  return root= merge(l, r), nl[-t];\n }\n T pop_back() {\n  auto [l, t]= split(root,\
    \ size() - 1);\n  return root= l, nl[-t];\n }\n T pop_front() {\n  auto [t, r]=\
    \ split(root, 1);\n  return root= r, nl[-t];\n }\n void set(size_t k, T val) {\
    \ set_val(root, k, val); }\n void mul(size_t k, T val) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"mul\\\" is not available\\n\");\n  mul_val(root, k, val);\n }\n T get(size_t\
    \ k) { return get_val(root, k); }\n T &at(size_t k) {\n  static_assert(!semigroup_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(root, k);\n }\n template\
    \ <class L= M> std::enable_if_t<semigroup_v<L>, T> operator[](size_t k) { return\
    \ get(k); }\n template <class L= M> std::enable_if_t<!semigroup_v<L>, T> &operator[](size_t\
    \ k) { return at(k); }\n T fold(size_t a, size_t b) {\n  static_assert(semigroup_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b);\n }\n void\
    \ apply(size_t a, size_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(root, a, b, x);\n }\n void reverse(size_t a,\
    \ size_t b) {\n  static_assert(reversible, \"\\\"reverse\\\" is not available\\\
    n\");\n  assert(root), assert(a <= b);\n  auto [tmp, r]= split(root, b);\n  auto\
    \ [l, c]= split(tmp, a);\n  if (c > 0) toggle(c);\n  root= merge(merge(l, c),\
    \ r);\n }\n std::vector<T> dump() {\n  if (!root) return std::vector<T>();\n \
    \ std::vector<T> ret(size());\n  return dump(root, ret.begin()), ret;\n }\n void\
    \ clear() { root= 0; }\n static void reset() { nmi= 1, nli= 1; }\n static std::string\
    \ which_available() {\n  std::string ret= \"\";\n  if constexpr (semigroup_v<M>)\
    \ ret+= \"\\\"fold\\\" \";\n  else ret+= \"\\\"at\\\" \";\n  if constexpr (dual_v<M>)\
    \ ret+= \"\\\"apply\\\" \";\n  if constexpr (reversible) ret+= \"\\\"reverse\\\
    \" \";\n  return ret;\n }\n static bool pool_empty() {\n  if constexpr (persistent\
    \ && (dual_v<M> || reversible)) return nmi + LEAF_SIZE >= M_SIZE || nli + LEAF_SIZE\
    \ >= L_SIZE;\n  else return nmi + 1000 >= M_SIZE || nli + 1000 >= L_SIZE;\n }\n\
    };\n#line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b),\
    \ z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod\
    \ : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 8 \"test/yosupo/range_affine_range_sum.WBT.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static T op(const T &l, const\
    \ T &r) { return l + r; }\n static void mp(T &v, const E &f, std::size_t sz) {\
    \ v= f.first * v + f.second * sz; }\n static void cp(E &pre, const E &suf) { pre=\
    \ {suf.first * pre.first, suf.first * pre.second + suf.second}; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >>\
    \ Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >> v[i];\n using WBT= WeightBalancedTree<RaffineQ_RsumQ>;\n\
    \ WBT wbt(v, v + N);\n while (Q--) {\n  bool op;\n  int l, r;\n  cin >> op >>\
    \ l >> r;\n  if (op) {\n   cout << wbt.fold(l, r) << endl;\n  } else {\n   Mint\
    \ b, c;\n   cin >> b >> c;\n   wbt.apply(l, r, {b, c});\n  }\n  if (WBT::pool_empty())\
    \ {\n   auto dump= wbt.dump();\n   WBT::reset();\n   wbt= WBT(dump);\n  }\n }\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n// \u9045\u5EF6\u4F1D\u642C\u306Everify\n\n#include <iostream>\n#include \"\
    src/DataStructure/WeightBalancedTree.hpp\"\n#include \"src/Math/ModInt.hpp\"\n\
    using namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct RaffineQ_RsumQ\
    \ {\n using T= Mint;\n using E= pair<Mint, Mint>;\n static T op(const T &l, const\
    \ T &r) { return l + r; }\n static void mp(T &v, const E &f, std::size_t sz) {\
    \ v= f.first * v + f.second * sz; }\n static void cp(E &pre, const E &suf) { pre=\
    \ {suf.first * pre.first, suf.first * pre.second + suf.second}; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >>\
    \ Q;\n Mint v[N];\n for (int i= 0; i < N; i++) cin >> v[i];\n using WBT= WeightBalancedTree<RaffineQ_RsumQ>;\n\
    \ WBT wbt(v, v + N);\n while (Q--) {\n  bool op;\n  int l, r;\n  cin >> op >>\
    \ l >> r;\n  if (op) {\n   cout << wbt.fold(l, r) << endl;\n  } else {\n   Mint\
    \ b, c;\n   cin >> b >> c;\n   wbt.apply(l, r, {b, c});\n  }\n  if (WBT::pool_empty())\
    \ {\n   auto dump= wbt.dump();\n   WBT::reset();\n   wbt= WBT(dump);\n  }\n }\n\
    \ return 0;\n}"
  dependsOn:
  - src/DataStructure/WeightBalancedTree.hpp
  - src/Internal/detection_idiom.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.WBT.test.cpp
  requiredBy: []
  timestamp: '2024-03-22 14:55:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.WBT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.WBT.test.cpp
- /verify/test/yosupo/range_affine_range_sum.WBT.test.cpp.html
title: test/yosupo/range_affine_range_sum.WBT.test.cpp
---
