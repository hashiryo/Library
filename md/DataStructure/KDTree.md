---
title: kD-Tree
documentation_of: ../../src/DataStructure/KDTree.hpp
---

## 概要

kD-Tree は、$k$ 次元のユークリッド空間上の点を管理するためのデータ構造です。点の追加や削除はできず、静的な点集合に対して高速な範囲探索や最近傍探索を可能にします。

## 計算量

$N$ を点の数、$k$ を次元数とする。

- **構築**: $O(N \log N)$
- **クエリ**:
    - 範囲探索 (`enum_*`, `prod_*`, `apply_*`): 平均的に $O(N^{1-1/k} + (\text{hit count}))$、最悪 $O(N)$
    - 最近傍探索 (`nearest_neighbor`): 平均的に $O(\log N)$、最悪 $O(N)$

## テンプレート `KDTree<class pos_t, size_t K, class M=void>`

- `pos_t`: 座標の型 (e.g., `int`, `long long`)。
- `K`: 次元の数 (e.g., `2`, `3`)。
- `M`: 点が持つ値に関する型。
    - `void` (デフォルト): 点に値を持たせない。
    - `T` (e.g., `int`): 点が型 `T` の値を持つ。
    - モノイド: `T` (型), `op` (二項演算), `ti` (単位元) を持つ構造体を指定すると、範囲積クエリ (`prod_*`) が利用可能になる。
    - 作用つきモノイド: 上記に加え、`E` (作用素の型), `mp` (作用), `cp` (合成) を持つ構造体を指定すると、範囲作用クエリ (`apply_*`) が利用可能になる。

## メンバ関数

### コンストラクタ

点の座標や値を様々な形式のコンテナから与えて構築できます。

- `KDTree(P* p, size_t n)`
- `KDTree(const vector<P>& p)`
- `KDTree(const set<P>& p)`
  - `P` は `array<pos_t, K>` や `tuple<pos_t, ...>` のような座標を表す型、または `array<pos_t, K+1>` のような座標と値を持つ型。
- `KDTree(P* p, size_t n, U v)`
- `KDTree(const vector<P>& p, U v)`
  - `P` は座標を表す型。すべての点に共通の初期値 `v` を設定する。
- `KDTree(pair<P, U>* p, size_t n)`
- `KDTree(const vector<pair<P, U>>& p)`
- `KDTree(const map<P, U>& p)`
  - `P` は座標を表す型、`U` は値の型。座標と値のペアから構築する。

### 範囲クエリ

- `vector<T> enum_cuboid(x1_min, x1_max, ..., xk_min, xk_max)`
  - 閉区間の直積で表される超直方体領域 [x1_min, x1_max] x ... x [xk_min, xk_max] 内に含まれる点の値を列挙する。
- `T prod_cuboid(x1_min, x1_max, ..., xk_min, xk_max)`
  - 超直方体領域内の点の値のモノイド積を返す。
- `void apply_cuboid(x1_min, x1_max, ..., xk_min, xk_max, E a)`
  - 超直方体領域内の各点 `p` の値 `v` を `M::mp(v, a)` で更新する。
- `vector<T> enum_ball(c1, ..., ck, r)`
  - 中心 (c1, ..., ck)、半径 r の超球内に含まれる点の値を列挙する。
- `T prod_ball(c1, ..., ck, r)`
  - 超球内の点の値のモノイド積を返す。
- `void apply_ball(c1, ..., ck, r, E a)`
  - 超球内の各点 `p` の値 `v` を `M::mp(v, a)` で更新する。

### 点への操作

クエリ対象の点 `(x1, ..., xk)` は構築時に与えられた点と完全に一致する必要があります。存在しない場合は `assert` で失敗します。

- `void set(x1, ..., xk, T v)`
  - 点の値を `v` に変更する。
- `T get(x1, ..., xk)`
  - 点の値を取得する。
- `void mul(x1, ..., xk, T v)`
  - 点の値にモノイド演算 `M::op` を適用する (`val = M::op(val, v)`)。
  
### 最近傍探索

- `array<pos_t, K> nearest_neighbor(x1, ..., xk)`
  - 点 $(x_1, ..., x_k)$ に最も近い点の座標を返す。
  - 点集合が空の場合は `assert` で失敗します。

## 使用例

```cpp
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include "src/DataStructure/KDTree.hpp"

int main() {
    // 2次元の点 (x, y, id)
    std::vector<std::array<int, 3>> points = {
        {1, 2, 0}, {5, 5, 1}, {2, 8, 2},
        {9, 3, 3}, {8, 7, 4}, {3, 1, 5}
    };

    // KDTree<座標の型, 次元数, 点が持つ値の型>
    KDTree<int, 2, int> kdt(points);

    // 矩形領域 [0, 5] x [0, 5] 内の点のIDを列挙
    std::cout << "Points in [0, 5] x [0, 5]:" << std::endl;
    auto result = kdt.enum_cuboid(0, 5, 0, 5);
    std::sort(result.begin(), result.end());
    for (int id : result) {
        std::cout << id << std::endl; // 0, 1, 5 が出力される
    }
    std::cout << std::endl;

    // 点 (7, 2) に最も近い点を探索
    std::cout << "Nearest neighbor to (7, 2):" << std::endl;
    auto nn = kdt.nearest_neighbor(7, 2);
    std::cout << "(" << nn[0] << ", " << nn[1] << ")" << std::endl; // (9, 3) が出力される
}
```

## 参考
[https://trap.jp/post/1489/](https://trap.jp/post/1489/)


## Verify

- [square869120Contest #4 G - Get the Salary of Atcoder](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g) (遅延伝搬)
- [AtCoder Regular Contest 010 D - 情報伝播](https://atcoder.jp/contests/arc010/tasks/arc010_4) (最近傍探索)
- [AOJ DSL_2_C - Range Search](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C) (範囲列挙)