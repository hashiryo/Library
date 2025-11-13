---
title: 凸多角形
documentation_of: ../../src/Geometry/Convex.hpp
---

## `Convex<K>` クラス
二次元空間上の凸多角形を表すクラス. `Polygon<K>` を継承している.
頂点は反時計回りにソートされている.
頂点数を $n$ とする.

### テンプレートパラメータ
- `K`: 座標の型. `long long` や `double` などの数値型を想定.

|メンバ関数|概要|計算量|
|---|---|---|
|`Convex()`|デフォルトコンストラクタ||
|`Convex(ps,strict)`|コンストラクタ. <br> `vector<Point<K>>` で与えられた点群 `ps` の凸包を計算し, 凸多角形を構築する. <br> `strict` が `true` (デフォルト) の場合, 同一直線上の3点を含まない狭義凸包を構築する. `false` の場合, 同一直線上の点も頂点として含める広義凸包を構築する.|$O(m\log m)$ <br> (引数の点数を $m$ とする)|
|`farthest_pair()`| 最遠点対 (最も距離が離れた2頂点のペア) を返す. |$O(n)$|
|`diameter()`|凸多角形の直径 (最遠点対間の距離) を `long double` 型で返す. <br> `sqrt` の計算を含むため, `K` が `Rational` の場合は使用できない.|$O(n)$|
|`cut(l, side)`|直線 $l$ で分けられる半平面との共通部分を返す. <br> `side` が正 (デフォルト) なら直線の左側, 負なら右側との共通部分を計算する. |$O(n)$|
|`cut(a, b, c, side)`| 半平面 $(ax+by+c)\cdot\mathrm{side} \geq 0$ との共通部分を返す. <br> `side` のデフォルトは正. |$O(n)$|

`Polygon<K>` から継承したメンバ関数 (面積計算 `area()` など) も使用可能. 詳細は `Polygon` のドキュメントを参照.

## その他関数

|名前|概要|計算量|
|---|---|---|
|`farthest_pair(ps)`| `vector<Point<K>>` で与えられた点群 `ps` の最遠点対を返す. |$O(m \log m)$ <br> (引数の点数を $m$ とする)|

## 使用例
```cpp
#include <iostream>
#include <vector>
#include "Geometry/Point.hpp"
#include "Geometry/Convex.hpp"

int main() {
    using P = geo::Point<long long>;
    std::vector<P> ps = {{0, 0}, {5, 0}, {3, 3}, {0, 5}, {2, 1}};
    
    // 点群から凸包を構築
    geo::Convex<long long> convex(ps);
    
    // 頂点の出力
    // 頂点は (0,0), (5,0), (3,3), (0,5) になる
    for (const auto& p : convex) {
        std::cout << p.x << " " << p.y << std::endl;
    }
    
    // 直径の計算
    // (0,5) と (5,0) の間の距離
    std::cout << "Diameter: " << convex.diameter() << std::endl;
    
    // 最遠点対の取得
    auto [p1, p2] = convex.farthest_pair();
    std::cout << "Farthest pair: (" << p1.x << "," << p1.y << ") and (" << p2.x << "," << p2.y << ")" << std::endl;
    
    return 0;
}
```
