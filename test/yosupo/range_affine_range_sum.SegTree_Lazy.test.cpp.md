---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Beats.hpp
    title: Segment-Tree Beats!
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <bits/stdc++.h>\n\n#line 3 \"src/DataStructure/SegmentTree_Beats.hpp\"\
    \n/**\n * @title Segment-Tree Beats!\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n * @brief \u57FA\u672C, \u9045\u5EF6\u4F1D\u642C\u3068\u3057\u3066\u3064\u304B\
    \u3046\n * @see https://rsm9.hatenablog.com/entry/2021/02/01/220408\n */\n\n//\
    \ BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree_Beats {\n  using\
    \ T = typename M::T;\n  using E = typename M::E;\n  SegmentTree_Beats() {}\n \
    \ SegmentTree_Beats(int n_)\n      : n(n_),\n        height(ceil(log2(n))),\n\
    \        dat(n * 2, M::ti()),\n        laz(n * 2, {E(), false}) {}\n  SegmentTree_Beats(int\
    \ n_, T v1) : SegmentTree_Beats(n_) {\n    for (int i = n; i--;) dat[i + n] =\
    \ v1;\n    for (int i = n; --i;) update(i);\n  }\n  SegmentTree_Beats(const std::vector<T>\
    \ &v) : SegmentTree_Beats(v.size()) {\n    for (int i = n; i--;) dat[i + n] =\
    \ v[i];\n    for (int i = n; --i;) update(i);\n  }\n  void unsafe_set(int k, T\
    \ x) { dat[k + n] = x; }\n  void rebuild() {\n    for (int i = n + n; i--;) laz[i].flg\
    \ = false;\n    for (int i = n; --i;) update(i);\n  }\n  void apply(int a, int\
    \ b, E x) {\n    a += n, b += n;\n    for (int i = height; i; i--)\n      if (((a\
    \ >> i) << i) != a) eval(a >> i);\n    for (int i = height; i; i--)\n      if\
    \ (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l = a, r = b; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n      if (r & 1) propagate(--r,\
    \ x);\n    }\n    for (int i = 1; a >> i; i++)\n      if (((a >> i) << i) != a)\
    \ update(a >> i);\n    for (int i = 1; b >> i; i++)\n      if (((b >> i) << i)\
    \ != b) update((b - 1) >> i);\n  }\n  void set(int k, T x) {\n    int i = height;\n\
    \    for (k += n; i; i--) eval(k >> i);\n    for (dat[k] = x, laz[k].flg = false,\
    \ i = 1; k >> i; i++) update(k >> i);\n  }\n  T fold(int a, int b) {  //[a,b)\n\
    \    a += n, b += n;\n    for (int i = height; i; i--)\n      if (((a >> i) <<\
    \ i) != a) eval(a >> i);\n    for (int i = height; i; i--)\n      if (((b >> i)\
    \ << i) != b) eval(b >> i);\n    T vl = M::ti(), vr = M::ti();\n    for (int l\
    \ = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) vl = M::op(vl, dat[l++]);\n\
    \      if (r & 1) vr = M::op(dat[--r], vr);\n    }\n    return M::op(vl, vr);\n\
    \  }\n  T operator[](const int k) { return fold(k, k + 1); }\n\n private:\n  const\
    \ int n, height;\n  struct Lazy {\n    E val;\n    bool flg;\n  };\n  std::vector<T>\
    \ dat;\n  std::vector<Lazy> laz;\n  inline void eval(int k) {\n    if (!laz[k].flg)\
    \ return;\n    propagate(k << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n\
    \    laz[k].flg = false;\n  }\n  inline void propagate(int k, const E &x) {\n\
    \    if (bool success = M::mapping(dat[k], x); k < n) {\n      laz[k].flg ? (M::composition(laz[k].val,\
    \ x), x) : laz[k].val = x;\n      if (laz[k].flg = true; !success) eval(k), update(k);\n\
    \    }\n  }\n  inline void update(int k) {\n    dat[k] = M::op(dat[k << 1 | 0],\
    \ dat[k << 1 | 1]);\n  }\n};\n#line 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title\
    \ \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n */\n\n\
    // BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0, b = mod;\n\
    \  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y = z - y * (q\
    \ = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n * @title\
    \ ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\u5B66\n\
    \ * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using u128 = __uint128_t;\nstruct MIntPro_Montg {\n  const u64 mod;\n  constexpr\
    \ MIntPro_Montg() : mod(0), iv(0), r2(0) {}\n  constexpr MIntPro_Montg(u64 m)\
    \ : mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr inline u64 mul(u64\
    \ l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l\
    \ op## = a, l += (mod << 1) & -(l >> 63)\n  constexpr inline u64 plus(u64 l, u64\
    \ r) const { BOP(+, r - (mod << 1)); }\n  constexpr inline u64 diff(u64 l, u64\
    \ r) const { BOP(-, r); }\n#undef BOP\n  constexpr inline u64 set(u64 n) const\
    \ { return mul(n, r2); }\n  constexpr inline u64 get(u64 n) const {\n    u64 ret\
    \ = reduce(n) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\n\n private:\n\
    \  const u64 iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n   \
    \ return e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64\
    \ reduce(const u128 &w) const {\n    return u64(w >> 64) + mod - ((u128(u64(w)\
    \ * iv) * mod) >> 64);\n  }\n};\ntemplate <class Uint>\nclass MIntPro_Na {\n \
    \ using DUint = conditional_t<is_same_v<Uint, u32>, u64, u128>;\n\n public:\n\
    \  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n  constexpr MIntPro_Na(Uint\
    \ m) : mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r) const { return DUint(l)\
    \ * r % mod; }\n#define BOP(m, p) return l m## = mod & -((l p## = r) >= mod)\n\
    \  constexpr inline Uint plus(Uint l, Uint r) const { BOP(-, +); }\n  constexpr\
    \ inline Uint diff(Uint l, Uint r) const { BOP(+, -); }\n#undef BOP\n  static\
    \ constexpr inline Uint set(Uint n) { return n; }\n  static constexpr inline Uint\
    \ get(Uint n) { return n; }\n  static constexpr inline Uint norm(Uint n) { return\
    \ n; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr Uint pow(Uint x,\
    \ u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);; x = md.mul(x, x))\n\
    \    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return ret;\n}\n}  // namespace\
    \ math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category\
    \ \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\nstruct modint_base\
    \ {};\nstruct sta_mint_base : modint_base {};\nstruct run_mint_base : modint_base\
    \ {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
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
    \  constexpr ModInt(T n)\n      : x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod\
    \ : n % B::md.mod))) {}\n  constexpr ModInt operator-() const { return ModInt()\
    \ - *this; }\n#define FUNC(name, op)          \\\n  constexpr ModInt name const\
    \ { \\\n    ModInt ret;                 \\\n    return ret.x = op, ret;     \\\
    \n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const\
    \ ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x,\
    \ r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr\
    \ ModInt operator/(const ModInt &r) const { return *this * r.inv(); }\n  constexpr\
    \ ModInt &operator+=(const ModInt &r) { return *this = *this + r; }\n  constexpr\
    \ ModInt &operator-=(const ModInt &r) { return *this = *this - r; }\n  constexpr\
    \ ModInt &operator*=(const ModInt &r) { return *this = *this * r; }\n  constexpr\
    \ ModInt &operator/=(const ModInt &r) { return *this = *this / r; }\n  constexpr\
    \ bool operator==(const ModInt &r) const {\n    return B::md.norm(x) == B::md.norm(r.x);\n\
    \  }\n  constexpr bool operator!=(const ModInt &r) const { return !(*this == r);\
    \ }\n  constexpr bool operator<(const ModInt &r) const {\n    return B::md.norm(x)\
    \ < B::md.norm(r.x);\n  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n  constexpr inline Uint val() const { return B::md.get(x); }\n\
    \  friend ostream &operator<<(ostream &os, const ModInt &r) {\n    return os <<\
    \ r.val();\n  }\n  friend istream &operator>>(istream &is, ModInt &r) {\n    long\
    \ long v;\n    return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n\
    };\ntemplate <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX,\
    \ ModInt<int, u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD\
    \ &(MOD < LLONG_MAX),\n                      ModInt<long long, u64, StaticB<MIntPro_Montg,\
    \ MOD>>,\n                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt\
    \ = conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 6 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\n// RsumQ\u306F\
    \u30E2\u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\
    \u304F\nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n    int sz;\n  };\n\
    \  using E = pair<Mint, Mint>;\n  static T ti() { return {0, 0}; }\n  static T\
    \ op(const T &l, const T &r) { return {l.val + r.val, l.sz + r.sz}; }\n  static\
    \ bool mapping(T &v, const E &f) {\n    return v.val = f.first * v.val + f.second\
    \ * v.sz, true;\n  }\n  static void composition(E &pre, const E &suf) {\n    pre\
    \ = {pre.first * suf.first, suf.first * pre.second + suf.second};\n  }\n};\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  SegmentTree_Beats<RaffineQ_RsumQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << seg.fold(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/DataStructure/SegmentTree_Beats.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\n\
    // RsumQ\u306F\u30E2\u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\
    \u3066\u304A\u304F\nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n   \
    \ int sz;\n  };\n  using E = pair<Mint, Mint>;\n  static T ti() { return {0, 0};\
    \ }\n  static T op(const T &l, const T &r) { return {l.val + r.val, l.sz + r.sz};\
    \ }\n  static bool mapping(T &v, const E &f) {\n    return v.val = f.first * v.val\
    \ + f.second * v.sz, true;\n  }\n  static void composition(E &pre, const E &suf)\
    \ {\n    pre = {pre.first * suf.first, suf.first * pre.second + suf.second};\n\
    \  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n  SegmentTree_Beats<RaffineQ_RsumQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    int l, r;\n    cin >> op >> l >>\
    \ r;\n    if (op) {\n      cout << seg.fold(l, r).val << endl;\n    } else {\n\
    \      Mint b, c;\n      cin >> b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree_Beats.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  requiredBy: []
  timestamp: '2022-12-10 17:29:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp.html
title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
---
