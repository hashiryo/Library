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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Segment-Tree(動的)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree_Dynamic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-15 20:49:13+09:00




## Required by

* :heavy_check_mark: <a href="BinaryTrie.hpp.html">二分Trie</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/649.BinaryTrie.test.cpp.html">test/yukicoder/649.BinaryTrie.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/649.SegTree_Dynamic.test.cpp.html">test/yukicoder/649.SegTree_Dynamic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Segment-Tree(動的)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M, size_t LIM = 1 << 23>
struct SegmentTree_Dynamic {
  using T = typename M::T;
  using ll = long long;
  using U = unsigned long long;
  struct Node {
    T dat;
    U xor_lazy;
    Node *ch[2];
    Node() : dat(M::ti()), xor_lazy(0), ch{nullptr, nullptr} {}
    void *operator new(size_t) {
      static vector<Node> pool(LIM);
      return &pool[node_count++];
    }
  };

 protected:
  int height;
  ll n;
  static int node_count;
  Node *root;

 private:
  inline void push(Node *t, ll b) {
    if ((t->xor_lazy >> (U)b) & (U)1) swap(t->ch[0], t->ch[1]);
    if (t->ch[0] != nullptr) t->ch[0]->xor_lazy ^= t->xor_lazy;
    if (t->ch[1] != nullptr) t->ch[1]->xor_lazy ^= t->xor_lazy;
    t->xor_lazy = 0;
  }
  T value(Node *t) { return t ? t->dat : M::ti(); }
  Node *set_Node(Node *t, const U &pos, const T &val, ll b) {
    if (t == nullptr) t = new Node();
    if (b < 0) {
      t->dat = val;
      return t;
    }
    push(t, b);
    bool f = (pos >> (U)b) & (U)1;
    t->ch[f] = set_Node(t->ch[f], pos, val, b - 1);
    t->dat = M::f(value(t->ch[0]), value(t->ch[1]));
    return t;
  }
  T query_Node(const ll &l, const ll &r, Node *t, const ll &lb, const ll &ub,
               ll b) {
    if (t == nullptr || ub <= l || r <= lb) return M::ti();
    push(t, b);
    if (l <= lb && ub <= r) return t->dat;
    ll c = (lb + ub) / 2;
    T vl = query_Node(l, r, t->ch[0], lb, c, b - 1);
    T vr = query_Node(l, r, t->ch[1], c, ub, b - 1);
    return M::f(vl, vr);
  }
  template <typename C>
  ll find(Node *t, C &check, U bias) {
    if (!t) return -1;
    ll ret = 0;
    T acc = M::ti();
    for (ll b = height - 1; b >= 0; b--) {
      push(t, b);
      bool f = (bias >> (U)b) & (U)1;
      if (!check(M::f(acc, value(t->ch[f]))))
        acc = M::f(acc, value(t->ch[f])), f = !f;
      t = t->ch[f];
      if (!t) return -1;
      ret |= (U)f << (U)b;
    }
    return ret;
  }

 public:
  SegmentTree_Dynamic() {}
  SegmentTree_Dynamic(ll n_)
      : height(ceil(log2(n_))), n(1LL << height), root(nullptr) {}
  void clear() {
    node_count = 0;
    root = nullptr;
  }
  void xor_all(U key) {
    if (root != nullptr) root->xor_lazy ^= key;
  }
  void set_val(ll k, T x) { root = set_Node(root, k, x, height - 1); }
  //[a,b)
  T query(ll a, ll b) { return query_Node(a, b, root, 0, n, height - 1); }
  T operator[](ll k) { return query(k, k + 1); }
  // min { i : check(query(0,i+1)) = true }
  template <typename C>
  ll find_first(C &check, U bias = 0) {
    return find(root, check, bias);
  }
};
template <typename M, size_t LIM>
int SegmentTree_Dynamic<M, LIM>::node_count = 0;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree_Dynamic.hpp"
/**
 * @title Segment-Tree(動的)
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M, size_t LIM = 1 << 23>
struct SegmentTree_Dynamic {
  using T = typename M::T;
  using ll = long long;
  using U = unsigned long long;
  struct Node {
    T dat;
    U xor_lazy;
    Node *ch[2];
    Node() : dat(M::ti()), xor_lazy(0), ch{nullptr, nullptr} {}
    void *operator new(size_t) {
      static vector<Node> pool(LIM);
      return &pool[node_count++];
    }
  };

 protected:
  int height;
  ll n;
  static int node_count;
  Node *root;

 private:
  inline void push(Node *t, ll b) {
    if ((t->xor_lazy >> (U)b) & (U)1) swap(t->ch[0], t->ch[1]);
    if (t->ch[0] != nullptr) t->ch[0]->xor_lazy ^= t->xor_lazy;
    if (t->ch[1] != nullptr) t->ch[1]->xor_lazy ^= t->xor_lazy;
    t->xor_lazy = 0;
  }
  T value(Node *t) { return t ? t->dat : M::ti(); }
  Node *set_Node(Node *t, const U &pos, const T &val, ll b) {
    if (t == nullptr) t = new Node();
    if (b < 0) {
      t->dat = val;
      return t;
    }
    push(t, b);
    bool f = (pos >> (U)b) & (U)1;
    t->ch[f] = set_Node(t->ch[f], pos, val, b - 1);
    t->dat = M::f(value(t->ch[0]), value(t->ch[1]));
    return t;
  }
  T query_Node(const ll &l, const ll &r, Node *t, const ll &lb, const ll &ub,
               ll b) {
    if (t == nullptr || ub <= l || r <= lb) return M::ti();
    push(t, b);
    if (l <= lb && ub <= r) return t->dat;
    ll c = (lb + ub) / 2;
    T vl = query_Node(l, r, t->ch[0], lb, c, b - 1);
    T vr = query_Node(l, r, t->ch[1], c, ub, b - 1);
    return M::f(vl, vr);
  }
  template <typename C>
  ll find(Node *t, C &check, U bias) {
    if (!t) return -1;
    ll ret = 0;
    T acc = M::ti();
    for (ll b = height - 1; b >= 0; b--) {
      push(t, b);
      bool f = (bias >> (U)b) & (U)1;
      if (!check(M::f(acc, value(t->ch[f]))))
        acc = M::f(acc, value(t->ch[f])), f = !f;
      t = t->ch[f];
      if (!t) return -1;
      ret |= (U)f << (U)b;
    }
    return ret;
  }

 public:
  SegmentTree_Dynamic() {}
  SegmentTree_Dynamic(ll n_)
      : height(ceil(log2(n_))), n(1LL << height), root(nullptr) {}
  void clear() {
    node_count = 0;
    root = nullptr;
  }
  void xor_all(U key) {
    if (root != nullptr) root->xor_lazy ^= key;
  }
  void set_val(ll k, T x) { root = set_Node(root, k, x, height - 1); }
  //[a,b)
  T query(ll a, ll b) { return query_Node(a, b, root, 0, n, height - 1); }
  T operator[](ll k) { return query(k, k + 1); }
  // min { i : check(query(0,i+1)) = true }
  template <typename C>
  ll find_first(C &check, U bias = 0) {
    return find(root, check, bias);
  }
};
template <typename M, size_t LIM>
int SegmentTree_Dynamic<M, LIM>::node_count = 0;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

