---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SparseTable.hpp
    title: Sparse-Table
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
    \ <iostream>\n#include <vector>\n#line 3 \"src/DataStructure/SparseTable.hpp\"\
    \ntemplate <class T, class F> class SparseTable {\n std::vector<std::vector<T>>\
    \ dat;\n F f;\npublic:\n SparseTable() {}\n SparseTable(const std::vector<T> &v,\
    \ const F &f): f(f) {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n -\
    \ 1) : 0;\n  dat.resize(log + 1), dat[0].assign(v.begin(), v.end());\n  for (int\
    \ i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size()\
    \ - I); j--;) dat[i + 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T\
    \ fold(int l, int r) const {\n  if (r == l + 1) return dat[0][l];\n  int k= 31\
    \ - __builtin_clz(r - l - 1);\n  return f(dat[k][l], dat[k][r - (1 << k)]);\n\
    \ }\n};\n#line 5 \"test/aoj/DSL_3_D.sparsetable.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, L;\n cin >>\
    \ N >> L;\n vector<int> a(N);\n for (int i= 0; i < N; i++) cin >> a[i];\n SparseTable\
    \ st(a, [](int l, int r) { return min(l, r); });\n for (int i= 0; i + L <= N;\
    \ i++) cout << st.fold(i, i + L) << \" \\n\"[i + L == N];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/DataStructure/SparseTable.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, L;\n cin >> N >> L;\n vector<int> a(N);\n for (int i= 0; i < N; i++)\
    \ cin >> a[i];\n SparseTable st(a, [](int l, int r) { return min(l, r); });\n\
    \ for (int i= 0; i + L <= N; i++) cout << st.fold(i, i + L) << \" \\n\"[i + L\
    \ == N];\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.sparsetable.test.cpp
  requiredBy: []
  timestamp: '2023-11-17 21:21:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.sparsetable.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp
- /verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html
title: test/aoj/DSL_3_D.sparsetable.test.cpp
---
