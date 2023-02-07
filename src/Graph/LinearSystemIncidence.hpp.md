---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/arc106_b.test.cpp
    title: test/atcoder/arc106_b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/LinearSystemIncidence.hpp\"\n#include <vector>\n\
    #include <tuple>\n#include <type_traits>\ntemplate <typename T> class LinearSystemIncidence\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<std::vector<int>> adj;\n\
    public:\n LinearSystemIncidence(int n): adj(n) {}\n void add_edge(int src, int\
    \ dst) {\n  int m= es.size();\n  adj[src].push_back(m), adj[dst].push_back(m),\
    \ es.push_back({src, dst});\n }\n std::vector<T> solve(std::vector<T> b) const\
    \ {\n  const int n= adj.size();\n  std::vector<T> x(es.size());\n  std::vector<int>\
    \ pre(n, -2), dat(n, 0);\n  for (int s= 0, p, e, q, f; s < n; ++s)\n   if (pre[s]\
    \ == -2)\n    for (pre[p= s]= -1;;) {\n     if (dat[p] == (int)adj[p].size())\
    \ {\n      if (e= pre[p]; e < 0) {\n       if (b[p] != T()) return {};  // no\
    \ solution\n       break;\n      }\n      f= (es[e][0] == p), q= es[e][f];\n \
    \     T tmp= b[p];\n      if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[q]=\
    \ tmp ^ b[q];\n      else x[e]= f ? -tmp : tmp, b[q]+= tmp;\n      p= q;\n   \
    \   continue;\n     }\n     if (e= adj[p][dat[p]++], q= es[e][es[e][0] == p];\
    \ pre[q] == -2) pre[q]= e, p= q;\n    }\n  return x;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <type_traits>\n\
    template <typename T> class LinearSystemIncidence {\n std::vector<std::array<int,\
    \ 2>> es;\n std::vector<std::vector<int>> adj;\npublic:\n LinearSystemIncidence(int\
    \ n): adj(n) {}\n void add_edge(int src, int dst) {\n  int m= es.size();\n  adj[src].push_back(m),\
    \ adj[dst].push_back(m), es.push_back({src, dst});\n }\n std::vector<T> solve(std::vector<T>\
    \ b) const {\n  const int n= adj.size();\n  std::vector<T> x(es.size());\n  std::vector<int>\
    \ pre(n, -2), dat(n, 0);\n  for (int s= 0, p, e, q, f; s < n; ++s)\n   if (pre[s]\
    \ == -2)\n    for (pre[p= s]= -1;;) {\n     if (dat[p] == (int)adj[p].size())\
    \ {\n      if (e= pre[p]; e < 0) {\n       if (b[p] != T()) return {};  // no\
    \ solution\n       break;\n      }\n      f= (es[e][0] == p), q= es[e][f];\n \
    \     T tmp= b[p];\n      if constexpr (std::is_same_v<T, bool>) x[e]= tmp, b[q]=\
    \ tmp ^ b[q];\n      else x[e]= f ? -tmp : tmp, b[q]+= tmp;\n      p= q;\n   \
    \   continue;\n     }\n     if (e= adj[p][dat[p]++], q= es[e][es[e][0] == p];\
    \ pre[q] == -2) pre[q]= e, p= q;\n    }\n  return x;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/LinearSystemIncidence.hpp
  requiredBy: []
  timestamp: '2023-02-07 17:34:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/arc106_b.test.cpp
documentation_of: src/Graph/LinearSystemIncidence.hpp
layout: document
title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
---
## 計算量
$\mathcal{O}(V+E)$
## 問題例
[AtCoder Beginner Contest 155 F - Perils in Parallel](https://atcoder.jp/contests/abc155/tasks/abc155_f) (sp judge)\
[AtCoder Grand Contest 035 B - Even Degrees ](https://atcoder.jp/contests/agc035/tasks/agc035_b) (sp judge)\
[CODE FESTIVAL 2017 Final E - Combination Lock](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e)