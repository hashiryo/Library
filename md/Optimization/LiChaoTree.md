---
title: Li-Chao-Tree
documentation_of: ../../src/Optimization/LiChaoTree.hpp
---
( 例えば 一次関数などの ) 高々一点で交わる $x$ の関数の集合

$\displaystyle
f_i(x) = f(x; \boldsymbol{p}^{(i)})= f(x;p^{(i)}_0,\dots,p^{(i)}_n)
$ 

を扱うデータ構造. \
浮動小数点数もいけるはず. \
2点以上で交わる可能性がある関数の集合を挿入した時の動作は未定義.\
クラステンプレートは推論させる.

## 使用例
宣言
```c++
auto f = [](long long x, int a, int b){return a * x + b;}; // ax+b
LiChaoTree lct(f);
auto tree = lct.make_tree<MINIMIZE>();
```
クエリ
```c++
tree.insert(2, 3); // 2x+3
tree.insert(1, 1, 0, 2); // x+1 (0<= x < 2)
auto [val1, id1] = tree.query(1);
cout << val1 << " "<< id1 << '\n'; // 2 1
auto [val2, id2] = tree.query(-1);
cout << val2 << " "<< id2 << '\n'; // 1 0
```

## `LiChaoTree` クラス
まず初期化のために触るクラス. \
内部で関数やパラメータを格納したりの役割がある.

|メンバ関数|概要|
|---|---|
|`LiChaoTree(f, LB, UB)`|コンストラクタ. <br> $x$ の関数 $f(x;p_0,\dots,p_n)$ を渡す. <br> クエリ引数 $x$ の収まる範囲を半開区間 $\lbrack \mathrm{LB}, \mathrm{UB})$ で渡す. ( デフォルトは `LB=-2e9`, `UB=2e9`)|
|`make_tree<sgn, persistent>()`| `LiChaoTreeInterface` クラスのオブジェクトを返す. <br> 何も関数が挿入されていない空のデータ構造を返す. <br> template 第一引数で最小か最大を指定する. (デフォルトは最小) <br> template 第二引数が true なら永続化. (デフォルトはfalse)|

## `LiChaoTreeInterface` クラス

メインで触ることになるもの.

|メンバ関数|概要|計算量|
|---|---|---|
| `insert(p_0,...,p_n)` |関数 $f(x;p_0,\dots,p_n)$ を挿入. | $O(\log n)$　|
| `insert(p_0,...,p_n,l)`| 半開区間制約付きの関数 $f(x;p_0,\dots,p_n) \hspace{1mm}x\in\lbrack l,\mathrm{UB}) $ を挿入. | $O((\log n)^2)$　|
| `insert(p_0,...,p_n,l,r)`| 半開区間制約付きの関数 $f(x;p_0,\dots,p_n) \hspace{1mm}x\in\lbrack l,r) $ を挿入. | $O((\log n)^2)$　|
|`query(x)` | { $x$ における最小値(最大値), それを達成する関数の番号 } を返す. <br>存在しない場合 { 未定義, -1 } を返す. |$O(\log n)$ | 
|`parms(i)` | $i$ 番目の関数のパラメータを返す．|$O(1)$ | 

## 問題例

[Kyoto University Programming Contest 2019 L - タケノコ](https://atcoder.jp/contests/kupc2019/tasks/kupc2019_l) (永続) \
[AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d) (doubleでac) \
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (有理数クラス, doubleでac) \
[COLOCON -Colopl programming contest 2018- Final C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c) \
[技術室奥プログラミングコンテスト#2 F - NPCの家 (NPC's House)](https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_f) 