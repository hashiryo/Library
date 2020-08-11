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
    - Last commit date: 2020-08-11 20:23:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/Graph/MaxFlow_Dinic.hpp.html">最大流(Dinic)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Graph/MaxFlow_Dinic.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  MaxFlow_Dinic<long long> graph;
  graph.add_vertices(N);
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
#line 1 "src/Graph/MaxFlow_Dinic.hpp"
/**
 * @title 最大流(Dinic)
 * @category グラフ
 *   O(V^2 E)
 *  link: s->tフローで辺(src,dst)の容量を1増やしたときの最大流の変化
 *  cut: s->tフローで辺(src,dst)の容量を1減らしたときの最大流の変化
 */

// 最小流量制限付き最大流 https://snuke.hatenablog.com/entry/2016/07/10/043918
#ifndef call_from_test
#line 12 "src/Graph/MaxFlow_Dinic.hpp"
using namespace std;
#endif

template <typename flow_t>
struct MaxFlow_Dinic {
 private:
  struct Edge {
    int dst;
    flow_t cap;
    int rev;
    bool isrev;
  };

 private:
  static constexpr flow_t FLOW_MAX = numeric_limits<flow_t>::max() / 2;
  int n;
  vector<vector<Edge>> adj;
  vector<int> level, iter;

 private:
  int levelize(const int &s, const int &t) {
    level.assign(n, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      if (u == t) break;
      for (auto &e : adj[u]) {
        if (e.cap > 0 && level[e.dst] < 0) {
          que.push(e.dst);
          level[e.dst] = level[u] + 1;
        }
      }
    }
    return level[t];
  }
  flow_t dfs(int u, const int &t, flow_t cur) {
    if (u == t) return cur;
    for (int &i = iter[u]; i < adj[u].size(); ++i) {
      Edge &e = adj[u][i], &r = adj[e.dst][e.rev];
      if (e.cap > 0 && level[u] < level[e.dst]) {
        flow_t f = dfs(e.dst, t, min(cur, e.cap));
        if (f > 0) {
          e.cap -= f;
          r.cap += f;
          return f;
        }
      }
    }
    return flow_t(0);
  }
  flow_t flow(int s, int t) {
    if (levelize(s, t) < 0) return 0;
    iter.assign(adj.size(), 0);
    return dfs(s, t, 1);
  }

 public:
  MaxFlow_Dinic() : n(0) {}
  int add_vertex() {
    adj.resize(++n);
    return n - 1;
  }
  vector<int> add_vertices(const int size) {
    vector<int> ret(size);
    iota(begin(ret), end(ret), n);
    n += size;
    adj.resize(n);
    return ret;
  }
  void add_edge(int src, int dst, flow_t cap) {
    adj[src].emplace_back((Edge){dst, cap, (int)adj[dst].size(), 0});
    adj[dst].emplace_back((Edge){src, 0, (int)adj[src].size() - 1, 1});
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
    for (auto &e : adj[src])
      if (e.dst == dst && !e.isrev) {
        e.cap += 1;
        break;
      }
    return flow(s, t);
  }
  flow_t cut(int src, int dst, int s, int t) {
    for (auto &e : adj[src])
      if (e.dst == dst && !e.isrev) {
        flow_t diff = 0;
        if (e.cap == 0) {
          if (flow(src, dst) == 0) {
            flow(t, dst);
            flow(src, s);
            diff = -1;
          }
          adj[e.dst][e.rev].cap -= 1;
        } else {
          e.cap -= 1;
        }
        return diff;
      }
    assert(false);  // no edge
  }
  void output() {
    for (int i = 0; i < adj.size(); i++) {
      for (auto &e : adj[i]) {
        if (e.isrev) continue;
        auto &rev_e = adj[e.dst][e.rev];
        cerr << i << "->" << e.dst << " (flow: " << rev_e.cap << "/"
             << e.cap + rev_e.cap << ")" << endl;
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
  MaxFlow_Dinic<long long> graph;
  graph.add_vertices(N);
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

