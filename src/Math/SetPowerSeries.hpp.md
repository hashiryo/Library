---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
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
  - icon: ':x:'
    path: test/atcoder/abc213_g.test.cpp
    title: test/atcoder/abc213_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc105_f.test.cpp
    title: test/atcoder/arc105_f.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_composite_set_power_series.test.cpp
    title: test/yosupo/polynomial_composite_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/SetPowerSeries.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#include <cassert>\ntemplate <unsigned short MAX_N= 21> struct SetPowerSeries\
    \ {\n#define SUBSET_REP(i, j, n) \\\n for (int _= (n); _>>= 1;) \\\n  for (int\
    \ __= 0, _2= _ << 1; __ < (n); __+= _2) \\\n   for (int j= __, i= j | _, ___=\
    \ i; j < ___; ++j, ++i)\n template <typename T> static inline void ranked_zeta_tr(const\
    \ T f[], T ret[][MAX_N + 1], const int sz) {\n  for (int S= sz, c; S--;) ret[S][c=\
    \ __builtin_popcount(S)]= f[S], std::fill_n(ret[S], c, 0);\n  SUBSET_REP(S, U,\
    \ sz)\n  for (int d= __builtin_popcount(S); d--;) ret[S][d]+= ret[U][d];\n }\n\
    \ template <typename T> static inline void conv_na(const T f[], const T g[], T\
    \ ret[], const int sz) {\n  for (int s= sz, t; s--;)\n   for (ret[t= s]= f[s]\
    \ * g[0]; t; --t&= s) ret[s]+= f[s ^ t] * g[t];\n }\n template <typename T> static\
    \ inline void conv_tr(const T f[], const T g[], T ret[], const int sz) {\n  static\
    \ T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1];\n  T tmp[MAX_N + 1];\n\
    \  ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G, sz);\n  const int n= __builtin_ctz(sz);\n\
    \  for (int S= sz, c, d, e, bg; S--;) {\n   c= __builtin_popcount(S), bg= std::min(2\
    \ * c, n);\n   for (d= bg; d >= c; d--)\n    for (tmp[d]= 0, e= d - c; e <= c;\
    \ ++e) tmp[d]+= F[S][e] * G[S][d - e];\n   for (d= bg; d >= c; d--) F[S][d]= tmp[d];\n\
    \  }\n  SUBSET_REP(S, U, sz)\n  for (int c= __builtin_popcount(U), d= std::min(2\
    \ * c, n); d > c; d--) F[S][d]-= F[U][d];\n  for (int S= sz; S--;) ret[S]= F[S][__builtin_popcount(S)];\n\
    \ }\n template <typename T, class F> static inline void onconv_na(const T g[],\
    \ T ret[], const F &phi, const int sz) {\n  for (int s= 1, t; s < sz; phi(s, ret[s]),\
    \ ++s)\n   for (ret[t= s]= 0; t; --t&= s) ret[s]+= ret[s ^ t] * g[t];\n }\n template\
    \ <typename T, class F> static inline void onconv_tr(const T g[], T ret[], const\
    \ F &phi, const int sz) {\n  static T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1\
    \ << MAX_N];\n  const int n= __builtin_ctz(sz);\n  ranked_zeta_tr(g, G, sz), std::fill_n(mat[0],\
    \ sz, ret[0]);\n  for (int d= n; d; d--) std::fill_n(mat[d], sz, 0);\n  for (int\
    \ I= sz; I>>= 1;) phi(I, mat[1][I]= ret[0] * g[I]);\n  for (int d= 2; d <= n;\
    \ ++d) {\n   SUBSET_REP(S, U, sz) mat[d - 1][S]+= mat[d - 1][U];\n   for (int\
    \ S= sz; S--;)\n    if (int c= __builtin_popcount(S); c <= d && d <= 2 * c)\n\
    \     for (int e= d; e--;) mat[d][S]+= mat[e][S] * G[S][d - e];\n   SUBSET_REP(S,\
    \ U, sz) mat[d][S]-= mat[d][U];\n   for (int S= sz; S--;) __builtin_popcount(S)\
    \ == d ? phi(S, mat[d][S]), 0 : (mat[d][S]= 0);\n  }\n  for (int S= sz; --S;)\
    \ ret[S]= mat[__builtin_popcount(S)][S];\n }\npublic:\n template <typename T>\
    \  // O(n 2^n)\n static inline void subset_sum(std::vector<T> &f) {\n  SUBSET_REP(S,\
    \ U, f.size()) f[S]+= f[U];\n }\n template <typename T>  // O(n 2^n)\n static\
    \ inline void subset_sum_inv(std::vector<T> &f) {\n  SUBSET_REP(S, U, f.size())\
    \ f[S]-= f[U];\n }\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ convolve(const std::vector<T> &f, const std::vector<T> &g) {\n  const int sz=\
    \ f.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  if (n <= 10) return\
    \ conv_na(f.data(), g.data(), ret.data(), sz), ret;\n  assert(sz == 1 << n &&\
    \ sz == g.size());\n  return conv_tr(f.data(), g.data(), ret.data(), sz), ret;\n\
    \ }\n // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n template <class T,\
    \ class F= void (*)(int, T &)>  // O(n^2 2^n)\n static inline std::vector<T> semi_relaxed_convolve(\n\
    \     const std::vector<T> &g, T init, const F &phi= [](int, T &) {}) {\n  const\
    \ int sz= g.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  ret[0]=\
    \ init;\n  if (n <= 12) return onconv_na(g.data(), ret.data(), phi, sz), ret;\n\
    \  assert(sz == 1 << n);\n  return onconv_tr(g.data(), ret.data(), phi, sz), ret;\n\
    \ }\n // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T) as binary numbers)\
    \ } f(T)f(S/T) )\n template <class T, class F>  // O(n^2 2^n)\n static inline\
    \ std::vector<T> self_relaxed_convolve(int n, const F &phi) {\n  assert(__builtin_popcount(n)\
    \ == 1);\n  int I= 1, ed= std::min(1 << 13, n);\n  std::vector<T> ret(n, 0);\n\
    \  for (int s, t, u= 1; I < ed; I<<= 1)\n   for (t= s= 0; s < I; phi(u, ret[u]),\
    \ t= ++s, ++u)\n    for (ret[u]= 0; t; --t&= s) ret[u]+= ret[u ^ t] * ret[t];\n\
    \  T *h= ret.data();\n  for (; I < n; I<<= 1)\n   phi(I, ret[I]), onconv_tr(\n\
    \                       h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n \
    \ return ret;\n }\n // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n //\
    \ \"f[\u2205] = 0\" is required.\n template <class T, class EGF>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> composite(const std::vector<T> &f, const EGF &F)\
    \ {\n  const int sz= f.size(), m= __builtin_ctz(sz), sz2= sz >> 1;\n  assert(sz\
    \ == 1 << m), assert(f.at(0) == 0);\n  std::vector<T> ret(sz);\n  T *h= ret.data()\
    \ + sz;\n  const T *g= f.data();\n  for (int i= 0; i <= m; ++i) ret[sz - (1 <<\
    \ i)]= F[m - i];\n  int l= 1, ed= std::min(sz, 1 << 11), j;\n  for (; l < ed;\
    \ l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_na(h - j, g + l, h - j - j + l,\
    \ l);\n  for (; l < sz; l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_tr(h - j,\
    \ g + l, h - j - j + l, l);\n  return ret;\n }\n // exp(f) : \"f[\u2205] = 0\"\
    \ is required.\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ exp(const std::vector<T> &f) {\n  const int sz= f.size();\n  assert(!(sz & (sz\
    \ - 1))), assert(f.at(0) == 0);\n  T h[sz];\n  const T *g= f.data();\n  int l=\
    \ 1, ed= std::min(sz, 1 << 11);\n  for (h[0]= 1; l < ed; l<<= 1) conv_na(h, g\
    \ + l, h + l, l);\n  for (; l < sz; l<<= 1) conv_tr(h, g + l, h + l, l);\n  return\
    \ std::vector<T>(h, h + sz);\n }\n // log(f) : \"f[\u2205] = 1\" is required.\n\
    \ template <class T>  // O(n^2 2^n)\n static inline std::vector<T> log(const std::vector<T>\
    \ &f) {\n  const int sz= f.size();\n  assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == T(1));\n  int I= 2, ed= std::min(sz, 1 << 13);\n  T h[sz];\n  const T *g=\
    \ f.data();\n  for (std::copy_n(g, ed, h); I < ed; I<<= 1)\n   for (int s= 1,\
    \ u= s | I; s < I; ++s, ++u)\n    for (int t= s; t; --t&= s) h[u]-= h[u ^ t] *\
    \ f[t];\n  for (; I < sz; I<<= 1)\n   h[I]= g[I], onconv_tr(\n               \
    \    g, h + I, [&](int s, T &x) { x= g[I | s] - x; }, I);\n  return h[0]= 0, std::vector<T>(h,\
    \ h + sz);\n }\n // f^k\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n  const int sz= f.size(), n= __builtin_ctz(sz);\n\
    \  assert(sz == 1 << n);\n  T F[MAX_N + 1]= {1}, pw= 1, bs= f[0];\n  int i= 1,\
    \ ed= std::min<std::uint64_t>(n, k);\n  for (; i <= ed; ++i) F[i]= F[i - 1] *\
    \ (k - i + 1);\n  for (auto e= k - --i; e; e>>= 1, bs*= bs)\n   if (e & 1) pw*=\
    \ bs;\n  for (; i >= 0; --i, pw*= f[0]) F[i]*= pw;\n  return f[0]= 0, composite(f,\
    \ F);\n }\n // P(f), P is polynomial\n template <class T> static inline std::vector<T>\
    \ polynomial_composite(std::vector<T> f, std::vector<T> P) {\n  const int sz=\
    \ f.size(), n= __builtin_ctz(sz);\n  assert(sz == 1 << n);\n  T F[MAX_N + 1]=\
    \ {};\n  int e= P.size();\n  if (!e) return std::vector<T>(sz);\n  for (int j=\
    \ 0;; ++j, --e) {\n   for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n   if (j ==\
    \ n || e == 1) break;\n   for (int i= 1; i < e; ++i) P[i - 1]= P[i] * i;\n  }\n\
    \  return f[0]= 0, composite(f, F);\n }\n // {[X^{[n]}]f^k/k!} for k=0,1,...,n\n\
    \ template <class T>  // O(n^2 2^n)\n static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n  static constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz),\
    \ sz4= sz >> 2;\n  assert(sz == 1 << n);\n  if (n == 1) return {0, f[1]};\n  int\
    \ l= sz4, m;\n  T *in= f.data() + l, *dp= in + l, tmp[sz4 / 2], *dp2;\n  for (int\
    \ s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz4; dp2= dp +\
    \ (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>= 1))\n\
    \   for (m= sz4; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1, 0);\n\
    \  for (int i= n + 1; --i;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    \ // {[X^{[n]}]g*f^k/k!} for k=0,1,...,n\n template <class T>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> egf(const std::vector<T> &f, std::vector<T> g)\
    \ {\n  static constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz),\
    \ sz2= sz >> 1, sz4= sz >> 2;\n  assert(sz == 1 << n), assert(sz == (int)g.size());\n\
    \  if (n == 1) return {g[1], f[1] * g[0] + f[0] * g[1]};\n  int l= sz2, m;\n \
    \ const T *in= f.data() + sz2;\n  T *dp= g.data(), tmp[sz2 / 2], *dp2;\n  for\
    \ (int s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz2; dp2=\
    \ dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l);\
    \ s--;) dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>=\
    \ 1))\n   for (m= sz2; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1);\n\
    \  for (int i= n + 1; i--;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    #undef SUBSET_REP\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <cassert>\n\
    template <unsigned short MAX_N= 21> struct SetPowerSeries {\n#define SUBSET_REP(i,\
    \ j, n) \\\n for (int _= (n); _>>= 1;) \\\n  for (int __= 0, _2= _ << 1; __ <\
    \ (n); __+= _2) \\\n   for (int j= __, i= j | _, ___= i; j < ___; ++j, ++i)\n\
    \ template <typename T> static inline void ranked_zeta_tr(const T f[], T ret[][MAX_N\
    \ + 1], const int sz) {\n  for (int S= sz, c; S--;) ret[S][c= __builtin_popcount(S)]=\
    \ f[S], std::fill_n(ret[S], c, 0);\n  SUBSET_REP(S, U, sz)\n  for (int d= __builtin_popcount(S);\
    \ d--;) ret[S][d]+= ret[U][d];\n }\n template <typename T> static inline void\
    \ conv_na(const T f[], const T g[], T ret[], const int sz) {\n  for (int s= sz,\
    \ t; s--;)\n   for (ret[t= s]= f[s] * g[0]; t; --t&= s) ret[s]+= f[s ^ t] * g[t];\n\
    \ }\n template <typename T> static inline void conv_tr(const T f[], const T g[],\
    \ T ret[], const int sz) {\n  static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N\
    \ + 1];\n  T tmp[MAX_N + 1];\n  ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G,\
    \ sz);\n  const int n= __builtin_ctz(sz);\n  for (int S= sz, c, d, e, bg; S--;)\
    \ {\n   c= __builtin_popcount(S), bg= std::min(2 * c, n);\n   for (d= bg; d >=\
    \ c; d--)\n    for (tmp[d]= 0, e= d - c; e <= c; ++e) tmp[d]+= F[S][e] * G[S][d\
    \ - e];\n   for (d= bg; d >= c; d--) F[S][d]= tmp[d];\n  }\n  SUBSET_REP(S, U,\
    \ sz)\n  for (int c= __builtin_popcount(U), d= std::min(2 * c, n); d > c; d--)\
    \ F[S][d]-= F[U][d];\n  for (int S= sz; S--;) ret[S]= F[S][__builtin_popcount(S)];\n\
    \ }\n template <typename T, class F> static inline void onconv_na(const T g[],\
    \ T ret[], const F &phi, const int sz) {\n  for (int s= 1, t; s < sz; phi(s, ret[s]),\
    \ ++s)\n   for (ret[t= s]= 0; t; --t&= s) ret[s]+= ret[s ^ t] * g[t];\n }\n template\
    \ <typename T, class F> static inline void onconv_tr(const T g[], T ret[], const\
    \ F &phi, const int sz) {\n  static T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1\
    \ << MAX_N];\n  const int n= __builtin_ctz(sz);\n  ranked_zeta_tr(g, G, sz), std::fill_n(mat[0],\
    \ sz, ret[0]);\n  for (int d= n; d; d--) std::fill_n(mat[d], sz, 0);\n  for (int\
    \ I= sz; I>>= 1;) phi(I, mat[1][I]= ret[0] * g[I]);\n  for (int d= 2; d <= n;\
    \ ++d) {\n   SUBSET_REP(S, U, sz) mat[d - 1][S]+= mat[d - 1][U];\n   for (int\
    \ S= sz; S--;)\n    if (int c= __builtin_popcount(S); c <= d && d <= 2 * c)\n\
    \     for (int e= d; e--;) mat[d][S]+= mat[e][S] * G[S][d - e];\n   SUBSET_REP(S,\
    \ U, sz) mat[d][S]-= mat[d][U];\n   for (int S= sz; S--;) __builtin_popcount(S)\
    \ == d ? phi(S, mat[d][S]), 0 : (mat[d][S]= 0);\n  }\n  for (int S= sz; --S;)\
    \ ret[S]= mat[__builtin_popcount(S)][S];\n }\npublic:\n template <typename T>\
    \  // O(n 2^n)\n static inline void subset_sum(std::vector<T> &f) {\n  SUBSET_REP(S,\
    \ U, f.size()) f[S]+= f[U];\n }\n template <typename T>  // O(n 2^n)\n static\
    \ inline void subset_sum_inv(std::vector<T> &f) {\n  SUBSET_REP(S, U, f.size())\
    \ f[S]-= f[U];\n }\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ convolve(const std::vector<T> &f, const std::vector<T> &g) {\n  const int sz=\
    \ f.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  if (n <= 10) return\
    \ conv_na(f.data(), g.data(), ret.data(), sz), ret;\n  assert(sz == 1 << n &&\
    \ sz == g.size());\n  return conv_tr(f.data(), g.data(), ret.data(), sz), ret;\n\
    \ }\n // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n template <class T,\
    \ class F= void (*)(int, T &)>  // O(n^2 2^n)\n static inline std::vector<T> semi_relaxed_convolve(\n\
    \     const std::vector<T> &g, T init, const F &phi= [](int, T &) {}) {\n  const\
    \ int sz= g.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  ret[0]=\
    \ init;\n  if (n <= 12) return onconv_na(g.data(), ret.data(), phi, sz), ret;\n\
    \  assert(sz == 1 << n);\n  return onconv_tr(g.data(), ret.data(), phi, sz), ret;\n\
    \ }\n // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T) as binary numbers)\
    \ } f(T)f(S/T) )\n template <class T, class F>  // O(n^2 2^n)\n static inline\
    \ std::vector<T> self_relaxed_convolve(int n, const F &phi) {\n  assert(__builtin_popcount(n)\
    \ == 1);\n  int I= 1, ed= std::min(1 << 13, n);\n  std::vector<T> ret(n, 0);\n\
    \  for (int s, t, u= 1; I < ed; I<<= 1)\n   for (t= s= 0; s < I; phi(u, ret[u]),\
    \ t= ++s, ++u)\n    for (ret[u]= 0; t; --t&= s) ret[u]+= ret[u ^ t] * ret[t];\n\
    \  T *h= ret.data();\n  for (; I < n; I<<= 1)\n   phi(I, ret[I]), onconv_tr(\n\
    \                       h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n \
    \ return ret;\n }\n // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n //\
    \ \"f[\u2205] = 0\" is required.\n template <class T, class EGF>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> composite(const std::vector<T> &f, const EGF &F)\
    \ {\n  const int sz= f.size(), m= __builtin_ctz(sz), sz2= sz >> 1;\n  assert(sz\
    \ == 1 << m), assert(f.at(0) == 0);\n  std::vector<T> ret(sz);\n  T *h= ret.data()\
    \ + sz;\n  const T *g= f.data();\n  for (int i= 0; i <= m; ++i) ret[sz - (1 <<\
    \ i)]= F[m - i];\n  int l= 1, ed= std::min(sz, 1 << 11), j;\n  for (; l < ed;\
    \ l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_na(h - j, g + l, h - j - j + l,\
    \ l);\n  for (; l < sz; l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_tr(h - j,\
    \ g + l, h - j - j + l, l);\n  return ret;\n }\n // exp(f) : \"f[\u2205] = 0\"\
    \ is required.\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ exp(const std::vector<T> &f) {\n  const int sz= f.size();\n  assert(!(sz & (sz\
    \ - 1))), assert(f.at(0) == 0);\n  T h[sz];\n  const T *g= f.data();\n  int l=\
    \ 1, ed= std::min(sz, 1 << 11);\n  for (h[0]= 1; l < ed; l<<= 1) conv_na(h, g\
    \ + l, h + l, l);\n  for (; l < sz; l<<= 1) conv_tr(h, g + l, h + l, l);\n  return\
    \ std::vector<T>(h, h + sz);\n }\n // log(f) : \"f[\u2205] = 1\" is required.\n\
    \ template <class T>  // O(n^2 2^n)\n static inline std::vector<T> log(const std::vector<T>\
    \ &f) {\n  const int sz= f.size();\n  assert(!(sz & (sz - 1))), assert(f.at(0)\
    \ == T(1));\n  int I= 2, ed= std::min(sz, 1 << 13);\n  T h[sz];\n  const T *g=\
    \ f.data();\n  for (std::copy_n(g, ed, h); I < ed; I<<= 1)\n   for (int s= 1,\
    \ u= s | I; s < I; ++s, ++u)\n    for (int t= s; t; --t&= s) h[u]-= h[u ^ t] *\
    \ f[t];\n  for (; I < sz; I<<= 1)\n   h[I]= g[I], onconv_tr(\n               \
    \    g, h + I, [&](int s, T &x) { x= g[I | s] - x; }, I);\n  return h[0]= 0, std::vector<T>(h,\
    \ h + sz);\n }\n // f^k\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n  const int sz= f.size(), n= __builtin_ctz(sz);\n\
    \  assert(sz == 1 << n);\n  T F[MAX_N + 1]= {1}, pw= 1, bs= f[0];\n  int i= 1,\
    \ ed= std::min<std::uint64_t>(n, k);\n  for (; i <= ed; ++i) F[i]= F[i - 1] *\
    \ (k - i + 1);\n  for (auto e= k - --i; e; e>>= 1, bs*= bs)\n   if (e & 1) pw*=\
    \ bs;\n  for (; i >= 0; --i, pw*= f[0]) F[i]*= pw;\n  return f[0]= 0, composite(f,\
    \ F);\n }\n // P(f), P is polynomial\n template <class T> static inline std::vector<T>\
    \ polynomial_composite(std::vector<T> f, std::vector<T> P) {\n  const int sz=\
    \ f.size(), n= __builtin_ctz(sz);\n  assert(sz == 1 << n);\n  T F[MAX_N + 1]=\
    \ {};\n  int e= P.size();\n  if (!e) return std::vector<T>(sz);\n  for (int j=\
    \ 0;; ++j, --e) {\n   for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n   if (j ==\
    \ n || e == 1) break;\n   for (int i= 1; i < e; ++i) P[i - 1]= P[i] * i;\n  }\n\
    \  return f[0]= 0, composite(f, F);\n }\n // {[X^{[n]}]f^k/k!} for k=0,1,...,n\n\
    \ template <class T>  // O(n^2 2^n)\n static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n  static constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz),\
    \ sz4= sz >> 2;\n  assert(sz == 1 << n);\n  if (n == 1) return {0, f[1]};\n  int\
    \ l= sz4, m;\n  T *in= f.data() + l, *dp= in + l, tmp[sz4 / 2], *dp2;\n  for (int\
    \ s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz4; dp2= dp +\
    \ (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>= 1))\n\
    \   for (m= sz4; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1, 0);\n\
    \  for (int i= n + 1; --i;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    \ // {[X^{[n]}]g*f^k/k!} for k=0,1,...,n\n template <class T>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> egf(const std::vector<T> &f, std::vector<T> g)\
    \ {\n  static constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz),\
    \ sz2= sz >> 1, sz4= sz >> 2;\n  assert(sz == 1 << n), assert(sz == (int)g.size());\n\
    \  if (n == 1) return {g[1], f[1] * g[0] + f[0] * g[1]};\n  int l= sz2, m;\n \
    \ const T *in= f.data() + sz2;\n  T *dp= g.data(), tmp[sz2 / 2], *dp2;\n  for\
    \ (int s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz2; dp2=\
    \ dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l);\
    \ s--;) dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>=\
    \ 1))\n   for (m= sz2; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1);\n\
    \  for (int i= n + 1; i--;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    #undef SUBSET_REP\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SetPowerSeries.hpp
  requiredBy:
  - src/Graph/UndirectedGraphSetPowerSeries.hpp
  timestamp: '2023-05-18 20:05:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/arc105_f.test.cpp
  - test/atcoder/abc213_g.test.cpp
  - test/atcoder/abc199_d.test.cpp
  - test/yosupo/subset_convolution.test.cpp
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/polynomial_composite_set_power_series.test.cpp
  - test/aoj/2345.test.cpp
documentation_of: src/Math/SetPowerSeries.hpp
layout: document
title: "\u96C6\u5408\u51AA\u7D1A\u6570"
---

集合 $S,T \in 2^{\lbrace0,1,\dots,n-1\rbrace}$ を2進数表記の非負整数で表現する.\
環 $K$ 上の集合冪級数 $f,g,h \in K^{2^n}$ を 
\\[
\begin{aligned}
f(X) = \sum_{S=0}^{2^n-1}f_SX^S, &&g(X) = \sum_{S=0}^{2^n-1}g_SX^S, &&h(X) = \sum_{S=0}^{2^n-1}h_SX^S
\end{aligned}
\\]
とする.\
$K$は乗法の逆元は必要としない. (各演算は定義できる)
## static メンバ関数


| 名前                                  | 概要                                                                                                                                                                                                                                                                      | 計算量                   |
| ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------ |
| `subset_sum(f)`                       | $g_S = \sum_{T \subseteq S} f_T$ となる $g$ を返す.                                                                                                                                                                                                                       | $\mathcal{O}(n2^n)$      |
| `subset_sum_inv(f)`                   | $f_S = \sum_{T \subseteq S} g_T$ となる $g$ を返す.                                                                                                                                                                                                                       | $\mathcal{O}(n2^n)$      |
| `convolve(f,g)`                       | $h = fg$ つまり $h_S = \sum_{T \subseteq S} f_Tg_{S\backslash T}$ となる $h$ を返す.                                                                                                                                                                                      | $\mathcal{O}(n^22^n)$    |
| `semi_relaxed_convolve(g, init, phi)` | \\[ \begin{cases} f_{\varnothing} = \text{init}& \\\\ f_S = \phi_S\left(\sum_{T \subsetneq S} f_Tg_{S\backslash T}\right) & S \neq \varnothing \end{cases}\\] となる $f$ を返す. <br> 実際は $\phi_S$ は `phi(int,T&)` で参照渡しの関数を与える.                          | $\mathcal{O}(n^22^n)$    |
| `self_relaxed_convolve<T>(n, phi)`    | \\[\begin{cases} f_{\varnothing} = 0 & \\\\ f_S = \phi_S\left(\frac{1}{2}\sum_{\varnothing \neq T \subsetneq S}  f_Tf_{S\backslash T}\right) & S \neq \varnothing \end{cases}\\] となる $f$ を返す. <br> 実際は $\phi_S$ は `phi(int,T&)` で参照渡しの関数を与える.　<br> | $\mathcal{O}(n^22^n)$    |
| `composite(f,F)`                      | \\[ F(f) = \sum_{i=0}^{\infty} \frac{F_i}{i!} f^i \\] を返す. <br> $f_{\varnothing}=0$ でないと assert で死ぬ.                                                                                                                                                            | $\mathcal{O}(n^22^n)$    |
| `exp(f)`                              | \\[ \exp(f) =  \sum_{i=0}^{\infty} \frac{1}{i!} f^i \\] を返す. <br> $f_{\varnothing}=0$ でないと assert で死ぬ.                                                                                                                                                          | $\mathcal{O}(n^22^n)$    |
| `log(f)`                              | $ \log f $ を返す. <br> $f_{\varnothing}=1$ でないと assert で死ぬ.                                                                                                                                                                                                       | $\mathcal{O}(n^22^n)$    |
| `pow(f,k)`                            | $f^k$ を返す.                                                                                                                                                                                                                                                             | $\mathcal{O}(n^22^n)$    |
| `polynomial_composite(f,P)`           | 多項式 \\[ P(x) = \sum_{i=0}^{m-1}P_ix^i \\] に対して $P(f)$ を返す.                                                                                                                                                                                                      | $\mathcal{O}(n^22^n+nm)$ |
| `egf(f)`                              | $k=0,1,\dots,n$ について \\[\left\lbrack X^{2^n-1}\right\rbrack\frac{1}{k!}f^k\\] を返す.                                                                                                                                                                                 | $\mathcal{O}(n^22^n)$    |
| `egf(f,g)`                            | $k=0,1,\dots,n$ について \\[\left\lbrack X^{2^n-1}\right\rbrack\frac{1}{k!}gf^k\\] を返す.                                                                                                                                                                                | $\mathcal{O}(n^22^n)$    |

## 参考
[https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex](https://github.com/EntropyIncreaser/ioi2021-homework/blob/master/thesis/main.tex) \
[https://notes.sshwy.name/Math/Subset-Power-Series](https://notes.sshwy.name/Math/Subset-Power-Series) \
[https://maspypy.com/category/集合べき級数](https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0)
## 問題例
[Xmas Contest 2020 H - Hierarchical Phylogeny](https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h) (self relax or 合成 1-√(1-2f)) \
[Xmas Contest 2022 F - Fast as Fast as Ryser](https://atcoder.jp/contests/xmascon22/tasks/xmascon22_f) (exp, egf)\
[AtCoder Beginner Contest 253 Ex - We Love Forest](https://atcoder.jp/contests/abc253/tasks/abc253_h) (egf)\
[AtCoder Beginner Contest 236 Ex - Distinct Multiples](https://atcoder.jp/contests/abc236/tasks/abc236_h) (exp) \
[LibraOJ #2340. 「WC2018」州区划分](https://loj.ac/p/2340) (semi relax)
