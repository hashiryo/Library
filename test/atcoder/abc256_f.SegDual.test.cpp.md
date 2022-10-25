---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
  bundledCode: "#line 1 \"test/atcoder/abc256_f.SegDual.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace std;\n\
    struct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct dyn_mint_base\
    \ : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
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
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const D &r) { return os << r.val(); }\n  friend istream &operator>>(istream\
    \ &is, D &r) {\n    long long v;\n    return is >> v, r = D(v), is;\n  }\n};\n\
    template <class B>\nstruct ModInt_Na : public B, public ModIntImpl<ModInt_Na<B>>\
    \ {\n  using Int = typename B::Int;\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, uint32_t>, u64, u128>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n  template <class\
    \ T>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod) : n % B::mod)\
    \ {}\n#define ASSIGN(m, p) return x m## = B::mod & -((x p## = r.x) >= B::mod),\
    \ *this\n  constexpr ModInt_Na &operator+=(const ModInt_Na &r) { ASSIGN(-, +);\
    \ }\n  constexpr ModInt_Na &operator-=(const ModInt_Na &r) { ASSIGN(+, -); }\n\
    #undef ASSIGN\n  constexpr ModInt_Na &operator*=(const ModInt_Na &r) {\n    return\
    \ x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr bool operator==(const\
    \ ModInt_Na &r) const { return x == r.x; }\n  constexpr auto val() const { return\
    \ x; }\n\n private:\n  typename B::Uint x = 0;\n};\ntemplate <class B>\nstruct\
    \ ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>> {\n  using Int = int64_t;\n\
    \  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n  constexpr\
    \ ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n  template\
    \ <class T>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod - ((-n)\
    \ % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op## = a, x\
    \ += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const mod_t\
    \ &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const mod_t\
    \ &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const mod_t\
    \ &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const mod_t\
    \ &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const {\n  \
    \  u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    #line 3 \"src/DataStructure/SegmentTree_Dual.hpp\"\n/**\n * @title Segment-Tree(\u53CC\
    \u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree_Dual {\n  using\
    \ T = typename M::T;\n  using E = typename M::E;\n  SegmentTree_Dual() {}\n  SegmentTree_Dual(int\
    \ n_, T v1 = T())\n      : n(n_), height(ceil(log2(n))), val(n, v1), laz(n * 2,\
    \ {E(), false}) {}\n  SegmentTree_Dual(const std::vector<T> &v)\n      : n(v.size()),\
    \ height(ceil(log2(n))), val(v), laz(n * 2, {E(), false}) {}\n  void apply(int\
    \ a, int b, E x) {\n    a += n, b += n;\n    for (int i = height; i >= 1; i--)\n\
    \      if (((a >> i) << i) != a) eval(a >> i);\n    for (int i = height; i >=\
    \ 1; i--)\n      if (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l\
    \ = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n\
    \      if (r & 1) propagate(--r, x);\n    }\n  }\n  void set(int k, T x) {\n \
    \   for (int i = height; i; i--) eval((k + n) >> i);\n    val[k] = x, laz[k +\
    \ n].flg = false;\n  }\n  T operator[](const int k) {\n    for (int i = height;\
    \ i; i--) eval((k + n) >> i);\n    if (laz[k + n].flg)\n      M::mapping(val[k],\
    \ laz[k + n].val), laz[k + n].flg = false;\n    return val[k];\n  }\n\n private:\n\
    \  const int n, height;\n  struct Lazy {\n    E val;\n    bool flg;\n  };\n  std::vector<T>\
    \ val;\n  std::vector<Lazy> laz;\n  inline void eval(int k) {\n    if (!laz[k].flg)\
    \ return;\n    propagate(k << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n\
    \    laz[k].flg = false;\n  }\n  inline void propagate(int k, const E &x) {\n\
    \    laz[k].flg ? (M::composition(laz[k].val, x), x) : laz[k].val = x;\n    laz[k].flg\
    \ = true;\n  }\n};\n#line 6 \"test/atcoder/abc256_f.SegDual.test.cpp\"\nusing\
    \ namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n  struct\
    \ T {\n    Mint val, coef[2];\n    T() = default;\n    T(Mint id, Mint v)\n  \
    \      : val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n  };\n  using\
    \ E = array<Mint, 3>;\n  static void mapping(T &x, const E &mapp) {\n    x.val\
    \ += mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n  }\n  static void\
    \ composition(E &pre, const E &suf) {\n    pre[0] += suf[0], pre[1] += suf[1],\
    \ pre[2] += suf[2];\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n  for (int i = 0; i < N; i++)\
    \ cin >> A[i], D[i] = A[i];\n  for (int j = 0; j < 3; j++)\n    for (int i = 1;\
    \ i < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dual<Mono> seg(N);\n  for (int\
    \ i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n    int op, x;\n\
    \    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n      cin >> v,\
    \ v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x * x / 2});\n \
    \   } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nusing Mint = StaticModInt<998244353>;\nstruct Mono {\n\
    \  struct T {\n    Mint val, coef[2];\n    T() = default;\n    T(Mint id, Mint\
    \ v)\n        : val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n \
    \ };\n  using E = array<Mint, 3>;\n  static void mapping(T &x, const E &mapp)\
    \ {\n    x.val += mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2];\n  }\n\
    \  static void composition(E &pre, const E &suf) {\n    pre[0] += suf[0], pre[1]\
    \ += suf[1], pre[2] += suf[2];\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  Mint A[N], D[N];\n  for (int i = 0; i < N; i++)\
    \ cin >> A[i], D[i] = A[i];\n  for (int j = 0; j < 3; j++)\n    for (int i = 1;\
    \ i < N; i++) D[i] += D[i - 1];\n  SegmentTree_Dual<Mono> seg(N);\n  for (int\
    \ i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--) {\n    int op, x;\n\
    \    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint v;\n      cin >> v,\
    \ v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x, v * x * x / 2});\n \
    \   } else {\n      cout << seg[x].val << '\\n';\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.SegDual.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 18:49:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.SegDual.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.SegDual.test.cpp
- /verify/test/atcoder/abc256_f.SegDual.test.cpp.html
title: test/atcoder/abc256_f.SegDual.test.cpp
---
