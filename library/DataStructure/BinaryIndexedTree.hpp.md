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


# :heavy_check_mark: Binary-Indexed-Tree

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryIndexedTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 00:26:14+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.BIT.test.cpp.html">test/yosupo/point_add_range_sum.BIT.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/649.BIT.test.cpp.html">test/yukicoder/649.BIT.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Binary-Indexed-Tree
 * @category データ構造
 * @brief O(logN)
 * @brief 0-indexed
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct BinaryIndexedTree {
  vector<long long> dat;
  BinaryIndexedTree(int n) : dat(n + 1, 0) {}
  BinaryIndexedTree(int n, long long a)
      : BinaryIndexedTree(vector<long long>(n, a)) {}
  BinaryIndexedTree(vector<long long> y) : dat(y.size() + 1) {
    for (int i = 0; i < y.size(); ++i) dat[i + 1] = y[i];
    for (int i = 1; i + (i & -i) < dat.size(); ++i) dat[i + (i & -i)] += dat[i];
  }
  void add(int i, long long a = 1) {
    for (++i; i < dat.size(); i += i & -i) dat[i] += a;
  }
  long long sum(int i) {  // sum [0,i)
    long long s = 0;
    for (; i > 0; i &= i - 1) s += dat[i];
    return s;
  }
  // min { i : sum(i+1) > k } -> kth element(0-indexed)
  int find(long long k) const {
    int i = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (i + p < dat.size() && dat[i + p] <= k) k -= dat[i += p];
    return i + 1 == dat.size() ? -1 : i;  // -1 -> no solutions
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryIndexedTree.hpp"
/**
 * @title Binary-Indexed-Tree
 * @category データ構造
 * @brief O(logN)
 * @brief 0-indexed
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct BinaryIndexedTree {
  vector<long long> dat;
  BinaryIndexedTree(int n) : dat(n + 1, 0) {}
  BinaryIndexedTree(int n, long long a)
      : BinaryIndexedTree(vector<long long>(n, a)) {}
  BinaryIndexedTree(vector<long long> y) : dat(y.size() + 1) {
    for (int i = 0; i < y.size(); ++i) dat[i + 1] = y[i];
    for (int i = 1; i + (i & -i) < dat.size(); ++i) dat[i + (i & -i)] += dat[i];
  }
  void add(int i, long long a = 1) {
    for (++i; i < dat.size(); i += i & -i) dat[i] += a;
  }
  long long sum(int i) {  // sum [0,i)
    long long s = 0;
    for (; i > 0; i &= i - 1) s += dat[i];
    return s;
  }
  // min { i : sum(i+1) > k } -> kth element(0-indexed)
  int find(long long k) const {
    int i = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (i + p < dat.size() && dat[i + p] <= k) k -= dat[i += p];
    return i + 1 == dat.size() ? -1 : i;  // -1 -> no solutions
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

