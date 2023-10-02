---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/SegmentArrangement.hpp
    title: src/Geometry/SegmentArrangement.hpp
  - icon: ':question:'
    path: src/Geometry/intersection_area.hpp
    title: "\u5186\u3068\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0269.test.cpp
    title: test/aoj/0269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0273.test.cpp
    title: test/aoj/0273.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0356.test.cpp
    title: test/aoj/0356.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1033.test.cpp
    title: test/aoj/1033.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1047.test.cpp
    title: test/aoj/1047.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1050.test.cpp
    title: test/aoj/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1066.test.cpp
    title: test/aoj/1066.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1107.test.cpp
    title: test/aoj/1107.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1136.test.cpp
    title: test/aoj/1136.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1198.test.cpp
    title: test/aoj/1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1226.test.cpp
    title: test/aoj/1226.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2402.test.cpp
    title: test/aoj/2402.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2448.test.cpp
    title: test/aoj/2448.test.cpp
  - icon: ':x:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':x:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  - icon: ':x:'
    path: test/yosupo/sort_points_by_argument.test.cpp
    title: test/yosupo/sort_points_by_argument.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Geometry/angle.hpp\"\n#include <vector>\n#line 2 \"\
    src/Geometry/Point.hpp\"\n#include <iostream>\n#include <fstream>\n#include <iomanip>\n\
    #include <cmath>\n#include <cassert>\nnamespace geo {\nusing namespace std;\n\
    struct Visualizer {\n ofstream ofs;\n Visualizer(string s= \"visualize.txt\"):\
    \ ofs(s) { ofs << fixed << setprecision(10); }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const string &s) { return vis.ofs << s, vis; }\n};\ntemplate <class K>\
    \ int sgn(K x) {\n if constexpr (is_floating_point_v<K>) {\n  static constexpr\
    \ K EPS= 1e-9;\n  return x < -EPS ? -1 : x > EPS;\n } else return x < 0 ? -1 :\
    \ x > 0;\n}\ntemplate <class K> K err_floor(K x) {\n K y= floor(x);\n if constexpr\
    \ (is_floating_point_v<K>)\n  if (K z= y + 1, w= x - z; 0 <= sgn(w) && sgn(w -\
    \ 1) < 0) return z;\n return y;\n}\ntemplate <class K> K err_ceil(K x) {\n K y=\
    \ ceil(x);\n if constexpr (is_floating_point_v<K>)\n  if (K z= y - 1, w= x - z;\
    \ 0 < sgn(w + 1) && sgn(w) <= 0) return z;\n return y;\n}\ntemplate <class K>\
    \ struct Point {\n K x, y;\n Point(K x= K(), K y= K()): x(x), y(y) {}\n Point\
    \ &operator+=(const Point &p) { return x+= p.x, y+= p.y, *this; }\n Point &operator-=(const\
    \ Point &p) { return x-= p.x, y-= p.y, *this; }\n Point &operator*=(K a) { return\
    \ x*= a, y*= a, *this; }\n Point &operator/=(K a) { return x/= a, y/= a, *this;\
    \ }\n Point operator+(const Point &p) const { return {x + p.x, y + p.y}; }\n Point\
    \ operator-(const Point &p) const { return {x - p.x, y - p.y}; }\n Point operator*(K\
    \ a) const { return {x * a, y * a}; }\n Point operator/(K a) const { return {x\
    \ / a, y / a}; }\n friend Point operator*(K a, const Point &p) { return {a * p.x,\
    \ a * p.y}; }\n Point operator-() const { return {-x, -y}; }\n bool operator<(const\
    \ Point &p) const {\n  int s= sgn(x - p.x);\n  return s ? s < 0 : sgn(y - p.y)\
    \ < 0;\n }\n bool operator>(const Point &p) const { return p < *this; }\n bool\
    \ operator<=(const Point &p) const { return !(p < *this); }\n bool operator>=(const\
    \ Point &p) const { return !(*this < p); }\n bool operator==(const Point &p) const\
    \ { return !sgn(x - p.x) && !sgn(y - p.y); }\n bool operator!=(const Point &p)\
    \ const { return sgn(x - p.x) || sgn(y - p.y); }\n Point operator!() const { return\
    \ {-y, x}; }  // rotate 90 degree\n friend istream &operator>>(istream &is, Point\
    \ &p) { return is >> p.x >> p.y; }\n friend ostream &operator<<(ostream &os, const\
    \ Point &p) { return os << \"(\" << p.x << \", \" << p.y << \")\"; }\n friend\
    \ Visualizer &operator<<(Visualizer &vis, const Point &p) { return vis.ofs <<\
    \ p.x << \" \" << p.y << \"\\n\", vis; }\n};\ntemplate <class K> K dot(const Point<K>\
    \ &p, const Point<K> &q) { return p.x * q.x + p.y * q.y; }\n// left turn: > 0,\
    \ right turn: < 0\ntemplate <class K> K cross(const Point<K> &p, const Point<K>\
    \ &q) { return p.x * q.y - p.y * q.x; }\ntemplate <class K> K norm2(const Point<K>\
    \ &p) { return dot(p, p); }\ntemplate <class K> long double norm(const Point<K>\
    \ &p) { return sqrt(norm2(p)); }\ntemplate <class K> K dist2(const Point<K> &p,\
    \ const Point<K> &q) { return norm2(p - q); }\ntemplate <class T, class U> long\
    \ double dist(const T &a, const U &b) { return sqrt(dist2(a, b)); }\nenum CCW\
    \ { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };\nostream\
    \ &operator<<(ostream &os, CCW c) { return os << (c == COUNTER_CLOCKWISE ? \"\
    COUNTER_CLOCKWISE\" : c == CLOCKWISE ? \"CLOCKWISE\" : c == ONLINE_BACK ? \"ONLINE_BACK\"\
    \ : c == ONLINE_FRONT ? \"ONLINE_FRONT\" : \"ON_SEGMENT\"); }\ntemplate <class\
    \ K> CCW ccw(const Point<K> &p0, const Point<K> &p1, const Point<K> &p2) {\n Point\
    \ a= p1 - p0, b= p2 - p0;\n if (int s= sgn(cross(a, b) / norm2(a)); s) return\
    \ s > 0 ? COUNTER_CLOCKWISE : CLOCKWISE;\n if (K d= dot(a, b); sgn(d) < 0) return\
    \ ONLINE_BACK;\n else return sgn(d - norm2(a)) > 0 ? ONLINE_FRONT : ON_SEGMENT;\n\
    }\ntemplate <class K> struct Line;\ntemplate <class K> struct Segment;\ntemplate\
    \ <class K> struct Polygon;\ntemplate <class K> struct Convex;\ntemplate <class\
    \ K> struct Affine {\n K a00= 1, a01= 0, a10= 0, a11= 1;\n Point<K> b;\n Point<K>\
    \ operator()(const Point<K> &p) const { return {a00 * p.x + a01 * p.y + b.x, a10\
    \ * p.x + a11 * p.y + b.y}; }\n Line<K> operator()(const Line<K> &l);\n Segment<K>\
    \ operator()(const Segment<K> &s);\n Polygon<K> operator()(const Polygon<K> &p);\n\
    \ Convex<K> operator()(const Convex<K> &c);\n Affine operator*(const Affine &r)\
    \ const { return {a00 * r.a00 + a01 * r.a10, a00 * r.a01 + a01 * r.a11, a10 *\
    \ r.a00 + a11 * r.a10, a10 * r.a01 + a11 * r.a11, (*this)(r)}; }\n Affine &operator*=(const\
    \ Affine &r) { return *this= *this * r; }\n};\ntemplate <class K> Affine<K> translate(const\
    \ Point<K> &p) { return {1, 0, 0, 1, p}; }\n}\n#line 4 \"src/Geometry/angle.hpp\"\
    \nnamespace geo {\nlong double radian_to_degree(long double r) { return r * 180.0\
    \ / M_PI; }\nlong double degree_to_radian(long double d) { return d * M_PI / 180.0;\
    \ }\nlong double normalize_radian(long double r) { return r= fmod(r + M_PI, 2\
    \ * M_PI), r > 0 ? r - M_PI : r + M_PI; }\ntemplate <class K> long double angle(const\
    \ Point<K> &p) { return atan2(p.y, p.x); }\ntemplate <class K> long double angle(const\
    \ Point<K> &p, const Point<K> &q) { return atan2(cross(p, q), dot(p, q)); }\n\
    template <class K> Affine<K> rotate(long double theta) {\n K c= cos(theta), s=\
    \ sin(theta);\n return {c, -s, s, c, Point<K>{0, 0}};\n}\ntemplate <class K> Affine<K>\
    \ rotate(const Point<K> &p, long double theta) {\n K c= cos(theta), s= sin(theta);\n\
    \ return {c, -s, s, c, Point<K>{p.x - c * p.x + s * p.y, p.y - s * p.x - c * p.y}};\n\
    }\ntemplate <class K> Affine<K> rotate90(const Point<K> &p) { return {0, -1, 1,\
    \ 0, p - !p}; }\n// (-PI,PI], counter-clockwise\ntemplate <class K> class AngleComp\
    \ {\n using P= Point<K>;\n static int quad(const P &p) {\n  if (int s= sgn(p.y);\
    \ s) return s;\n  return sgn(p.x) < 0 ? 2 : 0;\n }\npublic:\n bool operator()(const\
    \ P &p, const P &q) const {\n  if (int a= quad(p), b= quad(q); a != b) return\
    \ a < b;\n  return cross(p, q) > 0;\n }\n};\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"src/Geometry/Point.hpp\"\nnamespace\
    \ geo {\nlong double radian_to_degree(long double r) { return r * 180.0 / M_PI;\
    \ }\nlong double degree_to_radian(long double d) { return d * M_PI / 180.0; }\n\
    long double normalize_radian(long double r) { return r= fmod(r + M_PI, 2 * M_PI),\
    \ r > 0 ? r - M_PI : r + M_PI; }\ntemplate <class K> long double angle(const Point<K>\
    \ &p) { return atan2(p.y, p.x); }\ntemplate <class K> long double angle(const\
    \ Point<K> &p, const Point<K> &q) { return atan2(cross(p, q), dot(p, q)); }\n\
    template <class K> Affine<K> rotate(long double theta) {\n K c= cos(theta), s=\
    \ sin(theta);\n return {c, -s, s, c, Point<K>{0, 0}};\n}\ntemplate <class K> Affine<K>\
    \ rotate(const Point<K> &p, long double theta) {\n K c= cos(theta), s= sin(theta);\n\
    \ return {c, -s, s, c, Point<K>{p.x - c * p.x + s * p.y, p.y - s * p.x - c * p.y}};\n\
    }\ntemplate <class K> Affine<K> rotate90(const Point<K> &p) { return {0, -1, 1,\
    \ 0, p - !p}; }\n// (-PI,PI], counter-clockwise\ntemplate <class K> class AngleComp\
    \ {\n using P= Point<K>;\n static int quad(const P &p) {\n  if (int s= sgn(p.y);\
    \ s) return s;\n  return sgn(p.x) < 0 ? 2 : 0;\n }\npublic:\n bool operator()(const\
    \ P &p, const P &q) const {\n  if (int a= quad(p), b= quad(q); a != b) return\
    \ a < b;\n  return cross(p, q) > 0;\n }\n};\n}"
  dependsOn:
  - src/Geometry/Point.hpp
  isVerificationFile: false
  path: src/Geometry/angle.hpp
  requiredBy:
  - src/Geometry/SegmentArrangement.hpp
  - src/Geometry/intersection_area.hpp
  timestamp: '2023-10-02 19:27:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1198.test.cpp
  - test/aoj/0356.test.cpp
  - test/aoj/0273.test.cpp
  - test/aoj/1226.test.cpp
  - test/aoj/1107.test.cpp
  - test/aoj/1136.test.cpp
  - test/aoj/1050.test.cpp
  - test/aoj/2402.test.cpp
  - test/aoj/1047.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/1033.test.cpp
  - test/aoj/0269.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/1066.test.cpp
  - test/aoj/2448.test.cpp
  - test/yosupo/sort_points_by_argument.test.cpp
