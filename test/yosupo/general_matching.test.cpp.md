---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/Matching.hpp
    title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"test/yosupo/general_matching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/general_matching\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Optimization/Matching.hpp\"\nclass Matching {\n int n, ret;\n std::vector<std::vector<int>>\
    \ adj;\n std::vector<int> mt, idx, p;\n std::vector<std::array<int, 2>> es;\n\
    \ void rematch(int u, int v, int w= -1) {\n  if (w= mt[u], mt[u]= v; w == -1 ||\
    \ mt[w] != u) return;\n  if (es[u][1] == -1) {\n   rematch(mt[w]= es[u][0], w);\n\
    \  } else rematch(es[u][0], es[u][1]), rematch(es[u][1], es[u][0]);\n }\n int\
    \ f(int x) { return (idx[x] != ret || p[x] == -1) ? x : (p[x]= f(p[x])); }\n bool\
    \ check(int root) {\n  std::queue<int> que;\n  es[root]= {-1, -1}, idx[root]=\
    \ ret, p[root]= -1, que.push(root);\n  for (int x, u, v, w; !que.empty();) {\n\
    \   x= que.front(), que.pop();\n   for (int y: adj[x]) {\n    if (y == root) continue;\n\
    \    if (mt[y] == -1) {\n     return rematch(mt[y]= x, y), true;\n    } else if\
    \ (idx[y] == ret) {\n     if (u= f(x), v= f(y), w= root; u == v) continue;\n \
    \    for (; u != root || v != root; es[u]= {x, y}, u= f(es[mt[u]][0])) {\n   \
    \   if (v != root) std::swap(u, v);\n      if (es[u][0] == x && es[u][1] == y)\
    \ {\n       w= u;\n       break;\n      }\n     }\n     for (int t= f(x); t !=\
    \ w; t= f(es[mt[t]][0])) idx[t]= ret, p[t]= w, que.push(t);\n     for (int t=\
    \ f(y); t != w; t= f(es[mt[t]][0])) idx[t]= ret, p[t]= w, que.push(t);\n    }\
    \ else if (idx[mt[y]] != ret) es[y]= {-1, -1}, es[mt[y]]= {x, -1}, idx[mt[y]]=\
    \ ret, p[mt[y]]= y, que.push(mt[y]);\n   }\n  }\n  return false;\n }\npublic:\n\
    \ Matching(int n): n(n), ret(0), adj(n), mt(n, -1), idx(n, -1), p(n), es(n) {}\n\
    \ void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n\
    \ std::pair<int, std::vector<int>> get_matching() {\n  for (int i= 0; i < n; i++)\n\
    \   if (mt[i] == -1) ret+= check(i);\n  return std::make_pair(ret, mt);\n }\n\
    };\n#line 4 \"test/yosupo/general_matching.test.cpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M;\n  cin\
    \ >> N >> M;\n  Matching graph(N);\n  while (M--) {\n    int u, v;\n    cin >>\
    \ u >> v;\n    graph.add_edge(u, v);\n  }\n  auto ans = graph.get_matching();\n\
    \  cout << ans.first << endl;\n  for (int i = 0; i < N; i++)\n    if (i < ans.second[i])\
    \ cout << i << \" \" << ans.second[i] << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Optimization/Matching.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N,\
    \ M;\n  cin >> N >> M;\n  Matching graph(N);\n  while (M--) {\n    int u, v;\n\
    \    cin >> u >> v;\n    graph.add_edge(u, v);\n  }\n  auto ans = graph.get_matching();\n\
    \  cout << ans.first << endl;\n  for (int i = 0; i < N; i++)\n    if (i < ans.second[i])\
    \ cout << i << \" \" << ans.second[i] << endl;\n  return 0;\n}"
  dependsOn:
  - src/Optimization/Matching.hpp
  isVerificationFile: true
  path: test/yosupo/general_matching.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 23:16:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/general_matching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/general_matching.test.cpp
- /verify/test/yosupo/general_matching.test.cpp.html
title: test/yosupo/general_matching.test.cpp
---
