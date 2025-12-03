---
title: 多項式行列の総積
documentation_of: ../../src/FFT/polynomial_matrix_prod.hpp
---

## 概要
$d$ 次多項式を要素に持つ $n \times n$ の正方行列を $M(x)$ とする。
このとき、行列の総積 $M(0) \cdot M(1) \cdot \dots \cdot M(k-1)$ を高速に計算する。

## テンプレートパラメータ
- `mod_t`: modint の型
- `LM`: FFTのサイズ（省略可能、デフォルトは `1 << 20`）

## 引数
- `const std::vector<std::vector<std::vector<mod_t>>> &m`:
  - $n \times n$ の多項式行列 $M(x)$ を表す。
  - `m[i][j]` は $(i, j)$ 成分の多項式 $p(x)$ を表す `std::vector<mod_t>`。
  - 多項式 $p(x)$ は係数表現で `p(x) = m[i][j][0] + m[i][j][1]x + ...` のように格納する。
- `std::uint64_t k`:
  - 総積を計算する行列の数。$M(0)$ から $M(k-1)$ までの積を計算する。

## 返り値
- `std::vector<std::vector<mod_t>>`:
  - $M(0) \cdot M(1) \cdot \dots \cdot M(k-1)$ の計算結果である $n \times n$ 行列。

## 制約
- `m` は $n \times n$ の正方行列でなければならない ($n > 0$)。

## 計算量
$O(\sqrt{k} \log k \cdot \mathrm{poly}(n, d))$
- $n$: 行列のサイズ
- $d$: 多項式の最大次数

## 使用例
$k! \pmod{10^9+7}$ を計算する例。
これは $M(x) = [1+x]$ として、$M(0) \cdot M(1) \cdot \dots \cdot M(k-1) = 1 \cdot 2 \cdot \dots \cdot k = k!$ となることを利用している。

```cpp
#include <iostream>
#include "src/Math/ModInt.hpp"
#include "src/FFT/polynomial_matrix_prod.hpp"

void factorial_example() {
    using Mint = ModInt<1000000007>;
    long long k = 100;

    // M(x) = [1+x]
    std::vector<std::vector<std::vector<Mint>>> m(1, std::vector<std::vector<Mint>>(1));
    m[0][0] = {1, 1}; // 1 + 1*x

    Mint result = polynomial_matrix_prod<Mint>(m, k)[0][0];
    // result は k! mod 10^9+7
    std::cout << result << std::endl;
}
```
