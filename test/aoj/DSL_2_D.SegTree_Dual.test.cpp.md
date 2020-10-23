---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \n private:\n  const int height, n;\n  std::vector<T> val;\n  std::vector<E> laz;\n\
    \n private:\n  inline void eval(int k) {\n    if (laz[k] == M::ei()) return;\n\
    \    laz[(k << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) |\
    \ 1] = M::h(laz[(k << 1) | 1], laz[k]);\n    laz[k] = M::ei();\n  }\n  inline\
    \ void thrust(int k) {\n    for (int i = height; i; i--) eval(k >> i);\n  }\n\n\
    \ public:\n  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n \
    \     : SegmentTree_Dual(std::vector<T>(n_, v1)) {}\n  SegmentTree_Dual(const\
    \ std::vector<T>& v)\n      : height(ceil(log2(v.size()))),\n        n(1 << height),\n\
    \        val(v),\n        laz(n * 2, M::ei()) {}\n  void update(int a, int b,\
    \ E x) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int l = a, r\
    \ = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = M::h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r], x);\n    }\n  }\n  void\
    \ set_val(int a, T x) {\n    thrust(a += n);\n    val[a] = x;\n    laz[a] = M::ei();\n\
    \  }\n  T operator[](const int k) {\n    thrust(k + n);\n    if (laz[k + n] !=\
    \ M::ei()) {\n      val[k] = M::g(val[k], laz[k + n]);\n      laz[k + n] = M::ei();\n\
    \    }\n    return val[k];\n  }\n};\n#line 5 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static E ei() { return INT_MAX; }\n  static T g(const T& l, const E& r) { return\
    \ r == ei() ? l : r; }\n  static E h(const E& l, const E& r) { return r == ei()\
    \ ? l : r; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.update(s, t + 1, x);\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static E ei() { return INT_MAX; }\n  static T g(const T& l, const E& r) { return\
    \ r == ei() ? l : r; }\n  static E h(const E& l, const E& r) { return r == ei()\
    \ ? l : r; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.update(s, t + 1, x);\n    }\n  }\n\
    \  return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp.html
title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
---
