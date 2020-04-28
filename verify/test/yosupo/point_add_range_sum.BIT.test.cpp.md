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


# :heavy_check_mark: test/yosupo/point_add_range_sum.BIT.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_add_range_sum.BIT.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 00:25:18+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/BinaryIndexedTree.hpp.html">Binary-Indexed-Tree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/BinaryIndexedTree.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree bit(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    bit.add(i, a);
  }
  while (Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t)
      cout << bit[b] - bit[a] << endl;
    else
      bit.add(a, b);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_add_range_sum.BIT.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/BinaryIndexedTree.hpp"
/**
 * @title Binary-Indexed-Tree
 * @category データ構造
 * @brief O(logN)
 * @brief 0-indexed
 */

#ifndef call_from_test
#line 10 "DataStructure/BinaryIndexedTree.hpp"
using namespace std;
#endif

struct BinaryIndexedTree {
  vector<long long> dat;
  BinaryIndexedTree(int n) : dat(n + 1, 0) {}
  BinaryIndexedTree(int n, long long a)
      : BinaryIndexedTree(vector<long long>(n, a)) {}
  BinaryIndexedTree(vector<long long> y) : dat(y.size() + 1) {
    for (int k = 0; k < y.size(); ++k) dat[k + 1] = y[k];
    for (int k = 1; k + (k & -k) < dat.size(); ++k) dat[k + (k & -k)] += dat[k];
  }
  void add(int k, long long a) {
    for (++k; k < dat.size(); k += k & -k) dat[k] += a;
  }
  long long operator[](int k) {  // sum [0,k)
    long long s = 0;
    for (; k > 0; k &= k - 1) s += dat[k];
    return s;
  }
  // min{ k : sum(k) >= a }
  int lower_bound(long long a) const {
    int k = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (k + p < dat.size() && dat[k + p] < a) a -= dat[k += p];
    return k + 1 == dat.size() ? -1 : k;  // -1 => no solution
  }
};
#line 8 "test/yosupo/point_add_range_sum.BIT.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree bit(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    bit.add(i, a);
  }
  while (Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t)
      cout << bit[b] - bit[a] << endl;
    else
      bit.add(a, b);
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

