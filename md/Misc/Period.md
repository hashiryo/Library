---
title: 周期性の検出 (Functional Graph)
documentation_of: ../../src/Misc/Period.hpp
---

## 概要

関数 $f$ による状態遷移 $x_{i+1} = f(x_i)$ で定まる数列を考えます。状態の数が有限である場合、この数列は必ずどこかで周期に入ります（いわゆる「しっぽ付きのサイクル」構造）。

`Period<T>` クラスは、このような状態遷移の構造（Functional Graph）を解析し、以下の機能を提供します。

- ある状態から $k$ 回遷移した後の状態を高速に求める (`jump`)
- ある状態から $k$ 回遷移するまでの軌道を求める (`path`)

内部的には、Functional Graphをいくつかの木に分解し、Heavy-Light Decomposition を利用することで、各クエリを対数時間で処理します。

## `Period<T>` クラス

### テンプレートパラメータ

- `T`: 状態を表す型。`std::map` のキーとして使用できる必要があります。整数型の場合は内部で `std::unordered_map` を利用し高速化されます。

### メンバ関数

| メンバ関数 | 概要 | 計算量 |
| --- | --- | --- |
| `Period(f, init)` | コンストラクタ。<br>関数 `f: T -> T` と初期状態の集合 `init` (`vector<T>`) を渡す。 | $O(A \cdot n \log n)$ or $O(A \cdot n)$ ※1 |
| `Period(functional)` | コンストラクタ。<br>状態が `0, ..., n-1` の整数で、`functional[i]` が状態 `i` の遷移先を表す配列 (`vector<int>`) を渡す。<br> `T` は `int` である必要がある。 | $O(n)$ |
| `size()` | 状態の数 `n` を返す。 | $O(1)$ |
| `operator()(x)` | 状態 `x` に対応する内部ラベル (`int`) を返す。 | $O(\log n)$ or $O(1)$ ※2 |
| `jump(x, k)` | $k$ 回遷移した後の状態 $f^k(x)$ を返す。<br>`k` は `BigInt` など任意の整数型が使用可能。 | $O(\log n)$ |
| `path(x, k)` | $x, f(x), \dots, f^k(x)$ の軌道を表す半開区間の列を返す。<br>戻り値は `tuple<Path, Path, Int, Path>` で、それぞれサイクル前の軌道、サイクル1周の軌道、サイクル周回数、サイクルの余りの軌道を表す。<br>`Path` は `vector<pair<int, int>>` 型。 | $O(\log n)$ |
| `path_upto_cycle(x)` | 状態 `x` からサイクルに入り、サイクルを1周するまでの軌道を返す。 | $O(\log n)$ |

※1: $n$ は状態数、$A$ は関数 `f` の計算量。`T` が整数型でない場合、内部で `std::map` を使うため $\log n$ が付く。整数型の場合は `std::unordered_map` を使い償却 $O(A \cdot n)$。
※2: `T` が整数型でない場合は $O(\log n)$、整数型の場合は償却 $O(1)$。

## 制約

- `T` 型のオブジェクトは `std::map` のキーとして利用できること（比較演算子が定義されていること）。

## Verify

- [AtCoder Beginner Contest 030 D - へんてこ辞書](https://atcoder.jp/contests/abc030/tasks/abc030_d)
