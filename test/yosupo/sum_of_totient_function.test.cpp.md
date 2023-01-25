---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':heavy_check_mark:'
    path: src/Math/DirichletConvSumTable.hpp
    title: "\u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C"
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
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n#include\
    \ <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b, b= c -\
    \ b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n const u_t iv, r2;\n static CE u_t inv(u_t n,\
    \ int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE\
    \ IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n const u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: const u8 s;\n const u64 x;\n CE IL u64 quo(u64 n)\
    \ const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n\
    \ - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n const u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n const u64 x;\n CE IL u128 quo(const u128 &n) const { return (n\
    \ * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_D2B1 {\n const u64 mod;\n CE MP_D2B1(): mod(0), s(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): mod(m), s(__builtin_clzll(m)), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    \ const u8 s;\n const u64 d, v;\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t\
    \ x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if\
    \ (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef\
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"src/Math/ModInt.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return\
    \ ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt& r), B::md.mul(x,\
    \ r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n CE\
    \ MInt operator/(const MInt& r) const { return *this * r.inv(); }\n CE MInt& operator+=(const\
    \ MInt& r) { return *this= *this + r; }\n CE MInt& operator-=(const MInt& r) {\
    \ return *this= *this - r; }\n CE MInt& operator*=(const MInt& r) { return *this=\
    \ *this * r; }\n CE MInt& operator/=(const MInt& r) { return *this= *this / r;\
    \ }\n CE bool operator==(const MInt& r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n CE bool operator!=(const MInt& r) const { return !(*this == r); }\n CE bool\
    \ operator<(const MInt& r) const { return B::md.norm(x) < B::md.norm(r.x); }\n\
    \ CE inline MInt inv() const { return mod_inv<Int>(val(), B::md.mod); }\n CE inline\
    \ Uint val() const { return B::md.get(x); }\n friend ostream& operator<<(ostream&\
    \ os, const MInt& r) { return os << r.val(); }\n friend istream& operator>>(istream&\
    \ is, MInt& r) {\n  i64 v;\n  return is >> v, r= MInt(v), is;\n }\nprivate:\n\
    \ Uint x;\n};\ntemplate <u64 MOD> using ModInt= conditional_t < (MOD < (1 << 30))\
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t < (MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u\
    \ << 31), MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\ntemplate <class\
    \ mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Math/DirichletConvSumTable.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <cmath>\n#line 6 \"src/Math/DirichletConvSumTable.hpp\"\
    \n#include <numeric>\ntemplate <class T> struct DirichletConvSumTable {\n std::uint64_t\
    \ N;  // <= K * L\n std::vector<T> x /* (1 <= i <= K) */, X /* \u2211^{N/i} (1\
    \ <= i <= L) */;\n static DirichletConvSumTable get_epsilon(std::uint64_t N, std::size_t\
    \ K) {\n  std::size_t L= (N - 1 + K) / K;\n  std::vector<T> a(K + 1, 0);\n  return\
    \ a[1]= 1, DirichletConvSumTable(N, a, std::vector<T>(L + 1, 1));\n }\n DirichletConvSumTable(std::uint64_t\
    \ n_, const std::vector<T> &x_, const std::vector<T> &X_): N(n_), x(x_), X(X_)\
    \ { assert(N < std::uint64_t(x.size()) * X.size()); }\n DirichletConvSumTable(std::uint64_t\
    \ n_, std::size_t k_): N(n_), x(k_ + 1, 0), X((n_ - 1 + k_) / k_ + 1, 0) {}\n\
    \ template <class F> DirichletConvSumTable(std::uint64_t n_, std::size_t k_, const\
    \ F &sum): N(n_), x(k_ + 1), X((n_ - 1 + k_) / k_ + 1) {\n  assert(N < std::uint64_t(x.size())\
    \ * X.size());\n  for (std::size_t i= x.size(); --i;) x[i]= sum(i);\n  for (std::size_t\
    \ i= x.size(); --i > 1;) x[i]-= x[i - 1];\n  for (std::size_t i= X.size(); --i;)\
    \ X[i]= sum(N / i);\n }\n DirichletConvSumTable operator*(const DirichletConvSumTable\
    \ &r) const {\n  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N\
    \ <= std::uint64_t(K) * L), assert(N == r.N);\n  assert(K == r.x.size() - 1),\
    \ assert(L == r.X.size() - 1);\n  std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K\
    \ + 1, 0), B_l(K + 1, 0);\n  for (std::size_t i= 1; i <= K; i++) A_l[i]= A_l[i\
    \ - 1] + x[i];\n  for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1] + r.x[i];\n\
    \  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : X[N / n]; };\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : r.X[N / n]; };\n  std::uint64_t\
    \ n;\n  for (std::size_t i= K, j; i; i--)\n   for (j= K / i; j; j--) c[i * j]+=\
    \ x[i] * r.x[j];\n  for (std::size_t l= L, m, i; l; C[l--]-= A(m) * B(m))\n  \
    \ for (i= m= std::sqrt(n= N / l); i; i--) C[l]+= x[i] * B(n / i) + r.x[i] * A(n\
    \ / i);\n  return DirichletConvSumTable<T>(N, c, C);\n }\n DirichletConvSumTable\
    \ &operator*=(const DirichletConvSumTable &r) { return *this= *this * r; }\n DirichletConvSumTable\
    \ operator/(const DirichletConvSumTable &r) const { return DirichletConvSumTable(*this)/=\
    \ r; }\n DirichletConvSumTable &operator/=(const DirichletConvSumTable &r) {\n\
    \  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N <= std::uint64_t(K)\
    \ * L), assert(N == r.N);\n  assert(K == r.x.size() - 1), assert(L == r.X.size()\
    \ - 1);\n  std::vector<T> A_l(K + 1, 0), B_l(K + 1, 0);\n  for (std::size_t i=\
    \ 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1], j= 2, ed= K / i; j <= ed; j++)\
    \ x[i * j]-= x[i] * r.x[j];\n  for (std::size_t i= 1; i <= K; i++) A_l[i]= A_l[i\
    \ - 1] + r.x[i];\n  for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1] + x[i];\n\
    \  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : r.X[N / n]; };\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : X[N / n]; };\n  std::uint64_t\
    \ n;\n  for (std::size_t l= L, m; l; X[l--]/= r.x[1])\n   for (m= std::sqrt(n=\
    \ N / l), X[l]+= A(m) * B(m) - x[1] * A(n); m > 1;) X[l]-= r.x[m] * B(n / m) +\
    \ x[m] * A(n / m), m--;\n  return *this;\n }\n DirichletConvSumTable square()\
    \ const {\n  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N <=\
    \ std::uint64_t(K) * L);\n  std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K + 1,\
    \ 0);\n  for (int i= 1; i <= K; i++) A_l[i]= A_l[i - 1] + x[i];\n  auto A= [&](std::uint64_t\
    \ n) { return n <= K ? A_l[n] : X[N / n]; };\n  std::size_t i, j, l= std::sqrt(K);\n\
    \  std::uint64_t n;\n  T tmp;\n  for (i= l; i; i--)\n   for (j= K / i; j > i;\
    \ j--) c[i * j]+= x[i] * x[j];\n  for (i= K; i; i--) c[i]+= c[i];\n  for (i= l;\
    \ i; i--) c[i * i]+= x[i] * x[i];\n  for (l= L; l; C[l]+= C[l], C[l--]-= tmp *\
    \ tmp)\n   for (tmp= A(i= std::sqrt(n= N / l)); i; i--) C[l]+= x[i] * A(n / i);\n\
    \  return DirichletConvSumTable<T>(N, c, C);\n }\n DirichletConvSumTable pow1(std::uint64_t\
    \ M) const {\n  for (auto ret= get_epsilon(N, x.size() - 1), b= *this;; b= b.square())\
    \ {\n   if (M & 1) ret*= b;\n   if (!(M>>= 1)) return ret;\n  }\n }\n DirichletConvSumTable\
    \ pow2(std::uint64_t M) const {\n  const std::size_t K= x.size() - 1, L= X.size()\
    \ - 1;\n  assert(N <= std::uint64_t(K) * L);\n  if (M == 0) return get_epsilon(N,\
    \ K);\n  if (M == 1) return *this;\n  std::size_t n= 0, m, i, l, p= 2;\n  std::uint64_t\
    \ e, j;\n  while (n <= M && (1ULL << n) <= N) n++;\n  DirichletConvSumTable ret(N,\
    \ x.size() - 1);\n  T pw[65]= {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n\
    \   if (e & 1 ? pw[0]*= b : 0; !(e>>= 1)) break;\n  for (m= 1; m < n; m++) pw[m]=\
    \ pw[m - 1] * x[1];\n  std::vector<T> XX(X), z(K + 1, 0), Z(L + 1, 0), A_l(K +\
    \ 1, 0);\n  for (i= 2; i <= K; i++) A_l[i]= A_l[i - 1] + x[i];\n  for (i= L; i;\
    \ i--) XX[i]-= x[1];\n  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n]\
    \ : XX[N / n]; };\n  std::vector<T> y(x), Y(XX), B_l(A_l), c(y), C(Y);\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : Y[N / n]; };\n  for (tmp=\
    \ pw[n - 2] * M, l= L; l; l--) C[l]*= tmp;\n  for (i= 2; i <= K; i++) c[i]*= tmp;\n\
    \  for (c[1]= pw[n - 1], l= L; l; l--) C[l]+= c[1];\n  for (m= 1, b= M, l= std::min<std::uint64_t>(L,\
    \ N / p / 2); m + 1 < n;) {\n   b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m];\n\
    \   for (; l; C[l--]+= Z[l] * tmp) {\n    for (i= j= std::sqrt(e= N / l); i >=\
    \ p; i--) Z[l]+= y[i] * A(e / i);\n    for (i= std::min(j, e / p); i >= 2; i--)\
    \ Z[l]+= x[i] * B(e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i=\
    \ K; i >= p; i--)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n \
    \  for (i= p= 1 << m; i <= K; i++) c[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   l= std::min<std::uint64_t>(L, N / p / 2);\n   y.swap(z), Y.swap(Z), std::fill_n(Z.begin()\
    \ + 1, l, 0);\n   if (p * 2 <= K) std::fill(z.begin() + p * 2, z.end(), 0);\n\
    \   if (p <= K)\n    for (B_l[p]= y[p], i= p + 1; i <= K; i++) B_l[i]= B_l[i -\
    \ 1] + y[i];\n  }\n  return DirichletConvSumTable<T>(N, c, C);\n }\n inline T\
    \ sum() const { return X[1]; }\n};\ntemplate <class T>  // zeta(s)\nDirichletConvSumTable<T>\
    \ get_1(std::uint64_t N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n\
    \ std::vector<T> A(L + 1);\n for (std::size_t l= L; l; l--) A[l]= N / l;\n return\
    \ DirichletConvSumTable<T>(N, std::vector<T>(K + 1, 1), A);\n}\ntemplate <class\
    \ T>  // M\xF6bius, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T> get_mu(std::uint64_t\
    \ N, std::size_t K) {\n return DirichletConvSumTable<T>::get_epsilon(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // zeta(s-1)\nDirichletConvSumTable<T> get_Id(std::uint64_t\
    \ N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n std::vector<T> a(K +\
    \ 1), A(L + 1);\n for (std::size_t l= L; l; l--) A[l]= N / l, (A[l]*= A[l] + 1)/=\
    \ 2;\n return std::iota(a.begin(), a.end(), 0), DirichletConvSumTable<T>(N, a,\
    \ A);\n}\ntemplate <class T>  // Euler's totient, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_phi(std::uint64_t N, std::size_t K) {\n return get_Id<T>(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // zeta(2s)\nDirichletConvSumTable<T> get_1sq(std::uint64_t\
    \ N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n std::vector<T> a(K +\
    \ 1, 0), A(L + 1);\n for (std::size_t i= 1; i * i <= K; i++) a[i * i]= 1;\n for\
    \ (std::size_t l= L; l; l--) A[l]= sqrt(N / l);\n return DirichletConvSumTable<T>(N,\
    \ a, A);\n}\ntemplate <class T>  // Liouville, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_lambda(std::uint64_t N, std::size_t K) {\n return get_1sq<T>(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // |\xB5|, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_absmu(std::uint64_t N, std::size_t K) {\n return get_1<T>(N, K) / get_1sq<T>(N,\
    \ K);\n}\ntemplate <class T>  // O(\u221AN)\nT dirichlet_mul_sum(const DirichletConvSumTable<T>\
    \ &a, const DirichletConvSumTable<T> &b) {\n const std::size_t K= a.x.size() -\
    \ 1, L= a.X.size() - 1, M= std::min(K, L);\n assert(a.N == b.N), assert(M <= b.x.size()\
    \ - 1), assert(M <= b.X.size() - 1);\n assert(std::uint64_t(M + 1) * (M + 1) >\
    \ a.N);\n T ret= 0, A= 0, B= 0;\n for (int i= M; i; i--) ret+= a.x[i] * b.X[i]\
    \ + b.x[i] * a.X[i];\n for (int i= M; i; i--) A+= a.x[i], B+= b.x[i];\n return\
    \ ret-= A * B;\n}\ntemplate <class mod_t>  // return \u2211g s.t. s+t\u2211g =\
    \ \u2211f*g\nauto SemiRelaxed(const DirichletConvSumTable<mod_t> &F, mod_t s,\
    \ mod_t t) {\n const std::size_t K= F.x.size() - 1, L= F.X.size() - 1;\n assert(F.N\
    \ <= std::uint64_t(K) * L), assert(F.x[1] != t);\n std::vector<mod_t> A_l(K +\
    \ 1, 0), B_l(K + 1, 0), g(K + 1, 0), G(L + 1, 0);\n g[1]= s;\n for (std::size_t\
    \ j= 1, i, ed; j <= K; j++)\n  for (g[j]/= F.x[1] - t, i= 2, ed= K / j; i <= ed;\
    \ i++) g[i * j]-= F.x[i] * g[j];\n for (std::size_t i= 1; i <= K; i++) A_l[i]=\
    \ A_l[i - 1] + F.x[i];\n for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1]\
    \ + g[i];\n auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : F.X[F.N /\
    \ n]; };\n auto B= [&](std::uint64_t n) { return n <= K ? B_l[n] : G[F.N / n];\
    \ };\n std::uint64_t n;\n for (std::size_t l= L, m; l; (G[l--]+= s)/= F.x[1] -\
    \ t)\n  for (m= std::sqrt(n= F.N / l), G[l]= A(m) * B(m) - g[1] * A(n); m > 1;)\
    \ G[l]-= F.x[m] * B(n / m) + g[m] * A(n / m), m--;\n return DirichletConvSumTable<mod_t>(F.N,\
    \ g, G);\n}\n#line 5 \"test/yosupo/sum_of_totient_function.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint=\
    \ ModInt<998244353>;\n long long N;\n cin >> N;\n cout << get_phi<Mint>(N, powl(N,\
    \ 2. / 3)).sum() << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include <iostream>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/DirichletConvSumTable.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n long long N;\n cin >> N;\n cout << get_phi<Mint>(N,\
    \ powl(N, 2. / 3)).sum() << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Math/DirichletConvSumTable.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 17:48:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.test.cpp
- /verify/test/yosupo/sum_of_totient_function.test.cpp.html
title: test/yosupo/sum_of_totient_function.test.cpp
---
