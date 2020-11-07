---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':x:'
    path: test/yukicoder/644.test.cpp
    title: test/yukicoder/644.test.cpp
  - icon: ':x:'
    path: test/yukicoder/886.numth.test.cpp
    title: test/yukicoder/886.numth.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6570\u8AD6"
    links:
    - https://atcoder.jp/contests/agc038/tasks/agc038_c
    - https://en.wikipedia.org/wiki/Dirichlet_convolution
    - https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
  bundledCode: "#line 2 \"src/Math/number_theory.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6570\u8AD6\n * @category \u6570\u5B66\n *  \u7D04\u6570\u3084\
    \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3084\
    \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n *  \u3092\u3082\u3068\u306B\u6570\u8AD6\
    \u7684\u95A2\u6570\u3084gcd\u7573\u307F\u8FBC\u307F\u306A\u3069\u3092\u5B9F\u73FE\
    \n *  O(N log log N)\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n */\n\n// verify\u7528\
    :\n// https://atcoder.jp/contests/agc038/tasks/agc038_c\n\n// BEGIN CUT HERE\n\
    \nnamespace number_theory {\nstd::vector<int> primes;\nconst int MAX_N = 1 <<\
    \ 24;\nint mpf[MAX_N];  // minimum prime factor\nvoid init(int n) {\n  primes.push_back(2);\n\
    \  for (int i = 2; i <= n; i += 2) mpf[i] = 2;\n  for (long long p = 3; p <= n;\
    \ p += 2)\n    if (!mpf[p]) {\n      mpf[p] = p;\n      primes.push_back(p);\n\
    \      for (long long i = p * p; i <= n; i += 2 * p)\n        if (!mpf[i]) mpf[i]\
    \ = p;\n    }\n}\n\nstd::vector<pair<int, int>> prime_factorize(int n) {  // O(log\
    \ n)\n  std::vector<pair<int, int>> res;\n  while (n > 1) {\n    int p = mpf[n];\n\
    \    int e = 0;\n    while (mpf[n] == p) e++, n /= p;\n    res.push_back(make_pair(p,\
    \ e));\n  }\n  return res;\n}\n\n// f -> g s.t. g(n) = sum_{m|n} f(m)\ntemplate\
    \ <typename T>\nvoid divisor_zeta(std::vector<T> &f) {\n  int n = f.size();\n\
    \  if (!primes.size()) init(n);\n  for (int p : primes) {\n    if (p > n) break;\n\
    \    for (int i = 1; p * i < n; i++) f[p * i] += f[i];\n  }\n}\n// f -> h s.t.\
    \ f(n) = sum_{m|n} h(m)\ntemplate <typename T>\nvoid divisor_mobius(std::vector<T>\
    \ &f) {\n  int n = f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes)\
    \ {\n    if (p > n) break;\n    for (int i = (n - 1) / p; i > 0; i--) f[p * i]\
    \ -= f[i];\n  }\n}\n// get table of Mobius function\ntemplate <typename T = int>\n\
    std::vector<T> get_mu(int n) {\n  std::vector<T> f(n + 1, T(0));\n  f[1] = T(1);\n\
    \  divisor_mobius(f);\n  return f;\n}\n// get table of Euler's totient function\n\
    template <typename T = int>\nstd::vector<T> get_phi(int n) {\n  std::vector<T>\
    \ f(n + 1);\n  std::iota(f.begin(), f.end(), 0);\n  divisor_mobius(f);\n  return\
    \ f;\n}\n// get table of number-of-divisors function\ntemplate <typename T = int>\n\
    std::vector<T> get_d(int n) {\n  std::vector<T> f(n + 1, 1);\n  divisor_zeta(f);\n\
    \  return f;\n}\n// get table of sum-of-divisors function\ntemplate <typename\
    \ T = int>\nstd::vector<T> get_sigma(int n) {\n  std::vector<T> f(n + 1);\n  std::iota(f.begin(),\
    \ f.end(), 0);\n  divisor_zeta(f);\n  return f;\n}\ntemplate <typename T>\nstatic\
    \ std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {\n  int\
    \ n = max(a.size(), b.size());\n  a.resize(n);\n  b.resize(n);\n  divisor_zeta(a);\n\
    \  divisor_zeta(b);\n  for (int i = 0; i < n; i++) a[i] *= b[i];\n  divisor_mobius(a);\n\
    \  return a;\n}\n// f -> g s.t. g(n) = sum_{n|m} f(m)\ntemplate <typename T>\n\
    static void multiple_zeta(std::vector<T> &f) {\n  int n = f.size();\n  if (!primes.size())\
    \ init(n);\n  for (int p : primes) {\n    if (p > n) break;\n    for (int i =\
    \ (n - 1) / p; i > 0; i--) f[i] += f[p * i];\n  }\n}\n// f -> h s.t. f(n) = sum_{n|m}\
    \ h(m)\ntemplate <typename T>\nstatic void multiple_mobius(std::vector<T> &f)\
    \ {\n  int n = f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes)\
    \ {\n    if (p > n) break;\n    for (int i = 1; p * i < n; i++) f[i] -= f[p *\
    \ i];\n  }\n}\ntemplate <typename T>\nstatic std::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n  int n = std::max(a.size(), b.size());\n  a.resize(n);\n\
    \  b.resize(n);\n  multiple_zeta(a);\n  multiple_zeta(b);\n  for (int i = 0; i\
    \ < n; i++) a[i] *= b[i];\n  multiple_mobius(a);\n  return a;\n}\n}  // namespace\
    \ number_theory\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6570\u8AD6\n * @category\
    \ \u6570\u5B66\n *  \u7D04\u6570\u3084\u500D\u6570\u306B\u3064\u3044\u3066\u306E\
    \u30BC\u30FC\u30BF\u5909\u63DB\u3084\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n * \
    \ \u3092\u3082\u3068\u306B\u6570\u8AD6\u7684\u95A2\u6570\u3084gcd\u7573\u307F\u8FBC\
    \u307F\u306A\u3069\u3092\u5B9F\u73FE\n *  O(N log log N)\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n */\n\n// verify\u7528\
    :\n// https://atcoder.jp/contests/agc038/tasks/agc038_c\n\n// BEGIN CUT HERE\n\
    \nnamespace number_theory {\nstd::vector<int> primes;\nconst int MAX_N = 1 <<\
    \ 24;\nint mpf[MAX_N];  // minimum prime factor\nvoid init(int n) {\n  primes.push_back(2);\n\
    \  for (int i = 2; i <= n; i += 2) mpf[i] = 2;\n  for (long long p = 3; p <= n;\
    \ p += 2)\n    if (!mpf[p]) {\n      mpf[p] = p;\n      primes.push_back(p);\n\
    \      for (long long i = p * p; i <= n; i += 2 * p)\n        if (!mpf[i]) mpf[i]\
    \ = p;\n    }\n}\n\nstd::vector<pair<int, int>> prime_factorize(int n) {  // O(log\
    \ n)\n  std::vector<pair<int, int>> res;\n  while (n > 1) {\n    int p = mpf[n];\n\
    \    int e = 0;\n    while (mpf[n] == p) e++, n /= p;\n    res.push_back(make_pair(p,\
    \ e));\n  }\n  return res;\n}\n\n// f -> g s.t. g(n) = sum_{m|n} f(m)\ntemplate\
    \ <typename T>\nvoid divisor_zeta(std::vector<T> &f) {\n  int n = f.size();\n\
    \  if (!primes.size()) init(n);\n  for (int p : primes) {\n    if (p > n) break;\n\
    \    for (int i = 1; p * i < n; i++) f[p * i] += f[i];\n  }\n}\n// f -> h s.t.\
    \ f(n) = sum_{m|n} h(m)\ntemplate <typename T>\nvoid divisor_mobius(std::vector<T>\
    \ &f) {\n  int n = f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes)\
    \ {\n    if (p > n) break;\n    for (int i = (n - 1) / p; i > 0; i--) f[p * i]\
    \ -= f[i];\n  }\n}\n// get table of Mobius function\ntemplate <typename T = int>\n\
    std::vector<T> get_mu(int n) {\n  std::vector<T> f(n + 1, T(0));\n  f[1] = T(1);\n\
    \  divisor_mobius(f);\n  return f;\n}\n// get table of Euler's totient function\n\
    template <typename T = int>\nstd::vector<T> get_phi(int n) {\n  std::vector<T>\
    \ f(n + 1);\n  std::iota(f.begin(), f.end(), 0);\n  divisor_mobius(f);\n  return\
    \ f;\n}\n// get table of number-of-divisors function\ntemplate <typename T = int>\n\
    std::vector<T> get_d(int n) {\n  std::vector<T> f(n + 1, 1);\n  divisor_zeta(f);\n\
    \  return f;\n}\n// get table of sum-of-divisors function\ntemplate <typename\
    \ T = int>\nstd::vector<T> get_sigma(int n) {\n  std::vector<T> f(n + 1);\n  std::iota(f.begin(),\
    \ f.end(), 0);\n  divisor_zeta(f);\n  return f;\n}\ntemplate <typename T>\nstatic\
    \ std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {\n  int\
    \ n = max(a.size(), b.size());\n  a.resize(n);\n  b.resize(n);\n  divisor_zeta(a);\n\
    \  divisor_zeta(b);\n  for (int i = 0; i < n; i++) a[i] *= b[i];\n  divisor_mobius(a);\n\
    \  return a;\n}\n// f -> g s.t. g(n) = sum_{n|m} f(m)\ntemplate <typename T>\n\
    static void multiple_zeta(std::vector<T> &f) {\n  int n = f.size();\n  if (!primes.size())\
    \ init(n);\n  for (int p : primes) {\n    if (p > n) break;\n    for (int i =\
    \ (n - 1) / p; i > 0; i--) f[i] += f[p * i];\n  }\n}\n// f -> h s.t. f(n) = sum_{n|m}\
    \ h(m)\ntemplate <typename T>\nstatic void multiple_mobius(std::vector<T> &f)\
    \ {\n  int n = f.size();\n  if (!primes.size()) init(n);\n  for (int p : primes)\
    \ {\n    if (p > n) break;\n    for (int i = 1; p * i < n; i++) f[i] -= f[p *\
    \ i];\n  }\n}\ntemplate <typename T>\nstatic std::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n  int n = std::max(a.size(), b.size());\n  a.resize(n);\n\
    \  b.resize(n);\n  multiple_zeta(a);\n  multiple_zeta(b);\n  for (int i = 0; i\
    \ < n; i++) a[i] *= b[i];\n  multiple_mobius(a);\n  return a;\n}\n}  // namespace\
    \ number_theory\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/number_theory.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/886.numth.test.cpp
  - test/yukicoder/644.test.cpp
  - test/yosupo/sum_of_totient_function.test.cpp
documentation_of: src/Math/number_theory.hpp
layout: document
redirect_from:
- /library/src/Math/number_theory.hpp
- /library/src/Math/number_theory.hpp.html
title: "\u6570\u8AD6"
---
