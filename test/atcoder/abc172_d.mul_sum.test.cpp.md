---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/NumberTheory/ExtendedEratosthenesSieve.hpp
    title: "\u62E1\u5F35\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u7BE9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/atcoder/abc172_d.mul_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n// O(N^(3/4)/log N)\n\
    #include <iostream>\n#line 2 \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <tuple>\n#include <cmath>\n\
    #include <cstdint>\n#include <cassert>\ntemplate <class T> struct PrimeSum {\n\
    \ uint64_t N;\n size_t K;\n std::vector<T> Xs, Xl;\n PrimeSum(uint64_t N= 0):\
    \ N(N), K(std::sqrt(N)), Xs(K + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N, const\
    \ std::vector<T> &s, const std::vector<T> &l): N(N), K(std::sqrt(N)), Xs(s), Xl(l)\
    \ {}\n PrimeSum operator-() const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto &x: Ys)\
    \ x= -x;\n  for (auto &x: Yl) x= -x;\n  return PrimeSum(N, Ys, Yl);\n }\n PrimeSum\
    \ &operator*=(T r) {\n  for (auto &x: Xs) x*= r;\n  for (auto &x: Xl) x*= r;\n\
    \  return *this;\n }\n PrimeSum &operator+=(const PrimeSum &r) {\n  for (size_t\
    \ i= K + 1; i--;) Xs[i]+= r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]+= r.Xl[i];\n\
    \  return *this;\n }\n PrimeSum &operator-=(const PrimeSum &r) {\n  for (size_t\
    \ i= K + 1; i--;) Xs[i]-= r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]-= r.Xl[i];\n\
    \  return *this;\n }\n PrimeSum operator*(T r) const { return PrimeSum(*this)*=\
    \ r; }\n friend PrimeSum operator*(T l, const PrimeSum &r) { return r * l; }\n\
    \ PrimeSum operator+(const PrimeSum &r) const { return PrimeSum(*this)+= r; }\n\
    \ PrimeSum operator-(const PrimeSum &r) const { return PrimeSum(*this)-= r; }\n\
    \ inline T sum() const { return Xl[1]; }\n inline T sum(uint64_t n) const { return\
    \ n <= K ? Xs[n] : Xl[N / n]; }\n void add(uint64_t p, T v) {\n  for (size_t i=\
    \ p; i <= K; ++i) Xs[i]+= v;\n  for (size_t i= std::min<uint64_t>(N / p, K); i;\
    \ --i) Xl[i]+= v;\n }\n};\ntemplate <class T> class ExtendedEratosthenesSieve\
    \ {\n uint64_t N;\n size_t K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>>\
    \ pwsum;\n ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)),\
    \ pwsum(D + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)),\
    \ l(D + 1, std::vector<T>(K + 1));\n  T fct= 1;\n  for (size_t d= D + 1; d; --d)\
    \ fct*= d;\n  fct= T(1) / fct;\n  for (size_t n= 1, d= 0; n <= K; ++n, d= 0)\n\
    \   for (T prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd;\n  for (size_t n= 1,\
    \ d= 0; n <= K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n) + ++d))\
    \ l[d][n]= prd;\n  for (size_t d= D + 1; --d; fct*= d + 1)\n   for (size_t n=\
    \ 1; n <= K; ++n) s[d][n]*= fct, l[d][n]*= fct;\n  if (D >= 2) {\n   std::vector<T>\
    \ stir(D + 1, 0);\n   stir[1]= 1;\n   for (size_t d= 2; d <= D; stir[d++]= 1)\
    \ {\n    for (size_t j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n \
    \   for (size_t n= 1; n <= K; ++n)\n     for (size_t j= 1; j < d; ++j) s[d][n]-=\
    \ stir[j] * s[j][n], l[d][n]-= stir[j] * l[j][n];\n   }\n  }\n  for (size_t d=\
    \ 0; d <= D; ++d)\n   for (size_t n= 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n\
    \  for (size_t p= 2, d= 0; p <= K; ++p, d= 0)\n   if (s[0][p] != s[0][p - 1])\
    \ {\n    primes.emplace_back(p);\n    uint64_t q= uint64_t(p) * p, M= N / p;\n\
    \    int t= K / p, u= std::min<uint64_t>(K, N / q);\n    for (T pw= 1; d <= D;\
    \ ++d, pw*= p) {\n     T tk= s[d][p - 1];\n     for (int n= 1; n <= t; ++n) l[d][n]-=\
    \ (l[d][n * p] - tk) * pw;\n     for (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M\
    \ / n] - tk) * pw;\n     for (uint64_t n= K; n >= q; --n) s[d][n]-= (s[d][n /\
    \ p] - tk) * pw;\n    }\n   }\n  for (size_t d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N,\
    \ s[d], l[d]);\n }\n template <class F> T additive_sum(const F &f, const PrimeSum<T>\
    \ &X) const {\n  T ret= X.sum();\n  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+=\
    \ X.sum(nN= N / d) * ((nd= N / nN + 1) - d);\n  for (uint64_t p: primes)\n   for\
    \ (uint64_t pw= p * p, e= 2; pw <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1))\
    \ * (N / pw);\n  return ret;\n }\n template <class F> T additive_sum(const F &f,\
    \ const std::vector<T> &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size()\
    \ <= pwsum.size());\n  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n\
    \  return additive_sum(f, X);\n }\n template <class F> T multiplicative_sum(const\
    \ F &f, PrimeSum<T> X) const {\n  size_t psz= primes.size();\n  for (size_t j=\
    \ psz; j--;) {\n   uint64_t p= primes[j], M= N / p, q= p * p;\n   size_t t= K\
    \ / p, u= std::min<uint64_t>(K, N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i=\
    \ q; i <= K; ++i) X.Xs[i]+= (X.Xs[i / p] - tk) * f(p, 1);\n   for (size_t i= u;\
    \ i > t; --i) X.Xl[i]+= (X.Xs[M / i] - tk) * f(p, 1);\n   for (size_t i= t; i;\
    \ --i) X.Xl[i]+= (X.Xl[i * p] - tk) * f(p, 1);\n  }\n  for (auto n= K; n; --n)\
    \ X.Xs[n]+= 1;\n  for (auto n= K; n; --n) X.Xl[n]+= 1;\n  auto dfs= [&](auto &rc,\
    \ uint64_t n, size_t bg, T cf) -> T {\n   if (cf == T(0)) return T(0);\n   T ret=\
    \ cf * X.sum(n);\n   for (auto i= bg; i < psz; ++i) {\n    uint64_t p= primes[i],\
    \ q= p * p, nn= n / q;\n    if (!nn) break;\n    for (int e= 2; nn; nn/= p, ++e)\
    \ ret+= rc(rc, nn, i + 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n   }\n   return\
    \ ret;\n  };\n  return dfs(dfs, N, 0, 1);\n }\n template <class F> T multiplicative_sum(const\
    \ F &f, const std::vector<T> &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size()\
    \ <= pwsum.size());\n  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n\
    \  return multiplicative_sum(f, X);\n }\n};\n#line 5 \"test/atcoder/abc172_d.mul_sum.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ auto f= [](long long p, short e) {\n  long long ret= e + 1;\n  while (e--) ret*=\
    \ p;\n  return ret;\n };\n long long N;\n cin >> N;\n ExtendedEratosthenesSieve<long\
    \ long> ees(N, 1);\n cout << ees.multiplicative_sum(f, {0, 2}) << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n//\
    \ O(N^(3/4)/log N)\n#include <iostream>\n#include \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ auto f= [](long long p, short e) {\n  long long ret= e + 1;\n  while (e--) ret*=\
    \ p;\n  return ret;\n };\n long long N;\n cin >> N;\n ExtendedEratosthenesSieve<long\
    \ long> ees(N, 1);\n cout << ees.multiplicative_sum(f, {0, 2}) << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/NumberTheory/ExtendedEratosthenesSieve.hpp
  isVerificationFile: true
  path: test/atcoder/abc172_d.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-26 23:02:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc172_d.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc172_d.mul_sum.test.cpp
- /verify/test/atcoder/abc172_d.mul_sum.test.cpp.html
title: test/atcoder/abc172_d.mul_sum.test.cpp
---
