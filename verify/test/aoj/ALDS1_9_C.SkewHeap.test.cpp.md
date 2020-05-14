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


# :heavy_check_mark: test/aoj/ALDS1_9_C.SkewHeap.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_9_C.SkewHeap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 17:58:05+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C</a>


## Depends on

* :question: <a href="../../../library/DataStructure/SkewHeap.hpp.html">Skew-Heap</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/SkewHeap.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  SkewHeap<int> S;
  string op;
  while (cin >> op && op != "end") {
    if (op[0] == 'i') {
      int k;
      cin >> k;
      S.push(k);
    } else {
      cout << S.pop() << endl;
    }
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_9_C.SkewHeap.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "DataStructure/SkewHeap.hpp"
/**
 * @title Skew-Heap
 * @category データ構造
 * @brief マージできるヒープ
 * @brief top: O(1), pop, push, merge: O(logN)
 * @brief add(v): 全体に作用素vを適用
 */

#ifndef call_from_test
#line 11 "DataStructure/SkewHeap.hpp"
using namespace std;
#endif

template <typename T, typename E = T>
struct SkewHeap {
  using C = function<bool(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  C comp;
  G g;
  H h;
  E ei;
  struct Node {
    Node *ch[2];
    T key;
    E lazy;
    Node() {}
    Node(T k, E laz) : ch{nullptr, nullptr}, key(k), lazy(laz) {}
  } * root;

 private:
  void propagate(Node *a) {
    if (a->lazy != ei) {
      a->key = g(a->key, a->lazy);
      if (a->ch[0]) a->ch[0]->lazy = h(a->ch[0]->lazy, a->lazy);
      if (a->ch[1]) a->ch[1]->lazy = h(a->ch[1]->lazy, a->lazy);
      a->lazy = ei;
    }
  }
  Node *merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    propagate(a);
    propagate(b);
    if (comp(a->key, b->key)) swap(a, b);
    a->ch[1] = merge(b, a->ch[1]);
    swap(a->ch[0], a->ch[1]);
    return a;
  }

 public:
  SkewHeap(
      C c = [](const T &a, const T &b) { return a < b; } /* max heap */,
      G g = [](const T &a, const E &b) { return a + b; },
      H h = [](const E &a, const E &b) { return a + b; }, E ei = 0)
      : comp(c), g(g), h(h), ei(ei), root(nullptr) {}
  void push(T key) {
    Node *n = new Node(key, ei);
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
  void add(E v) { root->lazy = h(root->lazy, v); }
  void merge(SkewHeap x) { root = merge(root, x.root); }
};
#line 9 "test/aoj/ALDS1_9_C.SkewHeap.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  SkewHeap<int> S;
  string op;
  while (cin >> op && op != "end") {
    if (op[0] == 'i') {
      int k;
      cin >> k;
      S.push(k);
    } else {
      cout << S.pop() << endl;
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

