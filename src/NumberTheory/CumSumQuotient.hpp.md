---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/NumberTheory/sum_on_primes.hpp
    title: "\u7D20\u6570\u4E0A\u306E\u7D2F\u7A4D\u548C"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.mul_sum.test.cpp
    title: test/atcoder/abc172_d.mul_sum.test.cpp
  - icon: ':x:'
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
  bundledCode: "#line 2 \"src/NumberTheory/CumSumQuotient.hpp\"\n#include <cstdint>\n\
    #include <valarray>\ntemplate <class T> struct CumSumQuotient {\n uint64_t N;\n\
    \ size_t K;\n std::valarray<T> X;\n CumSumQuotient(uint64_t N): N(N), K(std::sqrt(N)),\
    \ X(K + K + 1) {}\n T &operator[](uint64_t i) { return i > K ? X[K + double(N)\
    \ / i] : X[i]; }\n T operator()(uint64_t i) const { return i > K ? X[K + double(N)\
    \ / i] : X[i]; }\n CumSumQuotient &operator+=(const CumSumQuotient &r) { return\
    \ X+= r.X, *this; }\n CumSumQuotient &operator-=(const CumSumQuotient &r) { return\
    \ X-= r.X, *this; }\n CumSumQuotient &operator*=(T a) { return X*= a, *this; }\n\
    \ CumSumQuotient operator-() const {\n  CumSumQuotient ret= *this;\n  return ret.X=\
    \ -ret.X, ret;\n }\n CumSumQuotient operator+(const CumSumQuotient &r) const {\
    \ return CumSumQuotient(*this)+= r; }\n CumSumQuotient operator-(const CumSumQuotient\
    \ &r) const { return CumSumQuotient(*this)-= r; }\n CumSumQuotient operator*(T\
    \ a) const { return CumSumQuotient(*this)*= a; }\n friend CumSumQuotient operator*(T\
    \ a, const CumSumQuotient &x) { return x * a; }\n void add(uint64_t i, T v) {\n\
    \  for (size_t j= std::min<uint64_t>(N / i, K) + K; j >= i; --j) X[j]+= v;\n }\n\
    \ T sum() const { return X[K + 1]; }\n T sum(uint64_t i) const { return i > K\
    \ ? X[K + double(N) / i] : X[i]; }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <valarray>\ntemplate <class T>\
    \ struct CumSumQuotient {\n uint64_t N;\n size_t K;\n std::valarray<T> X;\n CumSumQuotient(uint64_t\
    \ N): N(N), K(std::sqrt(N)), X(K + K + 1) {}\n T &operator[](uint64_t i) { return\
    \ i > K ? X[K + double(N) / i] : X[i]; }\n T operator()(uint64_t i) const { return\
    \ i > K ? X[K + double(N) / i] : X[i]; }\n CumSumQuotient &operator+=(const CumSumQuotient\
    \ &r) { return X+= r.X, *this; }\n CumSumQuotient &operator-=(const CumSumQuotient\
    \ &r) { return X-= r.X, *this; }\n CumSumQuotient &operator*=(T a) { return X*=\
    \ a, *this; }\n CumSumQuotient operator-() const {\n  CumSumQuotient ret= *this;\n\
    \  return ret.X= -ret.X, ret;\n }\n CumSumQuotient operator+(const CumSumQuotient\
    \ &r) const { return CumSumQuotient(*this)+= r; }\n CumSumQuotient operator-(const\
    \ CumSumQuotient &r) const { return CumSumQuotient(*this)-= r; }\n CumSumQuotient\
    \ operator*(T a) const { return CumSumQuotient(*this)*= a; }\n friend CumSumQuotient\
    \ operator*(T a, const CumSumQuotient &x) { return x * a; }\n void add(uint64_t\
    \ i, T v) {\n  for (size_t j= std::min<uint64_t>(N / i, K) + K; j >= i; --j) X[j]+=\
    \ v;\n }\n T sum() const { return X[K + 1]; }\n T sum(uint64_t i) const { return\
    \ i > K ? X[K + double(N) / i] : X[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/CumSumQuotient.hpp
  requiredBy:
  - src/NumberTheory/sum_on_primes.hpp
  timestamp: '2024-02-07 23:03:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc172_d.mul_sum.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
  - test/yosupo/counting_primes.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
documentation_of: src/NumberTheory/CumSumQuotient.hpp
layout: document
title: "\u7D04\u6570\u914D\u5217"
---

$\newcommand{\floor}[1]{\left\lfloor{#1}\right\rfloor}$


## `CumSumQuotient<T>` クラス

添字が

$
\displaystyle
S =\left\lbrace \left. \floor{\frac{N}{x}} \right \vert x\in \mathbb{Z}, 1\leq x\leq N\right\rbrace
$

の要素のみの配列.

特に数論的関数 $f(\cdot)$ の $n\in S$ までの累積和

$
\displaystyle
F(n) = \sum_{i=1}^nf(i)
$

の値を格納するのに用いる.

ベクトル的な演算 (加減算，スカラー倍) に対応.


|メンバ変数|概要|
|---|---|
|`N`|$N$|
|`K`|$K=\floor{\sqrt{N}}$|
|`X`|実体. `valarray`. 直接触ることはない|

||概要 |計算量|
|---|---|---|
|`operator-(F)`|$-F(n)$|$O(\sqrt{N})$|
|`operator+(F,G)`|$F(n)+G(n)$|$O(\sqrt{N})$|
|`operator-(F,G)`|$F(n)-G(n)$|$O(\sqrt{N})$|
|`operator*(F,a)`|$F(n)\cdot a$|$O(\sqrt{N})$|
|`operator*(a,F)`|$a\cdot F(n)$ (上と同じ)|$O(\sqrt{N})$|


|メンバ関数|概要|
|---|---|
|`CumSumQuotient(N)`|コンストラクタ. $N$ を渡して構築. 要素はデフォルト値. |
|`operator[](n)`| $F(n)$ の値を左参照で返す. <br> $n\in \left\lbrace \left. \floor{\frac{N}{x}} \right \vert x\in \mathbb{Z}, 1\leq x\leq N\right\rbrace$ を想定.|
|`operator()(n)`| $F(n)$ の値を返す. <br> $n\in \left\lbrace \left. \floor{\frac{N}{x}} \right \vert x\in \mathbb{Z}, 1\leq x\leq N\right\rbrace$ を想定.|
|`sum(n)`|$\displaystyle F(n)= \sum_{i=1}^n f(i)$ を返す.|
|`sum()`|$\displaystyle F(N)= \sum_{i=1}^N f(i)$ を返す.　`sum(N)` と同じ．|
|`add(i, v)`| $f(i)\leftarrow f(i)+v$|


