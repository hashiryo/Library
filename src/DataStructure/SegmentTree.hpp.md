---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.SegTree.test.cpp
    title: test/aoj/DSL_2_A.SegTree.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_set_range_composite.SegTree.test.cpp
    title: test/yosupo/point_set_range_composite.SegTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.SegTree.test.cpp
    title: test/yukicoder/649.SegTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Segment-Tree
    links:
    - https://atcoder.jp/contests/arc027/tasks/arc027_4
    - https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n\
    \ * 2\u51AA\u306B\u3057\u3066\u3044\u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04\
    )\n */\n\n// 2\u51AA\u306B\u3059\u308B\u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143\
    array(10x10)\u3092\u306E\u305B\u308B\u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree {\n  using T\
    \ = typename M::T;\n  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n <<\
    \ 1, M::ti()) {}\n  SegmentTree(int n_, T v) : n(n_), dat(n << 1, M::ti()) {\n\
    \    for (int i = n; i--;) dat[i + n] = v;\n    rebuild();\n  }\n  SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = n;\
    \ i--;) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set(int k, T x) {\n  \
    \  for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::op(dat[(k << 1) | 0], dat[(k\
    \ << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void\
    \ rebuild() {\n    for (int i = n; --i;) dat[i] = M::op(dat[i << 1 | 0], dat[i\
    \ << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(), dat.end(), M::ti()); }\n\
    \  inline T fold(int l, int r) const {  //[l,r)\n    T vl = M::ti(), vr = M::ti();\n\
    \    for (int a = l + n, b = r + n; a < b; a >>= 1, b >>= 1) {\n      if (a &\
    \ 1) vl = M::op(vl, dat[a++]);\n      if (b & 1) vr = M::op(dat[--b], vr);\n \
    \   }\n    return M::op(vl, vr);\n  }\n  T operator[](const int &k) const { return\
    \ dat[k + n]; }\n  template <bool last>\n  static inline T calc_op(const T &v,\
    \ const T &d) {\n    if constexpr (last)\n      return M::op(d, v);\n    else\n\
    \      return M::op(v, d);\n  }\n  // Case 0. find i s.t check(fold(k,i)) == False,\
    \ check(fold(k,i+1)) == True\n  // Case 1. find i s.t check(fold(i+1,b)) == False,\
    \ check(fold(i,b)) == True\n  // return -1 if not found\n  template <bool last,\
    \ class C>\n  int find(const C &check, int k) const {\n    assert(!check(M::ti()));\n\
    \    std::vector<int> id[2];\n    int a = n + (k & -(!last)), b = n + n + ((k\
    \ - n) & -(last));\n    for (; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) id[0].push_back(a++);\n\
    \      if (b & 1) id[1].push_back(--b);\n    }\n    id[last].insert(id[last].end(),\
    \ id[!last].rbegin(), id[!last].rend());\n    T val = M::ti();\n    for (int i\
    \ : id[last]) {\n      if (T tmp = calc_op<last>(val, dat[i]); check(tmp)) {\n\
    \        while (i < n)\n          if (tmp = calc_op<last>(val, dat[i = i << 1\
    \ | last]); !check(tmp))\n            val = tmp, i -= last * 2 - 1;\n        return\
    \ i - n + last;\n      } else\n        val = tmp;\n    }\n    return -1;\n  }\n\
    \n private:\n  const int n;\n  std::vector<T> dat;\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n * 2\u51AA\u306B\u3057\u3066\u3044\
    \u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04)\n */\n\n// 2\u51AA\u306B\u3059\u308B\
    \u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143array(10x10)\u3092\u306E\u305B\u308B\
    \u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree {\n  using T\
    \ = typename M::T;\n  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n <<\
    \ 1, M::ti()) {}\n  SegmentTree(int n_, T v) : n(n_), dat(n << 1, M::ti()) {\n\
    \    for (int i = n; i--;) dat[i + n] = v;\n    rebuild();\n  }\n  SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = n;\
    \ i--;) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set(int k, T x) {\n  \
    \  for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::op(dat[(k << 1) | 0], dat[(k\
    \ << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void\
    \ rebuild() {\n    for (int i = n; --i;) dat[i] = M::op(dat[i << 1 | 0], dat[i\
    \ << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(), dat.end(), M::ti()); }\n\
    \  inline T fold(int l, int r) const {  //[l,r)\n    T vl = M::ti(), vr = M::ti();\n\
    \    for (int a = l + n, b = r + n; a < b; a >>= 1, b >>= 1) {\n      if (a &\
    \ 1) vl = M::op(vl, dat[a++]);\n      if (b & 1) vr = M::op(dat[--b], vr);\n \
    \   }\n    return M::op(vl, vr);\n  }\n  T operator[](const int &k) const { return\
    \ dat[k + n]; }\n  template <bool last>\n  static inline T calc_op(const T &v,\
    \ const T &d) {\n    if constexpr (last)\n      return M::op(d, v);\n    else\n\
    \      return M::op(v, d);\n  }\n  // Case 0. find i s.t check(fold(k,i)) == False,\
    \ check(fold(k,i+1)) == True\n  // Case 1. find i s.t check(fold(i+1,b)) == False,\
    \ check(fold(i,b)) == True\n  // return -1 if not found\n  template <bool last,\
    \ class C>\n  int find(const C &check, int k) const {\n    assert(!check(M::ti()));\n\
    \    std::vector<int> id[2];\n    int a = n + (k & -(!last)), b = n + n + ((k\
    \ - n) & -(last));\n    for (; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) id[0].push_back(a++);\n\
    \      if (b & 1) id[1].push_back(--b);\n    }\n    id[last].insert(id[last].end(),\
    \ id[!last].rbegin(), id[!last].rend());\n    T val = M::ti();\n    for (int i\
    \ : id[last]) {\n      if (T tmp = calc_op<last>(val, dat[i]); check(tmp)) {\n\
    \        while (i < n)\n          if (tmp = calc_op<last>(val, dat[i = i << 1\
    \ | last]); !check(tmp))\n            val = tmp, i -= last * 2 - 1;\n        return\
    \ i - n + last;\n      } else\n        val = tmp;\n    }\n    return -1;\n  }\n\
    \n private:\n  const int n;\n  std::vector<T> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2022-06-19 23:17:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_A.SegTree.test.cpp
  - test/yukicoder/649.SegTree.test.cpp
  - test/yosupo/point_set_range_composite.SegTree.test.cpp
documentation_of: src/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree.hpp
- /library/src/DataStructure/SegmentTree.hpp.html
title: Segment-Tree
---
