---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    #include <vector>\n#include <functional>\n#include <algorithm>\nstruct StronglyConnectedComponents\
    \ {\n std::vector<std::vector<int>> adj;\n StronglyConnectedComponents(int n):\
    \ adj(n) {}\n void add_edge(int src, int dst) { adj[src].push_back(dst); }\n std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_SCC() {\n  std::vector<std::vector<int>> scc;\n  std::vector<int>\
    \ S, B, index(adj.size());\n  std::function<void(int)> dfs= [&](int u) {\n   B.push_back(index[u]=\
    \ S.size());\n   S.push_back(u);\n   for (int v: adj[u]) {\n    if (!index[v])\
    \ dfs(v);\n    else\n     while (index[v] < B.back()) B.pop_back();\n   }\n  \
    \ if (index[u] == B.back()) {\n    scc.push_back({});\n    B.pop_back();\n   \
    \ for (; index[u] < (int)S.size(); S.pop_back()) {\n     scc.back().push_back(S.back());\n\
    \     index[S.back()]= adj.size() + scc.size();\n    }\n   }\n  };\n  for (std::size_t\
    \ u= 0; u < adj.size(); u++)\n   if (!index[u]) dfs(u);\n  reverse(scc.begin(),\
    \ scc.end());\n  for (std::size_t u= 0; u < adj.size(); u++) index[u]= scc.size()\
    \ - index[u] + adj.size();\n  return std::make_pair(scc, index);\n }\n};\n#line\
    \ 4 \"test/yosupo/scc.test.cpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N, M;\n cin >> N >> M;\n StronglyConnectedComponents\
    \ graph(N);\n for (int i= 0; i < M; i++) {\n  int a, b;\n  cin >> a >> b;\n  graph.add_edge(a,\
    \ b);\n }\n auto ans= graph.get_SCC().first;\n cout << ans.size() << endl;\n for\
    \ (auto &a: ans) {\n  cout << a.size();\n  for (int &v: a) cout << \" \" << v;\n\
    \  cout << endl;\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <iostream>\n\
    #include \"src/Graph/StronglyConnectedComponents.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >>\
    \ N >> M;\n StronglyConnectedComponents graph(N);\n for (int i= 0; i < M; i++)\
    \ {\n  int a, b;\n  cin >> a >> b;\n  graph.add_edge(a, b);\n }\n auto ans= graph.get_SCC().first;\n\
    \ cout << ans.size() << endl;\n for (auto &a: ans) {\n  cout << a.size();\n  for\
    \ (int &v: a) cout << \" \" << v;\n  cout << endl;\n }\n return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 19:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