documentation_of: src/Geometry/angle.hpp
layout: document
title: "\u89D2\u5EA6\u30FB\u56DE\u8EE2\u95A2\u9023"
---

## 関数

|名前|概要|
|---|---|
|`radian_to_degree(r)`|ラジアンの値を度数に変換したものを返す.|
|`degree_to_radian(d)`|度数の値からラジアンに変換したものを返す.|
|`normalize_radian(r)`|ラジアンの値を $(-\pi,\pi\rbrack$ の区間に収まるように正規化したものを返す.|
|`angle(p)`|ベクトル $\boldsymbol{p}$ の偏角を返す.|
|`angle(p,q)`|ベクトル $\boldsymbol{p}$ からベクトル $\boldsymbol{q}$ への偏角を返す. |
|`rotate(theta)`| 原点を中心に角度 $\theta$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`.|
|`rotate(p, theta)`| 点 $\boldsymbol{p}$ を中心に角度 $\theta$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`.|
|`rotate90(p)`| 点 $\boldsymbol{p}$ を中心に $\pi/2$ だけ回転する変換を返す. <br>返り値の型は `Affine<K>`.|

## `AngleComp<K>` クラス

`Point<K>` を偏角の大小で比較する関数オブジェクト.\
偏角を $(-\pi,\pi\rbrack$ に正規化した上での大小比較する.\
ただし $\boldsymbol{0}=(0,0)$ の偏角は $0$ とする.\
`K` が整数でも動く \
主に偏角ソートで使う.
