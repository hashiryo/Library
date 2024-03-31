---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.mo.test.cpp
    title: test/yosupo/static_range_inversions_query.mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/Mo.hpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n#include <cmath>\nstruct Mo {\n std::vector<int> L, R;\n Mo()\
    \ {}\n void query(int l, int r) { L.push_back(l), R.push_back(r); } /* [l, r)\
    \ */\n template <typename AL, typename AR, typename EL, typename ER, typename\
    \ O> void run(const AL &add_left, const AR &add_right, const EL &erase_left, const\
    \ ER &erase_right, const O &out) {\n  int q= L.size(), n= *std::max_element(R.begin(),\
    \ R.end()), bs= n / std::min<int>(n, std::sqrt(q));\n  std::vector<int> ord(q);\n\
    \  std::iota(ord.begin(), ord.end(), 0), std::sort(ord.begin(), ord.end(), [&](int\
    \ a, int b) {\n   int ablk= L[a] / bs, bblk= L[b] / bs;\n   return ablk != bblk\
    \ ? ablk < bblk : (ablk & 1) ? R[a] > R[b] : R[a] < R[b];\n  });\n  int l= 0,\
    \ r= 0;\n  for (auto i: ord) {\n   while (l > L[i]) add_left(--l);\n   while (r\
    \ < R[i]) add_right(r++);\n   while (l < L[i]) erase_left(l++);\n   while (r >\
    \ R[i]) erase_right(--r);\n   out(i);\n  }\n }\n template <typename A, typename\
    \ E, typename O> void run(const A &add, const E &erase, const O &out) { run(add,\
    \ add, erase, erase, out); }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <cmath>\nstruct Mo {\n std::vector<int> L, R;\n Mo() {}\n void query(int\
    \ l, int r) { L.push_back(l), R.push_back(r); } /* [l, r) */\n template <typename\
    \ AL, typename AR, typename EL, typename ER, typename O> void run(const AL &add_left,\
    \ const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out)\
    \ {\n  int q= L.size(), n= *std::max_element(R.begin(), R.end()), bs= n / std::min<int>(n,\
    \ std::sqrt(q));\n  std::vector<int> ord(q);\n  std::iota(ord.begin(), ord.end(),\
    \ 0), std::sort(ord.begin(), ord.end(), [&](int a, int b) {\n   int ablk= L[a]\
    \ / bs, bblk= L[b] / bs;\n   return ablk != bblk ? ablk < bblk : (ablk & 1) ?\
    \ R[a] > R[b] : R[a] < R[b];\n  });\n  int l= 0, r= 0;\n  for (auto i: ord) {\n\
    \   while (l > L[i]) add_left(--l);\n   while (r < R[i]) add_right(r++);\n   while\
    \ (l < L[i]) erase_left(l++);\n   while (r > R[i]) erase_right(--r);\n   out(i);\n\
    \  }\n }\n template <typename A, typename E, typename O> void run(const A &add,\
    \ const E &erase, const O &out) { run(add, add, erase, erase, out); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/Mo.hpp
  requiredBy: []
  timestamp: '2023-02-09 16:12:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1270.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
  - test/aoj/0425.test.cpp
documentation_of: src/Misc/Mo.hpp
layout: document
title: Mo's Algorithm
---
## 計算量
$\mathcal{O}(N\sqrt{Q})$
## 参考
[https://ei1333.hateblo.jp/entry/2017/09/11/211011](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
## 問題例
[Hacker Rank Range Counting Query](https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query)