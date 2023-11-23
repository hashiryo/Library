---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Misc/CartesianTree.hpp
    title: Cartesian-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/yosupo/cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"src/Misc/CartesianTree.hpp\"\n#include <array>\nclass CartesianTree\
    \ {\n std::vector<std::array<int, 2>> rg, ch;\n std::vector<int> par;\n int rt;\n\
    public:\n template <class Vec> CartesianTree(const Vec &a, bool is_min= 1): rg(a.size()),\
    \ ch(a.size(), std::array{-1, -1}), par(a.size(), -1) {\n  const int n= a.size();\n\
    \  auto comp= [&](int l, int r) { return (is_min ? a[l] < a[r] : a[l] > a[r])\
    \ || (a[l] == a[r] && l < r); };\n  int st[n], t= 0;\n  for (int i= n; i--; rg[i][1]=\
    \ (t ? st[t - 1] : n), st[t++]= i)\n   while (t && comp(i, st[t - 1])) ch[i][1]=\
    \ st[--t];\n  for (int i= t= 0; i < n; rg[i][0]= (t ? st[t - 1] + 1 : 0), st[t++]=\
    \ i++)\n   while (t && comp(i, st[t - 1])) ch[i][0]= st[--t];\n  for (int i= 0;\
    \ i < n; ++i)\n   for (int b= 2; b--;)\n    if (ch[i][b] != -1) par[ch[i][b]]=\
    \ i;\n  for (int i= 0; i < n; ++i)\n   if (par[i] == -1) rt= i;\n }\n std::array<int,\
    \ 2> children(int i) const { return ch[i]; }\n int parent(int i) const { return\
    \ par[i]; }\n int root() const { return rt; }\n // [l,r)\n std::array<int, 2>\
    \ range(int i) const { return rg[i]; }\n};\n#line 5 \"test/yosupo/cartesian_tree.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n vector<int> a(N);\n for (int i= 0; i < N; ++i) cin >> a[i];\n\
    \ CartesianTree ct(a);\n for (int i= 0; i < N; ++i) cout << (ct.parent(i) == -1\
    \ ? i : ct.parent(i)) << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Misc/CartesianTree.hpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N;\n cin >> N;\n vector<int> a(N);\n for (int i= 0; i < N; ++i) cin >> a[i];\n\
    \ CartesianTree ct(a);\n for (int i= 0; i < N; ++i) cout << (ct.parent(i) == -1\
    \ ? i : ct.parent(i)) << \" \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn:
  - src/Misc/CartesianTree.hpp
  isVerificationFile: true
  path: test/yosupo/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 00:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cartesian_tree.test.cpp
- /verify/test/yosupo/cartesian_tree.test.cpp.html
title: test/yosupo/cartesian_tree.test.cpp
---
