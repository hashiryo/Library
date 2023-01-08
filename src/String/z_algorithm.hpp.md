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
    links: []
  bundledCode: "#line 2 \"src/String/z_algorithm.hpp\"\n#include <bits/stdc++.h>\n\
    std::vector<int> z_algorithm(const std::string &s) {\n std::vector<int> prefix(s.size());\n\
    \ for (int i= 1, j= 0; i < s.size(); i++) {\n  if (i + prefix[i - j] >= j + prefix[j])\
    \ {\n   int k= std::max(0, j + prefix[j] - i);\n   while (i + k < s.size() &&\
    \ s[k] == s[i + k]) ++k;\n   prefix[i]= k, j= i;\n  } else prefix[i]= prefix[i\
    \ - j];\n }\n return prefix[0]= (int)s.size(), prefix;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nstd::vector<int> z_algorithm(const\
    \ std::string &s) {\n std::vector<int> prefix(s.size());\n for (int i= 1, j= 0;\
    \ i < s.size(); i++) {\n  if (i + prefix[i - j] >= j + prefix[j]) {\n   int k=\
    \ std::max(0, j + prefix[j] - i);\n   while (i + k < s.size() && s[k] == s[i +\
    \ k]) ++k;\n   prefix[i]= k, j= i;\n  } else prefix[i]= prefix[i - j];\n }\n return\
    \ prefix[0]= (int)s.size(), prefix;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/z_algorithm.test.cpp
documentation_of: src/String/z_algorithm.hpp
layout: document
title: "\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(Z-Algorithm)"
---
`prefix[i]` は `S` と `S.substr(i)` の LCP(longest common prefix)
## 計算量
$\mathcal{O}(|S|)$