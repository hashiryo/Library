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


# :heavy_check_mark: test/yosupo/scc.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/scc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 14:58:00+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/StronglyConnectedComponents.hpp.html">強連結成分分解</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/StronglyConnectedComponents.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  StronglyConnectedComponents graph(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_SCC().first;
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
#line 1 "test/yosupo/scc.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/StronglyConnectedComponents.hpp"
/**
 * @title 強連結成分分解
 * @category グラフ
 * @brief Gabow
 * @brief O(V + E)
 * @brief 返り値:{強連結成分(トポロジカルソート),ノードの属する成分の添字}
 */

#ifndef call_from_test
#line 11 "Graph/StronglyConnectedComponents.hpp"
using namespace std;
#endif

struct StronglyConnectedComponents {
 private:
  int n;
  vector<vector<int>> radj;

 public:
  StronglyConnectedComponents(int n) : n(n), radj(n) {}
  void add_edge(int src, int dst) { radj[dst].push_back(src); }
  pair<vector<vector<int>>, vector<int>> get_SCC() {
    vector<vector<int>> scc;
    vector<int> S, B, index(n);
    function<void(int)> dfs = [&](int u) {
      B.push_back(index[u] = S.size());
      S.push_back(u);
      for (int v : radj[u]) {
        if (!index[v])
          dfs(v);
        else
          while (index[v] < B.back()) B.pop_back();
      }
      if (index[u] == B.back()) {
        scc.push_back({});
        B.pop_back();
        for (; index[u] < S.size(); S.pop_back()) {
          scc.back().push_back(S.back());
          index[S.back()] = n + scc.size();
        }
      }
    };
    for (int u = 0; u < n; ++u)
      if (!index[u]) dfs(u);
    for (int u = 0; u < n; ++u) index[u] -= n + 1;
    return make_pair(scc, index);
  }
};
#line 8 "test/yosupo/scc.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  StronglyConnectedComponents graph(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  auto ans = graph.get_SCC().first;
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

