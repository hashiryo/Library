---
title: Cartesian-Tree
documentation_of: ../../src/Misc/CartesianTree.hpp
---

<img src="https://github.com/hashiryo/Library/blob/master/img/cartesiantree.svg?raw=true" width="60%">

配列 `a` から構築される二分木であり、以下の条件を満たす。
- 頂点 `i` は `a[i]` に対応する。
- `i` が `j` の親であるとき、`a[i] >= a[j]` (max-heap property) または `a[i] <= a[j]` (min-heap property) が成り立つ。
- 頂点を `in-order` で巡回すると、元の配列の添字順 `0, 1, ..., n-1` と一致する。

## メンバ関数

| 名前 | 概要| 計算量 |
| --- | --- | --- |
| `CartesianTree(const Vec& a, bool is_min = true)` | コンストラクタ。<br> 配列 `a` をもとに構築する。`is_min` が `true` なら最小値が親 (min-heap property)、 `false` なら最大値が親 (max-heap property) になるように構築する。<br> `Vec` は `a[i]` で要素アクセス可能なコンテナ型。 | $O(N)$ |
| `range(int i)` | `a[i]` が最小（または最大）となるような `i` を含む極大な半開区間 `[l, r)` を返す。 | $O(1)$ |
| `root()` | Cartesian-Treeの根の添字を返す。 | $O(1)$ |
| `parent(int i)` | 頂点 `i` の親の添字を返す。根の親は `-1` を返す。 | $O(1)$ |
| `children(int i)` | 頂点 `i` の子の添字を `std::array<int, 2>` で返す。左の子、右の子の順で格納される。子がいない場合は `-1` を返す。 | $O(1)$ |

## 使用例
```cpp
#include <iostream>
#include <vector>
#include "src/Misc/CartesianTree.hpp"

int main() {
    std::vector<int> a = {3, 1, 4, 5, 9, 2, 6};
    // a[i] <= a[parent(i)] となるように構築 (min-heap property)
    CartesianTree ct(a, true);

    // 親を出力する
    // 根の親は-1だが、問題の仕様に応じて根自身を出力する場合が多い
    for (int i = 0; i < a.size(); ++i) {
        int p = ct.parent(i);
        std::cout << (p == -1 ? i : p) << (i == a.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
    // 出力: 1 1 1 2 2 1 5
}
```

## Verify
- [AtCoder Beginner Contest 275 Ex - Monster](https://atcoder.jp/contests/abc275/tasks/abc275_h)(木上をdfs)
- [yosupo judge - cartesian_tree](https://judge.yosupo.jp/problem/cartesian_tree)