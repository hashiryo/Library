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


# :heavy_check_mark: test/yosupo/point_set_range_composite.SegTree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_set_range_composite.SegTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 01:15:16+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/SegmentTree.hpp.html">Segment-Tree</a>
* :heavy_check_mark: <a href="../../../library/Math/ModInt.hpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/SegmentTree.hpp"
#include "Math/ModInt.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;
struct RcompositeQ {
  using T = pair<Mint, Mint>;
  static T ti() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<RcompositeQ::T> v(N);
  for (int i = 0; i < N; i++) {
    Mint a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  SegmentTree<RcompositeQ> seg(v);
  while (Q--) {
    bool op;
    cin >> op;
    if (op) {
      int l, r;
      Mint x;
      cin >> l >> r >> x;
      auto ans = seg.query(l, r);
      cout << ans.first * x + ans.second << endl;
    } else {
      int p;
      Mint c, d;
      cin >> p >> c >> d;
      seg.set_val(p, {c, d});
    }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_set_range_composite.SegTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/SegmentTree.hpp"
/**
 * @title Segment-Tree
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#line 9 "DataStructure/SegmentTree.hpp"
using namespace std;
#endif

template <typename M>
struct SegmentTree {
  using T = typename M::T;

 private:
  const int n;
  vector<T> dat;

 private:
  template <typename C>
  int find_subtree(int a, const C &check, T &cur, bool type) {
    while (a < n) {
      T nxt
          = type ? M::f(dat[2 * a + type], cur) : M::f(cur, dat[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        cur = nxt, a = 2 * a + !type;
    }
    return a - n;
  }

 public:
  SegmentTree() {}
  SegmentTree(int n_, T v1 = M::ti()) : SegmentTree(vector<T>(n_, v1)) {}
  SegmentTree(const vector<T> &v)
      : n(1 << int(ceil(log2(v.size())))), dat(n << 1, M::ti()) {
    for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
    for (int i = n - 1; i >= 1; i--)
      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);
  }
  void set_val(int k, T x) {
    for (dat[k += n] = x; k >>= 1;)
      dat[k] = M::f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  //[a,b)
  T query(int a, int b) {
    T vl = M::ti(), vr = M::ti();
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = M::f(vl, dat[l++]);
      if (r & 1) vr = M::f(dat[--r], vr);
    }
    return M::f(vl, vr);
  }
  T operator[](const int &k) const { return dat[k + n]; }
  // min { i : check(query(a,i+1)) = true }
  template <typename C>
  int find_first(const C &check, int a = 0) {
    T vl = M::ti();
    if (a <= 0) {
      if (check(M::f(vl, dat[1]))) return find_subtree(1, check, vl, false);
      return -1;
    }
    int b = n;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (a & 1) {
        T nxt = M::f(vl, dat[a]);
        if (check(nxt)) return find_subtree(a, check, vl, false);
        vl = nxt;
        ++a;
      }
    return -1;
  }
  // max { i : check(query(i,b)) = true }
  template <typename C>
  int find_last(const C &check, int b = -1) {
    if (b < 0) b = n;
    T vr = M::ti();
    if (b >= n) {
      if (check(M::f(dat[1], vr))) return find_subtree(1, check, vr, true);
      return -1;
    }
    int a = 0;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (b & 1) {
        T nxt = M::f(dat[--b], vr);
        if (check(nxt)) return find_subtree(b, check, vr, true);
        vr = nxt;
      }
    return -1;
  }
};
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
#line 9 "test/yosupo/point_set_range_composite.SegTree.test.cpp"
#undef call_from_test

using Mint = ModInt<998244353>;
struct RcompositeQ {
  using T = pair<Mint, Mint>;
  static T ti() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<RcompositeQ::T> v(N);
  for (int i = 0; i < N; i++) {
    Mint a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  SegmentTree<RcompositeQ> seg(v);
  while (Q--) {
    bool op;
    cin >> op;
    if (op) {
      int l, r;
      Mint x;
      cin >> l >> r >> x;
      auto ans = seg.query(l, r);
      cout << ans.first * x + ans.second << endl;
    } else {
      int p;
      Mint c, d;
      cin >> p >> c >> d;
      seg.set_val(p, {c, d});
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

