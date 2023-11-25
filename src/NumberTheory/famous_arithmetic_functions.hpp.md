---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.numth.test.cpp
    title: test/atcoder/abc172_d.numth.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
    title: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1019.numth.test.cpp
    title: test/yukicoder/1019.numth.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/famous_arithmetic_functions.hpp\"\n#include\
    \ <vector>\n#include <cstdint>\nnamespace famous_arithmetic_functions {\nnamespace\
    \ mul {\ntemplate <class T> struct Totient {\n static constexpr T f(uint64_t p,\
    \ short e) {\n  T ret= p - 1;\n  while (--e) ret*= p;\n  return ret;\n }\n static\
    \ std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class T> struct Moebius\
    \ {\n static constexpr T f(uint64_t, short e) { return (e == 0) - (e == 1); }\n\
    \ static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class T> struct\
    \ Liouville {\n static constexpr T f(uint64_t, short e) { return e & 1 ? -1 :\
    \ 1; }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class T,\
    \ uint64_t k> struct Divisor {\n static constexpr T f(uint64_t p, short e) {\n\
    \  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t kk= k; kk; kk>>= 1, b*= b)\n\
    \   if (kk & 1) pk*= b;\n  for (short i= 0; i <= e; i++, pkpw*= pk) ret+= pkpw;\n\
    \  return ret;\n }\n static std::vector<T> poly() {\n  std::vector<T> ret(k +\
    \ 1, 0);\n  return ret[0]+= 1, ret[k]+= 1, ret;\n }\n};\ntemplate <class T> struct\
    \ Dedekind {\n static constexpr T f(uint64_t p, short e) {\n  T ret= p + 1;\n\
    \  while (e-- > 1) ret*= p;\n  return ret;\n }\n static std::vector<T> poly()\
    \ { return {1, 1}; }\n};\n}  // namespace mul\nnamespace add {\ntemplate <class\
    \ T> struct BigOmega {  // the total number of prime factors of n\n static constexpr\
    \ T f(uint64_t, short e) { return e; }\n static std::vector<T> poly() { return\
    \ {1}; }\n};\ntemplate <class T> struct LittleOmega {  // the total number of\
    \ different prime factors of n\n static constexpr T f(uint64_t, short) { return\
    \ 1; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T>\
    \ struct Sopfr {  // the sum of primes dividing n counting multiplicity\n static\
    \ constexpr T f(uint64_t p, short e) { return p * e; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\ntemplate <class T> struct Sopf {  // the sum\
    \ of the distinct primes dividing n\n static constexpr T f(uint64_t p, short)\
    \ { return p; }\n static std::vector<T> poly() { return {0, 1}; }\n};\n}  // namespace\
    \ add\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\nnamespace famous_arithmetic_functions\
    \ {\nnamespace mul {\ntemplate <class T> struct Totient {\n static constexpr T\
    \ f(uint64_t p, short e) {\n  T ret= p - 1;\n  while (--e) ret*= p;\n  return\
    \ ret;\n }\n static std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class\
    \ T> struct Moebius {\n static constexpr T f(uint64_t, short e) { return (e ==\
    \ 0) - (e == 1); }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T> struct Liouville {\n static constexpr T f(uint64_t, short e) { return\
    \ e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T, uint64_t k> struct Divisor {\n static constexpr T f(uint64_t p, short\
    \ e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t kk= k; kk; kk>>= 1,\
    \ b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <= e; i++, pkpw*= pk) ret+=\
    \ pkpw;\n  return ret;\n }\n static std::vector<T> poly() {\n  std::vector<T>\
    \ ret(k + 1, 0);\n  return ret[0]+= 1, ret[k]+= 1, ret;\n }\n};\ntemplate <class\
    \ T> struct Dedekind {\n static constexpr T f(uint64_t p, short e) {\n  T ret=\
    \ p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n }\n static std::vector<T>\
    \ poly() { return {1, 1}; }\n};\n}  // namespace mul\nnamespace add {\ntemplate\
    \ <class T> struct BigOmega {  // the total number of prime factors of n\n static\
    \ constexpr T f(uint64_t, short e) { return e; }\n static std::vector<T> poly()\
    \ { return {1}; }\n};\ntemplate <class T> struct LittleOmega {  // the total number\
    \ of different prime factors of n\n static constexpr T f(uint64_t, short) { return\
    \ 1; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T>\
    \ struct Sopfr {  // the sum of primes dividing n counting multiplicity\n static\
    \ constexpr T f(uint64_t p, short e) { return p * e; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\ntemplate <class T> struct Sopf {  // the sum\
    \ of the distinct primes dividing n\n static constexpr T f(uint64_t p, short)\
    \ { return p; }\n static std::vector<T> poly() { return {0, 1}; }\n};\n}  // namespace\
    \ add\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/famous_arithmetic_functions.hpp
  requiredBy: []
  timestamp: '2023-11-25 22:39:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/yukicoder/1019.numth.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
