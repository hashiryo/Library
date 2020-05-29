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


# :heavy_check_mark: Segment-Tree(双対)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree_Dual.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 12:06:16+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp.html">test/aoj/DSL_2_D.SegTree_Dual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Segment-Tree(双対)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree_Dual.hpp"
/**
 * @title Segment-Tree(双対)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

