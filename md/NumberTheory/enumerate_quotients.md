---
title: ⌊N/i⌋ の列挙 (Enumerate Quotients)
documentation_of: ../../src/NumberTheory/enumerate_quotients.hpp
---

## 概要

$1$ から $N$ までの整数 $i$ について、 $\left\lfloor \frac{N}{i} \right\rfloor$ の値が等しくなるような $i$ の区間を列挙する。
$\left\lfloor \frac{N}{i} \right\rfloor$ の値は $O(\sqrt{N})$ 種類しか存在しないことを利用している。

---

## 使い方

### `enumerate_quotients(N)`

#### シグネチャ
```cpp
std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> enumerate_quotients(uint64_t N);
```

#### 説明
`l < i <= r` を満たさすすべての整数 `i` について $\left\lfloor \frac{N}{i} \right\rfloor = q$ が成り立つようなタプル `(q, l, r)` のベクタを返す。
返される区間 `(l, r]` の和集合は `(0, N]` となり、すべての $i \in \{1, \dots, N\}$ を網羅する。

返されるベクタ内のタプルの順序は保証されない。もし `q` の昇順で処理したい場合は、別途ソートが必要。

#### 使用例
```cpp
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

// ライブラリのヘッダ
#include "src/NumberTheory/enumerate_quotients.hpp"

int main() {
    uint64_t N = 10;
    auto quotients = enumerate_quotients(N);

    // q の昇順にソートして表示
    std::sort(quotients.begin(), quotients.end());

    for (const auto& [q, l, r] : quotients) {
        // q: floor(N/i) の値
        // l: 区間の始点 (含まない)
        // r: 区間の終点 (含む)
        std::cout << "q=" << q << ", l=" << l << ", r=" << r << std::endl;
    }

    return 0;
}
```

##### 出力例 (N=10)
```
q=1, l=5, r=10
q=2, l=3, r=5
q=3, l=2, r=3
q=5, l=1, r=2
q=10, l=0, r=1
```

---

## 計算量

$O(\sqrt{N})$