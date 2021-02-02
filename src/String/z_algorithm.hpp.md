---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/z_algorithm.test.cpp
    title: test/yosupo/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)"
    links: []
  bundledCode: "#line 2 \"src/String/z_algorithm.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)\n * @category\
    \ \u6587\u5B57\u5217\n *  $prefix_i$ \u306F\u3001$S$ \u3068 $S.substr(i)$ \u306E\
    \ LCP(longest common prefix)\n *  O(|S|)\n */\n\n// BEGIN CUT HERE\n\nstd::vector<int>\
    \ z_algorithm(const std::string &s) {\n  std::vector<int> prefix(s.size());\n\
    \  for (int i = 1, j = 0; i < s.size(); i++) {\n    if (i + prefix[i - j] < j\
    \ + prefix[j]) {\n      prefix[i] = prefix[i - j];\n    } else {\n      int k\
    \ = std::max(0, j + prefix[j] - i);\n      while (i + k < s.size() && s[k] ==\
    \ s[i + k]) ++k;\n      prefix[i] = k;\n      j = i;\n    }\n  }\n  prefix[0]\
    \ = (int)s.size();\n  return prefix;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u9577\u5171\
    \u901A\u63A5\u982D\u8F9E(Z-Algorithm)\n * @category \u6587\u5B57\u5217\n *  $prefix_i$\
    \ \u306F\u3001$S$ \u3068 $S.substr(i)$ \u306E LCP(longest common prefix)\n * \
    \ O(|S|)\n */\n\n// BEGIN CUT HERE\n\nstd::vector<int> z_algorithm(const std::string\
    \ &s) {\n  std::vector<int> prefix(s.size());\n  for (int i = 1, j = 0; i < s.size();\
    \ i++) {\n    if (i + prefix[i - j] < j + prefix[j]) {\n      prefix[i] = prefix[i\
    \ - j];\n    } else {\n      int k = std::max(0, j + prefix[j] - i);\n      while\
    \ (i + k < s.size() && s[k] == s[i + k]) ++k;\n      prefix[i] = k;\n      j =\
    \ i;\n    }\n  }\n  prefix[0] = (int)s.size();\n  return prefix;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/z_algorithm.test.cpp
documentation_of: src/String/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/String/z_algorithm.hpp
- /library/src/String/z_algorithm.hpp.html
title: "\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)"
---
