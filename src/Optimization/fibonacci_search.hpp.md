---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2276.test.cpp
    title: test/yukicoder/2276.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/fibonacci_search.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum\
    \ { MAXIMIZE= -1, MINIMIZE= 1 };\n#line 5 \"src/Optimization/fibonacci_search.hpp\"\
    \n// [l,r]\ntemplate <class T, MinMaxEnum obj, class F> std::pair<int64_t, T>\
    \ fibonacci_search(const F &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t\
    \ s= 1, t= 2, a= l - 1, x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+=\
    \ t, t);\n b= a + t, x= b - s;\n T fx= f(x), fy;\n for (bool g; a + b != 2 * x;)\
    \ {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if constexpr (obj ==\
    \ MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n   if (g) b= a,\
    \ a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include \"src/Optimization/MinMaxEnum.hpp\"\
    \n// [l,r]\ntemplate <class T, MinMaxEnum obj, class F> std::pair<int64_t, T>\
    \ fibonacci_search(const F &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t\
    \ s= 1, t= 2, a= l - 1, x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+=\
    \ t, t);\n b= a + t, x= b - s;\n T fx= f(x), fy;\n for (bool g; a + b != 2 * x;)\
    \ {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if constexpr (obj ==\
    \ MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n   if (g) b= a,\
    \ a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n}"
  dependsOn:
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/fibonacci_search.hpp
  requiredBy: []
  timestamp: '2023-08-11 21:45:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2276.test.cpp
documentation_of: src/Optimization/fibonacci_search.hpp
layout: document
title: "\u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u63A2\u7D22"
---
templateの第二引数で最大最小を指定. 
## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `fibonacci_search<T, sgn>(f,l,r)`   | 凸関数 $f(x)$ の $x\in\lbrack l, r\rbrack$ における最大値(最小値) を返す.            |      $\mathcal{O}(A\log n)$  <br> ただし $n=r-l$, $f(x)$ の評価が$\mathcal{O}(A)$                       |

## 参考
[https://qiita.com/tanaka-a/items/f380257328da421c6584](https://qiita.com/tanaka-a/items/f380257328da421c6584) 