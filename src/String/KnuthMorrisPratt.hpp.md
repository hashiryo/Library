---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_B.KMP.test.cpp
    title: test/aoj/ALDS1_14_B.KMP.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/KnuthMorrisPratt.hpp\"\n#include <vector>\n#include\
    \ <string>\nstruct KnuthMorrisPratt {\n std::vector<int> KMP;\n const std::string\
    \ s;\n int n;\n KnuthMorrisPratt(const std::string &str): s(str), n(s.length())\
    \ {\n  KMP.resize(n + 1, -1);\n  std::vector<int> knuth(n + 1, -1);\n  for (int\
    \ i= 0, j= -1; i < n; i++) {\n   while (~j && s[i] != s[j]) j= knuth[j];\n   knuth[i\
    \ + 1]= KMP[i + 1]= ++j;\n   if (i + 1 < n && s[i + 1] == s[j]) knuth[i + 1]=\
    \ knuth[j];\n  }\n }\n // the period of S[0:i]\n int period(int i) { return i\
    \ - KMP[i]; }\n // positions for T that match s\n // O(|T|)\n std::vector<int>\
    \ pattern_match(std::string T) {\n  int m= T.length();\n  std::vector<int> occur;\n\
    \  for (int i= 0, k= 0; i < m; ++i) {\n   while (k >= 0 && T[i] != s[k]) k= KMP[k];\n\
    \   if (++k == n) {\n    /* match at T[i-n+1 ... i] */\n    occur.push_back(i\
    \ - n + 1);\n   }\n  }\n  return occur;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <string>\nstruct KnuthMorrisPratt\
    \ {\n std::vector<int> KMP;\n const std::string s;\n int n;\n KnuthMorrisPratt(const\
    \ std::string &str): s(str), n(s.length()) {\n  KMP.resize(n + 1, -1);\n  std::vector<int>\
    \ knuth(n + 1, -1);\n  for (int i= 0, j= -1; i < n; i++) {\n   while (~j && s[i]\
    \ != s[j]) j= knuth[j];\n   knuth[i + 1]= KMP[i + 1]= ++j;\n   if (i + 1 < n &&\
    \ s[i + 1] == s[j]) knuth[i + 1]= knuth[j];\n  }\n }\n // the period of S[0:i]\n\
    \ int period(int i) { return i - KMP[i]; }\n // positions for T that match s\n\
    \ // O(|T|)\n std::vector<int> pattern_match(std::string T) {\n  int m= T.length();\n\
    \  std::vector<int> occur;\n  for (int i= 0, k= 0; i < m; ++i) {\n   while (k\
    \ >= 0 && T[i] != s[k]) k= KMP[k];\n   if (++k == n) {\n    /* match at T[i-n+1\
    \ ... i] */\n    occur.push_back(i - n + 1);\n   }\n  }\n  return occur;\n }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/String/KnuthMorrisPratt.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:06:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_B.KMP.test.cpp
documentation_of: src/String/KnuthMorrisPratt.hpp
layout: document
title: Knuth-Morris-Pratt
---
## 計算量
テーブル構築 $\mathcal{O}(|S|)$ \
pattern_match(T) $T$の中から$S$と一致する部分を検索 $\mathcal{O}(|T|)$
## 問題例
[AtCoder Regular Contest 060 F - 最良表現](https://atcoder.jp/contests/arc060/tasks/arc060_d) (`period(i)`)