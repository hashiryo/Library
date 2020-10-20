---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/BinaryIndexedTree.hpp
    title: Binary-Indexed-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.BIT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    src/DataStructure/BinaryIndexedTree.hpp\"\n/**\n * @title Binary-Indexed-Tree\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n *  O(logN)\n *  0-indexed\n */\n\
    \n#ifndef call_from_test\n#line 10 \"src/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <typename T>\nstruct BinaryIndexedTree\
    \ {\n  vector<T> dat;\n  BinaryIndexedTree(int n) : dat(n + 1, T(0)) {}\n  BinaryIndexedTree(int\
    \ n, T a) : BinaryIndexedTree(vector<T>(n, a)) {}\n  BinaryIndexedTree(vector<T>\
    \ y) : dat(y.size() + 1, 0) {\n    for (size_t i = 0; i < y.size(); ++i) dat[i\
    \ + 1] = y[i];\n    for (int i = 1; i < (int)dat.size(); ++i)\n      if (i + (i\
    \ & -i) < (int)dat.size()) dat[i + (i & -i)] += dat[i];\n  }\n  void add(int i,\
    \ T a = 1) {\n    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;\n \
    \ }\n  T sum(int i) {  // sum [0,i)\n    T s = 0;\n    for (; i > 0; i &= i -\
    \ 1) s += dat[i];\n    return s;\n  }\n  // sum [l,r)\n  T sum(int l, int r) {\
    \ return sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k + 1) - sum(k);\
    \ }\n  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n  int find(T k)\
    \ const {\n    int i = 0;\n    for (int p = 1 << (__lg(dat.size() - 1) + 1); p\
    \ > 0; p >>= 1)\n      if (i + p < (int)dat.size() && dat[i + p] <= k) k -= dat[i\
    \ += p];\n    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no solutions\n\
    \  }\n};\n#line 8 \"test/yosupo/point_add_range_sum.BIT.test.cpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  BinaryIndexedTree<long long> bit(N);\n  for (int i = 0; i < N;\
    \ i++) {\n    long long a;\n    cin >> a;\n    bit.add(i, a);\n  }\n  while (Q--)\
    \ {\n    int t, a, b;\n    cin >> t >> a >> b;\n    if (t)\n      cout << bit.sum(b)\
    \ - bit.sum(a) << endl;\n    else\n      bit.add(a, b);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/DataStructure/BinaryIndexedTree.hpp\"\n#undef call_from_test\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N\
    \ >> Q;\n  BinaryIndexedTree<long long> bit(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    long long a;\n    cin >> a;\n    bit.add(i, a);\n  }\n  while (Q--) {\n\
    \    int t, a, b;\n    cin >> t >> a >> b;\n    if (t)\n      cout << bit.sum(b)\
    \ - bit.sum(a) << endl;\n    else\n      bit.add(a, b);\n  }\n}\n"
  dependsOn:
  - src/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.BIT.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.BIT.test.cpp
- /verify/test/yosupo/point_add_range_sum.BIT.test.cpp.html
title: test/yosupo/point_add_range_sum.BIT.test.cpp
---
