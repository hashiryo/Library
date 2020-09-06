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


# :question: 線形漸化式の高速計算

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/kitamasa.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:06:06+09:00




## Depends on

* :question: <a href="FormalPowerSeries.hpp.html">形式的冪級数</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0168.test.cpp.html">test/aoj/0168.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/215.test.cpp.html">test/yukicoder/215.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/658.test.cpp.html">test/yukicoder/658.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 線形漸化式の高速計算
 * @category 数学
 *  O(NlogNlogk)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Math/FormalPowerSeries.hpp"
#undef call_from_test
#endif

// b[0] = a[0], b[1] = a[1], ..., b[N-1] = a[N-1]
// b[n] = c[0] * b[n-N] + c[1] * b[n-N+1] + ... + c[N-1] * b[n-1] (n >= N)
// calc b[k]

template <class Modint>
Modint kitamasa(const vector<Modint> &c, const vector<Modint> &a, uint64_t k) {
  assert(a.size() == c.size());
  int N = a.size();
  if (k < N) return a[k];
  using FPS = FormalPowerSeries<Modint>;
  uint64_t mask = (uint64_t(1) << (63 - __builtin_clzll(k))) >> 1;
  FPS f(N + 1);
  f[0] = 1;
  for (int i = 0; i < N; i++) f[N - i] = -c[i];
  FPS r({1, 0});
  if (N < 1150) {  // naive
    r = r.divrem_rev_n(f).second;
    for (; mask; mask >>= 1) {
      r *= r;
      if (k & mask) r.push_back(0);
      r = r.divrem_rev_n(f).second;
    }
  } else {
    FPS inv = f.inv(N);
    r = r.rem_rev_pre(f, inv);
    for (; mask; mask >>= 1) {
      r *= r;
      if (k & mask) r.push_back(0);
      r = r.rem_rev_pre(f, inv);
    }
  }
  Modint ret(0);
  for (int i = 0; i < N; i++) ret += r[N - i - 1] * a[i];
  return ret;
}

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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/kitamasa.hpp: line 12: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

