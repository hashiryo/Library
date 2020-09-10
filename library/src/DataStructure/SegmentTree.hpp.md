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


# :heavy_check_mark: Segment-Tree

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/SegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 13:44:33+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A.SegTree.test.cpp.html">test/aoj/DSL_2_A.SegTree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html">test/yosupo/point_set_range_composite.SegTree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/649.SegTree.test.cpp.html">test/yukicoder/649.SegTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Segment-Tree
 * @category データ構造
 * O(logN)
 * 2冪にしていない(メモリ節約)
 */

// 2冪にするのやめて二次元array(10x10)をのせることに成功
// https://atcoder.jp/contests/arc027/tasks/arc027_4

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

