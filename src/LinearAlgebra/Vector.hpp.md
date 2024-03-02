---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/LinearAlgebra/LU_Decomposition.hpp
    title: "LU\u5206\u89E3"
  - icon: ':question:'
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':x:'
    path: src/LinearAlgebra/characteristic_polynomial.hpp
    title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F \u4ED6"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.MinPoly.test.cpp
    title: test/aoj/2397.MinPoly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.test.cpp
    title: test/aoj/2397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc236_g.test.cpp
    title: test/atcoder/abc236_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc323_g.test.cpp
    title: test/atcoder/abc323_g.test.cpp
  - icon: ':x:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':x:'
    path: test/yosupo/inverse_matrix.test.cpp
    title: test/yosupo/inverse_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/linear_equations.test.cpp
    title: test/yosupo/linear_equations.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_det_arbitrary_mod.test.cpp
    title: test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':x:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.MinPoly.test.cpp
    title: test/yukicoder/1750.MinPoly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  - icon: ':x:'
    path: test/yukicoder/650.LCT.test.cpp
    title: test/yukicoder/650.LCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  - icon: ':x:'
    path: test/yukicoder/950.test.cpp
    title: test/yukicoder/950.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <cstdint>\n#include\
    \ <iostream>\n#include <valarray>\nnamespace _la_internal {\nusing namespace std;\n\
    template <class R> struct Vector: public valarray<R> {\n using valarray<R>::valarray;\n\
    \ friend ostream &operator<<(ostream &os, const Vector &v) {\n  os << '[';\n \
    \ for (int _= 0, __= v.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << v[_];\n\
    \  return os << ']';\n }\n};\nusing u128= __uint128_t;\nusing u8= uint8_t;\nclass\
    \ Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128 *r, u8 j, bool v):\
    \ ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >> i) & 1)) *ref^= u128(1)\
    \ << i;\n }\n Ref &operator=(const Ref &r) { return val= r.val, *this; }\n Ref\
    \ &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool b) { return\
    \ val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this; }\n Ref\
    \ &operator^=(bool b) { return val^= b, *this; }\n operator bool() const { return\
    \ val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n valarray<u128> dat;\n\
    public:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >> 7) {}\n\
    \ Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref operator[](int\
    \ i) {\n  u128 *ref= begin(dat) + (i >> 7);\n  u8 j= i & 127;\n  bool val= (*ref\
    \ >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int i) const {\
    \ return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const Vector &r)\
    \ { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector &r) { return\
    \ dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b) dat= 0;\n  return\
    \ *this;\n }\n Vector operator+(const Vector &r) const { return Vector(*this)+=\
    \ r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-= r; }\n\
    \ Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t size()\
    \ const { return n; }\n u128 *data() { return begin(dat); }\n friend Vector operator*(bool\
    \ b, const Vector &r) { return r * b; }\n friend ostream &operator<<(ostream &os,\
    \ const Vector &v) {\n  os << '[';\n  for (int _= 0, __= v.size(); _ < __; ++_)\
    \ os << (_ ? \", \" : \"\") << v[_];\n  return os << ']';\n }\n};\n}\nusing _la_internal::Vector;\n"
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\n#include <valarray>\n\
    namespace _la_internal {\nusing namespace std;\ntemplate <class R> struct Vector:\
    \ public valarray<R> {\n using valarray<R>::valarray;\n friend ostream &operator<<(ostream\
    \ &os, const Vector &v) {\n  os << '[';\n  for (int _= 0, __= v.size(); _ < __;\
    \ ++_) os << (_ ? \", \" : \"\") << v[_];\n  return os << ']';\n }\n};\nusing\
    \ u128= __uint128_t;\nusing u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8 i;\n bool\
    \ val;\npublic:\n Ref(u128 *r, u8 j, bool v): ref(r), i(j), val(v) {}\n ~Ref()\
    \ {\n  if (val ^ ((*ref >> i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const\
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
    \ * b; }\n friend ostream &operator<<(ostream &os, const Vector &v) {\n  os <<\
    \ '[';\n  for (int _= 0, __= v.size(); _ < __; ++_) os << (_ ? \", \" : \"\")\
    \ << v[_];\n  return os << ']';\n }\n};\n}\nusing _la_internal::Vector;"
  dependsOn: []
  isVerificationFile: false
  path: src/LinearAlgebra/Vector.hpp
  requiredBy:
  - src/LinearAlgebra/LU_Decomposition.hpp
  - src/LinearAlgebra/MinimalPolynomial.hpp
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/characteristic_polynomial.hpp
  timestamp: '2024-03-03 04:26:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1340.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1750.test.cpp
  - test/yukicoder/950.test.cpp
  - test/yukicoder/1750.MinPoly.test.cpp
  - test/yukicoder/184.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/650.LCT.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
  - test/yukicoder/310.test.cpp
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/yosupo/linear_equations.test.cpp
  - test/yosupo/matrix_det_arbitrary_mod.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/matrix_product.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2397.test.cpp
  - test/aoj/2397.MinPoly.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/2624.test.cpp
  - test/atcoder/abc236_g.test.cpp
  - test/atcoder/abc323_g.test.cpp
documentation_of: src/LinearAlgebra/Vector.hpp
layout: document
title: "\u30D9\u30AF\u30C8\u30EB"
---

ほとんど [`std::valarray`](https://cpprefjp.github.io/reference/valarray/valarray.html). \
`bool` は特殊化して有限体 $\mathbb{F}_2$ の意味で用いる.