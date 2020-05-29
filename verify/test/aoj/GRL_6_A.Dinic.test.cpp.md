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


# :heavy_check_mark: test/aoj/GRL_6_A.Dinic.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_A.Dinic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 20:46:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/MaxFlow_Dinic.hpp.html">最大流(Dinic)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MaxFlow_Dinic.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  MaxFlow_Dinic<long long> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    graph.add_edge(u, v, c);
  }
  cout << graph.max_flow(0, N - 1) << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_A.Dinic.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/MaxFlow_Dinic.hpp"
/**
 * @title 最大流(Dinic)
 * @category グラフ
 * @brief  O(V^2 E)
 * @brief link: s->tフローで辺(src,dst)の容量を1増やしたときの最大流の変化
 * @brief cut: s->tフローで辺(src,dst)の容量を1減らしたときの最大流の変化
 */

// 最小流量制限付き最大流 https://snuke.hatenablog.com/entry/2016/07/10/043918
#ifndef call_from_test
#line 12 "Graph/MaxFlow_Dinic.hpp"
using namespace std;
#endif

template <typename flow_t>
struct MaxFlow_Dinic {
  struct Edge {
    int dst;
    flow_t capacity;
    size_t rev;
    bool isrev;
  };

 private:
  static constexpr flow_t FLOW_MAX = numeric_limits<flow_t>::max() / 2;
  int n;
  vector<vector<Edge>> graph;
  vector<int> level, iter;

 private:
  int levelize(const int &s, const int &t) {
    level.assign(n, -1);
    level[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (u == t) break;
      for (auto &e : graph[u]) {
        if (e.capacity > 0 && level[e.dst] < 0) {
          Q.push(e.dst);
          level[e.dst] = level[u] + 1;
        }
      }
    }
    return level[t];
  }
  flow_t dfs(int u, const int &t, flow_t cur) {
    if (u == t) return cur;
    for (int &i = iter[u]; i < graph[u].size(); ++i) {
      Edge &e = graph[u][i], &r = graph[e.dst][e.rev];
      if (e.capacity > 0 && level[u] < level[e.dst]) {
        flow_t f = dfs(e.dst, t, min(cur, e.capacity));
        if (f > 0) {
          e.capacity -= f;
          r.capacity += f;
          return f;
        }
      }
    }
    return flow_t(0);
  }
  flow_t flow(int s, int t) {
    if (levelize(s, t) < 0) return 0;
    iter.assign(graph.size(), 0);
    return dfs(s, t, 1);
  }

 public:
  MaxFlow_Dinic(int n) : n(n), graph(n) {}
  void add_edge(int src, int dst, flow_t cap) {
    graph[src].emplace_back((Edge){dst, cap, graph[dst].size(), 0});
    graph[dst].emplace_back((Edge){src, 0, graph[src].size() - 1, 1});
  }
  flow_t max_flow(int s, int t, flow_t lim = FLOW_MAX) {
    flow_t flow = 0;
    while (levelize(s, t) >= 0) {
      iter.assign(n, 0);
      for (flow_t f; (f = dfs(s, t, lim)) > 0;) flow += f, lim -= f;
    }
    return flow;
  }
  flow_t link(int src, int dst, int s, int t) {
    for (auto &e : graph[src])
      if (e.dst == dst && !e.isrev) {
        e.capacity += 1;
        break;
      }
    return flow(s, t);
  }
  flow_t cut(int src, int dst, int s, int t) {
    for (auto &e : graph[src])
      if (e.dst == dst && !e.isrev) {
        flow_t diff = 0;
        if (e.capacity == 0) {
          if (flow(src, dst) == 0) {
            flow(t, dst);
            flow(src, s);
            diff = -1;
          }
          graph[e.dst][e.rev].capacity -= 1;
        } else {
          e.capacity -= 1;
        }
        return diff;
      }
    assert(false);  // no edge
  }
  void output() {
    for (int i = 0; i < graph.size(); i++) {
      for (auto &e : graph[i]) {
        if (e.isrev) continue;
        auto &rev_e = graph[e.dst][e.rev];
        cerr << i << "->" << e.dst << " (flow: " << rev_e.capacity << "/"
             << e.capacity + rev_e.capacity << ")" << endl;
      }
    }
  }
};
#line 9 "test/aoj/GRL_6_A.Dinic.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  MaxFlow_Dinic<long long> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    graph.add_edge(u, v, c);
  }
  cout << graph.max_flow(0, N - 1) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

