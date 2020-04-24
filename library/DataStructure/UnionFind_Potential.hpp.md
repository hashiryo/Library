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


# :heavy_check_mark: Union-Find(ポテンシャル)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind_Potential.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 16:54:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2207.test.cpp.html">test/aoj/2207.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Union-Find(ポテンシャル)
 * @category データ構造
 * @brief 各ノードにポテンシャルをもたせ、その差を求められる
 * @brief O(α(N))
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct UnionFind_Potential {
  typedef long long Weight;
  vector<int> par;
  vector<Weight> val;
  UnionFind_Potential(int size) : par(size, -1), val(size, 0) {}
  bool unionSet(int y, int x, Weight w) {
    w += potential(x) - potential(y);
    x = root(x), y = root(y);
    if (x != y) {
      if (par[y] < par[x]) swap(x, y), w = -w;
      par[x] += par[y];
      par[y] = x, val[y] = w;
    }
    return x != y;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int root(int x) {
    if (par[x] < 0) return x;
    int r = root(par[x]);
    val[x] += val[par[x]];
    return par[x] = r;
  }
  int size(int x) { return -par[root(x)]; }
  Weight potential(int x) {
    root(x);
    return val[x];
  }
  Weight diff(int x, int y) { return potential(x) - potential(y); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind_Potential.hpp"
/**
 * @title Union-Find(ポテンシャル)
 * @category データ構造
 * @brief 各ノードにポテンシャルをもたせ、その差を求められる
 * @brief O(α(N))
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct UnionFind_Potential {
  typedef long long Weight;
  vector<int> par;
  vector<Weight> val;
  UnionFind_Potential(int size) : par(size, -1), val(size, 0) {}
  bool unionSet(int y, int x, Weight w) {
    w += potential(x) - potential(y);
    x = root(x), y = root(y);
    if (x != y) {
      if (par[y] < par[x]) swap(x, y), w = -w;
      par[x] += par[y];
      par[y] = x, val[y] = w;
    }
    return x != y;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int root(int x) {
    if (par[x] < 0) return x;
    int r = root(par[x]);
    val[x] += val[par[x]];
    return par[x] = r;
  }
  int size(int x) { return -par[root(x)]; }
  Weight potential(int x) {
    root(x);
    return val[x];
  }
  Weight diff(int x, int y) { return potential(x) - potential(y); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

