---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/BiConnectedComponents.hpp
    title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/yosupo/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n#include <iostream>\n\
    #line 2 \"src/Graph/BiConnectedComponents.hpp\"\n#include <vector>\n#include <algorithm>\n\
    class BiConnectedComponents {\n std::vector<std::vector<int>> adj;\npublic:\n\
    \ BiConnectedComponents(int n): adj(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v),\
    \ adj[v].push_back(u); }\n std::vector<std::vector<int>> block_cut_tree() const\
    \ {\n  const int n= adj.size();\n  std::vector<int> ord(n), par(n, -2), dat(n,\
    \ 0), low;\n  std::vector<std::vector<int>> ret(n);\n  auto add= [&](int u, int\
    \ v) { ret[u].push_back(v), ret[v].push_back(u); };\n  int k= 0;\n  for (int s=\
    \ 0, p; s < n; ++s)\n   if (par[s] == -2)\n    for (par[p= s]= -1; p >= 0;) {\n\
    \     if (dat[p] == 0) ord[k++]= p;\n     if (dat[p] == (int)adj[p].size()) {\n\
    \      p= par[p];\n      continue;\n     }\n     if (int q= adj[p][dat[p]++];\
    \ par[q] == -2) par[q]= p, p= q;\n    }\n  for (int i= 0; i < n; ++i) dat[ord[i]]=\
    \ i;\n  low= dat;\n  for (int v= 0; v < n; ++v)\n   for (int u: adj[v]) low[v]=\
    \ std::min(low[v], dat[u]);\n  for (int i= n; i--;)\n   if (int p= ord[i], pp=\
    \ par[p]; pp >= 0) low[pp]= std::min(low[pp], low[p]);\n  for (int p: ord)\n \
    \  if (par[p] >= 0) {\n    if (int pp= par[p]; low[p] < dat[pp]) low[p]= low[pp],\
    \ add(low[p], p);\n    else ret.resize(k + 1), add(k, pp), add(k, p), low[p]=\
    \ k++;\n   }\n  for (int s= 0; s < n; ++s)\n   if (!adj[s].size()) ret.resize(k\
    \ + 1), add(k++, s);\n  return ret;\n }\n};\n#line 4 \"test/yosupo/biconnected_components.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n BiConnectedComponents bcc(N);\n for (int i= 0;\
    \ i < M; ++i) {\n  int a, b;\n  cin >> a >> b;\n  bcc.add_edge(a, b);\n }\n auto\
    \ bct= bcc.block_cut_tree();\n int K= bct.size();\n cout << K - N << '\\n';\n\
    \ for (int i= N; i < K; i++) {\n  cout << bct[i].size();\n  for (int v: bct[i])\
    \ cout << \" \" << v;\n  cout << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#include <iostream>\n#include \"src/Graph/BiConnectedComponents.hpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N, M;\n cin >> N >> M;\n BiConnectedComponents bcc(N);\n for (int i= 0; i <\
    \ M; ++i) {\n  int a, b;\n  cin >> a >> b;\n  bcc.add_edge(a, b);\n }\n auto bct=\
    \ bcc.block_cut_tree();\n int K= bct.size();\n cout << K - N << '\\n';\n for (int\
    \ i= N; i < K; i++) {\n  cout << bct[i].size();\n  for (int v: bct[i]) cout <<\
    \ \" \" << v;\n  cout << '\\n';\n }\n return 0;\n}\n"
  dependsOn:
  - src/Graph/BiConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2023-02-07 17:34:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/biconnected_components.test.cpp
- /verify/test/yosupo/biconnected_components.test.cpp.html
title: test/yosupo/biconnected_components.test.cpp
---
