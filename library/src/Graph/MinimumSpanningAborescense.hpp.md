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


# :question: 最小全域有向木

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a834e14ea57a0cf726f79f1ab2dcc39">グラフ</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Graph/MinimumSpanningAborescense.hpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2647.test.cpp.html">test/aoj/2647.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/directedmst.test.cpp.html">test/yosupo/directedmst.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最小全域有向木
 * @category グラフ
 *  Chu-Liu/Edmonds
 *  O(E log V)
 *  返り値:{全域木のコスト総和,全域木に使用する辺}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/UnionFind.hpp"
#include "DataStructure/SkewHeap.hpp"
#undef call_from_test
#endif

template <typename cost_t>
struct MinimumSpanningAborescense {
  struct Edge {
    int src, dst, id;
    cost_t cost;
    bool operator>(const Edge &r) const { return this->cost > r.cost; }
    Edge() {}
    Edge(int s, int d, int i, int c) : src(s), dst(d), id(i), cost(c) {}
  };
  struct Op_Edge_add {
    using E = cost_t;
    static E ei() { return 0; }
    static Edge g(const Edge &l, const E &r) {
      return Edge(l.src, l.dst, l.id, l.cost + r);
    }
    static E h(const E &l, const E &r) { return l + r; }
  };
  using Heap = SkewHeap<Edge, greater<Edge>, Op_Edge_add>;

 private:
  int n;

 public:
  vector<Edge> edges;

 public:
  MinimumSpanningAborescense(int n) : n(n) {}
  void add_edge(int src, int dst, cost_t cost) {
    edges.emplace_back(src, dst, edges.size(), cost);
  }
  pair<cost_t, vector<Edge>> get_MSA(int root) {
    UnionFind uf(n);
    vector<Heap> heap(n);
    for (auto &e : edges) heap[e.dst].push(e);
    cost_t score = 0;
    int m = edges.size();
    vector<int> seen(n, -1), paredge(m), ei, leaf(n, -1), par(n), usede(m);
    seen[root] = root;
    for (int s = 0; s < n; ++s) {
      vector<int> path, ch;
      int cyc = 0;
      for (int u = s; seen[u] < 0;) {
        path.push_back(u);
        seen[u] = s;
        if (heap[u].empty()) return {-1, vector<Edge>()};
        Edge min_e = heap[u].top();
        score += min_e.cost;
        heap[u].add(-min_e.cost);
        heap[u].pop();
        ei.push_back(min_e.id);
        if (leaf[min_e.dst] == -1) leaf[min_e.dst] = min_e.id;
        while (cyc) {
          paredge[ch.back()] = min_e.id;
          ch.pop_back();
          cyc--;
        }
        ch.push_back(min_e.id);
        int v = uf.root(min_e.src);
        if (seen[v] == s) {
          Heap new_heap;
          while (1) {
            int w = path.back();
            path.pop_back();
            new_heap.merge(heap[w]);
            cyc++;
            if (!uf.unite(v, w)) break;
          }
          heap[uf.root(v)] = new_heap;
          seen[uf.root(v)] = -1;
        }
        u = uf.root(v);
      }
    }
    reverse(ei.begin(), ei.end());
    vector<Edge> es;
    for (auto i : ei) {
      if (usede[i]) continue;
      es.emplace_back(edges[i]);
      int x = leaf[edges[i].dst];
      while (x != i) {
        usede[x] = 1;
        x = paredge[x];
      }
    }
    return {score, es};
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Graph/MinimumSpanningAborescense.hpp: line 14: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

