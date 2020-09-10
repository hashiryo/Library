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
    - Last commit date: 2020-09-09 18:34:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/BinaryIndexedTree.hpp.html">Binary-Indexed-Tree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/BinaryIndexedTree.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree<long long> bit(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    bit.add(i, a);
  }
  while (Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t)
      cout << bit.sum(b) - bit.sum(a) << endl;
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
#line 1 "src/DataStructure/BinaryIndexedTree.hpp"
/**
 * @title Binary-Indexed-Tree
 * @category データ構造
 *  O(logN)
 *  0-indexed
 */

#ifndef call_from_test
#line 10 "src/DataStructure/BinaryIndexedTree.hpp"
using namespace std;
#endif

template <typename T>
struct BinaryIndexedTree {
  vector<T> dat;
  BinaryIndexedTree(int n) : dat(n + 1, 0) {}
  BinaryIndexedTree(int n, T a) : BinaryIndexedTree(vector<T>(n, a)) {}
  BinaryIndexedTree(vector<T> y) : dat(y.size() + 1, 0) {
    for (size_t i = 0; i < y.size(); ++i) dat[i + 1] = y[i];
    for (int i = 1; i < (int)dat.size(); ++i)
      if (i + (i & -i) < (int)dat.size()) dat[i + (i & -i)] += dat[i];
  }
  void add(int i, T a = 1) {
    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;
  }
  T sum(int i) {  // sum [0,i)
    T s = 0;
    for (; i > 0; i &= i - 1) s += dat[i];
    return s;
  }
  // sum [l,r)
  T sum(int l, int r) { return sum(r) - sum(l); }
  T operator[](size_t k) { return sum(k + 1) - sum(k); }
  // min { i : sum(i+1) > k } -> kth element(0-indexed)
  int find(T k) const {
    int i = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (i + p < (int)dat.size() && dat[i + p] <= k) k -= dat[i += p];
    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no solutions
  }
};
#line 8 "test/yosupo/point_add_range_sum.BIT.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree<long long> bit(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    bit.add(i, a);
  }
  while (Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t)
      cout << bit.sum(b) - bit.sum(a) << endl;
    else
      bit.add(a, b);
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

