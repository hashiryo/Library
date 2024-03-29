---
title: 全方位木DP
documentation_of: ../../src/Graph/Rerooting.hpp
---

![image of tree dp](https://github.com/hashiryo/Library/blob/master/img/rerooting.drawio.svg?raw=true)

## `Rerooting<T>` クラス
全方位木DPの値(型 : `T` )が入っている配列だと思って使う. (`operator[](int v)`, `begin()`, `end()` がある. )

### コンストラクタ
```c++
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, F1 put_edge, F2 op, U ui, F3 put_vertex) // (1)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, HeavyLightDecomposition hld, F1 put_edge, F2 op, U ui, F3 put_vertex) // (2)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, CSRArray<int> adje, F1 put_edge, F2 op, U ui, F3 put_vertex) // (3)
Rerooting<T>::Rerooting<U,F1,F2,F3>(Graph g, CSRArray<int> adje,  HeavyLightDecomposition hld, F1 put_edge, F2 op, U ui, F3 put_vertex) // (4)
```

|引数|概要|
|---|---|
|`Graph g`|[`Graph` クラス](Graph.hpp)|
|`CSRArray<int> adje`|頂点 → 辺の隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp)) <br> 省略できる (1), (2). (ただし 内部で作ってる)|
|`HeavyLightDecomposition hld`|g を [重軽分解](HeavyLightDecomposition.hpp)したもの. <br> 省略できる (1), (3). (ただし 内部で作ってる) |
|`put_edge(int v, int e, T t) -> U`| 頂点 v と v から出る辺 e の情報によってクラス `T` の値 `t` をモノイド `U` の元に変換|
|`op(U l, U r) -> U`|モノイド `U` の二項演算|
|`U ui`|モノイド `U` の単位元|
|`put_vertex(int v, U sum) -> T`| 頂点 v でモノイド `U` の総積をクラス `T` の値に変換|

### その他メンバ関数

|名前|概要|
|---|---|
|`operator[](int v)`| 頂点 v についての全方位木DPの値を返す.|
|`begin()`|全方位木DPの値配列のイテレータ.|
|`end()`|全方位木DPの値配列のイテレータ.|
|`operator()(int root, int v)`|頂点 root が根である場合の 頂点 v を根とする部分木のDP値を返す.|

## 問題例
[AtCoder Regular Contest 022 C - ロミオとジュリエット](https://atcoder.jp/contests/arc022/tasks/arc022_3) \
[AtCoder Regular Contest 028 C - 高橋王国の分割統治](https://atcoder.jp/contests/arc028/tasks/arc028_3) \
[AtCoder Regular Contest 097 F - Monochrome Cat](https://atcoder.jp/contests/arc097/tasks/arc097_d) \
[Educational DP Contest V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) \
[Typical DP Contest N - 木](https://atcoder.jp/contests/tdpc/tasks/tdpc_tree) \
[square869120Contest #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)\
[NJPC2017 E - 限界集落](https://atcoder.jp/contests/njpc2017/tasks/njpc2017_e)\
[第二回全国統一プログラミング王決定戦本戦 D - 木、](https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_d) (根付き木ハッシュ, 二つの全方位木DP, `operator()(root,v)`) \
[東京工業大学プログラミングコンテスト2019 M - Inversion Numbers of Tree](https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_m)\
[JOI 2018/2019 春合宿 過去問 G - 指定都市 (Designated Cities)](https://atcoder.jp/contests/joisc2019/tasks/joisc2019_g) (全方位木DPでない部分が難しい)\
[yukicoder No.1153 ねこちゃんゲーム](https://yukicoder.me/problems/no/1153) (`operator()(root,v)`, sp judge)\
[Educational Codeforces Round 46 (Div. 2) G. Two-Paths](https://codeforces.com/contest/1000/problem/G) ( + LCA )\
[Educational Codeforces Round 67 (Div. 2) E. Tree Painting](https://codeforces.com/contest/1187/problem/E)\
[Codeforces Round 135 (Div. 2) D. Choosing Capital for Treeland](https://codeforces.com/contest/219/problem/D)\
[Codeforces Round 292 (Div. 1) D. Drazil and Morning Exercise](https://codeforces.com/contest/516/problem/D)\
[Codeforces Round 302 (Div. 1) D. Road Improvement](https://codeforces.com/contest/543/problem/D)\
[Codeforces Round 395 (Div. 1) D. Timofey and a flat tree](https://codeforces.com/contest/763/problem/D) (根付き木ハッシュ)\
[Codeforces Round 397 (Div. 1 + Div. 2 combined) E. Tree Folding](https://codeforces.com/contest/765/problem/E)\
[Codeforces Round 405 (Div. 2) D. Bear and Tree Jumps](https://codeforces.com/contest/791/problem/D)\
[Codeforces Round 615 (Div. 3) F. Three Paths on a Tree](https://codeforces.com/contest/1294/problem/F) (`operator()(root,v)`)\
[Codeforces Round 627 (Div. 3) F. Maximum White Subtree](https://codeforces.com/contest/1324/problem/F)\
[Codeforces Round 695 (Div. 2) E. Distinctive Roots in a Tree](https://codeforces.com/contest/1467/problem/E)\
[Codeforces Round 711 (Div. 2) F. Christmas Game](https://codeforces.com/contest/1498/problem/F) (staircase nim)\
[VK Cup 2012 Round 1 D. Distance in Tree](https://codeforces.com/contest/161/problem/D)\
[AIM Tech Round 3 (Div. 1) C. Centroids](https://codeforces.com/contest/708/problem/C) (`operator()(root,v)`)\
[2022 China Collegiate Programming Contest (CCPC) Guilin Site G. Group Homework](https://codeforces.com/gym/104008/problem/G) (`operator()(root,v)`)\
[LibreOJ #2072. 「JSOI2016」独特的树叶](https://loj.ac/p/2072) (根付き木ハッシュ, 二つの全方位木DP, `operator()(root,v)`)\
[LibreOJ #2192. 「SHOI2014」概率充电器](https://loj.ac/p/2192)\
[LibreOJ #3350. 「CEOI2020」星际迷航](https://loj.ac/p/3350)\
[LibreOJ #6699. 然而第六章的 A 面并没有草莓](https://loj.ac/p/6699) ( + LCA )\
[LibreOJ #10159. 「一本通 5.2 练习 2」旅游规划](https://loj.ac/p/10159) (`operator()(root,v)`)\
[洛谷 P2986 [USACO10MAR] Great Cow Gathering G](https://www.luogu.com.cn/problem/P2986)\
[洛谷 P3047 [USACO12FEB] Nearby Cows G](https://www.luogu.com.cn/problem/P3047)\
[洛谷 P3478 [POI2008] STA-Station](https://www.luogu.com.cn/problem/P3478)\
[洛谷 P3647 [APIO2014] 连珠线](https://www.luogu.com.cn/problem/P3647)\
[洛谷 P6419 [COCI2014-2015#1] Kamp](https://www.luogu.com.cn/problem/P6419)
## 参考
[https://trap.jp/post/1702/](https://trap.jp/post/1702/)