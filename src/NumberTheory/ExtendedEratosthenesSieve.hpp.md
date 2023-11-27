---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.mul_sum.test.cpp
    title: test/atcoder/abc172_d.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/ExtendedEratosthenesSieve.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <tuple>\n#include <cmath>\n#include\
    \ <cstdint>\n#include <cassert>\ntemplate <class T> struct PrimeSum {\n uint64_t\
    \ N;\n size_t K;\n std::vector<T> Xs, Xl;\n PrimeSum(uint64_t N= 0): N(N), K(std::sqrt(N)),\
    \ Xs(K + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N, const std::vector<T> &s, const\
    \ std::vector<T> &l): N(N), K(std::sqrt(N)), Xs(s), Xl(l) {}\n PrimeSum operator-()\
    \ const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto &x: Ys) x= -x;\n  for (auto &x:\
    \ Yl) x= -x;\n  return PrimeSum(N, Ys, Yl);\n }\n PrimeSum &operator*=(T r) {\n\
    \  for (auto &x: Xs) x*= r;\n  for (auto &x: Xl) x*= r;\n  return *this;\n }\n\
    \ PrimeSum &operator+=(const PrimeSum &r) {\n  for (size_t i= K + 1; i--;) Xs[i]+=\
    \ r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]+= r.Xl[i];\n  return *this;\n\
    \ }\n PrimeSum &operator-=(const PrimeSum &r) {\n  for (size_t i= K + 1; i--;)\
    \ Xs[i]-= r.Xs[i];\n  for (size_t i= K + 1; i--;) Xl[i]-= r.Xl[i];\n  return *this;\n\
    \ }\n PrimeSum operator*(T r) const { return PrimeSum(*this)*= r; }\n friend PrimeSum\
    \ operator*(T l, const PrimeSum &r) { return r * l; }\n PrimeSum operator+(const\
    \ PrimeSum &r) const { return PrimeSum(*this)+= r; }\n PrimeSum operator-(const\
    \ PrimeSum &r) const { return PrimeSum(*this)-= r; }\n inline T sum() const {\
    \ return Xl[1]; }\n inline T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[N\
    \ / n]; }\n void add(uint64_t p, T v) {\n  for (size_t i= p; i <= K; ++i) Xs[i]+=\
    \ v;\n  for (size_t i= std::min<uint64_t>(N / p, K); i; --i) Xl[i]+= v;\n }\n\
    };\ntemplate <class T> class ExtendedEratosthenesSieve {\n uint64_t N;\n size_t\
    \ K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>> pwsum;\n\
    \ ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)), pwsum(D\
    \ + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)), l(D +\
    \ 1, std::vector<T>(K + 1));\n  for (int n= 1, d= 0; n <= K; ++n, d= 0)\n   for\
    \ (T prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd / (d + 1);\n  for (int n= 1,\
    \ d= 0; n <= K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n) + ++d))\
    \ l[d][n]= prd / (d + 1);\n  if (D >= 2) {\n   std::vector<T> stir(D + 1, 0);\n\
    \   stir[1]= 1;\n   for (size_t d= 2; d <= D; stir[d++]= 1) {\n    for (size_t\
    \ j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n    for (size_t n= 1;\
    \ n <= K; ++n)\n     for (size_t j= 1; j < d; ++j) s[d][n]-= stir[j] * s[j][n],\
    \ l[d][n]-= stir[j] * l[j][n];\n   }\n  }\n  for (size_t d= 0; d <= D; ++d)\n\
    \   for (size_t n= 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n  for (size_t p=\
    \ 2, d= 0; p <= K; ++p, d= 0)\n   if (s[0][p] != s[0][p - 1]) {\n    primes.emplace_back(p);\n\
    \    uint64_t q= uint64_t(p) * p, M= N / p;\n    int t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n    for (T pw= 1; d <= D; ++d, pw*= p) {\n     T tk= s[d][p - 1];\n\
    \     for (int n= 1; n <= t; ++n) l[d][n]-= (l[d][n * p] - tk) * pw;\n     for\
    \ (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M / n] - tk) * pw;\n     for (uint64_t\
    \ n= K; n >= q; --n) s[d][n]-= (s[d][n / p] - tk) * pw;\n    }\n   }\n  for (size_t\
    \ d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N, s[d], l[d]);\n }\n template <class\
    \ F> T additive_sum(const F &f, const PrimeSum<T> &X) const {\n  T ret= X.sum();\n\
    \  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= N / d) * ((nd= N / nN\
    \ + 1) - d);\n  for (uint64_t p: primes)\n   for (uint64_t pw= p * p, e= 2; pw\
    \ <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (N / pw);\n  return ret;\n\
    \ }\n template <class F> T additive_sum(const F &f, const std::vector<T> &poly)\
    \ const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n  for\
    \ (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return additive_sum(f,\
    \ X);\n }\n template <class F> T multiplicative_sum(const F &f, PrimeSum<T> X)\
    \ const {\n  size_t psz= primes.size();\n  for (size_t j= psz; j--;) {\n   uint64_t\
    \ p= primes[j], M= N / p, q= p * p;\n   size_t t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i= q; i <= K; ++i) X.Xs[i]+= (X.Xs[i\
    \ / p] - tk) * f(p, 1);\n   for (size_t i= u; i > t; --i) X.Xl[i]+= (X.Xs[M /\
    \ i] - tk) * f(p, 1);\n   for (size_t i= t; i; --i) X.Xl[i]+= (X.Xl[i * p] - tk)\
    \ * f(p, 1);\n  }\n  for (auto n= K; n; --n) X.Xs[n]+= 1;\n  for (auto n= K; n;\
    \ --n) X.Xl[n]+= 1;\n  auto dfs= [&](auto &rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n   if (cf == T(0)) return T(0);\n   T ret= cf * X.sum(n);\n   for (auto\
    \ i= bg; i < psz; ++i) {\n    uint64_t p= primes[i], q= p * p, nn= n / q;\n  \
    \  if (!nn) break;\n    for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1,\
    \ cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n   }\n   return ret;\n  };\n  return\
    \ dfs(dfs, N, 0, 1);\n }\n template <class F> T multiplicative_sum(const F &f,\
    \ const std::vector<T> &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size()\
    \ <= pwsum.size());\n  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n\
    \  return multiplicative_sum(f, X);\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <tuple>\n\
    #include <cmath>\n#include <cstdint>\n#include <cassert>\ntemplate <class T> struct\
    \ PrimeSum {\n uint64_t N;\n size_t K;\n std::vector<T> Xs, Xl;\n PrimeSum(uint64_t\
    \ N= 0): N(N), K(std::sqrt(N)), Xs(K + 1), Xl(K + 1) {}\n PrimeSum(uint64_t N,\
    \ const std::vector<T> &s, const std::vector<T> &l): N(N), K(std::sqrt(N)), Xs(s),\
    \ Xl(l) {}\n PrimeSum operator-() const {\n  auto Ys= Xs, Yl= Xl;\n  for (auto\
    \ &x: Ys) x= -x;\n  for (auto &x: Yl) x= -x;\n  return PrimeSum(N, Ys, Yl);\n\
    \ }\n PrimeSum &operator*=(T r) {\n  for (auto &x: Xs) x*= r;\n  for (auto &x:\
    \ Xl) x*= r;\n  return *this;\n }\n PrimeSum &operator+=(const PrimeSum &r) {\n\
    \  for (size_t i= K + 1; i--;) Xs[i]+= r.Xs[i];\n  for (size_t i= K + 1; i--;)\
    \ Xl[i]+= r.Xl[i];\n  return *this;\n }\n PrimeSum &operator-=(const PrimeSum\
    \ &r) {\n  for (size_t i= K + 1; i--;) Xs[i]-= r.Xs[i];\n  for (size_t i= K +\
    \ 1; i--;) Xl[i]-= r.Xl[i];\n  return *this;\n }\n PrimeSum operator*(T r) const\
    \ { return PrimeSum(*this)*= r; }\n friend PrimeSum operator*(T l, const PrimeSum\
    \ &r) { return r * l; }\n PrimeSum operator+(const PrimeSum &r) const { return\
    \ PrimeSum(*this)+= r; }\n PrimeSum operator-(const PrimeSum &r) const { return\
    \ PrimeSum(*this)-= r; }\n inline T sum() const { return Xl[1]; }\n inline T sum(uint64_t\
    \ n) const { return n <= K ? Xs[n] : Xl[N / n]; }\n void add(uint64_t p, T v)\
    \ {\n  for (size_t i= p; i <= K; ++i) Xs[i]+= v;\n  for (size_t i= std::min<uint64_t>(N\
    \ / p, K); i; --i) Xl[i]+= v;\n }\n};\ntemplate <class T> class ExtendedEratosthenesSieve\
    \ {\n uint64_t N;\n size_t K;\npublic:\n std::vector<size_t> primes;\n std::vector<PrimeSum<T>>\
    \ pwsum;\n ExtendedEratosthenesSieve(uint64_t N, size_t D): N(N), K(std::sqrt(N)),\
    \ pwsum(D + 1) {\n  std::vector<std::vector<T>> s(D + 1, std::vector<T>(K + 1)),\
    \ l(D + 1, std::vector<T>(K + 1));\n  for (int n= 1, d= 0; n <= K; ++n, d= 0)\n\
    \   for (T prd= n; d <= D; prd*= (n + ++d)) s[d][n]= prd / (d + 1);\n  for (int\
    \ n= 1, d= 0; n <= K; ++n, d= 0)\n   for (T prd= N / n; d <= D; prd*= ((N / n)\
    \ + ++d)) l[d][n]= prd / (d + 1);\n  if (D >= 2) {\n   std::vector<T> stir(D +\
    \ 1, 0);\n   stir[1]= 1;\n   for (size_t d= 2; d <= D; stir[d++]= 1) {\n    for\
    \ (size_t j= d; --j;) stir[j]= stir[j - 1] + stir[j] * (d - 1);\n    for (size_t\
    \ n= 1; n <= K; ++n)\n     for (size_t j= 1; j < d; ++j) s[d][n]-= stir[j] * s[j][n],\
    \ l[d][n]-= stir[j] * l[j][n];\n   }\n  }\n  for (size_t d= 0; d <= D; ++d)\n\
    \   for (size_t n= 1; n <= K; ++n) s[d][n]-= 1, l[d][n]-= 1;\n  for (size_t p=\
    \ 2, d= 0; p <= K; ++p, d= 0)\n   if (s[0][p] != s[0][p - 1]) {\n    primes.emplace_back(p);\n\
    \    uint64_t q= uint64_t(p) * p, M= N / p;\n    int t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n    for (T pw= 1; d <= D; ++d, pw*= p) {\n     T tk= s[d][p - 1];\n\
    \     for (int n= 1; n <= t; ++n) l[d][n]-= (l[d][n * p] - tk) * pw;\n     for\
    \ (int n= t + 1; n <= u; ++n) l[d][n]-= (s[d][M / n] - tk) * pw;\n     for (uint64_t\
    \ n= K; n >= q; --n) s[d][n]-= (s[d][n / p] - tk) * pw;\n    }\n   }\n  for (size_t\
    \ d= 0; d <= D; ++d) pwsum[d]= PrimeSum(N, s[d], l[d]);\n }\n template <class\
    \ F> T additive_sum(const F &f, const PrimeSum<T> &X) const {\n  T ret= X.sum();\n\
    \  for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= N / d) * ((nd= N / nN\
    \ + 1) - d);\n  for (uint64_t p: primes)\n   for (uint64_t pw= p * p, e= 2; pw\
    \ <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * (N / pw);\n  return ret;\n\
    \ }\n template <class F> T additive_sum(const F &f, const std::vector<T> &poly)\
    \ const {\n  PrimeSum<T> X(N);\n  assert(poly.size() <= pwsum.size());\n  for\
    \ (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n  return additive_sum(f,\
    \ X);\n }\n template <class F> T multiplicative_sum(const F &f, PrimeSum<T> X)\
    \ const {\n  size_t psz= primes.size();\n  for (size_t j= psz; j--;) {\n   uint64_t\
    \ p= primes[j], M= N / p, q= p * p;\n   size_t t= K / p, u= std::min<uint64_t>(K,\
    \ N / q);\n   T tk= X.Xs[p - 1];\n   for (auto i= q; i <= K; ++i) X.Xs[i]+= (X.Xs[i\
    \ / p] - tk) * f(p, 1);\n   for (size_t i= u; i > t; --i) X.Xl[i]+= (X.Xs[M /\
    \ i] - tk) * f(p, 1);\n   for (size_t i= t; i; --i) X.Xl[i]+= (X.Xl[i * p] - tk)\
    \ * f(p, 1);\n  }\n  for (auto n= K; n; --n) X.Xs[n]+= 1;\n  for (auto n= K; n;\
    \ --n) X.Xl[n]+= 1;\n  auto dfs= [&](auto &rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n   if (cf == T(0)) return T(0);\n   T ret= cf * X.sum(n);\n   for (auto\
    \ i= bg; i < psz; ++i) {\n    uint64_t p= primes[i], q= p * p, nn= n / q;\n  \
    \  if (!nn) break;\n    for (int e= 2; nn; nn/= p, ++e) ret+= rc(rc, nn, i + 1,\
    \ cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n   }\n   return ret;\n  };\n  return\
    \ dfs(dfs, N, 0, 1);\n }\n template <class F> T multiplicative_sum(const F &f,\
    \ const std::vector<T> &poly) const {\n  PrimeSum<T> X(N);\n  assert(poly.size()\
    \ <= pwsum.size());\n  for (size_t d= poly.size(); d--;) X+= poly[d] * pwsum[d];\n\
    \  return multiplicative_sum(f, X);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/ExtendedEratosthenesSieve.hpp
  requiredBy: []
  timestamp: '2023-11-27 11:00:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/counting_primes.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/atcoder/abc172_d.mul_sum.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
documentation_of: src/NumberTheory/ExtendedEratosthenesSieve.hpp
layout: document
title: "\u62E1\u5F35\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u7BE9"
---

$\newcommand{\floor}[1]{\left\lfloor{#1}\right\rfloor}$


## `PrimeSum<T>` クラス
正の整数 $N$ が与えられるとする. <br>
ある数論的関数 $f$ と $k\in \lbrace a\in \mathbb{N}\; \vert\; \exists m \in \mathbb{N}, a=\floor{\frac{N}{m}}\rbrace$ について

$\displaystyle
F_p(k) = \sum_{\substack{p\leq k\newline p \text{ is a prime}}} f(p)
$

の値を格納する (と思うことにする) データ構造. \
$f$ や $F$ そのものは保持しない. \
加減算とスカラー倍の演算子をサポート.

|メンバ変数|概要|
|---|---|
|`N`|$N$|
|`K`|$K=\floor{\sqrt{N}}$|
|`Xs`|$F_p(1),\dots,F_p(K)$ の値を保存している配列. <br> サイズは$K+1$. 0番目の値は未定義.|
|`Xl`|$F_p(\floor{N/1}),\dots,F_p(\floor{N/L})$ の値を保存している配列. <br> サイズは$L+1$. 0番目の値は未定義.|

|演算子オーバーロード|概要 ( $f,g$ から $h$ を返すイメージ )|計算量|
|---|---|---|
|`operator-(f)`|$h(n)=-f(n)$|$O(K+L)$|
|`operator+(f,g)`|$h(n)=f(n)+g(n)$|$O(K+L)$|
|`operator-(f,g)`|$h(n)=f(n)-g(n)$|$O(K+L)$|
|`operator*(f,a)`|$h(n)= f(n)\cdot a$|$O(K+L)$|
|`operator*(a,f)`|$h(n)=a\cdot f(n)$ (上と同じ)|$O(K+L)$|


|メンバ関数|概要|
|---|---|
|`PrimeSum(N, Xs, Xl)`|コンストラクタ. $N$ と配列を直接渡して構築.||
|`PrimeSum(N=0)`|コンストラクタ. $N$ を渡して構築. <br> $f(n)\equiv \varepsilon(n)$ のケースとして構築. |
|`sum(k)`| $F_p(k)$ を返す. <br>ただし <br> $\displaystyle k\in\left \lbrace a\in \mathbb{N}\; \vert\; \exists m \in \mathbb{N}, a=\floor{\frac{N}{m}}\right\rbrace$ <br>のケースのみ想定.|
|`sum()`|$\displaystyle F_p(N)= \sum_{\substack{p\leq N\newline p \text{ is a prime}}} f(p)$ を返す.|
|`add(p, v)`| $f(p)\leftarrow f(p)+v$ <br> $p$ は素数を想定. |

## `ExtendedEratosthenesSieve<T>` クラス

コンストラクタで前処理をしておいて, 乗法的関数や加法的関数の累積和を求める関数を提供するクラス.

|メンバ変数|概要|
|---|---|
|`primes`|$\sqrt{N}$ 以下の素数が列挙されている `vector`. |
|`pwsum`|`pwsum[d]` が $f(p)\equiv p^d$ についての `PrimeSum` クラスのオブジェクト. <br> `vector<PrimeSum>` 型. |

|メンバ関数|概要|計算量|
|---|---|---|
|`ExtendedEratosthenesSieve(N,D)`|$N$ と `pwsum` の最大次元 $D$ を渡して構築. <br> 線形篩を計算する. |$\displaystyle \mathcal{O}\left(\frac{N^{3/4}}{\log N}\right)$|
|`addtive_sum(f, X)`|加法的関数 $f$ について累積和 $\displaystyle \sum_{n=1}^N f(n)$ を返す. <br> $f(p^e)$ を表す `f(p,e)` とその $f$ に関する `PrimeSum` クラスのオブジェクト `X` を渡す. | $\mathcal{O}(\sqrt{N})$ |
|`addtive_sum(f, poly)`|加法的関数 $f$ について累積和 $\displaystyle \sum_{n=1}^N f(n)$ を返す. <br> $f(p^e)$ を表す `f(p,e)` と $f(p)$ の $p$ の多項式の係数列 `poly` を渡す. | $\mathcal{O}(\sqrt{N})$ |
|`multiplicative_sum(f, X)`|乗法的関数 $f$ について累積和 $\displaystyle \sum_{n=1}^N f(n)$ を返す. <br> $f(p^e)$ を表す `f(p,e)` とその $f$ に関する `PrimeSum` クラスのオブジェクト `X` を渡す. | $\displaystyle \mathcal{O}\left(\frac{N^{3/4}}{\log N}\right)$ |
|`multiplicative_sum(f, poly)`|乗法的関数 $f$ について累積和 $\displaystyle \sum_{n=1}^N f(n)$ を返す. <br> $f(p^e)$ を表す `f(p,e)` と $f(p)$ の $p$ の多項式の係数列 `poly` を渡す. | $\displaystyle \mathcal{O}\left(\frac{N^{3/4}}{\log N}\right)$ |

## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) \
[Xmas Contest 2019 E - Sum of f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e) (加法的関数) \
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) (2次多項式) \
[LibreOJ #6053. 简单的函数](https://loj.ac/p/6053) (単純な多項式でない)
