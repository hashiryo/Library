---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/!geometry_temp.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
  bundledCode: "#line 1 \"test/aoj/CGL_4_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#line\
    \ 2 \"src/Geometry/!geometry_temp.hpp\"\n#include <bits/stdc++.h>\n/**\n * @title\
    \ \u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\n * @category \u5E7E\u4F55\n */\n\n// BEGIN\
    \ CUT HERE\n\nnamespace geometry {\n\nusing Real = long double;\nint sgn(Real\
    \ x) {\n  static constexpr Real EPS = 1e-8;\n  return x < -EPS ? -1 : x > +EPS\
    \ ? 1 : 0;\n}\nconst Real PI = std::acos(-1.0);\nReal radian_to_degree(Real r)\
    \ { return (r * 180.0 / PI); }\nReal degree_to_radian(Real d) { return (d * PI\
    \ / 180.0); }\nenum {\n  COUNTER_CLOCKWISE = +1,\n  CLOCKWISE = -1,\n  ONLINE_BACK\
    \ = +2,\n  ONLINE_FRONT = -2,\n  ON_SEGMENT = 0\n};\nenum { ON = 0, LEFT = +1,\
    \ RIGHT = -1, IN = +2, OUT = -2 };\nenum { DISJOINT = 0, TOUCH = 1, CROSSING =\
    \ 2, OVERLAP = 3 };\n//-----------------------------------------------------------------------------\n\
    // Point\n//-----------------------------------------------------------------------------\n\
    struct Point {\n  Real x, y;\n  Point &operator+=(Point p) { return x += p.x,\
    \ y += p.y, *this; }\n  Point &operator-=(Point p) { return x -= p.x, y -= p.y,\
    \ *this; }\n  Point &operator*=(Real a) { return x *= a, y *= a, *this; }\n  Point\
    \ &operator/=(Real a) { return *this *= (1.0 / a); }\n  Point operator-() const\
    \ { return {-x, -y}; }\n  bool operator<(Point p) const {\n    return sgn(x -\
    \ p.x) ? sgn(x - p.x) < 0 : sgn(y - p.y) < 0;\n  }\n};\nbool operator==(Point\
    \ p, Point q) { return !(p < q) && !(q < p); }\nbool operator!=(Point p, Point\
    \ q) { return p < q || q < p; }\nbool operator<=(Point p, Point q) { return !(q\
    \ < p); }\nPoint operator+(Point p, Point q) { return p += q; }\nPoint operator-(Point\
    \ p, Point q) { return p -= q; }\nPoint operator*(Real a, Point p) { return p\
    \ *= a; }\nPoint operator*(Point p, Real a) { return p *= a; }\nPoint operator/(Point\
    \ p, Real a) { return p /= a; }\nReal dot(Point p, Point q) { return p.x * q.x\
    \ + p.y * q.y; }\nReal cross(Point p, Point q) { return p.x * q.y - p.y * q.x;\
    \ }  // left turn > 0\nReal norm2(Point p) { return dot(p, p); }\nReal norm(Point\
    \ p) { return std::sqrt(norm2(p)); }\nReal arg(Point p) { return std::atan2(p.y,\
    \ p.x); }\nReal dist(Point p, Point q) { return norm(p - q); }\nReal arg(Point\
    \ p, Point q) { return std::atan2(cross(p, q), dot(p, q)); }\nPoint orth(Point\
    \ p) { return {-p.y, p.x}; }\nPoint rotate(Point p, Real theta) {\n  return {std::cos(theta)\
    \ * p.x - std::sin(theta) * p.y,\n          std::sin(theta) * p.x + std::cos(theta)\
    \ * p.y};\n}\nstd::istream &operator>>(std::istream &is, Point &p) {\n  return\
    \ is >> p.x >> p.y, is;\n}\nstd::ostream &operator<<(std::ostream &os, Point p)\
    \ {\n  return os << p.x << \" \" << p.y, os;\n}\nint ccw(Point p0, Point p1, Point\
    \ p2) {\n  Point a = p1 - p0, b = p2 - p0;\n  if (sgn(cross(a, b)) > 0) return\
    \ COUNTER_CLOCKWISE;\n  if (sgn(cross(a, b)) < 0) return CLOCKWISE;\n  if (sgn(dot(a,\
    \ b)) < 0) return ONLINE_BACK;\n  if (norm2(a) < norm2(b)) return ONLINE_FRONT;\n\
    \  return ON_SEGMENT;\n}\n//-----------------------------------------------------------------------------\n\
    // Line and Segment\n//-----------------------------------------------------------------------------\n\
    struct Segment;\nstruct Circle;\nstruct Polygon;\nstruct Convex;\nstruct Line\
    \ {\n  Point p1, p2;\n  Line() {}\n  Line(Point p, Point q) : p1(p), p2(q) {}\n\
    \  Line(Real a, Real b, Real c) {  // ax+by+c=0\n    if (!sgn(b)) {\n      p1\
    \ = {-c / a, 1}, p2 = {-c / a, 0};\n      if (sgn(a) < 0) std::swap(p1, p2);\n\
    \    } else if (!sgn(a))\n      p1 = {0, -c / b}, p2 = {1, -c / b};\n    else\n\
    \      p1 = {0, -c / b}, p2 = {1, -(c + a) / b};\n    if (sgn(b) < 0) std::swap(p1,\
    \ p2);\n    // ax+by+c>0: left, ax+by+c=0: on, ax+by+c<0: right\n  }\n  Point\
    \ &operator[](int i) {\n    assert(0 <= i && i <= 1);\n    return i ? p2 : p1;\n\
    \  }\n  bool operator==(Line l) const {\n    return !sgn(cross(p1 - p2, l.p1 -\
    \ l.p2)) && !sgn(cross(p1 - p2, l.p1 - p1));\n  }\n  // 1: left, 0: on, -1: right\n\
    \  int where(Point p) { return sgn(cross(p1 - p, p2 - p)); }\n  // return  a,b,c\
    \ of ax+by+c=0\n  std::tuple<Real, Real, Real> coef() {\n    auto n = orth(p2\
    \ - p1);\n    return std::make_tuple(n.x, n.y, -dot(n, p1));\n  }\n  Point project(Point\
    \ p) {\n    Point v = p2 - p1;\n    return p1 + dot(p - p1, v) / dot(v, v) * v;\n\
    \  }\n  Point reflect(Point p) { return 2 * project(p) - p; }\n  Line reflect(Line\
    \ l) { return {reflect(l.p1), reflect(l.p2)}; }\n  Segment reflect(Segment s);\n\
    \  Circle reflect(Circle c);\n  Polygon reflect(Polygon g);\n  Convex reflect(Convex\
    \ g);\n};\n\n// p on leftside\nLine bisector(Point p, Point q) {\n  return {(p\
    \ + q) / 2, (p + q) / 2 + orth(q - p)};\n}\n\nstruct Segment {\n  Point p1, p2;\n\
    \  Point &operator[](int i) {\n    assert(0 <= i && i <= 1);\n    return i ? p2\
    \ : p1;\n  }\n  bool operator==(Segment s) const {  // do not consider the direction\n\
    \    return (p1 == s.p1 && p2 == s.p2) || (p1 == s.p2 && p2 == s.p1);\n  }\n \
    \ int is_on(Point p) {\n    if (p1 == p || p2 == p) return 2;  // end Point\n\
    \    return !sgn(cross(p1 - p, p2 - p)) && sgn(dot(p1 - p, p2 - p) < 0);\n  }\n\
    \  Point closest_point(Point p) {\n    Point v = p2 - p1;\n    Real a = dot(v,\
    \ v), b = dot(p - p1, v);\n    if (sgn(b) < 0) return p1;\n    if (sgn(a - b)\
    \ < 0) return p2;\n    return p1 + b / a * v;\n  }\n};\nbool is_orthogonal(Line\
    \ l, Line m) {\n  return !sgn(dot(l.p1 - l.p2, m.p1 - m.p2));\n}\nbool is_parallel(Line\
    \ l, Line m) {\n  return !sgn(cross(l.p1 - l.p2, m.p1 - m.p2));\n}\n\nLine translate(Line\
    \ l, Point v) { return {l.p1 + v, l.p2 + v}; }\nLine rotate(Line l, Real theta)\
    \ {\n  return {rotate(l.p1, theta), rotate(l.p2, theta)};\n}\n\nSegment Line::reflect(Segment\
    \ s) { return {reflect(s.p1), reflect(s.p2)}; }\nSegment translate(Segment s,\
    \ Point v) { return {s.p1 + v, s.p2 + v}; }\nSegment rotate(Segment s, Real theta)\
    \ {\n  return {rotate(s.p1, theta), rotate(s.p2, theta)};\n}\n\nstd::vector<Point>\
    \ cross_points(Line l, Line m) {\n  Real a = cross(m.p2 - m.p1, l.p2 - l.p1);\n\
    \  Real b = cross(l.p1 - m.p1, l.p2 - l.p1);\n  if (sgn(a)) return {m.p1 + b /\
    \ a * (m.p2 - m.p1)};  // properly crossing\n  if (!sgn(b)) return {m.p1, m.p2};\
    \                   // same line\n  return {};                               \
    \           // disjoint parallel\n}\nstd::vector<Point> cross_points(Line l, Segment\
    \ s) {\n  Real a = cross(s.p2 - s.p1, l.p2 - l.p1);\n  Real b = cross(l.p1 - s.p1,\
    \ l.p2 - l.p1);\n  if (a < 0) a = -a, b = -b;\n  if (sgn(b) < 0 || sgn(a - b)\
    \ < 0) return {};        // no intersect\n  if (sgn(a)) return {s.p1 + b / a *\
    \ (s.p2 - s.p1)};  // properly crossing\n  if (!sgn(b)) return {s.p1, s.p2}; \
    \                  // same line\n  return {};                                \
    \          // disjoint parallel\n}\nstd::vector<Point> cross_points(Segment s,\
    \ Line l) {\n  return cross_points(l, s);\n}\nstd::vector<Point> cross_points(Segment\
    \ s, Segment t) {\n  Real a = cross(s.p2 - s.p1, t.p2 - t.p1);\n  Real b = cross(t.p1\
    \ - s.p1, t.p2 - t.p1);\n  Real c = cross(s.p2 - s.p1, s.p1 - t.p1);\n  if (a\
    \ < 0) a = -a, b = -b, c = -c;\n  if (sgn(b) < 0 || sgn(a - b) < 0 || sgn(c) <\
    \ 0 || sgn(a - c) < 0)\n    return {};                                       \
    \ // disjoint\n  if (sgn(a)) return {s.p1 + b / a * (s.p2 - s.p1)};  // properly\
    \ crossing\n  std::vector<Point> ps;                              // same line\n\
    \  auto insert_if_possible = [&](Point p) {\n    for (auto q : ps)\n      if (sgn(dot(p\
    \ - q, p - q)) == 0) return;\n    ps.emplace_back(p);\n  };\n  if (sgn(dot(s.p1\
    \ - t.p1, s.p2 - t.p1)) <= 0) insert_if_possible(t.p1);\n  if (sgn(dot(s.p1 -\
    \ t.p2, s.p2 - t.p2)) <= 0) insert_if_possible(t.p2);\n  if (sgn(dot(t.p1 - s.p1,\
    \ t.p2 - s.p1)) <= 0) insert_if_possible(s.p1);\n  if (sgn(dot(t.p1 - s.p2, t.p2\
    \ - s.p2)) <= 0) insert_if_possible(s.p2);\n  return ps;\n}\n\nint intersect(Segment\
    \ s, Segment t) {\n  auto cp = cross_points(s, t);\n  if (cp.size() == 0) return\
    \ DISJOINT;\n  if (cp.size() > 1) return OVERLAP;\n  if ((cp[0] == s.p1 || cp[0]\
    \ == s.p2 || cp[0] == t.p1 || cp[0] == t.p2))\n    return TOUCH;\n  return CROSSING;\n\
    }\n\n// angle\nstd::vector<Line> bisector(Line l, Line m) {\n  auto cp = cross_points(l,\
    \ m);\n  if (cp.size() > 1) return {};\n  if (cp.size() == 0) return {Line{(l.p1\
    \ + m.p1) / 2, (l.p2 + m.p1) / 2}};\n  auto p = l.p1 - l.p2, q = m.p1 - m.p2;\n\
    \  p /= norm(p), q /= norm(q);\n  return {Line{cp[0], cp[0] + p + q}, Line{cp[0],\
    \ cp[0] + p - q}};\n}\n\nReal dist(Line l, Point p) { return dist(p, l.project(p));\
    \ }\nReal dist(Point p, Line l) { return dist(l, p); }\nReal dist(Line l, Line\
    \ m) {\n  return sgn(cross(l.p1 - l.p2, m.p1 - m.p2)) ? 0 : dist(l.p1, m);\n}\n\
    Real dist(Segment s, Point p) { return dist(p, s.closest_point(p)); }\nReal dist(Point\
    \ p, Segment s) { return dist(s, p); }\nReal dist(Line l, Segment s) {\n  return\
    \ cross_points(l, s).size() ? 0 : std::min(dist(l, s.p1), dist(l, s.p2));\n}\n\
    Real dist(Segment s, Line l) { return dist(l, s); }\nReal dist(Segment s, Segment\
    \ t) {\n  if (cross_points(s, t).size()) return 0;\n  return std::min({dist(s.p1,\
    \ t), dist(s.p2, t), dist(t.p1, s), dist(t.p2, s)});\n}\n//-----------------------------------------------------------------------------\n\
    // Circle\n//-----------------------------------------------------------------------------\n\
    struct Circle {\n  Point o;\n  Real r;\n  Real area() { return PI * r * r; }\n\
    \  int where(Point p) {\n    int s = sgn(norm2(p - o) - r * r);\n    return s\
    \ < 0 ? IN : s == 0 ? ON : OUT;\n  }\n  std::vector<Line> tangent(Point p) {\n\
    \    Point u = p - o, v = orth(u);\n    Real len = norm2(u) - r * r;\n    if (sgn(len)\
    \ < 0) return {};\n    if (sgn(len) == 0) return {{p, p + v}};\n    u *= r * r\
    \ / norm2(u);\n    v *= r * std::sqrt(len) / norm2(v);\n    return {{p, o + u\
    \ + v}, {p, o + u - v}};\n  }\n};\n\nCircle Line::reflect(Circle c) { return {reflect(c.o),\
    \ c.r}; }\nCircle translate(Circle c, Point v) { return {c.o + v, c.r}; }\nCircle\
    \ rotate(Circle c, Real theta) { return {rotate(c.o, theta), c.r}; }\n\nstd::vector<Point>\
    \ cross_points(Circle c, Circle d) {\n  if (c.r < d.r) std::swap(c, d);\n  Real\
    \ g = norm2(c.o - d.o);\n  if (sgn(g) == 0) {\n    if (sgn(c.r - d.r)) return\
    \ {};\n    return {{c.o.x + c.r, c.o.y},\n            {c.o.x, c.o.y + c.r},\n\
    \            {c.o.x - c.r, c.o.y}};  // same\n  }\n  int inner = sgn(g - (c.r\
    \ - d.r) * (c.r - d.r));\n  int outer = sgn(g - (c.r + d.r) * (c.r + d.r));\n\
    \  if (inner < 0 || outer > 0) return {};\n  if (inner == 0) return {(c.r * d.o\
    \ - d.r * c.o) / (c.r - d.r)};\n  if (outer == 0) return {(c.r * d.o + d.r * c.o)\
    \ / (c.r + d.r)};\n  Real eta = (c.r * c.r - d.r * d.r + g) / (2 * g);\n  Real\
    \ mu = std::sqrt(c.r * c.r / g - eta * eta);\n  Point q = c.o + eta * (d.o - c.o),\
    \ v = mu * orth(d.o - c.o);\n  return {q + v, q - v};\n}\nstd::vector<Point> cross_points(Circle\
    \ c, Line l) {\n  Point u = l.p2 - l.p1, v = l.p1 - c.o;\n  Real a = norm2(u),\
    \ b = dot(u, v) / a, t = (norm2(v) - c.r * c.r) / a;\n  Real det = b * b - t;\n\
    \  if (sgn(det) < 0) return {};               // no solution\n  if (sgn(det) ==\
    \ 0) return {l.p1 - b * u};  // touch inner/outer\n  return {l.p1 - (b + std::sqrt(det))\
    \ * u,   // properly intersect\n          l.p1 - (b - std::sqrt(det)) * u};\n\
    }\nstd::vector<Point> cross_points(Line l, Circle c) { return cross_points(c,\
    \ l); }\nstd::vector<Point> cross_points(Circle c, Segment s) {\n  Point u = s.p2\
    \ - s.p1, v = s.p1 - c.o;\n  Real a = norm2(u), b = dot(u, v) / a, t = (norm2(v)\
    \ - c.r * c.r) / a;\n  Real det = b * b - t;\n  if (sgn(det) < 0) return {}; \
    \ // no solution\n  if (sgn(det) == 0 && sgn(-b) >= 0 && sgn(1 - (-b)) >= 0)\n\
    \    return {s.p1 - b * u};  // touch\n  Real t1 = -b - std::sqrt(det), t2 = -b\
    \ + std::sqrt(det);\n  std::vector<Point> qs;\n  if (sgn(t1) >= 0 && sgn(1 - t1)\
    \ >= 0) qs.emplace_back(s.p1 + t1 * u);\n  if (sgn(t2) >= 0 && sgn(1 - t2) >=\
    \ 0) qs.emplace_back(s.p1 + t2 * u);\n  return qs;\n}\nstd::vector<Point> cross_points(Segment\
    \ s, Circle c) {\n  return cross_points(c, s);\n}\n\n//-----------------------------------------------------------------------------\n\
    // Polygon\n// assuming counterclockwise rotation\n//-----------------------------------------------------------------------------\n\
    struct Polygon : std::vector<Point> {\n  using std::vector<Point>::vector;\n \
    \ int prev(int i) { return i ? i - 1 : (int)this->size() - 1; }\n  int next(int\
    \ i) { return (i + 1 == (int)this->size() ? 0 : i + 1); }\n  bool is_convex()\
    \ {\n    for (int i = 0; i < (int)this->size(); i++)\n      if (ccw((*this)[prev(i)],\
    \ (*this)[i], (*this)[next(i)]) == CLOCKWISE)\n        return false;\n    return\
    \ true;\n  }\n  Real area() {\n    if (this->size() <= 2) return 0;\n    Real\
    \ a = cross(this->back(), (*this)[0]);\n    for (int i = 0; i + 1 < (int)this->size();\
    \ i++)\n      a += cross((*this)[i], (*this)[i + 1]);\n    return a / 2;\n  }\n\
    \  int where(Point p) {\n    bool in = false;\n    for (int i = 0; i < (int)this->size();\
    \ i++) {\n      Point a = (*this)[i] - p, b = (*this)[next(i)] - p;\n      if\
    \ (a.y > b.y) std::swap(a, b);\n      if (a.y <= 0 && 0 < b.y && cross(a, b) <\
    \ 0) in = !in;\n      if (!sgn(cross(a, b)) && sgn(dot(a, b)) <= 0)\n        return\
    \ ON;  // Point on the edge\n    }\n    return in ? IN : OUT;  // Point in:out\
    \ the Polygon\n  }\n  bool contains(Segment s, int side = IN) {  // +2 for in,\
    \ -2 for out\n    int opp = side == IN ? OUT : IN;\n    if (where(s.p1) == opp\
    \ || where(s.p2) == opp) return false;\n    std::vector<Point> ps = {s.p1, s.p2};\n\
    \    for (int i = 0; i < (int)this->size(); i++)\n      for (Point p : cross_points(s,\
    \ Segment({(*this)[i], (*this)[next(i)]})))\n        ps.emplace_back(p);\n   \
    \ int n = ps.size();\n    sort(ps.begin(), ps.end());\n    for (int i = 0; i +\
    \ 1 < n; i++) ps.emplace_back((ps[i] + ps[i + 1]) / 2);\n    for (Point p : ps)\n\
    \      if (where(p) == opp) return false;\n    return true;\n  }\n};\n\nPolygon\
    \ Line::reflect(Polygon g) {\n  reverse(g.begin(), g.end());\n  Polygon res;\n\
    \  for (Point p : g) res.emplace_back(reflect(p));\n  return res;\n}\nPolygon\
    \ translate(Polygon g, Point v) {\n  Polygon h(g.size());\n  for (int i = 0; i\
    \ < (int)g.size(); i++) h[i] = g[i] + v;\n  return h;\n}\nPolygon rotate(Polygon\
    \ g, Real theta) {\n  Polygon h(g.size());\n  for (int i = 0; i < (int)g.size();\
    \ i++) h[i] = rotate(g[i], theta);\n  return h;\n}\n\nstruct Convex : Polygon\
    \ {\n  using Polygon::Polygon;\n  std::pair<Point, Point> farthest() {\n    int\
    \ u = 0, v = 1;\n    Real best = -1;\n    for (int i = 0, j = 1; i < (int)this->size();\
    \ ++i)\n      while (true) {\n        int k = next(j);\n        Real len = norm2((*this)[j]\
    \ - (*this)[i]);\n        if (sgn(len - norm2((*this)[k] - (*this)[i])) <= 0)\n\
    \          j = k;\n        else {\n          if (best < len) best = len, u = i,\
    \ v = j;\n          break;\n        }\n      }\n    return std::make_pair((*this)[u],\
    \ (*this)[v]);\n  }\n  Real diameter() {\n    auto [p, q] = farthest();\n    return\
    \ dist(p, q);\n  }\n  Convex cut(Line l, int side = LEFT) {  // +1 for left, -1\
    \ for right\n    Convex g;\n    for (int i = 0; i < (int)this->size(); i++) {\n\
    \      Point p = (*this)[i], q = (*this)[next(i)];\n      if (l.where(p) * side\
    \ >= 0) g.emplace_back(p);\n      if (l.where(p) * l.where(q) < 0) {\n       \
    \ Real a = cross(q - p, l.p2 - l.p1);\n        Real b = cross(l.p1 - p, l.p2 -\
    \ l.p1);\n        g.emplace_back(p + b / a * (q - p));\n      }\n    }\n    return\
    \ g;\n  }\n};\n\nConvex Line::reflect(Convex g) {\n  reverse(g.begin(), g.end());\n\
    \  Convex res;\n  for (Point p : g) res.emplace_back(reflect(p));\n  return res;\n\
    }\nConvex translate(Convex g, Point v) {\n  Convex h(g.size());\n  for (int i\
    \ = 0; i < (int)g.size(); i++) h[i] = g[i] + v;\n  return h;\n}\nConvex rotate(Convex\
    \ g, Real theta) {\n  Convex h(g.size());\n  for (int i = 0; i < (int)g.size();\
    \ i++) h[i] = rotate(g[i], theta);\n  return h;\n}\n\nReal dist(Polygon g, Point\
    \ p) {\n  if (g.where(p) != OUT) return 0;\n  Real res = dist(Segment({g.back(),\
    \ g[0]}), p);\n  for (int i = 0; i + 1 < (int)g.size(); i++)\n    res = std::min(res,\
    \ dist(Segment({g[i], g[i + 1]}), p));\n  return res;\n}\nReal dist(Point p, Polygon\
    \ g) { return dist(g, p); }\nReal dist(Polygon g, Line l) {\n  Real res = dist(Segment({g.back(),\
    \ g[0]}), l);\n  for (int i = 0; i + 1 < (int)g.size(); i++)\n    res = std::min(res,\
    \ dist(Segment({g[i], g[i + 1]}), l));\n  return res;\n}\nReal dist(Line l, Polygon\
    \ g) { return dist(g, l); }\nReal dist(Polygon g, Segment s) {\n  if (g.where(s.p1)\
    \ != OUT || g.where(s.p2) != OUT) return 0;\n  Real res = dist(Segment({g.back(),\
    \ g[0]}), s);\n  for (int i = 0; i + 1 < (int)g.size(); i++)\n    res = std::min(res,\
    \ dist(Segment({g[i], g[i + 1]}), s));\n  return res;\n}\nReal dist(Segment s,\
    \ Polygon g) { return dist(g, s); }\nReal dist(Polygon g, Polygon h) {\n  Real\
    \ res = dist(Segment({g.back(), g[0]}), h);\n  for (int i = 0; i + 1 < (int)g.size();\
    \ i++)\n    res = std::min(res, dist(Segment({g[i], g[i + 1]}), h));\n  return\
    \ res;\n}\n\nConvex convex_hull(std::vector<Point> ps) {\n  int n = ps.size(),\
    \ k = 0;\n  sort(ps.begin(), ps.end());\n  Convex ch(2 * n);\n  for (int i = 0;\
    \ i < n; ch[k++] = ps[i++])\n    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i])\
    \ == CLOCKWISE) k--;\n  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])\n\
    \    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) == CLOCKWISE) k--;\n  ch.resize(k\
    \ - 1);\n  return ch;\n}\n//-----------------------------------------------------------------------------\n\
    // visualizer\n// to use https://csacademy.com/app/geometry_widget/\n//-----------------------------------------------------------------------------\n\
    struct Visualizer {\n  std::ofstream ofs;\n  Visualizer(std::string s = \"visualize.txt\"\
    ) : ofs(s) {\n    ofs << std::fixed << std::setprecision(10);\n  }\n  Visualizer\
    \ &operator<<(Point p) { return ofs << p << '\\n', *this; }\n  Visualizer &operator<<(Line\
    \ l) {\n    auto [A, B, C] = l.coef();\n    return ofs << \"Line \" << A << \"\
    \ \" << B << \" \" << C << '\\n', *this;\n  }\n  Visualizer &operator<<(Segment\
    \ s) {\n    return ofs << \"Segment \" << s.p1 << \" \" << s.p2 << '\\n', *this;\n\
    \  }\n  Visualizer &operator<<(Circle c) {\n    return ofs << \"Circle \" << c.o\
    \ << \" \" << c.r << '\\n', *this;\n  }\n  Visualizer &operator<<(Polygon g) {\n\
    \    ofs << \"Polygon\" << '\\n';\n    for (Point p : g) ofs << p << '\\n';\n\
    \    ofs << \"...\" << '\\n';\n    return *this;\n  }\n};\n\n}  // namespace geometry\n\
    #line 6 \"test/aoj/CGL_4_C.test.cpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace geometry;\n cout\
    \ << fixed << setprecision(12);\n int n;\n cin >> n;\n Convex g(n);\n for (int\
    \ i= 0; i < n; i++) cin >> g[i];\n int q;\n cin >> q;\n while (q--) {\n  Line\
    \ l;\n  cin >> l.p1 >> l.p2;\n  cout << g.cut(l).area() << endl;\n }\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ \"src/Geometry/!geometry_temp.hpp\"\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace geometry;\n cout\
    \ << fixed << setprecision(12);\n int n;\n cin >> n;\n Convex g(n);\n for (int\
    \ i= 0; i < n; i++) cin >> g[i];\n int q;\n cin >> q;\n while (q--) {\n  Line\
    \ l;\n  cin >> l.p1 >> l.p2;\n  cout << g.cut(l).area() << endl;\n }\n return\
    \ 0;\n}"
  dependsOn:
  - src/Geometry/!geometry_temp.hpp
  isVerificationFile: true
  path: test/aoj/CGL_4_C.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 18:57:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_4_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_C.test.cpp
- /verify/test/aoj/CGL_4_C.test.cpp.html
title: test/aoj/CGL_4_C.test.cpp
---
