---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':x:'
    path: src/Graph/IncrementalBridgeConnectivity.hpp
    title: "Incremental-Bridge-Connectivity (\u4E8C\u8FBA\u9023\u7D50\u6210\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\
    \n#include <iostream>\n#include <vector>\n#include <array>\n#include <algorithm>\n\
    #line 2 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\n#include <unordered_set>\n\
    #line 4 \"src/DataStructure/UnionFind.hpp\"\n#include <cassert>\ntemplate <bool\
    \ undoable= false> class UnionFind {\n std::vector<int> par;\n std::vector<std::pair<int,\
    \ int>> his;\npublic:\n UnionFind(int n): par(n, -1) {}\n bool unite(int u, int\
    \ v) {\n  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v])\
    \ std::swap(u, v);\n  if constexpr (undoable) his.emplace_back(v, par[v]);\n \
    \ return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u, int v) { return\
    \ root(u) == root(v); }\n int root(int u) {\n  if constexpr (undoable) return\
    \ par[u] < 0 ? u : root(par[u]);\n  else return par[u] < 0 ? u : par[u]= root(par[u]);\n\
    \ }\n int size(int u) { return -par[root(u)]; }\n int time() const {\n  static_assert(undoable,\
    \ \"\\'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n\
    \  static_assert(undoable, \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n\
    \  his.pop_back(), par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n\
    \  static_assert(undoable, \"\\'rollback\\' is not enabled\");\n  assert(t <=\
    \ his.size());\n  while (his.size() > t) undo();\n }\n};\n#line 4 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\
    \nclass IncrementalBridgeConnectivity {\n UnionFind cc, bcc;\n std::vector<int>\
    \ bbf;\n inline int parent(int v) { return bbf[v] < 0 ? -1 : bcc.root(bbf[v]);\
    \ }\n int lca(int u, int v) {\n  for (std::unordered_set<int> reached;; std::swap(u,\
    \ v))\n   if (u != -1) {\n    if (!reached.insert(u).second) return u;\n    u=\
    \ parent(u);\n   }\n }\n void condense_path(int u, int v) {\n  for (int n; !bcc.same(u,\
    \ v);) n= parent(u), bbf[u]= bbf[v], bcc.unite(u, v), u= n;\n }\npublic:\n IncrementalBridgeConnectivity(int\
    \ n): cc(n), bcc(n), bbf(n, -1) {}\n int represent(int v) { return bcc.root(v);\
    \ }\n bool two_edge_connected(int u, int v) { return bcc.same(u, v); }\n bool\
    \ connected(int u, int v) { return cc.same(u, v); }\n void add_edge(int u, int\
    \ v) {\n  if (int w; cc.same(u= bcc.root(u), v= bcc.root(v))) w= lca(u, v), condense_path(u,\
    \ w), condense_path(v, w);\n  else {\n   if (cc.size(u) > cc.size(v)) std::swap(u,\
    \ v);\n   for (cc.unite(u, v); u != -1;) w= parent(u), bbf[u]= v, v= u, u= w;\n\
    \  }\n }\n};\n#line 7 \"test/aoj/GRL_3_B.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int V, E;\n cin >> V >>\
    \ E;\n IncrementalBridgeConnectivity ibc(V);\n int s[E], t[E];\n for (int i= 0;\
    \ i < E; ++i) {\n  cin >> s[i] >> t[i];\n  ibc.add_edge(s[i], t[i]);\n }\n vector<array<int,\
    \ 2>> ans;\n for (int i= 0; i < E; ++i)\n  if (ibc.connected(s[i], t[i]) && !ibc.two_edge_connected(s[i],\
    \ t[i])) {\n   auto [a, b]= minmax(s[i], t[i]);\n   ans.push_back({a, b});\n \
    \ }\n sort(ans.begin(), ans.end());\n for (auto [a, b]: ans) cout << a << \" \"\
    \ << b << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B\"\
    \n#include <iostream>\n#include <vector>\n#include <array>\n#include <algorithm>\n\
    #include \"src/Graph/IncrementalBridgeConnectivity.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int V, E;\n cin >>\
    \ V >> E;\n IncrementalBridgeConnectivity ibc(V);\n int s[E], t[E];\n for (int\
    \ i= 0; i < E; ++i) {\n  cin >> s[i] >> t[i];\n  ibc.add_edge(s[i], t[i]);\n }\n\
    \ vector<array<int, 2>> ans;\n for (int i= 0; i < E; ++i)\n  if (ibc.connected(s[i],\
    \ t[i]) && !ibc.two_edge_connected(s[i], t[i])) {\n   auto [a, b]= minmax(s[i],\
    \ t[i]);\n   ans.push_back({a, b});\n  }\n sort(ans.begin(), ans.end());\n for\
    \ (auto [a, b]: ans) cout << a << \" \" << b << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/IncrementalBridgeConnectivity.hpp
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 10:13:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
