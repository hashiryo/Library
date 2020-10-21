---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/Graph/StronglyConnectedComponents.hpp\"\n/**\n * @title \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n * @category \u30B0\u30E9\u30D5\n *  Gabow\n *\
    \  O(V + E)\n *  \u8FD4\u308A\u5024:{\u5F37\u9023\u7D50\u6210\u5206(\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8),\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\
    \u308B\u6210\u5206\u306E\u6DFB\u5B57}\n */\n\n#ifndef call_from_test\n#line 11\
    \ \"src/Graph/StronglyConnectedComponents.hpp\"\nusing namespace std;\n#endif\n\
    \nstruct StronglyConnectedComponents {\n  vector<vector<int>> adj;\n\n  StronglyConnectedComponents(int\
    \ n) : adj(n) {}\n  void add_edge(int src, int dst) { adj[src].push_back(dst);\
    \ }\n  pair<vector<vector<int>>, vector<int>> get_SCC() {\n    vector<vector<int>>\
    \ scc;\n    vector<int> S, B, index(adj.size());\n    function<void(int)> dfs\
    \ = [&](int u) {\n      B.push_back(index[u] = S.size());\n      S.push_back(u);\n\
    \      for (int v : adj[u]) {\n        if (!index[v])\n          dfs(v);\n   \
    \     else\n          while (index[v] < B.back()) B.pop_back();\n      }\n   \
    \   if (index[u] == B.back()) {\n        scc.push_back({});\n        B.pop_back();\n\
    \        for (; index[u] < (int)S.size(); S.pop_back()) {\n          scc.back().push_back(S.back());\n\
    \          index[S.back()] = adj.size() + scc.size();\n        }\n      }\n  \
    \  };\n    for (size_t u = 0; u < adj.size(); u++)\n      if (!index[u]) dfs(u);\n\
    \    reverse(scc.begin(), scc.end());\n    for (size_t u = 0; u < adj.size();\
    \ u++)\n      index[u] = scc.size() - index[u] + adj.size();\n    return make_pair(scc,\
    \ index);\n  }\n};\n#line 8 \"test/yosupo/scc.test.cpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M;\n  cin\
    \ >> N >> M;\n  StronglyConnectedComponents graph(N);\n  for (int i = 0; i < M;\
    \ i++) {\n    int a, b;\n    cin >> a >> b;\n    graph.add_edge(a, b);\n  }\n\
    \  auto ans = graph.get_SCC().first;\n  cout << ans.size() << endl;\n  for (auto\
    \ &a : ans) {\n    cout << a.size();\n    for (int &v : a) cout << \" \" << v;\n\
    \    cout << endl;\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, M;\n  cin >> N >> M;\n  StronglyConnectedComponents graph(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b;\n    graph.add_edge(a,\
    \ b);\n  }\n  auto ans = graph.get_SCC().first;\n  cout << ans.size() << endl;\n\
    \  for (auto &a : ans) {\n    cout << a.size();\n    for (int &v : a) cout <<\
    \ \" \" << v;\n    cout << endl;\n  }\n  return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-08-26 21:11:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---