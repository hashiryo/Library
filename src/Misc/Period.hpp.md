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
    path: test/atcoder/abc136_d.test.cpp
    title: test/atcoder/abc136_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc167_d.test.cpp
    title: test/atcoder/abc167_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_e.test.cpp
    title: test/atcoder/abc179_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc241_e.test.cpp
    title: test/atcoder/abc241_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc310_g.test.cpp
    title: test/atcoder/abc310_g.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1097.test.cpp
    title: test/yukicoder/1097.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1211.test.cpp
    title: test/yukicoder/1211.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1595.period.test.cpp
    title: test/yukicoder/1595.period.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1935.test.cpp
    title: test/yukicoder/1935.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':x:'
    path: test/yukicoder/658.period.test.cpp
    title: test/yukicoder/658.period.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/Period.hpp\"\n#include <map>\n#include <unordered_map>\n\
    #line 2 \"src/Graph/HeavyLightDecomposition.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <iterator>\n#include <type_traits>\n#define _LR(name, IT,\
    \ CT) \\\n template <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT;\
    \ \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\ntemplate\
    \ <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int> p;\n size_t\
    \ size() const { return p.size() - 1; }\n ListRange<T> operator[](int i) { return\
    \ {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T> operator[](int\
    \ i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate\
    \ <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
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
    };\n#line 5 \"src/Misc/Period.hpp\"\nnamespace period_internal {\ntemplate <class\
    \ Map> struct PeriodB {\n using Iter= typename Map::const_iterator;\n Map mp;\n\
    };\ntemplate <class T> using PerB= std::conditional_t<std::is_integral_v<T>, PeriodB<std::unordered_map<T,\
    \ int>>, PeriodB<std::map<T, int>>>;\n}\ntemplate <class T= int> class Period:\
    \ period_internal::PerB<T> {\n using typename period_internal::PerB<T>::Iter;\n\
    \ using Path= std::vector<std::pair<int, int>>;\n std::vector<int> t, rt;\n std::vector<T>\
    \ dc;\n HeavyLightDecomposition hld;\n static std::vector<int> iota(int n) {\n\
    \  std::vector<int> v(n);\n  for (int i= n; i--;) v[i]= i;\n  return v;\n }\n\
    public:\n Period()= default;\n template <class F> Period(const F &f, const std::vector<T>\
    \ &inits) {\n  int n= 0;\n  auto id= [&](const T &x) {\n   if (auto it= this->mp.find(x);\
    \ it != this->mp.end()) return it->second;\n   return dc.emplace_back(x), t.push_back(-1),\
    \ rt.push_back(-1), this->mp[x]= n++;\n  };\n  for (const T &s: inits)\n   if\
    \ (int v= id(s), w; rt[v] == -1) {\n    for (w= v;; rt[w]= -2, w= t[w]= id(f(dc[w])))\n\
    \     if (rt[w] != -1) {\n      if (rt[w] != -2) w= rt[w];\n      break;\n   \
    \  }\n    for (int u= v; rt[u] == -2; u= t[u]) rt[u]= w;\n   }\n  Graph g(n +\
    \ 1, n);\n  for (int v= n; v--;) g[v]= {(rt[v] == v ? n : t[v]), v};\n  hld= HeavyLightDecomposition(g.adjacency_vertex(1),\
    \ n);\n }\n Period(const std::vector<int> &functional): Period([&](int x) { return\
    \ functional[x]; }, iota(functional.size())) { static_assert(std::is_same_v<T,\
    \ int>); }\n int operator()(const T &x) const {\n  Iter it= this->mp.find(x);\n\
    \  assert(it != this->mp.end());\n  return t.size() - hld.to_seq(it->second);\n\
    \ }\n size_t size() const { return t.size(); }\n // f^k(x)\n template <class Int,\
    \ class= std::void_t<decltype(std::declval<Int>() % std::declval<int>())>> T jump(const\
    \ T &x, Int k) const {\n  Iter it= this->mp.find(x);\n  assert(it != this->mp.end());\n\
    \  int v= it->second, n= t.size(), d= hld.depth(v) - 1;\n  if (k <= d) return\
    \ dc[hld.la(v, (int)k)];\n  int b= t[v= rt[v]], l= (k-= d) % hld.depth(b);\n \
    \ if (l == 0) return dc[v];\n  return dc[hld.la(b, l - 1)];\n }\n // x, f(x),\
    \ f(f(x)), ... f^k(x)\n // (x,...,f^i(x)), (f^(i+1)(x),...,f^(j-1)(x)) x cycle,\
    \ (f^j(x),...,f^k(x))\n // sequence of half-open intervals [l,r)\n template <class\
    \ Int, class= std::void_t<decltype(std::declval<Int>() % std::declval<int>())>>\
    \ std::tuple<Path, Path, Int, Path> path(const T &x, Int k) const {\n  Iter it=\
    \ this->mp.find(x);\n  assert(it != this->mp.end());\n  int v= it->second, n=\
    \ t.size(), d= hld.depth(v) - 1;\n  std::array<Path, 3> pth;\n  Int cnt= 0;\n\
    \  if (k > d) {\n   int r= rt[v], b= t[r], c= hld.depth(b), l= (k-= d) % c;\n\
    \   if (pth[0]= hld.path(v, r), pth[1]= hld.path(b, r), cnt= k / c; l) pth[2]=\
    \ hld.path(b, hld.la(b, l - 1));\n  } else pth[0]= hld.path(v, hld.la(v, (int)k));\n\
    \  for (int s= 3; s--;)\n   for (auto &[l, r]: pth[s]) l= n - l, r= n - r + 1;\n\
    \  return {pth[0], pth[1], cnt, pth[2]};\n }\n Path path_upto_cycle(const T &x)\
    \ const {\n  Iter it= this->mp.find(x);\n  assert(it != this->mp.end());\n  int\
    \ v= it->second, n= t.size(), r= rt[v], b= t[r], w= hld.lca(b, v);\n  auto p1=\
    \ hld.path(v, r);\n  if (b != w) {\n   auto p2= hld.path(b, hld.jump(w, b, 1));\n\
    \   p1.insert(p1.end(), p2.begin(), p2.end());\n  }\n  for (auto &[l, r]: p1)\
    \ l= n - l, r= n - r + 1;\n  return p1;\n }\n};\n"
  code: "#pragma once\n#include <map>\n#include <unordered_map>\n#include \"src/Graph/HeavyLightDecomposition.hpp\"\
    \nnamespace period_internal {\ntemplate <class Map> struct PeriodB {\n using Iter=\
    \ typename Map::const_iterator;\n Map mp;\n};\ntemplate <class T> using PerB=\
    \ std::conditional_t<std::is_integral_v<T>, PeriodB<std::unordered_map<T, int>>,\
    \ PeriodB<std::map<T, int>>>;\n}\ntemplate <class T= int> class Period: period_internal::PerB<T>\
    \ {\n using typename period_internal::PerB<T>::Iter;\n using Path= std::vector<std::pair<int,\
    \ int>>;\n std::vector<int> t, rt;\n std::vector<T> dc;\n HeavyLightDecomposition\
    \ hld;\n static std::vector<int> iota(int n) {\n  std::vector<int> v(n);\n  for\
    \ (int i= n; i--;) v[i]= i;\n  return v;\n }\npublic:\n Period()= default;\n template\
    \ <class F> Period(const F &f, const std::vector<T> &inits) {\n  int n= 0;\n \
    \ auto id= [&](const T &x) {\n   if (auto it= this->mp.find(x); it != this->mp.end())\
    \ return it->second;\n   return dc.emplace_back(x), t.push_back(-1), rt.push_back(-1),\
    \ this->mp[x]= n++;\n  };\n  for (const T &s: inits)\n   if (int v= id(s), w;\
    \ rt[v] == -1) {\n    for (w= v;; rt[w]= -2, w= t[w]= id(f(dc[w])))\n     if (rt[w]\
    \ != -1) {\n      if (rt[w] != -2) w= rt[w];\n      break;\n     }\n    for (int\
    \ u= v; rt[u] == -2; u= t[u]) rt[u]= w;\n   }\n  Graph g(n + 1, n);\n  for (int\
    \ v= n; v--;) g[v]= {(rt[v] == v ? n : t[v]), v};\n  hld= HeavyLightDecomposition(g.adjacency_vertex(1),\
    \ n);\n }\n Period(const std::vector<int> &functional): Period([&](int x) { return\
    \ functional[x]; }, iota(functional.size())) { static_assert(std::is_same_v<T,\
    \ int>); }\n int operator()(const T &x) const {\n  Iter it= this->mp.find(x);\n\
    \  assert(it != this->mp.end());\n  return t.size() - hld.to_seq(it->second);\n\
    \ }\n size_t size() const { return t.size(); }\n // f^k(x)\n template <class Int,\
    \ class= std::void_t<decltype(std::declval<Int>() % std::declval<int>())>> T jump(const\
    \ T &x, Int k) const {\n  Iter it= this->mp.find(x);\n  assert(it != this->mp.end());\n\
    \  int v= it->second, n= t.size(), d= hld.depth(v) - 1;\n  if (k <= d) return\
    \ dc[hld.la(v, (int)k)];\n  int b= t[v= rt[v]], l= (k-= d) % hld.depth(b);\n \
    \ if (l == 0) return dc[v];\n  return dc[hld.la(b, l - 1)];\n }\n // x, f(x),\
    \ f(f(x)), ... f^k(x)\n // (x,...,f^i(x)), (f^(i+1)(x),...,f^(j-1)(x)) x cycle,\
    \ (f^j(x),...,f^k(x))\n // sequence of half-open intervals [l,r)\n template <class\
    \ Int, class= std::void_t<decltype(std::declval<Int>() % std::declval<int>())>>\
    \ std::tuple<Path, Path, Int, Path> path(const T &x, Int k) const {\n  Iter it=\
    \ this->mp.find(x);\n  assert(it != this->mp.end());\n  int v= it->second, n=\
    \ t.size(), d= hld.depth(v) - 1;\n  std::array<Path, 3> pth;\n  Int cnt= 0;\n\
    \  if (k > d) {\n   int r= rt[v], b= t[r], c= hld.depth(b), l= (k-= d) % c;\n\
    \   if (pth[0]= hld.path(v, r), pth[1]= hld.path(b, r), cnt= k / c; l) pth[2]=\
    \ hld.path(b, hld.la(b, l - 1));\n  } else pth[0]= hld.path(v, hld.la(v, (int)k));\n\
    \  for (int s= 3; s--;)\n   for (auto &[l, r]: pth[s]) l= n - l, r= n - r + 1;\n\
    \  return {pth[0], pth[1], cnt, pth[2]};\n }\n Path path_upto_cycle(const T &x)\
    \ const {\n  Iter it= this->mp.find(x);\n  assert(it != this->mp.end());\n  int\
    \ v= it->second, n= t.size(), r= rt[v], b= t[r], w= hld.lca(b, v);\n  auto p1=\
    \ hld.path(v, r);\n  if (b != w) {\n   auto p2= hld.path(b, hld.jump(w, b, 1));\n\
    \   p1.insert(p1.end(), p2.begin(), p2.end());\n  }\n  for (auto &[l, r]: p1)\
    \ l= n - l, r= n - r + 1;\n  return p1;\n }\n};"
  dependsOn:
  - src/Graph/HeavyLightDecomposition.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Misc/Period.hpp
  requiredBy: []
  timestamp: '2024-02-22 21:50:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1097.test.cpp
  - test/yukicoder/1935.test.cpp
  - test/yukicoder/1211.test.cpp
  - test/yukicoder/1595.period.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/658.period.test.cpp
  - test/yukicoder/1242.test.cpp
  - test/atcoder/abc310_g.test.cpp
  - test/atcoder/abc167_d.test.cpp
  - test/atcoder/abc179_e.test.cpp
  - test/atcoder/abc136_d.test.cpp
  - test/atcoder/abc241_e.test.cpp
