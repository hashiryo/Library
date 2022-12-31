---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0401.test.cpp
    title: test/aoj/0401.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Game/ImpartialGame.hpp\"\n#include <bits/stdc++.h>\n\
    template <typename Game, typename F> struct ImpartialGame {\n std::map<Game, unsigned>\
    \ mp;\n F f;  // : Game -> std::vector<Game>\n static unsigned mex(std::vector<unsigned>\
    \ S) {\n  std::sort(S.begin(), S.end());\n  S.erase(std::unique(S.begin(), S.end()),\
    \ S.end());\n  for (unsigned i= 0; i < S.size(); i++)\n   if (S[i] != i) return\
    \ i;\n  return S.size();\n }\npublic:\n ImpartialGame(const F &_f): f(_f) {}\n\
    \ unsigned eval(Game g) {\n  if (mp.count(g)) return mp[g];\n  std::vector<unsigned>\
    \ S;\n  for (const auto &_g: f(g)) S.emplace_back(eval(_g));\n  return mp[g]=\
    \ mex(S);\n }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <typename Game, typename\
    \ F> struct ImpartialGame {\n std::map<Game, unsigned> mp;\n F f;  // : Game ->\
    \ std::vector<Game>\n static unsigned mex(std::vector<unsigned> S) {\n  std::sort(S.begin(),\
    \ S.end());\n  S.erase(std::unique(S.begin(), S.end()), S.end());\n  for (unsigned\
    \ i= 0; i < S.size(); i++)\n   if (S[i] != i) return i;\n  return S.size();\n\
    \ }\npublic:\n ImpartialGame(const F &_f): f(_f) {}\n unsigned eval(Game g) {\n\
    \  if (mp.count(g)) return mp[g];\n  std::vector<unsigned> S;\n  for (const auto\
    \ &_g: f(g)) S.emplace_back(eval(_g));\n  return mp[g]= mex(S);\n }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Game/ImpartialGame.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:09:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0401.test.cpp
documentation_of: src/Game/ImpartialGame.hpp
layout: document
title: "\u4E0D\u504F\u30B2\u30FC\u30E0 (grundy\u6570)"
---
メモ化再帰でgrundy数を計算