---
title: 角度・回転関連
documentation_of: ../../src/Geometry/angle.hpp
---

## 関数

|名前|概要|
|---|---|
|`radian_to_degree(r)`|ラジアンの値を度数に変換したものを返す. <br> 計算量: $O(1)$|
|`degree_to_radian(d)`|度数の値からラジアンに変換したものを返す. <br> 計算量: $O(1)$|
|`normalize_radian(r)`|ラジアンの値を $(-\pi,\pi\rbrack$ の区間に収まるように正規化したものを返す. <br> 計算量: $O(1)$|
|`angle(p)`|ベクトル $\boldsymbol{p}$ の偏角を返す. 返り値の範囲は $(-\pi, \pi]$. <br> 計算量: $O(1)$|
|`angle(p,q)`|ベクトル $\boldsymbol{p}$ からベクトル $\boldsymbol{q}$ への偏角を返す. 返り値の範囲は $(-\pi, \pi]$. <br> 計算量: $O(1)$|
|`rotate(theta)`| 原点を中心に角度 $\theta$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`. <br> 計算量: $O(1)$|
|`rotate(p, theta)`| 点 $\boldsymbol{p}$ を中心に角度 $\theta$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`. <br> 計算量: $O(1)$|
|`rotate90(p)`| 点 $\boldsymbol{p}$ を中心に $\pi/2$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`. <br> 計算量: $O(1)$|

## `AngleComp<K>` クラス

`Point<K>` を偏角の大小で比較する関数オブジェクト.\
偏角を $(-\pi,\pi\rbrack$ に正規化した上で反時計回りに比較する. `K` が整数型の場合でも浮動小数点数誤差なしに動作する. \
原点 $(0,0)$ は、どの点よりも偏角が小さいものとして扱われる.

主に `std::sort` などと組み合わせて、点の集合を偏角ソートするために用いる.

### 使用例
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "src/Geometry/Point.hpp"
#include "src/Geometry/angle.hpp"

int main() {
    std::vector<geo::Point<int>> ps = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {0, 1}};
    std::sort(ps.begin(), ps.end(), geo::AngleComp<int>());
    // 出力:
    // 1 -1
    // -1 -1
    // -1 1
    // 0 1
    // 1 1
    for (const auto& p : ps) {
        std::cout << p.x << " " << p.y << std::endl;
    }
}
```