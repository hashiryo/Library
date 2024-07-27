---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2725.CHT.test.cpp
    title: test/aoj/2725.CHT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc244_ex.test.cpp
    title: test/atcoder/abc244_ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.CHT.test.cpp
    title: test/yosupo/line_add_get_min.CHT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1297.CHT.test.cpp
    title: test/yukicoder/1297.CHT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2458.CHT.test.cpp
    title: test/yukicoder/2458.CHT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/ConvexHullTrick.hpp\"\n#include <limits>\n\
    #include <algorithm>\n#include <set>\n#include <array>\n#include <cassert>\n#line\
    \ 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum { MAXIMIZE= -1, MINIMIZE=\
    \ 1 };\n#line 8 \"src/Optimization/ConvexHullTrick.hpp\"\ntemplate <typename T,\
    \ MinMaxEnum obj= MINIMIZE> class ConvexHullTrick {\n struct Line {\n  T k, m;\n\
    \  mutable T p;\n  bool operator<(const Line &o) const { return k < o.k; }\n \
    \ bool operator<(T x) const { return p < x; }\n };\n static constexpr T INF= std::numeric_limits<T>::max();\n\
    \ static T lc_div(T a, T b) {\n  if constexpr (std::is_integral_v<T>) return a\
    \ / b - ((a ^ b) < 0 && a % b);\n  else return a / b;\n }\n using ms= std::multiset<Line,\
    \ std::less<>>;\n ms ls;\n bool insect(typename ms::iterator x, typename ms::iterator\
    \ y) {\n  if (y == ls.end()) return x->p= INF, false;\n  if (x->k == y->k) x->p=\
    \ (x->m > y->m ? INF : -INF);\n  else x->p= lc_div(y->m - x->m, x->k - y->k);\n\
    \  return x->p >= y->p;\n }\npublic:\n void insert(T k, T m) {\n  if constexpr\
    \ (obj == MINIMIZE) k= -k, m= -m;\n  auto z= ls.insert({k, m, 0}), y= z++, x=\
    \ y;\n  while (insect(y, z)) z= ls.erase(z);\n  if (x != ls.begin() && insect(--x,\
    \ y)) insect(x, y= ls.erase(y));\n  while ((y= x) != ls.begin() && (--x)->p >=\
    \ y->p) insect(x, ls.erase(y));\n }\n bool empty() const { return ls.empty();\
    \ }\n std::array<T, 2> query_line(T x) const {\n  assert(!ls.empty());\n  auto\
    \ l= ls.lower_bound(x);\n  if constexpr (obj == MINIMIZE) return {-l->k, -l->m};\n\
    \  else return {l->k, l->m};\n }\n T query(T x) const {\n  auto [k, m]= query_line(x);\n\
    \  return k * x + m;\n }\n};\ntemplate <typename T> class ConvexHullTrick_XY {\n\
    \ ConvexHullTrick<long double, MINIMIZE> cht_mn;\n ConvexHullTrick<long double,\
    \ MAXIMIZE> cht_mx;\n T amx= std::numeric_limits<T>::lowest(), amn= std::numeric_limits<T>::max();\n\
    public:\n void insert(T a, T b) { cht_mn.insert(a, b), cht_mx.insert(a, b), amn=\
    \ std::min(amn, a), amx= std::max(amx, a); }\n bool empty() const { return cht_mn.empty();\
    \ }\n T get_max(T x, T y) const {\n  assert(!cht_mn.empty());\n  if (y == 0) return\
    \ std::max(amn * x, amx * x);\n  auto z= (long double)x / y;\n  auto [a, b]= y\
    \ > 0 ? cht_mx.query_line(z) : cht_mn.query_line(z);\n  return T(a) * x + T(b)\
    \ * y;\n }\n T get_min(T x, T y) const {\n  assert(!cht_mn.empty());\n  if (y\
    \ == 0) return std::min(amn * x, amx * x);\n  auto z= (long double)x / y;\n  auto\
    \ [a, b]= y > 0 ? cht_mn.query_line(z) : cht_mx.query_line(z);\n  return T(a)\
    \ * x + T(b) * y;\n }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n#include <set>\n#include\
    \ <array>\n#include <cassert>\n#include \"src/Optimization/MinMaxEnum.hpp\"\n\
    template <typename T, MinMaxEnum obj= MINIMIZE> class ConvexHullTrick {\n struct\
    \ Line {\n  T k, m;\n  mutable T p;\n  bool operator<(const Line &o) const { return\
    \ k < o.k; }\n  bool operator<(T x) const { return p < x; }\n };\n static constexpr\
    \ T INF= std::numeric_limits<T>::max();\n static T lc_div(T a, T b) {\n  if constexpr\
    \ (std::is_integral_v<T>) return a / b - ((a ^ b) < 0 && a % b);\n  else return\
    \ a / b;\n }\n using ms= std::multiset<Line, std::less<>>;\n ms ls;\n bool insect(typename\
    \ ms::iterator x, typename ms::iterator y) {\n  if (y == ls.end()) return x->p=\
    \ INF, false;\n  if (x->k == y->k) x->p= (x->m > y->m ? INF : -INF);\n  else x->p=\
    \ lc_div(y->m - x->m, x->k - y->k);\n  return x->p >= y->p;\n }\npublic:\n void\
    \ insert(T k, T m) {\n  if constexpr (obj == MINIMIZE) k= -k, m= -m;\n  auto z=\
    \ ls.insert({k, m, 0}), y= z++, x= y;\n  while (insect(y, z)) z= ls.erase(z);\n\
    \  if (x != ls.begin() && insect(--x, y)) insect(x, y= ls.erase(y));\n  while\
    \ ((y= x) != ls.begin() && (--x)->p >= y->p) insect(x, ls.erase(y));\n }\n bool\
    \ empty() const { return ls.empty(); }\n std::array<T, 2> query_line(T x) const\
    \ {\n  assert(!ls.empty());\n  auto l= ls.lower_bound(x);\n  if constexpr (obj\
    \ == MINIMIZE) return {-l->k, -l->m};\n  else return {l->k, l->m};\n }\n T query(T\
    \ x) const {\n  auto [k, m]= query_line(x);\n  return k * x + m;\n }\n};\ntemplate\
    \ <typename T> class ConvexHullTrick_XY {\n ConvexHullTrick<long double, MINIMIZE>\
    \ cht_mn;\n ConvexHullTrick<long double, MAXIMIZE> cht_mx;\n T amx= std::numeric_limits<T>::lowest(),\
    \ amn= std::numeric_limits<T>::max();\npublic:\n void insert(T a, T b) { cht_mn.insert(a,\
    \ b), cht_mx.insert(a, b), amn= std::min(amn, a), amx= std::max(amx, a); }\n bool\
    \ empty() const { return cht_mn.empty(); }\n T get_max(T x, T y) const {\n  assert(!cht_mn.empty());\n\
    \  if (y == 0) return std::max(amn * x, amx * x);\n  auto z= (long double)x /\
    \ y;\n  auto [a, b]= y > 0 ? cht_mx.query_line(z) : cht_mn.query_line(z);\n  return\
    \ T(a) * x + T(b) * y;\n }\n T get_min(T x, T y) const {\n  assert(!cht_mn.empty());\n\
    \  if (y == 0) return std::min(amn * x, amx * x);\n  auto z= (long double)x /\
    \ y;\n  auto [a, b]= y > 0 ? cht_mn.query_line(z) : cht_mx.query_line(z);\n  return\
    \ T(a) * x + T(b) * y;\n }\n};"
  dependsOn:
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2023-10-17 01:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2458.CHT.test.cpp
  - test/yukicoder/1297.CHT.test.cpp
  - test/yukicoder/2012.test.cpp
  - test/atcoder/abc244_ex.test.cpp
  - test/yosupo/line_add_get_min.CHT.test.cpp
  - test/aoj/2725.CHT.test.cpp
