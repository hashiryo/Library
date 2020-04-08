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


# :question: 高速きたまさ法

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Kitamasa.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-08 12:57:42+09:00




## Depends on

* :question: <a href="FormalPowerSeries.hpp.html">形式的冪級数(任意素数MOD)</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0168.test.cpp.html">test/aoj/0168.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/1973.test.cpp.html">test/yukicoder/1973.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 高速きたまさ法
 * @category 数学
 * @brief O(NlogNlogk)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/FormalPowerSeries.hpp"
#undef call_from_test
#endif

// b[0] = a[0], b[1] = a[1], ..., b[N-1] = a[N-1]
// b[n] = c[0] * b[n-N] + c[1] * b[n-N+1] + ... + c[N-1] * b[n-1] (n >= N)
// calc b[k]

R kitamasa(const vector<R> &c, const vector<R> &a, u64 k, R mod) {
  assert(a.size() == c.size());
  int N = a.size();
  if (k < N) return a[k];
  if (FPS::mod != mod) FPS::init(mod);
  auto rem_pre = [&](const FPS &f, const FPS &b, const FPS &inv) {
    if (f.size() < b.size()) return f;
    int sq = f.size() - b.size() + 1;
    FPS q = FPS(FPS(f, sq) * FPS(inv, sq), sq);
    FPS::mul2(q, b, true);
    int s = max(q.size(), b.size()), size = 1;
    while (size < s) size <<= 1;
    FPS p = FPS::mul_crt(0, size);
    int mask = p.size() - 1;
    for (int i = 0; i < sq; i++) FPS::mod_sub(p[i & mask], f[i & mask]);
    FPS r = FPS(f, sq, f.size());
    for (int i = 0; i < (int)r.size(); i++)
      FPS::mod_sub(r[i], p[(sq + i) & mask]);
    return r;
  };
  FPS f(N + 1);
  f[0] = 1;
  for (int i = 0; i < N; i++) f[N - i] = mod - c[i];
  FPS r = FPS(vector<R>({1, 0}));
  FPS inv = f.inv(N);
  r = rem_pre(r, f, inv);
  u64 mask = (u64(1) << (63 - __builtin_clzll(k))) >> 1;
  while (mask) {
    r *= r;
    if (k & mask) r.push_back(0);
    r = rem_pre(r, f, inv);
    mask >>= 1;
  }
  R ret = 0;
  for (int i = 0; i < N; i++)
    FPS::mod_add(ret, FPS::mod_mul(r[N - i - 1], a[i]));
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Math/Kitamasa.hpp: line 12: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

