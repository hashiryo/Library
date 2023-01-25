---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.rollinghash.test.cpp
    title: test/aoj/2614.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.rollinghash.test.cpp
    title: test/aoj/2711.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/z_algorithm.rollinghash.test.cpp
    title: test/yosupo/z_algorithm.rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/CartesianProduct.hpp\"\n#include <tuple>\n#include\
    \ <array>\n#include <utility>\ntemplate <class... Ks> struct CartesianProduct:\
    \ std::tuple<Ks...> {\n static constexpr int N= sizeof...(Ks);\n using Self= CartesianProduct;\n\
    \ using std::tuple<Ks...>::tuple;\n template <class T> CartesianProduct(const\
    \ T &v) { fill(v, std::make_index_sequence<N>()); }\n template <class T, std::size_t...\
    \ I> std::array<int, N> fill(const T &v, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)=\
    \ v), 0)...}}; }\n#define HELPER(name, op) \\\n template <std::size_t... I> std::array<int,\
    \ N> name(const Self &y, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)\
    \ op##= std::get<I>(y)), 0)...}}; } \\\n Self &operator op##=(const Self &r) {\
    \ return name(r, std::make_index_sequence<N>()), *this; }\n HELPER(add_assign,\
    \ +)\n HELPER(dif_assign, -)\n HELPER(mul_assign, *)\n HELPER(div_assign, /)\n\
    #undef HELPER\n Self operator+(const Self &r) const { return Self(*this)+= r;\
    \ }\n Self operator-(const Self &r) const { return Self(*this)-= r; }\n Self operator*(const\
    \ Self &r) const { return Self(*this)*= r; }\n Self operator/(const Self &r) const\
    \ { return Self(*this)/= r; }\n};\n"
  code: "#pragma once\n#include <tuple>\n#include <array>\n#include <utility>\ntemplate\
    \ <class... Ks> struct CartesianProduct: std::tuple<Ks...> {\n static constexpr\
    \ int N= sizeof...(Ks);\n using Self= CartesianProduct;\n using std::tuple<Ks...>::tuple;\n\
    \ template <class T> CartesianProduct(const T &v) { fill(v, std::make_index_sequence<N>());\
    \ }\n template <class T, std::size_t... I> std::array<int, N> fill(const T &v,\
    \ std::index_sequence<I...>) { return {{(void(std::get<I>(*this)= v), 0)...}};\
    \ }\n#define HELPER(name, op) \\\n template <std::size_t... I> std::array<int,\
    \ N> name(const Self &y, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)\
    \ op##= std::get<I>(y)), 0)...}}; } \\\n Self &operator op##=(const Self &r) {\
    \ return name(r, std::make_index_sequence<N>()), *this; }\n HELPER(add_assign,\
    \ +)\n HELPER(dif_assign, -)\n HELPER(mul_assign, *)\n HELPER(div_assign, /)\n\
    #undef HELPER\n Self operator+(const Self &r) const { return Self(*this)+= r;\
    \ }\n Self operator-(const Self &r) const { return Self(*this)-= r; }\n Self operator*(const\
    \ Self &r) const { return Self(*this)*= r; }\n Self operator/(const Self &r) const\
    \ { return Self(*this)/= r; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/CartesianProduct.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:06:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2711.rollinghash.test.cpp
  - test/aoj/2614.rollinghash.test.cpp
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - test/yosupo/z_algorithm.rollinghash.test.cpp
documentation_of: src/Math/CartesianProduct.hpp
layout: document
title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\times\
  \ K_n$)"
---
ロリハのために作った