documentation_of: src/NumberTheory/famous_arithmetic_functions.hpp
layout: document
title: "\u6709\u540D\u306A\u6570\u8AD6\u7684\u95A2\u6570"
---
有名な数論的関数についての補助的なツール.

名前空間 `famous_arithmetic_functions` に置いている.
```c++
using namespace famous_arithmetic_functions;
```
その中にさらに名前空間 `add`・`mul` を配置しており, それぞれ加法的関数・乗法的関数を置いている.

数論的関数 $f(n)$ について, この補助的クラスは `static` な関数 `f(p,e)` と `poly()` をもっている.

|||
|---|---|
|`f(p,e)`| $f(p^e)$ を表す関数. |
|`poly()`| $f(p)$ の $p$ の多項式としての係数. 返り値は `vector`.|

## 名前空間 `add` 内

|名前|概要|$f(p^e)$|OEIS|
|---|---|---|---|
|`BigOmega<T>`| $n$ の重複を含めた素因数の個数を表す関数 $\Omega(n)$ |　$e$ |[A001222](https://oeis.org/A001222)|
|`LittleOmega<T>`| $n$ の相異なる素因数の個数を表す関数 $\omega(n)$ |　$1$ |[A001221](https://oeis.org/A001221)|
|`Sopfr<T>`| $n$ の重複を含めた素因数の和を表す関数 $\mathrm{sopfr}(n)$ |　$p\cdot e$ |[A001414](https://oeis.org/A001414)|
|`Sopf<T>`| $n$ の相異なる素因数の和を表す関数 $\mathrm{sopf}(n)$ |　$p$ |[A008472](https://oeis.org/A008472)|

## 名前空間 `mul` 内

|名前|概要|$f(p^e)$|
|---|---|---|
|`Totient<T>`| [オイラーのトーシェント関数](https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%CF%86%E9%96%A2%E6%95%B0) $\varphi(n)$| $p^e(1-p^{-1})$ |
|`Moebius<T>`| [メビウス関数](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0) $\mu(n)$|$\displaystyle \begin{cases}-1&e=1\newline 0& e\gt 1\end{cases}$|
|`Liouville<T>`| [Liouville 関数](https://en.wikipedia.org/wiki/Liouville_function) $\lambda(n)$ |$(-1)^e$|
|`Divisor<T,k>`|[約数関数](https://ja.wikipedia.org/wiki/%E7%B4%84%E6%95%B0%E9%96%A2%E6%95%B0) $\sigma_k(n)$ |$\displaystyle \sum_{i=0}^ep^{ki}$|
|`Dedekind<T>`| [Dedekind psi function](https://en.wikipedia.org/wiki/Dedekind_psi_function) $\psi(n)$|$p^e(1+p^{-1})$|

## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) ( $\lambda(n)$ ) \
[Xmas Contest 2019 E - Sum of f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e) ( $\Omega(n)$ ) 
## 参考
[https://en.wikipedia.org/wiki/Arithmetic_function](https://en.wikipedia.org/wiki/Arithmetic_function)\
[https://en.wikipedia.org/wiki/Additive_function](https://en.wikipedia.org/wiki/Additive_function)\
[https://en.wikipedia.org/wiki/Multiplicative_function](https://en.wikipedia.org/wiki/Multiplicative_function)