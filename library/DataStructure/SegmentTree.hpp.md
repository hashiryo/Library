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


# :heavy_check_mark: Segment-Tree

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-01 23:22:39+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.SegTree.test.cpp.html">test/aoj/DSL_2_A.SegTree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html">test/yosupo/point_set_range_composite.SegTree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/649.SegTree.test.cpp.html">test/yukicoder/649.SegTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Segment-Tree
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M>
struct SegmentTree {
 private:
  using T = typename M::T;
  int n;
  vector<T> dat;
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
  // min { i : check(query(a,i)) = true }
  template <typename C>
  int find_first(int a, const C &check) {
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
  int find_last(int b, const C &check) {
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree.hpp"
/**
 * @title Segment-Tree
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M>
struct SegmentTree {
 private:
  using T = typename M::T;
  int n;
  vector<T> dat;
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
  // min { i : check(query(a,i)) = true }
  template <typename C>
  int find_first(int a, const C &check) {
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
  int find_last(int b, const C &check) {
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

