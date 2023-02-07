---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/arc106_b.test.cpp
    title: test/atcoder/arc106_b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/LinearSystemIncidence.hpp\"\n#include <vector>\n\
    #include <tuple>\n#include <type_traits>\ntemplate <typename T> class LinearSystemIncidence\
    \ {\n int m;\n std::vector<std::vector<std::tuple<int, int, bool>>> adj;\npublic:\n\
    \ LinearSystemIncidence(int n): m(0), adj(n) {}\n void add_edge(int src, int dst)\
    \ { adj[src].emplace_back(m, dst, true), adj[dst].emplace_back(m++, src, false);\
    \ }\n std::vector<T> solve(const std::vector<T> &b) const {\n  std::vector<T>\
    \ x(m);\n  std::vector<bool> used(adj.size());\n  auto dfs= [&](auto self, int\
    \ u) -> T {\n   used[u]= true;\n   T ret= b[u];\n   for (auto [id, to, fwd]: adj[u])\n\
    \    if (!used[to]) {\n     T tmp= self(self, to);\n     if constexpr (std::is_same_v<T,\
    \ bool>) x[id]= tmp, ret^= tmp;\n     else x[id]= fwd ? tmp : -tmp, ret+= tmp;\n\
    \    }\n   return ret;\n  };\n  for (std::size_t u= adj.size(); u--;)\n   if (!used[u]\
    \ && dfs(dfs, u) != T(0)) return std::vector<T>();  // no sloutions\n  return\
    \ x;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <type_traits>\n\
    template <typename T> class LinearSystemIncidence {\n int m;\n std::vector<std::vector<std::tuple<int,\
    \ int, bool>>> adj;\npublic:\n LinearSystemIncidence(int n): m(0), adj(n) {}\n\
    \ void add_edge(int src, int dst) { adj[src].emplace_back(m, dst, true), adj[dst].emplace_back(m++,\
    \ src, false); }\n std::vector<T> solve(const std::vector<T> &b) const {\n  std::vector<T>\
    \ x(m);\n  std::vector<bool> used(adj.size());\n  auto dfs= [&](auto self, int\
    \ u) -> T {\n   used[u]= true;\n   T ret= b[u];\n   for (auto [id, to, fwd]: adj[u])\n\
    \    if (!used[to]) {\n     T tmp= self(self, to);\n     if constexpr (std::is_same_v<T,\
    \ bool>) x[id]= tmp, ret^= tmp;\n     else x[id]= fwd ? tmp : -tmp, ret+= tmp;\n\
    \    }\n   return ret;\n  };\n  for (std::size_t u= adj.size(); u--;)\n   if (!used[u]\
    \ && dfs(dfs, u) != T(0)) return std::vector<T>();  // no sloutions\n  return\
    \ x;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/LinearSystemIncidence.hpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/arc106_b.test.cpp
documentation_of: src/Graph/LinearSystemIncidence.hpp
layout: document
title: "\u63A5\u7D9A\u884C\u5217\u306E\u9023\u7ACB\u65B9\u7A0B\u5F0F"
---
## 計算量
$\mathcal{O}(V+E)$
## 問題例
[AtCoder Beginner Contest 155 F - Perils in Parallel](https://atcoder.jp/contests/abc155/tasks/abc155_f) (sp judge)\
[AtCoder Grand Contest 035 B - Even Degrees ](https://atcoder.jp/contests/agc035/tasks/agc035_b) (sp judge)\
[CODE FESTIVAL 2017 Final E - Combination Lock](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e)