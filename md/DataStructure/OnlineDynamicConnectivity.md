---
title: OnlineDynamicConnectivity
documentation_of: ../../src/DataStructure/OnlineDynamicConnectivity.hpp
---

## 概要
オンラインでグラフの辺の追加・削除を行いながら、連結性や連結成分ごとの集約値をクエリできるデータ構造。
内部で Euler Tour Tree を利用している。

## テンプレートパラメータ
- `typename M`: 頂点の値に乗せるモノイド。
  - `M::T`: 値の型
  - `M::ti()`: 単位元
  - `M::op(l, r)`: 演算
- `std::size_t NODE_SIZE`: Euler Tour Tree が内部で確保するノードの最大サイズ。デフォルトは `4'000'000`。

## 使い方
`OnlineDynamicConnectivity<M> dicon(N)` のように宣言する。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `dicon.link(u, v)` | 頂点 `u` と `v` の間に辺を追加する。多重辺も管理される。 | $O((\log N)^2)$ |
| `dicon.cut(u, v)` | 頂点 `u` と `v` の間の辺を1つ削除する。 | $O((\log N)^2)$ |
| `dicon.connected(u, v)` | 頂点 `u` と `v` が連結か判定する。 | $O(\log N)$ |
| `dicon.set(k, val)` | 頂点 `k` の値を `val` に設定する。 | $O(\log N)$ |
| `dicon.get(k)` / `dicon[k]` | 頂点 `k` の値を取得する。 | $O(\log N)$ |
| `dicon.prod(k)` | 頂点 `k` が属する連結成分の集約値を取得する。 | $O(\log N)$ |
| `dicon.apply(k, f)` | 頂点 `k` が属する連結成分の各頂点に作用素 `f` を適用する。 | $O(\log N)$ |
| `dicon.size(k)` | 頂点 `k` が属する連結成分のサイズを取得する。 | $O(\log N)$ |

## コード例
```cpp
// 連結成分ごとの合計値を管理する例
struct Monoid {
    using T = long long;
    static T ti() { return 0; }
    static T op(T a, T b) { return a + b; }
};

// 頂点数 N で初期化
OnlineDynamicConnectivity<Monoid> dicon(N);

// 各頂点に値をセット
dicon.set(0, 10);
dicon.set(1, 20);
dicon.set(2, 30);

// 辺 (0, 1) を追加
dicon.link(0, 1);

// 頂点 0 と 1 は連結
assert(dicon.connected(0, 1));
// 頂点 0 と 2 は非連結
assert(!dicon.connected(0, 2));

// 頂点 0 が属する連結成分 {0, 1} の合計値は 30
long long sum0 = dicon.prod(0);
assert(sum0 == 30);

// 辺 (0, 1) を削除
dicon.cut(0, 1);

// 頂点 0 と 1 は非連結になる
assert(!dicon.connected(0, 1));

// 頂点 0 が属する連結成分 {0} の合計値は 10
sum0 = dicon.prod(0);
assert(sum0 == 10);
```

## 計算量
- `link`, `cut`: $O((\log N)^2)$
- `connected`, `set`, `get`, `prod`, `apply`, `size`: $O(\log N)$

## 注意点
- `NODE_SIZE` は Euler Tour Tree が内部で動的に確保するノード数を表す。辺の追加・削除の過程でノードは再利用されず、消費され続けるため、クエリ数も考慮して十分に大きな値を設定する必要がある。

## 参考
[https://qiita.com/hotman78/items/78cd3aa50b05a57738d4](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)

## Verify
- [Educational Codeforces Round 62 F. Extending Set of Points](https://codeforces.com/contest/1140/problem/F)
- [AOJ 2235 - Chain Disconnection](https://onlinejudge.u-aizu.ac.jp/problems/2235)
- [AOJ 2893 - To Star a New Journey](https://onlinejudge.u-aizu.ac.jp/problems/2893)
- [Yosupo Judge - Dynamic Graph Vertex Add Component Sum](https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum)