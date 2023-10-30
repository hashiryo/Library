---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/DataStructure/KDTree.hpp
    title: kD-Tree
  - icon: ':question:'
    path: src/Optimization/LiChaoTree.hpp
    title: Li-Chao-Tree
  - icon: ':warning:'
    path: test/yukicoder/1625.KDT.test copy.cpp
    title: test/yukicoder/1625.KDT.test copy.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1023.KDT.test.cpp
    title: test/aoj/1023.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1068.KDT.test.cpp
    title: test/aoj/1068.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.LiCT.test.cpp
    title: test/aoj/2603.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.LiCT.test.cpp
    title: test/aoj/2725.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.KDT.test.cpp
    title: test/aoj/2842.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.LiCT.test.cpp
    title: test/aoj/3086.LiCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.KDT.test.cpp
    title: test/aoj/DSL_2_C.KDT.test.cpp
  - icon: ':x:'
    path: test/hackerrank/cube-summation.KDT.test.cpp
    title: test/hackerrank/cube-summation.KDT.test.cpp
  - icon: ':x:'
    path: test/yosupo/line_add_get_min.LiCT.test.cpp
    title: test/yosupo/line_add_get_min.LiCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
    title: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - icon: ':x:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1297.LiCT.1.test.cpp
    title: test/yukicoder/1297.LiCT.1.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1297.LiCT.2.test.cpp
    title: test/yukicoder/1297.LiCT.2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625.KDT.test.cpp
    title: test/yukicoder/1625.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1867.test.cpp
    title: test/yukicoder/1867.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2458.LiCT.test.cpp
    title: test/yukicoder/2458.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/409.LiCT.test.cpp
    title: test/yukicoder/409.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/703.LiCT.test.cpp
    title: test/yukicoder/703.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/704.LiCT.test.cpp
    title: test/yukicoder/704.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/705.LiCT.test.cpp
    title: test/yukicoder/705.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.LiCT.test.cpp
    title: test/yukicoder/913.LiCT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/952.LiCT.test.cpp
    title: test/yukicoder/952.LiCT.test.cpp
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
    \ to_array_t= decltype(to_array(T()));\ntemplate <class T> struct other_than_first_argument_type_impl\
    \ {\n using type= void;\n};\ntemplate <class T, class... Args> struct other_than_first_argument_type_impl<std::tuple<T,\
    \ Args...>> {\n using type= std::tuple<Args...>;\n};\ntemplate <class T> using\
    \ other_than_first_argument_type_t= typename other_than_first_argument_type_impl<T>::type;\n"
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
    \ to_array_t= decltype(to_array(T()));\ntemplate <class T> struct other_than_first_argument_type_impl\
    \ {\n using type= void;\n};\ntemplate <class T, class... Args> struct other_than_first_argument_type_impl<std::tuple<T,\
    \ Args...>> {\n using type= std::tuple<Args...>;\n};\ntemplate <class T> using\
    \ other_than_first_argument_type_t= typename other_than_first_argument_type_impl<T>::type;"
  dependsOn: []
  isVerificationFile: false
  path: src/Internal/tuple_traits.hpp
  requiredBy:
  - src/Optimization/LiChaoTree.hpp
  - src/DataStructure/KDTree.hpp
  - test/yukicoder/1625.KDT.test copy.cpp
  timestamp: '2023-10-29 17:46:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/3086.LiCT.test.cpp
  - test/aoj/1023.KDT.test.cpp
  - test/aoj/2603.LiCT.test.cpp
  - test/aoj/DSL_2_C.KDT.test.cpp
  - test/aoj/2842.KDT.test.cpp
  - test/aoj/1068.KDT.test.cpp
  - test/aoj/2725.LiCT.test.cpp
  - test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - test/yosupo/min_plus_convolution_convex_arbitrary.LiCT.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.LiCT.test.cpp
  - test/yukicoder/2458.LiCT.test.cpp
  - test/yukicoder/703.LiCT.test.cpp
  - test/yukicoder/704.LiCT.test.cpp
  - test/yukicoder/409.LiCT.test.cpp
  - test/yukicoder/1297.LiCT.1.test.cpp
  - test/yukicoder/1297.LiCT.2.test.cpp
  - test/yukicoder/705.LiCT.test.cpp
  - test/yukicoder/1867.test.cpp
  - test/yukicoder/952.LiCT.test.cpp
  - test/yukicoder/1625.KDT.test.cpp
  - test/yukicoder/913.LiCT.test.cpp
  - test/hackerrank/cube-summation.KDT.test.cpp
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
|todo||