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


# :heavy_check_mark: Binary-Indexed-Tree(2次元)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/BinaryIndexedTree_2D.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2842.BIT_2D.test.cpp.html">test/aoj/2842.BIT_2D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Binary-Indexed-Tree(2次元)
 * @category データ構造
 * @brief O(logHW)
 * @brief 1-indexed
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T>
struct BinaryIndexedTree_2D {
  using vT = vector<T>;
  vector<vT> dat;
  BinaryIndexedTree_2D(int H, int W) : dat(vector<vT>(H + 1, vT(W + 1, 0))) {}
  void add(int y, int x, T v) {
    for (int i = y; i < dat.size(); i += i & -i)
      for (int j = x; j < dat[i].size(); j += j & -j) dat[i][j] += v;
  }
  T sum(int y, int x) {  // sum (0,y] * (0,x]
    T ret = 0;
    for (int i = y; i > 0; i -= i & -i)
      for (int j = x; j > 0; j -= j & -j) ret += dat[i][j];
    return ret;
  }
  T sum(int sy, int sx, int ty, int tx) {  // sum (sy,ty] * (sx,tx]
    return sum(ty, tx) - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/BinaryIndexedTree_2D.hpp"
/**
 * @title Binary-Indexed-Tree(2次元)
 * @category データ構造
 * @brief O(logHW)
 * @brief 1-indexed
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T>
struct BinaryIndexedTree_2D {
  using vT = vector<T>;
  vector<vT> dat;
  BinaryIndexedTree_2D(int H, int W) : dat(vector<vT>(H + 1, vT(W + 1, 0))) {}
  void add(int y, int x, T v) {
    for (int i = y; i < dat.size(); i += i & -i)
      for (int j = x; j < dat[i].size(); j += j & -j) dat[i][j] += v;
  }
  T sum(int y, int x) {  // sum (0,y] * (0,x]
    T ret = 0;
    for (int i = y; i > 0; i -= i & -i)
      for (int j = x; j > 0; j -= j & -j) ret += dat[i][j];
    return ret;
  }
  T sum(int sy, int sx, int ty, int tx) {  // sum (sy,ty] * (sx,tx]
    return sum(ty, tx) - sum(ty, sx) - sum(sy, tx) + sum(sy, sx);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

