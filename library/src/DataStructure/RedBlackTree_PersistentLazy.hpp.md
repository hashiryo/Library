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


# :heavy_check_mark: 赤黒木(永続遅延伝搬)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/RedBlackTree_PersistentLazy.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-13 01:05:53+09:00




## Depends on

* :heavy_check_mark: <a href="RedBlackTree_Lazy.hpp.html">赤黒木(遅延伝搬)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/persistent_queue.RBTPL.test.cpp.html">test/yosupo/persistent_queue.RBTPL.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 赤黒木(永続遅延伝搬)
 * @category データ構造
 * @brief O(logN)
 */

// verify用: https://atcoder.jp/contests/arc030/tasks/arc030_4
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/RedBlackTree_Lazy.hpp"
#undef call_from_test
#endif

template <typename M, size_t LIM = 1 << 22, size_t FULL = 1000>
struct RedBlackTree_PersistentLazy : RedBlackTree_Lazy<M, LIM> {
  using RBTL = RedBlackTree_Lazy<M, LIM>;
  using RBTL::RedBlackTree_Lazy;
  using Node = typename RBTL::Node;
  using RBTPL = RedBlackTree_PersistentLazy;

 private:
  Node *clone(Node *t) override { return &(*RBTL::pool.alloc() = *t); }

 public:
  // merge
  RBTPL operator+(const RBTPL &r) {
    if (!this->root || !r.root) return this->root ? *this : r;
    Node *c = RBTL::submerge(this->root, r.root);
    c->color = RBTL::BLACK;
    return RBTPL(c);
  }
  // [0,k) [k,size)
  pair<RBTPL, RBTPL> split(int k) {
    auto tmp = RBTL::split(this->root, k);
    return make_pair(RBTPL(tmp.first), RBTPL(tmp.second));
  }
  // [0,a) [a,b) [b,size)
  tuple<RBTPL, RBTPL, RBTPL> split3(int a, int b) {
    auto x = RBTL::split(this->root, a);
    auto y = RBTL::split(x.second, b - a);
    return make_tuple(RBTPL(x.first), RBTPL(y.first), RBTPL(y.second));
  }
  void rebuild() {
    auto ret = RBTL::dump();
    RBTL::pool.clear();
    RBTL::build(ret);
  }
  static bool almost_full() { return RBTL::pool.ptr < FULL; }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/RedBlackTree_PersistentLazy.hpp: line 13: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

