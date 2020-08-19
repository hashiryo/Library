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


# :heavy_check_mark: 最近点対

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/closest_pair.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-19 15:34:23+09:00




## Depends on

* :question: <a href="!geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_5_A.test.cpp.html">test/aoj/CGL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最近点対
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

pair<Point, Point> closest_pair(vector<Point> ps) {
  sort(ps.begin(), ps.end(), [](Point p, Point q) { return p.y < q.y; });
  Point u = ps[0], v = ps[1];
  Real best = norm2(u - v);
  auto update = [&](Point p, Point q) {
    Real dis = norm2(p - q);
    if (best > dis) best = dis, u = p, v = q;
  };
  function<void(int, int)> rec = [&](int l, int r) {
    if (r - l <= 1) {
      for (int i = l; i < r; ++i)
        for (int j = i + 1; j < r; ++j) update(ps[i], ps[j]);
      stable_sort(&ps[l], &ps[r]);
    } else {
      int m = (l + r) / 2;
      Real y = ps[m].y;
      rec(l, m);
      rec(m, r);
      inplace_merge(&ps[l], &ps[m], &ps[r]);
      vector<Point> qs;
      for (int i = l; i < r; ++i) {
        if ((ps[i].y - y) * (ps[i].y - y) >= best) continue;
        for (int j = (int)qs.size() - 1; j >= 0; --j) {
          if ((qs[j].x - ps[i].x) * (qs[j].x - ps[i].x) >= best) break;
          update(qs[j], ps[i]);
        }
        qs.push_back(ps[i]);
      }
    }
  };
  rec(0, ps.size());
  return {u, v};
}

pair<Point, Point> farthest_pair(vector<Point> ps) {
  return convex_hull(ps).farthest();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/closest_pair.hpp: line 11: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

