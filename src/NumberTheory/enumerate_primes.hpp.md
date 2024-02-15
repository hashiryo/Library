---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/NumberTheory/sum_on_primes.hpp
    title: "\u7D20\u6570\u4E0A\u306E\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: src/NumberTheory/tables.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30C6\u30FC\u30D6\u30EB\u3084 gcd \u7573\
      \u307F\u8FBC\u307F\u306A\u3069"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc162_e.test.cpp
    title: test/atcoder/abc162_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.mul_sum.test.cpp
    title: test/atcoder/abc172_d.mul_sum.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc172_d.numth.test.cpp
    title: test/atcoder/abc172_d.numth.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc177_e.gcd_conv.test.cpp
    title: test/atcoder/abc177_e.gcd_conv.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':x:'
    path: test/atcoder/agc038_c.numth.test.cpp
    title: test/atcoder/agc038_c.numth.test.cpp
  - icon: ':x:'
    path: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
    title: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - icon: ':x:'
    path: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
    title: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
  - icon: ':x:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  - icon: ':x:'
    path: test/yosupo/enumerate_primes.test.cpp
    title: test/yosupo/enumerate_primes.test.cpp
  - icon: ':x:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1006.test.cpp
    title: test/yukicoder/1006.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1019.numth.test.cpp
    title: test/yukicoder/1019.numth.test.cpp
  - icon: ':x:'
    path: test/yukicoder/644.test.cpp
    title: test/yukicoder/644.test.cpp
  - icon: ':x:'
    path: test/yukicoder/886.numth.test.cpp
    title: test/yukicoder/886.numth.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/enumerate_primes.hpp\"\n#include <algorithm>\n\
    #include <cstdint>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
    #include <iostream>\n#include <iterator>\n#include <type_traits>\n#define _LR(name,\
    \ IT, CT) \\\n template <class T> struct name { \\\n  using Iterator= typename\
    \ std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return\
    \ bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size() const {\
    \ return std::distance(bg, ed); } \\\n  CT &operator[](int i) const { return bg[i];\
    \ } \\\n }\n_LR(ListRange, iterator, const T);\n_LR(ConstListRange, const_iterator,\
    \ const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n std::vector<T>\
    \ dat;\n std::vector<int> p;\n size_t size() const { return p.size() - 1; }\n\
    \ ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin() + p[i\
    \ + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 5 \"src/NumberTheory/enumerate_primes.hpp\"\nnamespace nt_internal\
    \ {\nusing namespace std;\nvector<int> ps, lf;\nvoid sieve(int N) {\n static int\
    \ n= 2;\n if (n > N) return;\n if (lf.resize((N + 1) >> 1); n == 2) ps.push_back(n++);\n\
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
    \ f);\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstdint>\n#include \"src/Internal/ListRange.hpp\"\
    \nnamespace nt_internal {\nusing namespace std;\nvector<int> ps, lf;\nvoid sieve(int\
    \ N) {\n static int n= 2;\n if (n > N) return;\n if (lf.resize((N + 1) >> 1);\
    \ n == 2) ps.push_back(n++);\n int M= (N - 1) / 2;\n for (int j= 1, e= ps.size();\
    \ j < e; ++j) {\n  int p= ps[j];\n  if (int64_t(p) * p > N) break;\n  for (auto\
    \ k= int64_t(p) * max(n / p / 2 * 2 + 1, p) / 2; k <= M; k+= p) lf[k]+= p * !lf[k];\n\
    \ }\n for (; n <= N; n+= 2)\n  if (!lf[n >> 1]) {\n   ps.push_back(lf[n >> 1]=\
    \ n);\n   for (auto j= int64_t(n) * n / 2; j <= M; j+= n) lf[j]+= n * !lf[j];\n\
    \  }\n}\nConstListRange<int> enumerate_primes() { return {ps.cbegin(), ps.cend()};\
    \ }\nConstListRange<int> enumerate_primes(int N) {\n sieve(N);\n return {ps.cbegin(),\
    \ upper_bound(ps.cbegin(), ps.cend(), N)};\n}\nint least_prime_factor(int n) {\
    \ return n & 1 ? sieve(n), lf[(n >> 1)] : 2; }\n// f(p,e) := f(p^e)\ntemplate\
    \ <class T, class F> vector<T> completely_multiplicative_table(int N, const F\
    \ &f) {\n vector<T> ret(N + 1);\n sieve(N);\n for (int n= 3, i= 1; n <= N; n+=\
    \ 2, ++i) ret[n]= lf[i] == n ? f(n, 1) : ret[lf[i]] * ret[n / lf[i]];\n if (int\
    \ n= 4; 2 <= N)\n  for (T t= ret[2]= f(2, 1); n <= N; n+= 2) ret[n]= t * ret[n\
    \ >> 1];\n return ret[1]= 1, ret;\n}\n}\nusing nt_internal::enumerate_primes,\
    \ nt_internal::least_prime_factor, nt_internal::completely_multiplicative_table;\n\
    // O(N log k / log N + N)\ntemplate <class T> static std::vector<T> pow_table(int\
    \ N, uint64_t k) {\n if (k == 0) return std::vector<T>(N + 1, 1);\n auto f= [k](int\
    \ p, int) {\n  T ret= 1, b= p;\n  for (auto e= k;; b*= b) {\n   if (e & 1) ret*=\
    \ b;\n   if (!(e>>= 1)) return ret;\n  }\n };\n return completely_multiplicative_table<T>(N,\
    \ f);\n}"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/NumberTheory/enumerate_primes.hpp
  requiredBy:
  - src/NumberTheory/tables.hpp
  - src/NumberTheory/sum_on_primes.hpp
  timestamp: '2024-02-15 14:27:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1019.numth.test.cpp
  - test/yukicoder/886.numth.test.cpp
  - test/yukicoder/644.test.cpp
  - test/yukicoder/1006.test.cpp
  - test/yosupo/enumerate_primes.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/yosupo/counting_primes.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
  - test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
  - test/atcoder/agc038_c.numth.test.cpp
  - test/atcoder/abc177_e.gcd_conv.test.cpp
  - test/atcoder/abc172_d.mul_sum.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
  - test/atcoder/abc162_e.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
documentation_of: src/NumberTheory/enumerate_primes.hpp
layout: document
title: "\u7D20\u6570\u306E\u5217\u6319"
---
エラトステネス篩による素数列挙の前処理を自動でおこなう．

## 関数

|名前|概要|計算量|
|---|---|---|
| `enumerate_primes(N)`| $N$ 以下のすべての素数を返す. <br> 返り値は [`ListRange<int>`](src/Internal/ListRange.hpp)||
|`least_primes_factor(n)`| $n$ の最小素因数を返す. ||
|`completely_multiplicative_table<T>(N, f)`| 完全乗法的関数 $f$ の値が入ったテーブルを返す. <br> $f$ は素冪のもの `f(p,e)`$=f(p^e)$ を渡す(完全だけど).<br> サイズは $N+1$. |$\displaystyleO\left(N + \frac{N\alpha}{\log N}\right)$ <br> ただし $f(p)$ の計算量を $O(\alpha)$ とおいた.|
|`pow_table<T>(N,k)`| $n^k$ の値が入ったテーブルを返す. <br> サイズは $N+1$. |$\displaystyleO\left(N + \frac{N\log k}{\log N}\right)$|

## 参考
[https://37zigen.com/linear-sieve/](https://37zigen.com/linear-sieve/) 
