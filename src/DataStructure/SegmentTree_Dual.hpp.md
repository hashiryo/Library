---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
    title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Segment-Tree(\u53CC\u5BFE)"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree_Dual.hpp\"\n/**\n * @title\
    \ Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *\
    \ @brief O(logN)\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n\ntemplate <typename M>\nstruct SegmentTree_Dual {\n\
    \  using T = typename M::T;\n  using E = typename M::E;\n\n private:\n  const\
    \ int height, n;\n  vector<T> val;\n  vector<E> laz;\n\n private:\n  inline void\
    \ eval(int k) {\n    if (laz[k] == M::ei()) return;\n    laz[(k << 1) | 0] = M::h(laz[(k\
    \ << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = M::h(laz[(k << 1) | 1], laz[k]);\n\
    \    laz[k] = M::ei();\n  }\n  inline void thrust(int k) {\n    for (int i = height;\
    \ i; i--) eval(k >> i);\n  }\n\n public:\n  SegmentTree_Dual() {}\n  SegmentTree_Dual(int\
    \ n_, T v1 = T()) : SegmentTree_Dual(vector<T>(n_, v1)) {}\n  SegmentTree_Dual(const\
    \ vector<T>& v)\n      : height(ceil(log2(v.size()))),\n        n(1 << height),\n\
    \        val(v),\n        laz(n * 2, M::ei()) {}\n  void update(int a, int b,\
    \ E x) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int l = a, r\
    \ = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = M::h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r], x);\n    }\n  }\n  void\
    \ set_val(int a, T x) {\n    thrust(a += n);\n    val[a] = x;\n    laz[a] = M::ei();\n\
    \  }\n  T operator[](const int k) {\n    thrust(k + n);\n    if (laz[k + n] !=\
    \ M::ei()) {\n      val[k] = M::g(val[k], laz[k + n]);\n      laz[k + n] = M::ei();\n\
    \    }\n    return val[k];\n  }\n};\n"
  code: "/**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * @brief O(logN)\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\ntemplate <typename M>\nstruct SegmentTree_Dual\
    \ {\n  using T = typename M::T;\n  using E = typename M::E;\n\n private:\n  const\
    \ int height, n;\n  vector<T> val;\n  vector<E> laz;\n\n private:\n  inline void\
    \ eval(int k) {\n    if (laz[k] == M::ei()) return;\n    laz[(k << 1) | 0] = M::h(laz[(k\
    \ << 1) | 0], laz[k]);\n    laz[(k << 1) | 1] = M::h(laz[(k << 1) | 1], laz[k]);\n\
    \    laz[k] = M::ei();\n  }\n  inline void thrust(int k) {\n    for (int i = height;\
    \ i; i--) eval(k >> i);\n  }\n\n public:\n  SegmentTree_Dual() {}\n  SegmentTree_Dual(int\
    \ n_, T v1 = T()) : SegmentTree_Dual(vector<T>(n_, v1)) {}\n  SegmentTree_Dual(const\
    \ vector<T>& v)\n      : height(ceil(log2(v.size()))),\n        n(1 << height),\n\
    \        val(v),\n        laz(n * 2, M::ei()) {}\n  void update(int a, int b,\
    \ E x) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int l = a, r\
    \ = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = M::h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r], x);\n    }\n  }\n  void\
    \ set_val(int a, T x) {\n    thrust(a += n);\n    val[a] = x;\n    laz[a] = M::ei();\n\
    \  }\n  T operator[](const int k) {\n    thrust(k + n);\n    if (laz[k + n] !=\
    \ M::ei()) {\n      val[k] = M::g(val[k], laz[k + n]);\n      laz[k + n] = M::ei();\n\
    \    }\n    return val[k];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Dual.hpp
  requiredBy: []
  timestamp: '2020-08-11 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_D.SegTree_Dual.test.cpp
documentation_of: src/DataStructure/SegmentTree_Dual.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Dual.hpp
- /library/src/DataStructure/SegmentTree_Dual.hpp.html
title: "Segment-Tree(\u53CC\u5BFE)"
---
