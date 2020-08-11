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


# :warning: ラグランジュ補間

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/lagrange_interpolation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title ラグランジュ補間
 * @category 数学
 * @brief x=0,1,..,N-1とy=f(0),f(1),...,f(N-1)が与えられたときのf(t)を計算
 * @brief O(N)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// verify用:http://codeforces.com/contest/622/problem/F

template <typename K>
K lagrange_interpolation(vector<K> &y, K t) {
  int n = y.size() - 1;
  vector<K> pro(n + 1, 1), orp(n + 1, 1);
  for (int i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));
  for (int i = n; i > 0; i--) orp[i - 1] = orp[i] * (t - K(i));
  K fact = K(1);
  for (int i = 1; i <= n; i++) fact *= K(i);
  vector<K> finv(n + 1, 1);
  finv[n] = K(1) / fact;
  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * K(i);
  K res(0);
  for (int i = 0; i <= n; i++) {
    K tmp = y[i] * pro[i] * orp[i] * finv[i] * finv[n - i];
    res += (n - i) & 1 ? -tmp : tmp;
  }
  return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/lagrange_interpolation.hpp"
/**
 * @title ラグランジュ補間
 * @category 数学
 * @brief x=0,1,..,N-1とy=f(0),f(1),...,f(N-1)が与えられたときのf(t)を計算
 * @brief O(N)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// verify用:http://codeforces.com/contest/622/problem/F

template <typename K>
K lagrange_interpolation(vector<K> &y, K t) {
  int n = y.size() - 1;
  vector<K> pro(n + 1, 1), orp(n + 1, 1);
  for (int i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));
  for (int i = n; i > 0; i--) orp[i - 1] = orp[i] * (t - K(i));
  K fact = K(1);
  for (int i = 1; i <= n; i++) fact *= K(i);
  vector<K> finv(n + 1, 1);
  finv[n] = K(1) / fact;
  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * K(i);
  K res(0);
  for (int i = 0; i <= n; i++) {
    K tmp = y[i] * pro[i] * orp[i] * finv[i] * finv[n - i];
    res += (n - i) & 1 ? -tmp : tmp;
  }
  return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

