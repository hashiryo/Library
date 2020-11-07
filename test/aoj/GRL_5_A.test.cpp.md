---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/ReRooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Graph/ReRooting.hpp\"\n/**\n * @title\
    \ \u5168\u65B9\u4F4D\u6728DP\n * @category \u30B0\u30E9\u30D5\n * @see https://ei1333.hateblo.jp/entry/2018/12/21/004022\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <typename T, typename E = int>\nstruct ReRooting\
    \ {\n  struct Edge {\n    int to;\n    E data;\n    T dp, ndp;\n  };\n  std::vector<std::vector<Edge>>\
    \ adj;\n\n private:\n  const std::function<T(T, T)> op;\n  const T id;\n  const\
    \ std::function<T(T, E)> lift;\n  std::vector<T> subdp, dp;\n\n private:\n  void\
    \ dfs_sub(int idx, int par) {\n    for (auto &e : adj[idx]) {\n      if (e.to\
    \ == par) continue;\n      dfs_sub(e.to, idx);\n      subdp[idx] = op(subdp[idx],\
    \ lift(subdp[e.to], e.data));\n    }\n  }\n  void dfs_all(int idx, int par, const\
    \ T &top) {\n    T buff = id;\n    for (int i = 0; i < (int)adj[idx].size(); i++)\
    \ {\n      auto &e = adj[idx][i];\n      e.ndp = buff;\n      e.dp = lift(par\
    \ == e.to ? top : subdp[e.to], e.data);\n      buff = op(buff, e.dp);\n    }\n\
    \    dp[idx] = buff;\n    buff = id;\n    for (int i = (int)adj[idx].size() -\
    \ 1; i >= 0; i--) {\n      auto &e = adj[idx][i];\n      if (e.to != par) dfs_all(e.to,\
    \ idx, op(e.ndp, buff));\n      e.ndp = op(e.ndp, buff);\n      buff = op(buff,\
    \ e.dp);\n    }\n  }\n\n public:\n  ReRooting(\n      int N, const std::function<T(T,\
    \ T)> &op_, T id_,\n      const std::function<T(T, E)> &lift_\n      = [](const\
    \ T &dp, const E &dat) { return dp; })\n      : adj(N), op(op_), id(id_), lift(lift_),\
    \ subdp(N, id_), dp(N, id_) {}\n  void add_edge(int src, int dst, E d = E()) {\n\
    \    adj[src].emplace_back((Edge){dst, d, id, id});\n  }\n  std::vector<T> run()\
    \ {\n    dfs_sub(0, -1);\n    dfs_all(0, -1, id);\n    return dp;\n  }\n};\n#line\
    \ 5 \"test/aoj/GRL_5_A.test.cpp\"\nusing namespace std;\n\nsigned main() {\n \
    \ cin.tie(0);\n  ios::sync_with_stdio(0);\n  int n;\n  cin >> n;\n  auto op =\
    \ [](long long l, long long r) { return max(l, r); };\n  auto lift = [](long long\
    \ l, long long dat) { return l + dat; };\n  ReRooting<long long, long long> tree(n,\
    \ op, 0, lift);\n  for (int i = 0; i < n - 1; i++) {\n    int s, t;\n    long\
    \ long w;\n    cin >> s >> t >> w;\n    tree.add_edge(s, t, w);\n    tree.add_edge(t,\
    \ s, w);\n  }\n  auto ret = tree.run();\n  long long ans = 0;\n  for (int i =\
    \ 0; i < n; i++) ans = max(ans, ret[i]);\n  cout << ans << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n#include <bits/stdc++.h>\n#include \"src/Graph/ReRooting.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int n;\n\
    \  cin >> n;\n  auto op = [](long long l, long long r) { return max(l, r); };\n\
    \  auto lift = [](long long l, long long dat) { return l + dat; };\n  ReRooting<long\
    \ long, long long> tree(n, op, 0, lift);\n  for (int i = 0; i < n - 1; i++) {\n\
    \    int s, t;\n    long long w;\n    cin >> s >> t >> w;\n    tree.add_edge(s,\
    \ t, w);\n    tree.add_edge(t, s, w);\n  }\n  auto ret = tree.run();\n  long long\
    \ ans = 0;\n  for (int i = 0; i < n; i++) ans = max(ans, ret[i]);\n  cout << ans\
    \ << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Graph/ReRooting.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
