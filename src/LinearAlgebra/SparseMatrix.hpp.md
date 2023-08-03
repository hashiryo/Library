---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/SparseMatrix.hpp\"\n#include <vector>\n\
    #include <tuple>\n#include <cassert>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\
    \n#include <valarray>\nnamespace la_internal {\nusing namespace std;\ntemplate\
    \ <class R> struct Vector: public valarray<R> {\n using valarray<R>::valarray;\n\
    };\nusing u128= __uint128_t;\nusing u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8\
    \ i;\n bool val;\npublic:\n Ref(u128 *r, u8 j, bool v): ref(r), i(j), val(v) {}\n\
    \ ~Ref() {\n  if (val ^ ((*ref >> i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const\
    \ Ref &r) { return val= r.val, *this; }\n Ref &operator=(bool b) { return val=\
    \ b, *this; }\n Ref &operator|=(bool b) { return val|= b, *this; }\n Ref &operator&=(bool\
    \ b) { return val&= b, *this; }\n Ref &operator^=(bool b) { return val^= b, *this;\
    \ }\n operator bool() const { return val; }\n};\ntemplate <> class Vector<bool>\
    \ {\n size_t n;\n valarray<u128> dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t\
    \ n): n(n), dat((n + 127) >> 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b),\
    \ (n + 127) >> 7) {}\n Ref operator[](int i) {\n  u128 *ref= begin(dat) + (i >>\
    \ 7);\n  u8 j= i & 127;\n  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n\
    \ }\n bool operator[](int i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n\
    \ Vector &operator+=(const Vector &r) { return dat^= r.dat, *this; }\n Vector\
    \ &operator-=(const Vector &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool\
    \ b) {\n  if (!b) dat= 0;\n  return *this;\n }\n Vector operator+(const Vector\
    \ &r) const { return Vector(*this)+= r; }\n Vector operator-(const Vector &r)\
    \ const { return Vector(*this)-= r; }\n Vector operator*(bool b) const { return\
    \ Vector(*this)*= b; }\n size_t size() const { return n; }\n u128 *data() { return\
    \ begin(dat); }\n friend Vector operator*(bool b, const Vector &r) { return r\
    \ * b; }\n};\ntemplate <class R> struct DiagonalMatrix: public Vector<R> {\n using\
    \ Vector<R>::Vector;\n R det() const {\n  R ret(true);\n  for (auto x: *this)\
    \ ret*= x;\n  return ret;\n }\n};\n}\nusing la_internal::Vector, la_internal::DiagonalMatrix;\n\
    #line 6 \"src/LinearAlgebra/SparseMatrix.hpp\"\ntemplate <class R> class SparseMatrix\
    \ {\n std::vector<std::tuple<size_t, size_t, R>> dat;\n size_t H, W;\npublic:\n\
    \ SparseMatrix(size_t h, size_t w): H(h), W(w) {}\n size_t width() const { return\
    \ W; }\n size_t height() const { return H; }\n void add_component(size_t i, size_t\
    \ j, R v) { dat.emplace_back(i, j, v); }\n Vector<R> operator*(const Vector<R>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<R> ret(H);\n  for (auto [i,\
    \ j, v]: dat) ret[i]+= v * r[j];\n  return ret;\n }\n SparseMatrix &operator*=(const\
    \ DiagonalMatrix<R> &r) {\n  assert(W == r.size());\n  for (auto &[i, j, v]: dat)\
    \ v*= r[j];\n  return *this;\n }\n SparseMatrix operator*(const DiagonalMatrix<R>\
    \ &r) const { return SparseMatrix(*this)*= r; }\n friend SparseMatrix operator*(const\
    \ DiagonalMatrix<R> &l, SparseMatrix r) {\n  assert(r.H == l.size());\n  for (auto\
    \ &[i, j, v]: r.dat) v*= l[i];\n  return r;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <cassert>\n#include\
    \ \"src/LinearAlgebra/Vector.hpp\"\ntemplate <class R> class SparseMatrix {\n\
    \ std::vector<std::tuple<size_t, size_t, R>> dat;\n size_t H, W;\npublic:\n SparseMatrix(size_t\
    \ h, size_t w): H(h), W(w) {}\n size_t width() const { return W; }\n size_t height()\
    \ const { return H; }\n void add_component(size_t i, size_t j, R v) { dat.emplace_back(i,\
    \ j, v); }\n Vector<R> operator*(const Vector<R> &r) const {\n  assert(W == r.size());\n\
    \  Vector<R> ret(H);\n  for (auto [i, j, v]: dat) ret[i]+= v * r[j];\n  return\
    \ ret;\n }\n SparseMatrix &operator*=(const DiagonalMatrix<R> &r) {\n  assert(W\
    \ == r.size());\n  for (auto &[i, j, v]: dat) v*= r[j];\n  return *this;\n }\n\
    \ SparseMatrix operator*(const DiagonalMatrix<R> &r) const { return SparseMatrix(*this)*=\
    \ r; }\n friend SparseMatrix operator*(const DiagonalMatrix<R> &l, SparseMatrix\
    \ r) {\n  assert(r.H == l.size());\n  for (auto &[i, j, v]: r.dat) v*= l[i];\n\
    \  return r;\n }\n};"
  dependsOn:
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/SparseMatrix.hpp
  requiredBy: []
  timestamp: '2023-08-03 22:39:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
documentation_of: src/LinearAlgebra/SparseMatrix.hpp
layout: document
title: "\u758E\u884C\u5217"
---
半環が乗る. \
`Vector` や `DiagonalMatrix` との乗算をサポート. \
`SparseMatrix` 同士の乗算はできない