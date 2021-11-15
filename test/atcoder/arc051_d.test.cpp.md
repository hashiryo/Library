---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/LiChaoTree.hpp
    title: Li-Chao-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc051/tasks/arc051_d
    links:
    - https://atcoder.jp/contests/arc051/tasks/arc051_d
  bundledCode: "#line 1 \"test/atcoder/arc051_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc051/tasks/arc051_d\"\
    \n\n// double \u306E verify\n\n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/LiChaoTree.hpp\"\
    \n/**\n * @title Li-Chao-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ \u76F4\u7DDA\u633F\u5165:O(log n)\n * \u7DDA\u5206\u633F\u5165:O(log^2 n)\n\
    \ * \u6700\u5C0F\u5024\u53D6\u5F97:O(log n)\n * \u6700\u5927\u5024\u53D6\u5F97\
    \u3057\u305F\u3044\u306A\u3089(-a,-b)\u3092\u633F\u5165\u3057\u3066-\u6700\u5C0F\
    \u5024\u3092\u53D6\u5F97\n * \u6D6E\u52D5\u5C0F\u6570\u70B9\u3082\u884C\u3051\u308B\
    \u306F\u305A\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T, std::size_t LIM\
    \ = (1 << 23)>\nstruct LiChaoTree {\n  struct Line {\n    T a, b;\n    Line(T\
    \ a, T b) : a(a), b(b) {}\n    inline T get(T x) const { return a * x + b; }\n\
    \  };\n  struct Node {\n    Line f;\n    Node *ch[2];\n    Node() : f(0, INF)\
    \ {}\n    Node(const Line &f_) : f(f_), ch{nullptr, nullptr} {}\n    void *operator\
    \ new(size_t) {\n      static std::vector<Node> pool(LIM);\n      return &pool[node_count++];\n\
    \    }\n  };\n\n private:\n  static constexpr T lower = -2e9, upper = 2e9;\n \
    \ static constexpr T INF = std::numeric_limits<T>::max() / 2;\n  static inline\
    \ int node_count;\n  Node *root;\n\n private:\n  int sgn(const T &x) const {\n\
    \    static constexpr T EPS = 1e-10;\n    return x < -EPS ? -1 : x > +EPS ? 1\
    \ : 0;\n  }\n  Node *addl(Node *t, Line f, const T &x_l, const T &x_r) {\n   \
    \ if (!t) return new Node(f);\n    int dif_l = sgn(t->f.get(x_l) - f.get(x_l)),\n\
    \        dif_r = sgn(t->f.get(x_r) - f.get(x_r));\n    if (dif_l <= 0 && dif_r\
    \ <= 0) return t;\n    if (dif_l >= 0 && dif_r >= 0) return t->f = f, t;\n   \
    \ T x_m = (x_l + x_r) / 2;\n    int dif_m = sgn(t->f.get(x_m) - f.get(x_m));\n\
    \    if (dif_m > 0) std::swap(t->f, f), dif_l = -dif_l;\n    if (sgn(x_l - x_m)\
    \ == 0) return t;\n    if (dif_l > 0) t->ch[0] = addl(t->ch[0], f, x_l, x_m);\n\
    \    if (dif_l < 0) t->ch[1] = addl(t->ch[1], f, x_m, x_r);\n    return t;\n \
    \ }\n  Node *adds(Node *t, const Line &f, const T &l, const T &r, const T &x_l,\n\
    \             const T &x_r) {\n    if (sgn(x_r - l) <= 0 || 0 <= sgn(x_l - r))\
    \ return t;\n    if (0 <= sgn(x_l - l) && sgn(x_r - r) <= 0) return addl(t, f,\
    \ x_l, x_r);\n    if (t && sgn(t->f.get(x_l) - f.get(x_l)) <= 0 &&\n        sgn(t->f.get(x_r)\
    \ - f.get(x_r)) <= 0)\n      return t;\n    if (!t) t = new Node(Line(0, INF));\n\
    \    T x_m = (x_l + x_r) / 2;\n    t->ch[0] = adds(t->ch[0], f, l, r, x_l, x_m);\n\
    \    t->ch[1] = adds(t->ch[1], f, l, r, x_m, x_r);\n    return t;\n  }\n  T query(const\
    \ Node *t, const T &x_l, const T &x_r, const T &x) const {\n    if (!t) return\
    \ INF;\n    if (sgn(x_l - x_r) == 0) return t->f.get(x);\n    T x_m = (x_l + x_r)\
    \ / 2;\n    return std::min(t->f.get(x), sgn(x - x_m) < 0\n                  \
    \                   ? query(t->ch[0], x_l, x_m, x)\n                         \
    \            : query(t->ch[1], x_m, x_r, x));\n  }\n\n public:\n  LiChaoTree()\
    \ : root{nullptr} {}\n  T get_inf() { return INF; }\n  void clear() { node_count\
    \ = 0, root = nullptr; }\n  // ax+b\n  void insert_line(T a, T b) { root = addl(root,\
    \ Line(a, b), lower, upper); }\n  // ax+b for x in [l,r)\n  void insert_segment(T\
    \ l, T r, T a, T b) {\n    root = adds(root, Line(a, b), l, r, lower, upper);\n\
    \  }\n  T query(T x) const { return query(root, lower, upper, x); }\n};\n#line\
    \ 7 \"test/atcoder/arc051_d.test.cpp\"\n\nusing namespace std;\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int W, H;\n  cin >> W >> H;\n\
    \  long long a[W], b[H];\n  for (int i = 0; i < W; i++) cin >> a[i];\n  for (int\
    \ i = 0; i < H; i++) cin >> b[i];\n  long long adp[W][W + 1], bdp[H][H + 1];\n\
    \  for (int i = 0; i < W; i++) {\n    long long sum = 0;\n    for (int j = i,\
    \ cnt = 1; j >= 0; j--, cnt++) {\n      sum += a[j];\n      if (cnt == i + 1)\n\
    \        adp[i][cnt] = sum;\n      else\n        adp[i][cnt] = max(adp[i - 1][cnt],\
    \ sum);\n    }\n  }\n  for (int i = 0; i < H; i++) {\n    long long sum = 0;\n\
    \    for (int j = i, cnt = 1; j >= 0; j--, cnt++) {\n      sum += b[j];\n    \
    \  if (cnt == i + 1)\n        bdp[i][cnt] = sum;\n      else\n        bdp[i][cnt]\
    \ = max(bdp[i - 1][cnt], sum);\n    }\n  }\n  vector<LiChaoTree<double, 1 << 21>>\
    \ cht(W);\n  for (int i = 0; i < W; i++)\n    for (int j = 1; j <= i + 1; j++)\
    \ cht[i].insert_line(-j, -adp[i][j]);\n  int Q;\n  cin >> Q;\n  while (Q--) {\n\
    \    int A, B;\n    cin >> A >> B;\n    A--, B--;\n    long long ans = LLONG_MIN;\n\
    \    for (int i = 1; i <= B + 1; i++)\n      ans = max<double>(ans, round(1. *\
    \ i * -cht[A].query(1. * bdp[B][i] / i)));\n    cout << ans << '\\n';\n  }\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc051/tasks/arc051_d\"\n\n\
    // double \u306E verify\n\n#include <bits/stdc++.h>\n#include \"src/DataStructure/LiChaoTree.hpp\"\
    \n\nusing namespace std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int W, H;\n  cin >> W >> H;\n  long long a[W], b[H];\n  for (int i = 0; i <\
    \ W; i++) cin >> a[i];\n  for (int i = 0; i < H; i++) cin >> b[i];\n  long long\
    \ adp[W][W + 1], bdp[H][H + 1];\n  for (int i = 0; i < W; i++) {\n    long long\
    \ sum = 0;\n    for (int j = i, cnt = 1; j >= 0; j--, cnt++) {\n      sum += a[j];\n\
    \      if (cnt == i + 1)\n        adp[i][cnt] = sum;\n      else\n        adp[i][cnt]\
    \ = max(adp[i - 1][cnt], sum);\n    }\n  }\n  for (int i = 0; i < H; i++) {\n\
    \    long long sum = 0;\n    for (int j = i, cnt = 1; j >= 0; j--, cnt++) {\n\
    \      sum += b[j];\n      if (cnt == i + 1)\n        bdp[i][cnt] = sum;\n   \
    \   else\n        bdp[i][cnt] = max(bdp[i - 1][cnt], sum);\n    }\n  }\n  vector<LiChaoTree<double,\
    \ 1 << 21>> cht(W);\n  for (int i = 0; i < W; i++)\n    for (int j = 1; j <= i\
    \ + 1; j++) cht[i].insert_line(-j, -adp[i][j]);\n  int Q;\n  cin >> Q;\n  while\
    \ (Q--) {\n    int A, B;\n    cin >> A >> B;\n    A--, B--;\n    long long ans\
    \ = LLONG_MIN;\n    for (int i = 1; i <= B + 1; i++)\n      ans = max<double>(ans,\
    \ round(1. * i * -cht[A].query(1. * bdp[B][i] / i)));\n    cout << ans << '\\\
    n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: test/atcoder/arc051_d.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 19:50:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc051_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc051_d.test.cpp
- /verify/test/atcoder/arc051_d.test.cpp.html
title: test/atcoder/arc051_d.test.cpp
---
