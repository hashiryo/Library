---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_1_small_p_large_n.test.cpp
    title: test/yosupo/stirling_1_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_2_small_p_large_n.test.cpp
    title: test/yosupo/stirling_2_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)"
    links:
    - https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97
  bundledCode: "#line 2 \"src/Math/StirlingNumber.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ 450775, 9780504, 1795265022>(n);\n}\n#line 4 \"src/Math/StirlingNumber.hpp\"\
    \n/**\n * @title \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)\n\
    \ * @category \u6570\u5B66\n * @see\n * https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97\n\
    \ * \u524D\u51E6\u7406 O(p^2), \u30AF\u30A8\u30EA O(log n)\n */\n\n// BEGIN CUT\
    \ HERE\nclass StirlingNumber {\n  const std::uint16_t p;\n  std::vector<std::vector<std::uint16_t>>\
    \ c, s1, s2;\n  void buildS1() {\n    s1.resize(p), s1[0] = {1};\n    for (int\
    \ i = 1, j, t; i < p; s1[i][i] = 1, i++)\n      for (s1[i].resize(i + 1, 0), j\
    \ = 1, t = p - i + 1; j < i; j++)\n        s1[i][j] = (t * s1[i - 1][j] + s1[i\
    \ - 1][j - 1]) % p;\n  }\n  void buildS2() {\n    s2.resize(p), s2[0] = {1};\n\
    \    for (int i = 1, j; i < p; s2[i][i] = 1, i++)\n      for (s2[i].resize(i +\
    \ 1, 0), j = 1; j < i; j++)\n        s2[i][j] = (j * s2[i - 1][j] + s2[i - 1][j\
    \ - 1]) % p;\n  }\n\n public:\n  StirlingNumber(std::uint32_t p_, bool first =\
    \ true, bool second = true)\n      : p(p_), c(p) {\n    assert(is_prime(p_)),\
    \ assert(p_ < (1 << 15)), c[0] = {1};\n    for (int i = 1, j; i < p; i++)\n  \
    \    for (c[i] = c[i - 1], c[i].emplace_back(0), j = 1; j <= i; j++)\n       \
    \ c[i][j] -= p & -((c[i][j] += c[i - 1][j - 1]) >= p);\n    if (first) buildS1();\n\
    \    if (second) buildS2();\n  }\n  int nCk(std::uint64_t n, std::uint64_t k)\
    \ {\n    if (k > n) return 0;\n    int ret = 1, i, j;\n    for (k = std::min(k,\
    \ n - k); k; ret = ret * c[i][j] % p, n /= p, k /= p)\n      if (i = n % p, j\
    \ = k % p; j > i) return 0;\n    return ret;\n  }\n  int S1(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    std::uint64_t i = n / p;\n    if (i > k)\
    \ return 0;\n    std::int64_t a = (k - i) / (p - 1);\n    std::uint16_t j = n\
    \ % p, b = (k - i) % (p - 1);\n    if (!b && j) b += (p - 1), a -= 1;\n    if\
    \ (a < 0 || i < a || b > j) return 0;\n    return (j = nCk(i, a) * s1[j][b] %\
    \ p) && ((i + a) & 1) ? p - j : j;\n  }\n  int S2(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    if (!n) return 1;\n    std::uint64_t i =\
    \ k / p;\n    if (n <= i) return 0;\n    std::uint64_t a = (n - i - 1) / (p -\
    \ 1);\n    std::uint16_t j = k % p, b = (n - i) - a * (p - 1);\n    if (j > b)\
    \ return 0;\n    return b == p - 1 && !j ? nCk(a, i - 1) : nCk(a, i) * s2[b][j]\
    \ % p;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/is_prime.hpp\"\
    \n/**\n * @title \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)\n\
    \ * @category \u6570\u5B66\n * @see\n * https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97\n\
    \ * \u524D\u51E6\u7406 O(p^2), \u30AF\u30A8\u30EA O(log n)\n */\n\n// BEGIN CUT\
    \ HERE\nclass StirlingNumber {\n  const std::uint16_t p;\n  std::vector<std::vector<std::uint16_t>>\
    \ c, s1, s2;\n  void buildS1() {\n    s1.resize(p), s1[0] = {1};\n    for (int\
    \ i = 1, j, t; i < p; s1[i][i] = 1, i++)\n      for (s1[i].resize(i + 1, 0), j\
    \ = 1, t = p - i + 1; j < i; j++)\n        s1[i][j] = (t * s1[i - 1][j] + s1[i\
    \ - 1][j - 1]) % p;\n  }\n  void buildS2() {\n    s2.resize(p), s2[0] = {1};\n\
    \    for (int i = 1, j; i < p; s2[i][i] = 1, i++)\n      for (s2[i].resize(i +\
    \ 1, 0), j = 1; j < i; j++)\n        s2[i][j] = (j * s2[i - 1][j] + s2[i - 1][j\
    \ - 1]) % p;\n  }\n\n public:\n  StirlingNumber(std::uint32_t p_, bool first =\
    \ true, bool second = true)\n      : p(p_), c(p) {\n    assert(is_prime(p_)),\
    \ assert(p_ < (1 << 15)), c[0] = {1};\n    for (int i = 1, j; i < p; i++)\n  \
    \    for (c[i] = c[i - 1], c[i].emplace_back(0), j = 1; j <= i; j++)\n       \
    \ c[i][j] -= p & -((c[i][j] += c[i - 1][j - 1]) >= p);\n    if (first) buildS1();\n\
    \    if (second) buildS2();\n  }\n  int nCk(std::uint64_t n, std::uint64_t k)\
    \ {\n    if (k > n) return 0;\n    int ret = 1, i, j;\n    for (k = std::min(k,\
    \ n - k); k; ret = ret * c[i][j] % p, n /= p, k /= p)\n      if (i = n % p, j\
    \ = k % p; j > i) return 0;\n    return ret;\n  }\n  int S1(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    std::uint64_t i = n / p;\n    if (i > k)\
    \ return 0;\n    std::int64_t a = (k - i) / (p - 1);\n    std::uint16_t j = n\
    \ % p, b = (k - i) % (p - 1);\n    if (!b && j) b += (p - 1), a -= 1;\n    if\
    \ (a < 0 || i < a || b > j) return 0;\n    return (j = nCk(i, a) * s1[j][b] %\
    \ p) && ((i + a) & 1) ? p - j : j;\n  }\n  int S2(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    if (!n) return 1;\n    std::uint64_t i =\
    \ k / p;\n    if (n <= i) return 0;\n    std::uint64_t a = (n - i - 1) / (p -\
    \ 1);\n    std::uint16_t j = k % p, b = (n - i) - a * (p - 1);\n    if (j > b)\
    \ return 0;\n    return b == p - 1 && !j ? nCk(a, i - 1) : nCk(a, i) * s2[b][j]\
    \ % p;\n  }\n};"
  dependsOn:
  - src/Math/is_prime.hpp
  isVerificationFile: false
  path: src/Math/StirlingNumber.hpp
  requiredBy: []
  timestamp: '2022-10-16 17:42:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_1_small_p_large_n.test.cpp
  - test/yosupo/stirling_2_small_p_large_n.test.cpp
documentation_of: src/Math/StirlingNumber.hpp
layout: document
redirect_from:
- /library/src/Math/StirlingNumber.hpp
- /library/src/Math/StirlingNumber.hpp.html
title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)"
---
