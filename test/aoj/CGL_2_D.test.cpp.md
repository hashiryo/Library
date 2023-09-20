---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/Line.hpp
    title: src/Geometry/Line.hpp
  - icon: ':question:'
    path: src/Geometry/Point.hpp
    title: src/Geometry/Point.hpp
  - icon: ':question:'
    path: src/Geometry/Segment.hpp
    title: src/Geometry/Segment.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
  bundledCode: "#line 1 \"test/aoj/CGL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#line\
    \ 2 \"src/Geometry/Line.hpp\"\n#include <vector>\n#line 3 \"src/Geometry/Point.hpp\"\
    \n#include <fstream>\n#line 5 \"src/Geometry/Point.hpp\"\n#include <cmath>\n#include\
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
    template <class K> struct Point {\n K x= 0, y= 0;\n Point &operator+=(const Point\
    \ &p) { return x+= p.x, y+= p.y, *this; }\n Point &operator-=(const Point &p)\
    \ { return x-= p.x, y-= p.y, *this; }\n Point &operator*=(K a) { return x*= a,\
    \ y*= a, *this; }\n Point &operator/=(K a) { return x/= a, y/= a, *this; }\n Point\
    \ operator+(const Point &p) const { return {x + p.x, y + p.y}; }\n Point operator-(const\
    \ Point &p) const { return {x - p.x, y - p.y}; }\n Point operator*(K a) const\
    \ { return {x * a, y * a}; }\n Point operator/(K a) const { return {x / a, y /\
    \ a}; }\n friend Point operator*(K a, const Point &p) { return {a * p.x, a * p.y};\
    \ }\n Point operator-() const { return {-x, -y}; }\n bool operator<(const Point\
    \ &p) const {\n  int s= sgn(x - p.x);\n  return s ? s < 0 : sgn(y - p.y) < 0;\n\
    \ }\n bool operator>(const Point &p) const { return p < *this; }\n bool operator<=(const\
    \ Point &p) const { return !(p < *this); }\n bool operator>=(const Point &p) const\
    \ { return !(*this < p); }\n bool operator==(const Point &p) const { return !sgn(x\
    \ - p.x) && !sgn(y - p.y); }\n bool operator!=(const Point &p) const { return\
    \ sgn(x - p.x) || sgn(y - p.y); }\n Point operator!() const { return {-y, x};\
    \ }  // rotate 90 degree\n friend istream &operator>>(istream &is, Point &p) {\
    \ return is >> p.x >> p.y; }\n friend ostream &operator<<(ostream &os, const Point\
    \ &p) { return os << \"(\" << p.x << \", \" << p.y << \")\"; }\n friend Visualizer\
    \ &operator<<(Visualizer &vis, const Point &p) { return vis.ofs << p.x << \" \"\
    \ << p.y << \"\\n\", vis; }\n};\ntemplate <class K> K dot(const Point<K> &p, const\
    \ Point<K> &q) { return p.x * q.x + p.y * q.y; }\n// left turn: > 0, right turn:\
    \ < 0\ntemplate <class K> K cross(const Point<K> &p, const Point<K> &q) { return\
    \ p.x * q.y - p.y * q.x; }\ntemplate <class K> K norm(const Point<K> &p) { return\
    \ dot(p, p); }\ntemplate <class K> long double abs(const Point<K> &p) { return\
    \ sqrt(norm(p)); }\ntemplate <class K> K dist2(const Point<K> &p, const Point<K>\
    \ &q) { return norm(p - q); }\ntemplate <class T, class U> long double dist(const\
    \ T &a, const U &b) { return sqrt(dist2(a, b)); }\ntemplate <class K> long double\
    \ angle(const Point<K> &p) { return atan2(p.y, p.x); }\ntemplate <class K> long\
    \ double angle(const Point<K> &p, const Point<K> &q) { return atan2(cross(p, q),\
    \ dot(p, q)); }\nenum CCW { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT,\
    \ ON_SEGMENT };\nostream &operator<<(ostream &os, CCW c) { return os << (c ==\
    \ COUNTER_CLOCKWISE ? \"COUNTER_CLOCKWISE\" : c == CLOCKWISE ? \"CLOCKWISE\" :\
    \ c == ONLINE_BACK ? \"ONLINE_BACK\" : c == ONLINE_FRONT ? \"ONLINE_FRONT\" :\
    \ \"ON_SEGMENT\"); }\ntemplate <class K> CCW ccw(const Point<K> &p0, const Point<K>\
    \ &p1, const Point<K> &p2) {\n Point a= p1 - p0, b= p2 - p0;\n if (int s= sgn(cross(a,\
    \ b)); s) return s > 0 ? COUNTER_CLOCKWISE : CLOCKWISE;\n if (K d= dot(a, b);\
    \ sgn(d) < 0) return ONLINE_BACK;\n else return sgn(d - norm(a)) > 0 ? ONLINE_FRONT\
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
    \ 0, p - !p}; }\n}\n#line 4 \"src/Geometry/Line.hpp\"\nnamespace geo {\ntemplate\
    \ <class K> struct Line {\n using P= Point<K>;\n P p, d;  // p+td\n Line() {}\n\
    \ // p + td\n Line(const P &p, const P &d): p(p), d(d) { assert(sgn(norm(d)));\
    \ }\n // ax+by+c=0 ................. ax+by+c>0: left, ax+by+c=0: on, ax+by+c<0:\
    \ right\n Line(K a, K b, K c) {\n  int sa= sgn(a), sb= sgn(b);\n  assert(sa ||\
    \ sb);\n  if (sb) p= {0, -c / b}, d= sb > 0 ? P{1, -a / b} : P{-1, a / b};\n \
    \ else p= {-c / a, 0}, d= {0, K(sa > 0 ? -1 : 1)};\n }\n bool operator==(const\
    \ Line &l) const { return !sgn(cross(d, l.d)) && !where(l.p); }\n bool operator!=(const\
    \ Line &l) const { return sgn(cross(d, l.d)) || where(l.p); }\n // +1: left, 0:\
    \ on, -1: right\n int where(const P &q) const { return sgn(cross(d, q - p)); }\n\
    \ P project(const P &q) const { return p + dot(q - p, d) / norm(d) * d; }\n //\
    \ return  a,b,c of ax+by+c=0\n tuple<K, K, K> coef() const { return make_tuple(-d.y,\
    \ d.x, cross(p, d)); }\n friend ostream &operator<<(ostream &os, const Line &l)\
    \ { return os << l.p << \" + t\" << l.d; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Line &l) {\n  auto [a, b, c]= l.coef();\n  return vis.ofs << \"\
    Line \" << a << \" \" << b << \" \" << c << '\\n', vis;\n }\n};\n// p + t(q-p)\n\
    template <class K> Line<K> line_through(const Point<K> &p, const Point<K> &q)\
    \ { return Line(p, q - p); }\ntemplate <class K> bool is_parallel(const Line<K>\
    \ &l, const Line<K> &m) { return !sgn(cross(l.d, m.d)); }\ntemplate <class K>\
    \ bool is_orthogonal(const Line<K> &l, const Line<K> &m) { return !sgn(dot(l.d,\
    \ m.d)); }\n// 1 : properly crossing, 0 : disjoint parallel, 2 : same line\ntemplate\
    \ <class K> vector<Point<K>> cross_points(const Line<K> &l, const Line<K> &m)\
    \ {\n K a= cross(m.d, l.d), b= cross(l.p - m.p, l.d);\n if (sgn(a)) return {m.p\
    \ + b / a * m.d};  // properly crossing\n if (sgn(b)) return {};             \
    \      // disjoint parallel\n return {m.p, m.p + m.d};                 // same\
    \ line\n}\n// perpendicular bisector ............ p on leftside\ntemplate <class\
    \ K> Line<K> bisector(const Point<K> &p, const Point<K> &q) { return Line((p +\
    \ q) / 2, !(q - p)); }\n// angle bisector ........... parallel -> 1 line, non-parallel\
    \ -> 2 lines\ntemplate <class K> vector<Line<K>> bisector(const Line<K> &l, const\
    \ Line<K> &m) {\n auto cp= cross_points(l, m);\n if (cp.size() != 1) return {Line((l.p\
    \ + m.p) / 2, l.d)};\n auto d= l.d / abs(l.d) + m.d / abs(m.d);\n return {Line(cp[0],\
    \ d), Line(cp[0], !d)};\n}\ntemplate <class K> K dist2(const Line<K> &l, const\
    \ Point<K> &p) {\n K a= cross(l.d, p - l.p);\n return a * a / norm(l.d);\n}\n\
    template <class K> K dist2(const Point<K> &p, const Line<K> &l) { return dist2(l,\
    \ p); }\ntemplate <class K> K dist2(const Line<K> &l, const Line<K> &m) { return\
    \ is_parallel(l, m) ? dist2(l, m.p) : 0; }\ntemplate <class K> long double angle(const\
    \ Line<K> &l) { return angle(l.d); }\ntemplate <class K> long double angle(const\
    \ Line<K> &l, const Line<K> &m) { return angle(l.d, m.d); }\ntemplate <class K>\
    \ Affine<K> reflect(const Line<K> &l) {\n K a= l.d.x * l.d.x, b= l.d.x * l.d.y\
    \ * 2, c= l.d.y * l.d.y, d= a + c;\n a/= d, b/= d, c/= d, d= a - c;\n return {d,\
    \ b, b, -d, Point<K>{c * 2 * l.p.x - b * l.p.y, a * 2 * l.p.y - b * l.p.x}};\n\
    }\ntemplate <class K> Line<K> Affine<K>::operator()(const Line<K> &l) { return\
    \ line_through((*this)(l.p), (*this)(l.p + l.d)); }\n}\n#line 3 \"src/Geometry/Segment.hpp\"\
    \nnamespace geo {\ntemplate <class K> struct Segment {\n using P= Point<K>;\n\
    \ P p, q;\n Segment() {}\n Segment(const P &p, const P &q): p(p), q(q) {}\n //\
    \ do not consider the direction\n bool operator==(const Segment &s) const { return\
    \ (p == s.p && q == s.q) || (p == s.q && q == s.p); }\n bool operator!=(const\
    \ Segment &s) const { return !(*this == s); }\n bool is_on(const P &r) const {\
    \ return ccw(p, q, r) == ON_SEGMENT; }\n P &operator[](int i) { return i ? q :\
    \ p; }\n const P &operator[](int i) const { return i ? q : p; }\n long double\
    \ length() const { return dist(p, q); }\n P closest_point(const P &r) const {\n\
    \  P d= q - p;\n  K a= dot(r - p, d), b;\n  return sgn(a) > 0 ? sgn(a - (b= norm(d)))\
    \ < 0 ? p + a / b * d : q : p;\n }\n friend ostream &operator<<(ostream &os, const\
    \ Segment &s) { return os << s.p << \"---\" << s.q; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Segment &s) { return vis.ofs << \"Segment \" << s.p1 << \" \" <<\
    \ s.p2 << '\\n', vis; }\n};\n// 1: properly crossing, 0: no intersect, 2: same\
    \ line\ntemplate <class K> vector<Point<K>> cross_points(const Segment<K> &s,\
    \ const Line<K> &l) {\n Point d= s.q - s.p;\n K a= cross(d, l.d), b= cross(l.p\
    \ - s.p, l.d);\n if (sgn(a)) {\n  if (b/= a; sgn(b) < 0 || sgn(b - 1) > 0) return\
    \ {};  // no intersect\n  else return {s.p + b * d};                         \
    \  // properly crossing}\n }\n if (sgn(b)) return {};  // disjoint parallel\n\
    \ return {s.p, s.q};      // same line\n}\ntemplate <class K> vector<Point<K>>\
    \ cross_points(const Line<K> &l, const Segment<K> &s) { return cross_points(s,\
    \ l); }\n// 2: same line, 0: no intersect, 1: ...\ntemplate <class K> vector<Point<K>>\
    \ cross_points(const Segment<K> &s, const Segment<K> &t) {\n Point d= s.q - s.p,\
    \ e= t.q - t.p;\n K a= cross(d, e), b= cross(t.p - s.p, e);\n if (sgn(a)) {\n\
    \  if (b/= a; sgn(b) < 0 || sgn(b - 1) > 0) return {};                       //\
    \ no intersect\n  if (b= cross(d, s.p - t.p) / a; sgn(b) < 0 || sgn(b - 1) > 0)\
    \ return {};  // no intersect\n  return {t.p + b * e};                       \
    \                              // properly crossing\n }\n if (sgn(b)) return {};\
    \  // disjoint parallel\n vector<Point<K>> ps;    // same line\n auto insert_if_possible=\
    \ [&](const Point<K> &p) {\n  for (auto q: ps)\n   if (p == q) return;\n  ps.emplace_back(p);\n\
    \ };\n if (sgn(dot(t.p - s.p, t.q - s.p)) <= 0) insert_if_possible(s.p);\n if\
    \ (sgn(dot(t.p - s.q, t.q - s.q)) <= 0) insert_if_possible(s.q);\n if (sgn(dot(s.p\
    \ - t.p, s.q - t.p)) <= 0) insert_if_possible(t.p);\n if (sgn(dot(s.p - t.q, s.q\
    \ - t.q)) <= 0) insert_if_possible(t.q);\n return ps;\n}\nenum INTERSECTION {\
    \ CROSSING, TOUCHING, DISJOINT, OVERLAP };\nostream &operator<<(ostream &os, INTERSECTION\
    \ i) { return os << (i == CROSSING ? \"CROSSING\" : i == TOUCHING ? \"TOUCHING\"\
    \ : i == DISJOINT ? \"DISJOINT\" : \"OVERLAP\"); }\ntemplate <class K> INTERSECTION\
    \ intersection(const Segment<K> &s, const Segment<K> &t) {\n auto cp= cross_points(s,\
    \ t);\n return cp.size() == 0 ? DISJOINT : cp.size() == 2 ? OVERLAP : cp[0] ==\
    \ s.p || cp[0] == s.q || cp[0] == t.p || cp[0] == t.q ? TOUCHING : CROSSING;\n\
    }\ntemplate <class K> K dist2(const Segment<K> &s, const Point<K> &p) { return\
    \ dist2(p, s.closest_point(p)); }\ntemplate <class K> K dist2(const Point<K> &p,\
    \ const Segment<K> &s) { return dist2(s, p); }\ntemplate <class K> K dist2(const\
    \ Segment<K> &s, const Line<K> &l) { return cross_points(s, l).size() ? 0 : min(dist2(s.p,\
    \ l), dist2(s.q, l)); }\ntemplate <class K> K dist2(const Line<K> &l, const Segment<K>\
    \ &s) { return dist2(s, l); }\ntemplate <class K> K dist2(const Segment<K> &s,\
    \ const Segment<K> &t) { return cross_points(s, t).size() ? 0 : min({dist2(s,\
    \ t.p), dist2(s, t.q), dist2(t, s.p), dist2(t, s.q)}); }\ntemplate <class K> Segment<K>\
    \ Affine<K>::operator()(const Segment<K> &s) { return {(*this)(s.p), (*this)(s.q)};\
    \ }\n}\n#line 6 \"test/aoj/CGL_2_D.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace geo;\n cout\
    \ << fixed << setprecision(12);\n int q;\n cin >> q;\n while (q--) {\n  Segment<Point<long\
    \ double>> s, t;\n  cin >> s.p >> s.q >> t.p >> t.q;\n  cout << dist(s, t) <<\
    \ '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ \"src/Geometry/Segment.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n using namespace geo;\n cout << fixed << setprecision(12);\n\
    \ int q;\n cin >> q;\n while (q--) {\n  Segment<Point<long double>> s, t;\n  cin\
    \ >> s.p >> s.q >> t.p >> t.q;\n  cout << dist(s, t) << '\\n';\n }\n return 0;\n\
    }"
  dependsOn:
  - src/Geometry/Segment.hpp
  - src/Geometry/Line.hpp
  - src/Geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_2_D.test.cpp
  requiredBy: []
  timestamp: '2023-09-20 15:31:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_D.test.cpp
- /verify/test/aoj/CGL_2_D.test.cpp.html
title: test/aoj/CGL_2_D.test.cpp
---
