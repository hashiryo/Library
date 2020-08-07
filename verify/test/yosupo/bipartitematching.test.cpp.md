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


# :heavy_check_mark: test/yosupo/bipartitematching.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/bipartitematching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 12:18:23+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/MatchingBipartite.hpp.html">最大マッチング(二部グラフ)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MatchingBipartite.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int L, R, M;
  cin >> L >> R >> M;
  MatchingBipartite graph(L, R);
  while (M--) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_matching();
  auto left = ans.second.first;
  cout << ans.first << endl;
  for (int i = 0; i < left.size(); i++)
    if (left[i] != -1) {
      cout << i << " " << left[i] << endl;
    }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/bipartitematching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/MatchingBipartite.hpp"
/**
 * @title 最大マッチング(二部グラフ)
 * @category グラフ
 * @brief  O(VE)
 * @brief 速い(O(E√V)並?)
 * @brief 返り値:{マッチング数,{左の相方(いないなら-1),右の相方(いないなら-1)}}
 * @see https://snuke.hatenablog.com/entry/2019/05/07/013609
 */
// 被覆問題との関係 https://qiita.com/drken/items/7f98315b56c95a6181a4

#ifndef call_from_test
#line 13 "Graph/MatchingBipartite.hpp"
using namespace std;
#endif

struct MatchingBipartite {
  vector<vector<int>> adj;
  int n, m;
  MatchingBipartite(int n, int m) : adj(n), n(n), m(m) {}
  void add_edge(int l, int r) { adj[l].push_back(r); }
  pair<int, pair<vector<int>, vector<int>>> get_matching() {
    vector<int> pre(n, -1), root(n, -1);
    vector<int> leftmate(n, -1), rightmate(m, -1);
    int res = 0;
    bool update = true;
    while (update) {
      update = false;
      queue<int> que;
      for (int i = 0; i < n; ++i)
        if (leftmate[i] == -1) {
          root[i] = i;
          que.push(i);
        }
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (leftmate[root[v]] != -1) continue;
        for (int u : adj[v]) {
          if (rightmate[u] == -1) {
            while (u != -1) {
              rightmate[u] = v;
              swap(leftmate[v], u);
              v = pre[v];
            }
            update = true;
            res++;
            break;
          }
          u = rightmate[u];
          if (pre[u] != -1) continue;
          pre[u] = v;
          root[u] = root[v];
          que.push(u);
        }
      }
      if (update)
        fill(pre.begin(), pre.end(), -1), fill(root.begin(), root.end(), -1);
    }
    return make_pair(res, make_pair(leftmate, rightmate));
  }
};
#line 8 "test/yosupo/bipartitematching.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int L, R, M;
  cin >> L >> R >> M;
  MatchingBipartite graph(L, R);
  while (M--) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_matching();
  auto left = ans.second.first;
  cout << ans.first << endl;
  for (int i = 0; i < left.size(); i++)
    if (left[i] != -1) {
      cout << i << " " << left[i] << endl;
    }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

