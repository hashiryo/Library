---
data:
  _extendedDependsOn:
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
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc038/tasks/agc038_c
    links:
    - https://atcoder.jp/contests/agc038/tasks/agc038_c
  bundledCode: "#line 1 \"test/atcoder/agc038_c.numth.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/agc038/tasks/agc038_c\"\n\n#include <bits/stdc++.h>\n\
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
    \ a;\n }\n};\n#line 6 \"test/atcoder/agc038_c.numth.test.cpp\"\nusing namespace\
    \ std;\n\n// O(MAX_A log log MAX_A)\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<998244353>;\n  const int MAX_A = 1e6;\n  int N;\n\
    \  cin >> N;\n  vector<Mint> c(MAX_A + 1, 0);\n  Mint sum = 0;\n  for (int i =\
    \ 0, A; i < N; i++) cin >> A, c[A] += A, sum += A;\n  auto tmp = Sieve<>::gcd_conv(c,\
    \ c);\n  Mint sum2 = 0;\n  for (int d = 1; d <= MAX_A; d++) sum2 += tmp[d] / d;\n\
    \  cout << (sum2 - sum) / 2 << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc038/tasks/agc038_c\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/Sieve.hpp\"\
    \nusing namespace std;\n\n// O(MAX_A log log MAX_A)\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  using Mint = StaticModInt<998244353>;\n  const\
    \ int MAX_A = 1e6;\n  int N;\n  cin >> N;\n  vector<Mint> c(MAX_A + 1, 0);\n \
    \ Mint sum = 0;\n  for (int i = 0, A; i < N; i++) cin >> A, c[A] += A, sum +=\
    \ A;\n  auto tmp = Sieve<>::gcd_conv(c, c);\n  Mint sum2 = 0;\n  for (int d =\
    \ 1; d <= MAX_A; d++) sum2 += tmp[d] / d;\n  cout << (sum2 - sum) / 2 << endl;\n\
    \  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/Sieve.hpp
  isVerificationFile: true
  path: test/atcoder/agc038_c.numth.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 21:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/agc038_c.numth.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc038_c.numth.test.cpp
- /verify/test/atcoder/agc038_c.numth.test.cpp.html
title: test/atcoder/agc038_c.numth.test.cpp
---
