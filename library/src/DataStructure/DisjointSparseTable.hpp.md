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


# :question: Disjoint-Sparse-Table

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/DisjointSparseTable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2644.test.cpp.html">test/aoj/2644.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html">test/aoj/DSL_3_D.disjointsparsetable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Disjoint-Sparse-Table
 * @category データ構造
 * @brief fは結合則をみたす二項演算
 * @brief 構築 O(n log n)
 * @brief query O(1)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class T>
struct DisjointSparseTable {
  vector<vector<T>> ys;
  using F = function<T(T, T)>;
  const F f;
  DisjointSparseTable(vector<T> xs, F f_) : f(f_) {
    int n = 1;
    while (n <= xs.size()) n *= 2;
    xs.resize(n);
    ys.push_back(xs);
    for (int h = 1;; ++h) {
      int range = (2 << h), half = range / 2;
      if (range > n) break;
      ys.push_back(xs);
      for (int i = half; i < n; i += range) {
        for (int j = i - 2; j >= i - half; --j)
          ys[h][j] = f(ys[h][j], ys[h][j + 1]);
        for (int j = i + 1; j < min(n, i + half); ++j)
          ys[h][j] = f(ys[h][j - 1], ys[h][j]);
      }
    }
  }
  T query(int i, int j) {  // [i, j)
    if (i == --j) return ys[0][i];
    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(i ^ j);
    return f(ys[h][i], ys[h][j]);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/DisjointSparseTable.hpp"
/**
 * @title Disjoint-Sparse-Table
 * @category データ構造
 * @brief fは結合則をみたす二項演算
 * @brief 構築 O(n log n)
 * @brief query O(1)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class T>
struct DisjointSparseTable {
  vector<vector<T>> ys;
  using F = function<T(T, T)>;
  const F f;
  DisjointSparseTable(vector<T> xs, F f_) : f(f_) {
    int n = 1;
    while (n <= xs.size()) n *= 2;
    xs.resize(n);
    ys.push_back(xs);
    for (int h = 1;; ++h) {
      int range = (2 << h), half = range / 2;
      if (range > n) break;
      ys.push_back(xs);
      for (int i = half; i < n; i += range) {
        for (int j = i - 2; j >= i - half; --j)
          ys[h][j] = f(ys[h][j], ys[h][j + 1]);
        for (int j = i + 1; j < min(n, i + half); ++j)
          ys[h][j] = f(ys[h][j - 1], ys[h][j]);
      }
    }
  }
  T query(int i, int j) {  // [i, j)
    if (i == --j) return ys[0][i];
    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(i ^ j);
    return f(ys[h][i], ys[h][j]);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

