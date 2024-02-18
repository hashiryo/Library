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
    path: test/aoj/3506.test.cpp
    title: test/aoj/3506.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1170.test.cpp
    title: test/yukicoder/1170.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1868.test.cpp
    title: test/yukicoder/1868.test.cpp
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
    \ iterator, const T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\n\
    template <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int>\
    \ p;\n size_t size() const { return p.size() - 1; }\n ListRange<T> operator[](int\
    \ i) { return {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T>\
    \ operator[](int i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i +\
    \ 1]}; }\n};\ntemplate <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
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
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 3 \"src/Graph/RangeToRangeGraph.hpp\"\
    \ntemplate <typename cost_t= int> class RangeToRangeGraph {\n int n;\n inline\
    \ int to_upper_idx(int i) const { return i >= n ? i - n : n + i; }\n inline int\
    \ to_lower_idx(int i) const { return i >= n ? i - n : n + n + i; }\npublic:\n\
    \ Graph graph;\n std::vector<cost_t> weight;\n RangeToRangeGraph(int n): n(n),\
    \ graph(n * 3) {\n  for (int i= 2; i < n + n; ++i) add(to_upper_idx(i / 2), to_upper_idx(i));\n\
    \  for (int i= 2; i < n + n; ++i) add(to_lower_idx(i), to_lower_idx(i / 2));\n\
    \ }\n void add(int s, int t, cost_t w= 0) { graph.add_edge(s, t), weight.emplace_back(w);\
    \ }\n // [s_l, s_r) -> t\n void add_from_range(int s_l, int s_r, int t, cost_t\
    \ w= 0) {\n  for (int l= s_l + n, r= s_r + n; l < r; l>>= 1, r>>= 1) {\n   if\
    \ (l & 1) add(to_lower_idx(l++), t, w);\n   if (r & 1) add(to_lower_idx(--r),\
    \ t, w);\n  }\n }\n // s -> [t_l, t_r)\n void add_to_range(int s, int t_l, int\
    \ t_r, cost_t w= 0) {\n  for (int l= t_l + n, r= t_r + n; l < r; l>>= 1, r>>=\
    \ 1) {\n   if (l & 1) add(s, to_upper_idx(l++), w);\n   if (r & 1) add(s, to_upper_idx(--r),\
    \ w);\n  }\n }\n // [s_l, s_r) -> [t_l, t_r)\n void add_from_range_to_range(int\
    \ s_l, int s_r, int t_l, int t_r, cost_t w= 0) { add_from_range(s_l, s_r, graph.n,\
    \ w), add_to_range(graph.n, t_l, t_r, 0), ++graph.n; }\n};\n"
  code: "#pragma once\n#include \"src/Graph/Graph.hpp\"\ntemplate <typename cost_t=\
    \ int> class RangeToRangeGraph {\n int n;\n inline int to_upper_idx(int i) const\
    \ { return i >= n ? i - n : n + i; }\n inline int to_lower_idx(int i) const {\
    \ return i >= n ? i - n : n + n + i; }\npublic:\n Graph graph;\n std::vector<cost_t>\
    \ weight;\n RangeToRangeGraph(int n): n(n), graph(n * 3) {\n  for (int i= 2; i\
    \ < n + n; ++i) add(to_upper_idx(i / 2), to_upper_idx(i));\n  for (int i= 2; i\
    \ < n + n; ++i) add(to_lower_idx(i), to_lower_idx(i / 2));\n }\n void add(int\
    \ s, int t, cost_t w= 0) { graph.add_edge(s, t), weight.emplace_back(w); }\n //\
    \ [s_l, s_r) -> t\n void add_from_range(int s_l, int s_r, int t, cost_t w= 0)\
    \ {\n  for (int l= s_l + n, r= s_r + n; l < r; l>>= 1, r>>= 1) {\n   if (l & 1)\
    \ add(to_lower_idx(l++), t, w);\n   if (r & 1) add(to_lower_idx(--r), t, w);\n\
    \  }\n }\n // s -> [t_l, t_r)\n void add_to_range(int s, int t_l, int t_r, cost_t\
    \ w= 0) {\n  for (int l= t_l + n, r= t_r + n; l < r; l>>= 1, r>>= 1) {\n   if\
    \ (l & 1) add(s, to_upper_idx(l++), w);\n   if (r & 1) add(s, to_upper_idx(--r),\
    \ w);\n  }\n }\n // [s_l, s_r) -> [t_l, t_r)\n void add_from_range_to_range(int\
    \ s_l, int s_r, int t_l, int t_r, cost_t w= 0) { add_from_range(s_l, s_r, graph.n,\
    \ w), add_to_range(graph.n, t_l, t_r, 0), ++graph.n; }\n};"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/RangeToRangeGraph.hpp
  requiredBy: []
  timestamp: '2024-02-19 02:01:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1868.test.cpp
  - test/yukicoder/1170.test.cpp
  - test/aoj/3506.test.cpp
documentation_of: src/Graph/RangeToRangeGraph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---

## `RangeToRangeGraph<cost_t=int>` クラス

|メンバ変数|概要|
|---|---|
|`graph`|区間に辺を張るテクによって構築された有向グラフ．<br> [`Graph` クラス](Graph.hpp)|
|`weight`|区間に辺を張るテクによって構築された有向グラフの辺の重み．<br> `vector<cost_t>`|


|メンバ関数|概要|計算量|
|---|---|---|
|`RangeToRangeGraph(n)`|コンストラクタ．区間の長さ $n$ を渡す．||
|`add(s,t,w=0)`|点 $s$ から 点 $t$ へ重み $w$ の有向辺を張る．|$O(1)$|
|`add_from_range(s_l,s_r,t,w=0)`|区間 $\lbrack s_l, s_r)$ から点 $t$ へ重み $w$ の有向辺を張る．|$O(\log n)$|
|`add_to_range(s,t_l,t_r,w=0)`|点 $s$ から区間 $\lbrack t_l, t_r)$ へ重み $w$ の有向辺を張る．|$O(\log n)$|
|`add_from_range_to_range(s_l,s_r,t_l,t_r,w=0)`|区間 $\lbrack s_l, s_r)$ から区間 $\lbrack t_l, t_r)$ へ重み $w$ の有向辺を張る．|$O(\log n)$|


## 問題例
[第二回全国統一プログラミング王決定戦予選 D - Shortest Path on a Line](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d) \
[灘校文化祭コンテスト 2022 Day1 I - NPCA Kingdom](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_i)
## 参考
[https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)