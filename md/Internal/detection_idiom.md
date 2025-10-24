---
title: detection idiom
documentation_of: ../../src/Internal/detection_idiom.hpp
---

## 概要

C++ の SFINAE (Substitution Failure Is Not An Error) を利用して、ある型が特定の性質（メンバ型、メンバ関数、有効な式など）を持つかどうかをコンパイル時に判定するためのマクロを提供する。

これにより、テンプレートクラスや関数において、与えられた型 `T` に応じて `if constexpr` などで処理を分岐させたり、型定義を切り替えたりすることが容易になる。

## 使い方

各マクロで定義されるメタ関数は、テンプレートパラメータ `class T` を受け取る。マクロの `...` 部分には、この `T` に依存する式（例えば `typename T::value_type` や `decltype(std::declval<T&>().some_method())` など）を記述する。

## マクロ

### `_DETECT_BOOL(name, ...)`

指定した式 `...` が有効かどうかを判定し、`bool` 型の定数を返すメタ関数 `name` を定義する。

- **`name<T>::value`**: `T` に対して `...` が有効な式であれば `true`、そうでなければ `false` となる `std::bool_constant`。
- **`name_v<T>`**: `name<T>::value` と同値の `bool` 定数。

#### 使用例

テンプレートパラメータ `M` がモノイドの性質（メンバ型 `T`、メンバ関数 `op`、メンバ関数 `ti`）を持つかを判定する。

```cpp
// M が .T, .op, .ti を持つか調べるメタ関数 is_monoid を定義
_DETECT_BOOL(is_monoid, typename T::T, decltype(&T::op), decltype(&T::ti));

// is_monoid_v<M> を使って処理を分岐
if constexpr (is_monoid_v<M>) {
  // M がモノイドの性質を持つ場合の処理
} else {
  // 持たない場合の処理
}
```

### `_DETECT_TYPE(name, type1, type2, ...)`

指定した式 `...` が有効かどうかに応じて、異なる型を定義するメタ関数 `name` を定義する。

- **`name<T>::type`**: `T` に対して `...` が有効な式であれば `type1`、そうでなければ `type2` となる。

#### 使用例

テンプレートパラメータ `M` がメンバ型 `E` を持つか判定し、持たない場合は `std::nullptr_t` で代用する。

```cpp
// M がメンバ型 E を持つか調べ、
// 持つ場合は E を、持たない場合は std::nullptr_t を type とするメタ関数 get_E を定義
_DETECT_TYPE(get_E, typename T::E, std::nullptr_t, typename T::E);

// get_E<M>::type で型を取得
// M が E を持てば E、持たなければ std::nullptr_t となる
using E = typename get_E<M>::type;
```