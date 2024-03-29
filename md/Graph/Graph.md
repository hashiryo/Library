---
title: グラフ
documentation_of: ../../src/Graph/Graph.hpp
---

## 使い方

**構築例**
```c++
int n,m;cin>>n>>m; // n: 頂点数, m: 辺数
Graph g(n,m);
for(int i=0;i<m;++i)cin>>g[i],--g[i];
auto adj = g.adjecency_vertex(0); // 無向グラフ
// auto adj = g.adjecency_vertex(1); // 有向グラフ
```

**グラフ探索例**
```c++
for(int v=0;v<n;++v)
 for(int u: adj[v]){
  /* do something */
 }
```

## `Edge` クラス
`pair<int,int>` を継承 \
辺 $e=(s,d)$ を表すクラス．\
`first` で始点，`second` で終点を表現する.

|メンバ関数|概要|
|---|---|
|`to(u)`|端点のうち頂点 $u$ でない方を返す.|
|`operator--()`| 辺の端点をデクリメント. (1-index の入力をスムーズに 0-indexにするために用意).|

|その他関数|概要|
|---|---|
|`operator<(Edge e1, Edge e2)`|辞書順比較．|
|`operator>>(istream& is,Edge &e)`| `s d` のフォーマットの入力に対応.  |


## `Graph` クラス

`vector<Edge>` を継承.\
辺の配列の役割を担ったクラス.

|メンバ変数|概要|
|---|---|
|`n`|頂点数を意味する．|

|メンバ関数|概要|
|---|---|
|`Graph(n=0,m=0)`|コンストラクタ．頂点の数 $n$ と 辺の数 $m$ を渡す． <br> 辺はすべて $(0,0)$ で初期化．|
|`vertex_size()`|頂点の数を返す．|
|`edge_size()`|辺の数を返す．|
|`add_vertex()`|内部で頂点を 1 つ増やし，その頂点番号を返す．|
|`add_edge(Edge e)` <br> `add_edge(s,d)`| 辺 $e=(s,d)$ を追加し，その辺の番号を返す．|
|`adjacency_vertex(dir)`|頂点 → 頂点の隣接リストを返す. <br> 引数が正なら有向グラフ.<br> 引数が $0$ なら無向グラフ．<br> 引数が負なら逆向きの有向グラフ. <br> 返り値は[`CSRArray<int>` クラス](../Internal/ListRange.hpp)． <br> 辺番号でソートされている．|
|`adjacency_edge(dir)`|頂点 → 辺番号の隣接リストを返す. <br> 引数が正なら有向グラフ.<br> 引数が $0$ なら無向グラフ．<br> 引数が負なら逆向きの有向グラフ. <br>返り値は[`CSRArray<int>` クラス](../Internal/ListRange.hpp)． <br> 辺番号はソートされている．|


## 参考
[https://nachiavivias.github.io/cp-library/cpp/graph/graph.html](https://nachiavivias.github.io/cp-library/cpp/graph/graph.html)