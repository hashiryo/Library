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


# :heavy_check_mark: 最大マッチング(一般グラフ)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/MatchingGeneral.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 20:46:33+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/3032.test.cpp.html">test/aoj/3032.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/general_matching.test.cpp.html">test/yosupo/general_matching.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最大マッチング(一般グラフ)
 * @category グラフ
 * @brief  O(VE log V)
 * @brief GabowのEdmonds' Algorithm
 * @brief 返り値:{マッチング数,各頂点の相方(いないなら-1）}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingGeneral {
  struct edge {
    int u, v;
  };

 private:
  int n, res;
  vector<vector<int>> g;
  vector<int> mate, idx, p;
  vector<edge> es;

 private:
  void rematch(int u, int v) {
    int w = mate[u];
    mate[u] = v;
    if (w == -1 || mate[w] != u) return;
    if (es[u].v == -1) {
      mate[w] = es[u].u;
      rematch(es[u].u, w);
    } else {
      rematch(es[u].u, es[u].v);
      rematch(es[u].v, es[u].u);
    }
  }
  bool check(int rt) {
    function<int(int)> f = [&](int x) {
      return (idx[x] != res || p[x] == -1) ? x : (p[x] = f(p[x]));
    };
    queue<int> que;
    que.push(rt);
    p[rt] = -1;
    idx[rt] = res;
    es[rt] = {-1, -1};
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int y : g[x])
        if (y != rt) {
          if (mate[y] == -1) {
            mate[y] = x;
            rematch(x, y);
            return true;
          } else if (idx[y] == res) {
            int u = f(x), v = f(y), w = rt;
            if (u == v) continue;
            while (u != rt || v != rt) {
              if (v != rt) swap(u, v);
              if (es[u].u == x && es[u].v == y) {
                w = u;
                break;
              }
              es[u] = {x, y};
              u = f(es[mate[u]].u);
            }
            int t = f(x);
            while (t != w) {
              idx[t] = res;
              p[t] = w;
              que.push(t);
              t = f(es[mate[t]].u);
            }
            t = f(y);
            while (t != w) {
              idx[t] = res;
              p[t] = w;
              que.push(t);
              t = f(es[mate[t]].u);
            }
          } else if (idx[mate[y]] != res) {
            es[y] = {-1, -1};
            idx[mate[y]] = res;
            p[mate[y]] = y;
            es[mate[y]] = {x, -1};
            que.push(mate[y]);
          }
        }
    }
    return false;
  }

 public:
  MatchingGeneral(int n)
      : g(n), n(n), res(0), mate(n, -1), idx(n, -1), p(n), es(n) {}
  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
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
#line 1 "Graph/MatchingGeneral.hpp"
/**
 * @title 最大マッチング(一般グラフ)
 * @category グラフ
 * @brief  O(VE log V)
 * @brief GabowのEdmonds' Algorithm
 * @brief 返り値:{マッチング数,各頂点の相方(いないなら-1）}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingGeneral {
  struct edge {
    int u, v;
  };

 private:
  int n, res;
  vector<vector<int>> g;
  vector<int> mate, idx, p;
  vector<edge> es;

 private:
  void rematch(int u, int v) {
    int w = mate[u];
    mate[u] = v;
    if (w == -1 || mate[w] != u) return;
    if (es[u].v == -1) {
      mate[w] = es[u].u;
      rematch(es[u].u, w);
    } else {
      rematch(es[u].u, es[u].v);
      rematch(es[u].v, es[u].u);
    }
  }
  bool check(int rt) {
    function<int(int)> f = [&](int x) {
      return (idx[x] != res || p[x] == -1) ? x : (p[x] = f(p[x]));
    };
    queue<int> que;
    que.push(rt);
    p[rt] = -1;
    idx[rt] = res;
    es[rt] = {-1, -1};
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int y : g[x])
        if (y != rt) {
          if (mate[y] == -1) {
            mate[y] = x;
            rematch(x, y);
            return true;
          } else if (idx[y] == res) {
            int u = f(x), v = f(y), w = rt;
            if (u == v) continue;
            while (u != rt || v != rt) {
              if (v != rt) swap(u, v);
              if (es[u].u == x && es[u].v == y) {
                w = u;
                break;
              }
              es[u] = {x, y};
              u = f(es[mate[u]].u);
            }
            int t = f(x);
            while (t != w) {
              idx[t] = res;
              p[t] = w;
              que.push(t);
              t = f(es[mate[t]].u);
            }
            t = f(y);
            while (t != w) {
              idx[t] = res;
              p[t] = w;
              que.push(t);
              t = f(es[mate[t]].u);
            }
          } else if (idx[mate[y]] != res) {
            es[y] = {-1, -1};
            idx[mate[y]] = res;
            p[mate[y]] = y;
            es[mate[y]] = {x, -1};
            que.push(mate[y]);
          }
        }
    }
    return false;
  }

 public:
  MatchingGeneral(int n)
      : g(n), n(n), res(0), mate(n, -1), idx(n, -1), p(n), es(n) {}
  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  pair<int, vector<int>> get_matching() {
    for (int i = 0; i < n; i++)
      if (mate[i] == -1) res += check(i);
    return make_pair(res, mate);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

