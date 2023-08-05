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
    path: src/Math/Sieve.hpp
    title: "\u7BE9 \u4ED6"
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/yosupo/gcd_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"src/Math/Sieve.hpp\"\n#include <algorithm>\n#include <map>\n\
    template <int LIM= 1 << 24> class Sieve {\n static inline int ps[LIM >> 4], lpf[LIM\
    \ >> 1], lpfpw[LIM >> 1], psz= 0;\n static inline std::int8_t lpfe[LIM >> 1];\n\
    \ static inline void sieve(int N) {  // O(N)\n  static int n= 2, i= 1;\n  if (n\
    \ == 2) ps[psz++]= 2, n++;\n  for (; n <= N; n+= 2, i++) {\n   if (!lpf[i]) lpf[i]=\
    \ ps[psz++]= n;\n   for (int j= 1, e= std::min(lpf[i], N / n); j < psz && ps[j]\
    \ <= e; j++) lpf[(ps[j] * n) >> 1]= ps[j];\n  }\n }\n static inline void set_lpfe(int\
    \ N) {  // O(N)\n  static int n= 3, i= 1;\n  if (N < n) return;\n  sieve(N), std::copy(lpf\
    \ + i, lpf + (N >> 1) + 1, lpfpw + i);\n  for (std::fill(lpfe + i, lpfe + (N >>\
    \ 1) + 1, 1); n <= N; n+= 2, i++)\n   if (int j= (n / lpf[i]) >> 1; lpf[i] ==\
    \ lpf[j]) lpfe[i]+= lpfe[j], lpfpw[i]*= lpfpw[j];\n }\npublic:\n static int least_prime_factor(int\
    \ n) { return sieve(n), lpf[n]; }\n // O(log n)\n static std::map<int, short>\
    \ factorize(int n) {\n  std::map<int, short> ret;\n  if (int t; !(n & 1)) ret[2]=\
    \ t= __builtin_ctz(n), n>>= t;\n  if (int i= n >> 1; n > 1)\n   for (set_lpfe(n);\
    \ n > 1; i= n >> 1) ret[lpf[i]]= lpfe[i], n/= lpfpw[i];\n  return ret;\n }\n //\
    \ O(log n)\n static std::vector<int> divisors(int n) {\n  std::vector<int> ret=\
    \ {1};\n  for (auto [p, e]: factorize(n))\n   for (std::size_t sz= ret.size(),\
    \ pw= p; e--; pw*= p)\n    for (int i= sz - 1; i >= 0; i--) ret.push_back(ret[i]\
    \ * pw);\n  return std::sort(ret.begin(), ret.end()), ret;\n }\n // O(N)\n static\
    \ std::vector<int> get_primes(int N) { return sieve(N), std::vector<int>(ps, std::upper_bound(ps,\
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
    \ a;\n }\n};\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b * q;\n\
    \ return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\
    \nnamespace math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32=\
    \ uint32_t;\nusing u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n\
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
    \ return dat[n];\n}\n#line 6 \"test/yosupo/gcd_convolution.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using Mint=\
    \ ModInt<998244353>;\n int N;\n cin >> N;\n vector<Mint> a(N + 1), b(N + 1);\n\
    \ for (int i= 1; i <= N; i++) cin >> a[i];\n for (int i= 1; i <= N; i++) cin >>\
    \ b[i];\n auto c= Sieve<>::gcd_conv(a, b);\n for (int i= 1; i <= N; i++) cout\
    \ << c[i] << \" \\n\"[i == N];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Math/Sieve.hpp\"\n#include \"\
    src/Math/ModInt.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector<Mint> a(N + 1),\
    \ b(N + 1);\n for (int i= 1; i <= N; i++) cin >> a[i];\n for (int i= 1; i <= N;\
    \ i++) cin >> b[i];\n auto c= Sieve<>::gcd_conv(a, b);\n for (int i= 1; i <= N;\
    \ i++) cout << c[i] << \" \\n\"[i == N];\n return 0;\n}"
  dependsOn:
  - src/Math/Sieve.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/yosupo/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 18:38:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_convolution.test.cpp
- /verify/test/yosupo/gcd_convolution.test.cpp.html
title: test/yosupo/gcd_convolution.test.cpp
---
