---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.PerArr.test.cpp
    title: test/atcoder/abc133_f.PerArr.test.cpp
  - icon: ':x:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/PersistentArray.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6C38\u7D9A\u914D\u5217\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n */\n\n// BEGIN CUT HERE\n\ntemplate <class T, std::size_t M = 32>\nclass\
    \ PersistentArray {\n  struct Node {\n    T val;\n    Node *ch[M];\n  } * root;\n\
    \  T get(Node *&t, std::size_t k) {\n    return t ? (k ? get(t->ch[k % M], (k\
    \ - 1) / M) : t->val) : T();\n  }\n  bool is_null(Node *&t, std::size_t k) {\n\
    \    return t ? (k ? get(t->ch[k % M], (k - 1) / M) : false) : true;\n  }\n  template\
    \ <bool persistent = true>\n  T &at(Node *&t, std::size_t k) {\n    if (!t)\n\
    \      t = new Node();\n    else if constexpr (persistent)\n      t = new Node(*t);\n\
    \    return k ? at<persistent>(t->ch[k % M], (k - 1) / M) : t->val;\n  }\n\n public:\n\
    \  PersistentArray() : root(nullptr) {}\n  PersistentArray(std::size_t n, T v)\
    \ {\n    for (std::size_t i = n; i--;) at<false>(root, i) = v;\n  }\n  PersistentArray(T\
    \ *bg, T *ed) {\n    for (std::size_t i = ed - bg; i--;) at<false>(root, i) =\
    \ *(bg + i);\n  }\n  PersistentArray(const std::vector<T> &ar)\n      : PersistentArray(ar.data(),\
    \ ar.data() + ar.size()) {}\n  bool is_null(std::size_t k) { return is_null(root,\
    \ k); }\n  T get(std::size_t k) { return get(root, k); }\n  T &at(std::size_t\
    \ k) { return at(root, k); }\n  T &operator[](std::size_t k) { return at(k); }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6C38\u7D9A\u914D\
    \u5217\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <class T, std::size_t M = 32>\nclass PersistentArray {\n  struct Node\
    \ {\n    T val;\n    Node *ch[M];\n  } * root;\n  T get(Node *&t, std::size_t\
    \ k) {\n    return t ? (k ? get(t->ch[k % M], (k - 1) / M) : t->val) : T();\n\
    \  }\n  bool is_null(Node *&t, std::size_t k) {\n    return t ? (k ? get(t->ch[k\
    \ % M], (k - 1) / M) : false) : true;\n  }\n  template <bool persistent = true>\n\
    \  T &at(Node *&t, std::size_t k) {\n    if (!t)\n      t = new Node();\n    else\
    \ if constexpr (persistent)\n      t = new Node(*t);\n    return k ? at<persistent>(t->ch[k\
    \ % M], (k - 1) / M) : t->val;\n  }\n\n public:\n  PersistentArray() : root(nullptr)\
    \ {}\n  PersistentArray(std::size_t n, T v) {\n    for (std::size_t i = n; i--;)\
    \ at<false>(root, i) = v;\n  }\n  PersistentArray(T *bg, T *ed) {\n    for (std::size_t\
    \ i = ed - bg; i--;) at<false>(root, i) = *(bg + i);\n  }\n  PersistentArray(const\
    \ std::vector<T> &ar)\n      : PersistentArray(ar.data(), ar.data() + ar.size())\
    \ {}\n  bool is_null(std::size_t k) { return is_null(root, k); }\n  T get(std::size_t\
    \ k) { return get(root, k); }\n  T &at(std::size_t k) { return at(root, k); }\n\
    \  T &operator[](std::size_t k) { return at(k); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/PersistentArray.hpp
  requiredBy:
  - src/DataStructure/UnionFind_Persistent.hpp
  timestamp: '2021-11-15 21:42:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
  - test/atcoder/abc133_f.PerArr.test.cpp
documentation_of: src/DataStructure/PersistentArray.hpp
layout: document
redirect_from:
- /library/src/DataStructure/PersistentArray.hpp
- /library/src/DataStructure/PersistentArray.hpp.html
title: "\u6C38\u7D9A\u914D\u5217"
---
