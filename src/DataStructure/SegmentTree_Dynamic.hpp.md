---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/BinaryTrie.hpp
    title: "\u4E8C\u5206Trie"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.BinaryTrie.test.cpp
    title: test/yukicoder/649.BinaryTrie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.SegTree_Dynamic.test.cpp
    title: test/yukicoder/649.SegTree_Dynamic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment-Tree(\u52D5\u7684)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Segment-Tree(\u52D5\u7684)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M, std::size_t\
    \ LIM = 1 << 23>\nstruct SegmentTree_Dynamic {\n  using T = typename M::T;\n \
    \ using ll = long long;\n  using U = unsigned long long;\n  struct Node {\n  \
    \  T dat;\n    U xor_lazy;\n    Node *ch[2];\n    Node() : dat(M::ti()), xor_lazy(0),\
    \ ch{nullptr, nullptr} {}\n    void *operator new(std::size_t) {\n      static\
    \ std::vector<Node> pool(LIM);\n      return &pool[node_count++];\n    }\n  };\n\
    \n protected:\n  int height;\n  ll n;\n  static int node_count;\n  Node *root;\n\
    \n private:\n  inline void push(Node *t, ll b) {\n    if ((t->xor_lazy >> (U)b)\
    \ & (U)1) std::swap(t->ch[0], t->ch[1]);\n    if (t->ch[0] != nullptr) t->ch[0]->xor_lazy\
    \ ^= t->xor_lazy;\n    if (t->ch[1] != nullptr) t->ch[1]->xor_lazy ^= t->xor_lazy;\n\
    \    t->xor_lazy = 0;\n  }\n  T value(Node *t) { return t ? t->dat : M::ti();\
    \ }\n  Node *set_Node(Node *t, const U &pos, const T &val, ll b) {\n    if (t\
    \ == nullptr) t = new Node();\n    if (b < 0) {\n      t->dat = val;\n      return\
    \ t;\n    }\n    push(t, b);\n    bool f = (pos >> (U)b) & (U)1;\n    t->ch[f]\
    \ = set_Node(t->ch[f], pos, val, b - 1);\n    t->dat = M::f(value(t->ch[0]), value(t->ch[1]));\n\
    \    return t;\n  }\n  T query_Node(const ll &l, const ll &r, Node *t, const ll\
    \ &lb, const ll &ub,\n               ll b) {\n    if (t == nullptr || ub <= l\
    \ || r <= lb) return M::ti();\n    push(t, b);\n    if (l <= lb && ub <= r) return\
    \ t->dat;\n    ll c = (lb + ub) / 2;\n    T vl = query_Node(l, r, t->ch[0], lb,\
    \ c, b - 1);\n    T vr = query_Node(l, r, t->ch[1], c, ub, b - 1);\n    return\
    \ M::f(vl, vr);\n  }\n  template <typename C>\n  ll find(Node *t, C &check, U\
    \ bias) {\n    if (!t) return -1;\n    ll ret = 0;\n    T acc = M::ti();\n   \
    \ for (ll b = height - 1; b >= 0; b--) {\n      push(t, b);\n      bool f = (bias\
    \ >> (U)b) & (U)1;\n      if (!check(M::f(acc, value(t->ch[f]))))\n        acc\
    \ = M::f(acc, value(t->ch[f])), f = !f;\n      t = t->ch[f];\n      if (!t) return\
    \ -1;\n      ret |= (U)f << (U)b;\n    }\n    return ret;\n  }\n\n public:\n \
    \ SegmentTree_Dynamic() {}\n  SegmentTree_Dynamic(ll n_)\n      : height(ceil(log2(n_))),\
    \ n(1LL << height), root(nullptr) {}\n  void clear() {\n    node_count = 0;\n\
    \    root = nullptr;\n  }\n  void xor_all(U key) {\n    if (root != nullptr) root->xor_lazy\
    \ ^= key;\n  }\n  void set_val(ll k, T x) { root = set_Node(root, k, x, height\
    \ - 1); }\n  //[l,r)\n  T query(ll l, ll r) { return query_Node(l, r, root, 0,\
    \ n, height - 1); }\n  T operator[](ll k) { return query(k, k + 1); }\n  // min\
    \ { i : check(query(0,i+1)) = true }\n  template <typename C>\n  ll find_first(C\
    \ &check, U bias = 0) {\n    return find(root, check, bias);\n  }\n};\ntemplate\
    \ <typename M, std::size_t LIM>\nint SegmentTree_Dynamic<M, LIM>::node_count =\
    \ 0;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Segment-Tree(\u52D5\
    \u7684)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename M, std::size_t LIM = 1 << 23>\nstruct SegmentTree_Dynamic\
    \ {\n  using T = typename M::T;\n  using ll = long long;\n  using U = unsigned\
    \ long long;\n  struct Node {\n    T dat;\n    U xor_lazy;\n    Node *ch[2];\n\
    \    Node() : dat(M::ti()), xor_lazy(0), ch{nullptr, nullptr} {}\n    void *operator\
    \ new(std::size_t) {\n      static std::vector<Node> pool(LIM);\n      return\
    \ &pool[node_count++];\n    }\n  };\n\n protected:\n  int height;\n  ll n;\n \
    \ static int node_count;\n  Node *root;\n\n private:\n  inline void push(Node\
    \ *t, ll b) {\n    if ((t->xor_lazy >> (U)b) & (U)1) std::swap(t->ch[0], t->ch[1]);\n\
    \    if (t->ch[0] != nullptr) t->ch[0]->xor_lazy ^= t->xor_lazy;\n    if (t->ch[1]\
    \ != nullptr) t->ch[1]->xor_lazy ^= t->xor_lazy;\n    t->xor_lazy = 0;\n  }\n\
    \  T value(Node *t) { return t ? t->dat : M::ti(); }\n  Node *set_Node(Node *t,\
    \ const U &pos, const T &val, ll b) {\n    if (t == nullptr) t = new Node();\n\
    \    if (b < 0) {\n      t->dat = val;\n      return t;\n    }\n    push(t, b);\n\
    \    bool f = (pos >> (U)b) & (U)1;\n    t->ch[f] = set_Node(t->ch[f], pos, val,\
    \ b - 1);\n    t->dat = M::f(value(t->ch[0]), value(t->ch[1]));\n    return t;\n\
    \  }\n  T query_Node(const ll &l, const ll &r, Node *t, const ll &lb, const ll\
    \ &ub,\n               ll b) {\n    if (t == nullptr || ub <= l || r <= lb) return\
    \ M::ti();\n    push(t, b);\n    if (l <= lb && ub <= r) return t->dat;\n    ll\
    \ c = (lb + ub) / 2;\n    T vl = query_Node(l, r, t->ch[0], lb, c, b - 1);\n \
    \   T vr = query_Node(l, r, t->ch[1], c, ub, b - 1);\n    return M::f(vl, vr);\n\
    \  }\n  template <typename C>\n  ll find(Node *t, C &check, U bias) {\n    if\
    \ (!t) return -1;\n    ll ret = 0;\n    T acc = M::ti();\n    for (ll b = height\
    \ - 1; b >= 0; b--) {\n      push(t, b);\n      bool f = (bias >> (U)b) & (U)1;\n\
    \      if (!check(M::f(acc, value(t->ch[f]))))\n        acc = M::f(acc, value(t->ch[f])),\
    \ f = !f;\n      t = t->ch[f];\n      if (!t) return -1;\n      ret |= (U)f <<\
    \ (U)b;\n    }\n    return ret;\n  }\n\n public:\n  SegmentTree_Dynamic() {}\n\
    \  SegmentTree_Dynamic(ll n_)\n      : height(ceil(log2(n_))), n(1LL << height),\
    \ root(nullptr) {}\n  void clear() {\n    node_count = 0;\n    root = nullptr;\n\
    \  }\n  void xor_all(U key) {\n    if (root != nullptr) root->xor_lazy ^= key;\n\
    \  }\n  void set_val(ll k, T x) { root = set_Node(root, k, x, height - 1); }\n\
    \  //[l,r)\n  T query(ll l, ll r) { return query_Node(l, r, root, 0, n, height\
    \ - 1); }\n  T operator[](ll k) { return query(k, k + 1); }\n  // min { i : check(query(0,i+1))\
    \ = true }\n  template <typename C>\n  ll find_first(C &check, U bias = 0) {\n\
    \    return find(root, check, bias);\n  }\n};\ntemplate <typename M, std::size_t\
    \ LIM>\nint SegmentTree_Dynamic<M, LIM>::node_count = 0;"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree_Dynamic.hpp
  requiredBy:
  - src/DataStructure/BinaryTrie.hpp
  timestamp: '2020-11-07 14:59:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
  - test/yukicoder/649.SegTree_Dynamic.test.cpp
  - test/yukicoder/649.BinaryTrie.test.cpp
documentation_of: src/DataStructure/SegmentTree_Dynamic.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree_Dynamic.hpp
- /library/src/DataStructure/SegmentTree_Dynamic.hpp.html
title: "Segment-Tree(\u52D5\u7684)"
---
