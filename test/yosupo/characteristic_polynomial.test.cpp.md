---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/LinearAlgebra/characteristic_polynomial.hpp
    title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F"
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
    PROBLEM: https://judge.yosupo.jp/problem/characteristic_polynomial
    links:
    - https://judge.yosupo.jp/problem/characteristic_polynomial
  bundledCode: "#line 1 \"test/yosupo/characteristic_polynomial.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\n\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\
    \n/**\n * @title \u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F\n * @category\
    \ \u7DDA\u5F62\u4EE3\u6570\n * O(N^3)\n */\n\n// BEGIN CUT HERE\n\ntemplate <class\
    \ K>\nstd::vector<std::vector<K>> hessenberg(const std::vector<std::vector<K>>\
    \ &a) {\n  std::size_t n = a.size();\n  auto ret = a;\n  for (std::size_t j =\
    \ 0; j + 2 < n; ++j) {\n    for (std::size_t i = j + 1; i < n; ++i)\n      if\
    \ (ret[i][j] != 0) {\n        std::swap(ret[j + 1], ret[i]);\n        for (std::size_t\
    \ r = 0; r < n; ++r) std::swap(ret[r][j + 1], ret[r][i]);\n        break;\n  \
    \    }\n    if (ret[j + 1][j] != 0)\n      for (std::size_t i = j + 2; i < n;\
    \ ++i) {\n        auto m = ret[i][j] / ret[j + 1][j];\n        for (std::size_t\
    \ c = j; c < n; ++c) ret[i][c] -= m * ret[j + 1][c];\n        for (std::size_t\
    \ r = 0; r < n; ++r) ret[r][j + 1] += m * ret[r][i];\n      }\n  }\n  return ret;\n\
    }\n\ntemplate <class K>\nstd::vector<K> characteristic_polynomial(const std::vector<std::vector<K>>\
    \ &a) {\n  std::size_t n = a.size();\n  auto b = hessenberg(a);\n  for (std::size_t\
    \ i = 0; i < n; i++)\n    for (std::size_t j = 0; j < n; j++) b[i][j] = -b[i][j];\n\
    \  std::vector<std::vector<K>> fss(n + 1);\n  fss[0] = {1};\n  for (std::size_t\
    \ i = 0; i < n; ++i) {\n    fss[i + 1].assign(i + 2, 0);\n    for (std::size_t\
    \ k = 0; k <= i; ++k) fss[i + 1][k + 1] = fss[i][k];\n    for (std::size_t k =\
    \ 0; k <= i; ++k) fss[i + 1][k] += b[i][i] * fss[i][k];\n    K prod = 1;\n   \
    \ for (std::size_t j = i; j--;) {\n      prod *= -b[j + 1][j];\n      const K\
    \ s = prod * b[j][i];\n      for (std::size_t k = 0; k <= j; ++k) fss[i + 1][k]\
    \ += s * fss[j][k];\n    }\n  }\n  return fss.back();\n}\n#line 3 \"src/Math/mod_inv.hpp\"\
    \n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0,\
    \ b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y =\
    \ z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ?\
    \ mod - (-x) % mod : x % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\n/**\n * @title\
    \ ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal\
    \ {\nusing namespace std;\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
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
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 6 \"test/yosupo/characteristic_polynomial.test.cpp\"\
    \n\nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ a(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> a[i][j];\n  auto p = characteristic_polynomial(a);\n  for (int\
    \ i = 0; i <= N; i++) cout << (i ? \" \" : \"\") << p[i];\n  cout << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\
    \n\n#include <bits/stdc++.h>\n#include \"src/LinearAlgebra/characteristic_polynomial.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\n\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  vector<vector<Mint>> a(N, vector<Mint>(N));\n  for (int\
    \ i = 0; i < N; i++)\n    for (int j = 0; j < N; j++) cin >> a[i][j];\n  auto\
    \ p = characteristic_polynomial(a);\n  for (int i = 0; i <= N; i++) cout << (i\
    \ ? \" \" : \"\") << p[i];\n  cout << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/LinearAlgebra/characteristic_polynomial.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: true
  path: test/yosupo/characteristic_polynomial.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 09:47:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/characteristic_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/characteristic_polynomial.test.cpp
- /verify/test/yosupo/characteristic_polynomial.test.cpp.html
title: test/yosupo/characteristic_polynomial.test.cpp
---
