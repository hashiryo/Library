---
title: 関数型や関数オブジェクトに関するテンプレート
documentation_of: ../../src/Internal/function_traits.hpp
---

| 名前                 | 概要                                                                                             |
| ------------------- | ------------------------------------------------------------------------------------------------ |
| `result_type_t<F>`  | `F` のインスタンスの 関数としての 戻り値の型  ( `F` が関数型 でも 関数オブジェクトクラス でもないなら `void` ) |
| `argument_type_t<F>`| `F` のインスタンスの 関数としての 引数の型 ( `tuple` でラッピング, `F` が関数型 でも 関数オブジェクトクラス でもないなら `void` ) |