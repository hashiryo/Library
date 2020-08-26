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


# :question: Mo

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f89e5068e300e71a5d556a6a1143a3dc">アルゴリズム</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Algorithm/Mo.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-26 15:06:52+09:00


* see: <a href="https://ei1333.hateblo.jp/entry/2017/09/11/211011">https://ei1333.hateblo.jp/entry/2017/09/11/211011</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0425.test.cpp.html">test/aoj/0425.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/static_range_inversions_query.mo.test.cpp.html">test/yosupo/static_range_inversions_query.mo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Mo
 * @category アルゴリズム
 *  O((N+Q)√N)
 * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct Mo {
  int n;
  vector<pair<int, int> > lr;
  explicit Mo(int n) : n(n) {}
  /* [l, r) */
  void query(int l, int r) { lr.emplace_back(l, r); }

  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void run(const AL &add_left, const AR &add_right, const EL &erase_left,
           const ER &erase_right, const O &out) {
    int q = (int)lr.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return bool((ablock & 1) ^ (lr[a].second < lr[b].second));
    });
    int l = 0, r = 0;
    for (auto idx : ord) {
      while (l > lr[idx].first) add_left(--l);
      while (r < lr[idx].second) add_right(r++);
      while (l < lr[idx].first) erase_left(l++);
      while (r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }
  template <typename A, typename E, typename O>
  void run(const A &add, const E &erase, const O &out) {
    run(add, add, erase, erase, out);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Algorithm/Mo.hpp"
/**
 * @title Mo
 * @category アルゴリズム
 *  O((N+Q)√N)
 * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct Mo {
  int n;
  vector<pair<int, int> > lr;
  explicit Mo(int n) : n(n) {}
  /* [l, r) */
  void query(int l, int r) { lr.emplace_back(l, r); }

  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void run(const AL &add_left, const AR &add_right, const EL &erase_left,
           const ER &erase_right, const O &out) {
    int q = (int)lr.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return bool((ablock & 1) ^ (lr[a].second < lr[b].second));
    });
    int l = 0, r = 0;
    for (auto idx : ord) {
      while (l > lr[idx].first) add_left(--l);
      while (r < lr[idx].second) add_right(r++);
      while (l < lr[idx].first) erase_left(l++);
      while (r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }
  template <typename A, typename E, typename O>
  void run(const A &add, const E &erase, const O &out) {
    run(add, add, erase, erase, out);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

