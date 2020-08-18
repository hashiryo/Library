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


# :x: 偏角ソート

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/arg_sort.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-18 10:01:04+09:00




## Depends on

* :question: <a href="!geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo/argsort.test.cpp.html">test/yosupo/argsort.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 偏角ソート
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
// usage: sort(ps.begin(),ps.end(), polar_angle(origin, direction));
// (-PI,PI]
struct polar_angle {
  const Point o;
  const int s;  // +1 for ccw, -1 for cw
  polar_angle(Point origin = {0, 0}, int dir = +1) : o(origin), s(dir) {}
  int quad(Point p) const {
    for (int i = 0; i < 4; ++i, swap(p.x = -p.x, p.y))
      if (p.x < 0 && p.y < 0) return 2 * i;
    for (int i = 0; i < 4; ++i, swap(p.x = -p.x, p.y))
      if (p.x == 0 && p.y < 0) return 2 * i + 1;
    return 3;  // arg(0,0) = 0
  }
  bool operator()(Point p, Point q) const {
    p = p - o;
    q = q - o;
    if (quad(p) != quad(q)) return s * quad(p) < s * quad(q);
    if (cross(p, q)) return s * cross(p, q) > 0;
    return norm2(p) < norm2(q);  // closer first
  }
};
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/arg_sort.hpp: line 11: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

