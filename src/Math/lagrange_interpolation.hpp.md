---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
    title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/42.test.cpp
    title: test/yukicoder/42.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
    links:
    - http://codeforces.com/contest/622/problem/F
  bundledCode: "#line 2 \"src/Math/lagrange_interpolation.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\n * @category\
    \ \u6570\u5B66\n *  x=0,1,..,N-1\u3068y=f(0),f(1),...,f(N-1)\u304C\u4E0E\u3048\
    \u3089\u308C\u305F\u3068\u304D\u306Ef(t)\u3092\u8A08\u7B97\n *  O(N)\n */\n\n\
    // verify\u7528:http://codeforces.com/contest/622/problem/F\n\n// BEGIN CUT HERE\n\
    \ntemplate <typename K>\nK lagrange_interpolation(std::vector<K> &y, K t) {\n\
    \  int n = y.size() - 1;\n  std::vector<K> pro(n + 1, 1), orp(n + 1, 1);\n  for\
    \ (int i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));\n  for (int i = n;\
    \ i > 0; i--) orp[i - 1] = orp[i] * (t - K(i));\n  K fact = K(1);\n  for (int\
    \ i = 1; i <= n; i++) fact *= K(i);\n  std::vector<K> finv(n + 1, 1);\n  finv[n]\
    \ = K(1) / fact;\n  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * K(i);\n\
    \  K res(0);\n  for (int i = 0; i <= n; i++) {\n    K tmp = y[i] * pro[i] * orp[i]\
    \ * finv[i] * finv[n - i];\n    res += (n - i) & 1 ? -tmp : tmp;\n  }\n  return\
    \ res;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593\n * @category \u6570\u5B66\n *  x=0,1,..,N-1\u3068\
    y=f(0),f(1),...,f(N-1)\u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306Ef(t)\u3092\
    \u8A08\u7B97\n *  O(N)\n */\n\n// verify\u7528:http://codeforces.com/contest/622/problem/F\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename K>\nK lagrange_interpolation(std::vector<K>\
    \ &y, K t) {\n  int n = y.size() - 1;\n  std::vector<K> pro(n + 1, 1), orp(n +\
    \ 1, 1);\n  for (int i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));\n  for\
    \ (int i = n; i > 0; i--) orp[i - 1] = orp[i] * (t - K(i));\n  K fact = K(1);\n\
    \  for (int i = 1; i <= n; i++) fact *= K(i);\n  std::vector<K> finv(n + 1, 1);\n\
    \  finv[n] = K(1) / fact;\n  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i]\
    \ * K(i);\n  K res(0);\n  for (int i = 0; i <= n; i++) {\n    K tmp = y[i] * pro[i]\
    \ * orp[i] * finv[i] * finv[n - i];\n    res += (n - i) & 1 ? -tmp : tmp;\n  }\n\
    \  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  - test/yukicoder/42.test.cpp
  - test/yukicoder/665.test.cpp
documentation_of: src/Math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/src/Math/lagrange_interpolation.hpp
- /library/src/Math/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
---
