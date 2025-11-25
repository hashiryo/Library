---
title: Number-Theoretic Transform (NTT)
documentation_of: ../../src/FFT/NTT.hpp
---

## 概要

Number-Theoretic Transform (NTT) は、数論的な性質を利用して畳み込み（Convolution）を高速に計算するためのアルゴリズムです。FFT（高速フーリエ変換）と同様に、$O(N \log N)$ で畳み込みを計算できますが、剰余演算を用いるため、浮動小数点数誤差が発生しない利点があります。

このライブラリは、NTT に適した法（$P = c \cdot 2^k + 1$ の形の素数）を持つ `ModInt` を直接利用するだけでなく、NTT に適さない法や `long long` などの整数型に対しても、複数の NTT 素数で計算し、ガーナーのアルゴリズム（中国剰余定理の応用）を用いて結果を復元することで、任意法での畳み込みをサポートします。

`convolve.hpp` を介して利用することが推奨されますが、より低レベルな操作のために直接 `NTTArray` を使用することも可能です。

## 主要クラス

### `NTTArray<T, LM, v>`

NTT の計算を行うための中心的なクラスです。

-   **T**: 係数の型。`ModInt` や `long long` などの算術型を指定します。
-   **LM**: 処理可能な配列の最大長。コンパイル時に決定される静的な値で、$2$ のべき乗である必要があります。
-   **v**: 内部で `std::vector` を使用するかどうかのフラグ (`bool`)。`false` の場合、静的配列を使用します。

#### `is_nttfriend<T, LM>()`

型 `T` が静的な `ModInt` であり、その法 `mod` が NTT に適しているか（素数であり、`mod - 1` が $2^{\text{ctz}(LM)}$ で割り切れるか）を判定する `constexpr` 関数です。

-   **NTTフレンドリーな場合**: `is_nttfriend` が `true` となり、指定された `ModInt` の法の下で直接 NTT を実行します。
-   **NTTフレンドリーでない場合**: `is_nttfriend` が `false` となり、内部で複数の NTT に適した素数（`998244353` など）を用いて計算し、結果をガーナーのアルゴリズムで復元します。これにより、任意の法や整数型での畳み込みが可能になります。

### `GlobalNTTArray<T, LM, id>`

`NTTArray` のインスタンスをグローバルに確保するためのヘルパークラスです。複数回の畳み込みでメモリ確保のオーバーヘッドを避けるために利用されます。`convolve` 関数内で内部的に使用されます。

## 関数

`NTTArray` クラスのメンバ関数として提供されます。

-   `dft(b, e)`: 区間 `[b, e)` のデータに対して順方向の NTT (DFT) を適用します。
-   `idft(b, e)`: 区間 `[b, e)` のデータに対して逆方向の NTT (IDFT) を適用します。
-   `set(x[], b, e)`: 配列 `x` の `[b, e)` の内容を内部バッファにコピーします。
-   `get(x[], b, e)`: 内部バッファの内容を配列 `x` の `[b, e)` にコピーします。
-   `mul(other, b, e)`: 他の `NTTArray` のインスタンス `other` との間で、`[b, e)` の要素ごとの積を計算します。

## 使い方

通常は `convolve.hpp` の `convolve` 関数を利用してください。

```cpp
#include "src/FFT/convolve.hpp"
#include "src/Math/ModInt.hpp"
#include <vector>
#include <iostream>

int main() {
    using Mint = ModInt<998244353>;
    std::vector<Mint> a = {1, 2, 3};
    std::vector<Mint> b = {4, 5, 6};

    // a と b の畳み込みを計算
    // 結果: c = {4, 13, 28, 27, 18}
    auto c = convolve(a, b);

    for (size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << (i == c.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
```

## 計算量

-   NTT: $O(N \log N)$ （$N$ は変換対象の配列長）
-   ガーナーのアルゴリズムを用いる場合: $O(k \cdot N \log N)$ （$k$ は使用する素数の個数、通常は $2 \sim 5$ 程度の定数）

## 制約

-   `LM` (配列の最大長) はコンパイル時に決定され、$2$ のべき乗である必要があります。
-   NTT フレンドリーでない型の場合、畳み込み結果の各係数が、内部で使用される複数の NTT 素数の積（`long long` の範囲を超える巨大な数）を超えないことが必要です。超えた場合、結果がオーバーフローし、正しく復元されません。
