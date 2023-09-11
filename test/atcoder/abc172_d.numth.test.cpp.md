---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Sieve.hpp
    title: "\u7BE9 \u4ED6"
  - icon: ':heavy_check_mark:'
    path: src/Math/multiplicative_and_additive.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/atcoder/abc172_d.numth.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n// O(N)\n#include <iostream>\n\
    #line 2 \"src/Math/Sieve.hpp\"\n#include <vector>\n#include <algorithm>\n#include\
    \ <map>\ntemplate <int LIM= 1 << 24> class Sieve {\n static inline int ps[LIM\
    \ >> 4], lpf[LIM >> 1], lpfpw[LIM >> 1], psz= 0;\n static inline std::int8_t lpfe[LIM\
    \ >> 1];\n static inline void sieve(int N) {  // O(N)\n  static int n= 2, i= 1;\n\
    \  if (n == 2) ps[psz++]= 2, n++;\n  for (; n <= N; n+= 2, i++) {\n   if (!lpf[i])\
    \ lpf[i]= ps[psz++]= n;\n   for (int j= 1, e= std::min(lpf[i], N / n); j < psz\
    \ && ps[j] <= e; j++) lpf[(ps[j] * n) >> 1]= ps[j];\n  }\n }\n static inline void\
    \ set_lpfe(int N) {  // O(N)\n  static int n= 3, i= 1;\n  if (N < n) return;\n\
    \  sieve(N), std::copy(lpf + i, lpf + (N >> 1) + 1, lpfpw + i);\n  for (std::fill(lpfe\
    \ + i, lpfe + (N >> 1) + 1, 1); n <= N; n+= 2, i++)\n   if (int j= (n / lpf[i])\
    \ >> 1; lpf[i] == lpf[j]) lpfe[i]+= lpfe[j], lpfpw[i]*= lpfpw[j];\n }\npublic:\n\
    \ static int least_prime_factor(int n) { return sieve(n), lpf[n]; }\n // O(log\
    \ n)\n static std::map<int, short> factorize(int n) {\n  std::map<int, short>\
    \ ret;\n  if (int t; !(n & 1)) ret[2]= t= __builtin_ctz(n), n>>= t;\n  if (int\
    \ i= n >> 1; n > 1)\n   for (set_lpfe(n); n > 1; i= n >> 1) ret[lpf[i]]= lpfe[i],\
    \ n/= lpfpw[i];\n  return ret;\n }\n // O(log n)\n static std::vector<int> divisors(int\
    \ n) {\n  std::vector<int> ret= {1};\n  for (auto [p, e]: factorize(n))\n   for\
    \ (std::size_t sz= ret.size(), pw= p; e--; pw*= p)\n    for (int i= sz - 1; i\
    \ >= 0; i--) ret.push_back(ret[i] * pw);\n  return std::sort(ret.begin(), ret.end()),\
    \ ret;\n }\n // O(N)\n static std::vector<int> get_primes(int N) { return sieve(N),\
    \ std::vector<int>(ps, std::upper_bound(ps, ps + psz, N)); }\n template <class\
    \ T, class F> static inline std::vector<T> completely_multiplicative_table(int\
    \ N, const F &f) {\n  std::vector<T> ret(N + 1);\n  sieve(N);\n  for (int n= 3,\
    \ i= 1; n <= N; n+= 2, i++) ret[n]= lpf[i] == n ? f(n, 1) : ret[lpf[i]] * ret[n\
    \ / lpf[i]];\n  if (int n= 4; 2 <= N)\n   for (ret[2]= f(2, 1); n <= N; n+= 2)\
    \ ret[n]= ret[2] * ret[n >> 1];\n  return ret[1]= 1, ret;\n }\n template <class\
    \ T, class F> static inline std::vector<T> multiplicative_table(int N, const F\
    \ &f) {\n  std::vector<T> ret(N + 1);\n  set_lpfe(N);\n  for (int n= 3, i= 1;\
    \ n <= N; n+= 2, i++) ret[n]= lpfpw[i] == n ? f(lpf[i], lpfe[i]) : ret[lpfpw[i]]\
    \ * ret[n / lpfpw[i]];\n  for (int n= 2, t; n <= N; n+= 2) t= __builtin_ctz(n),\
    \ ret[n]= n & (n - 1) ? ret[n & -n] * ret[n >> t] : f(2, t);\n  return ret[1]=\
    \ 1, ret;\n }\n // O(N log k / log N + N)\n template <class T> static std::vector<T>\
    \ pow_table(int N, std::uint64_t k) {\n  if (k == 0) return std::vector<T>(N +\
    \ 1, 1);\n  auto f= [k](int p, short) {\n   T ret= 1, b= p;\n   for (auto e= k;;\
    \ b*= b)\n    if (e & 1 ? ret*= b, !(e>>= 1) : !(e>>= 1)) return ret;\n  };\n\
    \  return completely_multiplicative_table<T>(N, f);\n }\n // O(N log MOD / log\
    \ N + N)\n template <class T> static std::vector<T> inv_table(int N) {\n  return\
    \ completely_multiplicative_table<T>(N, [](int p, short) { return T(1) / p; });\n\
    \ }\n // naive , O(N log N)\n template <class T> static std::vector<T> dirichlet_conv(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n  std::size_t N= std::max(a.size(),\
    \ b.size()) - 1, i, j;\n  std::vector<T> ret(N + 1, 0);\n  for (i= a.size(); --i;)\n\
    \   for (j= std::min(b.size() - 1, N / i); j; j--) ret[i * j]+= a[i] * b[j];\n\
    \  return ret;\n }\n // a is multiplicative, O(N log log N)\n template <class\
    \ T, class F> static std::vector<T> dirichlet_conv(const F &a, std::vector<T>\
    \ b) {\n  std::size_t N= b.size() - 1, j= 0;\n  for (sieve(N), b.resize(N + 1,\
    \ 0); j < psz && ps[j] <= N; j++)\n   for (int i= N / ps[j], n, m, e; i; i--)\n\
    \    for (b[n= ps[j] * i]+= a(ps[j], e= 1) * b[m= i]; m % ps[j] == 0;) b[n]+=\
    \ a(ps[j], ++e) * b[m/= ps[j]];\n  return b;\n }\n // both a and b are multiplicative,\
    \ O(N)\n template <class T, class F1, class F2> static std::vector<T> dirichlet_conv(const\
    \ F1 &a, const F2 &b, std::size_t N) {\n  auto f= [&a, &b](int p, short e) {\n\
    \   T ret= a(p, e) + b(p, e);\n   for (int k= e; --k;) ret+= a(p, e - k) * b(p,\
    \ k);\n   return ret;\n  };\n  return multiplicative_table<T>(N, f);\n }\n //\
    \ f -> g s.t. g(n) = sum_{m|n} f(m), O(N log log N)\n template <typename T> static\
    \ void divisor_zeta(std::vector<T> &f) {\n  std::size_t N= f.size(), i, j;\n \
    \ for (sieve(N), i= 0; i < psz && ps[i] < N; i++)\n   for (j= 1; ps[i] * j < N;\
    \ j++) f[ps[i] * j]+= f[j];\n }\n // f -> h s.t. f(n) = sum_{m|n} h(m), O(N log\
    \ log N)\n template <typename T> static void divisor_mobius(std::vector<T> &f)\
    \ {\n  std::size_t N= f.size(), i, j;\n  for (sieve(N), i= 0; i < psz && ps[i]\
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
    \ a;\n }\n};\n#line 3 \"src/Math/multiplicative_and_additive.hpp\"\nnamespace\
    \ multiplicative_functions {\ntemplate <class T> struct Totient {\n static constexpr\
    \ T f(std::uint64_t p, short e) {\n  T ret= p - 1;\n  while (e-- > 1) ret*= p;\n\
    \  return ret;\n }\n static std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate\
    \ <class T> struct Moebius {\n static constexpr T f(std::uint64_t, short e) {\
    \ return (e == 0) - (e == 1); }\n static std::vector<T> poly() { return {-1};\
    \ }\n};\ntemplate <class T> struct Liouville {\n static constexpr T f(std::uint64_t,\
    \ short e) { return e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T, uint64_t k> struct Divisor {\n static constexpr\
    \ T f(std::uint64_t p, short e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t\
    \ kk= k; kk; kk>>= 1, b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <=\
    \ e; i++, pkpw*= pk) ret+= pkpw;\n  return ret;\n }\n static std::vector<T> poly()\
    \ {\n  std::vector<T> ret(k + 1, 0);\n  ret[0]+= 1, ret[k]+= 1;\n  return ret;\n\
    \ }\n};\ntemplate <class T> struct Dedekind {\n static constexpr T f(std::uint64_t\
    \ p, short e) {\n  T ret= p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n\
    \ }\n static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace multiplicative_functions\n\
    namespace additive_functions {\ntemplate <class T> struct BigOmega {  // the total\
    \ number of prime factors of n\n static constexpr T f(std::uint64_t, short e)\
    \ { return e; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class\
    \ T> struct LittleOmega {  // the total number of different prime factors of n\n\
    \ static constexpr T f(std::uint64_t, short) { return 1; }\n static std::vector<T>\
    \ poly() { return {1}; }\n};\ntemplate <class T> struct Sopfr {  // the sum of\
    \ primes dividing n counting multiplicity\n static constexpr T f(std::uint64_t\
    \ p, short e) { return p * e; }\n static std::vector<T> poly() { return {0, 1};\
    \ }\n};\ntemplate <class T> struct Sopf {  // the sum of the distinct primes dividing\
    \ n\n static constexpr T f(std::uint64_t p, short) { return p; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\n}  // namespace additive_functions\n#line 6 \"\
    test/atcoder/abc172_d.numth.test.cpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace multiplicative_functions;\n\
    \ int N;\n cin >> N;\n auto d= Sieve<>::multiplicative_table<long long>(N, Divisor<int,\
    \ 0>::f);\n long long ans= 0;\n for (long long i= 1; i <= N; i++) ans+= d[i] *\
    \ i;\n cout << ans << endl;\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n//\
    \ O(N)\n#include <iostream>\n#include \"src/Math/Sieve.hpp\"\n#include \"src/Math/multiplicative_and_additive.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using namespace multiplicative_functions;\n int N;\n cin >> N;\n auto d= Sieve<>::multiplicative_table<long\
    \ long>(N, Divisor<int, 0>::f);\n long long ans= 0;\n for (long long i= 1; i <=\
    \ N; i++) ans+= d[i] * i;\n cout << ans << endl;\n return 0;\n}"
  dependsOn:
  - src/Math/Sieve.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/atcoder/abc172_d.numth.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 22:03:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc172_d.numth.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc172_d.numth.test.cpp
- /verify/test/atcoder/abc172_d.numth.test.cpp.html
title: test/atcoder/abc172_d.numth.test.cpp
---
