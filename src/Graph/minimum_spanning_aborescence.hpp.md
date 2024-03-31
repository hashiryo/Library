---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/minimum_spanning_aborescence.hpp\"\n#include <utility>\n\
    #line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include <iostream>\n\
    #include <iterator>\n#include <type_traits>\n#define _LR(name, IT, CT) \\\n template\
    \ <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT; \\\
    \n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/DataStructure/UnionFind.hpp\"\
    \n#include <algorithm>\n#include <cassert>\ntemplate <bool undoable= false> class\
    \ UnionFind {\n std::vector<int> par;\n std::vector<std::pair<int, int>> his;\n\
    public:\n UnionFind(int n): par(n, -1) {}\n bool unite(int u, int v) {\n  if ((u=\
    \ root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u,\
    \ v);\n  if constexpr (undoable) his.emplace_back(v, par[v]);\n  return par[u]+=\
    \ par[v], par[v]= u, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) {\n  if constexpr (undoable) return par[u] < 0 ? u : root(par[u]);\n\
    \  else return par[u] < 0 ? u : par[u]= root(par[u]);\n }\n int size(int u) {\
    \ return -par[root(u)]; }\n int time() const {\n  static_assert(undoable, \"\\\
    'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n  static_assert(undoable,\
    \ \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n  his.pop_back(),\
    \ par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n  static_assert(undoable,\
    \ \"\\'rollback\\' is not enabled\");\n  assert(t <= his.size());\n  while (his.size()\
    \ > t) undo();\n }\n};\n#line 5 \"src/Graph/minimum_spanning_aborescence.hpp\"\
    \n// return {total cost, edge ids}\n// return {0, {}} if the graph has no spanning\
    \ aborescence of the root\ntemplate <class cost_t> std::pair<cost_t, std::vector<int>>\
    \ minimum_spanning_aborescence(const Graph &g, std::vector<cost_t> w, int root)\
    \ {\n const int n= g.vertex_size(), m= g.edge_size();\n assert((int)w.size() ==\
    \ m);\n std::vector<cost_t> lz(m);\n std::vector<std::pair<int, int>> lr(m, {-1,\
    \ -1}), cyc;\n std::vector<int> top(n, -1), es(n, -1);\n UnionFind uf(n);\n UnionFind<true>\
    \ uf2(n);\n auto upd= [&](int i, cost_t v) { w[i]-= v, lz[i]+= v; };\n auto push=\
    \ [&](int i) {\n  auto [l, r]= lr[i];\n  if (l != -1) upd(l, lz[i]);\n  if (r\
    \ != -1) upd(r, lz[i]);\n  lz[i]= 0;\n };\n auto merge= [&](auto &&rec, int u,\
    \ int v) -> int {\n  if (u == -1) return v;\n  if (v == -1) return u;\n  if (w[v]\
    \ < w[u]) std::swap(u, v);\n  auto &[l, r]= lr[u];\n  return push(u), r= rec(rec,\
    \ r, v), std::swap(l, r), u;\n };\n for (int i= m; i--;) {\n  auto [s, d]= g[i];\n\
    \  top[d]= merge(merge, top[d], i);\n }\n cost_t sum= 0;\n for (int i= n; i--;)\
    \ {\n  if (i == root) continue;\n  for (int v= i;;) {\n   if (top[v] == -1) return\
    \ {};\n   int x= uf2.root(g[es[v]= top[v]].first);\n   if (sum+= w[es[v]], upd(es[v],\
    \ w[es[v]]); uf.unite(v, x)) break;\n   int t= uf2.time();\n   for (int r; uf2.unite(v,\
    \ x); v= r, x= uf2.root(g[es[x]].first)) top[r= uf2.root(v)]= merge(merge, top[v],\
    \ top[x]);\n   cyc.emplace_back(es[v], t);\n   while (top[v] != -1 && uf2.same(v,\
    \ g[top[v]].first)) {\n    auto [l, r]= lr[top[v]];\n    push(top[v]), top[v]=\
    \ merge(merge, l, r);\n   }\n  }\n }\n for (auto it= cyc.rbegin(); it != cyc.rend();\
    \ ++it) {\n  auto [e, t]= *it;\n  int r= uf2.root(g[e].second);\n  uf2.rollback(t);\n\
    \  int v= uf2.root(g[es[r]].second);\n  es[v]= std::exchange(es[r], e);\n }\n\
    \ es.erase(es.begin() + root);\n return {sum, es};\n}\n"
  code: "#pragma once\n#include <utility>\n#include \"src/Graph/Graph.hpp\"\n#include\
    \ \"src/DataStructure/UnionFind.hpp\"\n// return {total cost, edge ids}\n// return\
    \ {0, {}} if the graph has no spanning aborescence of the root\ntemplate <class\
    \ cost_t> std::pair<cost_t, std::vector<int>> minimum_spanning_aborescence(const\
    \ Graph &g, std::vector<cost_t> w, int root) {\n const int n= g.vertex_size(),\
    \ m= g.edge_size();\n assert((int)w.size() == m);\n std::vector<cost_t> lz(m);\n\
    \ std::vector<std::pair<int, int>> lr(m, {-1, -1}), cyc;\n std::vector<int> top(n,\
    \ -1), es(n, -1);\n UnionFind uf(n);\n UnionFind<true> uf2(n);\n auto upd= [&](int\
    \ i, cost_t v) { w[i]-= v, lz[i]+= v; };\n auto push= [&](int i) {\n  auto [l,\
    \ r]= lr[i];\n  if (l != -1) upd(l, lz[i]);\n  if (r != -1) upd(r, lz[i]);\n \
    \ lz[i]= 0;\n };\n auto merge= [&](auto &&rec, int u, int v) -> int {\n  if (u\
    \ == -1) return v;\n  if (v == -1) return u;\n  if (w[v] < w[u]) std::swap(u,\
    \ v);\n  auto &[l, r]= lr[u];\n  return push(u), r= rec(rec, r, v), std::swap(l,\
    \ r), u;\n };\n for (int i= m; i--;) {\n  auto [s, d]= g[i];\n  top[d]= merge(merge,\
    \ top[d], i);\n }\n cost_t sum= 0;\n for (int i= n; i--;) {\n  if (i == root)\
    \ continue;\n  for (int v= i;;) {\n   if (top[v] == -1) return {};\n   int x=\
    \ uf2.root(g[es[v]= top[v]].first);\n   if (sum+= w[es[v]], upd(es[v], w[es[v]]);\
    \ uf.unite(v, x)) break;\n   int t= uf2.time();\n   for (int r; uf2.unite(v, x);\
    \ v= r, x= uf2.root(g[es[x]].first)) top[r= uf2.root(v)]= merge(merge, top[v],\
    \ top[x]);\n   cyc.emplace_back(es[v], t);\n   while (top[v] != -1 && uf2.same(v,\
    \ g[top[v]].first)) {\n    auto [l, r]= lr[top[v]];\n    push(top[v]), top[v]=\
    \ merge(merge, l, r);\n   }\n  }\n }\n for (auto it= cyc.rbegin(); it != cyc.rend();\
    \ ++it) {\n  auto [e, t]= *it;\n  int r= uf2.root(g[e].second);\n  uf2.rollback(t);\n\
    \  int v= uf2.root(g[es[r]].second);\n  es[v]= std::exchange(es[r], e);\n }\n\
    \ es.erase(es.begin() + root);\n return {sum, es};\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: false
  path: src/Graph/minimum_spanning_aborescence.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/directedmst.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/2647.test.cpp
documentation_of: src/Graph/minimum_spanning_aborescence.hpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
---

|関数名|概要|計算量|
|---|---|---|
|`minimum_spanning_aborescense(g,w,root)`|最小全域有向木を求める．<br> 引数は [`Graph` クラス](Graph.hpp) と辺の重みを表す`vector`と求めたい木の根 root.<br>返り値は `pair` でラッピングした二つを返す．<br> 一つ目は MSA の重みの和．<br>二つ目は MSA に使う辺の番号を表す　`vector<int>`. |$O(E\log V)$|