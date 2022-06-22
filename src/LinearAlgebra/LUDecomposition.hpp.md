---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':x:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':x:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
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
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':x:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "LU\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/LUDecomposition.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title LU\u5206\u89E3\n * @category \u7DDA\u5F62\u4EE3\u6570\n * bool\u578B\
    \u306E\u5834\u5408\u306Ekernel\u95A2\u6570 \u672Averify\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <class K, std::size_t MAX_ROWS = (1 << 12),\n          std::size_t\
    \ MAX_COLS = MAX_ROWS>\nclass LUDecomposition {\n  using Mat = std::vector<std::vector<K>>;\n\
    \  Mat dat;\n  std::vector<std::size_t> perm, piv;\n  bool sgn;\n  static bool\
    \ is_zero(K x) {\n    if constexpr (std::is_floating_point_v<K>)\n      return\
    \ std::abs(x) < 1e-8;\n    else\n      return x == T(0);\n  }\n\n public:\n  LUDecomposition(const\
    \ Mat &A) : dat(A), perm(A.size()), sgn(false) {\n    std::size_t rows = A.size(),\
    \ cols = A[0].size();\n    std::iota(perm.begin(), perm.end(), 0);\n    for (std::size_t\
    \ c = 0; c != cols && piv.size() != rows; c++) {\n      auto pos = piv.size();\n\
    \      if constexpr (IFPV<K>) {\n        for (std::size_t r = piv.size() + 1;\
    \ r < rows; r++)\n          if (std::abs(dat[pos][c]) < std::abs(dat[r][c])) pos\
    \ = r;\n      } else if (is_zero(dat[pos][c])) {\n        for (std::size_t r =\
    \ piv.size() + 1; r < rows; r++)\n          if (!is_zero(dat[r][c])) pos = r,\
    \ r = rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n      if (pos\
    \ != piv.size())\n        sgn = !sgn, std::swap(perm[pos], perm[piv.size()]),\n\
    \        std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r = piv.size()\
    \ + 1; r != rows; r++) {\n        auto m = dat[r][c] / dat[piv.size()][c];\n \
    \       dat[r][c] = 0, dat[r][piv.size()] = m;\n        for (std::size_t i = c\
    \ + 1; i != cols; i++)\n          dat[r][i] -= dat[piv.size()][i] * m;\n     \
    \ }\n      piv.emplace_back(c);\n    }\n  }\n  std::size_t rank() const { return\
    \ piv.size(); }\n  bool isregular() const {\n    return rank() == dat.size() &&\
    \ rank() == dat[0].size();\n  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n\
    \    K d = sgn ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d\
    \ *= dat[i][i];\n    return d;\n  }\n  std::vector<std::vector<K>> kernel() const\
    \ {\n    std::size_t cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols\
    \ - rank(), std::vector<K>(cols));\n    for (std::size_t c = 0, i = 0; c != cols;\
    \ c++) {\n      if (i != piv.size() && piv[i] == c) {\n        i++;\n        continue;\n\
    \      }\n      ker[c - i][c] = 1;\n      for (std::size_t r = 0; r != i; r++)\
    \ ker[c - i][r] = -dat[r][c];\n      for (std::size_t j = i; j--;) {\n       \
    \ auto x = ker[c - i][j] / dat[j][piv[j]];\n        ker[c - i][j] = 0, ker[c -\
    \ i][piv[j]] = x;\n        for (std::size_t r = 0; r != j; r++)\n          ker[c\
    \ - i][r] -= dat[r][piv[j]] * x;\n      }\n    }\n    return ker;\n  }\n  std::vector<K>\
    \ linear_equations(const std::vector<K> &b) const {\n    std::size_t rows = dat.size(),\
    \ cols = dat[0].size();\n    assert(rows <= b.size());\n    std::vector<K> y(rows),\
    \ x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n      y[c] += b[perm[c]];\n\
    \      if (c < cols)\n        for (std::size_t r = c + 1; r != rows; r++) y[r]\
    \ -= y[c] * dat[r][c];\n    }\n    for (std::size_t i = rank(); i != rows; i++)\n\
    \      if (!is_zero(y[i])) return {};  // no solution\n    for (std::size_t i\
    \ = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n      for (std::size_t\
    \ r = 0; r != i; r++) y[r] -= x[piv[i]] * dat[r][piv[i]];\n    }\n    return x;\n\
    \  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  // no\
    \ solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K> b(dat.size());\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++] = 0)\n     \
    \ b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0;\
    \ i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <std::size_t MAX_ROWS, std::size_t\
    \ MAX_COLS>\nclass LUDecomposition<bool, MAX_ROWS, MAX_COLS> {\n public:\n  using\
    \ Mat = std::vector<std::vector<bool>>;\n  std::size_t rows, cols;\n  std::vector<std::bitset<MAX_ROWS>>\
    \ tdat, tdat2;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()), cols(A[0].size()), tdat(cols), tdat2(cols),\
    \ perm(rows) {\n    std::vector<std::bitset<MAX_COLS>> dat(rows);\n    for (std::size_t\
    \ i = 0; i < rows; i++)\n      for (std::size_t j = 0; j < cols; j++) dat[i][j]\
    \ = A[i][j];\n    std::iota(perm.begin(), perm.end(), 0);\n    std::bitset<MAX_COLS>\
    \ mask;\n    for (std::size_t c = 1; c < cols; c++) mask.set(c);\n    for (std::size_t\
    \ c = 0; c < cols && piv.size() < rows; c++) {\n      mask.reset(c);\n      auto\
    \ pos = piv.size();\n      for (std::size_t r = piv.size(); r < rows; r++)\n \
    \       if (bool(dat[r][c])) pos = r, r = rows;\n      if (!bool(dat[pos][c]))\
    \ continue;\n      if (pos != piv.size())\n        std::swap(perm[pos], perm[piv.size()]),\n\
    \            std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r =\
    \ piv.size() + 1; r != rows; r++) {\n        auto m = bool(dat[r][c]);\n     \
    \   dat[r][c] = 0, dat[r][piv.size()] = m;\n        if (m) dat[r] ^= dat[piv.size()]\
    \ & mask;\n      }\n      piv.push_back(c);\n    }\n    for (std::size_t j = 0;\
    \ j < cols; j++)\n      for (std::size_t i = j + 1; i < rows; i++) tdat[j][i]\
    \ = dat[i][j];\n    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      for\
    \ (std::size_t r = 0; r < i; r++) tdat2[c][r] = dat[r][c];\n      if (i != piv.size()\
    \ && piv[i] == c) i++;\n    }\n  }\n  std::size_t rank() const { return piv.size();\
    \ }\n  bool isregular() const { return rank() == rows && rank() == cols; }\n \
    \ bool det() const { return isregular(); }\n  std::vector<std::vector<bool>> kernel()\
    \ const {\n    std::vector<std::bitset<MAX_COLS>> ker(cols - rank());\n    for\
    \ (std::size_t c = 0, i = 0; c != cols; c++) {\n      if (i != piv.size() && piv[i]\
    \ == c) {\n        i++;\n        continue;\n      }\n      ker[c - i] = tdat2[c],\
    \ ker[c - i][c] = 1;\n      for (std::size_t j = i; j--;) {\n        auto x =\
    \ bool(ker[c - i][j]);\n        ker[c - i][j] = 0, ker[c - i][piv[j]] = x;\n \
    \       if (x) ker[c - i] ^= tdat2[piv[j]];\n      }\n    }\n    std::vector<std::vector<bool>>\
    \ ret(cols - rank(), std::vector<bool>(cols));\n    for (std::size_t i = cols\
    \ - rank(); i--;)\n      for (std::size_t j = 0; j < cols; j++) ret[i][j] = ker[i][j];\n\
    \    return ret;\n  }\n  std::vector<bool> linear_equations(const std::vector<bool>\
    \ &b) const {\n    assert(rows <= b.size());\n    std::bitset<MAX_COLS> y;\n \
    \   std::vector<bool> x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n\
    \      if (b[perm[c]]) y[c].flip();\n      if (c < cols && bool(y[c])) y ^= tdat[c];\n\
    \    }\n    for (std::size_t i = rank(); i != rows; i++)\n      if (bool(y[i]))\
    \ return {};  // no solution\n    for (std::size_t i = rank(); i--;) {\n     \
    \ x[piv[i]] = y[i];\n      if (x[piv[i]]) y ^= tdat2[piv[i]];\n    }\n    return\
    \ x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  //\
    \ no solution\n    std::vector<bool> b(rows);\n    Mat ret;\n    for (std::size_t\
    \ i = 0; i < rows; b[i++] = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n\
    \    for (std::size_t i = 0; i < rows; i++)\n      for (std::size_t j = 0; j <\
    \ i; j++) std::swap(ret[i][j], ret[j][i]);\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title LU\u5206\u89E3\n *\
    \ @category \u7DDA\u5F62\u4EE3\u6570\n * bool\u578B\u306E\u5834\u5408\u306Ekernel\u95A2\
    \u6570 \u672Averify\n */\n\n// BEGIN CUT HERE\n\ntemplate <class K, std::size_t\
    \ MAX_ROWS = (1 << 12),\n          std::size_t MAX_COLS = MAX_ROWS>\nclass LUDecomposition\
    \ {\n  using Mat = std::vector<std::vector<K>>;\n  Mat dat;\n  std::vector<std::size_t>\
    \ perm, piv;\n  bool sgn;\n  static bool is_zero(K x) {\n    if constexpr (std::is_floating_point_v<K>)\n\
    \      return std::abs(x) < 1e-8;\n    else\n      return x == T(0);\n  }\n\n\
    \ public:\n  LUDecomposition(const Mat &A) : dat(A), perm(A.size()), sgn(false)\
    \ {\n    std::size_t rows = A.size(), cols = A[0].size();\n    std::iota(perm.begin(),\
    \ perm.end(), 0);\n    for (std::size_t c = 0; c != cols && piv.size() != rows;\
    \ c++) {\n      auto pos = piv.size();\n      if constexpr (IFPV<K>) {\n     \
    \   for (std::size_t r = piv.size() + 1; r < rows; r++)\n          if (std::abs(dat[pos][c])\
    \ < std::abs(dat[r][c])) pos = r;\n      } else if (is_zero(dat[pos][c])) {\n\
    \        for (std::size_t r = piv.size() + 1; r < rows; r++)\n          if (!is_zero(dat[r][c]))\
    \ pos = r, r = rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n   \
    \   if (pos != piv.size())\n        sgn = !sgn, std::swap(perm[pos], perm[piv.size()]),\n\
    \        std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r = piv.size()\
    \ + 1; r != rows; r++) {\n        auto m = dat[r][c] / dat[piv.size()][c];\n \
    \       dat[r][c] = 0, dat[r][piv.size()] = m;\n        for (std::size_t i = c\
    \ + 1; i != cols; i++)\n          dat[r][i] -= dat[piv.size()][i] * m;\n     \
    \ }\n      piv.emplace_back(c);\n    }\n  }\n  std::size_t rank() const { return\
    \ piv.size(); }\n  bool isregular() const {\n    return rank() == dat.size() &&\
    \ rank() == dat[0].size();\n  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n\
    \    K d = sgn ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d\
    \ *= dat[i][i];\n    return d;\n  }\n  std::vector<std::vector<K>> kernel() const\
    \ {\n    std::size_t cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols\
    \ - rank(), std::vector<K>(cols));\n    for (std::size_t c = 0, i = 0; c != cols;\
    \ c++) {\n      if (i != piv.size() && piv[i] == c) {\n        i++;\n        continue;\n\
    \      }\n      ker[c - i][c] = 1;\n      for (std::size_t r = 0; r != i; r++)\
    \ ker[c - i][r] = -dat[r][c];\n      for (std::size_t j = i; j--;) {\n       \
    \ auto x = ker[c - i][j] / dat[j][piv[j]];\n        ker[c - i][j] = 0, ker[c -\
    \ i][piv[j]] = x;\n        for (std::size_t r = 0; r != j; r++)\n          ker[c\
    \ - i][r] -= dat[r][piv[j]] * x;\n      }\n    }\n    return ker;\n  }\n  std::vector<K>\
    \ linear_equations(const std::vector<K> &b) const {\n    std::size_t rows = dat.size(),\
    \ cols = dat[0].size();\n    assert(rows <= b.size());\n    std::vector<K> y(rows),\
    \ x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n      y[c] += b[perm[c]];\n\
    \      if (c < cols)\n        for (std::size_t r = c + 1; r != rows; r++) y[r]\
    \ -= y[c] * dat[r][c];\n    }\n    for (std::size_t i = rank(); i != rows; i++)\n\
    \      if (!is_zero(y[i])) return {};  // no solution\n    for (std::size_t i\
    \ = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n      for (std::size_t\
    \ r = 0; r != i; r++) y[r] -= x[piv[i]] * dat[r][piv[i]];\n    }\n    return x;\n\
    \  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  // no\
    \ solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K> b(dat.size());\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++] = 0)\n     \
    \ b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0;\
    \ i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <std::size_t MAX_ROWS, std::size_t\
    \ MAX_COLS>\nclass LUDecomposition<bool, MAX_ROWS, MAX_COLS> {\n public:\n  using\
    \ Mat = std::vector<std::vector<bool>>;\n  std::size_t rows, cols;\n  std::vector<std::bitset<MAX_ROWS>>\
    \ tdat, tdat2;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()), cols(A[0].size()), tdat(cols), tdat2(cols),\
    \ perm(rows) {\n    std::vector<std::bitset<MAX_COLS>> dat(rows);\n    for (std::size_t\
    \ i = 0; i < rows; i++)\n      for (std::size_t j = 0; j < cols; j++) dat[i][j]\
    \ = A[i][j];\n    std::iota(perm.begin(), perm.end(), 0);\n    std::bitset<MAX_COLS>\
    \ mask;\n    for (std::size_t c = 1; c < cols; c++) mask.set(c);\n    for (std::size_t\
    \ c = 0; c < cols && piv.size() < rows; c++) {\n      mask.reset(c);\n      auto\
    \ pos = piv.size();\n      for (std::size_t r = piv.size(); r < rows; r++)\n \
    \       if (bool(dat[r][c])) pos = r, r = rows;\n      if (!bool(dat[pos][c]))\
    \ continue;\n      if (pos != piv.size())\n        std::swap(perm[pos], perm[piv.size()]),\n\
    \            std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r =\
    \ piv.size() + 1; r != rows; r++) {\n        auto m = bool(dat[r][c]);\n     \
    \   dat[r][c] = 0, dat[r][piv.size()] = m;\n        if (m) dat[r] ^= dat[piv.size()]\
    \ & mask;\n      }\n      piv.push_back(c);\n    }\n    for (std::size_t j = 0;\
    \ j < cols; j++)\n      for (std::size_t i = j + 1; i < rows; i++) tdat[j][i]\
    \ = dat[i][j];\n    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      for\
    \ (std::size_t r = 0; r < i; r++) tdat2[c][r] = dat[r][c];\n      if (i != piv.size()\
    \ && piv[i] == c) i++;\n    }\n  }\n  std::size_t rank() const { return piv.size();\
    \ }\n  bool isregular() const { return rank() == rows && rank() == cols; }\n \
    \ bool det() const { return isregular(); }\n  std::vector<std::vector<bool>> kernel()\
    \ const {\n    std::vector<std::bitset<MAX_COLS>> ker(cols - rank());\n    for\
    \ (std::size_t c = 0, i = 0; c != cols; c++) {\n      if (i != piv.size() && piv[i]\
    \ == c) {\n        i++;\n        continue;\n      }\n      ker[c - i] = tdat2[c],\
    \ ker[c - i][c] = 1;\n      for (std::size_t j = i; j--;) {\n        auto x =\
    \ bool(ker[c - i][j]);\n        ker[c - i][j] = 0, ker[c - i][piv[j]] = x;\n \
    \       if (x) ker[c - i] ^= tdat2[piv[j]];\n      }\n    }\n    std::vector<std::vector<bool>>\
    \ ret(cols - rank(), std::vector<bool>(cols));\n    for (std::size_t i = cols\
    \ - rank(); i--;)\n      for (std::size_t j = 0; j < cols; j++) ret[i][j] = ker[i][j];\n\
    \    return ret;\n  }\n  std::vector<bool> linear_equations(const std::vector<bool>\
    \ &b) const {\n    assert(rows <= b.size());\n    std::bitset<MAX_COLS> y;\n \
    \   std::vector<bool> x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n\
    \      if (b[perm[c]]) y[c].flip();\n      if (c < cols && bool(y[c])) y ^= tdat[c];\n\
    \    }\n    for (std::size_t i = rank(); i != rows; i++)\n      if (bool(y[i]))\
    \ return {};  // no solution\n    for (std::size_t i = rank(); i--;) {\n     \
    \ x[piv[i]] = y[i];\n      if (x[piv[i]]) y ^= tdat2[piv[i]];\n    }\n    return\
    \ x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  //\
    \ no solution\n    std::vector<bool> b(rows);\n    Mat ret;\n    for (std::size_t\
    \ i = 0; i < rows; b[i++] = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n\
    \    for (std::size_t i = 0; i < rows; i++)\n      for (std::size_t j = 0; j <\
    \ i; j++) std::swap(ret[i][j], ret[j][i]);\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/LinearAlgebra/LUDecomposition.hpp
  requiredBy: []
  timestamp: '2022-06-22 15:08:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/linear_equations.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2624.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/184.test.cpp
documentation_of: src/LinearAlgebra/LUDecomposition.hpp
layout: document
redirect_from:
- /library/src/LinearAlgebra/LUDecomposition.hpp
- /library/src/LinearAlgebra/LUDecomposition.hpp.html
title: "LU\u5206\u89E3"
---
