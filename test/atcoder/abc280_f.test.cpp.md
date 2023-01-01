---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind_Potential.hpp
    title: "Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc280/tasks/abc280_f
    links:
    - https://atcoder.jp/contests/abc280/tasks/abc280_f
  bundledCode: "#line 1 \"test/atcoder/abc280_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/UnionFind_Potential.hpp\"\
    \n/**\n * @title Union-Find(\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB)\n * @category\
    \ \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief \u5404\u30CE\u30FC\u30C9\u306B\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u3082\u305F\u305B\u3001\u305D\u306E\u5DEE\
    \u3092\u6C42\u3081\u3089\u308C\u308B\n * @brief O(\u03B1(N))\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename Weight>\nstruct UnionFind_Potential {\n  std::vector<int>\
    \ par;\n  std::vector<Weight> val;\n  UnionFind_Potential(int size) : par(size,\
    \ -1), val(size, 0) {}\n  bool unite(int v, int u, Weight w) {\n    w += potential(u)\
    \ - potential(v);\n    if ((u = root(u)) == (v = root(v))) return false;\n   \
    \ if (par[u] > par[v]) std::swap(u, v), w = -w;\n    par[u] += par[v], par[v]\
    \ = u, val[v] = w;\n    return true;\n  }\n  bool same(int u, int v) { return\
    \ root(u) == root(v); }\n  int root(int u) {\n    if (par[u] < 0) return u;\n\
    \    int r = root(par[u]);\n    val[u] += val[par[u]];\n    return par[u] = r;\n\
    \  }\n  int size(int u) { return -par[root(u)]; }\n  Weight potential(int u) {\n\
    \    root(u);\n    return val[u];\n  }\n  Weight diff(int u, int v) { return potential(u)\
    \ - potential(v); }\n};\n#line 4 \"test/atcoder/abc280_f.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N,\
    \ M, Q;\n  cin >> N >> M >> Q;\n  UnionFind_Potential<long long> uf(N);\n  vector<bool>\
    \ isinf(N, false);\n  for (int i = 0; i < M; i++) {\n    int A, B;\n    cin >>\
    \ A >> B, A--, B--;\n    long long C;\n    cin >> C;\n    if (uf.same(A, B)) {\n\
    \      if (uf.diff(A, B) != C) isinf[A] = true, isinf[B] = true;\n    } else {\n\
    \      uf.unite(A, B, C);\n    }\n  }\n  for (int i = 0; i < N; i++)\n    if (isinf[i])\
    \ isinf[uf.root(i)] = true;\n  while (Q--) {\n    int X, Y;\n    cin >> X >> Y,\
    \ X--, Y--;\n    if (!uf.same(X, Y)) {\n      cout << \"nan\" << '\\n';\n    }\
    \ else if (isinf[uf.root(X)]) {\n      cout << \"inf\" << '\\n';\n    } else {\n\
    \      cout << uf.diff(X, Y) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/DataStructure/UnionFind_Potential.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, M, Q;\n  cin >> N >> M >> Q;\n  UnionFind_Potential<long long> uf(N);\n\
    \  vector<bool> isinf(N, false);\n  for (int i = 0; i < M; i++) {\n    int A,\
    \ B;\n    cin >> A >> B, A--, B--;\n    long long C;\n    cin >> C;\n    if (uf.same(A,\
    \ B)) {\n      if (uf.diff(A, B) != C) isinf[A] = true, isinf[B] = true;\n   \
    \ } else {\n      uf.unite(A, B, C);\n    }\n  }\n  for (int i = 0; i < N; i++)\n\
    \    if (isinf[i]) isinf[uf.root(i)] = true;\n  while (Q--) {\n    int X, Y;\n\
    \    cin >> X >> Y, X--, Y--;\n    if (!uf.same(X, Y)) {\n      cout << \"nan\"\
    \ << '\\n';\n    } else if (isinf[uf.root(X)]) {\n      cout << \"inf\" << '\\\
    n';\n    } else {\n      cout << uf.diff(X, Y) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind_Potential.hpp
  isVerificationFile: true
  path: test/atcoder/abc280_f.test.cpp
  requiredBy: []
  timestamp: '2022-12-11 16:43:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc280_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc280_f.test.cpp
- /verify/test/atcoder/abc280_f.test.cpp.html
title: test/atcoder/abc280_f.test.cpp
---