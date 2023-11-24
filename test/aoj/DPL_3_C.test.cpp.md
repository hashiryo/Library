---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Misc/CartesianTree.hpp
    title: Cartesian-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C
  bundledCode: "#line 1 \"test/aoj/DPL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Misc/CartesianTree.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n vector<long long> h(N);\n for (int i= 0; i < N; ++i) cin\
    \ >> h[i];\n CartesianTree ct(h);\n long long ans= 0;\n for (int i= 0; i < N;\
    \ ++i) {\n  auto [l, r]= ct.range(i);\n  ans= max(ans, h[i] * (r - l));\n }\n\
    \ cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_C\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Misc/CartesianTree.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n vector<long long> h(N);\n for (int i= 0; i < N; ++i) cin\
    \ >> h[i];\n CartesianTree ct(h);\n long long ans= 0;\n for (int i= 0; i < N;\
    \ ++i) {\n  auto [l, r]= ct.range(i);\n  ans= max(ans, h[i] * (r - l));\n }\n\
    \ cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Misc/CartesianTree.hpp
  isVerificationFile: true
  path: test/aoj/DPL_3_C.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 00:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_C.test.cpp
- /verify/test/aoj/DPL_3_C.test.cpp.html
title: test/aoj/DPL_3_C.test.cpp
---
