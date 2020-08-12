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


# :heavy_check_mark: Berlekamp-Massey

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/berlekamp_massey.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:23:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/find_linear_recurrence.test.cpp.html">test/yosupo/find_linear_recurrence.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Berlekamp-Massey
 * @category 数学
 * 数列の最初のN項から、その数列を生成するN/2次以下の最小の線形漸化式を求める
 *  O(N^2)
 */

// verify用:
// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]
// return c

template <class T>
vector<T> berlekamp_massey(const vector<T> &a) {
  const int N = (int)a.size();
  vector<T> b = {T(-1)}, c = {T(-1)};
  T y = T(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size()) + 1;
    T x = 0;
    for (int i = 0; i < l; i++) x += c[i] * a[ed - l + i];
    b.emplace_back(0);
    if (x == T(0)) continue;
    T freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, T(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  c.pop_back();
  return c;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/berlekamp_massey.hpp"
/**
 * @title Berlekamp-Massey
 * @category 数学
 * 数列の最初のN項から、その数列を生成するN/2次以下の最小の線形漸化式を求める
 *  O(N^2)
 */

// verify用:
// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]
// return c

template <class T>
vector<T> berlekamp_massey(const vector<T> &a) {
  const int N = (int)a.size();
  vector<T> b = {T(-1)}, c = {T(-1)};
  T y = T(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size()) + 1;
    T x = 0;
    for (int i = 0; i < l; i++) x += c[i] * a[ed - l + i];
    b.emplace_back(0);
    if (x == T(0)) continue;
    T freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(begin(c), m - l, T(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  c.pop_back();
  return c;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

