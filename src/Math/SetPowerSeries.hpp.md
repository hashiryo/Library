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
    path: test/aoj/2345.test.cpp
    title: test/aoj/2345.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc199_d.test.cpp
    title: test/atcoder/abc199_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u96C6\u5408\u51AA\u7D1A\u6570"
    links:
    - https://atcoder.jp/contests/abc253/tasks/abc253_h
    - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
    - https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex
    - https://loj.ac/p/2340
    - https://notes.sshwy.name/Math/Subset-Power-Series/#%E5%88%86%E6%B2%BB%E5%8D%B7%E7%A7%AF-1
  bundledCode: "#line 2 \"src/Math/SetPowerSeries.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u96C6\u5408\u51AA\u7D1A\u6570\n * @category \u6570\u5B66\n * @see\n\
    \ * https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex\n\
    \ * @see\n * https://notes.sshwy.name/Math/Subset-Power-Series/#%E5%88%86%E6%B2%BB%E5%8D%B7%E7%A7%AF-1\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n// https://atcoder.jp/contests/abc253/tasks/abc253_h\
    \ (egf)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N = 21>\nstruct SetPowerSeries\
    \ {\n#define SUBSET_REP(i, j, n)                           \\\n  for (int _ =\
    \ (n); _ >>= 1;)                         \\\n    for (int __ = 0, _2 = _ << 1;\
    \ __ < (n); __ += _2) \\\n      for (int j = __, i = j | _, ___ = i; j < ___;\
    \ j++, i++)\n  template <typename T>\n  static inline void ranked_zeta_tr(const\
    \ T f[], T ret[][MAX_N + 1],\n                                    const int sz)\
    \ {\n    for (int S = sz, c; S--;)\n      ret[S][c = __builtin_popcount(S)] =\
    \ f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S, U, sz)\n    for (int d =\
    \ __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n  }\n  template <typename\
    \ T>\n  static inline void conv_na(const T f[], const T g[], T ret[], const int\
    \ sz) {\n    for (int s = sz, t; s--;)\n      for (ret[t = s] = f[s] * g[0]; t;\
    \ --t &= s) ret[s] += f[s ^ t] * g[t];\n  }\n  template <typename T>\n  static\
    \ inline void conv_tr(const T f[], const T g[], T ret[], const int sz) {\n   \
    \ static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1];\n    T tmp[MAX_N\
    \ + 1];\n    ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G, sz);\n    const int\
    \ n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e, bg; S--;) {\n      c =\
    \ __builtin_popcount(S), bg = std::min(2 * c, n);\n      for (d = bg; d >= c;\
    \ d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n          tmp[d] +=\
    \ F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d] = tmp[d];\n\
    \    }\n    SUBSET_REP(S, U, sz)\n    for (int c = __builtin_popcount(U), d =\
    \ std::min(2 * c, n); d > c; d--)\n      F[S][d] -= F[U][d];\n    for (int S =\
    \ sz; S--;) ret[S] = F[S][__builtin_popcount(S)];\n  }\n  template <typename T,\
    \ class F>\n  static inline void onconv_na(const T g[], T ret[], const F &phi,\n\
    \                               const int sz) {\n    for (int s = 1, t; s < sz;\
    \ phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; --t &= s) ret[s] += ret[s\
    \ ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline void onconv_tr(const\
    \ T g[], T ret[], const F &phi,\n                               const int sz)\
    \ {\n    static T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1 << MAX_N];\n    const\
    \ int n = __builtin_ctz(sz);\n    ranked_zeta_tr(g, G, sz), std::fill_n(mat[0],\
    \ sz, ret[0]);\n    for (int d = n; d; d--) std::fill_n(mat[d], sz, 0);\n    for\
    \ (int I = sz; I >>= 1;) phi(I, mat[1][I] = ret[0] * g[I]);\n    for (int d =\
    \ 2; d <= n; d++) {\n      SUBSET_REP(S, U, sz) mat[d - 1][S] += mat[d - 1][U];\n\
    \      for (int S = sz; S--;)\n        if (int c = __builtin_popcount(S); c <=\
    \ d && d <= 2 * c)\n          for (int e = d; e--;) mat[d][S] += mat[e][S] * G[S][d\
    \ - e];\n      SUBSET_REP(S, U, sz) mat[d][S] -= mat[d][U];\n      for (int S\
    \ = sz; S--;)\n        __builtin_popcount(S) == d ? phi(S, mat[d][S]), 0 : (mat[d][S]\
    \ = 0);\n    }\n    for (int S = sz; --S;) ret[S] = mat[__builtin_popcount(S)][S];\n\
    \  }\n\n public:\n  template <typename T>  // O(n 2^n)\n  static inline void subset_sum(std::vector<T>\
    \ &f) {\n    SUBSET_REP(S, U, f.size()) f[S] += f[U];\n  }\n  template <typename\
    \ T>  // O(n 2^n)\n  static inline void subset_sum_inv(std::vector<T> &f) {\n\
    \    SUBSET_REP(S, U, f.size()) f[S] -= f[U];\n  }\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> convolve(const std::vector<T> &f,\n   \
    \                                     const std::vector<T> &g) {\n    const int\
    \ sz = f.size(), n = __builtin_ctz(sz);\n    std::vector<T> ret(sz);\n    if (n\
    \ <= 10) return conv_na(f.data(), g.data(), ret.data(), sz), ret;\n    assert(sz\
    \ == 1 << n && sz == g.size());\n    return conv_tr(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n  template\
    \ <class T, class F = void (*)(int, T &)>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ online_convolve(\n      const std::vector<T> &g, T init, const F &phi = [](int,\
    \ T &) {}) {\n    const int sz = g.size(), n = __builtin_ctz(sz);\n    std::vector<T>\
    \ ret(sz);\n    ret[0] = init;\n    if (n <= 12) return onconv_na(g.data(), ret.data(),\
    \ phi, sz), ret;\n    assert(sz == 1 << n);\n    return onconv_tr(g.data(), ret.data(),\
    \ phi, sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T)\
    \ as binary numbers) } f(T)f(S/T) )\n  template <class T, class F>  // O(n^2 2^n)\n\
    \  static inline std::vector<T> online_convolve2(int sz, const F &phi) {\n   \
    \ assert(__builtin_popcount(sz) == 1);\n    int I = 1, ed = std::min(1 << 13,\
    \ sz);\n    std::vector<T> ret(sz, 0);\n    for (int s, t, u = 1; I < ed; I <<=\
    \ 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n        for\
    \ (ret[u] = 0; t; --t &= s) ret[u] += ret[u ^ t] * ret[t];\n    T *h = ret.data();\n\
    \    for (; I < sz; I <<= 1)\n      phi(I, ret[I]), onconv_tr(\n             \
    \             h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n    return ret;\n\
    \  }\n  // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n  // \"f[\u2205\
    ] = 0\" is required.\n  template <class T, class EGF>  // O(n^2 2^n)\n  static\
    \ inline std::vector<T> composite(const std::vector<T> &f,\n                 \
    \                        const EGF &F) {\n    const int sz = f.size(), m = __builtin_ctz(sz),\
    \ sz2 = sz >> 1;\n    assert(sz == 1 << m), assert(f.at(0) == 0);\n    std::vector<T>\
    \ ret(sz);\n    T *h = ret.data() + sz;\n    const T *g = f.data();\n    for (int\
    \ i = 0; i <= m; i++) ret[sz - (1 << i)] = F[m - i];\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11), j;\n    for (; l < ed; l <<= 1)\n      for (j = sz2; j >= l; j >>=\
    \ 1) conv_na(h - j, g + l, h - j - j + l, l);\n    for (; l < sz; l <<= 1)\n \
    \     for (j = sz2; j >= l; j >>= 1) conv_tr(h - j, g + l, h - j - j + l, l);\n\
    \    return ret;\n  }\n  // exp(f) : \"f[\u2205] = 0\" is required.\n  template\
    \ <class T>  // O(n^2 2^n)\n  static inline std::vector<T> exp(const std::vector<T>\
    \ &f) {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == 0);\n    T h[sz];\n    const T *g = f.data();\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11);\n    for (h[0] = 1; l < ed; l <<= 1) conv_na(h, g + l, h + l, l);\n\
    \    for (; l < sz; l <<= 1) conv_tr(h, g + l, h + l, l);\n    return std::vector<T>(h,\
    \ h + sz);\n  }\n  // log(f) : \"f[\u2205] = 1\" is required.\n  template <class\
    \ T>  // O(n^2 2^n)\n  static inline std::vector<T> log(const std::vector<T> &f)\
    \ {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == T(1));\n    int I = 2, ed = std::min(sz, 1 << 13);\n    T h[sz];\n    for\
    \ (std::copy_n(f.begin(), ed, h); I < ed; I <<= 1)\n      for (int s = 1, u =\
    \ s | I; s < I; s++, u++)\n        for (int t = s; t; --t &= s) h[u] -= h[u ^\
    \ t] * f[t];\n    const T *g = f.data();\n    for (; I < sz; I <<= 1)\n      h[I]\
    \ = g[I], onconv_tr(\n                       g, h + I, [&](int s, T &x) { x =\
    \ g[I | s] - x; }, I);\n    return h[0] = 0, std::vector<T>(h, h + sz);\n  }\n\
    \  // f^k\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
    \    assert(sz == 1 << n);\n    T F[MAX_N + 1] = {1}, pw = 1, bs = f[0];\n   \
    \ int i = 1, ed = std::min<std::uint64_t>(n, k);\n    for (; i <= ed; i++) F[i]\
    \ = F[i - 1] * (k - i + 1);\n    for (auto e = k - --i; e; e >>= 1, bs *= bs)\n\
    \      if (e & 1) pw *= bs;\n    for (; i >= 0; i--, pw *= f[0]) F[i] *= pw;\n\
    \    return f[0] = 0, composite(f, F);\n  }\n  // {[X^{[n]}](f^k)/(k!)} for k=0,1,...,n\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n    const int sz = f.size(), n = __builtin_ctz(sz), md = 1 << 11, sz4\
    \ = sz >> 2;\n    assert(sz == 1 << n);\n    if (n == 1) return {0, f[1]};\n \
    \   int l = sz4, m;\n    T *in = f.data() + l, *dp = in + l, tmp[sz4], *dp2;\n\
    \    for (int s; l > md; conv_tr(dp, in, dp, l), in -= (l >>= 1))\n      for (s\
    \ = l, m = sz4; dp2 = dp + (m - l), m > l; m >>= 1, s = l)\n        for (conv_tr(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s] += tmp[s];\n    for (int s; l; conv_na(dp,\
    \ in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4; dp2 = dp + (m - l),\
    \ m > l; m >>= 1, s = l)\n        for (conv_na(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s] += tmp[s];\n    std::vector<T> ret(n + 1, 0);\n    for (int i = n + 1;\
    \ --i;) ret[i] = dp[(1 << (n - i)) - 1];\n    return ret;\n  }\n#undef SUBSET_REP\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u96C6\u5408\u51AA\
    \u7D1A\u6570\n * @category \u6570\u5B66\n * @see\n * https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex\n\
    \ * @see\n * https://notes.sshwy.name/Math/Subset-Power-Series/#%E5%88%86%E6%B2%BB%E5%8D%B7%E7%A7%AF-1\n\
    \ */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h\n\
    //                        (\u30AA\u30F3\u30E9\u30A4\u30F3\u7573\u8FBC\u307F2 or\
    \ \u5408\u6210 1-\u221A(1-2f))\n// https://loj.ac/p/2340 (\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u7573\u8FBC\u307F)\n// https://atcoder.jp/contests/abc253/tasks/abc253_h\
    \ (egf)\n\n// BEGIN CUT HERE\n\ntemplate <unsigned short MAX_N = 21>\nstruct SetPowerSeries\
    \ {\n#define SUBSET_REP(i, j, n)                           \\\n  for (int _ =\
    \ (n); _ >>= 1;)                         \\\n    for (int __ = 0, _2 = _ << 1;\
    \ __ < (n); __ += _2) \\\n      for (int j = __, i = j | _, ___ = i; j < ___;\
    \ j++, i++)\n  template <typename T>\n  static inline void ranked_zeta_tr(const\
    \ T f[], T ret[][MAX_N + 1],\n                                    const int sz)\
    \ {\n    for (int S = sz, c; S--;)\n      ret[S][c = __builtin_popcount(S)] =\
    \ f[S], std::fill_n(ret[S], c, 0);\n    SUBSET_REP(S, U, sz)\n    for (int d =\
    \ __builtin_popcount(S); d--;) ret[S][d] += ret[U][d];\n  }\n  template <typename\
    \ T>\n  static inline void conv_na(const T f[], const T g[], T ret[], const int\
    \ sz) {\n    for (int s = sz, t; s--;)\n      for (ret[t = s] = f[s] * g[0]; t;\
    \ --t &= s) ret[s] += f[s ^ t] * g[t];\n  }\n  template <typename T>\n  static\
    \ inline void conv_tr(const T f[], const T g[], T ret[], const int sz) {\n   \
    \ static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1];\n    T tmp[MAX_N\
    \ + 1];\n    ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G, sz);\n    const int\
    \ n = __builtin_ctz(sz);\n    for (int S = sz, c, d, e, bg; S--;) {\n      c =\
    \ __builtin_popcount(S), bg = std::min(2 * c, n);\n      for (d = bg; d >= c;\
    \ d--)\n        for (tmp[d] = 0, e = d - c; e <= c; e++)\n          tmp[d] +=\
    \ F[S][e] * G[S][d - e];\n      for (d = bg; d >= c; d--) F[S][d] = tmp[d];\n\
    \    }\n    SUBSET_REP(S, U, sz)\n    for (int c = __builtin_popcount(U), d =\
    \ std::min(2 * c, n); d > c; d--)\n      F[S][d] -= F[U][d];\n    for (int S =\
    \ sz; S--;) ret[S] = F[S][__builtin_popcount(S)];\n  }\n  template <typename T,\
    \ class F>\n  static inline void onconv_na(const T g[], T ret[], const F &phi,\n\
    \                               const int sz) {\n    for (int s = 1, t; s < sz;\
    \ phi(s, ret[s]), s++)\n      for (ret[t = s] = 0; t; --t &= s) ret[s] += ret[s\
    \ ^ t] * g[t];\n  }\n  template <typename T, class F>\n  static inline void onconv_tr(const\
    \ T g[], T ret[], const F &phi,\n                               const int sz)\
    \ {\n    static T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1 << MAX_N];\n    const\
    \ int n = __builtin_ctz(sz);\n    ranked_zeta_tr(g, G, sz), std::fill_n(mat[0],\
    \ sz, ret[0]);\n    for (int d = n; d; d--) std::fill_n(mat[d], sz, 0);\n    for\
    \ (int I = sz; I >>= 1;) phi(I, mat[1][I] = ret[0] * g[I]);\n    for (int d =\
    \ 2; d <= n; d++) {\n      SUBSET_REP(S, U, sz) mat[d - 1][S] += mat[d - 1][U];\n\
    \      for (int S = sz; S--;)\n        if (int c = __builtin_popcount(S); c <=\
    \ d && d <= 2 * c)\n          for (int e = d; e--;) mat[d][S] += mat[e][S] * G[S][d\
    \ - e];\n      SUBSET_REP(S, U, sz) mat[d][S] -= mat[d][U];\n      for (int S\
    \ = sz; S--;)\n        __builtin_popcount(S) == d ? phi(S, mat[d][S]), 0 : (mat[d][S]\
    \ = 0);\n    }\n    for (int S = sz; --S;) ret[S] = mat[__builtin_popcount(S)][S];\n\
    \  }\n\n public:\n  template <typename T>  // O(n 2^n)\n  static inline void subset_sum(std::vector<T>\
    \ &f) {\n    SUBSET_REP(S, U, f.size()) f[S] += f[U];\n  }\n  template <typename\
    \ T>  // O(n 2^n)\n  static inline void subset_sum_inv(std::vector<T> &f) {\n\
    \    SUBSET_REP(S, U, f.size()) f[S] -= f[U];\n  }\n  template <class T>  // O(n^2\
    \ 2^n)\n  static inline std::vector<T> convolve(const std::vector<T> &f,\n   \
    \                                     const std::vector<T> &g) {\n    const int\
    \ sz = f.size(), n = __builtin_ctz(sz);\n    std::vector<T> ret(sz);\n    if (n\
    \ <= 10) return conv_na(f.data(), g.data(), ret.data(), sz), ret;\n    assert(sz\
    \ == 1 << n && sz == g.size());\n    return conv_tr(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n  template\
    \ <class T, class F = void (*)(int, T &)>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ online_convolve(\n      const std::vector<T> &g, T init, const F &phi = [](int,\
    \ T &) {}) {\n    const int sz = g.size(), n = __builtin_ctz(sz);\n    std::vector<T>\
    \ ret(sz);\n    ret[0] = init;\n    if (n <= 12) return onconv_na(g.data(), ret.data(),\
    \ phi, sz), ret;\n    assert(sz == 1 << n);\n    return onconv_tr(g.data(), ret.data(),\
    \ phi, sz), ret;\n  }\n  // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T)\
    \ as binary numbers) } f(T)f(S/T) )\n  template <class T, class F>  // O(n^2 2^n)\n\
    \  static inline std::vector<T> online_convolve2(int sz, const F &phi) {\n   \
    \ assert(__builtin_popcount(sz) == 1);\n    int I = 1, ed = std::min(1 << 13,\
    \ sz);\n    std::vector<T> ret(sz, 0);\n    for (int s, t, u = 1; I < ed; I <<=\
    \ 1)\n      for (t = s = 0; s < I; phi(u, ret[u]), t = ++s, u++)\n        for\
    \ (ret[u] = 0; t; --t &= s) ret[u] += ret[u ^ t] * ret[t];\n    T *h = ret.data();\n\
    \    for (; I < sz; I <<= 1)\n      phi(I, ret[I]), onconv_tr(\n             \
    \             h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n    return ret;\n\
    \  }\n  // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n  // \"f[\u2205\
    ] = 0\" is required.\n  template <class T, class EGF>  // O(n^2 2^n)\n  static\
    \ inline std::vector<T> composite(const std::vector<T> &f,\n                 \
    \                        const EGF &F) {\n    const int sz = f.size(), m = __builtin_ctz(sz),\
    \ sz2 = sz >> 1;\n    assert(sz == 1 << m), assert(f.at(0) == 0);\n    std::vector<T>\
    \ ret(sz);\n    T *h = ret.data() + sz;\n    const T *g = f.data();\n    for (int\
    \ i = 0; i <= m; i++) ret[sz - (1 << i)] = F[m - i];\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11), j;\n    for (; l < ed; l <<= 1)\n      for (j = sz2; j >= l; j >>=\
    \ 1) conv_na(h - j, g + l, h - j - j + l, l);\n    for (; l < sz; l <<= 1)\n \
    \     for (j = sz2; j >= l; j >>= 1) conv_tr(h - j, g + l, h - j - j + l, l);\n\
    \    return ret;\n  }\n  // exp(f) : \"f[\u2205] = 0\" is required.\n  template\
    \ <class T>  // O(n^2 2^n)\n  static inline std::vector<T> exp(const std::vector<T>\
    \ &f) {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == 0);\n    T h[sz];\n    const T *g = f.data();\n    int l = 1, ed = std::min(sz,\
    \ 1 << 11);\n    for (h[0] = 1; l < ed; l <<= 1) conv_na(h, g + l, h + l, l);\n\
    \    for (; l < sz; l <<= 1) conv_tr(h, g + l, h + l, l);\n    return std::vector<T>(h,\
    \ h + sz);\n  }\n  // log(f) : \"f[\u2205] = 1\" is required.\n  template <class\
    \ T>  // O(n^2 2^n)\n  static inline std::vector<T> log(const std::vector<T> &f)\
    \ {\n    const int sz = f.size();\n    assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == T(1));\n    int I = 2, ed = std::min(sz, 1 << 13);\n    T h[sz];\n    for\
    \ (std::copy_n(f.begin(), ed, h); I < ed; I <<= 1)\n      for (int s = 1, u =\
    \ s | I; s < I; s++, u++)\n        for (int t = s; t; --t &= s) h[u] -= h[u ^\
    \ t] * f[t];\n    const T *g = f.data();\n    for (; I < sz; I <<= 1)\n      h[I]\
    \ = g[I], onconv_tr(\n                       g, h + I, [&](int s, T &x) { x =\
    \ g[I | s] - x; }, I);\n    return h[0] = 0, std::vector<T>(h, h + sz);\n  }\n\
    \  // f^k\n  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n    const int sz = f.size(), n = __builtin_ctz(sz);\n\
    \    assert(sz == 1 << n);\n    T F[MAX_N + 1] = {1}, pw = 1, bs = f[0];\n   \
    \ int i = 1, ed = std::min<std::uint64_t>(n, k);\n    for (; i <= ed; i++) F[i]\
    \ = F[i - 1] * (k - i + 1);\n    for (auto e = k - --i; e; e >>= 1, bs *= bs)\n\
    \      if (e & 1) pw *= bs;\n    for (; i >= 0; i--, pw *= f[0]) F[i] *= pw;\n\
    \    return f[0] = 0, composite(f, F);\n  }\n  // {[X^{[n]}](f^k)/(k!)} for k=0,1,...,n\n\
    \  template <class T>  // O(n^2 2^n)\n  static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n    const int sz = f.size(), n = __builtin_ctz(sz), md = 1 << 11, sz4\
    \ = sz >> 2;\n    assert(sz == 1 << n);\n    if (n == 1) return {0, f[1]};\n \
    \   int l = sz4, m;\n    T *in = f.data() + l, *dp = in + l, tmp[sz4], *dp2;\n\
    \    for (int s; l > md; conv_tr(dp, in, dp, l), in -= (l >>= 1))\n      for (s\
    \ = l, m = sz4; dp2 = dp + (m - l), m > l; m >>= 1, s = l)\n        for (conv_tr(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s] += tmp[s];\n    for (int s; l; conv_na(dp,\
    \ in, dp, l), in -= (l >>= 1))\n      for (s = l, m = sz4; dp2 = dp + (m - l),\
    \ m > l; m >>= 1, s = l)\n        for (conv_na(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s] += tmp[s];\n    std::vector<T> ret(n + 1, 0);\n    for (int i = n + 1;\
    \ --i;) ret[i] = dp[(1 << (n - i)) - 1];\n    return ret;\n  }\n#undef SUBSET_REP\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SetPowerSeries.hpp
  requiredBy:
  - src/Graph/UndirectedGraphSetPowerSeries.hpp
  timestamp: '2022-10-10 20:30:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2345.test.cpp
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc199_d.test.cpp
  - test/atcoder/abc213_g.test.cpp
  - test/yosupo/subset_convolution.test.cpp
documentation_of: src/Math/SetPowerSeries.hpp
layout: document
redirect_from:
- /library/src/Math/SetPowerSeries.hpp
- /library/src/Math/SetPowerSeries.hpp.html
title: "\u96C6\u5408\u51AA\u7D1A\u6570"
---
