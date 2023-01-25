---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#include <iostream>\n#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n\
    #include <vector>\n#include <array>\n#include <algorithm>\nclass StronglyConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj, rev;\npublic:\n StronglyConnectedComponents(int\
    \ n): adj(n), rev(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst),\
    \ rev[dst].push_back(src); }\n std::vector<std::vector<int>> get_block() const\
    \ {\n  const int n= adj.size();\n  std::vector<std::vector<int>> blk;\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(n, 0);\n  int k= n;\n  for (int s= 0; s < n; ++s)\n\
    \   if (par[s] == -2) {\n    par[s]= -1;\n    for (int p= s; p >= 0;) {\n    \
    \ if (dat[p] == (int)adj[p].size()) {\n      ord[--k]= p, p= par[p];\n      continue;\n\
    \     }\n     if (int q= adj[p][dat[p]++]; par[q] == -2) par[q]= p, p= q;\n  \
    \  }\n   }\n  dat.assign(n, 1);\n  for (int s: ord)\n   if (dat[s]) {\n    blk.resize(++k),\
    \ dat[s]= 0, blk.back().push_back(s);\n    for (int i= 0; i < (int)blk.back().size();\
    \ ++i)\n     for (int v: rev[blk.back()[i]])\n      if (dat[v]) dat[v]= 0, blk.back().push_back(v);\n\
    \   }\n  return blk;\n }\n std::vector<int> get_index(const std::vector<std::vector<int>>\
    \ &blk) const {\n  std::vector<int> index(adj.size());\n  for (int i= blk.size();\
    \ i--;)\n   for (int v: blk[i]) index[v]= i;\n  return index;\n }\n std::vector<std::vector<int>>\
    \ get_dag(const std::vector<int> &index, int num) const {\n  std::vector<std::vector<int>>\
    \ dag(num);\n  std::vector<std::array<int, 2>> es;\n  for (int i= adj.size();\
    \ i--;)\n   for (int j: adj[i])\n    if (int u= index[i], v= index[j]; u != v)\
    \ es.push_back({u, v});\n  std::sort(es.begin(), es.end()), es.erase(std::unique(es.begin(),\
    \ es.end()), es.end());\n  for (auto [u, v]: es) dag[u].push_back(v);\n  return\
    \ dag;\n }\n};\n#line 4 \"test/yosupo/scc.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >> N >>\
    \ M;\n StronglyConnectedComponents scc(N);\n for (int i= 0; i < M; ++i) {\n  int\
    \ a, b;\n  cin >> a >> b;\n  scc.add_edge(a, b);\n }\n auto ans= scc.get_block();\n\
    \ cout << ans.size() << '\\n';\n for (const auto &blk: ans) {\n  cout << blk.size();\n\
    \  for (int v: blk) cout << \" \" << v;\n  cout << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <iostream>\n\
    #include \"src/Graph/StronglyConnectedComponents.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >>\
    \ N >> M;\n StronglyConnectedComponents scc(N);\n for (int i= 0; i < M; ++i) {\n\
    \  int a, b;\n  cin >> a >> b;\n  scc.add_edge(a, b);\n }\n auto ans= scc.get_block();\n\
    \ cout << ans.size() << '\\n';\n for (const auto &blk: ans) {\n  cout << blk.size();\n\
    \  for (int v: blk) cout << \" \" << v;\n  cout << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 18:54:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
