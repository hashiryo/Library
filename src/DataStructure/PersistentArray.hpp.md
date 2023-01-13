---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc133_f.PerArr.test.cpp
    title: test/atcoder/abc133_f.PerArr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/PersistentArray.hpp\"\n#include <bits/stdc++.h>\n\
    template <class T, std::size_t M= 8> class PersistentArray {\n struct Node {\n\
    \  T val;\n  Node *ch[M];\n } * root;\n T get(Node *&t, std::size_t k) { return\
    \ t ? (k ? get(t->ch[(k - 1) % M], (k - 1) / M) : t->val) : T(); }\n bool is_null(Node\
    \ *&t, std::size_t k) { return t ? (k ? is_null(t->ch[(k - 1) % M], (k - 1) /\
    \ M) : false) : true; }\n template <bool persistent= true> T &at(Node *&t, std::size_t\
    \ k) {\n  if (!t) t= new Node();\n  else if constexpr (persistent) t= new Node(*t);\n\
    \  return k ? at<persistent>(t->ch[(k - 1) % M], (k - 1) / M) : t->val;\n }\n\
    public:\n PersistentArray(): root(nullptr) {}\n PersistentArray(std::size_t n,\
    \ T v): root(nullptr) {\n  for (std::size_t i= n; i--;) at<false>(root, i)= v;\n\
    \ }\n PersistentArray(T *bg, T *ed): root(nullptr) {\n  for (std::size_t i= ed\
    \ - bg; i--;) at<false>(root, i)= *(bg + i);\n }\n PersistentArray(const std::vector<T>\
    \ &ar): PersistentArray(ar.data(), ar.data() + ar.size()) {}\n bool is_null(std::size_t\
    \ k) { return is_null(root, k); }\n T get(std::size_t k) { return get(root, k);\
    \ }\n T &at(std::size_t k) { return at<true>(root, k); }\n T &operator[](std::size_t\
    \ k) { return at(k); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <class T, std::size_t M=\
    \ 8> class PersistentArray {\n struct Node {\n  T val;\n  Node *ch[M];\n } * root;\n\
    \ T get(Node *&t, std::size_t k) { return t ? (k ? get(t->ch[(k - 1) % M], (k\
    \ - 1) / M) : t->val) : T(); }\n bool is_null(Node *&t, std::size_t k) { return\
    \ t ? (k ? is_null(t->ch[(k - 1) % M], (k - 1) / M) : false) : true; }\n template\
    \ <bool persistent= true> T &at(Node *&t, std::size_t k) {\n  if (!t) t= new Node();\n\
    \  else if constexpr (persistent) t= new Node(*t);\n  return k ? at<persistent>(t->ch[(k\
    \ - 1) % M], (k - 1) / M) : t->val;\n }\npublic:\n PersistentArray(): root(nullptr)\
    \ {}\n PersistentArray(std::size_t n, T v): root(nullptr) {\n  for (std::size_t\
    \ i= n; i--;) at<false>(root, i)= v;\n }\n PersistentArray(T *bg, T *ed): root(nullptr)\
    \ {\n  for (std::size_t i= ed - bg; i--;) at<false>(root, i)= *(bg + i);\n }\n\
    \ PersistentArray(const std::vector<T> &ar): PersistentArray(ar.data(), ar.data()\
    \ + ar.size()) {}\n bool is_null(std::size_t k) { return is_null(root, k); }\n\
    \ T get(std::size_t k) { return get(root, k); }\n T &at(std::size_t k) { return\
    \ at<true>(root, k); }\n T &operator[](std::size_t k) { return at(k); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/PersistentArray.hpp
  requiredBy:
  - src/DataStructure/UnionFind_Persistent.hpp
  timestamp: '2023-01-08 18:54:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc133_f.PerArr.test.cpp
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: src/DataStructure/PersistentArray.hpp
layout: document
title: "\u6C38\u7D9A\u914D\u5217"
---
M分木
## 計算量
get: $\mathcal{O}(\log_M N)$ \
at: $\mathcal{O}(M \log_M N)$