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


# :heavy_check_mark: test/aoj/DSL_2_D.SegTree_Dual.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_D.SegTree_Dual.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 12:06:16+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/SegmentTree_Dual.hpp.html">Segment-Tree(双対)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/SegmentTree_Dual.hpp"
#undef call_from_test

struct RupdQ {
  using T = int;
  using E = int;
  static E ei() { return INT_MAX; }
  static T g(const T& l, const E& r) { return r == ei() ? l : r; }
  static E h(const E& l, const E& r) { return r == ei() ? l : r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);
  while (q--) {
    bool com;
    cin >> com;
    if (com) {
      int i;
      cin >> i;
      cout << seg[i] << endl;
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      seg.update(s, t + 1, x);
    }
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_D.SegTree_Dual.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/SegmentTree_Dual.hpp"
/**
 * @title Segment-Tree(双対)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#line 9 "DataStructure/SegmentTree_Dual.hpp"
using namespace std;
#endif

template <typename M>
struct SegmentTree_Dual {
  using T = typename M::T;
  using E = typename M::E;

 private:
  const int height, n;
  vector<T> val;
  vector<E> laz;

 private:
  inline void eval(int k) {
    if (laz[k] == M::ei()) return;
    laz[(k << 1) | 0] = M::h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = M::h(laz[(k << 1) | 1], laz[k]);
    laz[k] = M::ei();
  }
  inline void thrust(int k) {
    for (int i = height; i; i--) eval(k >> i);
  }

 public:
  SegmentTree_Dual() {}
  SegmentTree_Dual(int n_, T v1 = T()) : SegmentTree_Dual(vector<T>(n_, v1)) {}
  SegmentTree_Dual(const vector<T>& v)
      : height(ceil(log2(v.size()))),
        n(1 << height),
        val(v),
        laz(n * 2, M::ei()) {}
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = M::h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = M::h(laz[r], x);
    }
  }
  void set_val(int a, T x) {
    thrust(a += n);
    val[a] = x;
    laz[a] = M::ei();
  }
  T operator[](const int k) {
    thrust(k + n);
    if (laz[k + n] != M::ei()) {
      val[k] = M::g(val[k], laz[k + n]);
      laz[k + n] = M::ei();
    }
    return val[k];
  }
};
#line 9 "test/aoj/DSL_2_D.SegTree_Dual.test.cpp"
#undef call_from_test

struct RupdQ {
  using T = int;
  using E = int;
  static E ei() { return INT_MAX; }
  static T g(const T& l, const E& r) { return r == ei() ? l : r; }
  static E h(const E& l, const E& r) { return r == ei() ? l : r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);
  while (q--) {
    bool com;
    cin >> com;
    if (com) {
      int i;
      cin >> i;
      cout << seg[i] << endl;
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      seg.update(s, t + 1, x);
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

