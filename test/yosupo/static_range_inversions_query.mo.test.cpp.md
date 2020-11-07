---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Algorithm/Mo.hpp
    title: Mo
  - icon: ':question:'
    path: src/DataStructure/BinaryIndexedTree.hpp
    title: Binary-Indexed-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.mo.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Algorithm/Mo.hpp\"\n/**\n * @title Mo\n\
    \ * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O((N+Q)\u221AN)\n * @see\
    \ https://ei1333.hateblo.jp/entry/2017/09/11/211011\n */\n\n// BEGIN CUT HERE\n\
    \nstruct Mo {\n  int n;\n  std::vector<std::pair<int, int> > lr;\n  explicit Mo(int\
    \ n) : n(n) {}\n  /* [l, r) */\n  void query(int l, int r) { lr.emplace_back(l,\
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
    \ const O &out) {\n    run(add, add, erase, erase, out);\n  }\n};\n#line 3 \"\
    src/DataStructure/BinaryIndexedTree.hpp\"\n/**\n * @title Binary-Indexed-Tree\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *  O(logN)\n *  0-indexed\n */\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  std::vector<T>\
    \ dat;\n  BinaryIndexedTree(int n) : dat(n + 1, T(0)) {}\n  BinaryIndexedTree(int\
    \ n, T a) : BinaryIndexedTree(std::vector<T>(n, a)) {}\n  BinaryIndexedTree(std::vector<T>\
    \ y) : dat(y.size() + 1, 0) {\n    for (size_t i = 0; i < y.size(); ++i) dat[i\
    \ + 1] = y[i];\n    for (int i = 1; i < (int)dat.size(); ++i)\n      if (i + (i\
    \ & -i) < (int)dat.size()) dat[i + (i & -i)] += dat[i];\n  }\n  void add(int i,\
    \ T a = 1) {\n    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;\n \
    \ }\n  T sum(int i) {  // sum [0,i)\n    T s = 0;\n    for (; i > 0; i &= i -\
    \ 1) s += dat[i];\n    return s;\n  }\n  // sum [l,r)\n  T sum(int l, int r) {\
    \ return sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k + 1) - sum(k);\
    \ }\n  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n  int find(T k)\
    \ const {\n    int i = 0;\n    for (int p = 1 << (std::__lg(dat.size() - 1) +\
    \ 1); p > 0; p >>= 1)\n      if (i + p < (int)dat.size() && dat[i + p] <= k) k\
    \ -= dat[i += p];\n    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no\
    \ solutions\n  }\n};\n#line 5 \"test/yosupo/static_range_inversions_query.mo.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  int A[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> A[i];\n  vector<int> v(A, A + N);\n  sort(v.begin(), v.end());\n  v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n  for (int i = 0; i < N; i++)\n    A[i] = lower_bound(v.begin(),\
    \ v.end(), A[i]) - v.begin();\n  Mo mo(N);\n  for (int q = 0; q < Q; q++) {\n\
    \    int l, r;\n    cin >> l >> r;\n    mo.query(l, r);\n  }\n  BinaryIndexedTree<long\
    \ long> bit(N + 1);\n  long long inv = 0, total = 0;\n  auto addl = [&](int i)\
    \ {\n    inv += bit.sum(A[i]);\n    bit.add(A[i], 1);\n    total++;\n  };\n  auto\
    \ addr = [&](int i) {\n    inv += total - bit.sum(A[i] + 1);\n    bit.add(A[i],\
    \ 1);\n    total++;\n  };\n  auto erasel = [&](int i) {\n    inv -= bit.sum(A[i]);\n\
    \    bit.add(A[i], -1);\n    total--;\n  };\n  auto eraser = [&](int i) {\n  \
    \  inv -= total - bit.sum(A[i] + 1);\n    bit.add(A[i], -1);\n    total--;\n \
    \ };\n  long long ans[Q];\n  auto out = [&](int q) { ans[q] = inv; };\n  mo.run(addl,\
    \ addr, erasel, eraser, out);\n  for (int q = 0; q < Q; q++) cout << ans[q] <<\
    \ \"\\n\";\n  cout << flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <bits/stdc++.h>\n#include \"src/Algorithm/Mo.hpp\"\n#include \"src/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  int A[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> A[i];\n  vector<int> v(A, A + N);\n  sort(v.begin(), v.end());\n  v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n  for (int i = 0; i < N; i++)\n    A[i] = lower_bound(v.begin(),\
    \ v.end(), A[i]) - v.begin();\n  Mo mo(N);\n  for (int q = 0; q < Q; q++) {\n\
    \    int l, r;\n    cin >> l >> r;\n    mo.query(l, r);\n  }\n  BinaryIndexedTree<long\
    \ long> bit(N + 1);\n  long long inv = 0, total = 0;\n  auto addl = [&](int i)\
    \ {\n    inv += bit.sum(A[i]);\n    bit.add(A[i], 1);\n    total++;\n  };\n  auto\
    \ addr = [&](int i) {\n    inv += total - bit.sum(A[i] + 1);\n    bit.add(A[i],\
    \ 1);\n    total++;\n  };\n  auto erasel = [&](int i) {\n    inv -= bit.sum(A[i]);\n\
    \    bit.add(A[i], -1);\n    total--;\n  };\n  auto eraser = [&](int i) {\n  \
    \  inv -= total - bit.sum(A[i] + 1);\n    bit.add(A[i], -1);\n    total--;\n \
    \ };\n  long long ans[Q];\n  auto out = [&](int q) { ans[q] = inv; };\n  mo.run(addl,\
    \ addr, erasel, eraser, out);\n  for (int q = 0; q < Q; q++) cout << ans[q] <<\
    \ \"\\n\";\n  cout << flush;\n  return 0;\n}"
  dependsOn:
  - src/Algorithm/Mo.hpp
  - src/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.mo.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 15:26:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.mo.test.cpp
- /verify/test/yosupo/static_range_inversions_query.mo.test.cpp.html
title: test/yosupo/static_range_inversions_query.mo.test.cpp
---
