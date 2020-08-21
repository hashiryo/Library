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


# :heavy_check_mark: 二分Trie

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/BinaryTrie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-13 01:05:53+09:00




## Depends on

* :heavy_check_mark: <a href="SegmentTree_Dynamic.hpp.html">Segment-Tree(動的)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/set_xor_min.test.cpp.html">test/yosupo/set_xor_min.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/649.BinaryTrie.test.cpp.html">test/yukicoder/649.BinaryTrie.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 二分Trie
 * @category データ構造
 * @brief O(logN)
 * @brief multiset的な仕様(内部は動的セグ木)
 */
// verify用:
// https://codeforces.com/contest/947/problem/C
// https://codeforces.com/contest/966/problem/C

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/DataStructure/SegmentTree_Dynamic.hpp"
#undef call_from_test
#endif

struct RsumQ {
  using T = int;
  static T ti() { return 0; }
  static T f(const T &l, const T &r) { return l + r; }
};
struct BinaryTrie : public SegmentTree_Dynamic<RsumQ> {
  using ll = long long;
  using U = unsigned long long;
  BinaryTrie(ll max_val = INT_MAX) : SegmentTree_Dynamic<RsumQ>(max_val) {}
  void insert(U val) { set_val(val, (*this)[val] + 1); }
  void erase(U val) { set_val(val, (*this)[val] - 1); }
  ll kth_element(int k, U bias = 0) {
    auto check = [&](int x) { return x > k; };
    return find_first(check, bias);
  }
  ll min_element(U bias = 0) { return kth_element(0, bias); }
  ll max_element(U bias = 0) { return kth_element(0, ~bias); }
  int lower_bound(U val) { return query(0, val); }
  int upper_bound(U val) { return query(0, val + 1); }
  int count(U val) { return query(val, val + 1); }
  int size() { return root ? root->dat : 0; }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/BinaryTrie.hpp: line 16: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

