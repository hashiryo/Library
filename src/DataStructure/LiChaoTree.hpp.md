---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LiChaoTree.hpp\"\n#include <limits>\n\
    #include <algorithm>\ntemplate <typename T> class LiChaoTree {\n struct Line {\n\
    \  T a, b;\n  inline T get(T x) const { return a * x + b; }\n };\n struct Node\
    \ {\n  Line f;\n  Node *ch[2]= {nullptr, nullptr};\n } * root;\n static constexpr\
    \ T L= -2e9, U= 2e9;\n static constexpr T INF= std::numeric_limits<T>::max() /\
    \ 2;\n static inline int node_count;\n int sgn(const T &x) const {\n  static constexpr\
    \ T EPS= 1e-10;\n  return x < -EPS ? -1 : x > +EPS ? 1 : 0;\n }\n void addl(Node\
    \ *&t, Line f, const T &x_l, const T &x_r) {\n  if (!t) return t= new Node{f},\
    \ void();\n  int dif_l= sgn(t->f.get(x_l) - f.get(x_l)), dif_r= sgn(t->f.get(x_r)\
    \ - f.get(x_r));\n  if (dif_l <= 0 && dif_r <= 0) return;\n  if (dif_l >= 0 &&\
    \ dif_r >= 0) return t->f= f, void();\n  T x_m= (x_l + x_r) / 2;\n  int dif_m=\
    \ sgn(t->f.get(x_m) - f.get(x_m));\n  if (dif_m > 0) std::swap(t->f, f), dif_l=\
    \ -dif_l;\n  if (sgn(x_l - x_m) == 0) return;\n  if (dif_l > 0) addl(t->ch[0],\
    \ f, x_l, x_m);\n  if (dif_l < 0) addl(t->ch[1], f, x_m, x_r);\n }\n void adds(Node\
    \ *&t, const Line &f, const T &l, const T &r, const T &x_l, const T &x_r) {\n\
    \  if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r)) return;\n  if (0 <= sgn(x_l - l)\
    \ && sgn(x_r - r) <= 0) return addl(t, f, x_l, x_r);\n  if (t && sgn(t->f.get(x_l)\
    \ - f.get(x_l)) <= 0 && sgn(t->f.get(x_r) - f.get(x_r)) <= 0) return;\n  if (!t)\
    \ t= new Node{Line{0, INF}};\n  T x_m= (x_l + x_r) / 2;\n  adds(t->ch[0], f, l,\
    \ r, x_l, x_m), adds(t->ch[1], f, l, r, x_m, x_r);\n }\n T query(const Node *t,\
    \ const T &x_l, const T &x_r, const T &x) const {\n  if (!t) return INF;\n  if\
    \ (sgn(x_l - x_r) == 0) return t->f.get(x);\n  T x_m= (x_l + x_r) / 2;\n  return\
    \ std::min(t->f.get(x), (sgn(x - x_m) < 0 ? query(t->ch[0], x_l, x_m, x) : query(t->ch[1],\
    \ x_m, x_r, x)));\n }\npublic:\n LiChaoTree(): root{nullptr} {}\n T get_inf()\
    \ { return INF; }\n // ax+b\n void insert_line(T a, T b) { addl(root, Line{a,\
    \ b}, L, U); }\n // ax+b for x in [l,r)\n void insert_segment(T l, T r, T a, T\
    \ b) { adds(root, Line{a, b}, l, r, L, U); }\n T query(T x) const { return query(root,\
    \ L, U, x); }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\ntemplate <typename\
    \ T> class LiChaoTree {\n struct Line {\n  T a, b;\n  inline T get(T x) const\
    \ { return a * x + b; }\n };\n struct Node {\n  Line f;\n  Node *ch[2]= {nullptr,\
    \ nullptr};\n } * root;\n static constexpr T L= -2e9, U= 2e9;\n static constexpr\
    \ T INF= std::numeric_limits<T>::max() / 2;\n static inline int node_count;\n\
    \ int sgn(const T &x) const {\n  static constexpr T EPS= 1e-10;\n  return x <\
    \ -EPS ? -1 : x > +EPS ? 1 : 0;\n }\n void addl(Node *&t, Line f, const T &x_l,\
    \ const T &x_r) {\n  if (!t) return t= new Node{f}, void();\n  int dif_l= sgn(t->f.get(x_l)\
    \ - f.get(x_l)), dif_r= sgn(t->f.get(x_r) - f.get(x_r));\n  if (dif_l <= 0 &&\
    \ dif_r <= 0) return;\n  if (dif_l >= 0 && dif_r >= 0) return t->f= f, void();\n\
    \  T x_m= (x_l + x_r) / 2;\n  int dif_m= sgn(t->f.get(x_m) - f.get(x_m));\n  if\
    \ (dif_m > 0) std::swap(t->f, f), dif_l= -dif_l;\n  if (sgn(x_l - x_m) == 0) return;\n\
    \  if (dif_l > 0) addl(t->ch[0], f, x_l, x_m);\n  if (dif_l < 0) addl(t->ch[1],\
    \ f, x_m, x_r);\n }\n void adds(Node *&t, const Line &f, const T &l, const T &r,\
    \ const T &x_l, const T &x_r) {\n  if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r))\
    \ return;\n  if (0 <= sgn(x_l - l) && sgn(x_r - r) <= 0) return addl(t, f, x_l,\
    \ x_r);\n  if (t && sgn(t->f.get(x_l) - f.get(x_l)) <= 0 && sgn(t->f.get(x_r)\
    \ - f.get(x_r)) <= 0) return;\n  if (!t) t= new Node{Line{0, INF}};\n  T x_m=\
    \ (x_l + x_r) / 2;\n  adds(t->ch[0], f, l, r, x_l, x_m), adds(t->ch[1], f, l,\
    \ r, x_m, x_r);\n }\n T query(const Node *t, const T &x_l, const T &x_r, const\
    \ T &x) const {\n  if (!t) return INF;\n  if (sgn(x_l - x_r) == 0) return t->f.get(x);\n\
    \  T x_m= (x_l + x_r) / 2;\n  return std::min(t->f.get(x), (sgn(x - x_m) < 0 ?\
    \ query(t->ch[0], x_l, x_m, x) : query(t->ch[1], x_m, x_r, x)));\n }\npublic:\n\
    \ LiChaoTree(): root{nullptr} {}\n T get_inf() { return INF; }\n // ax+b\n void\
    \ insert_line(T a, T b) { addl(root, Line{a, b}, L, U); }\n // ax+b for x in [l,r)\n\
    \ void insert_segment(T l, T r, T a, T b) { adds(root, Line{a, b}, l, r, L, U);\
    \ }\n T query(T x) const { return query(root, L, U, x); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:28:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/line_add_get_min.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
documentation_of: src/DataStructure/LiChaoTree.hpp
layout: document
title: Li-Chao-Tree
---
浮動小数点も行けるはず \
最大値取得したいなら(-a,-b)を挿入して-最小値を取得
## 計算量
直線挿入: $\mathcal{O}(\log n)$　\
線分挿入: $\mathcal{O}((\log n)^2)$　\
最小値取得: $\mathcal{O}(\log n)$
## 問題例
[AtCoder Regular Contest 051 D - 長方形](https://atcoder.jp/contests/arc051/tasks/arc051_d) (double型)