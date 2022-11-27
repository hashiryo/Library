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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @category \u30B0\
    \u30E9\u30D5\n *  Gabow\n *  O(V + E)\n *  \u8FD4\u308A\u5024:{\u5F37\u9023\u7D50\
    \u6210\u5206(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8),\u30CE\u30FC\
    \u30C9\u306E\u5C5E\u3059\u308B\u6210\u5206\u306E\u6DFB\u5B57}\n */\n\n// BEGIN\
    \ CUT HERE\n\nstruct StronglyConnectedComponents {\n  std::vector<std::vector<int>>\
    \ adj;\n\n  StronglyConnectedComponents(int n) : adj(n) {}\n  void add_edge(int\
    \ src, int dst) { adj[src].push_back(dst); }\n  std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_SCC() {\n    std::vector<std::vector<int>> scc;\n    std::vector<int>\
    \ S, B, index(adj.size());\n    std::function<void(int)> dfs = [&](int u) {\n\
    \      B.push_back(index[u] = S.size());\n      S.push_back(u);\n      for (int\
    \ v : adj[u]) {\n        if (!index[v])\n          dfs(v);\n        else\n   \
    \       while (index[v] < B.back()) B.pop_back();\n      }\n      if (index[u]\
    \ == B.back()) {\n        scc.push_back({});\n        B.pop_back();\n        for\
    \ (; index[u] < (int)S.size(); S.pop_back()) {\n          scc.back().push_back(S.back());\n\
    \          index[S.back()] = adj.size() + scc.size();\n        }\n      }\n  \
    \  };\n    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!index[u])\
    \ dfs(u);\n    reverse(scc.begin(), scc.end());\n    for (std::size_t u = 0; u\
    \ < adj.size(); u++)\n      index[u] = scc.size() - index[u] + adj.size();\n \
    \   return std::make_pair(scc, index);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u5F37\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\n * @category \u30B0\u30E9\u30D5\n *  Gabow\n *  O(V\
    \ + E)\n *  \u8FD4\u308A\u5024:{\u5F37\u9023\u7D50\u6210\u5206(\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8),\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\
    \u6210\u5206\u306E\u6DFB\u5B57}\n */\n\n// BEGIN CUT HERE\n\nstruct StronglyConnectedComponents\
    \ {\n  std::vector<std::vector<int>> adj;\n\n  StronglyConnectedComponents(int\
    \ n) : adj(n) {}\n  void add_edge(int src, int dst) { adj[src].push_back(dst);\
    \ }\n  std::pair<std::vector<std::vector<int>>, std::vector<int>> get_SCC() {\n\
    \    std::vector<std::vector<int>> scc;\n    std::vector<int> S, B, index(adj.size());\n\
    \    std::function<void(int)> dfs = [&](int u) {\n      B.push_back(index[u] =\
    \ S.size());\n      S.push_back(u);\n      for (int v : adj[u]) {\n        if\
    \ (!index[v])\n          dfs(v);\n        else\n          while (index[v] < B.back())\
    \ B.pop_back();\n      }\n      if (index[u] == B.back()) {\n        scc.push_back({});\n\
    \        B.pop_back();\n        for (; index[u] < (int)S.size(); S.pop_back())\
    \ {\n          scc.back().push_back(S.back());\n          index[S.back()] = adj.size()\
    \ + scc.size();\n        }\n      }\n    };\n    for (std::size_t u = 0; u < adj.size();\
    \ u++)\n      if (!index[u]) dfs(u);\n    reverse(scc.begin(), scc.end());\n \
    \   for (std::size_t u = 0; u < adj.size(); u++)\n      index[u] = scc.size()\
    \ - index[u] + adj.size();\n    return std::make_pair(scc, index);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/StronglyConnectedComponents.hpp
  requiredBy:
  - src/Math/TwoSatisfiability.hpp
  timestamp: '2020-10-24 15:09:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/scc.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/aoj/0366.test.cpp
documentation_of: src/Graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/Graph/StronglyConnectedComponents.hpp
- /library/src/Graph/StronglyConnectedComponents.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
