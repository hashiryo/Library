---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/angle.hpp
    title: "\u89D2\u5EA6\u30FB\u56DE\u8EE2\u95A2\u9023"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/yosupo/sort_points_by_argument.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#line 3 \"src/Geometry/Point.hpp\"\
    \n#include <fstream>\n#include <iomanip>\n#include <cmath>\n#include <cassert>\n\
    namespace geo {\nusing namespace std;\nstruct Visualizer {\n ofstream ofs;\n Visualizer(string\
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
    \ int s;\n if constexpr (is_floating_point_v<K>) s= sgn(sgn(cross(a, b) / sqrt(norm2(a)\
    \ * norm2(b))));\n else s= sgn(cross(a, b));\n if (s) return s > 0 ? COUNTER_CLOCKWISE\
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
    \ &p) { return {1, 0, 0, 1, p}; }\n}\n#line 4 \"src/Geometry/angle.hpp\"\nnamespace\
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
    \ a < b;\n  return cross(p, q) > 0;\n }\n};\n}\n#line 6 \"test/yosupo/sort_points_by_argument.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using namespace geo;\n int N;\n cin >> N;\n vector<Point<long long>> ps(N);\n\
    \ for (int i= 0; i < N; ++i) cin >> ps[i];\n sort(ps.begin(), ps.end(), AngleComp<long\
    \ long>());\n for (auto &p: ps) cout << p.x << \" \" << p.y << \"\\n\";\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Geometry/angle.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using namespace geo;\n int N;\n cin >> N;\n vector<Point<long long>> ps(N);\n\
    \ for (int i= 0; i < N; ++i) cin >> ps[i];\n sort(ps.begin(), ps.end(), AngleComp<long\
    \ long>());\n for (auto &p: ps) cout << p.x << \" \" << p.y << \"\\n\";\n return\
    \ 0;\n}"
  dependsOn:
  - src/Geometry/angle.hpp
  - src/Geometry/Point.hpp
  isVerificationFile: true
  path: test/yosupo/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2023-10-10 00:58:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sort_points_by_argument.test.cpp
- /verify/test/yosupo/sort_points_by_argument.test.cpp.html
title: test/yosupo/sort_points_by_argument.test.cpp
---
