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


# :heavy_check_mark: Li-Chao-Tree

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/LiChaoTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-20 14:20:17+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/segment_add_get_min.test.cpp.html">test/yosupo/segment_add_get_min.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Li-Chao-Tree
 * @category データ構造
 * @brief 直線挿入:O(n log n)
 * @brief 線分挿入:O(n log^2 n)
 * @brief 最小値取得:O(n log n)
 * @brief 最大値取得したいなら(-a,-b)を挿入して-最小値を取得
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, T x_low = -(1 << 30), T x_high = (1 << 30),
          size_t LIM = (1 << 23)>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T get(T x) const { return a * x + b; }
  };
  struct Node {
    Line x;
    Node *ch[2];
    Node() : x(0, INF) {}
    Node(const Line &x) : x(x), ch{nullptr, nullptr} {}
    void *operator new(size_t) {
      static vector<Node> pool(LIM);
      return &pool[node_count++];
    }
  };

 private:
  static constexpr T INF = numeric_limits<T>::max() / 2;
  static int node_count;
  Node *root;

 private:
  Node *insert_line(Node *t, Line &x, const T &l, const T &r, const T &x_l,
                    const T &x_r) {
    if (!t) return new Node(x);
    T t_l = t->x.get(l), t_r = t->x.get(r);
    if (t_l <= x_l && t_r <= x_r) {
      return t;
    } else if (t_l >= x_l && t_r >= x_r) {
      t->x = x;
      return t;
    } else {
      T m = (l + r) / 2;
      if (m == r) --m;
      T t_m = t->x.get(m), x_m = x.get(m);
      if (t_m > x_m) {
        swap(t->x, x);
        if (x_l >= t_l)
          t->ch[0] = insert_line(t->ch[0], x, l, m, t_l, t_m);
        else
          t->ch[1] = insert_line(t->ch[1], x, m + 1, r, t_m + x.a, t_r);
      } else {
        if (t_l >= x_l)
          t->ch[0] = insert_line(t->ch[0], x, l, m, x_l, x_m);
        else
          t->ch[1] = insert_line(t->ch[1], x, m + 1, r, x_m + x.a, x_r);
      }
      return t;
    }
  }
  Node *insert_segment(Node *t, Line &x, const T &a, const T &b, const T &l,
                       const T &r, const T &x_l, const T &x_r) {
    if (r < a || b < l) return t;
    if (a <= l && r <= b) {
      Line y{x};
      return insert_line(t, y, l, r, x_l, x_r);
    }
    if (t) {
      T t_l = t->x.get(l), t_r = t->x.get(r);
      if (t_l <= x_l && t_r <= x_r) return t;
    } else {
      t = new Node(Line(0, INF));
    }
    T m = (l + r) / 2;
    if (m == r) --m;
    T x_m = x.get(m);
    t->ch[0] = insert_segment(t->ch[0], x, a, b, l, m, x_l, x_m);
    t->ch[1] = insert_segment(t->ch[1], x, a, b, m + 1, r, x_m + x.a, x_r);
    return t;
  }
  T query(const Node *t, const T &l, const T &r, const T &x) const {
    if (!t) return INF;
    if (l == r) return t->x.get(x);
    T m = (l + r) / 2;
    if (m == r) --m;
    if (x <= m)
      return min(t->x.get(x), query(t->ch[0], l, m, x));
    else
      return min(t->x.get(x), query(t->ch[1], m + 1, r, x));
  }

 public:
  LiChaoTree() : root{nullptr} {}
  T get_inf() { return INF; }
  void clear() {
    node_count = 0;
    root = nullptr;
  }
  void insert_line(T a, T b) {
    Line x(a, b);
    root = insert_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
  }
  // [l,r)
  void insert_segment(T l, T r, T a, T b) {
    Line x(a, b);
    root = insert_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low),
                          x.get(x_high));
  }
  T query(T x) const { return query(root, x_low, x_high, x); }
};
template <typename T, T x_low, T x_high, size_t LIM>
int LiChaoTree<T, x_low, x_high, LIM>::node_count = 0;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/LiChaoTree.hpp"
/**
 * @title Li-Chao-Tree
 * @category データ構造
 * @brief 直線挿入:O(n log n)
 * @brief 線分挿入:O(n log^2 n)
 * @brief 最小値取得:O(n log n)
 * @brief 最大値取得したいなら(-a,-b)を挿入して-最小値を取得
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, T x_low = -(1 << 30), T x_high = (1 << 30),
          size_t LIM = (1 << 23)>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T get(T x) const { return a * x + b; }
  };
  struct Node {
    Line x;
    Node *ch[2];
    Node() : x(0, INF) {}
    Node(const Line &x) : x(x), ch{nullptr, nullptr} {}
    void *operator new(size_t) {
      static vector<Node> pool(LIM);
      return &pool[node_count++];
    }
  };

 private:
  static constexpr T INF = numeric_limits<T>::max() / 2;
  static int node_count;
  Node *root;

 private:
  Node *insert_line(Node *t, Line &x, const T &l, const T &r, const T &x_l,
                    const T &x_r) {
    if (!t) return new Node(x);
    T t_l = t->x.get(l), t_r = t->x.get(r);
    if (t_l <= x_l && t_r <= x_r) {
      return t;
    } else if (t_l >= x_l && t_r >= x_r) {
      t->x = x;
      return t;
    } else {
      T m = (l + r) / 2;
      if (m == r) --m;
      T t_m = t->x.get(m), x_m = x.get(m);
      if (t_m > x_m) {
        swap(t->x, x);
        if (x_l >= t_l)
          t->ch[0] = insert_line(t->ch[0], x, l, m, t_l, t_m);
        else
          t->ch[1] = insert_line(t->ch[1], x, m + 1, r, t_m + x.a, t_r);
      } else {
        if (t_l >= x_l)
          t->ch[0] = insert_line(t->ch[0], x, l, m, x_l, x_m);
        else
          t->ch[1] = insert_line(t->ch[1], x, m + 1, r, x_m + x.a, x_r);
      }
      return t;
    }
  }
  Node *insert_segment(Node *t, Line &x, const T &a, const T &b, const T &l,
                       const T &r, const T &x_l, const T &x_r) {
    if (r < a || b < l) return t;
    if (a <= l && r <= b) {
      Line y{x};
      return insert_line(t, y, l, r, x_l, x_r);
    }
    if (t) {
      T t_l = t->x.get(l), t_r = t->x.get(r);
      if (t_l <= x_l && t_r <= x_r) return t;
    } else {
      t = new Node(Line(0, INF));
    }
    T m = (l + r) / 2;
    if (m == r) --m;
    T x_m = x.get(m);
    t->ch[0] = insert_segment(t->ch[0], x, a, b, l, m, x_l, x_m);
    t->ch[1] = insert_segment(t->ch[1], x, a, b, m + 1, r, x_m + x.a, x_r);
    return t;
  }
  T query(const Node *t, const T &l, const T &r, const T &x) const {
    if (!t) return INF;
    if (l == r) return t->x.get(x);
    T m = (l + r) / 2;
    if (m == r) --m;
    if (x <= m)
      return min(t->x.get(x), query(t->ch[0], l, m, x));
    else
      return min(t->x.get(x), query(t->ch[1], m + 1, r, x));
  }

 public:
  LiChaoTree() : root{nullptr} {}
  T get_inf() { return INF; }
  void clear() {
    node_count = 0;
    root = nullptr;
  }
  void insert_line(T a, T b) {
    Line x(a, b);
    root = insert_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
  }
  // [l,r)
  void insert_segment(T l, T r, T a, T b) {
    Line x(a, b);
    root = insert_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low),
                          x.get(x_high));
  }
  T query(T x) const { return query(root, x_low, x_high, x); }
};
template <typename T, T x_low, T x_high, size_t LIM>
int LiChaoTree<T, x_low, x_high, LIM>::node_count = 0;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

