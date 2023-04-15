---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3022.test.cpp
    title: test/aoj/3022.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':x:'
    path: test/hackerrank/bonnie-and-clyde.test.cpp
    title: test/hackerrank/bonnie-and-clyde.test.cpp
  - icon: ':x:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/Tree.hpp\"\n#include <type_traits>\n#include <cstddef>\n\
    #include <algorithm>\n#include <array>\n#include <numeric>\n#include <cassert>\n\
    #line 2 \"src/DataStructure/CsrArray.hpp\"\n#include <vector>\n#include <iterator>\n\
    template <class T> struct ListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n\
    \ Iterator bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const\
    \ { return ed; }\n size_t size() const { return std::distance(bg, ed); }\n const\
    \ T &operator[](int i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray\
    \ {\n std::vector<T> csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n\
    \ CsrArray(const std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p)\
    \ {}\n size_t size() const { return pos.size() - 1; }\n const ListRange<T> operator[](int\
    \ i) const { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n\
    #line 9 \"src/Graph/Tree.hpp\"\ntemplate <class Cost= void> class Tree {\n template\
    \ <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator int() const\
    \ { return to; }\n };\n template <class D> struct Edge_B<D, void> {\n  int to;\n\
    \  operator int() const { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n\
    \ std::vector<std::conditional_t<std::is_same_v<Cost, void>, std::pair<int, int>,\
    \ std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n std::vector<int> P,\
    \ PP, D, I, L, R, pos;\npublic:\n Tree(int n): P(n, -2) {}\n template <class T=\
    \ Cost, std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t> = nullptr> void\
    \ add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u); }\n template\
    \ <class T, std::enable_if_t<std::is_convertible_v<T, Cost>, std::nullptr_t> =\
    \ nullptr> void add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_same_v<Cost, void>)\n   for (const auto &[f, t]: es)\
    \ g[--pos[f]]= {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t,\
    \ c};\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]=\
    \ r; i < t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n size_t size() const { return P.size();\
    \ }\n const ListRange<Edge> operator[](int v) const { return {g.cbegin() + pos[v],\
    \ g.cbegin() + pos[v + 1]}; }\n int depth(int v) const { return D[v]; }\n int\
    \ to_seq(int v) const { return L[v]; }\n int to_node(int i) const { return I[i];\
    \ }\n int parent(int v) const { return P[v]; }\n int root(int v) const {\n  for\
    \ (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n bool connected(int\
    \ u, int v) const { return root(u) == root(v); }\n int lca(int u, int v) const\
    \ {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u]\
    \ == PP[v]) return u;\n  }\n }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n\
    \  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]])\
    \ return I[L[v] - k];\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int dist(int u, int v) const { return depth(u) + depth(v) -\
    \ depth(lca(u, v)) * 2; }\n bool in_subtree(int u, int v) /* u is in v */ const\
    \ { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n std::array<int, 2> subtree(int v) /* half-open interval */\
    \ const { return std::array{L[v], R[v]}; }\n template <bool edge= 0> std::vector<std::array<int,\
    \ 2>> path(int u, int v) /* sequence of closed intervals */ const {\n  std::vector<std::array<int,\
    \ 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]],\
    \ L[v]}), v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u=\
    \ P[PP[u]];\n  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge,\
    \ L[v]});\n  else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v]\
    \ + edge});\n  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n\
    };\n#line 3 \"src/Graph/BiConnectedComponents.hpp\"\nclass BiConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\npublic:\n BiConnectedComponents(int\
    \ n): adj(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u);\
    \ }\n Tree<void> block_cut_tree() const {\n  const int n= adj.size();\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(n, 0), low;\n  std::vector<std::array<int, 2>> es;\n\
    \  int k= 0;\n  for (int s= 0, p; s < n; ++s)\n   if (par[s] == -2)\n    for (par[p=\
    \ s]= -1; p >= 0;) {\n     if (dat[p] == 0) ord[k++]= p;\n     if (dat[p] == (int)adj[p].size())\
    \ {\n      p= par[p];\n      continue;\n     }\n     if (int q= adj[p][dat[p]++];\
    \ par[q] == -2) par[q]= p, p= q;\n    }\n  for (int i= 0; i < n; ++i) dat[ord[i]]=\
    \ i;\n  low= dat;\n  for (int v= 0; v < n; ++v)\n   for (int u: adj[v]) low[v]=\
    \ std::min(low[v], dat[u]);\n  for (int i= n; i--;)\n   if (int p= ord[i], pp=\
    \ par[p]; pp >= 0) low[pp]= std::min(low[pp], low[p]);\n  for (int p: ord)\n \
    \  if (par[p] >= 0) {\n    if (int pp= par[p]; low[p] < dat[pp]) low[p]= low[pp],\
    \ es.push_back({low[p], p});\n    else es.push_back({k, pp}), es.push_back({k,\
    \ p}), low[p]= k++;\n   }\n  for (int s= 0; s < n; ++s)\n   if (!adj[s].size())\
    \ es.push_back({k++, s});\n  Tree ret(k);\n  for (auto [u, v]: es) ret.add_edge(u,\
    \ v);\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include \"src/Graph/Tree.hpp\"\nclass BiConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\npublic:\n BiConnectedComponents(int\
    \ n): adj(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u);\
    \ }\n Tree<void> block_cut_tree() const {\n  const int n= adj.size();\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(n, 0), low;\n  std::vector<std::array<int, 2>> es;\n\
    \  int k= 0;\n  for (int s= 0, p; s < n; ++s)\n   if (par[s] == -2)\n    for (par[p=\
    \ s]= -1; p >= 0;) {\n     if (dat[p] == 0) ord[k++]= p;\n     if (dat[p] == (int)adj[p].size())\
    \ {\n      p= par[p];\n      continue;\n     }\n     if (int q= adj[p][dat[p]++];\
    \ par[q] == -2) par[q]= p, p= q;\n    }\n  for (int i= 0; i < n; ++i) dat[ord[i]]=\
    \ i;\n  low= dat;\n  for (int v= 0; v < n; ++v)\n   for (int u: adj[v]) low[v]=\
    \ std::min(low[v], dat[u]);\n  for (int i= n; i--;)\n   if (int p= ord[i], pp=\
    \ par[p]; pp >= 0) low[pp]= std::min(low[pp], low[p]);\n  for (int p: ord)\n \
    \  if (par[p] >= 0) {\n    if (int pp= par[p]; low[p] < dat[pp]) low[p]= low[pp],\
    \ es.push_back({low[p], p});\n    else es.push_back({k, pp}), es.push_back({k,\
    \ p}), low[p]= k++;\n   }\n  for (int s= 0; s < n; ++s)\n   if (!adj[s].size())\
    \ es.push_back({k++, s});\n  Tree ret(k);\n  for (auto [u, v]: es) ret.add_edge(u,\
    \ v);\n  return ret;\n }\n};"
  dependsOn:
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: false
  path: src/Graph/BiConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-04-15 19:40:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/biconnected_components.test.cpp
  - test/aoj/3022.test.cpp
  - test/aoj/GRL_3_A.test.cpp
  - test/yukicoder/1326.test.cpp
  - test/hackerrank/bonnie-and-clyde.test.cpp
documentation_of: src/Graph/BiConnectedComponents.hpp
layout: document
title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
[0, n)：もとの頂点 \
[n, n + n_block)：block \
非再帰 [参考](https://nachiavivias.github.io/cp-library/column/2022/01.html)
## 問題例
[AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)
## 参考
[https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)