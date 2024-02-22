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
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Graph/DulmageMendelsohn.hpp
    title: "Dulmage-Mendelsohn \u5206\u89E3"
  - icon: ':x:'
    path: src/Graph/bipartite_edge_coloring.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0334.test.cpp
    title: test/aoj/0334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3168.bm.test.cpp
    title: test/aoj/3168.bm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3198.test.cpp
    title: test/aoj/3198.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc223_g.dm.test.cpp
    title: test/atcoder/abc223_g.dm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc282_d.test.cpp
    title: test/atcoder/abc282_d.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc327_d.test.cpp
    title: test/atcoder/abc327_d.test.cpp
  - icon: ':x:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  - icon: ':x:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  - icon: ':x:'
    path: test/yukicoder/421.test.cpp
    title: test/yukicoder/421.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/BipartiteGraph.hpp\"\n#include <cassert>\n#include\
    \ <tuple>\n#include <algorithm>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include\
    \ <vector>\n#include <iostream>\n#include <iterator>\n#include <type_traits>\n\
    #define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using Iterator=\
    \ typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const\
    \ { return bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size()\
    \ const { return std::distance(bg, ed); } \\\n  CT &operator[](int i) const {\
    \ return bg[i]; } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange, const_iterator,\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 6 \"src/Graph/BipartiteGraph.hpp\"\
    \n// [0, L) is left, [L, n) is right\nstruct BipartiteGraph: Graph {\n size_t\
    \ L;\n BipartiteGraph() {}\n BipartiteGraph(size_t L, size_t R, size_t m= 0):\
    \ Graph(L + R, m), L(L) {}\n size_t left_size() const { return L; }\n size_t right_size()\
    \ const { return this->n - L; }\n};\nstd::vector<int> paint_two_colors(const CSRArray<int>\
    \ &adj) {\n const int n= adj.size();\n std::vector<int> col(n, -1);\n for (int\
    \ s= n; s--;)\n  if (col[s] == -1) {\n   std::vector<int> q= {s};\n   for (int\
    \ i= col[s]= 0, v; i < (int)q.size(); ++i)\n    for (int u: adj[v= q[i]])\n  \
    \   if (int c= col[v]; col[u] == c) return {};\n     else if (col[u] == -1) col[u]=\
    \ c ^ 1, q.push_back(u);\n  }\n return col;\n}\nstd::vector<int> paint_two_colors(const\
    \ Graph &g) { return paint_two_colors(g.adjacency_vertex(0)); }\n// { BipartiteGraph\
    \ , original to new, new to original }\n// {{},{},{}} if not bipartite\nstd::tuple<BipartiteGraph,\
    \ std::vector<int>, std::vector<int>> graph_to_bipartite(const Graph &g, std::vector<int>\
    \ color= {}) {\n if (color.empty()) color= paint_two_colors(g);\n if (color.empty())\
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
    \ std::vector<int>> bipartite_matching(const BipartiteGraph &bg, std::vector<int>\
    \ partner= {}) {\n const int L= bg.left_size(), M= bg.edge_size();\n if (partner.empty())\
    \ partner.assign(bg.vertex_size(), -1);\n assert(partner.size() == bg.vertex_size());\n\
    \ {\n  CSRArray<int> adj{std::vector<int>(M), std::vector<int>(L + 1)};\n  for\
    \ (auto [l, r]: bg) ++adj.p[l];\n  for (int i= 0; i < L; ++i) adj.p[i + 1]+= adj.p[i];\n\
    \  for (auto [l, r]: bg) adj.dat[--adj.p[l]]= r;\n  if constexpr (lexical) {\n\
    \   for (int l= L; l--;) std::sort(adj[l].begin(), adj[l].end());\n   _bg_internal::_bm(L,\
    \ adj, partner);\n   std::vector<char> a(L, 1);\n   for (int l= 0; l < L; ++l)\n\
    \    if (int r= partner[l], v= l; r != -1) {\n     std::vector<int> p(L, partner[v]=\
    \ partner[r]= -1), c(adj.p.begin(), adj.p.begin() + L);\n     for (p[v]= -2;;)\
    \ {\n      if (c[v] == adj.p[v + 1]) v= p[v];\n      else if (int u= partner[r=\
    \ adj.dat[c[v]++]]; u == -1) {\n       for (; r != -1; v= p[v]) partner[r]= v,\
    \ std::swap(partner[v], r);\n       break;\n      } else if (a[u] && p[u] == -1)\
    \ p[u]= v, v= u;\n     }\n     a[l]= 0;\n    }\n  } else _bg_internal::_bm(L,\
    \ adj, partner);\n }\n std::vector<int> c;\n std::vector<char> p(L);\n for (int\
    \ i= 0; i < M; ++i)\n  if (auto [l, r]= bg[i]; partner[l] == r && !p[l]) c.push_back(i),\
    \ p[l]= 1;\n return {c, partner};\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <tuple>\n#include <algorithm>\n\
    #include \"src/Graph/Graph.hpp\"\n// [0, L) is left, [L, n) is right\nstruct BipartiteGraph:\
    \ Graph {\n size_t L;\n BipartiteGraph() {}\n BipartiteGraph(size_t L, size_t\
    \ R, size_t m= 0): Graph(L + R, m), L(L) {}\n size_t left_size() const { return\
    \ L; }\n size_t right_size() const { return this->n - L; }\n};\nstd::vector<int>\
    \ paint_two_colors(const CSRArray<int> &adj) {\n const int n= adj.size();\n std::vector<int>\
    \ col(n, -1);\n for (int s= n; s--;)\n  if (col[s] == -1) {\n   std::vector<int>\
    \ q= {s};\n   for (int i= col[s]= 0, v; i < (int)q.size(); ++i)\n    for (int\
    \ u: adj[v= q[i]])\n     if (int c= col[v]; col[u] == c) return {};\n     else\
    \ if (col[u] == -1) col[u]= c ^ 1, q.push_back(u);\n  }\n return col;\n}\nstd::vector<int>\
    \ paint_two_colors(const Graph &g) { return paint_two_colors(g.adjacency_vertex(0));\
    \ }\n// { BipartiteGraph , original to new, new to original }\n// {{},{},{}} if\
    \ not bipartite\nstd::tuple<BipartiteGraph, std::vector<int>, std::vector<int>>\
    \ graph_to_bipartite(const Graph &g, std::vector<int> color= {}) {\n if (color.empty())\
    \ color= paint_two_colors(g);\n if (color.empty()) return {};\n const int n= g.vertex_size(),\
    \ m= g.edge_size();\n std::vector<int> a(n), b(n);\n int l= 0, r= n;\n for (int\
    \ i= n; i--;) b[a[i]= color[i] ? --r : l++]= i;\n BipartiteGraph bg(l, n - l,\
    \ m);\n for (int i= m; i--;) {\n  auto [u, v]= g[i];\n  bg[i]= std::minmax(a[u],\
    \ a[v]);\n }\n return {bg, a, b};\n}\nnamespace _bg_internal {\nstd::vector<int>\
    \ _bm(int L, const CSRArray<int> &adj, std::vector<int> &m) {\n std::vector<int>\
    \ a, p, q(L);\n for (bool u= true; u;) {\n  u= false, a.assign(L, -1), p.assign(L,\
    \ -1);\n  int t= 0;\n  for (int l= L; l--;)\n   if (m[l] == -1) q[t++]= a[l]=\
    \ p[l]= l;\n  for (int i= 0; i < t; ++i)\n   if (int l= q[i], x; m[a[l]] == -1)\n\
    \    for (int r: adj[l]) {\n     if (x= m[r]; x == -1) {\n      for (u= true;\
    \ r != -1; l= p[l]) m[r]= l, std::swap(m[l], r);\n      break;\n     }\n     if\
    \ (p[x] == -1) a[q[t++]= x]= a[p[x]= l];\n    }\n }\n return a;\n}\n}\ntemplate\
    \ <bool lexical= false> std::pair<std::vector<int>, std::vector<int>> bipartite_matching(const\
    \ BipartiteGraph &bg, std::vector<int> partner= {}) {\n const int L= bg.left_size(),\
    \ M= bg.edge_size();\n if (partner.empty()) partner.assign(bg.vertex_size(), -1);\n\
    \ assert(partner.size() == bg.vertex_size());\n {\n  CSRArray<int> adj{std::vector<int>(M),\
    \ std::vector<int>(L + 1)};\n  for (auto [l, r]: bg) ++adj.p[l];\n  for (int i=\
    \ 0; i < L; ++i) adj.p[i + 1]+= adj.p[i];\n  for (auto [l, r]: bg) adj.dat[--adj.p[l]]=\
    \ r;\n  if constexpr (lexical) {\n   for (int l= L; l--;) std::sort(adj[l].begin(),\
    \ adj[l].end());\n   _bg_internal::_bm(L, adj, partner);\n   std::vector<char>\
    \ a(L, 1);\n   for (int l= 0; l < L; ++l)\n    if (int r= partner[l], v= l; r\
    \ != -1) {\n     std::vector<int> p(L, partner[v]= partner[r]= -1), c(adj.p.begin(),\
    \ adj.p.begin() + L);\n     for (p[v]= -2;;) {\n      if (c[v] == adj.p[v + 1])\
    \ v= p[v];\n      else if (int u= partner[r= adj.dat[c[v]++]]; u == -1) {\n  \
    \     for (; r != -1; v= p[v]) partner[r]= v, std::swap(partner[v], r);\n    \
    \   break;\n      } else if (a[u] && p[u] == -1) p[u]= v, v= u;\n     }\n    \
    \ a[l]= 0;\n    }\n  } else _bg_internal::_bm(L, adj, partner);\n }\n std::vector<int>\
    \ c;\n std::vector<char> p(L);\n for (int i= 0; i < M; ++i)\n  if (auto [l, r]=\
    \ bg[i]; partner[l] == r && !p[l]) c.push_back(i), p[l]= 1;\n return {c, partner};\n\
    }"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/BipartiteGraph.hpp
  requiredBy:
  - src/Graph/bipartite_edge_coloring.hpp
  - src/Graph/DulmageMendelsohn.hpp
  timestamp: '2024-02-20 00:09:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1745.test.cpp
  - test/yukicoder/421.test.cpp
  - test/yosupo/bipartitematching.test.cpp
  - test/yosupo/bipartite_edge_coloring.test.cpp
  - test/aoj/3198.test.cpp
  - test/aoj/3168.bm.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/0334.test.cpp
  - test/atcoder/abc282_d.test.cpp
  - test/atcoder/abc327_d.test.cpp
  - test/atcoder/abc223_g.dm.test.cpp
documentation_of: src/Graph/BipartiteGraph.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5"
---

## `BipartiteGraph` クラス

[`Graph` クラス](Graph.hpp)　を継承．\
左右の頂点の数をそれぞれ $L$, $R$ として
- 左側の頂点を $0,1,\dots,L-1$
- 右側の頂点を $L, L+1,\dots,L+R-1$

とする. (何かと都合がいいため)

また辺の向きは常に左から右を向くようにする．（手動でする）

二部マッチングなどの関数の引数に使用する．ただの箱

|メンバ関数|概要|
|---|---|
|`left_size()`|左側の頂点の数 $L$ を返す|
|`right_size()`|右側の頂点の数 $R$ を返す|



## 関数

|関数|概要|計算量|
|---|---|---|
|`paint_two_colors(adj)`<br> `paint_two_colors(g)`|グラフを2色で塗り分ける．<br> 引数は頂点 → 頂点の隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp)) もしくは [`Graph`クラス](Graph.hpp) で無向グラフを渡す. <br> 戻り値は頂点サイズの `vector<int>` で各頂点の色の割り当てを表す. <br> 二部グラフでない場合，空集合を返す．|$O(V+E)$|
|`graph_to_bipartite(g,color={})`|[`Graph` クラス](Graph.hpp)を頂点を2色に塗り分けてラベルを付け直して `BipartiteGraph` クラスにする. <br> 頂点のラベルを付け替えるだけのため，辺の順番は保たれている． <br> 引数は `Graph` クラスと色の割り当てが記録された `vector<int>`．<br> 第二引数は省略可能. <br> 戻り値は3つの要素を `tuple` でラッピングしたものを返す. <br> 一つ目は `BipartiteGraph`．<br> 二つ目は元のグラフの頂点番号から新しい番号を返す `vector<int>`．<br> 三つ目は新しいグラフの頂点番号から元のグラフの番号を返す `vector<int>`．<br> 二部グラフでない場合，空集合らを返す． |$O(V+E)$|
|`bipartite_matching<lexical=false>(bg)`|二部グラフの最大マッチングを実行する. <br> 引数は `BipartiteGraph`．戻り値は2つの要素を `pair` でラッピングしたものを返す．<br> 一つ目は最大マッチングに使われる辺の番号の集合を表す `vector<int>`．<br> 二つ目は各頂点のマッチング相手が記録 (noマッチなら -1) されている `vector<int>` ．<br> またテンプレート引数が `true` の場合，左側の頂点を順に並べた場合のマッチング相手が辞書順になるようにする．|1. $O(E\sqrt{V})$ <br> 2. テンプレート引数が `true` の場合 <br> $O(EV)$ |


二部グラフの最小頂点被覆は [Dulmage-Mendelsohn 分解](DulmageMendelsohn.hpp) で実装．

## 問題例
[CODE FESTIVAL 2017 qual B C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c) (二部グラフ塗り分け)\
[アルゴリズムと数学　演習問題集 047 - Bipartite Graph](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao) (二部グラフ判定)\
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (二部マッチング, 頂点:2e5+4e5, 辺:4e5)