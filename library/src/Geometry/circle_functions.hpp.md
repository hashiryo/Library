---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :question: 円のあれこれ

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/circle_functions.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-19 15:34:23+09:00




## Depends on

* :question: <a href="!geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1132.test.cpp.html">test/aoj/1132.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2201.test.cpp.html">test/aoj/2201.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2423.test.cpp.html">test/aoj/2423.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2514.test.cpp.html">test/aoj/2514.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3034.test.cpp.html">test/aoj/3034.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_A.test.cpp.html">test/aoj/CGL_7_A.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/CGL_7_B.test.cpp.html">test/aoj/CGL_7_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_C.test.cpp.html">test/aoj/CGL_7_C.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_G.test.cpp.html">test/aoj/CGL_7_G.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_H.test.cpp.html">test/aoj/CGL_7_H.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_I.test.cpp.html">test/aoj/CGL_7_I.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 円のあれこれ
 * @category 幾何
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Geometry/!geometry_temp.hpp"
#undef call_from_test
#endif

namespace geometry {

Circle inscribed_circle(Point A, Point B, Point C) {
  Real a = dist(B, C), b = dist(C, A), c = dist(A, B);
  Real s = a + b + c;
  Point o = (a * A + b * B + c * C) / s;
  Real r = sqrt((s - a) * (s - b) * (s - c) / s) / 2;
  return {o, r};
}

Circle circumscribed_circle(Point A, Point B, Point C) {
  Point u = orth(B - A), v = C - A;
  Point o = (A + B + u * dot(C - B, v) / dot(u, v)) / 2;
  return {o, dist(A, o)};
}

vector<Line> common_tangent(Circle c, Circle d) {
  Real len = dist(c.o, d.o);
  if (sgn(len) == 0) return {};  // same origin
  Point u = (d.o - c.o) / len, v = orth(u);
  vector<Line> ls;
  for (int s = +1; s >= -1; s -= 2) {
    Real h = (c.r + s * d.r) / len;
    if (sgn(1 - h * h) == 0) {  // touch inner/outer
      ls.emplace_back(Line{c.o + h * c.r * u, c.o + h * c.r * (u + v)});
    } else if (sgn(1 - h * h) > 0) {  // properly intersect
      Point uu = h * u, vv = sqrt(1 - h * h) * v;
      ls.emplace_back(Line{c.o + c.r * (uu + vv), d.o - d.r * (uu + vv) * s});
      ls.emplace_back(Line{c.o + c.r * (uu - vv), d.o - d.r * (uu - vv) * s});
    }
  }
  return ls;
}

Real intersection_area(Circle c, Circle d) {
  if (c.r < d.r) swap(c, d);
  auto A = [&](Real r, Real h) {
    return r * r * acos(h / r) - h * sqrt(r * r - h * h);
  };
  Real l = dist(c.o, d.o);
  Real a = (l * l + c.r * c.r - d.r * d.r) / (2 * l);
  if (sgn(l - c.r - d.r) >= 0) return 0;  // far away
  if (sgn(l - c.r + d.r) <= 0) return PI * d.r * d.r;
  if (sgn(l - c.r) >= 0)
    return A(c.r, a) + A(d.r, l - a);
  else
    return A(c.r, a) + PI * d.r * d.r - A(d.r, a - l);
}

Real intersection_area(Polygon g, Circle c) {
  auto tri = [&](Point p, Point q) {
    Point d = q - p;
    Real a = dot(d, p) / dot(d, d), b = (dot(p, p) - c.r * c.r) / dot(d, d);
    Real det = a * a - b;
    if (det <= 0) return arg(p, q) * c.r * c.r / 2;
    Real s = max((Real)0., -a - sqrt(det)), t = min((Real)1., -a + sqrt(det));
    if (t < 0 || 1 <= s) return c.r * c.r * arg(p, q) / 2;
    Point u = p + s * d, v = p + t * d;
    return arg(p, u) * c.r * c.r / 2 + cross(u, v) / 2
           + arg(v, q) * c.r * c.r / 2;
  };
  Real sum = 0.0;
  for (int i = 0; i < (int)g.size(); ++i)
    sum += tri(g[i] - c.o, g[g.next(i)] - c.o);
  return sum;
}
Real intersection_area(Circle c, Polygon g) { return intersection_area(g, c); }

Circle min_enclosing_circle(vector<Point> ps) {
  assert(ps.size());
  if (ps.size() == 1) return {ps[0], 0.};
  random_device seed_gen;
  mt19937 mt(seed_gen());
  shuffle(ps.begin(), ps.end(), mt);
  Circle c = {(ps[0] + ps[1]) / 2, dist(ps[0], ps[1]) / 2};
  for (int i = 2; i < ps.size(); i++)
    if (c.where(ps[i]) == OUT) {
      c = {(ps[0] + ps[i]) / 2, dist(ps[0], ps[i]) / 2};
      for (int j = 1; j < i; j++)
        if (c.where(ps[j]) == OUT) {
          c = {(ps[i] + ps[j]) / 2, dist(ps[i], ps[j]) / 2};
          for (int k = 0; k < j; k++)
            if (c.where(ps[k]) == OUT)
              c = circumscribed_circle(ps[i], ps[j], ps[k]);
        }
    }
  return c;
}

pair<int, Point> max_circle_cover(vector<Point> ps, Real r) {
  const Real dx[4] = {1, -1, -1, 1}, dy[4] = {1, 1, -1, -1};
  Point best_p;
  int best = 0;
  function<void(Point, Real, vector<Point>)> rec
      = [&](Point p, Real w, vector<Point> ps) {
          w /= 2;
          Point qs[4];
          vector<Point> pss[4];
          for (int i = 0; i < 4; ++i) {
            qs[i] = p + w * Point({dx[i], dy[i]});
            int lo = 0;
            for (Point q : ps) {
              Real d = dist(qs[i], q);
              if (sgn(d - r) <= 0) ++lo;
              if (sgn(d - w * sqrt(2) - r) <= 0) pss[i].push_back(q);
            }
            if (lo > best) {
              best = lo;
              best_p = qs[i];
            }
          }
          for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j)
              if (pss[i].size() < pss[j].size())
                swap(pss[i], pss[j]), swap(qs[i], qs[j]);
            if (pss[i].size() <= best) break;
            rec(qs[i], w, pss[i]);
          }
        };
  Real w = 0;
  for (Point p : ps) w = max({w, abs(p.x), abs(p.y)});
  rec({0, 0}, w, ps);
  return {best, best_p};
}

}  // namespace geometry

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/circle_functions.hpp: line 11: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

