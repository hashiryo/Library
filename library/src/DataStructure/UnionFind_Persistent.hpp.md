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


# :heavy_check_mark: Union-Find(完全永続)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/UnionFind_Persistent.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-13 01:21:15+09:00




## Depends on

* :heavy_check_mark: <a href="PersistentArray.hpp.html">永続配列</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/persistent_unionfind.test.cpp.html">test/yosupo/persistent_unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Union-Find(完全永続)
 * @category データ構造
 * 経路圧縮なし O(logN)
 */
// verify用:
// https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/PersistentArray.hpp"
#undef call_from_test
#endif

struct UnionFind_Persistent {
  PersistentArray<int> par;
  UnionFind_Persistent() {}
  UnionFind_Persistent(int n) : par(n, -1) {}
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;
    if (par.get(u) > par.get(v)) swap(u, v);
    par[u] += par.get(v), par[v] = u;
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int root(int u) { return par.get(u) < 0 ? u : root(par.get(u)); }
  int size(int u) { return -par.get(root(u)); }
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/UnionFind_Persistent.hpp: line 14: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

