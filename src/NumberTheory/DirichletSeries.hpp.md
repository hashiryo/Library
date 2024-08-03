---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.Dirichlet.test.cpp
    title: test/atcoder/abc172_d.Dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_c.Dirichlet.test.cpp
    title: test/atcoder/abc179_c.Dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc239_ex.test.cpp
    title: test/atcoder/abc239_ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc116_c.Dirichlet.test.cpp
    title: test/atcoder/arc116_c.Dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
    title: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1276.Dirichlet.test.cpp
    title: test/yukicoder/1276.Dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1573.Dirichlet.test.cpp
    title: test/yukicoder/1573.Dirichlet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/DirichletSeries.hpp\"\n#include <valarray>\n\
    #include <iterator>\n#include <algorithm>\n#include <cmath>\n#include <cassert>\n\
    #include <numeric>\n#include <cstdint>\ntemplate <class T> struct DirichletSeries\
    \ {\n using Self= DirichletSeries;\n uint64_t N;  // <= K * L\n size_t K, L;\n\
    \ std::valarray<T> x, X;\n DirichletSeries(uint64_t N, bool unit= false): N(N),\
    \ K(N > 1 ? std::max(std::ceil(std::pow((double)N / std::log2(N), 2. / 3)), std::sqrt(N)\
    \ + 1) : 1), L((N - 1 + K) / K), x(K + 1), X(K + L + 1) {\n  if (assert(N > 0);\
    \ unit) x[1]= 1, X= 1;\n }\n template <class F, typename= std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F,\
    \ uint64_t>, T>>> DirichletSeries(uint64_t N, const F &sum): DirichletSeries(N)\
    \ {\n  for (size_t i= 1; i <= K; ++i) X[i]= sum(i);\n  for (size_t i= 1; i <=\
    \ L; ++i) X[K + i]= sum(uint64_t((double)N / i));\n  for (size_t i= K; i; --i)\
    \ x[i]= X[i] - X[i - 1];\n }\n Self operator-() const {\n  Self ret(N);\n  return\
    \ ret.x= -x, ret.X= -X, ret;\n }\n Self &operator+=(T r) { return x[1]+= r, X+=\
    \ r, *this; }\n Self &operator-=(T r) { return x[1]-= r, X-= r, *this; }\n Self\
    \ &operator*=(T r) { return x*= r, X*= r, *this; }\n Self &operator/=(T r) {\n\
    \  if (T iv= T(1) / r; iv == 0) x/= r, X/= r;\n  else x*= iv, X*= iv;\n  return\
    \ *this;\n }\n Self &operator+=(const Self &r) { return assert(N == r.N), assert(K\
    \ == r.K), assert(L == r.L), x+= r.x, X+= r.X, *this; }\n Self &operator-=(const\
    \ Self &r) { return assert(N == r.N), assert(K == r.K), assert(L == r.L), x-=\
    \ r.x, X-= r.X, *this; }\n Self operator+(T r) const { return Self(*this)+= r;\
    \ }\n Self operator-(T r) const { return Self(*this)-= r; }\n Self operator*(T\
    \ r) const { return Self(*this)*= r; }\n Self operator/(T r) const { return Self(*this)/=\
    \ r; }\n Self operator+(const Self &r) const { return Self(*this)+= r; }\n Self\
    \ operator-(const Self &r) const { return Self(*this)-= r; }\n friend Self operator+(T\
    \ l, Self r) { return r+= l; }\n friend Self operator-(T l, Self r) { return r.x[1]-=\
    \ l, r.X-= l, r.x= -r.x, r.X= -r.X, r; }\n friend Self operator*(T l, const Self\
    \ &r) { return r * l; }\n friend Self operator/(T l, const Self &r) { return (Self(r.N,\
    \ true)/= r)*= l; }\n Self operator*(const Self &r) const {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  Self ret(N);\n  uint64_t n;\n  for (size_t\
    \ i= K, j; i; --i)\n   for (j= K / i; j; --j) ret.x[i * j]+= x[i] * r.x[j];\n\
    \  for (size_t l= L, m, i; l; ret.X[K + l--]-= sum(m) * r.sum(m))\n   for (i=\
    \ m= std::sqrt(n= (double)N / l); i; --i) ret.X[K + l]+= x[i] * r.sum((double)n\
    \ / i) + r.x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self operator/(const Self &r)\
    \ const { return Self(*this)/= r; }\n Self &operator*=(const Self &r) { return\
    \ *this= *this * r; }\n Self &operator/=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  for (size_t i= 1, j, ed; i <= K; i++)\n\
    \   for (x[i]/= r.x[1], j= 2, ed= K / i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n\
    \  X[1]= x[1];\n  for (size_t i= 2; i <= K; ++i) X[i]= X[i - 1] + x[i];\n  uint64_t\
    \ n;\n  for (size_t l= L, m; l; X[K + l--]/= r.x[1])\n   for (m= std::sqrt(n=\
    \ (double)N / l), X[K + l]+= r.sum(m) * sum(m) - x[1] * r.sum(n); m > 1;) X[K\
    \ + l]-= r.x[m] * sum((double)n / m) + x[m] * r.sum((double)n / m), --m;\n  return\
    \ *this;\n }\n Self square() const {\n  Self ret(N);\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ ret.x[i * j]+= x[i] * x[j];\n  ret.x+= ret.x;\n  for (i= l; i; --i) ret.x[i\
    \ * i]+= x[i] * x[i];\n  for (l= L; l; ret.X[K + l]+= ret.X[K + l], ret.X[K +\
    \ l--]-= tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i)\
    \ ret.X[K + l]+= x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i)\
    \ ret.X[i]= ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self pow(uint64_t M)\
    \ const {\n  if (N / M > M)\n   for (auto ret= Self(N, true), b= *this;; b= b.square())\
    \ {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return ret;\n   }\n  size_t n=\
    \ 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M && (1ULL << n) <= N) ++n;\n\
    \  T pw[65]= {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n   if (e & 1 ?\
    \ pw[0]*= b : T(); !(e>>= 1)) break;\n  for (m= 1; m < n; ++m) pw[m]= pw[m - 1]\
    \ * x[1];\n  Self ret(*this);\n  std::valarray<T> D= (ret.X-= x[1]), E(std::begin(D),\
    \ K + 1), Y(std::begin(D) + K, L + 1), y= x, z(K + 1), Z(L + 1);\n  auto A= [&](uint64_t\
    \ n) { return n > K ? D[K + (double)N / n] : D[n]; };\n  auto B= [&](uint64_t\
    \ n) { return n > K ? Y[(double)N / n] : E[n]; };\n  for (tmp= pw[n - 2] * M,\
    \ l= L; l; l--) ret.X[K + l]*= tmp;\n  for (i= 2; i <= K; ++i) ret.x[i]*= tmp;\n\
    \  for (ret.x[1]= pw[n - 1], l= L; l; l--) ret.X[K + l]+= ret.x[1];\n  for (m=\
    \ 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m + 1 < n;)\
    \ {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; ret.X[K + l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) ret.x[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(std::begin(Z) + 1, l, 0); p * 2 <= K) std::fill(std::begin(z) +\
    \ p * 2, std::end(z), 0);\n   if (p <= K)\n    for (E[p]= y[p], i= p + 1; i <=\
    \ K; ++i) E[i]= E[i - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n inline T sum() const { return\
    \ X[K + 1]; }\n inline T sum(uint64_t n) const { return n > K ? X[K + (double)N\
    \ / n] : X[n]; }\n inline T operator()(uint64_t n) const { return n > K ? x[K\
    \ + (double)N / n] : x[n]; }\n};\n// 1, zeta(s), O(K+L)\ntemplate <class T> DirichletSeries<T>\
    \ get_1(uint64_t N) {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.L; i;\
    \ --i) ret.X[ret.K + i]= uint64_t((double)N / i);\n return std::fill(std::begin(ret.x)\
    \ + 1, std::end(ret.x), T(1)), std::iota(std::begin(ret.X), std::begin(ret.X)\
    \ + ret.K + 1, 0), ret;\n}\n// Mobius, 1/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_mu(uint64_t N) { return DirichletSeries<T>(N,\
    \ true)/= get_1<T>(N); }\n// n, zeta(s-1)\ntemplate <class T> DirichletSeries<T>\
    \ get_Id(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a;\n for (size_t\
    \ l= ret.L; l; --l) a= (double)N / l, ret.X[ret.K + l]= (a * (a + 1)) >> 1;\n\
    \ std::iota(std::begin(ret.x), std::end(ret.x), 0);\n for (size_t i= 1; i <= ret.K;\
    \ ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return ret;\n}\n// n^2, zeta(s-2),\
    \ O(K+L)\ntemplate <class T> DirichletSeries<T> get_Id2(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a, b, c;\n for (size_t l= ret.L; l; --l) a= (double)N\
    \ / l, b= (a * (a + 1)) >> 1, c= (a + a + 1), ret.X[ret.K + l]= c % 3 == 0 ? T(c\
    \ / 3) * b : T(b / 3) * c;\n for (uint64_t i= ret.K; i; --i) ret.x[i]= i * i;\n\
    \ for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return\
    \ ret;\n}\n// number-of-divisors, zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_d(uint64_t N) { return get_1<T>(N).square();\
    \ }\n// sum-of-divisors, zeta(s)zeta(s-2), function, O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_sigma(uint64_t N) { return get_1<T>(N) * get_Id<T>(N);\
    \ }\n// Euler's totient, zeta(s-1)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_phi(uint64_t N) { return get_Id<T>(N)/= get_1<T>(N);\
    \ }\ntemplate <class T>  // zeta(2s), O(K+L)\nDirichletSeries<T> get_1sq(uint64_t\
    \ N) {\n DirichletSeries<T> ret(N);\n for (size_t i= 1, e= ret.x.size(); i * i\
    \ <= e; ++i) ret.x[i * i]= 1;\n for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i\
    \ - 1] + ret.x[i];\n for (size_t l= ret.L; l; --l) ret.X[ret.K + l]= uint64_t(std::sqrt((double)N\
    \ / l));\n return ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\n\
    template <class T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/=\
    \ get_1<T>(N); }\n// square-free, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N);\
    \ }\n"
  code: "#pragma once\n#include <valarray>\n#include <iterator>\n#include <algorithm>\n\
    #include <cmath>\n#include <cassert>\n#include <numeric>\n#include <cstdint>\n\
    template <class T> struct DirichletSeries {\n using Self= DirichletSeries;\n uint64_t\
    \ N;  // <= K * L\n size_t K, L;\n std::valarray<T> x, X;\n DirichletSeries(uint64_t\
    \ N, bool unit= false): N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N\
    \ / std::log2(N), 2. / 3)), std::sqrt(N) + 1) : 1), L((N - 1 + K) / K), x(K +\
    \ 1), X(K + L + 1) {\n  if (assert(N > 0); unit) x[1]= 1, X= 1;\n }\n template\
    \ <class F, typename= std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F,\
    \ uint64_t>, T>>> DirichletSeries(uint64_t N, const F &sum): DirichletSeries(N)\
    \ {\n  for (size_t i= 1; i <= K; ++i) X[i]= sum(i);\n  for (size_t i= 1; i <=\
    \ L; ++i) X[K + i]= sum(uint64_t((double)N / i));\n  for (size_t i= K; i; --i)\
    \ x[i]= X[i] - X[i - 1];\n }\n Self operator-() const {\n  Self ret(N);\n  return\
    \ ret.x= -x, ret.X= -X, ret;\n }\n Self &operator+=(T r) { return x[1]+= r, X+=\
    \ r, *this; }\n Self &operator-=(T r) { return x[1]-= r, X-= r, *this; }\n Self\
    \ &operator*=(T r) { return x*= r, X*= r, *this; }\n Self &operator/=(T r) {\n\
    \  if (T iv= T(1) / r; iv == 0) x/= r, X/= r;\n  else x*= iv, X*= iv;\n  return\
    \ *this;\n }\n Self &operator+=(const Self &r) { return assert(N == r.N), assert(K\
    \ == r.K), assert(L == r.L), x+= r.x, X+= r.X, *this; }\n Self &operator-=(const\
    \ Self &r) { return assert(N == r.N), assert(K == r.K), assert(L == r.L), x-=\
    \ r.x, X-= r.X, *this; }\n Self operator+(T r) const { return Self(*this)+= r;\
    \ }\n Self operator-(T r) const { return Self(*this)-= r; }\n Self operator*(T\
    \ r) const { return Self(*this)*= r; }\n Self operator/(T r) const { return Self(*this)/=\
    \ r; }\n Self operator+(const Self &r) const { return Self(*this)+= r; }\n Self\
    \ operator-(const Self &r) const { return Self(*this)-= r; }\n friend Self operator+(T\
    \ l, Self r) { return r+= l; }\n friend Self operator-(T l, Self r) { return r.x[1]-=\
    \ l, r.X-= l, r.x= -r.x, r.X= -r.X, r; }\n friend Self operator*(T l, const Self\
    \ &r) { return r * l; }\n friend Self operator/(T l, const Self &r) { return (Self(r.N,\
    \ true)/= r)*= l; }\n Self operator*(const Self &r) const {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  Self ret(N);\n  uint64_t n;\n  for (size_t\
    \ i= K, j; i; --i)\n   for (j= K / i; j; --j) ret.x[i * j]+= x[i] * r.x[j];\n\
    \  for (size_t l= L, m, i; l; ret.X[K + l--]-= sum(m) * r.sum(m))\n   for (i=\
    \ m= std::sqrt(n= (double)N / l); i; --i) ret.X[K + l]+= x[i] * r.sum((double)n\
    \ / i) + r.x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self operator/(const Self &r)\
    \ const { return Self(*this)/= r; }\n Self &operator*=(const Self &r) { return\
    \ *this= *this * r; }\n Self &operator/=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(L == r.L);\n  for (size_t i= 1, j, ed; i <= K; i++)\n\
    \   for (x[i]/= r.x[1], j= 2, ed= K / i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n\
    \  X[1]= x[1];\n  for (size_t i= 2; i <= K; ++i) X[i]= X[i - 1] + x[i];\n  uint64_t\
    \ n;\n  for (size_t l= L, m; l; X[K + l--]/= r.x[1])\n   for (m= std::sqrt(n=\
    \ (double)N / l), X[K + l]+= r.sum(m) * sum(m) - x[1] * r.sum(n); m > 1;) X[K\
    \ + l]-= r.x[m] * sum((double)n / m) + x[m] * r.sum((double)n / m), --m;\n  return\
    \ *this;\n }\n Self square() const {\n  Self ret(N);\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ ret.x[i * j]+= x[i] * x[j];\n  ret.x+= ret.x;\n  for (i= l; i; --i) ret.x[i\
    \ * i]+= x[i] * x[i];\n  for (l= L; l; ret.X[K + l]+= ret.X[K + l], ret.X[K +\
    \ l--]-= tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i)\
    \ ret.X[K + l]+= x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i)\
    \ ret.X[i]= ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n Self pow(uint64_t M)\
    \ const {\n  if (N / M > M)\n   for (auto ret= Self(N, true), b= *this;; b= b.square())\
    \ {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return ret;\n   }\n  size_t n=\
    \ 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M && (1ULL << n) <= N) ++n;\n\
    \  T pw[65]= {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n   if (e & 1 ?\
    \ pw[0]*= b : T(); !(e>>= 1)) break;\n  for (m= 1; m < n; ++m) pw[m]= pw[m - 1]\
    \ * x[1];\n  Self ret(*this);\n  std::valarray<T> D= (ret.X-= x[1]), E(std::begin(D),\
    \ K + 1), Y(std::begin(D) + K, L + 1), y= x, z(K + 1), Z(L + 1);\n  auto A= [&](uint64_t\
    \ n) { return n > K ? D[K + (double)N / n] : D[n]; };\n  auto B= [&](uint64_t\
    \ n) { return n > K ? Y[(double)N / n] : E[n]; };\n  for (tmp= pw[n - 2] * M,\
    \ l= L; l; l--) ret.X[K + l]*= tmp;\n  for (i= 2; i <= K; ++i) ret.x[i]*= tmp;\n\
    \  for (ret.x[1]= pw[n - 1], l= L; l; l--) ret.X[K + l]+= ret.x[1];\n  for (m=\
    \ 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m + 1 < n;)\
    \ {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; ret.X[K + l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) ret.x[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(std::begin(Z) + 1, l, 0); p * 2 <= K) std::fill(std::begin(z) +\
    \ p * 2, std::end(z), 0);\n   if (p <= K)\n    for (E[p]= y[p], i= p + 1; i <=\
    \ K; ++i) E[i]= E[i - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n inline T sum() const { return\
    \ X[K + 1]; }\n inline T sum(uint64_t n) const { return n > K ? X[K + (double)N\
    \ / n] : X[n]; }\n inline T operator()(uint64_t n) const { return n > K ? x[K\
    \ + (double)N / n] : x[n]; }\n};\n// 1, zeta(s), O(K+L)\ntemplate <class T> DirichletSeries<T>\
    \ get_1(uint64_t N) {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.L; i;\
    \ --i) ret.X[ret.K + i]= uint64_t((double)N / i);\n return std::fill(std::begin(ret.x)\
    \ + 1, std::end(ret.x), T(1)), std::iota(std::begin(ret.X), std::begin(ret.X)\
    \ + ret.K + 1, 0), ret;\n}\n// Mobius, 1/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_mu(uint64_t N) { return DirichletSeries<T>(N,\
    \ true)/= get_1<T>(N); }\n// n, zeta(s-1)\ntemplate <class T> DirichletSeries<T>\
    \ get_Id(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a;\n for (size_t\
    \ l= ret.L; l; --l) a= (double)N / l, ret.X[ret.K + l]= (a * (a + 1)) >> 1;\n\
    \ std::iota(std::begin(ret.x), std::end(ret.x), 0);\n for (size_t i= 1; i <= ret.K;\
    \ ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return ret;\n}\n// n^2, zeta(s-2),\
    \ O(K+L)\ntemplate <class T> DirichletSeries<T> get_Id2(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a, b, c;\n for (size_t l= ret.L; l; --l) a= (double)N\
    \ / l, b= (a * (a + 1)) >> 1, c= (a + a + 1), ret.X[ret.K + l]= c % 3 == 0 ? T(c\
    \ / 3) * b : T(b / 3) * c;\n for (uint64_t i= ret.K; i; --i) ret.x[i]= i * i;\n\
    \ for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return\
    \ ret;\n}\n// number-of-divisors, zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_d(uint64_t N) { return get_1<T>(N).square();\
    \ }\n// sum-of-divisors, zeta(s)zeta(s-2), function, O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_sigma(uint64_t N) { return get_1<T>(N) * get_Id<T>(N);\
    \ }\n// Euler's totient, zeta(s-1)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_phi(uint64_t N) { return get_Id<T>(N)/= get_1<T>(N);\
    \ }\ntemplate <class T>  // zeta(2s), O(K+L)\nDirichletSeries<T> get_1sq(uint64_t\
    \ N) {\n DirichletSeries<T> ret(N);\n for (size_t i= 1, e= ret.x.size(); i * i\
    \ <= e; ++i) ret.x[i * i]= 1;\n for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i\
    \ - 1] + ret.x[i];\n for (size_t l= ret.L; l; --l) ret.X[ret.K + l]= uint64_t(std::sqrt((double)N\
    \ / l));\n return ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\n\
    template <class T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/=\
    \ get_1<T>(N); }\n// square-free, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N);\
    \ }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/DirichletSeries.hpp
  requiredBy: []
  timestamp: '2024-02-08 01:24:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1573.Dirichlet.test.cpp
  - test/yukicoder/1276.Dirichlet.test.cpp
  - test/atcoder/arc116_c.Dirichlet.test.cpp
  - test/atcoder/abc239_ex.test.cpp
  - test/atcoder/abc179_c.Dirichlet.test.cpp
  - test/atcoder/abc172_d.Dirichlet.test.cpp
  - test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
