---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':x:'
    path: test/yukicoder/768.test.cpp
    title: test/yukicoder/768.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links:
    - https://ei1333.hateblo.jp/entry/2018/12/21/004022
  bundledCode: "#line 2 \"src/Graph/ReRooting.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u5168\u65B9\u4F4D\u6728DP\n * @category \u30B0\u30E9\u30D5\n * @see\
    \ https://ei1333.hateblo.jp/entry/2018/12/21/004022\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <typename T, typename E = int>\nstruct ReRooting {\n  struct Edge {\n\
    \    int to;\n    E data;\n    T dp, ndp;\n  };\n  std::vector<std::vector<Edge>>\
    \ adj;\n\n private:\n  const std::function<T(T, T)> op;\n  const T id;\n  const\
    \ std::function<T(T, E)> lift;\n  std::vector<T> subdp, dp;\n\n private:\n  void\
    \ dfs_sub(int idx, int par) {\n    for (auto &e : adj[idx]) {\n      if (e.to\
    \ == par) continue;\n      dfs_sub(e.to, idx);\n      subdp[idx] = op(subdp[idx],\
    \ lift(subdp[e.to], e.data));\n    }\n  }\n  void dfs_all(int idx, int par, const\
    \ T &top) {\n    T buff = id;\n    for (int i = 0; i < (int)adj[idx].size(); i++)\
    \ {\n      auto &e = adj[idx][i];\n      e.ndp = buff;\n      e.dp = lift(par\
    \ == e.to ? top : subdp[e.to], e.data);\n      buff = op(buff, e.dp);\n    }\n\
    \    dp[idx] = buff;\n    buff = id;\n    for (int i = (int)adj[idx].size() -\
    \ 1; i >= 0; i--) {\n      auto &e = adj[idx][i];\n      if (e.to != par) dfs_all(e.to,\
    \ idx, op(e.ndp, buff));\n      e.ndp = op(e.ndp, buff);\n      buff = op(buff,\
    \ e.dp);\n    }\n  }\n\n public:\n  ReRooting(\n      int N, const std::function<T(T,\
    \ T)> &op_, T id_,\n      const std::function<T(T, E)> &lift_\n      = [](const\
    \ T &dp, const E &dat) { return dp; })\n      : adj(N), op(op_), id(id_), lift(lift_),\
    \ subdp(N, id_), dp(N, id_) {}\n  void add_edge(int src, int dst, E d = E()) {\n\
    \    adj[src].emplace_back((Edge){dst, d, id, id});\n  }\n  std::vector<T> run()\
    \ {\n    dfs_sub(0, -1);\n    dfs_all(0, -1, id);\n    return dp;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u5168\u65B9\u4F4D\
    \u6728DP\n * @category \u30B0\u30E9\u30D5\n * @see https://ei1333.hateblo.jp/entry/2018/12/21/004022\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename T, typename E = int>\nstruct ReRooting\
    \ {\n  struct Edge {\n    int to;\n    E data;\n    T dp, ndp;\n  };\n  std::vector<std::vector<Edge>>\
    \ adj;\n\n private:\n  const std::function<T(T, T)> op;\n  const T id;\n  const\
    \ std::function<T(T, E)> lift;\n  std::vector<T> subdp, dp;\n\n private:\n  void\
    \ dfs_sub(int idx, int par) {\n    for (auto &e : adj[idx]) {\n      if (e.to\
    \ == par) continue;\n      dfs_sub(e.to, idx);\n      subdp[idx] = op(subdp[idx],\
    \ lift(subdp[e.to], e.data));\n    }\n  }\n  void dfs_all(int idx, int par, const\
    \ T &top) {\n    T buff = id;\n    for (int i = 0; i < (int)adj[idx].size(); i++)\
    \ {\n      auto &e = adj[idx][i];\n      e.ndp = buff;\n      e.dp = lift(par\
    \ == e.to ? top : subdp[e.to], e.data);\n      buff = op(buff, e.dp);\n    }\n\
    \    dp[idx] = buff;\n    buff = id;\n    for (int i = (int)adj[idx].size() -\
    \ 1; i >= 0; i--) {\n      auto &e = adj[idx][i];\n      if (e.to != par) dfs_all(e.to,\
    \ idx, op(e.ndp, buff));\n      e.ndp = op(e.ndp, buff);\n      buff = op(buff,\
    \ e.dp);\n    }\n  }\n\n public:\n  ReRooting(\n      int N, const std::function<T(T,\
    \ T)> &op_, T id_,\n      const std::function<T(T, E)> &lift_\n      = [](const\
    \ T &dp, const E &dat) { return dp; })\n      : adj(N), op(op_), id(id_), lift(lift_),\
    \ subdp(N, id_), dp(N, id_) {}\n  void add_edge(int src, int dst, E d = E()) {\n\
    \    adj[src].emplace_back((Edge){dst, d, id, id});\n  }\n  std::vector<T> run()\
    \ {\n    dfs_sub(0, -1);\n    dfs_all(0, -1, id);\n    return dp;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/ReRooting.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1595.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/yukicoder/768.test.cpp
documentation_of: src/Graph/ReRooting.hpp
layout: document
redirect_from:
- /library/src/Graph/ReRooting.hpp
- /library/src/Graph/ReRooting.hpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
