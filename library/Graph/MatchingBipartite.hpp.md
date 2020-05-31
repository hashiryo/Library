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


# :heavy_check_mark: 最大マッチング(二部グラフ)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/MatchingBipartite.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 23:40:33+09:00


* see: <a href="https://snuke.hatenablog.com/entry/2019/05/07/013609">https://snuke.hatenablog.com/entry/2019/05/07/013609</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/277.test.cpp.html">test/yukicoder/277.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingBipartite {
  vector<vector<int>> to;
  int n, m;
  MatchingBipartite(int n, int m) : to(n), n(n), m(m) {}
  void add_edge(int l, int r) { to[l].push_back(r); }
  pair<int, pair<vector<int>, vector<int>>> get_matching() {
    vector<int> pre(n, -1), root(n, -1);
    vector<int> leftmate(n, -1), rightmate(m, -1);
    int res = 0;
    bool upd = true;
    while (upd) {
      upd = false;
      queue<int> s;
      for (int i = 0; i < n; ++i) {
        if (leftmate[i] == -1) {
          root[i] = i;
          s.push(i);
        }
      }
      while (!s.empty()) {
        int v = s.front();
        s.pop();
        if (leftmate[root[v]] != -1) continue;
        for (int i = 0; i < (int)to[v].size(); ++i) {
          int u = to[v][i];
          if (rightmate[u] == -1) {
            while (u != -1) {
              rightmate[u] = v;
              swap(leftmate[v], u);
              v = pre[v];
            }
            upd = true;
            ++res;
            break;
          }
          u = rightmate[u];
          if (pre[u] != -1) continue;
          pre[u] = v;
          root[u] = root[v];
          s.push(u);
        }
      }
      if (upd)
        fill(pre.begin(), pre.end(), -1), fill(root.begin(), root.end(), -1);
    }
    return make_pair(res, make_pair(leftmate, rightmate));
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingBipartite {
  vector<vector<int>> to;
  int n, m;
  MatchingBipartite(int n, int m) : to(n), n(n), m(m) {}
  void add_edge(int l, int r) { to[l].push_back(r); }
  pair<int, pair<vector<int>, vector<int>>> get_matching() {
    vector<int> pre(n, -1), root(n, -1);
    vector<int> leftmate(n, -1), rightmate(m, -1);
    int res = 0;
    bool upd = true;
    while (upd) {
      upd = false;
      queue<int> s;
      for (int i = 0; i < n; ++i) {
        if (leftmate[i] == -1) {
          root[i] = i;
          s.push(i);
        }
      }
      while (!s.empty()) {
        int v = s.front();
        s.pop();
        if (leftmate[root[v]] != -1) continue;
        for (int i = 0; i < (int)to[v].size(); ++i) {
          int u = to[v][i];
          if (rightmate[u] == -1) {
            while (u != -1) {
              rightmate[u] = v;
              swap(leftmate[v], u);
              v = pre[v];
            }
            upd = true;
            ++res;
            break;
          }
          u = rightmate[u];
          if (pre[u] != -1) continue;
          pre[u] = v;
          root[u] = root[v];
          s.push(u);
        }
      }
      if (upd)
        fill(pre.begin(), pre.end(), -1), fill(root.begin(), root.end(), -1);
    }
    return make_pair(res, make_pair(leftmate, rightmate));
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

