---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/FFT/NTT.hpp
    title: Number-Theoretic-Transform
  - icon: ':x:'
    path: src/FFT/sample_points_shift.hpp
    title: "\u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8"
  - icon: ':question:'
    path: src/Math/Combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069 (\u968E\u4E57\u524D\u8A08\u7B97)\
      \ ($\\mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/Sieve.hpp
    title: "\u7BE9\u306A\u3069"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/Combination.hpp\"\ntemplate <class mint,\
    \ std::size_t LIM= (1 << 24)> class Combination {\n static inline mint _fact[LIM],\
    \ _finv[LIM];\n static inline int lim= 0;\n static inline void set(int sz) {\n\
    \  if (lim > sz) return;\n  if (lim == 0) _fact[0]= 1, _finv[0]= 1, lim= 1;\n\
    \  for (int i= lim; i <= sz; i++) _fact[i]= _fact[i - 1] * i;\n  _finv[sz]= mint(1)\
    \ / _fact[sz];\n  for (int i= sz; i >= lim; i--) _finv[i - 1]= _finv[i] * i;\n\
    \  lim= sz + 1;\n }\npublic:\n static inline mint fact(int n) { return set(n),\
    \ n < 0 ? mint(0) : _fact[n]; }\n static inline mint finv(int n) { return set(n),\
    \ n < 0 ? mint(0) : _finv[n]; }\n static mint nPr(int n, int r) { return fact(n)\
    \ * finv(n - r); }\n static mint nCr(int n, int r) { return nPr(n, r) * finv(r);\
    \ }\n static mint nHr(int n, int r) { return !r ? mint(1) : nCr(n + r - 1, r);\
    \ }\n};\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z\
    \ - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod -\
    \ (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
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
    #line 3 \"src/Math/Sieve.hpp\"\ntemplate <int LIM= 1 << 24> class Sieve {\n static\
    \ inline int ps[LIM >> 4], lpf[LIM >> 1], lpfpw[LIM >> 1], psz= 0;\n static inline\
    \ std::int8_t lpfe[LIM >> 1];\n static inline void sieve(int N) {  // O(N)\n \
    \ static int n= 2, i= 1;\n  if (n == 2) ps[psz++]= 2, n++;\n  for (; n <= N; n+=\
    \ 2, i++) {\n   if (!lpf[i]) lpf[i]= ps[psz++]= n;\n   for (int j= 1, e= std::min(lpf[i],\
    \ N / n); j < psz && ps[j] <= e; j++) lpf[(ps[j] * n) >> 1]= ps[j];\n  }\n }\n\
    \ static inline void set_lpfe(int N) {  // O(N)\n  static int n= 3, i= 1;\n  if\
    \ (N < n) return;\n  sieve(N), std::copy(lpf + i, lpf + (N >> 1) + 1, lpfpw +\
    \ i);\n  for (std::fill(lpfe + i, lpfe + (N >> 1) + 1, 1); n <= N; n+= 2, i++)\n\
    \   if (int j= (n / lpf[i]) >> 1; lpf[i] == lpf[j]) lpfe[i]+= lpfe[j], lpfpw[i]*=\
    \ lpfpw[j];\n }\npublic:\n static int least_prime_factor(int n) { return sieve(n),\
    \ lpf[n]; }\n // O(log n)\n static std::map<int, short> factorize(int n) {\n \
    \ std::map<int, short> ret;\n  if (int t; !(n & 1)) ret[2]= t= __builtin_ctz(n),\
    \ n>>= t;\n  if (int i= n >> 1; n > 1)\n   for (set_lpfe(n); n > 1; i= n >> 1)\
    \ ret[lpf[i]]= lpfe[i], n/= lpfpw[i];\n  return ret;\n }\n // O(log n)\n static\
    \ std::vector<int> divisors(int n) {\n  std::vector<int> ret= {1};\n  for (auto\
    \ [p, e]: factorize(n))\n   for (std::size_t sz= ret.size(), pw= p; e--; pw*=\
    \ p)\n    for (int i= sz - 1; i >= 0; i--) ret.push_back(ret[i] * pw);\n  return\
    \ std::sort(ret.begin(), ret.end()), ret;\n }\n // O(N)\n static std::vector<int>\
    \ get_primes(int N) { return sieve(N), std::vector<int>(ps, std::upper_bound(ps,\
    \ ps + psz, N)); }\n template <class T, class F> static inline std::vector<T>\
    \ completely_multiplicative_table(int N, const F &f) {\n  std::vector<T> ret(N\
    \ + 1);\n  sieve(N);\n  for (int n= 3, i= 1; n <= N; n+= 2, i++) ret[n]= lpf[i]\
    \ == n ? f(n, 1) : ret[lpf[i]] * ret[n / lpf[i]];\n  if (int n= 4; 2 <= N)\n \
    \  for (ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= ret[2] * ret[n >> 1];\n  return\
    \ ret[1]= 1, ret;\n }\n template <class T, class F> static inline std::vector<T>\
    \ multiplicative_table(int N, const F &f) {\n  std::vector<T> ret(N + 1);\n  set_lpfe(N);\n\
    \  for (int n= 3, i= 1; n <= N; n+= 2, i++) ret[n]= lpfpw[i] == n ? f(lpf[i],\
    \ lpfe[i]) : ret[lpfpw[i]] * ret[n / lpfpw[i]];\n  for (int n= 2, t; n <= N; n+=\
    \ 2) t= __builtin_ctz(n), ret[n]= n & (n - 1) ? ret[n & -n] * ret[n >> t] : f(2,\
    \ t);\n  return ret[1]= 1, ret;\n }\n // O(N log k / log N + N)\n template <class\
    \ T> static std::vector<T> pow_table(int N, std::uint64_t k) {\n  if (k == 0)\
    \ return std::vector<T>(N + 1, 1);\n  auto f= [k](int p, short) {\n   T ret= 1,\
    \ b= p;\n   for (auto e= k;; b*= b)\n    if (e & 1 ? ret*= b, !(e>>= 1) : !(e>>=\
    \ 1)) return ret;\n  };\n  return completely_multiplicative_table<T>(N, f);\n\
    \ }\n // O(N log MOD / log N + N)\n template <class T> static std::vector<T> inv_table(int\
    \ N) {\n  return completely_multiplicative_table<T>(N, [](int p, short) { return\
    \ T(1) / p; });\n }\n // naive , O(N log N)\n template <class T> static std::vector<T>\
    \ dirichlet_conv(const std::vector<T> &a, const std::vector<T> &b) {\n  std::size_t\
    \ N= std::max(a.size(), b.size()) - 1, i, j;\n  std::vector<T> ret(N + 1, 0);\n\
    \  for (i= a.size(); --i;)\n   for (j= std::min(b.size() - 1, N / i); j; j--)\
    \ ret[i * j]+= a[i] * b[j];\n  return ret;\n }\n // a is multiplicative, O(N log\
    \ log N)\n template <class T, class F> static std::vector<T> dirichlet_conv(const\
    \ F &a, std::vector<T> b) {\n  std::size_t N= b.size() - 1, j= 0;\n  for (sieve(N),\
    \ b.resize(N + 1, 0); j < psz && ps[j] <= N; j++)\n   for (int i= N / ps[j], n,\
    \ m, e; i; i--)\n    for (b[n= ps[j] * i]+= a(ps[j], e= 1) * b[m= i]; m % ps[j]\
    \ == 0;) b[n]+= a(ps[j], ++e) * b[m/= ps[j]];\n  return b;\n }\n // both a and\
    \ b are multiplicative, O(N)\n template <class T, class F1, class F2> static std::vector<T>\
    \ dirichlet_conv(const F1 &a, const F2 &b, std::size_t N) {\n  auto f= [&a, &b](int\
    \ p, short e) {\n   T ret= a(p, e) + b(p, e);\n   for (int k= e; --k;) ret+= a(p,\
    \ e - k) * b(p, k);\n   return ret;\n  };\n  return multiplicative_table<T>(N,\
    \ f);\n }\n // f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log N)\n template <typename\
    \ T> static void divisor_zeta(std::vector<T> &f) {\n  std::size_t N= f.size(),\
    \ i, j;\n  for (sieve(N), i= 0; i < psz && ps[i] < N; i++)\n   for (j= 1; ps[i]\
    \ * j < N; j++) f[ps[i] * j]+= f[j];\n }\n // f -> h s.t. f(n) = sum_{m|n} h(m),\
    \ O(N log log N)\n template <typename T> static void divisor_mobius(std::vector<T>\
    \ &f) {\n  std::size_t N= f.size(), i, j;\n  for (sieve(N), i= 0; i < psz && ps[i]\
    \ < N; i++)\n   for (j= (N - 1) / ps[i]; j; j--) f[ps[i] * j]-= f[j];\n }\n //\
    \ O(N log log N)\n template <typename T> static std::vector<T> lcm_conv(std::vector<T>\
    \ a, std::vector<T> b) {\n  std::size_t N= std::max(a.size(), b.size());\n  a.resize(N),\
    \ b.resize(N), divisor_zeta(a), divisor_zeta(b);\n  for (; N--;) a[N]*= b[N];\n\
    \  return divisor_mobius(a), a;\n }\n // both a and b are multiplicative, O(N)\n\
    \ template <class T, class F1, class F2> static std::vector<T> lcm_conv(const\
    \ F1 &a, const F2 &b, std::size_t N) {\n  auto f= [&a, &b](int p, short e) {\n\
    \   T suma= 1, sumb= 1;\n   for (short k= 1; k < e; k++) suma+= a(p, k), sumb+=\
    \ b(p, k);\n   return (a(p, e) + suma) * (b(p, e) + sumb) - suma * sumb;\n  };\n\
    \  return multiplicative_table<T>(N, f);\n }\n // f -> g s.t. g(n) = sum_{n|m}\
    \ f(m), O(N log log N)\n template <typename T> static void multiple_zeta(std::vector<T>\
    \ &f) {\n  std::size_t N= f.size(), i, j;\n  for (sieve(N), i= 0; i < psz && ps[i]\
    \ < N; i++)\n   for (j= (N - 1) / ps[i]; j; j--) f[j]+= f[ps[i] * j];\n }\n //\
    \ f -> h s.t. f(n) = sum_{n|m} h(m), O(N log log N)\n template <typename T> static\
    \ void multiple_mobius(std::vector<T> &f) {\n  std::size_t N= f.size(), i, j;\n\
    \  for (sieve(N), i= 0; i < psz && ps[i] < N; i++)\n   for (j= 1; ps[i] * j <\
    \ N; j++) f[j]-= f[ps[i] * j];\n }\n // O(N log log N)\n template <typename T>\
    \ static std::vector<T> gcd_conv(std::vector<T> a, std::vector<T> b) {\n  std::size_t\
    \ N= std::max(a.size(), b.size());\n  a.resize(N), b.resize(N), multiple_zeta(a),\
    \ multiple_zeta(b);\n  for (; N--;) a[N]*= b[N];\n  return multiple_mobius(a),\
    \ a;\n }\n};\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate\
    \ <class Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint\
    \ n) {\n const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >>\
    \ s, one= md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...}) {\n\
    \  Uint b= a % n, p= pow(md.set(b), d, md), i= s;\n  while (p= md.norm(p), (p\
    \ != one && p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p) != n1 &&\
    \ i != s) return 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64 n) {\n\
    \ if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX) return\
    \ miller_rabin<u32, MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return miller_rabin<u64,\
    \ MP_Mo, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 5 \"src/FFT/NTT.hpp\"\nnamespace math_internal\
    \ {\n#define CE constexpr\n#define ST static\n#define TP template\n#define BSF(_,\
    \ n) __builtin_ctz##_(n)\nTP<class mod_t> struct NTT {\n#define FOR(a, b, c) \\\
    \n for (a= n >> 2; a; a>>= 2, b<<= 2) \\\n  for (y= u= r= I, x0= x, s= 0;; r*=\
    \ c[BSF(, s)], u= r * r, y= u * r, x0= x3 + p)\n#define FOR2(a, b, c) \\\n for\
    \ (a= n; a>>= 1; b<<= 1) \\\n  for (s= 0, r= I, x0= x;; r*= c[BSF(, s)], x0= x1\
    \ + p)\n#define REP for (x1= x0 + p, x2= x1 + p, x3= x2 + (i= p); i--;)\n ST inline\
    \ void dft(int n, mod_t x[]) {\n  int p, e= 1, s, i;\n  mod_t r, u, y, *x0, *x1,\
    \ *x2, *x3;\n  if CE (md < INT_MAX) {\n   ST CE auto r3= ras<3>(rt, irt);\n  \
    \ ST CE u128 im= rt[2].val(), md3= u128(md) << 93;\n   FOR(p, e, r3) {\n    u64\
    \ ru= r.val(), ru2= u.val(), ru3= y.val();\n    REP {\n     u64 a= x0[i].val(),\
    \ b= ru * x1[i].val(), c= ru2 * x2[i].val(), d= ru3 * x3[i].val(), f= md2 - d,\
    \ g= md2 + a - c;\n     u128 h= im * (b + f);\n     x0[i]= a + b + c + d, x1[i]=\
    \ a + (md2 - b) + c + f, x2[i]= h + g, x3[i]= md3 - h + g;\n    }\n    if (++s\
    \ == e) break;\n   }\n   if (BSF(, n) & 1)\n    for (r= I, s= 0, p= 0;; r*= r2[BSF(,\
    \ ++s)])\n     if (x[p + 1]= x[p] - (u= x[p + 1] * r), x[p]+= u; (p+= 2) == n)\
    \ break;\n  } else FOR2(p, e, r2) {\n    for (x1= x0 + (i= p); i--;) x1[i]= x0[i]\
    \ - (u= r * x1[i]), x0[i]+= u;\n    if (++s == e) break;\n   }\n }\n ST inline\
    \ void idft(int n, mod_t x[]) {\n  int e, p= 1, s, i;\n  mod_t r, u, y, *x0, *x1,\
    \ *x2, *x3;\n  if CE (md < INT_MAX) {\n   ST CE auto ir3= ras<3>(irt, rt);\n \
    \  ST CE u64 im= irt[2].val();\n   FOR(e, p, ir3) {\n    u64 ru2= u.val();\n \
    \   u128 ru= r.val(), ru3= y.val();\n    REP {\n     u64 a= x0[i].val(), b= x1[i].val(),\
    \ c= x2[i].val(), d= x3[i].val(), f= md - d, g= a + md - b, h= im * (c + f);\n\
    \     x0[i]= a + b + c + d, x1[i]= ru * (g + h), x2[i]= ru2 * (a + b + (md - c)\
    \ + f), x3[i]= ru3 * (g + (md2 << 1) - h);\n    }\n    if (++s == e) break;\n\
    \   }\n   if (BSF(, n) & 1)\n    for (x1= x + (i= n >> 1); i--;) u= x[i] - x1[i],\
    \ x[i]+= x1[i], x1[i]= u;\n  } else FOR2(e, p, ir2) {\n    for (x1= x0 + (i= p);\
    \ i--;) u= x0[i] - x1[i], x0[i]+= x1[i], x1[i]= r * u;\n    if (++s == e) break;\n\
    \   }\n  for (const mod_t iv= I / n; n--;) x[n]*= iv;\n }\n#undef FOR\n#undef\
    \ FOR2\n#undef REP\n ST inline void even_dft(int n, mod_t x[]) {\n  for (int i=\
    \ 0, j= 0; i < n; i+= 2) x[j++]= iv2 * (x[i] + x[i + 1]);\n }\n ST inline void\
    \ odd_dft(int n, mod_t x[], mod_t r= iv2) {\n  for (int i= 0, j= 0;; r*= ir2[BSF(,\
    \ ++j)])\n   if (x[j]= r * (x[i] - x[i + 1]); (i+= 2) == n) break;\n }\n ST inline\
    \ void dft_doubling(int n, mod_t x[], int i= 0) {\n  mod_t k= I, t= rt[BSF(, n\
    \ << 1)];\n  for (copy_n(x, n, x + n), idft(n, x + n); i < n; ++i) x[n + i]*=\
    \ k, k*= t;\n  dft(n, x + n);\n }\nprotected:\n ST CE u64 md= mod_t::mod(), md2=\
    \ md << 31;\n static_assert(md & 1);\n static_assert(is_prime(md));\n ST CE u8\
    \ E= BSF(ll, md - 1);\n ST CE mod_t w= [](u8 e) {\n  for (mod_t r= 2;; r+= 1)\n\
    \   if (auto s= r.pow((md - 1) / 2); s != 1 && s * s == 1) return r.pow((md -\
    \ 1) >> e);\n  return mod_t();\n }(E);\n static_assert(w != mod_t());\n ST CE\
    \ mod_t I= 1, iv2= (md + 1) / 2, iw= w.pow((1ULL << E) - 1);\n ST CE auto roots(mod_t\
    \ w) {\n  array<mod_t, E + 1> x= {};\n  for (u8 e= E; e; w*= w) x[e--]= w;\n \
    \ return x[0]= w, x;\n }\n TP<u32 N> ST CE auto ras(const array<mod_t, E + 1>\
    \ &rt, const array<mod_t, E + 1> &irt, int i= N) {\n  array<mod_t, E + 1 - N>\
    \ x= {};\n  for (mod_t ro= 1; i <= E; ro*= irt[i++]) x[i - N]= rt[i] * ro;\n \
    \ return x;\n }\n ST CE auto rt= roots(w), irt= roots(iw);\n ST CE auto r2= ras<2>(rt,\
    \ irt), ir2= ras<2>(irt, rt);\n};\nTP<class T, u8 t, class B> struct NI: public\
    \ B {\n using B::B;\n#define FUNC(op, name, HG, ...) \\\n inline void name(__VA_ARGS__)\
    \ { \\\n  HG(op, 1); \\\n  if CE (t > 1) HG(op, 2); \\\n  if CE (t > 2) HG(op,\
    \ 3); \\\n  if CE (t > 3) HG(op, 4); \\\n  if CE (t > 4) HG(op, 5); \\\n }\n#define\
    \ REP for (int i= b; i < e; ++i)\n#define DFT(fft, _) B::ntt##_::fft(e - b, this->dt##_\
    \ + b)\n#define ZEROS(op, _) fill_n(this->dt##_ + b, e - b, typename B::m##_())\n\
    #define SET(op, _) copy(x + b, x + e, this->dt##_ + b)\n#define SET_S(op, _) this->dt##_[i]=\
    \ x;\n#define SUBST(op, _) copy(r.dt##_ + b, r.dt##_ + e, this->dt##_ + b)\n#define\
    \ ASGN(op, _) REP this->dt##_[i] op##= r.dt##_[i]\n#define ASN(nm, op) TP<class\
    \ C> FUNC(op, nm, ASGN, const NI<T, t, C> &r, int b, int e)\n#define BOP(op, _)\
    \ REP this->dt##_[i]= l.dt##_[i] op r.dt##_[i]\n#define OP(nm, op) TP<class C,\
    \ class D> FUNC(op, nm, BOP, const NI<T, t, C> &l, const NI<T, t, D> &r, int b,\
    \ int e)\n OP(add, +) OP(dif, -) OP(mul, *) ASN(add, +) ASN(dif, -) ASN(mul, *)\
    \ FUNC(dft, dft, DFT, int b, int e) FUNC(idft, idft, DFT, int b, int e) FUNC(__,\
    \ zeros, ZEROS, int b, int e) FUNC(__, set, SET, const T x[], int b, int e) FUNC(__,\
    \ set, SET_S, int i, T x) TP<class C> FUNC(__, subst, SUBST, const NI<T, t, C>\
    \ &r, int b, int e) inline void get(T x[], int b, int e) const {\n  if CE (t ==\
    \ 1) copy(this->dt1 + b, this->dt1 + e, x + b);\n  else REP x[i]= get(i);\n }\n\
    #define TMP(_) B::iv##_##1 * (this->dt##_[i] - r1)\n inline T get(int i) const\
    \ {\n  if CE (t > 1) {\n   u64 r1= this->dt1[i].val(), r2= (TMP(2)).val();\n \
    \  T a= 0;\n   if CE (t > 2) {\n    u64 r3= (TMP(3) - B::iv32 * r2).val();\n \
    \   if CE (t > 3) {\n     u64 r4= (TMP(4) - B::iv42 * r2 - B::iv43 * r3).val();\n\
    \     if CE (t > 4) a= T(B::m4::mod()) * (TMP(5) - B::iv52 * r2 - B::iv53 * r3\
    \ - B::iv54 * r4).val();\n     a= (a + r4) * B::m3::mod();\n    }\n    a= (a +\
    \ r3) * B::m2::mod();\n   }\n   return (a + r2) * B::m1::mod() + r1;\n  } else\
    \ return this->dt1[i];\n }\n#undef TMP\n#undef DFT\n#undef ZEROS\n#undef SET\n\
    #undef SET_S\n#undef SUBST\n#undef ASGN\n#undef ASN\n#undef BOP\n#undef OP\n#undef\
    \ FUNC\n#undef REP\n};\n#define ARR(_) \\\n using m##_= StaticModInt<M##_>; \\\
    \n using ntt##_= NTT<m##_>; \\\n m##_ dt##_[LM]= {};\n#define IV2 ST CE m2 iv21=\
    \ m2(1) / m1::mod();\n#define IV3 ST CE m3 iv32= m3(1) / m2::mod(), iv31= iv32\
    \ / m1::mod();\n#define IV4 ST CE m4 iv43= m4(1) / m3::mod(), iv42= iv43 / m2::mod(),\
    \ iv41= iv42 / m1::mod();\n#define IV5 ST CE m5 iv54= m5(1) / m4::mod(), iv53=\
    \ iv54 / m3::mod(), iv52= iv53 / m2::mod(), iv51= iv52 / m1::mod();\nTP<u8 t,\
    \ u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM, bool v> struct NB { ARR(1) };\n\
    TP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4,\
    \ M5, LM, 0> { ARR(1) ARR(2) IV2 };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5,\
    \ u32 LM> struct NB<3, M1, M2, M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) IV2 IV3\
    \ };\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<4, M1, M2,\
    \ M3, M4, M5, LM, 0> { ARR(1) ARR(2) ARR(3) ARR(4) IV2 IV3 IV4 };\nTP<u64 M1,\
    \ u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1, M2, M3, M4, M5, LM,\
    \ 0> { ARR(1) ARR(2) ARR(3) ARR(4) ARR(5) IV2 IV3 IV4 IV5 };\n#undef ARR\n#define\
    \ VC(_) \\\n using m##_= StaticModInt<M##_>; \\\n using ntt##_= NTT<m##_>; \\\n\
    \ vector<m##_> bf##_; \\\n m##_ *dt##_;\n#define RS resize\nTP<u64 M1, u32 M2,\
    \ u32 M3, u32 M4, u32 M5, u32 LM> struct NB<1, M1, M2, M3, M4, M5, LM, 1> {\n\
    \ NB(): dt1(bf1.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(); }\n\
    \ u32 size() const { return bf1.size(); }\n VC(1)\n};\nTP<u64 M1, u32 M2, u32\
    \ M3, u32 M4, u32 M5, u32 LM> struct NB<2, M1, M2, M3, M4, M5, LM, 1> {\n NB():\
    \ dt1(bf1.data()), dt2(bf2.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) IV2\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<3,\
    \ M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data())\
    \ {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(), bf2.RS(n), dt2= bf2.data(),\
    \ bf3.RS(n), dt3= bf3.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) VC(3) IV2 IV3\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM>\
    \ struct NB<4, M1, M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()),\
    \ dt3(bf3.data()), dt4(bf4.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data();\
    \ }\n u32 size() const { return bf1.size(); }\n VC(1) VC(2) VC(3) VC(4) IV2 IV3\
    \ IV4\n};\nTP<u64 M1, u32 M2, u32 M3, u32 M4, u32 M5, u32 LM> struct NB<5, M1,\
    \ M2, M3, M4, M5, LM, 1> {\n NB(): dt1(bf1.data()), dt2(bf2.data()), dt3(bf3.data()),\
    \ dt4(bf4.data()), dt5(bf5.data()) {}\n void RS(int n) { bf1.RS(n), dt1= bf1.data(),\
    \ bf2.RS(n), dt2= bf2.data(), bf3.RS(n), dt3= bf3.data(), bf4.RS(n), dt4= bf4.data(),\
    \ bf5.RS(n), dt5= bf5.data(); }\n u32 size() const { return bf1.size(); }\n VC(1)\
    \ VC(2) VC(3) VC(4) VC(5) IV2 IV3 IV4 IV5\n};\n#undef VC\n#undef IV2\n#undef IV3\n\
    #undef IV4\n#undef IV5\nTP<class T, u32 LM> CE bool is_nttfriend() {\n if CE (!is_staticmodint_v<T>)\
    \ return 0;\n else return (T::mod() & is_prime(T::mod())) && LM <= (1ULL << BSF(ll,\
    \ T::mod() - 1));\n}\nTP<class T> CE u64 mv() {\n if CE (is_runtimemodint_v<T>)\
    \ return numeric_limits<typename T::Uint>::max();\n else if CE (is_staticmodint_v<T>)\
    \ return T::mod();\n else return numeric_limits<T>::max();\n}\nTP<class T, u32\
    \ LM, u32 M1, u32 M2, u32 M3, u32 M4> CE u8 nt() {\n if CE (!is_nttfriend<T, LM>())\
    \ {\n  CE u128 m= mv<T>(), mv= m * m;\n  if CE (mv <= M1 / LM) return 1;\n  else\
    \ if CE (mv <= u64(M1) * M2 / LM) return 2;\n  else if CE (mv <= u128(M1) * M2\
    \ * M3 / LM) return 3;\n  else if CE (mv <= u128(M1) * M2 * M3 * M4 / LM) return\
    \ 4;\n  else return 5;\n } else return 1;\n}\n#undef BSF\n#undef RS\nCE u32 MOD1=\
    \ 0x7e000001, MOD2= 0x78000001, MOD3= 0x6c000001, MOD4= 0x66000001, MOD5= 0x42000001;\n\
    TP<class T, u32 LM> CE u8 nttarr_type= nt<T, LM, MOD1, MOD2, MOD3, MOD4>();\n\
    TP<class T, u32 LM> CE u8 nttarr_cat= is_nttfriend<T, LM>() && (mv<T>() > INT_MAX)\
    \ ? 0 : nttarr_type<T, LM>;\nTP<class T, u32 LM, bool v> using NTTArray= NI<T,\
    \ nttarr_type<T, LM>, conditional_t<is_nttfriend<T, LM>(), NB<1, mv<T>(), 0, 0,\
    \ 0, 0, LM, v>, NB<nttarr_type<T, LM>, MOD1, MOD2, MOD3, MOD4, MOD5, LM, v>>>;\n\
    #undef CE\n#undef ST\n#undef TP\n}\nusing math_internal::is_nttfriend, math_internal::nttarr_type,\
    \ math_internal::nttarr_cat, math_internal::NTT, math_internal::NTTArray;\ntemplate\
    \ <class T, size_t LM, int id= 0> struct GlobalNTTArray { static inline NTTArray<T,\
    \ LM, 0> bf; };\ntemplate <class T, size_t LM, size_t LM2, int id= 0> struct GlobalNTTArray2D\
    \ { static inline NTTArray<T, LM, 0> bf[LM2]; };\ntemplate <class T, size_t LM,\
    \ int id= 0> struct GlobalArray { static inline T bf[LM]; };\nconstexpr unsigned\
    \ get_len(unsigned n) { return 1 << (std::__lg(n - 1) + 1); }\n#line 4 \"src/FFT/sample_points_shift.hpp\"\
    \n\n/**\n * @title \u591A\u9805\u5F0F\u306E\u8A55\u4FA1\u70B9\u30B7\u30D5\u30C8\
    \n * @category FFT\n * y=f(0),f(1),...,f(n-1)\u304C\u4E0E\u3048\u3089\u308C\u305F\
    \u3068\u304D\u306Ef(c),f(c+1),...,f(c+m-1)\u3092\u8A08\u7B97\n * O( (n+m)log(n+m)\
    \ )\n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t, std::size_t _Nm = 1 << 22>\n\
    std::vector<mod_t> sample_points_shift(const std::vector<mod_t> &y, mod_t c,\n\
    \                                       int m = 1) {\n  assert(m <= mod_t::modulo()),\
    \ assert(y.size() <= mod_t::modulo());\n  static constexpr int TH = = is_nttfriend<mod_t,\
    \ _Nm2>()      ? 50\n                              : is_nttarraydouble<mod_t,\
    \ _Nm2> ? 130\n                                                              \
    \ : 145;\n  if (m == 0) return {};\n  std::uint64_t c_64 = c.val(), nc1 = (c +\
    \ (m - 1)).val();\n  std::uint32_t k = y.size(), d = k - 1, i = d, e;\n  if (c_64\
    \ + m <= k)\n    return std::vector<mod_t>(y.begin() + c_64, y.begin() + c_64\
    \ + m);\n  using GA = GlobalArray<mod_t, _Nm, 0>;\n  for (GA::bf[d] = 1; i; i--)\
    \ GA::bf[i - 1] = GA::bf[i] * i;\n  mod_t t = mod_t(1) / (GA::bf[0] * GA::bf[0]);\n\
    \  for (i = d / 2 + 1; i--;)\n    GA::bf[i] = GA::bf[d - i] = GA::bf[i] * GA::bf[d\
    \ - i] * t;\n  for (i = k; i--;) GA::bf[i] *= y[i];\n  for (i = 1; i < k; i +=\
    \ 2) GA::bf[d - i] = -GA::bf[d - i];\n  const mod_t Z = 0;\n  auto f = [&](mod_t\
    \ a, int n, mod_t ret[]) {\n    using GNA1 = GlobalNTTArray<mod_t, _Nm, 1>;\n\
    \    using GNA2 = GlobalNTTArray<mod_t, _Nm, 2>;\n    using GAq = GlobalArray<mod_t,\
    \ _Nm, 2>;\n    for (e = d + n, i = 0, t = a - d; i < e; i++, t += 1) ret[i] =\
    \ t;\n    std::partial_sum(ret, ret + e, GAq::bf, std::multiplies<>());\n    for\
    \ (t = mod_t(1) / GAq::bf[e - 1]; --i;)\n      GAq::bf[i] = t * GAq::bf[i - 1],\
    \ t *= ret[i];\n    if (GAq::bf[0] = t; k >= TH && n >= TH) {\n      const int\
    \ len = get_len(e + (d > 0));\n      GNA1::bf.set(GA::bf, 0, k), GNA1::bf.zeros(k,\
    \ len), GNA1::bf.dft(0, len);\n      GNA2::bf.set(GAq::bf, 0, e), GNA2::bf.zeros(e,\
    \ len), GNA2::bf.dft(0, len);\n      GNA1::bf.mul(GNA2::bf, 0, len), GNA1::bf.idft(0,\
    \ len);\n      GNA1::bf.get(ret - d, d, e);\n    } else\n      for (std::fill_n(ret,\
    \ n, Z), i = k; i--;)\n        for (int b = d - i, j = n; j--;) ret[j] += GA::bf[i]\
    \ * GAq::bf[j + b];\n    for (t = a, i = k; --i;) t *= a - i;\n    for (; i <\
    \ n; i++) ret[i] *= t, t *= (a + (i + 1)) * GAq::bf[i];\n    return ret + n;\n\
    \  };\n  using GAp = GlobalArray<mod_t, _Nm, 1>;\n  if (mod_t * bf; c_64 < k)\
    \ {\n    if (bf = std::copy_n(y.begin() + c_64, k - c_64, GAp::bf); nc1 < k)\n\
    \      std::copy_n(y.begin(), nc1 + 1, f(k, mod_t::modulo() - k, bf));\n    else\n\
    \      f(k, c_64 + m - k, bf);\n  } else if (nc1 < c_64) {\n    if (mod_t *bf\
    \ = f(c, (-c).val(), GAp::bf); nc1 < k)\n      std::copy_n(y.begin(), nc1 + 1,\
    \ bf);\n    else\n      f(k, nc1 + 1 - k, std::copy_n(y.begin(), k, bf));\n  }\
    \ else\n    f(c, m, GAp::bf);\n  return std::vector<mod_t>(GAp::bf, GAp::bf +\
    \ m);\n}\n#line 10 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  if (r == 0) {\n    cout << (d ? 0 : 1) << '\\n';\n    return\
    \ 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = sample_points_shift<Mint>(sum,\
    \ n)[0];\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * sample_points_shift<Mint>(y, n)[0];\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Math/Sieve.hpp\"\n#include \"src/FFT/sample_points_shift.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  using C = Combination<Mint>;\n  long\
    \ long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  if (r == 0) {\n    cout << (d ? 0 : 1) << '\\n';\n    return\
    \ 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = Sieve<>::pow_table<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = sample_points_shift<Mint>(sum,\
    \ n)[0];\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(1) / r, rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n     \
    \ y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n    ans\
    \ += Mint(r).pow(n) * sample_points_shift<Mint>(y, n)[0];\n  }\n  cout << ans\
    \ << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/Sieve.hpp
  - src/FFT/sample_points_shift.hpp
  - src/FFT/NTT.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-01-01 04:58:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
---
