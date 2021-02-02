---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/RedBlackTree.hpp
    title: "\u8D64\u9ED2\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.RBTP.test.cpp
    title: test/yosupo/persistent_queue.RBTP.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A)"
    links:
    - https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
  bundledCode: "#line 2 \"src/DataStructure/RedBlackTree_Persistent.hpp\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/DataStructure/RedBlackTree.hpp\"\n/**\n * @title\
    \ \u8D64\u9ED2\u6728\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename M, size_t LIM = 1 << 20>\nstruct\
    \ RedBlackTree {\n  using T = typename M::T;\n\n public:\n  enum COLOR { BLACK,\
    \ RED };\n  struct Node {\n    Node *ch[2];\n    COLOR color;\n    int level,\
    \ cnt;\n    T val, dat;\n    Node() {}\n    Node(const T &k)\n        : val(k),\n\
    \          dat(k),\n          ch{nullptr, nullptr},\n          color(BLACK),\n\
    \          level(0),\n          cnt(1) {}\n    Node(Node *l, Node *r, const T\
    \ &k) : val(k), color(RED), ch{l, r} {}\n  };\n  struct nPool {\n    std::vector<Node>\
    \ pool;\n    std::vector<Node *> stock;\n    int ptr;\n    nPool(int sz) : pool(sz),\
    \ stock(sz) { clear(); }\n    inline Node *alloc() { return stock[--ptr]; }\n\
    \    inline void free(Node *t) { stock[ptr++] = t; }\n    void clear() {\n   \
    \   ptr = (int)pool.size();\n      for (int i = 0; i < pool.size(); i++) stock[i]\
    \ = &pool[i];\n    }\n  };\n\n protected:\n  inline Node *alloc(Node *l, Node\
    \ *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M::ti()));\n    return pushup(t);\n\
    \  }\n  virtual Node *clone(Node *t) { return t; }\n  Node *rotate(Node *t, bool\
    \ b) {\n    t = clone(t);\n    Node *s;\n    s = clone(t->ch[!b]);\n    t->ch[!b]\
    \ = s->ch[b];\n    s->ch[b] = t;\n    pushup(t);\n    return pushup(s);\n  }\n\
    \  Node *submerge(Node *l, Node *r) {\n    if (l->level == r->level) return alloc(l,\
    \ r);\n    bool b = l->level < r->level;\n    if (!b) std::swap(l, r);\n    r\
    \ = clone(r);\n    Node *c = (r->ch[!b] = b ? submerge(l, r->ch[0]) : submerge(r->ch[1],\
    \ l));\n    if (r->color == BLACK && c->color == RED && c->ch[!b]\n        &&\
    \ c->ch[!b]->color == RED) {\n      r->color = RED;\n      c->color = BLACK;\n\
    \      if (r->ch[b]->color == BLACK) return rotate(r, b);\n      r->ch[b]->color\
    \ = BLACK;\n    }\n    return pushup(r);\n  }\n  Node *build(int l, int r, const\
    \ std::vector<T> &v) {\n    if (l + 1 >= r) return alloc(v[l]);\n    return merge(build(l,\
    \ (l + r) >> 1, v), build((l + r) >> 1, r, v));\n  }\n  Node *pushup(Node *t)\
    \ {\n    t->cnt = count(t->ch[0]) + count(t->ch[1]) + !t->ch[0];\n    t->level\
    \ = t->ch[0] ? t->ch[0]->level + (t->ch[0]->color == BLACK) : 0;\n    t->dat =\
    \ M::f(M::f(dat(t->ch[0]), t->val), dat(t->ch[1]));\n    return t;\n  }\n  void\
    \ dump(Node *r, typename std::vector<T>::iterator &it) {\n    if (r->ch[0] ==\
    \ nullptr) {\n      *it++ = r->val;\n      return;\n    }\n    dump(r->ch[0],\
    \ it);\n    dump(r->ch[1], it);\n  }\n  inline Node *alloc(const T &val) { return\
    \ &(*pool.alloc() = Node(val)); }\n  inline int count(const Node *t) { return\
    \ t ? t->cnt : 0; }\n  inline const T dat(const Node *t) { return t ? t->dat :\
    \ M::ti(); }\n  std::pair<Node *, Node *> split(Node *t, int k) {\n    if (!t)\
    \ return {nullptr, nullptr};\n    if (k == 0) return {nullptr, t};\n    if (k\
    \ >= count(t)) return {t, nullptr};\n    t = clone(t);\n    Node *l = t->ch[0],\
    \ *r = t->ch[1];\n    pool.free(t);\n    if (k < count(l)) {\n      auto pp =\
    \ split(l, k);\n      return {pp.first, merge(pp.second, r)};\n    }\n    if (k\
    \ > count(l)) {\n      auto pp = split(r, k - count(l));\n      return {merge(l,\
    \ pp.first), pp.second};\n    }\n    return {l, r};\n  }\n  Node *merge(Node *l,\
    \ Node *r) {\n    if (!l || !r) return l ? l : r;\n    Node *c = submerge(l, r);\n\
    \    c->color = BLACK;\n    return c;\n  }\n  void set_val(Node *&t, int k, const\
    \ T &x) {\n    t = clone(t);\n    if (!t->ch[0]) {\n      t->val = t->dat = x;\n\
    \      return;\n    }\n    if (k < count(t->ch[0]))\n      set_val(t->ch[0], k,\
    \ x);\n    else\n      set_val(t->ch[1], k - count(t->ch[0]), x);\n    t = pushup(t);\n\
    \  }\n  T get(Node *&t, int k) {\n    if (!t->ch[0]) return t->val;\n    return\
    \ k < count(t->ch[0]) ? get(t->ch[0], k)\n                               : get(t->ch[1],\
    \ k - count(t->ch[0]));\n  }\n  RedBlackTree(Node *t) : root(t) {}\n\n protected:\n\
    \  static nPool pool;\n  Node *root;\n\n public:\n  RedBlackTree() : root(nullptr)\
    \ {}\n  RedBlackTree(int n, T val = M::ti()) : RedBlackTree(std::vector<T>(n,\
    \ val)) {}\n  RedBlackTree(const std::vector<T> &v) { root = build(0, (int)v.size(),\
    \ v); }\n  void build(const std::vector<T> &v) { root = build(0, (int)v.size(),\
    \ v); }\n  void push_front(const T &v) { root = merge(alloc(v), root); }\n  void\
    \ push_back(const T &v) { root = merge(root, alloc(v)); }\n  T pop_front() {\n\
    \    auto ret = split(root, 1);\n    root = ret.second;\n    return ret.first->val;\n\
    \  }\n  T pop_back() {\n    auto ret = split(root, count(root) - 1);\n    root\
    \ = ret.first;\n    return ret.second->val;\n  }\n  // merge\n  RedBlackTree operator+(const\
    \ RedBlackTree &r) {\n    if (!this->root || !r.root) return this->root ? *this\
    \ : r;\n    Node *c = submerge(this->root, r.root);\n    c->color = BLACK;\n \
    \   return RedBlackTree(c);\n  }\n  // [0,k) [k,size)\n  std::pair<RedBlackTree,\
    \ RedBlackTree> split(int k) {\n    auto tmp = split(root, k);\n    return std::make_pair(RedBlackTree(tmp.first),\
    \ RedBlackTree(tmp.first));\n  }\n  // [0,a) [a,b) [b,size)\n  std::tuple<RedBlackTree,\
    \ RedBlackTree, RedBlackTree> split3(int a, int b) {\n    auto x = split(root,\
    \ a);\n    auto y = split(x.second, b - a);\n    return std::make_tuple(RedBlackTree(x.first),\
    \ RedBlackTree(y.first),\n                           RedBlackTree(y.second));\n\
    \  }\n  void insert(int k, const T &v) {\n    auto x = split(root, k);\n    root\
    \ = merge(merge(x.first, alloc(v)), x.second);\n  }\n  T erase(int k) {\n    auto\
    \ x = split(root, k);\n    auto y = split(x.second, 1);\n    T v = y.first->val;\n\
    \    pool.free(y.first);\n    root = merge(x.first, y.second);\n    return v;\n\
    \  }\n  //[a,b)\n  T query(int a, int b) {\n    auto x = split(root, a);\n   \
    \ auto y = split(x.second, b - a);\n    T ret = dat(y.first);\n    root = merge(x.first,\
    \ merge(y.first, y.second));\n    return ret;\n  }\n  T operator[](int k) { return\
    \ get(root, k); }\n  void set_val(int k, const T &x) { set_val(root, k, x); }\n\
    \  std::vector<T> dump() {\n    std::vector<T> v((size_t)count(root));\n    auto\
    \ it = begin(v);\n    dump(root, it);\n    return v;\n  }\n  int size() { return\
    \ count(root); }\n};\ntemplate <typename M, size_t LIM>\ntypename RedBlackTree<M,\
    \ LIM>::nPool RedBlackTree<M, LIM>::pool(LIM);\n#line 4 \"src/DataStructure/RedBlackTree_Persistent.hpp\"\
    \n/**\n * @title \u8D64\u9ED2\u6728(\u6C38\u7D9A)\n * @category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * O(logN)\n */\n// verify\u7528:\n// https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M, size_t LIM = 1 << 22, size_t FULL\
    \ = 1000>\nstruct RedBlackTree_Persistent : RedBlackTree<M, LIM> {\n  using RBT\
    \ = RedBlackTree<M, LIM>;\n  using RBT::RedBlackTree;\n  using Node = typename\
    \ RBT::Node;\n  using RBTP = RedBlackTree_Persistent;\n\n private:\n  Node *clone(Node\
    \ *t) override { return &(*RBT::pool.alloc() = *t); }\n\n public:\n  // merge\n\
    \  RBTP operator+(const RBTP &r) {\n    if (!this->root || !r.root) return this->root\
    \ ? *this : r;\n    Node *c = RBT::submerge(this->root, r.root);\n    c->color\
    \ = RBT::BLACK;\n    return RBTP(c);\n  }\n  // [0,k) [k,size)\n  std::pair<RBTP,\
    \ RBTP> split(int k) {\n    auto tmp = RBT::split(this->root, k);\n    return\
    \ std::make_pair(RBTP(tmp.first), RBTP(tmp.second));\n  }\n  // [0,a) [a,b) [b,size)\n\
    \  std::tuple<RBTP, RBTP, RBTP> split3(int a, int b) {\n    auto x = RBT::split(this->root,\
    \ a);\n    auto y = RBT::split(x.second, b - a);\n    return std::make_tuple(RBTP(x.first),\
    \ RBTP(y.first), RBTP(y.second));\n  }\n  void rebuild() {\n    auto ret = RBT::dump();\n\
    \    RBT::pool.clear();\n    RBT::build(ret);\n  }\n  static bool almost_full()\
    \ { return RBT::pool.ptr < FULL; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/DataStructure/RedBlackTree.hpp\"\
    \n/**\n * @title \u8D64\u9ED2\u6728(\u6C38\u7D9A)\n * @category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * O(logN)\n */\n// verify\u7528:\n// https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M, size_t LIM = 1 << 22, size_t FULL\
    \ = 1000>\nstruct RedBlackTree_Persistent : RedBlackTree<M, LIM> {\n  using RBT\
    \ = RedBlackTree<M, LIM>;\n  using RBT::RedBlackTree;\n  using Node = typename\
    \ RBT::Node;\n  using RBTP = RedBlackTree_Persistent;\n\n private:\n  Node *clone(Node\
    \ *t) override { return &(*RBT::pool.alloc() = *t); }\n\n public:\n  // merge\n\
    \  RBTP operator+(const RBTP &r) {\n    if (!this->root || !r.root) return this->root\
    \ ? *this : r;\n    Node *c = RBT::submerge(this->root, r.root);\n    c->color\
    \ = RBT::BLACK;\n    return RBTP(c);\n  }\n  // [0,k) [k,size)\n  std::pair<RBTP,\
    \ RBTP> split(int k) {\n    auto tmp = RBT::split(this->root, k);\n    return\
    \ std::make_pair(RBTP(tmp.first), RBTP(tmp.second));\n  }\n  // [0,a) [a,b) [b,size)\n\
    \  std::tuple<RBTP, RBTP, RBTP> split3(int a, int b) {\n    auto x = RBT::split(this->root,\
    \ a);\n    auto y = RBT::split(x.second, b - a);\n    return std::make_tuple(RBTP(x.first),\
    \ RBTP(y.first), RBTP(y.second));\n  }\n  void rebuild() {\n    auto ret = RBT::dump();\n\
    \    RBT::pool.clear();\n    RBT::build(ret);\n  }\n  static bool almost_full()\
    \ { return RBT::pool.ptr < FULL; }\n};\n"
  dependsOn:
  - src/DataStructure/RedBlackTree.hpp
  isVerificationFile: false
  path: src/DataStructure/RedBlackTree_Persistent.hpp
  requiredBy: []
  timestamp: '2020-10-24 15:28:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.RBTP.test.cpp
documentation_of: src/DataStructure/RedBlackTree_Persistent.hpp
layout: document
redirect_from:
- /library/src/DataStructure/RedBlackTree_Persistent.hpp
- /library/src/DataStructure/RedBlackTree_Persistent.hpp.html
title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A)"
---
