---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/BinaryIndexedTree.hpp
    title: Binary-Indexed-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.BIT.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <iostream>\n\
    #line 2 \"src/DataStructure/BinaryIndexedTree.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\ntemplate <typename T> class BinaryIndexedTree {\n std::vector<T> dat;\n\
    public:\n BinaryIndexedTree(int n): dat(n + 1, T()) {}\n BinaryIndexedTree(int\
    \ n, T a): BinaryIndexedTree(std::vector<T>(n, a)) {}\n BinaryIndexedTree(const\
    \ std::vector<T>& y): dat(y.size() + 1, 0) {\n  for (int i= y.size(); i--;) dat[i\
    \ + 1]= y[i];\n  for (int i= 1, e= dat.size(), j; i < e; ++i)\n   if ((j= i +\
    \ (i & -i)) < e) dat[j]+= dat[i];\n }\n void add(int i, T a= 1) {\n  for (++i;\
    \ i < (int)dat.size(); i+= i & -i) dat[i]+= a;\n }\n T sum(int i) const {  //\
    \ sum [0,i)\n  T s= 0;\n  for (; i; i&= i - 1) s+= dat[i];\n  return s;\n }\n\
    \ T sum(int l, int r) const { return sum(r) - sum(l); }  // sum [l,r)\n T operator[](int\
    \ k) const { return sum(k + 1) - sum(k); }\n int find(T k) const {  // min { i\
    \ : sum(i+1) > k } -> kth element(0-indexed)\n  int i= 0;\n  for (int p= 1 <<\
    \ (std::__lg(dat.size() - 1) + 1), e= dat.size(); p; p>>= 1)\n   if (i + p < e\
    \ && dat[i + p] <= k) k-= dat[i+= p];\n  return i + 1 == (int)dat.size() ? -1\
    \ : i;  // -1 -> no solutions\n }\n};\n#line 4 \"test/yosupo/point_add_range_sum.BIT.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n BinaryIndexedTree<long long> bit(N);\n for (int\
    \ i= 0; i < N; i++) {\n  long long a;\n  cin >> a;\n  bit.add(i, a);\n }\n while\
    \ (Q--) {\n  int t, a, b;\n  cin >> t >> a >> b;\n  if (t) cout << bit.sum(a,\
    \ b) << '\\n';\n  else bit.add(a, b);\n }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"src/DataStructure/BinaryIndexedTree.hpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N, Q;\n cin >> N >> Q;\n BinaryIndexedTree<long long> bit(N);\n for (int i=\
    \ 0; i < N; i++) {\n  long long a;\n  cin >> a;\n  bit.add(i, a);\n }\n while\
    \ (Q--) {\n  int t, a, b;\n  cin >> t >> a >> b;\n  if (t) cout << bit.sum(a,\
    \ b) << '\\n';\n  else bit.add(a, b);\n }\n}\n"
  dependsOn:
  - src/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.BIT.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 16:53:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.BIT.test.cpp
- /verify/test/yosupo/point_add_range_sum.BIT.test.cpp.html
title: test/yosupo/point_add_range_sum.BIT.test.cpp
---
