---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':x:'
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1295.test.cpp
    title: test/yukicoder/1295.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1333.test.cpp
    title: test/yukicoder/1333.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1418.test.cpp
    title: test/yukicoder/1418.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1494.test.cpp
    title: test/yukicoder/1494.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1718.test.cpp
    title: test/yukicoder/1718.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1976.test.cpp
    title: test/yukicoder/1976.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/768.test.cpp
    title: test/yukicoder/768.test.cpp
  - icon: ':heavy_check_mark:'
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
    template <class Cost= void, bool weight= false> class Tree {\n template <class\
    \ D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator int() const {\
    \ return to; }\n };\n template <class D> struct Edge_B<D, void> {\n  int to;\n\
    \  operator int() const { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n\
    \ using C= std::conditional_t<std::is_void_v<Cost>, std::nullptr_t, Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>,\
    \ std::pair<int, int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n\
    \ std::vector<int> P, PP, D, I, L, R, pos;\n std::vector<C> DW, W;\npublic:\n\
    \ Tree(int n): P(n, -2) {}\n template <class T= Cost> std::enable_if_t<std::is_void_v<T>,\
    \ void> add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u);\
    \ }\n template <class T> std::enable_if_t<std::is_convertible_v<T, Cost>, void>\
    \ add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v, u,\
    \ c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_void_v<Cost>)\n   for (const auto &[f, t]: es) g[--pos[f]]=\
    \ {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t, c};\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  if constexpr (weight) {\n   DW.resize(n), W.resize(n);\n   for (int v:\
    \ I)\n    for (auto &[u, c]: operator[](v)) {\n     if (u != P[v]) DW[u]= DW[v]\
    \ + c;\n     else W[v]= c;\n    }\n  }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n\
    \ size_t size() const { return P.size(); }\n const ListRange<Edge> operator[](int\
    \ v) const { return {g.cbegin() + pos[v], g.cbegin() + pos[v + 1]}; }\n int depth(int\
    \ v) const { return D[v]; }\n C depth_w(int v) const {\n  static_assert(weight,\
    \ \"\\'depth_w\\' is not available\");\n  return DW[v];\n }\n int to_seq(int v)\
    \ const { return L[v]; }\n int to_node(int i) const { return I[i]; }\n int parent(int\
    \ v) const { return P[v]; }\n int head(int v) const { return PP[v]; }\n int root(int\
    \ v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n\
    \ bool connected(int u, int v) const { return root(u) == root(v); }\n int lca(int\
    \ u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u,\
    \ v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v, int k) const\
    \ {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if\
    \ (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int la_w(int v, C w) const\
    \ {\n  static_assert(weight, \"\\'la_w\\' is not available\");\n  for (C c;; w-=\
    \ c) {\n   int u= PP[v];\n   if (c= DW[v] - DW[u] + W[u]; w < c) {\n    int ok=\
    \ L[v], ng= L[u] - 1;\n    for (int m; ok - ng > 1;) m= (ok + ng) / 2, (DW[v]\
    \ - DW[I[m]] <= w ? ok : ng)= m;\n    return I[ok];\n   }\n   if (v= P[u]; v ==\
    \ -1) return u;\n  }\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int jump_w(int u, int v, C w) const {\n  static_assert(weight,\
    \ \"\\'jump_w\\' is not available\");\n  if (u == v) return u;\n  int z= lca(u,\
    \ v);\n  C d_uz= DW[u] - DW[z], d_vz= DW[v] - DW[z];\n  return w >= d_uz + d_vz\
    \ ? v : w <= d_uz ? la_w(u, w) : la_w(v, d_uz + d_vz - w);\n }\n int dist(int\
    \ u, int v) const { return D[u] + D[v] - D[lca(u, v)] * 2; }\n C dist_w(int u,\
    \ int v) const {\n  static_assert(weight, \"\\'dist_w\\' is not available\");\n\
    \  return DW[u] + DW[v] - DW[lca(u, v)] * 2;\n }\n // u is in v\n bool in_subtree(int\
    \ u, int v) const { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int\
    \ v) const { return R[v] - L[v]; }\n // half-open interval\n std::array<int, 2>\
    \ subtree(int v) const { return std::array{L[v], R[v]}; }\n // sequence of closed\
    \ intervals\n template <bool edge= 0> std::vector<std::array<int, 2>> path(int\
    \ u, int v) const {\n  std::vector<std::array<int, 2>> up, down;\n  while (PP[u]\
    \ != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}),\
    \ v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n \
    \ else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n\
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};\n#line\
    \ 3 \"src/Graph/rerooting.hpp\"\ntemplate <class T, class C> class RerootingData\
    \ {\n Tree<C> &tree;\n std::vector<T> dp1, dp2, dp;\npublic:\n RerootingData(Tree<C>\
    \ &t, std::vector<T> &d1, std::vector<T> &d2, std::vector<T> &d): tree(t), dp1(d1),\
    \ dp2(d2), dp(d) {}\n T operator[](int v) const { return dp[v]; }\n auto begin()\
    \ const { return dp.cbegin(); }\n auto end() const { return dp.cend(); }\n const\
    \ T &get(int root, int v) const { return root == v ? dp[v] : tree.in_subtree(root,\
    \ v) ? dp2[tree.jump(v, root, 1)] : dp1[v]; }\n};\ntemplate <class T, class U,\
    \ class C, class F1, class F2, class F3> RerootingData<T, C> rerooting(Tree<C>\
    \ &t, const F1 &f_ee, const F2 &f_ve, const F3 &f_ev, const U &unit) {\n const\
    \ int n= t.size();\n std::vector<T> dp1(n), dp2(n), dp(n);\n for (int i= n; i--;)\
    \ {\n  int v= t.to_node(i);\n  U sum= unit;\n  for (const auto &e: t[v])\n   if\
    \ (int u= e.to; u != t.parent(v)) sum= f_ee(sum, f_ve(dp1[u], v, e));\n  dp1[v]=\
    \ f_ev(sum, v);\n }\n for (int i= 0; i < n; ++i) {\n  int v= t.to_node(i), deg=\
    \ t[v].size();\n  std::vector<U> f(deg + 1), b(deg + 1);\n  for (int j= 0; j <\
    \ deg; ++j) {\n   const auto &e= t[v][j];\n   int u= e.to;\n   f[j + 1]= f_ve(u\
    \ == t.parent(v) ? dp2[v] : dp1[u], v, e);\n  }\n  f[0]= b[deg]= unit;\n  for\
    \ (int j= deg; j--;) b[j]= f_ee(f[j + 1], b[j + 1]);\n  for (int j= 0; j < deg;\
    \ ++j) f[j + 1]= f_ee(f[j], f[j + 1]);\n  for (int j= 0; j < deg; ++j)\n   if\
    \ (int u= t[v][j]; u != t.parent(v)) dp2[u]= f_ev(f_ee(f[j], b[j + 1]), v);\n\
    \  dp[v]= f_ev(f[deg], v);\n }\n return RerootingData<T, C>(t, dp1, dp2, dp);\n\
    }\n"
  code: "#pragma once\n#include \"src/Graph/Tree.hpp\"\ntemplate <class T, class C>\
    \ class RerootingData {\n Tree<C> &tree;\n std::vector<T> dp1, dp2, dp;\npublic:\n\
    \ RerootingData(Tree<C> &t, std::vector<T> &d1, std::vector<T> &d2, std::vector<T>\
    \ &d): tree(t), dp1(d1), dp2(d2), dp(d) {}\n T operator[](int v) const { return\
    \ dp[v]; }\n auto begin() const { return dp.cbegin(); }\n auto end() const { return\
    \ dp.cend(); }\n const T &get(int root, int v) const { return root == v ? dp[v]\
    \ : tree.in_subtree(root, v) ? dp2[tree.jump(v, root, 1)] : dp1[v]; }\n};\ntemplate\
    \ <class T, class U, class C, class F1, class F2, class F3> RerootingData<T, C>\
    \ rerooting(Tree<C> &t, const F1 &f_ee, const F2 &f_ve, const F3 &f_ev, const\
    \ U &unit) {\n const int n= t.size();\n std::vector<T> dp1(n), dp2(n), dp(n);\n\
    \ for (int i= n; i--;) {\n  int v= t.to_node(i);\n  U sum= unit;\n  for (const\
    \ auto &e: t[v])\n   if (int u= e.to; u != t.parent(v)) sum= f_ee(sum, f_ve(dp1[u],\
    \ v, e));\n  dp1[v]= f_ev(sum, v);\n }\n for (int i= 0; i < n; ++i) {\n  int v=\
    \ t.to_node(i), deg= t[v].size();\n  std::vector<U> f(deg + 1), b(deg + 1);\n\
    \  for (int j= 0; j < deg; ++j) {\n   const auto &e= t[v][j];\n   int u= e.to;\n\
    \   f[j + 1]= f_ve(u == t.parent(v) ? dp2[v] : dp1[u], v, e);\n  }\n  f[0]= b[deg]=\
    \ unit;\n  for (int j= deg; j--;) b[j]= f_ee(f[j + 1], b[j + 1]);\n  for (int\
    \ j= 0; j < deg; ++j) f[j + 1]= f_ee(f[j], f[j + 1]);\n  for (int j= 0; j < deg;\
    \ ++j)\n   if (int u= t[v][j]; u != t.parent(v)) dp2[u]= f_ev(f_ee(f[j], b[j +\
    \ 1]), v);\n  dp[v]= f_ev(f[deg], v);\n }\n return RerootingData<T, C>(t, dp1,\
    \ dp2, dp);\n}\n"
  dependsOn:
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: false
  path: src/Graph/rerooting.hpp
  requiredBy: []
  timestamp: '2023-11-24 00:33:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/1418.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/1976.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/922.test.cpp
  - test/yukicoder/1494.test.cpp
  - test/yukicoder/768.test.cpp
  - test/yukicoder/1295.test.cpp
  - test/aoj/1595.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/atcoder/abc160_f.test.cpp
  - test/atcoder/abc222_f.test.cpp
  - test/atcoder/abc220_f.test.cpp
  - test/atcoder/abc223_g.rerooting.test.cpp
  - test/yosupo/tree_path_composite_sum.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
documentation_of: src/Graph/rerooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728DP"
---
## `rerooting` の戻り値 ( RerootingData クラス )
全方位木DPの値(型 : `T` )が入っている配列だと思って使う. (`operator[](int v)`, `begin()`, `end()` がある. )\
`get(int root, int v)` :  頂点 root が根である場合の 頂点 v を根とする部分木のDP値

## `rerooting` の引数
`rerooting<T,U,C,F1,F2,F3>(Tree<C> tree, F1 f_ee, F2 f_ve, F3 f_ev, U unit)` について

`tree` : 木 \
`f_ee(U l, U r) -> U` : モノイド `U` の二項演算 \
`f_ve(T d, int v, Edge e) -> U` : 頂点 e.to から 頂点 v への 遷移を考えていて、e.to の DPの値 (型 : `T` ) からモノイドの値 (型 : `U` )に変換 \
`f_ev(U u, int v) -> T` : 頂点 v で fold 結果のモノイドの値 (型 : `U` )からDPの値(型 : `T` ) に変換 \
`unit` : モノイド `U` の単位元

## 問題例
[AtCoder Regular Contest 097 F - Monochrome Cat](https://atcoder.jp/contests/arc097/tasks/arc097_d) \
[AtCoder Regular Contest 022 C - ロミオとジュリエット](https://atcoder.jp/contests/arc022/tasks/arc022_3) \
[AtCoder Regular Contest 028 C - 高橋王国の分割統治](https://atcoder.jp/contests/arc028/tasks/arc028_3) \
[Educational DP Contest V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) \
[Typical DP Contest N - 木](https://atcoder.jp/contests/tdpc/tasks/tdpc_tree) \
[square869120Contest #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)\
[NJPC2017 E - 限界集落](https://atcoder.jp/contests/njpc2017/tasks/njpc2017_e)\
[第二回全国統一プログラミング王決定戦本戦 D - 木、](https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_d) (根付き木ハッシュ) \
[yukicoder No.1153 ねこちゃんゲーム](https://yukicoder.me/problems/no/1153) (sp judge)