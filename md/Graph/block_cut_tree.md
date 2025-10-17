---
title: 二点連結成分分解 (Block-Cut Tree)
documentation_of: ../../src/Graph/block_cut_tree.hpp
---

無向グラフを二点連結成分分解（ブロックカット分解）し、その構造を木（森）で表現する Block-Cut Tree を構築する。

![図：左が元グラフ、右が構築されたBlock-Cut Tree。丸が元頂点、四角が二点連結成分（ブロック）を表す頂点。](https://github.com/hashiryo/Library/blob/master/img/bct.drawio.svg?raw=true)

|関数名|概要|計算量|
|---|---|---|
|`block_cut_tree(const CSRArray<int>& adj)` <br> `block_cut_tree(const Graph& g)` |無向グラフ `g` を二点連結成分分解して構築した Block-Cut Tree を返す。 <br> 引数は [`Graph`クラス](Graph.hpp) または隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp))で渡す。 <br> 返り値は `Graph` クラス。|$O(V+E)$ |

### Block-Cut Tree の構造

頂点数 $V$ の無向グラフ $g$ の二点連結成分（ブロック）の個数を $C$ とする。
構築される Block-Cut Tree は頂点数が $V+C$ の森である。

- **元頂点**: `0` から `V-1` の頂点が対応する。
  - Block-Cut Tree 上で、元頂点に隣接するのはブロック頂点のみである。
  - 次数が 2 以上の元頂点は、元グラフの**関節点** (articulation point) にあたる。
- **ブロック頂点**: `V` から `V+C-1` の頂点が対応する。
  - 各頂点は、元グラフの各二点連結成分（ブロック）を表す。
  - ブロック頂点に隣接するのは、そのブロックに属する元頂点のみである。
- **孤立点**: 元グラフの孤立点は、次数0の元頂点として表現される。

### 使い方

```cpp
// 頂点数N, 辺数Mのグラフgを構築
int N, M;
std::cin >> N >> M;
Graph g(N, M); // N頂点M辺のグラフを生成
for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    g.add_edge(u, v);
}

// Block-Cut Treeを構築
Graph bct = block_cut_tree(g);

// 各二点連結成分（ブロック）に属する頂点を列挙
// ブロック頂点は元のグラフの頂点数Nから始まる
int num_blocks = bct.vertex_size() - N;
for (int i = 0; i < num_blocks; ++i) {
    int block_node = N + i;
    std::cout << "Block " << i << ":";
    for (const auto& edge : bct.adj(block_node)) {
        int vertex_node = edge.to;
        std::cout << " " << vertex_node;
    }
    std::cout << std::endl;
}
```

### 制約
- 無向グラフを対象とする。
- 自己ループは無視される。
- 多重辺は1つの辺として扱われる（縮約される）。

## 参考
- [noshi91氏のツイート](https://twitter.com/noshi91/status/1529858538650374144)
- [Block-Cut Tree - なちあの学習帳](https://nachiavivias.github.io/cp-library/column/2022/01.html)