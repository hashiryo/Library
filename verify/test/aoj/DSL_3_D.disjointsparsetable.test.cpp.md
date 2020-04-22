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


# :heavy_check_mark: test/aoj/DSL_3_D.disjointsparsetable.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D.disjointsparsetable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 02:23:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/DisjointSparseTable.hpp.html">Disjoint-Sparse-Table</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/DisjointSparseTable.hpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    auto f = [](int a, int b) { return min(a, b); };
    DisjointSparseTable<int> dst(a, f);
    for(int i = 0; i + L <= N; i++) {
        if(i)
            cout << " ";
        cout << dst.query(i, i + L);
    }
    cout << endl;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_3_D.disjointsparsetable.test.cpp"
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/DisjointSparseTable.hpp"
/**
 * @title Disjoint-Sparse-Table
 * @category データ構造
 * @brief fは結合則をみたす二項演算
 * @brief 構築 O(n log n)
 * @brief query O(1)
 */

#ifndef call_from_test
#line 11 "DataStructure/DisjointSparseTable.hpp"
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
#line 9 "test/aoj/DSL_3_D.disjointsparsetable.test.cpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];
    auto f = [](int a, int b) { return min(a, b); };
    DisjointSparseTable<int> dst(a, f);
    for(int i = 0; i + L <= N; i++) {
        if(i)
            cout << " ";
        cout << dst.query(i, i + L);
    }
    cout << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

