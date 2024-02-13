---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Graph/FunctionalGraph.hpp
    title: "Functional\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':question:'
    path: src/Graph/Rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595.test.cpp
    title: test/aoj/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc136_d.test.cpp
    title: test/atcoder/abc136_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc160_f.test.cpp
    title: test/atcoder/abc160_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc167_d.test.cpp
    title: test/atcoder/abc167_d.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_e.test.cpp
    title: test/atcoder/abc179_e.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc220_f.test.cpp
    title: test/atcoder/abc220_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc222_f.test.cpp
    title: test/atcoder/abc222_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc223_g.rerooting.test.cpp
    title: test/atcoder/abc223_g.rerooting.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc241_e.test.cpp
    title: test/atcoder/abc241_e.test.cpp
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
  - icon: ':x:'
    path: test/yukicoder/1211.test.cpp
    title: test/yukicoder/1211.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1295.test.cpp
    title: test/yukicoder/1295.test.cpp
  - icon: ':x:'
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
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
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
  bundledCode: "#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <iterator>\ntemplate <class T> struct ListRange {\n using\
    \ Iterator= typename std::vector<T>::iterator;\n Iterator bg, ed;\n Iterator begin()\
    \ const { return bg; }\n Iterator end() const { return ed; }\n size_t size() const\
    \ { return std::distance(bg, ed); }\n T &operator[](int i) const { return bg[i];\
    \ }\n friend std::ostream &operator<<(std::ostream &os, const ListRange &r) {\n\
    \  os << '[';\n  for (int i= 0, e= r.size(); i < e; ++i) os << (i ? \", \" : \"\
    \") << r[i];\n  return os << ']';\n }\n};\ntemplate <class T> struct ConstListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n friend std::ostream &operator<<(std::ostream &os,\
    \ const ConstListRange &r) {\n  os << '[';\n  for (int i= 0, e= r.size(); i <\
    \ e; ++i) os << (i ? \", \" : \"\") << r[i];\n  return os << ']';\n }\n};\n#line\
    \ 3 \"src/Graph/Graph.hpp\"\nstruct Edge {\n int s, d;\n Edge(int s= 0, int d=\
    \ 0): s(s), d(d) {}\n Edge &operator--() { return --s, --d, *this; }\n int operator-(int\
    \ v) const { return s ^ d ^ v; }\n friend std::istream &operator>>(std::istream\
    \ &is, Edge &e) { return is >> e.s >> e.d, is; }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge &e) { return os << '(' << e.s << \", \" << e.d << ')'; }\n};\n\
    struct Graph: public std::vector<Edge> {\n std::vector<int> c, p;\n using std::vector<Edge>::vector;\n\
    \ void build(int n, bool direct) {\n  if (p.assign(n + 1, 0), c.resize(size()\
    \ << !direct); direct) {\n   for (auto [u, v]: *this) ++p[u];\n   for (int i=\
    \ 0; i < n; ++i) p[i + 1]+= p[i];\n   for (int i= size(); i--;) c[--p[(*this)[i].s]]=\
    \ i;\n  } else {\n   for (auto [u, v]: *this) ++p[u], ++p[v];\n   for (int i=\
    \ 0; i < n; ++i) p[i + 1]+= p[i];\n   for (int i= size(); i--;) c[--p[(*this)[i].s]]=\
    \ i, c[--p[(*this)[i].d]]= i;\n  }\n }\n size_t edge_size() const { return size();\
    \ }\n size_t vertex_size() const { return p.size() - 1; }\n ListRange<int> operator()(int\
    \ u) { return {c.begin() + p[u], c.begin() + p[u + 1]}; }\n ConstListRange<int>\
    \ operator()(int u) const { return {c.cbegin() + p[u], c.cbegin() + p[u + 1]};\
    \ }\n};\n"
  code: "#pragma once\n#include \"src/Internal/ListRange.hpp\"\nstruct Edge {\n int\
    \ s, d;\n Edge(int s= 0, int d= 0): s(s), d(d) {}\n Edge &operator--() { return\
    \ --s, --d, *this; }\n int operator-(int v) const { return s ^ d ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.s >> e.d,\
    \ is; }\n friend std::ostream &operator<<(std::ostream &os, const Edge &e) { return\
    \ os << '(' << e.s << \", \" << e.d << ')'; }\n};\nstruct Graph: public std::vector<Edge>\
    \ {\n std::vector<int> c, p;\n using std::vector<Edge>::vector;\n void build(int\
    \ n, bool direct) {\n  if (p.assign(n + 1, 0), c.resize(size() << !direct); direct)\
    \ {\n   for (auto [u, v]: *this) ++p[u];\n   for (int i= 0; i < n; ++i) p[i +\
    \ 1]+= p[i];\n   for (int i= size(); i--;) c[--p[(*this)[i].s]]= i;\n  } else\
    \ {\n   for (auto [u, v]: *this) ++p[u], ++p[v];\n   for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i];\n   for (int i= size(); i--;) c[--p[(*this)[i].s]]= i, c[--p[(*this)[i].d]]=\
    \ i;\n  }\n }\n size_t edge_size() const { return size(); }\n size_t vertex_size()\
    \ const { return p.size() - 1; }\n ListRange<int> operator()(int u) { return {c.begin()\
    \ + p[u], c.begin() + p[u + 1]}; }\n ConstListRange<int> operator()(int u) const\
    \ { return {c.cbegin() + p[u], c.cbegin() + p[u + 1]}; }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/Graph.hpp
  requiredBy:
  - src/Graph/Rerooting.hpp
  - src/Graph/FunctionalGraph.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  timestamp: '2024-02-13 11:50:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1494.test.cpp
  - test/yukicoder/1211.test.cpp
  - test/yukicoder/1976.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/1333.test.cpp
  - test/yukicoder/1124.test.cpp
  - test/yukicoder/1418.test.cpp
  - test/yukicoder/1295.test.cpp
  - test/yukicoder/1075.test.cpp
  - test/yukicoder/1718.test.cpp
  - test/yukicoder/922.test.cpp
  - test/yukicoder/1242.test.cpp
  - test/yukicoder/768.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/tree_path_composite_sum.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/1595.test.cpp
  - test/atcoder/abc136_d.test.cpp
  - test/atcoder/abc220_f.test.cpp
  - test/atcoder/abc167_d.test.cpp
  - test/atcoder/abc223_g.rerooting.test.cpp
  - test/atcoder/abc179_e.test.cpp
  - test/atcoder/abc222_f.test.cpp
  - test/atcoder/abc241_e.test.cpp
  - test/atcoder/abc160_f.test.cpp
