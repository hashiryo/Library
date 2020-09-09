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


# :heavy_check_mark: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 17:41:10+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :question: <a href="../../../library/src/DataStructure/SegmentTree_Lazy.hpp.html">Segment-Tree(遅延伝搬)</a>
* :question: <a href="../../../library/src/Math/ModInt.hpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/SegmentTree_Lazy.hpp"
#include "src/Math/ModInt.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;
// RsumQはモノイドでサイズを持っておく
struct RaffineQ_RsumQ {
  struct T {
    Mint val;
    int size;
    T(Mint v = 0, int s = 1) : val(v), size(s) {}
  };
  using E = pair<Mint, Mint>;
  static T ti() { return T(0, 0); }
  static E ei() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return T(l.val + r.val, l.size + r.size);
  }
  static T g(const T &l, const E &r) {
    return T(r.first * l.val + r.second * l.size, l.size);
  }
  static E h(const E &l, const E &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<RaffineQ_RsumQ::T> v(N);
  for (int i = 0; i < N; i++) {
    Mint a;
    cin >> a;
    v[i] = {a, 1};
  }
  SegmentTree_Lazy<RaffineQ_RsumQ> seg(v);
  while (Q--) {
    bool op;
    int l, r;
    cin >> op >> l >> r;
    if (op) {
      cout << seg.query(l, r).val << endl;
    } else {
      Mint b, c;
      cin >> b >> c;
      seg.update(l, r, {Mint(b), Mint(c)});
    }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/DataStructure/SegmentTree_Lazy.hpp"
/**
 * @title Segment-Tree(遅延伝搬)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#line 9 "src/DataStructure/SegmentTree_Lazy.hpp"
using namespace std;
#endif

template <typename M>
struct SegmentTree_Lazy {
  using T = typename M::T;
  using E = typename M::E;

 private:
  const int height, n;
  vector<T> dat;
  vector<E> laz;

 private:
  inline T reflect(int k) {
    return laz[k] == M::ei() ? dat[k] : M::g(dat[k], laz[k]);
  }
  inline void eval(int k) {
    if (laz[k] == M::ei()) return;
    laz[(k << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = M::h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = M::ei();
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1) dat[k] = M::f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  template <typename C>
  int find_subtree(int a, const C& check, T& cur, bool type) {
    while (a < n) {
      eval(a);
      T nxt = type ? M::f(reflect(2 * a + type), cur)
                   : M::f(cur, reflect(2 * a + type));
      if (check(nxt))
        a = 2 * a + type;
      else
        cur = nxt, a = 2 * a + !type;
    }
    return a - n;
  }

 public:
  SegmentTree_Lazy() {}
  SegmentTree_Lazy(int n_, T v1 = M::ti())
      : SegmentTree_Lazy(vector<T>(n_, v1)) {}
  SegmentTree_Lazy(const vector<T>& v)
      : height(ceil(log2(v.size()))),
        n(1 << height),
        dat(n * 2, M::ti()),
        laz(n * 2, M::ei()) {
    for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
    for (int i = n - 1; i >= 1; i--)
      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = M::h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = M::h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = M::ei();
    recalc(a);
  }
  //[a,b)
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = M::ti(), vr = M::ti();
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = M::f(vl, reflect(l++));
      if (r & 1) vr = M::f(reflect(--r), vr);
    }
    return M::f(vl, vr);
  }
  T operator[](const int k) { return query(k, k + 1); }
  // min { i : check(query(a,i+1)) = true }
  template <typename C>
  int find_first(const C& check, int a = 0) {
    T vl = M::ti();
    if (a <= 0) {
      if (check(M::f(vl, reflect(1)))) return find_subtree(1, check, vl, false);
      return -1;
    }
    thrust(a + n);
    int b = n;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (a & 1) {
        T nxt = M::f(vl, reflect(a));
        if (check(nxt)) return find_subtree(a, check, vl, false);
        vl = nxt;
        ++a;
      }
    return -1;
  }
  // max { i : check(query(i,b)) = true }
  template <typename C>
  int find_last(const C& check, int b = -1) {
    if (b < 0) b = n;
    T vr = M::ti();
    if (b >= n) {
      if (check(M::f(reflect(1), vr))) return find_subtree(1, check, vr, true);
      return -1;
    }
    thrust(b + n - 1);
    int a = 0;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (b & 1) {
        T nxt = M::f(reflect(--b), vr);
        if (check(nxt)) return find_subtree(b, check, vr, true);
        vr = nxt;
      }
    return -1;
  }
};
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
  int get() const { return x; }
};
#line 9 "test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp"
#undef call_from_test

using Mint = ModInt<998244353>;
// RsumQはモノイドでサイズを持っておく
struct RaffineQ_RsumQ {
  struct T {
    Mint val;
    int size;
    T(Mint v = 0, int s = 1) : val(v), size(s) {}
  };
  using E = pair<Mint, Mint>;
  static T ti() { return T(0, 0); }
  static E ei() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return T(l.val + r.val, l.size + r.size);
  }
  static T g(const T &l, const E &r) {
    return T(r.first * l.val + r.second * l.size, l.size);
  }
  static E h(const E &l, const E &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<RaffineQ_RsumQ::T> v(N);
  for (int i = 0; i < N; i++) {
    Mint a;
    cin >> a;
    v[i] = {a, 1};
  }
  SegmentTree_Lazy<RaffineQ_RsumQ> seg(v);
  while (Q--) {
    bool op;
    int l, r;
    cin >> op >> l >> r;
    if (op) {
      cout << seg.query(l, r).val << endl;
    } else {
      Mint b, c;
      cin >> b >> c;
      seg.update(l, r, {Mint(b), Mint(c)});
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

