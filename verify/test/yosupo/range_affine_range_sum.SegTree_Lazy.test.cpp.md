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


# :x: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/SegmentTree_Lazy.hpp"
#include "Math/ModInt.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;
// RsumQはモノイドでサイズを持っておく
struct RaffineQ_RsumQ {
  struct T {
    Mint val;
    int size;
    T(Mint v = 0, int s = 1) : val(v), size(s) {}
  };
  using E = pair<Mint, Mint>;
  static T ti() { return T(0, 0); }
  static E ei() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return T(l.val + r.val, l.size + r.size);
  }
  static T g(const T &l, const E &r) {
    return T(r.first * l.val + r.second * l.size, l.size);
  }
  static E h(const E &l, const E &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<RaffineQ_RsumQ::T> v(N);
  for (int i = 0; i < N; i++) {
    Mint a;
    cin >> a;
    v[i] = {a, 1};
  }
  SegmentTree_Lazy<RaffineQ_RsumQ> seg(v);
  while (Q--) {
    bool op;
    int l, r;
    cin >> op >> l >> r;
    if (op) {
      cout << seg.query(l, r).val << endl;
    } else {
      Mint b, c;
      cin >> b >> c;
      seg.update(l, r, {Mint(b), Mint(c)});
    }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: DataStructure/SegmentTree_Lazy.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

