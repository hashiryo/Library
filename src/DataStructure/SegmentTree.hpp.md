---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3086.test.cpp
    title: test/aoj/3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.SegTree.test.cpp
    title: test/aoj/DSL_2_A.SegTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.SegTree.test.cpp
    title: test/yosupo/point_set_range_composite.SegTree.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.SegTree.test.cpp
    title: test/yukicoder/649.SegTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree.hpp\"\n#include <vector>\n\
    #include <cassert>\ntemplate <typename M> struct SegmentTree {\n using T= typename\
    \ M::T;\n SegmentTree() {}\n SegmentTree(int n_): n(n_), dat(n << 1, M::ti())\
    \ {}\n SegmentTree(int n_, T v): n(n_), dat(n << 1, M::ti()) {\n  for (int i=\
    \ n; i--;) dat[i + n]= v;\n  rebuild();\n }\n SegmentTree(const std::vector<T>\
    \ &v): n(v.size()), dat(n << 1, M::ti()) {\n  for (int i= n; i--;) dat[i + n]=\
    \ v[i];\n  rebuild();\n }\n void set(int k, T x) {\n  for (dat[k+= n]= x; k>>=\
    \ 1;) dat[k]= M::op(dat[(k << 1) | 0], dat[(k << 1) | 1]);\n }\n void unsafe_set(int\
    \ k, T x) { dat[k + n]= x; }\n void rebuild() {\n  for (int i= n; --i;) dat[i]=\
    \ M::op(dat[i << 1 | 0], dat[i << 1 | 1]);\n }\n void clear() { fill(dat.begin(),\
    \ dat.end(), M::ti()); }\n inline T fold(int l, int r) const {  //[l,r)\n  T vl=\
    \ M::ti(), vr= M::ti();\n  for (int a= l + n, b= r + n; a < b; a>>= 1, b>>= 1)\
    \ {\n   if (a & 1) vl= M::op(vl, dat[a++]);\n   if (b & 1) vr= M::op(dat[--b],\
    \ vr);\n  }\n  return M::op(vl, vr);\n }\n T operator[](const int &k) const {\
    \ return dat[k + n]; }\n template <bool last> static inline T calc_op(const T\
    \ &v, const T &d) {\n  if constexpr (last) return M::op(d, v);\n  else return\
    \ M::op(v, d);\n }\n // Case 0. find i s.t check(fold(k,i)) == False, check(fold(k,i+1))\
    \ == True\n // Case 1. find i s.t check(fold(i+1,b)) == False, check(fold(i,b))\
    \ == True\n // return -1 if not found\n template <bool last, class C> int find(const\
    \ C &check, int k) const {\n  assert(!check(M::ti()));\n  std::vector<int> id[2];\n\
    \  int a= n + (k & -(!last)), b= n + n + ((k - n) & -(last));\n  for (; a < b;\
    \ a>>= 1, b>>= 1) {\n   if (a & 1) id[0].push_back(a++);\n   if (b & 1) id[1].push_back(--b);\n\
    \  }\n  id[last].insert(id[last].end(), id[!last].rbegin(), id[!last].rend());\n\
    \  T val= M::ti();\n  for (int i: id[last]) {\n   if (T tmp= calc_op<last>(val,\
    \ dat[i]); check(tmp)) {\n    while (i < n)\n     if (tmp= calc_op<last>(val,\
    \ dat[i= i << 1 | last]); !check(tmp)) val= tmp, i-= last * 2 - 1;\n    return\
    \ i - n + last;\n   } else val= tmp;\n  }\n  return -1;\n }\nprivate:\n const\
    \ int n;\n std::vector<T> dat;\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\ntemplate <typename M>\
    \ struct SegmentTree {\n using T= typename M::T;\n SegmentTree() {}\n SegmentTree(int\
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
    private:\n const int n;\n std::vector<T> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-01-22 23:12:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.HLD.test.cpp
  - test/yosupo/point_set_range_composite.SegTree.test.cpp
  - test/yukicoder/649.SegTree.test.cpp
  - test/aoj/DSL_2_A.SegTree.test.cpp
  - test/aoj/3086.test.cpp
documentation_of: src/DataStructure/SegmentTree.hpp
layout: document
title: Segment-Tree
---
2冪にしていない(メモリ節約)
## 計算量
$\mathcal{O}(\log N)$
## 問題例
[AtCoder Regular Contest 027 D - ぴょんぴょんトレーニング](https://atcoder.jp/contests/arc027/tasks/arc027_4) (2冪にするのやめて二次元array(10x10)をのせることに成功) \
[CODE FESTIVAL 2014 予選B D - 登山家](https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d)(find_left, find_right)
