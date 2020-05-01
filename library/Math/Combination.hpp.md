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


# :heavy_check_mark: 組み合わせ

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Combination.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:49:16+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 組み合わせ
 * @category 数学
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class Modint>
struct Combination {
  static vector<Modint> _fact, _finv, _inv;
  static void init(int sz) {
    int n = min(sz, Modint::modulo() - 1);
    _fact.resize(n + 1), _finv.resize(n + 1), _inv.resize(n + 1);
    for (int i = 0; i <= n; ++i) _fact[i] = i ? Modint(i) * _fact[i - 1] : 1;
    _finv[n] = _fact[n].inverse();
    for (int i = n; i; --i) _finv[i - 1] = Modint(i) * _finv[i];
    for (int i = 1; i <= n; ++i) _inv[i] = _finv[i] * _fact[i - 1];
  }
  static Modint inv(int n) { return _inv[n]; }
  static Modint fact(int n) { return _fact[n]; }
  static Modint fact_inv(int n) { return _finv[n]; }
  static Modint nPr(int n, int r) {
    if (n < r || r < 0) return Modint(0);
    return _fact[n] * _finv[n - r];
  }
  static Modint nCr(int n, int r) { return nPr(n, r) * _finv[r]; }
  static Modint nHr(int n, int r) { return !r ? Modint(1) : nCr(n + r - 1, r); }
  static size_t size() { return _inv.size(); }
};
template <class Modint>
vector<Modint> Combination<Modint>::_fact;
template <class Modint>
vector<Modint> Combination<Modint>::_finv;
template <class Modint>
vector<Modint> Combination<Modint>::_inv;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Combination.hpp"
/**
 * @title 組み合わせ
 * @category 数学
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class Modint>
struct Combination {
  static vector<Modint> _fact, _finv, _inv;
  static void init(int sz) {
    int n = min(sz, Modint::modulo() - 1);
    _fact.resize(n + 1), _finv.resize(n + 1), _inv.resize(n + 1);
    for (int i = 0; i <= n; ++i) _fact[i] = i ? Modint(i) * _fact[i - 1] : 1;
    _finv[n] = _fact[n].inverse();
    for (int i = n; i; --i) _finv[i - 1] = Modint(i) * _finv[i];
    for (int i = 1; i <= n; ++i) _inv[i] = _finv[i] * _fact[i - 1];
  }
  static Modint inv(int n) { return _inv[n]; }
  static Modint fact(int n) { return _fact[n]; }
  static Modint fact_inv(int n) { return _finv[n]; }
  static Modint nPr(int n, int r) {
    if (n < r || r < 0) return Modint(0);
    return _fact[n] * _finv[n - r];
  }
  static Modint nCr(int n, int r) { return nPr(n, r) * _finv[r]; }
  static Modint nHr(int n, int r) { return !r ? Modint(1) : nCr(n + r - 1, r); }
  static size_t size() { return _inv.size(); }
};
template <class Modint>
vector<Modint> Combination<Modint>::_fact;
template <class Modint>
vector<Modint> Combination<Modint>::_finv;
template <class Modint>
vector<Modint> Combination<Modint>::_inv;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

