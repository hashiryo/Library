---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.numth.test.cpp
    title: test/atcoder/abc172_d.numth.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc038_c.numth.test.cpp
    title: test/atcoder/agc038_c.numth.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1019.test.cpp
    title: test/yukicoder/1019.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/644.test.cpp
    title: test/yukicoder/644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/886.numth.test.cpp
    title: test/yukicoder/886.numth.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6570\u8AD6\u3044\u308D\u3044\u308D"
    links:
    - https://37zigen.com/linear-sieve/
    - https://en.wikipedia.org/wiki/Dirichlet_convolution
    - https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
  bundledCode: "#line 2 \"src/Math/NumberTheory.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6570\u8AD6\u3044\u308D\u3044\u308D\n * @category \u6570\u5B66\
    \n * \u7DDA\u5F62\u7BE9\u306B\u3088\u308B\u7D20\u6570\u5217\u6319\u306E\u524D\u51E6\
    \u7406\n * \u4E57\u6CD5\u7684\u95A2\u6570 \u30C6\u30FC\u30D6\u30EB\u5217\u6319\
    \ \u3084 gcd\u7573\u307F\u8FBC\u307F\u306A\u3069\n * @see https://37zigen.com/linear-sieve/\n\
    \ * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n\
    \ */\n\n// BEGIN CUT HERE\n\nclass NumberTheory {\n  static constexpr int MAX_N\
    \ = 1 << 24;\n  static inline int ps[MAX_N >> 4], mpf[MAX_N], psz = 0, lim = 2;\n\
    \  static inline void sieve(int N) {\n    if (lim > N) return;\n    for (int d\
    \ = lim; d <= N; d++) {\n      if (!mpf[d]) mpf[d] = ps[psz++] = d;\n      for\
    \ (int j = 0; j < psz && ps[j] <= mpf[d] && ps[j] * d <= N; j++)\n        mpf[ps[j]\
    \ * d] = ps[j];\n    }\n    lim = N + 1;\n  }\n\n public:\n  static int min_prime_factor(int\
    \ n) { return sieve(n), mpf[n]; }\n  // O(log n)\n  static std::map<int, short>\
    \ factorize(int n) {\n    std::map<int, short> ret;\n    sieve(n);\n    while\
    \ (n > 1) ret[mpf[n]]++, n /= mpf[n];\n    return ret;\n  }\n  // O(log n)\n \
    \ static std::vector<int> divisors(int n) {\n    std::vector<int> ret = {1};\n\
    \    for (auto [p, e] : factorize(n))\n      for (std::size_t sz = ret.size(),\
    \ pw = p; e--; pw *= p)\n        for (int i = sz - 1; i >= 0; i--) ret.push_back(ret[i]\
    \ * pw);\n    return std::sort(ret.begin(), ret.end()), ret;\n  }\n  // O(N)\n\
    \  static std::vector<int> get_primes(int N) {\n    return sieve(N), std::vector<int>(ps,\
    \ std::upper_bound(ps, ps + psz, N));\n  }\n  template <class T, class F>\n  static\
    \ std::vector<T> completely_multiplicative_table(int N, const F &f) {\n    std::vector<T>\
    \ ret(N + 1);\n    sieve(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] =\
    \ mpf[i] == i ? f(i, 1) : ret[mpf[i]] * ret[i / mpf[i]];\n    return ret[1] =\
    \ 1, ret;\n  }\n  template <class T, class F>\n  static std::vector<T> multiplicative_table(int\
    \ N, const F &f) {\n    std::vector<T> ret(N + 1, 0);\n    sieve(N);\n    auto\
    \ dfs = [&](auto rc, int i, long long x, T y) -> void {\n      if ((ret[x] = y)\
    \ == T(0)) return;\n      for (int j = i + 1; j < psz && ps[j] * x <= (long long)N;\
    \ j++)\n        for (long long e = 1, nx = ps[j] * x; nx <= N; nx *= ps[j], e++)\n\
    \          rc(rc, j, nx, y * f(ps[j], e));\n    };\n    return dfs(dfs, -1, 1,\
    \ 1), ret;\n  }\n  // O(N log k / log N)\n  template <class T>\n  static std::vector<T>\
    \ pow_table(int N, std::uint64_t k) {\n    auto f = [k](int p, short) {\n    \
    \  T ret = 1, b = p;\n      for (auto e = k; e; e >>= 1, b *= b)\n        if (e\
    \ & 1) ret *= b;\n      return ret;\n    };\n    return completely_multiplicative_table<T>(N,\
    \ f);\n  }\n  // O(N)\n  template <class T>\n  static std::vector<T> inv_table(int\
    \ N) {\n    return completely_multiplicative_table<T>(\n        N, [](int p, short)\
    \ { return T(1) / p; });\n  }\n  // naive , O(N log N)\n  template <class T>\n\
    \  static std::vector<T> dirichlet_conv(const std::vector<T> &a,\n           \
    \                            const std::vector<T> &b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size());\n    std::vector<T> ret(N, 0);\n    for (std::size_t i = 1; i < a.size();\
    \ i++)\n      for (std::size_t j = 1; j < b.size() && i * j < N; j++)\n      \
    \  ret[i * j] += a[i] * b[j];\n    return ret;\n  }\n  // f -> g s.t. g(n) = sum_{m|n}\
    \ f(m) , O(N log log N)\n  template <typename T>\n  static void divisor_zeta(std::vector<T>\
    \ &f) {\n    int N = f.size();\n    sieve(N);\n    for (int i = 0; i < psz &&\
    \ ps[i] < N; i++)\n      for (int j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];\n\
    \  }\n  // f -> h s.t. f(n) = sum_{m|n} h(m) , O(N log log N)\n  template <typename\
    \ T>\n  static void divisor_mobius(std::vector<T> &f) {\n    int N = f.size();\n\
    \    sieve(N);\n    for (int i = 0; i < psz && ps[i] < N; i++)\n      for (int\
    \ j = (N - 1) / ps[i]; j; j--) f[ps[i] * j] -= f[j];\n  }\n  // O(N log log N)\n\
    \  template <typename T>\n  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T>\
    \ b) {\n    int N = std::max(a.size(), b.size());\n    a.resize(N), b.resize(N),\
    \ divisor_zeta(a), divisor_zeta(b);\n    for (int i = 0; i < N; i++) a[i] *= b[i];\n\
    \    divisor_mobius(a);\n    return a;\n  }\n  // f -> g s.t. g(n) = sum_{n|m}\
    \ f(m) , O(N log log N)\n  template <typename T>\n  static void multiple_zeta(std::vector<T>\
    \ &f) {\n    int N = f.size();\n    sieve(N);\n    for (int i = 0; i < psz &&\
    \ ps[i] < N; i++)\n      for (int j = (N - 1) / ps[i]; j > 0; j--) f[j] += f[ps[i]\
    \ * j];\n  }\n  // f -> h s.t. f(n) = sum_{n|m} h(m) , O(N log log N)\n  template\
    \ <typename T>\n  static void multiple_mobius(std::vector<T> &f) {\n    int N\
    \ = f.size();\n    sieve(N);\n    for (int i = 0; i < psz && ps[i] < N; i++)\n\
    \      for (int j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] * j];\n  }\n  // O(N\
    \ log log N)\n  template <typename T>\n  static std::vector<T> gcd_conv(std::vector<T>\
    \ a, std::vector<T> b) {\n    int N = std::max(a.size(), b.size());\n    a.resize(N),\
    \ b.resize(N), multiple_zeta(a), multiple_zeta(b);\n    for (int i = 0; i < N;\
    \ i++) a[i] *= b[i];\n    multiple_mobius(a);\n    return a;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6570\u8AD6\u3044\
    \u308D\u3044\u308D\n * @category \u6570\u5B66\n * \u7DDA\u5F62\u7BE9\u306B\u3088\
    \u308B\u7D20\u6570\u5217\u6319\u306E\u524D\u51E6\u7406\n * \u4E57\u6CD5\u7684\u95A2\
    \u6570 \u30C6\u30FC\u30D6\u30EB\u5217\u6319 \u3084 gcd\u7573\u307F\u8FBC\u307F\
    \u306A\u3069\n * @see https://37zigen.com/linear-sieve/\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n */\n\n// BEGIN\
    \ CUT HERE\n\nclass NumberTheory {\n  static constexpr int MAX_N = 1 << 24;\n\
    \  static inline int ps[MAX_N >> 4], mpf[MAX_N], psz = 0, lim = 2;\n  static inline\
    \ void sieve(int N) {\n    if (lim > N) return;\n    for (int d = lim; d <= N;\
    \ d++) {\n      if (!mpf[d]) mpf[d] = ps[psz++] = d;\n      for (int j = 0; j\
    \ < psz && ps[j] <= mpf[d] && ps[j] * d <= N; j++)\n        mpf[ps[j] * d] = ps[j];\n\
    \    }\n    lim = N + 1;\n  }\n\n public:\n  static int min_prime_factor(int n)\
    \ { return sieve(n), mpf[n]; }\n  // O(log n)\n  static std::map<int, short> factorize(int\
    \ n) {\n    std::map<int, short> ret;\n    sieve(n);\n    while (n > 1) ret[mpf[n]]++,\
    \ n /= mpf[n];\n    return ret;\n  }\n  // O(log n)\n  static std::vector<int>\
    \ divisors(int n) {\n    std::vector<int> ret = {1};\n    for (auto [p, e] : factorize(n))\n\
    \      for (std::size_t sz = ret.size(), pw = p; e--; pw *= p)\n        for (int\
    \ i = sz - 1; i >= 0; i--) ret.push_back(ret[i] * pw);\n    return std::sort(ret.begin(),\
    \ ret.end()), ret;\n  }\n  // O(N)\n  static std::vector<int> get_primes(int N)\
    \ {\n    return sieve(N), std::vector<int>(ps, std::upper_bound(ps, ps + psz,\
    \ N));\n  }\n  template <class T, class F>\n  static std::vector<T> completely_multiplicative_table(int\
    \ N, const F &f) {\n    std::vector<T> ret(N + 1);\n    sieve(N);\n    for (int\
    \ i = 2; i <= N; i++)\n      ret[i] = mpf[i] == i ? f(i, 1) : ret[mpf[i]] * ret[i\
    \ / mpf[i]];\n    return ret[1] = 1, ret;\n  }\n  template <class T, class F>\n\
    \  static std::vector<T> multiplicative_table(int N, const F &f) {\n    std::vector<T>\
    \ ret(N + 1, 0);\n    sieve(N);\n    auto dfs = [&](auto rc, int i, long long\
    \ x, T y) -> void {\n      if ((ret[x] = y) == T(0)) return;\n      for (int j\
    \ = i + 1; j < psz && ps[j] * x <= (long long)N; j++)\n        for (long long\
    \ e = 1, nx = ps[j] * x; nx <= N; nx *= ps[j], e++)\n          rc(rc, j, nx, y\
    \ * f(ps[j], e));\n    };\n    return dfs(dfs, -1, 1, 1), ret;\n  }\n  // O(N\
    \ log k / log N)\n  template <class T>\n  static std::vector<T> pow_table(int\
    \ N, std::uint64_t k) {\n    auto f = [k](int p, short) {\n      T ret = 1, b\
    \ = p;\n      for (auto e = k; e; e >>= 1, b *= b)\n        if (e & 1) ret *=\
    \ b;\n      return ret;\n    };\n    return completely_multiplicative_table<T>(N,\
    \ f);\n  }\n  // O(N)\n  template <class T>\n  static std::vector<T> inv_table(int\
    \ N) {\n    return completely_multiplicative_table<T>(\n        N, [](int p, short)\
    \ { return T(1) / p; });\n  }\n  // naive , O(N log N)\n  template <class T>\n\
    \  static std::vector<T> dirichlet_conv(const std::vector<T> &a,\n           \
    \                            const std::vector<T> &b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size());\n    std::vector<T> ret(N, 0);\n    for (std::size_t i = 1; i < a.size();\
    \ i++)\n      for (std::size_t j = 1; j < b.size() && i * j < N; j++)\n      \
    \  ret[i * j] += a[i] * b[j];\n    return ret;\n  }\n  // f -> g s.t. g(n) = sum_{m|n}\
    \ f(m) , O(N log log N)\n  template <typename T>\n  static void divisor_zeta(std::vector<T>\
    \ &f) {\n    int N = f.size();\n    sieve(N);\n    for (int i = 0; i < psz &&\
    \ ps[i] < N; i++)\n      for (int j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];\n\
    \  }\n  // f -> h s.t. f(n) = sum_{m|n} h(m) , O(N log log N)\n  template <typename\
    \ T>\n  static void divisor_mobius(std::vector<T> &f) {\n    int N = f.size();\n\
    \    sieve(N);\n    for (int i = 0; i < psz && ps[i] < N; i++)\n      for (int\
    \ j = (N - 1) / ps[i]; j; j--) f[ps[i] * j] -= f[j];\n  }\n  // O(N log log N)\n\
    \  template <typename T>\n  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T>\
    \ b) {\n    int N = std::max(a.size(), b.size());\n    a.resize(N), b.resize(N),\
    \ divisor_zeta(a), divisor_zeta(b);\n    for (int i = 0; i < N; i++) a[i] *= b[i];\n\
    \    divisor_mobius(a);\n    return a;\n  }\n  // f -> g s.t. g(n) = sum_{n|m}\
    \ f(m) , O(N log log N)\n  template <typename T>\n  static void multiple_zeta(std::vector<T>\
    \ &f) {\n    int N = f.size();\n    sieve(N);\n    for (int i = 0; i < psz &&\
    \ ps[i] < N; i++)\n      for (int j = (N - 1) / ps[i]; j > 0; j--) f[j] += f[ps[i]\
    \ * j];\n  }\n  // f -> h s.t. f(n) = sum_{n|m} h(m) , O(N log log N)\n  template\
    \ <typename T>\n  static void multiple_mobius(std::vector<T> &f) {\n    int N\
    \ = f.size();\n    sieve(N);\n    for (int i = 0; i < psz && ps[i] < N; i++)\n\
    \      for (int j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] * j];\n  }\n  // O(N\
    \ log log N)\n  template <typename T>\n  static std::vector<T> gcd_conv(std::vector<T>\
    \ a, std::vector<T> b) {\n    int N = std::max(a.size(), b.size());\n    a.resize(N),\
    \ b.resize(N), multiple_zeta(a), multiple_zeta(b);\n    for (int i = 0; i < N;\
    \ i++) a[i] *= b[i];\n    multiple_mobius(a);\n    return a;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory.hpp
  requiredBy: []
  timestamp: '2022-02-07 21:00:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/agc038_c.numth.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
  - test/yosupo/sum_of_totient_function.test.cpp
  - test/yukicoder/644.test.cpp
  - test/yukicoder/1019.test.cpp
  - test/yukicoder/886.numth.test.cpp
documentation_of: src/Math/NumberTheory.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory.hpp
- /library/src/Math/NumberTheory.hpp.html
title: "\u6570\u8AD6\u3044\u308D\u3044\u308D"
---
