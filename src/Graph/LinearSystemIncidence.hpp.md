---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
    links:
    - https://opt-cp.com/linear-system-incidence/
  bundledCode: "#line 2 \"src/Graph/LinearSystemIncidence.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F\n\
    \ * @category \u30B0\u30E9\u30D5\n * @see https://opt-cp.com/linear-system-incidence/\n\
    \ * O(V+E)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nclass LinearSystemIncidence\
    \ {\n  struct Edge {\n    int id, to;\n    bool fwd;\n  };\n  int m;\n  std::vector<T>\
    \ x;\n  std::vector<char> used;\n  std::vector<std::vector<Edge>> adj;\n  T dfs(std::vector<T>\
    \ &b, int u) {\n    used[u] = true;\n    T ret = b[u];\n    for (Edge e : adj[u])\n\
    \      if (!used[e.to]) {\n        T tmp = dfs(b, e.to);\n        x[e.id] = e.fwd\
    \ ? tmp : -tmp, ret += tmp;\n      }\n    return ret;\n  }\n\n public:\n  LinearSystemIncidence(int\
    \ n) : m(0), adj(n) {}\n  void add_edge(int src, int dst) {\n    adj[src].emplace_back(m,\
    \ dst, true), adj[dst].emplace_back(m++, src, false);\n  }\n  std::pair<bool,\
    \ std::vector<T>> solve(std::vector<T> &b) {\n    x.assign(m, T(0)), used.assign(adj.size(),\
    \ false);\n    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!used[u]\
    \ && dfs(b, u) != T(0))\n        return {false, std::vector<T>()};  // no sloution\n\
    \    return {true, std::move(x)};\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u63A5\u7D9A\u884C\
    \u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F\n * @category \u30B0\u30E9\u30D5\n\
    \ * @see https://opt-cp.com/linear-system-incidence/\n * O(V+E)\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename T>\nclass LinearSystemIncidence {\n  struct Edge\
    \ {\n    int id, to;\n    bool fwd;\n  };\n  int m;\n  std::vector<T> x;\n  std::vector<char>\
    \ used;\n  std::vector<std::vector<Edge>> adj;\n  T dfs(std::vector<T> &b, int\
    \ u) {\n    used[u] = true;\n    T ret = b[u];\n    for (Edge e : adj[u])\n  \
    \    if (!used[e.to]) {\n        T tmp = dfs(b, e.to);\n        x[e.id] = e.fwd\
    \ ? tmp : -tmp, ret += tmp;\n      }\n    return ret;\n  }\n\n public:\n  LinearSystemIncidence(int\
    \ n) : m(0), adj(n) {}\n  void add_edge(int src, int dst) {\n    adj[src].emplace_back(m,\
    \ dst, true), adj[dst].emplace_back(m++, src, false);\n  }\n  std::pair<bool,\
    \ std::vector<T>> solve(std::vector<T> &b) {\n    x.assign(m, T(0)), used.assign(adj.size(),\
    \ false);\n    for (std::size_t u = 0; u < adj.size(); u++)\n      if (!used[u]\
    \ && dfs(b, u) != T(0))\n        return {false, std::vector<T>()};  // no sloution\n\
    \    return {true, std::move(x)};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/LinearSystemIncidence.hpp
  requiredBy: []
  timestamp: '2021-10-23 18:23:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/LinearSystemIncidence.hpp
layout: document
redirect_from:
- /library/src/Graph/LinearSystemIncidence.hpp
- /library/src/Graph/LinearSystemIncidence.hpp.html
title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
---
