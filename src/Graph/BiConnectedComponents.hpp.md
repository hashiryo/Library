---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3022.test.cpp
    title: test/aoj/3022.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/bonnie-and-clyde.test.cpp
    title: test/hackerrank/bonnie-and-clyde.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/BiConnectedComponents.hpp\"\n#include <vector>\n\
    #include <algorithm>\nclass BiConnectedComponents {\n std::vector<std::vector<int>>\
    \ adj;\npublic:\n BiConnectedComponents(int n): adj(n) {}\n void add_edge(int\
    \ u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n std::vector<std::vector<int>>\
    \ block_cut_tree() const {\n  const int n= adj.size();\n  std::vector<int> ord(n),\
    \ par(n, -2), dat(n, 0), low;\n  std::vector<std::vector<int>> ret(n);\n  auto\
    \ add= [&](int u, int v) { ret[u].push_back(v), ret[v].push_back(u); };\n  int\
    \ k= 0;\n  for (int s= 0; s < n; ++s)\n   if (par[s] == -2) {\n    par[s]= -1;\n\
    \    for (int p= s; p >= 0;) {\n     if (dat[p] == 0) ord[k++]= p;\n     if (dat[p]\
    \ == (int)adj[p].size()) {\n      p= par[p];\n      continue;\n     }\n     if\
    \ (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n    }\n   }\n  for\
    \ (int i= 0; i < n; ++i) dat[ord[i]]= i;\n  low= dat;\n  for (int v= 0; v < n;\
    \ ++v)\n   for (int u: adj[v]) low[v]= std::min(low[v], dat[u]);\n  for (int i=\
    \ n; i--;)\n   if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]= std::min(low[pp],\
    \ low[p]);\n  for (int p: ord)\n   if (par[p] >= 0) {\n    if (int pp= par[p];\
    \ low[p] < dat[pp]) low[p]= low[pp], add(low[p], p);\n    else ret.resize(k +\
    \ 1), add(k, pp), add(k, p), low[p]= k++;\n   }\n  for (int s= 0; s < n; ++s)\n\
    \   if (!adj[s].size()) ret.resize(k + 1), add(k++, s);\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nclass BiConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\npublic:\n BiConnectedComponents(int\
    \ n): adj(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u);\
    \ }\n std::vector<std::vector<int>> block_cut_tree() const {\n  const int n= adj.size();\n\
    \  std::vector<int> ord(n), par(n, -2), dat(n, 0), low;\n  std::vector<std::vector<int>>\
    \ ret(n);\n  auto add= [&](int u, int v) { ret[u].push_back(v), ret[v].push_back(u);\
    \ };\n  int k= 0;\n  for (int s= 0; s < n; ++s)\n   if (par[s] == -2) {\n    par[s]=\
    \ -1;\n    for (int p= s; p >= 0;) {\n     if (dat[p] == 0) ord[k++]= p;\n   \
    \  if (dat[p] == (int)adj[p].size()) {\n      p= par[p];\n      continue;\n  \
    \   }\n     if (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n    }\n\
    \   }\n  for (int i= 0; i < n; ++i) dat[ord[i]]= i;\n  low= dat;\n  for (int v=\
    \ 0; v < n; ++v)\n   for (int u: adj[v]) low[v]= std::min(low[v], dat[u]);\n \
    \ for (int i= n; i--;)\n   if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]= std::min(low[pp],\
    \ low[p]);\n  for (int p: ord)\n   if (par[p] >= 0) {\n    if (int pp= par[p];\
    \ low[p] < dat[pp]) low[p]= low[pp], add(low[p], p);\n    else ret.resize(k +\
    \ 1), add(k, pp), add(k, p), low[p]= k++;\n   }\n  for (int s= 0; s < n; ++s)\n\
    \   if (!adj[s].size()) ret.resize(k + 1), add(k++, s);\n  return ret;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/BiConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-01-25 18:54:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/3022.test.cpp
  - test/yosupo/biconnected_components.test.cpp
  - test/yukicoder/1326.test.cpp
  - test/hackerrank/bonnie-and-clyde.test.cpp
documentation_of: src/Graph/BiConnectedComponents.hpp
layout: document
title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
[0, n)：もとの頂点 \
[n, n + n_block)：block \
非再帰 [参考](https://nachiavivias.github.io/cp-library/column/2022/01.html)
## 問題例
[AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)
## 参考
[https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)