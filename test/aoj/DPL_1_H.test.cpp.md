---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/Knapsack.hpp
    title: "0-1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C (\u534A\u5206\u5168\
      \u5217\u6319)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_H
  bundledCode: "#line 1 \"test/aoj/DPL_1_H.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_H\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Optimization/Knapsack.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ Knapsack<int64_t, int64_t> K;\n int N;\n int64_t W;\n cin >> N >> W;\n for (int\
    \ i= 0; i < N; ++i) {\n  int64_t v, w;\n  cin >> v >> w;\n  K.add(v, w);\n }\n\
    \ K.build();\n cout << K.solve(W) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_H\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Optimization/Knapsack.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ Knapsack<int64_t, int64_t> K;\n int N;\n int64_t W;\n cin >> N >> W;\n for (int\
    \ i= 0; i < N; ++i) {\n  int64_t v, w;\n  cin >> v >> w;\n  K.add(v, w);\n }\n\
    \ K.build();\n cout << K.solve(W) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/Knapsack.hpp
  isVerificationFile: true
  path: test/aoj/DPL_1_H.test.cpp
  requiredBy: []
  timestamp: '2023-04-02 00:58:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_H.test.cpp
- /verify/test/aoj/DPL_1_H.test.cpp.html
title: test/aoj/DPL_1_H.test.cpp
---
