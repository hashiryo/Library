---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':x:'
    path: src/Math/tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3 $a\\upuparrows b$ ($\\mathbb{Z}/m\\\
      mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
  bundledCode: "#line 1 \"test/yosupo/tetration_mod.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tetration_mod\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/is_prime.hpp\"\n/**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category\
    \ \u6570\u5B66\n *  O(log N)\n * constexpr \u3067\u547C\u3079\u308B\n */\n\n//\
    \ BEGIN CUT HERE\nconstexpr std::uint64_t mul(std::uint64_t x, std::uint64_t y,\
    \ std::uint64_t m) {\n  return (__uint128_t)x * y % m;\n}\ntemplate <std::uint64_t...\
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
    \ 4 \"src/Math/tetration.hpp\"\n/**\n * @title \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\
    \u30F3 $a\\upuparrows b$ ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\
    \n *  O(m^(1/4))\n */\n// verify\u7528:\n// https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f\n\
    \n// BEGIN CUT HERE\nnamespace tetration_internal {\nconstexpr std::uint64_t rec(std::uint64_t\
    \ a, std::uint64_t b, std::uint64_t m) {\n  if (a == 0) return (b ^ 1) & 1;\n\
    \  if (b == 0 || m == 1) return 1;\n  std::uint64_t ret = 1, k = 1, tmp = 1, i\
    \ = 0;\n  for (const auto &[p, e] : Factors(m)) {\n    for (tmp = p - 1, i = e\
    \ - (p == 2 && e > 3); --i;) tmp *= p;\n    k = std::lcm(k, tmp);\n  }\n  auto\
    \ mod = [m](__uint128_t x) { return x < m ? x : x % m + m; };\n  for (k = rec(a,\
    \ b - 1, k), a = mod(a);; a = mod(__uint128_t(a) * a))\n    if (k & 1 ? ret =\
    \ mod(__uint128_t(ret) * a) : 0; !(k >>= 1)) return ret;\n}\n}  // namespace tetration_internal\n\
    constexpr std::uint64_t H4(std::uint64_t a, std::uint64_t b, std::uint64_t m)\
    \ {\n  return (a = tetration_internal::rec(a, b, m)) >= m ? a - m : a;\n}\n#line\
    \ 4 \"test/yosupo/tetration_mod.test.cpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin >> T;\n  while\
    \ (T--) {\n    int A, B, M;\n    cin >> A >> B >> M;\n    cout << H4(A, B, M)\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/tetration.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin\
    \ >> T;\n  while (T--) {\n    int A, B, M;\n    cin >> A >> B >> M;\n    cout\
    \ << H4(A, B, M) << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/tetration.hpp
  - src/Math/Factors.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/tetration_mod.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 01:24:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tetration_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tetration_mod.test.cpp
- /verify/test/yosupo/tetration_mod.test.cpp.html
title: test/yosupo/tetration_mod.test.cpp
---
