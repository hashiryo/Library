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


# :heavy_check_mark: 共通部分の面積

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/intersection_area.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-14 14:07:28+09:00




## Depends on

* :question: <a href="_geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_H.test.cpp.html">test/aoj/CGL_7_H.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_I.test.cpp.html">test/aoj/CGL_7_I.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 共通部分の面積
 * @category 幾何
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Geometry/_geometry_temp.hpp"
#undef call_from_test
#endif

namespace geometry {

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
  for (int i = 0; i < g.size(); ++i) sum += tri(g[i] - c.o, g[g.next(i)] - c.o);
  return sum;
}
Real intersection_area(Circle c, Polygon g) { return intersection_area(g, c); }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/intersection_area.hpp: line 11: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

