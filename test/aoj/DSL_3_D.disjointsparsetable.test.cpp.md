---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/DisjointSparseTable.hpp
    title: Disjoint-Sparse-Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.disjointsparsetable.test.cpp\"\n#define\
    \ PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/DataStructure/DisjointSparseTable.hpp\"\n/**\n * @title Disjoint-Sparse-Table\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief f\u306F\u7D50\u5408\u5247\
    \u3092\u307F\u305F\u3059\u4E8C\u9805\u6F14\u7B97\n * @brief \u69CB\u7BC9 O(n log\
    \ n)\n * @brief query O(1)\n */\n\n#ifndef call_from_test\n#line 11 \"src/DataStructure/DisjointSparseTable.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <class T>\nstruct DisjointSparseTable\
    \ {\n  vector<vector<T>> ys;\n  using F = function<T(T, T)>;\n  const F f;\n \
    \ DisjointSparseTable(vector<T> xs, F f_) : f(f_) {\n    int n = 1;\n    while\
    \ (n <= xs.size()) n *= 2;\n    xs.resize(n);\n    ys.push_back(xs);\n    for\
    \ (int h = 1;; ++h) {\n      int range = (2 << h), half = range / 2;\n      if\
    \ (range > n) break;\n      ys.push_back(xs);\n      for (int i = half; i < n;\
    \ i += range) {\n        for (int j = i - 2; j >= i - half; --j)\n          ys[h][j]\
    \ = f(ys[h][j], ys[h][j + 1]);\n        for (int j = i + 1; j < min(n, i + half);\
    \ ++j)\n          ys[h][j] = f(ys[h][j - 1], ys[h][j]);\n      }\n    }\n  }\n\
    \  T query(int i, int j) {  // [i, j)\n    if (i == --j) return ys[0][i];\n  \
    \  int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(i ^ j);\n    return\
    \ f(ys[h][i], ys[h][j]);\n  }\n};\n#line 9 \"test/aoj/DSL_3_D.disjointsparsetable.test.cpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, L;\n  cin >> N >> L;\n  vector<int> a(N);\n  for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n  auto f = [](int a, int b) { return min(a, b); };\n  DisjointSparseTable<int>\
    \ dst(a, f);\n  for (int i = 0; i + L <= N; i++) {\n    if (i) cout << \" \";\n\
    \    cout << dst.query(i, i + L);\n  }\n  cout << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/DataStructure/DisjointSparseTable.hpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, L;\n  cin\
    \ >> N >> L;\n  vector<int> a(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n\
    \  auto f = [](int a, int b) { return min(a, b); };\n  DisjointSparseTable<int>\
    \ dst(a, f);\n  for (int i = 0; i + L <= N; i++) {\n    if (i) cout << \" \";\n\
    \    cout << dst.query(i, i + L);\n  }\n  cout << endl;\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/DisjointSparseTable.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp
- /verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html
title: test/aoj/DSL_3_D.disjointsparsetable.test.cpp
---
