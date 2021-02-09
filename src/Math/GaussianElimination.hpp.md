---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_equations.test.cpp
    title: test/yosupo/linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/Math/GaussianElimination.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\n * @category \u6570\
    \u5B66\n * linear_equation(A,b) \u8FD4\u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\
    \u4E00\u3064,\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\
    \n// BEGIN CUT HERE\n\nclass GaussianElimination {\n  template <class T>\n  inline\
    \ static constexpr bool IFPV = std::is_floating_point_v<T>;\n  template <class\
    \ T, typename std::enable_if_t<IFPV<T>> * = nullptr>\n  static bool is_zero(T\
    \ x) {\n    return std::abs(x) < 1e-8;\n  }\n  template <class T, typename std::enable_if_t<!IFPV<T>>\
    \ * = nullptr>\n  static bool is_zero(T x) {\n    return x == T(0);\n  }\n  template\
    \ <class T, typename std::enable_if_t<IFPV<T>> * = nullptr>\n  static bool compare(T\
    \ x, T y) {\n    return std::abs(x) < std::abs(y);\n  }\n  template <class T,\
    \ typename std::enable_if_t<!IFPV<T>> * = nullptr>\n  static bool compare(T, T\
    \ y) {\n    return y != T(0);\n  }\n  template <class LHS, class RHS>\n  static\
    \ void subst(LHS &lhs, const RHS &rhs, int n, int m) {\n    for (int i = 0; i\
    \ < n; i++)\n      for (int j = 0; j < m; j++) lhs[i][j] = rhs[i][j];\n  }\n \
    \ template <int M>\n  static int row_reduction(std::vector<std::bitset<M>> &a,\
    \ int lim = 1 << 30) {\n    int n = a.size(), rank = 0, j, p;\n    for (lim =\
    \ std::min(lim, M), j = 0, p = rank; j < lim; j++, p = rank) {\n      while (p\
    \ < n - 1 && !a[p][j]) p++;\n      if (!a[p][j]) continue;\n      std::swap(a[p],\
    \ a[rank]);\n      for (int i = 0; i < n; i++)\n        if (i != rank && a[i][j])\
    \ a[i] ^= a[rank];\n      if (++rank == n) break;\n    }\n    return rank;\n \
    \ }\n\n public:\n  template <class K>\n  static auto row_reduction(std::vector<std::vector<K>>\
    \ &a, int lim = 1 << 30) {\n    int n = a.size(), m = a[0].size(), rank = 0, j,\
    \ p;\n    K det = K(1), invc;\n    for (lim = std::min(lim, m), j = 0, p = rank;\
    \ j < lim; j++, p = rank) {\n      for (int i = rank + 1; i < n; i++)\n      \
    \  if (compare(a[p][j], a[i][j])) p = i;\n      if (is_zero(a[p][j])) continue;\n\
    \      if (p != rank) std::swap(a[p], a[rank]), det = -det;\n      invc = K(1)\
    \ / a[rank][j], det *= a[rank][j];\n      for (int k = j; k < m; k++) a[rank][k]\
    \ *= invc;\n      for (int i = 0; i < n; i++)\n        if (i != rank && !is_zero(a[i][j]))\n\
    \          for (int k = m - 1; k >= j; k--) a[i][k] -= a[i][j] * a[rank][k];\n\
    \      if (++rank == n) break;\n    }\n    return std::make_pair(rank, rank ==\
    \ n ? det : K(0));\n  }\n  static auto row_reduction(std::vector<std::vector<bool>>\
    \ &a,\n                            int lim = 1 << 30) {\n    int n = a.size(),\
    \ m = a[0].size(), rank;\n    if (m < 1024) {\n      std::vector<std::bitset<1024>>\
    \ b(n);\n      subst(b, a, n, m), rank = row_reduction<1024>(b, lim), subst(a,\
    \ b, n, m);\n    } else {\n      std::vector<std::bitset<4096>> b(n);\n      subst(b,\
    \ a, n, m), rank = row_reduction<4096>(b, lim), subst(a, b, n, m);\n    }\n  \
    \  return std::make_pair(rank, rank == n);\n  }\n  template <class K>\n  static\
    \ std::pair<std::vector<K>, std::vector<std::vector<K>>> linear_equation(\n  \
    \    std::vector<std::vector<K>> a, const std::vector<K> &b) {\n    int n = a.size(),\
    \ m = a[0].size();\n    for (int i = 0; i < n; i++) a[i].emplace_back(b[i]);\n\
    \    int rank = row_reduction(a, m).first;\n    for (int i = rank; i < n; ++i)\n\
    \      if (!is_zero(K(a[i][m]))) return {{}, {}};\n    std::vector<K> c(m, K(0));\n\
    \    std::vector<int> piv(m, -1);\n    for (int i = 0, j = 0; i < rank; i++) {\n\
    \      while (is_zero(K(a[i][j]))) j++;\n      c[j] = a[i][m], piv[j] = i;\n \
    \   }\n    std::vector<std::vector<K>> d;\n    for (int j = 0; j < m; ++j) {\n\
    \      if (piv[j] != -1) continue;\n      std::vector<K> x(m, K(0));\n      x[j]\
    \ = K(-1);\n      for (int k = 0; k < j; ++k)\n        if (piv[k] != -1) x[k]\
    \ = a[piv[k]][j];\n      d.emplace_back(x);\n    }\n    return {c, d};\n  }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u30AC\u30A6\u30B9\
    \u306E\u6D88\u53BB\u6CD5\n * @category \u6570\u5B66\n * linear_equation(A,b) \u8FD4\
    \u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\u4E00\u3064,\u89E3\u7A7A\u9593\u306E\
    \u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\n// BEGIN CUT HERE\n\nclass GaussianElimination\
    \ {\n  template <class T>\n  inline static constexpr bool IFPV = std::is_floating_point_v<T>;\n\
    \  template <class T, typename std::enable_if_t<IFPV<T>> * = nullptr>\n  static\
    \ bool is_zero(T x) {\n    return std::abs(x) < 1e-8;\n  }\n  template <class\
    \ T, typename std::enable_if_t<!IFPV<T>> * = nullptr>\n  static bool is_zero(T\
    \ x) {\n    return x == T(0);\n  }\n  template <class T, typename std::enable_if_t<IFPV<T>>\
    \ * = nullptr>\n  static bool compare(T x, T y) {\n    return std::abs(x) < std::abs(y);\n\
    \  }\n  template <class T, typename std::enable_if_t<!IFPV<T>> * = nullptr>\n\
    \  static bool compare(T, T y) {\n    return y != T(0);\n  }\n  template <class\
    \ LHS, class RHS>\n  static void subst(LHS &lhs, const RHS &rhs, int n, int m)\
    \ {\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) lhs[i][j]\
    \ = rhs[i][j];\n  }\n  template <int M>\n  static int row_reduction(std::vector<std::bitset<M>>\
    \ &a, int lim = 1 << 30) {\n    int n = a.size(), rank = 0, j, p;\n    for (lim\
    \ = std::min(lim, M), j = 0, p = rank; j < lim; j++, p = rank) {\n      while\
    \ (p < n - 1 && !a[p][j]) p++;\n      if (!a[p][j]) continue;\n      std::swap(a[p],\
    \ a[rank]);\n      for (int i = 0; i < n; i++)\n        if (i != rank && a[i][j])\
    \ a[i] ^= a[rank];\n      if (++rank == n) break;\n    }\n    return rank;\n \
    \ }\n\n public:\n  template <class K>\n  static auto row_reduction(std::vector<std::vector<K>>\
    \ &a, int lim = 1 << 30) {\n    int n = a.size(), m = a[0].size(), rank = 0, j,\
    \ p;\n    K det = K(1), invc;\n    for (lim = std::min(lim, m), j = 0, p = rank;\
    \ j < lim; j++, p = rank) {\n      for (int i = rank + 1; i < n; i++)\n      \
    \  if (compare(a[p][j], a[i][j])) p = i;\n      if (is_zero(a[p][j])) continue;\n\
    \      if (p != rank) std::swap(a[p], a[rank]), det = -det;\n      invc = K(1)\
    \ / a[rank][j], det *= a[rank][j];\n      for (int k = j; k < m; k++) a[rank][k]\
    \ *= invc;\n      for (int i = 0; i < n; i++)\n        if (i != rank && !is_zero(a[i][j]))\n\
    \          for (int k = m - 1; k >= j; k--) a[i][k] -= a[i][j] * a[rank][k];\n\
    \      if (++rank == n) break;\n    }\n    return std::make_pair(rank, rank ==\
    \ n ? det : K(0));\n  }\n  static auto row_reduction(std::vector<std::vector<bool>>\
    \ &a,\n                            int lim = 1 << 30) {\n    int n = a.size(),\
    \ m = a[0].size(), rank;\n    if (m < 1024) {\n      std::vector<std::bitset<1024>>\
    \ b(n);\n      subst(b, a, n, m), rank = row_reduction<1024>(b, lim), subst(a,\
    \ b, n, m);\n    } else {\n      std::vector<std::bitset<4096>> b(n);\n      subst(b,\
    \ a, n, m), rank = row_reduction<4096>(b, lim), subst(a, b, n, m);\n    }\n  \
    \  return std::make_pair(rank, rank == n);\n  }\n  template <class K>\n  static\
    \ std::pair<std::vector<K>, std::vector<std::vector<K>>> linear_equation(\n  \
    \    std::vector<std::vector<K>> a, const std::vector<K> &b) {\n    int n = a.size(),\
    \ m = a[0].size();\n    for (int i = 0; i < n; i++) a[i].emplace_back(b[i]);\n\
    \    int rank = row_reduction(a, m).first;\n    for (int i = rank; i < n; ++i)\n\
    \      if (!is_zero(K(a[i][m]))) return {{}, {}};\n    std::vector<K> c(m, K(0));\n\
    \    std::vector<int> piv(m, -1);\n    for (int i = 0, j = 0; i < rank; i++) {\n\
    \      while (is_zero(K(a[i][j]))) j++;\n      c[j] = a[i][m], piv[j] = i;\n \
    \   }\n    std::vector<std::vector<K>> d;\n    for (int j = 0; j < m; ++j) {\n\
    \      if (piv[j] != -1) continue;\n      std::vector<K> x(m, K(0));\n      x[j]\
    \ = K(-1);\n      for (int k = 0; k < j; ++k)\n        if (piv[k] != -1) x[k]\
    \ = a[piv[k]][j];\n      d.emplace_back(x);\n    }\n    return {c, d};\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/GaussianElimination.hpp
  requiredBy: []
  timestamp: '2021-02-09 19:48:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/linear_equations.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/184.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2624.test.cpp
documentation_of: src/Math/GaussianElimination.hpp
layout: document
redirect_from:
- /library/src/Math/GaussianElimination.hpp
- /library/src/Math/GaussianElimination.hpp.html
title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5"
---
