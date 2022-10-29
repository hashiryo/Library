---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.test.cpp
    title: test/aoj/2397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc236_g.test.cpp
    title: test/atcoder/abc236_g.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  - icon: ':x:'
    path: test/yukicoder/650.LCT.test.cpp
    title: test/yukicoder/650.LCT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/Matrix.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u884C\u5217\n * @category \u7DDA\u5F62\u4EE3\u6570\n * \u534A\u74B0\
    \u304C\u8F09\u308B\n */\n\n// BEGIN CUT HERE\n\ntemplate <class R, int N, int\
    \ M>\nstruct Matrix : public std::array<std::array<R, M>, N> {\n  static constexpr\
    \ Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const Matrix &r) {\n \
    \   for (int i = N; i--;)\n      for (int j = M; j--;) (*this)[i][j] += r[i][j];\n\
    \    return *this;\n  }\n  Matrix operator+(const Matrix &r) const { return Matrix(*this)\
    \ += r; }\n  template <int L>\n  Matrix<R, N, L> operator*(const Matrix<R, M,\
    \ L> &r) const {\n    Matrix<R, N, L> ret;\n    for (int i = N; i--;)\n      for\
    \ (int k = M; k--;)\n        for (int j = L; j--;) ret[i][j] += (*this)[i][k]\
    \ * r[k][j];\n    return ret;\n  }\n  std::array<R, N> operator*(const std::array<R,\
    \ M> &r) const {\n    std::array<R, N> ret;\n    for (int i = N; i--;)\n     \
    \ for (int j = M; j--;) ret[i] += (*this)[i][j] * r[j];\n    return ret;\n  }\n\
    \  std::vector<std::vector<R>> to_vec(int n, int m) const {\n    std::vector<std::vector<R>>\
    \ ret(n, std::vector<R>(m));\n    for (int i = n; i--;)\n      for (int j = m;\
    \ j--;) ret[i][j] = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <int\
    \ N, int M>\nstruct Matrix<bool, N, M> : public std::array<std::bitset<M>, N>\
    \ {\n  static constexpr Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const\
    \ Matrix &r) {\n    for (int i = N; i--;) (*this)[i] ^= r[i];\n    return *this;\n\
    \  }\n  Matrix operator+(const Matrix &r) const { return Matrix(*this) += r; }\n\
    \  template <int L>\n  Matrix<bool, N, L> operator*(const Matrix<bool, M, L> &r)\
    \ const {\n    Matrix<bool, L, M> t;\n    Matrix<bool, N, L> ret;\n    for (int\
    \ i = M; i--;)\n      for (int j = L; j--;) t[j][i] = r[i][j];\n    for (int i\
    \ = N; i--;)\n      for (int j = L; j--;) ret[i][j] = ((*this)[i] & t[j]).count()\
    \ & 1;\n    return ret;\n  }\n  std::bitset<N> operator*(const std::bitset<N>\
    \ &r) const {\n    std::bitset<N> ret;\n    for (int i = N; i--;) ret[i] = ((*this)[i]\
    \ & r).count() & 1;\n    return ret;\n  }\n  std::vector<std::vector<bool>> to_vec(int\
    \ n, int m) const {\n    std::vector<std::vector<bool>> ret(n, std::vector<bool>(m));\n\
    \    for (int i = n; i--;)\n      for (int j = m; j--;) ret[i][j] = (*this)[i][j];\n\
    \    return ret;\n  }\n};\n\ntemplate <class R, int N>\nstruct SquareMatrix :\
    \ public Matrix<R, N, N> {\n  using Matrix<R, N, N>::Matrix;\n  SquareMatrix(Matrix<R,\
    \ N, N> m) { *this = m; }\n  static constexpr SquareMatrix I() {\n    SquareMatrix\
    \ ret = {};\n    for (int i = N; i--;) ret[i][i] = R(true);\n    return ret;\n\
    \  }\n  SquareMatrix &operator=(const Matrix<R, N, N> &r) {\n    for (int i =\
    \ N; i--;)\n      for (int j = N; j--;) (*this)[i][j] = r[i][j];\n    return *this;\n\
    \  }\n  SquareMatrix &operator*=(const SquareMatrix &r) {\n    return *this =\
    \ (*this) * r;\n  }\n  SquareMatrix pow(std::uint64_t e) const {\n    for (SquareMatrix\
    \ ret = I(), b = *this;; b *= b)\n      if (e & 1 ? ret *= b, !(e >>= 1) : !(e\
    \ >>= 1)) return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u884C\u5217\n * @category\
    \ \u7DDA\u5F62\u4EE3\u6570\n * \u534A\u74B0\u304C\u8F09\u308B\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <class R, int N, int M>\nstruct Matrix : public std::array<std::array<R,\
    \ M>, N> {\n  static constexpr Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const\
    \ Matrix &r) {\n    for (int i = N; i--;)\n      for (int j = M; j--;) (*this)[i][j]\
    \ += r[i][j];\n    return *this;\n  }\n  Matrix operator+(const Matrix &r) const\
    \ { return Matrix(*this) += r; }\n  template <int L>\n  Matrix<R, N, L> operator*(const\
    \ Matrix<R, M, L> &r) const {\n    Matrix<R, N, L> ret;\n    for (int i = N; i--;)\n\
    \      for (int k = M; k--;)\n        for (int j = L; j--;) ret[i][j] += (*this)[i][k]\
    \ * r[k][j];\n    return ret;\n  }\n  std::array<R, N> operator*(const std::array<R,\
    \ M> &r) const {\n    std::array<R, N> ret;\n    for (int i = N; i--;)\n     \
    \ for (int j = M; j--;) ret[i] += (*this)[i][j] * r[j];\n    return ret;\n  }\n\
    \  std::vector<std::vector<R>> to_vec(int n, int m) const {\n    std::vector<std::vector<R>>\
    \ ret(n, std::vector<R>(m));\n    for (int i = n; i--;)\n      for (int j = m;\
    \ j--;) ret[i][j] = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <int\
    \ N, int M>\nstruct Matrix<bool, N, M> : public std::array<std::bitset<M>, N>\
    \ {\n  static constexpr Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const\
    \ Matrix &r) {\n    for (int i = N; i--;) (*this)[i] ^= r[i];\n    return *this;\n\
    \  }\n  Matrix operator+(const Matrix &r) const { return Matrix(*this) += r; }\n\
    \  template <int L>\n  Matrix<bool, N, L> operator*(const Matrix<bool, M, L> &r)\
    \ const {\n    Matrix<bool, L, M> t;\n    Matrix<bool, N, L> ret;\n    for (int\
    \ i = M; i--;)\n      for (int j = L; j--;) t[j][i] = r[i][j];\n    for (int i\
    \ = N; i--;)\n      for (int j = L; j--;) ret[i][j] = ((*this)[i] & t[j]).count()\
    \ & 1;\n    return ret;\n  }\n  std::bitset<N> operator*(const std::bitset<N>\
    \ &r) const {\n    std::bitset<N> ret;\n    for (int i = N; i--;) ret[i] = ((*this)[i]\
    \ & r).count() & 1;\n    return ret;\n  }\n  std::vector<std::vector<bool>> to_vec(int\
    \ n, int m) const {\n    std::vector<std::vector<bool>> ret(n, std::vector<bool>(m));\n\
    \    for (int i = n; i--;)\n      for (int j = m; j--;) ret[i][j] = (*this)[i][j];\n\
    \    return ret;\n  }\n};\n\ntemplate <class R, int N>\nstruct SquareMatrix :\
    \ public Matrix<R, N, N> {\n  using Matrix<R, N, N>::Matrix;\n  SquareMatrix(Matrix<R,\
    \ N, N> m) { *this = m; }\n  static constexpr SquareMatrix I() {\n    SquareMatrix\
    \ ret = {};\n    for (int i = N; i--;) ret[i][i] = R(true);\n    return ret;\n\
    \  }\n  SquareMatrix &operator=(const Matrix<R, N, N> &r) {\n    for (int i =\
    \ N; i--;)\n      for (int j = N; j--;) (*this)[i][j] = r[i][j];\n    return *this;\n\
    \  }\n  SquareMatrix &operator*=(const SquareMatrix &r) {\n    return *this =\
    \ (*this) * r;\n  }\n  SquareMatrix pow(std::uint64_t e) const {\n    for (SquareMatrix\
    \ ret = I(), b = *this;; b *= b)\n      if (e & 1 ? ret *= b, !(e >>= 1) : !(e\
    \ >>= 1)) return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/LinearAlgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2022-10-29 11:11:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/650.LCT.test.cpp
  - test/yukicoder/1340.test.cpp
  - test/aoj/2624.test.cpp
  - test/aoj/2397.test.cpp
  - test/atcoder/abc236_g.test.cpp
documentation_of: src/LinearAlgebra/Matrix.hpp
layout: document
redirect_from:
- /library/src/LinearAlgebra/Matrix.hpp
- /library/src/LinearAlgebra/Matrix.hpp.html
title: "\u884C\u5217"
---
