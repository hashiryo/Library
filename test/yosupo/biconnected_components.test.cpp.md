---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/BiConnectedComponents.hpp
    title: "\u4E8C\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ adj[v].push_back(u); }\n std::vector<std::vector<int>> block_cut_tree() {\n\
    \  int n= adj.size(), m= n, k= 0;\n  std::vector<int> low(n), ord(n), st;\n  std::vector<bool>\
    \ used(n);\n  std::vector<std::vector<int>> bct;\n  st.reserve(n);\n  auto dfs=\
    \ [&](auto &self, int v, int p) -> void {\n   int ch= 0, s, x;\n   st.push_back(v),\
    \ used[v]= true, low[v]= ord[v]= k++;\n   for (int u: adj[v])\n    if (u != p)\
    \ {\n     if (used[u]) low[v]= std::min(low[v], ord[u]);\n     else if (s= st.size(),\
    \ ++ch, self(self, u, v), low[v]= std::min(low[v], low[u]); (p == -1 && ch > 1)\
    \ || (p != -1 && low[u] >= ord[v])) {\n      for (bct.resize(m + 1), bct[m].push_back(v),\
    \ bct[v].push_back(m); st.size() > s; st.pop_back()) bct[x= st.back()].push_back(m),\
    \ bct[m].push_back(x);\n      ++m;\n     }\n    }\n  };\n  for (int v= n; v--;)\n\
    \   if (!used[v]) {\n    dfs(dfs, v, -1), bct.resize(m + 1);\n    for (int x:\
    \ st) bct[x].push_back(m), bct[m].push_back(x);\n    ++m, st.clear();\n   }\n\
    \  return bct;\n }\n};\n#line 4 \"test/yosupo/biconnected_components.test.cpp\"\
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
  timestamp: '2023-01-24 14:48:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/biconnected_components.test.cpp
- /verify/test/yosupo/biconnected_components.test.cpp.html
title: test/yosupo/biconnected_components.test.cpp
---
