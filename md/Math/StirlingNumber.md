---
title: スターリング数 (小さい素数 mod)
documentation_of: ../../src/Math/StirlingNumber.hpp
---

## 概要
$n$ が大きい場合に、小さい素数 $p$ を法とした第一種スターリング数 $s(n, k) \pmod p$ および第二種スターリング数 $S(n, k) \pmod p$ を高速に計算する。

母関数が法 $p$ で簡単な形になることを利用し、$O(p^2)$ の前処理ののち、クエリあたり $O(\log_p n)$ で計算する。

## 原理
### 第二種スターリング数
第二種スターリング数 $S_2(n, k)$ の母関数は以下で与えられる。
$$ \sum_{n \ge k} S_2(n, k) x^n = \frac{x^k}{\prod_{l=0}^k (1-lx)} $$
法 $p$ で考えると、$\prod_{l=0}^{p-1} (1-lx) \equiv 1-x^{p-1} \pmod p$ ではなく、$1-x^p+x$に関する式に変形できるという事実があり、それを利用して $k=ip+j$ と分解し係数を比較することで、高速に計算が可能になる。

### 第一種スターリング数
第一種スターリング数 $s(n, k)$ の母関数は以下で与えられる。
$$ \sum_{k=0}^n s(n, k) x^k = \prod_{l=0}^{n-1} (x-l) $$
法 $p$ で考えると、$\prod_{l=0}^{p-1} (x-l) \equiv x^p - x \pmod p$ となる。$n=ip+j$ と分解し、この関係を繰り返し適用することで、高速な計算が可能になる。

## 制約
- `p` は素数であること
- `p < 32768`

## 使用方法
`StirlingNumber sn(p, first, second)`
- `p`: 素数の法
- `first`: `true` の場合、第一種スターリング数のための前処理を行う (デフォルト: `true`)
- `second`: `true` の場合、第二種スターリング数のための前処理を行う (デフォルト: `true`)

`sn.S1(n, k)`
- 第一種スターリング数 $s(n, k) \pmod p$ を返す。

`sn.S2(n, k)`
- 第二種スターリング数 $S(n, k) \pmod p$ を返す。

`sn.nCk(n, k)`
- Lucasの定理を利用して $nCk \pmod p$ を返す。

## 計算量
- 前処理: $O(p^2)$
- クエリ: $O(\log_p n)$

## コード
```cpp
#include <iostream>
#include "src/Math/StirlingNumber.hpp"

int main() {
    long long n = 1000000000000000000;
    long long k = 500000000000000000;
    int p = 101;

    // 第二種スターリング数のみ計算する場合
    StirlingNumber sn(p, false, true);

    std::cout << sn.S2(n, k) << std::endl;
}
```

## 参考
- [https://maspypy.com/stirling-数を-p-で割った余りの計算](https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97)