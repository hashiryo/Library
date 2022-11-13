---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial_coefficient.test.cpp
    title: test/yosupo/binomial_coefficient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
    links:
    - https://ferin-tech.hatenablog.com/entry/2018/01/17/010829
  bundledCode: "#line 2 \"src/Math/BinomialCoefficient.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/is_prime.hpp\"\n/**\n * @title \u7D20\u6570\u5224\u5B9A\n *\
    \ @category \u6570\u5B66\n *  O(log N)\n * constexpr \u3067\u547C\u3079\u308B\n\
    \ */\n\n// BEGIN CUT HERE\nconstexpr std::uint64_t mul(std::uint64_t x, std::uint64_t\
    \ y, std::uint64_t m) {\n  return (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t...\
    \ args>\nconstexpr bool miller_rabin(std::uint64_t n) {\n  const std::uint64_t\
    \ s = __builtin_ctzll(n - 1), d = n >> s;\n  for (auto a : {args...}) {\n    std::uint64_t\
    \ b = a % n, p = 1, i = s;\n    for (std::uint64_t k = d, x = b;; x = mul(x, x,\
    \ n))\n      if (k& 1 ? p = mul(p, x, n) : 0; !(k >>= 1)) break;\n    while (p\
    \ != 1 && p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i !=\
    \ s) return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022>(n);\n}\n#line 4 \"src/Math/Factors.hpp\"\n/**\n\
    \ * @title \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category\
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
    \ 4 \"src/Math/BinomialCoefficient.hpp\"\n/**\n * @title \u4E8C\u9805\u4FC2\u6570\
    \ ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n * @see https://ferin-tech.hatenablog.com/entry/2018/01/17/010829\n\
    \ */\n\n// BEGIN CUT HERE\nclass BinomialCoefficient {  // mod <= 1e6\n  static\
    \ inline constexpr int inv_mod(int a, int mod) {\n    int x = 1, y = 0, b = mod;\n\
    \    for (int q = 0, z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y *\
    \ (q = a / b), a = b, b = c - b * q;\n    return assert(a == 1), x < 0 ? mod -\
    \ (-x) % mod : x % mod;\n  }\n  using i64 = std::int64_t;\n  struct ModPe {\n\
    \    ModPe() = default;\n    ModPe(int p, int e, std::size_t pre_size = 1 << 14)\n\
    \        : p(p), e(e), ppows(e + 1, 1) {\n      for (int i = 1; i <= e; ++i) ppows[i]\
    \ = ppows[i - 1] * p;\n      for (pp = pe = ppows[e]; std::size_t(pp) * p <= pre_size;)\
    \ pp *= p;\n      q = pp / pe * p, facts.resize(pp, 1);\n      for (int qq = 1,\
    \ l = pp / p; qq < q; qq *= p, l /= p)\n        for (int i = 0; i < l; ++i)\n\
    \          for (int j = i * p + 1; j < i * p + p; ++j) facts[j * qq] = j;\n  \
    \    for (int i = 1; i < pp; ++i) facts[i] = i64(facts[i - 1]) * facts[i] % pe;\n\
    \      mask = (facts[pp - 1] == pe - 1), ds.resize(q, 0);\n      for (int i =\
    \ 0; i < pp / pe; ++i)\n        for (int j = 0, s = ds[i]; j < p; ++j) ds[i *\
    \ p + j] = s + j;\n    }\n    int operator()(i64 n, i64 m) const {\n      int\
    \ num = 1, den = 1, x = 0, s = 0;\n      if (i64 r = n - m; e > 1)\n        for\
    \ (i64 n1, m1, r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1\
    \ = m / pp, r1 = r / pp;\n          num = i64(num) * facts[n - n1 * pp] % pp;\n\
    \          den = i64(den) * facts[m - m1 * pp] % pp * facts[r - r1 * pp] % pp;\n\
    \          s += n1 - m1 - r1, n1 = n / q, m1 = m / q, r1 = r / q;\n          x\
    \ += ds[m - m1 * q] + ds[r - r1 * q] - ds[n - n1 * q];\n        }\n      else\n\
    \        for (i64 n1, m1, r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 =\
    \ n / pp, m1 = m / pp, r1 = r / pp;\n          int nr = n - n1 * pp, mr = m -\
    \ m1 * pp, rr = r - r1 * pp;\n          num = i64(num) * facts[nr] % pp;\n   \
    \       den = i64(den) * facts[mr] % pp * facts[rr] % pp;\n          s += n1 -\
    \ m1 - r1, x += ds[mr] + ds[rr] - ds[nr];\n        }\n      if (x >= e * (p -\
    \ 1)) return 0;\n      if (p > 2) x /= p - 1;\n      int ret = i64(num) * inv_mod(den,\
    \ pe) % pe * ppows[x] % pe;\n      return (s & mask) && ret > 0 ? pe - ret : ret;\n\
    \    }\n    int p, e, mask, pe, q, pp;\n    std::vector<int> ppows, facts, ds;\n\
    \  };\n  int mod;\n  std::vector<ModPe> binom_pp;\n  std::vector<int> iprods;\n\
    \n public:\n  BinomialCoefficient(int mod, std::size_t pre_size = 1 << 14) : mod(mod)\
    \ {\n    Factors f(mod);\n    if (f.size() == 1) pre_size = 1 << 20;\n    int\
    \ prod = 1;\n    for (auto [p, e] : f) {\n      binom_pp.emplace_back(ModPe(p,\
    \ e, pre_size));\n      iprods.push_back(inv_mod(prod, binom_pp.back().pe));\n\
    \      prod *= binom_pp.back().pe;\n    }\n  }\n  inline int nCr(i64 n, i64 r)\
    \ const {\n    assert(r >= 0);\n    if (n < r) return 0;\n    if (r == 0) return\
    \ (mod > 1);\n    int ret = 0, prod = 1;\n    for (size_t i = 0, d, ed = binom_pp.size();\
    \ i < ed; ++i, prod *= d)\n      d = binom_pp[i].pe,\n      ret += i64(binom_pp[i](n,\
    \ r) + d - ret % d) * iprods[i] % d * prod;\n    return ret;\n  }\n  inline int\
    \ nHr(i64 n, i64 r) const { return !r ? 1 : nCr(n + r - 1, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/Factors.hpp\"\
    \n/**\n * @title \u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category\
    \ \u6570\u5B66\n * @see https://ferin-tech.hatenablog.com/entry/2018/01/17/010829\n\
    \ */\n\n// BEGIN CUT HERE\nclass BinomialCoefficient {  // mod <= 1e6\n  static\
    \ inline constexpr int inv_mod(int a, int mod) {\n    int x = 1, y = 0, b = mod;\n\
    \    for (int q = 0, z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y *\
    \ (q = a / b), a = b, b = c - b * q;\n    return assert(a == 1), x < 0 ? mod -\
    \ (-x) % mod : x % mod;\n  }\n  using i64 = std::int64_t;\n  struct ModPe {\n\
    \    ModPe() = default;\n    ModPe(int p, int e, std::size_t pre_size = 1 << 14)\n\
    \        : p(p), e(e), ppows(e + 1, 1) {\n      for (int i = 1; i <= e; ++i) ppows[i]\
    \ = ppows[i - 1] * p;\n      for (pp = pe = ppows[e]; std::size_t(pp) * p <= pre_size;)\
    \ pp *= p;\n      q = pp / pe * p, facts.resize(pp, 1);\n      for (int qq = 1,\
    \ l = pp / p; qq < q; qq *= p, l /= p)\n        for (int i = 0; i < l; ++i)\n\
    \          for (int j = i * p + 1; j < i * p + p; ++j) facts[j * qq] = j;\n  \
    \    for (int i = 1; i < pp; ++i) facts[i] = i64(facts[i - 1]) * facts[i] % pe;\n\
    \      mask = (facts[pp - 1] == pe - 1), ds.resize(q, 0);\n      for (int i =\
    \ 0; i < pp / pe; ++i)\n        for (int j = 0, s = ds[i]; j < p; ++j) ds[i *\
    \ p + j] = s + j;\n    }\n    int operator()(i64 n, i64 m) const {\n      int\
    \ num = 1, den = 1, x = 0, s = 0;\n      if (i64 r = n - m; e > 1)\n        for\
    \ (i64 n1, m1, r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 = n / pp, m1\
    \ = m / pp, r1 = r / pp;\n          num = i64(num) * facts[n - n1 * pp] % pp;\n\
    \          den = i64(den) * facts[m - m1 * pp] % pp * facts[r - r1 * pp] % pp;\n\
    \          s += n1 - m1 - r1, n1 = n / q, m1 = m / q, r1 = r / q;\n          x\
    \ += ds[m - m1 * q] + ds[r - r1 * q] - ds[n - n1 * q];\n        }\n      else\n\
    \        for (i64 n1, m1, r1; n > 0; n = n1, m = m1, r = r1) {\n          n1 =\
    \ n / pp, m1 = m / pp, r1 = r / pp;\n          int nr = n - n1 * pp, mr = m -\
    \ m1 * pp, rr = r - r1 * pp;\n          num = i64(num) * facts[nr] % pp;\n   \
    \       den = i64(den) * facts[mr] % pp * facts[rr] % pp;\n          s += n1 -\
    \ m1 - r1, x += ds[mr] + ds[rr] - ds[nr];\n        }\n      if (x >= e * (p -\
    \ 1)) return 0;\n      if (p > 2) x /= p - 1;\n      int ret = i64(num) * inv_mod(den,\
    \ pe) % pe * ppows[x] % pe;\n      return (s & mask) && ret > 0 ? pe - ret : ret;\n\
    \    }\n    int p, e, mask, pe, q, pp;\n    std::vector<int> ppows, facts, ds;\n\
    \  };\n  int mod;\n  std::vector<ModPe> binom_pp;\n  std::vector<int> iprods;\n\
    \n public:\n  BinomialCoefficient(int mod, std::size_t pre_size = 1 << 14) : mod(mod)\
    \ {\n    Factors f(mod);\n    if (f.size() == 1) pre_size = 1 << 20;\n    int\
    \ prod = 1;\n    for (auto [p, e] : f) {\n      binom_pp.emplace_back(ModPe(p,\
    \ e, pre_size));\n      iprods.push_back(inv_mod(prod, binom_pp.back().pe));\n\
    \      prod *= binom_pp.back().pe;\n    }\n  }\n  inline int nCr(i64 n, i64 r)\
    \ const {\n    assert(r >= 0);\n    if (n < r) return 0;\n    if (r == 0) return\
    \ (mod > 1);\n    int ret = 0, prod = 1;\n    for (size_t i = 0, d, ed = binom_pp.size();\
    \ i < ed; ++i, prod *= d)\n      d = binom_pp[i].pe,\n      ret += i64(binom_pp[i](n,\
    \ r) + d - ret % d) * iprods[i] % d * prod;\n    return ret;\n  }\n  inline int\
    \ nHr(i64 n, i64 r) const { return !r ? 1 : nCr(n + r - 1, r); }\n};"
  dependsOn:
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: false
  path: src/Math/BinomialCoefficient.hpp
  requiredBy: []
  timestamp: '2022-11-13 14:36:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/binomial_coefficient.test.cpp
documentation_of: src/Math/BinomialCoefficient.hpp
layout: document
redirect_from:
- /library/src/Math/BinomialCoefficient.hpp
- /library/src/Math/BinomialCoefficient.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
