---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/MaxClique.hpp\"\n#include <vector>\n#include <bitset>\n\
    #include <algorithm>\nclass MaxClique {\n struct id_num {\n  std::size_t id, num;\n\
    \ };\n std::vector<std::bitset<128>> adj, buf;\n std::bitset<128> clique, cur;\n\
    \ std::vector<int> deg;\n void dfs(std::vector<id_num>& rem) {\n  if (clique.count()\
    \ < cur.count()) clique= cur;\n  std::sort(rem.begin(), rem.end(), [&](id_num\
    \ l, id_num r) { return deg[l.id] > deg[r.id]; });\n  std::size_t max_num= 1;\n\
    \  for (auto& v: rem) {\n   v.num= 0;\n   while ((adj[v.id] & buf[v.num]).any())\
    \ v.num++;\n   buf[v.num].set(v.id), max_num= std::max(max_num, v.num + 1);\n\
    \  }\n  for (int i= max_num - 1; i >= 0; i--) buf[i].reset();\n  std::sort(rem.begin(),\
    \ rem.end(), [&](id_num l, id_num r) { return l.num < r.num; });\n  std::vector<id_num>\
    \ nrem;\n  while (!rem.empty() && rem.back().num + cur.count() >= clique.count())\
    \ {\n   for (auto u: rem)\n    if (adj[rem.back().id][u.id]) nrem.emplace_back(u),\
    \ buf[0].set(u.id);\n   for (auto u: nrem) deg[u.id]= (buf[0] & adj[u.id]).count();\n\
    \   buf[0].reset(), cur.set(rem.back().id);\n   dfs(nrem);\n   nrem.clear(), cur.reset(rem.back().id),\
    \ rem.pop_back();\n  }\n }\npublic:\n MaxClique(int n_): adj(n_), buf(n_ + 1),\
    \ deg(n_) {}\n void add_edge(int u, int v) { adj[u][v]= adj[v][u]= true; }\n std::vector<int>\
    \ get_max_clique() {\n  std::vector<id_num> nrem;\n  for (int i= adj.size() -\
    \ 1; i >= 0; i--) nrem.emplace_back(id_num{(std::size_t)i, 0}), deg[i]= adj[i].count();\n\
    \  dfs(nrem);\n  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n;\
    \ i++)\n   if (clique[i]) ret.push_back(i);\n  return ret;\n }\n std::vector<int>\
    \ get_max_independent_set() {\n  for (int i= adj.size() - 1; i >= 0; i--)\n  \
    \ for (int j= i - 1; j >= 0; j--) adj[i][j]= adj[j][i]= ~adj[j][i];\n  return\
    \ get_max_clique();\n }\n std::vector<int> get_min_vertex_cover() {\n  get_max_independent_set();\n\
    \  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n; i++)\n   if (!clique[i])\
    \ ret.push_back(i);\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <bitset>\n#include <algorithm>\n\
    class MaxClique {\n struct id_num {\n  std::size_t id, num;\n };\n std::vector<std::bitset<128>>\
    \ adj, buf;\n std::bitset<128> clique, cur;\n std::vector<int> deg;\n void dfs(std::vector<id_num>&\
    \ rem) {\n  if (clique.count() < cur.count()) clique= cur;\n  std::sort(rem.begin(),\
    \ rem.end(), [&](id_num l, id_num r) { return deg[l.id] > deg[r.id]; });\n  std::size_t\
    \ max_num= 1;\n  for (auto& v: rem) {\n   v.num= 0;\n   while ((adj[v.id] & buf[v.num]).any())\
    \ v.num++;\n   buf[v.num].set(v.id), max_num= std::max(max_num, v.num + 1);\n\
    \  }\n  for (int i= max_num - 1; i >= 0; i--) buf[i].reset();\n  std::sort(rem.begin(),\
    \ rem.end(), [&](id_num l, id_num r) { return l.num < r.num; });\n  std::vector<id_num>\
    \ nrem;\n  while (!rem.empty() && rem.back().num + cur.count() >= clique.count())\
    \ {\n   for (auto u: rem)\n    if (adj[rem.back().id][u.id]) nrem.emplace_back(u),\
    \ buf[0].set(u.id);\n   for (auto u: nrem) deg[u.id]= (buf[0] & adj[u.id]).count();\n\
    \   buf[0].reset(), cur.set(rem.back().id);\n   dfs(nrem);\n   nrem.clear(), cur.reset(rem.back().id),\
    \ rem.pop_back();\n  }\n }\npublic:\n MaxClique(int n_): adj(n_), buf(n_ + 1),\
    \ deg(n_) {}\n void add_edge(int u, int v) { adj[u][v]= adj[v][u]= true; }\n std::vector<int>\
    \ get_max_clique() {\n  std::vector<id_num> nrem;\n  for (int i= adj.size() -\
    \ 1; i >= 0; i--) nrem.emplace_back(id_num{(std::size_t)i, 0}), deg[i]= adj[i].count();\n\
    \  dfs(nrem);\n  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n;\
    \ i++)\n   if (clique[i]) ret.push_back(i);\n  return ret;\n }\n std::vector<int>\
    \ get_max_independent_set() {\n  for (int i= adj.size() - 1; i >= 0; i--)\n  \
    \ for (int j= i - 1; j >= 0; j--) adj[i][j]= adj[j][i]= ~adj[j][i];\n  return\
    \ get_max_clique();\n }\n std::vector<int> get_min_vertex_cover() {\n  get_max_independent_set();\n\
    \  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n; i++)\n   if (!clique[i])\
    \ ret.push_back(i);\n  return ret;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/MaxClique.hpp
  requiredBy: []
  timestamp: '2023-01-23 16:45:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/maximum_independent_set.test.cpp
documentation_of: src/Graph/MaxClique.hpp
layout: document
title: "\u6700\u5927\u30AF\u30EA\u30FC\u30AF"
---
最大独立集合は補グラフの最大クリーク \
最小頂点被覆は最大独立集合の補集合 \
120頂点ぐらいはいける
## 問題例
[yukicoder No.382 シャイな人たち (2)](https://yukicoder.me/problems/no/382) (120頂点)