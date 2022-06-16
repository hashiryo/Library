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
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/Math/Matrix.hpp\"\n#include <bits/stdc++.h>\n/**\n *\
    \ @title \u884C\u5217\n * @category \u6570\u5B66\n * \u534A\u74B0\u304C\u8F09\u308B\
    \n */\n\n// BEGIN CUT HERE\n\nstruct has_I_impl {\n  template <class T>\n  static\
    \ auto check(T &&x) -> decltype(x.I(), std::true_type{});\n  template <class T>\n\
    \  static auto check(...) -> std::false_type;\n};\ntemplate <class T>\nclass has_I\
    \ : public decltype(has_I_impl::check<T>(std::declval<T>())) {};\ntemplate <class\
    \ T>\ninline constexpr bool has_I_v = has_I<T>::value;\n\ntemplate <class R, int\
    \ N, int M>\nstruct Matrix : public std::array<std::array<R, M>, N> {\n  static\
    \ Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const Matrix &r) {\n \
    \   for (int i = 0; i < N; i++)\n      for (int j = 0; j < M; j++) (*this)[i][j]\
    \ += r[i][j];\n    return *this;\n  }\n  Matrix operator+(const Matrix &r) const\
    \ { return Matrix(*this) += r; }\n  template <int L>\n  Matrix<R, N, L> operator*(const\
    \ Matrix<R, M, L> &r) const {\n    Matrix<R, N, L> ret;\n    for (int i = 0; i\
    \ < N; i++)\n      for (int j = 0; j < L; j++)\n        for (int k = 0; k < M;\
    \ k++) ret[i][j] += (*this)[i][k] * r[k][j];\n    return ret;\n  }\n  std::array<R,\
    \ N> operator*(const std::array<R, M> &r) const {\n    std::array<R, N> ret;\n\
    \    for (int i = 0; i < N; i++)\n      for (int j = 0; j < M; j++) ret[i] +=\
    \ (*this)[i][j] * r[j];\n    return ret;\n  }\n  std::vector<std::vector<R>> to_vec(int\
    \ n, int m) const {\n    std::vector<std::vector<R>> ret(n, std::vector<R>(m));\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) ret[i][j]\
    \ = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <int N, int M>\nstruct\
    \ Matrix<bool, N, M> : public std::array<std::bitset<M>, N> {\n  static Matrix\
    \ O() { return Matrix{}; }\n  Matrix &operator+=(const Matrix &r) {\n    for (int\
    \ i = 0; i < N; i++) (*this)[i] ^= r[i];\n    return *this;\n  }\n  Matrix operator+(const\
    \ Matrix &r) const { return Matrix(*this) += r; }\n  template <int L>\n  Matrix<bool,\
    \ N, L> operator*(const Matrix<bool, M, L> &r) const {\n    Matrix<bool, L, M>\
    \ t;\n    Matrix<bool, N, L> ret;\n    for (int i = 0; i < M; i++)\n      for\
    \ (int j = 0; j < L; j++) t[j][i] = r[i][j];\n    for (int i = 0; i < N; i++)\n\
    \      for (int j = 0; j < L; j++) ret[i][j] = ((*this)[i] & t[j]).count() & 1;\n\
    \    return ret;\n  }\n  std::bitset<N> operator*(const std::bitset<N> &r) const\
    \ {\n    std::bitset<N> ret;\n    for (int i = 0; i < N; i++) ret[i] = ((*this)[i]\
    \ & r).count() & 1;\n    return ret;\n  }\n  std::vector<std::vector<bool>> to_vec(int\
    \ n, int m) const {\n    std::vector<std::vector<bool>> ret(n, std::vector<bool>(m));\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) ret[i][j]\
    \ = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <class R, int N>\nstruct\
    \ SquareMatrix : public Matrix<R, N, N> {\n  using Matrix<R, N, N>::Matrix;\n\
    \  SquareMatrix(Matrix<R, N, N> m) { *this = m; }\n  static SquareMatrix I() {\n\
    \    SquareMatrix ret;\n    if constexpr (has_I_v<R>)\n      for (int i = 0; i\
    \ < N; i++) ret[i][i] = R::I();\n    else\n      for (int i = 0; i < N; i++) ret[i][i]\
    \ = R(1);\n    return ret;\n  }\n  SquareMatrix &operator=(const Matrix<R, N,\
    \ N> &r) {\n    for (int i = 0; i < N; i++)\n      for (int j = 0; j < N; j++)\
    \ (*this)[i][j] = r[i][j];\n    return *this;\n  }\n  SquareMatrix &operator*=(const\
    \ SquareMatrix &r) {\n    return *this = (*this) * r;\n  }\n  SquareMatrix pow(std::uint64_t\
    \ e) const {\n    for (SquareMatrix ret = I(), b = *this;; b *= b)\n      if (e\
    \ & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1)) return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u884C\u5217\n * @category\
    \ \u6570\u5B66\n * \u534A\u74B0\u304C\u8F09\u308B\n */\n\n// BEGIN CUT HERE\n\n\
    struct has_I_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.I(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\ntemplate <class T>\nclass has_I : public decltype(has_I_impl::check<T>(std::declval<T>()))\
    \ {};\ntemplate <class T>\ninline constexpr bool has_I_v = has_I<T>::value;\n\n\
    template <class R, int N, int M>\nstruct Matrix : public std::array<std::array<R,\
    \ M>, N> {\n  static Matrix O() { return Matrix{}; }\n  Matrix &operator+=(const\
    \ Matrix &r) {\n    for (int i = 0; i < N; i++)\n      for (int j = 0; j < M;\
    \ j++) (*this)[i][j] += r[i][j];\n    return *this;\n  }\n  Matrix operator+(const\
    \ Matrix &r) const { return Matrix(*this) += r; }\n  template <int L>\n  Matrix<R,\
    \ N, L> operator*(const Matrix<R, M, L> &r) const {\n    Matrix<R, N, L> ret;\n\
    \    for (int i = 0; i < N; i++)\n      for (int j = 0; j < L; j++)\n        for\
    \ (int k = 0; k < M; k++) ret[i][j] += (*this)[i][k] * r[k][j];\n    return ret;\n\
    \  }\n  std::array<R, N> operator*(const std::array<R, M> &r) const {\n    std::array<R,\
    \ N> ret;\n    for (int i = 0; i < N; i++)\n      for (int j = 0; j < M; j++)\
    \ ret[i] += (*this)[i][j] * r[j];\n    return ret;\n  }\n  std::vector<std::vector<R>>\
    \ to_vec(int n, int m) const {\n    std::vector<std::vector<R>> ret(n, std::vector<R>(m));\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) ret[i][j]\
    \ = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <int N, int M>\nstruct\
    \ Matrix<bool, N, M> : public std::array<std::bitset<M>, N> {\n  static Matrix\
    \ O() { return Matrix{}; }\n  Matrix &operator+=(const Matrix &r) {\n    for (int\
    \ i = 0; i < N; i++) (*this)[i] ^= r[i];\n    return *this;\n  }\n  Matrix operator+(const\
    \ Matrix &r) const { return Matrix(*this) += r; }\n  template <int L>\n  Matrix<bool,\
    \ N, L> operator*(const Matrix<bool, M, L> &r) const {\n    Matrix<bool, L, M>\
    \ t;\n    Matrix<bool, N, L> ret;\n    for (int i = 0; i < M; i++)\n      for\
    \ (int j = 0; j < L; j++) t[j][i] = r[i][j];\n    for (int i = 0; i < N; i++)\n\
    \      for (int j = 0; j < L; j++) ret[i][j] = ((*this)[i] & t[j]).count() & 1;\n\
    \    return ret;\n  }\n  std::bitset<N> operator*(const std::bitset<N> &r) const\
    \ {\n    std::bitset<N> ret;\n    for (int i = 0; i < N; i++) ret[i] = ((*this)[i]\
    \ & r).count() & 1;\n    return ret;\n  }\n  std::vector<std::vector<bool>> to_vec(int\
    \ n, int m) const {\n    std::vector<std::vector<bool>> ret(n, std::vector<bool>(m));\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) ret[i][j]\
    \ = (*this)[i][j];\n    return ret;\n  }\n};\n\ntemplate <class R, int N>\nstruct\
    \ SquareMatrix : public Matrix<R, N, N> {\n  using Matrix<R, N, N>::Matrix;\n\
    \  SquareMatrix(Matrix<R, N, N> m) { *this = m; }\n  static SquareMatrix I() {\n\
    \    SquareMatrix ret;\n    if constexpr (has_I_v<R>)\n      for (int i = 0; i\
    \ < N; i++) ret[i][i] = R::I();\n    else\n      for (int i = 0; i < N; i++) ret[i][i]\
    \ = R(1);\n    return ret;\n  }\n  SquareMatrix &operator=(const Matrix<R, N,\
    \ N> &r) {\n    for (int i = 0; i < N; i++)\n      for (int j = 0; j < N; j++)\
    \ (*this)[i][j] = r[i][j];\n    return *this;\n  }\n  SquareMatrix &operator*=(const\
    \ SquareMatrix &r) {\n    return *this = (*this) * r;\n  }\n  SquareMatrix pow(std::uint64_t\
    \ e) const {\n    for (SquareMatrix ret = I(), b = *this;; b *= b)\n      if (e\
    \ & 1 ? ret *= b, !(e >>= 1) : !(e >>= 1)) return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Matrix.hpp
  requiredBy: []
  timestamp: '2022-06-16 15:13:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2624.test.cpp
  - test/aoj/2397.test.cpp
  - test/yukicoder/1340.test.cpp
documentation_of: src/Math/Matrix.hpp
layout: document
redirect_from:
- /library/src/Math/Matrix.hpp
- /library/src/Math/Matrix.hpp.html
title: "\u884C\u5217"
---
