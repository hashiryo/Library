---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.SegTree.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree.hpp\"\n/**\n * @title\
    \ Segment-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n * 2\u51AA\
    \u306B\u3057\u3066\u3044\u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04)\n */\n\n\
    // 2\u51AA\u306B\u3059\u308B\u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143array(10x10)\u3092\
    \u306E\u305B\u308B\u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree {\n  using T\
    \ = typename M::T;\n\n private:\n  const int n;\n  std::vector<T> dat;\n\n public:\n\
    \  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n << 1, M::ti()) {}\n\
    \  SegmentTree(int n_, T v) : SegmentTree(std::vector<T>(n_, v)) {}\n  SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set_val(int\
    \ k, T x) {\n    for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::f(dat[(k <<\
    \ 1) | 0], dat[(k << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k + n]\
    \ = x; }\n  void rebuild() {\n    for (int i = n - 1; i >= 1; i--)\n      dat[i]\
    \ = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(),\
    \ dat.end(), M::ti()); }\n  //[l,r)\n  inline T query(int l, int r) {\n    T vl\
    \ = M::ti(), vr = M::ti();\n    for (int a = l + n, b = r + n; a < b; a >>= 1,\
    \ b >>= 1) {\n      if (a & 1) vl = M::f(vl, dat[a++]);\n      if (b & 1) vr =\
    \ M::f(dat[--b], vr);\n    }\n    return M::f(vl, vr);\n  }\n  T operator[](const\
    \ int &k) const { return dat[k + n]; }\n\n  // max{ i : check(query(l,i+1)) =\
    \ true}\n  template <class C>\n  int find_right(const C &check, int l = 0) {\n\
    \    assert(check(M::ti()));\n    if (l == n) return n;\n    std::vector<int>\
    \ idl, idr;\n    for (int a = l + n, b = 2 * n; a < b; a >>= 1, b >>= 1) {\n \
    \     if (a & 1) idl.push_back(a++);\n      if (b & 1) idr.push_back(--b);\n \
    \   }\n    for (auto itr = idr.rbegin(); itr != idr.rend(); itr++) idl.push_back(*itr);\n\
    \    T val = M::ti();\n    for (int i : idl) {\n      if (!check(M::f(val, dat[i])))\
    \ {\n        while (i < n) {\n          i = i << 1 | 0;\n          if (check(M::f(val,\
    \ dat[i]))) val = M::f(val, dat[i++]);\n        }\n        return i - n;\n   \
    \   }\n      val = M::f(val, dat[i]);\n    }\n    return n;\n  }\n  //   min {\
    \ i : check(query(i,r)) = true }\n  template <class C>\n  int find_left(const\
    \ C &check, int r = -1) {\n    if (r < 0) r = n;\n    assert(check(M::ti()));\n\
    \    if (r == 0) return 0;\n    std::vector<int> idl, idr;\n    for (int a = n,\
    \ b = r + n; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) idl.push_back(a++);\n\
    \      if (b & 1) idr.push_back(--b);\n    }\n    for (auto itr = idl.rbegin();\
    \ itr != idl.rend(); itr++) idr.push_back(*itr);\n    T val = M::ti();\n    for\
    \ (int i : idr) {\n      if (!check(M::f(dat[i], val))) {\n        while (i <\
    \ n) {\n          i = i << 1 | 1;\n          if (check(M::f(dat[i], val))) val\
    \ = M::f(dat[i--], val);\n        }\n        return i + 1 - n;\n      }\n    \
    \  val = M::f(dat[i], val);\n    }\n    return 0;\n  }\n};\n#line 5 \"test/aoj/DSL_2_A.SegTree.test.cpp\"\
    \nusing namespace std;\n\nstruct RminQ {\n  using T = int;\n  static T ti() {\
    \ return INT_MAX; }\n  static T f(const T &l, const T &r) { return min(l, r);\
    \ }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int n,\
    \ q;\n  cin >> n >> q;\n  SegmentTree<RminQ> seg(n);\n  while (q--) {\n    int\
    \ com, x, y;\n    cin >> com >> x >> y;\n    if (com) {\n      cout << seg.query(x,\
    \ y + 1) << endl;\n    } else {\n      seg.set_val(x, y);\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree.hpp\"\nusing\
    \ namespace std;\n\nstruct RminQ {\n  using T = int;\n  static T ti() { return\
    \ INT_MAX; }\n  static T f(const T &l, const T &r) { return min(l, r); }\n};\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int n, q;\n  cin\
    \ >> n >> q;\n  SegmentTree<RminQ> seg(n);\n  while (q--) {\n    int com, x, y;\n\
    \    cin >> com >> x >> y;\n    if (com) {\n      cout << seg.query(x, y + 1)\
    \ << endl;\n    } else {\n      seg.set_val(x, y);\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.SegTree.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.SegTree.test.cpp
- /verify/test/aoj/DSL_2_A.SegTree.test.cpp.html
title: test/aoj/DSL_2_A.SegTree.test.cpp
---
