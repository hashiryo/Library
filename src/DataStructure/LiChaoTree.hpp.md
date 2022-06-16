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
    document_title: Li-Chao-Tree
    links:
    - https://atcoder.jp/contests/arc051/tasks/arc051_d
  bundledCode: "#line 2 \"src/DataStructure/LiChaoTree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Li-Chao-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * \u76F4\
    \u7DDA\u633F\u5165:O(log n)\n * \u7DDA\u5206\u633F\u5165:O(log^2 n)\n * \u6700\
    \u5C0F\u5024\u53D6\u5F97:O(log n)\n * \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\
    \u3044\u306A\u3089(-a,-b)\u3092\u633F\u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\
    \u53D6\u5F97\n * \u6D6E\u52D5\u5C0F\u6570\u70B9\u3082\u884C\u3051\u308B\u306F\u305A\
    \n */\n\n// verify\u7528: https://atcoder.jp/contests/arc051/tasks/arc051_d (double\u578B\
    )\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nclass LiChaoTree {\n  struct\
    \ Line {\n    T a, b;\n    inline T get(T x) const { return a * x + b; }\n  };\n\
    \  struct Node {\n    Line f;\n    Node *ch[2] = {nullptr, nullptr};\n  } * root;\n\
    \  static constexpr T L = -2e9, U = 2e9;\n  static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n  static inline int node_count;\n  int sgn(const T &x) const {\n    static\
    \ constexpr T EPS = 1e-10;\n    return x < -EPS ? -1 : x > +EPS ? 1 : 0;\n  }\n\
    \  void addl(Node *&t, Line f, const T &x_l, const T &x_r) {\n    if (!t) return\
    \ t = new Node{f}, void();\n    int dif_l = sgn(t->f.get(x_l) - f.get(x_l)),\n\
    \        dif_r = sgn(t->f.get(x_r) - f.get(x_r));\n    if (dif_l <= 0 && dif_r\
    \ <= 0) return;\n    if (dif_l >= 0 && dif_r >= 0) return t->f = f, void();\n\
    \    T x_m = (x_l + x_r) / 2;\n    int dif_m = sgn(t->f.get(x_m) - f.get(x_m));\n\
    \    if (dif_m > 0) std::swap(t->f, f), dif_l = -dif_l;\n    if (sgn(x_l - x_m)\
    \ == 0) return;\n    if (dif_l > 0) addl(t->ch[0], f, x_l, x_m);\n    if (dif_l\
    \ < 0) addl(t->ch[1], f, x_m, x_r);\n  }\n  void adds(Node *&t, const Line &f,\
    \ const T &l, const T &r, const T &x_l,\n            const T &x_r) {\n    if (sgn(x_r\
    \ - l) <= 0 || 0 <= sgn(x_l - r)) return;\n    if (0 <= sgn(x_l - l) && sgn(x_r\
    \ - r) <= 0) return addl(t, f, x_l, x_r);\n    if (t && sgn(t->f.get(x_l) - f.get(x_l))\
    \ <= 0 &&\n        sgn(t->f.get(x_r) - f.get(x_r)) <= 0)\n      return;\n    if\
    \ (!t) t = new Node{Line{0, INF}};\n    T x_m = (x_l + x_r) / 2;\n    adds(t->ch[0],\
    \ f, l, r, x_l, x_m), adds(t->ch[1], f, l, r, x_m, x_r);\n  }\n  T query(const\
    \ Node *t, const T &x_l, const T &x_r, const T &x) const {\n    if (!t) return\
    \ INF;\n    if (sgn(x_l - x_r) == 0) return t->f.get(x);\n    T x_m = (x_l + x_r)\
    \ / 2;\n    return std::min(t->f.get(x),\n                    (sgn(x - x_m) <\
    \ 0 ? query(t->ch[0], x_l, x_m, x)\n                                      : query(t->ch[1],\
    \ x_m, x_r, x)));\n  }\n\n public:\n  LiChaoTree() : root{nullptr} {}\n  T get_inf()\
    \ { return INF; }\n  // ax+b\n  void insert_line(T a, T b) { addl(root, Line{a,\
    \ b}, L, U); }\n  // ax+b for x in [l,r)\n  void insert_segment(T l, T r, T a,\
    \ T b) {\n    adds(root, Line{a, b}, l, r, L, U);\n  }\n  T query(T x) const {\
    \ return query(root, L, U, x); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Li-Chao-Tree\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * \u76F4\u7DDA\u633F\u5165:O(log n)\n * \u7DDA\
    \u5206\u633F\u5165:O(log^2 n)\n * \u6700\u5C0F\u5024\u53D6\u5F97:O(log n)\n *\
    \ \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\u3044\u306A\u3089(-a,-b)\u3092\u633F\
    \u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\u53D6\u5F97\n * \u6D6E\u52D5\u5C0F\
    \u6570\u70B9\u3082\u884C\u3051\u308B\u306F\u305A\n */\n\n// verify\u7528: https://atcoder.jp/contests/arc051/tasks/arc051_d\
    \ (double\u578B)\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nclass LiChaoTree\
    \ {\n  struct Line {\n    T a, b;\n    inline T get(T x) const { return a * x\
    \ + b; }\n  };\n  struct Node {\n    Line f;\n    Node *ch[2] = {nullptr, nullptr};\n\
    \  } * root;\n  static constexpr T L = -2e9, U = 2e9;\n  static constexpr T INF\
    \ = std::numeric_limits<T>::max() / 2;\n  static inline int node_count;\n  int\
    \ sgn(const T &x) const {\n    static constexpr T EPS = 1e-10;\n    return x <\
    \ -EPS ? -1 : x > +EPS ? 1 : 0;\n  }\n  void addl(Node *&t, Line f, const T &x_l,\
    \ const T &x_r) {\n    if (!t) return t = new Node{f}, void();\n    int dif_l\
    \ = sgn(t->f.get(x_l) - f.get(x_l)),\n        dif_r = sgn(t->f.get(x_r) - f.get(x_r));\n\
    \    if (dif_l <= 0 && dif_r <= 0) return;\n    if (dif_l >= 0 && dif_r >= 0)\
    \ return t->f = f, void();\n    T x_m = (x_l + x_r) / 2;\n    int dif_m = sgn(t->f.get(x_m)\
    \ - f.get(x_m));\n    if (dif_m > 0) std::swap(t->f, f), dif_l = -dif_l;\n   \
    \ if (sgn(x_l - x_m) == 0) return;\n    if (dif_l > 0) addl(t->ch[0], f, x_l,\
    \ x_m);\n    if (dif_l < 0) addl(t->ch[1], f, x_m, x_r);\n  }\n  void adds(Node\
    \ *&t, const Line &f, const T &l, const T &r, const T &x_l,\n            const\
    \ T &x_r) {\n    if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r)) return;\n    if (0\
    \ <= sgn(x_l - l) && sgn(x_r - r) <= 0) return addl(t, f, x_l, x_r);\n    if (t\
    \ && sgn(t->f.get(x_l) - f.get(x_l)) <= 0 &&\n        sgn(t->f.get(x_r) - f.get(x_r))\
    \ <= 0)\n      return;\n    if (!t) t = new Node{Line{0, INF}};\n    T x_m = (x_l\
    \ + x_r) / 2;\n    adds(t->ch[0], f, l, r, x_l, x_m), adds(t->ch[1], f, l, r,\
    \ x_m, x_r);\n  }\n  T query(const Node *t, const T &x_l, const T &x_r, const\
    \ T &x) const {\n    if (!t) return INF;\n    if (sgn(x_l - x_r) == 0) return\
    \ t->f.get(x);\n    T x_m = (x_l + x_r) / 2;\n    return std::min(t->f.get(x),\n\
    \                    (sgn(x - x_m) < 0 ? query(t->ch[0], x_l, x_m, x)\n      \
    \                                : query(t->ch[1], x_m, x_r, x)));\n  }\n\n public:\n\
    \  LiChaoTree() : root{nullptr} {}\n  T get_inf() { return INF; }\n  // ax+b\n\
    \  void insert_line(T a, T b) { addl(root, Line{a, b}, L, U); }\n  // ax+b for\
    \ x in [l,r)\n  void insert_segment(T l, T r, T a, T b) {\n    adds(root, Line{a,\
    \ b}, l, r, L, U);\n  }\n  T query(T x) const { return query(root, L, U, x); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2021-11-21 22:42:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: src/DataStructure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/LiChaoTree.hpp
- /library/src/DataStructure/LiChaoTree.hpp.html
title: Li-Chao-Tree
---
