---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.test.cpp
    title: test/aoj/2397.test.cpp
  - icon: ':x:'
    path: test/yosupo/linear_equations.test.cpp
    title: test/yosupo/linear_equations.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/Math/Matrix.hpp\"\n#include <bits/stdc++.h>\n/**\n *\
    \ @title \u884C\u5217\n * @category \u6570\u5B66\n *  Gauss_Jordan(A,B) \u62E1\
    \u5927\u4FC2\u6570\u884C\u5217\u306B\u5BFE\u3059\u308B\u30AC\u30A6\u30B9\u30B8\
    \u30E7\u30EB\u30C0\u30F3\u6CD5\n *  linear_equations(A,b) \u8FD4\u308A\u5024 {\u89E3\
    \u306E\u3046\u3061\u306E\u4E00\u3064,\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u30D9\
    \u30AF\u30C8\u30EB}\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename K>\nstruct\
    \ Matrix {\n private:\n  std::vector<std::vector<K>> a;\n\n public:\n  Matrix()\
    \ {}\n  Matrix(std::size_t n, std::size_t m) : a(n, std::vector<K>(m, 0)) {}\n\
    \  Matrix(std::size_t n) : Matrix(n, n) {}\n  Matrix(std::vector<std::vector<K>>\
    \ a) : a(a) {}\n  std::size_t height() const { return a.size(); }\n  std::size_t\
    \ width() const { return a[0].size(); }\n  inline const std::vector<K> &operator[](std::size_t\
    \ k) const { return a[k]; }\n  inline std::vector<K> &operator[](std::size_t k)\
    \ { return a[k]; }\n  static Matrix diag(std::vector<K> v) {\n    Matrix mat(v.size());\n\
    \    for (std::size_t i = 0; i < v.size(); i++) mat[i][i] = v[i];\n    return\
    \ mat;\n  }\n  static Matrix I(std::size_t n, K e = {1}) {\n    return diag(std::vector<K>(n,\
    \ e));\n  }\n  Matrix &operator+=(const Matrix &b) {\n    std::size_t n = height(),\
    \ m = width();\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t\
    \ j = 0; j < m; j++) (*this)[i][j] += b[i][j];\n    return (*this);\n  }\n  Matrix\
    \ &operator-=(const Matrix &b) {\n    std::size_t n = height(), m = width();\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) (*this)[i][j] -= b[i][j];\n    return (*this);\n  }\n  Matrix &operator*=(const\
    \ Matrix &b) {\n    std::size_t n = height(), m = width(), l = b.width();\n  \
    \  assert(m == b.height());\n    std::vector<std::vector<K>> c(n, std::vector<K>(l,\
    \ 0));\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0;\
    \ j < l; j++)\n        for (std::size_t k = 0; k < m; k++) c[i][j] += (*this)[i][k]\
    \ * b[k][j];\n    a.swap(c);\n    return (*this);\n  }\n  Matrix operator+(const\
    \ Matrix &b) const { return (Matrix(*this) += b); }\n  Matrix operator-(const\
    \ Matrix &b) const { return (Matrix(*this) -= b); }\n  Matrix operator*(const\
    \ Matrix &b) const { return (Matrix(*this) *= b); }\n  Matrix pow(uint64_t n,\
    \ K e = {1}) {\n    Matrix ret = I(height(), e);\n    for (Matrix base = *this;\
    \ n; n >>= 1, base *= base)\n      if (n & 1) ret *= base;\n    return ret;\n\
    \  }\n  std::vector<K> operator*(const std::vector<K> &v) {\n    std::size_t n\
    \ = height(), m = width();\n    assert(m == v.size());\n    std::vector<K> ret(n);\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) ret[i] += (*this)[i][j] * v[j];\n    return ret;\n  }\n  bool operator==(const\
    \ Matrix &b) const { return a == b.a; }\n  template <typename T>\n  using ET =\
    \ std::enable_if<std::is_floating_point<T>::value>;\n  template <typename T>\n\
    \  using EF = std::enable_if<!std::is_floating_point<T>::value>;\n  template <typename\
    \ T, typename ET<T>::type * = nullptr>\n  static bool is_zero(T x) {\n    return\
    \ std::abs(x) < 1e-8;\n  }\n  template <typename T, typename EF<T>::type * = nullptr>\n\
    \  static bool is_zero(T x) {\n    return x == T(0);\n  }\n  template <typename\
    \ T, typename ET<T>::type * = nullptr>\n  static bool compare(T x, T y) {\n  \
    \  return std::abs(x) < std::abs(y);\n  }\n  template <typename T, typename EF<T>::type\
    \ * = nullptr>\n  static bool compare(T x, T y) {\n    (void)x;\n    return y\
    \ != T(0);\n  }\n  // O(nm(m+l))\n  static std::pair<Matrix, Matrix> Gauss_Jordan(const\
    \ Matrix &a,\n                                                const Matrix &b)\
    \ {\n    std::size_t n = a.height(), m = a.width(), l = b.width();\n    Matrix\
    \ c(n, m + l);\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t\
    \ j = 0; j < m; j++) c[i][j] = a[i][j];\n    for (std::size_t i = 0; i < n; i++)\n\
    \      for (std::size_t j = 0; j < l; j++) c[i][j + m] = b[i][j];\n    for (std::size_t\
    \ j = 0, d = 0; j < m && d < n; j++) {\n      int p = d;\n      for (std::size_t\
    \ i = d + 1; i < n; i++)\n        if (compare(c[p][j], c[i][j])) p = i;\n    \
    \  if (is_zero(c[p][j])) continue;\n      std::swap(c[p], c[d]);\n      K invc\
    \ = K(1) / c[d][j];\n      for (std::size_t k = j; k < m + l; k++) c[d][k] *=\
    \ invc;\n      for (std::size_t i = 0; i < n; i++) {\n        if (i == d) continue;\n\
    \        for (int k = m + l - 1; k >= (int)j; k--) c[i][k] -= c[i][j] * c[d][k];\n\
    \      }\n      d++;\n    }\n    Matrix reta(n, m), retb(n, l);\n    for (std::size_t\
    \ i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m; j++) reta[i][j] = c[i][j];\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < l;\
    \ j++) retb[i][j] = c[i][j + m];\n    return std::make_pair(reta, retb);\n  }\n\
    \  // O(nm^2)\n  static std::pair<std::vector<K>, std::vector<std::vector<K>>>\n\
    \  linear_equations(const Matrix &a, const std::vector<K> &b) {\n    std::size_t\
    \ n = a.height(), m = a.width();\n    Matrix B(n, 1);\n    for (std::size_t i\
    \ = 0; i < n; i++) B[i][0] = b[i];\n    auto p = Gauss_Jordan(a, B);\n    std::vector<int>\
    \ jdx(n, -1), idx(m, -1);\n    for (std::size_t i = 0, j; i < n; i++) {\n    \
    \  for (j = 0; j < m; j++)\n        if (!is_zero(p.first[i][j])) {\n         \
    \ jdx[i] = j, idx[j] = i;\n          break;\n        }\n      if (j == m && !is_zero(p.second[i][0]))\n\
    \        return std::make_pair(std::vector<K>(),\n                           \
    \   std::vector<std::vector<K>>());  // no solutions\n    }\n    std::vector<K>\
    \ c(m);\n    std::vector<std::vector<K>> d;\n    for (std::size_t j = 0; j < m;\
    \ j++) {\n      if (idx[j] != -1)\n        c[j] = p.second[idx[j]][0];\n     \
    \ else {\n        std::vector<K> v(m);\n        v[j] = 1;\n        for (std::size_t\
    \ i = 0; i < n; i++)\n          if (jdx[i] != -1) v[jdx[i]] = -p.first[i][j];\n\
    \        d.emplace_back(v);\n      }\n    }\n    return std::make_pair(c, d);\n\
    \  }\n  // O(n^3)\n  K det() const {\n    int n = height();\n    Matrix A(a);\n\
    \    K ret(1);\n    for (int i = 0; i < n; i++) {\n      int p = i;\n      for\
    \ (int j = i + 1; j < n; j++)\n        if (compare(A[p][i], A[j][i])) p = j;\n\
    \      if (is_zero(A[p][i])) return 0;\n      if (p != i) ret = -ret;\n      std::swap(A[p],\
    \ A[i]);\n      ret *= A[i][i];\n      K inva = K(1) / A[i][i];\n      for (int\
    \ j = i + 1; j < n; j++)\n        for (int k = n - 1; k >= i; k--) A[j][k] -=\
    \ inva * A[j][i] * A[i][k];\n    }\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u884C\u5217\n * @category\
    \ \u6570\u5B66\n *  Gauss_Jordan(A,B) \u62E1\u5927\u4FC2\u6570\u884C\u5217\u306B\
    \u5BFE\u3059\u308B\u30AC\u30A6\u30B9\u30B8\u30E7\u30EB\u30C0\u30F3\u6CD5\n * \
    \ linear_equations(A,b) \u8FD4\u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\u4E00\
    \u3064,\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\n\
    // BEGIN CUT HERE\n\ntemplate <typename K>\nstruct Matrix {\n private:\n  std::vector<std::vector<K>>\
    \ a;\n\n public:\n  Matrix() {}\n  Matrix(std::size_t n, std::size_t m) : a(n,\
    \ std::vector<K>(m, 0)) {}\n  Matrix(std::size_t n) : Matrix(n, n) {}\n  Matrix(std::vector<std::vector<K>>\
    \ a) : a(a) {}\n  std::size_t height() const { return a.size(); }\n  std::size_t\
    \ width() const { return a[0].size(); }\n  inline const std::vector<K> &operator[](std::size_t\
    \ k) const { return a[k]; }\n  inline std::vector<K> &operator[](std::size_t k)\
    \ { return a[k]; }\n  static Matrix diag(std::vector<K> v) {\n    Matrix mat(v.size());\n\
    \    for (std::size_t i = 0; i < v.size(); i++) mat[i][i] = v[i];\n    return\
    \ mat;\n  }\n  static Matrix I(std::size_t n, K e = {1}) {\n    return diag(std::vector<K>(n,\
    \ e));\n  }\n  Matrix &operator+=(const Matrix &b) {\n    std::size_t n = height(),\
    \ m = width();\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t\
    \ j = 0; j < m; j++) (*this)[i][j] += b[i][j];\n    return (*this);\n  }\n  Matrix\
    \ &operator-=(const Matrix &b) {\n    std::size_t n = height(), m = width();\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) (*this)[i][j] -= b[i][j];\n    return (*this);\n  }\n  Matrix &operator*=(const\
    \ Matrix &b) {\n    std::size_t n = height(), m = width(), l = b.width();\n  \
    \  assert(m == b.height());\n    std::vector<std::vector<K>> c(n, std::vector<K>(l,\
    \ 0));\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0;\
    \ j < l; j++)\n        for (std::size_t k = 0; k < m; k++) c[i][j] += (*this)[i][k]\
    \ * b[k][j];\n    a.swap(c);\n    return (*this);\n  }\n  Matrix operator+(const\
    \ Matrix &b) const { return (Matrix(*this) += b); }\n  Matrix operator-(const\
    \ Matrix &b) const { return (Matrix(*this) -= b); }\n  Matrix operator*(const\
    \ Matrix &b) const { return (Matrix(*this) *= b); }\n  Matrix pow(uint64_t n,\
    \ K e = {1}) {\n    Matrix ret = I(height(), e);\n    for (Matrix base = *this;\
    \ n; n >>= 1, base *= base)\n      if (n & 1) ret *= base;\n    return ret;\n\
    \  }\n  std::vector<K> operator*(const std::vector<K> &v) {\n    std::size_t n\
    \ = height(), m = width();\n    assert(m == v.size());\n    std::vector<K> ret(n);\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m;\
    \ j++) ret[i] += (*this)[i][j] * v[j];\n    return ret;\n  }\n  bool operator==(const\
    \ Matrix &b) const { return a == b.a; }\n  template <typename T>\n  using ET =\
    \ std::enable_if<std::is_floating_point<T>::value>;\n  template <typename T>\n\
    \  using EF = std::enable_if<!std::is_floating_point<T>::value>;\n  template <typename\
    \ T, typename ET<T>::type * = nullptr>\n  static bool is_zero(T x) {\n    return\
    \ std::abs(x) < 1e-8;\n  }\n  template <typename T, typename EF<T>::type * = nullptr>\n\
    \  static bool is_zero(T x) {\n    return x == T(0);\n  }\n  template <typename\
    \ T, typename ET<T>::type * = nullptr>\n  static bool compare(T x, T y) {\n  \
    \  return std::abs(x) < std::abs(y);\n  }\n  template <typename T, typename EF<T>::type\
    \ * = nullptr>\n  static bool compare(T x, T y) {\n    (void)x;\n    return y\
    \ != T(0);\n  }\n  // O(nm(m+l))\n  static std::pair<Matrix, Matrix> Gauss_Jordan(const\
    \ Matrix &a,\n                                                const Matrix &b)\
    \ {\n    std::size_t n = a.height(), m = a.width(), l = b.width();\n    Matrix\
    \ c(n, m + l);\n    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t\
    \ j = 0; j < m; j++) c[i][j] = a[i][j];\n    for (std::size_t i = 0; i < n; i++)\n\
    \      for (std::size_t j = 0; j < l; j++) c[i][j + m] = b[i][j];\n    for (std::size_t\
    \ j = 0, d = 0; j < m && d < n; j++) {\n      int p = d;\n      for (std::size_t\
    \ i = d + 1; i < n; i++)\n        if (compare(c[p][j], c[i][j])) p = i;\n    \
    \  if (is_zero(c[p][j])) continue;\n      std::swap(c[p], c[d]);\n      K invc\
    \ = K(1) / c[d][j];\n      for (std::size_t k = j; k < m + l; k++) c[d][k] *=\
    \ invc;\n      for (std::size_t i = 0; i < n; i++) {\n        if (i == d) continue;\n\
    \        for (int k = m + l - 1; k >= (int)j; k--) c[i][k] -= c[i][j] * c[d][k];\n\
    \      }\n      d++;\n    }\n    Matrix reta(n, m), retb(n, l);\n    for (std::size_t\
    \ i = 0; i < n; i++)\n      for (std::size_t j = 0; j < m; j++) reta[i][j] = c[i][j];\n\
    \    for (std::size_t i = 0; i < n; i++)\n      for (std::size_t j = 0; j < l;\
    \ j++) retb[i][j] = c[i][j + m];\n    return std::make_pair(reta, retb);\n  }\n\
    \  // O(nm^2)\n  static std::pair<std::vector<K>, std::vector<std::vector<K>>>\n\
    \  linear_equations(const Matrix &a, const std::vector<K> &b) {\n    std::size_t\
    \ n = a.height(), m = a.width();\n    Matrix B(n, 1);\n    for (std::size_t i\
    \ = 0; i < n; i++) B[i][0] = b[i];\n    auto p = Gauss_Jordan(a, B);\n    std::vector<int>\
    \ jdx(n, -1), idx(m, -1);\n    for (std::size_t i = 0, j; i < n; i++) {\n    \
    \  for (j = 0; j < m; j++)\n        if (!is_zero(p.first[i][j])) {\n         \
    \ jdx[i] = j, idx[j] = i;\n          break;\n        }\n      if (j == m && !is_zero(p.second[i][0]))\n\
    \        return std::make_pair(std::vector<K>(),\n                           \
    \   std::vector<std::vector<K>>());  // no solutions\n    }\n    std::vector<K>\
    \ c(m);\n    std::vector<std::vector<K>> d;\n    for (std::size_t j = 0; j < m;\
    \ j++) {\n      if (idx[j] != -1)\n        c[j] = p.second[idx[j]][0];\n     \
    \ else {\n        std::vector<K> v(m);\n        v[j] = 1;\n        for (std::size_t\
    \ i = 0; i < n; i++)\n          if (jdx[i] != -1) v[jdx[i]] = -p.first[i][j];\n\
    \        d.emplace_back(v);\n      }\n    }\n    return std::make_pair(c, d);\n\
    \  }\n  // O(n^3)\n  K det() const {\n    int n = height();\n    Matrix A(a);\n\
    \    K ret(1);\n    for (int i = 0; i < n; i++) {\n      int p = i;\n      for\
    \ (int j = i + 1; j < n; j++)\n        if (compare(A[p][i], A[j][i])) p = j;\n\
    \      if (is_zero(A[p][i])) return 0;\n      if (p != i) ret = -ret;\n      std::swap(A[p],\
    \ A[i]);\n      ret *= A[i][i];\n      K inva = K(1) / A[i][i];\n      for (int\
    \ j = i + 1; j < n; j++)\n        for (int k = n - 1; k >= i; k--) A[j][k] -=\
    \ inva * A[j][i] * A[i][k];\n    }\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Matrix.hpp
  requiredBy: []
  timestamp: '2020-10-24 00:25:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2397.test.cpp
  - test/aoj/1328.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/linear_equations.test.cpp
documentation_of: src/Math/Matrix.hpp
layout: document
redirect_from:
- /library/src/Math/Matrix.hpp
- /library/src/Math/Matrix.hpp.html
title: "\u884C\u5217"
---
