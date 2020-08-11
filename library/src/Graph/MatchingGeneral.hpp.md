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


# :question: 最大マッチング(一般グラフ)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/MatchingGeneral.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:23:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/3032.test.cpp.html">test/aoj/3032.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/general_matching.test.cpp.html">test/yosupo/general_matching.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最大マッチング(一般グラフ)
 * @category グラフ
 *   O(VE log V)
 *  GabowのEdmonds' Algorithm
 *  返り値:{マッチング数,各頂点の相方(いないなら-1）}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingGeneral {
 private:
  int n, res;
  vector<vector<int>> adj;
  vector<int> mate, idx, p;
  vector<pair<int, int>> edges;

 private:
  void rematch(int u, int v) {
    int w = mate[u];
    mate[u] = v;
    if (w == -1 || mate[w] != u) return;
    if (edges[u].second == -1) {
      rematch(mate[w] = edges[u].first, w);
    } else {
      rematch(edges[u].first, edges[u].second);
      rematch(edges[u].second, edges[u].first);
    }
  }
  bool check(int root) {
    function<int(int)> f = [&](int x) {
      return (idx[x] != res || p[x] == -1) ? x : (p[x] = f(p[x]));
    };
    queue<int> que;
    edges[root] = {-1, -1};
    idx[root] = res, p[root] = -1, que.push(root);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int y : adj[x])
        if (y != root) {
          if (mate[y] == -1) {
            rematch(mate[y] = x, y);
            return true;
          } else if (idx[y] == res) {
            int u = f(x), v = f(y), w = root;
            if (u == v) continue;
            while (u != root || v != root) {
              if (v != root) swap(u, v);
              if (edges[u].first == x && edges[u].second == y) {
                w = u;
                break;
              }
              edges[u] = {x, y};
              u = f(edges[mate[u]].first);
            }
            for (int t = f(x); t != w; t = f(edges[mate[t]].first))
              idx[t] = res, p[t] = w, que.push(t);
            for (int t = f(y); t != w; t = f(edges[mate[t]].first))
              idx[t] = res, p[t] = w, que.push(t);
          } else if (idx[mate[y]] != res) {
            edges[y] = {-1, -1};
            edges[mate[y]] = {x, -1};
            idx[mate[y]] = res, p[mate[y]] = y, que.push(mate[y]);
          }
        }
    }
    return false;
  }

 public:
  MatchingGeneral(int n)
      : n(n), res(0), adj(n), mate(n, -1), idx(n, -1), p(n), edges(n) {}
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  pair<int, vector<int>> get_matching() {
    for (int i = 0; i < n; i++)
      if (mate[i] == -1) res += check(i);
    return make_pair(res, mate);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/MatchingGeneral.hpp"
/**
 * @title 最大マッチング(一般グラフ)
 * @category グラフ
 *   O(VE log V)
 *  GabowのEdmonds' Algorithm
 *  返り値:{マッチング数,各頂点の相方(いないなら-1）}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingGeneral {
 private:
  int n, res;
  vector<vector<int>> adj;
  vector<int> mate, idx, p;
  vector<pair<int, int>> edges;

 private:
  void rematch(int u, int v) {
    int w = mate[u];
    mate[u] = v;
    if (w == -1 || mate[w] != u) return;
    if (edges[u].second == -1) {
      rematch(mate[w] = edges[u].first, w);
    } else {
      rematch(edges[u].first, edges[u].second);
      rematch(edges[u].second, edges[u].first);
    }
  }
  bool check(int root) {
    function<int(int)> f = [&](int x) {
      return (idx[x] != res || p[x] == -1) ? x : (p[x] = f(p[x]));
    };
    queue<int> que;
    edges[root] = {-1, -1};
    idx[root] = res, p[root] = -1, que.push(root);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int y : adj[x])
        if (y != root) {
          if (mate[y] == -1) {
            rematch(mate[y] = x, y);
            return true;
          } else if (idx[y] == res) {
            int u = f(x), v = f(y), w = root;
            if (u == v) continue;
            while (u != root || v != root) {
              if (v != root) swap(u, v);
              if (edges[u].first == x && edges[u].second == y) {
                w = u;
                break;
              }
              edges[u] = {x, y};
              u = f(edges[mate[u]].first);
            }
            for (int t = f(x); t != w; t = f(edges[mate[t]].first))
              idx[t] = res, p[t] = w, que.push(t);
            for (int t = f(y); t != w; t = f(edges[mate[t]].first))
              idx[t] = res, p[t] = w, que.push(t);
          } else if (idx[mate[y]] != res) {
            edges[y] = {-1, -1};
            edges[mate[y]] = {x, -1};
            idx[mate[y]] = res, p[mate[y]] = y, que.push(mate[y]);
          }
        }
    }
    return false;
  }

 public:
  MatchingGeneral(int n)
      : n(n), res(0), adj(n), mate(n, -1), idx(n, -1), p(n), edges(n) {}
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  pair<int, vector<int>> get_matching() {
    for (int i = 0; i < n; i++)
      if (mate[i] == -1) res += check(i);
    return make_pair(res, mate);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

