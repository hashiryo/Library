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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Li-Chao-Tree
    links: []
  bundledCode: "#line 2 \"src/DataStructure/LiChaoTree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Li-Chao-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * \u76F4\
    \u7DDA\u633F\u5165:O(n log n)\n * \u7DDA\u5206\u633F\u5165:O(n log^2 n)\n * \u6700\
    \u5C0F\u5024\u53D6\u5F97:O(n log n)\n * \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\
    \u3044\u306A\u3089(-a,-b)\u3092\u633F\u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\
    \u53D6\u5F97\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T, T lower = -(1\
    \ << 30), T upper = (1 << 30),\n          std::size_t LIM = (1 << 23)>\nstruct\
    \ LiChaoTree {\n  struct Line {\n    T a, b;\n    Line(T a, T b) : a(a), b(b)\
    \ {}\n    inline T get(T x) const { return a * x + b; }\n  };\n  struct Node {\n\
    \    Line f;\n    Node *ch[2];\n    Node() : f(0, INF) {}\n    Node(const Line\
    \ &f_) : f(f_), ch{nullptr, nullptr} {}\n    void *operator new(size_t) {\n  \
    \    static std::vector<Node> pool(LIM);\n      return &pool[node_count++];\n\
    \    }\n  };\n\n private:\n  static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n  static inline int node_count;\n  Node *root;\n\n private:\n  Node *insert_line(Node\
    \ *t, Line f, const T &x_l, const T &x_r) {\n    if (!t) return new Node(f);\n\
    \    T y_l = f.get(x_l), y_r = f.get(x_r), ty_l = t->f.get(x_l),\n      ty_r =\
    \ t->f.get(x_r);\n    if (ty_l <= y_l && ty_r <= y_r) return t;\n    if (ty_l\
    \ >= y_l && ty_r >= y_r) return t->f = f, t;\n    T x_m = x_l == x_r - 1 ? x_l\
    \ : (x_l + x_r) / 2, ty_m = t->f.get(x_m),\n      y_m = f.get(x_m);\n    if (ty_m\
    \ > y_m) std::swap(t->f, f), std::swap(y_l, ty_l);\n    if (ty_l >= y_l) t->ch[0]\
    \ = insert_line(t->ch[0], f, x_l, x_m);\n    if (ty_l < y_l) t->ch[1] = insert_line(t->ch[1],\
    \ f, x_m + 1, x_r);\n    return t;\n  }\n  Node *insert_segment(Node *t, const\
    \ Line &f, const T &l, const T &r,\n                       const T &x_l, const\
    \ T &x_r) {\n    if (x_r < l || r < x_l) return t;\n    if (l <= x_l && x_r <=\
    \ r) return insert_line(t, f, x_l, x_r);\n    T y_l = f.get(x_l), y_r = f.get(x_r);\n\
    \    if (t && t->f.get(x_l) <= y_l && t->f.get(x_r) <= y_r) return t;\n    if\
    \ (!t) t = new Node(Line(0, INF));\n    T x_m = x_l == x_r - 1 ? x_l : (x_l +\
    \ x_r) / 2;\n    t->ch[0] = insert_segment(t->ch[0], f, l, r, x_l, x_m);\n   \
    \ t->ch[1] = insert_segment(t->ch[1], f, l, r, x_m + 1, x_r);\n    return t;\n\
    \  }\n  T query(const Node *t, const T &x_l, const T &x_r, const T &x) const {\n\
    \    if (!t) return INF;\n    if (x_l == x_r) return t->f.get(x);\n    T x_m =\
    \ x_l == x_r - 1 ? x_l : (x_l + x_r) / 2;\n    return std::min(t->f.get(x), x\
    \ <= x_m ? query(t->ch[0], x_l, x_m, x)\n                                    \
    \      : query(t->ch[1], x_m + 1, x_r, x));\n  }\n\n public:\n  LiChaoTree() :\
    \ root{nullptr} {}\n  T get_inf() { return INF; }\n  void clear() {\n    node_count\
    \ = 0;\n    root = nullptr;\n  }\n  // ax+b\n  void insert_line(T a, T b) {\n\
    \    root = insert_line(root, Line(a, b), lower, upper);\n  }\n  // ax+b for x\
    \ in [l,r)\n  void insert_segment(T l, T r, T a, T b) {\n    root = insert_segment(root,\
    \ Line(a, b), l, r - 1, lower, upper);\n  }\n  T query(T x) const { return query(root,\
    \ lower, upper, x); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Li-Chao-Tree\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * \u76F4\u7DDA\u633F\u5165:O(n log n)\n * \u7DDA\
    \u5206\u633F\u5165:O(n log^2 n)\n * \u6700\u5C0F\u5024\u53D6\u5F97:O(n log n)\n\
    \ * \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\u3044\u306A\u3089(-a,-b)\u3092\u633F\
    \u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\u53D6\u5F97\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <typename T, T lower = -(1 << 30), T upper = (1 << 30),\n         \
    \ std::size_t LIM = (1 << 23)>\nstruct LiChaoTree {\n  struct Line {\n    T a,\
    \ b;\n    Line(T a, T b) : a(a), b(b) {}\n    inline T get(T x) const { return\
    \ a * x + b; }\n  };\n  struct Node {\n    Line f;\n    Node *ch[2];\n    Node()\
    \ : f(0, INF) {}\n    Node(const Line &f_) : f(f_), ch{nullptr, nullptr} {}\n\
    \    void *operator new(size_t) {\n      static std::vector<Node> pool(LIM);\n\
    \      return &pool[node_count++];\n    }\n  };\n\n private:\n  static constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n  static inline int node_count;\n\
    \  Node *root;\n\n private:\n  Node *insert_line(Node *t, Line f, const T &x_l,\
    \ const T &x_r) {\n    if (!t) return new Node(f);\n    T y_l = f.get(x_l), y_r\
    \ = f.get(x_r), ty_l = t->f.get(x_l),\n      ty_r = t->f.get(x_r);\n    if (ty_l\
    \ <= y_l && ty_r <= y_r) return t;\n    if (ty_l >= y_l && ty_r >= y_r) return\
    \ t->f = f, t;\n    T x_m = x_l == x_r - 1 ? x_l : (x_l + x_r) / 2, ty_m = t->f.get(x_m),\n\
    \      y_m = f.get(x_m);\n    if (ty_m > y_m) std::swap(t->f, f), std::swap(y_l,\
    \ ty_l);\n    if (ty_l >= y_l) t->ch[0] = insert_line(t->ch[0], f, x_l, x_m);\n\
    \    if (ty_l < y_l) t->ch[1] = insert_line(t->ch[1], f, x_m + 1, x_r);\n    return\
    \ t;\n  }\n  Node *insert_segment(Node *t, const Line &f, const T &l, const T\
    \ &r,\n                       const T &x_l, const T &x_r) {\n    if (x_r < l ||\
    \ r < x_l) return t;\n    if (l <= x_l && x_r <= r) return insert_line(t, f, x_l,\
    \ x_r);\n    T y_l = f.get(x_l), y_r = f.get(x_r);\n    if (t && t->f.get(x_l)\
    \ <= y_l && t->f.get(x_r) <= y_r) return t;\n    if (!t) t = new Node(Line(0,\
    \ INF));\n    T x_m = x_l == x_r - 1 ? x_l : (x_l + x_r) / 2;\n    t->ch[0] =\
    \ insert_segment(t->ch[0], f, l, r, x_l, x_m);\n    t->ch[1] = insert_segment(t->ch[1],\
    \ f, l, r, x_m + 1, x_r);\n    return t;\n  }\n  T query(const Node *t, const\
    \ T &x_l, const T &x_r, const T &x) const {\n    if (!t) return INF;\n    if (x_l\
    \ == x_r) return t->f.get(x);\n    T x_m = x_l == x_r - 1 ? x_l : (x_l + x_r)\
    \ / 2;\n    return std::min(t->f.get(x), x <= x_m ? query(t->ch[0], x_l, x_m,\
    \ x)\n                                          : query(t->ch[1], x_m + 1, x_r,\
    \ x));\n  }\n\n public:\n  LiChaoTree() : root{nullptr} {}\n  T get_inf() { return\
    \ INF; }\n  void clear() {\n    node_count = 0;\n    root = nullptr;\n  }\n  //\
    \ ax+b\n  void insert_line(T a, T b) {\n    root = insert_line(root, Line(a, b),\
    \ lower, upper);\n  }\n  // ax+b for x in [l,r)\n  void insert_segment(T l, T\
    \ r, T a, T b) {\n    root = insert_segment(root, Line(a, b), l, r - 1, lower,\
    \ upper);\n  }\n  T query(T x) const { return query(root, lower, upper, x); }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2020-11-07 14:11:46+09:00'
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
