---
title: 周期の利用 (Functionalグラフ)
documentation_of: ../../src/Misc/Period.hpp
---

## `Period<T>` クラス

初期状態が $x_0\in T$ な列 $(x_i)_i$ が次の漸化式で定まっているとする．

$
\displaystyle x_{i+1} = f(x_i)
$

$x_i$ として取りうる状態の数が有限であるときに周期性を利用して巨大な数 $k$ に対する $x_k$ を求める　

などするクラス．

初期状態が複数ある場合でも Functional グラフを重軽分解することで頑張る．

状態 $x$ をいい感じに並び替えて，ラベリングする．

状態の数を $n$ とする．

| メンバ関数 | 概要 | 計算量 |
| --- | --- | --- |
| `Period(f, init)` | コンストラクタ. <br> 関数 $f:T\to T$ と初期状態の集合 $X_0 \subset T $ を渡す． <br> 第二引数は `vector<T>`. |$O(An\log n)$ <br> ただし $f(x)$ の計算に $O(A)$ とかかるとした．<br> $\log$ は連想配列を用いたため．|
| `Period(functional)` | コンストラクタ. <br> 全状態の集合が $V＝\lbrace 0,\dots,n-1\rbrace$ だとして，それぞれの状態の移り先を表す配列 ( $V\to V$ ) を渡す．<br> 引数は `vector<int>`. <br> `T == int` でないと呼べない．| $O(n)$|
|`size()`|状態の数 $n$ を返す．||
|`operator()(x)`| $x$ に対応するラベルを返す．<br> 戻り値は `int`. |
| `jump(x,k)`          | $f^k(x)=\overbrace{f(\cdots f(f}^{k}(x)))$ を返す. <br> 第二引数は何らかの整数型 `Int`．( [`BigInt`クラス](../FFT/BigInt.hpp)も使える．) <br> 戻り値は `T`.| $O(\log n)$ |
| `path(x,k)`          | $x,f(x),\dots,f^k(x)$ という軌道を表す 半開区間の列 を返す．<br> 第二引数は何らかの整数型 `Int`．( [`BigInt`クラス](../FFT/BigInt.hpp)も使える．) <br> 戻り値は4つのデータをラッピングした`tuple`．<br> 一つ目はループに至るまでの軌道．<br> 二つ目はループ一回分を表す軌道．<br> 三つ目はループの回数 `Int`. <br> 四つ目はループの余りの軌道．<br> 軌道は `vector<pair<int,int>>` で表現する半開区間の列 $\lbrack a_0, b_0 ),\dots,\lbrack a_m, b_m )$ であり, $f^i(x)$ のラベルに対応している． | $O(\log n)$ |

## 問題例
[AtCoder Beginner Contest 030 D - へんてこ辞書](https://atcoder.jp/contests/abc030/tasks/abc030_d)