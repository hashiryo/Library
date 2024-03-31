---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: test/aoj/3168.bm.test.cpp
    title: test/aoj/3168.bm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc223_g.dm.test.cpp
    title: test/atcoder/abc223_g.dm.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/DulmageMendelsohn.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#line 2 \"src/Graph/BipartiteGraph.hpp\"\n#include <cassert>\n\
    #include <tuple>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
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
    \ p[l]= 1;\n return {c, partner};\n}\n#line 5 \"src/Graph/DulmageMendelsohn.hpp\"\
    \nclass DulmageMendelsohn {\n int L;\n std::vector<int> b, m, a;\n CSRArray<int>\
    \ dag[2];\npublic:\n DulmageMendelsohn(const BipartiteGraph &bg): L(bg.left_size())\
    \ {\n  auto adj= bg.adjacency_vertex(0);\n  const int n= adj.size();\n  m.assign(n,\
    \ -1), b.assign(n, -3), a= _bg_internal::_bm(L, adj, m);\n  std::vector<int> q(n\
    \ - L);\n  int t= 0, k= 0;\n  for (int l= L; l--;)\n   if (a[l] != -1)\n    if\
    \ (b[l]= -1; m[l] != -1) b[m[l]]= -1;\n  for (int r= n; r-- > L;)\n   if (m[r]\
    \ == -1) b[q[t++]= r]= 0;\n  for (int i= 0, r, w; i < t; ++i)\n   for (int l:\
    \ adj[r= q[i]])\n    if (b[l] == -3)\n     if (b[l]= 0, w= m[l]; w != -1 && b[w]\
    \ == -3) b[q[t++]= w]= 0;\n  t= 0;\n  {\n   std::vector<int> c(adj.p.begin(),\
    \ adj.p.begin() + L);\n   for (int l= L; l--;)\n    if (int v= l; b[v] == -3)\n\
    \     for (b[v]= -2; v >= 0;) {\n      if (c[v] == adj.p[v + 1]) a[t++]= v, v=\
    \ b[v];\n      else if (int w= m[adj.dat[c[v]++]]; b[w] == -3) b[w]= v, v= w;\n\
    \     }\n  }\n  for (int i= 0, e= 0, r; t--;)\n   if (int s= a[t], p= m[s]; b[p]\
    \ == -3)\n    for (b[q[e++]= p]= b[s]= ++k; i < e; ++i)\n     for (int l: adj[r=\
    \ q[i]])\n      if (b[m[l]] == -3) b[q[e++]= m[l]]= b[l]= k;\n  ++k;\n  for (int\
    \ l= L; l--;)\n   if (b[l] == -1)\n    if (b[l]= k; m[l] != -1) b[m[l]]= k;\n\
    \  a.assign(k + 2, 0);\n  for (int i= n; i--;) ++a[b[i]];\n  for (int i= 0; i\
    \ <= k; ++i) a[i + 1]+= a[i];\n  for (int i= n; i--;) m[--a[b[i]]]= i;\n  Graph\
    \ h(k + 1);\n  for (auto [l, r]: bg)\n   if (b[l] != b[r]) h.add_edge(b[l], b[r]);\n\
    \  std::sort(h.begin(), h.end()), h.erase(std::unique(h.begin(), h.end()), h.end()),\
    \ dag[0]= h.adjacency_vertex(1), dag[1]= h.adjacency_vertex(-1);\n }\n size_t\
    \ size() const { return a.size() - 1; }\n ConstListRange<int> block(int k) const\
    \ { return {m.cbegin() + a[k], m.cbegin() + a[k + 1]}; }\n int operator()(int\
    \ i) const { return b[i]; }\n std::vector<int> min_vertex_cover(std::vector<int>\
    \ ord= {}) const {\n  if (ord.empty()) ord.resize(b.size()), std::iota(ord.begin(),\
    \ ord.end(), 0);\n  std::vector<char> z(size(), -1);\n  std::vector<int> q(size()),\
    \ vc;\n  z[0]= 1, z.back()= 0;\n  for (int v: ord) {\n   int c= (v >= L), k= b[v],\
    \ s= z[k];\n   if (s == -1) {\n    auto &adj= dag[z[q[0]= k]= s= !c];\n    for\
    \ (int i= 0, t= 1; i < t; ++i)\n     for (int u: adj[q[i]])\n      if (z[u] ==\
    \ -1) z[u]= s, q[t++]= u;\n   }\n   if (c ^ s) vc.push_back(v);\n  }\n  return\
    \ vc;\n }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include \"src/Graph/BipartiteGraph.hpp\"\
    \nclass DulmageMendelsohn {\n int L;\n std::vector<int> b, m, a;\n CSRArray<int>\
    \ dag[2];\npublic:\n DulmageMendelsohn(const BipartiteGraph &bg): L(bg.left_size())\
    \ {\n  auto adj= bg.adjacency_vertex(0);\n  const int n= adj.size();\n  m.assign(n,\
    \ -1), b.assign(n, -3), a= _bg_internal::_bm(L, adj, m);\n  std::vector<int> q(n\
    \ - L);\n  int t= 0, k= 0;\n  for (int l= L; l--;)\n   if (a[l] != -1)\n    if\
    \ (b[l]= -1; m[l] != -1) b[m[l]]= -1;\n  for (int r= n; r-- > L;)\n   if (m[r]\
    \ == -1) b[q[t++]= r]= 0;\n  for (int i= 0, r, w; i < t; ++i)\n   for (int l:\
    \ adj[r= q[i]])\n    if (b[l] == -3)\n     if (b[l]= 0, w= m[l]; w != -1 && b[w]\
    \ == -3) b[q[t++]= w]= 0;\n  t= 0;\n  {\n   std::vector<int> c(adj.p.begin(),\
    \ adj.p.begin() + L);\n   for (int l= L; l--;)\n    if (int v= l; b[v] == -3)\n\
    \     for (b[v]= -2; v >= 0;) {\n      if (c[v] == adj.p[v + 1]) a[t++]= v, v=\
    \ b[v];\n      else if (int w= m[adj.dat[c[v]++]]; b[w] == -3) b[w]= v, v= w;\n\
    \     }\n  }\n  for (int i= 0, e= 0, r; t--;)\n   if (int s= a[t], p= m[s]; b[p]\
    \ == -3)\n    for (b[q[e++]= p]= b[s]= ++k; i < e; ++i)\n     for (int l: adj[r=\
    \ q[i]])\n      if (b[m[l]] == -3) b[q[e++]= m[l]]= b[l]= k;\n  ++k;\n  for (int\
    \ l= L; l--;)\n   if (b[l] == -1)\n    if (b[l]= k; m[l] != -1) b[m[l]]= k;\n\
    \  a.assign(k + 2, 0);\n  for (int i= n; i--;) ++a[b[i]];\n  for (int i= 0; i\
    \ <= k; ++i) a[i + 1]+= a[i];\n  for (int i= n; i--;) m[--a[b[i]]]= i;\n  Graph\
    \ h(k + 1);\n  for (auto [l, r]: bg)\n   if (b[l] != b[r]) h.add_edge(b[l], b[r]);\n\
    \  std::sort(h.begin(), h.end()), h.erase(std::unique(h.begin(), h.end()), h.end()),\
    \ dag[0]= h.adjacency_vertex(1), dag[1]= h.adjacency_vertex(-1);\n }\n size_t\
    \ size() const { return a.size() - 1; }\n ConstListRange<int> block(int k) const\
    \ { return {m.cbegin() + a[k], m.cbegin() + a[k + 1]}; }\n int operator()(int\
    \ i) const { return b[i]; }\n std::vector<int> min_vertex_cover(std::vector<int>\
    \ ord= {}) const {\n  if (ord.empty()) ord.resize(b.size()), std::iota(ord.begin(),\
    \ ord.end(), 0);\n  std::vector<char> z(size(), -1);\n  std::vector<int> q(size()),\
    \ vc;\n  z[0]= 1, z.back()= 0;\n  for (int v: ord) {\n   int c= (v >= L), k= b[v],\
    \ s= z[k];\n   if (s == -1) {\n    auto &adj= dag[z[q[0]= k]= s= !c];\n    for\
    \ (int i= 0, t= 1; i < t; ++i)\n     for (int u: adj[q[i]])\n      if (z[u] ==\
    \ -1) z[u]= s, q[t++]= u;\n   }\n   if (c ^ s) vc.push_back(v);\n  }\n  return\
    \ vc;\n }\n};"
  dependsOn:
  - src/Graph/BipartiteGraph.hpp
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/DulmageMendelsohn.hpp
  requiredBy: []
  timestamp: '2024-02-22 13:37:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1745.test.cpp
  - test/atcoder/abc223_g.dm.test.cpp
  - test/aoj/3168.bm.test.cpp
documentation_of: src/Graph/DulmageMendelsohn.hpp
layout: document
title: "Dulmage-Mendelsohn \u5206\u89E3"
---

## `DulmageMendelsohn` クラス

二部グラフを Dulmage-Mendelsohn 分解によって
K+1 個 の集合(0~K) に分割する．
- 左側の頂点： 0~K-1番目のいずれかの集合に属する $\iff$ マッチングに必ず使う
- 右側の頂点： 1~K番目のいずれかの集合に属する $\iff$ マッチングに必ず使う
- 左側の頂点lがa番目の集合, 右側の頂点rがb番目の集合に属する: 辺(l,r)が存在 $\implies$ a $\le$ b
  - 即ち DAG

|メンバ関数|概要|計算量|
|---|---|---|
|`DulmageMendelsohn(bg)`|コンストラクタ. <br> 引数は [`BipartiteGraph` クラス](BipartiteGraph.hpp)．| $O(E\sqrt{V})$|
|`size()`|分割された集合の個数(K+1)を返す．||
|`block(k)`| k 番目の集合を返す．<br> 頂点は昇順にソートされている．<br>(ので，ある区切りを境に左側頂点と右側頂点に分かれている)||
|`operator()(i)`|頂点 i の所属する集合が何番目かを返す．||
|`min_vertex_cover(ord={})`|最小頂点被覆を返す．<br> 引数は優先度で並んだ順列で，この順に貪欲に実行．<br> 引数を指定しない場合，頂点番号の低い順で実行．<br>（つまり左側の点が優先される）<br> 戻り値は `vector<int>` で最小頂点被覆に使う頂点の集合を表す．| $O(E+V)$|


## 問題例
[東京大学プログラミングコンテスト2013 K - 辞書順最小頂点被覆](https://atcoder.jp/contests/utpc2013/tasks/utpc2013_11) (辞書順最小頂点被覆のverify)\
[HackerRank Drawing Rectangles](https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles) (最小頂点被覆, 頂点:3e5+3e5, 辺:3e5)