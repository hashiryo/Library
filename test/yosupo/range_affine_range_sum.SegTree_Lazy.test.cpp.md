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
    \ mod) {\n  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n\
    \    z = x, c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return\
    \ assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    namespace modint_internal {\nusing namespace std;\nstruct modint_base {};\nstruct\
    \ sta_mint_base : modint_base {};\nstruct run_mint_base : modint_base {};\ntemplate\
    \ <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base, mod_t>;\n\
    template <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    return mod_inv<typename\
    \ D::Int>(((D *)this)->val(), D::mod);\n  }\n  constexpr D sqrt() const {\n  \
    \  if (((D *)this)->val() <= 1 || D::mod == 2) return *(D *)this;\n    u64 e =\
    \ (D::mod - 1) >> 1;\n    D b = 0, d = -(*this), ret = 1, r2 = 0, b2 = 1;\n  \
    \  if (this->pow(e) != 1) return 0;  // no solution\n    while (d.pow(e) == 1)\
    \ d += b * 2 + 1, b += 1;\n    auto mult = [d](D &u1, D &u2, D v1, D v2) {\n \
    \     D tmp = u1 * v1 + u2 * v2 * d;\n      u2 = u1 * v2 + u2 * v1, u1 = tmp;\n\
    \    };\n    for (++e;; mult(b, b2, b, b2)) {\n      if (e & 1) mult(ret, r2,\
    \ b, b2);\n      if (!(e >>= 1)) return ret.val() <= D::mod / 2 ? ret : -ret;\n\
    \    }\n  }\n  constexpr bool operator<(const D &r) const {\n    return ((D *)this)->val()\
    \ < r.val();\n  }  // for set or map\n  friend ostream &operator<<(ostream &os,\
    \ const D &r) { return os << r.val(); }\n  friend istream &operator>>(istream\
    \ &is, D &r) {\n    long long v;\n    return is >> v, r = D(v), is;\n  }\n};\n\
    template <class B>\nstruct ModInt_Na : public B, public ModIntImpl<ModInt_Na<B>>\
    \ {\n  using Int = typename B::Int;\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, uint32_t>, u64, u128>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod) : n % B::mod)\
    \ {}\n#define ASSIGN(m, p) return x m## = B::mod & -((x p## = r.x) >= B::mod),\
    \ *this\n  constexpr ModInt_Na &operator+=(const ModInt_Na &r) { ASSIGN(-, +);\
    \ }\n  constexpr ModInt_Na &operator-=(const ModInt_Na &r) { ASSIGN(+, -); }\n\
    #undef ASSIGN\n  constexpr ModInt_Na &operator*=(const ModInt_Na &r) {\n    return\
    \ x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr bool operator==(const\
    \ ModInt_Na &r) const { return x == r.x; }\n  constexpr auto val() const { return\
    \ x; }\n  constexpr auto norm() const { return x; }\n\n private:\n  typename B::Uint\
    \ x = 0;\n};\ntemplate <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Int = int64_t;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    \  template <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op##\
    \ = a, x += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const\
    \ mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const\
    \ mod_t &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const\
    \ {\n    u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n  constexpr inline u64 norm() const { return x - (B::mod & -(x >= B::mod));\
    \ }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n    return\
    \ u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n  static\
    \ constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r); }\n  u64\
    \ x = 0;\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n  return e\
    \ ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na\
    \ : sta_mint_base {\n protected:\n  using Int = conditional_t < MOD < INT_MAX,\
    \ int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n  using\
    \ Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct RuntimeB_Na : run_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct RuntimeB_Mon : run_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<RuntimeB_Mon<id>>,\n\
    \                  ModInt_Na<RuntimeB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::RuntimeModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_runtimemodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 6 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
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
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 01:24:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp.html
title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
---
