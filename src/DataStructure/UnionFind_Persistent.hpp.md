---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/PersistentArray.hpp\"\n#include <vector>\n\
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
    \ k) { return at(k); }\n};\n#line 3 \"src/DataStructure/UnionFind_Persistent.hpp\"\
    \nstruct UnionFind_Persistent {\n PersistentArray<int, 64> par;\n UnionFind_Persistent()\
    \ {}\n UnionFind_Persistent(int n): par(n, -1) {}\n bool unite(int u, int v) {\n\
    \  if ((u= root(u)) == (v= root(v))) return false;\n  if (par.get(u) > par.get(v))\
    \ std::swap(u, v);\n  par[u]+= par.get(v), par[v]= u;\n  return true;\n }\n bool\
    \ same(int u, int v) { return root(u) == root(v); }\n int root(int u) { return\
    \ par.get(u) < 0 ? u : root(par.get(u)); }\n int size(int u) { return -par.get(root(u));\
    \ }\n};\n"
  code: "#pragma once\n#include \"src/DataStructure/PersistentArray.hpp\"\nstruct\
    \ UnionFind_Persistent {\n PersistentArray<int, 64> par;\n UnionFind_Persistent()\
    \ {}\n UnionFind_Persistent(int n): par(n, -1) {}\n bool unite(int u, int v) {\n\
    \  if ((u= root(u)) == (v= root(v))) return false;\n  if (par.get(u) > par.get(v))\
    \ std::swap(u, v);\n  par[u]+= par.get(v), par[v]= u;\n  return true;\n }\n bool\
    \ same(int u, int v) { return root(u) == root(v); }\n int root(int u) { return\
    \ par.get(u) < 0 ? u : root(par.get(u)); }\n int size(int u) { return -par.get(root(u));\
    \ }\n};\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  isVerificationFile: false
  path: src/DataStructure/UnionFind_Persistent.hpp
  requiredBy: []
  timestamp: '2023-01-21 21:27:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: src/DataStructure/UnionFind_Persistent.hpp
layout: document
title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
---
経路圧縮なし
## 計算量
$\mathcal{O}(\log N)$
## 問題例
[CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h)