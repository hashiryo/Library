---
title: 形式的冪級数 div
documentation_of: ../../src/FFT/fps_div.hpp
---

## 概要
形式的冪級数 $P(x) = \sum_{i=0}^{N-1} p_i x^i$ と $Q(x) = \sum_{i=0}^{M-1} q_i x^i$ の除算 $P(x) / Q(x)$ を行い、結果の形式的冪級数 $R(x)$ の最初の $N$ 項を計算します。

$R(x) = P(x) / Q(x) \pmod{x^N}$

## 使用方法
```cpp
vector<mod_t> div(const vector<mod_t>& p, const vector<mod_t>& q);
```

### 引数
- `p`: 形式的冪級数 $P(x)$ の係数配列。`vector<mod_t>` 型。
- `q`: 形式的冪級数 $Q(x)$ の係数配列。`vector<mod_t>` 型。

### 戻り値
- $P(x) / Q(x)$ の結果である形式的冪級数の係数配列。サイズは `p.size()` となります。

## 制約
- `q` は空であってはならない。
- `q[0]` は $0$ であってはならない（逆元が存在する必要がある）。

## 計算量
$O(N \log N)$
ただし、$N$ は `p.size()`。

## 使用例
```cpp
#include <iostream>
#include <vector>
#include "src/Math/ModInt.hpp"
#include "src/FFT/fps_div.hpp"

using namespace std;
using mint = ModInt<998244353>;

int main() {
    // P(x) = 1 - 3x + 2x^2 = (1-x)(1-2x)
    vector<mint> p = {1, -3, 2};
    // Q(x) = 1 - x
    vector<mint> q = {1, -1};

    // R(x) = P(x) / Q(x) = 1 - 2x
    vector<mint> r = div(p, q);

    // 結果は p.size() = 3 項まで計算される
    // 期待される出力: 1 -2 0
    for (size_t i = 0; i < r.size(); ++i) {
        cout << r[i] << (i == r.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
```
