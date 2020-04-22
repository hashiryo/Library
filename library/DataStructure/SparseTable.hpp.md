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


# :heavy_check_mark: Sparse-Table

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SparseTable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 02:23:27+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html">test/aoj/DSL_3_D.sparsetable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Sparse-Table
 * @category データ構造
 * @brief RmQ
 * @brief 構築 O(n log n)
 * @brief query O(1)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class T>
struct SparseTable {
  const vector<T> &x;
  vector<vector<int>> table;
  int argmin(int i, int j) { return x[i] < x[j] ? i : j; }
  SparseTable(const vector<T> &x) : x(x) {
    int logn = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(x.size());
    table.assign(logn + 1, vector<int>(x.size()));
    iota(table[0].begin(), table[0].end(), 0);
    for (int h = 0; h + 1 <= logn; ++h)
      for (int i = 0; i + (1 << h) < x.size(); ++i)
        table[h + 1][i] = argmin(table[h][i], table[h][i + (1 << h)]);
  }
  T range_min(int i, int j) {  // = min x[i,j)
    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(j - i);  // = log2
    return x[argmin(table[h][i], table[h][j - (1 << h)])];
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SparseTable.hpp"
/**
 * @title Sparse-Table
 * @category データ構造
 * @brief RmQ
 * @brief 構築 O(n log n)
 * @brief query O(1)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <class T>
struct SparseTable {
  const vector<T> &x;
  vector<vector<int>> table;
  int argmin(int i, int j) { return x[i] < x[j] ? i : j; }
  SparseTable(const vector<T> &x) : x(x) {
    int logn = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(x.size());
    table.assign(logn + 1, vector<int>(x.size()));
    iota(table[0].begin(), table[0].end(), 0);
    for (int h = 0; h + 1 <= logn; ++h)
      for (int i = 0; i + (1 << h) < x.size(); ++i)
        table[h + 1][i] = argmin(table[h][i], table[h][i + (1 << h)]);
  }
  T range_min(int i, int j) {  // = min x[i,j)
    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(j - i);  // = log2
    return x[argmin(table[h][i], table[h][j - (1 << h)])];
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

