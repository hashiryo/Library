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


# :question: 強連結成分分解

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/StronglyConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:23:42+09:00




## Required by

* :x: <a href="../Math/TwoSatisfiability.hpp.html">2-SAT</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/PCK0366.test.cpp.html">test/aoj/PCK0366.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 強連結成分分解
 * @category グラフ
 *  Gabow
 *  O(V + E)
 *  返り値:{強連結成分(トポロジカルソート),ノードの属する成分の添字}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Graph/StronglyConnectedComponents.hpp"
/**
 * @title 強連結成分分解
 * @category グラフ
 *  Gabow
 *  O(V + E)
 *  返り値:{強連結成分(トポロジカルソート),ノードの属する成分の添字}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

