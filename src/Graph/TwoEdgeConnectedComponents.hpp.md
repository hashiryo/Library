---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.LCT.test.cpp
    title: test/yukicoder/529.LCT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"src/Graph/TwoEdgeConnectedComponents.hpp\"\n/**\n * @title\
    \ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @category \u30B0\u30E9\
    \u30D5\n *  O(V + E)\n *  \u8FD4\u308A\u5024:{\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206,\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\u6210\u5206\u306E\u6DFB\u5B57\
    }\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\nstruct TwoEdgeConnectedComponents {\n private:\n  int n;\n  vector<vector<int>>\
    \ adj;\n\n public:\n  TwoEdgeConnectedComponents(int n) : n(n), adj(n) {}\n  void\
    \ add_edge(int u, int v) {\n    adj[u].push_back(v);\n    adj[v].push_back(u);\n\
    \  }\n  pair<vector<vector<int>>, vector<int>> get_2ECC() {\n    vector<int> index(n,\
    \ -1), num(n), par(n, -1), cur(n);\n    vector<short> parcheck(n, 0);\n    vector<vector<int>>\
    \ block;\n    for (int s = 0; s < n; ++s) {\n      if (num[s]) continue;\n   \
    \   int time = 0;\n      vector<int> snum, path, stack = {s};\n      while (!stack.empty())\
    \ {\n        int u = stack.back();\n        if (cur[u] == 0) {\n          num[u]\
    \ = ++time;\n          path.push_back(u);\n          snum.push_back(num[u]);\n\
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
    \ make_pair(block, index);\n  }\n};\n"
  code: "/**\n * @title \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n *\
    \ @category \u30B0\u30E9\u30D5\n *  O(V + E)\n *  \u8FD4\u308A\u5024:{\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206,\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\u6210\
    \u5206\u306E\u6DFB\u5B57}\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n\nstruct TwoEdgeConnectedComponents {\n private:\n\
    \  int n;\n  vector<vector<int>> adj;\n\n public:\n  TwoEdgeConnectedComponents(int\
    \ n) : n(n), adj(n) {}\n  void add_edge(int u, int v) {\n    adj[u].push_back(v);\n\
    \    adj[v].push_back(u);\n  }\n  pair<vector<vector<int>>, vector<int>> get_2ECC()\
    \ {\n    vector<int> index(n, -1), num(n), par(n, -1), cur(n);\n    vector<short>\
    \ parcheck(n, 0);\n    vector<vector<int>> block;\n    for (int s = 0; s < n;\
    \ ++s) {\n      if (num[s]) continue;\n      int time = 0;\n      vector<int>\
    \ snum, path, stack = {s};\n      while (!stack.empty()) {\n        int u = stack.back();\n\
    \        if (cur[u] == 0) {\n          num[u] = ++time;\n          path.push_back(u);\n\
    \          snum.push_back(num[u]);\n        }\n        if (cur[u] == adj[u].size())\
    \ {\n          if (num[u] == snum.back()) {\n            snum.pop_back();\n  \
    \          block.push_back({});\n            while (1) {\n              int w\
    \ = path.back();\n              path.pop_back();\n              block.back().push_back(w);\n\
    \              index[w] = block.size() - 1;\n              if (u == w) break;\n\
    \            }\n          }\n          stack.pop_back();\n        } else {\n \
    \         int v = adj[u][cur[u]++];\n          if (!num[v]) {\n            par[v]\
    \ = u;\n            stack.push_back(v);\n          } else if (v == par[u] && !parcheck[u])\
    \ {\n            parcheck[u] = true;\n          } else if (index[v] < 0) {\n \
    \           while (snum.back() > num[v]) snum.pop_back();\n          }\n     \
    \   }\n      }\n    }\n    return make_pair(block, index);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2020-08-11 20:23:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/529.LCT.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: src/Graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/Graph/TwoEdgeConnectedComponents.hpp
- /library/src/Graph/TwoEdgeConnectedComponents.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
