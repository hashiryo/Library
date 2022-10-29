---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n#include <bits/stdc++.h>\n\
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
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
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
    #line 3 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n *\
    \ @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1]\
    \ * a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  if\
    \ (n == 0) return {};\n  std::vector<K> c(n), b(n), tmp;\n  K x = 1, y, coef;\n\
    \  const K Z = 0;\n  for (c[0] = b[0] = 1, i = 0, j; i < n; ++i) {\n    for (++m,\
    \ y = a[i], j = 1; j <= d; ++j) y += c[j] * a[i - j];\n    if (y == Z) continue;\n\
    \    for (tmp = c, coef = y / x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n\
    \    if (2 * d > i) continue;\n    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n\
    \  c.resize(d + 1), c.erase(c.begin());\n  for (auto &x : c) x = -x;\n  return\
    \ c;\n}\n#line 5 \"test/yosupo/find_linear_recurrence.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using\
    \ Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << '\\n';\n  for (int i = 0; i < d; i++) cout\
    \ << c[i] << \" \\n\"[i == d - 1];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/berlekamp_massey.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint>\
    \ a(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << '\\n';\n  for (int i = 0; i < d; i++) cout\
    \ << c[i] << \" \\n\"[i == d - 1];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: true
  path: test/yosupo/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2022-10-29 19:15:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---
