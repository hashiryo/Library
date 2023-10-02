---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Geometry/Circle.hpp
    title: "\u5186"
  - icon: ':question:'
    path: src/Geometry/Line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':question:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  - icon: ':question:'
    path: src/Geometry/Polygon.hpp
    title: "\u591A\u89D2\u5F62"
  - icon: ':question:'
    path: src/Geometry/Segment.hpp
    title: "\u7DDA\u5206"
  - icon: ':question:'
    path: src/Geometry/angle.hpp
    title: "\u89D2\u5EA6\u30FB\u56DE\u8EE2\u95A2\u9023"
  - icon: ':question:'
    path: src/Geometry/intersection_area.hpp
    title: "\u5186\u3068\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H
  bundledCode: "#line 1 \"test/aoj/CGL_7_H.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#line\
    \ 2 \"src/Geometry/angle.hpp\"\n#include <vector>\n#line 3 \"src/Geometry/Point.hpp\"\
    \n#include <fstream>\n#line 5 \"src/Geometry/Point.hpp\"\n#include <cmath>\n#include\
    \ <cassert>\nnamespace geo {\nusing namespace std;\nstruct Visualizer {\n ofstream\
    \ ofs;\n Visualizer(string s= \"visualize.txt\"): ofs(s) { ofs << fixed << setprecision(10);\
    \ }\n friend Visualizer &operator<<(Visualizer &vis, const string &s) { return\
    \ vis.ofs << s, vis; }\n};\ntemplate <class K> int sgn(K x) {\n if constexpr (is_floating_point_v<K>)\
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
    \ a < b;\n  return cross(p, q) > 0;\n }\n};\n}\n#line 2 \"src/Geometry/Segment.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/Geometry/Line.hpp\"\nnamespace geo {\ntemplate\
    \ <class K> struct Line {\n using P= Point<K>;\n P p, d;  // p+td\n Line() {}\n\
    \ // p + td\n Line(const P &p, const P &d): p(p), d(d) { assert(sgn(norm2(d)));\
    \ }\n // ax+by+c=0 ................. ax+by+c>0: left, ax+by+c=0: on, ax+by+c<0:\
    \ right\n Line(K a, K b, K c) {\n  int sa= sgn(a), sb= sgn(b);\n  assert(sa ||\
    \ sb);\n  d= P{b, -a}, p= sb ? P{0, -c / b} : P{-c / a, 0};\n }\n bool operator==(const\
    \ Line &l) const { return !sgn(cross(d, l.d)) && !where(l.p); }\n bool operator!=(const\
    \ Line &l) const { return sgn(cross(d, l.d)) || where(l.p); }\n // +1: left, 0:\
    \ on, -1: right\n int where(const P &q) const { return sgn(cross(d, q - p)); }\n\
    \ P project(const P &q) const { return p + dot(q - p, d) / norm2(d) * d; }\n //\
    \ return  a,b,c of ax+by+c=0\n tuple<K, K, K> coef() const { return make_tuple(-d.y,\
    \ d.x, cross(p, d)); }\n friend ostream &operator<<(ostream &os, const Line &l)\
    \ { return os << l.p << \" + t\" << l.d; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Line &l) {\n  auto [a, b, c]= l.coef();\n  return vis.ofs << \"\
    Line \" << a << \" \" << b << \" \" << c << \"\\n\", vis;\n }\n};\n// p + t(q-p)\n\
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
    \ + m.p) / 2, l.d)};\n auto d= l.d / norm(l.d) + m.d / norm(m.d);\n return {Line(cp[0],\
    \ d), Line(cp[0], !d)};\n}\ntemplate <class K> K dist2(const Line<K> &l, const\
    \ Point<K> &p) {\n K a= cross(l.d, p - l.p);\n return a * a / norm2(l.d);\n}\n\
    template <class K> K dist2(const Point<K> &p, const Line<K> &l) { return dist2(l,\
    \ p); }\ntemplate <class K> K dist2(const Line<K> &l, const Line<K> &m) { return\
    \ is_parallel(l, m) ? dist2(l, m.p) : 0; }\ntemplate <class K> Affine<K> reflect(const\
    \ Line<K> &l) {\n K a= l.d.x * l.d.x, b= l.d.x * l.d.y * 2, c= l.d.y * l.d.y,\
    \ d= a + c;\n a/= d, b/= d, c/= d, d= a - c;\n return {d, b, b, -d, Point<K>{c\
    \ * 2 * l.p.x - b * l.p.y, a * 2 * l.p.y - b * l.p.x}};\n}\ntemplate <class K>\
    \ Line<K> Affine<K>::operator()(const Line<K> &l) { return line_through((*this)(l.p),\
    \ (*this)(l.p + l.d)); }\n}\n#line 4 \"src/Geometry/Segment.hpp\"\nnamespace geo\
    \ {\ntemplate <class K> struct Segment {\n using P= Point<K>;\n P p, q;\n Segment()\
    \ {}\n Segment(const P &p, const P &q): p(p), q(q) {}\n // do not consider the\
    \ direction\n bool operator==(const Segment &s) const { return (p == s.p && q\
    \ == s.q) || (p == s.q && q == s.p); }\n bool operator!=(const Segment &s) const\
    \ { return !(*this == s); }\n bool on(const P &r) const { return ccw(p, q, r)\
    \ == ON_SEGMENT; }\n P &operator[](int i) { return i ? q : p; }\n const P &operator[](int\
    \ i) const { return i ? q : p; }\n long double length() const { return dist(p,\
    \ q); }\n P closest_point(const P &r) const {\n  P d= q - p;\n  K a= dot(r - p,\
    \ d), b;\n  return sgn(a) > 0 ? sgn(a - (b= norm2(d))) < 0 ? p + a / b * d : q\
    \ : p;\n }\n friend ostream &operator<<(ostream &os, const Segment &s) { return\
    \ os << s.p << \"---\" << s.q; }\n friend Visualizer &operator<<(Visualizer &vis,\
    \ const Segment &s) { return vis.ofs << \"Segment \" << s.p.x << \" \" << s.p.y\
    \ << \" \" << s.q.x << \" \" << s.q.y << \"\\n\", vis; }\n};\n// 1: properly crossing,\
    \ 0: no intersect, 2: same line\ntemplate <class K> vector<Point<K>> cross_points(const\
    \ Segment<K> &s, const Line<K> &l) {\n Point d= s.q - s.p;\n K a= cross(d, l.d),\
    \ b= cross(l.p - s.p, l.d);\n if (sgn(a)) {\n  if (b/= a; sgn(b) < 0 || sgn(b\
    \ - 1) > 0) return {};  // no intersect\n  else return {s.p + b * d};        \
    \                   // properly crossing}\n }\n if (sgn(b)) return {};  // disjoint\
    \ parallel\n return {s.p, s.q};      // same line\n}\ntemplate <class K> vector<Point<K>>\
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
    \ }\n}\n#line 3 \"src/Geometry/Polygon.hpp\"\nnamespace geo {\n// build counterclockwise\n\
    template <class K> class Polygon {\n using P= Point<K>;\n K a2= 0;\nprotected:\n\
    \ vector<P> dat;\n void build() {\n  if (dat.empty()) return;\n  a2= cross(dat.back(),\
    \ dat[0]);\n  for (int i= this->size(); --i;) a2+= cross(dat[i - 1], dat[i]);\n\
    \  if (a2 < 0) reverse(dat.begin(), dat.end()), a2= -a2;\n }\n template <int opp>\
    \ inline bool contain(const Segment<K> &s) const {\n  assert(dat.size());\n  if\
    \ (where(s.p) == opp || where(s.q) == opp) return false;\n  vector<P> ps, qs;\n\
    \  for (const auto &e: edges())\n   if (auto cp= cross_points(s, e); cp.size())\
    \ ps.insert(ps.end(), cp.begin(), cp.end());\n  if (ps.empty()) return true;\n\
    \  sort(ps.begin(), ps.end()), ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\
    \  for (int i= ps.size(); --i;) qs.emplace_back((ps[i] + ps[i - 1]) / 2);\n  for\
    \ (const auto &q: qs)\n   if (where(q) == opp) return false;\n  return true;\n\
    \ }\npublic:\n Polygon() {}\n Polygon(const vector<P> &ps): dat(ps) { build();\
    \ }\n inline int prev(int i) const { return i ? i - 1 : (int)this->size() - 1;\
    \ }\n inline int next(int i) const { return i + 1 >= (int)this->size() ? 0 : i\
    \ + 1; }\n const P &operator[](int i) const { return dat[i]; }\n auto begin()\
    \ const { return dat.begin(); }\n auto end() const { return dat.end(); }\n size_t\
    \ size() const { return dat.size(); }\n vector<Segment<K>> edges() const {\n \
    \ vector<Segment<K>> es;\n  for (int i= 0, e= dat.size(); i < e; ++i) es.emplace_back(dat[i],\
    \ dat[next(i)]);\n  return es;\n }\n // assuming no self-intersections\n bool\
    \ is_convex() const {\n  assert(dat.size());\n  for (int i= dat.size(); i--;)\n\
    \   if (P a= dat[i], b= a - dat[prev(i)], c= dat[next(i)] - a; sgn(cross(b, c))\
    \ < 0) return false;\n  return true;\n }\n K area() const { return a2 / 2; }\n\
    \ // for integer\n K area2() const { return a2; }\n // 1: in, 0: on, -1: out\n\
    \ int where(const P &p) const {\n  assert(dat.size());\n  bool in= false;\n  for\
    \ (int i= dat.size(); i--;) {\n   Point a= dat[i] - p, b= dat[next(i)] - p;\n\
    \   if (a.y > b.y) swap(a, b);\n   int s= sgn(cross(a, b));\n   if (!s && sgn(dot(a,\
    \ b)) <= 0) return 0;\n   if (s < 0 && sgn(a.y) <= 0 && 0 < sgn(b.y)) in= !in;\n\
    \  }\n  return in ? 1 : -1;\n }\n bool in(const Segment<K> &s) const { return\
    \ contain<-1>(s); }\n bool out(const Segment<K> &s) const { return contain<+1>(s);\
    \ }\n friend ostream &operator<<(ostream &os, const Polygon &g) {\n  for (int\
    \ i= 0, e= g.size(); i < e; ++i) os << \"--\" << g[i] << \"-\";\n  return os;\n\
    \ }\n friend Visualizer &operator<<(Visualizer &vis, const Polygon &g) {\n  vis.ofs\
    \ << \"Polygon\" << '\\n';\n  for (const auto &p: g) vis << p;\n  return vis.ofs\
    \ << \"...\" << '\\n', vis;\n }\n};\ntemplate <class K> K dist2(const Polygon<K>\
    \ &g, const Point<K> &p) {\n if (g.where(p) != -1) return 0;\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(e, p));\n return ret;\n}\n\
    template <class K> K dist2(const Point<K> &p, const Polygon<K> &g) { return dist2(g,\
    \ p); }\ntemplate <class K> K dist2(const Polygon<K> &g, const Line<K> &l) {\n\
    \ K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges()) ret= min(ret,\
    \ dist2(e, l));\n return ret;\n}\ntemplate <class K> K dist2(const Line<K> &l,\
    \ const Polygon<K> &g) { return dist2(g, l); }\ntemplate <class K> K dist2(const\
    \ Polygon<K> &g, const Segment<K> &s) {\n if (g.where(s.p) != -1 || g.where(s.q)\
    \ != -1) return 0;\n K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges())\
    \ ret= min(ret, dist2(e, s));\n return ret;\n}\ntemplate <class K> K dist2(const\
    \ Segment<K> &s, const Polygon<K> &g) { return dist2(g, s); }\ntemplate <class\
    \ K> K dist2(const Polygon<K> &g, const Polygon<K> &h) {\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(h, e));\n return ret;\n}\n\
    template <class K> Polygon<K> Affine<K>::operator()(const Polygon<K> &g) {\n vector<Point<K>>\
    \ ps;\n for (const auto &p: g) ps.emplace_back((*this)(p));\n return Polygon(ps);\n\
    }\n}\n#line 3 \"src/Geometry/Circle.hpp\"\nnamespace geo {\ntemplate <class R>\
    \ struct Circle {\n using P= Point<R>;\n P o;\n R r;\n Circle() {}\n Circle(const\
    \ P &o, R r): o(o), r(r) {}\n long double area() const { return r * r * M_PI;\
    \ }\n // +1: in, 0: on, -1: out\n int where(const P &p) const { return sgn(r *\
    \ r - dist2(p, o)); }\n // +1: intersect, 0: contact, -1: disjoint\n int where(const\
    \ Line<R> &l) const { return sgn(r * r - dist2(l, o)); }\n // true: c in *this\n\
    \ bool in(const Circle &c) const {\n  R a= c.r - r;\n  return sgn(a) <= 0 && sgn(dist2(o,\
    \ c.o) - a * a) <= 0;\n }\n vector<Line<R>> tangent(const P &p) const {\n  P d=\
    \ p - o, e= !d;\n  R b= norm2(d), a= b - r * r;\n  if (int s= sgn(a); s < 0) return\
    \ {};\n  else if (s == 0) return {{p, e}};\n  d*= r, e*= sqrt(a);\n  return {Line(p,\
    \ !(d + e)), Line(p, !(d - e))};\n }\n friend ostream &operator<<(ostream &os,\
    \ const Circle &c) { return os << c.o << \" \" << c.r; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Circle &c) { return vis.ofs << \"Circle \" << c.o.x << \" \" <<\
    \ c.o.y << \" \" << c.r << '\\n', vis; }\n};\n// 2: properly intersect, 1: contact,\
    \ 0: disjoint, 3: same\n// counter-clockwise of c and clockwise of d\ntemplate\
    \ <class R> vector<Point<R>> cross_points(const Circle<R> &c, const Circle<R>\
    \ &d) {\n Point v= d.o - c.o;\n R g= norm2(v), a= c.r - d.r, b= c.r + d.r;\n if\
    \ (!sgn(g)) {\n  if (sgn(a)) return {};\n  return {{c.o.x + c.r, c.o.y}, {c.o.x\
    \ - c.r, c.o.y}, {c.o.x, c.o.y + c.r}};\n }\n int in= sgn(g - a * a), out= sgn(g\
    \ - b * b);\n if (in < 0 || out > 0) return {};\n if (!in) return {(c.r * d.o\
    \ - d.r * c.o) / a};\n if (!out) return {(c.r * d.o + d.r * c.o) / b};\n R e=\
    \ (a * b + g) / (g * 2);\n Point q= c.o + e * v, n= !v * sqrt(c.r * c.r / g -\
    \ e * e);\n return {q - n, q + n};\n}\n// 2: properly intersect, 1: contact, 0:\
    \ disjoint\n// direction of l\ntemplate <class R> vector<Point<R>> cross_points(const\
    \ Circle<R> &c, const Line<R> &l) {\n Point<R> v= l.p - c.o;\n R a= norm2(l.d),\
    \ b= dot(l.d, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n int s= sgn(d);\n\
    \ if (s < 0) return {};\n if (!s) return {l.p - b * l.d};\n d= sqrt(d);\n return\
    \ {l.p - (b + d) * l.d, l.p - (b - d) * l.d};\n}\ntemplate <class R> vector<Point<R>>\
    \ cross_points(const Line<R> &l, const Circle<R> &c) { return cross_points(c,\
    \ l); }\ntemplate <class R> vector<Point<R>> cross_points(const Circle<R> &c,\
    \ const Segment<R> &s) {\n Point<R> u= s.q - s.p, v= s.p - c.o;\n R a= norm2(u),\
    \ b= dot(u, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n int t= sgn(d);\n\
    \ if (t < 0) return {};\n if (!t && sgn(b) <= 0 && sgn(1 + b) >= 0) return {s.p\
    \ - b * u};\n d= sqrt(d), a= -b - d, b= -b + d;\n vector<Point<R>> ps;\n if (0\
    \ <= sgn(a) && sgn(a - 1) <= 0) ps.emplace_back(s.p + a * u);\n if (0 <= sgn(b)\
    \ && sgn(b - 1) <= 0) ps.emplace_back(s.p + b * u);\n return ps;\n}\ntemplate\
    \ <class R> vector<Point<R>> cross_points(const Segment<R> &s, const Circle<R>\
    \ &c) { return cross_points(c, s); }\ntemplate <class R> Circle<R> circumscribed_circle(const\
    \ Point<R> &A, const Point<R> &B, const Point<R> &C) {\n Point u= !(B - A), v=\
    \ C - A, o= (A + B + dot(C - B, v) / dot(u, v) * u) / 2;\n return {o, dist(A,\
    \ o)};\n}\ntemplate <class R> Circle<R> inscribed_circle(const Point<R> &A, const\
    \ Point<R> &B, const Point<R> &C) {\n R a= dist(B, C), b= dist(C, A), c= dist(A,\
    \ B), s= (a + b + c) / 2;\n return {(a * A + b * B + c * C) / (s * 2), sqrt((s\
    \ - a) * (s - b) * (s - c) / s)};\n}\ntemplate <class R> vector<Line<R>> common_tangent(const\
    \ Circle<R> &c, const Circle<R> &d) {\n Point u= d.o - c.o, v= !u;\n R g= norm2(u),\
    \ b;\n if (!sgn(g)) return {};  // same origin\n vector<Line<R>> ls;\n for (R\
    \ a: {c.r - d.r, c.r + d.r}) {\n  if (int s= sgn(b= g - a * a); !s) ls.emplace_back(Line(c.o\
    \ + c.r * a / g * u, v));\n  else if (s > 0) {\n   Point x= a / g * u, y= sqrt(b)\
    \ / g * v, e= x + y, f= x - y;\n   ls.emplace_back(Line(c.o + c.r * e, !e)), ls.emplace_back(Line(c.o\
    \ + c.r * f, !f));\n  }\n }\n return ls;\n}\n}\n#line 5 \"src/Geometry/intersection_area.hpp\"\
    \nnamespace geo {\ntemplate <class R> R intersection_area(const Circle<R> &c,\
    \ const Circle<R> &d) {\n R l= dist2(d.o, c.o), g= c.r + d.r;\n if (sgn(l - g\
    \ * g) >= 0) return 0;\n R h= c.r - d.r, a= c.r * c.r, b= d.r * d.r;\n if (sgn(l\
    \ - h * h) <= 0) return min(a, b) * M_PI;\n R m= sqrt(l), z= (a - b + l) / (m\
    \ * 2), e= z / c.r, f= (m - z) / d.r;\n return a * acos(e) + b * acos(f) - m *\
    \ sqrt(a - z * z);\n}\ntemplate <class R> R intersection_area(const Circle<R>\
    \ &c, const Polygon<R> &g) {\n using P= Point<R>;\n auto sub= [&](const P &p,\
    \ const P &q) {\n  P u= q - p;\n  R a= norm2(u), b= dot(u, p) / a, e= c.r * c.r,\
    \ d= b * b - (norm2(p) - e) / a;\n  if (sgn(d) <= 0) return e * angle(p, q);\n\
    \  d= sqrt(d);\n  P x= p + clamp(-b - d, R(0), R(1)) * u, y= p + clamp(-b + d,\
    \ R(0), R(1)) * u;\n  return (cross(x, y) + e * (angle(p, x) + angle(y, q)));\n\
    \ };\n vector<P> ps;\n for (const auto &p: g) ps.emplace_back(p - c.o);\n R ret=\
    \ 0;\n for (int i= ps.size(); i--;) ret+= sub(ps[i], ps[g.next(i)]);\n return\
    \ ret / 2;\n}\ntemplate <class R> R intersection_area(const Polygon<R> &g, const\
    \ Circle<R> &c) { return intersection_area(c, g); }\n}\n#line 6 \"test/aoj/CGL_7_H.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using namespace geo;\n Circle<long double> c;\n int n;\n cin >> n >> c.r;\n\
    \ vector<Point<long double>> ps(n);\n for (int i= 0; i < n; ++i) cin >> ps[i];\n\
    \ cout << fixed << setprecision(12) << intersection_area(c, Polygon(ps)) << '\\\
    n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ \"src/Geometry/intersection_area.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace geo;\n Circle<long\
    \ double> c;\n int n;\n cin >> n >> c.r;\n vector<Point<long double>> ps(n);\n\
    \ for (int i= 0; i < n; ++i) cin >> ps[i];\n cout << fixed << setprecision(12)\
    \ << intersection_area(c, Polygon(ps)) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Geometry/intersection_area.hpp
  - src/Geometry/angle.hpp
  - src/Geometry/Point.hpp
  - src/Geometry/Polygon.hpp
  - src/Geometry/Segment.hpp
  - src/Geometry/Line.hpp
  - src/Geometry/Circle.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_H.test.cpp
  requiredBy: []
  timestamp: '2023-10-02 19:27:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_H.test.cpp
- /verify/test/aoj/CGL_7_H.test.cpp.html
title: test/aoj/CGL_7_H.test.cpp
---
