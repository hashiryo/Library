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
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/yosupo/static_range_frequency.WM.test copy.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n#include\
    \ <iostream>\n#include <vector>\n#line 3 \"src/DataStructure/SparseTable.hpp\"\
    \ntemplate <class T, class F> struct SparseTable {\n std::vector<std::vector<T>>\
    \ dat;\n const F &f;\n SparseTable(const std::vector<T> &v, const F &f): f(f)\
    \ {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n - 1) : 0;\n  dat.resize(log\
    \ + 1), dat[0].assign(v.begin(), v.end());\n  for (int i= 0, I= 1, j; i < log;\
    \ ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size() - I); j--;) dat[i +\
    \ 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T fold(int l, int r) {\n\
    \  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r - l - 1);\n\
    \  return f(dat[k][l], dat[k][r - (1 << k)]);\n }\n};\n#line 5 \"test/yosupo/static_range_frequency.WM.test\
    \ copy.cpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n vector<int> a(N);\n for (int i= 0; i < N; ++i)\
    \ cin >> a[i];\n SparseTable st(a, [](int l, int r) { return min(l, r); });\n\
    \ while (Q--) {\n  int l, r;\n  cin >> l >> r;\n  cout << st.fold(l, r) << '\\\
    n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/DataStructure/SparseTable.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n vector<int> a(N);\n for (int i= 0; i < N; ++i)\
    \ cin >> a[i];\n SparseTable st(a, [](int l, int r) { return min(l, r); });\n\
    \ while (Q--) {\n  int l, r;\n  cin >> l >> r;\n  cout << st.fold(l, r) << '\\\
    n';\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  isVerificationFile: false
  path: test/yosupo/static_range_frequency.WM.test copy.cpp
  requiredBy: []
  timestamp: '2023-11-16 23:12:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/static_range_frequency.WM.test copy.cpp
layout: document
redirect_from:
- /library/test/yosupo/static_range_frequency.WM.test copy.cpp
- /library/test/yosupo/static_range_frequency.WM.test copy.cpp.html
title: test/yosupo/static_range_frequency.WM.test copy.cpp
---
