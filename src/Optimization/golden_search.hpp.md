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
    path: test/aoj/2972.test.cpp
    title: test/aoj/2972.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/golden_search.hpp\"\n#include <cmath>\n\
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
    \ 1 };\n#line 6 \"src/Optimization/golden_search.hpp\"\n// [l,r]\ntemplate <MinMaxEnum\
    \ obj, class F> std::pair<long double, result_type_t<F>> golden_search(const F\
    \ &f, long double l, long double r, int iter= 100) {\n static constexpr long double\
    \ c= 0.38196601125;\n assert(l <= r);\n long double x= l + (r - l) * c, y= r -\
    \ (r - l) * c;\n result_type_t<F> fx= f(x), fy= f(y);\n for (bool g; iter--;)\
    \ {\n  if constexpr (obj == MINIMIZE) g= fx < fy;\n  else g= fx > fy;\n  if (g)\
    \ r= y, y= x, fy= fx, fx= f(x= l + (r - l) * c);\n  else l= x, x= y, fx= fy, fy=\
    \ f(y= r - (r - l) * c);\n }\n return {x, fx};\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <cassert>\n#include \"src/Internal/function_type.hpp\"\
    \n#include \"src/Optimization/MinMaxEnum.hpp\"\n// [l,r]\ntemplate <MinMaxEnum\
    \ obj, class F> std::pair<long double, result_type_t<F>> golden_search(const F\
    \ &f, long double l, long double r, int iter= 100) {\n static constexpr long double\
    \ c= 0.38196601125;\n assert(l <= r);\n long double x= l + (r - l) * c, y= r -\
    \ (r - l) * c;\n result_type_t<F> fx= f(x), fy= f(y);\n for (bool g; iter--;)\
    \ {\n  if constexpr (obj == MINIMIZE) g= fx < fy;\n  else g= fx > fy;\n  if (g)\
    \ r= y, y= x, fy= fx, fx= f(x= l + (r - l) * c);\n  else l= x, x= y, fx= fy, fy=\
    \ f(y= r - (r - l) * c);\n }\n return {x, fx};\n}"
  dependsOn:
  - src/Internal/function_type.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/golden_search.hpp
  requiredBy: []
  timestamp: '2023-09-20 18:34:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2972.test.cpp
documentation_of: src/Optimization/golden_search.hpp
layout: document
title: "\u9EC4\u91D1\u5206\u5272\u63A2\u7D22"
---

引数の型が `long double` の単峰関数が対象. \
引数の型が整数な単峰関数を対象にする場合は[フィボナッチ探索](fibonacci_search.md) を使う.

## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `golden_search<sgn>(f,l,r,iter=100)`   | $\lbrack l, r\rbrack$ 上で単峰となる関数 $f(x)$ の最適値とその最適解を返す. <br> 返り値は { 最適解 $x^\ast$, 最適値 $f(x^\ast)$ } <br> templateの引数で最大最小を指定. <br> 第四引数で反復回数を指定. デフォルトは100          | $n=r-l$ とおき, $f(x)$ の評価が$\mathcal{O}(A)$ かかるとしたとき<br>                  $\mathcal{O}(A\log n)$    |
