---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Beats.hpp
    title: Segment-Tree Beats!
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.SegTree_Lazy.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\n#include\
    \ <iostream>\n#line 2 \"src/DataStructure/SegmentTree_Beats.hpp\"\n#include <vector>\n\
    template <typename M> struct SegmentTree_Beats {\n using T= typename M::T;\n using\
    \ E= typename M::E;\n SegmentTree_Beats() {}\n SegmentTree_Beats(int n_): n(n_),\
    \ height(n == 1 ? 0 : std::__lg(n - 1) + 1), dat(n * 2, M::ti()), laz(n, {E(),\
    \ false}) {}\n SegmentTree_Beats(int n_, T v1): SegmentTree_Beats(n_) {\n  for\
    \ (int i= n; i--;) dat[i + n]= v1;\n  for (int i= n; --i;) update(i);\n }\n SegmentTree_Beats(const\
    \ std::vector<T> &v): SegmentTree_Beats(v.size()) {\n  for (int i= n; i--;) dat[i\
    \ + n]= v[i];\n  for (int i= n; --i;) update(i);\n }\n void unsafe_set(int k,\
    \ T x) { dat[k + n]= x; }\n void rebuild() {\n  for (int i= n; i--;) laz[i].flg=\
    \ false;\n  for (int i= n; --i;) update(i);\n }\n void apply(int a, int b, E x)\
    \ {\n  a+= n, b+= n;\n  for (int i= height; i; i--)\n   if (((a >> i) << i) !=\
    \ a) eval(a >> i);\n  for (int i= height; i; i--)\n   if (((b >> i) << i) != b)\
    \ eval((b - 1) >> i);\n  for (int l= a, r= b; l < r; l>>= 1, r>>= 1) {\n   if\
    \ (l & 1) propagate(l++, x);\n   if (r & 1) propagate(--r, x);\n  }\n  for (int\
    \ i= 1; a >> i; i++)\n   if (((a >> i) << i) != a) update(a >> i);\n  for (int\
    \ i= 1; b >> i; i++)\n   if (((b >> i) << i) != b) update((b - 1) >> i);\n }\n\
    \ void set(int k, T x) {\n  int i= height;\n  for (k+= n; i; i--) eval(k >> i);\n\
    \  for (dat[k]= x, i= 1; k >> i; i++) update(k >> i);\n }\n T fold(int a, int\
    \ b) {  //[a,b)\n  a+= n, b+= n;\n  for (int i= height; i; i--)\n   if (((a >>\
    \ i) << i) != a) eval(a >> i);\n  for (int i= height; i; i--)\n   if (((b >> i)\
    \ << i) != b) eval(b >> i);\n  T vl= M::ti(), vr= M::ti();\n  for (int l= a, r=\
    \ b; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) vl= M::op(vl, dat[l++]);\n   if (r\
    \ & 1) vr= M::op(dat[--r], vr);\n  }\n  return M::op(vl, vr);\n }\n T operator[](const\
    \ int k) { return fold(k, k + 1); }\nprivate:\n const int n, height;\n struct\
    \ Lazy {\n  E val;\n  bool flg;\n };\n std::vector<T> dat;\n std::vector<Lazy>\
    \ laz;\n inline void eval(int k) {\n  if (!laz[k].flg) return;\n  propagate(k\
    \ << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n  laz[k].flg= false;\n\
    \ }\n inline void propagate(int k, const E &x) {\n  if (bool success= M::mapping(dat[k],\
    \ x); k < n) {\n   laz[k].flg ? (M::composition(laz[k].val, x), x) : laz[k].val=\
    \ x;\n   if (laz[k].flg= true; !success) eval(k), update(k);\n  }\n }\n inline\
    \ void update(int k) { dat[k]= M::op(dat[k << 1 | 0], dat[k << 1 | 1]); }\n};\n\
    #line 4 \"test/aoj/DSL_2_F.SegTree_Lazy.test.cpp\"\nusing namespace std;\nstruct\
    \ RupdQ_RminQ {\n using T= int;\n using E= int;\n static T ti() { return 0x7fffffff;\
    \ }\n static T op(T l, T r) { return min(l, r); }\n static bool mapping(T& v,\
    \ E f) { return v= f, true; }\n static void composition(E& pre, E suf) { pre=\
    \ suf; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n,\
    \ q;\n cin >> n >> q;\n SegmentTree_Beats<RupdQ_RminQ> seg(n);\n while (q--) {\n\
    \  int com, s, t;\n  cin >> com >> s >> t;\n  if (com) {\n   cout << seg.fold(s,\
    \ t + 1) << endl;\n  } else {\n   int x;\n   cin >> x;\n   seg.apply(s, t + 1,\
    \ x);\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n#include <iostream>\n#include \"src/DataStructure/SegmentTree_Beats.hpp\"\n\
    using namespace std;\nstruct RupdQ_RminQ {\n using T= int;\n using E= int;\n static\
    \ T ti() { return 0x7fffffff; }\n static T op(T l, T r) { return min(l, r); }\n\
    \ static bool mapping(T& v, E f) { return v= f, true; }\n static void composition(E&\
    \ pre, E suf) { pre= suf; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int n, q;\n cin >> n >> q;\n SegmentTree_Beats<RupdQ_RminQ> seg(n);\n while\
    \ (q--) {\n  int com, s, t;\n  cin >> com >> s >> t;\n  if (com) {\n   cout <<\
    \ seg.fold(s, t + 1) << endl;\n  } else {\n   int x;\n   cin >> x;\n   seg.apply(s,\
    \ t + 1, x);\n  }\n }\n return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree_Beats.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 13:39:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
- /verify/test/aoj/DSL_2_F.SegTree_Lazy.test.cpp.html
title: test/aoj/DSL_2_F.SegTree_Lazy.test.cpp
---
