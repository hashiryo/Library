---
title: 2-SAT
documentation_of: ../../src/Misc/TwoSatisfiability.hpp
---

## 概要
2-Satisfiability (2-SAT) は、各節が高々 2 つのリテラル（変数またはその否定）の論理和で表される論理式の充足可能性を判定する問題です。

$N$ 個のブール変数 $x_0, x_1, 
udots, x_{N-1}$ があり、 $(x_i 
u {
u}x_j)$ のような形式の節が $M$ 個与えられたとき、全ての節を同時に満たすような真偽値の割り当てが存在するかを判定し、存在するならその一例を構築します。

強連結成分分解 (SCC) を用いて、$O(N+M)$ で解くことができます。

## 使い方
`TwoSatisfiability sat(N)` で $N$ 個の変数を持つインスタンスを生成します。変数は `0` から `N-1` の整数で表されます。

リテラル $
u x_i$ は `sat.neg(i)` で表現します。

### メソッド
- `add_if(u, v)`: $u 
uto v$ という節を追加
- `add_or(u, v)`: $u 
u
u v$ という節を追加
- `add_nand(u, v)`: $
u(u 
u
u v)$ という節を追加
- `set_true(u)`: $u$ が真であるという節を追加
- `set_false(u)`: $u$ が偽であるという節を追加
- `solve()`: 充足可能か判定し、可能な場合は各変数の真偽値割り当て `std::vector<bool>` を返す。不可能な場合は空のベクターを返す。

## 計算量
$O(N+M)$
- $N$: 変数の数
- $M$: 節の数

## コード例
```cpp
#include <iostream>
#include "src/Misc/TwoSatisfiability.hpp"

int main() {
    // 変数 x0, x1, x2 を用意
    TwoSatisfiability sat(3);

    // (x0 or x1)
    sat.add_or(0, 1);
    // (!x1 or x2)
    sat.add_or(sat.neg(1), 2);
    // (!x0 or !x2)
    sat.add_or(sat.neg(0), sat.neg(2));

    auto result = sat.solve();

    if (result.empty()) {
        std::cout << "UNSATISFIABLE" << std::endl;
    } else {
        std::cout << "SATISFIABLE" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "x" << i << " = " << (result[i] ? "true" : "false") << std::endl;
        }
    }
    return 0;
}
```

