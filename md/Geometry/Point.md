---
title: 点
documentation_of: ../../src/Geometry/Point.hpp
---

二次元幾何ライブラリの基礎となる、点やベクトルを扱うためのコンポーネント。
名前空間 `geo` 内で全て定義している。
浮動小数点数型 `K` を用いる場合、誤差を考慮して `sgn` 関数内で $10^{-9}$ 以下の絶対値は 0 とみなされる。
整数型 `K` で `dot`, `cross` などの計算を行う際、オーバーフローを防ぐために戻り値の型が `make_long_t<K>` (e.g., `int` -> `long long`) になる。

## `Point<K>` クラス
二次元空間上の点およびベクトルを表すクラス。
`public` メンバ変数 `x`, `y` を持つ。

### 演算子
基本的なベクトル演算が定義されている。

| 演算子 | 概要 |
|---|---|
| `p + q`, `p - q` | ベクトルの和・差 |
| `p * k`, `k * p`, `p / k` | ベクトルのスカラー倍・除算 |
| `p += q`, `p -= q`, `p *= k`, `p /= k` | 複合代入演算子 |
| `-p` | ベクトルの符号反転 |
| `!p` | 原点を中心に $\pi/2$ (90度) 反時計回りに回転 |
| `p == q`, `p != q` | 座標が（誤差を考慮して）等しいかどうかの比較 |
| `p < q`, `p > q`, `p <= q`, `p >= q` | 辞書順による比較 (`set` や `map` のキーとして使用可能) |
| `cin >> p`, `cout << p` | `x y` 形式での入力、`(x, y)` 形式での出力 |

## `Point<K>` を引数に取る関数
点やベクトルに関する基本的な幾何計算を行う関数。

|名前|概要|戻り値の型|
|---|---|---|
|`dot(p,q)`| 内積 $\boldsymbol{p}\cdot \boldsymbol{q}$ | `make_long_t<K>` |
|`cross(p,q)`| 外積 $\boldsymbol{p}\times \boldsymbol{q}$  <br>$\boldsymbol{p}$ から $\boldsymbol{q}$ へ反時計回りなら正。| `make_long_t<K>` |
|`norm2(p)`| ノルムの2乗 $\lVert \boldsymbol{p}\rVert^2$ | `make_long_t<K>` |
|`norm(p)`| ノルム $\lVert \boldsymbol{p}\rVert$  <br>(`sqrt` を用いるため `Rational` などでは使用不可) | `long double` |
|`dist2(p,q)`| 2点 $\boldsymbol{p}$, $\boldsymbol{q}$ 間のユークリッド距離の2乗。| `make_long_t<K>` |
|`dist(p,q)`| 2点 $\boldsymbol{p}$, $\boldsymbol{q}$ 間のユークリッド距離。 <br>(`sqrt` を用いるため `Rational` などでは使用不可) | `long double` |
|`ccw(p0,p1,p2)`| 3点 $\boldsymbol{p_0}, \boldsymbol{p_1}, \boldsymbol{p_2}$ の位置関係を判定する。<br>具体的には、ベクトル $\overrightarrow{p_0 p_1}$ から見て $\overrightarrow{p_0 p_2}$ がどの方向にあるかを示す。<br>浮動小数点数型 `K` の場合、誤差に強くするため、ベクトルを正規化してから外積を計算する。<br>戻り値は以下の `enum CCW` 型：<br>`COUNTER_CLOCKWISE`: 反時計回り (左折)<br>`CLOCKWISE`: 時計回り (右折)<br>`ONLINE_BACK`: $\boldsymbol{p_2}$--$\boldsymbol{p_0}$--$\boldsymbol{p_1}$ の順で同一直線上<br>`ONLINE_FRONT`: $\boldsymbol{p_0}$--$\boldsymbol{p_1}$--$\boldsymbol{p_2}$ の順で同一直線上<br>`ON_SEGMENT`: $\boldsymbol{p_0}$--$\boldsymbol{p_2}$--$\boldsymbol{p_1}$ の順で同一直線上（線分 $\boldsymbol{p_0 p_1}$ 上） | `enum CCW` |

## `Affine<K>` クラス
アフィン変換 $\boldsymbol{x} \mapsto A\boldsymbol{x} + \boldsymbol{b}$ を表現するクラス。
デフォルトコンストラクタでは恒等変換（何も変化させない変換）が生成される。
`operator()` で `Point` を変換する。
`f * g` で変換の合成 $f \circ g$ (g を適用した後に f を適用) が定義されている。

### `Affine<K>` を返す関数

|名前|概要|
|---|---|
|`translate(p)`| ベクトル $\boldsymbol{p}$ だけ平行移動する変換を返す。|

### 使用例
```cpp
// 原点を中心に theta 度回転するアフィン変換
Affine<double> rot;
rot.a00 = cos(theta); rot.a01 = -sin(theta);
rot.a10 = sin(theta); rot.a11 =  cos(theta);
Point<double> p = {1.0, 0.0};
Point<double> p_rotated = rot(p);
```

## 便利関数

|名前|概要|
|---|---|
|`sgn(x)`|誤差を考慮した符号関数。  負なら-1, 正なら+1, 0なら0を返す。  浮動小数点数の場合、絶対値が $10^{-9}$ 以下なら0とみなす。 |
|`err_floor(x)`|誤差を考慮した床関数。`floor(x)` と `floor(x)+1` のうち `x` に近い方を返す。|
|`err_ceil(x)`|誤差を考慮した天井関数。`ceil(x)` と `ceil(x)-1` のうち `x` に近い方を返す。|

## デバッグ用 `Visualizer`
`Point` やその他の幾何オブジェクトをファイルに出力し、可視化を助けるためのクラス。
デフォルトでは `visualize.txt` というファイルに出力する。

### 使用例
```cpp
#include "src/Geometry/Point.hpp"
#include "src/Geometry/Circle.hpp" // for example
geo::Visualizer vis;
geo::Point<double> p = {1, 2};
geo::Circle<double> c = {{0, 0}, 3};
vis << p; // ファイルに "1 2" を出力
vis << c; // ファイルに円を描画するための情報を出力
```