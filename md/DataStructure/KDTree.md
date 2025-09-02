---
title: kD-Tree
documentation_of: ../../src/DataStructure/KDTree.hpp
---

$k$次元空間上の点集合を管理し、領域探索や最近傍探索を効率的に行うデータ構造。

## 概要

$N$ 個の点を $k$ 次元空間に配置し、以下のクエリを処理できる。

- **構築**: $O(N \log N)$
- **最近傍探索**: ある点に最も近い点を探す。期待計算量 $O(\log N)$。
- **領域探索**: 指定された超矩形や超球に含まれる点を列挙したり、点に乗った値の総和を求めたりする。計算量は $k=2$ の場合、矩形領域内の点の個数を $m$ として $O(\sqrt{N} + m)$。

点にはモノイドを乗せることができ、領域内の値の総和や、領域内の値に対する一様作用（遅延伝搬）もサポートする。

### 制約

- 座標の型 `pos_t` は整数型を想定。
- 点に乗せる値の型 `M` がモノイドである場合、単位元 `M::ti()` の定義が必要。
- 遅延伝搬を利用する場合、作用素モノイドの定義が必要。

## テンプレート `KDTree<class pos_t, size_t K, class M=void>`

- `pos_t`: 座標の型 (e.g., `int`, `long long`)。
- `K`: 次元の数 (e.g., `2`, `3`)。
- `M`: 点に乗せる値に関する型。
    - `void` (デフォルト): 点に値を乗せない。最近傍探索など、座標のみが必要な場合に使用する。
    - `int`, `long long` など: 点に値を乗せるが、`prod` や `apply` などの集約・更新処理は行わない場合。`get`/`set` のみ利用可能。
    - **モノイド**: `prod` (領域和) を利用する場合。
    - **作用素モノイド**: `apply` (領域更新) を利用する場合。

### モノイドの指定方法

#### `prod` (領域和) のみを利用する場合

`M` には以下のメンバを持つ構造体を指定する。

- `using T = ...`: 点に乗せる値の型。
- `static T ti()`: 単位元を返す関数。
- `static T op(T l, T r)`: 2つの値を併合する二項演算。

**例: 領域和 (RSQ)**
```cpp
struct RSQ {
    using T = long long;
    static T ti() { return 0; }
    static T op(T l, T r) { return l + r; }
};
// KDTree<long long, 2, RSQ> kdt(...);
```

#### `apply` (領域更新) を利用する場合

`M` には上記に加えて、作用素モノイドの定義を追加する。

- `using E = ...`: 作用素の型。
- `static void mp(T &v, E x)`: 値 `v` に作用素 `x` を適用する。
- `static void cp(E &pre, E suf)`: 作用素 `pre` に `suf` を合成する。

**例: 領域加算・領域和 (RaddsumQ)**
```cpp
struct RaddsumQ {
    struct T { long long val; int sz; };
    using E = long long;
    static T ti() { return {0, 0}; }
    static T op(const T &l, const T &r) { return {l.val + r.val, l.sz + r.sz}; }
    static void mp(T &v, E x) { v.val += x * v.sz; }
    static void cp(E &pre, E suf) { pre += suf; }
};
// KDTree<int, 2, RaddsumQ> kdt(...);
```

## コンストラクタ

入力データの形式に応じて複数のコンストラクタが用意されている。

- **座標のみ**: `std::vector<std::array<pos_t, K>>`
- **座標と共通の初期値**: `std::vector<std::array<pos_t, K>>`, `初期値`
- **座標と各点の初期値**:
    - `std::vector<std::array<pos_t, K + 1>>` (最後の要素が値)
    - `std::vector<std::pair<std::array<pos_t, K>, T>>`
    - `std::map<std::array<pos_t, K>, T>`

**使用例**
```cpp
// 2次元、値なし
vector<array<int, 2>> xy(N);
KDTree<int, 2> kdt1(xy);

// 2次元、int型の値を乗せる (全点共通の初期値 1)
KDTree<int, 2, int> kdt2(xy, 1);

// 2次元、int型の値を乗せる (各点に異なる初期値)
vector<array<int, 3>> xyv(N); // x, y, value
KDTree<int, 2, int> kdt3(xyv);

// mapから構築 (座標が重複する場合に便利)
map<array<int, 2>, int> mp;
KDTree<int, 2, int> kdt4(mp);
```

## メンバ関数

- `pos_t...` は `pos_t` 型の引数が `K` 個並ぶことを示す。
- `min/max` はそれぞれ `K` 個のペア `(min_1, max_1, min_2, max_2, ...)` を示す。

|名前|概要|計算量|
|---|---|---|
|`nearest_neighbor(pos_t... p)`|点 `p` に最も近い点の座標 `std::array<pos_t, K>` を返す。点が存在しない場合は assert で失敗する。| $O(\log N)$ (期待) |
|`enum_cuboid(min/max)`|超矩形 $\lbrack \min_1, \max_1 \rbrack \times \dots \times \lbrack \min_K, \max_K \rbrack$ 内部の点の値 (`T`) を `std::vector` で列挙する。| $O(N^{1-1/k} + m)$ |
|`enum_ball(pos_t... center, pos_t r)`|中心 `center`、半径 `r` の超球内部の点の値 (`T`) を `std::vector` で列挙する。| $O(N^{1-1/k} + m)$ |
|`prod_cuboid(min/max)`|超矩形内部の点の値の総和 (`T`) を返す。(`M`がモノイドである必要あり)| $O(N^{1-1/k})$ |
|`prod_ball(pos_t... center, pos_t r)`|超球内部の点の値の総和 (`T`) を返す。(`M`がモノイドである必要あり)| $O(N^{1-1/k})$ |
|`apply_cuboid(min/max, E a)`|超矩形内部の全ての点に乗った値に作用素 `a` を適用する。(`M`が作用素モノイドである必要あり)| $O(N^{1-1/k})$ |
|`apply_ball(pos_t... center, pos_t r, E a)`|超球内部の全ての点に乗った値に作用素 `a` を適用する。(`M`が作用素モノイドである必要あり)| $O(N^{1-1/k})$ |
|`set(pos_t... p, T v)`|点 `p` の値を `v` に変更する。点が存在しない場合は assert で失敗する。| $O(\log N)$ |
|`get(pos_t... p)`|点 `p` の値を返す。点が存在しない場合は assert で失敗する。| $O(\log N)$ |
|`mul(pos_t... p, T v)`|点 `p` の値に `v` をモノイド演算 `op` で合成する。点が存在しない場合は assert で失敗する。| $O(\log N)$ |

## Verify

- **最近傍探索**: [AtCoder Regular Contest 010 D - 情報伝播](https://atcoder.jp/contests/arc010/tasks/arc010_4)
- **領域列挙**: [AOJ DSL_2_C - Range Search](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C)
- **領域和・点更新**: [Yosupo Judge - Point Add Rectangle Sum](https://judge.yosupo.jp/problem/point_add_rectangle_sum)
- **領域更新・領域和 (遅延伝搬)**: [square869120Contest #4 G - Get the Salary of Atcoder](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g)