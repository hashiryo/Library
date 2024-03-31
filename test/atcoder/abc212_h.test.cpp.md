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
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Math/set_power_series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc212/tasks/abc212_h
    links:
    - https://atcoder.jp/contests/abc212/tasks/abc212_h
  bundledCode: "#line 1 \"test/atcoder/abc212_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc212/tasks/abc212_h\"\
    \n// \u30A2\u30C0\u30DE\u30FC\u30EB\u5909\u63DB\n#include <iostream>\n#include\
    \ <algorithm>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b * q;\n\
    \ return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\
    \nnamespace math_internal {\nusing namespace std;\nusing u8= unsigned char;\n\
    using u32= unsigned;\nusing i64= long long;\nusing u64= unsigned long long;\n\
    using u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n#define NORM\
    \ \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U\
    \ l, U r) const { return l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M)\
    \ \\\n CE IL U diff(U l, U r) const { return l-= r, l >> C ? l + (M) : l; }\n\
    #define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U\
    \ get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate\
    \ <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
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
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 3 \"src/Math/set_power_series.hpp\"\
    \n#include <vector>\n#line 5 \"src/Math/set_power_series.hpp\"\nnamespace sps\
    \ {\nnamespace _sps_internal {\nusing namespace std;\n#define _ZETA(s, l) \\\n\
    \ if constexpr (!t) A[s + l]+= A[s]; \\\n else if constexpr (t == 1) A[s + l]-=\
    \ A[s]; \\\n else if constexpr (t == 2) A[s]+= A[s + l]; \\\n else if constexpr\
    \ (t == 3) A[s]-= A[s + l]; \\\n else tie(A[s], A[s + l])= make_pair(A[s] + A[s\
    \ + l], A[s] - A[s + l]);\ntemplate <int t, class T> void rec(T A[], int l) {\n\
    \ if (l > 127) {\n  l>>= 1, rec<t>(A, l), rec<t>(A + l, l);\n  for (int s= 0;\
    \ s < l; ++s) _ZETA(s, l);\n } else\n  for (int k= 1; k < l; k<<= 1)\n   for (int\
    \ i= 0; i < l; i+= k + k)\n    for (int j= 0; j < k; ++j) _ZETA(i + j, k);\n}\n\
    #undef _ZETA\n/*  f -> g s.t. g[S] = sum_{T subseteq S} f[T]  O(n 2^n) */\ntemplate\
    \ <class T> void subset_zeta(vector<T>& f) { rec<0>(f.data(), f.size()); }\n/*\
    \  f -> h s.t. f[S] = sum_{T subseteq S} h[T]  O(n 2^n) */\ntemplate <class T>\
    \ void subset_mobius(vector<T>& f) { rec<1>(f.data(), f.size()); }\n/*  f -> g\
    \ s.t. g[S] = sum_{S subseteq T} f[T]  O(n 2^n) */\ntemplate <class T> void supset_zeta(vector<T>&\
    \ f) { rec<2>(f.data(), f.size()); }\n/*  f -> h s.t. f[S] = sum_{S subseteq T}\
    \ h[T]  O(n 2^n) */\ntemplate <class T> void supset_mobius(vector<T>& f) { rec<3>(f.data(),\
    \ f.size()); }\n/* h[S] = sum_{U | T == S} f[U]g[T]  O(n 2^n) */\ntemplate <class\
    \ T> vector<T> or_convolve(vector<T> f, vector<T> g) {\n subset_zeta(f), subset_zeta(g);\n\
    \ for (int s= f.size(); s--;) f[s]*= g[s];\n return subset_mobius(f), f;\n}\n\
    /* h[S] = sum_{U & T == S} f[U]g[T]  O(n 2^n) */\ntemplate <class T> vector<T>\
    \ and_convolve(vector<T> f, vector<T> g) {\n supset_zeta(f), supset_zeta(g);\n\
    \ for (int s= f.size(); s--;) f[s]*= g[s];\n return supset_mobius(f), f;\n}\n\
    /* f -> g s.t. g[S] = sum_{T} (-1)^{|S & T|} f[T] */\ntemplate <class T> void\
    \ hadamard(vector<T>& f) { rec<4>(f.data(), f.size()); }\n/* h[S] = sum_{U ^ T\
    \ = S} f[U]g[T] */\ntemplate <class T> vector<T> xor_convolve(vector<T> f, vector<T>\
    \ g) {\n hadamard(f), hadamard(g);\n for (int s= f.size(); s--;) f[s]*= g[s];\n\
    \ hadamard(f);\n if (T iv= T(1) / f.size(); iv == 0)\n  for (int s= f.size();\
    \ s--;) f[s]/= f.size();\n else\n  for (int s= f.size(); s--;) f[s]*= iv;\n return\
    \ f;\n}\ntemplate <int t, class T> void rec_r(T A[], int l, int n, int c= 0) {\n\
    \ if (l >= (n << 4)) {\n  l>>= 1, rec_r<t>(A, l, n, c), rec_r<t>(A + l, l, n,\
    \ c + 1);\n  for (int s= l / n; s--;)\n   if constexpr (!t)\n    for (int d= 0,\
    \ e= __builtin_popcount(s) + c + 1; d < e; ++d) A[s * n + d + l]+= A[s * n + d];\n\
    \   else\n    for (int d= __builtin_popcount(s) + c + 1; d < n; ++d) A[s * n +\
    \ d + l]-= A[s * n + d];\n } else\n  for (int k= 1, m= l / n; k < m; k<<= 1)\n\
    \   for (int i= 0; i < m; i+= k + k)\n    for (int j= 0; j < k; ++j)\n     if\
    \ constexpr (!t)\n      for (int u= i + j, s= u + k, d= 0, e= __builtin_popcount(s)\
    \ + c; d < e; ++d) A[s * n + d]+= A[u * n + d];\n     else\n      for (int u=\
    \ i + j, s= u + k, d= __builtin_popcount(s) + c; d < n; ++d) A[s * n + d]-= A[u\
    \ * n + d];\n}\ntemplate <class T> void rnk_zeta(const T f[], T F[], int n) {\n\
    \ for (int s= 1 << n; s--;) F[s * (n + 1) + __builtin_popcount(s)]= f[s];\n rec_r<0>(F,\
    \ (n + 1) << n, n + 1);\n}\ntemplate <class T> void rnk_mobius(T F[], T f[], int\
    \ n) {\n rec_r<1>(F, (n + 1) << n, n + 1);\n for (int s= 1 << n; s--;) f[s]= F[s\
    \ * (n + 1) + __builtin_popcount(s)];\n}\ntemplate <class T> void cnv_(T A[],\
    \ T B[], int n) {\n for (int s= 1 << (n - 1); s--;) {\n  T t, *a= A + s * n, *b=\
    \ B + s * n;\n  for (int c= __builtin_popcount(s), d= min(2 * c, n - 1), e; d\
    \ >= c; a[d--]= t)\n   for (t= 0, e= d - c; e <= c; ++e) t+= a[e] * b[d - e];\n\
    \ }\n}\ntemplate <class T> void cnv_na(const T f[], const T g[], T h[], int N)\
    \ {\n for (int s= N, t; s--;)\n  for (h[t= s]= f[s] * g[0]; t; --t&= s) h[s]+=\
    \ f[s ^ t] * g[t];\n}\n// fg, O(n^2 2^n)\ntemplate <class T> vector<T> convolve(const\
    \ vector<T>& f, const vector<T>& g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1))), assert(N == (int)g.size());\n vector<T> h(N);\n if (n\
    \ < 11) return cnv_na(f.data(), g.data(), h.data(), N), h;\n vector<T> F((n +\
    \ 1) << n);\n if (rnk_zeta(f.data(), F.data(), n); f.data() == g.data()) return\
    \ cnv_(F.data(), F.data(), n + 1), rnk_mobius(F.data(), h.data(), n), h;\n vector<T>\
    \ G((n + 1) << n);\n return rnk_zeta(g.data(), G.data(), n), cnv_(F.data(), G.data(),\
    \ n + 1), rnk_mobius(F.data(), h.data(), n), h;\n}\ntemplate <class T> void div_na(T\
    \ f[], const T g[], int N) {\n for (int s= 1; s < N; ++s)\n  for (int t= s; t;\
    \ --t&= s) f[s]-= f[s ^ t] * g[t];\n}\n// 1/f, \"f[empty] = 1\" is required, O(n^2\
    \ 2^n)\ntemplate <class T> vector<T> inv(const vector<T>& f) {\n const int N=\
    \ f.size(), n= __builtin_ctz(N);\n assert(!(N & (N - 1))), assert(f[0] == 1);\n\
    \ vector<T> h(N);\n if (n < 11) return h[0]= 1, div_na(h.data(), f.data(), N),\
    \ h;\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f.data(), G.data(),\
    \ n);\n for (int s= N; s--;) {\n  T *a= F.data() + s * (n + 1), *b= G.data() +\
    \ s * (n + 1);\n  a[0]= 1;\n  for (int d= 0, c= __builtin_popcount(s); d++ < n;)\n\
    \   for (int e= max(0, d - c); e < d; ++e) a[d]-= a[e] * b[d - e];\n }\n return\
    \ rnk_mobius(F.data(), h.data(), n), h;\n}\n// f/g, \"f[empty] = 1\" is required,\
    \ O(n^2 2^n)\ntemplate <class T> vector<T> div(vector<T> f, const vector<T>& g)\
    \ {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N & (N - 1))), assert(N\
    \ == (int)g.size()), assert(g[0] == 1);\n if (n < 12) return div_na(f.data(),\
    \ g.data(), N), f;\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f.data(),\
    \ F.data(), n), rnk_zeta(g.data(), G.data(), n);\n for (int s= N; s--;) {\n  T\
    \ *a= F.data() + s * (n + 1), *b= G.data() + s * (n + 1);\n  for (int d= 0, c=\
    \ __builtin_popcount(s); d++ < n;)\n   for (int e= max(0, d - c); e < d; ++e)\
    \ a[d]-= a[e] * b[d - e];\n }\n return rnk_mobius(F.data(), f.data(), n), f;\n\
    }\ntemplate <class T, class P> void oncnv_(const T f[], T h[], const P& phi, int\
    \ n) {\n vector<T> F((n + 1) << n), G((n + 1) << n);\n rnk_zeta(f, F.data(), n),\
    \ fill_n(G.data(), 1 << n, h[0]);\n T* a= G.data() + (1 << n);\n for (int l= 1\
    \ << n; l>>= 1;) phi(l, a[l]= h[0] * f[l]), h[l]= a[l];\n for (int d= 2, s; d\
    \ <= n; ++d) {\n  for (rec<0>(a, 1 << n), a+= (s= 1 << n); --s;)\n   if (int c=\
    \ __builtin_popcount(s); c <= d && d <= 2 * c)\n    for (int e= d; e--;) a[s]+=\
    \ G[e << n | s] * F[s * (n + 1) + d - e];\n  for (rec<1>(a, 1 << n), s= 1 << n;\
    \ --s;)\n   if (__builtin_popcount(s) == d) phi(s, a[s]), h[s]= a[s];\n   else\
    \ a[s]= 0;\n }\n}\n// h[S] = phi(S, sum_{T subsetneq S} h[T]f[S/T] )  O(n^2 2^n)\n\
    // phi: [](int, T&x)\ntemplate <class T, class P> vector<T> semi_relaxed_convolve(const\
    \ vector<T>& f, T init, const P& phi) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n vector<T> h(N);\n if (h[0]= init; n < 12) {\n  for\
    \ (int s= 1, t; s < N; phi(s, h[s]), ++s)\n   for (t= s; t; --t&= s) h[s]+= h[s\
    \ ^ t] * f[t];\n } else oncnv_(f.data(), h.data(), phi, n);\n return h;\n}\n//\
    \ h[S] = phi(S, 1/2 sum_{empty neq T subseteq S} h[T]h[S/T] )  O(n^2 2^n)\n//\
    \ phi: [](int, T&x)\ntemplate <class T, class P> vector<T> self_relaxed_convolve(const\
    \ P& phi, int n) {\n const int e= min(n, 12);\n int i= 0, l= 1;\n vector<T> f(1\
    \ << n);\n for (int u= 1; i < e; l<<= 1, ++i)\n  for (int s= 0; s < l; phi(u,\
    \ f[u]), ++s, ++u)\n   for (int t= s; t; --t&= s) f[u]+= f[u ^ t] * f[t];\n for\
    \ (; i < n; l<<= 1, ++i)\n  phi(l, f[l]), oncnv_(\n                    f.data(),\
    \ f.data() + l, [&](int s, T& x) { phi(s | l, x); }, i);\n return f;\n}\n// exp(f)\
    \ , \"f[empty] = 0\" is required,  O(n^2 2^n)\ntemplate <class T> vector<T> exp(const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n int i= 0, l=\
    \ 1;\n for (h[0]= 1; i < e; l<<= 1, ++i) cnv_na(h.data(), f.data() + l, h.data()\
    \ + l, l);\n for (; i < n; l<<= 1, ++i) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  rnk_zeta(h.data(), F.data(), i), rnk_zeta(f.data() + l, G.data(),\
    \ i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h.data() + l, i);\n\
    \ }\n return h;\n}\n// log(f) , \"f[empty] = 1\" is required,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> log(const vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N),\
    \ e= min(n, 12);\n assert(!(N & (N - 1))), assert(f[0] == 1);\n vector<T> h= f;\n\
    \ int i= 0, l= 1;\n for (h[0]= 0; i < e; l<<= 1, ++i) div_na(h.data() + l, f.data(),\
    \ l);\n if (i < n) {\n  vector<T> G(n << (n - 1));\n  rnk_zeta(f.data(), G.data(),\
    \ n - 1);\n  for (; i < n; l<<= 1, ++i) {\n   vector<T> F((i + 1) << i, 0);\n\
    \   if constexpr (is_floating_point_v<T>) {\n    fill_n(F.data(), l, h[l]= f[l]);\n\
    \    T* a= F.data() + l;\n    for (int m= l; m>>= 1;) h[l | m]= a[m]= f[l | m]\
    \ - h[l] * f[m];\n    for (int d= 2, s; d <= i; ++d) {\n     for (rec<0>(a, l),\
    \ a+= (s= l); --s;)\n      if (int c= __builtin_popcount(s); c <= d && d <= 2\
    \ * c)\n       for (int e= d; e--;) a[s]+= F[e << i | s] * G[s * n + d - e];\n\
    \     for (rec<1>(a, l), s= l; --s;)\n      if (__builtin_popcount(s) == d) h[l\
    \ | s]= a[s]= f[l | s] - a[s];\n      else a[s]= 0;\n    }\n   } else {\n    rnk_zeta(f.data()\
    \ + l, F.data(), i);\n    for (int s= l; s--;) {\n     T t, *a= F.data() + s *\
    \ (i + 1), *b= G.data() + s * n;\n     for (int d= 0, c= __builtin_popcount(s),\
    \ e; d++ < i; a[d]-= t)\n      for (t= 0, e= max(0, d - c); e < d; ++e) t+= a[e]\
    \ * b[d - e];\n    }\n    rnk_mobius(F.data(), h.data() + l, i);\n   }\n  }\n\
    \ }\n return h;\n}\n// F(f) =  sum_i F_i f^i/i! , \"f[empty] = 0\" is required,\
    \ O(n^2 2^n)\ntemplate <class T> vector<T> egf_comp(const vector<T>& F, const\
    \ vector<T>& f) {\n const int N= f.size(), n= __builtin_ctz(N), e= min(n, 11);\n\
    \ assert(!(N & (N - 1))), assert(f[0] == 0);\n vector<T> h(N);\n T* b= h.data()\
    \ + N;\n for (int i= n - F.size(); i++ < n;) h[N - (1 << i)]= F[n - i];\n int\
    \ i= 0, l= 1;\n for (; i < e; l<<= 1, ++i)\n  for (int j= N >> 1; j >= l; j>>=\
    \ 1) cnv_na(b - j, f.data() + l, b - j - j + l, l);\n if (i < n) {\n  vector<T>\
    \ A(n << (n - 1)), B(n << (n - 1));\n  for (; i < n; l<<= 1, ++i) {\n   fill_n(B.data(),\
    \ (i + 1) << i, 0), rnk_zeta(f.data() + l, B.data(), i);\n   for (int j= N >>\
    \ 1; j >= l; j>>= 1) fill_n(A.data(), (i + 1) << i, 0), rnk_zeta(b - j, A.data(),\
    \ i), cnv_(A.data(), B.data(), i + 1), rnk_mobius(A.data(), b - j - j + l, i);\n\
    \  }\n }\n return h;\n}\n// P(f) = sum_{i=0}^m P_i f^i ,  O(n^2 2^n)\ntemplate\
    \ <class T> vector<T> poly_comp(vector<T> P, vector<T> f) {\n const int N= f.size(),\
    \ n= __builtin_ctz(N);\n assert(!(N & (N - 1)));\n vector<T> F(n + 1);\n for (int\
    \ j= 0, e= P.size();; ++j, --e) {\n  for (int i= e; i--;) (F[j]*= f[0])+= P[i];\n\
    \  if (j == n || e <= 1) break;\n  for (int i= 1; i < e; ++i) P[i - 1]= P[i] *\
    \ i;\n }\n return f[0]= 0, egf_comp(F, f);\n}\ntemplate <class T> vector<T> _egfT(const\
    \ T* b, T* h, int M, int n) {\n T *a, *d;\n vector<T> c(n + 1);\n int l= M;\n\
    \ if (int i= __builtin_ctz(M); i > 10) {\n  vector<T> F((i + 1) << i), G((i +\
    \ 1) << i);\n  for (int m, s; i > 10; fill_n(F.data(), (i + 1) << i, 0), rnk_zeta(h,\
    \ F.data(), i), cnv_(F.data(), G.data(), i + 1), rnk_mobius(F.data(), h, i), b-=\
    \ (l>>= 1), --i)\n   for (fill_n(G.data(), (i + 1) << i, 0), rnk_zeta(b, G.data(),\
    \ i), m= M; m > l; m>>= 1)\n    for (a= h + (m - l), fill_n(F.data(), (i + 1)\
    \ << i, 0), rnk_zeta(a + m - l, F.data(), i), cnv_(F.data(), G.data(), i + 1),\
    \ rec_r<1>(F.data(), (i + 1) << i, i + 1), s= l; s--;) a[s]+= F[s * (i + 1) +\
    \ __builtin_popcount(s)];\n }\n for (; l; cnv_na(h, b, h, l), b-= (l>>= 1))\n\
    \  for (int m= M, s, t; m > l; m>>= 1)\n   for (a= h + (m - l), d= a + (m - l),\
    \ s= l; s--;)\n    for (a[t= s]+= d[s] * b[0]; t; --t&= s) a[s]+= d[s ^ t] * b[t];\n\
    \ for (int i= 0; i <= n; ++i) c[i]= h[(1 << (n - i)) - 1];\n return c;\n}\n//\
    \ [X^{[n]}] f^k/k! for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T>\
    \ egf_T(vector<T> f) {\n const int N= f.size(), n= __builtin_ctz(N);\n assert(!(N\
    \ & (N - 1)));\n if (n == 0) return {1};\n if (n == 1) return {0, f[1]};\n return\
    \ _egfT(f.data() + (N >> 2), f.data() + (N >> 1), N >> 2, n);\n}\n// [X^{[n]}]\
    \ f^k/k! g for k=0,1,...,n , O(n^2 2^n)\ntemplate <class T> vector<T> egf_T(const\
    \ vector<T>& f, vector<T> g) {\n const int N= f.size(), n= __builtin_ctz(N);\n\
    \ assert(!(N & (N - 1)));\n if (n == 0) return {g[1]};\n return _egfT(f.data()\
    \ + (N >> 1), g.data(), N >> 1, n);\n}\n}\nusing _sps_internal::subset_zeta, _sps_internal::subset_mobius,\
    \ _sps_internal::supset_zeta, _sps_internal::supset_mobius, _sps_internal::hadamard,\
    \ _sps_internal::or_convolve, _sps_internal::and_convolve, _sps_internal::xor_convolve,\
    \ _sps_internal::convolve, _sps_internal::semi_relaxed_convolve, _sps_internal::self_relaxed_convolve,\
    \ _sps_internal::inv, _sps_internal::div, _sps_internal::exp, _sps_internal::log,\
    \ _sps_internal::egf_comp, _sps_internal::poly_comp, _sps_internal::egf_T;\n}\n\
    #line 7 \"test/atcoder/abc212_h.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ constexpr int n= 1 << 16;\n int N, K;\n cin >> N >> K;\n vector<Mint> a(n);\n\
    \ for (int i= 0, A; i < K; ++i) cin >> A, a[A]+= 1;\n sps::hadamard(a);\n for\
    \ (auto &x: a) x= x == 1 ? N : (x.pow(N) - 1) / (x - 1) * x;\n sps::hadamard(a);\n\
    \ Mint all= K == 1 ? N : (Mint(K).pow(N) - 1) / (K - 1) * K;\n cout << all - a[0]\
    \ / n << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc212/tasks/abc212_h\"\n//\
    \ \u30A2\u30C0\u30DE\u30FC\u30EB\u5909\u63DB\n#include <iostream>\n#include <algorithm>\n\
    #include \"src/Math/ModInt.hpp\"\n#include \"src/Math/set_power_series.hpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n constexpr int n= 1 << 16;\n int N, K;\n cin\
    \ >> N >> K;\n vector<Mint> a(n);\n for (int i= 0, A; i < K; ++i) cin >> A, a[A]+=\
    \ 1;\n sps::hadamard(a);\n for (auto &x: a) x= x == 1 ? N : (x.pow(N) - 1) / (x\
    \ - 1) * x;\n sps::hadamard(a);\n Mint all= K == 1 ? N : (Mint(K).pow(N) - 1)\
    \ / (K - 1) * K;\n cout << all - a[0] / n << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/set_power_series.hpp
  isVerificationFile: true
  path: test/atcoder/abc212_h.test.cpp
  requiredBy: []
  timestamp: '2024-02-23 11:54:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc212_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc212_h.test.cpp
- /verify/test/atcoder/abc212_h.test.cpp.html
title: test/atcoder/abc212_h.test.cpp
---