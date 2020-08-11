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


# :x: test/yosupo/min_cost_b_flow.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/min_cost_b_flow.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MinCostFlow.hpp"
#undef call_from_test

ostream &operator<<(ostream &stream, const __int128_t &v) {
  if (v == 0) stream << "0";
  __int128_t tmp;
  if (v < 0) {
    stream << "-";
    tmp = -v;
  } else {
    tmp = v;
  }
  std::string s;
  while (tmp) {
    s += '0' + (tmp % 10);
    tmp /= 10;
  }
  std::reverse(s.begin(), s.end());
  stream << s;
  return stream;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  using MCF = MinCostFlow<long long, long long>;
  MCF graph;
  vector<MCF::EdgePtr> edges;
  int N, M;
  cin >> N >> M;
  graph.add_vertices(N);
  for (int i = 0; i < N; i++) {
    long long b;
    cin >> b;
    graph.add_supply(i, b);
  }
  for (int i = 0; i < M; i++) {
    long long s, t, l, u, c;
    cin >> s >> t >> l >> u >> c;
    edges.emplace_back(graph.add_edge(s, t, l, u, c));
  }
  bool isok = graph.flow_run().first;
  if (isok) {
    cout << graph.get_result_value<__int128_t>() << endl;
    auto potential = graph.get_potential();
    for (auto p : potential) cout << p << endl;
    for (auto &e : edges) cout << e.flow() << endl;
  } else {
    cout << "infeasible" << endl;
  }
  return 0;
}

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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/MinCostFlow.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

