---
title: 区間に辺を張るグラフ (Range to Range Graph)
documentation_of: ../../src/Graph/RangeToRangeGraph.hpp
---

## 概要

点・区間から点・区間へ重み付き有向辺を追加できるグラフを構築する。
セグメント木を利用して、区間に関する辺を少数の辺に分解することで、効率的にグラフを表現する。

内部では $3n$ 個の頂点を持つグラフを構築する。元の $n$ 個の頂点はインデックス $0, \dots, n-1$ に対応する。
`add_from_range_to_range` を呼び出すたびに、グラフの頂点数が 1 ずつ増加する。

## `RangeToRangeGraph<cost_t=int>` クラス

|メンバ変数|概要|
|---|---|
|`graph`|構築された有向グラフ。頂点数は $3n$ 以上。<br> [`Graph` クラス](./Graph.md)|
|`weight`|`graph` の各辺に対応する重み。<br> `vector<cost_t>`|


|メンバ関数|概要|計算量|
|---|---|---|
|`RangeToRangeGraph(n)`|コンストラクタ。元のグラフの頂点数 $n$ を渡す。|$O(n)$|
|`add(s,t,w=0)`|頂点 $s$ から頂点 $t$ へ重み $w$ の有向辺を張る。|$O(1)$|
|`add_from_range(s_l,s_r,t,w=0)`|半開区間 $\lbrack s_l, s_r)$ の各頂点から頂点 $t$ へ重み $w$ の有向辺を張る。|$O(\log n)$|
|`add_to_range(s,t_l,t_r,w=0)`|頂点 $s$ から半開区間 $\lbrack t_l, t_r)$ の各頂点へ重み $w$ の有向辺を張る。|$O(\log n)$|
|`add_from_range_to_range(s_l,s_r,t_l,t_r,w=0)`|半開区間 $\lbrack s_l, s_r)$ の各頂点から半開区間 $\lbrack t_l, t_r)$ の各頂点へ重み $w$ の有向辺を張る。<br>内部で新しい頂点を 1 つ追加し、区間 $\lbrack s_l, s_r) \to$ 新頂点 (重み $w$), 新頂点 $\to$ 区間 $\lbrack t_l, t_r)$ (重み $0$) という辺を張ることで実現される。|$O(\log n)$|

## Verify


- [灘校文化祭コンテスト 2022 Day1 I - NPCA Kingdom](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_i)


## 参考
[https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
