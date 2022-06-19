---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree_Dual.hpp\"\n\
    /**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct SegmentTree_Dual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n      : n(n_),\n\
    \        height(ceil(log2(n))),\n        val(n, v1),\n        laz(n * 2),\n  \
    \      laz_flg(n * 2, false) {}\n  SegmentTree_Dual(const std::vector<T> &v)\n\
    \      : n(v.size()),\n        height(ceil(log2(n))),\n        val(v),\n     \
    \   laz(n * 2),\n        laz_flg(n * 2, false) {}\n  void apply(int a, int b,\
    \ E x) {\n    a += n, b += n;\n    for (int i = height; i >= 1; i--)\n      if\
    \ (((a >> i) << i) != a) eval(a >> i);\n    for (int i = height; i >= 1; i--)\n\
    \      if (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l = a, r =\
    \ b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n      if\
    \ (r & 1) propagate(--r, x);\n    }\n  }\n  void set(int k, T x) {\n    for (int\
    \ i = height; i; i--) eval((k + n) >> i);\n    val[k] = x, laz_flg[k + n] = false;\n\
    \  }\n  T operator[](const int k) {\n    for (int i = height; i; i--) eval(k >>\
    \ i);\n    if (laz_flg[k + n])\n      val[k] = M::mapping(val[k], laz[k + n]),\
    \ laz_flg[k + n] = false;\n    return val[k];\n  }\n\n private:\n  const int n,\
    \ height;\n  std::vector<T> val;\n  std::vector<E> laz;\n  std::vector<char> laz_flg;\n\
    \  inline void eval(int k) {\n    if (!laz_flg[k]) return;\n    propagate(k <<\
    \ 1 | 0, laz[k]), propagate(k << 1 | 1, laz[k]);\n    laz_flg[k] = false;\n  }\n\
    \  inline void propagate(int k, const E &x) {\n    laz[k] = laz_flg[k] ? M::composition(laz[k],\
    \ x) : x, laz_flg[k] = true;\n  }\n};\n#line 5 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static E ei() { return INT_MAX; }\n  static T mapping(const T& l, const E&\
    \ r) { return r == ei() ? l : r; }\n  static E composition(const E& l, const E&\
    \ r) { return r == ei() ? l : r; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.apply(s, t + 1, x);\n    }\n  }\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static E ei() { return INT_MAX; }\n  static T mapping(const T& l, const E&\
    \ r) { return r == ei() ? l : r; }\n  static E composition(const E& l, const E&\
    \ r) { return r == ei() ? l : r; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.apply(s, t + 1, x);\n    }\n  }\n \
    \ return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  requiredBy: []
  timestamp: '2022-06-19 22:48:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp.html
title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
---
