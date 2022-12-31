---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425.test.cpp
    title: test/aoj/0425.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.mo.test.cpp
    title: test/yosupo/static_range_inversions_query.mo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/Mo.hpp\"\n#include <bits/stdc++.h>\nstruct Mo {\n\
    \ int n;\n std::vector<std::pair<int, int> > lr;\n explicit Mo(int n): n(n) {}\n\
    \ void query(int l, int r) { lr.emplace_back(l, r); } /* [l, r) */\n template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O> void run(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const O &out) {\n  int q= (int)lr.size(), bs= n / std::min<int>(n, std::sqrt(q));\n\
    \  std::vector<int> ord(q);\n  std::iota(ord.begin(), ord.end(), 0);\n  std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n   int ablock= lr[a].first / bs, bblock= lr[b].first\
    \ / bs;\n   return ablock != bblock ? ablock < bblock : (ablock & 1) ? lr[a].second\
    \ > lr[b].second : lr[a].second < lr[b].second;\n  });\n  int l= 0, r= 0;\n  for\
    \ (auto idx: ord) {\n   while (l > lr[idx].first) add_left(--l);\n   while (r\
    \ < lr[idx].second) add_right(r++);\n   while (l < lr[idx].first) erase_left(l++);\n\
    \   while (r > lr[idx].second) erase_right(--r);\n   out(idx);\n  }\n }\n template\
    \ <typename A, typename E, typename O> void run(const A &add, const E &erase,\
    \ const O &out) { run(add, add, erase, erase, out); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nstruct Mo {\n int n;\n std::vector<std::pair<int,\
    \ int> > lr;\n explicit Mo(int n): n(n) {}\n void query(int l, int r) { lr.emplace_back(l,\
    \ r); } /* [l, r) */\n template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O> void run(const AL &add_left, const AR &add_right, const EL &erase_left,\
    \ const ER &erase_right, const O &out) {\n  int q= (int)lr.size(), bs= n / std::min<int>(n,\
    \ std::sqrt(q));\n  std::vector<int> ord(q);\n  std::iota(ord.begin(), ord.end(),\
    \ 0);\n  std::sort(ord.begin(), ord.end(), [&](int a, int b) {\n   int ablock=\
    \ lr[a].first / bs, bblock= lr[b].first / bs;\n   return ablock != bblock ? ablock\
    \ < bblock : (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;\n\
    \  });\n  int l= 0, r= 0;\n  for (auto idx: ord) {\n   while (l > lr[idx].first)\
    \ add_left(--l);\n   while (r < lr[idx].second) add_right(r++);\n   while (l <\
    \ lr[idx].first) erase_left(l++);\n   while (r > lr[idx].second) erase_right(--r);\n\
    \   out(idx);\n  }\n }\n template <typename A, typename E, typename O> void run(const\
    \ A &add, const E &erase, const O &out) { run(add, add, erase, erase, out); }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/Mo.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:09:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0425.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
documentation_of: src/Misc/Mo.hpp
layout: document
title: Mo's Algorithm
---
## 計算量
$\mathcal{O}((N+Q)\sqrt{N})$
## 参考
https://ei1333.hateblo.jp/entry/2017/09/11/211011
## 問題例
[Hacker Rank Range Counting Query](https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query)