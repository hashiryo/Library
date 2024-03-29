---
title: (暗黙的な)二部グラフ
documentation_of: ../../src/old/BipartiteGraph.hpp
---
明示的に二部グラフを与えない \
内部で頂点の色分けを自動で行う \
色0が左、色1が右を意味する

## メンバ関数

| 関数名                  | 内容                                                                              | 計算量                              |
| ----------------------- | --------------------------------------------------------------------------------- | ----------------------------------- |
| `BipartiteGraph(N)`     | コンストラクタ. 二部グラフの頂点数 N を渡す                                       |                                     |
| `add_edge(u,v)`         | 無向辺 (u,v) を追加                                                               |                                     |
| `build()`               | 頂点の色分け、マッチング、DM分解を実行                                            | $\mathcal{O}\left(E\sqrt{V}\right)$ |
| `color(v)`              | 頂点 v の色 ( 0 or 1 ) を返す                                                     |                                     |
| `component_num()`       | DM分解で分割された集合の個数(K+1)を返す                                           |                                     |
| `belong(v)`             | 頂点 v の所属先 ( DM分解で分割された集合 ) を返す                                 |                                     |
| `block(k)`              | DM分解で分割された集合の k 番目のものを返す                                       |                                     |
| `match(v)`              | (最大マッチングの一つを固定して) 頂点 v のマッチング相手を返す. 存在しないなら -1 |                                     |
| `max_matching()`        | (最大マッチングの一つを固定して) マッチングに使う辺を返す                         |                                     |
| `min_vertex_cover()`    | 最小頂点被覆を返す. 辞書順最小のものを返す                                        |                                     |
| `max_independent_set()` | 最大独立集合を返す. 辞書順最小のものを返す(はず)                                  |                                     |


## 問題例
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (頂点:2e5+4e5, 辺:4e5) \
[東京大学プログラミングコンテスト2013 K - 辞書順最小頂点被覆](https://atcoder.jp/contests/utpc2013/tasks/utpc2013_11) (辞書順最小頂点被覆のverify)