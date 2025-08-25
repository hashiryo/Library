---
title: 区間グラフ (Range to Range Graph)
documentation_of: ../../src/Graph/RangeToRangeGraph.hpp
---

## `RangeToRangeGraph<cost_t=int>` クラス

点 $0, 1, \dots, n-1$ を扱うグラフに対して、点・区間間の辺を効率的に追加するためのクラス。
内部でセグメント木に似た構造を持つ補助グラフを構築する。元の $n$ 個の点に加え、区間を表すための補助的な頂点が追加される。

- **頂点数**: コンストラクタ `RangeToRangeGraph(n)` を呼び出した時点で、$3n$ 個の頂点を持つグラフが構築される。
  - 頂点 $0, \dots, n-1$ が元のグラフの頂点に対応する。
  - `add_from_range_to_range` を呼び出すたびに、中間頂点が1つずつ追加される。
- **辺**: 追加された辺はメンバ変数 `graph` に格納され、その重みは `weight` に格納される。

### メンバ変数

|メンバ変数|概要|
|---|---|
|`graph`|構築された有向グラフ本体。[`Graph` クラス](Graph.md)のインスタンス。|
|`weight`|`graph` の各辺に対応する重みのリスト。`vector<cost_t>`。|

### メンバ関数

|メンバ関数|概要|計算量|
|---|---|---|
|`RangeToRangeGraph(n)`|コンストラクタ。$n$ 個の点を扱うグラフを初期化する。|$O(n)$|
|`add(s,t,w=0)`|点 $s$ から点 $t$ へ重み $w$ の有向辺を追加する。|$O(1)$|
|`add_from_range(s_l,s_r,t,w=0)`|区間 $\lbrack s_l, s_r)$ 内の各点から点 $t$ へ重み $w$ の有向辺を追加する。|$O(\log n)$|
|`add_to_range(s,t_l,t_r,w=0)`|点 $s$ から区間 $\lbrack t_l, t_r)$ 内の各点へ重み $w$ の有向辺を追加する。|$O(\log n)$|
|`add_from_range_to_range(s_l,s_r,t_l,t_r,w=0)`|区間 $\lbrack s_l, s_r)$ から区間 $\lbrack t_l, t_r)$ への辺を追加する。これは、区間 $\lbrack s_l, s_r)$ 内の任意の点 $u$ から、区間 $\lbrack t_l, t_r)$ 内の任意の点 $v$ への経路が存在することを意味する。 <br> **実装**: 内部で新しい中間頂点 $p$ を追加し、区間 $\lbrack s_l, s_r)$ から $p$ へ重み $w$ の辺を、 $p$ から区間 $\lbrack t_l, t_r)$ へ重み $0$ の辺を張る。|$O(\log n)$|

## 使用例

`graph` と `weight` を用いて最短路を計算する例。

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include "src/Graph/RangeToRangeGraph.hpp"

// main 関数内
int n, m;
std::cin >> n >> m;

RangeToRangeGraph<long long> r2r(n);

for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    // 例: 点uから点vへ重みwの辺
    r2r.add(u, v, w);
}

// グラフの実際の頂点数を取得
int V = r2r.graph.vertex_size();
auto adj = r2r.graph.adjacency_edge(1); // 辺eのインデックスを取得できる隣接リスト
std::vector<long long> dist(V, -1);
std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>,
                    std::greater<std::pair<long long, int>>> pq;

dist[0] = 0;
pq.push({0, 0});

while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (dist[v] != -1 && dist[v] < d) continue;

    for (auto e : adj[v]) {
        int u = r2r.graph[e].to(v);
        long long cost = r2r.weight[e];
        if (dist[u] == -1 || dist[u] > d + cost) {
            dist[u] = d + cost;
            pq.push({dist[u], u});
        }
    }
}

// 結果を出力
// ...
```

## Verify

- [灘校文化祭コンテスト 2022 Day1 I - NPCA Kingdom](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_i)

## 参考
- [セグメント木上の辺で区間グラフを表現する話 - ロレントの研究記録](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
