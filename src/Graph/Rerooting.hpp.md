---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc160_f.test.cpp
    title: test/atcoder/abc160_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc220_f.test.cpp
    title: test/atcoder/abc220_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_f.test.cpp
    title: test/atcoder/abc222_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc223_g.rerooting.test.cpp
    title: test/atcoder/abc223_g.rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc248_g.test.cpp
    title: test/atcoder/abc248_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc337_g.test.cpp
    title: test/atcoder/abc337_g.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':x:'
    path: test/yosupo/tree_path_composite_sum.test.cpp
    title: test/yosupo/tree_path_composite_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1075.test.cpp
    title: test/yukicoder/1075.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1124.test.cpp
    title: test/yukicoder/1124.test.cpp
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
    path: test/yukicoder/1833.test.cpp
    title: test/yukicoder/1833.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1976.test.cpp
    title: test/yukicoder/1976.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2360.test.cpp
    title: test/yukicoder/2360.test.cpp
  - icon: ':x:'
    path: test/yukicoder/768.test.cpp
    title: test/yukicoder/768.test.cpp
  - icon: ':x:'
    path: test/yukicoder/922.test.cpp
    title: test/yukicoder/922.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include <array>\n\
    #include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
    #include <iostream>\n#include <iterator>\n#include <type_traits>\n#define _LR(name,\
    \ IT, CT) \\\n template <class T> struct name { \\\n  using Iterator= typename\
    \ std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return\
    \ bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size() const {\
    \ return std::distance(bg, ed); } \\\n  CT &operator[](int i) const { return bg[i];\
    \ } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange, const_iterator,\
    \ const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n std::vector<T>\
    \ dat;\n std::vector<int> p;\n size_t size() const { return p.size() - 1; }\n\
    \ ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin() + p[i\
    \ + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int, int>\
    \ {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): vector(m), n(n) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (size_t i= 0; i < n;\
    \ ++i) p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 5 \"src/Graph/HeavyLightDecomposition.hpp\"\
    \nclass HeavyLightDecomposition {\n std::vector<int> P, PP, D, I, L, R;\npublic:\n\
    \ HeavyLightDecomposition()= default;\n HeavyLightDecomposition(const Graph &g,\
    \ int root= 0): HeavyLightDecomposition(g.adjacency_vertex(0), root) {}\n HeavyLightDecomposition(const\
    \ CSRArray<int> &adj, int root= 0) {\n  const int n= adj.size();\n  P.assign(n,\
    \ -2), PP.resize(n), D.resize(n), I.resize(n), L.resize(n), R.resize(n);\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: adj[v= I[i]])\n     if (P[v] != u) P[I[t++]= u]= v;\n\
    \  };\n  f(root);\n  for (int r= 0; r < n; ++r)\n   if (P[r] == -2) f(r);\n  std::vector<int>\
    \ Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n   if (P[v= I[i]] == -1) continue;\n\
    \   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]= v;\n   if (Z[nx[P[v]]] < Z[v])\
    \ nx[P[v]]= v;\n  }\n  for (int v= n; v--;) PP[v]= v;\n  for (int v: I)\n   if\
    \ (nx[v] != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: adj[v])\n    if (u != P[v] && u\
    \ != nx[v]) L[u]= (ir-= Z[u]);\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n  }\n\
    \  for (int i= n; i--;) I[L[i]]= i;\n }\n int to_seq(int v) const { return L[v];\
    \ }\n int to_vertex(int i) const { return I[i]; }\n size_t size() const { return\
    \ P.size(); }\n int parent(int v) const { return P[v]; }\n int head(int v) const\
    \ { return PP[v]; }\n int root(int v) const {\n  for (v= PP[v];; v= PP[P[v]])\n\
    \   if (P[v] == -1) return v;\n }\n bool connected(int u, int v) const { return\
    \ root(u) == root(v); }\n // u is in v\n bool in_subtree(int u, int v) const {\
    \ return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n int lca(int u, int v) const {\n  for (;; v= P[PP[v]]) {\n \
    \  if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u] == PP[v]) return u;\n  }\n\
    \ }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v]\
    \ - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n\
    \ }\n int jump(int u, int v, int k) const {\n  if (!k) return u;\n  if (u == v)\
    \ return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v, D[v] - D[u] - 1) :\
    \ P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v] - D[w];\n  return k\
    \ > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw + d_vw - k);\n }\n int\
    \ depth(int v) const { return D[v]; }\n int dist(int u, int v) const { return\
    \ D[u] + D[v] - D[lca(u, v)] * 2; }\n // half-open interval [l,r)\n std::pair<int,\
    \ int> subtree(int v) const { return {L[v], R[v]}; }\n // sequence of closed intervals\
    \ [l,r]\n std::vector<std::pair<int, int>> path(int u, int v, bool edge= 0) const\
    \ {\n  std::vector<std::pair<int, int>> up, down;\n  while (PP[u] != PP[v]) {\n\
    \   if (L[u] < L[v]) down.emplace_back(L[PP[v]], L[v]), v= P[PP[v]];\n   else\
    \ up.emplace_back(L[u], L[PP[u]]), u= P[PP[u]];\n  }\n  if (L[u] < L[v]) down.emplace_back(L[u]\
    \ + edge, L[v]);\n  else if (L[v] + edge <= L[u]) up.emplace_back(L[u], L[v] +\
    \ edge);\n  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n\
    };\n#line 3 \"src/Graph/Rerooting.hpp\"\n// put_edge(int v, int e, T t) -> U\n\
    // op(U l, U r) -> U\n// ui(:U) is the identity element of op\n// put_vertex(int\
    \ v, U sum) -> T\ntemplate <class T> class Rerooting {\n HeavyLightDecomposition\
    \ hld;\n std::vector<T> dp, dp1, dp2;\npublic:\n template <class U, class F1,\
    \ class F2, class F3> Rerooting(const Graph &g, const CSRArray<int> &adje, const\
    \ HeavyLightDecomposition &hld, const F1 &put_edge, const F2 &op, const U &ui,\
    \ const F3 &put_vertex): hld(hld) {\n  static_assert(std::is_invocable_r_v<U,\
    \ F1, int, int, T>, \"put_edge(int,int,T) is not invocable\");\n  static_assert(std::is_invocable_r_v<U,\
    \ F2, U, U>, \"op(U,U) is not invocable\");\n  static_assert(std::is_invocable_r_v<T,\
    \ F3, int, U>, \"put_vertex(int,U) is not invocable\");\n  const int n= g.vertex_size();\n\
    \  dp.resize(n), dp1.resize(n), dp2.resize(n);\n  for (int i= n, v; i--;) {\n\
    \   U sum= ui;\n   for (int e: adje[v= hld.to_vertex(i)])\n    if (int u= g[e].to(v);\
    \ u != hld.parent(v)) sum= op(sum, put_edge(v, e, dp1[u]));\n   dp1[v]= put_vertex(v,\
    \ sum);\n  }\n  for (int i= 0, v; i < n; ++i) {\n   auto gv= adje[v= hld.to_vertex(i)];\n\
    \   int dg= gv.size();\n   std::vector<U> f(dg + 1), b(dg + 1);\n   for (int j=\
    \ 0, e, u; j < dg; ++j) u= g[e= gv[j]].to(v), f[j + 1]= put_edge(v, e, u == hld.parent(v)\
    \ ? dp2[v] : dp1[u]);\n   f[0]= b[dg]= ui;\n   for (int j= dg; j--;) b[j]= op(f[j\
    \ + 1], b[j + 1]);\n   for (int j= 0; j < dg; ++j) f[j + 1]= op(f[j], f[j + 1]);\n\
    \   for (int j= 0; j < dg; ++j)\n    if (int u= g[gv[j]].to(v); u != hld.parent(v))\
    \ dp2[u]= put_vertex(v, op(f[j], b[j + 1]));\n   dp[v]= put_vertex(v, f[dg]);\n\
    \  }\n }\n template <class U, class F1, class F2, class F3> Rerooting(const Graph\
    \ &g, const CSRArray<int> &adje, const F1 &put_edge, const F2 &op, const U &ui,\
    \ const F3 &put_vertex): Rerooting(g, adje, HeavyLightDecomposition(g), put_edge,\
    \ op, ui, put_vertex) {}\n template <class U, class F1, class F2, class F3> Rerooting(const\
    \ Graph &g, const HeavyLightDecomposition &hld, const F1 &put_edge, const F2 &op,\
    \ const U &ui, const F3 &put_vertex): Rerooting(g, g.adjacency_edge(0), hld, put_edge,\
    \ op, ui, put_vertex) {}\n template <class U, class F1, class F2, class F3> Rerooting(const\
    \ Graph &g, const F1 &put_edge, const F2 &op, const U &ui, const F3 &put_vertex):\
    \ Rerooting(g, g.adjacency_edge(0), HeavyLightDecomposition(g), put_edge, op,\
    \ ui, put_vertex) {}\n const T &operator[](int v) const { return dp[v]; }\n auto\
    \ begin() const { return dp.cbegin(); }\n auto end() const { return dp.cend();\
    \ }\n const T &operator()(int root, int v) const { return root == v ? dp[v] :\
    \ hld.in_subtree(root, v) ? dp2[hld.jump(v, root, 1)] : dp1[v]; }\n};\n"
  code: "#pragma once\n#include \"src/Graph/HeavyLightDecomposition.hpp\"\n// put_edge(int\
    \ v, int e, T t) -> U\n// op(U l, U r) -> U\n// ui(:U) is the identity element\
    \ of op\n// put_vertex(int v, U sum) -> T\ntemplate <class T> class Rerooting\
    \ {\n HeavyLightDecomposition hld;\n std::vector<T> dp, dp1, dp2;\npublic:\n template\
    \ <class U, class F1, class F2, class F3> Rerooting(const Graph &g, const CSRArray<int>\
    \ &adje, const HeavyLightDecomposition &hld, const F1 &put_edge, const F2 &op,\
    \ const U &ui, const F3 &put_vertex): hld(hld) {\n  static_assert(std::is_invocable_r_v<U,\
    \ F1, int, int, T>, \"put_edge(int,int,T) is not invocable\");\n  static_assert(std::is_invocable_r_v<U,\
    \ F2, U, U>, \"op(U,U) is not invocable\");\n  static_assert(std::is_invocable_r_v<T,\
    \ F3, int, U>, \"put_vertex(int,U) is not invocable\");\n  const int n= g.vertex_size();\n\
    \  dp.resize(n), dp1.resize(n), dp2.resize(n);\n  for (int i= n, v; i--;) {\n\
    \   U sum= ui;\n   for (int e: adje[v= hld.to_vertex(i)])\n    if (int u= g[e].to(v);\
    \ u != hld.parent(v)) sum= op(sum, put_edge(v, e, dp1[u]));\n   dp1[v]= put_vertex(v,\
    \ sum);\n  }\n  for (int i= 0, v; i < n; ++i) {\n   auto gv= adje[v= hld.to_vertex(i)];\n\
    \   int dg= gv.size();\n   std::vector<U> f(dg + 1), b(dg + 1);\n   for (int j=\
    \ 0, e, u; j < dg; ++j) u= g[e= gv[j]].to(v), f[j + 1]= put_edge(v, e, u == hld.parent(v)\
    \ ? dp2[v] : dp1[u]);\n   f[0]= b[dg]= ui;\n   for (int j= dg; j--;) b[j]= op(f[j\
    \ + 1], b[j + 1]);\n   for (int j= 0; j < dg; ++j) f[j + 1]= op(f[j], f[j + 1]);\n\
    \   for (int j= 0; j < dg; ++j)\n    if (int u= g[gv[j]].to(v); u != hld.parent(v))\
    \ dp2[u]= put_vertex(v, op(f[j], b[j + 1]));\n   dp[v]= put_vertex(v, f[dg]);\n\
    \  }\n }\n template <class U, class F1, class F2, class F3> Rerooting(const Graph\
    \ &g, const CSRArray<int> &adje, const F1 &put_edge, const F2 &op, const U &ui,\
    \ const F3 &put_vertex): Rerooting(g, adje, HeavyLightDecomposition(g), put_edge,\
    \ op, ui, put_vertex) {}\n template <class U, class F1, class F2, class F3> Rerooting(const\
    \ Graph &g, const HeavyLightDecomposition &hld, const F1 &put_edge, const F2 &op,\
    \ const U &ui, const F3 &put_vertex): Rerooting(g, g.adjacency_edge(0), hld, put_edge,\
    \ op, ui, put_vertex) {}\n template <class U, class F1, class F2, class F3> Rerooting(const\
    \ Graph &g, const F1 &put_edge, const F2 &op, const U &ui, const F3 &put_vertex):\
    \ Rerooting(g, g.adjacency_edge(0), HeavyLightDecomposition(g), put_edge, op,\
    \ ui, put_vertex) {}\n const T &operator[](int v) const { return dp[v]; }\n auto\
    \ begin() const { return dp.cbegin(); }\n auto end() const { return dp.cend();\
    \ }\n const T &operator()(int root, int v) const { return root == v ? dp[v] :\
    \ hld.in_subtree(root, v) ? dp2[hld.jump(v, root, 1)] : dp1[v]; }\n};"
  dependsOn:
  - src/Graph/HeavyLightDecomposition.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-02-25 20:59:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/tree_path_composite_sum.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/1595.test.cpp
  - test/yukicoder/2360.test.cpp
  - test/yukicoder/768.test.cpp
  - test/yukicoder/1833.test.cpp
  - test/yukicoder/1494.test.cpp
  - test/yukicoder/922.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/1976.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/1418.test.cpp
  - test/yukicoder/1295.test.cpp
  - test/atcoder/abc337_g.test.cpp
  - test/atcoder/abc160_f.test.cpp
  - test/atcoder/abc248_g.test.cpp
  - test/atcoder/abc220_f.test.cpp
  - test/atcoder/abc222_f.test.cpp
  - test/atcoder/abc223_g.rerooting.test.cpp
documentation_of: src/Graph/Rerooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728DP"
---

![image of tree dp](https://github.com/hashiryo/Library/blob/master/img/rerooting.drawio.svg?raw=true)

## `Rerooting<T>` クラス
全方位木DPの値(型 : `T` )が入っている配列だと思って使う. (`operator[](int v)`, `begin()`, `end()` がある. )

### コンストラクタ
```c++
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, F1 put_edge, F2 op, U ui, F3 put_vertex) // (1)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, HeavyLightDecomposition hld, F1 put_edge, F2 op, U ui, F3 put_vertex) // (2)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, CSRArray<int> adje, F1 put_edge, F2 op, U ui, F3 put_vertex) // (3)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, CSRArray<int> adje,  HeavyLightDecomposition hld, F1 put_edge, F2 op, U ui, F3 put_vertex) // (4)
```

|引数|概要|
|---|---|
|`Graph g`|[`Graph` クラス](Graph.hpp)|
|`CSRArray<int> adje`|頂点 → 辺の隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp)) <br> 省略できる (1), (2). (ただし 内部で作ってる)|
|`HeavyLightDecomposition hld`|g を [重軽分解](HeavyLightDecomposition.hpp)したもの. <br> 省略できる (1), (3). (ただし 内部で作ってる) |
|`put_edge(int v, int e, T t) -> U`| 頂点 v と v から出る辺 e の情報によってクラス `T` の値 `t` をモノイド `U` の元に変換|
|`op(U l, U r) -> U`|モノイド `U` の二項演算|
|`U ui`|モノイド `U` の単位元|
|`put_vertex(int v, U sum) -> T`| 頂点 v でモノイド `U` の総積をクラス `T` の値に変換|

### その他メンバ関数

|名前|概要|
|---|---|
|`operator[](int v)`| 頂点 v についての全方位木DPの値を返す.|
|`begin()`|全方位木DPの値配列のイテレータ.|
|`end()`|全方位木DPの値配列のイテレータ.|
|`operator()(int root, int v)`|頂点 root が根である場合の 頂点 v を根とする部分木のDP値を返す.|

## 問題例
[AtCoder Regular Contest 022 C - ロミオとジュリエット](https://atcoder.jp/contests/arc022/tasks/arc022_3) \
[AtCoder Regular Contest 028 C - 高橋王国の分割統治](https://atcoder.jp/contests/arc028/tasks/arc028_3) \
[AtCoder Regular Contest 097 F - Monochrome Cat](https://atcoder.jp/contests/arc097/tasks/arc097_d) \
[Educational DP Contest V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) \
[Typical DP Contest N - 木](https://atcoder.jp/contests/tdpc/tasks/tdpc_tree) \
[square869120Contest #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)\
[NJPC2017 E - 限界集落](https://atcoder.jp/contests/njpc2017/tasks/njpc2017_e)\
[第二回全国統一プログラミング王決定戦本戦 D - 木、](https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_d) (根付き木ハッシュ, 二つの全方位木DP, `operator()(root,v)`) \
[東京工業大学プログラミングコンテスト2019 M - Inversion Numbers of Tree](https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_m)\
[JOI 2018/2019 春合宿 過去問 G - 指定都市 (Designated Cities)](https://atcoder.jp/contests/joisc2019/tasks/joisc2019_g) (全方位木DPでない部分が難しい)\
[yukicoder No.1153 ねこちゃんゲーム](https://yukicoder.me/problems/no/1153) (`operator()(root,v)`, sp judge)\
[Educational Codeforces Round 46 (Div. 2) G. Two-Paths](https://codeforces.com/contest/1000/problem/G) ( + LCA )\
[Educational Codeforces Round 67 (Div. 2) E. Tree Painting](https://codeforces.com/contest/1187/problem/E)\
[Codeforces Round 135 (Div. 2) D. Choosing Capital for Treeland](https://codeforces.com/contest/219/problem/D)\
[Codeforces Round 292 (Div. 1) D. Drazil and Morning Exercise](https://codeforces.com/contest/516/problem/D)\
[Codeforces Round 302 (Div. 1) D. Road Improvement](https://codeforces.com/contest/543/problem/D)\
[Codeforces Round 395 (Div. 1) D. Timofey and a flat tree](https://codeforces.com/contest/763/problem/D) (根付き木ハッシュ)\
[Codeforces Round 397 (Div. 1 + Div. 2 combined) E. Tree Folding](https://codeforces.com/contest/765/problem/E)\
[Codeforces Round 405 (Div. 2) D. Bear and Tree Jumps](https://codeforces.com/contest/791/problem/D)\
[Codeforces Round 615 (Div. 3) F. Three Paths on a Tree](https://codeforces.com/contest/1294/problem/F) (`operator()(root,v)`)\
[Codeforces Round 627 (Div. 3) F. Maximum White Subtree](https://codeforces.com/contest/1324/problem/F)\
[Codeforces Round 695 (Div. 2) E. Distinctive Roots in a Tree](https://codeforces.com/contest/1467/problem/E)\
[Codeforces Round 711 (Div. 2) F. Christmas Game](https://codeforces.com/contest/1498/problem/F) (staircase nim)\
[VK Cup 2012 Round 1 D. Distance in Tree](https://codeforces.com/contest/161/problem/D)\
[AIM Tech Round 3 (Div. 1) C. Centroids](https://codeforces.com/contest/708/problem/C) (`operator()(root,v)`)\
[2022 China Collegiate Programming Contest (CCPC) Guilin Site G. Group Homework](https://codeforces.com/gym/104008/problem/G) (`operator()(root,v)`)\
[LibreOJ #2072. 「JSOI2016」独特的树叶](https://loj.ac/p/2072) (根付き木ハッシュ, 二つの全方位木DP, `operator()(root,v)`)\
[LibreOJ #2192. 「SHOI2014」概率充电器](https://loj.ac/p/2192)\
[LibreOJ #3350. 「CEOI2020」星际迷航](https://loj.ac/p/3350)\
[LibreOJ #6699. 然而第六章的 A 面并没有草莓](https://loj.ac/p/6699) ( + LCA )\
[LibreOJ #10159. 「一本通 5.2 练习 2」旅游规划](https://loj.ac/p/10159) (`operator()(root,v)`)\
[洛谷 P2986 [USACO10MAR] Great Cow Gathering G](https://www.luogu.com.cn/problem/P2986)\
[洛谷 P3047 [USACO12FEB] Nearby Cows G](https://www.luogu.com.cn/problem/P3047)\
[洛谷 P3478 [POI2008] STA-Station](https://www.luogu.com.cn/problem/P3478)\
[洛谷 P3647 [APIO2014] 连珠线](https://www.luogu.com.cn/problem/P3647)\
[洛谷 P6419 [COCI2014-2015#1] Kamp](https://www.luogu.com.cn/problem/P6419)
## 参考
[https://trap.jp/post/1702/](https://trap.jp/post/1702/)