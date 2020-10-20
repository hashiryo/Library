---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0334.test.cpp
    title: test/aoj/0334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/421.test.cpp
    title: test/yukicoder/421.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\
      \u30E9\u30D5)"
    links:
    - https://qiita.com/drken/items/7f98315b56c95a6181a4
    - https://snuke.hatenablog.com/entry/2019/05/07/013609
  bundledCode: "#line 1 \"src/Graph/MatchingBipartite.hpp\"\n/**\n * @title \u6700\
    \u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\u30E9\u30D5)\n * @category\
    \ \u30B0\u30E9\u30D5\n *  O(VE) \u901F\u3044(O(E\u221AV)\u4E26?)\n *  \u8FD4\u308A\
    \u5024:{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,{\u5DE6\u306E\u76F8\u65B9(\u3044\u306A\
    \u3044\u306A\u3089-1),\u53F3\u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\u3089\
    -1)}}\n *  lexicographically_matching \u8F9E\u66F8\u9806\u6700\u5C0F\n * @see\
    \ https://snuke.hatenablog.com/entry/2019/05/07/013609\n */\n// \u88AB\u8986\u554F\
    \u984C\u3068\u306E\u95A2\u4FC2 https://qiita.com/drken/items/7f98315b56c95a6181a4\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \nstruct MatchingBipartite {\n private:\n  vector<vector<int>> adj;\n  vector<int>\
    \ pre, rt;\n  vector<int> lmate, rmate;\n\n  bool dfs(int v, const int &tstamp)\
    \ {\n    pre[v] = tstamp;\n    for (int u : adj[v]) {\n      int w = rmate[u];\n\
    \      if (w == -1 || (rt[w] != -2 && pre[w] != tstamp && dfs(w, tstamp))) {\n\
    \        rmate[u] = v;\n        lmate[v] = u;\n        return true;\n      }\n\
    \    }\n    return false;\n  }\n\n public:\n  MatchingBipartite(int n, int m)\n\
    \      : adj(n), pre(n, -1), rt(n, -1), lmate(n, -1), rmate(m, -1) {}\n  void\
    \ add_edge(int l, int r) { adj[l].push_back(r); }\n  pair<int, pair<vector<int>,\
    \ vector<int>>> get_matching() {\n    int res = 0;\n    queue<int> que;\n    for\
    \ (bool update = true; update;) {\n      update = false;\n      for (int i = 0;\
    \ i < (int)adj.size(); i++)\n        if (lmate[i] == -1) que.push(rt[i] = i);\n\
    \      while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        if (lmate[rt[v]] != -1) continue;\n        for (int u : adj[v]) {\n \
    \         if (rmate[u] == -1) {\n            for (; u != -1; v = pre[v]) rmate[u]\
    \ = v, swap(lmate[v], u);\n            update = true;\n            res++;\n  \
    \          break;\n          }\n          u = rmate[u];\n          if (pre[u]\
    \ != -1) continue;\n          rt[u] = rt[pre[u] = v];\n          que.push(u);\n\
    \        }\n      }\n      if (update)\n        fill(pre.begin(), pre.end(), -1),\
    \ fill(rt.begin(), rt.end(), -1);\n    }\n    return make_pair(res, make_pair(lmate,\
    \ rmate));\n  }\n  pair<int, pair<vector<int>, vector<int>>> lexicographically_matching()\
    \ {\n    int res = get_matching().first;\n    int tstamp = -2;\n    for (int i\
    \ = 0; i < (int)adj.size(); i++) {\n      if (lmate[i] != -1) {\n        rmate[lmate[i]]\
    \ = -1;\n        lmate[i] = -1;\n        dfs(i, --tstamp);\n        rt[i] = -2;\n\
    \      }\n    }\n    return make_pair(res, make_pair(lmate, rmate));\n  }\n};\n"
  code: "/**\n * @title \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\
    \u30E9\u30D5)\n * @category \u30B0\u30E9\u30D5\n *  O(VE) \u901F\u3044(O(E\u221A\
    V)\u4E26?)\n *  \u8FD4\u308A\u5024:{\u30DE\u30C3\u30C1\u30F3\u30B0\u6570,{\u5DE6\
    \u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\u3089-1),\u53F3\u306E\u76F8\u65B9\
    (\u3044\u306A\u3044\u306A\u3089-1)}}\n *  lexicographically_matching \u8F9E\u66F8\
    \u9806\u6700\u5C0F\n * @see https://snuke.hatenablog.com/entry/2019/05/07/013609\n\
    \ */\n// \u88AB\u8986\u554F\u984C\u3068\u306E\u95A2\u4FC2 https://qiita.com/drken/items/7f98315b56c95a6181a4\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\
    \nstruct MatchingBipartite {\n private:\n  vector<vector<int>> adj;\n  vector<int>\
    \ pre, rt;\n  vector<int> lmate, rmate;\n\n  bool dfs(int v, const int &tstamp)\
    \ {\n    pre[v] = tstamp;\n    for (int u : adj[v]) {\n      int w = rmate[u];\n\
    \      if (w == -1 || (rt[w] != -2 && pre[w] != tstamp && dfs(w, tstamp))) {\n\
    \        rmate[u] = v;\n        lmate[v] = u;\n        return true;\n      }\n\
    \    }\n    return false;\n  }\n\n public:\n  MatchingBipartite(int n, int m)\n\
    \      : adj(n), pre(n, -1), rt(n, -1), lmate(n, -1), rmate(m, -1) {}\n  void\
    \ add_edge(int l, int r) { adj[l].push_back(r); }\n  pair<int, pair<vector<int>,\
    \ vector<int>>> get_matching() {\n    int res = 0;\n    queue<int> que;\n    for\
    \ (bool update = true; update;) {\n      update = false;\n      for (int i = 0;\
    \ i < (int)adj.size(); i++)\n        if (lmate[i] == -1) que.push(rt[i] = i);\n\
    \      while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        if (lmate[rt[v]] != -1) continue;\n        for (int u : adj[v]) {\n \
    \         if (rmate[u] == -1) {\n            for (; u != -1; v = pre[v]) rmate[u]\
    \ = v, swap(lmate[v], u);\n            update = true;\n            res++;\n  \
    \          break;\n          }\n          u = rmate[u];\n          if (pre[u]\
    \ != -1) continue;\n          rt[u] = rt[pre[u] = v];\n          que.push(u);\n\
    \        }\n      }\n      if (update)\n        fill(pre.begin(), pre.end(), -1),\
    \ fill(rt.begin(), rt.end(), -1);\n    }\n    return make_pair(res, make_pair(lmate,\
    \ rmate));\n  }\n  pair<int, pair<vector<int>, vector<int>>> lexicographically_matching()\
    \ {\n    int res = get_matching().first;\n    int tstamp = -2;\n    for (int i\
    \ = 0; i < (int)adj.size(); i++) {\n      if (lmate[i] != -1) {\n        rmate[lmate[i]]\
    \ = -1;\n        lmate[i] = -1;\n        dfs(i, --tstamp);\n        rt[i] = -2;\n\
    \      }\n    }\n    return make_pair(res, make_pair(lmate, rmate));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/MatchingBipartite.hpp
  requiredBy: []
  timestamp: '2020-08-15 16:22:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/421.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/0334.test.cpp
  - test/yosupo/bipartitematching.test.cpp
documentation_of: src/Graph/MatchingBipartite.hpp
layout: document
redirect_from:
- /library/src/Graph/MatchingBipartite.hpp
- /library/src/Graph/MatchingBipartite.hpp.html
title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\u30E9\u30D5)"
---
