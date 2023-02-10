---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2207.test.cpp
    title: test/aoj/2207.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc280_f.test.cpp
    title: test/atcoder/abc280_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/UnionFind_Potential.hpp\"\n#include <vector>\n\
    #include <algorithm>\ntemplate <typename Weight> struct UnionFind_Potential {\n\
    \ std::vector<int> par;\n std::vector<Weight> val;\n UnionFind_Potential(int size):\
    \ par(size, -1), val(size, 0) {}\n bool unite(int v, int u, Weight w) {\n  if\
    \ (w+= potential(u) - potential(v); (u= root(u)) == (v= root(v))) return false;\n\
    \  if (par[u] > par[v]) std::swap(u, v), w= -w;\n  return par[u]+= par[v], par[v]=\
    \ u, val[v]= w, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) {\n  if (par[u] < 0) return u;\n  int r= root(par[u]);\n\
    \  return val[u]+= val[par[u]], par[u]= r;\n }\n int size(int u) { return -par[root(u)];\
    \ }\n Weight potential(int u) { return root(u), val[u]; }\n Weight diff(int u,\
    \ int v) { return potential(u) - potential(v); }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\ntemplate <typename\
    \ Weight> struct UnionFind_Potential {\n std::vector<int> par;\n std::vector<Weight>\
    \ val;\n UnionFind_Potential(int size): par(size, -1), val(size, 0) {}\n bool\
    \ unite(int v, int u, Weight w) {\n  if (w+= potential(u) - potential(v); (u=\
    \ root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u,\
    \ v), w= -w;\n  return par[u]+= par[v], par[v]= u, val[v]= w, true;\n }\n bool\
    \ same(int u, int v) { return root(u) == root(v); }\n int root(int u) {\n  if\
    \ (par[u] < 0) return u;\n  int r= root(par[u]);\n  return val[u]+= val[par[u]],\
    \ par[u]= r;\n }\n int size(int u) { return -par[root(u)]; }\n Weight potential(int\
    \ u) { return root(u), val[u]; }\n Weight diff(int u, int v) { return potential(u)\
    \ - potential(v); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind_Potential.hpp
  requiredBy: []
  timestamp: '2023-01-23 20:22:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2207.test.cpp
  - test/atcoder/abc280_f.test.cpp
documentation_of: src/DataStructure/UnionFind_Potential.hpp
layout: document
title: "Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)"
---
各ノードにポテンシャルをもたせ、その差を求められる
## 計算量
$\mathcal{O}(\alpha(N))$
