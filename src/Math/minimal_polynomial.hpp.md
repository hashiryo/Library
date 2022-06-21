---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sparse_matrix_det.test.cpp
    title: test/yosupo/sparse_matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u591A\u9805\u5F0F\u3068\u758E\u884C\u5217"
    links:
    - https://yukicoder.me/wiki/black_box_linear_algebra
  bundledCode: "#line 2 \"src/Math/minimal_polynomial.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n *\
    \ @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1]\
    \ * a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  std::vector<K>\
    \ c(n), b(n), tmp;\n  K x = 1, y, coef;\n  const K Z = 0;\n  for (c[0] = b[0]\
    \ = 1, i = 0, j; i < n; ++i) {\n    for (++m, y = a[i], j = 1; j <= d; ++j) y\
    \ += c[j] * a[i - j];\n    if (y == Z) continue;\n    for (tmp = c, coef = y /\
    \ x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n    if (2 * d > i) continue;\n\
    \    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n  c.resize(d + 1), c.erase(c.begin());\n\
    \  for (auto &x : c) x = -x;\n  return c;\n}\n#line 4 \"src/Math/minimal_polynomial.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u591A\u9805\u5F0F\u3068\u758E\u884C\u5217\n * @category\
    \ \u6570\u5B66\n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n */\n\
    \n// BEGIN CUT HERE\n\nstd::uint64_t get_rand(std::uint64_t l, std::uint64_t r)\
    \ {\n  static std::random_device rd;\n  static std::mt19937_64 gen(rd());\n  return\
    \ std::uniform_int_distribution<std::uint64_t>(l, r)(gen);\n}\n\n// (c[d] * M^d\
    \ + c[d-1] * M^(d-1)  + ... + c[1] * M + c[0]) * b = 0\n// return c\ntemplate\
    \ <class Mat, class Vec>\nauto minimal_polynomial(const Mat &M, Vec b) {\n  using\
    \ mod_t = std::remove_reference_t<decltype(b[0])>;\n  const std::uint64_t MOD\
    \ = mod_t::modulo();\n  std::size_t n = M.size(), i, j;\n  assert(n == b.size());\n\
    \  std::vector<mod_t> a(n), v;\n  for (auto &x : a) x = get_rand(1, MOD - 1);\n\
    \  mod_t tmp;\n  for (i = (n + 1) << 1; i--; v.push_back(tmp)) {\n    for (tmp\
    \ = 0, j = n; j--;) tmp += a[j] * b[j];\n    if (i) b = M * b;\n  }\n  auto ret\
    \ = berlekamp_massey(v);\n  for (auto &x : ret) x = -x;\n  return std::reverse(ret.begin(),\
    \ ret.end()), ret.push_back(1), ret;\n}\n\ntemplate <class mod_t>\nstruct SparseSquareMatrix\
    \ {\n  SparseSquareMatrix(std::size_t n_) : n(n_) {}\n  void add_component(std::size_t\
    \ i, std::size_t j, mod_t val) {\n    dat.emplace_back(i, j, val);\n  }\n  std::vector<mod_t>\
    \ operator*(const std::vector<mod_t> &vec) const {\n    std::vector<mod_t> ret(n);\n\
    \    assert(vec.size() == n);\n    for (const auto &[i, j, val] : dat) ret[i]\
    \ += val * vec[j];\n    return ret;\n  }\n  auto begin() { return dat.begin();\
    \ }\n  auto end() { return dat.end(); }\n  std::size_t size() const { return n;\
    \ }\n  mod_t det() const {\n    const std::uint64_t MOD = mod_t::modulo();\n \
    \   SparseSquareMatrix M(*this);\n    std::vector<mod_t> d(n), b(n);\n    for\
    \ (auto &x : b) x = get_rand(1, MOD - 1);\n    for (auto &x : d) x = get_rand(1,\
    \ MOD - 1);\n    for (auto &[i, j, val] : M) val *= d[j];\n    mod_t ret = minimal_polynomial(M,\
    \ b).front(), tmp = 1;\n    for (const auto &x : d) tmp *= x;\n    if (n & 1)\
    \ ret = -ret;\n    return ret / tmp;\n  }\n\n private:\n  std::size_t n;\n  std::vector<std::tuple<std::size_t,\
    \ std::size_t, mod_t>> dat;\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/berlekamp_massey.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u591A\u9805\u5F0F\u3068\u758E\u884C\u5217\n * @category\
    \ \u6570\u5B66\n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n */\n\
    \n// BEGIN CUT HERE\n\nstd::uint64_t get_rand(std::uint64_t l, std::uint64_t r)\
    \ {\n  static std::random_device rd;\n  static std::mt19937_64 gen(rd());\n  return\
    \ std::uniform_int_distribution<std::uint64_t>(l, r)(gen);\n}\n\n// (c[d] * M^d\
    \ + c[d-1] * M^(d-1)  + ... + c[1] * M + c[0]) * b = 0\n// return c\ntemplate\
    \ <class Mat, class Vec>\nauto minimal_polynomial(const Mat &M, Vec b) {\n  using\
    \ mod_t = std::remove_reference_t<decltype(b[0])>;\n  const std::uint64_t MOD\
    \ = mod_t::modulo();\n  std::size_t n = M.size(), i, j;\n  assert(n == b.size());\n\
    \  std::vector<mod_t> a(n), v;\n  for (auto &x : a) x = get_rand(1, MOD - 1);\n\
    \  mod_t tmp;\n  for (i = (n + 1) << 1; i--; v.push_back(tmp)) {\n    for (tmp\
    \ = 0, j = n; j--;) tmp += a[j] * b[j];\n    if (i) b = M * b;\n  }\n  auto ret\
    \ = berlekamp_massey(v);\n  for (auto &x : ret) x = -x;\n  return std::reverse(ret.begin(),\
    \ ret.end()), ret.push_back(1), ret;\n}\n\ntemplate <class mod_t>\nstruct SparseSquareMatrix\
    \ {\n  SparseSquareMatrix(std::size_t n_) : n(n_) {}\n  void add_component(std::size_t\
    \ i, std::size_t j, mod_t val) {\n    dat.emplace_back(i, j, val);\n  }\n  std::vector<mod_t>\
    \ operator*(const std::vector<mod_t> &vec) const {\n    std::vector<mod_t> ret(n);\n\
    \    assert(vec.size() == n);\n    for (const auto &[i, j, val] : dat) ret[i]\
    \ += val * vec[j];\n    return ret;\n  }\n  auto begin() { return dat.begin();\
    \ }\n  auto end() { return dat.end(); }\n  std::size_t size() const { return n;\
    \ }\n  mod_t det() const {\n    const std::uint64_t MOD = mod_t::modulo();\n \
    \   SparseSquareMatrix M(*this);\n    std::vector<mod_t> d(n), b(n);\n    for\
    \ (auto &x : b) x = get_rand(1, MOD - 1);\n    for (auto &x : d) x = get_rand(1,\
    \ MOD - 1);\n    for (auto &[i, j, val] : M) val *= d[j];\n    mod_t ret = minimal_polynomial(M,\
    \ b).front(), tmp = 1;\n    for (const auto &x : d) tmp *= x;\n    if (n & 1)\
    \ ret = -ret;\n    return ret / tmp;\n  }\n\n private:\n  std::size_t n;\n  std::vector<std::tuple<std::size_t,\
    \ std::size_t, mod_t>> dat;\n};\n"
  dependsOn:
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: false
  path: src/Math/minimal_polynomial.hpp
  requiredBy: []
  timestamp: '2022-06-21 23:28:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sparse_matrix_det.test.cpp
documentation_of: src/Math/minimal_polynomial.hpp
layout: document
redirect_from:
- /library/src/Math/minimal_polynomial.hpp
- /library/src/Math/minimal_polynomial.hpp.html
title: "\u6700\u5C0F\u591A\u9805\u5F0F\u3068\u758E\u884C\u5217"
---
