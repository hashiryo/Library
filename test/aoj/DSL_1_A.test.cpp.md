---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/UnionFind.hpp\"\n/**\n\
    \ * @title Union-Find\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ unite(x,y) x \u304C\u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3068 y \u304C\
    \u5165\u3063\u3066\u3044\u308B\u96C6\u5408\u3092\u4F75\u5408\u3059\u308B\uFF0E\
    \n * @brief same(x,y) x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5165\u3063\
    \u3066\u3044\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\uFF0E\
    \n * @brief O(\u03B1(N))\n */\n\n// BEGIN CUT HERE\n\nstruct UnionFind {\n  std::vector<int>\
    \ par;\n  UnionFind(int size) : par(size, -1) {}\n  bool unite(int u, int v) {\n\
    \    if ((u = root(u)) == (v = root(v))) return false;\n    if (par[u] > par[v])\
    \ std::swap(u, v);\n    par[u] += par[v], par[v] = u;\n    return true;\n  }\n\
    \  bool same(int u, int v) { return root(u) == root(v); }\n  int root(int u) {\
    \ return par[u] < 0 ? u : par[u] = root(par[u]); }\n  int size(int u) { return\
    \ -par[root(u)]; }\n};\n#line 5 \"test/aoj/DSL_1_A.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int\
    \ n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  for (int i = 0; i < q; i++) {\n\
    \    int c, x, y;\n    cin >> c >> x >> y;\n    if (c)\n      cout << uf.same(x,\
    \ y) << \"\\n\";\n    else\n      uf.unite(x, y);\n  }\n  cout << flush;\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  for (int i = 0; i < q;\
    \ i++) {\n    int c, x, y;\n    cin >> c >> x >> y;\n    if (c)\n      cout <<\
    \ uf.same(x, y) << \"\\n\";\n    else\n      uf.unite(x, y);\n  }\n  cout << flush;\n\
    \  return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 12:39:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
