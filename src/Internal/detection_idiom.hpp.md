---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/DataStructure/WeightBalancedTree.hpp
    title: Weight-Balanced-Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.WBT.test.cpp
    title: test/aoj/1508.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3024.WBT.test.cpp
    title: test/aoj/3024.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_2_D.WBT.test.cpp
    title: test/aoj/ITP2_2_D.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_A.WBT.test.cpp
    title: test/aoj/ITP2_4_A.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_B.WBT.test.cpp
    title: test/aoj/ITP2_4_B.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_4_C.WBT.test.cpp
    title: test/aoj/ITP2_4_C.WBT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc256_f.WBT.test.cpp
    title: test/atcoder/abc256_f.WBT.test.cpp
  - icon: ':x:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.WBT.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.WBT.test.cpp
  - icon: ':x:'
    path: test/yosupo/persistent_queue.WBT.test.cpp
    title: test/yosupo/persistent_queue.WBT.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.WBT.test.cpp
    title: test/yosupo/range_affine_range_sum.WBT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/detection_idiom.hpp\"\n#include <type_traits>\n\
    #define _DETECT_BOOL(name, ...) \\\n template <class, class= void> struct name:\
    \ std::false_type {}; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>:\
    \ std::true_type {}; \\\n template <class T> static constexpr bool name##_v= name<T>::value\n\
    #define _DETECT_TYPE(name, type1, type2, ...) \\\n template <class T, class= void>\
    \ struct name { \\\n  using type= type2; \\\n }; \\\n template <class T> struct\
    \ name<T, std::void_t<__VA_ARGS__>> { \\\n  using type= type1; \\\n }\n"
  code: "#pragma once\n#include <type_traits>\n#define _DETECT_BOOL(name, ...) \\\n\
    \ template <class, class= void> struct name: std::false_type {}; \\\n template\
    \ <class T> struct name<T, std::void_t<__VA_ARGS__>>: std::true_type {}; \\\n\
    \ template <class T> static constexpr bool name##_v= name<T>::value\n#define _DETECT_TYPE(name,\
    \ type1, type2, ...) \\\n template <class T, class= void> struct name { \\\n \
    \ using type= type2; \\\n }; \\\n template <class T> struct name<T, std::void_t<__VA_ARGS__>>\
    \ { \\\n  using type= type1; \\\n }"
  dependsOn: []
  isVerificationFile: false
  path: src/Internal/detection_idiom.hpp
  requiredBy:
  - src/DataStructure/WeightBalancedTree.hpp
  timestamp: '2024-03-21 17:56:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.WBT.test.cpp
  - test/yosupo/persistent_queue.WBT.test.cpp
  - test/yosupo/range_affine_range_sum.WBT.test.cpp
  - test/aoj/3024.WBT.test.cpp
  - test/aoj/ITP2_4_B.WBT.test.cpp
  - test/aoj/ITP2_2_D.WBT.test.cpp
  - test/aoj/ITP2_4_A.WBT.test.cpp
  - test/aoj/ITP2_4_C.WBT.test.cpp
  - test/aoj/1508.WBT.test.cpp
  - test/atcoder/abc256_f.WBT.test.cpp
documentation_of: src/Internal/detection_idiom.hpp
layout: document
title: detection idiom
---
