---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F"
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\n#include\
    \ <bits/stdc++.h>\n/**\n * @title \u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F\
    \n * @category \u7DDA\u5F62\u4EE3\u6570\n * O(N^3)\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <class K>\nstd::vector<std::vector<K>> hessenberg(const std::vector<std::vector<K>>\
    \ &a) {\n  std::size_t n = a.size();\n  auto ret = a;\n  for (std::size_t j =\
    \ 0; j + 2 < n; ++j) {\n    for (std::size_t i = j + 1; i < n; ++i)\n      if\
    \ (ret[i][j] != 0) {\n        std::swap(ret[j + 1], ret[i]);\n        for (std::size_t\
    \ r = 0; r < n; ++r) std::swap(ret[r][j + 1], ret[r][i]);\n        break;\n  \
    \    }\n    if (ret[j + 1][j] != 0)\n      for (std::size_t i = j + 2; i < n;\
    \ ++i) {\n        auto m = ret[i][j] / ret[j + 1][j];\n        for (std::size_t\
    \ c = j; c < n; ++c) ret[i][c] -= m * ret[j + 1][c];\n        for (std::size_t\
    \ r = 0; r < n; ++r) ret[r][j + 1] += m * ret[r][i];\n      }\n  }\n  return ret;\n\
    }\n\ntemplate <class K>\nstd::vector<K> characteristic_polynomial(const std::vector<std::vector<K>>\
    \ &a) {\n  std::size_t n = a.size();\n  auto b = hessenberg(a);\n  for (std::size_t\
    \ i = 0; i < n; i++)\n    for (std::size_t j = 0; j < n; j++) b[i][j] = -b[i][j];\n\
    \  std::vector<std::vector<K>> fss(n + 1);\n  fss[0] = {1};\n  for (std::size_t\
    \ i = 0; i < n; ++i) {\n    fss[i + 1].assign(i + 2, 0);\n    for (std::size_t\
    \ k = 0; k <= i; ++k) fss[i + 1][k + 1] = fss[i][k];\n    for (std::size_t k =\
    \ 0; k <= i; ++k) fss[i + 1][k] += b[i][i] * fss[i][k];\n    K prod = 1;\n   \
    \ for (std::size_t j = i; j--;) {\n      prod *= -b[j + 1][j];\n      const K\
    \ s = prod * b[j][i];\n      for (std::size_t k = 0; k <= j; ++k) fss[i + 1][k]\
    \ += s * fss[j][k];\n    }\n  }\n  return fss.back();\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u884C\u5217\u306E\
    \u7279\u6027\u591A\u9805\u5F0F\n * @category \u7DDA\u5F62\u4EE3\u6570\n * O(N^3)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class K>\nstd::vector<std::vector<K>> hessenberg(const\
    \ std::vector<std::vector<K>> &a) {\n  std::size_t n = a.size();\n  auto ret =\
    \ a;\n  for (std::size_t j = 0; j + 2 < n; ++j) {\n    for (std::size_t i = j\
    \ + 1; i < n; ++i)\n      if (ret[i][j] != 0) {\n        std::swap(ret[j + 1],\
    \ ret[i]);\n        for (std::size_t r = 0; r < n; ++r) std::swap(ret[r][j + 1],\
    \ ret[r][i]);\n        break;\n      }\n    if (ret[j + 1][j] != 0)\n      for\
    \ (std::size_t i = j + 2; i < n; ++i) {\n        auto m = ret[i][j] / ret[j +\
    \ 1][j];\n        for (std::size_t c = j; c < n; ++c) ret[i][c] -= m * ret[j +\
    \ 1][c];\n        for (std::size_t r = 0; r < n; ++r) ret[r][j + 1] += m * ret[r][i];\n\
    \      }\n  }\n  return ret;\n}\n\ntemplate <class K>\nstd::vector<K> characteristic_polynomial(const\
    \ std::vector<std::vector<K>> &a) {\n  std::size_t n = a.size();\n  auto b = hessenberg(a);\n\
    \  for (std::size_t i = 0; i < n; i++)\n    for (std::size_t j = 0; j < n; j++)\
    \ b[i][j] = -b[i][j];\n  std::vector<std::vector<K>> fss(n + 1);\n  fss[0] = {1};\n\
    \  for (std::size_t i = 0; i < n; ++i) {\n    fss[i + 1].assign(i + 2, 0);\n \
    \   for (std::size_t k = 0; k <= i; ++k) fss[i + 1][k + 1] = fss[i][k];\n    for\
    \ (std::size_t k = 0; k <= i; ++k) fss[i + 1][k] += b[i][i] * fss[i][k];\n   \
    \ K prod = 1;\n    for (std::size_t j = i; j--;) {\n      prod *= -b[j + 1][j];\n\
    \      const K s = prod * b[j][i];\n      for (std::size_t k = 0; k <= j; ++k)\
    \ fss[i + 1][k] += s * fss[j][k];\n    }\n  }\n  return fss.back();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/LinearAlgebra/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2022-06-22 15:08:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: src/LinearAlgebra/characteristic_polynomial.hpp
layout: document
redirect_from:
- /library/src/LinearAlgebra/characteristic_polynomial.hpp
- /library/src/LinearAlgebra/characteristic_polynomial.hpp.html
title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F"
---
