---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/bipartite_edge_coloring.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272"
  - icon: ':question:'
    path: src/Graph/minimum_spanning_aborescence.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  - icon: ':warning:'
    path: src/old/BipartiteEdgeColoring.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272"
  - icon: ':warning:'
    path: src/old/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559.LCT_Dual.test.cpp
    title: test/aoj/2559.LCT_Dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3506.test.cpp
    title: test/aoj/3506.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc282_d.test.cpp
    title: test/atcoder/abc282_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  - icon: ':x:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.KDT.test.cpp
    title: test/yukicoder/1600.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.Seg2D.test.cpp
    title: test/yukicoder/1600.Seg2D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\ntemplate <bool undoable= false> class UnionFind\
    \ {\n std::vector<int> par;\n std::vector<std::pair<int, int>> his;\npublic:\n\
    \ UnionFind(int n): par(n, -1) {}\n bool unite(int u, int v) {\n  if ((u= root(u))\
    \ == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u, v);\n  if\
    \ constexpr (undoable) his.emplace_back(v, par[v]);\n  return par[u]+= par[v],\
    \ par[v]= u, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) {\n  if constexpr (undoable) return par[u] < 0 ? u : root(par[u]);\n\
    \  else return par[u] < 0 ? u : par[u]= root(par[u]);\n }\n int size(int u) {\
    \ return -par[root(u)]; }\n int time() const {\n  static_assert(undoable, \"\\\
    'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n  static_assert(undoable,\
    \ \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n  his.pop_back(),\
    \ par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n  static_assert(undoable,\
    \ \"\\'rollback\\' is not enabled\");\n  assert(t <= his.size());\n  while (his.size()\
    \ > t) undo();\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    template <bool undoable= false> class UnionFind {\n std::vector<int> par;\n std::vector<std::pair<int,\
    \ int>> his;\npublic:\n UnionFind(int n): par(n, -1) {}\n bool unite(int u, int\
    \ v) {\n  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v])\
    \ std::swap(u, v);\n  if constexpr (undoable) his.emplace_back(v, par[v]);\n \
    \ return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u, int v) { return\
    \ root(u) == root(v); }\n int root(int u) {\n  if constexpr (undoable) return\
    \ par[u] < 0 ? u : root(par[u]);\n  else return par[u] < 0 ? u : par[u]= root(par[u]);\n\
    \ }\n int size(int u) { return -par[root(u)]; }\n int time() const {\n  static_assert(undoable,\
    \ \"\\'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n\
    \  static_assert(undoable, \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n\
    \  his.pop_back(), par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n\
    \  static_assert(undoable, \"\\'rollback\\' is not enabled\");\n  assert(t <=\
    \ his.size());\n  while (his.size() > t) undo();\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind.hpp
  requiredBy:
  - src/old/MinimumSpanningAborescense.hpp
  - src/old/BipartiteEdgeColoring.hpp
  - src/Graph/bipartite_edge_coloring.hpp
  - src/Graph/minimum_spanning_aborescence.hpp
  timestamp: '2024-02-17 10:13:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/bipartite_edge_coloring.test.cpp
  - test/yosupo/directedmst.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/2647.test.cpp
  - test/aoj/0342.test.cpp
  - test/aoj/2559.LCT_Dual.test.cpp
  - test/aoj/3506.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1600.Seg2D.test.cpp
  - test/yukicoder/1600.KDT.test.cpp
  - test/atcoder/abc282_d.test.cpp
documentation_of: src/DataStructure/UnionFind.hpp
layout: document
title: Union-Find
---

## `UnionFind<undoable=false>` クラス

1. テンプレート引数を指定しない，もしくは `false`　の場合
   - undo 操作が不可能
   - 経路圧縮により高速
2. テンプレート引数が `true` の場合
   - undo 操作が可能

アッカーマン関数の逆関数を $\alpha(n)$ と表す．

|メンバ関数|概要|計算量|
|---|---|---|
|`UnionFind(n)`|コンストラクタ. 要素数 $n$ を渡す.||
|`size(x)`|要素 $x$ の属する集合のサイズを返す.||
|`root(x)`|要素 $x$ の属する集合の代表元を返す.|1. $O(\alpha(n))$ <br> 2. $O(\log n)$|
|`same(x,y)`|要素 $x,y$ が同じ集合に属していれば `true` を返す．|1. $O(\alpha(n))$ <br> 2. $O(\log n)$|
|`unite(x,y)`|要素 $x,y$ それぞれが属する集合を併合する．<br> 元々要素 $x,y$ がそれぞれ異なる集合に属していれば，`true` を返す. |1. $O(\alpha(n))$ <br> 2. $O(\log n)$|
|`time()`|この関数を読んだ時点でのタイムスタンプを返す．<br> (2.) のときのみ|$O(1)$|
|`undo()`|`unite`によって状態が変化したうちの最も新しい場合を無かったことにする．<br> (2.) のときのみ|$O(1)$|
|`rollback(t)`| タイムスタンプ $t$ のときまで `undo` する． <br> (2.) のときのみ|`undo` を呼ぶ回数に比例|