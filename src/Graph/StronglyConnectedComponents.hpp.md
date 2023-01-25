---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0366.test.cpp
    title: test/aoj/0366.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1293.scc.test.cpp
    title: test/yukicoder/1293.scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1813.test.cpp
    title: test/yukicoder/1813.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n#include <vector>\n\
    #include <array>\n#include <algorithm>\nclass StronglyConnectedComponents {\n\
    \ std::vector<std::vector<int>> adj, rev;\npublic:\n StronglyConnectedComponents(int\
    \ n): adj(n), rev(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst),\
    \ rev[dst].push_back(src); }\n std::vector<std::vector<int>> get_block() const\
    \ {\n  const int n= adj.size();\n  std::vector<std::vector<int>> blk;\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(n, 0);\n  int k= n;\n  for (int s= 0; s < n; ++s)\n\
    \   if (par[s] == -2) {\n    par[s]= -1;\n    for (int p= s; p >= 0;) {\n    \
    \ if (dat[p] == (int)adj[p].size()) {\n      ord[--k]= p, p= par[p];\n      continue;\n\
    \     }\n     if (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n  \
    \  }\n   }\n  dat.assign(n, 1);\n  for (int s: ord)\n   if (dat[s]) {\n    blk.resize(++k),\
    \ dat[s]= 0, blk.back().push_back(s);\n    for (int i= 0; i < (int)blk.back().size();\
    \ ++i)\n     for (int v: rev[blk.back()[i]])\n      if (dat[v]) dat[v]= 0, blk.back().push_back(v);\n\
    \   }\n  return blk;\n }\n std::vector<int> get_index(const std::vector<std::vector<int>>\
    \ &blk) const {\n  std::vector<int> index(adj.size());\n  for (int i= blk.size();\
    \ i--;)\n   for (int v: blk[i]) index[v]= i;\n  return index;\n }\n std::vector<std::vector<int>>\
    \ get_dag(const std::vector<int> &index, int num) const {\n  std::vector<std::vector<int>>\
    \ dag(num);\n  std::vector<std::array<int, 2>> es;\n  for (int i= adj.size();\
    \ i--;)\n   for (int j: adj[i])\n    if (int u= index[i], v= index[j]; u != v)\
    \ es.push_back({u, v});\n  std::sort(es.begin(), es.end()), es.erase(std::unique(es.begin(),\
    \ es.end()), es.end());\n  for (auto [u, v]: es) dag[u].push_back(v);\n  return\
    \ dag;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <algorithm>\n\
    class StronglyConnectedComponents {\n std::vector<std::vector<int>> adj, rev;\n\
    public:\n StronglyConnectedComponents(int n): adj(n), rev(n) {}\n void add_edge(int\
    \ src, int dst) { adj[src].push_back(dst), rev[dst].push_back(src); }\n std::vector<std::vector<int>>\
    \ get_block() const {\n  const int n= adj.size();\n  std::vector<std::vector<int>>\
    \ blk;\n  std::vector<int> ord(n), par(n, -2), dat(n, 0);\n  int k= n;\n  for\
    \ (int s= 0; s < n; ++s)\n   if (par[s] == -2) {\n    par[s]= -1;\n    for (int\
    \ p= s; p >= 0;) {\n     if (dat[p] == (int)adj[p].size()) {\n      ord[--k]=\
    \ p, p= par[p];\n      continue;\n     }\n     if (int q= adj[p][dat[p]++]; par[q]\
    \ == -2) par[q]= p, p= q;\n    }\n   }\n  dat.assign(n, 1);\n  for (int s: ord)\n\
    \   if (dat[s]) {\n    blk.resize(++k), dat[s]= 0, blk.back().push_back(s);\n\
    \    for (int i= 0; i < (int)blk.back().size(); ++i)\n     for (int v: rev[blk.back()[i]])\n\
    \      if (dat[v]) dat[v]= 0, blk.back().push_back(v);\n   }\n  return blk;\n\
    \ }\n std::vector<int> get_index(const std::vector<std::vector<int>> &blk) const\
    \ {\n  std::vector<int> index(adj.size());\n  for (int i= blk.size(); i--;)\n\
    \   for (int v: blk[i]) index[v]= i;\n  return index;\n }\n std::vector<std::vector<int>>\
    \ get_dag(const std::vector<int> &index, int num) const {\n  std::vector<std::vector<int>>\
    \ dag(num);\n  std::vector<std::array<int, 2>> es;\n  for (int i= adj.size();\
    \ i--;)\n   for (int j: adj[i])\n    if (int u= index[i], v= index[j]; u != v)\
    \ es.push_back({u, v});\n  std::sort(es.begin(), es.end()), es.erase(std::unique(es.begin(),\
    \ es.end()), es.end());\n  for (auto [u, v]: es) dag[u].push_back(v);\n  return\
    \ dag;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/StronglyConnectedComponents.hpp
  requiredBy:
  - src/Math/TwoSatisfiability.hpp
  timestamp: '2023-01-25 18:54:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0366.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
  - test/yukicoder/1293.scc.test.cpp
  - test/yukicoder/1813.test.cpp
documentation_of: src/Graph/StronglyConnectedComponents.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
`get_block` : 強連結成分をトポロジカルソート順にしたものを返す \
`get_index` : 元の頂点が所属する強連結成分のidを返す \
`get_dag`   : 縮約したDAGを返す
## 計算量
$\mathcal{O}(V)$