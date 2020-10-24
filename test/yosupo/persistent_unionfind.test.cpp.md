---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':x:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/DataStructure/PersistentArray.hpp\"\n/**\n * @title \u6C38\u7D9A\
    \u914D\u5217\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n */\n\n// BEGIN CUT\
    \ HERE\n\ntemplate <typename T, int LOG = 3>\nstruct PersistentArray {\n  struct\
    \ Node {\n    T data;\n    Node *child[1 << LOG] = {};\n    Node() {}\n  };\n\n\
    \ private:\n  Node *root;\n\n public:\n  PersistentArray() : root(nullptr) {}\n\
    \  PersistentArray(size_t n, const T &v = T()) { build(std::vector<T>(n, v));\
    \ }\n  PersistentArray(const std::vector<T> &v) { build(v); }\n  const T get(const\
    \ int &k) const { return get(root, k); }\n  T &operator[](const int &k) { return\
    \ reference_get(k, false); }\n  void build(const std::vector<T> &v) {\n    root\
    \ = nullptr;\n    for (int i = 0; i < v.size(); i++) reference_get(i, true) =\
    \ v[i];\n  }\n\n private:\n  T get(Node *t, int k) const {\n    if (!t) return\
    \ T();\n    if (k == 0) return t->data;\n    return get(t->child[k & ((1 << LOG)\
    \ - 1)], k >> LOG);\n  }\n  pair<Node *, T &> reference_get(Node *t, int k, bool\
    \ destruct = false) {\n    t = t ? (destruct ? t : new Node(*t)) : new Node();\n\
    \    if (k == 0) return {t, t->data};\n    auto p = reference_get(t->child[k &\
    \ ((1 << LOG) - 1)], k >> LOG, destruct);\n    t->child[k & ((1 << LOG) - 1)]\
    \ = p.first;\n    return {t, p.second};\n  }\n  T &reference_get(const int &k,\
    \ bool destruct = false) {\n    auto ret = reference_get(root, k, destruct);\n\
    \    root = ret.first;\n    return ret.second;\n  }\n};\n#line 4 \"src/DataStructure/UnionFind_Persistent.hpp\"\
    \n/**\n * @title Union-Find(\u5B8C\u5168\u6C38\u7D9A)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057 O(logN)\n */\n// verify\u7528\
    :\n// https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h\n\
    \n// BEGIN CUT HERE\n\nstruct UnionFind_Persistent {\n  PersistentArray<int> par;\n\
    \  UnionFind_Persistent() {}\n  UnionFind_Persistent(int n) : par(n, -1) {}\n\
    \  bool unite(int u, int v) {\n    if ((u = root(u)) == (v = root(v))) return\
    \ false;\n    if (par.get(u) > par.get(v)) std::swap(u, v);\n    par[u] += par.get(v),\
    \ par[v] = u;\n    return true;\n  }\n  bool same(int u, int v) { return root(u)\
    \ == root(v); }\n  int root(int u) { return par.get(u) < 0 ? u : root(par.get(u));\
    \ }\n  int size(int u) { return -par.get(root(u)); }\n};\n#line 5 \"test/yosupo/persistent_unionfind.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<UnionFind_Persistent> uf(Q + 1);\n  uf[0]\
    \ = UnionFind_Persistent(N);\n  for (int i = 1; i <= Q; i++) {\n    int t, k,\
    \ u, v;\n    cin >> t >> k >> u >> v;\n    k++;\n    if (t) {\n      cout << uf[k].same(u,\
    \ v) << endl;\n    } else {\n      uf[i] = uf[k];\n      uf[i].unite(u, v);\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <bits/stdc++.h>\n#include \"src/DataStructure/PersistentArray.hpp\"\n\
    #include \"src/DataStructure/UnionFind_Persistent.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  vector<UnionFind_Persistent> uf(Q + 1);\n  uf[0] = UnionFind_Persistent(N);\n\
    \  for (int i = 1; i <= Q; i++) {\n    int t, k, u, v;\n    cin >> t >> k >> u\
    \ >> v;\n    k++;\n    if (t) {\n      cout << uf[k].same(u, v) << endl;\n   \
    \ } else {\n      uf[i] = uf[k];\n      uf[i].unite(u, v);\n    }\n  }\n}\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  - src/DataStructure/UnionFind_Persistent.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 12:39:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
