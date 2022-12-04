---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/binomial_coefficient.test.cpp
    title: test/yosupo/binomial_coefficient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
    links:
    - https://ferin-tech.hatenablog.com/entry/2018/01/17/010829
  bundledCode: "#line 2 \"src/Math/BinomialCoefficient.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n * @title ModInt\u306E\u30D7\u30ED\
    \u30C8\u30BF\u30A4\u30D7\n * @category \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\
    \u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\nusing\
    \ namespace std;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\n\
    struct MIntPro_Montg {\n  const u64 mod;\n  constexpr MIntPro_Montg() : mod(0),\
    \ iv(0), r2(0) {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod)\
    \ % mod) {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l)\
    \ * r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n\n private:\n  const u64 iv, r2;\n  constexpr u64 inv(u64\
    \ n, int e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2 - x * n)) :\
    \ x;\n  }\n  constexpr inline u64 reduce(const u128 &w) const {\n    return u64(w\
    \ >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n};\ntemplate <class\
    \ Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint, u32>,\
    \ u64, u128>;\n\n public:\n  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return\
    \ n; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static constexpr\
    \ inline Uint norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t>\n\
    constexpr Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 4 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate <class Uint,\
    \ class mod_pro_t, u64... args>\nconstexpr bool miller_rabin(Uint n) {\n  const\
    \ mod_pro_t md(n);\n  const Uint s = __builtin_ctzll(n - 1), d = n >> s, one =\
    \ md.set(1),\n             n1 = md.norm(md.set(n - 1));\n  for (auto a : {args...})\
    \ {\n    Uint b = a % n, p = pow(md.set(b), d, md), i = s;\n    while (p = md.norm(p),\
    \ (p != one && p != n1 && b && i--)) p = md.mul(p, p);\n    if (md.norm(p) !=\
    \ n1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(u64\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<u32, MIntPro_Na<u32>, 2, 7, 61>(n);\n  if (n < LLONG_MAX)\n\
    \    return miller_rabin<u64, MIntPro_Montg, 2, 325, 9375, 28178, 450775,\n  \
    \                      9780504, 1795265022>(n);\n  return miller_rabin<u64, MIntPro_Na<u64>,\
    \ 2, 325, 9375, 28178, 450775,\n                      9780504, 1795265022>(n);\n\
    }\n}  // namespace math_internal\nusing math_internal::is_prime;\n#line 4 \"src/Math/Factors.hpp\"\
    \n/**\n * @title \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category\
    \ \u6570\u5B66\n *  O(N^(1/4))\n */\n\n// BEGIN CUT HERE\nnamespace math_internal\
    \ {\ntemplate <class T>\nconstexpr void bubble_sort(T *bg, T *ed) {\n  for (int\
    \ sz = ed - bg, i = 0; i < sz; i++)\n    for (int j = sz; --j > i;)\n      if\
    \ (auto tmp = bg[j - 1]; bg[j - 1] > bg[j])\n        bg[j - 1] = bg[j], bg[j]\
    \ = tmp;\n}\ntemplate <class T, size_t _Nm>\nstruct ConstexprArray {\n  constexpr\
    \ size_t size() const { return sz; }\n  constexpr auto &operator[](int i) const\
    \ { return dat[i]; }\n  constexpr auto *begin() const { return dat; }\n  constexpr\
    \ auto *end() const { return dat + sz; }\n\n protected:\n  T dat[_Nm] = {};\n\
    \  size_t sz = 0;\n};\nclass Factors : public ConstexprArray<pair<u64, uint16_t>,\
    \ 16> {\n  template <class Uint, class mod_pro_t>\n  static constexpr Uint rho(Uint\
    \ n, Uint c) {\n    const mod_pro_t md(n);\n    auto f = [&md, n, c](Uint x) {\
    \ return md.plus(md.mul(x, x), c); };\n    const Uint m = 1LL << (__lg(n) / 5);\n\
    \    Uint x = 1, y = md.set(2), z = 1, q = md.set(1), g = 1;\n    for (Uint r\
    \ = 1, i = 0; g == 1; r <<= 1) {\n      for (x = y, i = r; i--;) y = f(y);\n \
    \     for (Uint k = 0; k < r && g == 1; g = gcd(md.get(q), n), k += m)\n     \
    \   for (z = y, i = min(m, r - k); i--;)\n          y = f(y), q = md.mul(q, md.diff(y,\
    \ x));\n    }\n    if (g == n) do {\n        z = f(z), g = gcd(md.get(md.diff(z,\
    \ x)), n);\n      } while (g == 1);\n    return g;\n  }\n  static constexpr u64\
    \ find_prime_factor(u64 n) {\n    if (is_prime(n)) return n;\n    for (u64 i =\
    \ 100; i--;)\n      if (n = n < UINT_MAX    ? rho<u32, MIntPro_Na<u32>>(n, i +\
    \ 1)\n              : n < LLONG_MAX ? rho<u64, MIntPro_Montg>(n, i + 1)\n    \
    \                          : rho<u64, MIntPro_Na<u64>>(n, i + 1);\n          is_prime(n))\n\
    \        return n;\n    return 0;\n  }\n  constexpr void init(u64 n) {\n    for\
    \ (u64 p = 2; p < 100 && p * p <= n; p++)\n      if (n % p == 0)\n        for\
    \ (dat[sz++].first = p; n % p == 0;) n /= p, dat[sz - 1].second++;\n    for (u64\
    \ p = 0; n > 1; dat[sz++].first = p)\n      for (p = find_prime_factor(n); n %\
    \ p == 0;) n /= p, dat[sz].second++;\n  }\n\n public:\n  constexpr Factors() =\
    \ default;\n  constexpr Factors(u64 n) { init(n), bubble_sort(dat, dat + sz);\
    \ }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr Uint inner_primitive_root(Uint\
    \ p) {\n  const mod_pro_t md(p);\n  const auto f = Factors(p - 1);\n  for (Uint\
    \ ret = 2, one = md.set(1), ng = 0;; ret++) {\n    for (auto [q, e] : f)\n   \
    \   if (ng = (md.norm(pow(md.set(ret), (p - 1) / q, md)) == one)) break;\n   \
    \ if (!ng) return ret;\n  }\n}\nconstexpr u64 primitive_root(u64 p) {\n  if (assert(is_prime(p));\
    \ p == 2) return 1;\n  if (p < UINT_MAX) return inner_primitive_root<u32, MIntPro_Na<u32>>(p);\n\
    \  if (p < LLONG_MAX) return inner_primitive_root<u64, MIntPro_Montg>(p);\n  return\
    \ inner_primitive_root<u64, MIntPro_Na<u64>>(p);\n}\n}  // namespace math_internal\n\
    using math_internal::Factors, math_internal::primitive_root;\nconstexpr std::uint64_t\
    \ totient(const Factors &f) {\n  std::uint64_t ret = 1, i = 0;\n  for (const auto\
    \ &[p, e] : f)\n    for (ret *= p - 1, i = e; --i;) ret *= p;\n  return ret;\n\
    }\nconstexpr auto totient(std::uint64_t n) { return totient(Factors(n)); }\n#line\
    \ 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 5 \"src/Math/BinomialCoefficient.hpp\"\
    \n/**\n * @title \u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category\
    \ \u6570\u5B66\n * @see https://ferin-tech.hatenablog.com/entry/2018/01/17/010829\n\
    \ */\n\n// BEGIN CUT HERE\nclass BinomialCoefficient {  // mod <= 1e6\n  using\
    \ i64 = std::int64_t;\n  struct ModPe {\n    ModPe() = default;\n    ModPe(int\
    \ p, int e, std::size_t pre_size = 1 << 14)\n        : p(p), e(e), ppows(e + 1,\
    \ 1) {\n      for (int i = 1; i <= e; ++i) ppows[i] = ppows[i - 1] * p;\n    \
    \  for (pp = pe = ppows[e]; std::size_t(pp) * p <= pre_size;) pp *= p;\n     \
    \ q = pp / pe * p, facts.resize(pp, 1);\n      for (int qq = 1, l = pp / p; qq\
    \ < q; qq *= p, l /= p)\n        for (int i = 0; i < l; ++i)\n          for (int\
    \ j = i * p + 1; j < i * p + p; ++j) facts[j * qq] = j;\n      for (int i = 1;\
    \ i < pp; ++i) facts[i] = i64(facts[i - 1]) * facts[i] % pe;\n      mask = (facts[pp\
    \ - 1] == pe - 1), ds.resize(q, 0);\n      for (int i = 0; i < pp / pe; ++i)\n\
    \        for (int j = 0, s = ds[i]; j < p; ++j) ds[i * p + j] = s + j;\n    }\n\
    \    int operator()(i64 n, i64 m) const {\n      int num = 1, den = 1, x = 0,\
    \ s = 0;\n      if (i64 r = n - m; e > 1)\n        for (i64 n1, m1, r1; n > 0;\
    \ n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1 = m / pp, r1 = r / pp;\n\
    \          num = i64(num) * facts[n - n1 * pp] % pp;\n          den = i64(den)\
    \ * facts[m - m1 * pp] % pp * facts[r - r1 * pp] % pp;\n          s += n1 - m1\
    \ - r1, n1 = n / q, m1 = m / q, r1 = r / q;\n          x += ds[m - m1 * q] + ds[r\
    \ - r1 * q] - ds[n - n1 * q];\n        }\n      else\n        for (i64 n1, m1,\
    \ r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1 = m / pp, r1\
    \ = r / pp;\n          int nr = n - n1 * pp, mr = m - m1 * pp, rr = r - r1 * pp;\n\
    \          num = i64(num) * facts[nr] % pp;\n          den = i64(den) * facts[mr]\
    \ % pp * facts[rr] % pp;\n          s += n1 - m1 - r1, x += ds[mr] + ds[rr] -\
    \ ds[nr];\n        }\n      if (x >= e * (p - 1)) return 0;\n      if (p > 2)\
    \ x /= p - 1;\n      int ret = i64(num) * mod_inv(den, pe) % pe * ppows[x] % pe;\n\
    \      return (s & mask) && ret > 0 ? pe - ret : ret;\n    }\n    int p, e, mask,\
    \ pe, q, pp;\n    std::vector<int> ppows, facts, ds;\n  };\n  int mod;\n  std::vector<ModPe>\
    \ binom_pp;\n  std::vector<int> iprods;\n\n public:\n  BinomialCoefficient(int\
    \ mod, std::size_t pre_size = 1 << 14) : mod(mod) {\n    Factors f(mod);\n   \
    \ if (f.size() == 1) pre_size = 1 << 20;\n    int prod = 1;\n    for (auto [p,\
    \ e] : f) {\n      binom_pp.emplace_back(ModPe(p, e, pre_size));\n      iprods.push_back(mod_inv(prod,\
    \ binom_pp.back().pe));\n      prod *= binom_pp.back().pe;\n    }\n  }\n  inline\
    \ int nCr(i64 n, i64 r) const {\n    assert(r >= 0);\n    if (n < r) return 0;\n\
    \    if (r == 0) return (mod > 1);\n    int ret = 0, prod = 1;\n    for (size_t\
    \ i = 0, d, ed = binom_pp.size(); i < ed; ++i, prod *= d)\n      d = binom_pp[i].pe,\n\
    \      ret += i64(binom_pp[i](n, r) + d - ret % d) * iprods[i] % d * prod;\n \
    \   return ret;\n  }\n  inline int nHr(i64 n, i64 r) const { return !r ? 1 : nCr(n\
    \ + r - 1, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/Factors.hpp\"\
    \n#include \"src/Math/mod_inv.hpp\"\n/**\n * @title \u4E8C\u9805\u4FC2\u6570 ($\\\
    mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n * @see https://ferin-tech.hatenablog.com/entry/2018/01/17/010829\n\
    \ */\n\n// BEGIN CUT HERE\nclass BinomialCoefficient {  // mod <= 1e6\n  using\
    \ i64 = std::int64_t;\n  struct ModPe {\n    ModPe() = default;\n    ModPe(int\
    \ p, int e, std::size_t pre_size = 1 << 14)\n        : p(p), e(e), ppows(e + 1,\
    \ 1) {\n      for (int i = 1; i <= e; ++i) ppows[i] = ppows[i - 1] * p;\n    \
    \  for (pp = pe = ppows[e]; std::size_t(pp) * p <= pre_size;) pp *= p;\n     \
    \ q = pp / pe * p, facts.resize(pp, 1);\n      for (int qq = 1, l = pp / p; qq\
    \ < q; qq *= p, l /= p)\n        for (int i = 0; i < l; ++i)\n          for (int\
    \ j = i * p + 1; j < i * p + p; ++j) facts[j * qq] = j;\n      for (int i = 1;\
    \ i < pp; ++i) facts[i] = i64(facts[i - 1]) * facts[i] % pe;\n      mask = (facts[pp\
    \ - 1] == pe - 1), ds.resize(q, 0);\n      for (int i = 0; i < pp / pe; ++i)\n\
    \        for (int j = 0, s = ds[i]; j < p; ++j) ds[i * p + j] = s + j;\n    }\n\
    \    int operator()(i64 n, i64 m) const {\n      int num = 1, den = 1, x = 0,\
    \ s = 0;\n      if (i64 r = n - m; e > 1)\n        for (i64 n1, m1, r1; n > 0;\
    \ n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1 = m / pp, r1 = r / pp;\n\
    \          num = i64(num) * facts[n - n1 * pp] % pp;\n          den = i64(den)\
    \ * facts[m - m1 * pp] % pp * facts[r - r1 * pp] % pp;\n          s += n1 - m1\
    \ - r1, n1 = n / q, m1 = m / q, r1 = r / q;\n          x += ds[m - m1 * q] + ds[r\
    \ - r1 * q] - ds[n - n1 * q];\n        }\n      else\n        for (i64 n1, m1,\
    \ r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1 = m / pp, r1\
    \ = r / pp;\n          int nr = n - n1 * pp, mr = m - m1 * pp, rr = r - r1 * pp;\n\
    \          num = i64(num) * facts[nr] % pp;\n          den = i64(den) * facts[mr]\
    \ % pp * facts[rr] % pp;\n          s += n1 - m1 - r1, x += ds[mr] + ds[rr] -\
    \ ds[nr];\n        }\n      if (x >= e * (p - 1)) return 0;\n      if (p > 2)\
    \ x /= p - 1;\n      int ret = i64(num) * mod_inv(den, pe) % pe * ppows[x] % pe;\n\
    \      return (s & mask) && ret > 0 ? pe - ret : ret;\n    }\n    int p, e, mask,\
    \ pe, q, pp;\n    std::vector<int> ppows, facts, ds;\n  };\n  int mod;\n  std::vector<ModPe>\
    \ binom_pp;\n  std::vector<int> iprods;\n\n public:\n  BinomialCoefficient(int\
    \ mod, std::size_t pre_size = 1 << 14) : mod(mod) {\n    Factors f(mod);\n   \
    \ if (f.size() == 1) pre_size = 1 << 20;\n    int prod = 1;\n    for (auto [p,\
    \ e] : f) {\n      binom_pp.emplace_back(ModPe(p, e, pre_size));\n      iprods.push_back(mod_inv(prod,\
    \ binom_pp.back().pe));\n      prod *= binom_pp.back().pe;\n    }\n  }\n  inline\
    \ int nCr(i64 n, i64 r) const {\n    assert(r >= 0);\n    if (n < r) return 0;\n\
    \    if (r == 0) return (mod > 1);\n    int ret = 0, prod = 1;\n    for (size_t\
    \ i = 0, d, ed = binom_pp.size(); i < ed; ++i, prod *= d)\n      d = binom_pp[i].pe,\n\
    \      ret += i64(binom_pp[i](n, r) + d - ret % d) * iprods[i] % d * prod;\n \
    \   return ret;\n  }\n  inline int nHr(i64 n, i64 r) const { return !r ? 1 : nCr(n\
    \ + r - 1, r); }\n};"
  dependsOn:
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: false
  path: src/Math/BinomialCoefficient.hpp
  requiredBy: []
  timestamp: '2022-12-04 16:01:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/binomial_coefficient.test.cpp
documentation_of: src/Math/BinomialCoefficient.hpp
layout: document
redirect_from:
- /library/src/Math/BinomialCoefficient.hpp
- /library/src/Math/BinomialCoefficient.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
