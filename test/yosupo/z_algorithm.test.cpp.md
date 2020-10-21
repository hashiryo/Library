---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/String/z_algorithm.hpp
    title: "\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/String/z_algorithm.hpp\"\n/**\n * @title \u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E(Z-Algorithm)\n * @category \u6587\u5B57\u5217\n *  $prefix_i$\
    \ \u306F\u3001$S$ \u3068 $S.substr(i)$ \u306E LCP(longest common prefix)\n * \
    \ O(|S|)\n */\n\n#ifndef call_from_test\n#line 10 \"src/String/z_algorithm.hpp\"\
    \nusing namespace std;\n#endif\n\nvector<int> z_algorithm(const string &s) {\n\
    \  vector<int> prefix(s.size());\n  for (int i = 1, j = 0; i < s.size(); i++)\
    \ {\n    if (i + prefix[i - j] < j + prefix[j]) {\n      prefix[i] = prefix[i\
    \ - j];\n    } else {\n      int k = max(0, j + prefix[j] - i);\n      while (i\
    \ + k < s.size() && s[k] == s[i + k]) ++k;\n      prefix[i] = k;\n      j = i;\n\
    \    }\n  }\n  prefix[0] = (int)s.size();\n  return prefix;\n}\n#line 8 \"test/yosupo/z_algorithm.test.cpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  string s;\n  cin >> s;\n  vector<int> ans = z_algorithm(s);\n  for (int i =\
    \ 0; i < s.size(); i++) {\n    cout << (i ? \" \" : \"\") << ans[i];\n  }\n  cout\
    \ << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/String/z_algorithm.hpp\"\n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  string s;\n  cin >> s;\n  vector<int> ans = z_algorithm(s);\n\
    \  for (int i = 0; i < s.size(); i++) {\n    cout << (i ? \" \" : \"\") << ans[i];\n\
    \  }\n  cout << endl;\n  return 0;\n}"
  dependsOn:
  - src/String/z_algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2020-08-11 20:23:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/z_algorithm.test.cpp
- /verify/test/yosupo/z_algorithm.test.cpp.html
title: test/yosupo/z_algorithm.test.cpp
---