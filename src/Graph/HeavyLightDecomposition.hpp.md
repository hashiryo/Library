---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.HLD.test.cpp
    title: test/aoj/2667.HLD.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include <vector>\n\
    #include <algorithm>\nclass HeavyLightDecomposition {\n std::vector<std::vector<int>>\
    \ adj;\n std::vector<int> sz, in, out, head, par;\n void dfs_sz(int v, int p)\
    \ {\n  if (adj[v].size() && adj[v][0] == p) std::swap(adj[v][0], adj[v].back());\n\
    \  for (auto &u: adj[v])\n   if (u != p)\n    if (dfs_sz(u, v), sz[v]+= sz[u];\
    \ sz[adj[v][0]] < sz[u]) std::swap(adj[v][0], u);\n }\n void dfs_hld(int v, int\
    \ p, int &ts) {\n  par[v]= p, in[v]= ts++;\n  for (auto &u: adj[v])\n   if (u\
    \ != p) head[u]= (adj[v][0] == u ? head[v] : u), dfs_hld(u, v, ts);\n  out[v]=\
    \ ts;\n }\npublic:\n HeavyLightDecomposition(int n): adj(n), sz(n, 1), in(n, 0),\
    \ out(n, 0), head(n, 0), par(n, 0) {}\n void add_edge(int u, int v) { adj[u].push_back(v),\
    \ adj[v].push_back(u); }\n void build(int rt= 0) {\n  int timestamp= 0;\n  dfs_sz(rt,\
    \ -1), dfs_hld(rt, -1, timestamp);\n }\n int lca(int u, int v) const {\n  for\
    \ (;; v= par[head[v]]) {\n   if (in[u] > in[v]) std::swap(u, v);\n   if (head[u]\
    \ == head[v]) return u;\n  }\n }\n template <typename T, typename Q, typename\
    \ F> T fold_path(int u, int v, const Q &q, const F &f, const T ti, bool edge=\
    \ false) {\n  T vl= ti, vr= ti;\n  for (;; vl= f(q(in[head[v]], in[v] + 1), vl),\
    \ v= par[head[v]]) {\n   if (in[u] > in[v]) std::swap(u, v), std::swap(vl, vr);\n\
    \   if (head[u] == head[v]) break;\n  }\n  return f(f(q(in[u] + edge, in[v] +\
    \ 1), vl), vr);\n }\n template <typename T, typename Q> T fold_subtree(int v,\
    \ const Q &q, bool edge= false) { return q(in[v] + edge, out[v]); }\n template\
    \ <typename Q> void apply_path(int u, int v, const Q &q, bool edge= false) {\n\
    \  for (;; q(in[head[v]], in[v] + 1), v= par[head[v]]) {\n   if (in[u] > in[v])\
    \ std::swap(u, v);\n   if (head[u] == head[v]) break;\n  }\n  q(in[u] + edge,\
    \ in[v] + 1);\n }\n template <typename Q> void apply_subtree(int v, const Q &q,\
    \ bool edge= false) { q(in[v] + edge, out[v]); }\n int operator[](int i) const\
    \ { return in[i]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nclass HeavyLightDecomposition\
    \ {\n std::vector<std::vector<int>> adj;\n std::vector<int> sz, in, out, head,\
    \ par;\n void dfs_sz(int v, int p) {\n  if (adj[v].size() && adj[v][0] == p) std::swap(adj[v][0],\
    \ adj[v].back());\n  for (auto &u: adj[v])\n   if (u != p)\n    if (dfs_sz(u,\
    \ v), sz[v]+= sz[u]; sz[adj[v][0]] < sz[u]) std::swap(adj[v][0], u);\n }\n void\
    \ dfs_hld(int v, int p, int &ts) {\n  par[v]= p, in[v]= ts++;\n  for (auto &u:\
    \ adj[v])\n   if (u != p) head[u]= (adj[v][0] == u ? head[v] : u), dfs_hld(u,\
    \ v, ts);\n  out[v]= ts;\n }\npublic:\n HeavyLightDecomposition(int n): adj(n),\
    \ sz(n, 1), in(n, 0), out(n, 0), head(n, 0), par(n, 0) {}\n void add_edge(int\
    \ u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n void build(int rt=\
    \ 0) {\n  int timestamp= 0;\n  dfs_sz(rt, -1), dfs_hld(rt, -1, timestamp);\n }\n\
    \ int lca(int u, int v) const {\n  for (;; v= par[head[v]]) {\n   if (in[u] >\
    \ in[v]) std::swap(u, v);\n   if (head[u] == head[v]) return u;\n  }\n }\n template\
    \ <typename T, typename Q, typename F> T fold_path(int u, int v, const Q &q, const\
    \ F &f, const T ti, bool edge= false) {\n  T vl= ti, vr= ti;\n  for (;; vl= f(q(in[head[v]],\
    \ in[v] + 1), vl), v= par[head[v]]) {\n   if (in[u] > in[v]) std::swap(u, v),\
    \ std::swap(vl, vr);\n   if (head[u] == head[v]) break;\n  }\n  return f(f(q(in[u]\
    \ + edge, in[v] + 1), vl), vr);\n }\n template <typename T, typename Q> T fold_subtree(int\
    \ v, const Q &q, bool edge= false) { return q(in[v] + edge, out[v]); }\n template\
    \ <typename Q> void apply_path(int u, int v, const Q &q, bool edge= false) {\n\
    \  for (;; q(in[head[v]], in[v] + 1), v= par[head[v]]) {\n   if (in[u] > in[v])\
    \ std::swap(u, v);\n   if (head[u] == head[v]) break;\n  }\n  q(in[u] + edge,\
    \ in[v] + 1);\n }\n template <typename Q> void apply_subtree(int v, const Q &q,\
    \ bool edge= false) { q(in[v] + edge, out[v]); }\n int operator[](int i) const\
    \ { return in[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-01-21 16:53:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2667.HLD.test.cpp
  - test/yukicoder/235.HLD.test.cpp
documentation_of: src/Graph/HeavyLightDecomposition.hpp
layout: document
title: "HL\u5206\u89E3"
---
可換性を要求