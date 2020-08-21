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


# :question: ModInt

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/ModInt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0168.test.cpp.html">test/aoj/0168.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2530.test.cpp.html">test/aoj/2530.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3072.test.cpp.html">test/aoj/3072.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/bernoulli.test.cpp.html">test/yosupo/bernoulli.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/comp_of_FPS.test.cpp.html">test/yosupo/comp_of_FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/convolution1000000007.test.cpp.html">test/yosupo/convolution1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp.html">test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/exp_of_FPS.test.cpp.html">test/yosupo/exp_of_FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/find_linear_recurrence.test.cpp.html">test/yosupo/find_linear_recurrence.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/inv_of_FPS.test.cpp.html">test/yosupo/inv_of_FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/linear_equations.test.cpp.html">test/yosupo/linear_equations.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/log_of_FPS.test.cpp.html">test/yosupo/log_of_FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/partition.test.cpp.html">test/yosupo/partition.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html">test/yosupo/point_set_range_composite.SegTree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/pow_of_FPS.test.cpp.html">test/yosupo/pow_of_FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/range_affine_range_sum.RBTL.test.cpp.html">test/yosupo/range_affine_range_sum.RBTL.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp.html">test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/sharp_p_subset_sum.test.cpp.html">test/yosupo/sharp_p_subset_sum.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/shift_of_FPS.test.cpp.html">test/yosupo/shift_of_FPS.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/sqrt_of_FPS.test.cpp.html">test/yosupo/sqrt_of_FPS.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/stirling_first.test.cpp.html">test/yosupo/stirling_first.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/stirling_second.test.cpp.html">test/yosupo/stirling_second.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/sum_of_exponential_times_polynomial_limit.FPS.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial_limit.FPS.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp.html">test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/sum_of_totient_function.test.cpp.html">test/yosupo/sum_of_totient_function.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1019.dujiao.test.cpp.html">test/yukicoder/1019.dujiao.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/196.test.cpp.html">test/yukicoder/196.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/1973.test.cpp.html">test/yukicoder/1973.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/22.test.cpp.html">test/yukicoder/22.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/3046.test.cpp.html">test/yukicoder/3046.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/3211.test.cpp.html">test/yukicoder/3211.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/444.test.cpp.html">test/yukicoder/444.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/644.test.cpp.html">test/yukicoder/644.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/665.test.cpp.html">test/yukicoder/665.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/803.test.cpp.html">test/yukicoder/803.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/886.dujiao.test.cpp.html">test/yukicoder/886.dujiao.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/886.numth.test.cpp.html">test/yukicoder/886.numth.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) { return *this *= p.inverse(); }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
    return ModInt(u);
  }
  ModInt pow(int64_t e) const {
    ModInt ret(1);
    for (ModInt b = *this; e; e >>= 1, b *= b)
      if (e & 1) ret *= b;
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int modulo() { return mod; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) { return *this *= p.inverse(); }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
    return ModInt(u);
  }
  ModInt pow(int64_t e) const {
    ModInt ret(1);
    for (ModInt b = *this; e; e >>= 1, b *= b)
      if (e & 1) ret *= b;
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int modulo() { return mod; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

