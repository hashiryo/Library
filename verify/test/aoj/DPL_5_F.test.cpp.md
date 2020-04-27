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


# :heavy_check_mark: test/aoj/DPL_5_F.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_5_F.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 16:54:44+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F</a>


## Depends on

* :question: <a href="../../../library/Math/Combination.hpp.html">組み合わせ</a>
* :question: <a href="../../../library/Math/ModInt.hpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/Combination.hpp"
#include "Math/ModInt.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  using Mint = ModInt<int(1e9 + 7)>;
  using C = Combination<Mint>;
  C::init(n + k);
  cout << C::H(n - k, k) << endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_5_F.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F"

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
  static Modint C(int n, int k) {
    if (n < k || k < 0) return Modint(0);
    return _fact[n] * _finv[n - k] * _finv[k];
  }
  static Modint P(int n, int k) {
    if (n < k || k < 0) return Modint(0);
    return _fact[n] * _finv[n - k];
  }
  static Modint H(int n, int k) {
    if (n < 0 || k < 0) return Modint(0);
    if (!n && !k) return Modint(1);
    return C(n + k - 1, n);
  }
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
#line 10 "test/aoj/DPL_5_F.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  using Mint = ModInt<int(1e9 + 7)>;
  using C = Combination<Mint>;
  C::init(n + k);
  cout << C::H(n - k, k) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

