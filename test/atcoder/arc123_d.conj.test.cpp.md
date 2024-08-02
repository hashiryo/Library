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
    PROBLEM: https://atcoder.jp/contests/arc123/tasks/arc123_d
    links:
    - https://atcoder.jp/contests/arc123/tasks/arc123_d
  bundledCode: "#line 1 \"test/atcoder/arc123_d.conj.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/arc123/tasks/arc123_d\"\n#include <iostream>\n#line\
    \ 2 \"src/Optimization/PiecewiseLinearConvex.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <array>\n#line 6 \"src/Optimization/PiecewiseLinearConvex.hpp\"\
    \n#include <sstream>\n#include <string>\n#include <cassert>\n#line 2 \"src/Internal/long_traits.hpp\"\
    \n#include <cstdint>\n// clang-format off\ntemplate<class T>struct make_long{using\
    \ type= T;};\ntemplate<>struct make_long<int8_t>{using type= int16_t;};\ntemplate<>struct\
    \ make_long<uint8_t>{using type= uint16_t;};\ntemplate<>struct make_long<int16_t>{using\
    \ type= int32_t;};\ntemplate<>struct make_long<uint16_t>{using type= uint32_t;};\n\
    template<>struct make_long<int32_t>{using type= int64_t;};\ntemplate<>struct make_long<uint32_t>{using\
    \ type= uint64_t;};\ntemplate<>struct make_long<int64_t>{using type= __int128_t;};\n\
    template<>struct make_long<uint64_t>{using type= __uint128_t;};\ntemplate<>struct\
    \ make_long<float>{using type= double;};\ntemplate<>struct make_long<double>{using\
    \ type= long double;};\ntemplate<class T> using make_long_t= typename make_long<T>::type;\n\
    // clang-format on\n#line 10 \"src/Optimization/PiecewiseLinearConvex.hpp\"\n\
    template <class T> class PiecewiseLinearConvex {\n using D= make_long_t<T>;\n\
    \ struct Node {\n  Node *ch[2], *par;\n  T z, x, d, a;\n  D s;\n  size_t sz;\n\
    \  friend std::ostream &operator<<(std::ostream &os, const Node &t) { return os\
    \ << \"{z:\" << t.z << \",x:\" << t.x << \",d:\" << t.d << \",a:\" << t.a << \"\
    ,s:\" << t.s << \",sz:\" << t.sz << \",ch:(\" << t.ch[0] << \",\" << t.ch[1] <<\
    \ \"),par:\" << t.par << \"}\"; }\n };\n using np= Node *;\n static inline void\
    \ info(np t, int d, std::stringstream &ss) {\n  if (!t) return;\n  push(t), info(t->ch[0],\
    \ d + 1, ss);\n  for (int i= 0; i < d; ++i) ss << \"   \";\n  ss << \" \u25A0\
    \ \" << *t << '\\n', info(t->ch[1], d + 1, ss);\n }\n static inline void dump_xs(np\
    \ t, std::vector<T> &xs) {\n  if (t) push(t), dump_xs(t->ch[0], xs), xs.push_back(t->x),\
    \ dump_xs(t->ch[1], xs);\n }\n static inline void dump_slopes_l(np t, T ofs, std::vector<T>\
    \ &as) {\n  if (t) push(t), dump_slopes_l(t->ch[1], ofs, as), ofs+= sl(t->ch[1])\
    \ + t->d, as.push_back(-ofs), dump_slopes_l(t->ch[0], ofs, as);\n }\n static inline\
    \ void dump_slopes_r(np t, T ofs, std::vector<T> &as) {\n  if (t) push(t), dump_slopes_r(t->ch[0],\
    \ ofs, as), ofs+= sl(t->ch[0]) + t->d, as.push_back(ofs), dump_slopes_r(t->ch[1],\
    \ ofs, as);\n }\n static inline void update(np t) {\n  t->sz= 1, t->a= t->d, t->s=\
    \ D(t->x) * t->d;\n  if (np l= t->ch[0]; l) t->sz+= l->sz, t->a+= l->a, t->s+=\
    \ l->s;\n  if (np r= t->ch[1]; r) t->sz+= r->sz, t->a+= r->a, t->s+= r->s;\n }\n\
    \ static inline void prop(np t, T v) { t->z+= v, t->s+= D(v) * t->a, t->x+= v;\
    \ }\n static inline void push(np t) {\n  if (t->z != 0) {\n   if (t->ch[0]) prop(t->ch[0],\
    \ t->z);\n   if (t->ch[1]) prop(t->ch[1], t->z);\n   t->z= 0;\n  }\n }\n static\
    \ inline void rot(np t) {\n  np p= t->par;\n  if (bool d= p->ch[1] == t; (p->ch[d]=\
    \ std::exchange(t->ch[!d], p))) p->ch[d]->par= p;\n  if ((t->par= std::exchange(p->par,\
    \ t))) t->par->ch[t->par->ch[1] == p]= t;\n  update(p);\n }\n static inline void\
    \ splay(np t) {\n  for (np p= t->par; p; rot(t), p= t->par)\n   if (p->par) rot(p->par->ch[p->ch[1]\
    \ == t] == p ? p : t);\n }\n static inline T sl(np t) { return t ? t->a : 0; }\n\
    \ static inline D sum(np t) { return t ? t->s : 0; }\n template <bool r> static\
    \ inline bool lt(T a, T b) {\n  if constexpr (r) return b < a;\n  else return\
    \ a < b;\n }\n template <bool r> inline D calc_y(np t, T x, T ol, T ou) {\n  if\
    \ (t) {\n   for (np n;; t= n) {\n    if (push(t); lt<r>(t->x, x)) n= t->ch[!r];\n\
    \    else {\n     ol+= sl(t->ch[!r]), ou+= sum(t->ch[!r]);\n     if (t->x == x)\
    \ break;\n     ol+= t->d, ou+= D(t->x) * t->d, n= t->ch[r];\n    }\n    if (!n)\
    \ break;\n   }\n   splay(t), splay(mn);\n  }\n  if constexpr (r) return D(x) *\
    \ ol - ou;\n  else return ou - D(x) * ol;\n }\n np mn;\n bool bf[2];\n T o[2],\
    \ rem, bx[2];\n D y;\n D calc_y(T x) {\n  if (!mn) return 0;\n  if (mn->x == x)\
    \ return 0;\n  return x < mn->x ? calc_y<0>(mn->ch[0], x, o[0], D(mn->x) * o[0])\
    \ : calc_y<1>(mn->ch[1], x, o[1], D(mn->x) * o[1]);\n }\n template <bool r> void\
    \ slope_lr() {\n  np t= mn;\n  if (!t) return;\n  T ol= o[r];\n  if constexpr\
    \ (r) y-= sum(t->ch[r]) + D(t->x) * ol, rem+= ol + sl(t->ch[r]);\n  else y+= sum(t->ch[r])\
    \ + D(t->x) * ol, rem-= ol + sl(t->ch[r]);\n  for (; push(t), t->ch[r];) t= t->ch[r];\n\
    \  splay(mn= t), o[r]= 0, o[!r]= t->d;\n }\n void slope_eval() {\n  if (rem ==\
    \ 0 || !mn) return;\n  bool neg= rem < 0;\n  T p= neg ? -rem : rem, ol= 0;\n \
    \ D ou= 0;\n  np t= mn;\n  if (ol= o[neg]; p <= ol) {\n   o[neg]-= p, o[!neg]+=\
    \ p, y+= D(t->x) * rem, rem= 0;\n   return;\n  }\n  if (ou+= D(t->x) * ol, t=\
    \ t->ch[neg]; ol + sl(t) < p) return neg ? slope_lr<1>() : slope_lr<0>();\n  for\
    \ (T s, l;;) {\n   if (push(t), s= ol + sl(t->ch[!neg]), l= s + t->d; p < s) t=\
    \ t->ch[!neg];\n   else if (l < p) ol= l, ou+= sum(t->ch[!neg]) + D(t->x) * t->d,\
    \ t= t->ch[neg];\n   else {\n    if (o[neg]= l - p, o[!neg]= p - s; neg) y+= D(t->x)\
    \ * s - (ou + sum(t->ch[!neg]));\n    else y-= D(t->x) * s - (ou + sum(t->ch[!neg]));\n\
    \    break;\n   }\n  }\n  splay(mn= t), y+= D(t->x) * rem, rem= 0;\n }\n template\
    \ <bool r> void add_inf(T x0) {\n  if (bf[r] && !lt<r>(bx[r], x0)) return;\n \
    \ assert(!bf[!r] || !lt<r>(bx[!r], x0));\n  bf[r]= true, bx[r]= x0;\n  if (!mn)\
    \ return;\n  slope_lr<!r>();\n  if (!lt<r>(x0, mn->x)) {\n   mn= nullptr;\n  \
    \ return;\n  }\n  np t= mn, s= t;\n  for (; t;)\n   if (push(t); lt<r>(x0, t->x))\
    \ s= t, t= t->ch[r];\n   else t= t->ch[!r];\n  splay(s), s->ch[r]= nullptr, splay(mn);\n\
    \ }\n void add_r(np t) {\n  if (t) push(t), add_r(t->ch[0]), add_max(0, t->d,\
    \ t->x), add_r(t->ch[1]);\n }\n void add_l(np t) {\n  if (t) push(t), add_l(t->ch[0]),\
    \ add_max(-t->d, 0, t->x), add_l(t->ch[1]);\n }\npublic:\n PiecewiseLinearConvex():\
    \ mn(nullptr), bf{0, 0}, rem(0), y(0) {}\n std::string info() {\n  std::stringstream\
    \ ss;\n  if (ss << \"\\n rem:\" << rem << \", y:\" << y << \", mn:\" << mn <<\
    \ \"\\n bf[0]:\" << bf[0] << \", bf[1]:\" << bf[1] << \", bx[0]:\" << bx[0] <<\
    \ \", bx[1]:\" << bx[1] << \"\\n \" << \"o[0]:\" << o[0] << \", o[1]:\" << o[1]\
    \ << \"\\n\"; mn) info(mn, 0, ss);\n  return ss.str();\n }\n std::vector<T> dump_xs()\
    \ {\n  std::vector<T> xs;\n  if (bf[0]) xs.push_back(bx[0]);\n  if (mn) dump_xs(mn,\
    \ xs);\n  if (bf[1]) xs.push_back(bx[1]);\n  return xs;\n }\n std::vector<std::pair<T,\
    \ D>> dump_xys() {\n  auto xs= dump_xs();\n  std::vector<std::pair<T, D>> xys(xs.size());\n\
    \  for (int i= xs.size(); i--;) xys[i]= {xs[i], operator()(xs[i])};\n  return\
    \ xys;\n }\n std::vector<T> dump_slopes() {\n  std::vector<T> as;\n  if (mn) as.push_back(-o[0]),\
    \ dump_slopes_l(mn->ch[0], o[0], as), std::reverse(as.begin(), as.end()), as.push_back(o[1]),\
    \ dump_slopes_r(mn->ch[1], o[1], as);\n  else as.push_back(0);\n  for (auto &a:\
    \ as) a+= rem;\n  return as;\n }\n // f(x) += c\n void add_const(D c) { y+= c;\
    \ }\n // f(x) += ax, /\n void add_linear(T a) { rem+= a; }\n //  f(x) += max(a(x-x0),b(x-x0)),\
    \ (a < b)\n void add_max(T a, T b, T x0) {\n  assert(a < b);\n  if (bf[0] && x0\
    \ <= bx[0]) y-= D(b) * x0, rem+= b;\n  else if (bf[1] && bx[1] <= x0) y-= D(a)\
    \ * x0, rem+= a;\n  else if (mn) {\n   np t= mn;\n   for (;;) {\n    if (push(t);\
    \ t->x == x0) {\n     t->d+= b - a;\n     break;\n    }\n    np &n= t->ch[t->x\
    \ < x0];\n    if (!n) {\n     n= new Node{{nullptr, nullptr}, t, 0, x0, b - a,\
    \ b - a, D(x0) * (b - a), 1}, t= n;\n     break;\n    }\n    t= n;\n   }\n   if\
    \ (splay(t), splay(mn); x0 < mn->x) y-= D(b) * x0, rem+= b;\n   else if (y-= D(a)\
    \ * x0, rem+= a; x0 == mn->x) o[1]+= b - a;\n  } else mn= new Node{{nullptr, nullptr},\
    \ nullptr, 0, x0, b - a, b - a, D(x0) * (b - a), 1}, y-= D(a) * x0, rem+= a, o[0]=\
    \ 0, o[1]= b - a;\n }\n // f(x) +=  max(0, a(x-x0))\n void add_ramp(T a, T x0)\
    \ {\n  if (a != 0) a > 0 ? add_max(0, a, x0) : add_max(a, 0, x0);\n }\n // f(x)\
    \ += a|x-x0|, \\/\n void add_abs(T a, T x0) {\n  if (assert(a >= 0); a != 0) add_max(-a,\
    \ a, x0);\n }\n // right=false : f(x) +=  inf  (x < x_0), right=true: f(x) +=\
    \ inf  (x_0 < x)\n void add_inf(bool right= false, T x0= 0) { return right ? add_inf<1>(x0)\
    \ : add_inf<0>(x0); }\n // f(x) <- f(x-x0)\n void shift(T x0) {\n  if (bx[0]+=\
    \ x0, bx[1]+= x0, y-= D(rem) * x0; mn) mn->z+= x0, mn->x+= x0;\n }\n // rev=false:\
    \ f(x) <- min_{y<=x} f(y), rev=true : f(x) <- min_{x<=y} f(y)\n void chmin_cum(bool\
    \ rev= false) {\n  if (bf[0] && bf[1] && bx[0] == bx[1]) y+= D(rem) * bx[0], rem=\
    \ 0;\n  else if (slope_eval(); rem == 0) {\n   if (mn) mn->d= o[rev], o[!rev]=\
    \ 0, mn->ch[!rev]= nullptr;\n  } else if ((rem > 0) ^ rev) assert(bf[rev]), y+=\
    \ D(rem) * bx[rev], rem= 0, mn= nullptr;\n  else if (bf[!rev]) {\n   T p= std::abs(rem);\n\
    \   np t= new Node{{nullptr, nullptr}, mn, 0, bx[!rev], p, p, D(bx[!rev]) * p,\
    \ 1};\n   if (mn) mn->ch[!rev]= t;\n   mn= t, o[rev]= p, o[!rev]= 0;\n  }\n  bf[!rev]=\
    \ false;\n }\n //  f(x) <- min_{lb<=y<=ub} f(x-y). (lb <= ub), \\_/ -> \\__/\n\
    \ void chmin_slide_win(T lb, T ub) {\n  assert(lb <= ub);\n  if (bf[0] && bf[1]\
    \ && bx[0] == bx[1]) y+= D(rem) * bx[0], rem= 0;\n  else if (slope_eval(); rem\
    \ == 0) {\n   if (mn) {\n    if (o[0] == 0) {\n     if (mn->z+= ub, mn->x+= ub;\
    \ mn->ch[0]) prop(mn->ch[0], lb - ub);\n    } else if (o[1] == 0) {\n     if (mn->z+=\
    \ lb, mn->x+= lb; mn->ch[1]) prop(mn->ch[1], ub - lb);\n    } else {\n     np\
    \ r= mn->ch[1], t= new Node{{nullptr, r}, mn, 0, mn->x, o[1], 0, 0, 1};\n    \
    \ if (update(t), prop(mn->ch[1]= t, ub - lb), mn->d= o[0], o[1]= 0, mn->z+= lb,\
    \ mn->x+= lb; r) r->par= t;\n    }\n   }\n  } else {\n   bool r= rem > 0;\n  \
    \ T b[2]= {lb, ub};\n   if (bf[!r]) {\n    T p= r ? rem : -rem;\n    np t= new\
    \ Node{{nullptr, nullptr}, nullptr, 0, bx[!r], p, p, D(bx[!r]) * p, 1};\n    if\
    \ (y+= D(rem) * bx[!r], rem= 0, mn= t, t->z+= b[r], t->x+= b[r], o[r]= p, o[!r]=\
    \ 0; mn) t->ch[r]= mn, mn->par= t;\n   } else if (y-= D(rem) * b[r]; mn) mn->z+=\
    \ b[r], mn->x+= b[r];\n  }\n  bx[0]+= lb, bx[1]+= ub;\n }\n D operator()(T x)\
    \ { return assert(!bf[0] || bx[0] <= x), assert(!bf[1] || x <= bx[1]), calc_y(x)\
    \ + D(rem) * x + y; }\n D min() { return slope_eval(), rem == 0 ? y : rem > 0\
    \ ? (assert(bf[0]), y + D(rem) * bx[0]) : (assert(bf[1]), y + D(rem) * bx[1]);\
    \ }\n std::array<T, 2> argmin() {\n  slope_eval();\n  if (rem > 0) {\n   assert(bf[0]);\n\
    \   return {bx[0], bx[0]};\n  }\n  if (rem < 0) {\n   assert(bf[1]);\n   return\
    \ {bx[1], bx[1]};\n  }\n  std::array<T, 2> ret= {bx[0], bx[1]};\n  np t= mn;\n\
    \  if (!t) return ret;\n  bool r= o[0] == 0;\n  if (!r && o[1] != 0) ret[0]= ret[1]=\
    \ t->x;\n  else if (ret[r]= t->x, t= t->ch[!r]; t) {\n   for (; t->ch[r];) push(t),\
    \ t= t->ch[r];\n   splay(t), ret[!r]= t->x, splay(mn);\n  } else assert(bf[!r]);\n\
    \  return ret;\n }\n size_t size() { return mn ? mn->sz : 0; }\n PiecewiseLinearConvex\
    \ &operator+=(const PiecewiseLinearConvex &r) {\n  if (y+= r.y, rem+= r.rem; r.bf[0])\
    \ add_inf(false, r.bx[0]);\n  if (r.bf[1]) add_inf(true, r.bx[1]);\n  if (r.mn)\
    \ add_l(r.mn->ch[0]), add_r(r.mn->ch[1]), add_max(-r.o[0], r.o[1], r.mn->x);\n\
    \  return *this;\n }\n};\n#line 4 \"test/atcoder/arc123_d.conj.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N;\n cin >> N;\n PiecewiseLinearConvex<long long> f;\n f.add_inf(), f.add_inf(true);\n\
    \ int pA;\n for (int i= 0; i < N; ++i) {\n  int A;\n  cin >> A;\n  if (i) f.add_linear(max(A\
    \ - pA, 0)), f.add_inf(true);\n  f.chmin_slide_win(-1, 1);\n  f.add_linear(-A);\n\
    \  f.chmin_slide_win(-1, 1);\n  f.add_linear(A);\n  pA= A;\n }\n cout << (long\
    \ long)-f(0) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\n#include\
    \ <iostream>\n#include \"src/Optimization/PiecewiseLinearConvex.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin\
    \ >> N;\n PiecewiseLinearConvex<long long> f;\n f.add_inf(), f.add_inf(true);\n\
    \ int pA;\n for (int i= 0; i < N; ++i) {\n  int A;\n  cin >> A;\n  if (i) f.add_linear(max(A\
    \ - pA, 0)), f.add_inf(true);\n  f.chmin_slide_win(-1, 1);\n  f.add_linear(-A);\n\
    \  f.chmin_slide_win(-1, 1);\n  f.add_linear(A);\n  pA= A;\n }\n cout << (long\
    \ long)-f(0) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/PiecewiseLinearConvex.hpp
  - src/Internal/long_traits.hpp
  isVerificationFile: true
  path: test/atcoder/arc123_d.conj.test.cpp
  requiredBy: []
  timestamp: '2024-08-02 10:52:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc123_d.conj.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc123_d.conj.test.cpp
- /verify/test/atcoder/arc123_d.conj.test.cpp.html
title: test/atcoder/arc123_d.conj.test.cpp
---
