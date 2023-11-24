---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/multiplicative_and_additive.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/Math/prime_count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc179/tasks/abc179_c
    links:
    - https://atcoder.jp/contests/abc179/tasks/abc179_c
  bundledCode: "#line 1 \"test/atcoder/abc179_c.mul_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n// O(N^(2/3)log^(1/3)N))\n\
    #include <iostream>\n#line 2 \"src/Math/prime_count.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <tuple>\n#include <cmath>\n#include <cstdint>\n\
    template <class T> class QuotientSum {\n uint64_t N;\n size_t K;\npublic:\n std::vector<T>\
    \ s, l;\n QuotientSum() {}\n QuotientSum(uint64_t N, size_t K, const std::vector<T>\
    \ &s, const std::vector<T> &l): N(N), K(K), s(s), l(l) {}\n inline T sum() const\
    \ { return l[1]; }\n inline T sum(uint64_t n) const { return n <= K ? s[n] : l[N\
    \ / n]; }\n};\ntemplate <class T= __int128_t> auto polynomial_prime_sum_table(uint64_t\
    \ N, const std::vector<T> &poly) {\n const int sqrtN= std::sqrt(N), d= poly.size();\n\
    \ std::vector<int> primes;\n std::vector<std::vector<T>> s(d, std::vector<T>(sqrtN\
    \ + 1)), l(d, std::vector<T>(sqrtN + 1));\n for (int n= 1, k= 0; n <= sqrtN; ++n,\
    \ k= 0)\n  for (T prd= n; k < d; prd*= (n + ++k)) s[k][n]= prd / (k + 1);\n for\
    \ (int n= 1, k= 0; n <= sqrtN; ++n, k= 0)\n  for (T prd= N / n; k < d; prd*= ((N\
    \ / n) + ++k)) l[k][n]= prd / (k + 1);\n if (d > 2) {\n  std::vector<T> stir(d,\
    \ 0);\n  stir[1]= 1;\n  for (int k= 2; k < d; stir[k++]= 1) {\n   for (int j=\
    \ k - 1; j; --j) stir[j]= stir[j - 1] + stir[j] * (k - 1);\n   for (int n= 1;\
    \ n <= sqrtN; ++n)\n    for (int j= 1; j < k; ++j) s[k][n]-= stir[j] * s[j][n],\
    \ l[k][n]-= stir[j] * l[j][n];\n  }\n }\n for (int k= 0; k < d; ++k)\n  for (int\
    \ n= 1; n <= sqrtN; ++n) s[k][n]-= 1, l[k][n]-= 1;\n for (int p= 2, k= 0; p <=\
    \ sqrtN; ++p, k= 0)\n  if (s[0][p] != s[0][p - 1]) {\n   primes.emplace_back(p);\n\
    \   uint64_t q= uint64_t(p) * p, M= N / p;\n   int t= sqrtN / p, u= std::min<uint64_t>(sqrtN,\
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
    \ return dfs(dfs, N, 0, 1);\n}\n#line 4 \"src/Math/multiplicative_and_additive.hpp\"\
    \nnamespace multiplicative_functions {\ntemplate <class T> struct Totient {\n\
    \ static constexpr T f(uint64_t p, short e) {\n  T ret= p - 1;\n  while (e-- >\
    \ 1) ret*= p;\n  return ret;\n }\n static std::vector<T> poly() { return {-1,\
    \ 1}; }\n};\ntemplate <class T> struct Moebius {\n static constexpr T f(uint64_t,\
    \ short e) { return (e == 0) - (e == 1); }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T> struct Liouville {\n static constexpr T f(uint64_t,\
    \ short e) { return e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return\
    \ {-1}; }\n};\ntemplate <class T, uint64_t k> struct Divisor {\n static constexpr\
    \ T f(uint64_t p, short e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t\
    \ kk= k; kk; kk>>= 1, b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <=\
    \ e; i++, pkpw*= pk) ret+= pkpw;\n  return ret;\n }\n static std::vector<T> poly()\
    \ {\n  std::vector<T> ret(k + 1, 0);\n  ret[0]+= 1, ret[k]+= 1;\n  return ret;\n\
    \ }\n};\ntemplate <class T> struct Dedekind {\n static constexpr T f(uint64_t\
    \ p, short e) {\n  T ret= p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n\
    \ }\n static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace multiplicative_functions\n\
    namespace additive_functions {\ntemplate <class T> struct BigOmega {  // the total\
    \ number of prime factors of n\n static constexpr T f(uint64_t, short e) { return\
    \ e; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T>\
    \ struct LittleOmega {  // the total number of different prime factors of n\n\
    \ static constexpr T f(uint64_t, short) { return 1; }\n static std::vector<T>\
    \ poly() { return {1}; }\n};\ntemplate <class T> struct Sopfr {  // the sum of\
    \ primes dividing n counting multiplicity\n static constexpr T f(uint64_t p, short\
    \ e) { return p * e; }\n static std::vector<T> poly() { return {0, 1}; }\n};\n\
    template <class T> struct Sopf {  // the sum of the distinct primes dividing n\n\
    \ static constexpr T f(uint64_t p, short) { return p; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\n}  // namespace additive_functions\n#line 6 \"\
    test/atcoder/abc179_c.mul_sum.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using namespace multiplicative_functions;\n\
    \ long long N;\n cin >> N;\n cout << multiplicative_sum<long long>(N - 1, Divisor<long\
    \ long, 0>::f, Divisor<long long, 0>::poly()) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n//\
    \ O(N^(2/3)log^(1/3)N))\n#include <iostream>\n#include \"src/Math/prime_count.hpp\"\
    \n#include \"src/Math/multiplicative_and_additive.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using namespace multiplicative_functions;\n\
    \ long long N;\n cin >> N;\n cout << multiplicative_sum<long long>(N - 1, Divisor<long\
    \ long, 0>::f, Divisor<long long, 0>::poly()) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/prime_count.hpp
  - src/Math/multiplicative_and_additive.hpp
  isVerificationFile: true
  path: test/atcoder/abc179_c.mul_sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-22 11:53:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc179_c.mul_sum.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc179_c.mul_sum.test.cpp
- /verify/test/atcoder/abc179_c.mul_sum.test.cpp.html
title: test/atcoder/abc179_c.mul_sum.test.cpp
---
