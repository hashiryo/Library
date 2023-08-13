---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_H.test.cpp
    title: test/aoj/DPL_1_H.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/Knapsack.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\ntemplate <class value_t, class weight_t> class Knapsack {\n std::vector<std::pair<weight_t,\
    \ value_t>> I, L, R, tmp;\npublic:\n Knapsack() {}\n void add(value_t v, weight_t\
    \ w) { I.emplace_back(w, v); }\n void build() {\n  const int n= I.size(), l= n\
    \ / 2, r= n - l;\n  int i= 0, u, s;\n  for (s= u= 1, L.resize(1 << l), tmp.resize(1\
    \ << l); i < l; std::merge(L.begin(), L.begin() + u, L.begin() + u, L.begin()\
    \ + u + u, tmp.begin()), ++i, s= u<<= 1, L.swap(tmp))\n   for (auto [w, v]= I[i];\
    \ s--;) L[u | s]= {L[s].first + w, L[s].second + v};\n  for (s= u= 1, R.resize(1\
    \ << r), tmp.resize(1 << r); i < n; std::merge(R.begin(), R.begin() + u, R.begin()\
    \ + u, R.begin() + u + u, tmp.begin()), ++i, s= u<<= 1, R.swap(tmp))\n   for (auto\
    \ [w, v]= I[i]; s--;) R[u | s]= {R[s].first + w, R[s].second + v};\n  for (i=\
    \ 1; i < u; ++i) R[i].second= std::max(R[i].second, R[i - 1].second);\n }\n value_t\
    \ solve(weight_t cap) const {\n  value_t ret= 0;\n  int j= R.size() - 1;\n  for\
    \ (auto [w, v]: L) {\n   if (cap < w) break;\n   for (auto c= cap - w; R[j].first\
    \ > c;) --j;\n   ret= std::max(ret, v + R[j].second);\n  }\n  return ret;\n }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\ntemplate <class value_t,\
    \ class weight_t> class Knapsack {\n std::vector<std::pair<weight_t, value_t>>\
    \ I, L, R, tmp;\npublic:\n Knapsack() {}\n void add(value_t v, weight_t w) { I.emplace_back(w,\
    \ v); }\n void build() {\n  const int n= I.size(), l= n / 2, r= n - l;\n  int\
    \ i= 0, u, s;\n  for (s= u= 1, L.resize(1 << l), tmp.resize(1 << l); i < l; std::merge(L.begin(),\
    \ L.begin() + u, L.begin() + u, L.begin() + u + u, tmp.begin()), ++i, s= u<<=\
    \ 1, L.swap(tmp))\n   for (auto [w, v]= I[i]; s--;) L[u | s]= {L[s].first + w,\
    \ L[s].second + v};\n  for (s= u= 1, R.resize(1 << r), tmp.resize(1 << r); i <\
    \ n; std::merge(R.begin(), R.begin() + u, R.begin() + u, R.begin() + u + u, tmp.begin()),\
    \ ++i, s= u<<= 1, R.swap(tmp))\n   for (auto [w, v]= I[i]; s--;) R[u | s]= {R[s].first\
    \ + w, R[s].second + v};\n  for (i= 1; i < u; ++i) R[i].second= std::max(R[i].second,\
    \ R[i - 1].second);\n }\n value_t solve(weight_t cap) const {\n  value_t ret=\
    \ 0;\n  int j= R.size() - 1;\n  for (auto [w, v]: L) {\n   if (cap < w) break;\n\
    \   for (auto c= cap - w; R[j].first > c;) --j;\n   ret= std::max(ret, v + R[j].second);\n\
    \  }\n  return ret;\n }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/Knapsack.hpp
  requiredBy: []
  timestamp: '2023-04-02 00:58:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_H.test.cpp
documentation_of: src/Optimization/Knapsack.hpp
layout: document
title: "0-1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C (\u534A\u5206\u5168\u5217\
  \u6319)"
---
計算量が n 倍 改善されてるやつ \
空間計算量的にも n は 50 ぐらいが限界か
## メンバ関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `add(v,w)`   | 価値 v, 重さ w のアイテムを追加                      |                                |
| `build()`    | 下準備 (半分に分けて全列挙する)                      | $\mathcal{O}(2^{\frac{n}{2}})$ |
| `solve(cap)` | 容量が cap 以下になるような価値の最大値を返す (尺取) | $\mathcal{O}(2^{\frac{n}{2}})$ |

## 参考
[https://twitter.com/noshi91/status/1271857111903825920](https://twitter.com/noshi91/status/1271857111903825920) 
## 問題例
[東京海上日動 プログラミングコンテスト2020 D - Knapsack Queries on a tree](https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_d)