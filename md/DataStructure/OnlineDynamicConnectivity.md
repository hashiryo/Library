---
title: Online-Dynamic-Connectivity
documentation_of: ../../src/DataStructure/OnlineDynamicConnectivity.hpp
---
単位元は必要あり（遅延側は必要なし）\
各ノードが部分木のサイズを保持しているのでmapping関数では引数としてsizeを渡せる
## 計算量
- `link`, `cut`: $\mathcal{O}((\log N)^2)$
- `connected`: $\mathcal{O}(\log N)$
## 参考
[https://qiita.com/hotman78/items/78cd3aa50b05a57738d4](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)