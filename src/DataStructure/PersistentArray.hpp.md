---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/PersistentArray.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6C38\u7D9A\u914D\u5217\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename T, int LOG = 3>\nstruct\
    \ PersistentArray {\n  struct Node {\n    T data;\n    Node *child[1 << LOG] =\
    \ {};\n    Node() {}\n  };\n\n private:\n  Node *root;\n\n public:\n  PersistentArray()\
    \ : root(nullptr) {}\n  PersistentArray(size_t n, const T &v = T()) { build(std::vector<T>(n,\
    \ v)); }\n  PersistentArray(const std::vector<T> &v) { build(v); }\n  const T\
    \ get(const int &k) const { return get(root, k); }\n  T &operator[](const int\
    \ &k) { return reference_get(k, false); }\n  void build(const std::vector<T> &v)\
    \ {\n    root = nullptr;\n    for (int i = 0; i < v.size(); i++) reference_get(i,\
    \ true) = v[i];\n  }\n\n private:\n  T get(Node *t, int k) const {\n    if (!t)\
    \ return T();\n    if (k == 0) return t->data;\n    return get(t->child[k & ((1\
    \ << LOG) - 1)], k >> LOG);\n  }\n  std::pair<Node *, T &> reference_get(Node\
    \ *t, int k, bool destruct = false) {\n    t = t ? (destruct ? t : new Node(*t))\
    \ : new Node();\n    if (k == 0) return {t, t->data};\n    auto p = reference_get(t->child[k\
    \ & ((1 << LOG) - 1)], k >> LOG, destruct);\n    t->child[k & ((1 << LOG) - 1)]\
    \ = p.first;\n    return {t, p.second};\n  }\n  T &reference_get(const int &k,\
    \ bool destruct = false) {\n    auto ret = reference_get(root, k, destruct);\n\
    \    root = ret.first;\n    return ret.second;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6C38\u7D9A\u914D\
    \u5217\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <typename T, int LOG = 3>\nstruct PersistentArray {\n  struct Node\
    \ {\n    T data;\n    Node *child[1 << LOG] = {};\n    Node() {}\n  };\n\n private:\n\
    \  Node *root;\n\n public:\n  PersistentArray() : root(nullptr) {}\n  PersistentArray(size_t\
    \ n, const T &v = T()) { build(std::vector<T>(n, v)); }\n  PersistentArray(const\
    \ std::vector<T> &v) { build(v); }\n  const T get(const int &k) const { return\
    \ get(root, k); }\n  T &operator[](const int &k) { return reference_get(k, false);\
    \ }\n  void build(const std::vector<T> &v) {\n    root = nullptr;\n    for (int\
    \ i = 0; i < v.size(); i++) reference_get(i, true) = v[i];\n  }\n\n private:\n\
    \  T get(Node *t, int k) const {\n    if (!t) return T();\n    if (k == 0) return\
    \ t->data;\n    return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n  }\n \
    \ std::pair<Node *, T &> reference_get(Node *t, int k, bool destruct = false)\
    \ {\n    t = t ? (destruct ? t : new Node(*t)) : new Node();\n    if (k == 0)\
    \ return {t, t->data};\n    auto p = reference_get(t->child[k & ((1 << LOG) -\
    \ 1)], k >> LOG, destruct);\n    t->child[k & ((1 << LOG) - 1)] = p.first;\n \
    \   return {t, p.second};\n  }\n  T &reference_get(const int &k, bool destruct\
    \ = false) {\n    auto ret = reference_get(root, k, destruct);\n    root = ret.first;\n\
    \    return ret.second;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/PersistentArray.hpp
  requiredBy:
  - src/DataStructure/UnionFind_Persistent.hpp
  timestamp: '2020-10-24 17:49:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: src/DataStructure/PersistentArray.hpp
layout: document
redirect_from:
- /library/src/DataStructure/PersistentArray.hpp
- /library/src/DataStructure/PersistentArray.hpp.html
title: "\u6C38\u7D9A\u914D\u5217"
---
