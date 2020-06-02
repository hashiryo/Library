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


# :heavy_check_mark: test/yosupo/general_matching.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/general_matching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 18:22:22+09:00


* see: <a href="https://judge.yosupo.jp/problem/general_matching">https://judge.yosupo.jp/problem/general_matching</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/MatchingGeneral.hpp.html">最大マッチング(一般グラフ)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MatchingGeneral.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  MatchingGeneral graph(N);
  while (M--) {
    int u, v;
    cin >> u >> v;
    graph.add_edge(u, v);
  }
  auto ans = graph.get_matching();
  cout << ans.first << endl;
  for (int i = 0; i < N; i++)
    if (i < ans.second[i]) cout << i << " " << ans.second[i] << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/general_matching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/MatchingGeneral.hpp"
/**
 * @title 最大マッチング(一般グラフ)
 * @category グラフ
 * @brief  O(VE log V)
 * @brief GabowのEdmonds' Algorithm
 * @brief 返り値:{マッチング数,各頂点の相方(いないなら-1）}
 */

#ifndef call_from_test
#line 11 "Graph/MatchingGeneral.hpp"
using namespace std;
#endif

struct MatchingGeneral {
  struct edge {
    int u, v;
  };

 private:
  int n, res;
  vector<vector<int>> adj;
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
      for (int y : adj[x])
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
      : n(n), res(0), adj(n), mate(n, -1), idx(n, -1), p(n), es(n) {}
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
#line 8 "test/yosupo/general_matching.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  MatchingGeneral graph(N);
  while (M--) {
    int u, v;
    cin >> u >> v;
    graph.add_edge(u, v);
  }
  auto ans = graph.get_matching();
  cout << ans.first << endl;
  for (int i = 0; i < N; i++)
    if (i < ans.second[i]) cout << i << " " << ans.second[i] << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

