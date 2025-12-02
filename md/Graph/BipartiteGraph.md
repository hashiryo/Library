---
title: 二部グラフ
documentation_of: ../../src/Graph/BipartiteGraph.hpp
---

## 概要
二部グラフを扱うためのクラスと、関連するアルゴリズム（二部グラフ判定、最大マッチング）を提供する。

二部グラフの最小頂点被覆や最大独立安定集合は、最大マッチングの結果を利用して求められる（参考：[牛ゲー，燃やす埋める，最小カット，最大マッチング，二部グラフ，マッチング，頂点被覆，独立安定集合](https://www.slideshare.net/drken1215/ss-86638703)）。
また、より複雑な問題に対しては [Dulmage-Mendelsohn 分解](DulmageMendelsohn.md) が有効な場合がある。

## `BipartiteGraph` クラス

[`Graph` クラス](Graph.md)を継承した、二部グラフを表現するためのクラス。
左右の頂点数をそれぞれ $L, R$ とし、グラフ全体で $L+R$ 頂点を持つ。
- 左側の頂点集合：$\{0, 1, \dots, L-1\}$
- 右側の頂点集合：$\{L, L+1, \dots, L+R-1\}$

辺は、`bipartite_matching` などの関数で利用する際に、**必ず左側から右側へ向かうように追加する必要がある**。

|コンストラクタ|概要|
|---|---|
|`BipartiteGraph(size_t L, size_t R, size_t m= 0)`|左側頂点数 $L$, 右側頂点数 $R$, 辺数 $m$ の二部グラフを構築する|

|メンバ関数|概要|
|---|---|
|`left_size()`|左側の頂点の数 $L$ を返す|
|`right_size()`|右側の頂点の数 $R$ を返す|

## 関数

|関数|概要|計算量|
|---|---|---|
|`paint_two_colors(adj)`<br> `paint_two_colors(g)`|無向グラフを2色 (0 と 1) で塗り分けることで、二部グラフ判定を行う。<br> 引数はグラフであり、隣接リスト ([`CSRArray<int>`クラス](../Internal/ListRange.md)) または [`Graph`クラス](Graph.md)で与える。<br> 戻り値は、各頂点の色の割り当てを格納した `vector<int>`。二部グラフでない場合は空の `vector` を返す。|$O(V+E)$|
|`graph_to_bipartite(g,color={})`|[`Graph` クラス](Graph.md)で表現された無向グラフを、2色に塗り分けてから頂点番号を付け直し、`BipartiteGraph` クラスのインスタンスに変換する。<br> 辺の順番は保たれる。<br> 第二引数 `color` に `paint_two_colors` の結果を渡すことができる。省略された場合は内部で `paint_two_colors` を呼び出す。<br> 戻り値は以下の3要素からなる `tuple` である。<br> 1. `BipartiteGraph` のインスタンス<br> 2. 元のグラフの頂点番号から、新しいグラフの頂点番号へのマッピング<br> 3. 新しいグラフの頂点番号から、元のグラフの頂点番号へのマッピング<br>二部グラフでない場合は、空の `BipartiteGraph` などを含む `tuple` を返す。 |$O(V+E)$|
|`bipartite_matching<lexical=false>(bg, partner={})`|二部グラフの最大マッチングを求める (Hopcroft-Karp法)。<br> 第二引数 `partner` に既存のマッチングを渡すことで、差分更新（辺の追加・削除後の再計算）を高速化できる場合がある。初期状態では全員がマッチング相手なし (-1) の `vector` を渡す。<br> 戻り値は以下の2要素からなる `pair` である。<br> 1. 最大マッチングに含まれる辺の番号リスト `vector<int>`<br> 2. 各頂点のマッチング相手の頂点番号 `vector<int>`（マッチング相手がいない場合は -1）<br>テンプレート引数 `lexical` を `true` にすると、左側頂点 $0, 1, \dots, L-1$ に対応するマッチング相手の頂点番号の組が、辞書順最小になるものを求める。|1. `lexical=false`: $O(E\sqrt{V})$ <br> 2. `lexical=true`: $O(EV)$ |

## Verify

- [CODE FESTIVAL 2017 qual B C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c) (二部グラフ塗り分け)
- [アルゴリズムと数学　演習問題集 047 - Bipartite Graph](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ao) (二部グラフ判定)
- [yosupo judge - Bipartite Matching](https://judge.yosupo.jp/problem/bipartitematching) (最大二部マッチング)
- [Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (最大二部マッチング)
