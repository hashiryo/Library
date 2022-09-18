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
    document_title: "\u7BE9\u306A\u3069"
    links:
    - https://37zigen.com/linear-sieve/
    - https://en.wikipedia.org/wiki/Dirichlet_convolution
    - https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C
    - https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
  bundledCode: "#line 2 \"src/Math/Sieve.hpp\"\n#include <bits/stdc++.h>\n/**\n *\
    \ @title \u7BE9\u306A\u3069\n * @category \u6570\u5B66\n * \u7DDA\u5F62\u7BE9\u306B\
    \u3088\u308B\u7D20\u6570\u5217\u6319\u306E\u524D\u51E6\u7406\n * \u4E57\u6CD5\u7684\
    \u95A2\u6570 \u30C6\u30FC\u30D6\u30EB\u5217\u6319 \u3084 gcd\u7573\u307F\u8FBC\
    \u307F\u306A\u3069\n * @see https://37zigen.com/linear-sieve/\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <int LIM = 1 << 24>\nclass Sieve {\n public:\n\
    \  static inline int ps[LIM >> 4], lpf[LIM], lpfe[LIM], lpfpw[LIM], psz = 0;\n\
    \  static inline void sieve(int N) {  // O(N)\n    static int n = 2;\n    for\
    \ (; n <= N; n++) {\n      if (!lpf[n]) lpf[n] = ps[psz++] = n;\n      for (int\
    \ j = 0, e = std::min(lpf[n], N / n); j < psz && ps[j] <= e; j++)\n        lpf[ps[j]\
    \ * n] = ps[j];\n    }\n  }\n  static inline void set_lpfe(int N) {  // O(N)\n\
    \    static int n = 2;\n    if (N < n) return;\n    sieve(N), std::fill(lpfe +\
    \ n, lpfe + N + 1, 1);\n    for (std::copy(lpf + n, lpf + N + 1, lpfpw + n); n\
    \ <= N; n++)\n      if (int m = n / lpf[n]; lpf[n] == lpf[m])\n        lpfe[n]\
    \ += lpfe[m], lpfpw[n] *= lpfpw[m];\n  }\n\n public:\n  static int least_prime_factor(int\
    \ n) { return sieve(n), lpf[n]; }\n  // O(log n)\n  static std::map<int, short>\
    \ factorize(int n) {\n    std::map<int, short> ret;\n    for (set_lpfe(n); n >\
    \ 1;) ret[lpf[n]] = lpfe[n], n /= lpfpw[n];\n    return ret;\n  }\n  // O(log\
    \ n)\n  static std::vector<int> divisors(int n) {\n    std::vector<int> ret =\
    \ {1};\n    for (auto [p, e] : factorize(n))\n      for (std::size_t sz = ret.size(),\
    \ pw = p; e--; pw *= p)\n        for (int i = sz - 1; i >= 0; i--) ret.push_back(ret[i]\
    \ * pw);\n    return std::sort(ret.begin(), ret.end()), ret;\n  }\n  // O(N)\n\
    \  static std::vector<int> get_primes(int N) {\n    return sieve(N), std::vector<int>(ps,\
    \ std::upper_bound(ps, ps + psz, N));\n  }\n  template <class T, class F>\n  static\
    \ inline std::vector<T> completely_multiplicative_table(int N,\n             \
    \                                                  const F &f) {\n    std::vector<T>\
    \ ret(N + 1);\n    sieve(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] =\
    \ lpf[i] == i ? f(i, 1) : ret[lpf[i]] * ret[i / lpf[i]];\n    return ret[1] =\
    \ 1, ret;\n  }\n  template <class T, class F>\n  static inline std::vector<T>\
    \ multiplicative_table(int N, const F &f) {\n    std::vector<T> ret(N + 1);\n\
    \    set_lpfe(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] = lpfpw[i] ==\
    \ i ? f(lpf[i], lpfe[i])\n                             : ret[lpfpw[i]] * ret[i\
    \ / lpfpw[i]];\n    return ret[1] = 1, ret;\n  }\n  // O(N log k / log N + N)\n\
    \  template <class T>\n  static std::vector<T> pow_table(int N, std::uint64_t\
    \ k) {\n    auto f = [k](int p, short) {\n      T ret = 1, b = p;\n      for (auto\
    \ e = k;; b *= b)\n        if (e & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1)) return\
    \ ret;\n    };\n    return completely_multiplicative_table<T>(N, f);\n  }\n  //\
    \ O(N log MOD / log N + N)\n  template <class T>\n  static std::vector<T> inv_table(int\
    \ N) {\n    return completely_multiplicative_table<T>(\n        N, [](int p, short)\
    \ { return T(1) / p; });\n  }\n  // naive , O(N log N)\n  template <class T>\n\
    \  static std::vector<T> dirichlet_conv(const std::vector<T> &a,\n           \
    \                            const std::vector<T> &b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size()) - 1, i, j;\n    std::vector<T> ret(N + 1, 0);\n    for (i = a.size();\
    \ --i;)\n      for (j = std::min(b.size() - 1, N / i); j; j--) ret[i * j] += a[i]\
    \ * b[j];\n    return ret;\n  }\n  // a is multiplicative, O(N log log N)\n  template\
    \ <class T, class F>\n  static std::vector<T> dirichlet_conv(const F &a, std::vector<T>\
    \ b) {\n    std::size_t N = b.size() - 1, j = 0;\n    for (sieve(N), b.resize(N\
    \ + 1, 0); j < psz && ps[j] <= N; j++)\n      for (int i = N / ps[j], n, m, e;\
    \ i; i--)\n        for (b[n = ps[j] * i] += a(ps[j], e = 1) * b[m = i]; m % ps[j]\
    \ == 0;)\n          b[n] += a(ps[j], ++e) * b[m /= ps[j]];\n    return b;\n  }\n\
    \  // both a and b are multiplicative, O(N)\n  template <class T, class F1, class\
    \ F2>\n  static std::vector<T> dirichlet_conv(const F1 &a, const F2 &b,\n    \
    \                                   std::size_t N) {\n    auto f = [&a, &b](int\
    \ p, short e) {\n      T ret = a(p, e) + b(p, e);\n      for (int k = e; --k;)\
    \ ret += a(p, e - k) * b(p, k);\n      return ret;\n    };\n    return multiplicative_table<T>(N,\
    \ f);\n  }\n  // f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log N)\n  template\
    \ <typename T>\n  static void divisor_zeta(std::vector<T> &f) {\n    std::size_t\
    \ N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n\
    \      for (j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];\n  }\n  // f -> h\
    \ s.t. f(n) = sum_{m|n} h(m), O(N log log N)\n  template <typename T>\n  static\
    \ void divisor_mobius(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n\
    \    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1)\
    \ / ps[i]; j; j--) f[ps[i] * j] -= f[j];\n  }\n  // O(N log log N)\n  template\
    \ <typename T>\n  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T>\
    \ b) {\n    std::size_t N = std::max(a.size(), b.size());\n    a.resize(N), b.resize(N),\
    \ divisor_zeta(a), divisor_zeta(b);\n    for (; N--;) a[N] *= b[N];\n    return\
    \ divisor_mobius(a), a;\n  }\n  // both a and b are multiplicative, O(N)\n  template\
    \ <class T, class F1, class F2>\n  static std::vector<T> lcm_conv(const F1 &a,\
    \ const F2 &b, std::size_t N) {\n    auto f = [&a, &b](int p, short e) {\n   \
    \   T suma = 1, sumb = 1;\n      for (short k = 1; k < e; k++) suma += a(p, k),\
    \ sumb += b(p, k);\n      return (a(p, e) + suma) * (b(p, e) + sumb) - suma *\
    \ sumb;\n    };\n    return multiplicative_table<T>(N, f);\n  }\n  // f -> g s.t.\
    \ g(n) = sum_{n|m} f(m), O(N log log N)\n  template <typename T>\n  static void\
    \ multiple_zeta(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n  \
    \  for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1) /\
    \ ps[i]; j; j--) f[j] += f[ps[i] * j];\n  }\n  // f -> h s.t. f(n) = sum_{n|m}\
    \ h(m), O(N log log N)\n  template <typename T>\n  static void multiple_mobius(std::vector<T>\
    \ &f) {\n    std::size_t N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz\
    \ && ps[i] < N; i++)\n      for (j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] *\
    \ j];\n  }\n  // O(N log log N)\n  template <typename T>\n  static std::vector<T>\
    \ gcd_conv(std::vector<T> a, std::vector<T> b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size());\n    a.resize(N), b.resize(N), multiple_zeta(a), multiple_zeta(b);\n\
    \    for (; N--;) a[N] *= b[N];\n    return multiple_mobius(a), a;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u7BE9\u306A\u3069\
    \n * @category \u6570\u5B66\n * \u7DDA\u5F62\u7BE9\u306B\u3088\u308B\u7D20\u6570\
    \u5217\u6319\u306E\u524D\u51E6\u7406\n * \u4E57\u6CD5\u7684\u95A2\u6570 \u30C6\
    \u30FC\u30D6\u30EB\u5217\u6319 \u3084 gcd\u7573\u307F\u8FBC\u307F\u306A\u3069\n\
    \ * @see https://37zigen.com/linear-sieve/\n * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5\n\
    \ * @see https://en.wikipedia.org/wiki/Dirichlet_convolution\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <int LIM = 1 << 24>\nclass Sieve {\n public:\n\
    \  static inline int ps[LIM >> 4], lpf[LIM], lpfe[LIM], lpfpw[LIM], psz = 0;\n\
    \  static inline void sieve(int N) {  // O(N)\n    static int n = 2;\n    for\
    \ (; n <= N; n++) {\n      if (!lpf[n]) lpf[n] = ps[psz++] = n;\n      for (int\
    \ j = 0, e = std::min(lpf[n], N / n); j < psz && ps[j] <= e; j++)\n        lpf[ps[j]\
    \ * n] = ps[j];\n    }\n  }\n  static inline void set_lpfe(int N) {  // O(N)\n\
    \    static int n = 2;\n    if (N < n) return;\n    sieve(N), std::fill(lpfe +\
    \ n, lpfe + N + 1, 1);\n    for (std::copy(lpf + n, lpf + N + 1, lpfpw + n); n\
    \ <= N; n++)\n      if (int m = n / lpf[n]; lpf[n] == lpf[m])\n        lpfe[n]\
    \ += lpfe[m], lpfpw[n] *= lpfpw[m];\n  }\n\n public:\n  static int least_prime_factor(int\
    \ n) { return sieve(n), lpf[n]; }\n  // O(log n)\n  static std::map<int, short>\
    \ factorize(int n) {\n    std::map<int, short> ret;\n    for (set_lpfe(n); n >\
    \ 1;) ret[lpf[n]] = lpfe[n], n /= lpfpw[n];\n    return ret;\n  }\n  // O(log\
    \ n)\n  static std::vector<int> divisors(int n) {\n    std::vector<int> ret =\
    \ {1};\n    for (auto [p, e] : factorize(n))\n      for (std::size_t sz = ret.size(),\
    \ pw = p; e--; pw *= p)\n        for (int i = sz - 1; i >= 0; i--) ret.push_back(ret[i]\
    \ * pw);\n    return std::sort(ret.begin(), ret.end()), ret;\n  }\n  // O(N)\n\
    \  static std::vector<int> get_primes(int N) {\n    return sieve(N), std::vector<int>(ps,\
    \ std::upper_bound(ps, ps + psz, N));\n  }\n  template <class T, class F>\n  static\
    \ inline std::vector<T> completely_multiplicative_table(int N,\n             \
    \                                                  const F &f) {\n    std::vector<T>\
    \ ret(N + 1);\n    sieve(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] =\
    \ lpf[i] == i ? f(i, 1) : ret[lpf[i]] * ret[i / lpf[i]];\n    return ret[1] =\
    \ 1, ret;\n  }\n  template <class T, class F>\n  static inline std::vector<T>\
    \ multiplicative_table(int N, const F &f) {\n    std::vector<T> ret(N + 1);\n\
    \    set_lpfe(N);\n    for (int i = 2; i <= N; i++)\n      ret[i] = lpfpw[i] ==\
    \ i ? f(lpf[i], lpfe[i])\n                             : ret[lpfpw[i]] * ret[i\
    \ / lpfpw[i]];\n    return ret[1] = 1, ret;\n  }\n  // O(N log k / log N + N)\n\
    \  template <class T>\n  static std::vector<T> pow_table(int N, std::uint64_t\
    \ k) {\n    auto f = [k](int p, short) {\n      T ret = 1, b = p;\n      for (auto\
    \ e = k;; b *= b)\n        if (e & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1)) return\
    \ ret;\n    };\n    return completely_multiplicative_table<T>(N, f);\n  }\n  //\
    \ O(N log MOD / log N + N)\n  template <class T>\n  static std::vector<T> inv_table(int\
    \ N) {\n    return completely_multiplicative_table<T>(\n        N, [](int p, short)\
    \ { return T(1) / p; });\n  }\n  // naive , O(N log N)\n  template <class T>\n\
    \  static std::vector<T> dirichlet_conv(const std::vector<T> &a,\n           \
    \                            const std::vector<T> &b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size()) - 1, i, j;\n    std::vector<T> ret(N + 1, 0);\n    for (i = a.size();\
    \ --i;)\n      for (j = std::min(b.size() - 1, N / i); j; j--) ret[i * j] += a[i]\
    \ * b[j];\n    return ret;\n  }\n  // a is multiplicative, O(N log log N)\n  template\
    \ <class T, class F>\n  static std::vector<T> dirichlet_conv(const F &a, std::vector<T>\
    \ b) {\n    std::size_t N = b.size() - 1, j = 0;\n    for (sieve(N), b.resize(N\
    \ + 1, 0); j < psz && ps[j] <= N; j++)\n      for (int i = N / ps[j], n, m, e;\
    \ i; i--)\n        for (b[n = ps[j] * i] += a(ps[j], e = 1) * b[m = i]; m % ps[j]\
    \ == 0;)\n          b[n] += a(ps[j], ++e) * b[m /= ps[j]];\n    return b;\n  }\n\
    \  // both a and b are multiplicative, O(N)\n  template <class T, class F1, class\
    \ F2>\n  static std::vector<T> dirichlet_conv(const F1 &a, const F2 &b,\n    \
    \                                   std::size_t N) {\n    auto f = [&a, &b](int\
    \ p, short e) {\n      T ret = a(p, e) + b(p, e);\n      for (int k = e; --k;)\
    \ ret += a(p, e - k) * b(p, k);\n      return ret;\n    };\n    return multiplicative_table<T>(N,\
    \ f);\n  }\n  // f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log N)\n  template\
    \ <typename T>\n  static void divisor_zeta(std::vector<T> &f) {\n    std::size_t\
    \ N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n\
    \      for (j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];\n  }\n  // f -> h\
    \ s.t. f(n) = sum_{m|n} h(m), O(N log log N)\n  template <typename T>\n  static\
    \ void divisor_mobius(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n\
    \    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1)\
    \ / ps[i]; j; j--) f[ps[i] * j] -= f[j];\n  }\n  // O(N log log N)\n  template\
    \ <typename T>\n  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T>\
    \ b) {\n    std::size_t N = std::max(a.size(), b.size());\n    a.resize(N), b.resize(N),\
    \ divisor_zeta(a), divisor_zeta(b);\n    for (; N--;) a[N] *= b[N];\n    return\
    \ divisor_mobius(a), a;\n  }\n  // both a and b are multiplicative, O(N)\n  template\
    \ <class T, class F1, class F2>\n  static std::vector<T> lcm_conv(const F1 &a,\
    \ const F2 &b, std::size_t N) {\n    auto f = [&a, &b](int p, short e) {\n   \
    \   T suma = 1, sumb = 1;\n      for (short k = 1; k < e; k++) suma += a(p, k),\
    \ sumb += b(p, k);\n      return (a(p, e) + suma) * (b(p, e) + sumb) - suma *\
    \ sumb;\n    };\n    return multiplicative_table<T>(N, f);\n  }\n  // f -> g s.t.\
    \ g(n) = sum_{n|m} f(m), O(N log log N)\n  template <typename T>\n  static void\
    \ multiple_zeta(std::vector<T> &f) {\n    std::size_t N = f.size(), i, j;\n  \
    \  for (sieve(N), i = 0; i < psz && ps[i] < N; i++)\n      for (j = (N - 1) /\
    \ ps[i]; j; j--) f[j] += f[ps[i] * j];\n  }\n  // f -> h s.t. f(n) = sum_{n|m}\
    \ h(m), O(N log log N)\n  template <typename T>\n  static void multiple_mobius(std::vector<T>\
    \ &f) {\n    std::size_t N = f.size(), i, j;\n    for (sieve(N), i = 0; i < psz\
    \ && ps[i] < N; i++)\n      for (j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] *\
    \ j];\n  }\n  // O(N log log N)\n  template <typename T>\n  static std::vector<T>\
    \ gcd_conv(std::vector<T> a, std::vector<T> b) {\n    std::size_t N = std::max(a.size(),\
    \ b.size());\n    a.resize(N), b.resize(N), multiple_zeta(a), multiple_zeta(b);\n\
    \    for (; N--;) a[N] *= b[N];\n    return multiple_mobius(a), a;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Sieve.hpp
  requiredBy: []
  timestamp: '2022-09-18 23:09:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/886.numth.test.cpp
  - test/yukicoder/1019.test.cpp
  - test/yukicoder/644.test.cpp
  - test/atcoder/agc038_c.numth.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
documentation_of: src/Math/Sieve.hpp
layout: document
redirect_from:
- /library/src/Math/Sieve.hpp
- /library/src/Math/Sieve.hpp.html
title: "\u7BE9\u306A\u3069"
---
