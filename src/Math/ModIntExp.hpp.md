---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_e.test.cpp
    title: test/atcoder/abc228_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt"
    links:
    - https://trap.jp/post/1444/
  bundledCode: "#line 2 \"src/Math/ModIntExp.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/is_prime.hpp\"\n/**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category\
    \ \u6570\u5B66\n *  O(log N)\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n//\
    \ BEGIN CUT HERE\nconstexpr std::uint16_t bsf(std::uint64_t n) {\n  constexpr\
    \ std::uint8_t convert[64] = {\n      0,  1,  2,  53, 3,  7,  54, 27, 4,  38,\
    \ 41, 8,  34, 55, 48, 28,\n      62, 5,  39, 46, 44, 42, 22, 9,  24, 35, 59, 56,\
    \ 49, 18, 29, 11,\n      63, 52, 6,  26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58,\
    \ 17, 10,\n      51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};\n\
    \  return convert[(n & ~(n - 1)) * 157587932685088877 >> 58];\n}\nconstexpr std::uint64_t\
    \ mul(std::uint64_t x, std::uint64_t y, std::uint64_t m) {\n  return (__uint128_t)x\
    \ * y % m;\n}\ntemplate <std::uint64_t... args>\nconstexpr bool miller_rabin(std::uint64_t\
    \ n) {\n  const std::uint64_t s = bsf(n - 1), d = n >> s;\n  for (auto a : {args...})\
    \ {\n    std::uint64_t b = a % n, p = 1, i = s;\n    for (std::uint64_t k = d,\
    \ x = b;; x = mul(x, x, n))\n      if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1))\
    \ break;\n    while (p != 1 && p != n - 1 && b && i--) p = mul(p, p, n);\n   \
    \ if (p != n - 1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool\
    \ is_prime(std::uint64_t n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) ==\
    \ 3;\n  if (n < UINT_MAX) return miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n#line 4 \"src/Math/Factors.hpp\"\
    \n/**\n * @title \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category\
    \ \u6570\u5B66\n *  O(N^(1/4))\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n\
    // BEGIN CUT HERE\ntemplate <class T>\nconstexpr void bubble_sort(T *bg, T *ed)\
    \ {\n  for (int sz = ed - bg, i = 0; i < sz; i++)\n    for (int j = sz; --j >\
    \ i;)\n      if (auto tmp = bg[j - 1]; bg[j - 1] > bg[j])\n        bg[j - 1] =\
    \ bg[j], bg[j] = tmp;\n}\ntemplate <class T, std::size_t _Nm>\nstruct ConstexprArray\
    \ {\n  constexpr std::size_t size() const { return sz; }\n  constexpr auto &operator[](int\
    \ i) const { return dat[i]; }\n  constexpr auto *begin() const { return dat; }\n\
    \  constexpr auto *end() const { return dat + sz; }\n\n protected:\n  T dat[_Nm]\
    \ = {};\n  std::size_t sz = 0;\n};\nclass Factors\n    : public ConstexprArray<std::pair<std::uint64_t,\
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
    \ 4 \"src/Math/ModIntExp.hpp\"\n/**\n * @title \u6307\u6570\u306B\u4E57\u305B\u3089\
    \u308C\u308BModInt\n * @category \u6570\u5B66\n * @see https://trap.jp/post/1444/\n\
    \ */\n// verify\u7528:\n\n// BEGIN CUT HERE\ntemplate <std::uint64_t MOD>\nclass\
    \ ModIntExp {\n  static_assert(MOD < 1uLL << 63, \"MOD must be smaller than 2^63\"\
    );\n  using Uint = std::conditional_t < MOD<UINT_MAX, std::uint32_t, std::uint64_t>;\n\
    \  using DUint = std::conditional_t<std::is_same_v<Uint, std::uint64_t>,\n   \
    \                                __uint128_t, std::uint64_t>;\n  using mod_t =\
    \ ModIntExp;\n  static constexpr inline Uint mod(DUint x) {\n    return x < MOD\
    \ * 2 ? Uint(x) : Uint(x % MOD) + MOD;\n  }\n  static constexpr inline Uint mul(Uint\
    \ a, Uint b) { return mod(DUint(a) * b); }\n  static constexpr inline Uint pow(Uint\
    \ b, Uint k) {\n    for (Uint ret(1);; b = mul(b, b))\n      if (k & 1 ? ret =\
    \ mul(ret, b) : 0; !(k >>= 1)) return ret;\n  }\n  static constexpr inline std::uint64_t\
    \ f(std::uint64_t x) {\n    std::uint64_t ret = 1, i = 0, tmp = 1;\n    for (const\
    \ auto &[p, e] : Factors(x)) {\n      for (tmp = p - 1, i = e - (p == 2 && e >\
    \ 3); --i;) tmp *= p;\n      ret = std::lcm(ret, tmp);\n    }\n    return ret;\n\
    \  }\n\n public:\n  Uint a;\n  ModIntExp<f(MOD)> b;\n  constexpr ModIntExp() =\
    \ default;\n  constexpr ModIntExp(std::uint64_t x) : a(mod(x)), b(x) {}\n  constexpr\
    \ ModIntExp(Uint a_, ModIntExp<f(MOD)> b_) : a(a_), b(b_) {}\n  constexpr Uint\
    \ val() const { return a < MOD ? a : a - MOD; }\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) {\n    return a = mul(a, r.a), b *= r.b, *this;\n  }\n  constexpr\
    \ mod_t &operator+=(const mod_t &r) {\n    return a -= MOD & -((a += r.a) >= MOD\
    \ * 2), b += r.b, *this;\n  }\n  constexpr mod_t operator*(const mod_t &r) const\
    \ { return mod_t(*this) *= r; }\n  constexpr mod_t operator+(const mod_t &r) const\
    \ { return mod_t(*this) += r; }\n  constexpr mod_t pow(const mod_t &r) const {\n\
    \    return mod_t{pow(a, r.b.a), b.pow(r.b)};\n  };\n};\ntemplate <>\nstruct ModIntExp<1>\
    \ {\n  using mod_t = ModIntExp;\n  bool a;\n  constexpr ModIntExp() : a(0) {}\n\
    \  constexpr ModIntExp(std::uint64_t x) : a(x) {}\n  constexpr std::uint32_t val()\
    \ { return 0; }\n  constexpr mod_t &operator*=(const mod_t &r) { return a &= r.a,\
    \ *this; }\n  constexpr mod_t &operator+=(const mod_t &r) { return a |= r.a, *this;\
    \ }\n  constexpr mod_t operator*(const mod_t &r) const { return mod_t(*this) *=\
    \ r; }\n  constexpr mod_t operator+(const mod_t &r) const { return mod_t(*this)\
    \ += r; }\n  constexpr mod_t pow(const mod_t &r) const { return {a || !r.a}; };\n\
    };\ntemplate <std::uint64_t MOD>\nstd::ostream &operator<<(std::ostream &os, const\
    \ ModIntExp<MOD> &r) {\n  return os << r.val();\n}\ntemplate <std::uint64_t MOD>\n\
    std::istream &operator>>(std::istream &is, ModIntExp<MOD> &r) {\n  std::uint64_t\
    \ v;\n  return is >> v, r = ModIntExp<MOD>(v), is;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/Factors.hpp\"\
    \n/**\n * @title \u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt\n * @category\
    \ \u6570\u5B66\n * @see https://trap.jp/post/1444/\n */\n// verify\u7528:\n\n\
    // BEGIN CUT HERE\ntemplate <std::uint64_t MOD>\nclass ModIntExp {\n  static_assert(MOD\
    \ < 1uLL << 63, \"MOD must be smaller than 2^63\");\n  using Uint = std::conditional_t\
    \ < MOD<UINT_MAX, std::uint32_t, std::uint64_t>;\n  using DUint = std::conditional_t<std::is_same_v<Uint,\
    \ std::uint64_t>,\n                                   __uint128_t, std::uint64_t>;\n\
    \  using mod_t = ModIntExp;\n  static constexpr inline Uint mod(DUint x) {\n \
    \   return x < MOD * 2 ? Uint(x) : Uint(x % MOD) + MOD;\n  }\n  static constexpr\
    \ inline Uint mul(Uint a, Uint b) { return mod(DUint(a) * b); }\n  static constexpr\
    \ inline Uint pow(Uint b, Uint k) {\n    for (Uint ret(1);; b = mul(b, b))\n \
    \     if (k & 1 ? ret = mul(ret, b) : 0; !(k >>= 1)) return ret;\n  }\n  static\
    \ constexpr inline std::uint64_t f(std::uint64_t x) {\n    std::uint64_t ret =\
    \ 1, i = 0, tmp = 1;\n    for (const auto &[p, e] : Factors(x)) {\n      for (tmp\
    \ = p - 1, i = e - (p == 2 && e > 3); --i;) tmp *= p;\n      ret = std::lcm(ret,\
    \ tmp);\n    }\n    return ret;\n  }\n\n public:\n  Uint a;\n  ModIntExp<f(MOD)>\
    \ b;\n  constexpr ModIntExp() = default;\n  constexpr ModIntExp(std::uint64_t\
    \ x) : a(mod(x)), b(x) {}\n  constexpr ModIntExp(Uint a_, ModIntExp<f(MOD)> b_)\
    \ : a(a_), b(b_) {}\n  constexpr Uint val() const { return a < MOD ? a : a - MOD;\
    \ }\n  constexpr mod_t &operator*=(const mod_t &r) {\n    return a = mul(a, r.a),\
    \ b *= r.b, *this;\n  }\n  constexpr mod_t &operator+=(const mod_t &r) {\n   \
    \ return a -= MOD & -((a += r.a) >= MOD * 2), b += r.b, *this;\n  }\n  constexpr\
    \ mod_t operator*(const mod_t &r) const { return mod_t(*this) *= r; }\n  constexpr\
    \ mod_t operator+(const mod_t &r) const { return mod_t(*this) += r; }\n  constexpr\
    \ mod_t pow(const mod_t &r) const {\n    return mod_t{pow(a, r.b.a), b.pow(r.b)};\n\
    \  };\n};\ntemplate <>\nstruct ModIntExp<1> {\n  using mod_t = ModIntExp;\n  bool\
    \ a;\n  constexpr ModIntExp() : a(0) {}\n  constexpr ModIntExp(std::uint64_t x)\
    \ : a(x) {}\n  constexpr std::uint32_t val() { return 0; }\n  constexpr mod_t\
    \ &operator*=(const mod_t &r) { return a &= r.a, *this; }\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { return a |= r.a, *this; }\n  constexpr mod_t operator*(const mod_t\
    \ &r) const { return mod_t(*this) *= r; }\n  constexpr mod_t operator+(const mod_t\
    \ &r) const { return mod_t(*this) += r; }\n  constexpr mod_t pow(const mod_t &r)\
    \ const { return {a || !r.a}; };\n};\ntemplate <std::uint64_t MOD>\nstd::ostream\
    \ &operator<<(std::ostream &os, const ModIntExp<MOD> &r) {\n  return os << r.val();\n\
    }\ntemplate <std::uint64_t MOD>\nstd::istream &operator>>(std::istream &is, ModIntExp<MOD>\
    \ &r) {\n  std::uint64_t v;\n  return is >> v, r = ModIntExp<MOD>(v), is;\n}\n"
  dependsOn:
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: false
  path: src/Math/ModIntExp.hpp
  requiredBy: []
  timestamp: '2022-10-02 18:17:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc228_e.test.cpp
documentation_of: src/Math/ModIntExp.hpp
layout: document
redirect_from:
- /library/src/Math/ModIntExp.hpp
- /library/src/Math/ModIntExp.hpp.html
title: "\u6307\u6570\u306B\u4E57\u305B\u3089\u308C\u308BModInt"
---
