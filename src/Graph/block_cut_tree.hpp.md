---
data:
  _extendedDependsOn:
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
    path: test/aoj/3022.test.cpp
    title: test/aoj/3022.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/block_cut_tree.hpp\"\
    \n// [0,n) : vertex\n// [n,n+b) : block\n// deg(v) > 1 -> articulation point\n\
    Graph block_cut_tree(const CSRArray<int> &adj) {\n const int n= adj.size();\n\
    \ std::vector<int> ord(n), par(n, -2), dat(adj.p.begin(), adj.p.begin() + n);\n\
    \ int k= 0;\n for (int s= n, p; s--;)\n  if (par[s] == -2)\n   for (par[p= s]=\
    \ -1; p >= 0;) {\n    if (dat[p] == adj.p[p]) ord[k++]= p;\n    if (dat[p] ==\
    \ adj.p[p + 1]) p= par[p];\n    else if (int q= adj.dat[dat[p]++]; par[q] == -2)\
    \ par[q]= p, p= q;\n   }\n for (int i= n; i--;) dat[ord[i]]= i;\n auto low= dat;\n\
    \ for (int v= n; v--;)\n  for (int u: adj[v]) low[v]= std::min(low[v], dat[u]);\n\
    \ for (int i= n; i--;)\n  if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]= std::min(low[pp],\
    \ low[p]);\n Graph ret(k);\n for (int p: ord)\n  if (par[p] >= 0) {\n   if (int\
    \ pp= par[p]; low[p] < dat[pp]) ret.add_edge(low[p]= low[pp], p);\n   else ret.add_vertex(),\
    \ ret.add_edge(k, pp), ret.add_edge(k, p), low[p]= k++;\n  }\n for (int s= 0;\
    \ s < n; ++s)\n  if (!adj[s].size()) ret.add_edge(ret.add_vertex(), s);\n return\
    \ ret;\n}\nGraph block_cut_tree(const Graph &g) { return block_cut_tree(g.adjacency_vertex(0));\
    \ }\n"
  code: "#pragma once\n#include \"src/Graph/Graph.hpp\"\n// [0,n) : vertex\n// [n,n+b)\
    \ : block\n// deg(v) > 1 -> articulation point\nGraph block_cut_tree(const CSRArray<int>\
    \ &adj) {\n const int n= adj.size();\n std::vector<int> ord(n), par(n, -2), dat(adj.p.begin(),\
    \ adj.p.begin() + n);\n int k= 0;\n for (int s= n, p; s--;)\n  if (par[s] == -2)\n\
    \   for (par[p= s]= -1; p >= 0;) {\n    if (dat[p] == adj.p[p]) ord[k++]= p;\n\
    \    if (dat[p] == adj.p[p + 1]) p= par[p];\n    else if (int q= adj.dat[dat[p]++];\
    \ par[q] == -2) par[q]= p, p= q;\n   }\n for (int i= n; i--;) dat[ord[i]]= i;\n\
    \ auto low= dat;\n for (int v= n; v--;)\n  for (int u: adj[v]) low[v]= std::min(low[v],\
    \ dat[u]);\n for (int i= n; i--;)\n  if (int p= ord[i], pp= par[p]; pp >= 0) low[pp]=\
    \ std::min(low[pp], low[p]);\n Graph ret(k);\n for (int p: ord)\n  if (par[p]\
    \ >= 0) {\n   if (int pp= par[p]; low[p] < dat[pp]) ret.add_edge(low[p]= low[pp],\
    \ p);\n   else ret.add_vertex(), ret.add_edge(k, pp), ret.add_edge(k, p), low[p]=\
    \ k++;\n  }\n for (int s= 0; s < n; ++s)\n  if (!adj[s].size()) ret.add_edge(ret.add_vertex(),\
    \ s);\n return ret;\n}\nGraph block_cut_tree(const Graph &g) { return block_cut_tree(g.adjacency_vertex(0));\
    \ }"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/block_cut_tree.hpp
  requiredBy: []
  timestamp: '2024-02-19 15:31:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1326.test.cpp
  - test/yosupo/biconnected_components.test.cpp
  - test/aoj/3022.test.cpp
  - test/aoj/GRL_3_A.test.cpp
  - test/hackerrank/bonnie-and-clyde.test.cpp
documentation_of: src/Graph/block_cut_tree.hpp
layout: document
title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (block-cut-tree (\u62E1\u5F35\
  ))"
---
![bct.svg](https://github.com/hashiryo/Library/blob/master/img/bct.drawio.svg?raw=true)

|関数名|概要|計算量|
|---|---|---|
|`block_cut_tree(CSRArray<int> adj)` <br> `block_cut_tree(Graph g)` |無向グラフ g を二点連結成分分解して構築した block-cut-tree (拡張) を返す. <br> 引数は頂点 → 頂点の隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp)) もしくは [`Graph`クラス](Graph.hpp) で無向グラフを渡す.　<br> 返り値は `Graph` クラス．|$O(V+E)$ |


### block-cut-tree (拡張) について
[参考](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)

頂点数 $N$ の無向グラフ $g$ の二点連結成分の個数を $C$ とする.\
block-cut-tree (拡張) は頂点数が $N+C$ の森である. 
- $N$ 個の頂点 $0,1,\dots,N-1$ は元のグラフ $g$ の頂点に対応.
  - 隣接頂点は属する二点連結成分を指す.
  - 隣接頂点が複数  $(>1)\rightarrow$ 関節点
- $C$ 個の頂点 $N,N+1,\dots,N+C-1$ は $g$ の二点連結成分に対応.
  - 隣接頂点はその二点連結成分を構成する頂点を指す.

## 問題例
[AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)
## 参考
[https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)\
[https://nachiavivias.github.io/cp-library/column/2022/01.html](https://nachiavivias.github.io/cp-library/column/2022/01.html)