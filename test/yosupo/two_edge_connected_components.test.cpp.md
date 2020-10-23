---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/TwoEdgeConnectedComponents.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/Graph/TwoEdgeConnectedComponents.hpp\"\
    \n/**\n * @title \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @category\
    \ \u30B0\u30E9\u30D5\n *  O(V + E)\n *  \u8FD4\u308A\u5024:{\u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206,\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\u6210\u5206\
    \u306E\u6DFB\u5B57}\n */\n\n// BEGIN CUT HERE\n\nstruct TwoEdgeConnectedComponents\
    \ {\n private:\n  int n;\n  std::vector<std::vector<int>> adj;\n\n public:\n \
    \ TwoEdgeConnectedComponents(int n) : n(n), adj(n) {}\n  void add_edge(int u,\
    \ int v) {\n    adj[u].push_back(v);\n    adj[v].push_back(u);\n  }\n  std::pair<std::vector<std::vector<int>>,\
    \ std::vector<int>> get_2ECC() {\n    std::vector<int> index(n, -1), num(n), par(n,\
    \ -1), cur(n);\n    std::vector<short> parcheck(n, 0);\n    std::vector<std::vector<int>>\
    \ block;\n    for (int s = 0; s < n; ++s) {\n      if (num[s]) continue;\n   \
    \   int time = 0;\n      std::vector<int> snum, path, stack = {s};\n      while\
    \ (!stack.empty()) {\n        int u = stack.back();\n        if (cur[u] == 0)\
    \ {\n          num[u] = ++time;\n          path.push_back(u);\n          snum.push_back(num[u]);\n\
    \        }\n        if (cur[u] == adj[u].size()) {\n          if (num[u] == snum.back())\
    \ {\n            snum.pop_back();\n            block.push_back({});\n        \
    \    while (1) {\n              int w = path.back();\n              path.pop_back();\n\
    \              block.back().push_back(w);\n              index[w] = block.size()\
    \ - 1;\n              if (u == w) break;\n            }\n          }\n       \
    \   stack.pop_back();\n        } else {\n          int v = adj[u][cur[u]++];\n\
    \          if (!num[v]) {\n            par[v] = u;\n            stack.push_back(v);\n\
    \          } else if (v == par[u] && !parcheck[u]) {\n            parcheck[u]\
    \ = true;\n          } else if (index[v] < 0) {\n            while (snum.back()\
    \ > num[v]) snum.pop_back();\n          }\n        }\n      }\n    }\n    return\
    \ std::make_pair(block, index);\n  }\n};\n#line 4 \"test/yosupo/two_edge_connected_components.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, M;\n  cin >> N >> M;\n  TwoEdgeConnectedComponents graph(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b;\n    graph.add_edge(a,\
    \ b);\n  }\n  auto ans = graph.get_2ECC().first;\n  cout << ans.size() << endl;\n\
    \  for (auto &a : ans) {\n    cout << a.size();\n    for (int &v : a) cout <<\
    \ \" \" << v;\n    cout << endl;\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <bits/stdc++.h>\n#include \"src/Graph/TwoEdgeConnectedComponents.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, M;\n  cin >> N >> M;\n  TwoEdgeConnectedComponents graph(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b;\n    graph.add_edge(a,\
    \ b);\n  }\n  auto ans = graph.get_2ECC().first;\n  cout << ans.size() << endl;\n\
    \  for (auto &a : ans) {\n    cout << a.size();\n    for (int &v : a) cout <<\
    \ \" \" << v;\n    cout << endl;\n  }\n  return 0;\n}"
  dependsOn:
  - src/Graph/TwoEdgeConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
