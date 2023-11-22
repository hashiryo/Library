---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Polygon.hpp
    title: "\u591A\u89D2\u5F62"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Segment.hpp
    title: "\u7DDA\u5206"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_f
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_f
  bundledCode: "#line 1 \"test/atcoder/abc202_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_f\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/Geometry/Segment.hpp\"\
    \n#include <algorithm>\n#line 3 \"src/Geometry/Point.hpp\"\n#include <fstream>\n\
    #include <iomanip>\n#include <cmath>\n#include <cassert>\nnamespace geo {\nusing\
    \ namespace std;\nstruct Visualizer {\n ofstream ofs;\n Visualizer(string s= \"\
    visualize.txt\"): ofs(s) { ofs << fixed << setprecision(10); }\n friend Visualizer\
    \ &operator<<(Visualizer &vis, const string &s) { return vis.ofs << s, vis; }\n\
    };\ntemplate <class K> int sgn(K x) {\n if constexpr (is_floating_point_v<K>)\
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
    \ &p) { return {1, 0, 0, 1, p}; }\n}\n#line 4 \"src/Geometry/Line.hpp\"\nnamespace\
    \ geo {\ntemplate <class K> struct Line {\n using P= Point<K>;\n P p, d;  // p+td\n\
    \ Line() {}\n // p + td\n Line(const P &p, const P &d): p(p), d(d) { assert(sgn(norm2(d)));\
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
    }\n}\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#line 4 \"src/Math/mod_inv.hpp\"\
    \ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 6 \"test/atcoder/abc202_f.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using namespace\
    \ geo;\n using Mint= ModInt<int(1e9) + 7>;\n int N;\n cin >> N;\n vector<Point<int>>\
    \ ps(N);\n for (int i= 0; i < N; ++i) cin >> ps[i];\n sort(ps.begin(), ps.end());\n\
    \ int parity[N][N][N], inside[N][N][N];\n for (int i= N; i--;)\n  for (int j=\
    \ N; j--;) {\n   if (i == j) continue;\n   for (int k= N; k--;) {\n    if (i ==\
    \ k || j == k) continue;\n    Polygon<int> g({ps[i], ps[j], ps[k]});\n    parity[i][j][k]=\
    \ g.area2() & 1, inside[i][j][k]= 0;\n    for (int l= N; l--;) {\n     if (l ==\
    \ i || l == j || l == k) continue;\n     inside[i][j][k]+= g.where(ps[l]) != -1;\n\
    \    }\n   }\n  }\n Mint ans= 0, pw[N + 1];\n pw[0]= 1;\n for (int i= 0; i < N;\
    \ ++i) pw[i + 1]= pw[i] + pw[i];\n for (int must= N; must--;) {\n  Mint dp[N][N][2][2];\n\
    \  for (int i= must; i < N; ++i)\n   for (int j= must; j < N; ++j)\n    for (int\
    \ k= 2; k--;) dp[i][j][k][0]= dp[i][j][k][1]= 0;\n  for (int i= must + 1; i <\
    \ N; ++i) dp[must][i][0][0]= dp[must][i][0][1]= 1;\n  for (int i= must; i < N;\
    \ ++i)\n   for (int j= i + 1; j < N; ++j)\n    for (int k= 2; k--;)\n     for\
    \ (int l= j + 1; l < N; ++l) {\n      bool f= ccw(ps[i], ps[j], ps[l]) == CLOCKWISE;\n\
    \      dp[j][l][k ^ parity[must][j][l]][f]+= dp[i][j][k][f] * pw[inside[must][j][l]];\n\
    \     }\n  for (int j= must + 1; j < N; ++j)\n   for (int k= 2; k--;) {\n    Mint\
    \ up= 0, lo= 0;\n    for (int i= must; i < j; ++i) up+= dp[i][j][k][0], lo+= dp[i][j][k][1];\n\
    \    ans+= up * lo;\n   }\n }\n cout << ans - N * (N - 1) / 2 << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_f\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Geometry/Polygon.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n using namespace geo;\n using Mint= ModInt<int(1e9)\
    \ + 7>;\n int N;\n cin >> N;\n vector<Point<int>> ps(N);\n for (int i= 0; i <\
    \ N; ++i) cin >> ps[i];\n sort(ps.begin(), ps.end());\n int parity[N][N][N], inside[N][N][N];\n\
    \ for (int i= N; i--;)\n  for (int j= N; j--;) {\n   if (i == j) continue;\n \
    \  for (int k= N; k--;) {\n    if (i == k || j == k) continue;\n    Polygon<int>\
    \ g({ps[i], ps[j], ps[k]});\n    parity[i][j][k]= g.area2() & 1, inside[i][j][k]=\
    \ 0;\n    for (int l= N; l--;) {\n     if (l == i || l == j || l == k) continue;\n\
    \     inside[i][j][k]+= g.where(ps[l]) != -1;\n    }\n   }\n  }\n Mint ans= 0,\
    \ pw[N + 1];\n pw[0]= 1;\n for (int i= 0; i < N; ++i) pw[i + 1]= pw[i] + pw[i];\n\
    \ for (int must= N; must--;) {\n  Mint dp[N][N][2][2];\n  for (int i= must; i\
    \ < N; ++i)\n   for (int j= must; j < N; ++j)\n    for (int k= 2; k--;) dp[i][j][k][0]=\
    \ dp[i][j][k][1]= 0;\n  for (int i= must + 1; i < N; ++i) dp[must][i][0][0]= dp[must][i][0][1]=\
    \ 1;\n  for (int i= must; i < N; ++i)\n   for (int j= i + 1; j < N; ++j)\n   \
    \ for (int k= 2; k--;)\n     for (int l= j + 1; l < N; ++l) {\n      bool f= ccw(ps[i],\
    \ ps[j], ps[l]) == CLOCKWISE;\n      dp[j][l][k ^ parity[must][j][l]][f]+= dp[i][j][k][f]\
    \ * pw[inside[must][j][l]];\n     }\n  for (int j= must + 1; j < N; ++j)\n   for\
    \ (int k= 2; k--;) {\n    Mint up= 0, lo= 0;\n    for (int i= must; i < j; ++i)\
    \ up+= dp[i][j][k][0], lo+= dp[i][j][k][1];\n    ans+= up * lo;\n   }\n }\n cout\
    \ << ans - N * (N - 1) / 2 << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Geometry/Polygon.hpp
  - src/Geometry/Segment.hpp
  - src/Geometry/Line.hpp
  - src/Geometry/Point.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/atcoder/abc202_f.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 11:44:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc202_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc202_f.test.cpp
- /verify/test/atcoder/abc202_f.test.cpp.html
title: test/atcoder/abc202_f.test.cpp
---
