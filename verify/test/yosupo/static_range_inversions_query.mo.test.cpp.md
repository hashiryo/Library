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


# :x: test/yosupo/static_range_inversions_query.mo.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/static_range_inversions_query.mo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:06:06+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_inversions_query">https://judge.yosupo.jp/problem/static_range_inversions_query</a>


## Depends on

* :question: <a href="../../../library/src/Algorithm/Mo.hpp.html">Mo</a>
* :x: <a href="../../../library/src/DataStructure/BinaryIndexedTree.hpp.html">Binary-Indexed-Tree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Algorithm/Mo.hpp"
#include "src/DataStructure/BinaryIndexedTree.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<int> v(A, A + N);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < N; i++)
    A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
  Mo mo(N);
  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    mo.query(l, r);
  }
  BinaryIndexedTree<long long> bit(N + 1);
  long long inv = 0, total = 0;
  auto addl = [&](int i) {
    inv += bit.sum(A[i]);
    bit.add(A[i], 1);
    total++;
  };
  auto addr = [&](int i) {
    inv += total - bit.sum(A[i] + 1);
    bit.add(A[i], 1);
    total++;
  };
  auto erasel = [&](int i) {
    inv -= bit.sum(A[i]);
    bit.add(A[i], -1);
    total--;
  };
  auto eraser = [&](int i) {
    inv -= total - bit.sum(A[i] + 1);
    bit.add(A[i], -1);
    total--;
  };
  long long ans[Q];
  auto out = [&](int q) { ans[q] = inv; };
  mo.run(addl, addr, erasel, eraser, out);
  for (int q = 0; q < Q; q++) cout << ans[q] << "\n";
  cout << flush;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/static_range_inversions_query.mo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/Algorithm/Mo.hpp"
/**
 * @title Mo
 * @category アルゴリズム
 *  O((N+Q)√N)
 * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011
 */

#ifndef call_from_test
#line 10 "src/Algorithm/Mo.hpp"
using namespace std;
#endif

struct Mo {
  int n;
  vector<pair<int, int> > lr;
  explicit Mo(int n) : n(n) {}
  /* [l, r) */
  void query(int l, int r) { lr.emplace_back(l, r); }

  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void run(const AL &add_left, const AR &add_right, const EL &erase_left,
           const ER &erase_right, const O &out) {
    int q = (int)lr.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second
                          : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for (auto idx : ord) {
      while (l > lr[idx].first) add_left(--l);
      while (r < lr[idx].second) add_right(r++);
      while (l < lr[idx].first) erase_left(l++);
      while (r > lr[idx].second) erase_right(--r);
      out(idx);
    }
  }
  template <typename A, typename E, typename O>
  void run(const A &add, const E &erase, const O &out) {
    run(add, add, erase, erase, out);
  }
};
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
  BinaryIndexedTree(vector<T> y) : dat(y.size() + 1) {
    for (int i = 0; i < y.size(); ++i) dat[i + 1] = y[i];
    for (int i = 1; i + (i & -i) < dat.size(); ++i) dat[i + (i & -i)] += dat[i];
  }
  void add(int i, T a = 1) {
    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;
  }
  T sum(int i) {  // sum [0,i)
    T s = 0;
    for (; i > 0; i &= i - 1) s += dat[i];
    return s;
  }
  // min { i : sum(i+1) > k } -> kth element(0-indexed)
  int find(T k) const {
    int i = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (i + p < (int)dat.size() && dat[i + p] <= k) k -= dat[i += p];
    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no solutions
  }
  T operator[](size_t k) { return sum(k + 1) - sum(k); }
};
#line 9 "test/yosupo/static_range_inversions_query.mo.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<int> v(A, A + N);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < N; i++)
    A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
  Mo mo(N);
  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    mo.query(l, r);
  }
  BinaryIndexedTree<long long> bit(N + 1);
  long long inv = 0, total = 0;
  auto addl = [&](int i) {
    inv += bit.sum(A[i]);
    bit.add(A[i], 1);
    total++;
  };
  auto addr = [&](int i) {
    inv += total - bit.sum(A[i] + 1);
    bit.add(A[i], 1);
    total++;
  };
  auto erasel = [&](int i) {
    inv -= bit.sum(A[i]);
    bit.add(A[i], -1);
    total--;
  };
  auto eraser = [&](int i) {
    inv -= total - bit.sum(A[i] + 1);
    bit.add(A[i], -1);
    total--;
  };
  long long ans[Q];
  auto out = [&](int q) { ans[q] = inv; };
  mo.run(addl, addr, erasel, eraser, out);
  for (int q = 0; q < Q; q++) cout << ans[q] << "\n";
  cout << flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

