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


# :heavy_check_mark: Union-Find

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 22:54:22+09:00




## Required by

* :heavy_check_mark: <a href="../Graph/MinimumSpanningAborescense.hpp.html">最小全域有向木</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2647.test.cpp.html">test/aoj/2647.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_A.test.cpp.html">test/aoj/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/directedmst.test.cpp.html">test/yosupo/directedmst.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Union-Find
 * @category データ構造
 * @brief unite(x,y) x が入っている集合と y が入っている集合を併合する．
 * @brief same(x,y) x と y が同じ集合に入っているかどうかを判定する．
 * @brief O(α(N))
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct UnionFind {
  vector<int> par;
  UnionFind(int size) : par(size, -1) {}
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v], par[v] = u;
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
  int size(int u) { return -par[root(u)]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind.hpp"
/**
 * @title Union-Find
 * @category データ構造
 * @brief unite(x,y) x が入っている集合と y が入っている集合を併合する．
 * @brief same(x,y) x と y が同じ集合に入っているかどうかを判定する．
 * @brief O(α(N))
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct UnionFind {
  vector<int> par;
  UnionFind(int size) : par(size, -1) {}
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v], par[v] = u;
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
  int size(int u) { return -par[root(u)]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

