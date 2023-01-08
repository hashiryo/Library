---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/UndirectedGraphSetPowerSeries.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u6570\u3048\u4E0A\u3052(\u96C6\u5408\u51AA\
      \u7D1A\u6570)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':heavy_check_mark:'
    path: src/Math/SetPowerSeries.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc105/tasks/arc105_f
    links:
    - https://atcoder.jp/contests/arc105/tasks/arc105_f
  bundledCode: "#line 1 \"test/atcoder/arc105_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc105/tasks/arc105_f\"\
    \n\n// \u9023\u7D50\u4E8C\u90E8\u30B0\u30E9\u30D5\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n\
    \ for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b,\
    \ b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n\
    }\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal {\nusing\
    \ namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\n\
    using i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n const u64 mod;\n\
    \ constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr MP_Mo(u64 m): mod(m),\
    \ iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline u64 mul(u64 l, u64 r)\
    \ const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l op##= a,\
    \ l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64 l, u64 r) const\
    \ { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64 l, u64 r) const\
    \ { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n) const { return\
    \ mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64 ret= reduce(n)\
    \ - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr inline u64 norm(u64\
    \ n) const { return n - (mod & -(n >= mod)); }\nprivate:\n const u64 iv, r2;\n\
    \ constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n constexpr inline u64 reduce(const u128& w) const { return\
    \ u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64); }\n};\ntemplate <class\
    \ Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint, u32>, u64,\
    \ u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n constexpr\
    \ MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint r) const {\
    \ return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod & -((l p##=\
    \ r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const { BOP(-, +); }\n\
    \ constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -); }\n#undef BOP\n\
    \ static constexpr inline Uint set(Uint n) { return n; }\n static constexpr inline\
    \ Uint get(Uint n) { return n; }\n static constexpr inline Uint norm(Uint n) {\
    \ return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr Uint pow(Uint\
    \ x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);; x= md.mul(x, x))\n\
    \  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n}\n#line 5 \"\
    src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\nstruct\
    \ m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t> CE\
    \ bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 3 \"src/Math/SetPowerSeries.hpp\"\ntemplate <unsigned short MAX_N= 21> struct\
    \ SetPowerSeries {\n#define SUBSET_REP(i, j, n) \\\n for (int _= (n); _>>= 1;)\
    \ \\\n  for (int __= 0, _2= _ << 1; __ < (n); __+= _2) \\\n   for (int j= __,\
    \ i= j | _, ___= i; j < ___; j++, i++)\n template <typename T> static inline void\
    \ ranked_zeta_tr(const T f[], T ret[][MAX_N + 1], const int sz) {\n  for (int\
    \ S= sz, c; S--;) ret[S][c= __builtin_popcount(S)]= f[S], std::fill_n(ret[S],\
    \ c, 0);\n  SUBSET_REP(S, U, sz)\n  for (int d= __builtin_popcount(S); d--;) ret[S][d]+=\
    \ ret[U][d];\n }\n template <typename T> static inline void conv_na(const T f[],\
    \ const T g[], T ret[], const int sz) {\n  for (int s= sz, t; s--;)\n   for (ret[t=\
    \ s]= f[s] * g[0]; t; --t&= s) ret[s]+= f[s ^ t] * g[t];\n }\n template <typename\
    \ T> static inline void conv_tr(const T f[], const T g[], T ret[], const int sz)\
    \ {\n  static T F[1 << MAX_N][MAX_N + 1], G[1 << MAX_N][MAX_N + 1];\n  T tmp[MAX_N\
    \ + 1];\n  ranked_zeta_tr(f, F, sz), ranked_zeta_tr(g, G, sz);\n  const int n=\
    \ __builtin_ctz(sz);\n  for (int S= sz, c, d, e, bg; S--;) {\n   c= __builtin_popcount(S),\
    \ bg= std::min(2 * c, n);\n   for (d= bg; d >= c; d--)\n    for (tmp[d]= 0, e=\
    \ d - c; e <= c; e++) tmp[d]+= F[S][e] * G[S][d - e];\n   for (d= bg; d >= c;\
    \ d--) F[S][d]= tmp[d];\n  }\n  SUBSET_REP(S, U, sz)\n  for (int c= __builtin_popcount(U),\
    \ d= std::min(2 * c, n); d > c; d--) F[S][d]-= F[U][d];\n  for (int S= sz; S--;)\
    \ ret[S]= F[S][__builtin_popcount(S)];\n }\n template <typename T, class F> static\
    \ inline void onconv_na(const T g[], T ret[], const F &phi, const int sz) {\n\
    \  for (int s= 1, t; s < sz; phi(s, ret[s]), s++)\n   for (ret[t= s]= 0; t; --t&=\
    \ s) ret[s]+= ret[s ^ t] * g[t];\n }\n template <typename T, class F> static inline\
    \ void onconv_tr(const T g[], T ret[], const F &phi, const int sz) {\n  static\
    \ T G[1 << MAX_N][MAX_N + 1], mat[MAX_N + 1][1 << MAX_N];\n  const int n= __builtin_ctz(sz);\n\
    \  ranked_zeta_tr(g, G, sz), std::fill_n(mat[0], sz, ret[0]);\n  for (int d= n;\
    \ d; d--) std::fill_n(mat[d], sz, 0);\n  for (int I= sz; I>>= 1;) phi(I, mat[1][I]=\
    \ ret[0] * g[I]);\n  for (int d= 2; d <= n; d++) {\n   SUBSET_REP(S, U, sz) mat[d\
    \ - 1][S]+= mat[d - 1][U];\n   for (int S= sz; S--;)\n    if (int c= __builtin_popcount(S);\
    \ c <= d && d <= 2 * c)\n     for (int e= d; e--;) mat[d][S]+= mat[e][S] * G[S][d\
    \ - e];\n   SUBSET_REP(S, U, sz) mat[d][S]-= mat[d][U];\n   for (int S= sz; S--;)\
    \ __builtin_popcount(S) == d ? phi(S, mat[d][S]), 0 : (mat[d][S]= 0);\n  }\n \
    \ for (int S= sz; --S;) ret[S]= mat[__builtin_popcount(S)][S];\n }\npublic:\n\
    \ template <typename T>  // O(n 2^n)\n static inline void subset_sum(std::vector<T>\
    \ &f) {\n  SUBSET_REP(S, U, f.size()) f[S]+= f[U];\n }\n template <typename T>\
    \  // O(n 2^n)\n static inline void subset_sum_inv(std::vector<T> &f) {\n  SUBSET_REP(S,\
    \ U, f.size()) f[S]-= f[U];\n }\n template <class T>  // O(n^2 2^n)\n static inline\
    \ std::vector<T> convolve(const std::vector<T> &f, const std::vector<T> &g) {\n\
    \  const int sz= f.size(), n= __builtin_ctz(sz);\n  std::vector<T> ret(sz);\n\
    \  if (n <= 10) return conv_na(f.data(), g.data(), ret.data(), sz), ret;\n  assert(sz\
    \ == 1 << n && sz == g.size());\n  return conv_tr(f.data(), g.data(), ret.data(),\
    \ sz), ret;\n }\n // f(S) = \u03C6_S ( \u03A3_{T\u228AS} f(T)g(S/T) )\n template\
    \ <class T, class F= void (*)(int, T &)>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ online_convolve(\n     const std::vector<T> &g, T init, const F &phi= [](int,\
    \ T &) {}) {\n  const int sz= g.size(), n= __builtin_ctz(sz);\n  std::vector<T>\
    \ ret(sz);\n  ret[0]= init;\n  if (n <= 12) return onconv_na(g.data(), ret.data(),\
    \ phi, sz), ret;\n  assert(sz == 1 << n);\n  return onconv_tr(g.data(), ret.data(),\
    \ phi, sz), ret;\n }\n // f(S) = \u03C6_S ( \u03A3_{\u2205\u2260T\u228AS & (T<(S/T)\
    \ as binary numbers) } f(T)f(S/T) )\n template <class T, class F>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> online_convolve2(int sz, const F &phi) {\n  assert(__builtin_popcount(sz)\
    \ == 1);\n  int I= 1, ed= std::min(1 << 13, sz);\n  std::vector<T> ret(sz, 0);\n\
    \  for (int s, t, u= 1; I < ed; I<<= 1)\n   for (t= s= 0; s < I; phi(u, ret[u]),\
    \ t= ++s, u++)\n    for (ret[u]= 0; t; --t&= s) ret[u]+= ret[u ^ t] * ret[t];\n\
    \  T *h= ret.data();\n  for (; I < sz; I<<= 1)\n   phi(I, ret[I]), onconv_tr(\n\
    \                       h, h + I, [&](int s, T &x) { phi(s | I, x); }, I);\n \
    \ return ret;\n }\n // F(f) : F[i] is coefficient of EGF ( = F^{(i)}(0) )\n //\
    \ \"f[\u2205] = 0\" is required.\n template <class T, class EGF>  // O(n^2 2^n)\n\
    \ static inline std::vector<T> composite(const std::vector<T> &f, const EGF &F)\
    \ {\n  const int sz= f.size(), m= __builtin_ctz(sz), sz2= sz >> 1;\n  assert(sz\
    \ == 1 << m), assert(f.at(0) == 0);\n  std::vector<T> ret(sz);\n  T *h= ret.data()\
    \ + sz;\n  const T *g= f.data();\n  for (int i= 0; i <= m; i++) ret[sz - (1 <<\
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
    \ == T(1));\n  int I= 2, ed= std::min(sz, 1 << 13);\n  T h[sz];\n  for (std::copy_n(f.begin(),\
    \ ed, h); I < ed; I<<= 1)\n   for (int s= 1, u= s | I; s < I; s++, u++)\n    for\
    \ (int t= s; t; --t&= s) h[u]-= h[u ^ t] * f[t];\n  const T *g= f.data();\n  for\
    \ (; I < sz; I<<= 1)\n   h[I]= g[I], onconv_tr(\n                   g, h + I,\
    \ [&](int s, T &x) { x= g[I | s] - x; }, I);\n  return h[0]= 0, std::vector<T>(h,\
    \ h + sz);\n }\n // f^k\n template <class T>  // O(n^2 2^n)\n static inline std::vector<T>\
    \ pow(std::vector<T> f, std::uint64_t k) {\n  const int sz= f.size(), n= __builtin_ctz(sz);\n\
    \  assert(sz == 1 << n);\n  T F[MAX_N + 1]= {1}, pw= 1, bs= f[0];\n  int i= 1,\
    \ ed= std::min<std::uint64_t>(n, k);\n  for (; i <= ed; i++) F[i]= F[i - 1] *\
    \ (k - i + 1);\n  for (auto e= k - --i; e; e>>= 1, bs*= bs)\n   if (e & 1) pw*=\
    \ bs;\n  for (; i >= 0; i--, pw*= f[0]) F[i]*= pw;\n  return f[0]= 0, composite(f,\
    \ F);\n }\n // {[X^{[n]}](f^k)/(k!)} for k=0,1,...,n\n template <class T>  //\
    \ O(n^2 2^n)\n static inline std::vector<T> egf(std::vector<T> f) {\n  const int\
    \ sz= f.size(), n= __builtin_ctz(sz), md= 1 << 11, sz4= sz >> 2;\n  assert(sz\
    \ == 1 << n);\n  if (n == 1) return {0, f[1]};\n  int l= sz4, m;\n  T *in= f.data()\
    \ + l, *dp= in + l, tmp[sz4], *dp2;\n  for (int s; l > md; conv_tr(dp, in, dp,\
    \ l), in-= (l>>= 1))\n   for (s= l, m= sz4; dp2= dp + (m - l), m > l; m>>= 1,\
    \ s= l)\n    for (conv_tr(dp2 + m - l, in, tmp, l); s--;) dp2[s]+= tmp[s];\n \
    \ for (int s; l; conv_na(dp, in, dp, l), in-= (l>>= 1))\n   for (s= l, m= sz4;\
    \ dp2= dp + (m - l), m > l; m>>= 1, s= l)\n    for (conv_na(dp2 + m - l, in, tmp,\
    \ l); s--;) dp2[s]+= tmp[s];\n  std::vector<T> ret(n + 1, 0);\n  for (int i= n\
    \ + 1; --i;) ret[i]= dp[(1 << (n - i)) - 1];\n  return ret;\n }\n#undef SUBSET_REP\n\
    };\n#line 4 \"src/Graph/UndirectedGraphSetPowerSeries.hpp\"\ntemplate <unsigned\
    \ short MAX_V= 21> class UndirectedGraphSetPowerSeries {\n using SPS= SetPowerSeries<MAX_V>;\n\
    \ template <class T> using sps= std::vector<T>;\n template <class T> using poly=\
    \ std::vector<T>;\n const unsigned V, sz;\n unsigned adj[MAX_V][MAX_V]= {0}, edge[MAX_V]=\
    \ {0};\n template <class T> static inline T pow(T x, int k) {\n  for (T ret(1);;\
    \ x*= x)\n   if (k & 1 ? ret*= x : 0; !(k>>= 1)) return ret;\n }\n template <class\
    \ F> inline void bfs(int s, const F &f) const {\n  for (int t= s, u, j; t;)\n\
    \   for (f(u= 1 << __builtin_ctz(t)); u;) j= __builtin_ctz(u), t^= 1 << j, u^=\
    \ 1 << j, u|= edge[j] & t;\n }\npublic:\n UndirectedGraphSetPowerSeries(int n):\
    \ V(n), sz(1 << V) {}\n UndirectedGraphSetPowerSeries(const std::vector<std::vector<int>>\
    \ &g): V(g.size()), sz(1 << V) {\n  for (int i= V; i--;)\n   for (int j= i; j--;)\
    \ assert(g[i][j] == g[j][i]);\n  for (int i= V; i--;)\n   for (int j= V; j--;)\
    \ adj[i][j]= g[i][j];\n  for (int i= V; i--;)\n   for (int j= V; j--;) edge[i]|=\
    \ !(!(adj[i][j])) << j;\n }\n int *operator[](int u) const { return adj[u]; }\n\
    \ void add_edge(int u, int v, int cnt= 1) {\n  adj[u][v]= (adj[v][u]+= cnt), edge[u]|=\
    \ (1 << v), edge[v]|= (1 << u);\n  if (!(adj[u][v])) edge[u]^= (1 << v), edge[v]^=\
    \ (1 << u);\n }\n template <class T> static inline sps<T> space_size(const sps<int>\
    \ &rank) {\n  sps<T> ret(rank.size());\n  for (int s= rank.size(); s--;) ret[s]=\
    \ pow<T>(2, rank[s]);\n  return ret;\n }\n template <class T, class G> static\
    \ inline void transform(sps<T> &f, const G &g) {\n  const int sz2= f.size() /\
    \ 2;\n  sps<T> tmp(sz2);\n  for (int I= sz2; I; I>>= 1) {\n   for (int t= 0; t\
    \ < sz2; t+= I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= f[t2 | I | u];\n\
    \   tmp= g(tmp);\n   for (int t= 0; t < sz2; t+= I)\n    for (int u= I, t2= t\
    \ << 1; u--;) f[t2 | I | u]= tmp[t | u];\n  }\n }\n template <class T>  // O(V^3\
    \ 2^V)\n static inline void connect_to_biconnect(sps<T> &f) {\n  transform(f,\
    \ SPS::template log<T>);\n }\n template <class T>  // O(V^3 2^V)\n static inline\
    \ void biconnect_to_connect(sps<T> &f) {\n  transform(f, SPS::template exp<T>);\n\
    \ }\n template <class T>  // O(V 2^V)\n inline void loop_ignored_to_loop_permitted(sps<T>\
    \ &f) const {\n  auto tmp= space_size<T>(loop_size());\n  for (int s= sz; s--;)\
    \ f[s]*= tmp[s];\n }\n inline sps<int> edge_space_rank() const {  // O(V 2^V)\n\
    \  sps<int> ret(sz, 0);\n  for (int i= V; i--;)\n   for (int j= i + 1; j--;) ret[(1\
    \ << i) | (1 << j)]= adj[i][j];\n  return SPS::subset_sum(ret), ret;\n }\n inline\
    \ sps<int> loop_size() const {  // O(V 2^V)\n  sps<int> ret(sz, 0);\n  for (int\
    \ i= V; i--;) ret[(1 << i)]= adj[i][i];\n  return SPS::subset_sum(ret), ret;\n\
    \ }\n inline sps<int> loop_ignored_edge_space_rank() const {  // O(V 2^V)\n  sps<int>\
    \ ret(sz, 0);\n  for (int i= V; i--;)\n   for (int j= i; j--;) ret[(1 << i) |\
    \ (1 << j)]= adj[i][j];\n  return SPS::subset_sum(ret), ret;\n }\n inline sps<int>\
    \ connected_component_num() const {  // O(V 2^V)\n  sps<int> ret(sz, 0);\n  for\
    \ (int s= sz; s--;) bfs(s, [&](int) { ret[s]++; });\n  return ret;\n }\n inline\
    \ sps<int> cycle_space_rank() const {  // O(V 2^V)\n  sps<int> e= edge_space_rank(),\
    \ k= connected_component_num(), ret(sz, 0);\n  for (int s= sz; s--;) ret[s]= e[s]\
    \ + k[s] - __builtin_popcount(s);\n  return ret;\n }\n template <class T>  //\
    \ O(V 2^V)\n inline sps<T> edge_space_size() const {\n  return space_size<T>(edge_space_rank());\n\
    \ }\n template <class T>  // O(V 2^V)\n inline sps<T> loop_ignored_edge_space_size()\
    \ const {\n  return space_size<T>(loop_ignored_edge_space_rank());\n }\n template\
    \ <class T>  // O(V 2^V)\n inline sps<T> cycle_space_size() const {\n  return\
    \ space_size<T>(cycle_space_rank());\n }\n template <class T>  // O(V^2 2^V)\n\
    \ inline sps<T> connected_graph_num() const {\n  return SPS::log(edge_space_size<T>());\n\
    \ }\n template <class T>  // O(V^2 2^V)\n inline sps<T> loop_ignored_connected_graph_num()\
    \ const {\n  return SPS::log(loop_ignored_edge_space_size<T>());\n }\n template\
    \ <class T>  // O(V^2 2^V)\n inline sps<T> euler_graph_num() const {\n  return\
    \ SPS::log(cycle_space_size<T>());\n }\n template <class T>  // O(V^2 2^V)\n inline\
    \ sps<T> connected_biparate_graph_num() const {\n  sps<T> tmp= edge_space_size<T>(),\
    \ ret(sz, 1);\n  for (int s= sz; s--;) ret[s]/= tmp[s];\n  ret= SPS::convolve(ret,\
    \ ret);\n  for (int s= sz; s--;) ret[s]*= tmp[s];\n  ret= SPS::log(ret);\n  for\
    \ (int s= sz; s--;) ret[s]/= 2;\n  return ret;\n }\n template <class T>  // O(V^3\
    \ 2^V)\n inline sps<T> loop_ignored_biconnected_graph_num() const {\n  auto ret=\
    \ loop_ignored_connected_graph_num<T>();\n  return connect_to_biconnect(ret),\
    \ ret;\n }\n template <class T>  // O(V^3 2^V)\n inline sps<T> biconnected_graph_num()\
    \ const {\n  auto ret= loop_ignored_biconnected_graph_num<T>();\n  return loop_ignored_to_loop_permitted(ret),\
    \ ret;\n }\n template <class T>  // O(V^2 2^V)\n inline sps<T> spanning_tree_num()\
    \ const {\n  sps<int> e= edge_space_rank();\n  sps<T> ret= {0, 1};\n  ret.reserve(sz);\n\
    \  for (int I= 2; I < sz; I<<= 1) {\n   sps<T> g(ret);\n   for (int s= I; --s;)\
    \ g[s]*= e[s | I] - e[s] - e[I];\n   g= SPS::exp(g);\n   std::copy(g.begin(),\
    \ g.end(), std::back_inserter(ret));\n  }\n  return ret;\n }\n template <class\
    \ T>  // O(V^2 2^V)\n inline sps<T> forest_num() const {\n  return SPS::exp(spanning_tree_num<T>());\n\
    \ }\n template <class T>  // O(V^2 2^V)\n inline sps<T> rooted_spanning_tree_num()\
    \ const {\n  auto ret= spanning_tree_num<T>();\n  for (int s= sz; s--;) ret[s]*=\
    \ __builtin_popcount(s);\n  return ret;\n }\n template <class T>  // O(V^2 2^V)\n\
    \ inline sps<T> rooted_forest_num() const {\n  return SPS::exp(rooted_spanning_tree_num<T>());\n\
    \ }\n template <class T>  // O(V^2 2^V)\n inline sps<T> cycle_graph_num() const\
    \ {\n  T dp[sz][V - 1];\n  sps<T> ret(sz, 0);\n  for (int i= V, I= sz; I>>= 1,\
    \ --i;) {\n   for (int s= I; --s;) std::fill_n(dp[s], i, 0);\n   for (int j= i;\
    \ j--;) dp[1 << j][j]= adj[i][j];\n   for (int s= 1; s < I; s++)\n    for (int\
    \ t= s, j, u, r, k; t; ret[s | I]+= dp[s][j] * adj[j][i])\n     for (t^= 1 <<\
    \ (j= __builtin_ctz(t)), u= r= s ^ (1 << j); u; dp[s][j]+= dp[r][k] * adj[k][j])\
    \ u^= 1 << (k= __builtin_ctz(u));\n  }\n  for (int i= V; i--;)\n   for (int j=\
    \ i; j--;) ret[(1 << i) | (1 << j)]-= adj[i][j];\n  for (int s= sz; --s;) ret[s]/=\
    \ 2;\n  for (int i= V; i--;) ret[1 << i]= adj[i][i];\n  return ret;\n }\n template\
    \ <class T>  // O(V^3 2^V)\n inline sps<T> cactus_graph_num() const {\n  auto\
    \ ret= cycle_graph_num<T>();\n  for (int i= V; i--;)\n   for (int j= i; j--;)\
    \ ret[(1 << i) | (1 << j)]+= adj[i][j];\n  for (int i= V; i--;) ret[1 << i]= 0;\n\
    \  return biconnect_to_connect(ret), loop_ignored_to_loop_permitted(ret), ret;\n\
    \ }\n template <class T>  // O(V^3 2^V)\n inline sps<T> two_edge_connected_graph_num()\
    \ const {\n  const int sz2= sz / 2;\n  sps<T> ret= connected_graph_num<T>(), tmp(sz2),\
    \ tmp2;\n  for (int i= V, I= sz2; --i; I>>= 1) {\n   for (int t= 0; t < sz2; t+=\
    \ I)\n    for (int u= I, t2= t << 1; u--;) tmp[t | u]= ret[t2 | I | u];\n   tmp2.assign(sz2,\
    \ 0);\n   for (int t= 0; t < sz2; t+= I)\n    for (int j= i, J= I, t2= t << 1;\
    \ J>>= 1, j--;)\n     for (int s= J, J2= J * 2; s < I; s+= J2)\n      for (int\
    \ u= s + J; u-- > s;) tmp2[t | u]-= ret[t2 | u] * adj[i][j];\n   tmp= SPS::convolve(tmp,\
    \ SPS::exp(tmp2));\n   for (int t= 0; t < sz2; t+= I)\n    for (int u= I, t2=\
    \ t << 1; u--;) ret[t2 | I | u]= tmp[t | u];\n  }\n  return ret;\n }\n template\
    \ <class T>  // O(V^2 2^V)\n inline sps<T> acyclic_orientations() const {\n  auto\
    \ k= connected_component_num();\n  sps<T> g(sz, 0);\n  for (int s= sz; --s;)\n\
    \   if (k[s] == __builtin_popcount(s)) g[s]= (k[s] + 1) & 1 ? -1 : 1;\n  return\
    \ SPS::template online_convolve<T>(g, 1);\n }\n template <class T>  // O(V^2 2^V)\n\
    \ inline std::vector<T> colorings_using_exactly_k_colors_num() const {\n  if (V\
    \ == 0) return {0};  // impossible in any number of ways\n  for (int i= V; i--;)\n\
    \   if (adj[i][i]) return {0};  // impossible in any number of ways\n  auto k=\
    \ connected_component_num();\n  std::vector<T> indep(sz, 0);\n  for (int s= sz;\
    \ --s;) indep[s]= k[s] == __builtin_popcount(s);\n  return SPS::egf(indep);\n\
    \ }\n template <class T>  // O(V^2 2^V)\n inline poly<T> chromatic_polynomial()\
    \ const {\n  auto e= colorings_using_exactly_k_colors_num<T>();\n  if (e.back()\
    \ == 0) return {0};\n  poly<T> ret(V + 1, 0);\n  T tmp[V]= {1};\n  for (int i=\
    \ 1, j; i < V; i++)\n   for (j= i; j--; tmp[j]*= -i) ret[j + 1]+= tmp[j] * e[i],\
    \ tmp[j + 1]+= tmp[j];\n  for (int j= V; j--;) ret[j + 1]+= tmp[j];\n  return\
    \ ret;\n }\n template <class T>  //  O(V^2 2^V)\n inline T tutte_polynomial(T\
    \ x, T y) const {\n  int sum[sz], s, t, lim= 2, i, j;\n  T fum[10'000]= {0, 1};\n\
    \  std::vector<T> g= {0}, h;\n  for (g.reserve(sz), h.reserve(sz), i= 0; i < V;\
    \ i++) {\n   for (sum[0]= j= 0; j < i; j++)\n    for (s= t= 1 << j; s--;) sum[s\
    \ | t]= sum[s] + adj[i][j];\n   for (h.resize(s= 1 << i); s--; h[s]= g[s] * fum[sum[s]])\n\
    \    for (; lim <= sum[s]; lim++) fum[lim]= fum[lim - 1] * y + 1;\n   h= SPS::exp(h),\
    \ std::copy(h.begin(), h.end(), std::back_inserter(g));\n  }\n  for (x-= 1, t=\
    \ ~0, j= 0, i= V; i--;) j+= adj[i][i];\n  for (bfs((s= sz) - 1, [&](int u) { t^=\
    \ u; }); --s&= t;) g[s]*= x;\n  return SPS::exp(g)[sz - 1] * pow(y, j);\n }\n\
    };\n#line 9 \"test/atcoder/arc105_f.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N, M;\n  cin >> N >> M;\n  UndirectedGraphSetPowerSeries<17> g(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b;\n    g.add_edge(--a,\
    \ --b);\n  }\n  cout << g.connected_biparate_graph_num<Mint>()[(1 << N) - 1] <<\
    \ '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc105/tasks/arc105_f\"\n\n\
    // \u9023\u7D50\u4E8C\u90E8\u30B0\u30E9\u30D5\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/Math/SetPowerSeries.hpp\"\n#include\
    \ \"src/Graph/UndirectedGraphSetPowerSeries.hpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N, M;\n  cin >> N >> M;\n  UndirectedGraphSetPowerSeries<17> g(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b;\n    g.add_edge(--a,\
    \ --b);\n  }\n  cout << g.connected_biparate_graph_num<Mint>()[(1 << N) - 1] <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/SetPowerSeries.hpp
  - src/Graph/UndirectedGraphSetPowerSeries.hpp
  isVerificationFile: true
  path: test/atcoder/arc105_f.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 22:09:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc105_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc105_f.test.cpp
- /verify/test/atcoder/arc105_f.test.cpp.html
title: test/atcoder/arc105_f.test.cpp
---
