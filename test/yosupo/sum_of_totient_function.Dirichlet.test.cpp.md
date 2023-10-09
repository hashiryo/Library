---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: src/Math/DirichletSeries.hpp
    title: "\u30C7\u30A3\u30EA\u30AF\u30EC\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.Dirichlet.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    // O(N^(2/3)log^(1/3)N))\n#include <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n\
    \ CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod)\
    \ DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const\
    \ { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n)\
    \ * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2():\
    \ mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL\
    \ u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod <<\
    \ 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE\
    \ IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\n\
    private:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x) >> 84;\
    \ }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n};\nstruct\
    \ MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0)\
    \ {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    };\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n\
    \ for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate\
    \ <class mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Math/DirichletSeries.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cmath>\n#line 6 \"src/Math/DirichletSeries.hpp\"\
    \n#include <numeric>\ntemplate <class T> struct DirichletSeries {\n using Self=\
    \ DirichletSeries;\n uint64_t N;  // <= K * L\n size_t K;\n // x: i (1 <= i <=\
    \ K), Xl : 1+2+...+\u230AN/i\u230B (1 <= i <= L)\n std::vector<T> x, Xs, Xl;\n\
    \ DirichletSeries(uint64_t N, const std::vector<T> &x, const std::vector<T> &Xs,\
    \ const std::vector<T> &Xl): N(N), K(x.size() - 1), x(x), Xs(Xs), Xl(Xl) { assert(K\
    \ + 1 == Xs.size()), assert(N < uint64_t(K) * Xl.size()); }\n DirichletSeries(uint64_t\
    \ N, bool unit= false): N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N\
    \ / std::log2(N), 2. / 3)), std::sqrt(N) + 1) : 1) {\n  if (assert(N > 0), x.resize(K\
    \ + 1), Xs.resize(K + 1), Xl.resize(size_t(double(N - 1 + K) / K) + 1); unit)\
    \ x[1]= 1, std::fill(Xl.begin() + 1, Xl.end(), 1), std::fill(Xs.begin() + 1, Xs.end(),\
    \ 1);\n }\n template <class F, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F,\
    \ uint64_t>, T>, std::nullptr_t> = nullptr> DirichletSeries(uint64_t N, const\
    \ F &sum): DirichletSeries(N) {\n  for (size_t i= Xs.size(); --i;) Xs[i]= sum(i);\n\
    \  for (size_t i= x.size(); --i;) x[i]= Xs[i] - Xs[i - 1];\n  for (size_t i= Xl.size();\
    \ --i;) Xl[i]= sum(uint64_t((double)N / i));\n }\n Self &operator*=(const T &r)\
    \ {\n  for (size_t i= x.size(); --i;) x[i]*= r;\n  for (size_t i= Xs.size(); --i;)\
    \ Xs[i]*= r;\n  for (size_t i= Xl.size(); --i;) Xl[i]*= r;\n  return *this;\n\
    \ }\n Self operator*(const T &r) const { return Self(*this)*= r; }\n Self &operator+=(const\
    \ Self &r) {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  for (size_t i= x.size(); --i;) x[i]+= r.x[i];\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]+= r.Xs[i];\n  for (size_t i= Xl.size(); --i;) Xl[i]+= r.Xl[i];\n\
    \  return *this;\n }\n Self &operator-=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(Xl.size() == r.Xl.size());\n  for (size_t i= x.size();\
    \ --i;) x[i]-= r.x[i];\n  for (size_t i= Xs.size(); --i;) Xs[i]-= r.Xs[i];\n \
    \ for (size_t i= Xl.size(); --i;) Xl[i]-= r.Xl[i];\n }\n Self operator+(const\
    \ Self &r) const { return Self(*this)+= r; }\n Self operator-(const Self &r) const\
    \ { return Self(*this)-= r; }\n Self operator-() const {\n  std::vector<T> a(x.size()),\
    \ As(Xl.size()), A(Xl.size());\n  for (size_t i= x.size(); --i;) a[i]= -x[i];\n\
    \  for (size_t i= Xs.size(); --i;) As[i]= -Xs[i];\n  for (size_t i= Xl.size();\
    \ --i;) A[i]= -Xl[i];\n  return Self(N, a, As, A);\n }\n Self &operator+=(const\
    \ T &r) {\n  for (size_t i= Xl.size(); --i;) Xl[i]+= r;\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]+= r;\n  return x[1]+= r, *this;\n }\n Self &operator-=(const T &r)\
    \ {\n  for (size_t i= Xl.size(); --i;) Xl[i]-= r;\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]-= r;\n  return x[1]-= r, *this;\n }\n Self operator+(const T &r)\
    \ const { return Self(*this)+= r; }\n Self operator-(const T &r) const { return\
    \ Self(*this)-= r; }\n friend Self operator+(const T &l, Self r) { return r+=\
    \ l; }\n friend Self operator-(const T &l, Self r) { return -(r-= l); }\n friend\
    \ Self operator*(const T &l, Self r) { return r*= l; }\n friend Self operator/(const\
    \ T &l, Self r) { return (Self(r.N, true)/= r)*= l; }\n Self operator*(const Self\
    \ &r) const {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n  uint64_t n;\n  for (size_t\
    \ i= K, j; i; --i)\n   for (j= K / i; j; --j) c[i * j]+= x[i] * r.x[j];\n  for\
    \ (size_t l= Xl.size(), m, i; --l; C[l]-= sum(m) * r.sum(m))\n   for (i= m= std::sqrt(n=\
    \ (double)N / l); i; --i) C[l]+= x[i] * r.sum((double)n / i) + r.x[i] * sum((double)n\
    \ / i);\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n  return Self(N,\
    \ c, Cs, C);\n }\n Self &operator*=(const Self &r) { return *this= *this * r;\
    \ }\n Self operator/(const Self &r) const { return Self(*this)/= r; }\n Self &operator/=(const\
    \ Self &r) {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  for (size_t i= 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1], j= 2, ed= K /\
    \ i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n  for (size_t i= 1; i <= K; ++i)\
    \ Xs[i]= Xs[i - 1] + x[i];\n  uint64_t n;\n  for (size_t l= Xl.size(), m; --l;\
    \ Xl[l]/= r.x[1])\n   for (m= std::sqrt(n= (double)N / l), Xl[l]+= r.sum(m) *\
    \ sum(m) - x[1] * r.sum(n); m > 1;) Xl[l]-= r.x[m] * sum((double)n / m) + x[m]\
    \ * r.sum((double)n / m), --m;\n  return *this;\n }\n Self square() const {\n\
    \  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ c[i * j]+= x[i] * x[j];\n  for (i= K; i; --i) c[i]+= c[i];\n  for (i= l; i;\
    \ --i) c[i * i]+= x[i] * x[i];\n  for (l= Xl.size(); --l; C[l]+= C[l], C[l]-=\
    \ tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i) C[l]+=\
    \ x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1]\
    \ + c[i];\n  return Self(N, c, Cs, C);\n }\n Self pow(uint64_t M) const {\n  const\
    \ size_t L= Xl.size() - 1;\n  if (N / M > M)\n   for (auto ret= Self(N, true),\
    \ b= *this;; b= b.square()) {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return\
    \ ret;\n   }\n  size_t n= 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M\
    \ && (1ULL << n) <= N) ++n;\n  Self ret(N);\n  T pw[65]= {1}, b= x[1], tmp;\n\
    \  for (e= M - n + 1;; b*= b)\n   if (e & 1 ? pw[0]*= b : T(); !(e>>= 1)) break;\n\
    \  for (m= 1; m < n; ++m) pw[m]= pw[m - 1] * x[1];\n  std::vector<T> Al(Xl), z(K\
    \ + 1, 0), Z(L + 1, 0), As(Xs);\n  for (i= K; i; --i) As[i]-= x[1];\n  for (i=\
    \ L; i; --i) Al[i]-= x[1];\n  auto A= [&](uint64_t n) { return n <= K ? As[n]\
    \ : Al[(double)N / n]; };\n  std::vector<T> y(x), Y(Al), Bs(As), c(y), Cs(K +\
    \ 1), C(Y);\n  auto B= [&](uint64_t n) { return n <= K ? Bs[n] : Y[(double)N /\
    \ n]; };\n  for (tmp= pw[n - 2] * M, l= L; l; l--) C[l]*= tmp;\n  for (i= 2; i\
    \ <= K; ++i) c[i]*= tmp;\n  for (c[1]= pw[n - 1], l= L; l; l--) C[l]+= c[1];\n\
    \  for (m= 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m +\
    \ 1 < n;) {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; C[l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) c[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(Z.begin() + 1, l, 0); p * 2 <= K) std::fill(z.begin() + p * 2, z.end(),\
    \ 0);\n   if (p <= K)\n    for (Bs[p]= y[p], i= p + 1; i <= K; ++i) Bs[i]= Bs[i\
    \ - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n\
    \  return Self(N, c, Cs, C);\n }\n inline T sum() const { return Xl[1]; }\n inline\
    \ T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[(double)N / n]; }\n};\n\
    template <class T>  // 1, zeta(s), O(N)\nDirichletSeries<T> get_1(uint64_t N)\
    \ {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.Xl.size(); --i;) ret.Xl[i]=\
    \ uint64_t((double)N / i);\n return std::fill(ret.x.begin() + 1, ret.x.end(),\
    \ T(1)), std::iota(ret.Xs.begin(), ret.Xs.end(), 0), ret;\n}\n// M\xF6bius, 1/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_mu(uint64_t\
    \ N) { return DirichletSeries<T>(N, true)/= get_1<T>(N); }\ntemplate <class T>\
    \  // n, zeta(s-1)\nDirichletSeries<T> get_Id(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a;\n for (size_t l= ret.Xl.size(); --l;) a= (double)N\
    \ / l, ret.Xl[l]= (a * (a + 1)) >> 1;\n std::iota(ret.x.begin(), ret.x.end(),\
    \ 0);\n for (size_t i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n\
    \ return ret;\n}\ntemplate <class T>  // n^2, zeta(s-2), O(N)\nDirichletSeries<T>\
    \ get_Id2(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a, b, c;\n\
    \ for (size_t l= ret.Xl.size(); --l;) a= (double)N / l, b= (a * (a + 1)) >> 1,\
    \ c= (a + a + 1), ret.Xl[l]= c % 3 == 0 ? T(c / 3) * b : T(b / 3) * c;\n for (uint64_t\
    \ i= ret.x.size(); --i;) ret.x[i]= i * i;\n for (size_t i= 1; i <= ret.K; ++i)\
    \ ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n return ret;\n}\n// number-of-divisors,\
    \ zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_d(uint64_t N) { return get_1<T>(N).square(); }\n// sum-of-divisors, zeta(s)zeta(s-2),\
    \ function, O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_sigma(uint64_t\
    \ N) { return get_1<T>(N) * get_Id<T>(N); }\n// Euler's totient, zeta(s-1)/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_phi(uint64_t\
    \ N) { return get_Id<T>(N)/= get_1<T>(N); }\ntemplate <class T>  // zeta(2s),\
    \ O(N)\nDirichletSeries<T> get_1sq(uint64_t N) {\n DirichletSeries<T> ret(N);\n\
    \ for (size_t i= 1, e= ret.x.size(); i * i <= e; ++i) ret.x[i * i]= 1;\n for (size_t\
    \ i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n for (size_t l=\
    \ ret.Xl.size(); --l;) ret.Xl[l]= uint64_t(std::sqrt((double)N / l));\n return\
    \ ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/= get_1<T>(N);\
    \ }\n// |\xB5|, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N); }\n#line 6 \"test/yosupo/sum_of_totient_function.Dirichlet.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n long long N;\n cin >> N;\n cout << get_phi<Mint>(N).sum()\
    \ << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n// O(N^(2/3)log^(1/3)N))\n#include <iostream>\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Math/DirichletSeries.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ long long N;\n cin >> N;\n cout << get_phi<Mint>(N).sum() << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/DirichletSeries.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 18:38:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
- /verify/test/yosupo/sum_of_totient_function.Dirichlet.test.cpp.html
title: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
---
