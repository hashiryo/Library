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
  - icon: ':x:'
    path: test/atcoder/arc116_c.Dirichlet.test.cpp
    title: test/atcoder/arc116_c.Dirichlet.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
    title: test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1276.Dirichlet.test.cpp
    title: test/yukicoder/1276.Dirichlet.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1573.Dirichlet.test.cpp
    title: test/yukicoder/1573.Dirichlet.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/DirichletSeries.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <cmath>\n#include <cassert>\n#include <numeric>\ntemplate\
    \ <class T> struct DirichletSeries {\n using Self= DirichletSeries;\n uint64_t\
    \ N;  // <= K * L\n size_t K;\n // x: i (1 <= i <= K), Xl : 1+2+...+\u230AN/i\u230B\
    \ (1 <= i <= L)\n std::vector<T> x, Xs, Xl;\n DirichletSeries(uint64_t N, const\
    \ std::vector<T> &x, const std::vector<T> &Xs, const std::vector<T> &Xl): N(N),\
    \ K(x.size() - 1), x(x), Xs(Xs), Xl(Xl) { assert(K + 1 == Xs.size()), assert(N\
    \ < uint64_t(K) * Xl.size()); }\n DirichletSeries(uint64_t N, bool unit= false):\
    \ N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N / std::log2(N), 2. / 3)),\
    \ std::sqrt(N) + 1) : 1) {\n  if (assert(N > 0), x.resize(K + 1), Xs.resize(K\
    \ + 1), Xl.resize(size_t(double(N - 1 + K) / K) + 1); unit) x[1]= 1, std::fill(Xl.begin()\
    \ + 1, Xl.end(), 1), std::fill(Xs.begin() + 1, Xs.end(), 1);\n }\n template <class\
    \ F, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F, uint64_t>,\
    \ T>, std::nullptr_t> = nullptr> DirichletSeries(uint64_t N, const F &sum): DirichletSeries(N)\
    \ {\n  for (size_t i= Xs.size(); --i;) Xs[i]= sum(i);\n  for (size_t i= x.size();\
    \ --i;) x[i]= Xs[i] - Xs[i - 1];\n  for (size_t i= Xl.size(); --i;) Xl[i]= sum(uint64_t((double)N\
    \ / i));\n }\n Self &operator*=(const T &r) {\n  for (size_t i= x.size(); --i;)\
    \ x[i]*= r;\n  for (size_t i= Xs.size(); --i;) Xs[i]*= r;\n  for (size_t i= Xl.size();\
    \ --i;) Xl[i]*= r;\n  return *this;\n }\n Self operator*(const T &r) const { return\
    \ Self(*this)*= r; }\n Self &operator+=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(Xl.size() == r.Xl.size());\n  for (size_t i= x.size();\
    \ --i;) x[i]+= r.x[i];\n  for (size_t i= Xs.size(); --i;) Xs[i]+= r.Xs[i];\n \
    \ for (size_t i= Xl.size(); --i;) Xl[i]+= r.Xl[i];\n  return *this;\n }\n Self\
    \ &operator-=(const Self &r) {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size()\
    \ == r.Xl.size());\n  for (size_t i= x.size(); --i;) x[i]-= r.x[i];\n  for (size_t\
    \ i= Xs.size(); --i;) Xs[i]-= r.Xs[i];\n  for (size_t i= Xl.size(); --i;) Xl[i]-=\
    \ r.Xl[i];\n }\n Self operator+(const Self &r) const { return Self(*this)+= r;\
    \ }\n Self operator-(const Self &r) const { return Self(*this)-= r; }\n Self operator-()\
    \ const {\n  std::vector<T> a(x.size()), As(Xl.size()), A(Xl.size());\n  for (size_t\
    \ i= x.size(); --i;) a[i]= -x[i];\n  for (size_t i= Xs.size(); --i;) As[i]= -Xs[i];\n\
    \  for (size_t i= Xl.size(); --i;) A[i]= -Xl[i];\n  return Self(N, a, As, A);\n\
    \ }\n Self &operator+=(const T &r) {\n  for (size_t i= Xl.size(); --i;) Xl[i]+=\
    \ r;\n  for (size_t i= Xs.size(); --i;) Xs[i]+= r;\n  return x[1]+= r, *this;\n\
    \ }\n Self &operator-=(const T &r) {\n  for (size_t i= Xl.size(); --i;) Xl[i]-=\
    \ r;\n  for (size_t i= Xs.size(); --i;) Xs[i]-= r;\n  return x[1]-= r, *this;\n\
    \ }\n Self operator+(const T &r) const { return Self(*this)+= r; }\n Self operator-(const\
    \ T &r) const { return Self(*this)-= r; }\n friend Self operator+(const T &l,\
    \ Self r) { return r+= l; }\n friend Self operator-(const T &l, Self r) { return\
    \ -(r-= l); }\n friend Self operator*(const T &l, Self r) { return r*= l; }\n\
    \ friend Self operator/(const T &l, Self r) { return (Self(r.N, true)/= r)*= l;\
    \ }\n Self operator*(const Self &r) const {\n  assert(N == r.N), assert(K == r.K),\
    \ assert(Xl.size() == r.Xl.size());\n  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n\
    \  uint64_t n;\n  for (size_t i= K, j; i; --i)\n   for (j= K / i; j; --j) c[i\
    \ * j]+= x[i] * r.x[j];\n  for (size_t l= Xl.size(), m, i; --l; C[l]-= sum(m)\
    \ * r.sum(m))\n   for (i= m= std::sqrt(n= (double)N / l); i; --i) C[l]+= x[i]\
    \ * r.sum((double)n / i) + r.x[i] * sum((double)n / i);\n  for (size_t i= 1; i\
    \ <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n  return Self(N, c, Cs, C);\n }\n Self\
    \ &operator*=(const Self &r) { return *this= *this * r; }\n Self operator/(const\
    \ Self &r) const { return Self(*this)/= r; }\n Self &operator/=(const Self &r)\
    \ {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  for (size_t i= 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1], j= 2, ed= K /\
    \ i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n  for (size_t i= 1; i <= K; ++i)\
    \ Xs[i]= Xs[i - 1] + x[i];\n  uint64_t n;\n  for (size_t l= Xl.size(), m; --l;\
    \ Xl[l]/= r.x[1])\n   for (m= std::sqrt(n= (double)N / l), Xl[l]+= r.sum(m) *\
    \ sum(m) - x[1] * r.sum(n); m > 1;) Xl[l]-= r.x[m] * sum((double)n / m) + x[m]\
    \ * r.sum((double)n / m), --m;\n  return *this;\n }\n Self square() const {\n\
    \  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ c[i * j]+= x[i] * x[j];\n  for (i= K; i; --i) c[i]+= c[i];\n  for (i= l; i;\
    \ --i) c[i * i]+= x[i] * x[i];\n  for (l= Xl.size(); --l; C[l]+= C[l], C[l]-=\
    \ tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i) C[l]+=\
    \ x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1]\
    \ + c[i];\n  return Self(N, c, Cs, C);\n }\n Self pow(uint64_t M) const {\n  const\
    \ size_t L= Xl.size() - 1;\n  if (N / M > M)\n   for (auto ret= Self(N, true),\
    \ b= *this;; b= b.square()) {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return\
    \ ret;\n   }\n  size_t n= 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M\
    \ && (1ULL << n) <= N) ++n;\n  Self ret(N);\n  T pw[65]= {1}, b= x[1], tmp;\n\
    \  for (e= M - n + 1;; b*= b)\n   if (e & 1 ? pw[0]*= b : T(); !(e>>= 1)) break;\n\
    \  for (m= 1; m < n; ++m) pw[m]= pw[m - 1] * x[1];\n  std::vector<T> Al(Xl), z(K\
    \ + 1, 0), Z(L + 1, 0), As(Xs);\n  for (i= K; i; --i) As[i]-= x[1];\n  for (i=\
    \ L; i; --i) Al[i]-= x[1];\n  auto A= [&](uint64_t n) { return n <= K ? As[n]\
    \ : Al[(double)N / n]; };\n  std::vector<T> y(x), Y(Al), Bs(As), c(y), Cs(K +\
    \ 1), C(Y);\n  auto B= [&](uint64_t n) { return n <= K ? Bs[n] : Y[(double)N /\
    \ n]; };\n  for (tmp= pw[n - 2] * M, l= L; l; l--) C[l]*= tmp;\n  for (i= 2; i\
    \ <= K; ++i) c[i]*= tmp;\n  for (c[1]= pw[n - 1], l= L; l; l--) C[l]+= c[1];\n\
    \  for (m= 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m +\
    \ 1 < n;) {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; C[l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) c[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(Z.begin() + 1, l, 0); p * 2 <= K) std::fill(z.begin() + p * 2, z.end(),\
    \ 0);\n   if (p <= K)\n    for (Bs[p]= y[p], i= p + 1; i <= K; ++i) Bs[i]= Bs[i\
    \ - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n\
    \  return Self(N, c, Cs, C);\n }\n inline T sum() const { return Xl[1]; }\n inline\
    \ T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[(double)N / n]; }\n};\n\
    template <class T>  // 1, zeta(s), O(N)\nDirichletSeries<T> get_1(uint64_t N)\
    \ {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.Xl.size(); --i;) ret.Xl[i]=\
    \ uint64_t((double)N / i);\n return std::fill(ret.x.begin() + 1, ret.x.end(),\
    \ T(1)), std::iota(ret.Xs.begin(), ret.Xs.end(), 0), ret;\n}\n// M\xF6bius, 1/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_mu(uint64_t\
    \ N) { return DirichletSeries<T>(N, true)/= get_1<T>(N); }\ntemplate <class T>\
    \  // n, zeta(s-1)\nDirichletSeries<T> get_Id(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a;\n for (size_t l= ret.Xl.size(); --l;) a= (double)N\
    \ / l, ret.Xl[l]= (a * (a + 1)) >> 1;\n std::iota(ret.x.begin(), ret.x.end(),\
    \ 0);\n for (size_t i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n\
    \ return ret;\n}\ntemplate <class T>  // n^2, zeta(s-2), O(N)\nDirichletSeries<T>\
    \ get_Id2(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a, b, c;\n\
    \ for (size_t l= ret.Xl.size(); --l;) a= (double)N / l, b= (a * (a + 1)) >> 1,\
    \ c= (a + a + 1), ret.Xl[l]= c % 3 == 0 ? T(c / 3) * b : T(b / 3) * c;\n for (uint64_t\
    \ i= ret.x.size(); --i;) ret.x[i]= i * i;\n for (size_t i= 1; i <= ret.K; ++i)\
    \ ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n return ret;\n}\n// number-of-divisors,\
    \ zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_d(uint64_t N) { return get_1<T>(N).square(); }\n// sum-of-divisors, zeta(s)zeta(s-2),\
    \ function, O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_sigma(uint64_t\
    \ N) { return get_1<T>(N) * get_Id<T>(N); }\n// Euler's totient, zeta(s-1)/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_phi(uint64_t\
    \ N) { return get_Id<T>(N)/= get_1<T>(N); }\ntemplate <class T>  // zeta(2s),\
    \ O(N)\nDirichletSeries<T> get_1sq(uint64_t N) {\n DirichletSeries<T> ret(N);\n\
    \ for (size_t i= 1, e= ret.x.size(); i * i <= e; ++i) ret.x[i * i]= 1;\n for (size_t\
    \ i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n for (size_t l=\
    \ ret.Xl.size(); --l;) ret.Xl[l]= uint64_t(std::sqrt((double)N / l));\n return\
    \ ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/= get_1<T>(N);\
    \ }\n// |\xB5|, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N); }\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cmath>\n\
    #include <cassert>\n#include <numeric>\ntemplate <class T> struct DirichletSeries\
    \ {\n using Self= DirichletSeries;\n uint64_t N;  // <= K * L\n size_t K;\n //\
    \ x: i (1 <= i <= K), Xl : 1+2+...+\u230AN/i\u230B (1 <= i <= L)\n std::vector<T>\
    \ x, Xs, Xl;\n DirichletSeries(uint64_t N, const std::vector<T> &x, const std::vector<T>\
    \ &Xs, const std::vector<T> &Xl): N(N), K(x.size() - 1), x(x), Xs(Xs), Xl(Xl)\
    \ { assert(K + 1 == Xs.size()), assert(N < uint64_t(K) * Xl.size()); }\n DirichletSeries(uint64_t\
    \ N, bool unit= false): N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N\
    \ / std::log2(N), 2. / 3)), std::sqrt(N) + 1) : 1) {\n  if (assert(N > 0), x.resize(K\
    \ + 1), Xs.resize(K + 1), Xl.resize(size_t(double(N - 1 + K) / K) + 1); unit)\
    \ x[1]= 1, std::fill(Xl.begin() + 1, Xl.end(), 1), std::fill(Xs.begin() + 1, Xs.end(),\
    \ 1);\n }\n template <class F, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F,\
    \ uint64_t>, T>, std::nullptr_t> = nullptr> DirichletSeries(uint64_t N, const\
    \ F &sum): DirichletSeries(N) {\n  for (size_t i= Xs.size(); --i;) Xs[i]= sum(i);\n\
    \  for (size_t i= x.size(); --i;) x[i]= Xs[i] - Xs[i - 1];\n  for (size_t i= Xl.size();\
    \ --i;) Xl[i]= sum(uint64_t((double)N / i));\n }\n Self &operator*=(const T &r)\
    \ {\n  for (size_t i= x.size(); --i;) x[i]*= r;\n  for (size_t i= Xs.size(); --i;)\
    \ Xs[i]*= r;\n  for (size_t i= Xl.size(); --i;) Xl[i]*= r;\n  return *this;\n\
    \ }\n Self operator*(const T &r) const { return Self(*this)*= r; }\n Self &operator+=(const\
    \ Self &r) {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  for (size_t i= x.size(); --i;) x[i]+= r.x[i];\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]+= r.Xs[i];\n  for (size_t i= Xl.size(); --i;) Xl[i]+= r.Xl[i];\n\
    \  return *this;\n }\n Self &operator-=(const Self &r) {\n  assert(N == r.N),\
    \ assert(K == r.K), assert(Xl.size() == r.Xl.size());\n  for (size_t i= x.size();\
    \ --i;) x[i]-= r.x[i];\n  for (size_t i= Xs.size(); --i;) Xs[i]-= r.Xs[i];\n \
    \ for (size_t i= Xl.size(); --i;) Xl[i]-= r.Xl[i];\n }\n Self operator+(const\
    \ Self &r) const { return Self(*this)+= r; }\n Self operator-(const Self &r) const\
    \ { return Self(*this)-= r; }\n Self operator-() const {\n  std::vector<T> a(x.size()),\
    \ As(Xl.size()), A(Xl.size());\n  for (size_t i= x.size(); --i;) a[i]= -x[i];\n\
    \  for (size_t i= Xs.size(); --i;) As[i]= -Xs[i];\n  for (size_t i= Xl.size();\
    \ --i;) A[i]= -Xl[i];\n  return Self(N, a, As, A);\n }\n Self &operator+=(const\
    \ T &r) {\n  for (size_t i= Xl.size(); --i;) Xl[i]+= r;\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]+= r;\n  return x[1]+= r, *this;\n }\n Self &operator-=(const T &r)\
    \ {\n  for (size_t i= Xl.size(); --i;) Xl[i]-= r;\n  for (size_t i= Xs.size();\
    \ --i;) Xs[i]-= r;\n  return x[1]-= r, *this;\n }\n Self operator+(const T &r)\
    \ const { return Self(*this)+= r; }\n Self operator-(const T &r) const { return\
    \ Self(*this)-= r; }\n friend Self operator+(const T &l, Self r) { return r+=\
    \ l; }\n friend Self operator-(const T &l, Self r) { return -(r-= l); }\n friend\
    \ Self operator*(const T &l, Self r) { return r*= l; }\n friend Self operator/(const\
    \ T &l, Self r) { return (Self(r.N, true)/= r)*= l; }\n Self operator*(const Self\
    \ &r) const {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n  uint64_t n;\n  for (size_t\
    \ i= K, j; i; --i)\n   for (j= K / i; j; --j) c[i * j]+= x[i] * r.x[j];\n  for\
    \ (size_t l= Xl.size(), m, i; --l; C[l]-= sum(m) * r.sum(m))\n   for (i= m= std::sqrt(n=\
    \ (double)N / l); i; --i) C[l]+= x[i] * r.sum((double)n / i) + r.x[i] * sum((double)n\
    \ / i);\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n  return Self(N,\
    \ c, Cs, C);\n }\n Self &operator*=(const Self &r) { return *this= *this * r;\
    \ }\n Self operator/(const Self &r) const { return Self(*this)/= r; }\n Self &operator/=(const\
    \ Self &r) {\n  assert(N == r.N), assert(K == r.K), assert(Xl.size() == r.Xl.size());\n\
    \  for (size_t i= 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1], j= 2, ed= K /\
    \ i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n  for (size_t i= 1; i <= K; ++i)\
    \ Xs[i]= Xs[i - 1] + x[i];\n  uint64_t n;\n  for (size_t l= Xl.size(), m; --l;\
    \ Xl[l]/= r.x[1])\n   for (m= std::sqrt(n= (double)N / l), Xl[l]+= r.sum(m) *\
    \ sum(m) - x[1] * r.sum(n); m > 1;) Xl[l]-= r.x[m] * sum((double)n / m) + x[m]\
    \ * r.sum((double)n / m), --m;\n  return *this;\n }\n Self square() const {\n\
    \  std::vector<T> c(K + 1), Cs(K + 1), C(Xl.size());\n  size_t i, j, l= std::sqrt(K);\n\
    \  uint64_t n;\n  T tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j)\
    \ c[i * j]+= x[i] * x[j];\n  for (i= K; i; --i) c[i]+= c[i];\n  for (i= l; i;\
    \ --i) c[i * i]+= x[i] * x[i];\n  for (l= Xl.size(); --l; C[l]+= C[l], C[l]-=\
    \ tmp * tmp)\n   for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i) C[l]+=\
    \ x[i] * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1]\
    \ + c[i];\n  return Self(N, c, Cs, C);\n }\n Self pow(uint64_t M) const {\n  const\
    \ size_t L= Xl.size() - 1;\n  if (N / M > M)\n   for (auto ret= Self(N, true),\
    \ b= *this;; b= b.square()) {\n    if (M & 1) ret*= b;\n    if (!(M>>= 1)) return\
    \ ret;\n   }\n  size_t n= 0, m, i, l, p= 2;\n  uint64_t e, j;\n  while (n <= M\
    \ && (1ULL << n) <= N) ++n;\n  Self ret(N);\n  T pw[65]= {1}, b= x[1], tmp;\n\
    \  for (e= M - n + 1;; b*= b)\n   if (e & 1 ? pw[0]*= b : T(); !(e>>= 1)) break;\n\
    \  for (m= 1; m < n; ++m) pw[m]= pw[m - 1] * x[1];\n  std::vector<T> Al(Xl), z(K\
    \ + 1, 0), Z(L + 1, 0), As(Xs);\n  for (i= K; i; --i) As[i]-= x[1];\n  for (i=\
    \ L; i; --i) Al[i]-= x[1];\n  auto A= [&](uint64_t n) { return n <= K ? As[n]\
    \ : Al[(double)N / n]; };\n  std::vector<T> y(x), Y(Al), Bs(As), c(y), Cs(K +\
    \ 1), C(Y);\n  auto B= [&](uint64_t n) { return n <= K ? Bs[n] : Y[(double)N /\
    \ n]; };\n  for (tmp= pw[n - 2] * M, l= L; l; l--) C[l]*= tmp;\n  for (i= 2; i\
    \ <= K; ++i) c[i]*= tmp;\n  for (c[1]= pw[n - 1], l= L; l; l--) C[l]+= c[1];\n\
    \  for (m= 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m +\
    \ 1 < n;) {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; C[l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) c[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(Z.begin() + 1, l, 0); p * 2 <= K) std::fill(z.begin() + p * 2, z.end(),\
    \ 0);\n   if (p <= K)\n    for (Bs[p]= y[p], i= p + 1; i <= K; ++i) Bs[i]= Bs[i\
    \ - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) Cs[i]= Cs[i - 1] + c[i];\n\
    \  return Self(N, c, Cs, C);\n }\n inline T sum() const { return Xl[1]; }\n inline\
    \ T sum(uint64_t n) const { return n <= K ? Xs[n] : Xl[(double)N / n]; }\n};\n\
    template <class T>  // 1, zeta(s), O(N)\nDirichletSeries<T> get_1(uint64_t N)\
    \ {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.Xl.size(); --i;) ret.Xl[i]=\
    \ uint64_t((double)N / i);\n return std::fill(ret.x.begin() + 1, ret.x.end(),\
    \ T(1)), std::iota(ret.Xs.begin(), ret.Xs.end(), 0), ret;\n}\n// M\xF6bius, 1/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_mu(uint64_t\
    \ N) { return DirichletSeries<T>(N, true)/= get_1<T>(N); }\ntemplate <class T>\
    \  // n, zeta(s-1)\nDirichletSeries<T> get_Id(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a;\n for (size_t l= ret.Xl.size(); --l;) a= (double)N\
    \ / l, ret.Xl[l]= (a * (a + 1)) >> 1;\n std::iota(ret.x.begin(), ret.x.end(),\
    \ 0);\n for (size_t i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n\
    \ return ret;\n}\ntemplate <class T>  // n^2, zeta(s-2), O(N)\nDirichletSeries<T>\
    \ get_Id2(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a, b, c;\n\
    \ for (size_t l= ret.Xl.size(); --l;) a= (double)N / l, b= (a * (a + 1)) >> 1,\
    \ c= (a + a + 1), ret.Xl[l]= c % 3 == 0 ? T(c / 3) * b : T(b / 3) * c;\n for (uint64_t\
    \ i= ret.x.size(); --i;) ret.x[i]= i * i;\n for (size_t i= 1; i <= ret.K; ++i)\
    \ ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n return ret;\n}\n// number-of-divisors,\
    \ zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_d(uint64_t N) { return get_1<T>(N).square(); }\n// sum-of-divisors, zeta(s)zeta(s-2),\
    \ function, O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_sigma(uint64_t\
    \ N) { return get_1<T>(N) * get_Id<T>(N); }\n// Euler's totient, zeta(s-1)/zeta(s),\
    \ O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T> get_phi(uint64_t\
    \ N) { return get_Id<T>(N)/= get_1<T>(N); }\ntemplate <class T>  // zeta(2s),\
    \ O(N)\nDirichletSeries<T> get_1sq(uint64_t N) {\n DirichletSeries<T> ret(N);\n\
    \ for (size_t i= 1, e= ret.x.size(); i * i <= e; ++i) ret.x[i * i]= 1;\n for (size_t\
    \ i= 1; i <= ret.K; ++i) ret.Xs[i]= ret.Xs[i - 1] + ret.x[i];\n for (size_t l=\
    \ ret.Xl.size(); --l;) ret.Xl[l]= uint64_t(std::sqrt((double)N / l));\n return\
    \ ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/= get_1<T>(N);\
    \ }\n// |\xB5|, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate <class T> DirichletSeries<T>\
    \ get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N); }"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/DirichletSeries.hpp
  requiredBy: []
  timestamp: '2023-05-16 15:13:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1276.Dirichlet.test.cpp
  - test/yukicoder/1573.Dirichlet.test.cpp
  - test/atcoder/arc116_c.Dirichlet.test.cpp
  - test/atcoder/abc179_c.Dirichlet.test.cpp
  - test/atcoder/abc172_d.Dirichlet.test.cpp
  - test/yosupo/sum_of_totient_function.Dirichlet.test.cpp
documentation_of: src/Math/DirichletSeries.hpp
layout: document
title: "\u30C7\u30A3\u30EA\u30AF\u30EC\u7D1A\u6570"
---

ディリクレ級数の四則演算で作り上げた数論的関数の累積和を計算する

## 計算量
$\mathcal{O} (N^{2/3}(\log N)^{1/3})$

## 参考
[https://maspypy.com/dirichlet-積と、数論関数の累積和](https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C)
## 問題例
[Xmas Contest 2019 D - Sum of (-1)^f(n)](https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d) (Liouville)\
[AtCoder Beginner Contest 239 Ex - Dice Product 2](https://atcoder.jp/contests/abc239/tasks/abc239_h) \
[LibreOJ #6491. 「XXOI 2018」简单的最大公约数](https://loj.ac/p/6491) \
[LibreOJ #6686. Stupid GCD](https://loj.ac/p/6686) \
[LibreOJ #6714. Stupid Product](https://loj.ac/p/6714)\
[LibreOJ #572. 「LibreOJ Round #11」Misaka Network 与求和](https://loj.ac/p/572) (prime count もいる)