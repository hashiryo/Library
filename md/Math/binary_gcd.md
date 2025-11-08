---
title: Binary GCD
documentation_of: ../../src/Math/binary_gcd.hpp
---

除算の代わりにシフト演算と引き算を使うことで高速に最大公約数を求めるアルゴリズム。
`constexpr` での呼び出しが可能。

|名前|概要|
|---|---|
|`binary_gcd(a,b)`| 整数 $a,b$ の最大公約数を返す。|

## 計算量
$O(\log(\min(|a|,|b|)))$

## 備考
- $a, b$ が共に非ゼロの場合、結果は `gcd(|a|, |b|)` と等価になる。
- $a, b$ のいずれかがゼロの場合、結果は `a + b` となる。例えば `binary_gcd(x, 0)` は `x` を返し、`binary_gcd(0, 0)` は `0` を返す。これは `std::gcd` の仕様 (`std::gcd(x, 0) = |x|`) とは異なるため注意。