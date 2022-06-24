---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/factorize.hpp\"\n/**\n * @title\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069\n * @category \u6570\u5B66\
    \n *  O(N^(1/4))\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n// BEGIN CUT HERE\n\
    \n#ifndef MATH_TEMP\n#define MATH_TEMP\nconstexpr std::uint16_t bsf(std::uint64_t\
    \ n) {\n  constexpr std::uint8_t convert[64] = {\n      0,  1,  2,  53, 3,  7,\
    \  54, 27, 4,  38, 41, 8,  34, 55, 48, 28,\n      62, 5,  39, 46, 44, 42, 22,\
    \ 9,  24, 35, 59, 56, 49, 18, 29, 11,\n      63, 52, 6,  26, 37, 40, 33, 47, 61,\
    \ 45, 43, 21, 23, 58, 17, 10,\n      51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19,\
    \ 15, 30, 14, 13, 12};\n  return convert[(n & ~(n - 1)) * 157587932685088877 >>\
    \ 58];\n}\nconstexpr std::uint64_t mul(std::uint64_t x, std::uint64_t y, std::uint64_t\
    \ m) {\n  return (__uint128_t)x * y % m;\n}\nconstexpr std::uint64_t pow(std::uint64_t\
    \ x, std::uint64_t k, std::uint64_t m) {\n  for (std::uint64_t ret = 1;; x = mul(x,\
    \ x, m))\n    if (k & 1 ? ret = mul(ret, x, m) : 0; !(k >>= 1)) return ret;\n\
    }\ntemplate <std::uint64_t... args>\nconstexpr bool miller_rabin(std::uint64_t\
    \ n) {\n  const std::uint64_t s = bsf(n - 1), d = n >> s;\n  for (auto a : {args...})\
    \ {\n    std::uint64_t b = a % n, p = pow(b, d, n), i = s;\n    while (p != 1\
    \ && p != n - 1 && b && i--) p = mul(p, p, n);\n    if (p != n - 1 && i != s)\
    \ return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(std::uint64_t\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<2, 7, 61>(n);\n  return miller_rabin<2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022>(n);\n}\ntemplate <class T>\nconstexpr void bubble_sort(T\
    \ *bg, T *ed) {\n  for (int sz = ed - bg, i = 0; i < sz; i++)\n    for (int j\
    \ = sz; --j > i;)\n      if (auto tmp = bg[j - 1]; bg[j - 1] > bg[j])\n      \
    \  bg[j - 1] = bg[j], bg[j] = tmp;\n}\n\ntemplate <class T, std::size_t _Nm>\n\
    struct ConstexprArray {\n  constexpr std::size_t size() const { return _sz; }\n\
    \  constexpr auto &operator[](int i) const { return dat[i]; }\n  constexpr auto\
    \ *begin() const { return dat; }\n  constexpr auto *end() const { return dat +\
    \ _sz; }\n\n protected:\n  T dat[_Nm] = {};\n  std::size_t _sz = 0;\n};\nclass\
    \ Factors\n    : public ConstexprArray<std::pair<std::uint64_t, std::uint16_t>,\
    \ 16> {\n  static constexpr std::uint64_t rho(std::uint64_t n, std::uint64_t c)\
    \ {\n    auto f = [n, c](std::uint64_t x) { return ((__uint128_t)x * x + c) %\
    \ n; };\n    std::uint64_t x = 1, y = 2, z = 1, q = 1, g = 1;\n    const std::uint64_t\
    \ m = 1LL << (std::__lg(n) / 5);\n    for (std::uint64_t r = 1, i = 0; g == 1;\
    \ r <<= 1) {\n      for (x = y, i = r; i--;) y = f(y);\n      for (std::uint64_t\
    \ k = 0; k < r && g == 1; g = std::gcd(q, n), k += m)\n        for (z = y, i =\
    \ std::min(m, r - k); i--;)\n          y = f(y), q = mul(q, (x > y ? x - y : y\
    \ - x), n);\n    }\n    if (g == n) do {\n        z = f(z), g = std::gcd((x >\
    \ z ? x - z : z - x), n);\n      } while (g == 1);\n    return g;\n  }\n  static\
    \ constexpr std::uint64_t find_prime_factor(std::uint64_t n) {\n    if (is_prime(n))\
    \ return n;\n    for (std::uint64_t i = 100, m = 0; i--; n = m)\n      if (m =\
    \ rho(n, i + 1); is_prime(m)) return m;\n    return 0;\n  }\n  constexpr void\
    \ init(std::uint64_t n) {\n    for (std::uint64_t p = 2; p < 100 && p * p <= n;\
    \ p++)\n      if (n % p == 0) {\n        for (; n % p == 0;) n /= p, dat[_sz].second++;\n\
    \        dat[_sz++].first = p;\n      }\n    for (std::uint64_t p = 0; n > 1;\
    \ dat[_sz++].first = p)\n      for (p = find_prime_factor(n); n % p == 0;) n /=\
    \ p, dat[_sz].second++;\n    bubble_sort(dat, dat + _sz);\n  }\n\n public:\n \
    \ constexpr Factors() = default;\n  constexpr Factors(std::uint64_t n) { init(n);\
    \ }\n};\nconstexpr std::uint64_t totient(const Factors &f) {\n  std::uint64_t\
    \ ret = 1, i = 0;\n  for (const auto &[p, e] : f)\n    for (ret *= p - 1, i =\
    \ e; --i;) ret *= p;\n  return ret;\n}\nconstexpr auto totient(std::uint64_t n)\
    \ { return totient(Factors(n)); }\nconstexpr std::uint64_t carmichael(const Factors\
    \ &f) {\n  std::uint64_t ret = 1, i = 0, tmp = 1;\n  for (const auto &[p, e] :\
    \ f) {\n    for (tmp = p - 1, i = e - (p == 2 && e > 2); --i;) tmp *= p;\n   \
    \ ret = std::lcm(ret, tmp);\n  }\n  return ret;\n}\nconstexpr auto carmichael(std::uint64_t\
    \ n) { return carmichael(Factors(n)); }\n#endif\n#line 4 \"test/yosupo/factorize.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int Q;\n  cin >> Q;\n  while (Q--) {\n    long long a;\n    cin >> a;\n   \
    \ vector<long long> ans;\n    for (auto& [p, e] : Factors(a)) {\n      for (int\
    \ i = 0; i < e; i++) ans.push_back(p);\n    }\n    cout << ans.size();\n    for\
    \ (auto x : ans) cout << \" \" << x;\n    cout << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <bits/stdc++.h>\n\
    #include \"src/Math/factorize.hpp\"\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int Q;\n  cin >> Q;\n  while (Q--)\
    \ {\n    long long a;\n    cin >> a;\n    vector<long long> ans;\n    for (auto&\
    \ [p, e] : Factors(a)) {\n      for (int i = 0; i < e; i++) ans.push_back(p);\n\
    \    }\n    cout << ans.size();\n    for (auto x : ans) cout << \" \" << x;\n\
    \    cout << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/factorize.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-06-24 14:27:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---
