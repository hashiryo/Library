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


# :x: test/yosupo/sum_of_exponential_times_polynomial.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sum_of_exponential_times_polynomial.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00


* see: <a href="https://min-25.hatenablog.com/entry/2015/04/24/031413">https://min-25.hatenablog.com/entry/2015/04/24/031413</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413
 */

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/Combination.hpp"
#include "Math/ModInt.hpp"
#include "Math/lagrange_interpolation.hpp"
#undef call_from_test

template <class Modint>
vector<Modint> pow_d_list(int n, long long d) {
  vector<int> pdiv(n);
  for (int i = 2; i < n; i++) pdiv[i] = i & 1 ? i : 2;
  for (int p = 3; p * p < n; p += 2)
    if (pdiv[p] == p)
      for (int q = p * p; q < n; q += 2 * p) pdiv[q] = p;

  vector<Modint> res(n);
  if (d == 0) res[0] = 1;
  if (n >= 2) res[1] = 1;
  for (int i = 2; i < n; i++) {
    if (pdiv[i] == i)
      res[i] = Modint(i).pow(d);
    else
      res[i] = res[pdiv[i]] * res[i / pdiv[i]];
  }
  return res;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Mint = ModInt<998244353>;
  using C = Combination<Mint>;
  long long r, d, n;
  cin >> r >> d >> n;
  if (--n < 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<Mint> sum(d + 2), rpow(d + 2), pd = pow_d_list<Mint>(d + 2, d);
  rpow[0] = 1, sum[0] = rpow[0] * pd[0];
  for (int i = 1; i <= d + 1; i++) rpow[i] = rpow[i - 1] * r;
  for (int i = 1; i <= d + 1; i++) sum[i] = sum[i - 1] + rpow[i] * pd[i];
  Mint ans = 0;
  if (r == 1)
    ans = lagrange_interpolation<Mint>(sum, n);
  else {
    C::init(d + 1);
    for (int i = 0; i <= d; i++) {
      Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];
      ans += (d - i) & 1 ? -tmp : tmp;
    }
    ans /= Mint(1 - r).pow(d + 1);
    vector<Mint> y(d + 1);
    Mint rinv = Mint(r).inverse(), rinvpow = 1;
    for (int i = 0; i <= d; i++) {
      y[i] = Mint(sum[i] - ans) * rinvpow;
      rinvpow *= rinv;
    }
    ans += Mint(r).pow(n) * lagrange_interpolation<Mint>(y, n);
  }
  cout << ans << endl;
  return 0;
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Math/Combination.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

