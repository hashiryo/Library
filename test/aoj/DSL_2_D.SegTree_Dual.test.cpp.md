---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n#include\
    \ <iostream>\n#line 2 \"src/DataStructure/SegmentTree_Dual.hpp\"\n#include <vector>\n\
    template <typename M> struct SegmentTree_Dual {\n using T= typename M::T;\n using\
    \ E= typename M::E;\n SegmentTree_Dual() {}\n SegmentTree_Dual(int n_, T v1= T()):\
    \ n(n_), height(n == 1 ? 0 : std::__lg(n - 1) + 1), val(n, v1), laz(n * 2, {E(),\
    \ false}) {}\n SegmentTree_Dual(const std::vector<T> &v): n(v.size()), height(n\
    \ == 1 ? 1 : std::__lg(n - 1) + 1), val(v), laz(n * 2, {E(), false}) {}\n void\
    \ apply(int a, int b, E x) {\n  a+= n, b+= n;\n  for (int i= height; i >= 1; i--)\n\
    \   if (((a >> i) << i) != a) eval(a >> i);\n  for (int i= height; i >= 1; i--)\n\
    \   if (((b >> i) << i) != b) eval((b - 1) >> i);\n  for (int l= a, r= b; l <\
    \ r; l>>= 1, r>>= 1) {\n   if (l & 1) propagate(l++, x);\n   if (r & 1) propagate(--r,\
    \ x);\n  }\n }\n void set(int k, T x) {\n  for (int i= height; i; i--) eval((k\
    \ + n) >> i);\n  val[k]= x, laz[k + n].flg= false;\n }\n T &operator[](const int\
    \ k) {\n  for (int i= height; i; i--) eval((k + n) >> i);\n  if (laz[k + n].flg)\
    \ M::mp(val[k], laz[k + n].val), laz[k + n].flg= false;\n  return val[k];\n }\n\
    private:\n const int n, height;\n struct Lazy {\n  E val;\n  bool flg;\n };\n\
    \ std::vector<T> val;\n std::vector<Lazy> laz;\n inline void eval(int k) {\n \
    \ if (!laz[k].flg) return;\n  propagate(k << 1 | 0, laz[k].val), propagate(k <<\
    \ 1 | 1, laz[k].val);\n  laz[k].flg= false;\n }\n inline void propagate(int k,\
    \ const E &x) {\n  laz[k].flg ? (M::cp(laz[k].val, x), x) : laz[k].val= x;\n \
    \ laz[k].flg= true;\n }\n};\n#line 4 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\
    \nusing namespace std;\nstruct RupdQ {\n using T= int;\n using E= int;\n static\
    \ void mp(T& v, E f) { v= f; }\n static void cp(E& pre, E suf) { pre= suf; }\n\
    };\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin\
    \ >> n >> q;\n SegmentTree_Dual<RupdQ> seg(n, 0x7fffffff);\n while (q--) {\n \
    \ bool com;\n  cin >> com;\n  if (com) {\n   int i;\n   cin >> i;\n   cout <<\
    \ seg[i] << endl;\n  } else {\n   int s, t, x;\n   cin >> s >> t >> x;\n   seg.apply(s,\
    \ t + 1, x);\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include <iostream>\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\nusing\
    \ namespace std;\nstruct RupdQ {\n using T= int;\n using E= int;\n static void\
    \ mp(T& v, E f) { v= f; }\n static void cp(E& pre, E suf) { pre= suf; }\n};\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n cin >>\
    \ n >> q;\n SegmentTree_Dual<RupdQ> seg(n, 0x7fffffff);\n while (q--) {\n  bool\
    \ com;\n  cin >> com;\n  if (com) {\n   int i;\n   cin >> i;\n   cout << seg[i]\
    \ << endl;\n  } else {\n   int s, t, x;\n   cin >> s >> t >> x;\n   seg.apply(s,\
    \ t + 1, x);\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  requiredBy: []
  timestamp: '2024-03-31 22:05:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp.html
title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
---
