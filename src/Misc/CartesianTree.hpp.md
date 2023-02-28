---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_B.test.cpp
    title: test/aoj/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_C.test.cpp
    title: test/aoj/DPL_3_C.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/CartesianTree.hpp\"\n#include <vector>\n#include\
    \ <array>\nclass CartesianTree {\n std::vector<std::array<int, 2>> rg, ch;\n std::vector<int>\
    \ par;\n int rt;\npublic:\n template <class T> CartesianTree(const std::vector<T>&\
    \ a, bool is_min= 1): rg(a.size()), ch(a.size(), std::array{-1, -1}), par(a.size(),\
    \ -1) {\n  const int n= a.size();\n  auto comp= [&](int l, int r) { return (is_min\
    \ ? a[l] < a[r] : a[l] > a[r]) || (a[l] == a[r] && l < r); };\n  std::vector<int>\
    \ st;\n  st.reserve(n);\n  for (int i= 0; i < n; rg[i][0]= (st.empty() ? 0 : st.back()\
    \ + 1), st.push_back(i++))\n   for (; !st.empty() && comp(i, st.back()); st.pop_back())\
    \ ch[i][0]= st.back();\n  st.clear();\n  for (int i= n; i--; rg[i][1]= (st.empty()\
    \ ? n : st.back()), st.push_back(i))\n   for (; !st.empty() && comp(i, st.back());\
    \ st.pop_back()) ch[i][1]= st.back();\n  for (int i= 0; i < n; ++i)\n   for (int\
    \ b= 2; b--;)\n    if (ch[i][b] != -1) par[ch[i][b]]= i;\n  for (int i= 0; i <\
    \ n; ++i)\n   if (par[i] == -1) rt= i;\n }\n std::array<int, 2> children(int i)\
    \ const { return ch[i]; }\n int parent(int i) const { return par[i]; }\n int root()\
    \ const { return rt; }\n // [l,r)\n std::array<int, 2> range(int i) const { return\
    \ rg[i]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <array>\nclass CartesianTree {\n\
    \ std::vector<std::array<int, 2>> rg, ch;\n std::vector<int> par;\n int rt;\n\
    public:\n template <class T> CartesianTree(const std::vector<T>& a, bool is_min=\
    \ 1): rg(a.size()), ch(a.size(), std::array{-1, -1}), par(a.size(), -1) {\n  const\
    \ int n= a.size();\n  auto comp= [&](int l, int r) { return (is_min ? a[l] < a[r]\
    \ : a[l] > a[r]) || (a[l] == a[r] && l < r); };\n  std::vector<int> st;\n  st.reserve(n);\n\
    \  for (int i= 0; i < n; rg[i][0]= (st.empty() ? 0 : st.back() + 1), st.push_back(i++))\n\
    \   for (; !st.empty() && comp(i, st.back()); st.pop_back()) ch[i][0]= st.back();\n\
    \  st.clear();\n  for (int i= n; i--; rg[i][1]= (st.empty() ? n : st.back()),\
    \ st.push_back(i))\n   for (; !st.empty() && comp(i, st.back()); st.pop_back())\
    \ ch[i][1]= st.back();\n  for (int i= 0; i < n; ++i)\n   for (int b= 2; b--;)\n\
    \    if (ch[i][b] != -1) par[ch[i][b]]= i;\n  for (int i= 0; i < n; ++i)\n   if\
    \ (par[i] == -1) rt= i;\n }\n std::array<int, 2> children(int i) const { return\
    \ ch[i]; }\n int parent(int i) const { return par[i]; }\n int root() const { return\
    \ rt; }\n // [l,r)\n std::array<int, 2> range(int i) const { return rg[i]; }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/CartesianTree.hpp
  requiredBy: []
  timestamp: '2023-02-28 17:13:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1031.test.cpp
  - test/yosupo/cartesian_tree.test.cpp
  - test/aoj/DPL_3_C.test.cpp
  - test/aoj/DPL_3_B.test.cpp
  - test/atcoder/arc115_e.test.cpp
  - test/atcoder/abc234_g.test.cpp
documentation_of: src/Misc/CartesianTree.hpp
layout: document
title: Cartesian-Tree
---
極大長方形のアルゴリズム
## メンバ関数
コンストラクタ `CartesianTree(vector a, bool is_min)` : 配列 $(a_n)$ をもとに構築. `is_min` が True なら 最小値, False なら 最大値 が親になるように構築 \
`range(int i)` : $a_i \in [l_i,r_i)$, $\forall j \in [l_i,r_i)\  a_j \ge (\text{or} \le\;) \;a_i$ を満たすもののうち $r_i-l_i$ が最大になるような 半開区間$[l_i, r_i)$ を返す \
`root()`: Cartesian-Treeの根を返す \
`parent(int i)`: Cartesian-Treeの$i$の親を返す \
`children(int i)`: Cartesian-Treeの$i$の子を返す. 二分木なので`array<int,2>` で返す. いない場合 $-1$.

## 計算量
構築 $\mathcal{O}(N)$

## 問題例
[AtCoder Beginner Contest 275 Ex - Monster](https://atcoder.jp/contests/abc275/tasks/abc275_h)