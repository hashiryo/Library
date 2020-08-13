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


# :heavy_check_mark: 赤黒木

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/RedBlackTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Required by

* :heavy_check_mark: <a href="RedBlackTree_Persistent.hpp.html">赤黒木(永続)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1508.RBT.test.cpp.html">test/aoj/1508.RBT.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/persistent_queue.RBTP.test.cpp.html">test/yosupo/persistent_queue.RBTP.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 赤黒木
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M, size_t LIM = 1 << 20>
struct RedBlackTree {
  using T = typename M::T;

 public:
  enum COLOR { BLACK, RED };
  struct Node {
    Node *ch[2];
    COLOR color;
    int level, cnt;
    T val, dat;
    Node() {}
    Node(const T &k)
        : val(k),
          dat(k),
          ch{nullptr, nullptr},
          color(BLACK),
          level(0),
          cnt(1) {}
    Node(Node *l, Node *r, const T &k) : val(k), color(RED), ch{l, r} {}
  };
  struct nPool {
    vector<Node> pool;
    vector<Node *> stock;
    int ptr;
    nPool(int sz) : pool(sz), stock(sz) { clear(); }
    inline Node *alloc() { return stock[--ptr]; }
    inline void free(Node *t) { stock[ptr++] = t; }
    void clear() {
      ptr = (int)pool.size();
      for (int i = 0; i < pool.size(); i++) stock[i] = &pool[i];
    }
  };

