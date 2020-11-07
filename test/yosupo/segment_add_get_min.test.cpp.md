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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/segment_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/LiChaoTree.hpp\"\n/**\n * @title Li-Chao-Tree\n *\
    \ @category \u30C7\u30FC\u30BF\u69CB\u9020\n * \u76F4\u7DDA\u633F\u5165:O(n log\
    \ n)\n * \u7DDA\u5206\u633F\u5165:O(n log^2 n)\n * \u6700\u5C0F\u5024\u53D6\u5F97\
    :O(n log n)\n * \u6700\u5927\u5024\u53D6\u5F97\u3057\u305F\u3044\u306A\u3089(-a,-b)\u3092\
    \u633F\u5165\u3057\u3066-\u6700\u5C0F\u5024\u3092\u53D6\u5F97\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename T, T lower = -(1 << 30), T upper = (1 << 30),\n\
    \          std::size_t LIM = (1 << 23)>\nstruct LiChaoTree {\n  struct Line {\n\
    \    T a, b;\n    Line(T a, T b) : a(a), b(b) {}\n    inline T get(T x) const\
    \ { return a * x + b; }\n  };\n  struct Node {\n    Line f;\n    Node *ch[2];\n\
    \    Node() : f(0, INF) {}\n    Node(const Line &f_) : f(f_), ch{nullptr, nullptr}\
    \ {}\n    void *operator new(size_t) {\n      static std::vector<Node> pool(LIM);\n\
    \      return &pool[node_count++];\n    }\n  };\n\n private:\n  static constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n  static inline int node_count;\n\
    \  Node *root;\n\n private:\n  Node *addl(Node *t, Line f, const T &x_l, const\
    \ T &x_r) {\n    if (!t) return new Node(f);\n    T y_l = f.get(x_l), y_r = f.get(x_r),\
    \ ty_l = t->f.get(x_l),\n      ty_r = t->f.get(x_r);\n    if (ty_l <= y_l && ty_r\
    \ <= y_r) return t;\n    if (ty_l >= y_l && ty_r >= y_r) return t->f = f, t;\n\
    \    T x_m = x_l == x_r - 1 ? x_l : (x_l + x_r) / 2, ty_m = t->f.get(x_m),\n \
    \     y_m = f.get(x_m);\n    if (ty_m > y_m) std::swap(t->f, f), std::swap(y_l,\
    \ ty_l);\n    if (ty_l >= y_l) t->ch[0] = addl(t->ch[0], f, x_l, x_m);\n    if\
    \ (ty_l < y_l) t->ch[1] = addl(t->ch[1], f, x_m + 1, x_r);\n    return t;\n  }\n\
    \  Node *adds(Node *t, const Line &f, const T &l, const T &r, const T &x_l,\n\
    \             const T &x_r) {\n    if (x_r < l || r < x_l) return t;\n    if (l\
    \ <= x_l && x_r <= r) return addl(t, f, x_l, x_r);\n    T y_l = f.get(x_l), y_r\
    \ = f.get(x_r);\n    if (t && t->f.get(x_l) <= y_l && t->f.get(x_r) <= y_r) return\
    \ t;\n    if (!t) t = new Node(Line(0, INF));\n    T x_m = x_l == x_r - 1 ? x_l\
    \ : (x_l + x_r) / 2;\n    t->ch[0] = adds(t->ch[0], f, l, r, x_l, x_m);\n    t->ch[1]\
    \ = adds(t->ch[1], f, l, r, x_m + 1, x_r);\n    return t;\n  }\n  T query(const\
    \ Node *t, const T &x_l, const T &x_r, const T &x) const {\n    if (!t) return\
    \ INF;\n    if (x_l == x_r) return t->f.get(x);\n    T x_m = x_l == x_r - 1 ?\
    \ x_l : (x_l + x_r) / 2;\n    return std::min(t->f.get(x), x <= x_m ? query(t->ch[0],\
    \ x_l, x_m, x)\n                                          : query(t->ch[1], x_m\
    \ + 1, x_r, x));\n  }\n\n public:\n  LiChaoTree() : root{nullptr} {}\n  T get_inf()\
    \ { return INF; }\n  void clear() { node_count = 0, root = nullptr; }\n  // ax+b\n\
    \  void insert_line(T a, T b) { root = addl(root, Line(a, b), lower, upper); }\n\
    \  // ax+b for x in [l,r)\n  void insert_segment(T l, T r, T a, T b) {\n    root\
    \ = adds(root, Line(a, b), l, r - 1, lower, upper);\n  }\n  T query(T x) const\
    \ { return query(root, lower, upper, x); }\n};\n#line 4 \"test/yosupo/segment_add_get_min.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LiChaoTree<long long> cht;\n  while (N--) {\n\
    \    long long l, r, a, b;\n    cin >> l >> r >> a >> b;\n    cht.insert_segment(l,\
    \ r, a, b);\n  }\n  while (Q--) {\n    bool op;\n    cin >> op;\n    if (op) {\n\
    \      long long p;\n      cin >> p;\n      long long ans = cht.query(p);\n  \
    \    if (ans == cht.get_inf()) {\n        cout << \"INFINITY\" << endl;\n    \
    \  } else {\n        cout << ans << endl;\n      }\n    } else {\n      long long\
    \ l, r, a, b;\n      cin >> l >> r >> a >> b;\n      cht.insert_segment(l, r,\
    \ a, b);\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include <bits/stdc++.h>\n#include \"src/DataStructure/LiChaoTree.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LiChaoTree<long long> cht;\n  while (N--) {\n\
    \    long long l, r, a, b;\n    cin >> l >> r >> a >> b;\n    cht.insert_segment(l,\
    \ r, a, b);\n  }\n  while (Q--) {\n    bool op;\n    cin >> op;\n    if (op) {\n\
    \      long long p;\n      cin >> p;\n      long long ans = cht.query(p);\n  \
    \    if (ans == cht.get_inf()) {\n        cout << \"INFINITY\" << endl;\n    \
    \  } else {\n        cout << ans << endl;\n      }\n    } else {\n      long long\
    \ l, r, a, b;\n      cin >> l >> r >> a >> b;\n      cht.insert_segment(l, r,\
    \ a, b);\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 15:26:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
