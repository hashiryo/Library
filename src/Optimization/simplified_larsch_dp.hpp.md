---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.AlienDP.test.cpp
    title: test/aoj/2603.AlienDP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3086.test.cpp
    title: test/aoj/3086.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/simplified_larsch_dp.hpp\"\n#include <vector>\n\
    #include <limits>\n#line 2 \"src/Internal/function_type.hpp\"\n#include <type_traits>\n\
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
    #line 5 \"src/Optimization/simplified_larsch_dp.hpp\"\n// dp[i] = min_{j<i} (dp[j]\
    \ + w(i,j))\n// w(i,j) -> monge cost\ntemplate <class F> std::vector<result_type_t<F>>\
    \ simplified_larsch_dp(int n, const F &w) {\n using T= result_type_t<F>;\n std::vector<T>\
    \ dp(n + 1, std::numeric_limits<T>::max());\n std::vector<int> x(n + 1);\n auto\
    \ check= [&](int i, int j) {\n  if (T cost= dp[j] + w(i, j); dp[i] > cost) dp[i]=\
    \ cost, x[i]= j;\n };\n auto rec= [&](auto &rec, int l, int r) {\n  if (r - l\
    \ <= 1) return;\n  int m= (l + r) / 2;\n  for (int i= x[l]; i <= x[r]; ++i) check(m,\
    \ i);\n  rec(rec, l, m);\n  for (int i= l + 1; i <= m; ++i) check(r, i);\n  rec(rec,\
    \ m, r);\n };\n return dp[0]= 0, check(n, 0), rec(rec, 0, n), dp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include \"src/Internal/function_type.hpp\"\
    \n// dp[i] = min_{j<i} (dp[j] + w(i,j))\n// w(i,j) -> monge cost\ntemplate <class\
    \ F> std::vector<result_type_t<F>> simplified_larsch_dp(int n, const F &w) {\n\
    \ using T= result_type_t<F>;\n std::vector<T> dp(n + 1, std::numeric_limits<T>::max());\n\
    \ std::vector<int> x(n + 1);\n auto check= [&](int i, int j) {\n  if (T cost=\
    \ dp[j] + w(i, j); dp[i] > cost) dp[i]= cost, x[i]= j;\n };\n auto rec= [&](auto\
    \ &rec, int l, int r) {\n  if (r - l <= 1) return;\n  int m= (l + r) / 2;\n  for\
    \ (int i= x[l]; i <= x[r]; ++i) check(m, i);\n  rec(rec, l, m);\n  for (int i=\
    \ l + 1; i <= m; ++i) check(r, i);\n  rec(rec, m, r);\n };\n return dp[0]= 0,\
    \ check(n, 0), rec(rec, 0, n), dp;\n}"
  dependsOn:
  - src/Internal/function_type.hpp
  isVerificationFile: false
  path: src/Optimization/simplified_larsch_dp.hpp
  requiredBy: []
  timestamp: '2023-09-10 19:51:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/705.test.cpp
  - test/yukicoder/704.test.cpp
  - test/yukicoder/409.test.cpp
  - test/yukicoder/703.test.cpp
  - test/aoj/3086.test.cpp
  - test/aoj/2603.AlienDP.test.cpp
documentation_of: src/Optimization/simplified_larsch_dp.hpp
layout: document
title: "\u7C21\u6613\u7248LARSCH"
---

## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `simplified_larsch_dp(N,w)` | \\[\mathrm{dp}_ {i}=\begin{cases} 0 & i=0 \newline \min _{j\lt i}\lbrace\mathrm{dp}_j+w(i,j)\rbrace&i\gt 0\end{cases}\\] の形のDPを解く.<br>ただしコスト $w$ は Monge.<br> 返り値は$\mathrm{dp}_i$ ( $i=0,\dots,N$ の $N+1$ 成分 ) |           $\mathcal{O}(N\log N)$             |

## 参考
[https://noshi91.hatenablog.com/entry/2023/02/18/005856](https://noshi91.hatenablog.com/entry/2023/02/18/005856)
