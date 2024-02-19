---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':question:'
    path: src/Graph/BipartiteGraph.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/bipartite_edge_coloring.hpp\"\n#include <queue>\n\
    #include <numeric>\n#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\ntemplate <bool undoable= false> class\
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
    \ > t) undo();\n }\n};\n#line 3 \"src/Graph/BipartiteGraph.hpp\"\n#include <tuple>\n\
    #line 3 \"src/Internal/ListRange.hpp\"\n#include <iostream>\n#include <iterator>\n\
    #include <type_traits>\n#define _LR(name, IT, CT) \\\n template <class T> struct\
    \ name { \\\n  using Iterator= typename std::vector<T>::IT; \\\n  Iterator bg,\
    \ ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator end() const {\
    \ return ed; } \\\n  size_t size() const { return std::distance(bg, ed); } \\\n\
    \  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange, iterator,\
    \ T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\ntemplate <class\
    \ T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int> p;\n size_t size()\
    \ const { return p.size() - 1; }\n ListRange<T> operator[](int i) { return {dat.begin()\
    \ + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const\
    \ { return {dat.cbegin() + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template\
    \ <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 6 \"src/Graph/BipartiteGraph.hpp\"\
    \n// [0, L) is left, [L, n) is right\nstruct BipartiteGraph: Graph {\n size_t\
    \ L;\n BipartiteGraph() {}\n BipartiteGraph(size_t L, size_t R, size_t m= 0):\
    \ Graph(L + R, m), L(L) {}\n size_t left_size() const { return L; }\n size_t right_size()\
    \ const { return this->n - L; }\n};\nstd::vector<int> paint_in_2_color(const CSRArray<int>\
    \ &adj) {\n const int n= adj.size();\n std::vector<int> col(n, -1);\n for (int\
    \ s= n; s--;)\n  if (col[s] == -1) {\n   std::vector<int> q= {s};\n   for (int\
    \ i= col[s]= 0, v; i < (int)q.size(); ++i)\n    for (int u: adj[v= q[i]])\n  \
    \   if (int c= col[v]; col[u] == c) return {};\n     else if (col[u] == -1) col[u]=\
    \ c ^ 1, q.push_back(u);\n  }\n return col;\n}\nstd::vector<int> paint_in_2_color(const\
    \ Graph &g) { return paint_in_2_color(g.adjacency_vertex(0)); }\n// { BipartiteGraph\
    \ , original to new, new to original }\n// {{},{},{}} if not bipartite\nstd::tuple<BipartiteGraph,\
    \ std::vector<int>, std::vector<int>> graph_to_bipartite(const Graph &g, std::vector<int>\
    \ color= {}) {\n if (color.empty()) color= paint_in_2_color(g);\n if (color.empty())\
    \ return {};\n const int n= g.vertex_size(), m= g.edge_size();\n std::vector<int>\
    \ a(n), b(n);\n int l= 0, r= n;\n for (int i= n; i--;) b[a[i]= color[i] ? --r\
    \ : l++]= i;\n BipartiteGraph bg(l, n - l, m);\n for (int i= m; i--;) {\n  auto\
    \ [u, v]= g[i];\n  bg[i]= std::minmax(a[u], a[v]);\n }\n return {bg, a, b};\n\
    }\nnamespace _bg_internal {\nstd::vector<int> _bm(int L, const CSRArray<int> &adj,\
    \ std::vector<int> &m) {\n std::vector<int> a, p, q(L);\n for (bool u= true; u;)\
    \ {\n  u= false, a.assign(L, -1), p.assign(L, -1);\n  int t= 0;\n  for (int l=\
    \ L; l--;)\n   if (m[l] == -1) q[t++]= a[l]= p[l]= l;\n  for (int i= 0; i < t;\
    \ ++i)\n   if (int l= q[i], x; m[a[l]] == -1)\n    for (int r: adj[l]) {\n   \
    \  if (x= m[r]; x == -1) {\n      for (u= true; r != -1; l= p[l]) m[r]= l, std::swap(m[l],\
    \ r);\n      break;\n     }\n     if (p[x] == -1) a[q[t++]= x]= a[p[x]= l];\n\
    \    }\n }\n return a;\n}\n}\ntemplate <bool lexical= false> std::pair<std::vector<int>,\
    \ std::vector<int>> bipartite_matching(const BipartiteGraph &g, std::vector<int>\
    \ partner= {}) {\n const int L= g.left_size(), M= g.edge_size();\n if (partner.empty())\
    \ partner.assign(g.vertex_size(), -1);\n assert(partner.size() == g.vertex_size());\n\
    \ {\n  CSRArray<int> adj{std::vector<int>(M), std::vector<int>(L + 1)};\n  for\
    \ (auto [l, r]: g) ++adj.p[l];\n  for (int i= 0; i < L; ++i) adj.p[i + 1]+= adj.p[i];\n\
    \  for (auto [l, r]: g) adj.dat[--adj.p[l]]= r;\n  if constexpr (lexical) {\n\
    \   for (int l= L; l--;) std::sort(adj[l].begin(), adj[l].end());\n   _bg_internal::_bm(L,\
    \ adj, partner);\n   std::vector<char> a(L, 1);\n   for (int l= 0; l < L; ++l)\n\
    \    if (int r= partner[l], v= l; r != -1) {\n     std::vector<int> p(L, partner[v]=\
    \ partner[r]= -1), c(adj.p.begin(), adj.p.begin() + L);\n     for (p[v]= -2;;)\
    \ {\n      if (c[v] == adj.p[v + 1]) v= p[v];\n      else if (int u= partner[r=\
    \ adj.dat[c[v]++]]; u == -1) {\n       for (; r != -1; v= p[v]) partner[r]= v,\
    \ std::swap(partner[v], r);\n       break;\n      } else if (a[u] && p[u] == -1)\
    \ p[u]= v, v= u;\n     }\n     a[l]= 0;\n    }\n  } else _bg_internal::_bm(L,\
    \ adj, partner);\n }\n std::vector<int> c;\n std::vector<char> p(L);\n for (int\
    \ i= 0; i < M; ++i)\n  if (auto [l, r]= g[i]; partner[l] == r && !p[l]) c.push_back(i),\
    \ p[l]= 1;\n return {c, partner};\n}\n#line 6 \"src/Graph/bipartite_edge_coloring.hpp\"\
    \nstd::vector<int> bipartite_edge_coloring(BipartiteGraph g) {\n const int m=\
    \ g.edge_size();\n int L= g.left_size(), n= g.vertex_size(), D, col= 0;\n {\n\
    \  std::vector<int> deg(n), id(n);\n  for (auto [l, r]: g) ++deg[l], ++deg[r];\n\
    \  D= *std::max_element(deg.begin(), deg.end());\n  UnionFind uf(n);\n  for (int\
    \ _: {0, n}) {\n   auto [b, e]= std::minmax(_, L);\n   std::priority_queue<std::pair<int,\
    \ int>> pq;\n   for (int i= b; i < e; ++i) pq.emplace(-deg[i], i);\n   for (;\
    \ pq.size() > 1;) {\n    auto [a, v]= pq.top();\n    pq.pop();\n    auto [b, u]=\
    \ pq.top();\n    pq.pop();\n    if (int sum= a + b; -sum <= D) uf.unite(v, u),\
    \ pq.emplace(sum, v);\n    else break;\n   }\n  }\n  int i= 0, cl= 0, cr= 0;\n\
    \  for (; i < L; ++i)\n   if (uf.root(i) == i) id[i]= cl++;\n  for (; i < n; ++i)\n\
    \   if (uf.root(i) == i) id[i]= cr++;\n  L= std::max(cl, cr), deg.assign(n= L\
    \ + L, 0), g.reserve(L * D);\n  for (auto &[l, r]: g) ++deg[l= id[uf.root(l)]],\
    \ ++deg[r= id[uf.root(r)] + L];\n  for (int l= 0, r= L; l < L; ++l)\n   while\
    \ (deg[l] < D) {\n    while (r < n && deg[r] == D) ++r;\n    int x= D - std::max(deg[l],\
    \ deg[r]);\n    for (int k= x; k--;) g.add_edge(l, r);\n    deg[l]+= x, deg[r]+=\
    \ x;\n   }\n }\n std::vector<int> color(m, -1);\n auto rc= [&](auto &&rc, int\
    \ d, const std::vector<int> &idx) -> void {\n  if (!d) return;\n  if (d == 1)\
    \ {\n   for (int e: idx)\n    if (e < m) color[e]= col;\n   ++col;\n   return;\n\
    \  }\n  if (d & 1) {\n   CSRArray<int> adj{std::vector<int>(idx.size()), std::vector<int>(L\
    \ + 1)};\n   for (int e: idx) ++adj.p[g[e].first];\n   for (int i= 0; i < L; ++i)\
    \ adj.p[i + 1]+= adj.p[i];\n   for (int e: idx) {\n    auto [l, r]= g[e];\n  \
    \  adj.dat[--adj.p[l]]= r;\n   }\n   std::vector<int> mate(n, -1), rm;\n   _bg_internal::_bm(L,\
    \ adj, mate);\n   for (int e: idx) {\n    auto [l, r]= g[e];\n    if (mate[l]\
    \ == r) {\n     if (mate[l]= mate[r]= -1; e < m) color[e]= col;\n    } else rm.push_back(e);\n\
    \   }\n   return ++col, rc(rc, d - 1, rm);\n  }\n  const int mm= idx.size();\n\
    \  std::vector<int> circuit;\n  {\n   std::vector<int> c(mm), p(n + 1);\n   for\
    \ (int e: idx) {\n    auto [l, r]= g[e];\n    ++p[l], ++p[r];\n   }\n   for (int\
    \ i= 0; i < L; ++i) p[i + 1]+= p[i];\n   for (int i= mm; i--;) {\n    auto [l,\
    \ r]= g[idx[i]];\n    c[--p[l]]= i, c[--p[r]]= i;\n   }\n   std::vector<int> it(p.begin(),\
    \ p.begin() + n);\n   std::vector<char> used1(n), used2(mm);\n   for (int v= n;\
    \ v--;)\n    if (!used1[v]) {\n     for (std::vector<std::pair<int, int>> st=\
    \ {{v, -1}}; st.size();) {\n      auto [u, e]= st.back();\n      if (used1[u]=\
    \ 1; it[u] == p[u + 1]) circuit.push_back(e), st.pop_back();\n      else if (int\
    \ i= c[it[u]++]; !used2[i]) used2[i]= 1, st.emplace_back(g[idx[i]].to(u), i);\n\
    \     }\n     circuit.pop_back();\n    }\n  }\n  std::vector<int> half1(mm / 2),\
    \ half2(mm / 2);\n  for (int i= mm / 2; i--;) half1[i]= idx[circuit[i * 2]], half2[i]=\
    \ idx[circuit[i * 2 + 1]];\n  rc(rc, d / 2, half1), rc(rc, d / 2, half2);\n };\n\
    \ std::vector<int> idx(m * D);\n return std::iota(idx.begin(), idx.end(), 0),\
    \ rc(rc, D, idx), color;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <numeric>\n#include \"src/DataStructure/UnionFind.hpp\"\
    \n#include \"src/Graph/BipartiteGraph.hpp\"\nstd::vector<int> bipartite_edge_coloring(BipartiteGraph\
    \ g) {\n const int m= g.edge_size();\n int L= g.left_size(), n= g.vertex_size(),\
    \ D, col= 0;\n {\n  std::vector<int> deg(n), id(n);\n  for (auto [l, r]: g) ++deg[l],\
    \ ++deg[r];\n  D= *std::max_element(deg.begin(), deg.end());\n  UnionFind uf(n);\n\
    \  for (int _: {0, n}) {\n   auto [b, e]= std::minmax(_, L);\n   std::priority_queue<std::pair<int,\
    \ int>> pq;\n   for (int i= b; i < e; ++i) pq.emplace(-deg[i], i);\n   for (;\
    \ pq.size() > 1;) {\n    auto [a, v]= pq.top();\n    pq.pop();\n    auto [b, u]=\
    \ pq.top();\n    pq.pop();\n    if (int sum= a + b; -sum <= D) uf.unite(v, u),\
    \ pq.emplace(sum, v);\n    else break;\n   }\n  }\n  int i= 0, cl= 0, cr= 0;\n\
    \  for (; i < L; ++i)\n   if (uf.root(i) == i) id[i]= cl++;\n  for (; i < n; ++i)\n\
    \   if (uf.root(i) == i) id[i]= cr++;\n  L= std::max(cl, cr), deg.assign(n= L\
    \ + L, 0), g.reserve(L * D);\n  for (auto &[l, r]: g) ++deg[l= id[uf.root(l)]],\
    \ ++deg[r= id[uf.root(r)] + L];\n  for (int l= 0, r= L; l < L; ++l)\n   while\
    \ (deg[l] < D) {\n    while (r < n && deg[r] == D) ++r;\n    int x= D - std::max(deg[l],\
    \ deg[r]);\n    for (int k= x; k--;) g.add_edge(l, r);\n    deg[l]+= x, deg[r]+=\
    \ x;\n   }\n }\n std::vector<int> color(m, -1);\n auto rc= [&](auto &&rc, int\
    \ d, const std::vector<int> &idx) -> void {\n  if (!d) return;\n  if (d == 1)\
    \ {\n   for (int e: idx)\n    if (e < m) color[e]= col;\n   ++col;\n   return;\n\
    \  }\n  if (d & 1) {\n   CSRArray<int> adj{std::vector<int>(idx.size()), std::vector<int>(L\
    \ + 1)};\n   for (int e: idx) ++adj.p[g[e].first];\n   for (int i= 0; i < L; ++i)\
    \ adj.p[i + 1]+= adj.p[i];\n   for (int e: idx) {\n    auto [l, r]= g[e];\n  \
    \  adj.dat[--adj.p[l]]= r;\n   }\n   std::vector<int> mate(n, -1), rm;\n   _bg_internal::_bm(L,\
    \ adj, mate);\n   for (int e: idx) {\n    auto [l, r]= g[e];\n    if (mate[l]\
    \ == r) {\n     if (mate[l]= mate[r]= -1; e < m) color[e]= col;\n    } else rm.push_back(e);\n\
    \   }\n   return ++col, rc(rc, d - 1, rm);\n  }\n  const int mm= idx.size();\n\
    \  std::vector<int> circuit;\n  {\n   std::vector<int> c(mm), p(n + 1);\n   for\
    \ (int e: idx) {\n    auto [l, r]= g[e];\n    ++p[l], ++p[r];\n   }\n   for (int\
    \ i= 0; i < L; ++i) p[i + 1]+= p[i];\n   for (int i= mm; i--;) {\n    auto [l,\
    \ r]= g[idx[i]];\n    c[--p[l]]= i, c[--p[r]]= i;\n   }\n   std::vector<int> it(p.begin(),\
    \ p.begin() + n);\n   std::vector<char> used1(n), used2(mm);\n   for (int v= n;\
    \ v--;)\n    if (!used1[v]) {\n     for (std::vector<std::pair<int, int>> st=\
    \ {{v, -1}}; st.size();) {\n      auto [u, e]= st.back();\n      if (used1[u]=\
    \ 1; it[u] == p[u + 1]) circuit.push_back(e), st.pop_back();\n      else if (int\
    \ i= c[it[u]++]; !used2[i]) used2[i]= 1, st.emplace_back(g[idx[i]].to(u), i);\n\
    \     }\n     circuit.pop_back();\n    }\n  }\n  std::vector<int> half1(mm / 2),\
    \ half2(mm / 2);\n  for (int i= mm / 2; i--;) half1[i]= idx[circuit[i * 2]], half2[i]=\
    \ idx[circuit[i * 2 + 1]];\n  rc(rc, d / 2, half1), rc(rc, d / 2, half2);\n };\n\
    \ std::vector<int> idx(m * D);\n return std::iota(idx.begin(), idx.end(), 0),\
    \ rc(rc, D, idx), color;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/Graph/BipartiteGraph.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/bipartite_edge_coloring.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bipartite_edge_coloring.test.cpp
documentation_of: src/Graph/bipartite_edge_coloring.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272"
---



## 問題例
[AtCoder Grand Contest 037 D - Sorting a Grid](https://atcoder.jp/contests/agc037/tasks/agc037_d) (sp judge)

## 参考
[https://ei1333.hateblo.jp/entry/2020/08/25/015955](https://ei1333.hateblo.jp/entry/2020/08/25/015955)