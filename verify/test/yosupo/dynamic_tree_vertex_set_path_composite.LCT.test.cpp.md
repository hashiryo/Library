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


# :x: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/LinkCutTree_Monoid.hpp"
#include "Math/ModInt.hpp"
#undef call_from_test

using Mint = ModInt<998244353>;
struct RcompositeQ {
  using T = pair<Mint, Mint>;
  static T ti() { return make_pair(Mint(1), Mint(0)); }
  static T f(const T &l, const T &r) {
    return make_pair(r.first * l.first, r.first * l.second + r.second);
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  LinkCutTree_Monoid<RcompositeQ> lct(N);
  for (int i = 0; i < N; i++) {
    Mint a, b;
    cin >> a >> b;
    lct.set_val(i, {a, b});
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    lct.link(u, v);
  }
  while (Q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int u, v, w, x;
      cin >> u >> v >> w >> x;
      lct.cut(u, v);
      lct.link(w, x);
    } else if (op == 1) {
      int p;
      Mint c, d;
      cin >> p >> c >> d;
      lct.set_val(p, {c, d});
    } else {
      int u, v;
      Mint x;
      cin >> u >> v >> x;
      auto ans = lct.query(u, v);
      cout << ans.first * x + ans.second << endl;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: DataStructure/LinkCutTree_Monoid.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

