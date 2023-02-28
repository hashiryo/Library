---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
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
    \ ord(n), par(n, -2), dat(n, 0);\n  int k= n;\n  for (int s= 0, p; s < n; ++s)\n\
    \   if (par[s] == -2)\n    for (par[p= s]= -1; p >= 0;) {\n     if (dat[p] ==\
    \ (int)adj[p].size()) {\n      ord[--k]= p, p= par[p];\n      continue;\n    \
    \ }\n     if (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n    }\n\
    \  dat.assign(n, 1);\n  for (int s: ord)\n   if (dat[s]) {\n    blk.resize(++k),\
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
    \ dag;\n }\n};\n#line 3 \"src/Math/TwoSatisfiability.hpp\"\nclass TwoSatisfiability\
    \ {\n int sz;\n StronglyConnectedComponents scc;\npublic:\n TwoSatisfiability(int\
    \ n): sz(n), scc(2 * n) {}\n void add_if(int u, int v) { scc.add_edge(u, v), scc.add_edge(neg(v),\
    \ neg(u)); }  // u -> v <=> !v -> !u\n void add_or(int u, int v) { add_if(neg(u),\
    \ v); }                                 // u or v <=> !u -> v\n void add_nand(int\
    \ u, int v) { add_if(u, neg(v)); }                               // u nand v <=>\
    \ u -> !v\n void set_true(int u) { scc.add_edge(neg(u), u); }                \
    \                // u <=> !u -> u\n void set_false(int u) { scc.add_edge(u, neg(u));\
    \ }                               // !u <=> u -> !u\n inline int neg(int x) const\
    \ { return x >= sz ? x - sz : x + sz; }\n std::vector<bool> solve() const {\n\
    \  std::vector<int> I= scc.get_index(scc.get_block());\n  std::vector<bool> ret(sz);\n\
    \  for (int i= 0; i < sz; i++) {\n   if (I[i] == I[neg(i)]) return {};  // no\
    \ solution\n   ret[i]= I[i] > I[neg(i)];\n  }\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\nclass\
    \ TwoSatisfiability {\n int sz;\n StronglyConnectedComponents scc;\npublic:\n\
    \ TwoSatisfiability(int n): sz(n), scc(2 * n) {}\n void add_if(int u, int v) {\
    \ scc.add_edge(u, v), scc.add_edge(neg(v), neg(u)); }  // u -> v <=> !v -> !u\n\
    \ void add_or(int u, int v) { add_if(neg(u), v); }                           \
    \      // u or v <=> !u -> v\n void add_nand(int u, int v) { add_if(u, neg(v));\
    \ }                               // u nand v <=> u -> !v\n void set_true(int\
    \ u) { scc.add_edge(neg(u), u); }                                // u <=> !u ->\
    \ u\n void set_false(int u) { scc.add_edge(u, neg(u)); }                     \
    \          // !u <=> u -> !u\n inline int neg(int x) const { return x >= sz ?\
    \ x - sz : x + sz; }\n std::vector<bool> solve() const {\n  std::vector<int> I=\
    \ scc.get_index(scc.get_block());\n  std::vector<bool> ret(sz);\n  for (int i=\
    \ 0; i < sz; i++) {\n   if (I[i] == I[neg(i)]) return {};  // no solution\n  \
    \ ret[i]= I[i] > I[neg(i)];\n  }\n  return ret;\n }\n};\n"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: src/Math/TwoSatisfiability.hpp
  requiredBy: []
  timestamp: '2023-02-07 17:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: src/Math/TwoSatisfiability.hpp
layout: document
title: 2-SAT
---
強連結成分分解を用いる \
solve():真偽値の割当を返す(充足不可能なら空)