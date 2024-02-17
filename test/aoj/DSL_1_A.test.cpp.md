---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <iostream>\n#line 2 \"src/DataStructure/UnionFind.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\ntemplate <bool undoable= false> class\
    \ UnionFind {\n std::vector<int> par;\n std::vector<std::pair<int, int>> his;\n\
    public:\n UnionFind(int n): par(n, -1) {}\n bool unite(int u, int v) {\n  if ((u=\
    \ root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v]) std::swap(u,\
    \ v);\n  if constexpr (undoable) his.emplace_back(v, par[v]);\n  return par[u]+=\
    \ par[v], par[v]= u, true;\n }\n bool same(int u, int v) { return root(u) == root(v);\
    \ }\n int root(int u) {\n  if constexpr (undoable) return par[u] < 0 ? u : root(par[u]);\n\
    \  else return par[u] < 0 ? u : par[u]= root(par[u]);\n }\n int size(int u) {\
    \ return -par[root(u)]; }\n int time() const {\n  static_assert(undoable, \"\\\
    'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n  static_assert(undoable,\
    \ \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n  his.pop_back(),\
    \ par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n  static_assert(undoable,\
    \ \"\\'rollback\\' is not enabled\");\n  assert(t <= his.size());\n  while (his.size()\
    \ > t) undo();\n }\n};\n#line 4 \"test/aoj/DSL_1_A.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n\
    \ cin >> n >> q;\n UnionFind uf(n);\n for (int i= 0; i < q; i++) {\n  int c, x,\
    \ y;\n  cin >> c >> x >> y;\n  if (c) cout << uf.same(x, y) << \"\\n\";\n  else\
    \ uf.unite(x, y);\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <iostream>\n#include \"src/DataStructure/UnionFind.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int n, q;\n\
    \ cin >> n >> q;\n UnionFind uf(n);\n for (int i= 0; i < q; i++) {\n  int c, x,\
    \ y;\n  cin >> c >> x >> y;\n  if (c) cout << uf.same(x, y) << \"\\n\";\n  else\
    \ uf.unite(x, y);\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 10:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
