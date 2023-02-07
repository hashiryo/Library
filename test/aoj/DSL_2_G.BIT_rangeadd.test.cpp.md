---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.BIT_rangeadd.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\n#include\
    \ <iostream>\n#line 2 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\n#include\
    \ <vector>\ntemplate <typename T> class BinaryIndexedTree_RangeAdd {\n std::vector<T>\
    \ dat1, dat2;\npublic:\n BinaryIndexedTree_RangeAdd(int n): dat1(n + 1, T()),\
    \ dat2(n + 1, T()) {}\n void add_range(int l, int r, T w) {  // add w [l,r)\n\
    \  int n= dat1.size();\n  for (int k= l + 1; k < n; k+= k & -k) dat1[k]-= w *\
    \ l;\n  for (int k= r + 1; k < n; k+= k & -k) dat1[k]+= w * r;\n  for (int k=\
    \ l + 1; k < n; k+= k & -k) dat2[k]+= w;\n  for (int k= r + 1; k < n; k+= k &\
    \ -k) dat2[k]-= w;\n }\n T sum(int x) const {  // sum [0,x)\n  T s= 0;\n  for\
    \ (int k= x; k; k&= k - 1) s+= dat1[k];\n  for (int k= x; k; k&= k - 1) s+= dat2[k]\
    \ * x;\n  return s;\n }\n T sum(int l, int r) const { return sum(r) - sum(l);\
    \ }  // sum [l,r)\n T operator[](size_t k) const { return sum(k + 1) - sum(k);\
    \ }\n};\n#line 4 \"test/aoj/DSL_2_G.BIT_rangeadd.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, Q;\n cin >>\
    \ N >> Q;\n BinaryIndexedTree_RangeAdd<long long> bit(N);\n while (Q--) {\n  int\
    \ op, s, t;\n  cin >> op >> s >> t;\n  --s;\n  if (op) cout << bit.sum(s, t) <<\
    \ '\\n';\n  else {\n   long long x;\n   cin >> x;\n   bit.add_range(s, t, x);\n\
    \  }\n }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n#include <iostream>\n#include \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n BinaryIndexedTree_RangeAdd<long long> bit(N);\n\
    \ while (Q--) {\n  int op, s, t;\n  cin >> op >> s >> t;\n  --s;\n  if (op) cout\
    \ << bit.sum(s, t) << '\\n';\n  else {\n   long long x;\n   cin >> x;\n   bit.add_range(s,\
    \ t, x);\n  }\n }\n}\n"
  dependsOn:
  - src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 16:53:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
- /verify/test/aoj/DSL_2_G.BIT_rangeadd.test.cpp.html
title: test/aoj/DSL_2_G.BIT_rangeadd.test.cpp
---
