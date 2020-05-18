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


# :heavy_check_mark: 木DP

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Tree_DP.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-18 11:25:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/196.test.cpp.html">test/yukicoder/196.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/417.test.cpp.html">test/yukicoder/417.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/763.test.cpp.html">test/yukicoder/763.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/768.test.cpp.html">test/yukicoder/768.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 木DP
 * @category グラフ
 * @brief run(root):木dp
 * @brief run_rerooting():全方位木dp
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, typename E = int>
struct Tree_DP {
  struct Edge {
    int to;
    E data;
    T dp, ndp;
  };
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;

 private:
  vector<vector<Edge>> graph;
  vector<T> subdp, dp;
  const T init;
  const F f;
  const G g;

 private:
  void dfs_sub(int idx, int par) {
    for (auto &e : graph[idx]) {
      if (e.to == par) continue;
      dfs_sub(e.to, idx);
      subdp[idx] = f(subdp[idx], g(subdp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int par, const T &top) {
    T buff{init};
    for (int i = 0; i < (int)graph[idx].size(); i++) {
      auto &e = graph[idx][i];
      e.ndp = buff;
      e.dp = g(par == e.to ? top : subdp[e.to], e.data);
      buff = f(buff, e.dp);
    }
    dp[idx] = buff;
    buff = init;
    for (int i = (int)graph[idx].size() - 1; i >= 0; i--) {
      auto &e = graph[idx][i];
      if (e.to != par) dfs_all(e.to, idx, f(e.ndp, buff));
      e.ndp = f(e.ndp, buff);
      buff = f(buff, e.dp);
    }
  }

 public:
  Tree_DP(
      int V, const F &f, T init,
      const G &g = [](const T &dp, const E &dat) { return dp; })
      : graph(V), f(f), g(g), init(init), subdp(V, init), dp(V, init) {}

  void add_edge(int u, int v, E d = E()) {
    graph[u].emplace_back((Edge){v, d, init, init});
  }

  T run(int root) {
    dfs_sub(root, -1);
    return subdp[root];
  }

  vector<T> run_rerooting() {
    dfs_sub(0, -1);
    dfs_all(0, -1, init);
    return dp;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Tree_DP.hpp"
/**
 * @title 木DP
 * @category グラフ
 * @brief run(root):木dp
 * @brief run_rerooting():全方位木dp
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, typename E = int>
struct Tree_DP {
  struct Edge {
    int to;
    E data;
    T dp, ndp;
  };
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;

 private:
  vector<vector<Edge>> graph;
  vector<T> subdp, dp;
  const T init;
  const F f;
  const G g;

 private:
  void dfs_sub(int idx, int par) {
    for (auto &e : graph[idx]) {
      if (e.to == par) continue;
      dfs_sub(e.to, idx);
      subdp[idx] = f(subdp[idx], g(subdp[e.to], e.data));
    }
  }

  void dfs_all(int idx, int par, const T &top) {
    T buff{init};
    for (int i = 0; i < (int)graph[idx].size(); i++) {
      auto &e = graph[idx][i];
      e.ndp = buff;
      e.dp = g(par == e.to ? top : subdp[e.to], e.data);
      buff = f(buff, e.dp);
    }
    dp[idx] = buff;
    buff = init;
    for (int i = (int)graph[idx].size() - 1; i >= 0; i--) {
      auto &e = graph[idx][i];
      if (e.to != par) dfs_all(e.to, idx, f(e.ndp, buff));
      e.ndp = f(e.ndp, buff);
      buff = f(buff, e.dp);
    }
  }

 public:
  Tree_DP(
      int V, const F &f, T init,
      const G &g = [](const T &dp, const E &dat) { return dp; })
      : graph(V), f(f), g(g), init(init), subdp(V, init), dp(V, init) {}

  void add_edge(int u, int v, E d = E()) {
    graph[u].emplace_back((Edge){v, d, init, init});
  }

  T run(int root) {
    dfs_sub(root, -1);
    return subdp[root];
  }

  vector<T> run_rerooting() {
    dfs_sub(0, -1);
    dfs_all(0, -1, init);
    return dp;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

