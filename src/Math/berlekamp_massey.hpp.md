---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Berlekamp-Massey
    links:
    - https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c
  bundledCode: "#line 1 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n\
    \ * @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \n// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]\n// return\
    \ c\n\ntemplate <class T>\nvector<T> berlekamp_massey(const vector<T> &a) {\n\
    \  const int N = (int)a.size();\n  vector<T> b = {T(-1)}, c = {T(-1)};\n  T y\
    \ = T(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()), m =\
    \ int(b.size()) + 1;\n    T x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * a[ed - l + i];\n    b.emplace_back(0);\n    if (x == T(0)) continue;\n   \
    \ T freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n      c.insert(begin(c),\
    \ m - l, T(0));\n      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m\
    \ - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n      for (int i = 0;\
    \ i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  c.pop_back();\n\
    \  return c;\n}\n"
  code: "/**\n * @title Berlekamp-Massey\n * @category \u6570\u5B66\n * \u6570\u5217\
    \u306E\u6700\u521D\u306EN\u9805\u304B\u3089\u3001\u305D\u306E\u6570\u5217\u3092\
    \u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\
    \u6F38\u5316\u5F0F\u3092\u6C42\u3081\u308B\n *  O(N^2)\n */\n\n// verify\u7528\
    :\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \n// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]\n// return\
    \ c\n\ntemplate <class T>\nvector<T> berlekamp_massey(const vector<T> &a) {\n\
    \  const int N = (int)a.size();\n  vector<T> b = {T(-1)}, c = {T(-1)};\n  T y\
    \ = T(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()), m =\
    \ int(b.size()) + 1;\n    T x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * a[ed - l + i];\n    b.emplace_back(0);\n    if (x == T(0)) continue;\n   \
    \ T freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n      c.insert(begin(c),\
    \ m - l, T(0));\n      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m\
    \ - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n      for (int i = 0;\
    \ i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  c.pop_back();\n\
    \  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/berlekamp_massey.hpp
  requiredBy: []
  timestamp: '2020-08-11 20:23:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/find_linear_recurrence.test.cpp
documentation_of: src/Math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/Math/berlekamp_massey.hpp
- /library/src/Math/berlekamp_massey.hpp.html
title: Berlekamp-Massey
---
