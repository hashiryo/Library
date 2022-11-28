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
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "LU\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/LUDecomposition.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title LU\u5206\u89E3\n * @category \u7DDA\u5F62\u4EE3\u6570\n */\n\n\
    // BEGIN CUT HERE\ntemplate <class K>\nclass LUDecomposition {\n  using Mat =\
    \ std::vector<std::vector<K>>;\n  Mat dat;\n  std::vector<std::size_t> perm, piv;\n\
    \  bool sgn;\n  static bool is_zero(K x) {\n    if constexpr (std::is_floating_point_v<K>)\n\
    \      return std::abs(x) < 1e-8;\n    else\n      return x == K(0);\n  }\n\n\
    \ public:\n  LUDecomposition(const Mat &A) : dat(A), perm(A.size()), sgn(false)\
    \ {\n    std::size_t rows = A.size(), cols = A[0].size();\n    std::iota(perm.begin(),\
    \ perm.end(), 0);\n    for (std::size_t c = 0, psz = 0; c != cols && psz != rows;\
    \ c++) {\n      auto pos = psz;\n      if constexpr (std::is_floating_point_v<K>)\
    \ {\n        for (std::size_t r = psz + 1; r < rows; r++)\n          if (std::abs(dat[pos][c])\
    \ < std::abs(dat[r][c])) pos = r;\n      } else if (is_zero(dat[pos][c])) {\n\
    \        for (std::size_t r = psz + 1; r < rows; r++)\n          if (!is_zero(dat[r][c]))\
    \ pos = r, r = rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n   \
    \   if (pos != psz)\n        sgn = !sgn, std::swap(perm[pos], perm[psz]), dat[pos].swap(dat[psz]);\n\
    \      for (std::size_t r = psz + 1; r < rows; r++) {\n        auto m = dat[r][c]\
    \ / dat[psz][c];\n        dat[r][c] = 0, dat[r][psz] = m;\n        for (std::size_t\
    \ i = c + 1; i < cols; i++) dat[r][i] -= dat[psz][i] * m;\n      }\n      piv.emplace_back(c),\
    \ psz++;\n    }\n  }\n  std::size_t rank() const { return piv.size(); }\n  bool\
    \ isregular() const {\n    return rank() == dat.size() && rank() == dat[0].size();\n\
    \  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n    K d = sgn\
    \ ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d *= dat[i][i];\n\
    \    return d;\n  }\n  std::vector<std::vector<K>> kernel() const {\n    std::size_t\
    \ cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols - rank(), std::vector<K>(cols));\n\
    \    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      if (i < piv.size()\
    \ && piv[i] == c) {\n        i++;\n        continue;\n      }\n      ker[c - i][c]\
    \ = 1;\n      for (std::size_t r = i; r--;) ker[c - i][r] = -dat[r][c];\n    \
    \  for (std::size_t j = i, k; j--;) {\n        auto x = ker[c - i][j] / dat[j][k\
    \ = piv[j]];\n        ker[c - i][j] = 0, ker[c - i][k] = x;\n        for (std::size_t\
    \ r = j; r--;) ker[c - i][r] -= dat[r][k] * x;\n      }\n    }\n    return ker;\n\
    \  }\n  std::vector<K> linear_equations(const std::vector<K> &b) const {\n   \
    \ std::size_t rows = dat.size(), cols = dat[0].size();\n    assert(rows <= b.size());\n\
    \    std::vector<K> y(rows), x(cols);\n    for (std::size_t c = 0; c < rows; c++)\n\
    \      if (y[c] += b[perm[c]]; c < cols)\n        for (std::size_t r = c + 1;\
    \ r < rows; r++) y[r] -= y[c] * dat[r][c];\n    for (std::size_t i = rank(); i\
    \ < rows; i++)\n      if (!is_zero(y[i])) return {};  // no solution\n    for\
    \ (std::size_t i = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n\
    \      for (std::size_t r = i; r--;) y[r] -= x[piv[i]] * dat[r][piv[i]];\n   \
    \ }\n    return x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular())\
    \ return {};  // no solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K>\
    \ b(dat.size());\n    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++]\
    \ = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t\
    \ i = 0; i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <>\nclass LUDecomposition<bool>\
    \ {\n public:\n  using Mat = std::vector<std::vector<bool>>;\n  using u128 = __uint128_t;\n\
    \  const std::size_t rows, cols, row128, col128;\n  std::vector<std::vector<u128>>\
    \ tdat;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()),\n        cols(A[0].size()),\n        row128((rows\
    \ + 127) >> 7),\n        col128((cols + 127) >> 7),\n        tdat(cols, std::vector<u128>(row128)),\n\
    \        perm(rows) {\n    std::vector dat(rows, std::vector<u128>(col128));\n\
    \    for (std::size_t i = rows; i--;)\n      for (std::size_t j = cols; j--;)\n\
    \        dat[i][j >> 7] |= u128(A[i][j]) << (j & 127);\n    std::iota(perm.begin(),\
    \ perm.end(), 0);\n    for (std::size_t c = 0, psz = 0; c < cols && psz < rows;\
    \ c++) {\n      auto pos = psz, a = c >> 7, b = c & 127;\n      for (std::size_t\
    \ r = psz; r < rows; r++)\n        if ((dat[r][a] >> b) & 1) pos = r, r = rows;\n\
    \      if (!((dat[pos][a] >> b) & 1)) continue;\n      if (pos != psz) std::swap(perm[pos],\
    \ perm[psz]), dat[pos].swap(dat[psz]);\n      for (std::size_t r = psz + 1; r\
    \ < rows; r++) {\n        if ((dat[r][a] >> b) & 1) {\n          for (auto i =\
    \ a + 1; i < col128; i++) dat[r][i] ^= dat[psz][i];\n          dat[r][a] ^= dat[psz][a]\
    \ & u128(-(u128(1) << b));\n          dat[r][psz >> 7] |= u128(1) << (psz & 127);\n\
    \        }\n      }\n      piv.push_back(c), psz++;\n    }\n    for (std::size_t\
    \ j = cols; j--;)\n      for (std::size_t i = rows; i--;)\n        tdat[j][i >>\
    \ 7] |= u128((dat[i][j >> 7] >> (j & 127)) & 1) << (i & 127);\n  }\n  std::size_t\
    \ rank() const { return piv.size(); }\n  bool isregular() const { return rank()\
    \ == rows && rank() == cols; }\n  bool det() const { return isregular(); }\n \
    \ std::vector<std::vector<bool>> kernel() const {\n    std::vector ker(cols -\
    \ rank(), std::vector<u128>(col128));\n    for (std::size_t c = 0, i = 0; c <\
    \ cols; c++) {\n      if (i < piv.size() && piv[i] == c) {\n        i++;\n   \
    \     continue;\n      }\n      ker[c - i][c >> 7] |= u128(1) << (c & 127);\n\
    \      for (std::size_t r = i >> 7; r--;) ker[c - i][r] = tdat[c][r];\n      ker[c\
    \ - i][i >> 7] = tdat[c][i >> 7] & ((u128(1) << (i & 127)) - 1);\n      for (std::size_t\
    \ j = i; j--;) {\n        if (std::size_t k = piv[j]; (ker[c - i][j >> 7] >> (j\
    \ & 127)) & 1) {\n          for (std::size_t r = j >> 7; r--;) ker[c - i][r] ^=\
    \ tdat[k][r];\n          ker[c - i][j >> 7] ^= tdat[k][j >> 7] & ((u128(1) <<\
    \ (j & 127)) - 1);\n          ker[c - i][k >> 7] |= u128(1) << (k & 127);\n  \
    \      }\n      }\n    }\n    std::vector ret(cols - rank(), std::vector<bool>(cols));\n\
    \    for (std::size_t i = cols - rank(); i--;)\n      for (std::size_t j = cols;\
    \ j--;) ret[i][j] = ker[i][j >> 7] << (j & 127);\n    return ret;\n  }\n  std::vector<bool>\
    \ linear_equations(const std::vector<bool> &b) const {\n    assert(rows <= b.size());\n\
    \    std::vector<u128> y(row128);\n    std::vector<bool> x(cols);\n    for (std::size_t\
    \ c = 0; c < rows; c++) {\n      y[c >> 7] ^= u128(b[perm[c]]) << (c & 127);\n\
    \      if ((c < cols) & (y[c >> 7] >> (c & 127)))\n        if (std::size_t a =\
    \ (c + 1) >> 7; a < row128) {\n          for (std::size_t r = a + 1; r < row128;\
    \ r++) y[r] ^= tdat[c][r];\n          y[a] ^= tdat[c][a] & u128(-(u128(1) << ((c\
    \ + 1) & 127)));\n        }\n    }\n    if ((rank() >> 7) < row128 && (y[rank()\
    \ >> 7] >> (rank() & 127)))\n      return {};  // no solution\n    for (std::size_t\
    \ r = (rank() >> 7) + 1; r < row128; r++)\n      if (y[r]) return {};  // no solution\n\
    \    for (std::size_t i = rank(); i--;)\n      if (std::size_t k = piv[i]; (x[k]\
    \ = (y[i >> 7] >> (i & 127)) & 1)) {\n        for (std::size_t r = i >> 7; r--;)\
    \ y[r] ^= tdat[k][r];\n        y[i >> 7] ^= tdat[k][i >> 7] & ((u128(1) << (i\
    \ & 127)) - 1);\n      }\n    return x;\n  }\n  Mat inverse_matrix() const {\n\
    \    if (!isregular()) return {};  // no solution\n    std::vector<bool> b(rows);\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < rows; b[i++] = 0)\n      b[i] =\
    \ 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0; i < rows;\
    \ i++)\n      for (std::size_t j = 0; j < i; j++) {\n        bool tmp = ret[i][j];\n\
    \        ret[i][j] = ret[j][i];\n        ret[j][i] = tmp;\n      }\n    return\
    \ ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title LU\u5206\u89E3\n *\
    \ @category \u7DDA\u5F62\u4EE3\u6570\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ K>\nclass LUDecomposition {\n  using Mat = std::vector<std::vector<K>>;\n  Mat\
    \ dat;\n  std::vector<std::size_t> perm, piv;\n  bool sgn;\n  static bool is_zero(K\
    \ x) {\n    if constexpr (std::is_floating_point_v<K>)\n      return std::abs(x)\
    \ < 1e-8;\n    else\n      return x == K(0);\n  }\n\n public:\n  LUDecomposition(const\
    \ Mat &A) : dat(A), perm(A.size()), sgn(false) {\n    std::size_t rows = A.size(),\
    \ cols = A[0].size();\n    std::iota(perm.begin(), perm.end(), 0);\n    for (std::size_t\
    \ c = 0, psz = 0; c != cols && psz != rows; c++) {\n      auto pos = psz;\n  \
    \    if constexpr (std::is_floating_point_v<K>) {\n        for (std::size_t r\
    \ = psz + 1; r < rows; r++)\n          if (std::abs(dat[pos][c]) < std::abs(dat[r][c]))\
    \ pos = r;\n      } else if (is_zero(dat[pos][c])) {\n        for (std::size_t\
    \ r = psz + 1; r < rows; r++)\n          if (!is_zero(dat[r][c])) pos = r, r =\
    \ rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n      if (pos !=\
    \ psz)\n        sgn = !sgn, std::swap(perm[pos], perm[psz]), dat[pos].swap(dat[psz]);\n\
    \      for (std::size_t r = psz + 1; r < rows; r++) {\n        auto m = dat[r][c]\
    \ / dat[psz][c];\n        dat[r][c] = 0, dat[r][psz] = m;\n        for (std::size_t\
    \ i = c + 1; i < cols; i++) dat[r][i] -= dat[psz][i] * m;\n      }\n      piv.emplace_back(c),\
    \ psz++;\n    }\n  }\n  std::size_t rank() const { return piv.size(); }\n  bool\
    \ isregular() const {\n    return rank() == dat.size() && rank() == dat[0].size();\n\
    \  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n    K d = sgn\
    \ ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d *= dat[i][i];\n\
    \    return d;\n  }\n  std::vector<std::vector<K>> kernel() const {\n    std::size_t\
    \ cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols - rank(), std::vector<K>(cols));\n\
    \    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      if (i < piv.size()\
    \ && piv[i] == c) {\n        i++;\n        continue;\n      }\n      ker[c - i][c]\
    \ = 1;\n      for (std::size_t r = i; r--;) ker[c - i][r] = -dat[r][c];\n    \
    \  for (std::size_t j = i, k; j--;) {\n        auto x = ker[c - i][j] / dat[j][k\
    \ = piv[j]];\n        ker[c - i][j] = 0, ker[c - i][k] = x;\n        for (std::size_t\
    \ r = j; r--;) ker[c - i][r] -= dat[r][k] * x;\n      }\n    }\n    return ker;\n\
    \  }\n  std::vector<K> linear_equations(const std::vector<K> &b) const {\n   \
    \ std::size_t rows = dat.size(), cols = dat[0].size();\n    assert(rows <= b.size());\n\
    \    std::vector<K> y(rows), x(cols);\n    for (std::size_t c = 0; c < rows; c++)\n\
    \      if (y[c] += b[perm[c]]; c < cols)\n        for (std::size_t r = c + 1;\
    \ r < rows; r++) y[r] -= y[c] * dat[r][c];\n    for (std::size_t i = rank(); i\
    \ < rows; i++)\n      if (!is_zero(y[i])) return {};  // no solution\n    for\
    \ (std::size_t i = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n\
    \      for (std::size_t r = i; r--;) y[r] -= x[piv[i]] * dat[r][piv[i]];\n   \
    \ }\n    return x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular())\
    \ return {};  // no solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K>\
    \ b(dat.size());\n    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++]\
    \ = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t\
    \ i = 0; i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <>\nclass LUDecomposition<bool>\
    \ {\n public:\n  using Mat = std::vector<std::vector<bool>>;\n  using u128 = __uint128_t;\n\
    \  const std::size_t rows, cols, row128, col128;\n  std::vector<std::vector<u128>>\
    \ tdat;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()),\n        cols(A[0].size()),\n        row128((rows\
    \ + 127) >> 7),\n        col128((cols + 127) >> 7),\n        tdat(cols, std::vector<u128>(row128)),\n\
    \        perm(rows) {\n    std::vector dat(rows, std::vector<u128>(col128));\n\
    \    for (std::size_t i = rows; i--;)\n      for (std::size_t j = cols; j--;)\n\
    \        dat[i][j >> 7] |= u128(A[i][j]) << (j & 127);\n    std::iota(perm.begin(),\
    \ perm.end(), 0);\n    for (std::size_t c = 0, psz = 0; c < cols && psz < rows;\
    \ c++) {\n      auto pos = psz, a = c >> 7, b = c & 127;\n      for (std::size_t\
    \ r = psz; r < rows; r++)\n        if ((dat[r][a] >> b) & 1) pos = r, r = rows;\n\
    \      if (!((dat[pos][a] >> b) & 1)) continue;\n      if (pos != psz) std::swap(perm[pos],\
    \ perm[psz]), dat[pos].swap(dat[psz]);\n      for (std::size_t r = psz + 1; r\
    \ < rows; r++) {\n        if ((dat[r][a] >> b) & 1) {\n          for (auto i =\
    \ a + 1; i < col128; i++) dat[r][i] ^= dat[psz][i];\n          dat[r][a] ^= dat[psz][a]\
    \ & u128(-(u128(1) << b));\n          dat[r][psz >> 7] |= u128(1) << (psz & 127);\n\
    \        }\n      }\n      piv.push_back(c), psz++;\n    }\n    for (std::size_t\
    \ j = cols; j--;)\n      for (std::size_t i = rows; i--;)\n        tdat[j][i >>\
    \ 7] |= u128((dat[i][j >> 7] >> (j & 127)) & 1) << (i & 127);\n  }\n  std::size_t\
    \ rank() const { return piv.size(); }\n  bool isregular() const { return rank()\
    \ == rows && rank() == cols; }\n  bool det() const { return isregular(); }\n \
    \ std::vector<std::vector<bool>> kernel() const {\n    std::vector ker(cols -\
    \ rank(), std::vector<u128>(col128));\n    for (std::size_t c = 0, i = 0; c <\
    \ cols; c++) {\n      if (i < piv.size() && piv[i] == c) {\n        i++;\n   \
    \     continue;\n      }\n      ker[c - i][c >> 7] |= u128(1) << (c & 127);\n\
    \      for (std::size_t r = i >> 7; r--;) ker[c - i][r] = tdat[c][r];\n      ker[c\
    \ - i][i >> 7] = tdat[c][i >> 7] & ((u128(1) << (i & 127)) - 1);\n      for (std::size_t\
    \ j = i; j--;) {\n        if (std::size_t k = piv[j]; (ker[c - i][j >> 7] >> (j\
    \ & 127)) & 1) {\n          for (std::size_t r = j >> 7; r--;) ker[c - i][r] ^=\
    \ tdat[k][r];\n          ker[c - i][j >> 7] ^= tdat[k][j >> 7] & ((u128(1) <<\
    \ (j & 127)) - 1);\n          ker[c - i][k >> 7] |= u128(1) << (k & 127);\n  \
    \      }\n      }\n    }\n    std::vector ret(cols - rank(), std::vector<bool>(cols));\n\
    \    for (std::size_t i = cols - rank(); i--;)\n      for (std::size_t j = cols;\
    \ j--;) ret[i][j] = ker[i][j >> 7] << (j & 127);\n    return ret;\n  }\n  std::vector<bool>\
    \ linear_equations(const std::vector<bool> &b) const {\n    assert(rows <= b.size());\n\
    \    std::vector<u128> y(row128);\n    std::vector<bool> x(cols);\n    for (std::size_t\
    \ c = 0; c < rows; c++) {\n      y[c >> 7] ^= u128(b[perm[c]]) << (c & 127);\n\
    \      if ((c < cols) & (y[c >> 7] >> (c & 127)))\n        if (std::size_t a =\
    \ (c + 1) >> 7; a < row128) {\n          for (std::size_t r = a + 1; r < row128;\
    \ r++) y[r] ^= tdat[c][r];\n          y[a] ^= tdat[c][a] & u128(-(u128(1) << ((c\
    \ + 1) & 127)));\n        }\n    }\n    if ((rank() >> 7) < row128 && (y[rank()\
    \ >> 7] >> (rank() & 127)))\n      return {};  // no solution\n    for (std::size_t\
    \ r = (rank() >> 7) + 1; r < row128; r++)\n      if (y[r]) return {};  // no solution\n\
    \    for (std::size_t i = rank(); i--;)\n      if (std::size_t k = piv[i]; (x[k]\
    \ = (y[i >> 7] >> (i & 127)) & 1)) {\n        for (std::size_t r = i >> 7; r--;)\
    \ y[r] ^= tdat[k][r];\n        y[i >> 7] ^= tdat[k][i >> 7] & ((u128(1) << (i\
    \ & 127)) - 1);\n      }\n    return x;\n  }\n  Mat inverse_matrix() const {\n\
    \    if (!isregular()) return {};  // no solution\n    std::vector<bool> b(rows);\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < rows; b[i++] = 0)\n      b[i] =\
    \ 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0; i < rows;\
    \ i++)\n      for (std::size_t j = 0; j < i; j++) {\n        bool tmp = ret[i][j];\n\
    \        ret[i][j] = ret[j][i];\n        ret[j][i] = tmp;\n      }\n    return\
    \ ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/LinearAlgebra/LUDecomposition.hpp
  requiredBy: []
  timestamp: '2022-11-28 13:23:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/803.test.cpp
  - test/yukicoder/184.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/linear_equations.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/2624.test.cpp
documentation_of: src/LinearAlgebra/LUDecomposition.hpp
layout: document
redirect_from:
- /library/src/LinearAlgebra/LUDecomposition.hpp
- /library/src/LinearAlgebra/LUDecomposition.hpp.html
title: "LU\u5206\u89E3"
---
