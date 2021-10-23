---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.HLD.test.cpp
    title: test/aoj/2667.HLD.test.cpp
  - icon: ':x:'
    path: test/atcoder/kupc2018_m.test.cpp
    title: test/atcoder/kupc2018_m.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "HL\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title HL\u5206\u89E3\n * @category \u30B0\u30E9\u30D5\n * \u53EF\u63DB\
    \u6027\u3092\u8981\u6C42\n */\n\n// BEGIN CUT HERE\n\nstruct HeavyLightDecomposition\
    \ {\n  std::vector<std::vector<int>> adj;\n  std::vector<int> sz, in, out, head,\
    \ par;\n\n  HeavyLightDecomposition(int n) : adj(n) {}\n  void add_edge(int u,\
    \ int v) {\n    adj[u].push_back(v);\n    adj[v].push_back(u);\n  }\n  void build(int\
    \ rt = 0) {\n    sz.assign(adj.size(), 1);\n    in.assign(adj.size(), 0);\n  \
    \  out.assign(adj.size(), 0);\n    head.assign(adj.size(), 0);\n    par.assign(adj.size(),\
    \ 0);\n    dfs_sz(rt, -1);\n    int t = 0;\n    dfs_hld(rt, -1, t);\n  }\n  int\
    \ lca(int u, int v) const {\n    for (;; v = par[head[v]]) {\n      if (in[u]\
    \ > in[v]) std::swap(u, v);\n      if (head[u] == head[v]) return u;\n    }\n\
    \  }\n  template <typename T, typename Q, typename F>\n  T fold_path(int u, int\
    \ v, const Q &q, const F &f, const T ti,\n               bool edge = false) {\n\
    \    T vl = ti, vr = ti;\n    for (;; v = par[head[v]]) {\n      if (in[u] > in[v])\
    \ std::swap(u, v), std::swap(vl, vr);\n      if (head[u] == head[v]) break;\n\
    \      vl = f(q(in[head[v]], in[v] + 1), vl);\n    }\n    return f(f(q(in[u] +\
    \ edge, in[v] + 1), vl), vr);\n  }\n  template <typename T, typename Q>\n  T fold_subtree(int\
    \ v, const Q &q, bool edge = false) {\n    return q(in[v] + edge, out[v]);\n \
    \ }\n\n  template <typename Q>\n  void apply_path(int u, int v, const Q &q, bool\
    \ edge = false) {\n    for (;; v = par[head[v]]) {\n      if (in[u] > in[v]) std::swap(u,\
    \ v);\n      if (head[u] == head[v]) break;\n      q(in[head[v]], in[v] + 1);\n\
    \    }\n    q(in[u] + edge, in[v] + 1);\n  }\n  template <typename Q>\n  void\
    \ apply_subtree(int v, const Q &q, bool edge = false) {\n    q(in[v] + edge, out[v]);\n\
    \  }\n\n private:\n  void dfs_sz(int v, int p) {\n    if (adj[v].size() && adj[v][0]\
    \ == p) std::swap(adj[v][0], adj[v].back());\n    for (auto &u : adj[v])\n   \
    \   if (u != p) {\n        dfs_sz(u, v);\n        sz[v] += sz[u];\n        if\
    \ (sz[adj[v][0]] < sz[u]) std::swap(adj[v][0], u);\n      }\n  }\n  void dfs_hld(int\
    \ v, int p, int &times) {\n    par[v] = p;\n    in[v] = times++;\n    for (auto\
    \ &u : adj[v])\n      if (u != p) {\n        head[u] = (adj[v][0] == u ? head[v]\
    \ : u);\n        dfs_hld(u, v, times);\n      }\n    out[v] = times;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title HL\u5206\u89E3\n *\
    \ @category \u30B0\u30E9\u30D5\n * \u53EF\u63DB\u6027\u3092\u8981\u6C42\n */\n\
    \n// BEGIN CUT HERE\n\nstruct HeavyLightDecomposition {\n  std::vector<std::vector<int>>\
    \ adj;\n  std::vector<int> sz, in, out, head, par;\n\n  HeavyLightDecomposition(int\
    \ n) : adj(n) {}\n  void add_edge(int u, int v) {\n    adj[u].push_back(v);\n\
    \    adj[v].push_back(u);\n  }\n  void build(int rt = 0) {\n    sz.assign(adj.size(),\
    \ 1);\n    in.assign(adj.size(), 0);\n    out.assign(adj.size(), 0);\n    head.assign(adj.size(),\
    \ 0);\n    par.assign(adj.size(), 0);\n    dfs_sz(rt, -1);\n    int t = 0;\n \
    \   dfs_hld(rt, -1, t);\n  }\n  int lca(int u, int v) const {\n    for (;; v =\
    \ par[head[v]]) {\n      if (in[u] > in[v]) std::swap(u, v);\n      if (head[u]\
    \ == head[v]) return u;\n    }\n  }\n  template <typename T, typename Q, typename\
    \ F>\n  T fold_path(int u, int v, const Q &q, const F &f, const T ti,\n      \
    \         bool edge = false) {\n    T vl = ti, vr = ti;\n    for (;; v = par[head[v]])\
    \ {\n      if (in[u] > in[v]) std::swap(u, v), std::swap(vl, vr);\n      if (head[u]\
    \ == head[v]) break;\n      vl = f(q(in[head[v]], in[v] + 1), vl);\n    }\n  \
    \  return f(f(q(in[u] + edge, in[v] + 1), vl), vr);\n  }\n  template <typename\
    \ T, typename Q>\n  T fold_subtree(int v, const Q &q, bool edge = false) {\n \
    \   return q(in[v] + edge, out[v]);\n  }\n\n  template <typename Q>\n  void apply_path(int\
    \ u, int v, const Q &q, bool edge = false) {\n    for (;; v = par[head[v]]) {\n\
    \      if (in[u] > in[v]) std::swap(u, v);\n      if (head[u] == head[v]) break;\n\
    \      q(in[head[v]], in[v] + 1);\n    }\n    q(in[u] + edge, in[v] + 1);\n  }\n\
    \  template <typename Q>\n  void apply_subtree(int v, const Q &q, bool edge =\
    \ false) {\n    q(in[v] + edge, out[v]);\n  }\n\n private:\n  void dfs_sz(int\
    \ v, int p) {\n    if (adj[v].size() && adj[v][0] == p) std::swap(adj[v][0], adj[v].back());\n\
    \    for (auto &u : adj[v])\n      if (u != p) {\n        dfs_sz(u, v);\n    \
    \    sz[v] += sz[u];\n        if (sz[adj[v][0]] < sz[u]) std::swap(adj[v][0],\
    \ u);\n      }\n  }\n  void dfs_hld(int v, int p, int &times) {\n    par[v] =\
    \ p;\n    in[v] = times++;\n    for (auto &u : adj[v])\n      if (u != p) {\n\
    \        head[u] = (adj[v][0] == u ? head[v] : u);\n        dfs_hld(u, v, times);\n\
    \      }\n    out[v] = times;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2021-09-20 02:40:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/235.HLD.test.cpp
  - test/atcoder/kupc2018_m.test.cpp
  - test/aoj/2667.HLD.test.cpp
documentation_of: src/Graph/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/src/Graph/HeavyLightDecomposition.hpp
- /library/src/Graph/HeavyLightDecomposition.hpp.html
title: "HL\u5206\u89E3"
---
