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


# :heavy_check_mark: Skew-Heap

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/SkewHeap.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00




## Required by

* :heavy_check_mark: <a href="../Graph/MinimumSpanningAborescense.hpp.html">最小全域有向木</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2647.test.cpp.html">test/aoj/2647.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_9_C.SkewHeap.test.cpp.html">test/aoj/ALDS1_9_C.SkewHeap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/directedmst.test.cpp.html">test/yosupo/directedmst.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Skew-Heap
 * @category データ構造
 * @brief マージできるヒープ
 * @brief top: O(1), pop, push, merge: O(logN)
 * @brief add(v): 全体に作用素vを適用
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T>
struct Op_RaddQ {
  using E = T;
  static E ei() { return 0; }
  static T g(const T &l, const E &r) { return l + r; }
  static E h(const E &l, const E &r) { return l + r; }
};

template <typename T, typename Compare = less<T>, typename Op = Op_RaddQ<T>>
struct SkewHeap {
  using E = typename Op::E;
  struct Node {
    Node *ch[2];
    T key;
    E lazy;
    Node() {}
    Node(T k, E laz) : ch{nullptr, nullptr}, key(k), lazy(laz) {}
  } * root;

 private:
  void propagate(Node *a) {
    if (a->lazy != Op::ei()) {
      a->key = Op::g(a->key, a->lazy);
      if (a->ch[0]) a->ch[0]->lazy = Op::h(a->ch[0]->lazy, a->lazy);
      if (a->ch[1]) a->ch[1]->lazy = Op::h(a->ch[1]->lazy, a->lazy);
      a->lazy = Op::ei();
    }
  }
  Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    propagate(a);
    propagate(b);
    if (Compare()(a->key, b->key)) swap(a, b);
    a->ch[1] = merge(b, a->ch[1]);
    swap(a->ch[0], a->ch[1]);
    return a;
  }

 public:
  /* max heap */
  SkewHeap() : root(nullptr) {}
  void push(T key) {
    Node *n = new Node(key, Op::ei());
    root = merge(root, n);
  }
  T pop() {
    propagate(root);
    T ret = root->key;
    Node *temp = root;
    root = merge(root->ch[0], root->ch[1]);
    delete temp;
    return ret;
  }
  T top() {
    propagate(root);
    return root->key;
  }
  bool empty() { return !root; }
  void add(E v) { root->lazy = Op::h(root->lazy, v); }
  void merge(SkewHeap x) { root = merge(root, x.root); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/SkewHeap.hpp"
/**
 * @title Skew-Heap
 * @category データ構造
 * @brief マージできるヒープ
 * @brief top: O(1), pop, push, merge: O(logN)
 * @brief add(v): 全体に作用素vを適用
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T>
struct Op_RaddQ {
  using E = T;
  static E ei() { return 0; }
  static T g(const T &l, const E &r) { return l + r; }
  static E h(const E &l, const E &r) { return l + r; }
};

template <typename T, typename Compare = less<T>, typename Op = Op_RaddQ<T>>
struct SkewHeap {
  using E = typename Op::E;
  struct Node {
    Node *ch[2];
    T key;
    E lazy;
    Node() {}
    Node(T k, E laz) : ch{nullptr, nullptr}, key(k), lazy(laz) {}
  } * root;

 private:
  void propagate(Node *a) {
    if (a->lazy != Op::ei()) {
      a->key = Op::g(a->key, a->lazy);
      if (a->ch[0]) a->ch[0]->lazy = Op::h(a->ch[0]->lazy, a->lazy);
      if (a->ch[1]) a->ch[1]->lazy = Op::h(a->ch[1]->lazy, a->lazy);
      a->lazy = Op::ei();
    }
  }
  Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    propagate(a);
    propagate(b);
    if (Compare()(a->key, b->key)) swap(a, b);
    a->ch[1] = merge(b, a->ch[1]);
    swap(a->ch[0], a->ch[1]);
    return a;
  }

 public:
  /* max heap */
  SkewHeap() : root(nullptr) {}
  void push(T key) {
    Node *n = new Node(key, Op::ei());
    root = merge(root, n);
  }
  T pop() {
    propagate(root);
    T ret = root->key;
    Node *temp = root;
    root = merge(root->ch[0], root->ch[1]);
    delete temp;
    return ret;
  }
  T top() {
    propagate(root);
    return root->key;
  }
  bool empty() { return !root; }
  void add(E v) { root->lazy = Op::h(root->lazy, v); }
  void merge(SkewHeap x) { root = merge(root, x.root); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

