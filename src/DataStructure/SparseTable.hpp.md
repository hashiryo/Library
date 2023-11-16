---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/yosupo/static_range_frequency.WM.test copy.cpp
    title: test/yosupo/static_range_frequency.WM.test copy.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparsetable.test.cpp
    title: test/aoj/DSL_3_D.sparsetable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SparseTable.hpp\"\n#include <vector>\n\
    template <class T, class F> struct SparseTable {\n std::vector<std::vector<T>>\
    \ dat;\n const F &f;\n SparseTable(const std::vector<T> &v, const F &f): f(f)\
    \ {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n - 1) : 0;\n  dat.resize(log\
    \ + 1), dat[0].assign(v.begin(), v.end());\n  for (int i= 0, I= 1, j; i < log;\
    \ ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size() - I); j--;) dat[i +\
    \ 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T fold(int l, int r) {\n\
    \  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r - l - 1);\n\
    \  return f(dat[k][l], dat[k][r - (1 << k)]);\n }\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <class T, class F> struct SparseTable\
    \ {\n std::vector<std::vector<T>> dat;\n const F &f;\n SparseTable(const std::vector<T>\
    \ &v, const F &f): f(f) {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n\
    \ - 1) : 0;\n  dat.resize(log + 1), dat[0].assign(v.begin(), v.end());\n  for\
    \ (int i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size()\
    \ - I); j--;) dat[i + 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T\
    \ fold(int l, int r) {\n  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r\
    \ - l - 1);\n  return f(dat[k][l], dat[k][r - (1 << k)]);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SparseTable.hpp
  requiredBy:
  - test/yosupo/static_range_frequency.WM.test copy.cpp
  timestamp: '2023-11-16 23:12:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.sparsetable.test.cpp
documentation_of: src/DataStructure/SparseTable.hpp
layout: document
title: Sparse-Table
---

結合則と冪等則を満たす二項演算子を渡して区間のまとめあげを高速に行うデータ構造.\
冪等則を要求する代わりに disjoint-sparse-table より定数倍が良い.

## メンバ関数

|名前|概要|計算量|
|---|---|---|
|`SparseTable(v,f)`|コンストラクタ. <br> 配列 `v` と2変数引数の関数 `f` 渡す. |以下配列のサイズを $n$ とする. <br> $\mathcal{O}(n\log n)$|
|`fold(l,r)`|半開区間$\lbrack l,r)$ について `f` でまとめあげた値を返す.|$\mathcal{O}(1)$|