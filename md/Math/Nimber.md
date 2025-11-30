---
title: Nimber
documentation_of: ../../src/Math/Nimber.hpp
---

## 概要

Nimber (ニム数) の実装です。体 $\mathbb{F}_{2^{64}}$ 上の演算を提供します。`unsigned long long` 型の値をラップして、Nimberとしての演算を可能にします。

Grundy数としても知られ、不偏ゲームの理論などで利用されます。加算はXOR演算、乗算はNim積に対応します。

## 使い方

### 初期化

**重要:** プログラムの最初に必ず `Nimber::init()` を呼び出して、乗算のためのテーブルを初期化してください。

### コード例

```cpp
#include <iostream>
#include "src/Math/Nimber.hpp"

int main() {
    // 必ず最初に呼び出す
    Nimber::init();

    Nimber a(5);
    Nimber b(3);

    // 加算 (XOR)
    Nimber c = a + b;
    std::cout << "a + b = " << c.val() << std::endl; // 5 XOR 3 = 6

    // 乗算 (Nim積)
    Nimber d = a * b;
    std::cout << "a * b = " << d.val() << std::endl; // 13

    // 逆元
    Nimber a_inv = a.inv();
    std::cout << "a * a^-1 = " << (a * a_inv).val() << std::endl; // 1
}
```

## インターフェース

| 関数 | 説明 | 計算量 |
|:---|:---|:---|
| `Nimber::init()` | 乗算テーブルを初期化する（静的メンバ関数） | $O(2^{16})$ |
| `Nimber(unsigned long long x)` | `x` を値としてNimberを構築する | $O(1)$ |
| `n.val()` | `unsigned long long` 型の値を取得する | $O(1)$ |
| `n + m`, `n - m` | 加算・減算（XOR演算） | $O(1)$ |
| `n * m` | 乗算（Nim積） | $O(1)$ |
| `n / m` | 除算 | $O(1)$ |
| `n.inv()` | 乗法逆元を求める | $O(1)$ |
| `n.pow(k)` | `n` の `k` 乗を求める | $O(\log k)$ |
| `n.sqrt()` | 平方根を求める | $O(1)$ |
| `n.log(r)` | 離散対数 $n^x = r$ となる $x$ を求める | 非常に大きい（定数時間だが遅い） |

## 参考

- [Wikipedia: Nimber](https://en.wikipedia.org/wiki/Nimber)
- [Nimber(体 $F_{2^k}$ の実装)](https://natsugiri.hatenablog.com/entry/2020/03/29/073605)

## Verify

- [Codeforces Round #623 (Div. 1, based on VK Cup 2019-2020 - Elimination Round, Engine) F. Bad Cryptography](https://codeforces.com/contest/1314/problem/F) (log)
- [Yosupo Judge: Nim Product (64-bit)](https://judge.yosupo.jp/problem/nim_product_64)
