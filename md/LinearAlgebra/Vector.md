---
title: ベクトル
documentation_of: ../../src/LinearAlgebra/Vector.hpp
---

## `Vector<K>` クラス

$K$ 上の $n$ 次元数ベクトル空間 $K^n$ のベクトルを表すクラス．
`std::valarray` を用いて実装されている。

### `Vector<bool>` の特殊化

`K=bool` の場合は、有限体 $\mathbb{F}_2$ 上のベクトルとして扱われるように特殊化されている。これにより、ビット演算を用いた高速化が図られている。
- 加算 `+`, 減算 `-` は XOR 演算となる。
- 単項マイナス `-v` は `v` と等しい（$\mathbb{F}_2$ では  = -1$ のため）。
- 内積 `dot(u, v)` は $\sum u_i v_i \pmod 2$ を計算する。

## コンストラクタ

| コンストラクタ | 概要 |
| --- | --- |
| `Vector()` | 次元数 $0$ の空ベクトルを生成する。 |
| `Vector(n)` | 次元数 $n$ のゼロベクトルを生成する。 |
| `Vector(n, a)` | 次元数 $n$ で、全成分が $a$ のベクトルを生成する。 |
| `Vector({...})` | `initializer_list` からベクトルを生成する。 |

## メンバ関数

| メンバ関数 | 概要 | 計算量 |
| --- | --- | --- |
| `operator[](i)` | 第 $i$ 成分 $v_i$ への参照を返す。 | $O(1)$ |
| `size()` | ベクトルの次元数 $n$ を返す。 | $O(1)$ |

## 演算子

| 演算子オーバーロード | 概要 | 計算量 |
| --- | --- | --- |
| `operator- (v)` | $-\boldsymbol{v}$ を返す。 | $O(n)$ |
| `operator+ (v, u)` | $\boldsymbol{v}+\boldsymbol{u}$ を返す。 | $O(n)$ |
| `operator- (v, u)` | $\boldsymbol{v}-\boldsymbol{u}$ を返す。 | $O(n)$ |
| `operator* (v, a)` | スカラー倍 $a\boldsymbol{v}$ を返す。 | $O(n)$ |
| `operator* (a, v)` | スカラー倍 $a\boldsymbol{v}$ を返す。 | $O(n)$ |
| `operator== (v, u)` | $\boldsymbol{v}=\boldsymbol{u}$ なら `true` を返す。 | $O(n)$ |
| `operator!= (v, u)` | $\boldsymbol{v}\ne\boldsymbol{u}$ なら `true` を返す。 | $O(n)$ |
| `operator+= (v, u)` | $\boldsymbol{v} \leftarrow \boldsymbol{v}+\boldsymbol{u}$ | $O(n)$ |
| `operator-= (v, u)` | $\boldsymbol{v} \leftarrow \boldsymbol{v}-\boldsymbol{u}$ | $O(n)$ |
| `operator*= (v, a)` | $\boldsymbol{v} \leftarrow a\boldsymbol{v}$ | $O(n)$ |
| `explicit operator bool (v)` | 次元数が 1 以上なら `true` を返す。 | $O(1)$ |

## その他関数

| その他関数 | 概要 | 計算量 |
| --- | --- | --- |
| `dot(u, v)` | 内積 $\boldsymbol{u}^{\top}\boldsymbol{v}$ を返す。 | $O(n)$ |
| `operator<< (os, v)` | ベクトル `v` を `os` に `[v_0, v_1, ...]` の形式で出力する。 | $O(n)$ |

## 使用例

### `Vector<int>` の場合

```cpp
#include <iostream>
#include "src/LinearAlgebra/Vector.hpp"

int main() {
    Vector<int> x = {1, 2, 3};
    Vector<int> y = {4, 5, 6};

    // ベクトルの和
    Vector<int> z = x + y; // {5, 7, 9}
    std::cout << "x + y = " << z << std::endl;

    // スカラー倍
    x *= 2; // {2, 4, 6}
    std::cout << "x * 2 = " << x << std::endl;

    // 内積
    int d = dot(x, y); // 2*4 + 4*5 + 6*6 = 8 + 20 + 36 = 64
    std::cout << "dot(x, y) = " << d << std::endl;

    return 0;
}
```

### `Vector<bool>` の場合

```cpp
#include <iostream>
#include "src/LinearAlgebra/Vector.hpp"

int main() {
    Vector<bool> x = {1, 0, 1};
    Vector<bool> y = {0, 1, 1};

    // ベクトルの和 (XOR)
    Vector<bool> z = x + y; // {1, 1, 0}
    std::cout << "x + y = " << z << std::endl;

    // 内積 (mod 2)
    bool d = dot(x, y); // (1*0 + 0*1 + 1*1) mod 2 = 1
    std::cout << "dot(x, y) = " << d << std::endl;

    return 0;
}
```