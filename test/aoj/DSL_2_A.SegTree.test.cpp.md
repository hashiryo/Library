---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.SegTree.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\n#include <iostream>\n\
    #line 2 \"src/DataStructure/SegmentTree.hpp\"\n#include <vector>\ntemplate <typename\
    \ M> struct SegmentTree {\n using T= typename M::T;\n SegmentTree() {}\n SegmentTree(int\
    \ n_): n(n_), dat(n << 1, M::ti()) {}\n SegmentTree(int n_, T v): n(n_), dat(n\
    \ << 1, M::ti()) {\n  for (int i= n; i--;) dat[i + n]= v;\n  rebuild();\n }\n\
    \ SegmentTree(const std::vector<T> &v): n(v.size()), dat(n << 1, M::ti()) {\n\
    \  for (int i= n; i--;) dat[i + n]= v[i];\n  rebuild();\n }\n void set(int k,\
    \ T x) {\n  for (dat[k+= n]= x; k>>= 1;) dat[k]= M::op(dat[(k << 1) | 0], dat[(k\
    \ << 1) | 1]);\n }\n void unsafe_set(int k, T x) { dat[k + n]= x; }\n void rebuild()\
    \ {\n  for (int i= n; --i;) dat[i]= M::op(dat[i << 1 | 0], dat[i << 1 | 1]);\n\
    \ }\n void clear() { fill(dat.begin(), dat.end(), M::ti()); }\n inline T fold(int\
    \ l, int r) const {  //[l,r)\n  T vl= M::ti(), vr= M::ti();\n  for (int a= l +\
    \ n, b= r + n; a < b; a>>= 1, b>>= 1) {\n   if (a & 1) vl= M::op(vl, dat[a++]);\n\
    \   if (b & 1) vr= M::op(dat[--b], vr);\n  }\n  return M::op(vl, vr);\n }\n T\
    \ operator[](const int &k) const { return dat[k + n]; }\n template <bool last>\
    \ static inline T calc_op(const T &v, const T &d) {\n  if constexpr (last) return\
    \ M::op(d, v);\n  else return M::op(v, d);\n }\n // Case 0. find i s.t check(fold(k,i))\
    \ == False, check(fold(k,i+1)) == True\n // Case 1. find i s.t check(fold(i+1,b))\
    \ == False, check(fold(i,b)) == True\n // return -1 if not found\n template <bool\
    \ last, class C> int find(const C &check, int k) const {\n  assert(!check(M::ti()));\n\
    \  std::vector<int> id[2];\n  int a= n + (k & -(!last)), b= n + n + ((k - n) &\
    \ -(last));\n  for (; a < b; a>>= 1, b>>= 1) {\n   if (a & 1) id[0].push_back(a++);\n\
    \   if (b & 1) id[1].push_back(--b);\n  }\n  id[last].insert(id[last].end(), id[!last].rbegin(),\
    \ id[!last].rend());\n  T val= M::ti();\n  for (int i: id[last]) {\n   if (T tmp=\
    \ calc_op<last>(val, dat[i]); check(tmp)) {\n    while (i < n)\n     if (tmp=\
    \ calc_op<last>(val, dat[i= i << 1 | last]); !check(tmp)) val= tmp, i-= last *\
    \ 2 - 1;\n    return i - n + last;\n   } else val= tmp;\n  }\n  return -1;\n }\n\
    private:\n const int n;\n std::vector<T> dat;\n};\n#line 4 \"test/aoj/DSL_2_A.SegTree.test.cpp\"\
    \nusing namespace std;\nstruct RminQ {\n using T= int;\n static T ti() { return\
    \ 0x7fffffff; }\n static T op(T l, T r) { return min(l, r); }\n};\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin >> n >> q;\n SegmentTree<RminQ>\
    \ seg(n);\n while (q--) {\n  int com, x, y;\n  cin >> com >> x >> y;\n  if (com)\
    \ {\n   cout << seg.fold(x, y + 1) << endl;\n  } else {\n   seg.set(x, y);\n \
    \ }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <iostream>\n#include \"src/DataStructure/SegmentTree.hpp\"\nusing namespace\
    \ std;\nstruct RminQ {\n using T= int;\n static T ti() { return 0x7fffffff; }\n\
    \ static T op(T l, T r) { return min(l, r); }\n};\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int n, q;\n cin >> n >> q;\n SegmentTree<RminQ> seg(n);\n\
    \ while (q--) {\n  int com, x, y;\n  cin >> com >> x >> y;\n  if (com) {\n   cout\
    \ << seg.fold(x, y + 1) << endl;\n  } else {\n   seg.set(x, y);\n  }\n }\n return\
    \ 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.SegTree.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 23:17:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.SegTree.test.cpp
- /verify/test/aoj/DSL_2_A.SegTree.test.cpp.html
title: test/aoj/DSL_2_A.SegTree.test.cpp
---
