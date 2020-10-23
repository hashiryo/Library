---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
    title: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
    title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Lazy.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree(\u9045\u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename\
    \ M>\nstruct SegmentTree_Lazy {\n  using T = typename M::T;\n  using E = typename\
    \ M::E;\n\n private:\n  const int height, n;\n  std::vector<T> dat;\n  std::vector<E>\
    \ laz;\n\n private:\n  inline T reflect(int k) {\n    return laz[k] == M::ei()\
    \ ? dat[k] : M::g(dat[k], laz[k]);\n  }\n  inline void eval(int k) {\n    if (laz[k]\
    \ == M::ei()) return;\n    laz[(k << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);\n\
    \    laz[(k << 1) | 1] = M::h(laz[(k << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n\
    \    laz[k] = M::ei();\n  }\n  inline void thrust(int k) {\n    for (int i = height;\
    \ i; i--) eval(k >> i);\n  }\n  inline void recalc(int k) {\n    while (k >>=\
    \ 1) dat[k] = M::f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n  }\n\n public:\n\
    \  SegmentTree_Lazy() {}\n  SegmentTree_Lazy(int n_, T v1 = M::ti())\n      :\
    \ SegmentTree_Lazy(std::vector<T>(n_, v1)) {}\n  SegmentTree_Lazy(const std::vector<T>&\
    \ v)\n      : height(ceil(log2(v.size()))),\n        n(1 << height),\n       \
    \ dat(n * 2, M::ti()),\n        laz(n * 2, M::ei()) {\n    for (int i = 0; i <\
    \ (int)v.size(); i++) dat[i + n] = v[i];\n    for (int i = n - 1; i >= 1; i--)\n\
    \      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);\n  }\n  void update(int\
    \ a, int b, E x) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int\
    \ l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = M::h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r], x);\n    }\n    recalc(a);\n\
    \    recalc(b);\n  }\n  void set_val(int a, T x) {\n    thrust(a += n);\n    dat[a]\
    \ = x;\n    laz[a] = M::ei();\n    recalc(a);\n  }\n  //[a,b)\n  T query(int a,\
    \ int b) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = M::ti(),\
    \ vr = M::ti();\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n \
    \     if (l & 1) vl = M::f(vl, reflect(l++));\n      if (r & 1) vr = M::f(reflect(--r),\
    \ vr);\n    }\n    return M::f(vl, vr);\n  }\n  T operator[](const int k) { return\
    \ query(k, k + 1); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree(\u9045\
    \u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree_Lazy {\n\
    \  using T = typename M::T;\n  using E = typename M::E;\n\n private:\n  const\
    \ int height, n;\n  std::vector<T> dat;\n  std::vector<E> laz;\n\n private:\n\
    \  inline T reflect(int k) {\n    return laz[k] == M::ei() ? dat[k] : M::g(dat[k],\
    \ laz[k]);\n  }\n  inline void eval(int k) {\n    if (laz[k] == M::ei()) return;\n\
    \    laz[(k << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);\n    laz[(k << 1) |\
    \ 1] = M::h(laz[(k << 1) | 1], laz[k]);\n    dat[k] = reflect(k);\n    laz[k]\
    \ = M::ei();\n  }\n  inline void thrust(int k) {\n    for (int i = height; i;\
    \ i--) eval(k >> i);\n  }\n  inline void recalc(int k) {\n    while (k >>= 1)\
    \ dat[k] = M::f(reflect((k << 1) | 0), reflect((k << 1) | 1));\n  }\n\n public:\n\
    \  SegmentTree_Lazy() {}\n  SegmentTree_Lazy(int n_, T v1 = M::ti())\n      :\
    \ SegmentTree_Lazy(std::vector<T>(n_, v1)) {}\n  SegmentTree_Lazy(const std::vector<T>&\
    \ v)\n      : height(ceil(log2(v.size()))),\n        n(1 << height),\n       \
    \ dat(n * 2, M::ti()),\n        laz(n * 2, M::ei()) {\n    for (int i = 0; i <\
    \ (int)v.size(); i++) dat[i + n] = v[i];\n    for (int i = n - 1; i >= 1; i--)\n\
    \      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);\n  }\n  void update(int\
    \ a, int b, E x) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    for (int\
    \ l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) laz[l] = M::h(laz[l],\
    \ x), l++;\n      if (r & 1) --r, laz[r] = M::h(laz[r], x);\n    }\n    recalc(a);\n\
    \    recalc(b);\n  }\n  void set_val(int a, T x) {\n    thrust(a += n);\n    dat[a]\
    \ = x;\n    laz[a] = M::ei();\n    recalc(a);\n  }\n  //[a,b)\n  T query(int a,\
    \ int b) {\n    thrust(a += n);\n    thrust(b += n - 1);\n    T vl = M::ti(),\
    \ vr = M::ti();\n    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n \
    \     if (l & 1) vl = M::f(vl, reflect(l++));\n      if (r & 1) vr = M::f(reflect(--r),\
    \ vr);\n    }\n    return M::f(vl, vr);\n  }\n  T operator[](const int k) { return\
    \ query(k, k + 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Lazy.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/235.HLD.test.cpp
  - test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
  - test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
documentation_of: src/DataStructure/SegmentTree_Lazy.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Lazy.hpp
- /library/src/DataStructure/SegmentTree_Lazy.hpp.html
title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
---
