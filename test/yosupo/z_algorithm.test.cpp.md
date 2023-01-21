---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/String/z_algorithm.hpp
    title: "\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#include <iostream>\n#include <string>\n#include <vector>\n#line 4 \"src/String/z_algorithm.hpp\"\
    \nstd::vector<int> z_algorithm(const std::string &s) {\n std::vector<int> prefix(s.size());\n\
    \ for (int i= 1, j= 0; i < s.size(); i++) {\n  if (i + prefix[i - j] >= j + prefix[j])\
    \ {\n   int k= std::max(0, j + prefix[j] - i);\n   while (i + k < s.size() &&\
    \ s[k] == s[i + k]) ++k;\n   prefix[i]= k, j= i;\n  } else prefix[i]= prefix[i\
    \ - j];\n }\n return prefix[0]= (int)s.size(), prefix;\n}\n#line 6 \"test/yosupo/z_algorithm.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ string s;\n cin >> s;\n vector<int> ans= z_algorithm(s);\n int N= s.length();\n\
    \ for (int i= 0; i < N; i++) cout << ans[i] << \" \\n\"[i == N - 1];\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n#include \"src/String/z_algorithm.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ string s;\n cin >> s;\n vector<int> ans= z_algorithm(s);\n int N= s.length();\n\
    \ for (int i= 0; i < N; i++) cout << ans[i] << \" \\n\"[i == N - 1];\n return\
    \ 0;\n}"
  dependsOn:
  - src/String/z_algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 20:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/z_algorithm.test.cpp
- /verify/test/yosupo/z_algorithm.test.cpp.html
title: test/yosupo/z_algorithm.test.cpp
---
