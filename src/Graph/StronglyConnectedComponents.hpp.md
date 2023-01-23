---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0366.test.cpp
    title: test/aoj/0366.test.cpp
  - icon: ':x:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n#include <vector>\n\
    #include <functional>\n#include <algorithm>\nstruct StronglyConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\n StronglyConnectedComponents(int n):\
    \ adj(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst); }\n std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_SCC() {\n  std::vector<std::vector<int>> scc;\n  std::vector<int>\
    \ S, B, index(adj.size());\n  std::function<void(int)> dfs= [&](int u) {\n   B.push_back(index[u]=\
    \ S.size());\n   S.push_back(u);\n   for (int v: adj[u]) {\n    if (!index[v])\
    \ dfs(v);\n    else\n     while (index[v] < B.back()) B.pop_back();\n   }\n  \
    \ if (index[u] == B.back()) {\n    scc.push_back({});\n    B.pop_back();\n   \
    \ for (; index[u] < (int)S.size(); S.pop_back()) {\n     scc.back().push_back(S.back());\n\
    \     index[S.back()]= adj.size() + scc.size();\n    }\n   }\n  };\n  for (std::size_t\
    \ u= 0; u < adj.size(); u++)\n   if (!index[u]) dfs(u);\n  reverse(scc.begin(),\
    \ scc.end());\n  for (std::size_t u= 0; u < adj.size(); u++) index[u]= scc.size()\
    \ - index[u] + adj.size();\n  return std::make_pair(scc, index);\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <algorithm>\n\
    struct StronglyConnectedComponents {\n std::vector<std::vector<int>> adj;\n StronglyConnectedComponents(int\
    \ n): adj(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst); }\n\
    \ std::pair<std::vector<std::vector<int>>, std::vector<int>> get_SCC() {\n  std::vector<std::vector<int>>\
    \ scc;\n  std::vector<int> S, B, index(adj.size());\n  std::function<void(int)>\
    \ dfs= [&](int u) {\n   B.push_back(index[u]= S.size());\n   S.push_back(u);\n\
    \   for (int v: adj[u]) {\n    if (!index[v]) dfs(v);\n    else\n     while (index[v]\
    \ < B.back()) B.pop_back();\n   }\n   if (index[u] == B.back()) {\n    scc.push_back({});\n\
    \    B.pop_back();\n    for (; index[u] < (int)S.size(); S.pop_back()) {\n   \
    \  scc.back().push_back(S.back());\n     index[S.back()]= adj.size() + scc.size();\n\
    \    }\n   }\n  };\n  for (std::size_t u= 0; u < adj.size(); u++)\n   if (!index[u])\
    \ dfs(u);\n  reverse(scc.begin(), scc.end());\n  for (std::size_t u= 0; u < adj.size();\
    \ u++) index[u]= scc.size() - index[u] + adj.size();\n  return std::make_pair(scc,\
    \ index);\n }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/StronglyConnectedComponents.hpp
  requiredBy:
  - src/Math/TwoSatisfiability.hpp
  timestamp: '2023-01-23 19:46:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0366.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: src/Graph/StronglyConnectedComponents.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
Gabow \
返り値:{強連結成分(トポロジカルソート),ノードの属する成分の添字}
## 計算量
$\mathcal{O}(V)$