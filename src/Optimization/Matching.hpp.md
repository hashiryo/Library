---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3032.test.cpp
    title: test/aoj/3032.test.cpp
  - icon: ':x:'
    path: test/yosupo/general_matching.test.cpp
    title: test/yosupo/general_matching.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\
      \u30E9\u30D5)"
    links: []
  bundledCode: "#line 2 \"src/Optimization/Matching.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\
    \u30D5)\n * @category \u30B0\u30E9\u30D5\n *   O(VE log V)\n *  Gabow\u306EEdmonds'\
    \ Algorithm\n *  \u8FD4\u308A\u5024:{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,\u5404\
    \u9802\u70B9\u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\u3089-1\uFF09}\n */\n\n\
    // BEGIN CUT HERE\nclass Matching {\n  int n, ret;\n  std::vector<std::vector<int>>\
    \ adj;\n  std::vector<int> mt, idx, p;\n  std::vector<std::array<int, 2>> es;\n\
    \  void rematch(int u, int v, int w = -1) {\n    if (w = mt[u], mt[u] = v; w ==\
    \ -1 || mt[w] != u) return;\n    if (es[u][1] == -1) {\n      rematch(mt[w] =\
    \ es[u][0], w);\n    } else\n      rematch(es[u][0], es[u][1]), rematch(es[u][1],\
    \ es[u][0]);\n  }\n  int f(int x) { return (idx[x] != ret || p[x] == -1) ? x :\
    \ (p[x] = f(p[x])); }\n  bool check(int root) {\n    std::queue<int> que;\n  \
    \  es[root] = {-1, -1}, idx[root] = ret, p[root] = -1, que.push(root);\n    for\
    \ (int x, u, v, w; !que.empty();) {\n      x = que.front(), que.pop();\n     \
    \ for (int y : adj[x]) {\n        if (y == root) continue;\n        if (mt[y]\
    \ == -1) {\n          return rematch(mt[y] = x, y), true;\n        } else if (idx[y]\
    \ == ret) {\n          if (u = f(x), v = f(y), w = root; u == v) continue;\n \
    \         for (; u != root || v != root; es[u] = {x, y}, u = f(es[mt[u]][0]))\
    \ {\n            if (v != root) std::swap(u, v);\n            if (es[u][0] ==\
    \ x && es[u][1] == y) {\n              w = u;\n              break;\n        \
    \    }\n          }\n          for (int t = f(x); t != w; t = f(es[mt[t]][0]))\n\
    \            idx[t] = ret, p[t] = w, que.push(t);\n          for (int t = f(y);\
    \ t != w; t = f(es[mt[t]][0]))\n            idx[t] = ret, p[t] = w, que.push(t);\n\
    \        } else if (idx[mt[y]] != ret)\n          es[y] = {-1, -1}, es[mt[y]]\
    \ = {x, -1}, idx[mt[y]] = ret, p[mt[y]] = y,\n          que.push(mt[y]);\n   \
    \   }\n    }\n    return false;\n  }\n\n public:\n  Matching(int n) : n(n), ret(0),\
    \ adj(n), mt(n, -1), idx(n, -1), p(n), es(n) {}\n  void add_edge(int u, int v)\
    \ { adj[u].push_back(v), adj[v].push_back(u); }\n  std::pair<int, std::vector<int>>\
    \ get_matching() {\n    for (int i = 0; i < n; i++)\n      if (mt[i] == -1) ret\
    \ += check(i);\n    return std::make_pair(ret, mt);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5)\n * @category \u30B0\u30E9\
    \u30D5\n *   O(VE log V)\n *  Gabow\u306EEdmonds' Algorithm\n *  \u8FD4\u308A\u5024\
    :{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,\u5404\u9802\u70B9\u306E\u76F8\u65B9(\u3044\
    \u306A\u3044\u306A\u3089-1\uFF09}\n */\n\n// BEGIN CUT HERE\nclass Matching {\n\
    \  int n, ret;\n  std::vector<std::vector<int>> adj;\n  std::vector<int> mt, idx,\
    \ p;\n  std::vector<std::array<int, 2>> es;\n  void rematch(int u, int v, int\
    \ w = -1) {\n    if (w = mt[u], mt[u] = v; w == -1 || mt[w] != u) return;\n  \
    \  if (es[u][1] == -1) {\n      rematch(mt[w] = es[u][0], w);\n    } else\n  \
    \    rematch(es[u][0], es[u][1]), rematch(es[u][1], es[u][0]);\n  }\n  int f(int\
    \ x) { return (idx[x] != ret || p[x] == -1) ? x : (p[x] = f(p[x])); }\n  bool\
    \ check(int root) {\n    std::queue<int> que;\n    es[root] = {-1, -1}, idx[root]\
    \ = ret, p[root] = -1, que.push(root);\n    for (int x, u, v, w; !que.empty();)\
    \ {\n      x = que.front(), que.pop();\n      for (int y : adj[x]) {\n       \
    \ if (y == root) continue;\n        if (mt[y] == -1) {\n          return rematch(mt[y]\
    \ = x, y), true;\n        } else if (idx[y] == ret) {\n          if (u = f(x),\
    \ v = f(y), w = root; u == v) continue;\n          for (; u != root || v != root;\
    \ es[u] = {x, y}, u = f(es[mt[u]][0])) {\n            if (v != root) std::swap(u,\
    \ v);\n            if (es[u][0] == x && es[u][1] == y) {\n              w = u;\n\
    \              break;\n            }\n          }\n          for (int t = f(x);\
    \ t != w; t = f(es[mt[t]][0]))\n            idx[t] = ret, p[t] = w, que.push(t);\n\
    \          for (int t = f(y); t != w; t = f(es[mt[t]][0]))\n            idx[t]\
    \ = ret, p[t] = w, que.push(t);\n        } else if (idx[mt[y]] != ret)\n     \
    \     es[y] = {-1, -1}, es[mt[y]] = {x, -1}, idx[mt[y]] = ret, p[mt[y]] = y,\n\
    \          que.push(mt[y]);\n      }\n    }\n    return false;\n  }\n\n public:\n\
    \  Matching(int n) : n(n), ret(0), adj(n), mt(n, -1), idx(n, -1), p(n), es(n)\
    \ {}\n  void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u);\
    \ }\n  std::pair<int, std::vector<int>> get_matching() {\n    for (int i = 0;\
    \ i < n; i++)\n      if (mt[i] == -1) ret += check(i);\n    return std::make_pair(ret,\
    \ mt);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/Matching.hpp
  requiredBy: []
  timestamp: '2022-11-18 14:42:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/general_matching.test.cpp
  - test/aoj/3032.test.cpp
documentation_of: src/Optimization/Matching.hpp
layout: document
redirect_from:
- /library/src/Optimization/Matching.hpp
- /library/src/Optimization/Matching.hpp.html
title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5)"
---
