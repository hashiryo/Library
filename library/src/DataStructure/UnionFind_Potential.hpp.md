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


# :heavy_check_mark: Union-Find(ポテンシャル)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/UnionFind_Potential.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2207.test.cpp.html">test/aoj/2207.test.cpp</a>


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

template <typename Weight>
struct UnionFind_Potential {
  vector<int> par;
  vector<Weight> val;
  UnionFind_Potential(int size) : par(size, -1), val(size, 0) {}
  bool unite(int v, int u, Weight w) {
    w += potential(u) - potential(v);
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v), w = -w;
    par[u] += par[v], par[v] = u, val[v] = w;
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int root(int u) {
    if (par[u] < 0) return u;
    int r = root(par[u]);
    val[u] += val[par[u]];
    return par[u] = r;
  }
  int size(int u) { return -par[root(u)]; }
  Weight potential(int u) {
    root(u);
    return val[u];
  }
  Weight diff(int u, int v) { return potential(u) - potential(v); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/UnionFind_Potential.hpp"
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

template <typename Weight>
struct UnionFind_Potential {
  vector<int> par;
  vector<Weight> val;
  UnionFind_Potential(int size) : par(size, -1), val(size, 0) {}
  bool unite(int v, int u, Weight w) {
    w += potential(u) - potential(v);
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v), w = -w;
    par[u] += par[v], par[v] = u, val[v] = w;
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int root(int u) {
    if (par[u] < 0) return u;
    int r = root(par[u]);
    val[u] += val[par[u]];
    return par[u] = r;
  }
  int size(int u) { return -par[root(u)]; }
  Weight potential(int u) {
    root(u);
    return val[u];
  }
  Weight diff(int u, int v) { return potential(u) - potential(v); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

