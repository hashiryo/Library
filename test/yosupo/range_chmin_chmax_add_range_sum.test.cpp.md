---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Beats.hpp
    title: Segment-Tree Beats!
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <iostream>\n#line 2 \"src/DataStructure/SegmentTree_Beats.hpp\"\n#include\
    \ <vector>\ntemplate <typename M> struct SegmentTree_Beats {\n using T= typename\
    \ M::T;\n using E= typename M::E;\n SegmentTree_Beats() {}\n SegmentTree_Beats(int\
    \ n_): n(n_), height(n == 1 ? 0 : std::__lg(n - 1) + 1), dat(n * 2, M::ti()),\
    \ laz(n, {E(), false}) {}\n SegmentTree_Beats(int n_, T v1): SegmentTree_Beats(n_)\
    \ {\n  for (int i= n; i--;) dat[i + n]= v1;\n  for (int i= n; --i;) update(i);\n\
    \ }\n SegmentTree_Beats(const std::vector<T> &v): SegmentTree_Beats(v.size())\
    \ {\n  for (int i= n; i--;) dat[i + n]= v[i];\n  for (int i= n; --i;) update(i);\n\
    \ }\n void unsafe_set(int k, T x) { dat[k + n]= x; }\n void rebuild() {\n  for\
    \ (int i= n + n; i--;) laz[i].flg= false;\n  for (int i= n; --i;) update(i);\n\
    \ }\n void apply(int a, int b, E x) {\n  a+= n, b+= n;\n  for (int i= height;\
    \ i; i--)\n   if (((a >> i) << i) != a) eval(a >> i);\n  for (int i= height; i;\
    \ i--)\n   if (((b >> i) << i) != b) eval((b - 1) >> i);\n  for (int l= a, r=\
    \ b; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) propagate(l++, x);\n   if (r & 1)\
    \ propagate(--r, x);\n  }\n  for (int i= 1; a >> i; i++)\n   if (((a >> i) <<\
    \ i) != a) update(a >> i);\n  for (int i= 1; b >> i; i++)\n   if (((b >> i) <<\
    \ i) != b) update((b - 1) >> i);\n }\n void set(int k, T x) {\n  int i= height;\n\
    \  for (k+= n; i; i--) eval(k >> i);\n  for (dat[k]= x, laz[k].flg= false, i=\
    \ 1; k >> i; i++) update(k >> i);\n }\n T fold(int a, int b) {  //[a,b)\n  a+=\
    \ n, b+= n;\n  for (int i= height; i; i--)\n   if (((a >> i) << i) != a) eval(a\
    \ >> i);\n  for (int i= height; i; i--)\n   if (((b >> i) << i) != b) eval(b >>\
    \ i);\n  T vl= M::ti(), vr= M::ti();\n  for (int l= a, r= b; l < r; l>>= 1, r>>=\
    \ 1) {\n   if (l & 1) vl= M::op(vl, dat[l++]);\n   if (r & 1) vr= M::op(dat[--r],\
    \ vr);\n  }\n  return M::op(vl, vr);\n }\n T operator[](const int k) { return\
    \ fold(k, k + 1); }\nprivate:\n const int n, height;\n struct Lazy {\n  E val;\n\
    \  bool flg;\n };\n std::vector<T> dat;\n std::vector<Lazy> laz;\n inline void\
    \ eval(int k) {\n  if (!laz[k].flg) return;\n  propagate(k << 1 | 0, laz[k].val),\
    \ propagate(k << 1 | 1, laz[k].val);\n  laz[k].flg= false;\n }\n inline void propagate(int\
    \ k, const E &x) {\n  if (bool success= M::mapping(dat[k], x); k < n) {\n   laz[k].flg\
    \ ? (M::composition(laz[k].val, x), x) : laz[k].val= x;\n   if (laz[k].flg= true;\
    \ !success) eval(k), update(k);\n  }\n }\n inline void update(int k) { dat[k]=\
    \ M::op(dat[k << 1 | 0], dat[k << 1 | 1]); }\n};\n#line 4 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nusing namespace std;\nstruct Mono {\n static constexpr long long INF= 1ll <<\
    \ 62;\n struct T {\n  long long sum, h, l, h2, l2;\n  int sz, hc, lc;\n };\n struct\
    \ E {  // clamp(x,lb,ub)+ad\n  long long lb, ub, ad;\n  static E add(long long\
    \ x) { return {-INF, INF, x}; }\n  static E chmin(long long x) { return {-INF,\
    \ x, 0}; }\n  static E chmax(long long x) { return {x, INF, 0}; }\n };\n static\
    \ long long min2(long long a, long long a2, long long b, long long b2) { return\
    \ a == b ? min(a2, b2) : a2 <= b ? a2 : b2 <= a ? b2 : max(a, b); }\n static long\
    \ long max2(long long a, long long a2, long long b, long long b2) { return a ==\
    \ b ? max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : min(a, b); }\n static T ti()\
    \ { return {0, -INF, INF, -INF, INF, 0, 0, 0}; }\n static T op(const T &vl, const\
    \ T &vr) { return {vl.sum + vr.sum, max(vl.h, vr.h), min(vl.l, vr.l), max2(vl.h,\
    \ vl.h2, vr.h, vr.h2), min2(vl.l, vl.l2, vr.l, vr.l2), vl.sz + vr.sz, vl.hc *\
    \ (vl.h >= vr.h) + vr.hc * (vl.h <= vr.h), vl.lc * (vl.l <= vr.l) + vr.lc * (vl.l\
    \ >= vr.l)}; }\n static bool mapping(T &v, const E &f) {\n  if (v.h <= f.lb) {\n\
    \   v.sum= (v.h= v.l= f.lb + f.ad) * (v.hc= v.lc= v.sz);\n   v.h2= -INF, v.l2=\
    \ INF;\n   return true;\n  }\n  if (v.l >= f.ub) {\n   v.sum= (v.h= v.l= f.ub\
    \ + f.ad) * (v.hc= v.lc= v.sz);\n   v.h2= -INF, v.l2= INF;\n   return true;\n\
    \  }\n  if (f.lb <= v.l && v.h <= f.ub) {\n   v.sum+= f.ad * v.sz, v.h+= f.ad,\
    \ v.l+= f.ad;\n   v.h2+= f.ad, v.l2+= f.ad;\n   return true;\n  }\n  if (v.h2\
    \ <= f.lb) {\n   v.l= v.h2= f.lb + f.ad, v.lc= v.sz - v.hc;\n   v.l2= v.h= min(f.ub,\
    \ v.h) + f.ad;\n   v.sum= v.h * v.hc + v.l * v.lc;\n   return true;\n  }\n  if\
    \ (v.l2 >= f.ub) {\n   v.h= v.l2= f.ub + f.ad, v.hc= v.sz - v.lc;\n   v.h2= v.l=\
    \ max(f.lb, v.l) + f.ad;\n   v.sum= v.h * v.hc + v.l * v.lc;\n   return true;\n\
    \  }\n  return false;\n }\n static void composition(E &pre, const E &suf) {\n\
    \  if (auto tmpl= suf.lb - pre.ad; pre.ub <= tmpl) pre.ub= pre.lb= tmpl;\n  else\
    \ if (auto tmpu= suf.ub - pre.ad; tmpu <= pre.lb) pre.ub= pre.lb= tmpu;\n  else\
    \ pre.lb= max(pre.lb, tmpl), pre.ub= min(pre.ub, tmpu);\n  pre.ad+= suf.ad;\n\
    \ }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N,\
    \ Q;\n cin >> N >> Q;\n SegmentTree_Beats<Mono> seg(N);\n for (int i= 0; i < N;\
    \ i++) {\n  long long a;\n  cin >> a;\n  seg.unsafe_set(i, {a, a, a, -Mono::INF,\
    \ Mono::INF, 1, 1, 1});\n }\n seg.rebuild();\n while (Q--) {\n  int op, l, r;\n\
    \  cin >> op >> l >> r;\n  if (op == 3) {\n   cout << seg.fold(l, r).sum << '\\\
    n';\n  } else {\n   long long b;\n   cin >> b;\n   if (op == 0) seg.apply(l, r,\
    \ Mono::E::chmin(b));\n   if (op == 1) seg.apply(l, r, Mono::E::chmax(b));\n \
    \  if (op == 2) seg.apply(l, r, Mono::E::add(b));\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <iostream>\n#include \"src/DataStructure/SegmentTree_Beats.hpp\"\n\
    using namespace std;\nstruct Mono {\n static constexpr long long INF= 1ll << 62;\n\
    \ struct T {\n  long long sum, h, l, h2, l2;\n  int sz, hc, lc;\n };\n struct\
    \ E {  // clamp(x,lb,ub)+ad\n  long long lb, ub, ad;\n  static E add(long long\
    \ x) { return {-INF, INF, x}; }\n  static E chmin(long long x) { return {-INF,\
    \ x, 0}; }\n  static E chmax(long long x) { return {x, INF, 0}; }\n };\n static\
    \ long long min2(long long a, long long a2, long long b, long long b2) { return\
    \ a == b ? min(a2, b2) : a2 <= b ? a2 : b2 <= a ? b2 : max(a, b); }\n static long\
    \ long max2(long long a, long long a2, long long b, long long b2) { return a ==\
    \ b ? max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : min(a, b); }\n static T ti()\
    \ { return {0, -INF, INF, -INF, INF, 0, 0, 0}; }\n static T op(const T &vl, const\
    \ T &vr) { return {vl.sum + vr.sum, max(vl.h, vr.h), min(vl.l, vr.l), max2(vl.h,\
    \ vl.h2, vr.h, vr.h2), min2(vl.l, vl.l2, vr.l, vr.l2), vl.sz + vr.sz, vl.hc *\
    \ (vl.h >= vr.h) + vr.hc * (vl.h <= vr.h), vl.lc * (vl.l <= vr.l) + vr.lc * (vl.l\
    \ >= vr.l)}; }\n static bool mapping(T &v, const E &f) {\n  if (v.h <= f.lb) {\n\
    \   v.sum= (v.h= v.l= f.lb + f.ad) * (v.hc= v.lc= v.sz);\n   v.h2= -INF, v.l2=\
    \ INF;\n   return true;\n  }\n  if (v.l >= f.ub) {\n   v.sum= (v.h= v.l= f.ub\
    \ + f.ad) * (v.hc= v.lc= v.sz);\n   v.h2= -INF, v.l2= INF;\n   return true;\n\
    \  }\n  if (f.lb <= v.l && v.h <= f.ub) {\n   v.sum+= f.ad * v.sz, v.h+= f.ad,\
    \ v.l+= f.ad;\n   v.h2+= f.ad, v.l2+= f.ad;\n   return true;\n  }\n  if (v.h2\
    \ <= f.lb) {\n   v.l= v.h2= f.lb + f.ad, v.lc= v.sz - v.hc;\n   v.l2= v.h= min(f.ub,\
    \ v.h) + f.ad;\n   v.sum= v.h * v.hc + v.l * v.lc;\n   return true;\n  }\n  if\
    \ (v.l2 >= f.ub) {\n   v.h= v.l2= f.ub + f.ad, v.hc= v.sz - v.lc;\n   v.h2= v.l=\
    \ max(f.lb, v.l) + f.ad;\n   v.sum= v.h * v.hc + v.l * v.lc;\n   return true;\n\
    \  }\n  return false;\n }\n static void composition(E &pre, const E &suf) {\n\
    \  if (auto tmpl= suf.lb - pre.ad; pre.ub <= tmpl) pre.ub= pre.lb= tmpl;\n  else\
    \ if (auto tmpu= suf.ub - pre.ad; tmpu <= pre.lb) pre.ub= pre.lb= tmpu;\n  else\
    \ pre.lb= max(pre.lb, tmpl), pre.ub= min(pre.ub, tmpu);\n  pre.ad+= suf.ad;\n\
    \ }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N,\
    \ Q;\n cin >> N >> Q;\n SegmentTree_Beats<Mono> seg(N);\n for (int i= 0; i < N;\
    \ i++) {\n  long long a;\n  cin >> a;\n  seg.unsafe_set(i, {a, a, a, -Mono::INF,\
    \ Mono::INF, 1, 1, 1});\n }\n seg.rebuild();\n while (Q--) {\n  int op, l, r;\n\
    \  cin >> op >> l >> r;\n  if (op == 3) {\n   cout << seg.fold(l, r).sum << '\\\
    n';\n  } else {\n   long long b;\n   cin >> b;\n   if (op == 0) seg.apply(l, r,\
    \ Mono::E::chmin(b));\n   if (op == 1) seg.apply(l, r, Mono::E::chmax(b));\n \
    \  if (op == 2) seg.apply(l, r, Mono::E::add(b));\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Beats.hpp
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 22:42:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
