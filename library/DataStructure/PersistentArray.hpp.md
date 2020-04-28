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


# :heavy_check_mark: 永続配列

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PersistentArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 22:54:22+09:00




## Required by

* :heavy_check_mark: <a href="UnionFind_Persistent.hpp.html">Union-Find(完全永続)</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/persistent_unionfind.test.cpp.html">test/yosupo/persistent_unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 永続配列
 * @category データ構造
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, int LOG = 3>
struct PersistentArray {
  struct Node {
    T data;
    Node *child[1 << LOG] = {};
    Node() {}
    Node(const T &data) : data(data) {}
  };

 private:
  Node *root;

 public:
  PersistentArray() : root(nullptr) {}
  PersistentArray(size_t n, const T &val = T()) { build(vector<T>(n, val)); }
  PersistentArray(const vector<T> &v) { build(v); }
  const T get(const int &k) const { return get(root, k); }
  T &operator[](const int &k) { return reference_get(k, false); }
  void build(const vector<T> &v) {
    root = nullptr;
    for (int i = 0; i < v.size(); i++) reference_get(i, true) = v[i];
  }

 private:
  T get(Node *t, int k) const {
    if (!t) return T();
    if (k == 0) return t->data;
    return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
  }
  pair<Node *, T &> reference_get(Node *t, int k, bool destruct = false) {
    t = t ? (destruct ? t : new Node(*t)) : new Node();
    if (k == 0) return {t, t->data};
    auto p = reference_get(t->child[k & ((1 << LOG) - 1)], k >> LOG, destruct);
    t->child[k & ((1 << LOG) - 1)] = p.first;
    return {t, p.second};
  }
  T &reference_get(const int &k, bool destruct = false) {
    auto ret = reference_get(root, k, destruct);
    root = ret.first;
    return ret.second;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PersistentArray.hpp"
/**
 * @title 永続配列
 * @category データ構造
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, int LOG = 3>
struct PersistentArray {
  struct Node {
    T data;
    Node *child[1 << LOG] = {};
    Node() {}
    Node(const T &data) : data(data) {}
  };

 private:
  Node *root;

 public:
  PersistentArray() : root(nullptr) {}
  PersistentArray(size_t n, const T &val = T()) { build(vector<T>(n, val)); }
  PersistentArray(const vector<T> &v) { build(v); }
  const T get(const int &k) const { return get(root, k); }
  T &operator[](const int &k) { return reference_get(k, false); }
  void build(const vector<T> &v) {
    root = nullptr;
    for (int i = 0; i < v.size(); i++) reference_get(i, true) = v[i];
  }

 private:
  T get(Node *t, int k) const {
    if (!t) return T();
    if (k == 0) return t->data;
    return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
  }
  pair<Node *, T &> reference_get(Node *t, int k, bool destruct = false) {
    t = t ? (destruct ? t : new Node(*t)) : new Node();
    if (k == 0) return {t, t->data};
    auto p = reference_get(t->child[k & ((1 << LOG) - 1)], k >> LOG, destruct);
    t->child[k & ((1 << LOG) - 1)] = p.first;
    return {t, p.second};
  }
  T &reference_get(const int &k, bool destruct = false) {
    auto ret = reference_get(root, k, destruct);
    root = ret.first;
    return ret.second;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

