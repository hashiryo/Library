---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/min_Lconvex.hpp
    title: "L\u51F8\u95A2\u6570\u6700\u5C0F\u5316(\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0\
      \u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc018/tasks/agc018_c
    links:
    - https://atcoder.jp/contests/agc018/tasks/agc018_c
  bundledCode: "#line 1 \"test/atcoder/agc018_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc018/tasks/agc018_c\"\
    \n#include <iostream>\n#include <algorithm>\n#line 2 \"src/Optimization/min_Lconvex.hpp\"\
    \n#include <vector>\ntemplate <typename TD, typename TR, class F> std::pair<TR,\
    \ std::vector<TD>> min_Lconvex(const F &f, std::vector<TD> x, TD alpha) {\n TR\
    \ f0= f(x), f1= f0, fS;\n for (int n= x.size(); alpha; f0 == f1 ? alpha>>= 1 :\
    \ f0= f1) {\n  std::vector<TD> x0{x};\n  for (int S= 1; S < (1 << n) - 1; S++)\
    \ {\n   std::vector<TD> xS{x0};\n   for (int i= 0; i < n; i++)\n    if ((S >>\
    \ i) & 1) xS[i]+= alpha;\n   if ((fS= f(xS)) < f1) f1= fS, x= std::move(xS);\n\
    \  }\n }\n return {f1, std::move(x)};\n}\n#line 5 \"test/atcoder/agc018_c.test.cpp\"\
    \nusing namespace std;\n// O(MAX_A log log MAX_A)\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n int x[3], n= 0;\n for (int j= 0; j < 3; j++)\
    \ cin >> x[j], n+= x[j];\n int c[n][3];\n for (int i= 0; i < n; i++)\n  for (int\
    \ j= 0; j < 3; j++) cin >> c[i][j];\n auto f= [&](const std::vector<int> &q) {\n\
    \  long long ret= 0;\n  for (int i= 0; i < n; i++) ret+= max({c[i][0] - q[0],\
    \ c[i][1] - q[1], c[i][2] - q[2]});\n  for (int j= 0; j < 3; j++) ret+= 1LL *\
    \ x[j] * q[j];\n  return ret;\n };\n cout << min_Lconvex<int, long long>(f, {0,\
    \ 0, 0}, 1 << 29).first << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc018/tasks/agc018_c\"\n#include\
    \ <iostream>\n#include <algorithm>\n#include \"src/Optimization/min_Lconvex.hpp\"\
    \nusing namespace std;\n// O(MAX_A log log MAX_A)\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n int x[3], n= 0;\n for (int j= 0; j < 3; j++)\
    \ cin >> x[j], n+= x[j];\n int c[n][3];\n for (int i= 0; i < n; i++)\n  for (int\
    \ j= 0; j < 3; j++) cin >> c[i][j];\n auto f= [&](const std::vector<int> &q) {\n\
    \  long long ret= 0;\n  for (int i= 0; i < n; i++) ret+= max({c[i][0] - q[0],\
    \ c[i][1] - q[1], c[i][2] - q[2]});\n  for (int j= 0; j < 3; j++) ret+= 1LL *\
    \ x[j] * q[j];\n  return ret;\n };\n cout << min_Lconvex<int, long long>(f, {0,\
    \ 0, 0}, 1 << 29).first << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/min_Lconvex.hpp
  isVerificationFile: true
  path: test/atcoder/agc018_c.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 21:04:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/agc018_c.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc018_c.test.cpp
- /verify/test/atcoder/agc018_c.test.cpp.html
title: test/atcoder/agc018_c.test.cpp
---
