---
title: Online-Dynamic-Connectivity
documentation_of: ../../src/DataStructure/OnlineDynamicConnectivity.hpp
---

## 概要
オンラインでグラフの辺の追加・削除を行いながら、連結性や連結成分ごとの集約値をクエリできるデータ構造。
内部で Euler Tour Tree を利用している。

## テンプレートパラメータ
- `typename M`: (省略可) 頂点の値に乗せるモノイド。省略した場合、連結性の判定のみ可能となり、値に関する操作はできなくなる。
  - `M::T`: 値の型
  - `M::ti()`: 単位元
  - `M::op(l, r)`: 演算
- `std::size_t NODE_SIZE`: (省略可) 内部の Euler Tour Tree が確保するノードの最大サイズ。デフォルトは `4'000'000`。クエリ回数や頂点数に応じて調整が必要。

## 使い方
`OnlineDynamicConnectivity<M> dicon(N)` のように宣言する。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `dicon.link(u, v)` | 頂点 `u` と `v` の間に辺を追加する。 | $O((\log N)^2)$ |
| `dicon.cut(u, v)` | 頂点 `u` と `v` の間の辺を削除する。 | $O((\log N)^2)$ |
| `dicon.connected(u, v)` | 頂点 `u` と `v` が連結か判定する。 | $O(\log N)$ |
| `dicon.size(k)` | 頂点 `k` が属する連結成分のサイズを取得する。 | $O(\log N)$ |
| `dicon.set(k, val)` | (`M`指定時のみ) 頂点 `k` の値を `val` に設定する。 | $O(\log N)$ |
| `dicon.get(k)` / `dicon[k]` | (`M`指定時のみ) 頂点 `k` の値を取得する。 | $O(\log N)$ |
| `dicon.prod(k)` | (`M`指定時のみ) 頂点 `k` が属する連結成分の集約値を取得する。 | $O(\log N)$ |
| `dicon.apply(k, v)` | (`M`指定時のみ) 頂点 `k` が属する連結成分の各頂点に作用素 `v` を適用する。 | $O(\log N)$ |

## コード例
### 連結成分ごとの合計値を管理する場合
```cpp
#include <iostream>
#include "DataStructure/OnlineDynamicConnectivity.hpp"

// 連結成分ごとの合計値を管理するモノイド
struct Monoid {
    using T = long long;
    static T ti() { return 0; }
    static T op(T a, T b) { return a + b; }
};

void sample_with_monoid() {
    int N = 5;
    OnlineDynamicConnectivity<Monoid> dicon(N);

    // 各頂点に値を設定
    dicon.set(0, 10);
    dicon.set(1, 20);
    dicon.set(2, 30);
    dicon.set(3, 40);
    dicon.set(4, 50);

    // 辺 (0, 1), (2, 3) を追加
    dicon.link(0, 1);
    dicon.link(2, 3);

    // {0, 1}, {2, 3}, {4} の3つの連結成分
    std::cout << "Sum of component 0: " << dicon.prod(0) << std::endl; // 10 + 20 = 30
    std::cout << "Sum of component 2: " << dicon.prod(2) << std::endl; // 30 + 40 = 70
    std::cout << "Sum of component 4: " << dicon.prod(4) << std::endl; // 50

    // 辺 (1, 2) を追加
    dicon.link(1, 2);
    // {0, 1, 2, 3}, {4} の2つの連結成分
    std::cout << "Sum of component 0 after link: " << dicon.prod(0) << std::endl; // 30 + 70 = 100

    // 辺 (2, 3) を削除
    dicon.cut(2, 3);
    // {0, 1, 2}, {3}, {4} の3つの連結成分
    std::cout << "Sum of component 0 after cut: " << dicon.prod(0) << std::endl; // 10 + 20 + 30 = 60
    std::cout << "Sum of component 3 after cut: " << dicon.prod(3) << std::endl; // 40
}
```

### 連結性のみを管理する場合
```cpp
#include <iostream>
#include "DataStructure/OnlineDynamicConnectivity.hpp"

void sample_connectivity_only() {
    int N = 4;
    // モノイドを省略
    OnlineDynamicConnectivity dicon(N);

    dicon.link(0, 1);
    dicon.link(2, 3);

    std::cout << std::boolalpha;
    std::cout << "0 and 1 connected? " << dicon.connected(0, 1) << std::endl; // true
    std::cout << "0 and 2 connected? " << dicon.connected(0, 2) << std::endl; // false

    dicon.link(1, 2);
    std::cout << "0 and 2 connected? " << dicon.connected(0, 2) << std::endl; // true

    dicon.cut(1, 2);
    std::cout << "0 and 2 connected? " << dicon.connected(0, 2) << std::endl; // false
}
```

## 参考
[https://qiita.com/hotman78/items/78cd3aa50b05a57738d4](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)

## Verify
- [Educational Codeforces Round 62 F. Extending Set of Points](https://codeforces.com/contest/1140/problem/F)
- [AOJ 2235 - Chain Disconnection](https://onlinejudge.u-aizu.ac.jp/problems/2235)
- [AOJ 2893 - To Star a New Journey](https://onlinejudge.u-aizu.ac.jp/problems/2893)
- [Yosupo Judge - Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum)
