---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\n#include <iostream>\n\
    #include <algorithm>\n#include <numeric>\n#line 2 \"src/DataStructure/UnionFind.hpp\"\
    \n#include <vector>\n#line 4 \"src/DataStructure/UnionFind.hpp\"\nclass UnionFind\
    \ {\n std::vector<int> par;\npublic:\n UnionFind(int n): par(n, -1) {}\n bool\
    \ unite(int u, int v) {\n  if ((u= root(u)) == (v= root(v))) return false;\n \
    \ if (par[u] > par[v]) std::swap(u, v);\n  return par[u]+= par[v], par[v]= u,\
    \ true;\n }\n bool same(int u, int v) { return root(u) == root(v); }\n int root(int\
    \ u) { return par[u] < 0 ? u : par[u]= root(par[u]); }\n int size(int u) { return\
    \ -par[root(u)]; }\n};\n#line 6 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N,\
    \ M;\n cin >> N >> M;\n UnionFind uf(N);\n int s[N], t[N];\n long long w[N];\n\
    \ for (int i= 0; i < M; i++) cin >> s[i] >> t[i] >> w[i];\n long long ans= 0;\n\
    \ int ord[N];\n iota(ord, ord + N, 0), sort(ord, ord + N, [&](int l, int r) {\
    \ return w[l] < w[r]; });\n for (int i: ord)\n  if (uf.unite(s[i], t[i])) ans+=\
    \ w[i];\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n#include <iostream>\n#include <algorithm>\n#include <numeric>\n#include \"src/DataStructure/UnionFind.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, M;\n cin >> N >> M;\n UnionFind uf(N);\n int s[N], t[N];\n long long\
    \ w[N];\n for (int i= 0; i < M; i++) cin >> s[i] >> t[i] >> w[i];\n long long\
    \ ans= 0;\n int ord[N];\n iota(ord, ord + N, 0), sort(ord, ord + N, [&](int l,\
    \ int r) { return w[l] < w[r]; });\n for (int i: ord)\n  if (uf.unite(s[i], t[i]))\
    \ ans+= w[i];\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.kruskal.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 15:27:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp.html
title: test/aoj/GRL_2_A.kruskal.test.cpp
---
