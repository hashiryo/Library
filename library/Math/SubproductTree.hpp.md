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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: 複数の値代入と多項式補間

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/SubproductTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 19:44:41+09:00




## Depends on

* :heavy_check_mark: <a href="FormalPowerSeries.hpp.html">形式的冪級数</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 複数の値代入と多項式補間
 * @category 数学
 * @brief どちらもO(N log^2 N)
 * @brief 多項式補間はxが等差数列ならラグランジュ補間のほうがO(N)で速い
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/FormalPowerSeries.hpp"
#undef call_from_test
#endif

template <typename Modint>
struct SubproductTree {
  using FPS = FormalPowerSeries<Modint>;
  int n;
  vector<Modint> xs;
  vector<FPS> buf;
  SubproductTree() {}
  SubproductTree(const vector<Modint> &_xs)
      : n(_xs.size()), xs(_xs), buf(4 * n) {
    pre(0, n, 1);
  }
  void pre(int l, int r, int k) {
    if (r - l == 1) {
      buf[k] = {-xs[l], 1};
      return;
    }
    int m = (l + r) >> 1;
    pre(l, m, k * 2), pre(m, r, k * 2 + 1);
    buf[k] = buf[k * 2] * buf[k * 2 + 1];
  }
  vector<Modint> multi_eval(const FPS &f) {
    vector<Modint> res(n);
    function<void(FPS, int, int, int)> dfs = [&](FPS g, int l, int r, int k) {
      g %= buf[k];
      if (r - l <= 128) {
        for (int i = l; i < r; i++) res[i] = g.eval(xs[i]);
        return;
      }
      int m = (l + r) >> 1;
      dfs(g, l, m, k * 2), dfs(g, m, r, k * 2 + 1);
    };
    dfs(f, 0, n, 1);
    return res;
  }
  FPS interpolate(const vector<Modint> &ys) {
    FPS w = buf[1].diff();
    vector<Modint> vs = multi_eval(w);
    function<FPS(int, int, int)> dfs = [&](int l, int r, int k) {
      if (r - l == 1) return FPS({ys[l] / vs[l]});
      int m = (l + r) >> 1;
      return buf[k * 2 + 1] * dfs(l, m, k * 2)
             + buf[k * 2] * dfs(m, r, k * 2 + 1);
    };
    FPS res = dfs(0, n, 1);
    res.resize(n);
    return res;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Math/SubproductTree.hpp: line 13: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

