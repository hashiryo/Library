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


# :heavy_check_mark: test/yosupo/directedmst.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/directedmst.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-13 01:05:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/directedmst">https://judge.yosupo.jp/problem/directedmst</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/DataStructure/SkewHeap.hpp.html">Skew-Heap</a>
* :heavy_check_mark: <a href="../../../library/src/DataStructure/UnionFind.hpp.html">Union-Find</a>
* :heavy_check_mark: <a href="../../../library/src/Graph/MinimumSpanningAborescense.hpp.html">最小全域有向木</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/UnionFind.hpp"
#include "src/DataStructure/SkewHeap.hpp"
#include "src/Graph/MinimumSpanningAborescense.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M, r;
  cin >> N >> M >> r;
  MinimumSpanningAborescense<long long> graph(N);
  for (int i = 0; i < M; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    graph.add_edge(s, t, w);
  }
  auto ans = graph.get_MSA(r);
  vector<int> par(N);
  iota(par.begin(), par.end(), 0);
  for (auto e : ans.second) par[e.dst] = e.src;
  cout << ans.first << endl;
  for (int i = 0; i < N; i++) cout << (i ? " " : "") << par[i];
  cout << endl;
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Graph/MinimumSpanningAborescense.hpp: line 14: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

