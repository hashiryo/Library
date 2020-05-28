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


# :heavy_check_mark: test/aoj/GRL_6_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 00:58:18+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/MinCostFlow.hpp.html">最小費用流</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MinCostFlow.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V, E, F;
  cin >> V >> E >> F;
  MinCostFlow<int, int> graph(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph.add_edge(u, v, c, d);
  }
  auto ans = graph.min_cost_flow(0, V - 1, F);
  cout << (ans.second ? ans.first : -1) << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_B.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/MinCostFlow.hpp"
/**
 * @title 最小費用流
 * @category グラフ
 * @brief PrimalDual
 * @brief O((f+F')ElogV)
 * @brief 負辺除去あり
 * @brief 返り値:{流量f流したときの最小コスト,そもそも流量f流せたか(bool)}
 */
// verify用:
// https://codeforces.com/contest/316/problem/C2 (Radix-HeapでないとTLEした)
// https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b (コスト実数)

#ifndef call_from_test
#line 15 "Graph/MinCostFlow.hpp"
using namespace std;
#endif

template <typename flow_t, typename cost_t,
          typename Heap
          = priority_queue<pair<cost_t, int>, vector<pair<cost_t, int>>,
                           greater<pair<cost_t, int>>>>
struct MinCostFlow {
  struct Edge {
    int dst;
    flow_t capacity;
    cost_t cost;
    size_t rev;
    bool isrev;
  };

 private:
  static constexpr double EPS = 1e-7;
  int n, S, T;
  cost_t neg;
  vector<vector<Edge>> adj;
  vector<flow_t> d;
  vector<cost_t> potential, dist;
  vector<int> prev;

 private:
  void dijkstra() {
    Heap que;
    dist.assign(n, -2);
    dist[S] = 0;
    que.emplace(0, S);
    while (!que.empty()) {
      auto a = que.top();
      que.pop();
      int v = a.second;
      if (dist[v] < a.first) continue;
      if (v == T) break;
      for (Edge &e : adj[v]) {
        cost_t nextcost = e.cost + potential[v] - potential[e.dst];
        if (e.capacity == 0) continue;
        if (abs(nextcost) < EPS) nextcost = 0;
        if ((dist[e.dst] < -1 || dist[e.dst] > dist[v] + nextcost)) {
          dist[e.dst] = dist[v] + nextcost;
          prev[e.dst] = e.rev;
          que.emplace(dist[v] + nextcost, e.dst);
        }
      }
    }
  }
  pair<cost_t, bool> flow(vector<flow_t> d0) {
    cost_t res = 0;
    potential.assign(n, 0);
    prev.assign(n, -1);
    flow_t f = 0;
    for (int i = 0; i < d.size(); i++) {
      if (i < d0.size()) d[i] += d0[i];
      if (d[i] > 0)
        add_edge(S, i, d[i], 0), f += d[i];
      else if (d[i] < 0)
        add_edge(i, T, -d[i], 0);
    }
    while (f > 0) {
      dijkstra();
      if (dist[T] < -1) return {0, false};  // no solution
      for (int v = 0; v < n; v++) {
        if (dist[v] > -1 && dist[v] < dist[T] + EPS)
          potential[v] += dist[v] - dist[T];
        // if (dist[v] > -1) potential[v] += dist[v];
      }

      flow_t addflow = f;
      for (int v = T; v != S;) {
        Edge &r = adj[v][prev[v]], &e = adj[r.dst][r.rev];
        addflow = min(addflow, e.capacity);
        v = r.dst;
      }
      f -= addflow;
      res += addflow * (potential[T] - potential[S]);
      for (int v = T; v != S;) {
        Edge &r = adj[v][prev[v]], &e = adj[r.dst][r.rev];
        e.capacity -= addflow;
        r.capacity += addflow;
        v = r.dst;
      }
    }
    return {neg + res, true};
  }

 public:
  MinCostFlow(int n_)
      : n(n_ + 2), S(n_), T(n_ + 1), neg(0), adj(n_ + 2), d(n_ + 2) {}
  void add_edge(int src, int dst, flow_t cap, cost_t cost) {
    if (cost >= 0) {
      adj[src].emplace_back((Edge){dst, cap, cost, adj[dst].size(), 0});
      adj[dst].emplace_back((Edge){src, 0, -cost, adj[src].size() - 1, 1});
    } else {
      d[src] -= cap;
      d[dst] += cap;
      neg += cap * cost;
      add_edge(dst, src, cap, -cost);
    }
  }
  pair<cost_t, bool> min_cost_flow(int s, int t, flow_t f) {
    vector<flow_t> d0(n);
    d0[s] = f, d0[t] = -f;
    return flow(d0);
  }
  void output() {
    for (int i = 0; i < adj.size(); i++)
      for (auto &e : adj[i]) {
        if (e.isrev) continue;
        auto &rev_e = adj[e.dst][e.rev];
        cerr << i << "->" << e.dst << " (flow: " << rev_e.capacity << "/"
             << e.capacity + rev_e.capacity << ") cost:" << e.cost << endl;
      }
  }
};
#line 9 "test/aoj/GRL_6_B.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V, E, F;
  cin >> V >> E >> F;
  MinCostFlow<int, int> graph(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph.add_edge(u, v, c, d);
  }
  auto ans = graph.min_cost_flow(0, V - 1, F);
  cout << (ans.second ? ans.first : -1) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

