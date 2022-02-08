---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/UndirectedGraphSetPowerSeries.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u6570\u3048\u4E0A\u3052(\u96C6\u5408\u51AA\
      \u7D1A\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96C6\u5408\u51AA\u7D1A\u6570"
    links:
    - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
    - https://loj.ac/p/2340
  bundledCode: "#line 2 \"src/Math/SetPowerSeries.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u96C6\u5408\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\n */\n\
    \n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N\
    \ = 21>\nclass SetPowerSeries {\n#define SUBSET_REP(i, j, n)                 \
    \          \\\n  for (int _ = (n); _ >>= 1;)                         \\\n    for\
    \ (int __ = 0, _2 = _ << 1; __ < (n); __ += _2) \\\n      for (int j = __, i =\
    \ j | _, ___ = i; j < ___; j++, i++)\n  template <typename T>\n  static inline\
    \ void ranked_zeta_trans(const T f[], T ret[][MAX_N + 1],\n                  \
    \                     const int &sz) {\n    for (int S = sz, c; S--;)\n      ret[S][c\
    \ = __builtin_popcount(S)] = f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S,\
    \ U, sz)\n    for (int d = __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n\
    \  }\n  template <typename T>\n  static inline void ranked_moebius_trans(T mat[][MAX_N\
    \ + 1], T ret[],\n                                          const int &sz) {\n\
    \    const int n = __builtin_ctz(sz);\n    SUBSET_REP(S, U, sz)\n    for (int\
    \ c = __builtin_popcount(U), d = std::min(2 * c, n); d > c; d--)\n      mat[S][d]\
    \ -= mat[U][d];\n    for (int S = sz; S--;) ret[S] = mat[S][__builtin_popcount(S)];\n\
    \  }\n  template <typename T>\n  static inline void conv_naive(const T f[], const\
    \ T g[], T ret[],\n                                const int &sz) {\n    for (int\
    \ s = sz, t; s--;)\n      for (ret[t = s] = f[s] * g[0]; t; (--t) &= s) ret[s]\
    \ += f[s ^ t] * g[t];\n  }\n  template <typename T>\n  static inline void conv_trans(const\
    \ T f[], const T g[], T ret[],\n                                const int &sz)\
    \ {\n    static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1], tmp[MAX_N\
    \ + 1];\n    ranked_zeta_trans(f, F, sz), ranked_zeta_trans(g, G, sz);\n    const\
    \ int n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e, bg; S--;) {\n    \
    \  c = __builtin_popcount(S), bg = std::min(2 * c, n);\n      for (d = bg; d >=\
    \ c; d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n          tmp[d]\
    \ += F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d] = tmp[d];\n\
    \    }\n    ranked_moebius_trans(F, ret, sz);\n  }\n  template <typename T, class\
    \ F>\n  static inline void online_conv_naive(const T g[], T ret[], const F &phi,\n\
    \                                       const int &sz) {\n    for (int s = 1,\
    \ t; s < sz; phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; (--t) &= s) ret[s]\
    \ += ret[s ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline\
    \ void online_conv_trans(const T g[], T ret[], const F &phi,\n               \
    \                        const int &sz) {\n    static T G[1 << MAX_N][MAX_N +\
    \ 1], mat[MAX_N + 1][1 << MAX_N];\n    const int n = __builtin_ctz(sz);\n    ranked_zeta_trans(g,\
    \ G, sz), std::fill_n(mat[0], sz, ret[0]);\n    for (int d = n; d; d--) std::fill_n(mat[d],\
    \ sz, 0);\n    for (int I = sz; I >>= 1;) phi(I, mat[1][I] = ret[0] * g[I]);\n\
    \    for (int d = 2; d <= n; d++) {\n      SUBSET_REP(S, U, sz) mat[d - 1][S]\
    \ += mat[d - 1][U];\n      for (int S = sz; S--;)\n        if (int c = __builtin_popcount(S);\
    \ c <= d && d <= 2 * c)\n          for (int e = d; e--;) mat[d][S] += mat[e][S]\
    \ * G[S][d - e];\n      SUBSET_REP(S, U, sz) mat[d][S] -= mat[d][U];\n      for\
    \ (int S = sz; S--;)\n        __builtin_popcount(S) == d ? phi(S, mat[d][S]),\
    \ 0 : (mat[d][S] = 0);\n    }\n    for (int S = sz; --S;) ret[S] = mat[__builtin_popcount(S)][S];\n\
    \  }\n\n public:\n  template <typename T>  // O(n 2^n)\n  static inline void subset_sum(std::vector<T>\
    \ &f) {\n    SUBSET_REP(S, U, f.size()) f[S] += f[U];\n  }\n  template <typename\
    \ T>  // O(n 2^n)\n  static inline void subset_sum_inv(std::vector<T> &f) {\n\
    \    SUBSET_REP(S, U, f.size()) f[S] -= f[U];\n  }\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> convolution(std::vector<T> f, std::vector<T>\
    \ g) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n    std::vector<T>\
    \ ret(sz);\n    if (n <= 10) return conv_naive(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n    assert(sz == 1 << n && sz == g.size());\n    return conv_trans(f.data(),\
    \ g.data(), ret.data(), sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{T\u2282\
    S & T\u2260\u2205} g(T)f(S/T) )\n  template <class T, class F = void (*)(int,\
    \ T &)>  // O(n^2 2^n)\n  static inline std::vector<T> online_convolution(\n \
    \     std::vector<T> g, T init, const F &phi = [](int, T &) {}) {\n    const int\
    \ sz = g.size(), n = __builtin_ctz(sz);\n    std::vector<T> ret(sz);\n    ret[0]\
    \ = init;\n    if (n <= 12) return online_conv_naive(g.data(), ret.data(), phi,\
    \ sz), ret;\n    assert(sz == 1 << n);\n    return online_conv_trans(g.data(),\
    \ ret.data(), phi, sz), ret;\n  }\n  // f(S) = \u03C6_S ( (1/2) * \u03A3_{T\u2282\
    S & T\u2260\u2205 & T\u2260S} f(T)f(S/T) )\n  template <class T, class F>  //\
    \ O(n^2 2^n)\n  static inline std::vector<T> online_convolution2(int sz, const\
    \ F &phi) {\n    assert(__builtin_popcount(sz) == 1);\n    int mid = std::min(1\
    \ << 13, sz);\n    std::vector<T> ret(sz, 0);\n    for (int I = 1, s, t, u = 1;\
    \ I < mid; I <<= 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n\
    \        for (ret[u] = 0; t; (--t) &= s) ret[u] += ret[I | (s ^ t)] * ret[t];\n\
    \    for (int I = mid; I < sz; I <<= 1) {\n      auto phi2 = [&](int s, T &x)\
    \ { phi(s | I, x); };\n      phi(I, ret[I]), online_conv_trans(ret.data(), ret.data()\
    \ + I, phi2, I);\n    }\n    return ret;\n  }\n  // F(f) : F[i] is coefficient\
    \ of EGF ( = F^{(i)}(0) )\n  // \"f[\u03C6] = 0\" is required.\n  template <class\
    \ T, class EGF>  // O(n^2 2^n)\n  static inline std::vector<T> composite(const\
    \ std::vector<T> &f,\n                                         const EGF &F) {\n\
    \    const int sz = f.size(), m = __builtin_ctz(sz), sz2 = sz >> 1;\n    assert(sz\
    \ == 1 << m);\n    assert(f.at(0) == 0);\n    std::vector<T> ret(sz);\n    T *h\
    \ = ret.data() + sz;\n    const T *g = f.data();\n    for (int i = 0; i <= m;\
    \ i++) ret[sz - (1 << i)] = F[m - i];\n    int l = 1, ed = std::min(sz, 1 << 11),\
    \ j;\n    for (; l < ed; l <<= 1)\n      for (j = sz2; j >= l; j >>= 1) conv_naive(h\
    \ - j, g + l, h - j - j + l, l);\n    for (; l < sz; l <<= 1)\n      for (j =\
    \ sz2; j >= l; j >>= 1) conv_trans(h - j, g + l, h - j - j + l, l);\n    return\
    \ ret;\n  }\n  // exp(f) : \"f[\u03C6] = 0\" is required.\n  template <class T>\
    \  // O(n^2 2^n)\n  static inline std::vector<T> exp(const std::vector<T> &f)\
    \ {\n    const int sz = f.size();\n    assert(sz == 1 << __builtin_ctz(sz));\n\
    \    assert(f.at(0) == 0);\n    std::vector<T> ret(sz);\n    T *h = ret.data();\n\
    \    const T *g = f.data();\n    int l = 1, ed = std::min(sz, 1 << 11);\n    for\
    \ (h[0] = 1; l < ed; l <<= 1) conv_naive(h, g + l, h + l, l);\n    for (; l <\
    \ sz; l <<= 1) conv_trans(h, g + l, h + l, l);\n    return ret;\n  }\n  // log(f)\
    \ : \"f[\u03C6] = 1\" is required.\n  template <class T>  // O(n^2 2^n)\n  static\
    \ inline std::vector<T> log(std::vector<T> f) {\n    const int sz = f.size(),\
    \ m = __builtin_ctz(sz);\n    assert(sz == 1 << m);\n    assert(f.at(0) == T(1));\n\
    \    static T F[MAX_N + 1] = {0, 1};\n    for (int i = 2; i <= m; i++) F[i] =\
    \ -F[i - 1] * (i - 1);\n    return f[0] = 0, composite(f, F);\n  }\n  // f^k\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> pow(std::vector<T>\
    \ f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
    \    assert(sz == 1 << n);\n    T F[MAX_N + 1] = {1}, pw = 1, bs = f[0];\n   \
    \ int i = 1, ed = std::min<std::uint64_t>(n, k);\n    for (; i <= ed; i++) F[i]\
    \ = F[i - 1] * (k - i + 1);\n    for (auto e = k - --i; e; e >>= 1, bs *= bs)\n\
    \      if (e & 1) pw *= bs;\n    for (; i >= 0; i--, pw *= f[0]) F[i] *= pw;\n\
    \    return f[0] = 0, composite(f, F);\n  }\n\n  // {[X^{[n]}](f^k)/(k!)} for\
    \ k=0,1,...,n\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ egf(std::vector<T> f) {\n    const int sz = f.size(), n = __builtin_ctz(sz),\
    \ md = 1 << 11, sz4 = sz >> 2;\n    assert(sz == 1 << n);\n    int l = sz4, m;\n\
    \    T *in = f.data() + l, *dp = in + l, tmp[sz4], *dp2;\n    for (int s; l >\
    \ md; conv_trans(dp, in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4;\
    \ dp2 = dp + (m - l), m > l; m >>= 1, s = l)\n        for (conv_trans(dp2 + m\
    \ - l, in, tmp, l); s--;) dp2[s] += tmp[s];\n    for (int s; l; conv_naive(dp,\
    \ in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4; dp2 = dp + (m - l),\
    \ m > l; m >>= 1, s = l)\n        for (conv_naive(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s] += tmp[s];\n    std::vector<T> ret(n + 1, 0);\n    for (int i = n + 1;\
    \ --i;) ret[i] = dp[(1 << (n - i)) - 1];\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u96C6\u5408\u51AA\
    \u7D1A\u6570\n * @category \u6570\u5B66\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N\
    \ = 21>\nclass SetPowerSeries {\n#define SUBSET_REP(i, j, n)                 \
    \          \\\n  for (int _ = (n); _ >>= 1;)                         \\\n    for\
    \ (int __ = 0, _2 = _ << 1; __ < (n); __ += _2) \\\n      for (int j = __, i =\
    \ j | _, ___ = i; j < ___; j++, i++)\n  template <typename T>\n  static inline\
    \ void ranked_zeta_trans(const T f[], T ret[][MAX_N + 1],\n                  \
    \                     const int &sz) {\n    for (int S = sz, c; S--;)\n      ret[S][c\
    \ = __builtin_popcount(S)] = f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S,\
    \ U, sz)\n    for (int d = __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n\
    \  }\n  template <typename T>\n  static inline void ranked_moebius_trans(T mat[][MAX_N\
    \ + 1], T ret[],\n                                          const int &sz) {\n\
    \    const int n = __builtin_ctz(sz);\n    SUBSET_REP(S, U, sz)\n    for (int\
    \ c = __builtin_popcount(U), d = std::min(2 * c, n); d > c; d--)\n      mat[S][d]\
    \ -= mat[U][d];\n    for (int S = sz; S--;) ret[S] = mat[S][__builtin_popcount(S)];\n\
    \  }\n  template <typename T>\n  static inline void conv_naive(const T f[], const\
    \ T g[], T ret[],\n                                const int &sz) {\n    for (int\
    \ s = sz, t; s--;)\n      for (ret[t = s] = f[s] * g[0]; t; (--t) &= s) ret[s]\
    \ += f[s ^ t] * g[t];\n  }\n  template <typename T>\n  static inline void conv_trans(const\
    \ T f[], const T g[], T ret[],\n                                const int &sz)\
    \ {\n    static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1], tmp[MAX_N\
    \ + 1];\n    ranked_zeta_trans(f, F, sz), ranked_zeta_trans(g, G, sz);\n    const\
    \ int n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e, bg; S--;) {\n    \
    \  c = __builtin_popcount(S), bg = std::min(2 * c, n);\n      for (d = bg; d >=\
    \ c; d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n          tmp[d]\
    \ += F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d] = tmp[d];\n\
    \    }\n    ranked_moebius_trans(F, ret, sz);\n  }\n  template <typename T, class\
    \ F>\n  static inline void online_conv_naive(const T g[], T ret[], const F &phi,\n\
    \                                       const int &sz) {\n    for (int s = 1,\
    \ t; s < sz; phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; (--t) &= s) ret[s]\
    \ += ret[s ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline\
    \ void online_conv_trans(const T g[], T ret[], const F &phi,\n               \
    \                        const int &sz) {\n    static T G[1 << MAX_N][MAX_N +\
    \ 1], mat[MAX_N + 1][1 << MAX_N];\n    const int n = __builtin_ctz(sz);\n    ranked_zeta_trans(g,\
    \ G, sz), std::fill_n(mat[0], sz, ret[0]);\n    for (int d = n; d; d--) std::fill_n(mat[d],\
    \ sz, 0);\n    for (int I = sz; I >>= 1;) phi(I, mat[1][I] = ret[0] * g[I]);\n\
    \    for (int d = 2; d <= n; d++) {\n      SUBSET_REP(S, U, sz) mat[d - 1][S]\
    \ += mat[d - 1][U];\n      for (int S = sz; S--;)\n        if (int c = __builtin_popcount(S);\
    \ c <= d && d <= 2 * c)\n          for (int e = d; e--;) mat[d][S] += mat[e][S]\
    \ * G[S][d - e];\n      SUBSET_REP(S, U, sz) mat[d][S] -= mat[d][U];\n      for\
    \ (int S = sz; S--;)\n        __builtin_popcount(S) == d ? phi(S, mat[d][S]),\
    \ 0 : (mat[d][S] = 0);\n    }\n    for (int S = sz; --S;) ret[S] = mat[__builtin_popcount(S)][S];\n\
    \  }\n\n public:\n  template <typename T>  // O(n 2^n)\n  static inline void subset_sum(std::vector<T>\
    \ &f) {\n    SUBSET_REP(S, U, f.size()) f[S] += f[U];\n  }\n  template <typename\
    \ T>  // O(n 2^n)\n  static inline void subset_sum_inv(std::vector<T> &f) {\n\
    \    SUBSET_REP(S, U, f.size()) f[S] -= f[U];\n  }\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> convolution(std::vector<T> f, std::vector<T>\
    \ g) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n    std::vector<T>\
    \ ret(sz);\n    if (n <= 10) return conv_naive(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n    assert(sz == 1 << n && sz == g.size());\n    return conv_trans(f.data(),\
    \ g.data(), ret.data(), sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{T\u2282\
    S & T\u2260\u2205} g(T)f(S/T) )\n  template <class T, class F = void (*)(int,\
    \ T &)>  // O(n^2 2^n)\n  static inline std::vector<T> online_convolution(\n \
    \     std::vector<T> g, T init, const F &phi = [](int, T &) {}) {\n    const int\
    \ sz = g.size(), n = __builtin_ctz(sz);\n    std::vector<T> ret(sz);\n    ret[0]\
    \ = init;\n    if (n <= 12) return online_conv_naive(g.data(), ret.data(), phi,\
    \ sz), ret;\n    assert(sz == 1 << n);\n    return online_conv_trans(g.data(),\
    \ ret.data(), phi, sz), ret;\n  }\n  // f(S) = \u03C6_S ( (1/2) * \u03A3_{T\u2282\
    S & T\u2260\u2205 & T\u2260S} f(T)f(S/T) )\n  template <class T, class F>  //\
    \ O(n^2 2^n)\n  static inline std::vector<T> online_convolution2(int sz, const\
    \ F &phi) {\n    assert(__builtin_popcount(sz) == 1);\n    int mid = std::min(1\
    \ << 13, sz);\n    std::vector<T> ret(sz, 0);\n    for (int I = 1, s, t, u = 1;\
    \ I < mid; I <<= 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n\
    \        for (ret[u] = 0; t; (--t) &= s) ret[u] += ret[I | (s ^ t)] * ret[t];\n\
    \    for (int I = mid; I < sz; I <<= 1) {\n      auto phi2 = [&](int s, T &x)\
    \ { phi(s | I, x); };\n      phi(I, ret[I]), online_conv_trans(ret.data(), ret.data()\
    \ + I, phi2, I);\n    }\n    return ret;\n  }\n  // F(f) : F[i] is coefficient\
    \ of EGF ( = F^{(i)}(0) )\n  // \"f[\u03C6] = 0\" is required.\n  template <class\
    \ T, class EGF>  // O(n^2 2^n)\n  static inline std::vector<T> composite(const\
    \ std::vector<T> &f,\n                                         const EGF &F) {\n\
    \    const int sz = f.size(), m = __builtin_ctz(sz), sz2 = sz >> 1;\n    assert(sz\
    \ == 1 << m);\n    assert(f.at(0) == 0);\n    std::vector<T> ret(sz);\n    T *h\
    \ = ret.data() + sz;\n    const T *g = f.data();\n    for (int i = 0; i <= m;\
    \ i++) ret[sz - (1 << i)] = F[m - i];\n    int l = 1, ed = std::min(sz, 1 << 11),\
    \ j;\n    for (; l < ed; l <<= 1)\n      for (j = sz2; j >= l; j >>= 1) conv_naive(h\
    \ - j, g + l, h - j - j + l, l);\n    for (; l < sz; l <<= 1)\n      for (j =\
    \ sz2; j >= l; j >>= 1) conv_trans(h - j, g + l, h - j - j + l, l);\n    return\
    \ ret;\n  }\n  // exp(f) : \"f[\u03C6] = 0\" is required.\n  template <class T>\
    \  // O(n^2 2^n)\n  static inline std::vector<T> exp(const std::vector<T> &f)\
    \ {\n    const int sz = f.size();\n    assert(sz == 1 << __builtin_ctz(sz));\n\
    \    assert(f.at(0) == 0);\n    std::vector<T> ret(sz);\n    T *h = ret.data();\n\
    \    const T *g = f.data();\n    int l = 1, ed = std::min(sz, 1 << 11);\n    for\
    \ (h[0] = 1; l < ed; l <<= 1) conv_naive(h, g + l, h + l, l);\n    for (; l <\
    \ sz; l <<= 1) conv_trans(h, g + l, h + l, l);\n    return ret;\n  }\n  // log(f)\
    \ : \"f[\u03C6] = 1\" is required.\n  template <class T>  // O(n^2 2^n)\n  static\
    \ inline std::vector<T> log(std::vector<T> f) {\n    const int sz = f.size(),\
    \ m = __builtin_ctz(sz);\n    assert(sz == 1 << m);\n    assert(f.at(0) == T(1));\n\
    \    static T F[MAX_N + 1] = {0, 1};\n    for (int i = 2; i <= m; i++) F[i] =\
    \ -F[i - 1] * (i - 1);\n    return f[0] = 0, composite(f, F);\n  }\n  // f^k\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> pow(std::vector<T>\
    \ f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
    \    assert(sz == 1 << n);\n    T F[MAX_N + 1] = {1}, pw = 1, bs = f[0];\n   \
    \ int i = 1, ed = std::min<std::uint64_t>(n, k);\n    for (; i <= ed; i++) F[i]\
    \ = F[i - 1] * (k - i + 1);\n    for (auto e = k - --i; e; e >>= 1, bs *= bs)\n\
    \      if (e & 1) pw *= bs;\n    for (; i >= 0; i--, pw *= f[0]) F[i] *= pw;\n\
    \    return f[0] = 0, composite(f, F);\n  }\n\n  // {[X^{[n]}](f^k)/(k!)} for\
    \ k=0,1,...,n\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ egf(std::vector<T> f) {\n    const int sz = f.size(), n = __builtin_ctz(sz),\
    \ md = 1 << 11, sz4 = sz >> 2;\n    assert(sz == 1 << n);\n    int l = sz4, m;\n\
    \    T *in = f.data() + l, *dp = in + l, tmp[sz4], *dp2;\n    for (int s; l >\
    \ md; conv_trans(dp, in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4;\
    \ dp2 = dp + (m - l), m > l; m >>= 1, s = l)\n        for (conv_trans(dp2 + m\
    \ - l, in, tmp, l); s--;) dp2[s] += tmp[s];\n    for (int s; l; conv_naive(dp,\
    \ in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4; dp2 = dp + (m - l),\
    \ m > l; m >>= 1, s = l)\n        for (conv_naive(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s] += tmp[s];\n    std::vector<T> ret(n + 1, 0);\n    for (int i = n + 1;\
    \ --i;) ret[i] = dp[(1 << (n - i)) - 1];\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SetPowerSeries.hpp
  requiredBy:
  - src/Graph/UndirectedGraphSetPowerSeries.hpp
  timestamp: '2022-02-09 02:04:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/subset_convolution.test.cpp
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc213_g.test.cpp
documentation_of: src/Math/SetPowerSeries.hpp
layout: document
redirect_from:
- /library/src/Math/SetPowerSeries.hpp
- /library/src/Math/SetPowerSeries.hpp.html
title: "\u96C6\u5408\u51AA\u7D1A\u6570"
---
