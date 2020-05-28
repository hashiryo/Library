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


# :heavy_check_mark: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_G.BIT_rangeadd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 00:58:18+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/BinaryIndexedTree_RangeAdd.hpp.html">Binary-Indexed-Tree(区間加算)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/BinaryIndexedTree_RangeAdd.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree_RangeAdd<long long> bit(N);
  while (Q--) {
    int op, s, t;
    cin >> op >> s >> t;
    s--, t--;
    if (op)
      cout << bit.sum(t + 1) - bit.sum(s) << endl;
    else {
      long long x;
      cin >> x;
      bit.add_range(s, t + 1, x);
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_G.BIT_rangeadd.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/BinaryIndexedTree_RangeAdd.hpp"
/**
 * @title Binary-Indexed-Tree(区間加算)
 * @category データ構造
 * @brief O(logN)
 * @brief 0-indexed
 */

#ifndef call_from_test
#line 10 "DataStructure/BinaryIndexedTree_RangeAdd.hpp"
using namespace std;
#endif

template <typename T>
struct BinaryIndexedTree_RangeAdd {
  vector<T> dat1;
  vector<T> dat2;
  BinaryIndexedTree_RangeAdd(int n) : dat1(n + 1, 0), dat2(n + 1, 0) {}
  void add_range(int l, int r, T w) {  // add w [l,r)
    for (int k = l + 1; k < (int)dat1.size(); k += k & -k) dat1[k] -= w * l;
    for (int k = r + 1; k < (int)dat1.size(); k += k & -k) dat1[k] += w * r;
    for (int k = l + 1; k < (int)dat2.size(); k += k & -k) dat2[k] += w;
    for (int k = r + 1; k < (int)dat2.size(); k += k & -k) dat2[k] -= w;
  }
  T sum(int x) {  // sum [0,x)
    T s = 0;
    for (int k = x; k > 0; k &= k - 1) s += dat1[k];
    for (int k = x; k > 0; k &= k - 1) s += dat2[k] * x;
    return s;
  }
};
#line 9 "test/aoj/DSL_2_G.BIT_rangeadd.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree_RangeAdd<long long> bit(N);
  while (Q--) {
    int op, s, t;
    cin >> op >> s >> t;
    s--, t--;
    if (op)
      cout << bit.sum(t + 1) - bit.sum(s) << endl;
    else {
      long long x;
      cin >> x;
      bit.add_range(s, t + 1, x);
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

