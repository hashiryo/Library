---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/LinearAlgebra/SparseSquareMatrix.hpp
    title: "\u758E\u884C\u5217"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2397.SparseMat.test.cpp
    title: test/aoj/2397.SparseMat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.SparseMat.test.cpp
    title: test/yukicoder/1750.SparseMat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
    links:
    - https://yukicoder.me/wiki/black_box_linear_algebra
  bundledCode: "#line 2 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n *\
    \ @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1]\
    \ * a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  if\
    \ (n == 0) return {};\n  std::vector<K> c(n), b(n), tmp;\n  K x = 1, y, coef;\n\
    \  const K Z = 0;\n  for (c[0] = b[0] = 1, i = 0, j; i < n; ++i) {\n    for (++m,\
    \ y = a[i], j = 1; j <= d; ++j) y += c[j] * a[i - j];\n    if (y == Z) continue;\n\
    \    for (tmp = c, coef = y / x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n\
    \    if (2 * d > i) continue;\n    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n\
    \  c.resize(d + 1), c.erase(c.begin());\n  for (auto &x : c) x = -x;\n  return\
    \ c;\n}\n#line 4 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\n/**\n * @title \u884C\
    \u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F\n * @category \u7DDA\u5F62\u4EE3\u6570\
    \n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n * O(N*S(N))\n */\n\
    \n// BEGIN CUT HERE\n\n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)  + ... + c[1]\
    \ * M + c[0]) * b = 0\ntemplate <class Mat, class Vec>\nclass MinimalPolynomial\
    \ {\n  using mod_t = std::remove_reference_t<decltype((Vec{1})[0])>;\n  static\
    \ const inline mod_t ZERO = 0;\n  std::vector<mod_t> poly, rev;\n  std::vector<Vec>\
    \ bs;\n  std::size_t dg, n;\n  static inline int deg(const std::vector<mod_t>\
    \ &p) {\n    for (int d = p.size() - 1;; d--)\n      if (d < 0 || p[d] != ZERO)\
    \ return d;\n  }\n  static inline std::vector<mod_t> bostan_mori_msb(const std::vector<mod_t>\
    \ &q,\n                                                   std::uint64_t k) {\n\
    \    int d = deg(q);\n    assert(d >= 0), assert(q[0] != ZERO);\n    std::vector<mod_t>\
    \ ret(std::max(d, 1));\n    if (k == 0) return ret.back() = mod_t(1), ret;\n \
    \   std::vector<mod_t> v(d + 1);\n    for (int i = 0; i <= d; i += 2)\n      for\
    \ (int j = 0; j <= d; j += 2) v[(i + j) >> 1] += q[i] * q[j];\n    for (int i\
    \ = 1; i <= d; i += 2)\n      for (int j = 1; j <= d; j += 2) v[(i + j) >> 1]\
    \ -= q[i] * q[j];\n    auto w = bostan_mori_msb(v, k >> 1);\n    for (int i =\
    \ 2 * d - 1 - (k & 1); i >= d; i -= 2)\n      for (int j = 0; j <= d; j += 2)\
    \ ret[i - d] += q[j] * w[(i - j) >> 1];\n    for (int i = 2 * d - 1 - !(k & 1);\
    \ i >= d; i -= 2)\n      for (int j = 1; j <= d; j += 2) ret[i - d] -= q[j] *\
    \ w[(i - j) >> 1];\n    return ret;\n  }\n  std::vector<mod_t> x_pow_mod(std::uint64_t\
    \ k) const {\n    assert(k >= n);\n    std::vector<mod_t> ret(n), u = bostan_mori_msb(rev,\
    \ k - n + dg);\n    for (int i = dg; i--;)\n      for (int j = i + 1; j--;) ret[n\
    \ - 1 - i] += u[j] * rev[i - j];\n    return ret;\n  }\n\n public:\n  MinimalPolynomial(const\
    \ Mat &M, Vec b) : n(M.size()) {\n    std::size_t i, j;\n    assert(n == b.size());\n\
    \    std::vector<mod_t> a(n), v;\n    for (auto &x : a) x = get_rand(1, mod_t::modulo()\
    \ - 1);\n    mod_t tmp;\n    for (i = (n + 1) << 1; i--; v.push_back(tmp)) {\n\
    \      if (i > n) bs.emplace_back(b);\n      for (tmp = 0, j = n; j--;) tmp +=\
    \ a[j] * b[j];\n      if (i) b = M * b;\n    }\n    rev = berlekamp_massey(v);\n\
    \    for (auto &x : rev) x = -x;\n    rev.insert(rev.begin(), 1), poly = rev;\n\
    \    rev.erase(rev.begin() + (dg = deg(rev)) + 1, rev.end());\n    std::reverse(poly.begin(),\
    \ poly.end());\n  }\n  static std::uint64_t get_rand(std::uint64_t l, std::uint64_t\
    \ r) {\n    static std::mt19937_64 gen(std::random_device{}());\n    return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n  }\n  Vec pow(std::uint64_t k) const {  // M^k * b\n    if (k < n)\
    \ return bs[k];\n    auto r = x_pow_mod(k);\n    Vec ret = bs[0];\n    for (auto\
    \ &x : ret) x *= r[0];\n    for (int i = 1, e = r.size(), j; i < e; i++)\n   \
    \   for (j = n; j--;) ret[j] += r[i] * bs[i][j];\n    return ret;\n  }\n  const\
    \ mod_t operator[](std::size_t k) const { return poly[k]; }\n  const auto begin()\
    \ const { return poly.begin(); }\n  const auto end() const { return poly.end();\
    \ }\n  const std::size_t size() const { return dg + 1; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/berlekamp_massey.hpp\"\
    \n/**\n * @title \u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F\n * @category\
    \ \u7DDA\u5F62\u4EE3\u6570\n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n\
    \ * O(N*S(N))\n */\n\n// BEGIN CUT HERE\n\n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)\
    \  + ... + c[1] * M + c[0]) * b = 0\ntemplate <class Mat, class Vec>\nclass MinimalPolynomial\
    \ {\n  using mod_t = std::remove_reference_t<decltype((Vec{1})[0])>;\n  static\
    \ const inline mod_t ZERO = 0;\n  std::vector<mod_t> poly, rev;\n  std::vector<Vec>\
    \ bs;\n  std::size_t dg, n;\n  static inline int deg(const std::vector<mod_t>\
    \ &p) {\n    for (int d = p.size() - 1;; d--)\n      if (d < 0 || p[d] != ZERO)\
    \ return d;\n  }\n  static inline std::vector<mod_t> bostan_mori_msb(const std::vector<mod_t>\
    \ &q,\n                                                   std::uint64_t k) {\n\
    \    int d = deg(q);\n    assert(d >= 0), assert(q[0] != ZERO);\n    std::vector<mod_t>\
    \ ret(std::max(d, 1));\n    if (k == 0) return ret.back() = mod_t(1), ret;\n \
    \   std::vector<mod_t> v(d + 1);\n    for (int i = 0; i <= d; i += 2)\n      for\
    \ (int j = 0; j <= d; j += 2) v[(i + j) >> 1] += q[i] * q[j];\n    for (int i\
    \ = 1; i <= d; i += 2)\n      for (int j = 1; j <= d; j += 2) v[(i + j) >> 1]\
    \ -= q[i] * q[j];\n    auto w = bostan_mori_msb(v, k >> 1);\n    for (int i =\
    \ 2 * d - 1 - (k & 1); i >= d; i -= 2)\n      for (int j = 0; j <= d; j += 2)\
    \ ret[i - d] += q[j] * w[(i - j) >> 1];\n    for (int i = 2 * d - 1 - !(k & 1);\
    \ i >= d; i -= 2)\n      for (int j = 1; j <= d; j += 2) ret[i - d] -= q[j] *\
    \ w[(i - j) >> 1];\n    return ret;\n  }\n  std::vector<mod_t> x_pow_mod(std::uint64_t\
    \ k) const {\n    assert(k >= n);\n    std::vector<mod_t> ret(n), u = bostan_mori_msb(rev,\
    \ k - n + dg);\n    for (int i = dg; i--;)\n      for (int j = i + 1; j--;) ret[n\
    \ - 1 - i] += u[j] * rev[i - j];\n    return ret;\n  }\n\n public:\n  MinimalPolynomial(const\
    \ Mat &M, Vec b) : n(M.size()) {\n    std::size_t i, j;\n    assert(n == b.size());\n\
    \    std::vector<mod_t> a(n), v;\n    for (auto &x : a) x = get_rand(1, mod_t::modulo()\
    \ - 1);\n    mod_t tmp;\n    for (i = (n + 1) << 1; i--; v.push_back(tmp)) {\n\
    \      if (i > n) bs.emplace_back(b);\n      for (tmp = 0, j = n; j--;) tmp +=\
    \ a[j] * b[j];\n      if (i) b = M * b;\n    }\n    rev = berlekamp_massey(v);\n\
    \    for (auto &x : rev) x = -x;\n    rev.insert(rev.begin(), 1), poly = rev;\n\
    \    rev.erase(rev.begin() + (dg = deg(rev)) + 1, rev.end());\n    std::reverse(poly.begin(),\
    \ poly.end());\n  }\n  static std::uint64_t get_rand(std::uint64_t l, std::uint64_t\
    \ r) {\n    static std::mt19937_64 gen(std::random_device{}());\n    return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n  }\n  Vec pow(std::uint64_t k) const {  // M^k * b\n    if (k < n)\
    \ return bs[k];\n    auto r = x_pow_mod(k);\n    Vec ret = bs[0];\n    for (auto\
    \ &x : ret) x *= r[0];\n    for (int i = 1, e = r.size(), j; i < e; i++)\n   \
    \   for (j = n; j--;) ret[j] += r[i] * bs[i][j];\n    return ret;\n  }\n  const\
    \ mod_t operator[](std::size_t k) const { return poly[k]; }\n  const auto begin()\
    \ const { return poly.begin(); }\n  const auto end() const { return poly.end();\
    \ }\n  const std::size_t size() const { return dg + 1; }\n};"
  dependsOn:
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/MinimalPolynomial.hpp
  requiredBy:
  - src/LinearAlgebra/SparseSquareMatrix.hpp
  timestamp: '2022-06-24 13:41:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
  - test/aoj/2397.SparseMat.test.cpp
  - test/yukicoder/1750.SparseMat.test.cpp
documentation_of: src/LinearAlgebra/MinimalPolynomial.hpp
layout: document
redirect_from:
- /library/src/LinearAlgebra/MinimalPolynomial.hpp
- /library/src/LinearAlgebra/MinimalPolynomial.hpp.html
title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
---
