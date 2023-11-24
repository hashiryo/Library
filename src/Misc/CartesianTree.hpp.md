---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/String/SuffixTree.hpp
    title: "Suffix Tree (\u63A5\u5C3E\u8F9E\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_B.test.cpp
    title: test/aoj/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_C.test.cpp
    title: test/aoj/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc141_e.SuffixTree.test.cpp
    title: test/atcoder/abc141_e.SuffixTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_f.SuffixTree.test.cpp
    title: test/atcoder/abc213_f.SuffixTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc234_g.test.cpp
    title: test/atcoder/abc234_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc115_e.test.cpp
    title: test/atcoder/arc115_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cartesian_tree.test.cpp
    title: test/yosupo/cartesian_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1031.test.cpp
    title: test/yukicoder/1031.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2361.SuffixTree.test.cpp
    title: test/yukicoder/2361.SuffixTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/CartesianTree.hpp\"\n#include <vector>\n#include\
    \ <array>\nclass CartesianTree {\n std::vector<std::array<int, 2>> rg, ch;\n std::vector<int>\
    \ par;\n int rt;\npublic:\n template <class Vec> CartesianTree(const Vec &a, bool\
    \ is_min= 1): rg(a.size()), ch(a.size(), std::array{-1, -1}), par(a.size(), -1)\
    \ {\n  const int n= a.size();\n  auto comp= [&](int l, int r) { return (is_min\
    \ ? a[l] < a[r] : a[l] > a[r]) || (a[l] == a[r] && l < r); };\n  int st[n], t=\
    \ 0;\n  for (int i= n; i--; rg[i][1]= (t ? st[t - 1] : n), st[t++]= i)\n   while\
    \ (t && comp(i, st[t - 1])) ch[i][1]= st[--t];\n  for (int i= t= 0; i < n; rg[i][0]=\
    \ (t ? st[t - 1] + 1 : 0), st[t++]= i++)\n   while (t && comp(i, st[t - 1])) ch[i][0]=\
    \ st[--t];\n  for (int i= 0; i < n; ++i)\n   for (int b= 2; b--;)\n    if (ch[i][b]\
    \ != -1) par[ch[i][b]]= i;\n  for (int i= 0; i < n; ++i)\n   if (par[i] == -1)\
    \ rt= i;\n }\n std::array<int, 2> children(int i) const { return ch[i]; }\n int\
    \ parent(int i) const { return par[i]; }\n int root() const { return rt; }\n //\
    \ [l,r)\n std::array<int, 2> range(int i) const { return rg[i]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <array>\nclass CartesianTree {\n\
    \ std::vector<std::array<int, 2>> rg, ch;\n std::vector<int> par;\n int rt;\n\
    public:\n template <class Vec> CartesianTree(const Vec &a, bool is_min= 1): rg(a.size()),\
    \ ch(a.size(), std::array{-1, -1}), par(a.size(), -1) {\n  const int n= a.size();\n\
    \  auto comp= [&](int l, int r) { return (is_min ? a[l] < a[r] : a[l] > a[r])\
    \ || (a[l] == a[r] && l < r); };\n  int st[n], t= 0;\n  for (int i= n; i--; rg[i][1]=\
    \ (t ? st[t - 1] : n), st[t++]= i)\n   while (t && comp(i, st[t - 1])) ch[i][1]=\
    \ st[--t];\n  for (int i= t= 0; i < n; rg[i][0]= (t ? st[t - 1] + 1 : 0), st[t++]=\
    \ i++)\n   while (t && comp(i, st[t - 1])) ch[i][0]= st[--t];\n  for (int i= 0;\
    \ i < n; ++i)\n   for (int b= 2; b--;)\n    if (ch[i][b] != -1) par[ch[i][b]]=\
    \ i;\n  for (int i= 0; i < n; ++i)\n   if (par[i] == -1) rt= i;\n }\n std::array<int,\
    \ 2> children(int i) const { return ch[i]; }\n int parent(int i) const { return\
    \ par[i]; }\n int root() const { return rt; }\n // [l,r)\n std::array<int, 2>\
    \ range(int i) const { return rg[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/CartesianTree.hpp
  requiredBy:
  - src/String/SuffixTree.hpp
  timestamp: '2023-11-24 00:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/cartesian_tree.test.cpp
  - test/yukicoder/1031.test.cpp
  - test/yukicoder/2361.SuffixTree.test.cpp
  - test/aoj/DPL_3_B.test.cpp
  - test/aoj/DPL_3_C.test.cpp
  - test/atcoder/abc141_e.SuffixTree.test.cpp
  - test/atcoder/abc213_f.SuffixTree.test.cpp
  - test/atcoder/arc115_e.test.cpp
  - test/atcoder/abc234_g.test.cpp
documentation_of: src/Misc/CartesianTree.hpp
layout: document
title: Cartesian-Tree
---

<img src="https://github.com/hashiryo/Library/blob/master/img/cartesiantree.svg?raw=true" width="60%">

## メンバ関数

| 名前 | 概要| |
| --- |---| ---|
| `CartesianTree(Vec a, bool is_min)` | コンストラクタ.<br> 配列 $(a_n)$ をもとに構築. `is_min` が` true` なら 最小値, `false` なら 最大値 が親になるように構築. <br> 極大長方形のアルゴリズム.<br> 計算量は $\mathcal{O}(N)$ ||
| `range(int i)`                         | 次の条件を満たす半開区間 $\lbrack l, r)$ を返す. <br> 1. $i \in \lbrace l,\dots,r-1\rbrace$<br> 2. $\min_{j \in \lbrace l,\dots,r-1\rbrace} \lbrace a_j  \rbrace = a_i$ <br> ( `is_min` が `true` の場合, `false` なら $\max$ ) <br> 3. 極大. つまり <br> $\min_{j \in \lbrace l-1,\dots,r-1\rbrace} \lbrace a_j  \rbrace \neq a_i$ かつ $\min_{j \in \lbrace l,\dots,r\rbrace} \lbrace a_j  \rbrace \neq a_i$ <br>( `is_min` が `true` の場合, `false` なら $\max$ ) |<img src="https://github.com/hashiryo/Library/blob/master/img/cartesiantree_range.svg?raw=true" width="40%">|
| `root()`                               | Cartesian-Treeの根を返す. ||
| `parent(int i)`                        | Cartesian-Treeの頂点 $i$ の親を返す. |<img src="https://github.com/hashiryo/Library/blob/master/img/cartesiantree_parent.svg?raw=true" width="40%">|
| `children(int i)`                      | Cartesian-Treeの頂点 $i$ の子を返す. <br> 二分木なので`array<int,2>` で返す. いない場合 $-1$.|<img src="https://github.com/hashiryo/Library/blob/master/img/cartesiantree_children.svg?raw=true" width="40%">|


## 問題例
[AtCoder Beginner Contest 275 Ex - Monster](https://atcoder.jp/contests/abc275/tasks/abc275_h)(木上をdfs)