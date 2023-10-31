---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':x:'
    path: src/Math/SetPowerSeries.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_composite_set_power_series
    links:
    - https://judge.yosupo.jp/problem/polynomial_composite_set_power_series
  bundledCode: "#line 1 \"test/yosupo/polynomial_composite_set_power_series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_composite_set_power_series\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include\
    \ <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b),\
    \ z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod\
    \ : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n \
    \ if (l+= r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n\
    \ CE IL U diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return\
    \ l; \\\n }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static\
    \ CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\n\
    template <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, enable_if_t<is_modint_v<T> && !is_same_v<T,\
    \ MInt>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod))\
    \ {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Math/SetPowerSeries.hpp\"\n#include <algorithm>\n\
    #line 5 \"src/Math/SetPowerSeries.hpp\"\n#include <cstdint>\ntemplate <unsigned\
    \ short MAX_N= 21> struct SetPowerSeries {\n#define SUBSET_REP(i, j, n) \\\n for\
    \ (int _= (n), _e= (n); _>>= 1;) \\\n  for (int __= 0, _2= _ << 1; __ < _e; __+=\
    \ _2) \\\n   for (int j= __, i= j | _, ___= i; j < ___; ++j, ++i)\n template <typename\
    \ T> static inline void ranked_zeta_tr(const T f[], T ret[][MAX_N + 1], const\
    \ int sz) {\n  for (int S= sz, c; S--;) ret[S][c= __builtin_popcount(S)]= f[S],\
    \ std::fill_n(ret[S], c, 0);\n  SUBSET_REP(S, U, sz)\n  for (int d= __builtin_popcount(S);\
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
    \ ret[S]= mat[__builtin_popcount(S)][S];\n }\npublic:\n // O(n 2^n)\n template\
    \ <typename T> static inline void subset_sum(std::vector<T> &f) { SUBSET_REP(S,\
    \ U, f.size()) f[S]+= f[U]; }\n // O(n 2^n)\n template <typename T> static inline\
    \ void subset_sum_inv(std::vector<T> &f) { SUBSET_REP(S, U, f.size()) f[S]-= f[U];\
    \ }\n // O(n^2 2^n)\n template <class T> static inline std::vector<T> convolve(const\
    \ std::vector<T> &f, const std::vector<T> &g) {\n  const int sz= f.size(), n=\
    \ __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  if (n <= 10) return conv_na(f.data(),\
    \ g.data(), ret.data(), sz), ret;\n  assert(sz == 1 << n && sz == (int)g.size());\n\
    \  return conv_tr(f.data(), g.data(), ret.data(), sz), ret;\n }\n // f(S) = \u03C6\
    _S ( \u03A3_{T\u228AS} f(T)g(S/T) )   O(n^2 2^n)\n template <class T, class F=\
    \ void (*)(int, T &)>\n static inline std::vector<T> semi_relaxed_convolve(\n\
    \     const std::vector<T> &g, T init, const F &phi= [](int, T &) {}) {\n  const\
    \ int sz= g.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n  ret[0]=\
    \ init;\n  if (n <= 12) return onconv_na(g.data(), ret.data(), phi, sz), ret;\n\
    \  assert(sz == 1 << n);\n  return onconv_tr(g.data(), ret.data(), phi, sz), ret;\n\
    \ }\n // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T) as binary numbers)\
    \ } f(T)f(S/T) )   O(n^2 2^n)\n template <class T, class F> static inline std::vector<T>\
    \ self_relaxed_convolve(int n, const F &phi) {\n  assert(__builtin_popcount(n)\
    \ == 1);\n  int I= 1, ed= std::min(1 << 13, n);\n  std::vector<T> ret(n, 0);\n\
    \  for (int s, t, u= 1; I < ed; I<<= 1)\n   for (t= s= 0; s < I; phi(u, ret[u]),\
    \ t= ++s, ++u)\n    for (ret[u]= 0; t; --t&= s) ret[u]+= ret[u ^ t] * ret[t];\n\
    \  T *h= ret.data();\n  for (; I < n; I<<= 1)\n   phi(I, ret[I]), onconv_tr(\n\
    \                       h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n \
    \ return ret;\n }\n // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n //\
    \ \"f[\u2205] = 0\" is required.  O(n^2 2^n)\n template <class T, class EGF> static\
    \ inline std::vector<T> composite(const std::vector<T> &f, const EGF &F) {\n \
    \ const int sz= f.size(), m= __builtin_ctz(sz), sz2= sz >> 1;\n  assert(sz ==\
    \ 1 << m), assert(f.at(0) == 0);\n  std::vector<T> ret(sz);\n  T *h= ret.data()\
    \ + sz;\n  const T *g= f.data();\n  for (int i= 0; i <= m; ++i) ret[sz - (1 <<\
    \ i)]= F[m - i];\n  int l= 1, ed= std::min(sz, 1 << 11), j;\n  for (; l < ed;\
    \ l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_na(h - j, g + l, h - j - j + l,\
    \ l);\n  for (; l < sz; l<<= 1)\n   for (j= sz2; j >= l; j>>= 1) conv_tr(h - j,\
    \ g + l, h - j - j + l, l);\n  return ret;\n }\n // exp(f) : \"f[\u2205] = 0\"\
    \ is required.  O(n^2 2^n)\n template <class T> static inline std::vector<T> exp(const\
    \ std::vector<T> &f) {\n  const int sz= f.size();\n  assert(!(sz & (sz - 1))),\
    \ assert(f.at(0) == 0);\n  T h[sz];\n  const T *g= f.data();\n  int l= 1, ed=\
    \ std::min(sz, 1 << 11);\n  for (h[0]= 1; l < ed; l<<= 1) conv_na(h, g + l, h\
    \ + l, l);\n  for (; l < sz; l<<= 1) conv_tr(h, g + l, h + l, l);\n  return std::vector<T>(h,\
    \ h + sz);\n }\n // log(f) : \"f[\u2205] = 1\" is required.  O(n^2 2^n)\n template\
    \ <class T> static inline std::vector<T> log(const std::vector<T> &f) {\n  const\
    \ int sz= f.size();\n  assert(!(sz & (sz - 1))), assert(f.at(0) == T(1));\n  int\
    \ I= 2, ed= std::min(sz, 1 << 13);\n  T h[sz];\n  const T *g= f.data();\n  for\
    \ (std::copy_n(g, ed, h); I < ed; I<<= 1)\n   for (int s= 1, u= s | I; s < I;\
    \ ++s, ++u)\n    for (int t= s; t; --t&= s) h[u]-= h[u ^ t] * f[t];\n  for (;\
    \ I < sz; I<<= 1)\n   h[I]= g[I], onconv_tr(\n                   g, h + I, [&](int\
    \ s, T &x) { x= g[I | s] - x; }, I);\n  return h[0]= 0, std::vector<T>(h, h +\
    \ sz);\n }\n // f^k   O(n^2 2^n)\n template <class T> static inline std::vector<T>\
    \ pow(std::vector<T> f, uint64_t k) {\n  const int sz= f.size(), n= __builtin_ctz(sz);\n\
    \  assert(sz == 1 << n);\n  T F[MAX_N + 1]= {1}, pw= 1, bs= f[0];\n  int i= 1,\
    \ ed= std::min<uint64_t>(n, k);\n  for (; i <= ed; ++i) F[i]= F[i - 1] * (k -\
    \ i + 1);\n  for (auto e= k - --i; e; e>>= 1, bs*= bs)\n   if (e & 1) pw*= bs;\n\
    \  for (; i >= 0; --i, pw*= f[0]) F[i]*= pw;\n  return f[0]= 0, composite(f, F);\n\
    \ }\n // P(f), P is polynomial  O(n^2 2^n)\n template <class T> static inline\
    \ std::vector<T> polynomial_composite(std::vector<T> f, std::vector<T> P) {\n\
    \  const int sz= f.size(), n= __builtin_ctz(sz);\n  assert(sz == 1 << n);\n  T\
    \ F[MAX_N + 1]= {};\n  int e= P.size();\n  if (!e) return std::vector<T>(sz);\n\
    \  for (int j= 0;; ++j, --e) {\n   for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n\
    \   if (j == n || e == 1) break;\n   for (int i= 1; i < e; ++i) P[i - 1]= P[i]\
    \ * i;\n  }\n  return f[0]= 0, composite(f, F);\n }\n // {[X^{[n]}]f^k/k!} for\
    \ k=0,1,...,n  O(n^2 2^n)\n template <class T> static inline std::vector<T> egf(std::vector<T>\
    \ f) {\n  static constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz),\
    \ sz4= sz >> 2;\n  assert(sz == 1 << n);\n  if (n == 1) return {0, f[1]};\n  int\
    \ l= sz4, m;\n  T *in= f.data() + l, *dp= in + l, tmp[sz4 / 2], *dp2;\n  for (int\
    \ s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz4; dp2= dp +\
    \ (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l); s--;)\
    \ dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>= 1))\n\
    \   for (m= sz4; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1, 0);\n\
    \  for (int i= n + 1; --i;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    \ // {[X^{[n]}]g*f^k/k!} for k=0,1,...,n   O(n^2 2^n)\n template <class T> static\
    \ inline std::vector<T> egf(const std::vector<T> &f, std::vector<T> g) {\n  static\
    \ constexpr int M= 1 << 11;\n  const int sz= f.size(), n= __builtin_ctz(sz), sz2=\
    \ sz >> 1, sz4= sz >> 2;\n  assert(sz == 1 << n), assert(sz == (int)g.size());\n\
    \  if (n == 1) return {g[1], f[1] * g[0] + f[0] * g[1]};\n  int l= sz2, m;\n \
    \ const T *in= f.data() + sz2;\n  T *dp= g.data(), tmp[sz2 / 2], *dp2;\n  for\
    \ (int s; l > M; conv_tr(dp, in, dp, l), in-= (l>>= 1))\n   for (m= sz2; dp2=\
    \ dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_tr(dp2 + m - l, in, tmp, l);\
    \ s--;) dp2[s]+= tmp[s];\n  for (int s; l; conv_na(dp, in, dp, l), in-= (l>>=\
    \ 1))\n   for (m= sz2; dp2= dp + (m - l), m > l; m>>= 1)\n    for (s= l, conv_na(dp2\
    \ + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1);\n\
    \  for (int i= n + 1; i--;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n\
    #undef SUBSET_REP\n};\n#line 6 \"test/yosupo/polynomial_composite_set_power_series.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int M, N;\n cin >> M >> N;\n int S= 1 << N;\n\
    \ vector<Mint> a(M), b(S);\n for (int i= 0; i < M; ++i) cin >> a[i];\n for (int\
    \ i= 0; i < S; ++i) cin >> b[i];\n auto c= SetPowerSeries<20>::polynomial_composite(b,\
    \ a);\n for (int i= 0; i < S; ++i) cout << c[i] << \" \\n\"[i == S - 1];\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_composite_set_power_series\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/Math/SetPowerSeries.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n using Mint= ModInt<998244353>;\n int M, N;\n cin\
    \ >> M >> N;\n int S= 1 << N;\n vector<Mint> a(M), b(S);\n for (int i= 0; i <\
    \ M; ++i) cin >> a[i];\n for (int i= 0; i < S; ++i) cin >> b[i];\n auto c= SetPowerSeries<20>::polynomial_composite(b,\
    \ a);\n for (int i= 0; i < S; ++i) cout << c[i] << \" \\n\"[i == S - 1];\n return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/SetPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/polynomial_composite_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 14:54:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/polynomial_composite_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial_composite_set_power_series.test.cpp
- /verify/test/yosupo/polynomial_composite_set_power_series.test.cpp.html
title: test/yosupo/polynomial_composite_set_power_series.test.cpp
---
