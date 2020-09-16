---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/MaxFlow_Dinic.hpp
    title: "\u6700\u5927\u6D41(Dinic)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.Dinic.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    src/Graph/MaxFlow_Dinic.hpp\"\n/**\n * @title \u6700\u5927\u6D41(Dinic)\n * @category\
    \ \u30B0\u30E9\u30D5\n *   O(V^2 E)\n *  link: s->t\u30D5\u30ED\u30FC\u3067\u8FBA\
    (src,dst)\u306E\u5BB9\u91CF\u30921\u5897\u3084\u3057\u305F\u3068\u304D\u306E\u6700\
    \u5927\u6D41\u306E\u5909\u5316\n *  cut: s->t\u30D5\u30ED\u30FC\u3067\u8FBA(src,dst)\u306E\
    \u5BB9\u91CF\u30921\u6E1B\u3089\u3057\u305F\u3068\u304D\u306E\u6700\u5927\u6D41\
    \u306E\u5909\u5316\n */\n\n// \u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\
    \u6700\u5927\u6D41 https://snuke.hatenablog.com/entry/2016/07/10/043918\n#ifndef\
    \ call_from_test\n#line 12 \"src/Graph/MaxFlow_Dinic.hpp\"\nusing namespace std;\n\
    #endif\n\ntemplate <typename flow_t>\nstruct MaxFlow_Dinic {\n private:\n  struct\
    \ Edge {\n    int dst;\n    flow_t cap;\n    int rev;\n    bool isrev;\n  };\n\
    \n private:\n  static constexpr flow_t FLOW_MAX = numeric_limits<flow_t>::max()\
    \ / 2;\n  int n;\n  vector<vector<Edge>> adj;\n  vector<int> level, iter;\n\n\
    \ private:\n  int levelize(const int &s, const int &t) {\n    level.assign(n,\
    \ -1);\n    level[s] = 0;\n    queue<int> que;\n    que.push(s);\n    while (!que.empty())\
    \ {\n      int u = que.front();\n      que.pop();\n      if (u == t) break;\n\
    \      for (auto &e : adj[u]) {\n        if (e.cap > 0 && level[e.dst] < 0) {\n\
    \          que.push(e.dst);\n          level[e.dst] = level[u] + 1;\n        }\n\
    \      }\n    }\n    return level[t];\n  }\n  flow_t dfs(int u, const int &t,\
    \ flow_t cur) {\n    if (u == t) return cur;\n    for (int &i = iter[u]; i < adj[u].size();\
    \ ++i) {\n      Edge &e = adj[u][i], &r = adj[e.dst][e.rev];\n      if (e.cap\
    \ > 0 && level[u] < level[e.dst]) {\n        flow_t f = dfs(e.dst, t, min(cur,\
    \ e.cap));\n        if (f > 0) {\n          e.cap -= f;\n          r.cap += f;\n\
    \          return f;\n        }\n      }\n    }\n    return flow_t(0);\n  }\n\
    \  flow_t flow(int s, int t) {\n    if (levelize(s, t) < 0) return 0;\n    iter.assign(adj.size(),\
    \ 0);\n    return dfs(s, t, 1);\n  }\n\n public:\n  MaxFlow_Dinic() : n(0) {}\n\
    \  int add_vertex() {\n    adj.resize(++n);\n    return n - 1;\n  }\n  vector<int>\
    \ add_vertices(const int size) {\n    vector<int> ret(size);\n    iota(begin(ret),\
    \ end(ret), n);\n    n += size;\n    adj.resize(n);\n    return ret;\n  }\n  void\
    \ add_edge(int src, int dst, flow_t cap) {\n    adj[src].emplace_back((Edge){dst,\
    \ cap, (int)adj[dst].size(), 0});\n    adj[dst].emplace_back((Edge){src, 0, (int)adj[src].size()\
    \ - 1, 1});\n  }\n  flow_t max_flow(int s, int t, flow_t lim = FLOW_MAX) {\n \
    \   flow_t flow = 0;\n    while (levelize(s, t) >= 0) {\n      iter.assign(n,\
    \ 0);\n      for (flow_t f; (f = dfs(s, t, lim)) > 0;) flow += f, lim -= f;\n\
    \    }\n    return flow;\n  }\n  flow_t link(int src, int dst, int s, int t) {\n\
    \    for (auto &e : adj[src])\n      if (e.dst == dst && !e.isrev) {\n       \
    \ e.cap += 1;\n        break;\n      }\n    return flow(s, t);\n  }\n  flow_t\
    \ cut(int src, int dst, int s, int t) {\n    for (auto &e : adj[src])\n      if\
    \ (e.dst == dst && !e.isrev) {\n        flow_t diff = 0;\n        if (e.cap ==\
    \ 0) {\n          if (flow(src, dst) == 0) {\n            flow(t, dst);\n    \
    \        flow(src, s);\n            diff = -1;\n          }\n          adj[e.dst][e.rev].cap\
    \ -= 1;\n        } else {\n          e.cap -= 1;\n        }\n        return diff;\n\
    \      }\n    assert(false);  // no edge\n  }\n  void output() {\n    for (int\
    \ i = 0; i < adj.size(); i++) {\n      for (auto &e : adj[i]) {\n        if (e.isrev)\
    \ continue;\n        auto &rev_e = adj[e.dst][e.rev];\n        cerr << i << \"\
    ->\" << e.dst << \" (flow: \" << rev_e.cap << \"/\"\n             << e.cap + rev_e.cap\
    \ << \")\" << endl;\n      }\n    }\n  }\n};\n#line 9 \"test/aoj/GRL_6_A.Dinic.test.cpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, M;\n  cin >> N >> M;\n  MaxFlow_Dinic<long long> graph;\n  graph.add_vertices(N);\n\
    \  for (int i = 0; i < M; i++) {\n    int u, v;\n    long long c;\n    cin >>\
    \ u >> v >> c;\n    graph.add_edge(u, v, c);\n  }\n  cout << graph.max_flow(0,\
    \ N - 1) << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Graph/MaxFlow_Dinic.hpp\"\n#undef call_from_test\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M;\n  cin >> N >> M;\n\
    \  MaxFlow_Dinic<long long> graph;\n  graph.add_vertices(N);\n  for (int i = 0;\
    \ i < M; i++) {\n    int u, v;\n    long long c;\n    cin >> u >> v >> c;\n  \
    \  graph.add_edge(u, v, c);\n  }\n  cout << graph.max_flow(0, N - 1) << endl;\n\
    \  return 0;\n}"
  dependsOn:
  - src/Graph/MaxFlow_Dinic.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.Dinic.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.Dinic.test.cpp
- /verify/test/aoj/GRL_6_A.Dinic.test.cpp.html
title: test/aoj/GRL_6_A.Dinic.test.cpp
---