documentation_of: src/Misc/Period.hpp
layout: document
title: "\u5468\u671F\u6027\u306E\u5229\u7528 (Functional\u30B0\u30E9\u30D5)"
---

## `Period<T>` クラス

初期状態が $x_0\in T$ な列 $(x_i)_i$ が次の漸化式で定まっているとする．

$
\displaystyle x_{i+1} = f(x_i)
$

$x_i$ として取りうる状態の数が有限であるときに周期性を利用して巨大な数 $k$ に対する $x_k$ を求める　

などするクラス．

初期状態が複数ある場合でも Functional グラフを重軽分解することで頑張る．

状態 $x$ をいい感じに並び替えて，ラベリングする．

状態の数を $n$ とする．

| メンバ関数 | 概要 | 計算量 |
| --- | --- | --- |
| `Period(f, init)` | コンストラクタ. <br> 関数 $f:T\to T$ と初期状態の集合 $X_0 \subset T $ を渡す． <br> 第二引数は `vector<T>`. |$O(An\log n)$ <br> ただし $f(x)$ の計算に $O(A)$ とかかるとした．<br> $\log$ は連想配列を用いたため．|
| `Period(functional)` | コンストラクタ. <br> 全状態の集合が $V＝\lbrace 0,\dots,n-1\rbrace$ だとして，それぞれの状態の移り先を表す配列 ( $V\to V$ ) を渡す．<br> 引数は `vector<int>`. <br> `T == int` でないと呼べない．| $O(n)$|
|`size()`|状態の数 $n$ を返す．||
|`operator()(x)`| $x$ に対応するラベルを返す．<br> 戻り値は `int`. |
| `jump(x,k)`          | $f^k(x)=\overbrace{f(\cdots f(f}^{k}(x)))$ を返す. <br> 第二引数は何らかの整数型 `Int`．( [`BigInt`クラス](../FFT/BigInt.hpp)も使える．) <br> 戻り値は `T`.| $O(\log n)$ |
| `path(x,k)`          | $x,f(x),\dots,f^k(x)$ という軌道を表す 半開区間の列 を返す．<br> 第二引数は何らかの整数型 `Int`．( [`BigInt`クラス](../FFT/BigInt.hpp)も使える．) <br> 戻り値は4つのデータをラッピングした`tuple`．<br> 一つ目はサイクルに至るまでの軌道．<br> 二つ目はサイクル一周分を表す軌道．<br> 三つ目はサイクルの周回数 `Int`. <br> 四つ目はサイクルの余りの軌道．<br> 軌道は `vector<pair<int,int>>` で表現する半開区間の列 $\lbrack a_0, b_0 ),\dots,\lbrack a_m, b_m )$ であり, `operator()` のラベルに対応している． | $O(\log n)$ |
| `path_upto_cycle(x)`          | 同じ値が出るまでの軌道を返す．<br> 軌道は `vector<pair<int,int>>` で表現する半開区間の列 $\lbrack a_0, b_0 ),\dots,\lbrack a_m, b_m )$ であり, `operator()` のラベルに対応している． | $O(\log n)$ |

## 問題例
[AtCoder Beginner Contest 030 D - へんてこ辞書](https://atcoder.jp/contests/abc030/tasks/abc030_d)\
[JOI 2010-2011 日本代表選手選考会 (春合宿代替措置) 過去問 report - 報告 (Report)](https://atcoder.jp/contests/joisc2011/tasks/joisc2011_report) (`path_upto_cycle`)