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


# :heavy_check_mark: 最小包含円

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8f833136c094b0b1f887309fa147399d">幾何</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Geometry/min_enclosing_circle.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 01:00:29+09:00




## Depends on

* :question: <a href="!geometry_temp.hpp.html">幾何テンプレ</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2423.test.cpp.html">test/aoj/2423.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3034.test.cpp.html">test/aoj/3034.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最小包含円
 * @category 幾何
 * 期待値 O(N)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Geometry/!geometry_temp.hpp"
#undef call_from_test
#endif

namespace geometry {

Circle min_enclosing_circle(vector<Point> ps) {
  assert(ps.size());
  if (ps.size() == 1) return {ps[0], 0.};
  random_device seed_gen;
  mt19937 mt(seed_gen());
  shuffle(ps.begin(), ps.end(), mt);
  Circle c = {(ps[0] + ps[1]) / 2, dist(ps[0], ps[1]) / 2};
  for (int i = 2; i < ps.size(); i++)
    if (c.contains(ps[i]) == OUT) {
      c = {(ps[0] + ps[i]) / 2, dist(ps[0], ps[i]) / 2};
      for (int j = 1; j < i; j++)
        if (c.contains(ps[j]) == OUT) {
          c = {(ps[i] + ps[j]) / 2, dist(ps[i], ps[j]) / 2};
          for (int k = 0; k < j; k++)
            if (c.contains(ps[k]) == OUT)
              c = circumscribed_circle(ps[i], ps[j], ps[k]);
        }
    }
  return c;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Geometry/min_enclosing_circle.hpp: line 12: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

