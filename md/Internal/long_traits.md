---
title: より大きい型へ変換する型特性
documentation_of: ../../src/Internal/long_traits.hpp
---

## 概要

`make_long_t<T>` は、整数型や浮動小数点数型 `T` を、より大きい表現範囲を持つ型に変換するための型特性テンプレートである。乗算などで型 `T` の範囲を超える可能性がある場合に、オーバーフローを防ぐために使用できる。

## 型の対応

| 元の型 (`T`)       | 変換後の型 (`make_long_t<T>`) |
| ------------------ | ----------------------------- |
| `char`             | `short`                       |
| `unsigned char`    | `unsigned short`              |
| `short`            | `int`                         |
| `unsigned short`   | `unsigned`                    |
| `int`              | `long long`                   |
| `unsigned`         | `unsigned long long`          |
| `long long`        | `__int128_t`                  |
| `unsigned long long` | `__uint128_t`                 |
| `float`            | `double`                      |
| `double`           | `long double`                 |

## 使用例

```cpp
#include <iostream>
#include <type_traits>
#include "Internal/long_traits.hpp"

int main() {
    int a = 100000;
    int b = 100000;

    // int 型のまま計算するとオーバーフローする可能性がある
    // long long c = a * b; // warning or overflow

    // make_long_t を使ってより大きい型で計算する
    make_long_t<int> c = (make_long_t<int>)a * b;

    std::cout << c << std::endl; // 10000000000

    // 型が long long になっていることを確認
    static_assert(std::is_same_v<decltype(c), long long>);

    return 0;
}
```
