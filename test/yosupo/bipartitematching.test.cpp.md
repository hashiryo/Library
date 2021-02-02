---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/MatchingBipartite.hpp
    title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\u30E9\u30D5\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Graph/MatchingBipartite.hpp\"\n/**\n * @title \u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0(\u4E8C\u90E8\u30B0\u30E9\u30D5)\n * @category \u30B0\u30E9\
    \u30D5\n *  O(VE) \u901F\u3044(O(E\u221AV)\u4E26?)\n *  \u8FD4\u308A\u5024:{\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u6570,{\u5DE6\u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\
    \u3089-1),\u53F3\u306E\u76F8\u65B9(\u3044\u306A\u3044\u306A\u3089-1)}}\n *  lexicographically_matching\
    \ \u8F9E\u66F8\u9806\u6700\u5C0F\n * @see https://snuke.hatenablog.com/entry/2019/05/07/013609\n\
    \ */\n// \u88AB\u8986\u554F\u984C\u3068\u306E\u95A2\u4FC2 https://qiita.com/drken/items/7f98315b56c95a6181a4\n\
    \n// BEGIN CUT HERE\n\nclass MatchingBipartite {\n  std::vector<std::vector<int>>\
    \ adj;\n  std::vector<int> pre, rt, lmate, rmate;\n  bool dfs(int v, const int\
    \ &tstamp) {\n    pre[v] = tstamp;\n    for (int u : adj[v]) {\n      int w =\
    \ rmate[u];\n      if (w == -1 || (rt[w] != -2 && pre[w] != tstamp && dfs(w, tstamp)))\n\
    \        return rmate[u] = v, lmate[v] = u, true;\n    }\n    return false;\n\
    \  }\n\n public:\n  MatchingBipartite(int n, int m) : adj(n), lmate(n, -1), rmate(m,\
    \ -1) {}\n  void add_edge(int l, int r) { adj[l].push_back(r); }\n  std::pair<int,\
    \ std::pair<std::vector<int>, std::vector<int>>> get_matching() {\n    int res\
    \ = 0;\n    std::queue<int> que;\n    for (bool update = true; update;) {\n  \
    \    update = false, pre.assign(adj.size(), -1), rt.assign(adj.size(), -1);\n\
    \      for (int i = 0; i < (int)adj.size(); i++)\n        if (lmate[i] == -1)\
    \ que.push(rt[i] = i);\n      while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        if (lmate[rt[v]] != -1) continue;\n        for (int\
    \ u : adj[v]) {\n          if (rmate[u] == -1) {\n            for (; u != -1;\
    \ v = pre[v]) rmate[u] = v, std::swap(lmate[v], u);\n            update = true,\
    \ res++;\n            break;\n          }\n          if (pre[rmate[u]] != -1)\
    \ continue;\n          rt[rmate[u]] = rt[pre[rmate[u]] = v], que.push(rmate[u]);\n\
    \        }\n      }\n    }\n    return std::make_pair(res, std::make_pair(lmate,\
    \ rmate));\n  }\n  std::pair<int, std::pair<std::vector<int>, std::vector<int>>>\n\
    \  lexicographically_matching() {\n    int res = get_matching().first, tstamp\
    \ = -2;\n    for (int i = 0; i < (int)adj.size(); i++)\n      if (lmate[i] !=\
    \ -1)\n        lmate[i] = rmate[lmate[i]] = -1, dfs(i, --tstamp), rt[i] = -2;\n\
    \    return std::make_pair(res, std::make_pair(lmate, rmate));\n  }\n};\n#line\
    \ 4 \"test/yosupo/bipartitematching.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int L, R, M;\n  cin >>\
    \ L >> R >> M;\n  MatchingBipartite graph(L, R);\n  while (M--) {\n    int a,\
    \ b;\n    cin >> a >> b;\n    graph.add_edge(a, b);\n  }\n  auto ans = graph.get_matching();\n\
    \  auto left = ans.second.first;\n  cout << ans.first << '\\n';\n  for (int i\
    \ = 0; i < (int)left.size(); i++)\n    if (left[i] != -1) {\n      cout << i <<\
    \ \" \" << left[i] << '\\n';\n    }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Graph/MatchingBipartite.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int L,\
    \ R, M;\n  cin >> L >> R >> M;\n  MatchingBipartite graph(L, R);\n  while (M--)\
    \ {\n    int a, b;\n    cin >> a >> b;\n    graph.add_edge(a, b);\n  }\n  auto\
    \ ans = graph.get_matching();\n  auto left = ans.second.first;\n  cout << ans.first\
    \ << '\\n';\n  for (int i = 0; i < (int)left.size(); i++)\n    if (left[i] !=\
    \ -1) {\n      cout << i << \" \" << left[i] << '\\n';\n    }\n  return 0;\n}"
  dependsOn:
  - src/Graph/MatchingBipartite.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
