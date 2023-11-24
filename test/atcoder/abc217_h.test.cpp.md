---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/PiecewiseLinearConvexfunction.hpp
    title: "\u533A\u5206\u7DDA\u5F62\u51F8\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc217/tasks/abc217_h
    links:
    - https://atcoder.jp/contests/abc217/tasks/abc217_h
  bundledCode: "#line 1 \"test/atcoder/abc217_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc217/tasks/abc217_h\"\
    \n#include <iostream>\n#line 2 \"src/Optimization/PiecewiseLinearConvexfunction.hpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <array>\n#include <sstream>\n\
    #include <string>\n#line 8 \"src/Optimization/PiecewiseLinearConvexfunction.hpp\"\
    \n#include <cassert>\ntemplate <std::size_t NODE_SIZE= 1 << 22> class PiecewiseLinearConvexfunction\
    \ {\n using i64= long long;\n using i128= __int128_t;\n using node_id= int;\n\
    \ static constexpr i64 INF= 1ll << 41;\n template <class Int> static inline std::string\
    \ str(Int x) {\n  if (x >= INF) return \"inf\";\n  if (x <= -INF) return \"-inf\"\
    ;\n  std::stringstream ss;\n  ss << x;\n  return ss.str();\n }\n struct Node {\n\
    \  node_id ch[2], par;\n  int sz;\n  i64 dx, slope, laz, x;\n  i128 y;\n };\n\
    \ friend std::ostream &operator<<(std::ostream &os, Node *t) {\n  if (!t) return\
    \ os << \"nullptr\";\n  return os << \"{dx:\" << str(t->dx) << \",slope:\" <<\
    \ str(t->slope) << \",x:\" << str(t->x) << \",y:\" << str(t->y) << \",laz:\" <<\
    \ str(t->laz) << \"}\";\n }\n static inline Node ns[NODE_SIZE];\n static inline\
    \ node_id ni= 1;\n static inline node_id new_node() { return ni++; }\n static\
    \ inline node_id new_node(i64 dx, i64 slope) { return ns[ni].ch[0]= ns[ni].ch[1]=\
    \ ns[ni].par= ns[ni].laz= 0, ns[ni].y= i128(ns[ni].x= ns[ni].dx= dx) * (ns[ni].slope=\
    \ slope), ns[ni].sz= 1, ni++; }\n static inline void propagate(node_id i, i64\
    \ a) {\n  if (i) ns[i].slope+= a, ns[i].laz+= a, ns[i].y+= i128(a) * ns[i].x;\n\
    \ }\n static inline void push(node_id i) {\n  if (ns[i].laz) propagate(ns[i].ch[0],\
    \ ns[i].laz), propagate(ns[i].ch[1], ns[i].laz), ns[i].laz= 0;\n }\n static inline\
    \ void update(node_id i) {\n  ns[i].sz= 1, ns[i].x= ns[i].dx, ns[i].y= i128(ns[i].slope)\
    \ * ns[i].dx;\n  if (int j= ns[i].ch[0]; j) ns[i].sz+= ns[j].sz, ns[i].x+= ns[j].x,\
    \ ns[i].y+= ns[j].y;\n  if (int j= ns[i].ch[1]; j) ns[i].sz+= ns[j].sz, ns[i].x+=\
    \ ns[j].x, ns[i].y+= ns[j].y;\n }\n static inline int dir(node_id i) { return\
    \ ns[ns[i].par].ch[1] == i; }\n static inline void rot(node_id i) {\n  node_id\
    \ p= ns[i].par;\n  int d= dir(i);\n  if ((ns[p].ch[d]= ns[i].ch[!d])) ns[ns[p].ch[d]].par=\
    \ p;\n  ns[i].ch[!d]= p;\n  if ((ns[i].par= ns[p].par)) ns[ns[p].par].ch[dir(p)]=\
    \ i;\n  ns[p].par= i, update(p);\n }\n static inline void splay(node_id i) {\n\
    \  for (node_id p= ns[i].par; p; rot(i), p= ns[i].par)\n   if (node_id pp= ns[p].par;\
    \ pp) rot(dir(i) == dir(p) ? p : i);\n  update(i);\n }\n static inline void slope_search(node_id\
    \ &i, i64 k) {\n  for (node_id s;; i= s) {\n   push(i);\n   i64 tmp= ns[i].slope;\n\
    \   if (tmp == k) break;\n   if (s= ns[i].ch[tmp < k]; !s) break;\n  }\n  splay(i);\n\
    \ }\n static inline void x_search(node_id &i, i64 x) {\n  for (bool c;; i= ns[i].ch[c])\
    \ {\n   push(i);\n   i64 l= ns[i].ch[0] ? ns[ns[i].ch[0]].x : 0, r= l + ns[i].dx;\n\
    \   if (l <= x && x <= r) return splay(i);\n   if ((c= (r < x))) x-= r;\n  }\n\
    \ }\n static inline void add(node_id i, i64 &x, i64 &p, PiecewiseLinearConvexfunction\
    \ &f) {\n  if (!i) return;\n  push(i);\n  add(ns[i].ch[0], x, p, f);\n  f.add_ax_bx_c(0,\
    \ ns[i].slope - p, x);\n  x+= ns[i].dx, p= ns[i].slope;\n  add(ns[i].ch[1], x,\
    \ p, f);\n }\n static inline void debugoutput(node_id i, int d) {\n  if (!i) return;\n\
    \  push(i);\n  debugoutput(ns[i].ch[0], d + 1);\n  for (int i= 0; i < d; ++i)\
    \ std::cerr << \"   \";\n  std::cerr << \"\u25A0 \" << (i ? ns + i : nullptr)\
    \ << '\\n';\n  debugoutput(ns[i].ch[1], d + 1);\n }\n node_id root;\n i64 lx,\
    \ lslope;\n i128 ly;\n void chmin_sliding_window(i64 a) {\n  if (!a) return;\n\
    \  assert(a > 0);\n  if (root) {\n   slope_search(root, 0);\n   if (ns[root].slope)\
    \ {\n    node_id i= new_node(a, 0);\n    bool c= ns[root].slope < 0;\n    if ((ns[i].ch[c]=\
    \ ns[root].ch[c])) ns[ns[i].ch[c]].par= i;\n    update(i), ns[root].ch[c]= i,\
    \ ns[i].par= root;\n   } else ns[root].dx+= a;\n   update(root);\n  } else if\
    \ (lslope >= 0) lx+= a;\n  else root= new_node(a, 0);\n }\npublic:\n static inline\
    \ void clear() { ni= 1; }\n void debugoutput() { debugoutput(root, 0); }\n i64\
    \ upper_bound() { return lx + (root ? ns[root].x : 0); }\n // f(x) := 0\n PiecewiseLinearConvexfunction():\
    \ root(0), lx(INF * 2), lslope(0), ly(0) {}\n // f(x) + c\n void add_const(i128\
    \ c) { ly+= c; }\n // f(x) + ax+c\n void add_linear(i64 a, i128 c= 0) { lslope+=\
    \ a, ly+= i128(a) * lx + c, propagate(root, a); }\n // f(x-a)\n void shift(i64\
    \ a) { lx+= a; }\n // f(x) + a * max{x-c, 0}\n void add_relu(i64 a, i64 c) {\n\
    \  if (!a) return;\n  assert(a > 0);\n  if (c < lx) {\n   if (lslope < -INF) return\
    \ add_linear(a, -i128(a) * c);\n   node_id i= new_node(lx - c, lslope);\n   if\
    \ (root) x_search(root, 0), ns[root].ch[0]= i, ns[i].par= root, update(root);\n\
    \   else root= i;\n   ly-= ns[i].y, lx= c, propagate(root, a);\n   return;\n \
    \ }\n  if (upper_bound() <= c) return;\n  c-= lx, x_search(root, c);\n  i64 l=\
    \ ns[root].ch[0] ? ns[ns[root].ch[0]].x : 0, r= l + ns[root].dx;\n  if (l == c)\
    \ {\n   node_id i= ns[root].ch[0];\n   ns[root].ch[0]= 0, propagate(root, a),\
    \ push(root), ns[root].ch[0]= i;\n  } else if (r == c) {\n   propagate(ns[root].ch[1],\
    \ a);\n  } else {\n   node_id i= new_node(r - c, ns[root].slope);\n   if ((ns[i].ch[1]=\
    \ ns[root].ch[1])) ns[ns[i].ch[1]].par= i;\n   update(i), propagate(i, a), ns[root].ch[1]=\
    \ i, ns[i].par= root, ns[root].dx= c - l, update(root);\n  }\n }\n // f(x) + a\
    \ * min{x-c,0} + b * max{x-c,0}\n void add_ax_bx_c(i64 a, i64 b, i64 c) { assert(a\
    \ <= b), add_linear(a, -i128(a) * c), add_relu(b - a, c); }\n // f(x) + a * |x-c|\n\
    \ void add_abs(i64 a, i64 c) { add_ax_bx_c(-a, a, c); }\n // \u221E if x>a else\
    \ f(x)\n void chinfty_right(i64 a= 0) {\n  assert(lx <= a || lslope >= -INF);\n\
    \  if (root) {\n   if (a-= lx; ns[root].x <= a) return;\n   x_search(root, a);\n\
    \   i64 l= ns[root].ch[0] ? ns[ns[root].ch[0]].x : 0;\n   if (l == a) root= ns[root].ch[0],\
    \ ns[root].par= 0;\n   else ns[root].dx= a - l, ns[root].ch[1]= 0, update(root);\n\
    \  } else lx= a;\n }\n // \u221E if x<a else f(x)\n void chinfty_left(i64 a= 0)\
    \ {\n  assert(a <= upper_bound());\n  if (a-= lx; a < 0) {\n   if (lslope < -INF)\
    \ return;\n   node_id i= new_node(-a, lslope);\n   if (root) x_search(root, 0),\
    \ ns[root].ch[0]= i, ns[i].par= root, update(root);\n   else root= i;\n   ly-=\
    \ ns[i].y;\n  } else if (a > 0) {\n   assert(root);\n   x_search(root, a);\n \
    \  i64 r= ns[root].dx;\n   if (int i= ns[root].ch[0]; i) ly+= ns[i].y + i128(a\
    \ - ns[i].x) * ns[root].slope, r+= ns[i].x;\n   else ly+= i128(a) * ns[root].slope;\n\
    \   if (r == a) root= ns[root].ch[1], ns[root].par= 0;\n   else ns[root].dx= r\
    \ - a, ns[root].ch[0]= 0, update(root);\n  }\n  lx+= a, lslope= -INF * 2;\n }\n\
    \ // min_{y<=x} f(y)\n void cumulative_chmin() {\n  assert(lslope <= 0);\n  if\
    \ (root) {\n   slope_search(root, 0);\n   if (ns[root].slope < 0) {\n    if (!ns[root].ch[1])\
    \ ns[root].ch[1]= new_node();\n    node_id i= ns[root].ch[1];\n    ns[i].sz= 1,\
    \ ns[i].x= ns[i].dx= INF * 2, ns[i].slope= ns[i].ch[0]= ns[i].ch[1]= ns[i].laz=\
    \ ns[i].y= 0, ns[i].par= root;\n   } else ns[root].ch[1]= 0, ns[root].dx= INF\
    \ * 2, ns[root].slope= 0;\n   update(root);\n  } else if (lslope) root= new_node(INF\
    \ * 2, 0);\n  else lx= INF * 2;\n }\n // min_{y<=x \u2227 y<=a} f(y)\n void cumulative_chmin_with_condition(i64\
    \ a) { chinfty_right(a), cumulative_chmin(); }\n // min_{y>=x} f(y)\n void cumulative_chmin_rev()\
    \ {\n  if (root) {\n   slope_search(root, 0);\n   i64 l= ns[root].ch[0] ? ns[ns[root].ch[0]].x\
    \ : 0, r= l + ns[root].dx, x= ns[root].slope > 0 ? l : r;\n   if (int i= ns[root].ch[0];\
    \ i) ly+= ns[i].y + i128(x - ns[i].x) * ns[root].slope;\n   else ly+= i128(x)\
    \ * ns[root].slope;\n   if (ns[root].slope > 0) ns[root].ch[0]= 0, update(root);\n\
    \   else root= ns[root].ch[1], ns[root].par= 0;\n   lx+= x;\n  }\n  lslope= 0;\n\
    \ }\n // min_{y>=x \u2227 y>=a} f(y)\n void cumulative_chmin_rev_with_condition(i64\
    \ a) { chinfty_left(a), cumulative_chmin_rev(); }\n // min_{x-b<=y<=x-a} f(y)\n\
    \ void chmin_sliding_window(i64 a, i64 b) { assert(a <= b), shift(a), chmin_sliding_window(b\
    \ - a); }\n // inf_y { f(x-y) + ( a * min{y-c,0} + b * max{y-c,0} ) }\n void convex_convolution_with_ax_bx_c(i64\
    \ a, i64 b, i64 c) { assert(a <= b), shift(c), add_linear(-a), cumulative_chmin_rev(),\
    \ add_linear(a), add_linear(-b), cumulative_chmin(), add_linear(b); }\n // inf_y\
    \ { f(x-y) + a |y-c| }\n void convex_convolution_with_abs(i64 a, i64 c) { convex_convolution_with_ax_bx_c(-a,\
    \ a, c); }\n std::array<i64, 2> argmin() {\n  assert(lslope <= 0);\n  if (!lslope)\
    \ return std::array{-INF, lx};\n  if (!root) return std::array{lx, lx};\n  slope_search(root,\
    \ 0);\n  i64 l= lx + (ns[root].ch[0] ? ns[ns[root].ch[0]].x : 0), r= l + ns[root].dx;\n\
    \  if (ns[root].slope == 0) return {l, r};\n  return ns[root].slope < 0 ? std::array{r,\
    \ r} : std::array{l, l};\n }\n i64 min() { return eval(argmin()[1]); }\n i64 eval(i64\
    \ x) {\n  if (x < lx && lslope < -INF) return INF;\n  if (x <= lx) return ly +\
    \ i128(x - lx) * lslope;\n  if (!root) return INF;\n  if (x-= lx; ns[root].x <\
    \ x) return INF;\n  x_search(root, x);\n  if (int i= ns[root].ch[0]; i) return\
    \ ly + ns[i].y + i128(x - ns[i].x) * ns[root].slope;\n  return ly + i128(x) *\
    \ ns[root].slope;\n }\n i64 operator()(i64 x) { return eval(x); }\n int size()\
    \ { return root ? ns[root].sz : 0; }\n // destructive\n PiecewiseLinearConvexfunction\
    \ operator+(PiecewiseLinearConvexfunction &r) {\n  if (size() > r.size()) std::swap(*this,\
    \ r);\n  if (lslope < -INF) r.chinfty_left(lx);\n  else r.add_ax_bx_c(lslope,\
    \ 0, lx);\n  r.chinfty_right(upper_bound());\n  long long x= lx, p= 0;\n  add(root,\
    \ x, p, r), r.add_const(ly);\n  return r;\n }\n // destructive\n PiecewiseLinearConvexfunction\
    \ &operator+=(PiecewiseLinearConvexfunction &r) { return *this= *this + r; }\n\
    };\n#line 4 \"test/atcoder/abc217_h.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n PiecewiseLinearConvexfunction\
    \ f;\n f.chinfty_right(), f.chinfty_left();\n long long pT= 0;\n for (int i= 0;\
    \ i < N; ++i) {\n  long long i64, D, X;\n  cin >> i64 >> D >> X;\n  long long\
    \ dT= i64 - pT;\n  f.chmin_sliding_window(-dT, dT);\n  if (D) f.add_ax_bx_c(0,\
    \ 1, X);\n  else f.add_ax_bx_c(-1, 0, X);\n  pT= i64;\n }\n cout << f.min() <<\
    \ '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc217/tasks/abc217_h\"\n#include\
    \ <iostream>\n#include \"src/Optimization/PiecewiseLinearConvexfunction.hpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n PiecewiseLinearConvexfunction f;\n f.chinfty_right(), f.chinfty_left();\n\
    \ long long pT= 0;\n for (int i= 0; i < N; ++i) {\n  long long i64, D, X;\n  cin\
    \ >> i64 >> D >> X;\n  long long dT= i64 - pT;\n  f.chmin_sliding_window(-dT,\
    \ dT);\n  if (D) f.add_ax_bx_c(0, 1, X);\n  else f.add_ax_bx_c(-1, 0, X);\n  pT=\
    \ i64;\n }\n cout << f.min() << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/PiecewiseLinearConvexfunction.hpp
  isVerificationFile: true
  path: test/atcoder/abc217_h.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 17:57:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc217_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc217_h.test.cpp
- /verify/test/atcoder/abc217_h.test.cpp.html
title: test/atcoder/abc217_h.test.cpp
---
