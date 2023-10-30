---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/DataStructure/KDTree.hpp
    title: kD-Tree
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
    path: test/aoj/2842.KDT.test.cpp
    title: test/aoj/2842.KDT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.KDT.test.cpp
    title: test/aoj/DSL_2_C.KDT.test.cpp
  - icon: ':x:'
    path: test/hackerrank/cube-summation.KDT.test.cpp
    title: test/hackerrank/cube-summation.KDT.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
    title: test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625.KDT.test.cpp
    title: test/yukicoder/1625.KDT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "src/Internal/long_traits.hpp"

    #include <cstdint>

    // clang-format off

    template<class T>struct make_long{using type= T;};

    template<>struct make_long<int8_t>{using type= int16_t;};

    template<>struct make_long<uint8_t>{using type= uint16_t;};

    template<>struct make_long<int16_t>{using type= int32_t;};

    template<>struct make_long<uint16_t>{using type= uint32_t;};

    template<>struct make_long<int32_t>{using type= int64_t;};

    template<>struct make_long<uint32_t>{using type= uint64_t;};

    template<>struct make_long<int64_t>{using type= __int128_t;};

    template<>struct make_long<uint64_t>{using type= __uint128_t;};

    template<>struct make_long<float>{using type= double;};

    template<>struct make_long<double>{using type= long double;};

    template<class T> using make_long_t= typename make_long<T>::type;

    // clang-format on

    '
  code: '#pragma once

    #include <cstdint>

    // clang-format off

    template<class T>struct make_long{using type= T;};

    template<>struct make_long<int8_t>{using type= int16_t;};

    template<>struct make_long<uint8_t>{using type= uint16_t;};

    template<>struct make_long<int16_t>{using type= int32_t;};

    template<>struct make_long<uint16_t>{using type= uint32_t;};

    template<>struct make_long<int32_t>{using type= int64_t;};

    template<>struct make_long<uint32_t>{using type= uint64_t;};

    template<>struct make_long<int64_t>{using type= __int128_t;};

    template<>struct make_long<uint64_t>{using type= __uint128_t;};

    template<>struct make_long<float>{using type= double;};

    template<>struct make_long<double>{using type= long double;};

    template<class T> using make_long_t= typename make_long<T>::type;

    // clang-format on'
  dependsOn: []
  isVerificationFile: false
  path: src/Internal/long_traits.hpp
  requiredBy:
  - src/DataStructure/KDTree.hpp
  - test/yukicoder/1625.KDT.test copy.cpp
  timestamp: '2023-10-29 17:46:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1023.KDT.test.cpp
  - test/aoj/DSL_2_C.KDT.test.cpp
  - test/aoj/2842.KDT.test.cpp
  - test/aoj/1068.KDT.test.cpp
  - test/yosupo/point_add_rectangle_sum.KDT.test.cpp
  - test/yukicoder/1625.KDT.test.cpp
  - test/hackerrank/cube-summation.KDT.test.cpp
documentation_of: src/Internal/long_traits.hpp
layout: document
title: "int \u304B\u3089 long long \u306A\u3069\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\
  \u30C8"
---

| 名前                 | 概要                                                                                             |
| ------------------- | ------------------------------------------------------------------------------------------------ |
| `make_long_t<T>`| `T=int` から `long long`, `float` から `double` など |