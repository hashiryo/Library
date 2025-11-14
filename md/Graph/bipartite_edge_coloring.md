---
title: 二部グラフの辺彩色
documentation_of: ../../src/Graph/bipartite_edge_coloring.hpp
---

## 概要

二部グラフの辺を、隣接する辺が同じ色にならないように彩色する。ケーニヒの定理の系より、二部グラフの辺彩色は頂点の最大次数を $\Delta$ とすると、常に $\Delta$ 色で可能である。

この実装は、分割統治法に基づき、最大マッチングを繰り返し解くことで辺彩色を構築する。

|関数名|概要|計算量|
|---|---|---|
|`bipartite_edge_coloring(bg)`|二部グラフ `bg` の辺彩色を構築する。<br> 引数は [`BipartiteGraph` クラス](./BipartiteGraph.md)のインスタンス。<br> 戻り値は、各辺の色を示す `vector<int>`。`bg` に登録された $i$ 番目の辺の色が、ベクトルの $i$ 番目の要素に格納される。<br> 彩色数は頂点の最大次数 $\Delta$ に一致し、色は $0, 1, \dots, \Delta-1$ で表現される。| $O(E\sqrt{V}\log \Delta)$ <br> ただし $\Delta$ は頂点の最大次数。 |

## 使用例

```cpp
#include <iostream>
#include <algorithm>
#include "src/Graph/BipartiteGraph.hpp"
#include "src/Graph/bipartite_edge_coloring.hpp"

int main() {
    // 左側頂点数 L, 右側頂点数 R, 辺数 M
    int L = 3, R = 3, M = 5;
    BipartiteGraph bg(L, R);

    // 辺を追加 (0-0, 0-1, 1-1, 1-2, 2-0)
    // 右側頂点のインデックスは L を足して区別する
    bg.add_edge(0, 0 + L);
    bg.add_edge(0, 1 + L);
    bg.add_edge(1, 1 + L);
    bg.add_edge(1, 2 + L);
    bg.add_edge(2, 0 + L);

    // 辺彩色を実行
    auto colors = bipartite_edge_coloring(bg);

    // 彩色数を計算（頂点の最大次数と一致する）
    int num_colors = 0;
    if (!colors.empty()) {
        num_colors = *std::max_element(colors.begin(), colors.end()) + 1;
    }
    std::cout << "Number of colors: " << num_colors << std::endl;

    // 各辺の色を出力
    for (size_t i = 0; i < bg.edge_size(); ++i) {
        auto [u, v] = bg[i];
        std::cout << "Edge " << u << "-" << v << " is colored " << colors[i] << std::endl;
    }

    return 0;
}
```

### 出力例
```
Number of colors: 3
Edge 0-3 is colored 0
Edge 0-4 is colored 1
Edge 1-4 is colored 2
Edge 1-5 is colored 0
Edge 2-3 is colored 2
```
*注: `BipartiteGraph`クラスでは、左右の頂点集合を区別するため、右側頂点のインデックスは `[L, L+R)` の範囲になるようにオフセットして扱う必要がある。*


## Verify

- [AtCoder Grand Contest 037 D - Sorting a Grid](https://atcoder.jp/contests/agc037/tasks/agc037_d) (sp judge)

## 参考
- [二部グラフの辺彩色](https://ei1333.hateblo.jp/entry/2020/08/25/015955)
