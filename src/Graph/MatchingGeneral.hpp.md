---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3032.test.cpp
    title: test/aoj/3032.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/general_matching.test.cpp
    title: test/yosupo/general_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\
      \u30E9\u30D5)"
    links: []
  bundledCode: "#line 2 \"src/Graph/MatchingGeneral.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\
    \u30D5)\n * @category \u30B0\u30E9\u30D5\n *   O(VE log V)\n *  Gabow\u306EEdmonds'\
    \ Algorithm\n *  \u8FD4\u308A\u5024:{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,\u5404\
    \u9802\u70B9\u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\u3089-1\uFF09}\n */\n\n\
    // BEGIN CUT HERE\n\nclass MatchingGeneral {\n  int n, res;\n  std::vector<std::vector<int>>\
    \ adj;\n  std::vector<int> mate, idx, p;\n  std::vector<std::pair<int, int>> edges;\n\
    \  void rematch(int u, int v) {\n    int w = mate[u];\n    mate[u] = v;\n    if\
    \ (w == -1 || mate[w] != u) return;\n    if (edges[u].second == -1) {\n      rematch(mate[w]\
    \ = edges[u].first, w);\n    } else {\n      rematch(edges[u].first, edges[u].second);\n\
    \      rematch(edges[u].second, edges[u].first);\n    }\n  }\n  int f(int x) {\
    \ return (idx[x] != res || p[x] == -1) ? x : (p[x] = f(p[x])); }\n  bool check(int\
    \ root) {\n    std::queue<int> que;\n    edges[root] = {-1, -1}, idx[root] = res,\
    \ p[root] = -1, que.push(root);\n    while (!que.empty()) {\n      int x = que.front();\n\
    \      que.pop();\n      for (int y : adj[x]) {\n        if (y == root) continue;\n\
    \        if (mate[y] == -1) {\n          return rematch(mate[y] = x, y), true;\n\
    \        } else if (idx[y] == res) {\n          int u = f(x), v = f(y), w = root;\n\
    \          if (u == v) continue;\n          while (u != root || v != root) {\n\
    \            if (v != root) std::swap(u, v);\n            if (edges[u].first ==\
    \ x && edges[u].second == y) {\n              w = u;\n              break;\n \
    \           }\n            edges[u] = {x, y}, u = f(edges[mate[u]].first);\n \
    \         }\n          for (int t = f(x); t != w; t = f(edges[mate[t]].first))\n\
    \            idx[t] = res, p[t] = w, que.push(t);\n          for (int t = f(y);\
    \ t != w; t = f(edges[mate[t]].first))\n            idx[t] = res, p[t] = w, que.push(t);\n\
    \        } else if (idx[mate[y]] != res) {\n          edges[y] = {-1, -1}, edges[mate[y]]\
    \ = {x, -1};\n          idx[mate[y]] = res, p[mate[y]] = y, que.push(mate[y]);\n\
    \        }\n      }\n    }\n    return false;\n  }\n\n public:\n  MatchingGeneral(int\
    \ n)\n      : n(n), res(0), adj(n), mate(n, -1), idx(n, -1), p(n), edges(n) {}\n\
    \  void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n\
    \  std::pair<int, std::vector<int>> get_matching() {\n    for (int i = 0; i <\
    \ n; i++)\n      if (mate[i] == -1) res += check(i);\n    return std::make_pair(res,\
    \ mate);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5)\n * @category \u30B0\u30E9\
    \u30D5\n *   O(VE log V)\n *  Gabow\u306EEdmonds' Algorithm\n *  \u8FD4\u308A\u5024\
    :{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,\u5404\u9802\u70B9\u306E\u76F8\u65B9(\u3044\
    \u306A\u3044\u306A\u3089-1\uFF09}\n */\n\n// BEGIN CUT HERE\n\nclass MatchingGeneral\
    \ {\n  int n, res;\n  std::vector<std::vector<int>> adj;\n  std::vector<int> mate,\
    \ idx, p;\n  std::vector<std::pair<int, int>> edges;\n  void rematch(int u, int\
    \ v) {\n    int w = mate[u];\n    mate[u] = v;\n    if (w == -1 || mate[w] !=\
    \ u) return;\n    if (edges[u].second == -1) {\n      rematch(mate[w] = edges[u].first,\
    \ w);\n    } else {\n      rematch(edges[u].first, edges[u].second);\n      rematch(edges[u].second,\
    \ edges[u].first);\n    }\n  }\n  int f(int x) { return (idx[x] != res || p[x]\
    \ == -1) ? x : (p[x] = f(p[x])); }\n  bool check(int root) {\n    std::queue<int>\
    \ que;\n    edges[root] = {-1, -1}, idx[root] = res, p[root] = -1, que.push(root);\n\
    \    while (!que.empty()) {\n      int x = que.front();\n      que.pop();\n  \
    \    for (int y : adj[x]) {\n        if (y == root) continue;\n        if (mate[y]\
    \ == -1) {\n          return rematch(mate[y] = x, y), true;\n        } else if\
    \ (idx[y] == res) {\n          int u = f(x), v = f(y), w = root;\n          if\
    \ (u == v) continue;\n          while (u != root || v != root) {\n           \
    \ if (v != root) std::swap(u, v);\n            if (edges[u].first == x && edges[u].second\
    \ == y) {\n              w = u;\n              break;\n            }\n       \
    \     edges[u] = {x, y}, u = f(edges[mate[u]].first);\n          }\n         \
    \ for (int t = f(x); t != w; t = f(edges[mate[t]].first))\n            idx[t]\
    \ = res, p[t] = w, que.push(t);\n          for (int t = f(y); t != w; t = f(edges[mate[t]].first))\n\
    \            idx[t] = res, p[t] = w, que.push(t);\n        } else if (idx[mate[y]]\
    \ != res) {\n          edges[y] = {-1, -1}, edges[mate[y]] = {x, -1};\n      \
    \    idx[mate[y]] = res, p[mate[y]] = y, que.push(mate[y]);\n        }\n     \
    \ }\n    }\n    return false;\n  }\n\n public:\n  MatchingGeneral(int n)\n   \
    \   : n(n), res(0), adj(n), mate(n, -1), idx(n, -1), p(n), edges(n) {}\n  void\
    \ add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n  std::pair<int,\
    \ std::vector<int>> get_matching() {\n    for (int i = 0; i < n; i++)\n      if\
    \ (mate[i] == -1) res += check(i);\n    return std::make_pair(res, mate);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/MatchingGeneral.hpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/general_matching.test.cpp
  - test/aoj/3032.test.cpp
documentation_of: src/Graph/MatchingGeneral.hpp
layout: document
redirect_from:
- /library/src/Graph/MatchingGeneral.hpp
- /library/src/Graph/MatchingGeneral.hpp.html
title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5)"
---