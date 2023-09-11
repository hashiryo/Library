---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.AlienDP.test.cpp
    title: test/aoj/2603.AlienDP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3044.test.cpp
    title: test/aoj/3044.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc204_e.test.cpp
    title: test/atcoder/abc204_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc218_h.test.cpp
    title: test/atcoder/abc218_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc279_d.test.cpp
    title: test/atcoder/abc279_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/180.test.cpp
    title: test/yukicoder/180.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2276.test.cpp
    title: test/yukicoder/2276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2309.test.cpp
    title: test/yukicoder/2309.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/fibonacci_search.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
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
    };\ntemplate <class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n\
    #line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum { MAXIMIZE= -1, MINIMIZE=\
    \ 1 };\n#line 6 \"src/Optimization/fibonacci_search.hpp\"\n// [l,r]\ntemplate\
    \ <MinMaxEnum obj, class F> std::pair<int64_t, result_type_t<F>> fibonacci_search(const\
    \ F &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t s= 1, t= 2, a= l -\
    \ 1, x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+= t, t);\n b= a\
    \ + t, x= b - s;\n result_type_t<F> fx= f(x), fy;\n for (bool g; a + b != 2 *\
    \ x;) {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if constexpr (obj\
    \ == MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n   if (g) b=\
    \ a, a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include \"src/Internal/function_type.hpp\"\
    \n#include \"src/Optimization/MinMaxEnum.hpp\"\n// [l,r]\ntemplate <MinMaxEnum\
    \ obj, class F> std::pair<int64_t, result_type_t<F>> fibonacci_search(const F\
    \ &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t s= 1, t= 2, a= l - 1,\
    \ x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+= t, t);\n b= a +\
    \ t, x= b - s;\n result_type_t<F> fx= f(x), fy;\n for (bool g; a + b != 2 * x;)\
    \ {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if constexpr (obj ==\
    \ MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n   if (g) b= a,\
    \ a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n}"
  dependsOn:
  - src/Internal/function_type.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/fibonacci_search.hpp
  requiredBy: []
  timestamp: '2023-08-13 00:05:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2603.AlienDP.test.cpp
  - test/aoj/3044.test.cpp
  - test/atcoder/abc204_e.test.cpp
  - test/atcoder/abc218_h.test.cpp
  - test/atcoder/abc279_d.test.cpp
  - test/yukicoder/2276.test.cpp
  - test/yukicoder/180.test.cpp
  - test/yukicoder/2309.test.cpp
documentation_of: src/Optimization/fibonacci_search.hpp
layout: document
title: "\u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u63A2\u7D22"
---
## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `fibonacci_search<sgn>(f,l,r)`   | $\lbrack l, r\rbrack \cap\mathbb{Z}$ 上で単峰となる関数 $f(x)$ の最適値とその最適解を返す. <br> 返り値は { 最適解 $x^\ast$, 最適値 $f(x^\ast)$ } <br> templateの引数で最大最小を指定.           | $n=r-l$ とおき, $f(x)$ の評価が$\mathcal{O}(A)$ かかるとしたとき<br>                  $\mathcal{O}(A\log n)$    |


## 問題例
[京セラプログラミングコンテスト2023(AtCoder Beginner Contest 305) Ex - Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h) (Alien DP)

## 参考
[https://qiita.com/tanaka-a/items/f380257328da421c6584](https://qiita.com/tanaka-a/items/f380257328da421c6584) 