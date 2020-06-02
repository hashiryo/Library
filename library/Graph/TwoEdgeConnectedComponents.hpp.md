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


# :question: 二重辺連結成分分解

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/TwoEdgeConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 14:58:00+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/two_edge_connected_components.test.cpp.html">test/yosupo/two_edge_connected_components.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/1290.LCT.test.cpp.html">test/yukicoder/1290.LCT.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 二重辺連結成分分解
 * @category グラフ
 * @brief O(V + E)
 * @brief 返り値:{二重辺連結成分,ノードの属する成分の添字}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/TwoEdgeConnectedComponents.hpp"
/**
 * @title 二重辺連結成分分解
 * @category グラフ
 * @brief O(V + E)
 * @brief 返り値:{二重辺連結成分,ノードの属する成分の添字}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

