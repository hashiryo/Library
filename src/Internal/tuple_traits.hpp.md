---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/DataStructure/KDTree.hpp
    title: kD-Tree
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_2D.hpp
    title: "Segment-Tree(2\u6B21\u5143)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1023.KDT.test.cpp
    title: test/aoj/1023.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1068.KDT.test.cpp
    title: test/aoj/1068.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1068.Seg2D.test.cpp
    title: test/aoj/1068.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.KDT.test.cpp
    title: test/aoj/2842.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.Seg2D.test.cpp
    title: test/aoj/2842.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.KDT.test.cpp
    title: test/aoj/DSL_2_C.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc228_f.Seg2D.test.cpp
    title: test/atcoder/abc228_f.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc234_ex.KDT.test.cpp
    title: test/atcoder/abc234_ex.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc309_f.KDT.3D.test.cpp
    title: test/atcoder/abc309_f.KDT.3D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc309_f.KDT.test.cpp
    title: test/atcoder/abc309_f.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc309_f.Seg2D.test.cpp
    title: test/atcoder/abc309_f.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/cube-summation.KDT.test.cpp
    title: test/hackerrank/cube-summation.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
    title: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
    title: test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1216.KDT.test.cpp
    title: test/yukicoder/1216.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1216.Seg2D.test.cpp
    title: test/yukicoder/1216.Seg2D.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.KDT.test.cpp
    title: test/yukicoder/1600.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.Seg2D.test.cpp
    title: test/yukicoder/1600.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.KDT.test.cpp
    title: test/yukicoder/1625.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.Seg2D.test.cpp
    title: test/yukicoder/1625.Seg2D.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1649.Seg2D.test.cpp
    title: test/yukicoder/1649.Seg2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2065.Seg2D.test.cpp
    title: test/yukicoder/2065.Seg2D.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2342.KDT.test.cpp
    title: test/yukicoder/2342.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.Seg2D.test.cpp
    title: test/yukicoder/924.Seg2D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/tuple_traits.hpp\"\n#include <tuple>\n#include\
    \ <array>\n#include <type_traits>\n#include <cstddef>\ntemplate <class T> static\
    \ constexpr bool tuple_like_v= false;\ntemplate <class... Args> static constexpr\
    \ bool tuple_like_v<std::tuple<Args...>> = true;\ntemplate <class T, class U>\
    \ static constexpr bool tuple_like_v<std::pair<T, U>> = true;\ntemplate <class\
    \ T, size_t K> static constexpr bool tuple_like_v<std::array<T, K>> = true;\n\
    template <class T> auto to_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::make_tuple(x...); }, t);\n}\n\
    template <class T> auto forward_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::forward_as_tuple(x...); }, t);\n\
    }\ntemplate <class T> static constexpr bool array_like_v= false;\ntemplate <class\
    \ T, size_t K> static constexpr bool array_like_v<std::array<T, K>> = true;\n\
    template <class T, class U> static constexpr bool array_like_v<std::pair<T, U>>\
    \ = std::is_convertible_v<T, U>;\ntemplate <class T> static constexpr bool array_like_v<std::tuple<T>>\
    \ = true;\ntemplate <class T, class U, class... Args> static constexpr bool array_like_v<std::tuple<T,\
    \ U, Args...>> = array_like_v<std::tuple<T, Args...>> && std::is_convertible_v<U,\
    \ T>;\ntemplate <class T> auto to_array(const T &t) {\n if constexpr (array_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::array{x...}; }, t);\n}\ntemplate\
    \ <class T> using to_tuple_t= decltype(to_tuple(T()));\ntemplate <class T> using\
    \ to_array_t= decltype(to_array(T()));\n"
  code: "#pragma once\n#include <tuple>\n#include <array>\n#include <type_traits>\n\
    #include <cstddef>\ntemplate <class T> static constexpr bool tuple_like_v= false;\n\
    template <class... Args> static constexpr bool tuple_like_v<std::tuple<Args...>>\
    \ = true;\ntemplate <class T, class U> static constexpr bool tuple_like_v<std::pair<T,\
    \ U>> = true;\ntemplate <class T, size_t K> static constexpr bool tuple_like_v<std::array<T,\
    \ K>> = true;\ntemplate <class T> auto to_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::make_tuple(x...); }, t);\n}\n\
    template <class T> auto forward_tuple(const T &t) {\n if constexpr (tuple_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::forward_as_tuple(x...); }, t);\n\
    }\ntemplate <class T> static constexpr bool array_like_v= false;\ntemplate <class\
    \ T, size_t K> static constexpr bool array_like_v<std::array<T, K>> = true;\n\
    template <class T, class U> static constexpr bool array_like_v<std::pair<T, U>>\
    \ = std::is_convertible_v<T, U>;\ntemplate <class T> static constexpr bool array_like_v<std::tuple<T>>\
    \ = true;\ntemplate <class T, class U, class... Args> static constexpr bool array_like_v<std::tuple<T,\
    \ U, Args...>> = array_like_v<std::tuple<T, Args...>> && std::is_convertible_v<U,\
    \ T>;\ntemplate <class T> auto to_array(const T &t) {\n if constexpr (array_like_v<T>)\
    \ return std::apply([](auto &&...x) { return std::array{x...}; }, t);\n}\ntemplate\
    \ <class T> using to_tuple_t= decltype(to_tuple(T()));\ntemplate <class T> using\
    \ to_array_t= decltype(to_array(T()));"
  dependsOn: []
  isVerificationFile: false
  path: src/Internal/tuple_traits.hpp
  requiredBy:
  - src/DataStructure/KDTree.hpp
  - src/DataStructure/SegmentTree_2D.hpp
  timestamp: '2023-10-31 18:36:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1216.KDT.test.cpp
  - test/yukicoder/1600.Seg2D.test.cpp
  - test/yukicoder/1649.Seg2D.test.cpp
  - test/yukicoder/1625.KDT.test.cpp
  - test/yukicoder/924.Seg2D.test.cpp
  - test/yukicoder/2342.KDT.test.cpp
  - test/yukicoder/1600.KDT.test.cpp
  - test/yukicoder/1625.Seg2D.test.cpp
  - test/yukicoder/2065.Seg2D.test.cpp
  - test/yukicoder/1216.Seg2D.test.cpp
  - test/yosupo/point_add_rectangle_sum.Seg2D.test.cpp
  - test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - test/hackerrank/cube-summation.KDT.test.cpp
  - test/aoj/1068.Seg2D.test.cpp
  - test/aoj/2842.Seg2D.test.cpp
  - test/aoj/1068.KDT.test.cpp
  - test/aoj/2842.KDT.test.cpp
  - test/aoj/DSL_2_C.KDT.test.cpp
  - test/aoj/1023.KDT.test.cpp
  - test/atcoder/abc309_f.KDT.3D.test.cpp
  - test/atcoder/abc228_f.Seg2D.test.cpp
  - test/atcoder/abc234_ex.KDT.test.cpp
  - test/atcoder/abc309_f.Seg2D.test.cpp
  - test/atcoder/abc309_f.KDT.test.cpp
documentation_of: src/Internal/tuple_traits.hpp
layout: document
title: "tuple\u3084array\u306B\u95A2\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
  \ \u4ED6"
---

| 名前                 | 概要                                                                                             |
| ------------------- | ------------------------------------------------------------------------------------------------ |
|`tuple_like_v<T>`|`T` が tuple, array, pair なら true.|
|`array_like_v<T>`|`T` が array, pair<U,U>, tuple<U,...,U> なら true.|
|`to_tuple(t)`| `t` を tuple に変換したものを返す. tuple like じゃないなら void.|
|`forward_tuple(t)`|`t` を tuple に変換したもの (forwad) を返す. tuple like じゃないなら void.|
|`to_array(t)`|`t` を array に変換したものを返す. array like じゃないなら void.|
|`to_tuple_t<T>`|`T` を tuple に変換した型 を返す. tuple like じゃないなら void.|
|`to_array_t<T>`|`T` を array に変換した型 を返す. array like じゃないなら void.|
| `other_than_first_argument_type_t<T>`| `T=tuple<U,Args...>` から `tuple<Args...>` を作る |
