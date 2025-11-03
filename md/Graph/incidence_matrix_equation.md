---
title: グラフの接続行列に関する連立方程式
documentation_of: ../../src/Graph/incidence_matrix_equation.hpp
---

## 概要
有向グラフ $g=(V, E)$ と、各頂点 $v \in V$ に対応する値を持つベクトル $\boldsymbol{b}$ が与えられたとき、連立方程式 $A\boldsymbol{x} = \boldsymbol{b}$ を解く。

ここで $A$ はグラフ $g$ の**接続行列 (incidence matrix)** であり、$|V| \times |E|$ のサイズを持つ。辺 $e=(u, v)$ に対応する $A$ の列は、頂点 $u$ に対応する行が $-1$、頂点 $v$ に対応する行が $1$ で、それ以外の行は $0$ となる。

この方程式は、各頂点での流入・流出の差が $\boldsymbol{b}$ に等しくなるような、各辺のフロー（あるいはポテンシャル差）$\boldsymbol{x}$ を求める問題と解釈できる。

解が存在するための必要十分条件は、グラフの各連結成分において、対応する $\boldsymbol{b}$ の要素の総和が $0$ (より一般には `T()`) となることである。この条件が満たされない場合、解は存在しない。

### T=bool の場合
テンプレートパラメータ `T` が `bool` の場合、体 $\mathbb{F}_2$ 上で計算が行われる。このとき、接続行列の要素は $-1$ と $1$ の区別がなくなり、辺で結ばれている頂点に対応する要素が $1$ となる。これは、無向グラフとして扱った場合の接続行列方程式を解いていることと等価である。

|関数名|概要|計算量|
|---|---|---|
|`incidence_matrix_equation<T>(g, b)`|有向グラフ $g$ の接続行列 $A$ とベクトル $\boldsymbol{b}$ に対して、$A\boldsymbol{x}=\boldsymbol{b}$ を満たすベクトル $\boldsymbol{x}$ を一つ返す。<br> 解が存在しない場合は空の `vector` を返す。| $O(|V|+|E|)$ |

## 引数
- `const Graph &g`: 有向グラフ。多重辺や自己ループを含んでいてもよい。
- `std::vector<T> b`: 各頂点に対応する値のベクトル。`b.size()` は `g.vertex_size()` と等しくなければならない。

## 戻り値
- `std::vector<T>`:
  - 解が存在する場合: 方程式の解 $\boldsymbol{x}$ を返す。`x.size()` は `g.edge_size()` と等しく、`x[i]` は `g` に `i` 番目に追加された辺に対応する。解が複数存在する場合、そのうちの一つを返す。
  - 解が存在しない場合: 空の `vector` を返す。

## 制約
- テンプレートパラメータ `T` は、加減算が定義されており、`T()` でゼロ元が取得できる型である必要がある。`bool` の場合は $\mathbb{F}_2$ 上の演算が用いられる。

## Verify
- [AtCoder Beginner Contest 155 F - Perils in Parallel](https://atcoder.jp/contests/abc155/tasks/abc155_f) (sp judge)
- [AtCoder Grand Contest 035 B - Even Degrees](https://atcoder.jp/contests/agc035/tasks/agc035_b) (sp judge)
- [AtCoder Regular Contest 106 B - Values](https://atcoder.jp/contests/arc106/tasks/arc106_b)
- [Codeforces Round #527 (Div. 3) F. Tree with Maximum Cost](https://codeforces.com/contest/1095/problem/F)
- [AOJ 3142 Path Add Query](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3142)