---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_B.KMP.test.cpp
    title: test/aoj/ALDS1_14_B.KMP.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Knuth-Morris-Pratt
    links: []
  bundledCode: "#line 2 \"src/String/KnuthMorrisPratt.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Knuth-Morris-Pratt\n * @category \u6587\u5B57\u5217\n *  \u30C6\
    \u30FC\u30D6\u30EB\u69CB\u7BC9 O(|S|)\n *  pattern_match(T) T\u306E\u4E2D\u304B\
    \u3089S\u3068\u4E00\u81F4\u3059\u308B\u90E8\u5206\u3092\u691C\u7D22 O(|T|)\n *\
    \  period(i) verified :ARC060_F\n */\n\n// BEGIN CUT HERE\n\nstruct KnuthMorrisPratt\
    \ {\n  std::vector<int> KMP;\n  const std::string s;\n  int n;\n  KnuthMorrisPratt(const\
    \ std::string &str) : s(str), n(s.length()) {\n    KMP.resize(n + 1, -1);\n  \
    \  std::vector<int> knuth(n + 1, -1);\n    for (int i = 0, j = -1; i < n; i++)\
    \ {\n      while (~j && s[i] != s[j]) j = knuth[j];\n      knuth[i + 1] = KMP[i\
    \ + 1] = ++j;\n      if (i + 1 < n && s[i + 1] == s[j]) knuth[i + 1] = knuth[j];\n\
    \    }\n  }\n\n  // the period of S[0:i]\n  int period(int i) { return i - KMP[i];\
    \ }\n\n  // positions for T that match s\n  // O(|T|)\n  std::vector<int> pattern_match(std::string\
    \ T) {\n    int m = T.length();\n    std::vector<int> occur;\n    for (int i =\
    \ 0, k = 0; i < m; ++i) {\n      while (k >= 0 && T[i] != s[k]) k = KMP[k];\n\
    \      if (++k == n) {\n        /* match at T[i-n+1 ... i] */\n        occur.push_back(i\
    \ - n + 1);\n      }\n    }\n    return occur;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Knuth-Morris-Pratt\n\
    \ * @category \u6587\u5B57\u5217\n *  \u30C6\u30FC\u30D6\u30EB\u69CB\u7BC9 O(|S|)\n\
    \ *  pattern_match(T) T\u306E\u4E2D\u304B\u3089S\u3068\u4E00\u81F4\u3059\u308B\
    \u90E8\u5206\u3092\u691C\u7D22 O(|T|)\n *  period(i) verified :ARC060_F\n */\n\
    \n// BEGIN CUT HERE\n\nstruct KnuthMorrisPratt {\n  std::vector<int> KMP;\n  const\
    \ std::string s;\n  int n;\n  KnuthMorrisPratt(const std::string &str) : s(str),\
    \ n(s.length()) {\n    KMP.resize(n + 1, -1);\n    std::vector<int> knuth(n +\
    \ 1, -1);\n    for (int i = 0, j = -1; i < n; i++) {\n      while (~j && s[i]\
    \ != s[j]) j = knuth[j];\n      knuth[i + 1] = KMP[i + 1] = ++j;\n      if (i\
    \ + 1 < n && s[i + 1] == s[j]) knuth[i + 1] = knuth[j];\n    }\n  }\n\n  // the\
    \ period of S[0:i]\n  int period(int i) { return i - KMP[i]; }\n\n  // positions\
    \ for T that match s\n  // O(|T|)\n  std::vector<int> pattern_match(std::string\
    \ T) {\n    int m = T.length();\n    std::vector<int> occur;\n    for (int i =\
    \ 0, k = 0; i < m; ++i) {\n      while (k >= 0 && T[i] != s[k]) k = KMP[k];\n\
    \      if (++k == n) {\n        /* match at T[i-n+1 ... i] */\n        occur.push_back(i\
    \ - n + 1);\n      }\n    }\n    return occur;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/KnuthMorrisPratt.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_B.KMP.test.cpp
documentation_of: src/String/KnuthMorrisPratt.hpp
layout: document
redirect_from:
- /library/src/String/KnuthMorrisPratt.hpp
- /library/src/String/KnuthMorrisPratt.hpp.html
title: Knuth-Morris-Pratt
---
