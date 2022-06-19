---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
    title: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
    title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.HLD.test.cpp
    title: test/yukicoder/235.HLD.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Lazy.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree(\u9045\u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename\
    \ M>\nstruct SegmentTree_Lazy {\n  using T = typename M::T;\n  using E = typename\
    \ M::E;\n  SegmentTree_Lazy() {}\n  SegmentTree_Lazy(int n_)\n      : n(n_),\n\
    \        height(ceil(log2(n))),\n        dat(n * 2, M::ti()),\n        laz(n *\
    \ 2),\n        laz_flg(n * 2, false) {}\n  SegmentTree_Lazy(int n_, T v1) : SegmentTree_Lazy(n_)\
    \ {\n    for (int i = n; i--;) dat[i + n] = v1;\n    for (int i = n; --i;) update(i);\n\
    \  }\n  SegmentTree_Lazy(const std::vector<T> &v) : SegmentTree_Lazy(v.size())\
    \ {\n    for (int i = n; i--;) dat[i + n] = v[i];\n    for (int i = n; --i;) update(i);\n\
    \  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void rebuild() {\n\
    \    laz_flg.assign(n * 2, false);\n    for (int i = n; --i;) update(i);\n  }\n\
    \  void apply(int a, int b, E x) {\n    a += n, b += n;\n    for (int i = height;\
    \ i; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n    for (int i = height;\
    \ i; i--)\n      if (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l\
    \ = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n\
    \      if (r & 1) propagate(--r, x);\n    }\n    for (int i = 1; a >> i; i++)\n\
    \      if (((a >> i) << i) != a) update(a >> i);\n    for (int i = 1; b >> i;\
    \ i++)\n      if (((b >> i) << i) != b) update((b - 1) >> i);\n  }\n  void set(int\
    \ k, T x) {\n    int i = height;\n    for (k += n; i; i--) eval(k >> i);\n   \
    \ for (dat[k] = x, laz_flg[k] = false, i = 1; k >> i; i++) update(k >> i);\n \
    \ }\n  T fold(int a, int b) {  //[a,b)\n    a += n, b += n;\n    for (int i =\
    \ height; i; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n    for (int\
    \ i = height; i; i--)\n      if (((b >> i) << i) != b) eval(b >> i);\n    T vl\
    \ = M::ti(), vr = M::ti();\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) vl = M::op(vl, dat[l++]);\n      if (r & 1) vr = M::op(dat[--r],\
    \ vr);\n    }\n    return M::op(vl, vr);\n  }\n  T operator[](const int k) { return\
    \ fold(k, k + 1); }\n\n private:\n  const int n, height;\n  std::vector<T> dat;\n\
    \  std::vector<E> laz;\n  std::vector<char> laz_flg;\n  inline void eval(int k)\
    \ {\n    if (!laz_flg[k]) return;\n    propagate(k << 1 | 0, laz[k]), propagate(k\
    \ << 1 | 1, laz[k]);\n    laz_flg[k] = false;\n  }\n  inline void propagate(int\
    \ k, const E &x) {\n    laz[k] = laz_flg[k] ? M::composition(laz[k], x) : x, laz_flg[k]\
    \ = true;\n    dat[k] = M::mapping(dat[k], x);\n  }\n  inline void update(int\
    \ k) {\n    dat[k] = M::op(dat[k << 1 | 0], dat[k << 1 | 1]);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree(\u9045\
    \u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree_Lazy {\n\
    \  using T = typename M::T;\n  using E = typename M::E;\n  SegmentTree_Lazy()\
    \ {}\n  SegmentTree_Lazy(int n_)\n      : n(n_),\n        height(ceil(log2(n))),\n\
    \        dat(n * 2, M::ti()),\n        laz(n * 2),\n        laz_flg(n * 2, false)\
    \ {}\n  SegmentTree_Lazy(int n_, T v1) : SegmentTree_Lazy(n_) {\n    for (int\
    \ i = n; i--;) dat[i + n] = v1;\n    for (int i = n; --i;) update(i);\n  }\n \
    \ SegmentTree_Lazy(const std::vector<T> &v) : SegmentTree_Lazy(v.size()) {\n \
    \   for (int i = n; i--;) dat[i + n] = v[i];\n    for (int i = n; --i;) update(i);\n\
    \  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void rebuild() {\n\
    \    laz_flg.assign(n * 2, false);\n    for (int i = n; --i;) update(i);\n  }\n\
    \  void apply(int a, int b, E x) {\n    a += n, b += n;\n    for (int i = height;\
    \ i; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n    for (int i = height;\
    \ i; i--)\n      if (((b >> i) << i) != b) eval((b - 1) >> i);\n    for (int l\
    \ = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) propagate(l++, x);\n\
    \      if (r & 1) propagate(--r, x);\n    }\n    for (int i = 1; a >> i; i++)\n\
    \      if (((a >> i) << i) != a) update(a >> i);\n    for (int i = 1; b >> i;\
    \ i++)\n      if (((b >> i) << i) != b) update((b - 1) >> i);\n  }\n  void set(int\
    \ k, T x) {\n    int i = height;\n    for (k += n; i; i--) eval(k >> i);\n   \
    \ for (dat[k] = x, laz_flg[k] = false, i = 1; k >> i; i++) update(k >> i);\n \
    \ }\n  T fold(int a, int b) {  //[a,b)\n    a += n, b += n;\n    for (int i =\
    \ height; i; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n    for (int\
    \ i = height; i; i--)\n      if (((b >> i) << i) != b) eval(b >> i);\n    T vl\
    \ = M::ti(), vr = M::ti();\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) vl = M::op(vl, dat[l++]);\n      if (r & 1) vr = M::op(dat[--r],\
    \ vr);\n    }\n    return M::op(vl, vr);\n  }\n  T operator[](const int k) { return\
    \ fold(k, k + 1); }\n\n private:\n  const int n, height;\n  std::vector<T> dat;\n\
    \  std::vector<E> laz;\n  std::vector<char> laz_flg;\n  inline void eval(int k)\
    \ {\n    if (!laz_flg[k]) return;\n    propagate(k << 1 | 0, laz[k]), propagate(k\
    \ << 1 | 1, laz[k]);\n    laz_flg[k] = false;\n  }\n  inline void propagate(int\
    \ k, const E &x) {\n    laz[k] = laz_flg[k] ? M::composition(laz[k], x) : x, laz_flg[k]\
    \ = true;\n    dat[k] = M::mapping(dat[k], x);\n  }\n  inline void update(int\
    \ k) {\n    dat[k] = M::op(dat[k << 1 | 0], dat[k << 1 | 1]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Lazy.hpp
  requiredBy: []
  timestamp: '2022-06-19 23:17:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  - test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
  - test/yukicoder/235.HLD.test.cpp
documentation_of: src/DataStructure/SegmentTree_Lazy.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Lazy.hpp
- /library/src/DataStructure/SegmentTree_Lazy.hpp.html
title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
---
