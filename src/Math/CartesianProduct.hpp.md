---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0322.RH.test.cpp
    title: test/aoj/0322.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0355.test.cpp
    title: test/aoj/0355.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.RH.test.cpp
    title: test/aoj/2614.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.RH.test.cpp
    title: test/aoj/2711.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2763.RH.test.cpp
    title: test/aoj/2763.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.RH.test.cpp
    title: test/aoj/ALDS1_14_B.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc135_f.RH.test.cpp
    title: test/atcoder/abc135_f.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc141_e.RH.test.cpp
    title: test/atcoder/abc141_e.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc272_f.RH.test.cpp
    title: test/atcoder/abc272_f.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc047_b.RH.test.cpp
    title: test/atcoder/agc047_b.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_palindromes.RH.test.cpp
    title: test/yosupo/enumerate_palindromes.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/z_algorithm.RH.test.cpp
    title: test/yosupo/z_algorithm.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2332.RH.test.cpp
    title: test/yukicoder/2332.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2454.RH.test.cpp
    title: test/yukicoder/2454.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/599.RH.test.cpp
    title: test/yukicoder/599.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/765.RH.test.cpp
    title: test/yukicoder/765.RH.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/z_algorithm.RH.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/enumerate_palindromes.RH.test.cpp
  - test/yukicoder/765.RH.test.cpp
  - test/yukicoder/2332.RH.test.cpp
  - test/yukicoder/599.RH.test.cpp
  - test/yukicoder/2454.RH.test.cpp
  - test/aoj/2711.RH.test.cpp
  - test/aoj/0322.RH.test.cpp
  - test/aoj/2763.RH.test.cpp
  - test/aoj/ALDS1_14_B.RH.test.cpp
  - test/aoj/2614.RH.test.cpp
  - test/aoj/0355.test.cpp
  - test/atcoder/abc272_f.RH.test.cpp
  - test/atcoder/abc141_e.RH.test.cpp
  - test/atcoder/agc047_b.RH.test.cpp
  - test/atcoder/abc135_f.RH.test.cpp
documentation_of: src/Math/CartesianProduct.hpp
layout: document
title: "\u4EE3\u6570\u7CFB\u3092\u4E26\u5217\u306B\u6271\u3046 ($K_1\\times K_2\\\
  times\\cdots\\times K_n$)"
---
[Rolling Hash](RollingHash.md) などのハッシュ計算をする時に, baseを変えたパターンのを並行して扱うのを便利にするために作った.
## 問題例
[AtCoder Regular Contest 099 F - Eating Symbols Hard](https://atcoder.jp/contests/arc099/tasks/arc099_d)(多項式ハッシュ)\
[第二回全国統一プログラミング王決定戦本戦 D - 木、](https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_d) (根付き木ハッシュ)
