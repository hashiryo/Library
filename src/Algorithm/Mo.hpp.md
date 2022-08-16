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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo
    links:
    - https://ei1333.hateblo.jp/entry/2017/09/11/211011
    - https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query
  bundledCode: "#line 2 \"src/Algorithm/Mo.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title Mo\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O((N+Q)\u221A\
    N)\n * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011\n */\n// verify\u7528\
    \n// https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query\n\
    // BEGIN CUT HERE\n\nstruct Mo {\n  int n;\n  std::vector<std::pair<int, int>\
    \ > lr;\n  explicit Mo(int n) : n(n) {}\n  void query(int l, int r) { lr.emplace_back(l,\
    \ r); } /* [l, r) */\n  template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\n  void run(const AL &add_left, const AR &add_right, const EL\
    \ &erase_left,\n           const ER &erase_right, const O &out) {\n    int q =\
    \ (int)lr.size(), bs = n / std::min<int>(n, std::sqrt(q));\n    std::vector<int>\
    \ ord(q);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n      int ablock = lr[a].first / bs, bblock\
    \ = lr[b].first / bs;\n      return ablock != bblock ? ablock < bblock\n     \
    \        : (ablock & 1)   ? lr[a].second > lr[b].second\n                    \
    \          : lr[a].second < lr[b].second;\n    });\n    int l = 0, r = 0;\n  \
    \  for (auto idx : ord) {\n      while (l > lr[idx].first) add_left(--l);\n  \
    \    while (r < lr[idx].second) add_right(r++);\n      while (l < lr[idx].first)\
    \ erase_left(l++);\n      while (r > lr[idx].second) erase_right(--r);\n     \
    \ out(idx);\n    }\n  }\n  template <typename A, typename E, typename O>\n  void\
    \ run(const A &add, const E &erase, const O &out) {\n    run(add, add, erase,\
    \ erase, out);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Mo\n * @category \u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\n *  O((N+Q)\u221AN)\n * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    \ */\n// verify\u7528\n// https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query\n\
    // BEGIN CUT HERE\n\nstruct Mo {\n  int n;\n  std::vector<std::pair<int, int>\
    \ > lr;\n  explicit Mo(int n) : n(n) {}\n  void query(int l, int r) { lr.emplace_back(l,\
    \ r); } /* [l, r) */\n  template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\n  void run(const AL &add_left, const AR &add_right, const EL\
    \ &erase_left,\n           const ER &erase_right, const O &out) {\n    int q =\
    \ (int)lr.size(), bs = n / std::min<int>(n, std::sqrt(q));\n    std::vector<int>\
    \ ord(q);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n      int ablock = lr[a].first / bs, bblock\
    \ = lr[b].first / bs;\n      return ablock != bblock ? ablock < bblock\n     \
    \        : (ablock & 1)   ? lr[a].second > lr[b].second\n                    \
    \          : lr[a].second < lr[b].second;\n    });\n    int l = 0, r = 0;\n  \
    \  for (auto idx : ord) {\n      while (l > lr[idx].first) add_left(--l);\n  \
    \    while (r < lr[idx].second) add_right(r++);\n      while (l < lr[idx].first)\
    \ erase_left(l++);\n      while (r > lr[idx].second) erase_right(--r);\n     \
    \ out(idx);\n    }\n  }\n  template <typename A, typename E, typename O>\n  void\
    \ run(const A &add, const E &erase, const O &out) {\n    run(add, add, erase,\
    \ erase, out);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2022-08-16 12:30:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0425.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
documentation_of: src/Algorithm/Mo.hpp
layout: document
redirect_from:
- /library/src/Algorithm/Mo.hpp
- /library/src/Algorithm/Mo.hpp.html
title: Mo
---
