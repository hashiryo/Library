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


# :heavy_check_mark: test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 14:51:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum">https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/LinkCutTree_Monoid.hpp.html">Link-Cut-Tree(モノイド)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/LinkCutTree_Monoid.hpp"
#undef call_from_test

struct RsumQ {
  using T = long long;
  static T ti() { return 0; }
  static T f(const T &l, const T &r) { return l + r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  LinkCutTree_Monoid<RsumQ> lct(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    lct.set_val(i, a);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    lct.link(v, u);
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
      long long x;
      cin >> p >> x;
      lct.set_val(p, lct[p] + x);
    } else {
      int u, v;
      cin >> u >> v;
      cout << lct.query(u, v) << endl;
    }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp"
#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/LinkCutTree_Monoid.hpp"
/**
 * @title Link-Cut-Tree(モノイド)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#line 9 "DataStructure/LinkCutTree_Monoid.hpp"
using namespace std;
#endif

template <typename M>
struct LinkCutTree_Monoid {
  using T = typename M::T;
  struct Node {
    Node *ch[2], *par;
    bool rev;
    T val, dat, rdat;
    Node() : rev(false), val(M::ti()), dat(M::ti()), rdat(M::ti()) {
      ch[0] = ch[1] = par = nullptr;
    }
  };

 private:
  bool is_root(Node *x) {
    return !x->par || (x->par->ch[0] != x && x->par->ch[1] != x);
  }
  bool dir(Node *x) { return x->par && x->par->ch[1] == x; }
  void rot(Node *t) {
    Node *p = t->par;
    bool d = dir(t);
    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;
    t->ch[!d] = p;
    pushup(p);
    pushup(t);
    t->par = p->par;
    if (!is_root(p)) {
      p->par->ch[dir(p)] = t;
      pushup(t->par);
    }
    p->par = t;
  }
  void splay(Node *x) {
    eval(x);
    while (!is_root(x)) {
      if (!is_root(x->par)) eval(x->par->par);
      eval(x->par);
      eval(x);
      if (!is_root(x->par)) {
        if (dir(x) == dir(x->par))
          rot(x->par);
        else
          rot(x);
      }
      rot(x);
    }
  }
  void pushup(Node *t) {
    t->rdat = t->dat = t->val;
    if (t->ch[0])
      t->dat = M::f(t->ch[0]->dat, t->dat),
      t->rdat = M::f(t->rdat, t->ch[0]->rdat);
    if (t->ch[1])
      t->dat = M::f(t->dat, t->ch[1]->dat),
      t->rdat = M::f(t->ch[1]->rdat, t->rdat);
  }
  Node *expose(Node *x) {
    Node *r = nullptr;
    for (Node *p = x; p; p = p->par) {
      splay(p);
      p->ch[1] = r;
      pushup(p);
      r = p;
    }
    splay(x);
    return r;
  }
  void toggle(Node *t) {
    swap(t->ch[0], t->ch[1]);
    swap(t->dat, t->rdat);
    t->rev ^= 1;
  }
  Node *eval(Node *t) {
    if (t->rev) {
      if (t->ch[0]) toggle(t->ch[0]);
      if (t->ch[1]) toggle(t->ch[1]);
      t->rev = false;
    }
    return t;
  }

 public:
  vector<Node> ns;

 public:
  LinkCutTree_Monoid(int n) : ns(n) {}
  // make k the root
  void evert(int k) {
    expose(&ns[k]);
    toggle(&ns[k]);
    eval(&ns[k]);
  }
  // add link from c to p
  void link(int c, int p) {
    evert(c);
    expose(&ns[p]);
    ns[p].ch[1] = &ns[c];
    ns[c].par = &ns[p];
    pushup(&ns[p]);
  }
  // cut link from c to p
  void cut(int c, int p) {
    evert(p);
    expose(&ns[c]);
    Node *y = ns[c].ch[0];
    ns[c].ch[0] = y->par = nullptr;
    pushup(&ns[c]);
  }
  int lca(int x, int y) {
    expose(&ns[x]);
    Node *u = expose(&ns[y]);
    return ns[x].par ? u - &ns[0] : -1;
  }
  T operator[](int k) { return ns[k].val; }
  // [a,b] closed section
  T query(int a, int b) {
    evert(a);
    expose(&ns[b]);
    return ns[b].dat;
  }
  void set_val(int k, T v) {
    expose(&ns[k]);
    ns[k].val = v;
    eval(&ns[k]);
  }
};
#line 9 "test/yosupo/dynamic_tree_vertex_add_path_sum.LCT.test.cpp"
#undef call_from_test

struct RsumQ {
  using T = long long;
  static T ti() { return 0; }
  static T f(const T &l, const T &r) { return l + r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  LinkCutTree_Monoid<RsumQ> lct(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    lct.set_val(i, a);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    lct.link(v, u);
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
      long long x;
      cin >> p >> x;
      lct.set_val(p, lct[p] + x);
    } else {
      int u, v;
      cin >> u >> v;
      cout << lct.query(u, v) << endl;
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

