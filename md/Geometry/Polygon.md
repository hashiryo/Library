---
title: 多角形
documentation_of: ../../src/Geometry/Polygon.hpp
---

## `Polygon<K>` クラス
二次元空間上の多角形を表すクラス. \
頂点が反時計回りになるようにしてある. \
頂点数を $n$ とする.

|メンバ関数|概要|計算量|
|---|---|---|
|`Polygon()`|デフォルトコンストラクタ||
|`Polygon(ps)`|コンストラクタ. <br> 引数として `vector<Point<K>>` で点列を与え, 順に線を結ぶことで多角形を作る. <br> ただし反時計回りになるように頂点を順序づける.|$O(n)$|
|`prev(i)`|頂点 `i` の (反時計回りで) 一つ前の頂点番号を返す.|$O(1)$|
|`next(i)`|頂点 `i` の (反時計回りで) 一つ次の頂点番号を返す.|$O(1)$|
|`operator[](i)`| `i` 番目の頂点を返す.|$O(1)$|
|`begin()`|頂点列の最初. (範囲for文のため)||
|`end()`|頂点列の最後. (範囲for文のため)||
|`size()`|頂点の数を返す.|$O(1)$|
|`edges()`| 辺の列を返す. <br> 各辺の端点は多角形の頂点順に並んでいる. <br> 返り値の型は `vector<Segment<K>>`.|$O(n)$|
|`area()`|多角形の面積を返す.|$O(1)$|
|`area2()`|多角形の面積の2倍を返す. <br>これは整数のまま扱うことを想定したもの.|$O(1)$|
|`is_convex()`| 凸多角形なら `true`. <br> 自己交差がある場合は未定義. |$O(n)$|
|`where(p)`|点 $\boldsymbol{p}$ と多角形の位置関係を表す. <br> +1: 多角形内部: 0: 多角形の周上, -1: 多角形外部. |$O(n)$|
|`in(s)`|線分 $s$ が多角形内部にあるなら `true`.|$O(n)$|
|`out(s)`|線分 $s$ が多角形外部にあるなら `true`.|$O(n)$|


## その他関数

|名前|概要|
|---|---|
|`dist2(g,p)` <br> `dist2(p,g)`| 多角形 $g$ と点 $\boldsymbol{p}$ との距離の二乗. <br>ただし点 $\boldsymbol{p}$ が多角形 $g$ の内部にあるなら 0.|
|`dist2(g,l)` <br> `dist2(l,g)`| 多角形 $g$ と直線 $l$ との距離の二乗. ただし交わるときは 0.|
|`dist2(g,s)` <br> `dist2(s,g)`| 多角形 $g$ と 線分 $s$ との距離の二乗. <br> ただし線分 $s$ が多角形 $g$ の内部にあるときや交わるときは 0.|
|`dist2(g,h)`|多角形 $g,h$ の間の距離の二乗. <br>ただし一方がもう一方の内部にあるときや交わるときは 0.|

