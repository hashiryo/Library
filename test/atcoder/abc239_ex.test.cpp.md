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
    path: src/NumberTheory/DirichletSeries.hpp
    title: "\u30C7\u30A3\u30EA\u30AF\u30EC\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc239/tasks/abc239_Ex
    links:
    - https://atcoder.jp/contests/abc239/tasks/abc239_Ex
    - https://atcoder.jp/contests/abc239/tasks/abc239_h
  bundledCode: "#line 1 \"test/atcoder/abc239_ex.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc239/tasks/abc239_Ex\"\
    \n// https://atcoder.jp/contests/abc239/tasks/abc239_h\n#include <iostream>\n\
    #line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include <cassert>\n\
    template <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 2 \"src/NumberTheory/DirichletSeries.hpp\"\
    \n#include <valarray>\n#include <iterator>\n#include <algorithm>\n#include <cmath>\n\
    #line 7 \"src/NumberTheory/DirichletSeries.hpp\"\n#include <numeric>\n#include\
    \ <cstdint>\ntemplate <class T> struct DirichletSeries {\n using Self= DirichletSeries;\n\
    \ uint64_t N;  // <= K * L\n size_t K, L;\n std::valarray<T> x, X;\n DirichletSeries(uint64_t\
    \ N, bool unit= false): N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N\
    \ / std::log2(N), 2. / 3)), std::sqrt(N) + 1) : 1), L((N - 1 + K) / K), x(K +\
    \ 1), X(K + L + 1) {\n  if (assert(N > 0); unit) x[1]= 1, X= 1;\n }\n template\
    \ <class F, typename= std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F,\
    \ uint64_t>, T>>> DirichletSeries(uint64_t N, const F &sum): DirichletSeries(N)\
    \ {\n  for (size_t i= 1; i <= K; ++i) X[i]= sum(i);\n  for (size_t i= 1; i <=\
    \ L; ++i) X[K + i]= sum(uint64_t((double)N / i));\n  for (size_t i= K; i; --i)\
    \ x[i]= X[i] - X[i - 1];\n }\n Self operator-() const {\n  Self ret(N);\n  return\
    \ ret.x= -x, ret.X= -X, ret;\n }\n Self &operator+=(T r) { return x[1]+= r, X+=\
    \ r, *this; }\n Self &operator-=(T r) { return x[1]-= r, X-= r, *this; }\n Self\
    \ &operator*=(T r) { return x*= r, X*= r, *this; }\n Self &operator/=(T r) {\n\
    \  if (T iv= T(1) / r; iv == 0) x/= r, X/= r;\n  else x*= iv, X*= iv;\n  return\
    \ *this;\n }\n Self &operator+=(const Self &r) { return assert(N == r.N), assert(K\
    \ == r.K), assert(L == r.L), x+= r.x, X+= r.X, *this; }\n Self &operator-=(const\
    \ Self &r) { return assert(N == r.N), assert(K == r.K), assert(L == r.L), x-=\
    \ r.x, X-= r.X, *this; }\n Self operator+(T r) const { return Self(*this)+= r;\
    \ }\n Self operator-(T r) const { return Self(*this)-= r; }\n Self operator*(T\
    \ r) const { return Self(*this)*= r; }\n Self operator/(T r) const { return Self(*this)/=\
    \ r; }\n Self operator+(const Self &r) const { return Self(*this)+= r; }\n Self\
    \ operator-(const Self &r) const { return Self(*this)-= r; }\n friend Self operator+(T\
    \ l, Self r) { return r+= l; }\n friend Self operator-(T l, Self r) { return r.x[1]-=\
    \ l, r.X-= l, r.x= -r.x, r.X= -r.X, r; }\n friend Self operator*(T l, const Self\
    \ &r) { return r * l; }\n friend Self operator/(T l, const Self &r) { return (Self(r.N,\
    \ true)/= r)*= l; }\n Self operator*(const Self &r) const {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  Self ret(N);\n  uint64_t n;\n  for (size_t\
    \ i= K, j; i; --i)\n   for (j= K / i; j; --j) ret.x[i * j]+= x[i] * r.x[j];\n\
    \  for (size_t l= L, m, i; l; ret.X[K + l--]-= sum(m) * r.sum(m))\n   for (i=\
    \ m= std::sqrt(n= (double)N / l); i; --i) ret.X[K + l]+= x[i] * r.sum((double)n\
    \ / i) + r.x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self operator/(const Self &r)\
    \ const { return Self(*this)/= r; }\n Self &operator*=(const Self &r) { return\
    \ *this= *this * r; }\n Self &operator/=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  for (size_t i= 1, j, ed; i <= K; i++)\n\
    \   for (x[i]/= r.x[1], j= 2, ed= K / i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n\
    \  X[1]= x[1];\n  for (size_t i= 2; i <= K; ++i) X[i]= X[i - 1] + x[i];\n  uint64_t\
    \ n;\n  for (size_t l= L, m; l; X[K + l--]/= r.x[1])\n   for (m= std::sqrt(n=\
    \ (double)N / l), X[K + l]+= r.sum(m) * sum(m) - x[1] * r.sum(n); m > 1;) X[K\
    \ + l]-= r.x[m] * sum((double)n / m) + x[m] * r.sum((double)n / m), --m;\n  return\
    \ *this;\n }\n Self square() const {\n  Self ret(N);\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ ret.x[i * j]+= x[i] * x[j];\n  ret.x+= ret.x;\n  for (i= l; i; --i) ret.x[i\
    \ * i]+= x[i] * x[i];\n  for (l= L; l; ret.X[K + l]+= ret.X[K + l], ret.X[K +\
    \ l--]-= tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i)\
    \ ret.X[K + l]+= x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i)\
    \ ret.X[i]= ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self pow(uint64_t M)\
    \ const {\n  if (N / M > M)\n   for (auto ret= Self(N, true), b= *this;; b= b.square())\
    \ {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return ret;\n   }\n  size_t n=\
    \ 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M && (1ULL << n) <= N) ++n;\n\
    \  T pw[65]= {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n   if (e & 1 ?\
    \ pw[0]*= b : T(); !(e>>= 1)) break;\n  for (m= 1; m < n; ++m) pw[m]= pw[m - 1]\
    \ * x[1];\n  Self ret(*this);\n  std::valarray<T> D= (ret.X-= x[1]), E(std::begin(D),\
    \ K + 1), Y(std::begin(D) + K, L + 1), y= x, z(K + 1), Z(L + 1);\n  auto A= [&](uint64_t\
    \ n) { return n > K ? D[K + (double)N / n] : D[n]; };\n  auto B= [&](uint64_t\
    \ n) { return n > K ? Y[(double)N / n] : E[n]; };\n  for (tmp= pw[n - 2] * M,\
    \ l= L; l; l--) ret.X[K + l]*= tmp;\n  for (i= 2; i <= K; ++i) ret.x[i]*= tmp;\n\
    \  for (ret.x[1]= pw[n - 1], l= L; l; l--) ret.X[K + l]+= ret.x[1];\n  for (m=\
    \ 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m + 1 < n;)\
    \ {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; ret.X[K + l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) ret.x[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(std::begin(Z) + 1, l, 0); p * 2 <= K) std::fill(std::begin(z) +\
    \ p * 2, std::end(z), 0);\n   if (p <= K)\n    for (E[p]= y[p], i= p + 1; i <=\
    \ K; ++i) E[i]= E[i - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n inline T sum() const { return\
    \ X[K + 1]; }\n inline T sum(uint64_t n) const { return n > K ? X[K + (double)N\
    \ / n] : X[n]; }\n inline T operator()(uint64_t n) const { return n > K ? x[K\
    \ + (double)N / n] : x[n]; }\n};\n// 1, zeta(s), O(K+L)\ntemplate <class T> DirichletSeries<T>\
    \ get_1(uint64_t N) {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.L; i;\
    \ --i) ret.X[ret.K + i]= uint64_t((double)N / i);\n return std::fill(std::begin(ret.x)\
    \ + 1, std::end(ret.x), T(1)), std::iota(std::begin(ret.X), std::begin(ret.X)\
    \ + ret.K + 1, 0), ret;\n}\n// Mobius, 1/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_mu(uint64_t N) { return DirichletSeries<T>(N,\
    \ true)/= get_1<T>(N); }\n// n, zeta(s-1)\ntemplate <class T> DirichletSeries<T>\
    \ get_Id(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a;\n for (size_t\
    \ l= ret.L; l; --l) a= (double)N / l, ret.X[ret.K + l]= (a * (a + 1)) >> 1;\n\
    \ std::iota(std::begin(ret.x), std::end(ret.x), 0);\n for (size_t i= 1; i <= ret.K;\
    \ ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return ret;\n}\n// n^2, zeta(s-2),\
    \ O(K+L)\ntemplate <class T> DirichletSeries<T> get_Id2(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a, b, c;\n for (size_t l= ret.L; l; --l) a= (double)N\
    \ / l, b= (a * (a + 1)) >> 1, c= (a + a + 1), ret.X[ret.K + l]= c % 3 == 0 ? T(c\
    \ / 3) * b : T(b / 3) * c;\n for (uint64_t i= ret.K; i; --i) ret.x[i]= i * i;\n\
    \ for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return\
    \ ret;\n}\n// number-of-divisors, zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_d(uint64_t N) { return get_1<T>(N).square();\
    \ }\n// sum-of-divisors, zeta(s)zeta(s-2), function, O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_sigma(uint64_t N) { return get_1<T>(N) * get_Id<T>(N);\
    \ }\n// Euler's totient, zeta(s-1)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_phi(uint64_t N) { return get_Id<T>(N)/= get_1<T>(N);\
    \ }\ntemplate <class T>  // zeta(2s), O(K+L)\nDirichletSeries<T> get_1sq(uint64_t\
    \ N) {\n DirichletSeries<T> ret(N);\n for (size_t i= 1, e= ret.x.size(); i * i\
    \ <= e; ++i) ret.x[i * i]= 1;\n for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i\
    \ - 1] + ret.x[i];\n for (size_t l= ret.L; l; --l) ret.X[ret.K + l]= uint64_t(std::sqrt((double)N\
    \ / l));\n return ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\n\
    template <class T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/=\
    \ get_1<T>(N); }\n// square-free, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N);\
    \ }\n#line 6 \"test/atcoder/abc239_ex.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using Mint= ModInt<int(1e9\
    \ + 7)>;\n int N, M;\n cin >> N >> M;\n auto hsum= [&](int) -> Mint { return N;\
    \ };\n auto gsum= [&](int x) -> Mint { return max(0, N - x); };\n DirichletSeries<Mint>\
    \ H(M, hsum), G(M, gsum);\n cout << (H / G).sum() << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc239/tasks/abc239_Ex\"\n\
    // https://atcoder.jp/contests/abc239/tasks/abc239_h\n#include <iostream>\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/NumberTheory/DirichletSeries.hpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<int(1e9 + 7)>;\n int N, M;\n cin >> N >> M;\n auto hsum=\
    \ [&](int) -> Mint { return N; };\n auto gsum= [&](int x) -> Mint { return max(0,\
    \ N - x); };\n DirichletSeries<Mint> H(M, hsum), G(M, gsum);\n cout << (H / G).sum()\
    \ << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/NumberTheory/DirichletSeries.hpp
  isVerificationFile: true
  path: test/atcoder/abc239_ex.test.cpp
  requiredBy: []
  timestamp: '2024-02-08 01:24:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc239_ex.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc239_ex.test.cpp
- /verify/test/atcoder/abc239_ex.test.cpp.html
title: test/atcoder/abc239_ex.test.cpp
---
