---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/Graph/rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':x:'
    path: test/aoj/2667.HLD.test.cpp
    title: test/aoj/2667.HLD.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc160_f.test.cpp
    title: test/atcoder/abc160_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc220_f.test.cpp
    title: test/atcoder/abc220_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc222_f.test.cpp
    title: test/atcoder/abc222_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc223_g.test.cpp
    title: test/atcoder/abc223_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc097_d.test.cpp
    title: test/atcoder/arc097_d.test.cpp
  - icon: ':x:'
    path: test/yosupo/lca.HLD.test.cpp
    title: test/yosupo/lca.HLD.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1075.test.cpp
    title: test/yukicoder/1075.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1124.test.cpp
    title: test/yukicoder/1124.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1153.test.cpp
    title: test/yukicoder/1153.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1295.test.cpp
    title: test/yukicoder/1295.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1333.test.cpp
    title: test/yukicoder/1333.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1418.test.cpp
    title: test/yukicoder/1418.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1494.test.cpp
    title: test/yukicoder/1494.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1718.test.cpp
    title: test/yukicoder/1718.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1976.test.cpp
    title: test/yukicoder/1976.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  - icon: ':x:'
    path: test/yukicoder/768.test.cpp
    title: test/yukicoder/768.test.cpp
  - icon: ':x:'
    path: test/yukicoder/922.test.cpp
    title: test/yukicoder/922.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/Tree.hpp\"\n#include <type_traits>\n#include <cstddef>\n\
    #include <vector>\n#include <algorithm>\n#include <array>\ntemplate <class Cost=\
    \ void> class Tree {\n template <class D, class T> struct Edge_B {\n  int to;\n\
    \  T cost;\n };\n template <class D> struct Edge_B<D, void> { int to; };\n using\
    \ Edge= Edge_B<void, Cost>;\n std::vector<std::vector<Edge>> adj;\n std::vector<int>\
    \ P, PP, D, I, L, R;\npublic:\n Tree(int n): adj(n) {}\n template <class T= Cost,\
    \ std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v) { adj[u].emplace_back(Edge{v}), adj[v].emplace_back(Edge{u}); }\n\
    \ template <class T, std::enable_if_t<std::is_convertible_v<T, Cost>, std::nullptr_t>\
    \ = nullptr> void add_edge(int u, int v, T c) { adj[u].emplace_back(Edge{v, c}),\
    \ adj[v].emplace_back(Edge{u, c}); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { adj[u].emplace_back(Edge{v, c}),\
    \ adj[v].emplace_back(Edge{u, d}); }\n const std::vector<Edge> &operator[](int\
    \ v) const { return adj[v]; }\n void build(int root= 0) {\n  const int n= adj.size();\n\
    \  P.assign(n, -2), I.reserve(n), PP.resize(n), std::iota(PP.begin(), PP.end(),\
    \ 0), D.assign(n, 0), L.assign(n, 0), R.assign(n, 0);\n  auto f= [&, i= 0, v=\
    \ 0](int r) mutable {\n   for (P[r]= -1, I.push_back(r); i < (int)I.size(); ++i)\n\
    \    for (const Edge &e: adj[v= I[i]])\n     if (P[v] != e.to) I.push_back(e.to),\
    \ P[e.to]= v;\n  };\n  f(root);\n  for (int r= 0; r < n; ++r)\n   if (P[r] ==\
    \ -2) f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;)\
    \ {\n   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1)\
    \ nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n\
    \   if (nx[v] != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]=\
    \ PP[PP[v]], D[v]= D[P[v]] + 1;\n  for (int i= 0; i < n; ++i) L[I[i]]= i;\n  for\
    \ (int v: I) {\n   int ir= R[v]= L[v] + Z[v];\n   for (const Edge &e: adj[v])\n\
    \    if (int u= e.to; u != P[v] && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v]\
    \ != -1) L[nx[v]]= L[v] + 1;\n  }\n  for (int i= 0; i < n; ++i) I[L[i]]= i;\n\
    \ }\n int size() const { return adj.size(); }\n bool builded() const { return\
    \ L.size() == adj.size(); }\n int depth(int v) const { return assert(builded()),\
    \ D[v]; }\n int to_seq(int v) const { return assert(builded()), L[v]; }\n int\
    \ to_node(int i) const { return assert(builded()), I[i]; }\n int parent(int v)\
    \ const { return assert(builded()), P[v]; }\n int root(int v) const {\n  for (assert(builded()),\
    \ v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n bool connected(int\
    \ u, int v) const { return root(u) == root(v); }\n int lca(int u, int v) const\
    \ {\n  for (assert(builded());; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u,\
    \ v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v, int k) const\
    \ {\n  assert(builded()), assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] +\
    \ 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int jump(int\
    \ u, int v, int k) const {\n  if (assert(builded()); u == v) return -1;\n  if\
    \ (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) : P[u];\n  int w=\
    \ lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k > d_uw + d_vw ?\
    \ -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int dist(int u, int\
    \ v) const { return assert(builded()), depth(u) + depth(v) - depth(lca(u, v))\
    \ * 2; }\n bool in_subtree(int u, int v) /* u is in v */ const { return assert(builded()),\
    \ L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return assert(builded()),\
    \ R[v] - L[v]; }\n std::array<int, 2> subtree(int v) /* half-open interval */\
    \ const { return assert(builded()), std::array{L[v], R[v]}; }\n template <bool\
    \ edge= 0> std::vector<std::array<int, 2>> path(int u, int v) /* sequence of closed\
    \ intervals */ const {\n  assert(builded());\n  std::vector<std::array<int, 2>>\
    \ up, down;\n  while (PP[u] != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]],\
    \ L[v]}), v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u=\
    \ P[PP[u]];\n  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge,\
    \ L[v]});\n  else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v]\
    \ + edge});\n  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n\
    };\n"
  code: "#pragma once\n#include <type_traits>\n#include <cstddef>\n#include <vector>\n\
    #include <algorithm>\n#include <array>\ntemplate <class Cost= void> class Tree\
    \ {\n template <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n };\n\
    \ template <class D> struct Edge_B<D, void> { int to; };\n using Edge= Edge_B<void,\
    \ Cost>;\n std::vector<std::vector<Edge>> adj;\n std::vector<int> P, PP, D, I,\
    \ L, R;\npublic:\n Tree(int n): adj(n) {}\n template <class T= Cost, std::enable_if_t<std::is_same_v<T,\
    \ void>, std::nullptr_t> = nullptr> void add_edge(int u, int v) { adj[u].emplace_back(Edge{v}),\
    \ adj[v].emplace_back(Edge{u}); }\n template <class T, std::enable_if_t<std::is_convertible_v<T,\
    \ Cost>, std::nullptr_t> = nullptr> void add_edge(int u, int v, T c) { adj[u].emplace_back(Edge{v,\
    \ c}), adj[v].emplace_back(Edge{u, c}); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { adj[u].emplace_back(Edge{v, c}),\
    \ adj[v].emplace_back(Edge{u, d}); }\n const std::vector<Edge> &operator[](int\
    \ v) const { return adj[v]; }\n void build(int root= 0) {\n  const int n= adj.size();\n\
    \  P.assign(n, -2), I.reserve(n), PP.resize(n), std::iota(PP.begin(), PP.end(),\
    \ 0), D.assign(n, 0), L.assign(n, 0), R.assign(n, 0);\n  auto f= [&, i= 0, v=\
    \ 0](int r) mutable {\n   for (P[r]= -1, I.push_back(r); i < (int)I.size(); ++i)\n\
    \    for (const Edge &e: adj[v= I[i]])\n     if (P[v] != e.to) I.push_back(e.to),\
    \ P[e.to]= v;\n  };\n  f(root);\n  for (int r= 0; r < n; ++r)\n   if (P[r] ==\
    \ -2) f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;)\
    \ {\n   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1)\
    \ nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n\
    \   if (nx[v] != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]=\
    \ PP[PP[v]], D[v]= D[P[v]] + 1;\n  for (int i= 0; i < n; ++i) L[I[i]]= i;\n  for\
    \ (int v: I) {\n   int ir= R[v]= L[v] + Z[v];\n   for (const Edge &e: adj[v])\n\
    \    if (int u= e.to; u != P[v] && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v]\
    \ != -1) L[nx[v]]= L[v] + 1;\n  }\n  for (int i= 0; i < n; ++i) I[L[i]]= i;\n\
    \ }\n int size() const { return adj.size(); }\n bool builded() const { return\
    \ L.size() == adj.size(); }\n int depth(int v) const { return assert(builded()),\
    \ D[v]; }\n int to_seq(int v) const { return assert(builded()), L[v]; }\n int\
    \ to_node(int i) const { return assert(builded()), I[i]; }\n int parent(int v)\
    \ const { return assert(builded()), P[v]; }\n int root(int v) const {\n  for (assert(builded()),\
    \ v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n bool connected(int\
    \ u, int v) const { return root(u) == root(v); }\n int lca(int u, int v) const\
    \ {\n  for (assert(builded());; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u,\
    \ v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v, int k) const\
    \ {\n  assert(builded()), assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] +\
    \ 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int jump(int\
    \ u, int v, int k) const {\n  if (assert(builded()); u == v) return -1;\n  if\
    \ (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) : P[u];\n  int w=\
    \ lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k > d_uw + d_vw ?\
    \ -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int dist(int u, int\
    \ v) const { return assert(builded()), depth(u) + depth(v) - depth(lca(u, v))\
    \ * 2; }\n bool in_subtree(int u, int v) /* u is in v */ const { return assert(builded()),\
    \ L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return assert(builded()),\
    \ R[v] - L[v]; }\n std::array<int, 2> subtree(int v) /* half-open interval */\
    \ const { return assert(builded()), std::array{L[v], R[v]}; }\n template <bool\
    \ edge= 0> std::vector<std::array<int, 2>> path(int u, int v) /* sequence of closed\
    \ intervals */ const {\n  assert(builded());\n  std::vector<std::array<int, 2>>\
    \ up, down;\n  while (PP[u] != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]],\
    \ L[v]}), v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u=\
    \ P[PP[u]];\n  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge,\
    \ L[v]});\n  else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v]\
    \ + edge});\n  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/Tree.hpp
  requiredBy:
  - src/Graph/rerooting.hpp
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/1595.test.cpp
  - test/aoj/2667.HLD.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/lca.HLD.test.cpp
  - test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - test/yukicoder/922.test.cpp
  - test/yukicoder/1976.test.cpp
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/235.HLD.test.cpp
  - test/yukicoder/768.test.cpp
  - test/yukicoder/1153.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/1494.test.cpp
  - test/yukicoder/1295.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/1418.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/atcoder/abc222_f.test.cpp
  - test/atcoder/abc160_f.test.cpp
  - test/atcoder/abc220_f.test.cpp
  - test/atcoder/arc097_d.test.cpp
  - test/atcoder/abc223_g.test.cpp
documentation_of: src/Graph/Tree.hpp
layout: document
title: "\u6728\u30AF\u30E9\u30B9"
---
HL分解＋オイラーツアーで頂点集合を数列に \
非連結(森)でも動くはず

## メンバ関数
重みなし ( `Cost=void` ) \
　`add_edge(int u, int v)` : 無向辺 (u, v) を追加 \
重みあり \
　`add_edge(int u, int v, Cost c)` : 無向辺 (u, v) を重み c で追加 \
　`add_edge(int u, int v, Cost c, Cost d)` : 有向辺 (u, v) を重み c で、 有向辺 (v, u) を重み d で追加

`build(int root=0)` : 頂点 root を根としてHL分解を実行. 辺をセットし終えたらとにかく最初に実行. \
`path(int u, int v)` : 頂点 u から頂点 v へのパスを表す"閉"区間列を返す. \
`subtree(int v)` : 頂点 v を根とする部分木を表す"開"区間を返す \
`jump(int u, int v, int k)` : 頂点 u から 頂点 v へ向けて 長さ k 移動した先の頂点 \
`operator[](int v)` : 頂点 v から隣接する辺集合