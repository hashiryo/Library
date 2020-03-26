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


# :heavy_check_mark: test/aoj/DSL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-26 12:31:03+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/UnionFind.hpp.html">DataStructure/UnionFind.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/UnionFind.hpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for(int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c)
            cout << uf.same(x, y) << "\n";
        else
            uf.unionSet(x, y);
    }
    cout << flush;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_1_A.test.cpp"
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/UnionFind.hpp"

#line 3 "DataStructure/UnionFind.hpp"
using namespace std;
#endif

struct UnionFind {
    vector<int> par;
    UnionFind(int size) : par(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if(x != y) {
            if(par[y] < par[x])
                swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
    int size(int x) { return -par[root(x)]; }
};
#line 9 "test/aoj/DSL_1_A.test.cpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for(int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c)
            cout << uf.same(x, y) << "\n";
        else
            uf.unionSet(x, y);
    }
    cout << flush;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

