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


# :heavy_check_mark: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 15:26:05+09:00


* see: <a href="https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite">https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/LinkCutTree_Monoid.hpp.html">Link-Cut-Tree(モノイド)</a>
* :heavy_check_mark: <a href="../../../library/Math/ModInt.hpp.html">ModInt</a>


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
#line 1 "test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp"
#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

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
    Node(T init = M::ti()) : rev(false), val(init), dat(init), rdat(init) {
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
  LinkCutTree_Monoid(int n, T init = M::ti()) : ns(n, init) {}
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
#line 1 "Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#line 8 "Math/ModInt.hpp"
using namespace std;
#endif

template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) { return *this *= p.inverse(); }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
    return ModInt(u);
  }
  ModInt pow(int64_t e) const {
    ModInt ret(1);
    for (ModInt b = *this; e; e >>= 1, b *= b)
      if (e & 1) ret *= b;
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int modulo() { return mod; }
};
#line 10 "test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp"
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

<a href="../../../index.html">Back to top page</a>

