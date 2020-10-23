---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2207.test.cpp
    title: test/aoj/2207.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind_Potential.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u5404\u30CE\u30FC\u30C9\u306B\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u3082\u305F\u305B\u3001\u305D\u306E\u5DEE\
    \u3092\u6C42\u3081\u3089\u308C\u308B\n * @brief O(\u03B1(N))\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename Weight>\nstruct UnionFind_Potential {\n  std::vector<int>\
    \ par;\n  std::vector<Weight> val;\n  UnionFind_Potential(int size) : par(size,\
    \ -1), val(size, 0) {}\n  bool unite(int v, int u, Weight w) {\n    w += potential(u)\
    \ - potential(v);\n    if ((u = root(u)) == (v = root(v))) return false;\n   \
    \ if (par[u] > par[v]) swap(u, v), w = -w;\n    par[u] += par[v], par[v] = u,\
    \ val[v] = w;\n    return true;\n  }\n  bool same(int u, int v) { return root(u)\
    \ == root(v); }\n  int root(int u) {\n    if (par[u] < 0) return u;\n    int r\
    \ = root(par[u]);\n    val[u] += val[par[u]];\n    return par[u] = r;\n  }\n \
    \ int size(int u) { return -par[root(u)]; }\n  Weight potential(int u) {\n   \
    \ root(u);\n    return val[u];\n  }\n  Weight diff(int u, int v) { return potential(u)\
    \ - potential(v); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Union-Find(\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ \u5404\u30CE\u30FC\u30C9\u306B\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u3082\
    \u305F\u305B\u3001\u305D\u306E\u5DEE\u3092\u6C42\u3081\u3089\u308C\u308B\n * @brief\
    \ O(\u03B1(N))\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename Weight>\nstruct\
    \ UnionFind_Potential {\n  std::vector<int> par;\n  std::vector<Weight> val;\n\
    \  UnionFind_Potential(int size) : par(size, -1), val(size, 0) {}\n  bool unite(int\
    \ v, int u, Weight w) {\n    w += potential(u) - potential(v);\n    if ((u = root(u))\
    \ == (v = root(v))) return false;\n    if (par[u] > par[v]) swap(u, v), w = -w;\n\
    \    par[u] += par[v], par[v] = u, val[v] = w;\n    return true;\n  }\n  bool\
    \ same(int u, int v) { return root(u) == root(v); }\n  int root(int u) {\n   \
    \ if (par[u] < 0) return u;\n    int r = root(par[u]);\n    val[u] += val[par[u]];\n\
    \    return par[u] = r;\n  }\n  int size(int u) { return -par[root(u)]; }\n  Weight\
    \ potential(int u) {\n    root(u);\n    return val[u];\n  }\n  Weight diff(int\
    \ u, int v) { return potential(u) - potential(v); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind_Potential.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2207.test.cpp
documentation_of: src/DataStructure/UnionFind_Potential.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind_Potential.hpp
- /library/src/DataStructure/UnionFind_Potential.hpp.html
title: "Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)"
---
