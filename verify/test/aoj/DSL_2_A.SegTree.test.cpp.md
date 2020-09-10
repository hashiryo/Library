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


# :heavy_check_mark: test/aoj/DSL_2_A.SegTree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_A.SegTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 13:44:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/SegmentTree.hpp.html">Segment-Tree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/SegmentTree.hpp"
#undef call_from_test

struct RminQ {
  using T = int;
  static T ti() { return INT_MAX; }
  static T f(const T &l, const T &r) { return min(l, r); }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegmentTree<RminQ> seg(n);
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      cout << seg.query(x, y + 1) << endl;
    } else {
      seg.set_val(x, y);
    }
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_A.SegTree.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/DataStructure/SegmentTree.hpp"
/**
 * @title Segment-Tree
 * @category データ構造
 * O(logN)
 * 2冪にしていない(メモリ節約)
 */

// 2冪にするのやめて二次元array(10x10)をのせることに成功
// https://atcoder.jp/contests/arc027/tasks/arc027_4

#ifndef call_from_test
#line 13 "src/DataStructure/SegmentTree.hpp"
using namespace std;
#endif

template <typename M>
struct SegmentTree {
  using T = typename M::T;

 private:
  const int n;
  vector<T> dat;

 public:
  SegmentTree() {}
  SegmentTree(int n_) : n(n_), dat(n << 1, M::ti()) {}
  SegmentTree(int n_, T v) : SegmentTree(vector<T>(n_, v)) {}
  SegmentTree(const vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {
    for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
    rebuild();
  }
  void set_val(int k, T x) {
    for (dat[k += n] = x; k >>= 1;)
      dat[k] = M::f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  void unsafe_set(int k, T x) { dat[k + n] = x; }
  void rebuild() {
    for (int i = n - 1; i >= 1; i--)
      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);
  }
  void clear() { fill(dat.begin(), dat.end(), M::ti()); }
  //[l,r)
  inline T query(int l, int r) {
    T vl = M::ti(), vr = M::ti();
    for (int a = l + n, b = r + n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) vl = M::f(vl, dat[a++]);
      if (b & 1) vr = M::f(dat[--b], vr);
    }
    return M::f(vl, vr);
  }
  T operator[](const int &k) const { return dat[k + n]; }

  // max{ i : check(query(l,i+1)) = true}
  template <class C>
  int find_right(const C &check, int l = 0) {
    assert(check(M::ti()));
    if (l == n) return n;
    vector<int> idl, idr;
    for (int a = l + n, b = 2 * n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) idl.push_back(a++);
      if (b & 1) idr.push_back(--b);
    }
    for (auto itr = idr.rbegin(); itr != idr.rend(); itr++) idl.push_back(*itr);
    T val = M::ti();
    for (int i : idl) {
      if (!check(M::f(val, dat[i]))) {
        while (i < n) {
          i = i << 1 | 0;
          if (check(M::f(val, dat[i]))) val = M::f(val, dat[i++]);
        }
        return i - n;
      }
      val = M::f(val, dat[i]);
    }
    return n;
  }
  //   min { i : check(query(i,r)) = true }
  template <class C>
  int find_left(const C &check, int r = -1) {
    if (r < 0) r = n;
    assert(check(M::ti()));
    if (r == 0) return 0;
    vector<int> idl, idr;
    for (int a = n, b = r + n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) idl.push_back(a++);
      if (b & 1) idr.push_back(--b);
    }
    for (auto itr = idl.rbegin(); itr != idl.rend(); itr++) idr.push_back(*itr);
    T val = M::ti();
    for (int i : idr) {
      if (!check(M::f(dat[i], val))) {
        while (i < n) {
          i = i << 1 | 1;
          if (check(M::f(dat[i], val))) val = M::f(dat[i--], val);
        }
        return i + 1 - n;
      }
      val = M::f(dat[i], val);
    }
    return 0;
  }
};
#line 9 "test/aoj/DSL_2_A.SegTree.test.cpp"
#undef call_from_test

struct RminQ {
  using T = int;
  static T ti() { return INT_MAX; }
  static T f(const T &l, const T &r) { return min(l, r); }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  SegmentTree<RminQ> seg(n);
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      cout << seg.query(x, y + 1) << endl;
    } else {
      seg.set_val(x, y);
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

