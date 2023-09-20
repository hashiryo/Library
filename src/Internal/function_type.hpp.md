---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/DiscreteLogarithm.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/fibonacci_search.hpp
    title: "\u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/golden_search.hpp
    title: "\u9EC4\u91D1\u5206\u5272\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/simplified_larsch_dp.hpp
    title: "\u7C21\u6613\u7248LARSCH"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.AlienDP.test.cpp
    title: test/aoj/2603.AlienDP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2972.test.cpp
    title: test/aoj/2972.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3044.test.cpp
    title: test/aoj/3044.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.test.cpp
    title: test/aoj/3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc204_e.test.cpp
    title: test/atcoder/abc204_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc218_h.test.cpp
    title: test/atcoder/abc218_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_g.test.cpp
    title: test/atcoder/abc222_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc279_d.test.cpp
    title: test/atcoder/abc279_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/180.test.cpp
    title: test/yukicoder/180.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2276.test.cpp
    title: test/yukicoder/2276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2309.test.cpp
    title: test/yukicoder/2309.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/261.test.cpp
    title: test/yukicoder/261.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/409.test.cpp
    title: test/yukicoder/409.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/703.test.cpp
    title: test/yukicoder/703.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/704.test.cpp
    title: test/yukicoder/704.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/950.test.cpp
    title: test/yukicoder/950.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
    template <class C> struct is_function_object {\n template <class U, int dummy=\
    \ (&U::operator(), 0)> static std::true_type check(U *);\n static std::false_type\
    \ check(...);\n static C *m;\n static constexpr bool value= decltype(check(m))::value;\n\
    };\ntemplate <class F, bool, bool> struct function_type_impl {\n using type= void;\n\
    };\ntemplate <class F> struct function_type_impl<F, true, false> {\n using type=\
    \ F *;\n};\ntemplate <class F> struct function_type_impl<F, false, true> {\n using\
    \ type= decltype(&F::operator());\n};\ntemplate <class F> using function_type_t=\
    \ typename function_type_impl<F, std::is_function_v<F>, is_function_object<F>::value>::type;\n\
    template <class... Args> struct result_type_impl {\n using type= void;\n};\ntemplate\
    \ <class R, class... Args> struct result_type_impl<R (*)(Args...)> {\n using type=\
    \ R;\n};\ntemplate <class C, class R, class... Args> struct result_type_impl<R\
    \ (C::*)(Args...)> {\n using type= R;\n};\ntemplate <class C, class R, class...\
    \ Args> struct result_type_impl<R (C::*)(Args...) const> {\n using type= R;\n\
    };\ntemplate <class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n"
  code: "#pragma once\n#include <type_traits>\ntemplate <class C> struct is_function_object\
    \ {\n template <class U, int dummy= (&U::operator(), 0)> static std::true_type\
    \ check(U *);\n static std::false_type check(...);\n static C *m;\n static constexpr\
    \ bool value= decltype(check(m))::value;\n};\ntemplate <class F, bool, bool> struct\
    \ function_type_impl {\n using type= void;\n};\ntemplate <class F> struct function_type_impl<F,\
    \ true, false> {\n using type= F *;\n};\ntemplate <class F> struct function_type_impl<F,\
    \ false, true> {\n using type= decltype(&F::operator());\n};\ntemplate <class\
    \ F> using function_type_t= typename function_type_impl<F, std::is_function_v<F>,\
    \ is_function_object<F>::value>::type;\ntemplate <class... Args> struct result_type_impl\
    \ {\n using type= void;\n};\ntemplate <class R, class... Args> struct result_type_impl<R\
    \ (*)(Args...)> {\n using type= R;\n};\ntemplate <class C, class R, class... Args>\
    \ struct result_type_impl<R (C::*)(Args...)> {\n using type= R;\n};\ntemplate\
    \ <class C, class R, class... Args> struct result_type_impl<R (C::*)(Args...)\
    \ const> {\n using type= R;\n};\ntemplate <class F> using result_type_t= typename\
    \ result_type_impl<function_type_t<F>>::type;"
  dependsOn: []
  isVerificationFile: false
  path: src/Internal/function_type.hpp
  requiredBy:
  - src/Math/DiscreteLogarithm.hpp
  - src/Optimization/simplified_larsch_dp.hpp
  - src/Optimization/golden_search.hpp
  - src/Optimization/fibonacci_search.hpp
  timestamp: '2023-04-02 00:58:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc270_g.test.cpp
  - test/atcoder/abc218_h.test.cpp
  - test/atcoder/abc279_d.test.cpp
  - test/atcoder/abc204_e.test.cpp
  - test/atcoder/abc222_g.test.cpp
  - test/yukicoder/705.test.cpp
  - test/yukicoder/704.test.cpp
  - test/yukicoder/409.test.cpp
  - test/yukicoder/2309.test.cpp
  - test/yukicoder/180.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/950.test.cpp
  - test/yukicoder/703.test.cpp
  - test/yukicoder/2276.test.cpp
  - test/yukicoder/261.test.cpp
  - test/aoj/2972.test.cpp
  - test/aoj/3086.test.cpp
  - test/aoj/3044.test.cpp
  - test/aoj/2603.AlienDP.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Internal/function_type.hpp
layout: document
title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3092\
  \u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

| 名前                    | 概要                                                                                                           |
| ----------------------- | -------------------------------------------------------------------------------------------------------------- |
| `is_function_object<F>` | メンバー変数 `value` は クラス `F` が関数オブジェクトなら `true_type`, 違えば `false_type`                     |
| `result_type_t<F>`      | `F` のインスタンスの 関数としての 戻り値の型  ( `F` が関数型 でも 関数オブジェクトクラス でもないなら `void` ) |