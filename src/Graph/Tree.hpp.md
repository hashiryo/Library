---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/BiConnectedComponents.hpp
    title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: src/Graph/rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.DynSeg.test.cpp
    title: test/aoj/2270.DynSeg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.HLD.test.cpp
    title: test/aoj/2667.HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3022.test.cpp
    title: test/aoj/3022.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
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
    path: test/hackerrank/bonnie-and-clyde.test.cpp
    title: test/hackerrank/bonnie-and-clyde.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.HLD.test.cpp
    title: test/yosupo/lca.HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1075.test.cpp
    title: test/yukicoder/1075.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1124.test.cpp
    title: test/yukicoder/1124.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1295.test.cpp
    title: test/yukicoder/1295.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  - icon: ':heavy_check_mark:'
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
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/Tree.hpp\"\n#include <type_traits>\n#include <cstddef>\n\
    #include <algorithm>\n#include <array>\n#include <tuple>\n#include <numeric>\n\
    #include <cassert>\n#line 2 \"src/DataStructure/CsrArray.hpp\"\n#include <vector>\n\
    #include <iterator>\ntemplate <class T> struct ListRange {\n using Iterator= typename\
    \ std::vector<T>::const_iterator;\n Iterator bg, ed;\n Iterator begin() const\
    \ { return bg; }\n Iterator end() const { return ed; }\n size_t size() const {\
    \ return std::distance(bg, ed); }\n const T &operator[](int i) const { return\
    \ bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T> csr;\n std::vector<int>\
    \ pos;\npublic:\n CsrArray()= default;\n CsrArray(const std::vector<T> &c, const\
    \ std::vector<int> &p): csr(c), pos(p) {}\n size_t size() const { return pos.size()\
    \ - 1; }\n const ListRange<T> operator[](int i) const { return {csr.cbegin() +\
    \ pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n#line 10 \"src/Graph/Tree.hpp\"\n\
    template <class Cost= void> class Tree {\n template <class D, class T> struct\
    \ Edge_B {\n  int to;\n  T cost;\n  operator int() const { return to; }\n };\n\
    \ template <class D> struct Edge_B<D, void> {\n  int to;\n  operator int() const\
    \ { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n std::vector<std::conditional_t<std::is_same_v<Cost,\
    \ void>, std::pair<int, int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge>\
    \ g;\n std::vector<int> P, PP, D, I, L, R, pos;\npublic:\n Tree(int n): P(n, -2)\
    \ {}\n template <class T= Cost, std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t>\
    \ = nullptr> void add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v,\
    \ u); }\n template <class T, std::enable_if_t<std::is_convertible_v<T, Cost>,\
    \ std::nullptr_t> = nullptr> void add_edge(int u, int v, T c) { es.emplace_back(u,\
    \ v, c), es.emplace_back(v, u, c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
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
    \ depth(lca(u, v)) * 2; }\n // u is in v\n bool in_subtree(int u, int v) const\
    \ { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n // half-open interval\n std::array<int, 2> subtree(int v) const\
    \ { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n template\
    \ <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const {\n\
    \  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n"
  code: "#pragma once\n#include <type_traits>\n#include <cstddef>\n#include <algorithm>\n\
    #include <array>\n#include <tuple>\n#include <numeric>\n#include <cassert>\n#include\
    \ \"src/DataStructure/CsrArray.hpp\"\ntemplate <class Cost= void> class Tree {\n\
    \ template <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator\
    \ int() const { return to; }\n };\n template <class D> struct Edge_B<D, void>\
    \ {\n  int to;\n  operator int() const { return to; }\n };\n using Edge= Edge_B<void,\
    \ Cost>;\n std::vector<std::conditional_t<std::is_same_v<Cost, void>, std::pair<int,\
    \ int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n std::vector<int>\
    \ P, PP, D, I, L, R, pos;\npublic:\n Tree(int n): P(n, -2) {}\n template <class\
    \ T= Cost, std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t> = nullptr>\
    \ void add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u);\
    \ }\n template <class T, std::enable_if_t<std::is_convertible_v<T, Cost>, std::nullptr_t>\
    \ = nullptr> void add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v,\
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
    \ depth(lca(u, v)) * 2; }\n // u is in v\n bool in_subtree(int u, int v) const\
    \ { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n // half-open interval\n std::array<int, 2> subtree(int v) const\
    \ { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n template\
    \ <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const {\n\
    \  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};"
  dependsOn:
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: false
  path: src/Graph/Tree.hpp
  requiredBy:
  - src/Graph/rerooting.hpp
  - src/Graph/BiConnectedComponents.hpp
  timestamp: '2023-04-16 21:58:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc160_f.test.cpp
  - test/atcoder/abc222_f.test.cpp
  - test/atcoder/abc223_g.rerooting.test.cpp
  - test/atcoder/abc220_f.test.cpp
  - test/yosupo/biconnected_components.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - test/yosupo/lca.HLD.test.cpp
  - test/aoj/1595.test.cpp
  - test/aoj/2270.DynSeg.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/2667.HLD.test.cpp
  - test/aoj/3022.test.cpp
  - test/aoj/GRL_3_A.test.cpp
  - test/yukicoder/1418.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/yukicoder/1976.test.cpp
  - test/yukicoder/922.test.cpp
  - test/yukicoder/768.test.cpp
  - test/yukicoder/1295.test.cpp
  - test/yukicoder/1326.test.cpp
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/235.HLD.test.cpp
  - test/yukicoder/1494.test.cpp
  - test/hackerrank/bonnie-and-clyde.test.cpp
documentation_of: src/Graph/Tree.hpp
layout: document
title: "\u6728\u30AF\u30E9\u30B9"
---
HL分解＋オイラーツアーで頂点集合を数列に \
非連結(森)でも動くはず

## メンバ関数
**※`add_edge` (とコンストラクタと`build`) 以外の関数は `build` 関数が実行済みであることを前提とする**

| 名前                                             | 概要                                                                                                              | 備考                          |
| ------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------- | ----------------------------- |
| `Tree(n)`                                        | コンストラクタ. 頂点数 n を渡す                                                                                   |                               |
| `add_edge(u,v)`                                  | 無向辺 (u, v) を追加                                                                                              | 重みなし(Cost=void)の場合のみ |
| 1. `add_edge(u,v,c) `<br> 2. `add_edge(u,v,c,d)` | 1.  無向辺 (u, v) を重み c で追加 <br> 2.  有向辺 (u, v) を重み c で、 有向辺 (v, u) を重み d で追加              | 重みあり(Cost≠void)の場合のみ |
| `build(root=0)`                                  | 頂点 root を根としてHL分解を実行. 辺をセットし終えたらとにかく最初に実行.                                         |                               |
| `size()`                                         | 頂点数を返す.                                                                                                     |                               |
| `operator[](v)`                                  | 頂点 v から隣接する辺集合                                                                                         |                               |
| `path<edge=0>(u,v)`                              | 頂点 u から頂点 v へのパスを表す"閉"区間列を返す. <br> `edge`フラグが true なら lca を含めないような区間列を返す. |                               |
| `subtree(v)`                                     | 頂点 v を根とする部分木を表す"開"区間を返す.                                                                      |                               |
| `depth(v)`                                       | 頂点 v の深さを返す                                                                                               |                               |
| `to_seq(v)`                                      | 頂点 v がオイラーツアー列で何番目に対応するかを返す                                                               |                               |
| `to_node(i)`                                     | オイラーツアー列で i 番目が指す頂点を返す                                                                         |                               |
| `parent(v)`                                      | 頂点 v の親を返す. v が根なら -1                                                                                  |                               |
| `root(v)`                                        | 頂点 v が属する木の根を返す                                                                                       |                               |
| `lca(u,v)`                                       | 頂点 u と 頂点 v の最小共通祖先を返す. u と v が非連結の場合は未定義.                                             |                               |  |
| `la(v,k)`                                        | 頂点 v から根へ向けて 長さ k 移動した先の頂点を返す.  存在しないなら -1                                           |                               |
| `jump(u,v,k)`                                    | 頂点 u から 頂点 v へ向けて 長さ k 移動した先の頂点を返す.  存在しないなら -1                                     |                               |
| `dist(u,v)`                                      | 頂点 u から 頂点 v までの辺の数を返す. u と v が非連結の場合は未定義.                                             |                               |
| `connected(u,v)`                                 | 頂点 u と 頂点 v が連結なら true, 非連結なら false                                                                |                               |
| `in_subtree(u,v)`                                | 頂点 u が 頂点 v を根とする部分木に属するなら true, そうでないなら false.                                         |                               |
| `subtree_size(v)`                                | 頂点 v を根とする部分木の頂点数を返す.                                                                            |                               |