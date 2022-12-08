---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
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
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_f
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.DynSeg.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n// \u53CC\u5BFE \u306E\
    \ verify\n\n#include <bits/stdc++.h>\n#line 3 \"src/Math/mod_inv.hpp\"\n/**\n\
    \ * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n\
    \ * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\
    \u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\n\
    namespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\nstruct MIntPro_Montg {\n  const\
    \ u64 mod;\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0) {}\n  constexpr\
    \ MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr\
    \ inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define\
    \ BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n  constexpr inline\
    \ u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n  constexpr inline\
    \ u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n  constexpr inline\
    \ u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline u64 get(u64\
    \ n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod & -(ret >>\
    \ 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n - (mod & -(n\
    \ >= mod)); }\n\n private:\n  const u64 iv, r2;\n  constexpr u64 inv(u64 n, int\
    \ e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n\
    \  constexpr inline u64 reduce(const u128 &w) const {\n    return u64(w >> 64)\
    \ + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n};\ntemplate <class Uint>\n\
    class MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint, u32>, u64, u128>;\n\
    \n public:\n  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n  constexpr\
    \ MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r)\
    \ const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m## = mod &\
    \ -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return n; }\n  static\
    \ constexpr inline Uint get(Uint n) { return n; }\n  static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class U, class B>\nstruct ModInt : public B {\n\
    \  using Uint = U;\n  static constexpr inline auto modulo() { return B::md.mod;\
    \ }\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x)\
    \ {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T v) : x(B::md.set(v.val() % B::md.mod)) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T n)\n      : x(B::md.set((n %= B::md.mod) < 0 ? n + B::md.mod\
    \ : n)) {}\n  constexpr ModInt operator-() const { return ModInt() - *this; }\n\
    #define FUNC(name, op)          \\\n  constexpr ModInt name const { \\\n    ModInt\
    \ ret;                 \\\n    return ret.x = op, ret;     \\\n  }\n  FUNC(operator+(const\
    \ ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const ModInt &r), B::md.diff(x,\
    \ r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64\
    \ k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr ModInt operator/(const\
    \ ModInt &r) const { return *this * r.inv(); }\n  constexpr ModInt &operator+=(const\
    \ ModInt &r) { return *this = *this + r; }\n  constexpr ModInt &operator-=(const\
    \ ModInt &r) { return *this = *this - r; }\n  constexpr ModInt &operator*=(const\
    \ ModInt &r) { return *this = *this * r; }\n  constexpr ModInt &operator/=(const\
    \ ModInt &r) { return *this = *this / r; }\n  constexpr bool operator==(const\
    \ ModInt &r) const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr\
    \ bool operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr\
    \ bool operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), B::md.mod);\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 3 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n\
    /**\n * @title Segment-Tree(\u52D5\u7684\u69CB\u7BC9)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u9045\u5EF6\u4F1D\u642C\u53EF\n * \u6C38\u7D9A\u5316\u53EF\
    \n * O(logN)\n */\n\n// verify\u7528:\n// https://codeforces.com/contest/464/problem/E\
    \ (\u6C38\u7D9A+\u9045\u5EF6\u4F1D\u642C+find*2)\n// https://codeforces.com/contest/947/problem/C\
    \ (find+xor)\n// https://codeforces.com/contest/966/problem/C (find+xor)\n// https://codeforces.com/contest/295/problem/E\
    \ (\u7279\u6B8A\u30E2\u30CE\u30A4\u30C9+\u5EA7\u5727\u30B5\u30DC\u308A)\n// https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query\n\
    // (\u6C38\u7D9A)\n\n// BEGIN CUT HERE\n\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
    \ Dummy)                              \\\n  template <class T>               \
    \                           \\\n  struct has_##member {                      \
    \                 \\\n    template <class U, Dummy>                          \
    \       \\\n    static std::true_type check(U *);                         \\\n\
    \    static std::false_type check(...);                        \\\n    static\
    \ T *mClass;                                         \\\n    static const bool\
    \ value = decltype(check(mClass))::value; \\\n  };\n#define HAS_MEMBER(member)\
    \ HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member) HAS_CHECK(member,\
    \ class dummy = typename U::member)\n#endif\n\ntemplate <typename M, bool persistent\
    \ = false, std::uint8_t HEIGHT = 30>\nclass SegmentTree_Dynamic {\n  HAS_MEMBER(op);\n\
    \  HAS_MEMBER(ti);\n  HAS_MEMBER(mapping);\n  HAS_MEMBER(composition);\n  HAS_TYPE(T);\n\
    \  HAS_TYPE(E);\n  template <class L>\n  using monoid = std::conjunction<has_T<L>,\
    \ has_op<L>, has_ti<L>>;\n  template <class L>\n  using dual =\n      std::conjunction<has_T<L>,\
    \ has_E<L>, has_mapping<L>, has_composition<L>>;\n  using id_t = long long;\n\
    \  template <class T, class tDerived, class F = std::nullptr_t>\n  struct Node_B\
    \ {\n    using E = F;\n    T val;\n    tDerived *ch[2] = {nullptr, nullptr};\n\
    \  };\n  template <bool mo_, bool du_, typename tEnable = void>\n  struct Node_D\
    \ : Node_B<M, Node_D<mo_, du_, tEnable>> {};\n  template <bool mo_, bool du_>\n\
    \  struct Node_D<mo_, du_, typename std::enable_if_t<mo_ && !du_>>\n      : Node_B<typename\
    \ M::T, Node_D<mo_, du_>> {};\n  template <bool mo_, bool du_>\n  struct Node_D<mo_,\
    \ du_, typename std::enable_if_t<du_>>\n      : Node_B<typename M::T, Node_D<mo_,\
    \ du_>, typename M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false;\n\
    \  };\n  using Node = Node_D<monoid<M>::value, dual<M>::value>;\n  using T = decltype(Node::val);\n\
    \  using E = typename Node::E;\n  Node *root;\n  static inline constexpr T def_val()\
    \ {\n    if constexpr (monoid<M>::value)\n      return M::ti();\n    else\n  \
    \    return T();\n  }\n  template <class S>\n  void build(Node *&t, const id_t\
    \ &n, std::array<id_t, 2> b, const S &bg) {\n    if (n <= b[0]) return;\n    id_t\
    \ m = (b[0] + b[1]) >> 1;\n    if (b[1] - b[0] == 1) {\n      if constexpr (std::is_same_v<S,\
    \ T>)\n        t = new Node{bg};\n      else\n        t = new Node{*(bg + b[0])};\n\
    \    } else {\n      t = new Node{def_val()};\n      build(t->ch[0], n, {b[0],\
    \ m}, bg), build(t->ch[1], n, {m, b[1]}, bg);\n      if constexpr (monoid<M>::value)\
    \ pushup(t);\n    }\n  }\n  void dump(Node *t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b,\n            typename std::vector<T>::iterator itr) {\n    if (r <= b[0]\
    \ || b[1] <= l) return;\n    if (l <= b[0] && b[1] <= r && !t) {\n      for (id_t\
    \ i = b[0]; i < b[1]; i++) *(itr + i) = def_val();\n    } else if (b[1] - b[0]\
    \ != 1) {\n      if constexpr (dual<M>::value) eval(t, b[1] - b[0]);\n      auto\
    \ m = (b[0] + b[1]) >> 1;\n      dump(t ? t->ch[0] : nullptr, l, r, {b[0], m},\
    \ itr);\n      dump(t ? t->ch[1] : nullptr, l, r, {m, b[1]}, itr);\n    } else\n\
    \      *(itr + b[0]) = t->val;\n  }\n  static inline void pushup(Node *&t) {\n\
    \    t->val = def_val();\n    if (t->ch[0]) t->val = M::op(t->ch[0]->val, t->val);\n\
    \    if (t->ch[1]) t->val = M::op(t->val, t->ch[1]->val);\n  }\n  static inline\
    \ T &reflect(Node *&t) {\n    if constexpr (dual<M>::value && !monoid<M>::value)\n\
    \      if (t->lazy_flg) M::mapping(t->val, t->lazy, 1), t->lazy_flg = false;\n\
    \    return t->val;\n  }\n  static inline void propagate(Node *&t, const E &x,\
    \ const id_t &sz) {\n    t->lazy_flg ? (M::composition(t->lazy, x), x) : t->lazy\
    \ = x;\n    t->lazy_flg = true;\n    if constexpr (monoid<M>::value) M::mapping(t->val,\
    \ x, sz);\n  }\n  static inline void cp_node(Node *&t) {\n    if (!t)\n      t\
    \ = new Node{def_val()};\n    else if constexpr (persistent)\n      t = new Node(*t);\n\
    \  }\n  static inline void eval(Node *&t, const id_t &sz) {\n    if (!t->lazy_flg)\
    \ return;\n    cp_node(t->ch[0]), cp_node(t->ch[1]), t->lazy_flg = false;\n  \
    \  propagate(t->ch[0], t->lazy, sz / 2), propagate(t->ch[1], t->lazy, sz / 2);\n\
    \  }\n  T fold(Node *&t, const id_t &l, const id_t &r, std::array<id_t, 2> b,\n\
    \         const id_t &bias) {\n    if (!t || r <= b[0] || b[1] <= l) return def_val();\n\
    \    if (l <= b[0] && b[1] <= r) return t->val;\n    if constexpr (dual<M>::value)\
    \ eval(t, b[1] - b[0]);\n    id_t m = (b[0] + b[1]) >> 1;\n    bool flg = (bias\
    \ >> (__builtin_ctzll(b[1] - b[0]) - 1)) & 1;\n    return M::op(fold(t->ch[flg],\
    \ l, r, {b[0], m}, bias),\n                 fold(t->ch[!flg], l, r, {m, b[1]},\
    \ bias));\n  }\n  void apply(Node *&t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b,\n             const E &x) {\n    if (r <= b[0] || b[1] <= l) return;\n\
    \    id_t m = (b[0] + b[1]) >> 1;\n    if (cp_node(t); l <= b[0] && b[1] <= r)\
    \ return propagate(t, x, b[1] - b[0]);\n    eval(t, b[1] - b[0]);\n    apply(t->ch[0],\
    \ l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);\n    if constexpr\
    \ (monoid<M>::value) pushup(t);\n  }\n  void set_val(Node *&t, const id_t &k,\
    \ const T &val, std::uint8_t h) {\n    if (cp_node(t); !h) return reflect(t) =\
    \ val, void();\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    set_val(t->ch[(k\
    \ >> (h - 1)) & 1], k, val, h - 1);\n    if constexpr (monoid<M>::value) pushup(t);\n\
    \  }\n  T &at_val(Node *&t, const id_t &k, std::uint8_t h) {\n    if (cp_node(t);\
    \ !h) return reflect(t);\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n\
    \    return at_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  bool is_null(Node\
    \ *&t, const id_t &k, std::uint8_t h) {\n    if (!t) return true;\n    if (!h)\
    \ return false;\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    return\
    \ is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  T get_val(Node *&t, const\
    \ id_t &k, std::uint8_t h) {\n    if (!t) return def_val();\n    if (!h) return\
    \ reflect(t);\n    if constexpr (dual<M>::value) eval(t, 1LL << h);\n    return\
    \ get_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n  }\n  template <bool last>\n\
    \  static inline T calc_op(Node *&t, const T &v) {\n    if constexpr (last)\n\
    \      return M::op((t ? t->val : def_val()), v);\n    else\n      return M::op(v,\
    \ (t ? t->val : def_val()));\n  }\n  template <bool last>\n  static inline bool\
    \ is_in(const id_t &m, const id_t &k) {\n    if constexpr (last)\n      return\
    \ k <= m;\n    else\n      return m <= k;\n  }\n  template <bool last, class C,\
    \ std::size_t N>\n  static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias,\n                   std::uint8_t h, const C &check, std::array<Node\
    \ *, N> &ts,\n                   std::array<T, N> &sums) {\n    static_assert(monoid<M>::value,\
    \ \"\\\"find\\\" is not available\\n\");\n    static std::array<T, N> sums2;\n\
    \    if (std::all_of(ts.begin(), ts.end(), [](Node *t) { return !t; }))\n    \
    \  return -1;\n    if (!h) {\n      for (std::size_t i = N; i--;) sums[i] = calc_op<last>(ts[i],\
    \ sums[i]);\n      return std::apply(check, sums) ? std::get<last>(b) : -1;\n\
    \    } else if (is_in<last>(k, b[0])) {\n      for (std::size_t i = N; i--;) sums2[i]\
    \ = calc_op<last>(ts[i], sums[i]);\n      if (!std::apply(check, sums2)) return\
    \ sums = std::move(sums2), -1;\n    }\n    if constexpr (dual<M>::value)\n   \
    \   for (std::size_t i = N; i--;) eval(ts[i], b[1] - b[0]);\n    std::array<Node\
    \ *, N> ss;\n    id_t m = (b[0] + b[1]) >> 1;\n    bool flg = (bias >> (h - 1))\
    \ & 1;\n    if (!is_in<last>(m, k)) {\n      for (std::size_t i = N; i--;) ss[i]\
    \ = ts[i] ? ts[i]->ch[flg] : nullptr;\n      id_t ret = find<last>(k, {b[0], m},\
    \ bias, h - 1, check, ss, sums);\n      if (ret >= 0) return ret;\n    }\n   \
    \ for (std::size_t i = N; i--;) ss[i] = ts[i] ? ts[i]->ch[!flg] : nullptr;\n \
    \   return find<last>(k, {m, b[1]}, bias, h - 1, check, ss, sums);\n  }\n\n public:\n\
    \  SegmentTree_Dynamic(Node *t = nullptr) : root(t) {}\n  SegmentTree_Dynamic(std::size_t\
    \ n, T val) : root(nullptr) {\n    build(root, n, {0, 1LL << HEIGHT}, val);\n\
    \  }\n  SegmentTree_Dynamic(const T *bg, const T *ed) : root(nullptr) {\n    build(root,\
    \ ed - bg, {0, 1LL << HEIGHT}, bg);\n  }\n  SegmentTree_Dynamic(const std::vector<T>\
    \ &ar)\n      : SegmentTree_Dynamic(ar.data(), ar.data() + ar.size()) {}\n  void\
    \ set(id_t k, T val) { set_val(root, k, val, HEIGHT); }\n  T get(id_t k) { return\
    \ get_val(root, k, HEIGHT); }\n  bool is_null(id_t k) { return is_null(root, k,\
    \ HEIGHT); }\n  T &at(id_t k) {\n    static_assert(!monoid<M>::value, \"\\\"at\\\
    \" is not available\\n\");\n    return at_val(root, k, HEIGHT);\n  }\n  template\
    \ <class L = M,\n            typename std::enable_if_t<monoid<L>::value> * = nullptr>\n\
    \  T operator[](id_t k) {\n    return get(k);\n  }\n  template <class L = M,\n\
    \            typename std::enable_if_t<!monoid<L>::value> * = nullptr>\n  T &operator[](id_t\
    \ k) {\n    return at(k);\n  }\n  T fold(id_t a, id_t b, id_t bias = 0) {\n  \
    \  static_assert(monoid<M>::value, \"\\\"fold\\\" is not available\\n\");\n  \
    \  return fold(root, a, b, {0, 1LL << HEIGHT}, bias);\n  }\n  // find i s.t.\n\
    \  //  check(fold(a,i)) == False, check(fold(a,i+1)) == True\n  // return -1 if\
    \ not found\n  template <class C>\n  id_t find_first(id_t a, C check, id_t bias\
    \ = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node *, 1> t{root};\n\
    \    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n  }\n\
    \  template <std::size_t N, class C>\n  static id_t find_first(id_t a, C check,\n\
    \                         std::array<SegmentTree_Dynamic, N> segs,\n         \
    \                id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  // find i s.t.\n  //  check(fold(i+1,b)) == False, check(fold(i,b))\
    \ == True\n  // return -1 if not found\n  template <class C>\n  id_t find_last(id_t\
    \ b, C check, id_t bias = 0) {\n    std::array<T, 1> sum{def_val()};\n    std::array<Node\
    \ *, 1> t{root};\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ t, sum);\n  }\n  template <std::size_t N, class C>\n  static id_t find_last(id_t\
    \ b, C check,\n                        std::array<SegmentTree_Dynamic, N> segs,\n\
    \                        id_t bias = 0) {\n    std::array<T, N> sums;\n    sums.fill(def_val());\n\
    \    std::array<Node *, N> ts;\n    for (std::size_t i = 0; i < N; i++) ts[i]\
    \ = segs[i].root;\n    return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check,\
    \ ts, sums);\n  }\n  void apply(id_t a, id_t b, E x) {\n    static_assert(dual<M>::value,\
    \ \"\\\"apply\\\" is not available\\n\");\n    apply(root, a, b, {0, 1LL << HEIGHT},\
    \ x);\n  }\n  std::vector<T> dump(id_t bg, id_t ed) {\n    std::vector<T> ret(ed\
    \ - bg);\n    return dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin()), ret;\n\
    \  }\n  static std::string which_available() {\n    std::string ret = \"\";\n\
    \    if constexpr (monoid<M>::value)\n      ret += \"\\\"fold\\\" \\\"find\\\"\
    \ \";\n    else\n      ret += \"\\\"at\\\" \";\n    if constexpr (dual<M>::value)\
    \ ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n};\n#line 8 \"test/atcoder/abc256_f.DynSeg.test.cpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n\
    \  struct T {\n    Mint val, coef[2];\n    T() = default;\n    T(Mint id, Mint\
    \ v)\n        : val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n \
    \ };\n  using E = array<Mint, 3>;\n  static void mapping(T &x, const E &mapp,\
    \ int) {\n    x.val += mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n\
    \  }\n  static void composition(E &pre, const E &suf) {\n    pre[0] += suf[0],\
    \ pre[1] += suf[1], pre[2] += suf[2];\n  }\n};\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  int N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n\
    \  for (int i = 0; i < N; i++) cin >> A[i], D[i] = A[i];\n  for (int j = 0; j\
    \ < 3; j++)\n    for (int i = 1; i < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dynamic<Mono>\
    \ seg;\n  for (int i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n\
    \    int op, x;\n    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n\
    \      cin >> v, v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x\
    \ * x / 2});\n    } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n\
    // \u53CC\u5BFE \u306E verify\n\n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/DataStructure/SegmentTree_Dynamic.hpp\"\nusing namespace std;\n\
    \nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n  struct T {\n    Mint\
    \ val, coef[2];\n    T() = default;\n    T(Mint id, Mint v)\n        : val(v),\
    \ coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n  };\n  using E = array<Mint,\
    \ 3>;\n  static void mapping(T &x, const E &mapp, int) {\n    x.val += mapp[0]\
    \ * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n  }\n  static void composition(E\
    \ &pre, const E &suf) {\n    pre[0] += suf[0], pre[1] += suf[1], pre[2] += suf[2];\n\
    \  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> A[i], D[i] = A[i];\n  for (int j = 0; j < 3; j++)\n    for (int i = 1; i\
    \ < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dynamic<Mono> seg;\n  for (int i\
    \ = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n    int op, x;\n \
    \   cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n      cin >> v, v\
    \ -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x * x / 2});\n   \
    \ } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/DataStructure/SegmentTree_Dynamic.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2022-12-08 15:47:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.DynSeg.test.cpp
- /verify/test/atcoder/abc256_f.DynSeg.test.cpp.html
title: test/atcoder/abc256_f.DynSeg.test.cpp
---
