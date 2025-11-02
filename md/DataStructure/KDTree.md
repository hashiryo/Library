---
title: kD-Tree
documentation_of: ../../src/DataStructure/KDTree.hpp
---

## 概要

kD-Tree (k-dimensional tree) は、k次元空間上の点を効率的に管理するためのデータ構造です。
主に、以下のクエリを高速に処理できます。

- **領域探索**: 特定の矩形領域や円（超球）領域に含まれる点を列挙・集約する。
- **最近傍探索**: 与えられた点に最も近い点を探す。

### 計算量
$N$ を点の数、 $K$ を次元数とする。

- **構築**: $O(N \log N)$
- **領域探索・最近傍探索**:
  - 平均的には $O(\log N)$ から $O(N^{1-1/K})$ 程度。
  - 最悪計算量は $O(N)$ となる場合がある。
  - 実用的には、ランダムなデータに対しては非常に高速に動作することが多い。

### 制約・注意事項
- 座標 `pos_t` は整数型を想定しています。
- 領域クエリはすべて閉区間（境界を含む）として扱われます。
- 点の値にモノイドを乗せる場合、モノイドの単位元 `M::ti` は明示的に与える必要があります。
- `set`, `get`, `mul` を使用する際、指定した座標の点が存在しない場合は `assert` でプログラムが停止します。

---

## テンプレート `KDTree<class pos_t, size_t K, class M=void>`

| パラメータ | 説明 |
|---|---|
| `pos_t` | 座標の型。`int`, `long long` など。 |
| `K` | 空間の次元数。通常は 2 や 3。 |
| `M` | 各点に持たせる値の型、またはモノイド。 |

`M` に指定する型によって、点に持たせる値の性質が変わります。
- `void` (デフォルト): 点は値を持たない。
- `int`, `long long` など: 点がその型の値を一つ持つ。
- **モノイド**: 点が持つ値に対して、二項演算 `op` と単位元 `ti` を持つ構造体（クラス）を指定する。これにより、領域内の値の総和などを計算できる。
  ```cpp
  struct Sum {
    using T = long long;
    static T op(T a, T b) { return a + b; }
    static T ti() { return 0; }
  };
  ```
- **作用つきモノイド**: 領域更新を行う場合は、上記に加えて作用 `mp`、作用の合成 `cp`、作用素の単位元 `E` を持つ構造体を指定する。

---

## コンストラクタ

点の座標と、必要に応じて各点が持つ初期値を与えて構築します。

| 形式 | 説明 |
|---|---|
| `KDTree(points)` | `points` からKD-Treeを構築する。`points` は `array<pos_t, K>` や `tuple<pos_t, ...>` のコンテナ（`vector`, `set` など）。 |
| `KDTree(points, initial_value)` | すべての点に共通の初期値 `initial_value` を設定する。 |
| `KDTree(points_with_values)` | `points_with_values` から構築する。各要素は `array<pos_t, K+1>` や `pair<array<pos_t, K>, value_t>` のように、座標と値が組になっている必要がある。 |

#### 使用例1: 座標のみ
```cpp
// 2次元の点を管理 (値なし)
vector<array<int, 2>> points = {{1, 2}, {5, 3}, {4, 6}};
KDTree<int, 2> kdt(points);
```

#### 使用例2: 座標と共通の初期値
```cpp
// 2次元の点に、共通の値 10 を持たせる
vector<array<int, 2>> points = {{1, 2}, {5, 3}, {4, 6}};
KDTree<int, 2, int> kdt(points, 10);
```

#### 使用例3: 座標と個別の初期値
```cpp
// 2次元の点に、それぞれ異なる値を持たせる
vector<array<int, 3>> points_with_values = {{1, 2, 100}, {5, 3, 200}, {4, 6, 300}};
KDTree<int, 2, int> kdt(points_with_values);

// map からの構築も可能
map<array<int, 2>, int> point_map = {{{1, 2}, 100}, {{5, 3}, 200}};
KDTree<int, 2, int> kdt_from_map(point_map);
```

---

## メンバ関数

### 領域探索

| 名前 | 概要 |
|---|---|
| `enum_cuboid(x1_min, x1_max, ..., xK_min, xK_max)` | 矩形領域 $\lbrack x1_{\min}, x1_{\max}\rbrack \times \dots \times \lbrack xK_{\min}, xK_{\max}\rbrack$ 内の点の値を `vector` で返す。 |
| `prod_cuboid(x1_min, x1_max, ..., xK_min, xK_max)` | 矩形領域内の点の値の総和（モノイド `M` の `op` で畳み込んだ結果）を返す。 |
| `apply_cuboid(x1_min, x1_max, ..., xK_min, xK_max, a)` | 矩形領域内のすべての点に作用素 `a` を適用する。 |
| `enum_ball(c1, ..., cK, r)` | 中心 $(c1, \dots, cK)$, 半径 $r$ の円（超球）内の点の値を `vector` で返す。 |
| `prod_ball(c1, ..., cK, r)` | 円（超球）内の点の値の総和を返す。 |
| `apply_ball(c1, ..., cK, r, a)` | 円（超球）内のすべての点に作用素 `a` を適用する。 |

#### 使用例: 矩形領域の合計値
```cpp
struct Sum {
  using T = long long;
  static T op(T a, T b) { return a + b; }
  static T ti() { return 0; }
};

vector<array<long long, 3>> points = {{1, 2, 10}, {5, 5, 20}, {3, 4, 30}, {8, 1, 40}};
KDTree<long long, 2, Sum> kdt(points);

// 矩形領域 [0, 4] x [0, 5] 内の点の合計値を求める
// 含まれる点: {1, 2, 10}, {3, 4, 30}
long long result = kdt.prod_cuboid(0, 4, 0, 5);
// result は 10 + 30 = 40
```

### 最近傍探索

| 名前 | 概要 |
|---|---|
| `nearest_neighbor(x1, ..., xK)` | 点 $(x1, \dots, xK)$ に最も近い点の座標 `array<pos_t, K>` を返す。 |

#### 使用例: 最近傍探索
```cpp
vector<array<int, 2>> points = {{1, 1}, {10, 10}, {3, 4}};
KDTree<int, 2> kdt(points);

// 点 (4, 5) に最も近い点を探索
array<int, 2> nearest = kdt.nearest_neighbor(4, 5);
// nearest は {3, 4}
```

### 点に対する操作

| 名前 | 概要 |
|---|---|
| `get(x1, ..., xK)` | 点 $(x1, \dots, xK)$ の値を返す。 |
| `set(x1, ..., xK, v)` | 点 $(x1, \dots, xK)$ の値を `v` に変更する。 |
| `mul(x1, ..., xK, v)` | 点 $(x1, \dots, xK)$ の値に `v` をモノイド演算で畳み込む (`val = M::op(val, v)`)。 |

---

## Verify

- [AOJ DSL_2_C - Range Search (kD Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C): 矩形領域内の点列挙 (`enum_cuboid`)
- [Yosupo Judge - Point Add Rectangle Sum](https://judge.yosupo.jp/problem/point_add_rectangle_sum): 矩形領域内の値の総和 (`prod_cuboid`) と点更新 (`mul`)
- [AtCoder Regular Contest 010 D - 情報伝播](https://atcoder.jp/contests/arc010/tasks/arc010_4): 最近傍探索 (`nearest_neighbor`)
- [square869120Contest #4 G - Get the Salary of Atcoder](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g): 領域更新 (遅延伝搬)
