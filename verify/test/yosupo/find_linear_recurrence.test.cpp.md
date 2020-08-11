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


# :x: test/yosupo/find_linear_recurrence.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/find_linear_recurrence.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 17:25:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/find_linear_recurrence">https://judge.yosupo.jp/problem/find_linear_recurrence</a>


## Depends on

* :question: <a href="../../../library/src/Math/ModInt.hpp.html">ModInt</a>
* :x: <a href="../../../library/src/Math/berlekamp_massey.hpp.html">Berlekamp-Massey</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Math/ModInt.hpp"
#include "src/Math/berlekamp_massey.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Mint = ModInt<998244353>;
  int N;
  cin >> N;
  vector<Mint> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  vector<Mint> c = berlekamp_massey(a);
  int d = c.size();
  cout << d << endl;
  for (int i = 0; i < d; i++) cout << (i ? " " : "") << c[d - 1 - i];
  cout << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/find_linear_recurrence.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#line 8 "src/Math/ModInt.hpp"
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
#line 1 "src/Math/berlekamp_massey.hpp"
/**
 * @title Berlekamp-Massey
 * @category 数学
 * @brief　数列の最初のN項から、その数列を生成するN/2次以下の最小の線形漸化式を求める
 * @brief O(N^2)
 */

// verify用:
// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c

#ifndef call_from_test
#line 13 "src/Math/berlekamp_massey.hpp"
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
#line 9 "test/yosupo/find_linear_recurrence.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Mint = ModInt<998244353>;
  int N;
  cin >> N;
  vector<Mint> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  vector<Mint> c = berlekamp_massey(a);
  int d = c.size();
  cout << d << endl;
  for (int i = 0; i < d; i++) cout << (i ? " " : "") << c[d - 1 - i];
  cout << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

