---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':x:'
    path: src/Math/mod_kth_root.hpp
    title: "k\u4E57\u6839 ($\\mathbb{F}_p$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_mod
    links:
    - https://judge.yosupo.jp/problem/kth_root_mod
  bundledCode: "#line 1 \"test/yosupo/kth_root_mod.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/kth_root_mod\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n  Int x = 1, y = 0, b = mod;\n  for (Int\
    \ q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y = z - y * (q = a / b),\
    \ a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x) % mod : x\
    \ % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category\
    \ \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace\
    \ std;\nstruct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct\
    \ run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v\
    \ = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\nconstexpr bool\
    \ is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base, mod_t>;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\nstruct ModIntImpl\
    \ {\n  static constexpr inline auto modulo() { return D::mod; }\n  constexpr D\
    \ operator-() const { return D() -= (D &)*this; }\n  constexpr D &operator/=(const\
    \ D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const D &r)\
    \ const { return D((D &)*this) += r; }\n  constexpr D operator-(const D &r) const\
    \ { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r) const {\
    \ return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const { return\
    \ D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const { return\
    \ !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D ret(1),\
    \ b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>= 1)) return\
    \ ret;\n  }\n  constexpr D inv() const {\n    return mod_inv<typename D::Int>(((D\
    \ *)this)->val(), D::mod);\n  }\n  constexpr D sqrt() const {\n    if (((D *)this)->val()\
    \ <= 1 || D::mod == 2) return *(D *)this;\n    u64 e = (D::mod - 1) >> 1;\n  \
    \  D b = 0, d = -(*this), ret = 1, r2 = 0, b2 = 1;\n    if (this->pow(e) != 1)\
    \ return 0;  // no solution\n    while (d.pow(e) == 1) d += b * 2 + 1, b += 1;\n\
    \    auto mult = [d](D &u1, D &u2, D v1, D v2) {\n      D tmp = u1 * v1 + u2 *\
    \ v2 * d;\n      u2 = u1 * v2 + u2 * v1, u1 = tmp;\n    };\n    for (++e;; mult(b,\
    \ b2, b, b2)) {\n      if (e & 1) mult(ret, r2, b, b2);\n      if (!(e >>= 1))\
    \ return ret.val() <= D::mod / 2 ? ret : -ret;\n    }\n  }\n  constexpr bool operator<(const\
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
    \ auto val() const { return x; }\n  constexpr auto norm() const { return x; }\n\
    \n private:\n  typename B::Uint x = 0;\n};\ntemplate <class B>\nstruct ModInt_Mon\
    \ : public B, public ModIntImpl<ModInt_Mon<B>> {\n  using Int = int64_t;\n  using\
    \ mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n  constexpr ModInt_Mon()\
    \ = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n  template <class T,\n\
    \            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod - ((-n) % B::mod) :\
    \ n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op## = a, x += (B::mod\
    \ << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const mod_t &r) { ASGN(+,\
    \ r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const mod_t &r) { ASGN(-,\
    \ r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const mod_t &r) { return\
    \ x = mul(x, r.x), *this; }\n  constexpr bool operator==(const mod_t &r) const\
    \ { return norm() == r.norm(); }\n  constexpr u64 val() const {\n    u64 ret =\
    \ reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n  }\n  constexpr\
    \ inline u64 norm() const { return x - (B::mod & -(x >= B::mod)); }\n\n private:\n\
    \  static constexpr inline u64 reduce(const u128 &w) {\n    return u64(w >> 64)\
    \ + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n  static constexpr\
    \ inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r); }\n  u64 x = 0;\n\
    };\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n  return e ? mul_inv(n,\
    \ e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na : sta_mint_base\
    \ {\n protected:\n  using Int = conditional_t < MOD < INT_MAX, int32_t,\n    \
    \    conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n  using Uint = conditional_t\
    \ < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX, u64, u128>>;\n\
    \  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct StaticB_Mon\
    \ : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static constexpr\
    \ u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate <class\
    \ I, int id = -1>\nstruct RuntimeB_Na : run_mint_base {\n  static_assert(is_integral_v<I>);\n\
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
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 3 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n// BEGIN CUT HERE\nconstexpr\
    \ std::uint64_t mul(std::uint64_t x, std::uint64_t y, std::uint64_t m) {\n  return\
    \ (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t... args>\nconstexpr bool\
    \ miller_rabin(std::uint64_t n) {\n  const std::uint64_t s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n  for (auto a : {args...}) {\n    std::uint64_t b = a % n,\
    \ p = 1, i = s;\n    for (std::uint64_t k = d, x = b;; x = mul(x, x, n))\n   \
    \   if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1)) break;\n    while (p != 1 &&\
    \ p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i != s) return\
    \ false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t n) {\n\
    \  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX) return\
    \ miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022>(n);\n}\n#line 4 \"src/Math/Factors.hpp\"\n/**\n * @title\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category \u6570\u5B66\
    \n *  O(N^(1/4))\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n// BEGIN CUT HERE\n\
    template <class T>\nconstexpr void bubble_sort(T *bg, T *ed) {\n  for (int sz\
    \ = ed - bg, i = 0; i < sz; i++)\n    for (int j = sz; --j > i;)\n      if (auto\
    \ tmp = bg[j - 1]; bg[j - 1] > bg[j])\n        bg[j - 1] = bg[j], bg[j] = tmp;\n\
    }\ntemplate <class T, std::size_t _Nm>\nstruct ConstexprArray {\n  constexpr std::size_t\
    \ size() const { return sz; }\n  constexpr auto &operator[](int i) const { return\
    \ dat[i]; }\n  constexpr auto *begin() const { return dat; }\n  constexpr auto\
    \ *end() const { return dat + sz; }\n\n protected:\n  T dat[_Nm] = {};\n  std::size_t\
    \ sz = 0;\n};\nclass Factors\n    : public ConstexprArray<std::pair<std::uint64_t,\
    \ std::uint16_t>, 16> {\n  static constexpr std::uint64_t rho(std::uint64_t n,\
    \ std::uint64_t c) {\n    auto f = [n, c](std::uint64_t x) { return ((__uint128_t)x\
    \ * x + c) % n; };\n    std::uint64_t x = 1, y = 2, z = 1, q = 1, g = 1;\n   \
    \ const std::uint64_t m = 1LL << (std::__lg(n) / 5);\n    for (std::uint64_t r\
    \ = 1, i = 0; g == 1; r <<= 1) {\n      for (x = y, i = r; i--;) y = f(y);\n \
    \     for (std::uint64_t k = 0; k < r && g == 1; g = std::gcd(q, n), k += m)\n\
    \        for (z = y, i = std::min(m, r - k); i--;)\n          y = f(y), q = mul(q,\
    \ (x > y ? x - y : y - x), n);\n    }\n    if (g == n) do {\n        z = f(z),\
    \ g = std::gcd((x > z ? x - z : z - x), n);\n      } while (g == 1);\n    return\
    \ g;\n  }\n  static constexpr std::uint64_t find_prime_factor(std::uint64_t n)\
    \ {\n    if (is_prime(n)) return n;\n    for (std::uint64_t i = 100, m = 0; i--;\
    \ n = m)\n      if (m = rho(n, i + 1); is_prime(m)) return m;\n    return 0;\n\
    \  }\n  constexpr void init(std::uint64_t n) {\n    for (std::uint64_t p = 2;\
    \ p < 100 && p * p <= n; p++)\n      if (n % p == 0)\n        for (dat[sz++].first\
    \ = p; n % p == 0;) n /= p, dat[sz - 1].second++;\n    for (std::uint64_t p =\
    \ 0; n > 1; dat[sz++].first = p)\n      for (p = find_prime_factor(n); n % p ==\
    \ 0;) n /= p, dat[sz].second++;\n  }\n\n public:\n  constexpr Factors() = default;\n\
    \  constexpr Factors(std::uint64_t n) { init(n), bubble_sort(dat, dat + sz); }\n\
    };\nconstexpr std::uint64_t totient(const Factors &f) {\n  std::uint64_t ret =\
    \ 1, i = 0;\n  for (const auto &[p, e] : f)\n    for (ret *= p - 1, i = e; --i;)\
    \ ret *= p;\n  return ret;\n}\nconstexpr auto totient(std::uint64_t n) { return\
    \ totient(Factors(n)); }\n\nconstexpr std::uint64_t primitive_root(std::uint64_t\
    \ p) {\n  if (assert(is_prime(p)); p == 2) return 1;\n  auto f = Factors(p - 1);\n\
    \  for (std::uint64_t ret = 2, pw = 0, x = 0, k = 0, ng = 0;; ret++) {\n    for\
    \ (auto [q, e] : f) {\n      for (pw = 1, x = ret, k = (p - 1) / q;; x = mul(x,\
    \ x, p))\n        if (k & 1 ? pw = mul(pw, x, p) : 0; !(k >>= 1)) break;\n   \
    \   if (ng = (pw == 1)) break;\n    }\n    if (!ng) return ret;\n  }\n}\n#line\
    \ 6 \"src/Math/mod_kth_root.hpp\"\n/**\n * @title k\u4E57\u6839 ($\\mathbb{F}_p$)\n\
    \ * @category \u6570\u5B66\n * O( min(k,p)^(1/4) )\n * @see https://nyaannyaan.github.io/library/modulo/mod-kth-root.hpp\n\
    \ */\n\n// verify\u7528\n//  https://yukicoder.me/problems/no/981 (\u5236\u7D04\
    \u304C\u53B3\u3057\u3044, sp judge)\n\n// BEGIN CUT HERE\nnamespace kth_root_internal\
    \ {\ntemplate <class Int, class mod_t>\nmod_t peth_root(mod_t c, Int pi, int ei)\
    \ {\n  const Int p = mod_t::modulo();\n  int t = 0;\n  Int s = p - 1, pe = 1;\n\
    \  while (s % pi == 0) s /= pi, ++t;\n  for (int i = ei; i--;) pe *= pi;\n  Int\
    \ u = inv_mod(pe - s % pe, pe);\n  mod_t ONE = 1, z = c.pow((s * u + 1) / pe),\
    \ zpe = c.pow(s * u);\n  if (zpe == ONE) return z;\n  Int ptm1 = 1;\n  for (int\
    \ i = t; --i;) ptm1 *= pi;\n  mod_t vs, base;\n  for (mod_t v = 2;; v += ONE)\n\
    \    if (vs = v.pow(s), base = vs.pow(ptm1); base != ONE) break;\n  int size =\
    \ 1 << std::__lg(int(std::sqrt(pi)) + 1), mask = size - 1,\n      os[size + 1]\
    \ = {};\n  std::pair<mod_t, int> vec[size];\n  mod_t x = 1, vspe = vs.pow(pe);\n\
    \  for (int i = 0; i < size; ++i, x *= base) os[x.norm() & mask]++;\n  for (int\
    \ i = 1; i < size; ++i) os[i] += os[i - 1];\n  x = 1, os[size] = size;\n  for\
    \ (int i = 0; i < size; ++i, x *= base) vec[--os[x.norm() & mask]] = {x, i};\n\
    \  for (int vs_e = ei, td; zpe != ONE;) {\n    mod_t tmp = zpe, base_zpe = mod_t(1)\
    \ / zpe;\n    for (td = 0; tmp != ONE; td++) tmp = tmp.pow(pi);\n    for (int\
    \ e = t - td; vs_e != e; vs_e++)\n      vs = vs.pow(pi), vspe = vspe.pow(pi);\n\
    \    for (int i = td; --i;) base_zpe = base_zpe.pow(pi);\n    for (int tt = 0,\
    \ upd = 1, n; upd; tt += size, base_zpe *= x)\n      for (int m = (base_zpe.norm()\
    \ & mask), i = os[m]; i < os[m + 1]; i++)\n        if (base_zpe == vec[i].first)\
    \ {\n          if (n = vec[i].second - tt; n < 0) n += pi;\n          z *= vs.pow(n),\
    \ zpe *= vspe.pow(n), upd = false;\n          break;\n        }\n  }\n  return\
    \ z;\n}\ntemplate <class Int, class mod_t>\nInt inner_kth_root(Int a, std::uint64_t\
    \ k, Int p) {\n  if (k == 0) return a == 1 ? a : -1;\n  if (a <= 1 || k <= 1)\
    \ return a;\n  mod_t::set_mod(p);\n  Int g = std::gcd(k, p - 1);\n  mod_t ma =\
    \ a;\n  Int pp = (p - 1) / g, kk = (k / g) % pp;\n  if (ma.pow(pp) != mod_t(1))\
    \ return -1;\n  ma = ma.pow(inv_mod(kk, pp));\n  for (auto [pi, ei] : Factors(g))\
    \ ma = peth_root<Int>(ma, pi, ei);\n  return ma.val();\n}\nstd::int64_t mod_kth_root(std::int64_t\
    \ a, std::uint64_t k, std::int64_t p) {\n  if (a %= p; p < INT_MAX)\n    return\
    \ inner_kth_root<int, RuntimeModInt<int, -2>>(a, k, p);\n  else\n    return inner_kth_root<std::int64_t,\
    \ RuntimeModInt<Montgomery, -2>>(a, k, p);\n}\n}  // namespace kth_root_internal\n\
    using kth_root_internal::mod_kth_root;\n#line 4 \"test/yosupo/kth_root_mod.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int T;\n  cin >> T;\n  while (T--) {\n    int K, Y, P;\n    cin >> K >> Y >>\
    \ P;\n    cout << mod_kth_root(Y, K, P) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/mod_kth_root.hpp\"\nusing namespace std;\n\
    \nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int T;\n  cin\
    \ >> T;\n  while (T--) {\n    int K, Y, P;\n    cin >> K >> Y >> P;\n    cout\
    \ << mod_kth_root(Y, K, P) << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/mod_kth_root.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/kth_root_mod.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 01:24:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/kth_root_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_root_mod.test.cpp
- /verify/test/yosupo/kth_root_mod.test.cpp.html
title: test/yosupo/kth_root_mod.test.cpp
---
