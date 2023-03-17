---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#line 2 \"src/LinearAlgebra/Matrix.hpp\"\n#include\
    \ <cassert>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <valarray>\nnamespace\
    \ la_internal {\ntemplate <class R> struct Vector: public std::valarray<R> {\n\
    \ using std::valarray<R>::valarray;\n};\nusing u128= __uint128_t;\nusing u8= uint8_t;\n\
    class Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128 *r, u8 j, bool\
    \ v): ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >> i) & 1)) *ref^=\
    \ u128(1) << i;\n }\n Ref &operator=(const Ref &r) { return val= r.val, *this;\
    \ }\n Ref &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool\
    \ b) { return val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this;\
    \ }\n Ref &operator^=(bool b) { return val^= b, *this; }\n operator bool() const\
    \ { return val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n std::valarray<u128>\
    \ dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >>\
    \ 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref\
    \ operator[](int i) {\n  u128 *ref= std::begin(dat) + (i >> 7);\n  u8 j= i & 127;\n\
    \  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int\
    \ i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const\
    \ Vector &r) { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector\
    \ &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b)\
    \ dat= 0;\n  return *this;\n }\n Vector operator+(const Vector &r) const { return\
    \ Vector(*this)+= r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-=\
    \ r; }\n Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t\
    \ size() const { return n; }\n u128 *data() { return std::begin(dat); }\n friend\
    \ Vector operator*(bool b, const Vector &r) { return r * b; }\n};\ntemplate <class\
    \ R> struct DiagonalMatrix: public Vector<R> {\n using Vector<R>::Vector;\n R\
    \ det() const {\n  R ret(true);\n  for (auto x: *this) ret*= x;\n  return ret;\n\
    \ }\n};\n}\nusing la_internal::Vector, la_internal::DiagonalMatrix;\n#line 4 \"\
    src/LinearAlgebra/Matrix.hpp\"\nnamespace la_internal {\ntemplate <class R> class\
    \ Matrix {\npublic:\n size_t W;\n std::valarray<R> dat;\npublic:\n static Matrix\
    \ identity_matrix(int n) {\n  Matrix ret(n, n);\n  return ret.dat[std::slice(0,\
    \ n, n + 1)]= R(true), ret;\n }\n Matrix(): W(0) {}\n Matrix(size_t h, size_t\
    \ w, R v= R()): W(w), dat(v, h * w) {}\n size_t width() const { return W; }\n\
    \ size_t height() const { return W ? dat.size() / W : 0; }\n operator bool() const\
    \ { return W; }\n auto operator[](int i) { return std::next(std::begin(dat), i\
    \ * W); }\n auto operator[](int i) const { return std::next(std::cbegin(dat),\
    \ i * W); }\n Matrix &operator+=(const Matrix &r) { return assert(dat.size() ==\
    \ r.dat.size()), assert(W == r.W), dat+= r.dat, *this; }\n Matrix operator+(const\
    \ Matrix &r) const { return Matrix(*this)+= r; }\n Matrix operator*(const Matrix\
    \ &r) const {\n  const size_t h= height(), w= r.W, l= W;\n  assert(l == r.height());\n\
    \  Matrix ret(h, w);\n  auto a= std::cbegin(dat);\n  auto c= std::begin(ret.dat);\n\
    \  for (int i= h; i--; std::advance(c, w)) {\n   auto b= std::cbegin(r.dat);\n\
    \   for (int k= l; k--; ++a) {\n    auto d= c;\n    auto v= *a;\n    for (int\
    \ j= w; j--; ++b, ++d) *d+= v * *b;\n   }\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Matrix &operator*=(const DiagonalMatrix<R>\
    \ &r) {\n  assert(W == r.size());\n  const size_t h= height();\n  auto a= std::begin(dat);\n\
    \  for (int i= 0; i < h; ++i)\n   for (int j= 0; j < W; ++j, ++a) *a*= r[j];\n\
    \  return *this;\n }\n Matrix operator*(const DiagonalMatrix<R> &r) const { return\
    \ Matrix(*this)*= r; }\n friend Matrix operator*(const DiagonalMatrix<R> &l, Matrix\
    \ r) {\n  const size_t h= r.height();\n  assert(h == l.size());\n  auto a= std::begin(r.dat);\n\
    \  for (int i= 0; i < h; ++i) {\n   auto v= l[i];\n   for (int j= 0; j < r.W;\
    \ ++j, ++a) *a*= v;\n  }\n  return r;\n }\n Vector<R> operator*(const Vector<R>\
    \ &r) const {\n  assert(W == r.size());\n  const size_t h= height();\n  Vector<R>\
    \ ret(h);\n  auto a= std::cbegin(dat);\n  for (int i= 0; i < h; ++i)\n   for (int\
    \ k= 0; k < W; ++k, ++a) ret[i]+= *a * r[k];\n  return ret;\n }\n Matrix pow(uint64_t\
    \ k) const {\n  assert(W * W == dat.size());\n  for (auto ret= identity_matrix(W),\
    \ b= *this;; b*= b)\n   if (k & 1 ? ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n\
    \ }\n};\ntemplate <> class Matrix<bool> {\n size_t H, W, m;\n std::valarray<u128>\
    \ dat;\n class Array {\n  u128 *bg;\n public:\n  Array(u128 *it): bg(it) {}\n\
    \  u128 *data() const { return bg; }\n  Ref operator[](int i) {\n   u128 *ref=\
    \ bg + (i >> 7);\n   u8 j= i & 127;\n   bool val= (*ref >> j) & 1;\n   return\
    \ Ref{ref, j, val};\n  }\n  bool operator[](int i) const { return (bg[i >> 7]\
    \ >> (i & 127)) & 1; }\n };\n class ConstArray {\n  const u128 *bg;\n public:\n\
    \  ConstArray(const u128 *it): bg(it) {}\n  const u128 *data() const { return\
    \ bg; }\n  bool operator[](int i) const { return (bg[i >> 7] >> (i & 127)) & 1;\
    \ }\n };\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix ret(n, n);\n\
    \  for (; n--;) ret[n][n]= 1;\n  return ret;\n }\n Matrix(): H(0), W(0), m(0)\
    \ {}\n Matrix(size_t h, size_t w, bool b= 0): H(h), W(w), m((w + 127) >> 7), dat(-u128(b),\
    \ h * m) {}\n size_t width() const { return W; }\n size_t height() const { return\
    \ H; }\n operator bool() const { return W; }\n Array operator[](int i) { return\
    \ {std::next(std::begin(dat), i * m)}; }\n ConstArray operator[](int i) const\
    \ { return {std::next(std::cbegin(dat), i * m)}; }\n ConstArray get(int i) const\
    \ { return {std::next(std::cbegin(dat), i * m)}; }\n Matrix &operator+=(const\
    \ Matrix &r) { return assert(H == r.H), assert(W == r.W), dat^= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  assert(W == r.H);\n  Matrix ret(H,\
    \ r.W);\n  u128 *c= std::begin(ret.dat);\n  for (size_t i= 0; i < H; ++i, std::advance(c,\
    \ m)) {\n   ConstArray a= this->operator[](i);\n   const u128 *b= std::cbegin(r.dat);\n\
    \   for (size_t k= 0; k < W; ++k, std::advance(b, r.m))\n    if (a[k])\n     for\
    \ (size_t j= 0; j < r.m; ++j) c[j]^= b[j];\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Vector<bool> operator*(const Vector<bool>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<bool> ret(H);\n  auto a= std::cbegin(dat);\n\
    \  for (size_t i= 0; i < H; ++i)\n   for (size_t j= 0; j < m; ++j, ++a) ret[i]^=\
    \ *a & r[j];\n  return ret;\n }\n Matrix pow(uint64_t k) const {\n  assert(W ==\
    \ H);\n  for (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ?\
    \ ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n }\n};\n}\nusing la_internal::Matrix;\n\
    #line 5 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\ntemplate <class K>\
    \ Matrix<K> hessenberg(const Matrix<K> &A) {\n size_t n= A.width();\n assert(n\
    \ == A.height());\n auto ret= A;\n for (size_t j= 0, i; j + 2 < n; ++j) {\n  for\
    \ (i= j + 1; i < n; ++i)\n   if (ret[i][j] != K()) {\n    for (size_t r= n; r--;)\
    \ std::swap(ret[j + 1][r], ret[i][r]);\n    for (size_t r= n; r--;) std::swap(ret[r][j\
    \ + 1], ret[r][i]);\n    break;\n   }\n  if (K iv; ret[j + 1][j] != K())\n   for\
    \ (iv= K(1) / ret[j + 1][j], i= j + 2; i < n; ++i) {\n    K m= ret[i][j] * iv;\n\
    \    for (size_t c= j; c < n; ++c) ret[i][c]-= m * ret[j + 1][c];\n    for (size_t\
    \ r= n; r--;) ret[r][j + 1]+= m * ret[r][i];\n   }\n }\n return ret;\n}\ntemplate\
    \ <class K> std::vector<K> characteristic_polynomial(const Matrix<K> &A) {\n size_t\
    \ n= A.width();\n assert(n == A.height());\n auto b= hessenberg(A);\n std::vector<K>\
    \ fss((n + 1) * (n + 2) / 2);\n K *pr= fss.data(), *nx= pr, prod, tmp, s;\n fss[0]=\
    \ 1;\n for (size_t i= 0; i < n; ++i, pr= nx) {\n  prod= 1, tmp= -b[i][i], nx=\
    \ pr + i + 1, std::copy_n(pr, i + 1, nx + 1);\n  for (size_t k= 0; k <= i; ++k)\
    \ nx[k]+= tmp * pr[k];\n  for (size_t j= i, k; j--;)\n   for (pr-= j + 1, s= (prod*=\
    \ b[j + 1][j]) * -b[j][i], k= 0; k <= j; ++k) nx[k]+= s * pr[k];\n }\n return\
    \ std::vector<K>(fss.begin() + n * (n + 1) / 2, fss.end());\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"src/LinearAlgebra/Matrix.hpp\"\
    \ntemplate <class K> Matrix<K> hessenberg(const Matrix<K> &A) {\n size_t n= A.width();\n\
    \ assert(n == A.height());\n auto ret= A;\n for (size_t j= 0, i; j + 2 < n; ++j)\
    \ {\n  for (i= j + 1; i < n; ++i)\n   if (ret[i][j] != K()) {\n    for (size_t\
    \ r= n; r--;) std::swap(ret[j + 1][r], ret[i][r]);\n    for (size_t r= n; r--;)\
    \ std::swap(ret[r][j + 1], ret[r][i]);\n    break;\n   }\n  if (K iv; ret[j +\
    \ 1][j] != K())\n   for (iv= K(1) / ret[j + 1][j], i= j + 2; i < n; ++i) {\n \
    \   K m= ret[i][j] * iv;\n    for (size_t c= j; c < n; ++c) ret[i][c]-= m * ret[j\
    \ + 1][c];\n    for (size_t r= n; r--;) ret[r][j + 1]+= m * ret[r][i];\n   }\n\
    \ }\n return ret;\n}\ntemplate <class K> std::vector<K> characteristic_polynomial(const\
    \ Matrix<K> &A) {\n size_t n= A.width();\n assert(n == A.height());\n auto b=\
    \ hessenberg(A);\n std::vector<K> fss((n + 1) * (n + 2) / 2);\n K *pr= fss.data(),\
    \ *nx= pr, prod, tmp, s;\n fss[0]= 1;\n for (size_t i= 0; i < n; ++i, pr= nx)\
    \ {\n  prod= 1, tmp= -b[i][i], nx= pr + i + 1, std::copy_n(pr, i + 1, nx + 1);\n\
    \  for (size_t k= 0; k <= i; ++k) nx[k]+= tmp * pr[k];\n  for (size_t j= i, k;\
    \ j--;)\n   for (pr-= j + 1, s= (prod*= b[j + 1][j]) * -b[j][i], k= 0; k <= j;\
    \ ++k) nx[k]+= s * pr[k];\n }\n return std::vector<K>(fss.begin() + n * (n + 1)\
    \ / 2, fss.end());\n}"
  dependsOn:
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2023-03-12 23:00:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: src/LinearAlgebra/characteristic_polynomial.hpp
layout: document
title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F"
---
行列の成分は 体 であること (特に乗法に関する逆元の存在) を前提にしている

| 関数                           | 概要                                                                                 | 計算量              |
| ------------------------------ | ------------------------------------------------------------------------------------ | ------------------- |
| `hessenberg(A)`                | 正方行列 $A$ ( `Matrix` クラス ) のヘッセンベルグ型を返す                            | $\mathcal{O} (n^3)$ |
| `characteristic_polynomial(A)` | 正方行列 $A$ ( `Matrix` クラス ) の特性多項式 $\phi(x)=\det(x \mathrm{I}-A)$ を返す. | $\mathcal{O} (n^3)$ |

