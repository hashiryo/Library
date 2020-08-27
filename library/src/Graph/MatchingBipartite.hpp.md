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


# :heavy_check_mark: 最大マッチング(二部グラフ)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/MatchingBipartite.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 16:22:18+09:00


* see: <a href="https://snuke.hatenablog.com/entry/2019/05/07/013609">https://snuke.hatenablog.com/entry/2019/05/07/013609</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0334.test.cpp.html">test/aoj/0334.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2423.test.cpp.html">test/aoj/2423.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/421.test.cpp.html">test/yukicoder/421.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最大マッチング(二部グラフ)
 * @category グラフ
 *  O(VE) 速い(O(E√V)並?)
 *  返り値:{マッチング数,{左の相方(いないなら-1),右の相方(いないなら-1)}}
 *  lexicographically_matching 辞書順最小
 * @see https://snuke.hatenablog.com/entry/2019/05/07/013609
 */
// 被覆問題との関係 https://qiita.com/drken/items/7f98315b56c95a6181a4

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingBipartite {
 private:
  vector<vector<int>> adj;
  vector<int> pre, rt;
  vector<int> lmate, rmate;

  bool dfs(int v, const int &tstamp) {
    pre[v] = tstamp;
    for (int u : adj[v]) {
      int w = rmate[u];
      if (w == -1 || (rt[w] != -2 && pre[w] != tstamp && dfs(w, tstamp))) {
        rmate[u] = v;
        lmate[v] = u;
        return true;
      }
    }
    return false;
  }

 public:
  MatchingBipartite(int n, int m)
      : adj(n), pre(n, -1), rt(n, -1), lmate(n, -1), rmate(m, -1) {}
  void add_edge(int l, int r) { adj[l].push_back(r); }
  pair<int, pair<vector<int>, vector<int>>> get_matching() {
    int res = 0;
    queue<int> que;
    for (bool update = true; update;) {
      update = false;
      for (int i = 0; i < (int)adj.size(); i++)
        if (lmate[i] == -1) que.push(rt[i] = i);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (lmate[rt[v]] != -1) continue;
        for (int u : adj[v]) {
          if (rmate[u] == -1) {
            for (; u != -1; v = pre[v]) rmate[u] = v, swap(lmate[v], u);
            update = true;
            res++;
            break;
          }
          u = rmate[u];
          if (pre[u] != -1) continue;
          rt[u] = rt[pre[u] = v];
          que.push(u);
        }
      }
      if (update)
        fill(pre.begin(), pre.end(), -1), fill(rt.begin(), rt.end(), -1);
    }
    return make_pair(res, make_pair(lmate, rmate));
  }
  pair<int, pair<vector<int>, vector<int>>> lexicographically_matching() {
    int res = get_matching().first;
    int tstamp = -2;
    for (int i = 0; i < (int)adj.size(); i++) {
      if (lmate[i] != -1) {
        rmate[lmate[i]] = -1;
        lmate[i] = -1;
        dfs(i, --tstamp);
        rt[i] = -2;
      }
    }
    return make_pair(res, make_pair(lmate, rmate));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/MatchingBipartite.hpp"
/**
 * @title 最大マッチング(二部グラフ)
 * @category グラフ
 *  O(VE) 速い(O(E√V)並?)
 *  返り値:{マッチング数,{左の相方(いないなら-1),右の相方(いないなら-1)}}
 *  lexicographically_matching 辞書順最小
 * @see https://snuke.hatenablog.com/entry/2019/05/07/013609
 */
// 被覆問題との関係 https://qiita.com/drken/items/7f98315b56c95a6181a4

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct MatchingBipartite {
 private:
  vector<vector<int>> adj;
  vector<int> pre, rt;
  vector<int> lmate, rmate;

  bool dfs(int v, const int &tstamp) {
    pre[v] = tstamp;
    for (int u : adj[v]) {
      int w = rmate[u];
      if (w == -1 || (rt[w] != -2 && pre[w] != tstamp && dfs(w, tstamp))) {
        rmate[u] = v;
        lmate[v] = u;
        return true;
      }
    }
    return false;
  }

 public:
  MatchingBipartite(int n, int m)
      : adj(n), pre(n, -1), rt(n, -1), lmate(n, -1), rmate(m, -1) {}
  void add_edge(int l, int r) { adj[l].push_back(r); }
  pair<int, pair<vector<int>, vector<int>>> get_matching() {
    int res = 0;
    queue<int> que;
    for (bool update = true; update;) {
      update = false;
      for (int i = 0; i < (int)adj.size(); i++)
        if (lmate[i] == -1) que.push(rt[i] = i);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (lmate[rt[v]] != -1) continue;
        for (int u : adj[v]) {
          if (rmate[u] == -1) {
            for (; u != -1; v = pre[v]) rmate[u] = v, swap(lmate[v], u);
            update = true;
            res++;
            break;
          }
          u = rmate[u];
          if (pre[u] != -1) continue;
          rt[u] = rt[pre[u] = v];
          que.push(u);
        }
      }
      if (update)
        fill(pre.begin(), pre.end(), -1), fill(rt.begin(), rt.end(), -1);
    }
    return make_pair(res, make_pair(lmate, rmate));
  }
  pair<int, pair<vector<int>, vector<int>>> lexicographically_matching() {
    int res = get_matching().first;
    int tstamp = -2;
    for (int i = 0; i < (int)adj.size(); i++) {
      if (lmate[i] != -1) {
        rmate[lmate[i]] = -1;
        lmate[i] = -1;
        dfs(i, --tstamp);
        rt[i] = -2;
      }
    }
    return make_pair(res, make_pair(lmate, rmate));
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

