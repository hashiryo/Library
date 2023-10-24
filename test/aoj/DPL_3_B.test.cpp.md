---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Misc/CartesianTree.hpp
    title: Cartesian-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B
  bundledCode: "#line 1 \"test/aoj/DPL_3_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Misc/CartesianTree.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int H, W;\n cin >> H >> W;\n vector<int> h(W, 0);\n int ans= 0;\n for (int i=\
    \ 0; i < H; ++i) {\n  for (int j= 0; j < W; ++j) {\n   bool c;\n   cin >> c;\n\
    \   h[j]= c ? 0 : h[j] + 1;\n  }\n  CartesianTree ct(h);\n  for (int j= 0; j <\
    \ W; ++j) {\n   auto [l, r]= ct.range(j);\n   ans= max(ans, h[j] * (r - l));\n\
    \  }\n }\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <src/Misc/CartesianTree.hpp>\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int H, W;\n cin >> H >> W;\n vector<int> h(W, 0);\n int ans= 0;\n for (int i=\
    \ 0; i < H; ++i) {\n  for (int j= 0; j < W; ++j) {\n   bool c;\n   cin >> c;\n\
    \   h[j]= c ? 0 : h[j] + 1;\n  }\n  CartesianTree ct(h);\n  for (int j= 0; j <\
    \ W; ++j) {\n   auto [l, r]= ct.range(j);\n   ans= max(ans, h[j] * (r - l));\n\
    \  }\n }\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Misc/CartesianTree.hpp
  isVerificationFile: true
  path: test/aoj/DPL_3_B.test.cpp
  requiredBy: []
  timestamp: '2023-04-16 21:58:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_B.test.cpp
- /verify/test/aoj/DPL_3_B.test.cpp.html
title: test/aoj/DPL_3_B.test.cpp
---