documentation_of: src/Graph/Graph.hpp
layout: document
title: "\u30B0\u30E9\u30D5"
---

## 使い方

**構築例**
```c++
int n,m;cin>>n>>m; // n: 頂点数, m: 辺数
Graph g(m);
for(int i=0;i<m;++i)cin>>g[i],--g[i];
g.build(n, 0); // 無向グラフ
// g.build(n, 1); // 有向グラフ
```

**グラフ探索例**
```c++
for(int v=0;v<n;++v)
 for(int e: g(v)){ // 辺リスト
  int u=g[e]-v; // 隣接頂点
  /* do something */
 }
```

## `Edge` クラス
辺 $e=(s,d)$ を表すクラス．

|メンバ変数|概要|
|---|---|
|`s`|辺の端点の一つ．有向辺なら始点を表す．|
|`d`|辺の端点の一つ．有向辺なら終点を表す．|

|||
|---|---|
|`operator--()`| 辺の端点をデクリメント. (1-index の入力をスムーズに 0-indexにするために用意).|
|`operator-(Edge e, int v)`|辺 $e$ の端点のうち頂点 $v$ でない方を返す.|
|`operator>>(istream& is,Edge &e)`| `s d` のフォーマットの入力に対応.  |


## `Graph` クラス

`vector<Edge>` を継承.\
コンストラクタも `vector` . \
辺の配列と隣接リストの役割を担ったクラス.

|名前|概要|
|---|---|
|`build(direct)`|隣接リストを構築する. <br> 引数が `false` なら辺を無向辺とみなす.<br> 引数が `true` なら辺を有向辺とみなす.|
|`vertex_size()`|頂点の数を返す. <br> **※`build` 関数が実行済みであることを前提とする**　|
|`edge_size()`|辺の数を返す.|
|`operator()(u)`| 頂点 $u$ から出る辺 (の番号) のリストを返す. <br> 返り値は [`ListRange<int>`](src/Internal/ListRange.hpp). <br> **※`build` 関数が実行済みであることを前提とする**　|