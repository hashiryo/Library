---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SparseTable.hpp
    title: "Sparse-Table(\u533A\u9593min)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.sparsetable.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/DataStructure/SparseTable.hpp\"\
    \n#include <bits/stdc++.h>\n/**\n * @title Sparse-Table(\u533A\u9593min)\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief RmQ\n * @brief \u69CB\u7BC9 O(n log\
    \ n)\n * @brief query O(1)\n */\n\n// BEGIN CUT HERE\n\ntemplate <class T>\nstruct\
    \ SparseTable {\n  const std::vector<T> &x;\n  std::vector<std::vector<int>> table;\n\
    \  int argmin(int i, int j) { return x[i] < x[j] ? i : j; }\n  SparseTable(const\
    \ std::vector<T> &x) : x(x) {\n    int logn = sizeof(int) * __CHAR_BIT__ - 1 -\
    \ __builtin_clz(x.size());\n    table.assign(logn + 1, std::vector<int>(x.size()));\n\
    \    iota(table[0].begin(), table[0].end(), 0);\n    for (int h = 0; h + 1 <=\
    \ logn; ++h)\n      for (int i = 0; i + (1 << h) < x.size(); ++i)\n        table[h\
    \ + 1][i] = argmin(table[h][i], table[h][i + (1 << h)]);\n  }\n  T range_min(int\
    \ i, int j) {  // = min x[i,j)\n    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(j\
    \ - i);  // = log2\n    return x[argmin(table[h][i], table[h][j - (1 << h)])];\n\
    \  }\n};\n#line 5 \"test/aoj/DSL_3_D.sparsetable.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, L;\n cin >>\
    \ N >> L;\n vector<int> a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n SparseTable<int>\
    \ st(a);\n for (int i= 0; i + L <= N; i++) {\n  cout << (i ? \" \" : \"\") <<\
    \ st.range_min(i, i + L);\n }\n cout << endl;\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/DataStructure/SparseTable.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, L;\n cin >> N >> L;\n vector<int> a(N);\n for (int i= 0; i < N; i++)\
    \ cin >> a[i];\n SparseTable<int> st(a);\n for (int i= 0; i + L <= N; i++) {\n\
    \  cout << (i ? \" \" : \"\") << st.range_min(i, i + L);\n }\n cout << endl;\n\
    \ return 0;\n}"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.sparsetable.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 18:57:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.sparsetable.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html
title: test/aoj/DSL_3_D.sparsetable.test.cpp
---
