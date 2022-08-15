---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Algorithm/Mo.hpp
    title: Mo
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query
    links:
    - https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query
  bundledCode: "#line 1 \"test/hackerrank/range-counting-query.Mo.test.cpp\"\n#define\
    \ PROBLEM \\\n  \"https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query\"\
    \n\n#include <bits/stdc++.h>\n#line 3 \"src/Algorithm/Mo.hpp\"\n/**\n * @title\
    \ Mo\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O((N+Q)\u221AN)\n\
    \ * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011\n */\n\n// BEGIN CUT\
    \ HERE\n\nstruct Mo {\n  int n;\n  std::vector<std::pair<int, int> > lr;\n  explicit\
    \ Mo(int n) : n(n) {}\n  /* [l, r) */\n  void query(int l, int r) { lr.emplace_back(l,\
    \ r); }\n\n  template <typename AL, typename AR, typename EL, typename ER, typename\
    \ O>\n  void run(const AL &add_left, const AR &add_right, const EL &erase_left,\n\
    \           const ER &erase_right, const O &out) {\n    int q = (int)lr.size();\n\
    \    int bs = n / std::min<int>(n, std::sqrt(q));\n    std::vector<int> ord(q);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(), ord.end(),\
    \ [&](int a, int b) {\n      int ablock = lr[a].first / bs, bblock = lr[b].first\
    \ / bs;\n      if (ablock != bblock) return ablock < bblock;\n      return (ablock\
    \ & 1) ? lr[a].second > lr[b].second\n                          : lr[a].second\
    \ < lr[b].second;\n    });\n    int l = 0, r = 0;\n    for (auto idx : ord) {\n\
    \      while (l > lr[idx].first) add_left(--l);\n      while (r < lr[idx].second)\
    \ add_right(r++);\n      while (l < lr[idx].first) erase_left(l++);\n      while\
    \ (r > lr[idx].second) erase_right(--r);\n      out(idx);\n    }\n  }\n  template\
    \ <typename A, typename E, typename O>\n  void run(const A &add, const E &erase,\
    \ const O &out) {\n    run(add, add, erase, erase, out);\n  }\n};\n#line 6 \"\
    test/hackerrank/range-counting-query.Mo.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N;\n  cin >> N;\n\
    \  int A[N], cnt[N] = {}, sum[N + 2] = {};\n  for (int i = 0; i < N; i++) cin\
    \ >> A[i], A[i]--;\n  Mo mo(N);\n  int Q;\n  cin >> Q;\n  int x[Q], y[Q], ans[Q];\n\
    \  for (int q = 0; q < Q; q++) {\n    int l, r;\n    cin >> l >> r >> x[q] >>\
    \ y[q];\n    mo.query(--l, r);\n  }\n  auto add = [&](int k) { sum[++cnt[A[k]]]++;\
    \ };\n  auto erase = [&](int k) { sum[cnt[A[k]]--]--; };\n  auto out = [&](int\
    \ q) { ans[q] = sum[x[q]] - sum[y[q] + 1]; };\n  mo.run(add, erase, out);\n  for\
    \ (int q = 0; q < Q; q++) cout << ans[q] << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://www.hackerrank.com/contests/happy-query-contest/challenges/range-counting-query\"\
    \n\n#include <bits/stdc++.h>\n#include \"src/Algorithm/Mo.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N;\n\
    \  cin >> N;\n  int A[N], cnt[N] = {}, sum[N + 2] = {};\n  for (int i = 0; i <\
    \ N; i++) cin >> A[i], A[i]--;\n  Mo mo(N);\n  int Q;\n  cin >> Q;\n  int x[Q],\
    \ y[Q], ans[Q];\n  for (int q = 0; q < Q; q++) {\n    int l, r;\n    cin >> l\
    \ >> r >> x[q] >> y[q];\n    mo.query(--l, r);\n  }\n  auto add = [&](int k) {\
    \ sum[++cnt[A[k]]]++; };\n  auto erase = [&](int k) { sum[cnt[A[k]]--]--; };\n\
    \  auto out = [&](int q) { ans[q] = sum[x[q]] - sum[y[q] + 1]; };\n  mo.run(add,\
    \ erase, out);\n  for (int q = 0; q < Q; q++) cout << ans[q] << '\\n';\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Algorithm/Mo.hpp
  isVerificationFile: true
  path: test/hackerrank/range-counting-query.Mo.test.cpp
  requiredBy: []
  timestamp: '2022-08-16 03:00:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/range-counting-query.Mo.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/range-counting-query.Mo.test.cpp
- /verify/test/hackerrank/range-counting-query.Mo.test.cpp.html
title: test/hackerrank/range-counting-query.Mo.test.cpp
---
