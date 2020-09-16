---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/LiChaoTree.hpp
    title: Li-Chao-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"src/DataStructure/LiChaoTree.hpp\"\
    \n/**\n * @title Li-Chao-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ @brief \u76F4\u7DDA\u633F\u5165:O(n log n)\n * @brief \u7DDA\u5206\u633F\u5165\
    :O(n log^2 n)\n * @brief \u6700\u5C0F\u5024\u53D6\u5F97:O(n log n)\n * @brief\
    \ \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\u3044\u306A\u3089(-a,-b)\u3092\u633F\
    \u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\u53D6\u5F97\n */\n\n#ifndef call_from_test\n\
    #line 12 \"src/DataStructure/LiChaoTree.hpp\"\nusing namespace std;\n#endif\n\n\
    template <typename T, T x_low = -(1 << 30), T x_high = (1 << 30),\n          size_t\
    \ LIM = (1 << 23)>\nstruct LiChaoTree {\n  struct Line {\n    T a, b;\n    Line(T\
    \ a, T b) : a(a), b(b) {}\n    inline T get(T x) const { return a * x + b; }\n\
    \  };\n  struct Node {\n    Line x;\n    Node *ch[2];\n    Node() : x(0, INF)\
    \ {}\n    Node(const Line &x) : x(x), ch{nullptr, nullptr} {}\n    void *operator\
    \ new(size_t) {\n      static vector<Node> pool(LIM);\n      return &pool[node_count++];\n\
    \    }\n  };\n\n private:\n  static constexpr T INF = numeric_limits<T>::max()\
    \ / 2;\n  static int node_count;\n  Node *root;\n\n private:\n  Node *insert_line(Node\
    \ *t, Line &x, const T &l, const T &r, const T &x_l,\n                    const\
    \ T &x_r) {\n    if (!t) return new Node(x);\n    T t_l = t->x.get(l), t_r = t->x.get(r);\n\
    \    if (t_l <= x_l && t_r <= x_r) {\n      return t;\n    } else if (t_l >= x_l\
    \ && t_r >= x_r) {\n      t->x = x;\n      return t;\n    } else {\n      T m\
    \ = (l + r) / 2;\n      if (m == r) --m;\n      T t_m = t->x.get(m), x_m = x.get(m);\n\
    \      if (t_m > x_m) {\n        swap(t->x, x);\n        if (x_l >= t_l)\n   \
    \       t->ch[0] = insert_line(t->ch[0], x, l, m, t_l, t_m);\n        else\n \
    \         t->ch[1] = insert_line(t->ch[1], x, m + 1, r, t_m + x.a, t_r);\n   \
    \   } else {\n        if (t_l >= x_l)\n          t->ch[0] = insert_line(t->ch[0],\
    \ x, l, m, x_l, x_m);\n        else\n          t->ch[1] = insert_line(t->ch[1],\
    \ x, m + 1, r, x_m + x.a, x_r);\n      }\n      return t;\n    }\n  }\n  Node\
    \ *insert_segment(Node *t, Line &x, const T &a, const T &b, const T &l,\n    \
    \                   const T &r, const T &x_l, const T &x_r) {\n    if (r < a ||\
    \ b < l) return t;\n    if (a <= l && r <= b) {\n      Line y{x};\n      return\
    \ insert_line(t, y, l, r, x_l, x_r);\n    }\n    if (t) {\n      T t_l = t->x.get(l),\
    \ t_r = t->x.get(r);\n      if (t_l <= x_l && t_r <= x_r) return t;\n    } else\
    \ {\n      t = new Node(Line(0, INF));\n    }\n    T m = (l + r) / 2;\n    if\
    \ (m == r) --m;\n    T x_m = x.get(m);\n    t->ch[0] = insert_segment(t->ch[0],\
    \ x, a, b, l, m, x_l, x_m);\n    t->ch[1] = insert_segment(t->ch[1], x, a, b,\
    \ m + 1, r, x_m + x.a, x_r);\n    return t;\n  }\n  T query(const Node *t, const\
    \ T &l, const T &r, const T &x) const {\n    if (!t) return INF;\n    if (l ==\
    \ r) return t->x.get(x);\n    T m = (l + r) / 2;\n    if (m == r) --m;\n    if\
    \ (x <= m)\n      return min(t->x.get(x), query(t->ch[0], l, m, x));\n    else\n\
    \      return min(t->x.get(x), query(t->ch[1], m + 1, r, x));\n  }\n\n public:\n\
    \  LiChaoTree() : root{nullptr} {}\n  T get_inf() { return INF; }\n  void clear()\
    \ {\n    node_count = 0;\n    root = nullptr;\n  }\n  void insert_line(T a, T\
    \ b) {\n    Line x(a, b);\n    root = insert_line(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n  }\n  // [l,r)\n  void insert_segment(T l, T r, T a, T b)\
    \ {\n    Line x(a, b);\n    root = insert_segment(root, x, l, r - 1, x_low, x_high,\
    \ x.get(x_low),\n                          x.get(x_high));\n  }\n  T query(T x)\
    \ const { return query(root, x_low, x_high, x); }\n};\ntemplate <typename T, T\
    \ x_low, T x_high, size_t LIM>\nint LiChaoTree<T, x_low, x_high, LIM>::node_count\
    \ = 0;\n#line 8 \"test/yosupo/line_add_get_min.test.cpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  LiChaoTree<long long> cht;\n  while (N--) {\n    long long a,\
    \ b;\n    cin >> a >> b;\n    cht.insert_line(a, b);\n  }\n  while (Q--) {\n \
    \   bool op;\n    cin >> op;\n    if (op) {\n      long long p;\n      cin >>\
    \ p;\n      cout << cht.query(p) << endl;\n    } else {\n      long long a, b;\n\
    \      cin >> a >> b;\n      cht.insert_line(a, b);\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/DataStructure/LiChaoTree.hpp\"\n#undef call_from_test\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n\
    \  LiChaoTree<long long> cht;\n  while (N--) {\n    long long a, b;\n    cin >>\
    \ a >> b;\n    cht.insert_line(a, b);\n  }\n  while (Q--) {\n    bool op;\n  \
    \  cin >> op;\n    if (op) {\n      long long p;\n      cin >> p;\n      cout\
    \ << cht.query(p) << endl;\n    } else {\n      long long a, b;\n      cin >>\
    \ a >> b;\n      cht.insert_line(a, b);\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-08-11 17:25:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min.test.cpp
- /verify/test/yosupo/line_add_get_min.test.cpp.html
title: test/yosupo/line_add_get_min.test.cpp
---
