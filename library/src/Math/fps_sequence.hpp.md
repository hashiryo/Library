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


# :question: 数列(形式的冪級数使用)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/fps_sequence.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 11:16:08+09:00


* see: <a href="https://min-25.hatenablog.com/entry/2015/04/07/160154">https://min-25.hatenablog.com/entry/2015/04/07/160154</a>
* see: <a href="https://en.wikipedia.org/wiki/Bernoulli_number">https://en.wikipedia.org/wiki/Bernoulli_number</a>
* see: <a href="https://en.wikipedia.org/wiki/Partition_function_(number_theory)">https://en.wikipedia.org/wiki/Partition_function_(number_theory)</a>
* see: <a href="https://en.wikipedia.org/wiki/Stirling_number">https://en.wikipedia.org/wiki/Stirling_number</a>
* see: <a href="https://en.m.wikipedia.org/wiki/Eulerian_number">https://en.m.wikipedia.org/wiki/Eulerian_number</a>


## Depends on

* :question: <a href="FormalPowerSeries.hpp.html">形式的冪級数</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/bernoulli.test.cpp.html">test/yosupo/bernoulli.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/partition.test.cpp.html">test/yosupo/partition.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/stirling_first.test.cpp.html">test/yosupo/stirling_first.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/stirling_second.test.cpp.html">test/yosupo/stirling_second.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/sum_of_exponential_times_polynomial_limit.FPS.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial_limit.FPS.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 数列(形式的冪級数使用)
 * @category 数学
 *  O(NlogN)
 * @see https://min-25.hatenablog.com/entry/2015/04/07/160154
 * @see https://en.wikipedia.org/wiki/Bernoulli_number
 * @see https://en.wikipedia.org/wiki/Partition_function_(number_theory)
 * @see https://en.wikipedia.org/wiki/Stirling_number
 * @see https://en.m.wikipedia.org/wiki/Eulerian_number
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Math/FormalPowerSeries.hpp"
#undef call_from_test
#endif

template <typename Modint>
FormalPowerSeries<Modint> bernoulli(int N) {
  FormalPowerSeries<Modint> ret(N + 1);
  ret[0] = 1;
  for (int i = 1; i <= N; i++) ret[i] = ret[i - 1] / Modint(i + 1);
  ret = ret.inv();
  Modint fact = 1;
  for (int i = 1; i <= N; fact *= (++i)) ret[i] *= fact;
  return ret;
}

template <typename Modint>
FormalPowerSeries<Modint> partition(int N) {
  FormalPowerSeries<Modint> ret(N + 1);
  ret[0] = 1;
  for (int k = 1; 1ll * k * (3 * k + 1) / 2 <= N; k++)
    ret[k * (3 * k + 1) / 2] = (k & 1 ? -1 : 1);
  for (int k = 1; 1ll * k * (3 * k - 1) / 2 <= N; k++)
    ret[k * (3 * k - 1) / 2] = (k & 1 ? -1 : 1);
  return ret.inv();
}

template <typename Modint>
FormalPowerSeries<Modint> stirling_first(int N) {
  if (!N) return {1};
  auto ret = stirling_first<Modint>(N / 2);
  ret *= ret.shift(N / 2);
  if (N & 1) ret *= {N - 1, 1};
  return ret;
}

template <typename Modint>
FormalPowerSeries<Modint> stirling_second(int N) {
  FormalPowerSeries<Modint> a(N + 1), b(N + 1);
  Modint finv = 1;
  for (int i = 0; i <= N; finv /= (++i))
    a[i] = Modint(i).pow(N) * finv, b[i] = i & 1 ? -finv : finv;
  return (a * b).part(N + 1);
}

template <typename Modint>
FormalPowerSeries<Modint> eulerian(int N) {
  vector<Modint> fact(N + 2), finv(N + 2);
  fact[0] = finv[N + 1] = 1;
  for (int i = 1; i <= N + 1; i++) fact[i] = fact[i - 1] * i;
  finv[N + 1] /= fact[N + 1];
  for (int i = N; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);
  FormalPowerSeries<Modint> a((N + 1) / 2), b((N + 1) / 2);
  for (int i = 0; i <= (N - 1) / 2; i++) {
    a[i] = i & 1 ? -finv[i] * finv[N + 1 - i] : finv[i] * finv[N + 1 - i];
    b[i] = Modint(i + 1).pow(N);
  }
  FormalPowerSeries<Modint> ret = (a * b).part(N);
  for (int i = 0; i <= (N - 1) / 2; i++)
    ret[N - i - 1] = ret[i] = ret[i] * fact[N + 1];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/fps_sequence.hpp: line 17: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

