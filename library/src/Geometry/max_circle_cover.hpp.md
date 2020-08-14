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


# :heavy_check_mark: 半径固定の円の最大被覆点数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/max_circle_cover.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 01:00:29+09:00




## Depends on

* :question: <a href="!geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1132.test.cpp.html">test/aoj/1132.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 半径固定の円の最大被覆点数
 * @category 幾何
 * ４分木
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Geometry/!geometry_temp.hpp"
#undef call_from_test
#endif

namespace geometry {

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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/max_circle_cover.hpp: line 12: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

