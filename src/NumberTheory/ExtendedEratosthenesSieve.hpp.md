---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc172_d.mul_sum.test.cpp
    title: test/atcoder/abc172_d.mul_sum.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <tuple>\n#include <cmath>\n#include\
    \ <cstdint>\ntemplate <class T> class PrimeSum {\n uint64_t N;\n size_t K;\npublic:\n\
    \ std::vector<T> Xs, Xl;\n PrimeSum(uint64_t N= 0): N(N), K(std::sqrt(N)), Xs(K\
    \ + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N, size_t K, const std::vector<T> &s,\
    \ const std::vector<T> &l): N(N), K(K), Xs(s), Xl(l) {}\n PrimeSum operator-()\
    \ const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto &x: Ys) x= -x;\n  for (auto &x:\
    \ Yl) x= -x;\n  return PrimeSum(N, K, Ys, Yl);\n }\n PrimeSum &operator*=(T r)\
    \ {\n  for (auto &x: Xs) x*= r;\n  for (auto &x: Xl) x*= r;\n  return *this;\n\
    \ }\n PrimeSum &operator+=(T r) {\n  for (auto &x: Xs) x+= r;\n  for (auto &x:\
    \ Xl) x+= r;\n  return *this;\n }\n PrimeSum &operator-=(T r) {\n  for (auto &x:\
    \ Xs) x-= r;\n  for (auto &x: Xl) x-= r;\n  return *this;\n }\n PrimeSum &operator+=(const\
    \ PrimeSum &r) {\n  for (size_t i= Xs.size(); i--;) Xs[i]+= r.Xs[i];\n  for (size_t\
    \ i= Xl.size(); i--;) Xl[i]+= r.Xl[i];\n  return *this;\n }\n PrimeSum &operator-=(const\
    \ PrimeSum &r) {\n  for (size_t i= Xs.size(); i--;) Xs[i]-= r.Xs[i];\n  for (size_t\
    \ i= Xl.size(); i--;) Xl[i]-= r.Xl[i];\n  return *this;\n }\n PrimeSum operator*(T\
    \ r) const { return PrimeSum(*this)*= r; }\n PrimeSum operator+(T r) const { return\
    \ PrimeSum(*this)+= r; }\n PrimeSum operator-(T r) const { return PrimeSum(*this)-=\
    \ r; }\n friend PrimeSum operator*(T l, const PrimeSum &r) { return r * l; }\n\
    \ friend PrimeSum operator+(T l, const PrimeSum &r) { return r + l; }\n friend\
    \ PrimeSum operator-(T l, PrimeSum r) {\n  for (auto &x: r.Xs) x= l - x;\n  for\
    \ (auto &x: r.Xl) x= l - x;\n  return r;\n }\n PrimeSum operator+(const PrimeSum\
    \ &r) const { return PrimeSum(*this)+= r; }\n PrimeSum operator-(const PrimeSum\
    \ &r) const { return PrimeSum(*this)-= r; }\n inline T sum() const { return Xl[1];\
    \ }\n inline T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[N / n]; }\n\
    };\ntemplate <class T> class ExtendedEratosthenesSieve {\n uint64_t N;\n size_t\
    \ K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>> pwsum;\n\
    \ ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)), pwsum(D\
    \ + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)), l(D +\
    \ 1, std::vector<T>(K + 1));\n  T fct= 1;\n  for (int d= D + 1; d; --d) fct*=\
    \ d;\n  fct= T(1) / fct;\n  for (int n= 1, d= 0; n <= K; ++n, d= 0)\n   for (T\
    \ prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd;\n  for (int n= 1, d= 0; n <=\
    \ K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n) + ++d)) l[d][n]=\
    \ prd;\n  for (int d= D + 1; --d; fct*= d + 1)\n   for (int n= 1; n <= K; ++n)\
    \ s[d][n]*= fct, l[d][n]*= fct;\n  if (D >= 2) {\n   std::vector<T> stir(D + 1,\
    \ 0);\n   stir[1]= 1;\n   for (int d= 2; d <= D; stir[d++]= 1) {\n    for (int\
    \ j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n    for (int n= 1; n\
    \ <= K; ++n)\n     for (int j= 1; j < d; ++j) s[d][n]-= stir[j] * s[j][n], l[d][n]-=\
    \ stir[j] * l[j][n];\n   }\n  }\n  for (int d= 0; d <= D; ++d)\n   for (int n=\
    \ 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n  for (int p= 2, d= 0; p <= K; ++p,\
    \ d= 0)\n   if (s[0][p] != s[0][p - 1]) {\n    primes.emplace_back(p);\n    uint64_t\
    \ q= uint64_t(p) * p, M= N / p;\n    int t= K / p, u= std::min<uint64_t>(K, N\
    \ / q);\n    for (T pw= 1; d <= D; ++d, pw*= p) {\n     T tk= s[d][p - 1];\n \
    \    for (int n= 1; n <= t; ++n) l[d][n]-= (l[d][n * p] - tk) * pw;\n     for\
    \ (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M / n] - tk) * pw;\n     for (uint64_t\
    \ n= K; n >= q; --n) s[d][n]-= (s[d][n / p] - tk) * pw;\n    }\n   }\n  for (int\
    \ d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N, K, s[d], l[d]);\n }\n template <class\
    \ F> T additive_sum(const F &f, const PrimeSum<T> &X) const {\n  T ret= X.sum();\n\
    \  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= N / d) * ((nd= N / nN\
    \ + 1) - d);\n  for (uint64_t p: primes)\n   for (uint64_t pw= p * p, e= 2; pw\
    \ <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (N / pw);\n  return ret;\n\
    \ }\n template <class F> T additive_sum(const F &f, const std::vector<T> &poly)\
    \ const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n  for\
    \ (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return additive_sum(f,\
    \ X);\n }\n template <class F> T multiplicative_sum(const F &f, PrimeSum<T> X)\
    \ const {\n  size_t psz= primes.size();\n  for (size_t j= psz; j--;) {\n   uint64_t\
    \ p= primes[j], M= N / p, q= p * p;\n   int t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i= q; i <= K; ++i) X.Xs[i]+= (X.Xs[i\
    \ / p] - tk) * f(p, 1);\n   for (int i= u; i > t; --i) X.Xl[i]+= (X.Xs[M / i]\
    \ - tk) * f(p, 1);\n   for (int i= t; i; --i) X.Xl[i]+= (X.Xl[i * p] - tk) * f(p,\
    \ 1);\n  }\n  for (auto n= K; n; --n) X.Xs[n]+= 1;\n  for (auto n= K; n; --n)\
    \ X.Xl[n]+= 1;\n  auto dfs= [&](auto rc, uint64_t n, size_t bg, T cf) -> T {\n\
    \   if (cf == T(0)) return T(0);\n   T ret= cf * X.sum(n);\n   for (auto i= bg;\
    \ i < psz; ++i) {\n    uint64_t p= primes[i], q= p * p, nn= n / q;\n    if (!nn)\
    \ break;\n    for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1, cf * (f(p,\
    \ e) - f(p, 1) * f(p, e - 1)));\n   }\n   return ret;\n  };\n  return dfs(dfs,\
    \ N, 0, 1);\n }\n template <class F> T multiplicative_sum(const F &f, const std::vector<T>\
    \ &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n\
    \  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return multiplicative_sum(f,\
    \ X);\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <tuple>\n\
    #include <cmath>\n#include <cstdint>\ntemplate <class T> class PrimeSum {\n uint64_t\
    \ N;\n size_t K;\npublic:\n std::vector<T> Xs, Xl;\n PrimeSum(uint64_t N= 0):\
    \ N(N), K(std::sqrt(N)), Xs(K + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N, size_t\
    \ K, const std::vector<T> &s, const std::vector<T> &l): N(N), K(K), Xs(s), Xl(l)\
    \ {}\n PrimeSum operator-() const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto &x: Ys)\
    \ x= -x;\n  for (auto &x: Yl) x= -x;\n  return PrimeSum(N, K, Ys, Yl);\n }\n PrimeSum\
    \ &operator*=(T r) {\n  for (auto &x: Xs) x*= r;\n  for (auto &x: Xl) x*= r;\n\
    \  return *this;\n }\n PrimeSum &operator+=(T r) {\n  for (auto &x: Xs) x+= r;\n\
    \  for (auto &x: Xl) x+= r;\n  return *this;\n }\n PrimeSum &operator-=(T r) {\n\
    \  for (auto &x: Xs) x-= r;\n  for (auto &x: Xl) x-= r;\n  return *this;\n }\n\
    \ PrimeSum &operator+=(const PrimeSum &r) {\n  for (size_t i= Xs.size(); i--;)\
    \ Xs[i]+= r.Xs[i];\n  for (size_t i= Xl.size(); i--;) Xl[i]+= r.Xl[i];\n  return\
    \ *this;\n }\n PrimeSum &operator-=(const PrimeSum &r) {\n  for (size_t i= Xs.size();\
    \ i--;) Xs[i]-= r.Xs[i];\n  for (size_t i= Xl.size(); i--;) Xl[i]-= r.Xl[i];\n\
    \  return *this;\n }\n PrimeSum operator*(T r) const { return PrimeSum(*this)*=\
    \ r; }\n PrimeSum operator+(T r) const { return PrimeSum(*this)+= r; }\n PrimeSum\
    \ operator-(T r) const { return PrimeSum(*this)-= r; }\n friend PrimeSum operator*(T\
    \ l, const PrimeSum &r) { return r * l; }\n friend PrimeSum operator+(T l, const\
    \ PrimeSum &r) { return r + l; }\n friend PrimeSum operator-(T l, PrimeSum r)\
    \ {\n  for (auto &x: r.Xs) x= l - x;\n  for (auto &x: r.Xl) x= l - x;\n  return\
    \ r;\n }\n PrimeSum operator+(const PrimeSum &r) const { return PrimeSum(*this)+=\
    \ r; }\n PrimeSum operator-(const PrimeSum &r) const { return PrimeSum(*this)-=\
    \ r; }\n inline T sum() const { return Xl[1]; }\n inline T sum(uint64_t n) const\
    \ { return n <= K ? Xs[n] : Xl[N / n]; }\n};\ntemplate <class T> class ExtendedEratosthenesSieve\
    \ {\n uint64_t N;\n size_t K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>>\
    \ pwsum;\n ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)),\
    \ pwsum(D + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)),\
    \ l(D + 1, std::vector<T>(K + 1));\n  T fct= 1;\n  for (int d= D + 1; d; --d)\
    \ fct*= d;\n  fct= T(1) / fct;\n  for (int n= 1, d= 0; n <= K; ++n, d= 0)\n  \
    \ for (T prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd;\n  for (int n= 1, d= 0;\
    \ n <= K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n) + ++d)) l[d][n]=\
    \ prd;\n  for (int d= D + 1; --d; fct*= d + 1)\n   for (int n= 1; n <= K; ++n)\
    \ s[d][n]*= fct, l[d][n]*= fct;\n  if (D >= 2) {\n   std::vector<T> stir(D + 1,\
    \ 0);\n   stir[1]= 1;\n   for (int d= 2; d <= D; stir[d++]= 1) {\n    for (int\
    \ j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n    for (int n= 1; n\
    \ <= K; ++n)\n     for (int j= 1; j < d; ++j) s[d][n]-= stir[j] * s[j][n], l[d][n]-=\
    \ stir[j] * l[j][n];\n   }\n  }\n  for (int d= 0; d <= D; ++d)\n   for (int n=\
    \ 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n  for (int p= 2, d= 0; p <= K; ++p,\
    \ d= 0)\n   if (s[0][p] != s[0][p - 1]) {\n    primes.emplace_back(p);\n    uint64_t\
    \ q= uint64_t(p) * p, M= N / p;\n    int t= K / p, u= std::min<uint64_t>(K, N\
    \ / q);\n    for (T pw= 1; d <= D; ++d, pw*= p) {\n     T tk= s[d][p - 1];\n \
    \    for (int n= 1; n <= t; ++n) l[d][n]-= (l[d][n * p] - tk) * pw;\n     for\
    \ (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M / n] - tk) * pw;\n     for (uint64_t\
    \ n= K; n >= q; --n) s[d][n]-= (s[d][n / p] - tk) * pw;\n    }\n   }\n  for (int\
    \ d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N, K, s[d], l[d]);\n }\n template <class\
    \ F> T additive_sum(const F &f, const PrimeSum<T> &X) const {\n  T ret= X.sum();\n\
    \  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= N / d) * ((nd= N / nN\
    \ + 1) - d);\n  for (uint64_t p: primes)\n   for (uint64_t pw= p * p, e= 2; pw\
    \ <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (N / pw);\n  return ret;\n\
    \ }\n template <class F> T additive_sum(const F &f, const std::vector<T> &poly)\
    \ const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n  for\
    \ (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return additive_sum(f,\
    \ X);\n }\n template <class F> T multiplicative_sum(const F &f, PrimeSum<T> X)\
    \ const {\n  size_t psz= primes.size();\n  for (size_t j= psz; j--;) {\n   uint64_t\
    \ p= primes[j], M= N / p, q= p * p;\n   int t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i= q; i <= K; ++i) X.Xs[i]+= (X.Xs[i\
    \ / p] - tk) * f(p, 1);\n   for (int i= u; i > t; --i) X.Xl[i]+= (X.Xs[M / i]\
    \ - tk) * f(p, 1);\n   for (int i= t; i; --i) X.Xl[i]+= (X.Xl[i * p] - tk) * f(p,\
    \ 1);\n  }\n  for (auto n= K; n; --n) X.Xs[n]+= 1;\n  for (auto n= K; n; --n)\
    \ X.Xl[n]+= 1;\n  auto dfs= [&](auto rc, uint64_t n, size_t bg, T cf) -> T {\n\
    \   if (cf == T(0)) return T(0);\n   T ret= cf * X.sum(n);\n   for (auto i= bg;\
    \ i < psz; ++i) {\n    uint64_t p= primes[i], q= p * p, nn= n / q;\n    if (!nn)\
    \ break;\n    for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1, cf * (f(p,\
    \ e) - f(p, 1) * f(p, e - 1)));\n   }\n   return ret;\n  };\n  return dfs(dfs,\
    \ N, 0, 1);\n }\n template <class F> T multiplicative_sum(const F &f, const std::vector<T>\
    \ &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n\
    \  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return multiplicative_sum(f,\
    \ X);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/ExtendedEratosthenesSieve.hpp
  requiredBy: []
  timestamp: '2023-11-25 18:44:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/counting_primes.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/atcoder/abc172_d.mul_sum.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
documentation_of: src/NumberTheory/ExtendedEratosthenesSieve.hpp
layout: document
title: "\u62E1\u5F35\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u7BE9"
---

## 計算量
$\mathcal{O} (d^2\sqrt{N}+dN^{3/4}/\log N)$ \
$d$ := degre of polynomial
## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) \
[Xmas Contest 2019 E - Sum of f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e) (加法的関数) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) (2次多項式) \
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) 
