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


# :heavy_check_mark: HL分解

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/HeavyLightDecomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-26 20:37:18+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2667.HLD.test.cpp.html">test/aoj/2667.HLD.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/235.HLD.test.cpp.html">test/yukicoder/235.HLD.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title HL分解
 * @category グラフ
 * 可換性を要求
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct HeavyLightDecomposition {
  vector<vector<int>> adj;
  vector<int> sz, in, out, head, par;

  HeavyLightDecomposition(int n) : adj(n) {}
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void build(int rt = 0) {
    sz.assign(adj.size(), 1);
    in.assign(adj.size(), 0);
    out.assign(adj.size(), 0);
    head.assign(adj.size(), 0);
    par.assign(adj.size(), 0);
    dfs_sz(rt, -1, 0);
    int t = 0;
    dfs_hld(rt, -1, t);
  }
  int lca(int u, int v) const {
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }
  template <typename T, typename Q, typename F>
  T query_path(int u, int v, const Q &q, const F &f, const T ti,
               bool edge = false) {
    T vl = ti, vr = ti;
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v), swap(vl, vr);
      if (head[u] == head[v]) break;
      vl = f(q(in[head[v]], in[v] + 1), vl);
    }
    return f(f(q(in[u] + edge, in[v] + 1), vl), vr);
  }
  template <typename T, typename Q>
  T query_subtree(int v, const Q &q, bool edge = false) {
    return q(in[v] + edge, out[v]);
  }

  template <typename Q>
  void update_path(int u, int v, const Q &q, bool edge = false) {
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) break;
      q(in[head[v]], in[v] + 1);
    }
    q(in[u] + edge, in[v] + 1);
  }
  template <typename Q>
  void update_subtree(int v, const Q &q, bool edge = false) {
    q(in[v] + edge, out[v]);
  }

 private:
  void dfs_sz(int v, int p, int d) {
    if (adj[v].size() && adj[v][0] == p) swap(adj[v][0], adj[v].back());
    for (auto &u : adj[v])
      if (u != p) {
        dfs_sz(u, v, d + 1);
        sz[v] += sz[u];
        if (sz[adj[v][0]] < sz[u]) swap(adj[v][0], u);
      }
  }
  void dfs_hld(int v, int p, int &times) {
    par[v] = p;
    in[v] = times++;
    for (auto &u : adj[v])
      if (u != p) {
        head[u] = (adj[v][0] == u ? head[v] : u);
        dfs_hld(u, v, times);
      }
    out[v] = times;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/HeavyLightDecomposition.hpp"
/**
 * @title HL分解
 * @category グラフ
 * 可換性を要求
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct HeavyLightDecomposition {
  vector<vector<int>> adj;
  vector<int> sz, in, out, head, par;

  HeavyLightDecomposition(int n) : adj(n) {}
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void build(int rt = 0) {
    sz.assign(adj.size(), 1);
    in.assign(adj.size(), 0);
    out.assign(adj.size(), 0);
    head.assign(adj.size(), 0);
    par.assign(adj.size(), 0);
    dfs_sz(rt, -1, 0);
    int t = 0;
    dfs_hld(rt, -1, t);
  }
  int lca(int u, int v) const {
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }
  template <typename T, typename Q, typename F>
  T query_path(int u, int v, const Q &q, const F &f, const T ti,
               bool edge = false) {
    T vl = ti, vr = ti;
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v), swap(vl, vr);
      if (head[u] == head[v]) break;
      vl = f(q(in[head[v]], in[v] + 1), vl);
    }
    return f(f(q(in[u] + edge, in[v] + 1), vl), vr);
  }
  template <typename T, typename Q>
  T query_subtree(int v, const Q &q, bool edge = false) {
    return q(in[v] + edge, out[v]);
  }

  template <typename Q>
  void update_path(int u, int v, const Q &q, bool edge = false) {
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) break;
      q(in[head[v]], in[v] + 1);
    }
    q(in[u] + edge, in[v] + 1);
  }
  template <typename Q>
  void update_subtree(int v, const Q &q, bool edge = false) {
    q(in[v] + edge, out[v]);
  }

 private:
  void dfs_sz(int v, int p, int d) {
    if (adj[v].size() && adj[v][0] == p) swap(adj[v][0], adj[v].back());
    for (auto &u : adj[v])
      if (u != p) {
        dfs_sz(u, v, d + 1);
        sz[v] += sz[u];
        if (sz[adj[v][0]] < sz[u]) swap(adj[v][0], u);
      }
  }
  void dfs_hld(int v, int p, int &times) {
    par[v] = p;
    in[v] = times++;
    for (auto &u : adj[v])
      if (u != p) {
        head[u] = (adj[v][0] == u ? head[v] : u);
        dfs_hld(u, v, times);
      }
    out[v] = times;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

