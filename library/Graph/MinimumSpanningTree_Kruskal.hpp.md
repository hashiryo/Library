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


# :heavy_check_mark: 最小全域木(Kruskal)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/MinimumSpanningTree_Kruskal.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 15:26:05+09:00




## Depends on

* :heavy_check_mark: <a href="../DataStructure/UnionFind.hpp.html">Union-Find</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2559.LCT_Dual.test.cpp.html">test/aoj/2559.LCT_Dual.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.kruskal.test.cpp.html">test/aoj/GRL_2_A.kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最小全域木(Kruskal)
 * @category グラフ
 * @brief O(m log n)
 * @brief 返り値:{全域木のコスト総和,全域木に使用する辺}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/UnionFind.hpp"
#undef call_from_test
#endif

template <typename cost_t>
struct MinimumSpanningTree_Kruskal {
  struct Edge {
    int src, dst, id;
    cost_t cost;
    bool operator<(const Edge &rhs) const { return this->cost < rhs.cost; }
    Edge() {}
    Edge(int s, int d, int i, int c) : src(s), dst(d), id(i), cost(c) {}
  };

 private:
  int n;

 public:
  vector<Edge> edges;

 public:
  MinimumSpanningTree_Kruskal(int n) : n(n) {}
  void add_edge(int src, int dst, cost_t cost) {
    edges.emplace_back(src, dst, edges.size(), cost);
  }
  pair<cost_t, vector<Edge>> get_MST() {
    UnionFind uf(n);
    sort(begin(edges), end(edges));
    cost_t total = cost_t();
    vector<Edge> es;
    for (auto &e : edges)
      if (uf.unite(e.src, e.dst)) {
        es.emplace_back(e);
        total += e.cost;
      }
    return {total, es};
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/MinimumSpanningTree_Kruskal.hpp: line 13: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

