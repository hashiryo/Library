---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  - icon: ':question:'
    path: src/NumberTheory/CumSumQuotient.hpp
    title: "$\\lfloor N/x \\rfloor$ \u306E\u914D\u5217"
  - icon: ':question:'
    path: src/NumberTheory/enumerate_primes.hpp
    title: "\u7D20\u6570\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.mul_sum.test.cpp
    title: test/atcoder/abc172_d.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/enumerate_primes.hpp\"\n#include <algorithm>\n\
    #include <cstdint>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
    #include <iostream>\n#include <iterator>\ntemplate <class T> struct ListRange\
    \ {\n using Iterator= typename std::vector<T>::iterator;\n Iterator bg, ed;\n\
    \ Iterator begin() const { return bg; }\n Iterator end() const { return ed; }\n\
    \ size_t size() const { return std::distance(bg, ed); }\n T &operator[](int i)\
    \ const { return bg[i]; }\n friend std::ostream &operator<<(std::ostream &os,\
    \ const ListRange &r) {\n  os << '[';\n  for (int i= 0, e= r.size(); i < e; ++i)\
    \ os << (i ? \", \" : \"\") << r[i];\n  return os << ']';\n }\n};\ntemplate <class\
    \ T> struct ConstListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n\
    \ Iterator bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const\
    \ { return ed; }\n size_t size() const { return std::distance(bg, ed); }\n const\
    \ T &operator[](int i) const { return bg[i]; }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const ConstListRange &r) {\n  os << '[';\n  for (int i= 0, e= r.size();\
    \ i < e; ++i) os << (i ? \", \" : \"\") << r[i];\n  return os << ']';\n }\n};\n\
    #line 5 \"src/NumberTheory/enumerate_primes.hpp\"\nnamespace nt_internal {\nusing\
    \ namespace std;\nvector<int> ps, lf;\nvoid sieve(int N) {\n static int n= 2;\n\
    \ if (n > N) return;\n if (lf.resize((N + 1) >> 1); n == 2) ps.push_back(n++);\n\
    \ int M= (N - 1) / 2;\n for (int j= 1, e= ps.size(); j < e; ++j) {\n  int p= ps[j];\n\
    \  if (int64_t(p) * p > N) break;\n  for (auto k= int64_t(p) * max(n / p / 2 *\
    \ 2 + 1, p) / 2; k <= M; k+= p) lf[k]+= p * !lf[k];\n }\n for (; n <= N; n+= 2)\n\
    \  if (!lf[n >> 1]) {\n   ps.push_back(lf[n >> 1]= n);\n   for (auto j= int64_t(n)\
    \ * n / 2; j <= M; j+= n) lf[j]+= n * !lf[j];\n  }\n}\nConstListRange<int> enumerate_primes()\
    \ { return {ps.cbegin(), ps.cend()}; }\nConstListRange<int> enumerate_primes(int\
    \ N) {\n sieve(N);\n return {ps.cbegin(), upper_bound(ps.cbegin(), ps.cend(),\
    \ N)};\n}\nint least_prime_factor(int n) { return n & 1 ? sieve(n), lf[(n >> 1)]\
    \ : 2; }\n// f(p,e) := f(p^e)\ntemplate <class T, class F> vector<T> completely_multiplicative_table(int\
    \ N, const F &f) {\n vector<T> ret(N + 1);\n sieve(N);\n for (int n= 3, i= 1;\
    \ n <= N; n+= 2, ++i) ret[n]= lf[i] == n ? f(n, 1) : ret[lf[i]] * ret[n / lf[i]];\n\
    \ if (int n= 4; 2 <= N)\n  for (T t= ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= t\
    \ * ret[n >> 1];\n return ret[1]= 1, ret;\n}\n}\nusing nt_internal::enumerate_primes,\
    \ nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;\n\
    // O(N log k / log N + N)\ntemplate <class T> static std::vector<T> pow_table(int\
    \ N, uint64_t k) {\n if (k == 0) return std::vector<T>(N + 1, 1);\n auto f= [k](int\
    \ p, int) {\n  T ret= 1, b= p;\n  for (auto e= k;; b*= b) {\n   if (e & 1) ret*=\
    \ b;\n   if (!(e>>= 1)) return ret;\n  }\n };\n return completely_multiplicative_table<T>(N,\
    \ f);\n}\n#line 3 \"src/NumberTheory/CumSumQuotient.hpp\"\n#include <valarray>\n\
    template <class T> struct CumSumQuotient {\n uint64_t N;\n size_t K;\n std::valarray<T>\
    \ X;\n CumSumQuotient(uint64_t N): N(N), K(std::sqrt(N)), X(K + K + 1) {}\n T\
    \ &operator[](uint64_t i) { return i > K ? X[K + double(N) / i] : X[i]; }\n T\
    \ operator()(uint64_t i) const { return i > K ? X[K + double(N) / i] : X[i]; }\n\
    \ CumSumQuotient &operator+=(const CumSumQuotient &r) { return X+= r.X, *this;\
    \ }\n CumSumQuotient &operator-=(const CumSumQuotient &r) { return X-= r.X, *this;\
    \ }\n CumSumQuotient &operator*=(T a) { return X*= a, *this; }\n CumSumQuotient\
    \ operator-() const {\n  CumSumQuotient ret= *this;\n  return ret.X= -ret.X, ret;\n\
    \ }\n CumSumQuotient operator+(const CumSumQuotient &r) const { return CumSumQuotient(*this)+=\
    \ r; }\n CumSumQuotient operator-(const CumSumQuotient &r) const { return CumSumQuotient(*this)-=\
    \ r; }\n CumSumQuotient operator*(T a) const { return CumSumQuotient(*this)*=\
    \ a; }\n friend CumSumQuotient operator*(T a, const CumSumQuotient &x) { return\
    \ x * a; }\n void add(uint64_t i, T v) {\n  for (size_t j= std::min<uint64_t>(N\
    \ / i, K) + K; j >= i; --j) X[j]+= v;\n }\n T sum() const { return X[K + 1]; }\n\
    \ T sum(uint64_t i) const { return i > K ? X[K + double(N) / i] : X[i]; }\n};\n\
    #line 4 \"src/NumberTheory/sum_on_primes.hpp\"\ntemplate <class T> std::vector<CumSumQuotient<T>>\
    \ sums_of_powers_on_primes(uint64_t N, size_t D) {\n size_t K= std::sqrt(N);\n\
    \ std::vector ret(D + 1, CumSumQuotient<T>(N));\n for (size_t n= 1, d= 0; n <=\
    \ K; ++n, d= 0)\n  for (T prd= n; d <= D; prd*= (n + ++d)) ret[d].X[n]= prd /\
    \ (d + 1);\n for (size_t n= 1, d= 0; n <= K; ++n, d= 0)\n  for (T prd= N / n;\
    \ d <= D; prd*= ((N / n) + ++d)) ret[d].X[n + K]= prd / (d + 1);\n if (D >= 2)\
    \ {\n  std::vector<T> stir(D + 1, 0);\n  stir[1]= 1;\n  for (size_t d= 2; d <=\
    \ D; stir[d++]= 1) {\n   for (size_t j= d; --j;) stir[j]= stir[j - 1] + stir[j]\
    \ * (d - 1);\n   for (size_t j= 1; j < d; ++j) ret[d].X-= stir[j] * ret[j].X;\n\
    \  }\n }\n for (size_t d= 0; d <= D; ++d) ret[d].X-= 1;\n for (int p: enumerate_primes(K))\
    \ {\n  uint64_t q= uint64_t(p) * p, M= N / p;\n  T pw= 1;\n  for (size_t d= 0,\
    \ t= K / p, u= std::min<uint64_t>(K, N / q); d <= D; ++d, pw*= p) {\n   auto &X=\
    \ ret[d].X;\n   T tk= X[p - 1];\n   for (size_t n= 1; n <= t; ++n) X[n + K]-=\
    \ (X[n * p + K] - tk) * pw;\n   for (size_t n= t + 1; n <= u; ++n) X[n + K]-=\
    \ (X[double(M) / n] - tk) * pw;\n   for (uint64_t n= K; n >= q; --n) X[n]-= (X[double(n)\
    \ / p] - tk) * pw;\n  }\n }\n return ret;\n}\ntemplate <class T, class F> T additive_sum(const\
    \ CumSumQuotient<T> &P, const F &f) {\n T ret= P.sum();\n for (uint64_t d= 2,\
    \ nN, nd; nN= double(P.N) / d; d= nd) ret+= P(nN) * ((nd= double(P.N) / nN + 1)\
    \ - d);\n for (uint64_t p: enumerate_primes(P.K))\n  for (uint64_t pw= p * p,\
    \ e= 2; pw <= P.N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (P.N / pw);\n\
    \ return ret;\n}\ntemplate <class T, class F> T multiplicative_sum(CumSumQuotient<T>\
    \ P, const F &f) {\n auto ps= enumerate_primes(P.K);\n size_t psz= ps.size();\n\
    \ for (size_t j= psz; j--;) {\n  uint64_t p= ps[j], M= P.N / p, q= p * p;\n  size_t\
    \ t= P.K / p, u= std::min<uint64_t>(P.K, P.N / q);\n  T tk= P.X[p - 1];\n  for\
    \ (auto i= q; i <= P.K; ++i) P.X[i]+= (P.X[double(i) / p] - tk) * f(p, 1);\n \
    \ for (size_t i= u; i > t; --i) P.X[i + P.K]+= (P.X[double(M) / i] - tk) * f(p,\
    \ 1);\n  for (size_t i= t; i; --i) P.X[i + P.K]+= (P.X[i * p + P.K] - tk) * f(p,\
    \ 1);\n }\n P.X+= 1;\n auto dfs= [&](auto &rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n  if (cf == T(0)) return T(0);\n  T ret= cf * P(n);\n  for (auto i= bg;\
    \ i < psz; ++i) {\n   uint64_t p= ps[i], q= p * p, nn= n / q;\n   if (!nn) break;\n\
    \   for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1, cf * (f(p, e) - f(p,\
    \ 1) * f(p, e - 1)));\n  }\n  return ret;\n };\n return dfs(dfs, P.N, 0, 1);\n\
    }\n"
  code: "#pragma once\n#include \"src/NumberTheory/enumerate_primes.hpp\"\n#include\
    \ \"src/NumberTheory/CumSumQuotient.hpp\"\ntemplate <class T> std::vector<CumSumQuotient<T>>\
    \ sums_of_powers_on_primes(uint64_t N, size_t D) {\n size_t K= std::sqrt(N);\n\
    \ std::vector ret(D + 1, CumSumQuotient<T>(N));\n for (size_t n= 1, d= 0; n <=\
    \ K; ++n, d= 0)\n  for (T prd= n; d <= D; prd*= (n + ++d)) ret[d].X[n]= prd /\
    \ (d + 1);\n for (size_t n= 1, d= 0; n <= K; ++n, d= 0)\n  for (T prd= N / n;\
    \ d <= D; prd*= ((N / n) + ++d)) ret[d].X[n + K]= prd / (d + 1);\n if (D >= 2)\
    \ {\n  std::vector<T> stir(D + 1, 0);\n  stir[1]= 1;\n  for (size_t d= 2; d <=\
    \ D; stir[d++]= 1) {\n   for (size_t j= d; --j;) stir[j]= stir[j - 1] + stir[j]\
    \ * (d - 1);\n   for (size_t j= 1; j < d; ++j) ret[d].X-= stir[j] * ret[j].X;\n\
    \  }\n }\n for (size_t d= 0; d <= D; ++d) ret[d].X-= 1;\n for (int p: enumerate_primes(K))\
    \ {\n  uint64_t q= uint64_t(p) * p, M= N / p;\n  T pw= 1;\n  for (size_t d= 0,\
    \ t= K / p, u= std::min<uint64_t>(K, N / q); d <= D; ++d, pw*= p) {\n   auto &X=\
    \ ret[d].X;\n   T tk= X[p - 1];\n   for (size_t n= 1; n <= t; ++n) X[n + K]-=\
    \ (X[n * p + K] - tk) * pw;\n   for (size_t n= t + 1; n <= u; ++n) X[n + K]-=\
    \ (X[double(M) / n] - tk) * pw;\n   for (uint64_t n= K; n >= q; --n) X[n]-= (X[double(n)\
    \ / p] - tk) * pw;\n  }\n }\n return ret;\n}\ntemplate <class T, class F> T additive_sum(const\
    \ CumSumQuotient<T> &P, const F &f) {\n T ret= P.sum();\n for (uint64_t d= 2,\
    \ nN, nd; nN= double(P.N) / d; d= nd) ret+= P(nN) * ((nd= double(P.N) / nN + 1)\
    \ - d);\n for (uint64_t p: enumerate_primes(P.K))\n  for (uint64_t pw= p * p,\
    \ e= 2; pw <= P.N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (P.N / pw);\n\
    \ return ret;\n}\ntemplate <class T, class F> T multiplicative_sum(CumSumQuotient<T>\
    \ P, const F &f) {\n auto ps= enumerate_primes(P.K);\n size_t psz= ps.size();\n\
    \ for (size_t j= psz; j--;) {\n  uint64_t p= ps[j], M= P.N / p, q= p * p;\n  size_t\
    \ t= P.K / p, u= std::min<uint64_t>(P.K, P.N / q);\n  T tk= P.X[p - 1];\n  for\
    \ (auto i= q; i <= P.K; ++i) P.X[i]+= (P.X[double(i) / p] - tk) * f(p, 1);\n \
    \ for (size_t i= u; i > t; --i) P.X[i + P.K]+= (P.X[double(M) / i] - tk) * f(p,\
    \ 1);\n  for (size_t i= t; i; --i) P.X[i + P.K]+= (P.X[i * p + P.K] - tk) * f(p,\
    \ 1);\n }\n P.X+= 1;\n auto dfs= [&](auto &rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n  if (cf == T(0)) return T(0);\n  T ret= cf * P(n);\n  for (auto i= bg;\
    \ i < psz; ++i) {\n   uint64_t p= ps[i], q= p * p, nn= n / q;\n   if (!nn) break;\n\
    \   for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1, cf * (f(p, e) - f(p,\
    \ 1) * f(p, e - 1)));\n  }\n  return ret;\n };\n return dfs(dfs, P.N, 0, 1);\n\
    }"
  dependsOn:
  - src/NumberTheory/enumerate_primes.hpp
  - src/Internal/ListRange.hpp
  - src/NumberTheory/CumSumQuotient.hpp
  isVerificationFile: false
  path: src/NumberTheory/sum_on_primes.hpp
  requiredBy: []
  timestamp: '2024-02-13 11:50:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc172_d.mul_sum.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
  - test/yosupo/counting_primes.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
documentation_of: src/NumberTheory/sum_on_primes.hpp
layout: document
title: "\u7D20\u6570\u4E0A\u306E\u7D2F\u7A4D\u548C"
---

$\newcommand{\floor}[1]{\left\lfloor{#1}\right\rfloor}$

加法的関数もしくは乗法的関数 $f$ について，その累積和

$
\displaystyle
F(N) = \sum_{i=1}^N f(i)
$

を計算するための関数群．

数論的関数 $f$ について，素数上で $n\in \left\lbrace \left. \floor{\frac{N}{x}} \right \vert x\in \mathbb{Z}, 1\leq x\leq N\right\rbrace$ まで累積和をとったもの

$
\displaystyle
P(n) = \sum_{\substack{p: \mathrm{prime} \\ p \leq n}} f(p)
$

を利用することで $F(n)$ を計算する. \
$P(n)$ は[`CumSumQuotient<T>` クラス](CumSumQuotient.hpp) として扱う.


|関数名|概要|計算量|
|---|---|---|
|`sums_of_powers_on_primes<T>(N,D)`| $n\in \left\lbrace \left. \floor{\frac{N}{x}} \right \vert x\in \mathbb{Z}, 1\leq x\leq N\right\rbrace$ までの <br> 素数上の $k$ 乗数の累積和 <br> $\displaystyle \sum_{\substack{p: \mathrm{prime} \\ p \leq n}} p^k$ <br>を $k=0,\dots,D$ まで計算したものを返す. <br> 特に $k=0$ は素数計数関数 $\pi(n)$ となる. <br> 返り値は`vector<CumSumQuotient<T>>`.|$\displaystyle O\left(\frac{DN^{3/4}}{\log N}\right)$|
|`additive_sum(P,f)`|加法的関数 $f$ について累積和 $F(N)$ を返す. <br> $\displaystyle P(n)=\sum_{\substack{p: \mathrm{prime} \\ p \leq n}} f(p)$ を表す `CumSumQuotient<T>` クラスの `P` と $f(p^e)$ を表す `f(p,e)`を渡す．|$\displaystyle O\left(\sqrt{N}\right)$|
|`multiplicative_sum(P,f)`|乗法的関数 $f$ について累積和 $F(N)$ を返す. <br> $\displaystyle P(n)=\sum_{\substack{p: \mathrm{prime} \\ p \leq n}} f(p)$ を表す `CumSumQuotient<T>` クラスの `P` と $f(p^e)$ を表す `f(p,e)`を渡す．|$\displaystyle O\left(\frac{DN^{3/4}}{\log N}\right)$|

## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) \
[Xmas Contest 2019 E - Sum of f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e) (加法的関数) \
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) ($f(p)$ が2次多項式) \
[LibreOJ #6053. 简单的函数](https://loj.ac/p/6053) ($f(p)$ が単純な多項式でない)

## 参考
[https://oi-wiki.org/math/number-theory/min-25/](https://oi-wiki.org/math/number-theory/min-25/)