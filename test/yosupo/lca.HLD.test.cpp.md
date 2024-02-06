---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.HLD.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include <iostream>\n#line 2 \"src/Graph/Tree.hpp\"\n#include <type_traits>\n\
    #include <cstddef>\n#include <algorithm>\n#include <array>\n#include <tuple>\n\
    #include <numeric>\n#include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\
    \n#include <vector>\n#include <iterator>\ntemplate <class T> struct ListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n};\n#line 10 \"src/Graph/Tree.hpp\"\ntemplate <class\
    \ Cost= void, bool weight= false> class Tree {\n template <class D, class T> struct\
    \ Edge_B {\n  int to;\n  T cost;\n  operator int() const { return to; }\n };\n\
    \ template <class D> struct Edge_B<D, void> {\n  int to;\n  operator int() const\
    \ { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n using C= std::conditional_t<std::is_void_v<Cost>,\
    \ std::nullptr_t, Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>,\
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
    \ 4 \"test/yosupo/lca.HLD.test.cpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >> Q;\n Tree tree(N);\n\
    \ for (int i= 1; i < N; i++) {\n  int p;\n  cin >> p;\n  tree.add_edge(i, p);\n\
    \ }\n tree.build(0);\n while (Q--) {\n  int u, v;\n  cin >> u >> v;\n  cout <<\
    \ tree.lca(u, v) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    #include \"src/Graph/Tree.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N, Q;\n cin >> N >> Q;\n Tree tree(N);\n for\
    \ (int i= 1; i < N; i++) {\n  int p;\n  cin >> p;\n  tree.add_edge(i, p);\n }\n\
    \ tree.build(0);\n while (Q--) {\n  int u, v;\n  cin >> u >> v;\n  cout << tree.lca(u,\
    \ v) << '\\n';\n }\n return 0;\n}\n"
  dependsOn:
  - src/Graph/Tree.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: true
  path: test/yosupo/lca.HLD.test.cpp
  requiredBy: []
  timestamp: '2024-02-06 20:21:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/lca.HLD.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.HLD.test.cpp
- /verify/test/yosupo/lca.HLD.test.cpp.html
title: test/yosupo/lca.HLD.test.cpp
---
