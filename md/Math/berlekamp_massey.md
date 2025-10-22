---
title: Berlekamp-Massey Algorithm
documentation_of: ../../src/Math/berlekamp_massey.hpp
---

## 概要
与えられた数列 $a = \lbrace a_0, a_1, \dots, a_{N-1} \rbrace$ を生成する最短の線形漸化式
$$
a_i = \sum_{j=1}^{d} c_j a_{i-j} \quad (i \ge d)
$$
を求めるアルゴリズム。

返り値は係数のベクトル `c` であり、`c[j-1]` が上記の式の係数 $c_j$ に対応する。

## テンプレートパラメータ
- `K`: 体 (field) である型。四則演算が定義されている必要がある。
  - 例: `ModInt`, `double`, `Rational`

## 関数
- `berlekamp_massey(const vector<K>& a)`
  - 引数 `a`: 線形漸化式を満たす数列の最初の $N$ 項。
  - 返り値: 最短線形漸化式の係数列 `c`。

## 使い方
```cpp
// a = {1, 2, 4, 8, 16, ...}
vector<ModInt<998244353>> a = {1, 2, 4, 8, 16};
auto c = berlekamp_massey(a);
// c = {2}
// a_i = 2 * a_{i-1}
```

## 計算量
$O(N^2)$
- $N$ は入力数列 `a` の長さ

## Verify
- [yosupo judge - Find Linear Recurrence](https://judge.yosupo.jp/problem/find_linear_recurrence)
- [天下一プログラマーコンテスト2015予選B C - 擬二等辺三角形](https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c)