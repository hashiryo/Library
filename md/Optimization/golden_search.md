---
title: 黄金分割探索 (Golden-section search)
documentation_of: ../../src/Optimization/golden_search.hpp
---

## 概要

実数上の単峰関数 (unimodal function) の最小値または最大値を求めるアルゴリズム。探索範囲を黄金比を用いて狭めていくことで、効率的に最適解を探索する。
単峰関数とは、最適解をただ一つ持つ関数のことで、その最適解を境に関数の単調性が変化するものを指す。例えば、最小化の場合は下に凸な関数、最大化の場合は上に凸な関数などがこれに相当します。

対象とする関数の引数の型は `long double`。引数の型が整数な単峰関数を対象にする場合は[フィボッチ探索](../fibonacci_search.hpp) を使う。

### 計算量

関数 `f(x)` の評価に $O(A)$ の計算量がかかるとしたとき、全体の計算量は $O(A \cdot \text{iter})$ となる。
ここで `iter` は反復回数。

## インクルード

```cpp
#include "src/Optimization/golden_search.hpp"
```

## 関数

| 名前 | 概要 |
|---|---|
| `golden_search<obj>(f, l, r, iter=100)` | 区間 $\lbrack l, r\rbrack$ 上で単峰となる関数 $f(x)$ の最適値とその最適解を返す。<br> **テンプレート引数 `obj`**: `MinMaxEnum::MINIMIZE` (最小化) または `MinMaxEnum::MAXIMIZE` (最大化) を指定する。<br> **引数**: <br> - `f`: 対象の関数オブジェクト (ラムダ式など)。`long double` を受け取り、評価値を返す。<br> - `l`, `r`: 探索範囲の下限と上限 (`long double`)。<br> - `iter`: 反復回数 (`int`)。デフォルトは100。精度に影響する。<br> **返り値**: `{最適解, 最適値}` の `std::pair<long double, decltype(f(l))>`。`second` の型は `f` の返り値の型に一致する。 |

## 使用例

### 最小化

二次関数 $f(x) = (x-2)^2$ の最小値を求める。

```cpp
#include <iostream>
#include <iomanip>
#include "src/Optimization/golden_search.hpp"

int main() {
    auto f = [](long double x) {
        return (x - 2.0) * (x - 2.0);
    };

    // 探索範囲 [-10.0, 10.0] で f(x) を最小化する
    auto result = golden_search<MINIMIZE>(f, -10.0, 10.0);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "x_min = " << result.first << std::endl;
    std::cout << "f(x_min) = " << result.second << std::endl;

    return 0;
}
```

#### 出力

```
x_min = 2.0000000000
f(x_min) = 0.0000000000
```

### 最大化

二次関数 $f(x) = -(x-2)^2 + 10$ の最大値を求める。

```cpp
#include <iostream>
#include <iomanip>
#include "src/Optimization/golden_search.hpp"

int main() {
    auto f = [](long double x) {
        return -(x - 2.0) * (x - 2.0) + 10.0;
    };

    // 探索範囲 [-10.0, 10.0] で f(x) を最大化する
    auto result = golden_search<MAXIMIZE>(f, -10.0, 10.0);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "x_max = " << result.first << std::endl;
    std::cout << "f(x_max) = " << result.second << std::endl;

    return 0;
}
```

#### 出力

```
x_max = 2.0000000000
f(x_max) = 10.0000000000
```