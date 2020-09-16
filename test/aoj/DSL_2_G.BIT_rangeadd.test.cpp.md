---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.BIT_rangeadd.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n/**\n * @title Binary-Indexed-Tree(\u533A\
    \u9593\u52A0\u7B97)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n\
    \ * 0-indexed\n */\n\n#ifndef call_from_test\n#line 10 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <typename T>\nstruct BinaryIndexedTree_RangeAdd\
    \ {\n  vector<T> dat1;\n  vector<T> dat2;\n  BinaryIndexedTree_RangeAdd(int n)\
    \ : dat1(n + 1, 0), dat2(n + 1, 0) {}\n  void add_range(int l, int r, T w) { \
    \ // add w [l,r)\n    for (int k = l + 1; k < (int)dat1.size(); k += k & -k) dat1[k]\
    \ -= w * l;\n    for (int k = r + 1; k < (int)dat1.size(); k += k & -k) dat1[k]\
    \ += w * r;\n    for (int k = l + 1; k < (int)dat2.size(); k += k & -k) dat2[k]\
    \ += w;\n    for (int k = r + 1; k < (int)dat2.size(); k += k & -k) dat2[k] -=\
    \ w;\n  }\n  T sum(int x) {  // sum [0,x)\n    T s = 0;\n    for (int k = x; k\
    \ > 0; k &= k - 1) s += dat1[k];\n    for (int k = x; k > 0; k &= k - 1) s +=\
    \ dat2[k] * x;\n    return s;\n  }\n  // sum [l,r)\n  T sum(int l, int r) { return\
    \ sum(r) - sum(l); }\n  T operator[](size_t k) { return sum(k + 1) - sum(k); }\n\
    };\n#line 9 \"test/aoj/DSL_2_G.BIT_rangeadd.test.cpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  BinaryIndexedTree_RangeAdd<long long> bit(N);\n  while (Q--) {\n\
    \    int op, s, t;\n    cin >> op >> s >> t;\n    s--, t--;\n    if (op)\n   \
    \   cout << bit.sum(t + 1) - bit.sum(s) << endl;\n    else {\n      long long\
    \ x;\n      cin >> x;\n      bit.add_range(s, t + 1, x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  BinaryIndexedTree_RangeAdd<long long> bit(N);\n  while (Q--) {\n\
    \    int op, s, t;\n    cin >> op >> s >> t;\n    s--, t--;\n    if (op)\n   \
    \   cout << bit.sum(t + 1) - bit.sum(s) << endl;\n    else {\n      long long\
    \ x;\n      cin >> x;\n      bit.add_range(s, t + 1, x);\n    }\n  }\n}\n"
  dependsOn:
  - src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
- /verify/test/aoj/DSL_2_G.BIT_rangeadd.test.cpp.html
title: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
---