documentation_of: src/Optimization/ConvexHullTrick.hpp
layout: document
title: Convex-Hull-Trick
---
浮動小数点数も行けるはず

## `ConvexHullTrick`
templateの第二引数で最大最小を指定. デフォルトは最小値取得.

|メンバ関数|概要|計算量|
|---|---|---|
|`empty()`|何も直線を挿入していないなら true||
|`insert(k,m)`|直線 $y=kx+m$ を挿入 | $\mathcal{O}(\log n)$　|
|`query_line(x)` | $x$ における最小値(最大値)をとる直線 $y=kx+m$ の係数 $(k,m)$ を返す. |$\mathcal{O}(\log n)$ | 
|`query(x)` | $x$ における最小値(最大値) を返す |$\mathcal{O}(\log n)$ | 

## `ConvexHullTrick_XY`

|メンバ関数|概要|計算量|
|---|---|---|
|`empty()`|何も直線を挿入していないなら true||
|`insert(a,b)`|直線 $ax+by$ を挿入 | $\mathcal{O}(\log n)$　|
|`get_min(x,y)` | $(x,y)$ における最小値を返す.  |$\mathcal{O}(\log n)$ | 
|`get_max(x,y)` | $(x,y)$ における最大値を返す.  |$\mathcal{O}(\log n)$ | 

## 問題例
[AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d) (ax+by) \
[AtCoder Beginner Contest 244 Ex - Linear Maximization](https://atcoder.jp/contests/abc244/tasks/abc244_h) (ax+by)\
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (有理数クラスでac)

## 参考
[https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h) \
[https://maspypy.github.io/library/convex/cht.hpp](https://maspypy.github.io/library/convex/cht.hpp)