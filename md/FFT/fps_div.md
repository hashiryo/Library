# 多項式の除算

## 概要

多項式 $f(x), g(x)$ ($g(x) \neq 0$) が与えられたとき、$f(x) = q(x)g(x) + r(x)$ を満たす多項式 $q(x), r(x)$ を求める。ここで $\deg r < \deg g$ である。

`FormalPowerSeries` クラスの `div_mod` メソッドで計算できる。

## 計算量

$O(N \log N)$
($N$ は $f$ の次数)

## 使用方法

```cpp
auto [q, r] = f.div_mod(g); // q: 商, r: 余り
```

## verify

- [Library Checker - Division of Polynomials](https://judge.yosupo.jp/problem/division_of_polynomials)
  - [提出コード](https://github.com/kurenaif/library/blob/master/test/yosupo/polynomial/division_of_polynomials.test.cpp)

## 関連

- [形式的べき級数の逆元](./fps_inv.md)