documentation_of: src/NumberTheory/DirichletSeries.hpp
layout: document
title: "\u30C7\u30A3\u30EA\u30AF\u30EC\u7D1A\u6570"
---

$\newcommand{\floor}[1]{\left\lfloor{#1}\right\rfloor}$

ディリクレ級数の四則演算で作り上げた数論的関数の累積和を計算するためのもの.
## `DirichletSeries<T>` クラス
正の整数 $N$ が与えられるとする. <br>
ある数論的関数 $f$ と $k\in \lbrace a\in \mathbb{N}\; \vert\; \exists m \in \mathbb{N}, a=\floor{\frac{N}{m}}\rbrace$ について

$\displaystyle
F(k) = \sum_{n=1}^k f(n)
$

の値を格納する (と思うことにする) データ構造. \
$f$ や $F$ そのものは保持しない. \
またディリクレ級数として四則演算をサポート. \
以下 $K,L$ は 

$\displaystyle
K \simeq (N/\log N)^{2/3}, L\simeq N^{1/3}(\log N)^{2/3}
$

ぐらいの $N \leq KL$ を満たす正の整数を表す.

$O(K\log K+\sqrt{NL})=O(N^{2/3}(\log N)^{1/3})$

またディリクレ級数の単元として次の表記を導入.

$\displaystyle 
\varepsilon(n) \equiv \lbrack n=1
\rbrack 
\equiv 
\begin{cases}
1& n=1, \newline
0& n \gt 1.
\end{cases}
$


|メンバ変数|概要|
|---|---|
|`N`|$N$|
|`K`|$K$|
|`x`| $f(1),\dots,f(K)$ の値を保存している配列. <br> サイズは$K+1$. 0番目の値は未定義.|
|`Xs`|$F(1),\dots,F(K)$ の値を保存している配列. <br> サイズは$K+1$. 0番目の値は未定義.|
|`Xl`|$F(\floor{N/1}),\dots,F(\floor{N/L})$ の値を保存している配列. <br> サイズは$L+1$. 0番目の値は未定義.|

|演算子オーバーロード|概要 ( $f,g$ から $h$ を返すイメージ )|計算量|
|---|---|---|
|`operator-(f)`|$h(n)=-f(n)$|$O(K+L)$|
|`operator+(f,g)`|$h(n)=f(n)+g(n)$|$O(K+L)$|
|`operator+(f,a)` |$h(n)=f(n)+a\cdot\varepsilon(n)$|$O(K+L)$|
|`operator+(a,f)` |$h(n)=a\cdot\varepsilon(n) + f(n)$　(上と同じ)|$O(K+L)$|
|`operator-(f,g)`|$h(n)=f(n)-g(n)$|$O(K+L)$|
|`operator-(f,a)`|$h(n)=f(n)-a\cdot\varepsilon(n)$|$O(K+L)$|
|`operator-(a,f)`|$h(n)=a\cdot\varepsilon(n)-f(n)$|$O(K+L)$|
|`operator*(f,g)`|$\displaystyle h(n)=\sum_{ij=n}f(i)g(j)$|$O(K\log K+\sqrt{NL})$|
|`operator*(f,a)`|$h(n)= f(n)\cdot a$|$O(K+L)$|
|`operator*(a,f)`|$h(n)=a\cdot f(n)$ (上と同じ)|$O(K+L)$|
|`operator/(f,g)`|$\displaystyle f(n) = \sum_{ij=n}h(i)g(j)$ を満たす $h$.|$O(K\log K+\sqrt{NL})$|
|`operator/(f,a)`|$h(n)=f(n) /a$|$O(K+L)$|
|`operator/(a,f)`|$\displaystyle a\cdot \varepsilon(n) = \sum_{ij=n}h(i)f(j)$ を満たす $h$.|$O(K\log K+\sqrt{NL})$|

|メンバ関数|概要|計算量|
|---|---|---|
|`DirichletSeries(N, x, Xs, Xl)`|コンストラクタ. $N$ と配列を直接渡して構築.||
|`DirichletSeries(N, unit=false)`|コンストラクタ. $N$ を渡して構築. <br> `unit` が `false` なら $f(n)\equiv0$, `true` なら $f(n)\equiv \varepsilon(n)$ のケースとして構築. <br> それぞれディリクレ級数の零元, 単元を意味する. ||
|`DirichletSeries(N, sum)`|コンストラクタ. $N$ と関数 $F$ を渡して構築. ||
|`sum(k)`| $F(k)$ を返す. <br>ただし <br> $\displaystyle k\in\left \lbrace a\in \mathbb{N}\; \vert\; \exists m \in \mathbb{N}, a=\floor{\frac{N}{m}}\right\rbrace$ <br>のケースのみ想定.|$O(1)$|
|`sum()`|$\displaystyle F(N)=\sum_{n=1}^N f(n)$ を返す.|$O(1)$
|`square()`|$\displaystyle h(n)=\sum_{ij=n}f(i)f(j)$ についての `DirichletSeries` クラスのオブジェクトを返す. <br> `operator*(f,f)` と同じ結果 (定数倍速い).|$O(K\log K+\sqrt{NL})$|
|`pow(M)`|$\displaystyle h(n)=\sum_{i_1\cdots i_M=n}f(i_1)\cdots f(i_M)$ についての `DirichletSeries` クラスのオブジェクトを返す. <br> つまりディリクレ積の $M$ 乗.|$O(R(N)\log N)$<br> ただし $R(N)=O(K\log K+\sqrt{NL})$|


## 具体的な数論的関数の　`DirichletSeries<T>`

$N$ を与えて, 具体的な数論的関数についての `DirichletSeries` クラスのオブジェクトを返す.

|関数|数論的関数|計算量|
|---|---|---|
|`get_1(N)`|$f(n)\equiv 1$| $O(K+L)$|
|`get_mu(N)`|$f(n)\equiv\mu(n)$ <br> メビウス関数| $O(K\log K+\sqrt{NL})$|
|`get_Id(N)`|$f(n)\equiv n$| $O(K+L)$|
|`get_Id2(N)`|$f(n)\equiv n^2$| $O(K+L)$|
|`get_d(N)`|$f(n)\equiv d(n)$ <br> 約数の個数関数| $O(K\log K+\sqrt{NL})$|
|`get_sigma(N)`|$f(n)\equiv \sigma(n)$ <br> 約数の和関数| $O(K\log K+\sqrt{NL})$|
|`get_phi(N)`|$f(n)\equiv \phi(n)$ <br> オイラーのトーシェント関数| $O(K\log K+\sqrt{NL})$|
|`get_1sq(N)`|$f(n)\equiv \lbrack n \text{ is a square} \rbrack$ <br> $n$ が平方数の時のみ $1$, それ以外 $0$| $O(K\log K+\sqrt{NL})$|
|`get_lambda(N)`|$f(n)\equiv\lambda(n)$ <br> Liouville のラムダ関数| $O(K\log K+\sqrt{NL})$|
|`get_absmu(N)`|$f(n)\equiv\lvert\mu(n)\rvert$ <br> メビウス関数の絶対値. square-free| $O(K\log K+\sqrt{NL})$|


## 参考
[https://maspypy.com/dirichlet-積と、数論関数の累積和](https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C)
## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) (Liouville)\
[LibreOJ #6491. 「XXOI 2018」简单的最大公约数](https://loj.ac/p/6491) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) \
[LibreOJ #6714. Stupid Product](https://loj.ac/p/6714)\
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) ([prime count](src/NumberTheory/ExtendedEratosthenesSieve.hpp) もいる)