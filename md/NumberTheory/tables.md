---
title: 乗法的関数テーブル・高速ゼータ/メビウス変換
documentation_of: ../../src/NumberTheory/tables.hpp
---

## 概要

`#include "src/NumberTheory/enumerate_primes.hpp"` が必要です。

- 素因数分解、乗法的関数のテーブル作成
- 高速ゼータ・メビウス変換（約数、倍数）
- 畳み込み（gcd, lcm）

などを提供するライブラリです。

---

## 関数

| 名前                               | 概要                                                                                             | 計算量                |
| ---------------------------------- | ------------------------------------------------------------------------------------------------ | --------------------- |
| `factorize(n)`                     | $n$ の素因数分解を `vector<pair<int,short>>` で返す (素因数, 指数)。                               | $O(\log n)$           |
| `multiplicative_table<T>(N, f)`    | 乗法的関数 $f$ の $1 \dots N$ における値のテーブルを返す。 $f(p^e)$ を計算する関数 `f(p, e)` を渡す。 | $O(N)$                |
| `mobius_table<T=int>(N)`           | メビウス関数 $\mu(n)$ のテーブルを返す。                                                           | $O(N)$                |
| `totient_table<T=int>(N)`          | オイラーのトーシェント関数 $\varphi(n)$ のテーブルを返す。                                         | $O(N)$                |
| `divisor_zeta(a)`                  | **(in-place)** 約数ゼータ変換 $b_n = \sum_{d|n} a_d$ を行う。                                      | $O(N \log \log N)$    |
| `divisor_mobius(a)`                | **(in-place)** 約数メビウス変換 $b_n = \sum_{d|n} \mu(n/d) a_d$ を行う。                           | $O(N \log \log N)$    |
| `multiple_zeta(a)`                 | **(in-place)** 倍数ゼータ変換 $b_n = \sum_{n|d} a_d$ を行う。                                      | $O(N \log \log N)$    |
| `multiple_mobius(a)`               | **(in-place)** 倍数メビウス変換 $b_n = \sum_{n|d} \mu(d/n) a_d$ を行う。                           | $O(N \log \log N)$    |
| `gcd_convolve(a, b)`               | $c_n = \sum_{\gcd(i,j)=n} a_i b_j$ となる $c$ を返す。                                             | $O(N \log \log N)$    |
| `lcm_convolve(a, b)`               | $c_n = \sum_{\mathrm{lcm}(i,j)=n} a_i b_j$ となる $c$ を返す。                                     | $O(N \log \log N)$    |

---

## 使用例

```cpp
#include <iostream>
#include <vector>
#include "src/NumberTheory/tables.hpp"

int main() {
    // オイラーのトーシェント関数のテーブルを作成
    int N = 10;
    auto phi = totient_table(N);
    // phi[1] から phi[10] まで表示
    // 1 1 2 2 4 2 6 4 6 4
    for (int i = 1; i <= N; ++i) {
        std::cout << phi[i] << (i == N ? "" : " ");
    }
    std::cout << std::endl;

    // 約数ゼータ変換
    std::vector<int> a = {0, 1, 2, 3, 4, 5}; // a[0]は未使用
    // b_n = sum_{d|n} a_d
    // b[1]=a[1]=1, b[2]=a[1]+a[2]=3, b[3]=a[1]+a[3]=4, b[4]=a[1]+a[2]+a[4]=7, b[5]=a[1]+a[5]=6
    auto b = a;
    divisor_zeta(b);
    for (int i = 1; i < b.size(); ++i) {
        std::cout << b[i] << (i == b.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // gcd畳み込み
    std::vector<long long> f = {0, 1, 1, 1, 1, 1};
    std::vector<long long> g = {0, 1, 1, 1, 1, 1};
    auto h = gcd_convolve(f, g);
    // h[1] = 25, h[2] = 9, h[3] = 9, h[4] = 1, h[5] = 9
    for (int i = 1; i < h.size(); ++i) {
        std::cout << h[i] << (i == h.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
```

## 参考
- [高速ゼータ変換・メビウス変換 - 37zigenのHP](https://37zigen.com/linear-sieve/)
- [約数系包除と高速ゼータ変換 - Qiita](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)