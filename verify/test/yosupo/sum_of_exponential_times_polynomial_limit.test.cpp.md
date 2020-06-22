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


# :heavy_check_mark: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 17:39:38+09:00


* see: <a href="https://min-25.hatenablog.com/entry/2015/04/24/031413">https://min-25.hatenablog.com/entry/2015/04/24/031413</a>
* see: <a href="https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit">https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Math/Combination.hpp.html">組み合わせ</a>
* :question: <a href="../../../library/Math/ModInt.hpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413
 */
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/Combination.hpp"
#include "Math/ModInt.hpp"
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
  long long r, d;
  cin >> r >> d;
  vector<Mint> sum(d + 1), rpow(d + 1), pd = pow_d_list<Mint>(d + 1, d);
  rpow[0] = 1, sum[0] = rpow[0] * pd[0];
  for (int i = 1; i <= d; i++) rpow[i] = rpow[i - 1] * r;
  for (int i = 1; i <= d; i++) sum[i] = sum[i - 1] + rpow[i] * pd[i];
  Mint ans = 0;
  C::init(d + 1);
  for (int i = 0; i <= d; i++) {
    Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];
    ans += (d - i) & 1 ? -tmp : tmp;
  }
  ans /= Mint(1 - r).pow(d + 1);
  cout << ans << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp"
#define PROBLEM \
  "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413
 */
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Math/Combination.hpp"
/**
 * @title 組み合わせ
 * @category 数学
 */

#ifndef call_from_test
#line 8 "Math/Combination.hpp"
using namespace std;
#endif

template <class Modint>
struct Combination {
  static vector<Modint> _fact, _finv, _inv;
  static void init(int sz) {
    int n = min(2 * sz, Modint::modulo() - 1);
    _fact.resize(n + 1), _finv.resize(n + 1), _inv.resize(n + 1);
    for (int i = 0; i <= n; ++i) _fact[i] = i ? Modint(i) * _fact[i - 1] : 1;
    _finv[n] = _fact[n].inverse();
    for (int i = n; i; --i) _finv[i - 1] = Modint(i) * _finv[i];
    for (int i = 1; i <= n; ++i) _inv[i] = _finv[i] * _fact[i - 1];
  }
  static Modint inverse(int n) { return _inv[n]; }
  static Modint fact(int n, bool inv = 0) { return inv ? _finv[n] : _fact[n]; }
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
#line 1 "Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#line 8 "Math/ModInt.hpp"
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
#line 12 "test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp"
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
  long long r, d;
  cin >> r >> d;
  vector<Mint> sum(d + 1), rpow(d + 1), pd = pow_d_list<Mint>(d + 1, d);
  rpow[0] = 1, sum[0] = rpow[0] * pd[0];
  for (int i = 1; i <= d; i++) rpow[i] = rpow[i - 1] * r;
  for (int i = 1; i <= d; i++) sum[i] = sum[i - 1] + rpow[i] * pd[i];
  Mint ans = 0;
  C::init(d + 1);
  for (int i = 0; i <= d; i++) {
    Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];
    ans += (d - i) & 1 ? -tmp : tmp;
  }
  ans /= Mint(1 - r).pow(d + 1);
  cout << ans << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

