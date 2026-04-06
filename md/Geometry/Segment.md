---
title: 線分
documentation_of: ../../src/Geometry/Segment.hpp
---

## `Segment<K>` クラス
二次元空間上の線分を表すクラス. 
`Point<K>` 型のpublicメンバ変数 `p`, `q` を持ち, それらを端点とした線分を表現している. 

| メンバ関数 | 概要 | 計算量 |
|---|---|---|
| `Segment()` | デフォルトコンストラクタ | O(1) |
| `Segment(p,q)` | コンストラクタ | O(1) |
| `operator[](i)` | `i==0` なら `p`, `i==1` なら `q` を返す | O(1) |
| `on(r)` | 点 $r$ が線分上にあるなら `true` | O(1) |
| `length()` | 線分の長さを返す | O(1) |
| `closest_point(r)` | 点 $r$ から最も近い線分上の点を返す | O(1) |

## その他関数

| 名前 | 概要 | 計算量 |
|---|---|---|
| `cross_points(s,t)` | 2線分 $s,t$ の交点を `vector<Point<K>>` で返す. <br> - 交わらない: 空の `vector` <br> - 1点で交わる: 要素数1の `vector` <br> - 線分として重なる: 共通部分の端点 (要素数2の `vector`) | O(1) |
| `cross_points(s,l)` <br> `cross_points(l,s)` | 線分 $s$ と直線 $l$ の交点を `vector<Point<K>>` で返す. <br> - 交わらない: 空の `vector` <br> - 1点で交わる: 要素数1の `vector` <br> - $s$が$l$上に含まれる: $s$の端点 (要素数2の `vector`) | O(1) |
| `intersection(s,t)` | 2線分 $s,t$ の位置関係を返す. <br> `CROSSING`: 1点で交わる (端点を除く). <br> `TOUCHING`: 1点で交わり, その点が少なくとも一方の端点. <br> `OVERLAP`: 長さが正の共通部分を持つ. <br> `DISJOINT`: 共有点を持たない. | O(1) |
| `dist2(s,p)` <br> `dist2(p,s)` | 線分 $s$ と点 $\boldsymbol{p}$ との距離の二乗を返す | O(1) |
| `dist2(s,l)` <br> `dist2(l,s)` | 線分 $s$ と直線 $l$ との距離の二乗を返す. (交わる場合は0) | O(1) |
| `dist2(s,t)` | 線分 $s$ と線分 $t$ との距離の二乗を返す. (交わる場合は0) | O(1) |

