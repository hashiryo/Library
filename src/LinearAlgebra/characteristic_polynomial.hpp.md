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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det_arbitrary_mod.test.cpp
    title: test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#line 2 \"src/LinearAlgebra/Matrix.hpp\"\n#include\
    \ <cassert>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <valarray>\nnamespace\
    \ la_internal {\nusing namespace std;\ntemplate <class R> struct Vector: public\
    \ valarray<R> {\n using valarray<R>::valarray;\n};\nusing u128= __uint128_t;\n\
    using u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128\
    \ *r, u8 j, bool v): ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >>\
    \ i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const Ref &r) { return val=\
    \ r.val, *this; }\n Ref &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool\
    \ b) { return val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this;\
    \ }\n Ref &operator^=(bool b) { return val^= b, *this; }\n operator bool() const\
    \ { return val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n valarray<u128>\
    \ dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >>\
    \ 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref\
    \ operator[](int i) {\n  u128 *ref= begin(dat) + (i >> 7);\n  u8 j= i & 127;\n\
    \  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int\
    \ i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const\
    \ Vector &r) { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector\
    \ &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b)\
    \ dat= 0;\n  return *this;\n }\n Vector operator+(const Vector &r) const { return\
    \ Vector(*this)+= r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-=\
    \ r; }\n Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t\
    \ size() const { return n; }\n u128 *data() { return begin(dat); }\n friend Vector\
    \ operator*(bool b, const Vector &r) { return r * b; }\n};\n}\nusing la_internal::Vector;\n\
    #line 5 \"src/LinearAlgebra/Matrix.hpp\"\nnamespace la_internal {\ntemplate <class\
    \ R> class Matrix {\npublic:\n size_t W;\n valarray<R> dat;\npublic:\n static\
    \ Matrix identity_matrix(int n) {\n  Matrix ret(n, n);\n  return ret.dat[slice(0,\
    \ n, n + 1)]= R(true), ret;\n }\n Matrix(): W(0) {}\n Matrix(size_t h, size_t\
    \ w, R v= R()): W(w), dat(v, h * w) {}\n size_t width() const { return W; }\n\
    \ size_t height() const { return W ? dat.size() / W : 0; }\n explicit operator\
    \ bool() const { return W; }\n auto operator[](int i) { return next(begin(dat),\
    \ i * W); }\n auto operator[](int i) const { return next(begin(dat), i * W); }\n\
    \ Matrix submatrix(const vector<int> &rows, const vector<int> &cols) const {\n\
    \  Matrix ret(rows.size(), cols.size());\n  for (int i= rows.size(); i--;)\n \
    \  for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n  return\
    \ ret;\n }\n bool operator==(const Matrix &r) const {\n  if (W != r.W || dat.size()\
    \ != r.dat.size()) return false;\n  for (int i= dat.size(); i--;)\n   if (dat[i]\
    \ != r.dat[i]) return false;\n  return true;\n }\n bool operator!=(const Matrix\
    \ &r) const { return !(*this == r); }\n Matrix &operator+=(const Matrix &r) {\
    \ return assert(dat.size() == r.dat.size()), assert(W == r.W), dat+= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  const size_t h= height(), w= r.W,\
    \ l= W;\n  assert(l == r.height());\n  Matrix ret(h, w);\n  auto a= begin(dat);\n\
    \  auto c= begin(ret.dat);\n  for (int i= h; i--; advance(c, w)) {\n   auto b=\
    \ begin(r.dat);\n   for (int k= l; k--; ++a) {\n    auto d= c;\n    auto v= *a;\n\
    \    for (int j= w; j--; ++b, ++d) *d+= v * *b;\n   }\n  }\n  return ret;\n }\n\
    \ Matrix &operator*=(const Matrix &r) { return *this= *this * r; }\n Matrix &operator*=(R\
    \ r) { return dat*= r, *this; }\n Matrix operator*(R r) const { return Matrix(*this)*=\
    \ r; }\n Vector<R> operator*(const Vector<R> &r) const {\n  assert(W == r.size());\n\
    \  const size_t h= height();\n  Vector<R> ret(h);\n  auto a= begin(dat);\n  for\
    \ (int i= 0; i < h; ++i)\n   for (int k= 0; k < W; ++k, ++a) ret[i]+= *a * r[k];\n\
    \  return ret;\n }\n Vector<R> operator()(const Vector<R> &r) const { return *this\
    \ * r; }\n Matrix pow(uint64_t k) const {\n  assert(W * W == dat.size());\n  for\
    \ (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ? ret*= b, !(k>>=\
    \ 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <> class Matrix<bool> {\n size_t\
    \ H, W, m;\n valarray<u128> dat;\n class Array {\n  u128 *bg;\n public:\n  Array(u128\
    \ *it): bg(it) {}\n  u128 *data() const { return bg; }\n  Ref operator[](int i)\
    \ {\n   u128 *ref= bg + (i >> 7);\n   u8 j= i & 127;\n   bool val= (*ref >> j)\
    \ & 1;\n   return Ref{ref, j, val};\n  }\n  bool operator[](int i) const { return\
    \ (bg[i >> 7] >> (i & 127)) & 1; }\n };\n class ConstArray {\n  const u128 *bg;\n\
    \ public:\n  ConstArray(const u128 *it): bg(it) {}\n  const u128 *data() const\
    \ { return bg; }\n  bool operator[](int i) const { return (bg[i >> 7] >> (i &\
    \ 127)) & 1; }\n };\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix\
    \ ret(n, n);\n  for (; n--;) ret[n][n]= 1;\n  return ret;\n }\n Matrix(): H(0),\
    \ W(0), m(0) {}\n Matrix(size_t h, size_t w): H(h), W(w), m((w + 127) >> 7), dat(u128(0),\
    \ h * m) {}\n size_t width() const { return W; }\n size_t height() const { return\
    \ H; }\n explicit operator bool() const { return W; }\n Array operator[](int i)\
    \ { return {next(begin(dat), i * m)}; }\n ConstArray operator[](int i) const {\
    \ return {next(begin(dat), i * m)}; }\n ConstArray get(int i) const { return {next(begin(dat),\
    \ i * m)}; }\n Matrix submatrix(const std::vector<int> &rows, const std::vector<int>\
    \ &cols) const {\n  Matrix ret(rows.size(), cols.size());\n  for (int i= rows.size();\
    \ i--;)\n   for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n\
    \  return ret;\n }\n bool operator==(const Matrix &r) const { return W == r.W\
    \ && H == r.H && (dat == r.dat).min(); }\n bool operator!=(const Matrix &r) const\
    \ { return W != r.W || H != r.H || (dat != r.dat).max(); }\n Matrix &operator+=(const\
    \ Matrix &r) { return assert(H == r.H), assert(W == r.W), dat^= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  assert(W == r.H);\n  Matrix ret(H,\
    \ r.W);\n  u128 *c= begin(ret.dat);\n  for (size_t i= 0; i < H; ++i, advance(c,\
    \ m)) {\n   ConstArray a= this->operator[](i);\n   const u128 *b= begin(r.dat);\n\
    \   for (size_t k= 0; k < W; ++k, advance(b, r.m))\n    if (a[k])\n     for (size_t\
    \ j= 0; j < r.m; ++j) c[j]^= b[j];\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Vector<bool> operator*(const Vector<bool>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<bool> ret(H);\n  auto a= begin(dat);\n\
    \  for (size_t i= 0; i < H; ++i)\n   for (size_t j= 0; j < m; ++j, ++a) ret[i]^=\
    \ *a & r[j];\n  return ret;\n }\n Vector<bool> operator()(const Vector<bool> &r)\
    \ const { return *this * r; }\n Matrix pow(uint64_t k) const {\n  assert(W ==\
    \ H);\n  for (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ?\
    \ ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <class K> static\
    \ bool is_zero(K x) {\n if constexpr (is_floating_point_v<K>) return abs(x) <\
    \ 1e-8;\n else return x == K();\n}\n}\nusing la_internal::Matrix;\n#line 5 \"\
    src/LinearAlgebra/characteristic_polynomial.hpp\"\ntemplate <class K> Matrix<K>\
    \ hessenberg(Matrix<K> A, bool mint= false) {\n using la_internal::is_zero;\n\
    \ const size_t n= A.width();\n assert(n == A.height());\n for (size_t j= 0, i,\
    \ r; j + 2 < n; ++j) {\n  if constexpr (std::is_floating_point_v<K>) {\n   for\
    \ (i= j + 1, r= j + 2; r < n; ++r)\n    if (std::abs(A[i][j]) < std::abs(A[r][j]))\
    \ i= r;\n  } else\n   for (i= r= j + 1; r < n; ++r)\n    if (A[r][j] != K()) i=\
    \ r, r= n;\n  if (i != j + 1) {\n   for (r= 0; r < n; ++r) std::swap(A[j + 1][r],\
    \ A[i][r]);\n   for (; r--;) std::swap(A[r][j + 1], A[r][i]);\n  }\n  if (is_zero(A[j\
    \ + 1][j])) continue;\n  if (K s, iv; mint) {\n   for (i= j + 2; i < n; ++i)\n\
    \    if (!is_zero(A[i][j])) {\n     K m00= K(1), m01= K(), m10= K(), m11= K(1);\n\
    \     for (uint64_t a= A[j + 1][j].val(), b= A[i][j].val(), t, l; b;) l= b, b=\
    \ a - (t= a / b) * b, a= l, s= m10, m10= m00 - m10 * t, m00= s, s= m11, m11= m01\
    \ - m11 * t, m01= s;\n     for (r= 0; r < n; ++r) s= m00 * A[j + 1][r] + m01 *\
    \ A[i][r], A[i][r]= m10 * A[j + 1][r] + m11 * A[i][r], A[j + 1][r]= s;\n     for\
    \ (; r--;) s= m11 * A[r][j + 1] - m10 * A[r][i], A[r][i]= m00 * A[r][i] - m01\
    \ * A[r][j + 1], A[r][j + 1]= s;\n    }\n  } else {\n   for (iv= K(1) / A[j +\
    \ 1][j], i= j + 2; i < n; ++i)\n    if (!is_zero(A[i][j])) {\n     for (s= A[i][r=\
    \ j] * iv; r < n; ++r) A[i][r]-= s * A[j + 1][r];\n     for (; r--;) A[r][j +\
    \ 1]+= s * A[r][i];\n    }\n  }\n }\n return A;\n}\ntemplate <class K> std::vector<K>\
    \ characteristic_polynomial(const Matrix<K> &A, bool mint= false) {\n size_t n=\
    \ A.width(), i= 0, k, j;\n assert(n == A.height());\n auto b= hessenberg(A, mint);\n\
    \ std::vector<K> fss((n + 1) * (n + 2) / 2);\n K *pr= fss.data(), *nx= pr, prod,\
    \ tmp, s;\n for (fss[0]= 1; i < n; ++i, pr= nx) {\n  for (prod= 1, tmp= -b[i][i],\
    \ nx= pr + i + 1, std::copy_n(pr, i + 1, nx + 1), k= 0; k <= i; ++k) nx[k]+= tmp\
    \ * pr[k];\n  for (j= i; j--;)\n   for (pr-= j + 1, s= (prod*= b[j + 1][j]) *\
    \ -b[j][i], k= 0; k <= j; ++k) nx[k]+= s * pr[k];\n }\n return std::vector<K>(fss.begin()\
    \ + n * (n + 1) / 2, fss.end());\n}\ntemplate <class K> std::vector<K> det_of_first_degree_poly_mat(Matrix<K>\
    \ M0, Matrix<K> M1) {\n const size_t n= M0.height();\n assert(n == M1.height()),\
    \ assert(n == M0.width()), assert(n == M1.width());\n size_t cnt= 0;\n K det=\
    \ 1, v, iv;\n for (size_t p= 0, piv, r, i; p < n;) {\n  if constexpr (std::is_floating_point_v<K>)\
    \ {\n   for (piv= p, r= p + 1; r < n; ++r)\n    if (std::abs(M1[piv][p]) < std::abs(M1[r][p]))\
    \ piv= r;\n  } else\n   for (piv= p; piv < n; ++piv)\n    if (M1[piv][p] != K())\
    \ break;\n  if (piv == n || la_internal::is_zero(M1[piv][p])) {\n   if (++cnt\
    \ > n) return std::vector<K>(n + 1);\n   for (r= p; r--;)\n    for (v= M1[r][p],\
    \ M1[r][p]= K(), i= n; i--;) M0[i][p]-= v * M0[i][r];\n   for (i= n; i--;) std::swap(M0[i][p],\
    \ M1[i][p]);\n   continue;\n  }\n  if (piv != p) {\n   for (det*= -1, i= 0; i\
    \ < n; ++i) std::swap(M0[p][i], M0[piv][i]);\n   for (; i--;) std::swap(M1[p][i],\
    \ M1[piv][i]);\n  }\n  for (det*= v= M1[p][p], iv= K(1) / v, i= 0; i < n; ++i)\
    \ M0[p][i]*= iv;\n  for (; i--;) M1[p][i]*= iv;\n  for (r= n; r--;)\n   if (r\
    \ != p) {\n    for (v= M1[r][p], i= 0; i < n; ++i) M0[r][i]-= v * M0[p][i];\n\
    \    for (; i--;) M1[r][i]-= v * M1[p][i];\n   }\n  ++p;\n }\n auto poly= characteristic_polynomial(M0\
    \ * -1);\n poly.erase(poly.begin(), poly.begin() + cnt);\n for (auto &x: poly)\
    \ x*= det;\n return poly.resize(n + 1), poly;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"src/LinearAlgebra/Matrix.hpp\"\
    \ntemplate <class K> Matrix<K> hessenberg(Matrix<K> A, bool mint= false) {\n using\
    \ la_internal::is_zero;\n const size_t n= A.width();\n assert(n == A.height());\n\
    \ for (size_t j= 0, i, r; j + 2 < n; ++j) {\n  if constexpr (std::is_floating_point_v<K>)\
    \ {\n   for (i= j + 1, r= j + 2; r < n; ++r)\n    if (std::abs(A[i][j]) < std::abs(A[r][j]))\
    \ i= r;\n  } else\n   for (i= r= j + 1; r < n; ++r)\n    if (A[r][j] != K()) i=\
    \ r, r= n;\n  if (i != j + 1) {\n   for (r= 0; r < n; ++r) std::swap(A[j + 1][r],\
    \ A[i][r]);\n   for (; r--;) std::swap(A[r][j + 1], A[r][i]);\n  }\n  if (is_zero(A[j\
    \ + 1][j])) continue;\n  if (K s, iv; mint) {\n   for (i= j + 2; i < n; ++i)\n\
    \    if (!is_zero(A[i][j])) {\n     K m00= K(1), m01= K(), m10= K(), m11= K(1);\n\
    \     for (uint64_t a= A[j + 1][j].val(), b= A[i][j].val(), t, l; b;) l= b, b=\
    \ a - (t= a / b) * b, a= l, s= m10, m10= m00 - m10 * t, m00= s, s= m11, m11= m01\
    \ - m11 * t, m01= s;\n     for (r= 0; r < n; ++r) s= m00 * A[j + 1][r] + m01 *\
    \ A[i][r], A[i][r]= m10 * A[j + 1][r] + m11 * A[i][r], A[j + 1][r]= s;\n     for\
    \ (; r--;) s= m11 * A[r][j + 1] - m10 * A[r][i], A[r][i]= m00 * A[r][i] - m01\
    \ * A[r][j + 1], A[r][j + 1]= s;\n    }\n  } else {\n   for (iv= K(1) / A[j +\
    \ 1][j], i= j + 2; i < n; ++i)\n    if (!is_zero(A[i][j])) {\n     for (s= A[i][r=\
    \ j] * iv; r < n; ++r) A[i][r]-= s * A[j + 1][r];\n     for (; r--;) A[r][j +\
    \ 1]+= s * A[r][i];\n    }\n  }\n }\n return A;\n}\ntemplate <class K> std::vector<K>\
    \ characteristic_polynomial(const Matrix<K> &A, bool mint= false) {\n size_t n=\
    \ A.width(), i= 0, k, j;\n assert(n == A.height());\n auto b= hessenberg(A, mint);\n\
    \ std::vector<K> fss((n + 1) * (n + 2) / 2);\n K *pr= fss.data(), *nx= pr, prod,\
    \ tmp, s;\n for (fss[0]= 1; i < n; ++i, pr= nx) {\n  for (prod= 1, tmp= -b[i][i],\
    \ nx= pr + i + 1, std::copy_n(pr, i + 1, nx + 1), k= 0; k <= i; ++k) nx[k]+= tmp\
    \ * pr[k];\n  for (j= i; j--;)\n   for (pr-= j + 1, s= (prod*= b[j + 1][j]) *\
    \ -b[j][i], k= 0; k <= j; ++k) nx[k]+= s * pr[k];\n }\n return std::vector<K>(fss.begin()\
    \ + n * (n + 1) / 2, fss.end());\n}\ntemplate <class K> std::vector<K> det_of_first_degree_poly_mat(Matrix<K>\
    \ M0, Matrix<K> M1) {\n const size_t n= M0.height();\n assert(n == M1.height()),\
    \ assert(n == M0.width()), assert(n == M1.width());\n size_t cnt= 0;\n K det=\
    \ 1, v, iv;\n for (size_t p= 0, piv, r, i; p < n;) {\n  if constexpr (std::is_floating_point_v<K>)\
    \ {\n   for (piv= p, r= p + 1; r < n; ++r)\n    if (std::abs(M1[piv][p]) < std::abs(M1[r][p]))\
    \ piv= r;\n  } else\n   for (piv= p; piv < n; ++piv)\n    if (M1[piv][p] != K())\
    \ break;\n  if (piv == n || la_internal::is_zero(M1[piv][p])) {\n   if (++cnt\
    \ > n) return std::vector<K>(n + 1);\n   for (r= p; r--;)\n    for (v= M1[r][p],\
    \ M1[r][p]= K(), i= n; i--;) M0[i][p]-= v * M0[i][r];\n   for (i= n; i--;) std::swap(M0[i][p],\
    \ M1[i][p]);\n   continue;\n  }\n  if (piv != p) {\n   for (det*= -1, i= 0; i\
    \ < n; ++i) std::swap(M0[p][i], M0[piv][i]);\n   for (; i--;) std::swap(M1[p][i],\
    \ M1[piv][i]);\n  }\n  for (det*= v= M1[p][p], iv= K(1) / v, i= 0; i < n; ++i)\
    \ M0[p][i]*= iv;\n  for (; i--;) M1[p][i]*= iv;\n  for (r= n; r--;)\n   if (r\
    \ != p) {\n    for (v= M1[r][p], i= 0; i < n; ++i) M0[r][i]-= v * M0[p][i];\n\
    \    for (; i--;) M1[r][i]-= v * M1[p][i];\n   }\n  ++p;\n }\n auto poly= characteristic_polynomial(M0\
    \ * -1);\n poly.erase(poly.begin(), poly.begin() + cnt);\n for (auto &x: poly)\
    \ x*= det;\n return poly.resize(n + 1), poly;\n}"
  dependsOn:
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2023-09-11 13:10:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/1303.test.cpp
documentation_of: src/LinearAlgebra/characteristic_polynomial.hpp
layout: document
title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F \u4ED6"
---



| 関数                           | 概要                                                                                 | 計算量              |
| ------------------------------ | ------------------------------------------------------------------------------------ | ------------------- |
| `hessenberg(A, mint=false)`                | 正方行列 $A$ ( `Matrix` クラス ) のヘッセンベルグ型を返す. <br> 第二引数 が `true`  : 互除法で計算. modintを前提にしてる. <br> 第二引数 が `false` : 乗法の逆元で計算. 体でないとダメ. デフォルト               | $\mathcal{O} (n^3)$ |
| `characteristic_polynomial(A, mint=false)` | 正方行列 $A$ ( `Matrix` クラス ) の特性多項式 $\phi(x)=\det(x \mathrm{I}-A)$ を返す. <br> 第二引数 が `true`  : 互除法で計算. modintを前提にしてる. <br> 第二引数 が `false` : 乗法の逆元で計算. 体でないとダメ. デフォルト | $\mathcal{O} (n^3)$ |
|`det_of_first_degree_poly_mat(M0, M1)` |$\det(M_0 + M_1x)$ を計算. <br>  体でないとダメ.|$\mathcal{O} (n^3)$|


## 参考
[https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/hessenberg_reduction.hpp](https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/hessenberg_reduction.hpp)\
[https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/determinant_of_first_degree_poly_mat.hpp](https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/determinant_of_first_degree_poly_mat.hpp)

## 問題例
[Codeforces Round 459 (Div. 1) D. Stranger Trees](https://codeforces.com/contest/917/problem/D) (`det_of_first_degree_poly_mat`)