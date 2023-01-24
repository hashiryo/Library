---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/BiConnectedComponents.hpp\"\n#include <vector>\n\
    #include <algorithm>\nclass BiConnectedComponents {\n std::vector<std::vector<int>>\
    \ adj;\npublic:\n BiConnectedComponents(int n): adj(n) {}\n void add_edge(int\
    \ u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n std::vector<std::vector<int>>\
    \ block_cut_tree() {\n  int n= adj.size(), m= n, k= 0;\n  std::vector<int> low(n),\
    \ ord(n), st;\n  std::vector<bool> used(n);\n  std::vector<std::vector<int>> bct;\n\
    \  st.reserve(n);\n  auto dfs= [&](auto &self, int v, int p) -> void {\n   int\
    \ ch= 0, s, x;\n   st.push_back(v), used[v]= true, low[v]= ord[v]= k++;\n   for\
    \ (int u: adj[v])\n    if (u != p) {\n     if (used[u]) low[v]= std::min(low[v],\
    \ ord[u]);\n     else if (s= st.size(), ++ch, self(self, u, v), low[v]= std::min(low[v],\
    \ low[u]); (p == -1 && ch > 1) || (p != -1 && low[u] >= ord[v])) {\n      for\
    \ (bct.resize(m + 1), bct[m].push_back(v), bct[v].push_back(m); st.size() > s;\
    \ st.pop_back()) bct[x= st.back()].push_back(m), bct[m].push_back(x);\n      ++m;\n\
    \     }\n    }\n  };\n  for (int v= n; v--;)\n   if (!used[v]) {\n    dfs(dfs,\
    \ v, -1), bct.resize(m + 1);\n    for (int x: st) bct[x].push_back(m), bct[m].push_back(x);\n\
    \    ++m, st.clear();\n   }\n  return bct;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nclass BiConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\npublic:\n BiConnectedComponents(int\
    \ n): adj(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u);\
    \ }\n std::vector<std::vector<int>> block_cut_tree() {\n  int n= adj.size(), m=\
    \ n, k= 0;\n  std::vector<int> low(n), ord(n), st;\n  std::vector<bool> used(n);\n\
    \  std::vector<std::vector<int>> bct;\n  st.reserve(n);\n  auto dfs= [&](auto\
    \ &self, int v, int p) -> void {\n   int ch= 0, s, x;\n   st.push_back(v), used[v]=\
    \ true, low[v]= ord[v]= k++;\n   for (int u: adj[v])\n    if (u != p) {\n    \
    \ if (used[u]) low[v]= std::min(low[v], ord[u]);\n     else if (s= st.size(),\
    \ ++ch, self(self, u, v), low[v]= std::min(low[v], low[u]); (p == -1 && ch > 1)\
    \ || (p != -1 && low[u] >= ord[v])) {\n      for (bct.resize(m + 1), bct[m].push_back(v),\
    \ bct[v].push_back(m); st.size() > s; st.pop_back()) bct[x= st.back()].push_back(m),\
    \ bct[m].push_back(x);\n      ++m;\n     }\n    }\n  };\n  for (int v= n; v--;)\n\
    \   if (!used[v]) {\n    dfs(dfs, v, -1), bct.resize(m + 1);\n    for (int x:\
    \ st) bct[x].push_back(m), bct[m].push_back(x);\n    ++m, st.clear();\n   }\n\
    \  return bct;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/BiConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-01-24 14:48:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/yosupo/biconnected_components.test.cpp
  - test/yukicoder/1326.test.cpp
documentation_of: src/Graph/BiConnectedComponents.hpp
layout: document
title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
## 参考
[https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)