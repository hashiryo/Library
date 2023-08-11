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
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/LiChaoTree.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum {\
    \ MAXIMIZE= -1, MINIMIZE= 1 };\n#line 5 \"src/Optimization/LiChaoTree.hpp\"\n\
    template <typename T, MinMaxEnum obj= MINIMIZE> class LiChaoTree {\n struct Line\
    \ {\n  T a, b;\n  inline T get(T x) const { return a * x + b; }\n };\n struct\
    \ Node {\n  Line f;\n  Node *ch[2]= {nullptr, nullptr};\n } *root;\n const T L,\
    \ U, INF;\n static inline int node_count;\n int sgn(const T &x) const {\n  if\
    \ constexpr (std::is_floating_point_v<T>) {\n   static constexpr T EPS= 1e-10;\n\
    \   return x < -EPS ? -1 : x > +EPS ? 1 : 0;\n  } else return x < 0 ? -1 : x >\
    \ 0 ? 1 : 0;\n }\n void addl(Node *&t, Line f, const T &x_l, const T &x_r) {\n\
    \  if (!t) return t= new Node{f}, void();\n  int dif_l= sgn(t->f.get(x_l) - f.get(x_l)),\
    \ dif_r= sgn(t->f.get(x_r) - f.get(x_r));\n  if (dif_l <= 0 && dif_r <= 0) return;\n\
    \  if (dif_l >= 0 && dif_r >= 0) return t->f= f, void();\n  T x_m= (x_l + x_r)\
    \ / 2;\n  int dif_m= sgn(t->f.get(x_m) - f.get(x_m));\n  if (dif_m > 0) std::swap(t->f,\
    \ f), dif_l= -dif_l;\n  if (sgn(x_l - x_m) == 0) return;\n  if (dif_l > 0) addl(t->ch[0],\
    \ f, x_l, x_m);\n  if (dif_l < 0) addl(t->ch[1], f, x_m, x_r);\n }\n void adds(Node\
    \ *&t, const Line &f, const T &l, const T &r, const T &x_l, const T &x_r) {\n\
    \  if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r)) return;\n  if (0 <= sgn(x_l - l)\
    \ && sgn(x_r - r) <= 0) return addl(t, f, x_l, x_r);\n  if (t && sgn(t->f.get(x_l)\
    \ - f.get(x_l)) <= 0 && sgn(t->f.get(x_r) - f.get(x_r)) <= 0) return;\n  if (!t)\
    \ t= new Node{Line{0, INF}};\n  T x_m= (x_l + x_r) / 2;\n  adds(t->ch[0], f, l,\
    \ r, x_l, x_m), adds(t->ch[1], f, l, r, x_m, x_r);\n }\n inline T query(const\
    \ Node *t, const T &x_l, const T &x_r, const T &x) const {\n  if (!t) return INF;\n\
    \  if (sgn(x_l - x_r) == 0) return t->f.get(x);\n  T x_m= (x_l + x_r) / 2;\n \
    \ return std::min(t->f.get(x), (sgn(x - x_m) < 0 ? query(t->ch[0], x_l, x_m, x)\
    \ : query(t->ch[1], x_m, x_r, x)));\n }\npublic:\n LiChaoTree(T l= -2e9, T u=\
    \ 2e9, T inf= std::numeric_limits<T>::max() / 2): root{nullptr}, L(l), U(u), INF(inf)\
    \ {}\n T get_inf() { return INF; }\n // ax+b\n void insert_line(T a, T b) { addl(root,\
    \ Line{a * obj, b * obj}, L, U); }\n // ax+b for x in [l,r)\n void insert_segment(T\
    \ l, T r, T a, T b) { adds(root, Line{a * obj, b * obj}, l, r, L, U); }\n T query(T\
    \ x) const { else return query(root, L, U, x) * obj; }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n#include \"src/Optimization/MinMaxEnum.hpp\"\
    \ntemplate <typename T, MinMaxEnum obj= MINIMIZE> class LiChaoTree {\n struct\
    \ Line {\n  T a, b;\n  inline T get(T x) const { return a * x + b; }\n };\n struct\
    \ Node {\n  Line f;\n  Node *ch[2]= {nullptr, nullptr};\n } *root;\n const T L,\
    \ U, INF;\n static inline int node_count;\n int sgn(const T &x) const {\n  if\
    \ constexpr (std::is_floating_point_v<T>) {\n   static constexpr T EPS= 1e-10;\n\
    \   return x < -EPS ? -1 : x > +EPS ? 1 : 0;\n  } else return x < 0 ? -1 : x >\
    \ 0 ? 1 : 0;\n }\n void addl(Node *&t, Line f, const T &x_l, const T &x_r) {\n\
    \  if (!t) return t= new Node{f}, void();\n  int dif_l= sgn(t->f.get(x_l) - f.get(x_l)),\
    \ dif_r= sgn(t->f.get(x_r) - f.get(x_r));\n  if (dif_l <= 0 && dif_r <= 0) return;\n\
    \  if (dif_l >= 0 && dif_r >= 0) return t->f= f, void();\n  T x_m= (x_l + x_r)\
    \ / 2;\n  int dif_m= sgn(t->f.get(x_m) - f.get(x_m));\n  if (dif_m > 0) std::swap(t->f,\
    \ f), dif_l= -dif_l;\n  if (sgn(x_l - x_m) == 0) return;\n  if (dif_l > 0) addl(t->ch[0],\
    \ f, x_l, x_m);\n  if (dif_l < 0) addl(t->ch[1], f, x_m, x_r);\n }\n void adds(Node\
    \ *&t, const Line &f, const T &l, const T &r, const T &x_l, const T &x_r) {\n\
    \  if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r)) return;\n  if (0 <= sgn(x_l - l)\
    \ && sgn(x_r - r) <= 0) return addl(t, f, x_l, x_r);\n  if (t && sgn(t->f.get(x_l)\
    \ - f.get(x_l)) <= 0 && sgn(t->f.get(x_r) - f.get(x_r)) <= 0) return;\n  if (!t)\
    \ t= new Node{Line{0, INF}};\n  T x_m= (x_l + x_r) / 2;\n  adds(t->ch[0], f, l,\
    \ r, x_l, x_m), adds(t->ch[1], f, l, r, x_m, x_r);\n }\n inline T query(const\
    \ Node *t, const T &x_l, const T &x_r, const T &x) const {\n  if (!t) return INF;\n\
    \  if (sgn(x_l - x_r) == 0) return t->f.get(x);\n  T x_m= (x_l + x_r) / 2;\n \
    \ return std::min(t->f.get(x), (sgn(x - x_m) < 0 ? query(t->ch[0], x_l, x_m, x)\
    \ : query(t->ch[1], x_m, x_r, x)));\n }\npublic:\n LiChaoTree(T l= -2e9, T u=\
    \ 2e9, T inf= std::numeric_limits<T>::max() / 2): root{nullptr}, L(l), U(u), INF(inf)\
    \ {}\n T get_inf() { return INF; }\n // ax+b\n void insert_line(T a, T b) { addl(root,\
    \ Line{a * obj, b * obj}, L, U); }\n // ax+b for x in [l,r)\n void insert_segment(T\
    \ l, T r, T a, T b) { adds(root, Line{a * obj, b * obj}, l, r, L, U); }\n T query(T\
    \ x) const { else return query(root, L, U, x) * obj; }\n};\n"
  dependsOn:
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: false
  path: src/Optimization/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-08-11 21:45:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/line_add_get_min.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
documentation_of: src/Optimization/LiChaoTree.hpp
layout: document
title: Li-Chao-Tree
---
浮動小数点も行けるはず \
templateの第二引数で最大最小を指定. デフォルトは最小値取得.

## メンバ関数

|名前|概要|計算量|
|---|---|---|
|`LiChaoTree(l,u,inf)`| コンストラクタ. <br>考える $x$ の範囲 $\lbrack l,r\rbrack$ と $y$ 方向の ($\infty$ とみなせるほどの) 十分大きい値を与える. <br> デフォルトは `l=-2e^9, r=2e^9, inf=numeric_limits<T>::max()/2` .||
|`insert_line(a,b)`|直線 $y=ax+b$ を挿入 | $\mathcal{O}(\log n)$　|
|`insert_segment(l,r,a,b)`| 線分 $y=ax+b\;(x\in\lbrack l,r \rbrack) $ を挿入 | $\mathcal{O}((\log n)^2)$|
|`query(x)` | $x$ における最小値(最大値) を返す |$\mathcal{O}(\log n)$ | 

## 問題例
[AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d) (doubleでac, 有理数クラスだとacできず...) \
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (有理数クラスでac, doubleだとwa)