 protected:
  inline Node *alloc(Node *l, Node *r) {
    auto t = &(*pool.alloc() = Node(l, r, M::ti()));
    return pushup(t);
  }
  virtual Node *clone(Node *t) { return t; }
  Node *rotate(Node *t, bool b) {
    t = clone(t);
    Node *s;
    s = clone(t->ch[!b]);
    t->ch[!b] = s->ch[b];
    s->ch[b] = t;
    pushup(t);
    return pushup(s);
  }
  Node *submerge(Node *l, Node *r) {
    if (l->level == r->level) return alloc(l, r);
    bool b = l->level < r->level;
    if (!b) swap(l, r);
    r = clone(r);
    Node *c = (r->ch[!b] = b ? submerge(l, r->ch[0]) : submerge(r->ch[1], l));
    if (r->color == BLACK && c->color == RED && c->ch[!b]
        && c->ch[!b]->color == RED) {
      r->color = RED;
      c->color = BLACK;
      if (r->ch[b]->color == BLACK) return rotate(r, b);
      r->ch[b]->color = BLACK;
    }
    return pushup(r);
  }
  Node *build(int l, int r, const vector<T> &v) {
    if (l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
  Node *pushup(Node *t) {
    t->cnt = count(t->ch[0]) + count(t->ch[1]) + !t->ch[0];
    t->level = t->ch[0] ? t->ch[0]->level + (t->ch[0]->color == BLACK) : 0;
    t->dat = M::f(M::f(dat(t->ch[0]), t->val), dat(t->ch[1]));
    return t;
  }
  void dump(Node *r, typename vector<T>::iterator &it) {
    if (r->ch[0] == nullptr) {
      *it++ = r->val;
      return;
    }
    dump(r->ch[0], it);
    dump(r->ch[1], it);
  }
  inline Node *alloc(const T &val) { return &(*pool.alloc() = Node(val)); }
  inline int count(const Node *t) { return t ? t->cnt : 0; }
  inline const T dat(const Node *t) { return t ? t->dat : M::ti(); }
  pair<Node *, Node *> split(Node *t, int k) {
    if (!t) return {nullptr, nullptr};
    if (k == 0) return {nullptr, t};
    if (k >= count(t)) return {t, nullptr};
    t = clone(t);
    Node *l = t->ch[0], *r = t->ch[1];
    pool.free(t);
    if (k < count(l)) {
      auto pp = split(l, k);
      return {pp.first, merge(pp.second, r)};
    }
    if (k > count(l)) {
      auto pp = split(r, k - count(l));
      return {merge(l, pp.first), pp.second};
    }
    return {l, r};
  }
  Node *merge(Node *l, Node *r) {
    if (!l || !r) return l ? l : r;
    Node *c = submerge(l, r);
    c->color = BLACK;
    return c;
  }
  void set_val(Node *&t, int k, const T &x) {
    t = clone(t);
    if (!t->ch[0]) {
      t->val = t->dat = x;
      return;
    }
    if (k < count(t->ch[0]))
      set_val(t->ch[0], k, x);
    else
      set_val(t->ch[1], k - count(t->ch[0]), x);
    t = pushup(t);
  }
  T get(Node *&t, int k) {
    if (!t->ch[0]) return t->val;
    return k < count(t->ch[0]) ? get(t->ch[0], k)
                               : get(t->ch[1], k - count(t->ch[0]));
  }
  RedBlackTree(Node *t) : root(t) {}

 protected:
  static nPool pool;
  Node *root;

 public:
  RedBlackTree() : root(nullptr) {}
  RedBlackTree(int n, T val = M::ti()) : RedBlackTree(vector<T>(n, val)) {}
  RedBlackTree(const vector<T> &v) { root = build(0, (int)v.size(), v); }
  void build(const vector<T> &v) { root = build(0, (int)v.size(), v); }
  void push_front(const T &v) { root = merge(alloc(v), root); }
  void push_back(const T &v) { root = merge(root, alloc(v)); }
  T pop_front() {
    auto ret = split(root, 1);
    root = ret.second;
    return ret.first->val;
  }
  T pop_back() {
    auto ret = split(root, count(root) - 1);
    root = ret.first;
    return ret.second->val;
  }
  // merge
  RedBlackTree operator+(const RedBlackTree &r) {
    if (!this->root || !r.root) return this->root ? *this : r;
    Node *c = submerge(this->root, r.root);
    c->color = BLACK;
    return RedBlackTree(c);
  }
  // [0,k) [k,size)
  pair<RedBlackTree, RedBlackTree> split(int k) {
    auto tmp = split(root, k);
    return make_pair(RedBlackTree(tmp.first), RedBlackTree(tmp.first));
  }
  // [0,a) [a,b) [b,size)
  tuple<RedBlackTree, RedBlackTree, RedBlackTree> split3(int a, int b) {
    auto x = split(root, a);
    auto y = split(x.second, b - a);
    return make_tuple(RedBlackTree(x.first), RedBlackTree(y.first),
                      RedBlackTree(y.second));
  }
  void insert(int k, const T &v) {
    auto x = split(root, k);
    root = merge(merge(x.first, alloc(v)), x.second);
  }
  T erase(int k) {
    auto x = split(root, k);
    auto y = split(x.second, 1);
    T v = y.first->val;
    pool.free(y.first);
    root = merge(x.first, y.second);
    return v;
  }
  //[a,b)
  T query(int a, int b) {
    auto x = split(root, a);
    auto y = split(x.second, b - a);
    T ret = dat(y.first);
    root = merge(x.first, merge(y.first, y.second));
    return ret;
  }
  T operator[](int k) { return get(root, k); }
  void set_val(int k, const T &x) { set_val(root, k, x); }
  vector<T> dump() {
    vector<T> v((size_t)count(root));
    auto it = begin(v);
    dump(root, it);
    return v;
  }
  int size() { return count(root); }
};
template <typename M, size_t LIM>
typename RedBlackTree<M, LIM>::nPool RedBlackTree<M, LIM>::pool(LIM);

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/RedBlackTree.hpp"
/**
 * @title 赤黒木
 * @category データ構造
 * @brief O(logN)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename M, size_t LIM = 1 << 20>
struct RedBlackTree {
  using T = typename M::T;

 public:
  enum COLOR { BLACK, RED };
  struct Node {
    Node *ch[2];
    COLOR color;
    int level, cnt;
    T val, dat;
    Node() {}
    Node(const T &k)
        : val(k),
          dat(k),
          ch{nullptr, nullptr},
          color(BLACK),
          level(0),
          cnt(1) {}
    Node(Node *l, Node *r, const T &k) : val(k), color(RED), ch{l, r} {}
  };
  struct nPool {
    vector<Node> pool;
    vector<Node *> stock;
    int ptr;
    nPool(int sz) : pool(sz), stock(sz) { clear(); }
    inline Node *alloc() { return stock[--ptr]; }
    inline void free(Node *t) { stock[ptr++] = t; }
    void clear() {
      ptr = (int)pool.size();
      for (int i = 0; i < pool.size(); i++) stock[i] = &pool[i];
    }
  };

 protected:
  inline Node *alloc(Node *l, Node *r) {
    auto t = &(*pool.alloc() = Node(l, r, M::ti()));
    return pushup(t);
  }
  virtual Node *clone(Node *t) { return t; }
  Node *rotate(Node *t, bool b) {
    t = clone(t);
    Node *s;
    s = clone(t->ch[!b]);
    t->ch[!b] = s->ch[b];
    s->ch[b] = t;
    pushup(t);
    return pushup(s);
  }
  Node *submerge(Node *l, Node *r) {
    if (l->level == r->level) return alloc(l, r);
    bool b = l->level < r->level;
    if (!b) swap(l, r);
    r = clone(r);
    Node *c = (r->ch[!b] = b ? submerge(l, r->ch[0]) : submerge(r->ch[1], l));
    if (r->color == BLACK && c->color == RED && c->ch[!b]
        && c->ch[!b]->color == RED) {
      r->color = RED;
      c->color = BLACK;
      if (r->ch[b]->color == BLACK) return rotate(r, b);
      r->ch[b]->color = BLACK;
    }
    return pushup(r);
  }
  Node *build(int l, int r, const vector<T> &v) {
    if (l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
  Node *pushup(Node *t) {
    t->cnt = count(t->ch[0]) + count(t->ch[1]) + !t->ch[0];
    t->level = t->ch[0] ? t->ch[0]->level + (t->ch[0]->color == BLACK) : 0;
    t->dat = M::f(M::f(dat(t->ch[0]), t->val), dat(t->ch[1]));
    return t;
  }
  void dump(Node *r, typename vector<T>::iterator &it) {
    if (r->ch[0] == nullptr) {
      *it++ = r->val;
      return;
    }
    dump(r->ch[0], it);
    dump(r->ch[1], it);
  }
  inline Node *alloc(const T &val) { return &(*pool.alloc() = Node(val)); }
  inline int count(const Node *t) { return t ? t->cnt : 0; }
  inline const T dat(const Node *t) { return t ? t->dat : M::ti(); }
  pair<Node *, Node *> split(Node *t, int k) {
    if (!t) return {nullptr, nullptr};
    if (k == 0) return {nullptr, t};
    if (k >= count(t)) return {t, nullptr};
    t = clone(t);
    Node *l = t->ch[0], *r = t->ch[1];
    pool.free(t);
    if (k < count(l)) {
      auto pp = split(l, k);
      return {pp.first, merge(pp.second, r)};
    }
    if (k > count(l)) {
      auto pp = split(r, k - count(l));
      return {merge(l, pp.first), pp.second};
    }
    return {l, r};
  }
  Node *merge(Node *l, Node *r) {
    if (!l || !r) return l ? l : r;
    Node *c = submerge(l, r);
    c->color = BLACK;
    return c;
  }
  void set_val(Node *&t, int k, const T &x) {
    t = clone(t);
    if (!t->ch[0]) {
      t->val = t->dat = x;
      return;
    }
    if (k < count(t->ch[0]))
      set_val(t->ch[0], k, x);
    else
      set_val(t->ch[1], k - count(t->ch[0]), x);
    t = pushup(t);
  }
  T get(Node *&t, int k) {
    if (!t->ch[0]) return t->val;
    return k < count(t->ch[0]) ? get(t->ch[0], k)
                               : get(t->ch[1], k - count(t->ch[0]));
  }
  RedBlackTree(Node *t) : root(t) {}

 protected:
  static nPool pool;
  Node *root;

 public:
  RedBlackTree() : root(nullptr) {}
  RedBlackTree(int n, T val = M::ti()) : RedBlackTree(vector<T>(n, val)) {}
  RedBlackTree(const vector<T> &v) { root = build(0, (int)v.size(), v); }
  void build(const vector<T> &v) { root = build(0, (int)v.size(), v); }
  void push_front(const T &v) { root = merge(alloc(v), root); }
  void push_back(const T &v) { root = merge(root, alloc(v)); }
  T pop_front() {
    auto ret = split(root, 1);
    root = ret.second;
    return ret.first->val;
  }
  T pop_back() {
    auto ret = split(root, count(root) - 1);
    root = ret.first;
    return ret.second->val;
  }
  // merge
  RedBlackTree operator+(const RedBlackTree &r) {
    if (!this->root || !r.root) return this->root ? *this : r;
    Node *c = submerge(this->root, r.root);
    c->color = BLACK;
    return RedBlackTree(c);
  }
  // [0,k) [k,size)
  pair<RedBlackTree, RedBlackTree> split(int k) {
    auto tmp = split(root, k);
    return make_pair(RedBlackTree(tmp.first), RedBlackTree(tmp.first));
  }
  // [0,a) [a,b) [b,size)
  tuple<RedBlackTree, RedBlackTree, RedBlackTree> split3(int a, int b) {
    auto x = split(root, a);
    auto y = split(x.second, b - a);
    return make_tuple(RedBlackTree(x.first), RedBlackTree(y.first),
                      RedBlackTree(y.second));
  }
  void insert(int k, const T &v) {
    auto x = split(root, k);
    root = merge(merge(x.first, alloc(v)), x.second);
  }
  T erase(int k) {
    auto x = split(root, k);
    auto y = split(x.second, 1);
    T v = y.first->val;
    pool.free(y.first);
    root = merge(x.first, y.second);
    return v;
  }
  //[a,b)
  T query(int a, int b) {
    auto x = split(root, a);
    auto y = split(x.second, b - a);
    T ret = dat(y.first);
    root = merge(x.first, merge(y.first, y.second));
    return ret;
  }
  T operator[](int k) { return get(root, k); }
  void set_val(int k, const T &x) { set_val(root, k, x); }
  vector<T> dump() {
    vector<T> v((size_t)count(root));
    auto it = begin(v);
    dump(root, it);
    return v;
  }
  int size() { return count(root); }
};
template <typename M, size_t LIM>
typename RedBlackTree<M, LIM>::nPool RedBlackTree<M, LIM>::pool(LIM);

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

