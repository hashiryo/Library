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


# :x: test/yosupo/two_edge_connected_components.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/two_edge_connected_components.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 17:25:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :x: <a href="../../../library/src/Graph/TwoEdgeConnectedComponents.hpp.html">二重辺連結成分分解</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Graph/TwoEdgeConnectedComponents.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  TwoEdgeConnectedComponents graph(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_2ECC().first;
  cout << ans.size() << endl;
  for (auto &a : ans) {
    cout << a.size();
    for (int &v : a) cout << " " << v;
    cout << endl;
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/two_edge_connected_components.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/Graph/TwoEdgeConnectedComponents.hpp"
/**
 * @title 二重辺連結成分分解
 * @category グラフ
 * @brief O(V + E)
 * @brief 返り値:{二重辺連結成分,ノードの属する成分の添字}
 */

#ifndef call_from_test
#line 10 "src/Graph/TwoEdgeConnectedComponents.hpp"
using namespace std;
#endif

struct TwoEdgeConnectedComponents {
 private:
  int n;
  vector<vector<int>> adj;

 public:
  TwoEdgeConnectedComponents(int n) : n(n), adj(n) {}
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pair<vector<vector<int>>, vector<int>> get_2ECC() {
    vector<int> index(n, -1), num(n), par(n, -1), cur(n);
    vector<short> parcheck(n, 0);
    vector<vector<int>> block;
    for (int s = 0; s < n; ++s) {
      if (num[s]) continue;
      int time = 0;
      vector<int> snum, path, stack = {s};
      while (!stack.empty()) {
        int u = stack.back();
        if (cur[u] == 0) {
          num[u] = ++time;
          path.push_back(u);
          snum.push_back(num[u]);
        }
        if (cur[u] == adj[u].size()) {
          if (num[u] == snum.back()) {
            snum.pop_back();
            block.push_back({});
            while (1) {
              int w = path.back();
              path.pop_back();
              block.back().push_back(w);
              index[w] = block.size() - 1;
              if (u == w) break;
            }
          }
          stack.pop_back();
        } else {
          int v = adj[u][cur[u]++];
          if (!num[v]) {
            par[v] = u;
            stack.push_back(v);
          } else if (v == par[u] && !parcheck[u]) {
            parcheck[u] = true;
          } else if (index[v] < 0) {
            while (snum.back() > num[v]) snum.pop_back();
          }
        }
      }
    }
    return make_pair(block, index);
  }
};
#line 8 "test/yosupo/two_edge_connected_components.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  TwoEdgeConnectedComponents graph(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_2ECC().first;
  cout << ans.size() << endl;
  for (auto &a : ans) {
    cout << a.size();
    for (int &v : a) cout << " " << v;
    cout << endl;
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

