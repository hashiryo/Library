---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2647.test.cpp
    title: test/aoj/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
    title: test/aoj/ALDS1_9_C.SkewHeap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.test.cpp
    title: test/aoj/GRL_2_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Skew-Heap
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SkewHeap.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Skew-Heap\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ \u30DE\u30FC\u30B8\u3067\u304D\u308B\u30D2\u30FC\u30D7\n * @brief top: O(1),\
    \ pop, push, merge: O(logN)\n * @brief add(v): \u5168\u4F53\u306B\u4F5C\u7528\u7D20\
    v\u3092\u9069\u7528\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T>\nstruct\
    \ Op_RaddQ {\n  using E = T;\n  static E ei() { return 0; }\n  static T g(const\
    \ T &l, const E &r) { return l + r; }\n  static E h(const E &l, const E &r) {\
    \ return l + r; }\n};\n\ntemplate <typename T, typename Compare = std::less<T>,\n\
    \          typename Op = Op_RaddQ<T>>\nstruct SkewHeap {\n  using E = typename\
    \ Op::E;\n  struct Node {\n    Node *ch[2];\n    T key;\n    E lazy;\n    Node()\
    \ {}\n    Node(T k, E laz) : ch{nullptr, nullptr}, key(k), lazy(laz) {}\n  } *\
    \ root;\n\n private:\n  void propagate(Node *a) {\n    if (a->lazy != Op::ei())\
    \ {\n      a->key = Op::g(a->key, a->lazy);\n      if (a->ch[0]) a->ch[0]->lazy\
    \ = Op::h(a->ch[0]->lazy, a->lazy);\n      if (a->ch[1]) a->ch[1]->lazy = Op::h(a->ch[1]->lazy,\
    \ a->lazy);\n      a->lazy = Op::ei();\n    }\n  }\n  Node *merge(Node *a, Node\
    \ *b) {\n    if (!a || !b) return a ? a : b;\n    propagate(a);\n    propagate(b);\n\
    \    if (Compare()(a->key, b->key)) std::swap(a, b);\n    a->ch[1] = merge(b,\
    \ a->ch[1]);\n    std::swap(a->ch[0], a->ch[1]);\n    return a;\n  }\n\n public:\n\
    \  /* max heap */\n  SkewHeap() : root(nullptr) {}\n  void push(T key) {\n   \
    \ Node *n = new Node(key, Op::ei());\n    root = merge(root, n);\n  }\n  T pop()\
    \ {\n    propagate(root);\n    T ret = root->key;\n    Node *temp = root;\n  \
    \  root = merge(root->ch[0], root->ch[1]);\n    delete temp;\n    return ret;\n\
    \  }\n  T top() {\n    propagate(root);\n    return root->key;\n  }\n  bool empty()\
    \ { return !root; }\n  void add(E v) { root->lazy = Op::h(root->lazy, v); }\n\
    \  void merge(SkewHeap x) { root = merge(root, x.root); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Skew-Heap\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u30DE\u30FC\u30B8\u3067\u304D\u308B\
    \u30D2\u30FC\u30D7\n * @brief top: O(1), pop, push, merge: O(logN)\n * @brief\
    \ add(v): \u5168\u4F53\u306B\u4F5C\u7528\u7D20v\u3092\u9069\u7528\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename T>\nstruct Op_RaddQ {\n  using E = T;\n  static\
    \ E ei() { return 0; }\n  static T g(const T &l, const E &r) { return l + r; }\n\
    \  static E h(const E &l, const E &r) { return l + r; }\n};\n\ntemplate <typename\
    \ T, typename Compare = std::less<T>,\n          typename Op = Op_RaddQ<T>>\n\
    struct SkewHeap {\n  using E = typename Op::E;\n  struct Node {\n    Node *ch[2];\n\
    \    T key;\n    E lazy;\n    Node() {}\n    Node(T k, E laz) : ch{nullptr, nullptr},\
    \ key(k), lazy(laz) {}\n  } * root;\n\n private:\n  void propagate(Node *a) {\n\
    \    if (a->lazy != Op::ei()) {\n      a->key = Op::g(a->key, a->lazy);\n    \
    \  if (a->ch[0]) a->ch[0]->lazy = Op::h(a->ch[0]->lazy, a->lazy);\n      if (a->ch[1])\
    \ a->ch[1]->lazy = Op::h(a->ch[1]->lazy, a->lazy);\n      a->lazy = Op::ei();\n\
    \    }\n  }\n  Node *merge(Node *a, Node *b) {\n    if (!a || !b) return a ? a\
    \ : b;\n    propagate(a);\n    propagate(b);\n    if (Compare()(a->key, b->key))\
    \ std::swap(a, b);\n    a->ch[1] = merge(b, a->ch[1]);\n    std::swap(a->ch[0],\
    \ a->ch[1]);\n    return a;\n  }\n\n public:\n  /* max heap */\n  SkewHeap() :\
    \ root(nullptr) {}\n  void push(T key) {\n    Node *n = new Node(key, Op::ei());\n\
    \    root = merge(root, n);\n  }\n  T pop() {\n    propagate(root);\n    T ret\
    \ = root->key;\n    Node *temp = root;\n    root = merge(root->ch[0], root->ch[1]);\n\
    \    delete temp;\n    return ret;\n  }\n  T top() {\n    propagate(root);\n \
    \   return root->key;\n  }\n  bool empty() { return !root; }\n  void add(E v)\
    \ { root->lazy = Op::h(root->lazy, v); }\n  void merge(SkewHeap x) { root = merge(root,\
    \ x.root); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SkewHeap.hpp
  requiredBy:
  - src/Graph/MinimumSpanningAborescense.hpp
  timestamp: '2020-10-24 12:39:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_2_B.test.cpp
  - test/aoj/ALDS1_9_C.SkewHeap.test.cpp
  - test/aoj/2647.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: src/DataStructure/SkewHeap.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SkewHeap.hpp
- /library/src/DataStructure/SkewHeap.hpp.html
title: Skew-Heap
---
