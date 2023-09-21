---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Point.hpp
    title: src/Geometry/Point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2635.test.cpp
    title: test/aoj/2635.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Geometry/IncrementalConvexHull.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <set>\n#line 2 \"src/Geometry/Point.hpp\"\n#include\
    \ <iostream>\n#include <fstream>\n#include <iomanip>\n#include <cmath>\n#include\
    \ <cassert>\nnamespace geo {\nusing namespace std;\nstruct Visualizer {\n ofstream\
    \ ofs;\n Visualizer(string s= \"visualize.txt\"): ofs(s) { ofs << fixed << setprecision(10);\
    \ }\n};\ntemplate <class K> int sgn(K x) {\n if constexpr (is_floating_point_v<K>)\
    \ {\n  static constexpr K EPS= 1e-9;\n  return x < -EPS ? -1 : x > EPS;\n } else\
    \ return x < 0 ? -1 : x > 0;\n}\ntemplate <class K> K err_floor(const K &x) {\n\
    \ K y= floor(x);\n if constexpr (is_floating_point_v<K>)\n  if (K z= y + 1, w=\
    \ x - z; 0 <= sgn(w) && sgn(w - 1) < 0) return z;\n return y;\n}\ntemplate <class\
    \ K> K err_ceil(const K &x) {\n K y= ceil(x);\n if constexpr (is_floating_point_v<K>)\n\
    \  if (K z= y - 1, w= x - z; 0 < sgn(w + 1) && sgn(w) <= 0) return z;\n return\
    \ y;\n}\nlong double radian_to_degree(long double r) { return r * 180.0 / M_PI;\
    \ }\nlong double degree_to_radian(long double d) { return d * M_PI / 180.0; }\n\
    template <class K> struct Point {\n K x, y;\n Point(K x= K(), K y= K()): x(x),\
    \ y(y) {}\n Point &operator+=(const Point &p) { return x+= p.x, y+= p.y, *this;\
    \ }\n Point &operator-=(const Point &p) { return x-= p.x, y-= p.y, *this; }\n\
    \ Point &operator*=(K a) { return x*= a, y*= a, *this; }\n Point &operator/=(K\
    \ a) { return x/= a, y/= a, *this; }\n Point operator+(const Point &p) const {\
    \ return {x + p.x, y + p.y}; }\n Point operator-(const Point &p) const { return\
    \ {x - p.x, y - p.y}; }\n Point operator*(K a) const { return {x * a, y * a};\
    \ }\n Point operator/(K a) const { return {x / a, y / a}; }\n friend Point operator*(K\
    \ a, const Point &p) { return {a * p.x, a * p.y}; }\n Point operator-() const\
    \ { return {-x, -y}; }\n bool operator<(const Point &p) const {\n  int s= sgn(x\
    \ - p.x);\n  return s ? s < 0 : sgn(y - p.y) < 0;\n }\n bool operator>(const Point\
    \ &p) const { return p < *this; }\n bool operator<=(const Point &p) const { return\
    \ !(p < *this); }\n bool operator>=(const Point &p) const { return !(*this < p);\
    \ }\n bool operator==(const Point &p) const { return !sgn(x - p.x) && !sgn(y -\
    \ p.y); }\n bool operator!=(const Point &p) const { return sgn(x - p.x) || sgn(y\
    \ - p.y); }\n Point operator!() const { return {-y, x}; }  // rotate 90 degree\n\
    \ friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y;\
    \ }\n friend ostream &operator<<(ostream &os, const Point &p) { return os << \"\
    (\" << p.x << \", \" << p.y << \")\"; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Point &p) { return vis.ofs << p.x << \" \" << p.y << \"\\n\", vis;\
    \ }\n};\ntemplate <class K> K dot(const Point<K> &p, const Point<K> &q) { return\
    \ p.x * q.x + p.y * q.y; }\n// left turn: > 0, right turn: < 0\ntemplate <class\
    \ K> K cross(const Point<K> &p, const Point<K> &q) { return p.x * q.y - p.y *\
    \ q.x; }\ntemplate <class K> K norm2(const Point<K> &p) { return dot(p, p); }\n\
    template <class K> long double norm(const Point<K> &p) { return sqrt(norm2(p));\
    \ }\ntemplate <class K> K dist2(const Point<K> &p, const Point<K> &q) { return\
    \ norm2(p - q); }\ntemplate <class T, class U> long double dist(const T &a, const\
    \ U &b) { return sqrt(dist2(a, b)); }\ntemplate <class K> long double angle(const\
    \ Point<K> &p) { return atan2(p.y, p.x); }\ntemplate <class K> long double angle(const\
    \ Point<K> &p, const Point<K> &q) { return atan2(cross(p, q), dot(p, q)); }\n\
    enum CCW { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT\
    \ };\nostream &operator<<(ostream &os, CCW c) { return os << (c == COUNTER_CLOCKWISE\
    \ ? \"COUNTER_CLOCKWISE\" : c == CLOCKWISE ? \"CLOCKWISE\" : c == ONLINE_BACK\
    \ ? \"ONLINE_BACK\" : c == ONLINE_FRONT ? \"ONLINE_FRONT\" : \"ON_SEGMENT\");\
    \ }\ntemplate <class K> CCW ccw(const Point<K> &p0, const Point<K> &p1, const\
    \ Point<K> &p2) {\n Point a= p1 - p0, b= p2 - p0;\n if (int s= sgn(cross(a, b));\
    \ s) return s > 0 ? COUNTER_CLOCKWISE : CLOCKWISE;\n if (K d= dot(a, b); sgn(d)\
    \ < 0) return ONLINE_BACK;\n else return sgn(d - norm2(a)) > 0 ? ONLINE_FRONT\
    \ : ON_SEGMENT;\n}\ntemplate <class K> struct Line;\ntemplate <class K> struct\
    \ Segment;\ntemplate <class K> struct Circle;\ntemplate <class K> struct Polygon;\n\
    template <class K> struct Convex;\ntemplate <class K> struct Affine {\n K a00=\
    \ 1, a01= 0, a10= 0, a11= 1;\n Point<K> b;\n Point<K> operator()(const Point<K>\
    \ &p) const { return {a00 * p.x + a01 * p.y + b.x, a10 * p.x + a11 * p.y + b.y};\
    \ }\n Line<K> operator()(const Line<K> &l);\n Segment<K> operator()(const Segment<K>\
    \ &s);\n Circle<K> operator()(const Circle<K> &c);\n Polygon<K> operator()(const\
    \ Polygon<K> &p);\n Convex<K> operator()(const Convex<K> &c);\n Affine operator*(const\
    \ Affine &r) const { return {a00 * r.a00 + a01 * r.a10, a00 * r.a01 + a01 * r.a11,\
    \ a10 * r.a00 + a11 * r.a10, a10 * r.a01 + a11 * r.a11, (*this)(r)}; }\n Affine\
    \ &operator*=(const Affine &r) { return *this= *this * r; }\n};\ntemplate <class\
    \ K> Affine<K> translate(const Point<K> &p) { return {1, 0, 0, 1, p}; }\ntemplate\
    \ <class K> Affine<K> rotate(long double theta) {\n K c= cos(theta), s= sin(theta);\n\
    \ return {c, -s, s, c, Point<K>{0, 0}};\n}\ntemplate <class K> Affine<K> rotate(const\
    \ Point<K> &p, long double theta) {\n K c= cos(theta), s= sin(theta);\n return\
    \ {c, -s, s, c, Point<K>{p.x - c * p.x + s * p.y, p.y - s * p.x - c * p.y}};\n\
    }\ntemplate <class K> Affine<K> rotate90(const Point<K> &p) { return {0, -1, 1,\
    \ 0, p - !p}; }\n}\n#line 6 \"src/Geometry/IncrementalConvexHull.hpp\"\nnamespace\
    \ geo {\ntemplate <class K> class IncrementalConvexHull {\n using P= Point<K>;\n\
    \ struct Lower {\n  set<P> S;\n  template <class A, class R> void insert(const\
    \ P &p, const A &ad, const R &rm) {\n   if (where(p) >= 0) return;\n   S.insert(p);\n\
    \   vector<P> l, r;\n   auto st= S.find(p);\n   for (auto it= st; it != S.begin();)\
    \ {\n    if (--it; l.empty()) {\n     l.emplace_back(*it);\n     continue;\n \
    \   }\n    if (sgn(cross(*it - p, l.back() - p)) > 0) break;\n    rm(*it, l.back()),\
    \ l.emplace_back(*it);\n   }\n   for (auto it= st; ++it != S.end();) {\n    if\
    \ (r.empty()) {\n     r.emplace_back(*it);\n     continue;\n    }\n    if (sgn(cross(r.back()\
    \ - p, *it - p)) > 0) break;\n    rm(r.back(), *it), r.emplace_back(*it);\n  \
    \ }\n   if (l.size() > 1) S.erase(next(S.find(l.back())), S.find(p));\n   if (l.size())\
    \ ad(l.back(), p);\n   if (r.size() > 1) S.erase(next(S.find(p)), S.find(r.back()));\n\
    \   if (r.size()) ad(p, r.back());\n   if (l.size() && r.size()) rm(l[0], r[0]);\n\
    \  }\n  int where(const P &p) const {\n   auto r= S.lower_bound(p);\n   if (r\
    \ == S.begin()) return S.size() && *r == p ? 0 : -1;\n   if (r == S.end()) return\
    \ -1;\n   return sgn(cross(*prev(r) - p, *r - p));\n  }\n } L, U;\n size_t m;\n\
    \ K a;\npublic:\n IncrementalConvexHull(): m(0), a(0) {}\n size_t edge_size()\
    \ const { return m; }\n K area() const { return a / 2; }\n // for integer\n K\
    \ area2() const { return a; }\n // +1: in, 0: on, -1: out\n int where(const P\
    \ &p) const {\n  int l= L.where(p), u= U.where(-p);\n  return !l || !u ? 0 : min(l,\
    \ u);\n }\n void insert(const P &p) {\n  auto ad= [&](const P &q, const P &r)\
    \ { a+= cross(q, r), ++m; };\n  auto rm= [&](const P &q, const P &r) { a-= cross(q,\
    \ r), --m; };\n  L.insert(p, ad, rm), U.insert(-p, ad, rm);\n }\n};\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <set>\n#include\
    \ \"src/Geometry/Point.hpp\"\nnamespace geo {\ntemplate <class K> class IncrementalConvexHull\
    \ {\n using P= Point<K>;\n struct Lower {\n  set<P> S;\n  template <class A, class\
    \ R> void insert(const P &p, const A &ad, const R &rm) {\n   if (where(p) >= 0)\
    \ return;\n   S.insert(p);\n   vector<P> l, r;\n   auto st= S.find(p);\n   for\
    \ (auto it= st; it != S.begin();) {\n    if (--it; l.empty()) {\n     l.emplace_back(*it);\n\
    \     continue;\n    }\n    if (sgn(cross(*it - p, l.back() - p)) > 0) break;\n\
    \    rm(*it, l.back()), l.emplace_back(*it);\n   }\n   for (auto it= st; ++it\
    \ != S.end();) {\n    if (r.empty()) {\n     r.emplace_back(*it);\n     continue;\n\
    \    }\n    if (sgn(cross(r.back() - p, *it - p)) > 0) break;\n    rm(r.back(),\
    \ *it), r.emplace_back(*it);\n   }\n   if (l.size() > 1) S.erase(next(S.find(l.back())),\
    \ S.find(p));\n   if (l.size()) ad(l.back(), p);\n   if (r.size() > 1) S.erase(next(S.find(p)),\
    \ S.find(r.back()));\n   if (r.size()) ad(p, r.back());\n   if (l.size() && r.size())\
    \ rm(l[0], r[0]);\n  }\n  int where(const P &p) const {\n   auto r= S.lower_bound(p);\n\
    \   if (r == S.begin()) return S.size() && *r == p ? 0 : -1;\n   if (r == S.end())\
    \ return -1;\n   return sgn(cross(*prev(r) - p, *r - p));\n  }\n } L, U;\n size_t\
    \ m;\n K a;\npublic:\n IncrementalConvexHull(): m(0), a(0) {}\n size_t edge_size()\
    \ const { return m; }\n K area() const { return a / 2; }\n // for integer\n K\
    \ area2() const { return a; }\n // +1: in, 0: on, -1: out\n int where(const P\
    \ &p) const {\n  int l= L.where(p), u= U.where(-p);\n  return !l || !u ? 0 : min(l,\
    \ u);\n }\n void insert(const P &p) {\n  auto ad= [&](const P &q, const P &r)\
    \ { a+= cross(q, r), ++m; };\n  auto rm= [&](const P &q, const P &r) { a-= cross(q,\
    \ r), --m; };\n  L.insert(p, ad, rm), U.insert(-p, ad, rm);\n }\n};\n}"
  dependsOn:
  - src/Geometry/Point.hpp
  isVerificationFile: false
  path: src/Geometry/IncrementalConvexHull.hpp
  requiredBy: []
  timestamp: '2023-09-21 16:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2635.test.cpp
documentation_of: src/Geometry/IncrementalConvexHull.hpp
layout: document
redirect_from:
- /library/src/Geometry/IncrementalConvexHull.hpp
- /library/src/Geometry/IncrementalConvexHull.hpp.html
title: src/Geometry/IncrementalConvexHull.hpp
---
