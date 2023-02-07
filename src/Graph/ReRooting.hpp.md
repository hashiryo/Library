---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/Tree.hpp
    title: "\u6728\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    };\n#line 3 \"src/Graph/ReRooting.hpp\"\ntemplate <class T, class C> class RerootingData\
    \ {\n Tree<C> &tree;\n std::vector<T> dp1, dp2, dp;\npublic:\nRerootingData(Tree<C>\
    \ &t,std::vector<T>& d1,std::vector<T>& d2,std::vector<T>& d):tree(t),dp1(d1),dp2(d2),dp(d){}\n\
    \ T operator[](int v)const { return dp[v]; }\n auto begin() const { return dp.begin();\
    \ }\n auto end() const { return dp.end(); }\n const T& get(int root, int v)const{\n\
    \  return root==v?dp[v]:tree.in_subtree(root,v)? dp2[tree.jump(v,root,1)]:dp1[v];\n\
    \ }\n};\ntemplate <class T, class U, class C,  class F1, class F2, class F3>\n\
    RerootingData<T,C> rerooting(Tree<C> &t, const F1 &f_ee, const F2 &f_ve, const\
    \ F3 &f_ev, const U &unit){\n  const int n= t.size();\n  std::vector<T> dp1(n),\
    \ dp2(n), dp(n);\n  for (int i= n; i--;) {\n   int v= t.to_node(i);\n   U sum=\
    \ unit;\n   for (const auto &e: t[v])\n    if (int u=e.to;u != t.parent(v)) sum=\
    \ f_ee(sum, f_ve(dp1[u], v, e));\n   dp1[v]= f_ev(sum, v);\n  }\n  for (int i=\
    \ 0; i < n; ++i) {\n   int v= t.to_node(i), deg= t[v].size();\n   std::vector<U>\
    \ f(deg + 1), b(deg + 1);\n   for (int j= 0; j < deg; ++j) {\n    const auto &e=\
    \ t[v][j];\n    int u= e.to;\n    f[j + 1]= f_ve(u == t.parent(v) ? dp2[v] : dp1[u],v,\
    \ e);\n   }\n   f[0]= b[deg]= unit;\n   for (int j= deg; j--;) b[j]= f_ee(f[j\
    \ + 1], b[j + 1]);\n   for (int j= 0; j < deg; ++j) f[j + 1]= f_ee(f[j], f[j +\
    \ 1]);\n   for (int j= 0; j < deg; ++j) {\n    const auto &e= t[v][j];\n    if\
    \ (int u= e.to;u != t.parent(v)) dp2[u]= f_ev(f_ee(f[j], b[j + 1]), v);\n   }\n\
    \   dp[v]= f_ev(f[deg], v);\n  }\n return RerootingData<T,C>(t, dp1, dp2, dp);\n\
    }\n"
  code: "#pragma once\n#include \"src/Graph/Tree.hpp\"\ntemplate <class T, class C>\
    \ class RerootingData {\n Tree<C> &tree;\n std::vector<T> dp1, dp2, dp;\npublic:\n\
    RerootingData(Tree<C> &t,std::vector<T>& d1,std::vector<T>& d2,std::vector<T>&\
    \ d):tree(t),dp1(d1),dp2(d2),dp(d){}\n T operator[](int v)const { return dp[v];\
    \ }\n auto begin() const { return dp.begin(); }\n auto end() const { return dp.end();\
    \ }\n const T& get(int root, int v)const{\n  return root==v?dp[v]:tree.in_subtree(root,v)?\
    \ dp2[tree.jump(v,root,1)]:dp1[v];\n }\n};\ntemplate <class T, class U, class\
    \ C,  class F1, class F2, class F3>\nRerootingData<T,C> rerooting(Tree<C> &t,\
    \ const F1 &f_ee, const F2 &f_ve, const F3 &f_ev, const U &unit){\n  const int\
    \ n= t.size();\n  std::vector<T> dp1(n), dp2(n), dp(n);\n  for (int i= n; i--;)\
    \ {\n   int v= t.to_node(i);\n   U sum= unit;\n   for (const auto &e: t[v])\n\
    \    if (int u=e.to;u != t.parent(v)) sum= f_ee(sum, f_ve(dp1[u], v, e));\n  \
    \ dp1[v]= f_ev(sum, v);\n  }\n  for (int i= 0; i < n; ++i) {\n   int v= t.to_node(i),\
    \ deg= t[v].size();\n   std::vector<U> f(deg + 1), b(deg + 1);\n   for (int j=\
    \ 0; j < deg; ++j) {\n    const auto &e= t[v][j];\n    int u= e.to;\n    f[j +\
    \ 1]= f_ve(u == t.parent(v) ? dp2[v] : dp1[u],v, e);\n   }\n   f[0]= b[deg]= unit;\n\
    \   for (int j= deg; j--;) b[j]= f_ee(f[j + 1], b[j + 1]);\n   for (int j= 0;\
    \ j < deg; ++j) f[j + 1]= f_ee(f[j], f[j + 1]);\n   for (int j= 0; j < deg; ++j)\
    \ {\n    const auto &e= t[v][j];\n    if (int u= e.to;u != t.parent(v)) dp2[u]=\
    \ f_ev(f_ee(f[j], b[j + 1]), v);\n   }\n   dp[v]= f_ev(f[deg], v);\n  }\n return\
    \ RerootingData<T,C>(t, dp1, dp2, dp);\n}"
  dependsOn:
  - src/Graph/Tree.hpp
  isVerificationFile: false
  path: src/Graph/ReRooting.hpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/ReRooting.hpp
layout: document
redirect_from:
- /library/src/Graph/ReRooting.hpp
- /library/src/Graph/ReRooting.hpp.html
title: src/Graph/ReRooting.hpp
---
