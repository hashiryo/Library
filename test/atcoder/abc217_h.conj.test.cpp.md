---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/long_traits.hpp
    title: "int \u304B\u3089 long long \u306A\u3069\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
  - icon: ':x:'
    path: src/Optimization/PiecewiseLinearConvex.hpp
    title: src/Optimization/PiecewiseLinearConvex.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc217/tasks/abc217_h
    links:
    - https://atcoder.jp/contests/abc217/tasks/abc217_h
  bundledCode: "#line 1 \"test/atcoder/abc217_h.conj.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc217/tasks/abc217_h\"\n#include <iostream>\n#line\
    \ 2 \"src/Optimization/PiecewiseLinearConvex.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <array>\n#line 6 \"src/Optimization/PiecewiseLinearConvex.hpp\"\
    \n#include <sstream>\n#include <string>\n#include <cassert>\n#include <utility>\n\
    #line 2 \"src/Internal/long_traits.hpp\"\n#include <cstdint>\n// clang-format\
    \ off\ntemplate<class T>struct make_long{using type= T;};\ntemplate<>struct make_long<int8_t>{using\
    \ type= int16_t;};\ntemplate<>struct make_long<uint8_t>{using type= uint16_t;};\n\
    template<>struct make_long<int16_t>{using type= int32_t;};\ntemplate<>struct make_long<uint16_t>{using\
    \ type= uint32_t;};\ntemplate<>struct make_long<int32_t>{using type= int64_t;};\n\
    template<>struct make_long<uint32_t>{using type= uint64_t;};\ntemplate<>struct\
    \ make_long<int64_t>{using type= __int128_t;};\ntemplate<>struct make_long<uint64_t>{using\
    \ type= __uint128_t;};\ntemplate<>struct make_long<float>{using type= double;};\n\
    template<>struct make_long<double>{using type= long double;};\ntemplate<class\
    \ T> using make_long_t= typename make_long<T>::type;\n// clang-format on\n#line\
    \ 11 \"src/Optimization/PiecewiseLinearConvex.hpp\"\nnamespace plc_internal {\n\
    #ifdef __LOCAL\nstatic constexpr size_t __NODE_SIZE= 1 << 15;\n#else\nstatic constexpr\
    \ size_t __NODE_SIZE= 1 << 22;\n#endif\n}\ntemplate <class T, size_t NODE_SIZE=\
    \ plc_internal::__NODE_SIZE> class PiecewiseLinearConvex {\n using D= make_long_t<T>;\n\
    \ struct Node {\n  int ch[2], par;\n  T z, x, d, a;\n  D s;\n  size_t sz;\n  friend\
    \ std::ostream &operator<<(std::ostream &os, const Node &t) { return os << \"\
    {z:\" << t.z << \",x:\" << t.x << \",d:\" << t.d << \",a:\" << t.a << \",s:\"\
    \ << t.s << \",sz:\" << t.sz << \",ch:(\" << t.ch[0] << \",\" << t.ch[1] << \"\
    ),par:\" << t.par << \"}\"; }\n };\n static inline int ni= 1;\n static inline\
    \ Node n[NODE_SIZE];\n static inline void info(int t, int d, std::stringstream\
    \ &ss) {\n  if (!t) return;\n  // push(t);\n  info(n[t].ch[0], d + 1, ss);\n \
    \ for (int i= 0; i < d; ++i) ss << \"   \";\n  ss << \" \u25A0 \" << n[t] << '\\\
    n', info(n[t].ch[1], d + 1, ss);\n }\n static inline void dump_xs(int t, std::vector<T>\
    \ &xs) {\n  if (t) push(t), dump_xs(n[t].ch[0], xs), xs.push_back(n[t].x), dump_xs(n[t].ch[1],\
    \ xs);\n }\n static inline void dump_slopes_l(int t, T ofs, std::vector<T> &as)\
    \ {\n  if (t) push(t), dump_slopes_l(n[t].ch[1], ofs, as), ofs+= n[n[t].ch[1]].a\
    \ + n[t].d, as.push_back(-ofs), dump_slopes_l(n[t].ch[0], ofs, as);\n }\n static\
    \ inline void dump_slopes_r(int t, T ofs, std::vector<T> &as) {\n  if (t) push(t),\
    \ dump_slopes_r(n[t].ch[0], ofs, as), ofs+= n[n[t].ch[0]].a + n[t].d, as.push_back(ofs),\
    \ dump_slopes_r(n[t].ch[1], ofs, as);\n }\n static inline void update(int t) {\n\
    \  n[t].sz= 1, n[t].a= n[t].d, n[t].s= D(n[t].x) * n[t].d;\n  if (int l= n[t].ch[0];\
    \ l) n[t].sz+= n[l].sz, n[t].a+= n[l].a, n[t].s+= n[l].s;\n  if (int r= n[t].ch[1];\
    \ r) n[t].sz+= n[r].sz, n[t].a+= n[r].a, n[t].s+= n[r].s;\n }\n static inline\
    \ void prop(int t, T v) { n[t].z+= v, n[t].s+= D(v) * n[t].a, n[t].x+= v; }\n\
    \ static inline void push(int t) {\n  if (n[t].z != 0) {\n   if (n[t].ch[0]) prop(n[t].ch[0],\
    \ n[t].z);\n   if (n[t].ch[1]) prop(n[t].ch[1], n[t].z);\n   n[t].z= 0;\n  }\n\
    \ }\n static inline void rot(int t) {\n  int p= n[t].par;\n  if (bool d= n[p].ch[1]\
    \ == t; (n[p].ch[d]= std::exchange(n[t].ch[!d], p))) n[n[p].ch[d]].par= p;\n \
    \ if ((n[t].par= std::exchange(n[p].par, t))) n[n[t].par].ch[n[n[t].par].ch[1]\
    \ == p]= t;\n  update(p);\n }\n static inline void splay(int t) {\n  for (int\
    \ p= n[t].par; p; rot(t), p= n[t].par)\n   if (n[p].par) rot(n[n[p].par].ch[n[p].ch[1]\
    \ == t] == p ? p : t);\n }\n template <bool r> static inline bool lt(T a, T b)\
    \ {\n  if constexpr (r) return b < a;\n  else return a < b;\n }\n template <bool\
    \ r> inline D calc_y(int t, T x, T ol, T ou) {\n  if (t) {\n   for (int s;; t=\
    \ s) {\n    if (push(t); lt<r>(n[t].x, x)) s= n[t].ch[!r];\n    else {\n     ol+=\
    \ n[n[t].ch[!r]].a, ou+= n[n[t].ch[!r]].s;\n     if (n[t].x == x) break;\n   \
    \  ol+= n[t].d, ou+= D(n[t].x) * n[t].d, s= n[t].ch[r];\n    }\n    if (!s) break;\n\
    \   }\n   splay(t), splay(mn);\n  }\n  if constexpr (r) return D(x) * ol - ou;\n\
    \  else return ou - D(x) * ol;\n }\n int mn;\n bool bf[2];\n T o[2], rem, bx[2];\n\
    \ D y;\n D calc_y(T x) {\n  if (!mn) return 0;\n  if (n[mn].x == x) return 0;\n\
    \  return push(mn), x < n[mn].x ? calc_y<0>(n[mn].ch[0], x, o[0], D(n[mn].x) *\
    \ o[0]) : calc_y<1>(n[mn].ch[1], x, o[1], D(n[mn].x) * o[1]);\n }\n void slope_lr(bool\
    \ r) {\n  int t= mn;\n  if (!t) return;\n  for (; push(t), n[t].ch[r];) t= n[t].ch[r];\n\
    \  D p= n[n[mn].ch[r]].s + D(n[mn].x) * o[r];\n  T q= o[r] + n[n[mn].ch[r]].a;\n\
    \  splay(mn= t), o[r]= 0, o[!r]= n[t].d, r ? (y-= p, rem+= q) : (y+= p, rem-=\
    \ q);\n }\n void slope_eval() {\n  if (rem == 0 || !mn) return;\n  bool neg= rem\
    \ < 0;\n  T p= neg ? -rem : rem, ol= 0;\n  D ou= 0;\n  int t= mn;\n  if (push(t),\
    \ ol= o[neg]; p <= ol) {\n   o[neg]-= p, o[!neg]+= p, y+= D(n[t].x) * rem, rem=\
    \ 0;\n   return;\n  }\n  if (ou+= D(n[t].x) * ol, t= n[t].ch[neg]; ol + n[t].a\
    \ < p) return slope_lr(neg);\n  for (T s, l;;) {\n   if (push(t), s= ol + n[n[t].ch[!neg]].a,\
    \ l= s + n[t].d; p < s) t= n[t].ch[!neg];\n   else if (l < p) ol= l, ou+= n[n[t].ch[!neg]].s\
    \ + D(n[t].x) * n[t].d, t= n[t].ch[neg];\n   else {\n    if (o[neg]= l - p, o[!neg]=\
    \ p - s; neg) y+= D(n[t].x) * s - (ou + n[n[t].ch[!neg]].s);\n    else y-= D(n[t].x)\
    \ * s - (ou + n[n[t].ch[!neg]].s);\n    break;\n   }\n  }\n  splay(mn= t), y+=\
    \ D(n[t].x) * rem, rem= 0;\n }\n template <bool r> void add_inf(T x0) {\n  if\
    \ (bf[r] && !lt<r>(bx[r], x0)) return;\n  if (assert(!bf[!r] || !lt<r>(bx[!r],\
    \ x0)), bf[r]= true, bx[r]= x0; !mn) return;\n  if (slope_lr(!r); !lt<r>(x0, n[mn].x))\
    \ return mn= 0, void();\n  int t= mn, s= t;\n  for (; t;)\n   if (push(t); lt<r>(x0,\
    \ n[t].x)) s= t, t= n[t].ch[r];\n   else t= n[t].ch[!r];\n  splay(s), n[s].ch[r]=\
    \ 0, splay(mn);\n }\n void add_r(int t) {\n  if (t) push(t), add_r(n[t].ch[0]),\
    \ add_max(0, n[t].d, n[t].x), add_r(n[t].ch[1]);\n }\n void add_l(int t) {\n \
    \ if (t) push(t), add_l(n[t].ch[0]), add_max(-n[t].d, 0, n[t].x), add_l(n[t].ch[1]);\n\
    \ }\npublic:\n PiecewiseLinearConvex(): mn(0), bf{0, 0}, rem(0), y(0) {}\n static\
    \ void clear() { ni= 1; }\n std::string info() {\n  std::stringstream ss;\n  if\
    \ (ss << \"\\n rem:\" << rem << \", y:\" << y << \", mn:\" << mn << \"\\n bf[0]:\"\
    \ << bf[0] << \", bf[1]:\" << bf[1] << \", bx[0]:\" << bx[0] << \", bx[1]:\" <<\
    \ bx[1] << \"\\n \" << \"o[0]:\" << o[0] << \", o[1]:\" << o[1] << \"\\n\"; mn)\
    \ info(mn, 0, ss);\n  return ss.str();\n }\n std::vector<T> dump_xs() {\n  std::vector<T>\
    \ xs;\n  if (bf[0]) xs.push_back(bx[0]);\n  if (mn) dump_xs(mn, xs);\n  if (bf[1])\
    \ xs.push_back(bx[1]);\n  return xs;\n }\n std::vector<std::pair<T, D>> dump_xys()\
    \ {\n  auto xs= dump_xs();\n  std::vector<std::pair<T, D>> xys(xs.size());\n \
    \ for (int i= xs.size(); i--;) xys[i]= {xs[i], operator()(xs[i])};\n  return xys;\n\
    \ }\n std::vector<T> dump_slopes() {\n  std::vector<T> as;\n  if (mn) as.push_back(-o[0]),\
    \ dump_slopes_l(n[mn].ch[0], o[0], as), std::reverse(as.begin(), as.end()), as.push_back(o[1]),\
    \ dump_slopes_r(n[mn].ch[1], o[1], as);\n  else as.push_back(0);\n  for (auto\
    \ &a: as) a+= rem;\n  return as;\n }\n // f(x) += c\n void add_const(D c) { y+=\
    \ c; }\n // f(x) += ax, /\n void add_linear(T a) { rem+= a; }\n //  f(x) += max(a(x-x0),b(x-x0)),\
    \ (a < b)\n void add_max(T a, T b, T x0) {\n  assert(a < b);\n  if (bf[0] && x0\
    \ <= bx[0]) y-= D(b) * x0, rem+= b;\n  else if (bf[1] && bx[1] <= x0) y-= D(a)\
    \ * x0, rem+= a;\n  else if (mn) {\n   int t= mn;\n   for (;;) {\n    if (push(t);\
    \ n[t].x == x0) {\n     n[t].d+= b - a;\n     break;\n    }\n    int &s= n[t].ch[n[t].x\
    \ < x0];\n    if (!s) {\n     n[s= ni++]= Node{{0, 0}, t, 0, x0, b - a, b - a,\
    \ D(x0) * (b - a), 1}, t= s;\n     break;\n    }\n    t= s;\n   }\n   if (splay(t),\
    \ splay(mn); x0 < n[mn].x) y-= D(b) * x0, rem+= b;\n   else if (y-= D(a) * x0,\
    \ rem+= a; x0 == n[mn].x) o[1]+= b - a;\n  } else n[mn= ni++]= Node{{0, 0}, 0,\
    \ 0, x0, b - a, b - a, D(x0) * (b - a), 1}, y-= D(a) * x0, rem+= a, o[0]= 0, o[1]=\
    \ b - a;\n }\n // f(x) +=  max(0, a(x-x0))\n void add_ramp(T a, T x0) {\n  if\
    \ (a != 0) a > 0 ? add_max(0, a, x0) : add_max(a, 0, x0);\n }\n // f(x) += a|x-x0|,\
    \ \\/\n void add_abs(T a, T x0) {\n  if (assert(a >= 0); a != 0) add_max(-a, a,\
    \ x0);\n }\n // right=false : f(x) +=  inf  (x < x_0), right=true: f(x) += inf\
    \  (x_0 < x)\n void add_inf(bool right= false, T x0= 0) { return right ? add_inf<1>(x0)\
    \ : add_inf<0>(x0); }\n // f(x) <- f(x-x0)\n void shift(T x0) {\n  if (bx[0]+=\
    \ x0, bx[1]+= x0, y-= D(rem) * x0; mn) n[mn].z+= x0, n[mn].x+= x0;\n }\n // rev=false:\
    \ f(x) <- min_{y<=x} f(y), rev=true : f(x) <- min_{x<=y} f(y)\n void chmin_cum(bool\
    \ rev= false) {\n  if (bf[0] && bf[1] && bx[0] == bx[1]) y+= D(rem) * bx[0], rem=\
    \ 0;\n  else if (slope_eval(); rem == 0) {\n   if (mn) n[mn].d= o[rev], o[!rev]=\
    \ 0, n[mn].ch[!rev]= 0;\n  } else if ((rem > 0) ^ rev) assert(bf[rev]), y+= D(rem)\
    \ * bx[rev], rem= 0, mn= 0;\n  else if (bf[!rev]) {\n   T p= std::abs(rem);\n\
    \   int t= ni++;\n   n[t]= Node{{0, 0}, 0, 0, bx[!rev], p, p, D(bx[!rev]) * p,\
    \ 1};\n   if (mn) update(mn), n[t].ch[rev]= mn, n[mn].par= t;\n   mn= t, o[rev]=\
    \ p, o[!rev]= 0, y+= D(rem) * bx[!rev], rem= 0;\n  }\n  bf[!rev]= false;\n }\n\
    \ //  f(x) <- min_{lb<=y<=ub} f(x-y). (lb <= ub), \\_/ -> \\__/\n void chmin_slide_win(T\
    \ lb, T ub) {\n  assert(lb <= ub);\n  if (bf[0] && bf[1] && bx[0] == bx[1]) y+=\
    \ D(rem) * bx[0], rem= 0;\n  else if (slope_eval(); rem == 0) {\n   if (mn) {\n\
    \    if (o[0] == 0) {\n     if (n[mn].z+= ub, n[mn].x+= ub; n[mn].ch[0]) prop(n[mn].ch[0],\
    \ lb - ub);\n    } else if (o[1] == 0) {\n     if (n[mn].z+= lb, n[mn].x+= lb;\
    \ n[mn].ch[1]) prop(n[mn].ch[1], ub - lb);\n    } else {\n     int r= n[mn].ch[1],\
    \ t= ni++;\n     n[t]= Node{{0, r}, mn, 0, n[mn].x, o[1], 0, 0, 1};\n     if (update(t),\
    \ prop(n[mn].ch[1]= t, ub - lb), n[mn].d= o[0], o[1]= 0, n[mn].z+= lb, n[mn].x+=\
    \ lb; r) n[r].par= t;\n    }\n   }\n  } else {\n   bool r= rem > 0;\n   T b[2]=\
    \ {lb, ub};\n   if (bf[!r]) {\n    T p= r ? rem : -rem;\n    int t= ni++;\n  \
    \  n[t]= Node{{0, 0}, 0, 0, bx[!r], p, p, D(bx[!r]) * p, 1};\n    if (mn) update(mn),\
    \ n[t].ch[r]= mn, n[mn].par= t;\n    y+= D(rem) * bx[!r], rem= 0, mn= t, n[t].z+=\
    \ b[r], n[t].x+= b[r], o[r]= p, o[!r]= 0;\n   } else if (y-= D(rem) * b[r]; mn)\
    \ n[mn].z+= b[r], n[mn].x+= b[r];\n  }\n  bx[0]+= lb, bx[1]+= ub;\n }\n D operator()(T\
    \ x) { return assert(!bf[0] || bx[0] <= x), assert(!bf[1] || x <= bx[1]), calc_y(x)\
    \ + D(rem) * x + y; }\n D min() { return slope_eval(), rem == 0 ? y : rem > 0\
    \ ? (assert(bf[0]), y + D(rem) * bx[0]) : (assert(bf[1]), y + D(rem) * bx[1]);\
    \ }\n std::array<T, 2> argmin() {\n  slope_eval();\n  if (rem > 0) {\n   assert(bf[0]);\n\
    \   return {bx[0], bx[0]};\n  }\n  if (rem < 0) {\n   assert(bf[1]);\n   return\
    \ {bx[1], bx[1]};\n  }\n  std::array<T, 2> ret= {bx[0], bx[1]};\n  int t= mn;\n\
    \  if (!t) return ret;\n  bool r= o[0] == 0;\n  if (!r && o[1] != 0) ret[0]= ret[1]=\
    \ n[t].x;\n  else if (ret[r]= n[t].x, t= n[t].ch[!r]; t) {\n   for (; n[t].ch[r];)\
    \ push(t), t= n[t].ch[r];\n   splay(t), ret[!r]= n[t].x, splay(mn);\n  } else\
    \ assert(bf[!r]);\n  return ret;\n }\n size_t size() { return mn ? update(mn),\
    \ n[mn].sz : 0; }\n PiecewiseLinearConvex &operator+=(const PiecewiseLinearConvex\
    \ &r) {\n  if (y+= r.y, rem+= r.rem; r.bf[0]) add_inf(false, r.bx[0]);\n  if (r.bf[1])\
    \ add_inf(true, r.bx[1]);\n  if (r.mn) add_l(n[r.mn].ch[0]), add_r(n[r.mn].ch[1]),\
    \ add_max(-r.o[0], r.o[1], n[r.mn].x);\n  return *this;\n }\n};\n#line 4 \"test/atcoder/abc217_h.conj.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n PiecewiseLinearConvex<long long> f;\n long long pT= 0;\n\
    \ for (int i= 0; i < N; ++i) {\n  long long i64, D, X;\n  cin >> i64 >> D >> X;\n\
    \  long long dT= i64 - pT;\n  f.add_abs(dT, 0);\n  f.add_linear(-X);\n  if (D)\
    \ f.chmin_slide_win(0, 1);\n  else f.chmin_slide_win(-1, 0);\n  f.add_linear(X);\n\
    \  pT= i64;\n }\n cout << (long long)-f(0) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc217/tasks/abc217_h\"\n#include\
    \ <iostream>\n#include \"src/Optimization/PiecewiseLinearConvex.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin\
    \ >> N;\n PiecewiseLinearConvex<long long> f;\n long long pT= 0;\n for (int i=\
    \ 0; i < N; ++i) {\n  long long i64, D, X;\n  cin >> i64 >> D >> X;\n  long long\
    \ dT= i64 - pT;\n  f.add_abs(dT, 0);\n  f.add_linear(-X);\n  if (D) f.chmin_slide_win(0,\
    \ 1);\n  else f.chmin_slide_win(-1, 0);\n  f.add_linear(X);\n  pT= i64;\n }\n\
    \ cout << (long long)-f(0) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/PiecewiseLinearConvex.hpp
  - src/Internal/long_traits.hpp
  isVerificationFile: true
  path: test/atcoder/abc217_h.conj.test.cpp
  requiredBy: []
  timestamp: '2024-08-03 18:26:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc217_h.conj.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc217_h.conj.test.cpp
- /verify/test/atcoder/abc217_h.conj.test.cpp.html
title: test/atcoder/abc217_h.conj.test.cpp
---
