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
    document_title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
    links:
    - https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h
  bundledCode: "#line 2 \"src/DataStructure/UnionFind_Persistent.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/PersistentArray.hpp\"\n/**\n * @title \u6C38\u7D9A\
    \u914D\u5217\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * M\u5206\u6728\n\
    \ * get: O(log_M N)\n * at: O(M log_M N)\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <class T, std::size_t M = 8>\nclass PersistentArray {\n  struct Node {\n   \
    \ T val;\n    Node *ch[M];\n  } * root;\n  T get(Node *&t, std::size_t k) {\n\
    \    return t ? (k ? get(t->ch[(k - 1) % M], (k - 1) / M) : t->val) : T();\n \
    \ }\n  bool is_null(Node *&t, std::size_t k) {\n    return t ? (k ? is_null(t->ch[(k\
    \ - 1) % M], (k - 1) / M) : false) : true;\n  }\n  template <bool persistent =\
    \ true>\n  T &at(Node *&t, std::size_t k) {\n    if (!t)\n      t = new Node();\n\
    \    else if constexpr (persistent)\n      t = new Node(*t);\n    return k ? at<persistent>(t->ch[(k\
    \ - 1) % M], (k - 1) / M) : t->val;\n  }\n\n public:\n  PersistentArray() : root(nullptr)\
    \ {}\n  PersistentArray(std::size_t n, T v) : root(nullptr) {\n    for (std::size_t\
    \ i = n; i--;) at<false>(root, i) = v;\n  }\n  PersistentArray(T *bg, T *ed) :\
    \ root(nullptr) {\n    for (std::size_t i = ed - bg; i--;) at<false>(root, i)\
    \ = *(bg + i);\n  }\n  PersistentArray(const std::vector<T> &ar)\n      : PersistentArray(ar.data(),\
    \ ar.data() + ar.size()) {}\n  bool is_null(std::size_t k) { return is_null(root,\
    \ k); }\n  T get(std::size_t k) { return get(root, k); }\n  T &at(std::size_t\
    \ k) { return at<true>(root, k); }\n  T &operator[](std::size_t k) { return at(k);\
    \ }\n};\n#line 4 \"src/DataStructure/UnionFind_Persistent.hpp\"\n/**\n * @title\
    \ Union-Find(\u5B8C\u5168\u6C38\u7D9A)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n * \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057 O(logN)\n */\n// verify\u7528:\n// https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h\n\
    \n// BEGIN CUT HERE\n\nstruct UnionFind_Persistent {\n  PersistentArray<int, 64>\
    \ par;\n  UnionFind_Persistent() {}\n  UnionFind_Persistent(int n) : par(n, -1)\
    \ {}\n  bool unite(int u, int v) {\n    if ((u = root(u)) == (v = root(v))) return\
    \ false;\n    if (par.get(u) > par.get(v)) std::swap(u, v);\n    par[u] += par.get(v),\
    \ par[v] = u;\n    return true;\n  }\n  bool same(int u, int v) { return root(u)\
    \ == root(v); }\n  int root(int u) { return par.get(u) < 0 ? u : root(par.get(u));\
    \ }\n  int size(int u) { return -par.get(root(u)); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/DataStructure/PersistentArray.hpp\"\
    \n/**\n * @title Union-Find(\u5B8C\u5168\u6C38\u7D9A)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057 O(logN)\n */\n// verify\u7528\
    :\n// https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h\n\
    \n// BEGIN CUT HERE\n\nstruct UnionFind_Persistent {\n  PersistentArray<int, 64>\
    \ par;\n  UnionFind_Persistent() {}\n  UnionFind_Persistent(int n) : par(n, -1)\
    \ {}\n  bool unite(int u, int v) {\n    if ((u = root(u)) == (v = root(v))) return\
    \ false;\n    if (par.get(u) > par.get(v)) std::swap(u, v);\n    par[u] += par.get(v),\
    \ par[v] = u;\n    return true;\n  }\n  bool same(int u, int v) { return root(u)\
    \ == root(v); }\n  int root(int u) { return par.get(u) < 0 ? u : root(par.get(u));\
    \ }\n  int size(int u) { return -par.get(root(u)); }\n};\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  isVerificationFile: false
  path: src/DataStructure/UnionFind_Persistent.hpp
  requiredBy: []
  timestamp: '2021-11-16 15:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: src/DataStructure/UnionFind_Persistent.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind_Persistent.hpp
- /library/src/DataStructure/UnionFind_Persistent.hpp.html
title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
---
