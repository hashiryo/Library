---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u758E\u884C\u5217\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':heavy_check_mark:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/SparseSquareMatrix.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/berlekamp_massey.hpp\"\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2]\
    \ + ... + c[d-1] * a[n-d]\n// return c\ntemplate <class K> std::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n std::size_t n= a.size(), d= 0, m= 0, i, j;\n if (n ==\
    \ 0) return {};\n std::vector<K> c(n), b(n), tmp;\n K x= 1, y, coef;\n const K\
    \ Z= 0;\n for (c[0]= b[0]= 1, i= 0, j; i < n; ++i) {\n  for (++m, y= a[i], j=\
    \ 1; j <= d; ++j) y+= c[j] * a[i - j];\n  if (y == Z) continue;\n  for (tmp= c,\
    \ coef= y / x, j= m; j < n; ++j) c[j]-= coef * b[j - m];\n  if (2 * d > i) continue;\n\
    \  d= i + 1 - d, b= tmp, x= y, m= 0;\n }\n c.resize(d + 1), c.erase(c.begin());\n\
    \ for (auto &x: c) x= -x;\n return c;\n}\n#line 4 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\
    \n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)  + ... + c[1] * M + c[0]) * b = 0\n\
    template <class Mat, class Vec> class MinimalPolynomial {\n using mod_t= std::remove_reference_t<decltype((Vec{1})[0])>;\n\
    \ static const inline mod_t ZERO= 0;\n std::vector<mod_t> poly, rev;\n std::vector<Vec>\
    \ bs;\n std::size_t dg, n;\n static inline int deg(const std::vector<mod_t> &p)\
    \ {\n  for (int d= p.size() - 1;; d--)\n   if (d < 0 || p[d] != ZERO) return d;\n\
    \ }\n static inline std::vector<mod_t> bostan_mori_msb(const std::vector<mod_t>\
    \ &q, std::uint64_t k) {\n  int d= deg(q);\n  assert(d >= 0), assert(q[0] != ZERO);\n\
    \  std::vector<mod_t> ret(std::max(d, 1));\n  if (k == 0) return ret.back()= mod_t(1),\
    \ ret;\n  std::vector<mod_t> v(d + 1);\n  for (int i= 0; i <= d; i+= 2)\n   for\
    \ (int j= 0; j <= d; j+= 2) v[(i + j) >> 1]+= q[i] * q[j];\n  for (int i= 1; i\
    \ <= d; i+= 2)\n   for (int j= 1; j <= d; j+= 2) v[(i + j) >> 1]-= q[i] * q[j];\n\
    \  auto w= bostan_mori_msb(v, k >> 1);\n  for (int i= 2 * d - 1 - (k & 1); i >=\
    \ d; i-= 2)\n   for (int j= 0; j <= d; j+= 2) ret[i - d]+= q[j] * w[(i - j) >>\
    \ 1];\n  for (int i= 2 * d - 1 - !(k & 1); i >= d; i-= 2)\n   for (int j= 1; j\
    \ <= d; j+= 2) ret[i - d]-= q[j] * w[(i - j) >> 1];\n  return ret;\n }\n std::vector<mod_t>\
    \ x_pow_mod(std::uint64_t k) const {\n  assert(k >= n);\n  std::vector<mod_t>\
    \ ret(n), u= bostan_mori_msb(rev, k - n + dg);\n  for (int i= dg; i--;)\n   for\
    \ (int j= i + 1; j--;) ret[n - 1 - i]+= u[j] * rev[i - j];\n  return ret;\n }\n\
    public:\n MinimalPolynomial(const Mat &M, Vec b): n(M.size()) {\n  std::size_t\
    \ i, j;\n  assert(n == b.size());\n  std::vector<mod_t> a(n), v;\n  for (auto\
    \ &x: a) x= get_rand(1, mod_t::mod() - 1);\n  mod_t tmp;\n  for (i= (n + 1) <<\
    \ 1; i--; v.push_back(tmp)) {\n   if (i > n) bs.emplace_back(b);\n   for (tmp=\
    \ 0, j= n; j--;) tmp+= a[j] * b[j];\n   if (i) b= M * b;\n  }\n  rev= berlekamp_massey(v);\n\
    \  for (auto &x: rev) x= -x;\n  rev.insert(rev.begin(), 1), poly= rev;\n  rev.erase(rev.begin()\
    \ + (dg= deg(rev)) + 1, rev.end());\n  std::reverse(poly.begin(), poly.end());\n\
    \ }\n static std::uint64_t get_rand(std::uint64_t l, std::uint64_t r) {\n  static\
    \ std::mt19937_64 gen(std::random_device{}());\n  return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n }\n Vec pow(std::uint64_t k) const {  // M^k * b\n  if (k < n) return\
    \ bs[k];\n  auto r= x_pow_mod(k);\n  Vec ret= bs[0];\n  for (auto &x: ret) x*=\
    \ r[0];\n  for (int i= 1, e= r.size(), j; i < e; i++)\n   for (j= n; j--;) ret[j]+=\
    \ r[i] * bs[i][j];\n  return ret;\n }\n const mod_t operator[](std::size_t k)\
    \ const { return poly[k]; }\n const auto begin() const { return poly.begin();\
    \ }\n const auto end() const { return poly.end(); }\n const std::size_t size()\
    \ const { return dg + 1; }\n};\n#line 4 \"src/LinearAlgebra/SparseSquareMatrix.hpp\"\
    \ntemplate <class mod_t> struct SparseSquareMatrix {\n SparseSquareMatrix(std::size_t\
    \ n_): n(n_) {}\n void add_component(std::size_t i, std::size_t j, mod_t val)\
    \ { dat.emplace_back(i, j, val); }\n std::vector<mod_t> operator*(const std::vector<mod_t>\
    \ &vec) const {\n  std::vector<mod_t> ret(n);\n  assert(vec.size() == n);\n  for\
    \ (const auto &[i, j, val]: dat) ret[i]+= val * vec[j];\n  return ret;\n }\n auto\
    \ begin() { return dat.begin(); }\n auto end() { return dat.end(); }\n std::size_t\
    \ size() const { return n; }\n mod_t det() const {\n  const std::uint64_t MOD=\
    \ mod_t::mod();\n  using MinPoly= MinimalPolynomial<SparseSquareMatrix, std::vector<mod_t>>;\n\
    \  SparseSquareMatrix M(*this);\n  std::vector<mod_t> d(n), b(n);\n  for (auto\
    \ &x: b) x= MinPoly::get_rand(1, MOD - 1);\n  for (auto &x: d) x= MinPoly::get_rand(1,\
    \ MOD - 1);\n  for (auto &[i, j, val]: M) val*= d[j];\n  mod_t ret= MinPoly(M,\
    \ b)[0], tmp= 1;\n  for (const auto &x: d) tmp*= x;\n  if (n & 1) ret= -ret;\n\
    \  return ret / tmp;\n }\nprivate:\n std::size_t n;\n std::vector<std::tuple<std::size_t,\
    \ std::size_t, mod_t>> dat;\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/LinearAlgebra/MinimalPolynomial.hpp\"\
    \ntemplate <class mod_t> struct SparseSquareMatrix {\n SparseSquareMatrix(std::size_t\
    \ n_): n(n_) {}\n void add_component(std::size_t i, std::size_t j, mod_t val)\
    \ { dat.emplace_back(i, j, val); }\n std::vector<mod_t> operator*(const std::vector<mod_t>\
    \ &vec) const {\n  std::vector<mod_t> ret(n);\n  assert(vec.size() == n);\n  for\
    \ (const auto &[i, j, val]: dat) ret[i]+= val * vec[j];\n  return ret;\n }\n auto\
    \ begin() { return dat.begin(); }\n auto end() { return dat.end(); }\n std::size_t\
    \ size() const { return n; }\n mod_t det() const {\n  const std::uint64_t MOD=\
    \ mod_t::mod();\n  using MinPoly= MinimalPolynomial<SparseSquareMatrix, std::vector<mod_t>>;\n\
    \  SparseSquareMatrix M(*this);\n  std::vector<mod_t> d(n), b(n);\n  for (auto\
    \ &x: b) x= MinPoly::get_rand(1, MOD - 1);\n  for (auto &x: d) x= MinPoly::get_rand(1,\
    \ MOD - 1);\n  for (auto &[i, j, val]: M) val*= d[j];\n  mod_t ret= MinPoly(M,\
    \ b)[0], tmp= 1;\n  for (const auto &x: d) tmp*= x;\n  if (n & 1) ret= -ret;\n\
    \  return ret / tmp;\n }\nprivate:\n std::size_t n;\n std::vector<std::tuple<std::size_t,\
    \ std::size_t, mod_t>> dat;\n};\n"
  dependsOn:
  - src/LinearAlgebra/MinimalPolynomial.hpp
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/SparseSquareMatrix.hpp
  requiredBy: []
  timestamp: '2023-01-23 16:45:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
documentation_of: src/LinearAlgebra/SparseSquareMatrix.hpp
layout: document
title: "\u758E\u884C\u5217"
---
## 計算量
$\mathcal{O} (N^2+N \cdot T(N))$ \
$T(N)$: 行列とベクトルの乗算にかかる時間
## 参考
[https://yukicoder.me/wiki/black_box_linear_algebra](https://yukicoder.me/wiki/black_box_linear_algebra)