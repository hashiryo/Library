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


# :x: 2-SAT

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/TwoSatisfiability.hpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Verified with

* :x: <a href="../../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 2-SAT
 * @category 数学
 *  強連結成分分解を用いる
 *  solve():真偽値の割当を返す(充足不可能なら空)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/StronglyConnectedComponents.hpp"
#undef call_from_test
#endif

struct TwoSatisfiability {
 private:
  int sz;
  StronglyConnectedComponents scc;

 public:
  TwoSatisfiability(int n) : sz(n), scc(2 * n) {}
  void add_if(int u, int v) {
    scc.add_edge(u, v);
    scc.add_edge(neg(v), neg(u));
  }                                                   // u -> v <=> !v -> !u
  void add_or(int u, int v) { add_if(neg(u), v); }    // u or v <=> !u -> v
  void add_nand(int u, int v) { add_if(u, neg(v)); }  // u nand v <=> u -> !v
  void set_true(int u) { scc.add_edge(neg(u), u); }   // u <=> !u -> u
  void set_false(int u) { scc.add_edge(u, neg(u)); }  // !u <=> u -> !u
  inline int neg(int x) { return x >= sz ? x - sz : x + sz; }
  vector<short> solve() {
    vector<int> I = scc.get_SCC().second;
    vector<short> ret(sz);
    for (int i = 0; i < sz; i++) {
      if (I[i] == I[neg(i)]) return {};
      ret[i] = I[i] > I[neg(i)];
    }
    return ret;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/TwoSatisfiability.hpp: line 13: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

