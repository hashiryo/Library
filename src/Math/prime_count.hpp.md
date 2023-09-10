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
  bundledCode: "#line 2 \"src/Math/prime_count.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <tuple>\n#include <cmath>\ntemplate <class T> class QuotientSum\
    \ {\n uint64_t N;\n size_t K;\npublic:\n std::vector<T> s, l;\n QuotientSum()\
    \ {}\n QuotientSum(uint64_t N, size_t K, const std::vector<T> &s, const std::vector<T>\
    \ &l): N(N), K(K), s(s), l(l) {}\n inline T sum() const { return l[1]; }\n inline\
    \ T sum(uint64_t n) const { return n <= K ? s[n] : l[N / n]; }\n};\ntemplate <class\
    \ T= __int128_t> auto polynomial_prime_sum_table(uint64_t N, const std::vector<T>\
    \ &poly) {\n const int sqrtN= std::sqrt(N), d= poly.size();\n std::vector<int>\
    \ primes;\n std::vector<std::vector<T>> s(d, std::vector<T>(sqrtN + 1)), l(d,\
    \ std::vector<T>(sqrtN + 1));\n for (int n= 1, k= 0; n <= sqrtN; ++n, k= 0)\n\
    \  for (T prd= n; k < d; prd*= (n + ++k)) s[k][n]= prd / (k + 1);\n for (int n=\
    \ 1, k= 0; n <= sqrtN; ++n, k= 0)\n  for (T prd= N / n; k < d; prd*= ((N / n)\
    \ + ++k)) l[k][n]= prd / (k + 1);\n if (d > 2) {\n  std::vector<T> stir(d, 0);\n\
    \  stir[1]= 1;\n  for (int k= 2; k < d; stir[k++]= 1) {\n   for (int j= k - 1;\
    \ j; --j) stir[j]= stir[j - 1] + stir[j] * (k - 1);\n   for (int n= 1; n <= sqrtN;\
    \ ++n)\n    for (int j= 1; j < k; ++j) s[k][n]-= stir[j] * s[j][n], l[k][n]-=\
    \ stir[j] * l[j][n];\n  }\n }\n for (int k= 0; k < d; ++k)\n  for (int n= 1; n\
    \ <= sqrtN; ++n) s[k][n]-= 1, l[k][n]-= 1;\n for (int p= 2, k= 0; p <= sqrtN;\
    \ ++p, k= 0)\n  if (s[0][p] != s[0][p - 1]) {\n   primes.emplace_back(p);\n  \
    \ uint64_t q= uint64_t(p) * p, M= N / p;\n   int t= sqrtN / p, u= std::min<uint64_t>(sqrtN,\
    \ N / q);\n   for (T pw= 1; k < d; ++k, pw*= p)\n    if (!k || poly[k] != T(0))\
    \ {\n     T tk= s[k][p - 1];\n     for (int i= 1; i <= t; ++i) l[k][i]-= (l[k][i\
    \ * p] - tk) * pw;\n     for (int i= t + 1; i <= u; ++i) l[k][i]-= (s[k][double(M)\
    \ / i] - tk) * pw;\n     for (uint64_t i= sqrtN; i >= q; --i) s[k][i]-= (s[k][double(i)\
    \ / p] - tk) * pw;\n    }\n  }\n std::vector<T> Xs(sqrtN + 1, 0), Xl(sqrtN + 1,\
    \ 0);\n for (int n= 1; n <= sqrtN; ++n)\n  for (int k= 0; k < d; ++k) Xs[n]+=\
    \ s[k][n] * poly[k], Xl[n]+= l[k][n] * poly[k];\n return std::make_pair(primes,\
    \ QuotientSum(N, sqrtN, Xs, Xl));\n}\nauto prime_count_table(uint64_t N) { return\
    \ polynomial_prime_sum_table<uint64_t>(N, {1}); }\ntemplate <class T, class F>\
    \ T additive_sum(uint64_t N, const F &f, std::vector<T> poly) {\n const uint64_t\
    \ sqrtN= std::sqrt(N);\n auto [primes, X]= polynomial_prime_sum_table<T>(N, poly);\n\
    \ T ret= X.sum();\n for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= double(N)\
    \ / d) * ((nd= N / nN + 1) - d);\n for (uint64_t p: primes)\n  for (uint64_t pw=\
    \ p * p, e= 2; pw <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * uint64_t(double(N)\
    \ / pw);\n return ret;\n}\ntemplate <class T= __int128_t, class F> T multiplicative_sum(uint64_t\
    \ N, const F &f, const std::vector<T> &poly) {\n const uint64_t sqrtN= std::sqrt(N);\n\
    \ std::vector<int> primes;\n QuotientSum<T> X;\n tie(primes, X)= polynomial_prime_sum_table<T>(N,\
    \ poly);\n size_t psz= primes.size();\n for (auto it= primes.rbegin(); it != primes.rend();\
    \ ++it) {\n  uint64_t p= *it, M= N / p, q= p * p;\n  int t= sqrtN / p, u= std::min(sqrtN,\
    \ N / q);\n  T tk= X.s[p - 1];\n  for (auto i= q; i <= sqrtN; ++i) X.s[i]+= (X.s[double(i)\
    \ / p] - tk) * f(p, 1);\n  for (int i= u; i > t; --i) X.l[i]+= (X.s[double(M)\
    \ / i] - tk) * f(p, 1);\n  for (int i= t; i; --i) X.l[i]+= (X.l[i * p] - tk) *\
    \ f(p, 1);\n }\n for (auto n= sqrtN; n; --n) X.s[n]+= 1;\n for (auto n= sqrtN;\
    \ n; --n) X.l[n]+= 1;\n auto dfs= [&](auto rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n  if (cf == T(0)) return T(0);\n  T ret= cf * X.sum(n);\n  for (auto i=\
    \ bg; i < psz; ++i) {\n   uint64_t p= primes[i], q= p * p, nn= double(n) / q;\n\
    \   if (!nn) break;\n   for (int e= 2; nn; nn= double(nn) / p, ++e) ret+= rc(rc,\
    \ nn, i + 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n  }\n  return ret;\n };\n\
    \ return dfs(dfs, N, 0, 1);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <tuple>\n\
    #include <cmath>\ntemplate <class T> class QuotientSum {\n uint64_t N;\n size_t\
    \ K;\npublic:\n std::vector<T> s, l;\n QuotientSum() {}\n QuotientSum(uint64_t\
    \ N, size_t K, const std::vector<T> &s, const std::vector<T> &l): N(N), K(K),\
    \ s(s), l(l) {}\n inline T sum() const { return l[1]; }\n inline T sum(uint64_t\
    \ n) const { return n <= K ? s[n] : l[N / n]; }\n};\ntemplate <class T= __int128_t>\
    \ auto polynomial_prime_sum_table(uint64_t N, const std::vector<T> &poly) {\n\
    \ const int sqrtN= std::sqrt(N), d= poly.size();\n std::vector<int> primes;\n\
    \ std::vector<std::vector<T>> s(d, std::vector<T>(sqrtN + 1)), l(d, std::vector<T>(sqrtN\
    \ + 1));\n for (int n= 1, k= 0; n <= sqrtN; ++n, k= 0)\n  for (T prd= n; k < d;\
    \ prd*= (n + ++k)) s[k][n]= prd / (k + 1);\n for (int n= 1, k= 0; n <= sqrtN;\
    \ ++n, k= 0)\n  for (T prd= N / n; k < d; prd*= ((N / n) + ++k)) l[k][n]= prd\
    \ / (k + 1);\n if (d > 2) {\n  std::vector<T> stir(d, 0);\n  stir[1]= 1;\n  for\
    \ (int k= 2; k < d; stir[k++]= 1) {\n   for (int j= k - 1; j; --j) stir[j]= stir[j\
    \ - 1] + stir[j] * (k - 1);\n   for (int n= 1; n <= sqrtN; ++n)\n    for (int\
    \ j= 1; j < k; ++j) s[k][n]-= stir[j] * s[j][n], l[k][n]-= stir[j] * l[j][n];\n\
    \  }\n }\n for (int k= 0; k < d; ++k)\n  for (int n= 1; n <= sqrtN; ++n) s[k][n]-=\
    \ 1, l[k][n]-= 1;\n for (int p= 2, k= 0; p <= sqrtN; ++p, k= 0)\n  if (s[0][p]\
    \ != s[0][p - 1]) {\n   primes.emplace_back(p);\n   uint64_t q= uint64_t(p) *\
    \ p, M= N / p;\n   int t= sqrtN / p, u= std::min<uint64_t>(sqrtN, N / q);\n  \
    \ for (T pw= 1; k < d; ++k, pw*= p)\n    if (!k || poly[k] != T(0)) {\n     T\
    \ tk= s[k][p - 1];\n     for (int i= 1; i <= t; ++i) l[k][i]-= (l[k][i * p] -\
    \ tk) * pw;\n     for (int i= t + 1; i <= u; ++i) l[k][i]-= (s[k][double(M) /\
    \ i] - tk) * pw;\n     for (uint64_t i= sqrtN; i >= q; --i) s[k][i]-= (s[k][double(i)\
    \ / p] - tk) * pw;\n    }\n  }\n std::vector<T> Xs(sqrtN + 1, 0), Xl(sqrtN + 1,\
    \ 0);\n for (int n= 1; n <= sqrtN; ++n)\n  for (int k= 0; k < d; ++k) Xs[n]+=\
    \ s[k][n] * poly[k], Xl[n]+= l[k][n] * poly[k];\n return std::make_pair(primes,\
    \ QuotientSum(N, sqrtN, Xs, Xl));\n}\nauto prime_count_table(uint64_t N) { return\
    \ polynomial_prime_sum_table<uint64_t>(N, {1}); }\ntemplate <class T, class F>\
    \ T additive_sum(uint64_t N, const F &f, std::vector<T> poly) {\n const uint64_t\
    \ sqrtN= std::sqrt(N);\n auto [primes, X]= polynomial_prime_sum_table<T>(N, poly);\n\
    \ T ret= X.sum();\n for (uint64_t d= 2, nN, nd; nN; d= nd) ret+= X.sum(nN= double(N)\
    \ / d) * ((nd= N / nN + 1) - d);\n for (uint64_t p: primes)\n  for (uint64_t pw=\
    \ p * p, e= 2; pw <= N; ++e, pw*= p) ret+= (f(p, e) - f(p, e - 1)) * uint64_t(double(N)\
    \ / pw);\n return ret;\n}\ntemplate <class T= __int128_t, class F> T multiplicative_sum(uint64_t\
    \ N, const F &f, const std::vector<T> &poly) {\n const uint64_t sqrtN= std::sqrt(N);\n\
    \ std::vector<int> primes;\n QuotientSum<T> X;\n tie(primes, X)= polynomial_prime_sum_table<T>(N,\
    \ poly);\n size_t psz= primes.size();\n for (auto it= primes.rbegin(); it != primes.rend();\
    \ ++it) {\n  uint64_t p= *it, M= N / p, q= p * p;\n  int t= sqrtN / p, u= std::min(sqrtN,\
    \ N / q);\n  T tk= X.s[p - 1];\n  for (auto i= q; i <= sqrtN; ++i) X.s[i]+= (X.s[double(i)\
    \ / p] - tk) * f(p, 1);\n  for (int i= u; i > t; --i) X.l[i]+= (X.s[double(M)\
    \ / i] - tk) * f(p, 1);\n  for (int i= t; i; --i) X.l[i]+= (X.l[i * p] - tk) *\
    \ f(p, 1);\n }\n for (auto n= sqrtN; n; --n) X.s[n]+= 1;\n for (auto n= sqrtN;\
    \ n; --n) X.l[n]+= 1;\n auto dfs= [&](auto rc, uint64_t n, size_t bg, T cf) ->\
    \ T {\n  if (cf == T(0)) return T(0);\n  T ret= cf * X.sum(n);\n  for (auto i=\
    \ bg; i < psz; ++i) {\n   uint64_t p= primes[i], q= p * p, nn= double(n) / q;\n\
    \   if (!nn) break;\n   for (int e= 2; nn; nn= double(nn) / p, ++e) ret+= rc(rc,\
    \ nn, i + 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n  }\n  return ret;\n };\n\
    \ return dfs(dfs, N, 0, 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/prime_count.hpp
  requiredBy: []
  timestamp: '2023-05-14 19:41:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/yosupo/counting_primes.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
  - test/atcoder/abc172_d.mul_sum.test.cpp
documentation_of: src/Math/prime_count.hpp
layout: document
title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8 \u4ED6"
---
乗法的関数や加法的関数の累積和も添えて

## 計算量
$\mathcal{O} (d^2\sqrt{N}+dN^{3/4}/\log N)$ \
$d$ := degre of polynomial
## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) \
[Xmas Contest 2019 E - Sum of f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e) (加法的関数) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) (2次多項式) \
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) 
