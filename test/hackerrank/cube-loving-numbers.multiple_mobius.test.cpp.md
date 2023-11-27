---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/NumberTheory/Sieve.hpp
    title: "\u7DDA\u5F62\u7BE9 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers
    links:
    - https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers
  bundledCode: "#line 1 \"test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp\"\
    \n#define PROBLEM \"https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers\"\
    \n#include <iostream>\n#include <vector>\n#line 3 \"src/NumberTheory/Sieve.hpp\"\
    \n#include <algorithm>\n#include <map>\n#include <cstdint>\ntemplate <int LIM=\
    \ 1 << 24> class Sieve {\n static inline int ps[LIM >> 4], lpf[LIM >> 1], lpfpw[LIM\
    \ >> 1], psz= 0;\n static inline int8_t lpfe[LIM >> 1];\n static inline void sieve(int\
    \ N) {  // O(N)\n  static int n= 2, i= 1;\n  if (n == 2) ps[psz++]= 2, n++;\n\
    \  for (; n <= N; n+= 2, i++) {\n   if (!lpf[i]) lpf[i]= ps[psz++]= n;\n   for\
    \ (int j= 1, e= std::min(lpf[i], N / n); j < psz && ps[j] <= e; j++) lpf[(ps[j]\
    \ * n) >> 1]= ps[j];\n  }\n }\n static inline void set_lpfe(int N) {  // O(N)\n\
    \  static int n= 3, i= 1;\n  if (N < n) return;\n  sieve(N), std::copy(lpf + i,\
    \ lpf + (N >> 1) + 1, lpfpw + i);\n  for (std::fill(lpfe + i, lpfe + (N >> 1)\
    \ + 1, 1); n <= N; n+= 2, i++)\n   if (int j= (n / lpf[i]) >> 1; lpf[i] == lpf[j])\
    \ lpfe[i]+= lpfe[j], lpfpw[i]*= lpfpw[j];\n }\npublic:\n static int least_prime_factor(int\
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
    \ a;\n }\n};\n#line 5 \"test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp\"\
    \n// \u500D\u6570\u30E1\u30D3\u30A6\u30B9\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int T;\n cin >> T;\n long long\
    \ f[1'000'010];\n while (T--) {\n  long long N, a= 2, ans= 0;\n  cin >> N;\n \
    \ for (; a * a * a <= N; a++) f[a]= N / (a * a * a);\n  vector<long long> g(f,\
    \ f + a);\n  Sieve<>::multiple_mobius(g);\n  for (; --a >= 2;) ans+= g[a];\n \
    \ cout << ans << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/NumberTheory/Sieve.hpp\"\
    \n// \u500D\u6570\u30E1\u30D3\u30A6\u30B9\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int T;\n cin >> T;\n long long\
    \ f[1'000'010];\n while (T--) {\n  long long N, a= 2, ans= 0;\n  cin >> N;\n \
    \ for (; a * a * a <= N; a++) f[a]= N / (a * a * a);\n  vector<long long> g(f,\
    \ f + a);\n  Sieve<>::multiple_mobius(g);\n  for (; --a >= 2;) ans+= g[a];\n \
    \ cout << ans << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/NumberTheory/Sieve.hpp
  isVerificationFile: true
  path: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 22:39:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
- /verify/test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp.html
title: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
---
