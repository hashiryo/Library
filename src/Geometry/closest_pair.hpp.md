---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Geometry/closest_pair.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#line 2 \"src/Geometry/Point.hpp\"\n#include <iostream>\n#include\
    \ <fstream>\n#include <iomanip>\n#include <cmath>\n#include <cassert>\nnamespace\
    \ geo {\nusing namespace std;\nstruct Visualizer {\n ofstream ofs;\n Visualizer(string\
    \ s= \"visualize.txt\"): ofs(s) { ofs << fixed << setprecision(10); }\n friend\
    \ Visualizer &operator<<(Visualizer &vis, const string &s) { return vis.ofs <<\
    \ s, vis; }\n};\ntemplate <class K> int sgn(K x) {\n if constexpr (is_floating_point_v<K>)\
    \ {\n  static constexpr K EPS= 1e-9;\n  return x < -EPS ? -1 : x > EPS;\n } else\
    \ return x < 0 ? -1 : x > 0;\n}\ntemplate <class K> K err_floor(K x) {\n K y=\
    \ floor(x);\n if constexpr (is_floating_point_v<K>)\n  if (K z= y + 1, w= x -\
    \ z; 0 <= sgn(w) && sgn(w - 1) < 0) return z;\n return y;\n}\ntemplate <class\
    \ K> K err_ceil(K x) {\n K y= ceil(x);\n if constexpr (is_floating_point_v<K>)\n\
    \  if (K z= y - 1, w= x - z; 0 < sgn(w + 1) && sgn(w) <= 0) return z;\n return\
    \ y;\n}\ntemplate <class K> struct Point {\n K x, y;\n Point(K x= K(), K y= K()):\
    \ x(x), y(y) {}\n Point &operator+=(const Point &p) { return x+= p.x, y+= p.y,\
    \ *this; }\n Point &operator-=(const Point &p) { return x-= p.x, y-= p.y, *this;\
    \ }\n Point &operator*=(K a) { return x*= a, y*= a, *this; }\n Point &operator/=(K\
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
    \ U &b) { return sqrt(dist2(a, b)); }\nenum CCW { COUNTER_CLOCKWISE, CLOCKWISE,\
    \ ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };\nostream &operator<<(ostream &os, CCW\
    \ c) { return os << (c == COUNTER_CLOCKWISE ? \"COUNTER_CLOCKWISE\" : c == CLOCKWISE\
    \ ? \"CLOCKWISE\" : c == ONLINE_BACK ? \"ONLINE_BACK\" : c == ONLINE_FRONT ? \"\
    ONLINE_FRONT\" : \"ON_SEGMENT\"); }\ntemplate <class K> CCW ccw(const Point<K>\
    \ &p0, const Point<K> &p1, const Point<K> &p2) {\n Point a= p1 - p0, b= p2 - p0;\n\
    \ if (int s= sgn(cross(a, b) / norm2(a)); s) return s > 0 ? COUNTER_CLOCKWISE\
    \ : CLOCKWISE;\n if (K d= dot(a, b); sgn(d) < 0) return ONLINE_BACK;\n else return\
    \ sgn(d - norm2(a)) > 0 ? ONLINE_FRONT : ON_SEGMENT;\n}\ntemplate <class K> struct\
    \ Line;\ntemplate <class K> struct Segment;\ntemplate <class K> struct Polygon;\n\
    template <class K> struct Convex;\ntemplate <class K> struct Affine {\n K a00=\
    \ 1, a01= 0, a10= 0, a11= 1;\n Point<K> b;\n Point<K> operator()(const Point<K>\
    \ &p) const { return {a00 * p.x + a01 * p.y + b.x, a10 * p.x + a11 * p.y + b.y};\
    \ }\n Line<K> operator()(const Line<K> &l);\n Segment<K> operator()(const Segment<K>\
    \ &s);\n Polygon<K> operator()(const Polygon<K> &p);\n Convex<K> operator()(const\
    \ Convex<K> &c);\n Affine operator*(const Affine &r) const { return {a00 * r.a00\
    \ + a01 * r.a10, a00 * r.a01 + a01 * r.a11, a10 * r.a00 + a11 * r.a10, a10 * r.a01\
    \ + a11 * r.a11, (*this)(r)}; }\n Affine &operator*=(const Affine &r) { return\
    \ *this= *this * r; }\n};\ntemplate <class K> Affine<K> translate(const Point<K>\
    \ &p) { return {1, 0, 0, 1, p}; }\n}\n#line 5 \"src/Geometry/closest_pair.hpp\"\
    \nnamespace geo {\ntemplate <class K> pair<Point<K>, Point<K>> closest_pair(vector<Point<K>>\
    \ ps) {\n int n= ps.size();\n assert(n >= 2);\n sort(ps.begin(), ps.end(), [](const\
    \ Point<K> &p, const Point<K> &q) { return p.y < q.y; });\n vector<Point<K>> memo(n);\n\
    \ pair<Point<K>, Point<K>> ret= {ps[0], ps[1]};\n K best= dist2(ps[0], ps[1]),\
    \ tmp;\n auto rec= [&](auto &rec, int l, int r) -> void {\n  if (r - l == 1) return;\n\
    \  int m= (l + r) / 2;\n  K y= ps[m].y, d;\n  rec(rec, l, m), rec(rec, m, r),\
    \ inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r);\n  for (int i=\
    \ l, cnt= 0; i < r; ++i) {\n   if (d= ps[i].y - y; d * d >= best) continue;\n\
    \   for (int j= cnt; j--;) {\n    if (d= ps[i].x - memo[j].x, tmp= d * d; tmp\
    \ >= best) break;\n    if (d= ps[i].y - memo[j].y, tmp+= d * d; best > tmp) best=\
    \ tmp, ret= {ps[i], memo[j]};\n   }\n   memo[cnt++]= ps[i];\n  }\n };\n return\
    \ rec(rec, 0, n), ret;\n}\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"src/Geometry/Point.hpp\"\
    \nnamespace geo {\ntemplate <class K> pair<Point<K>, Point<K>> closest_pair(vector<Point<K>>\
    \ ps) {\n int n= ps.size();\n assert(n >= 2);\n sort(ps.begin(), ps.end(), [](const\
    \ Point<K> &p, const Point<K> &q) { return p.y < q.y; });\n vector<Point<K>> memo(n);\n\
    \ pair<Point<K>, Point<K>> ret= {ps[0], ps[1]};\n K best= dist2(ps[0], ps[1]),\
    \ tmp;\n auto rec= [&](auto &rec, int l, int r) -> void {\n  if (r - l == 1) return;\n\
    \  int m= (l + r) / 2;\n  K y= ps[m].y, d;\n  rec(rec, l, m), rec(rec, m, r),\
    \ inplace_merge(ps.begin() + l, ps.begin() + m, ps.begin() + r);\n  for (int i=\
    \ l, cnt= 0; i < r; ++i) {\n   if (d= ps[i].y - y; d * d >= best) continue;\n\
    \   for (int j= cnt; j--;) {\n    if (d= ps[i].x - memo[j].x, tmp= d * d; tmp\
    \ >= best) break;\n    if (d= ps[i].y - memo[j].y, tmp+= d * d; best > tmp) best=\
    \ tmp, ret= {ps[i], memo[j]};\n   }\n   memo[cnt++]= ps[i];\n  }\n };\n return\
    \ rec(rec, 0, n), ret;\n}\n}"
  dependsOn:
  - src/Geometry/Point.hpp
  isVerificationFile: false
  path: src/Geometry/closest_pair.hpp
  requiredBy: []
  timestamp: '2023-10-02 19:27:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
documentation_of: src/Geometry/closest_pair.hpp
layout: document
title: "\u6700\u8FD1\u70B9\u5BFE"
---

分割統治+枝刈り
## 関数

|名前|概要|計算量|
|---|---|---|
|`closest_pair(ps)`| 引数は `vector<Point<K>>`. <br>点群のペアのうち2点間の距離が最も近いもの (最近点対) を返す. |$\mathcal{O}(n \log n)$ <br> ただし引数の点の個数を $n$ とした|
