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


# :heavy_check_mark: 杜教筛

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/dujiao_sieve.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 07:59:43+09:00


* see: <a href="https://maspypy.com/yukicoder-no-886-direct">https://maspypy.com/yukicoder-no-886-direct</a>
* see: <a href="https://yukicoder.me/problems/no/1019/editorial">https://yukicoder.me/problems/no/1019/editorial</a>
* see: <a href="https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula">https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula</a>
* see: <a href="https://yukicoder.me/wiki/sum_totient">https://yukicoder.me/wiki/sum_totient</a>
* see: <a href="https://oi-wiki.org/math/du/">https://oi-wiki.org/math/du/</a>
* see: <a href="https://blog.bill.moe/multiplicative-function-sieves-notes/">https://blog.bill.moe/multiplicative-function-sieves-notes/</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/sum_of_totient_function.test.cpp.html">test/yosupo/sum_of_totient_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1019.dujiao.test.cpp.html">test/yukicoder/1019.dujiao.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/886.dujiao.test.cpp.html">test/yukicoder/886.dujiao.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 杜教筛
 * @category 数学
 * @see https://maspypy.com/yukicoder-no-886-direct
 * @see https://yukicoder.me/problems/no/1019/editorial
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
 * @see https://yukicoder.me/wiki/sum_totient
 * @see https://oi-wiki.org/math/du/
 * @see https://blog.bill.moe/multiplicative-function-sieves-notes/
 * @brief メモ化再帰で実装(map使ってるのでlogがつく)
 * @brief k==1ならO(N^(3/4)) (g,bの計算量無視)
 * @brief 前処理でN^(2/3)まで計算できるならO(N^(2/3))
 * @brief O(N^((k+2)/(k+1)^2))ぐらい?
 */

// input H,W,g,b,k
// output a(1)f(H,W)
//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])
//       b(d) = a(1)+a(2)+...+a(d)

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, typename G, typename A>
T dujiao_sieve(int64_t H, int64_t W, const G &g, const A &b,
               map<pair<int64_t, int64_t>, T> &memo, int k = 1) {
  if (memo.count(make_pair(H, W))) return memo[make_pair(H, W)];
  T ret = g(H, W);
  int64_t d = 2;
  while (true) {
    int64_t Hd = H / pow(d, k), Wd = W / pow(d, k);
    if (!Hd || !Wd) break;
    int64_t next_d
        = min(pow(1. * H / Hd, 1. / k), pow(1. * W / Wd, 1. / k)) + 1;
    T r = dujiao_sieve<T>(Hd, Wd, g, b, memo, k);
    ret -= r * (b(next_d - 1) - b(d - 1));
    d = next_d;
  }
  return memo[make_pair(H, W)] = ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/dujiao_sieve.hpp"
/**
 * @title 杜教筛
 * @category 数学
 * @see https://maspypy.com/yukicoder-no-886-direct
 * @see https://yukicoder.me/problems/no/1019/editorial
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
 * @see https://yukicoder.me/wiki/sum_totient
 * @see https://oi-wiki.org/math/du/
 * @see https://blog.bill.moe/multiplicative-function-sieves-notes/
 * @brief メモ化再帰で実装(map使ってるのでlogがつく)
 * @brief k==1ならO(N^(3/4)) (g,bの計算量無視)
 * @brief 前処理でN^(2/3)まで計算できるならO(N^(2/3))
 * @brief O(N^((k+2)/(k+1)^2))ぐらい?
 */

// input H,W,g,b,k
// output a(1)f(H,W)
//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])
//       b(d) = a(1)+a(2)+...+a(d)

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, typename G, typename A>
T dujiao_sieve(int64_t H, int64_t W, const G &g, const A &b,
               map<pair<int64_t, int64_t>, T> &memo, int k = 1) {
  if (memo.count(make_pair(H, W))) return memo[make_pair(H, W)];
  T ret = g(H, W);
  int64_t d = 2;
  while (true) {
    int64_t Hd = H / pow(d, k), Wd = W / pow(d, k);
    if (!Hd || !Wd) break;
    int64_t next_d
        = min(pow(1. * H / Hd, 1. / k), pow(1. * W / Wd, 1. / k)) + 1;
    T r = dujiao_sieve<T>(Hd, Wd, g, b, memo, k);
    ret -= r * (b(next_d - 1) - b(d - 1));
    d = next_d;
  }
  return memo[make_pair(H, W)] = ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

