---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test/aoj/2313.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.Dinic.test.cpp
    title: test/aoj/GRL_6_A.Dinic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41(Dinic)"
    links:
    - https://snuke.hatenablog.com/entry/2016/07/10/043918
  bundledCode: "#line 2 \"src/Graph/MaxFlow_Dinic.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5927\u6D41(Dinic)\n * @category \u30B0\u30E9\u30D5\n *\
    \   O(V^2 E)\n *  link: s->t\u30D5\u30ED\u30FC\u3067\u8FBA(src,dst)\u306E\u5BB9\
    \u91CF\u30921\u5897\u3084\u3057\u305F\u3068\u304D\u306E\u6700\u5927\u6D41\u306E\
    \u5909\u5316\n *  cut: s->t\u30D5\u30ED\u30FC\u3067\u8FBA(src,dst)\u306E\u5BB9\
    \u91CF\u30921\u6E1B\u3089\u3057\u305F\u3068\u304D\u306E\u6700\u5927\u6D41\u306E\
    \u5909\u5316\n */\n\n// \u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\
    \u5927\u6D41 https://snuke.hatenablog.com/entry/2016/07/10/043918\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename flow_t>\nstruct MaxFlow_Dinic {\n private:\n\
    \  struct Edge {\n    int dst;\n    flow_t cap;\n    int rev;\n    bool isrev;\n\
    \  };\n\n private:\n  static constexpr flow_t FLOW_MAX = std::numeric_limits<flow_t>::max()\
    \ / 2;\n  int n;\n  std::vector<std::vector<Edge>> adj;\n  std::vector<int> level,\
    \ iter;\n\n private:\n  int levelize(const int &s, const int &t) {\n    level.assign(n,\
    \ -1);\n    level[s] = 0;\n    std::queue<int> que;\n    que.push(s);\n    while\
    \ (!que.empty()) {\n      int u = que.front();\n      que.pop();\n      if (u\
    \ == t) break;\n      for (auto &e : adj[u]) {\n        if (e.cap > 0 && level[e.dst]\
    \ < 0) {\n          que.push(e.dst);\n          level[e.dst] = level[u] + 1;\n\
    \        }\n      }\n    }\n    return level[t];\n  }\n  flow_t dfs(int u, const\
    \ int &t, flow_t cur) {\n    if (u == t) return cur;\n    for (int &i = iter[u];\
    \ i < adj[u].size(); ++i) {\n      Edge &e = adj[u][i], &r = adj[e.dst][e.rev];\n\
    \      if (e.cap > 0 && level[u] < level[e.dst]) {\n        flow_t f = dfs(e.dst,\
    \ t, std::min(cur, e.cap));\n        if (f > 0) {\n          e.cap -= f;\n   \
    \       r.cap += f;\n          return f;\n        }\n      }\n    }\n    return\
    \ flow_t(0);\n  }\n  flow_t flow(int s, int t) {\n    if (levelize(s, t) < 0)\
    \ return 0;\n    iter.assign(adj.size(), 0);\n    return dfs(s, t, 1);\n  }\n\n\
    \ public:\n  MaxFlow_Dinic() : n(0) {}\n  int add_vertex() {\n    adj.resize(++n);\n\
    \    return n - 1;\n  }\n  std::vector<int> add_vertices(const int size) {\n \
    \   std::vector<int> ret(size);\n    std::iota(ret.begin(), ret.end(), n);\n \
    \   n += size;\n    adj.resize(n);\n    return ret;\n  }\n  void add_edge(int\
    \ src, int dst, flow_t cap) {\n    adj[src].emplace_back((Edge){dst, cap, (int)adj[dst].size(),\
    \ 0});\n    adj[dst].emplace_back((Edge){src, 0, (int)adj[src].size() - 1, 1});\n\
    \  }\n  flow_t max_flow(int s, int t, flow_t lim = FLOW_MAX) {\n    flow_t flow\
    \ = 0;\n    while (levelize(s, t) >= 0) {\n      iter.assign(n, 0);\n      for\
    \ (flow_t f; (f = dfs(s, t, lim)) > 0;) flow += f, lim -= f;\n    }\n    return\
    \ flow;\n  }\n  flow_t link(int src, int dst, int s, int t) {\n    for (auto &e\
    \ : adj[src])\n      if (e.dst == dst && !e.isrev) {\n        e.cap += 1;\n  \
    \      break;\n      }\n    return flow(s, t);\n  }\n  flow_t cut(int src, int\
    \ dst, int s, int t) {\n    for (auto &e : adj[src])\n      if (e.dst == dst &&\
    \ !e.isrev) {\n        flow_t diff = 0;\n        if (e.cap == 0) {\n         \
    \ if (flow(src, dst) == 0) {\n            flow(t, dst);\n            flow(src,\
    \ s);\n            diff = -1;\n          }\n          adj[e.dst][e.rev].cap -=\
    \ 1;\n        } else {\n          e.cap -= 1;\n        }\n        return diff;\n\
    \      }\n    assert(false);  // no edge\n  }\n  void output() {\n    for (int\
    \ i = 0; i < adj.size(); i++) {\n      for (auto &e : adj[i]) {\n        if (e.isrev)\
    \ continue;\n        auto &rev_e = adj[e.dst][e.rev];\n        std::cerr << i\
    \ << \"->\" << e.dst << \" (flow: \" << rev_e.cap << \"/\"\n                 \
    \ << e.cap + rev_e.cap << \")\" << '\\n';\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5927\u6D41\
    (Dinic)\n * @category \u30B0\u30E9\u30D5\n *   O(V^2 E)\n *  link: s->t\u30D5\u30ED\
    \u30FC\u3067\u8FBA(src,dst)\u306E\u5BB9\u91CF\u30921\u5897\u3084\u3057\u305F\u3068\
    \u304D\u306E\u6700\u5927\u6D41\u306E\u5909\u5316\n *  cut: s->t\u30D5\u30ED\u30FC\
    \u3067\u8FBA(src,dst)\u306E\u5BB9\u91CF\u30921\u6E1B\u3089\u3057\u305F\u3068\u304D\
    \u306E\u6700\u5927\u6D41\u306E\u5909\u5316\n */\n\n// \u6700\u5C0F\u6D41\u91CF\
    \u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41 https://snuke.hatenablog.com/entry/2016/07/10/043918\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename flow_t>\nstruct MaxFlow_Dinic {\n private:\n\
    \  struct Edge {\n    int dst;\n    flow_t cap;\n    int rev;\n    bool isrev;\n\
    \  };\n\n private:\n  static constexpr flow_t FLOW_MAX = std::numeric_limits<flow_t>::max()\
    \ / 2;\n  int n;\n  std::vector<std::vector<Edge>> adj;\n  std::vector<int> level,\
    \ iter;\n\n private:\n  int levelize(const int &s, const int &t) {\n    level.assign(n,\
    \ -1);\n    level[s] = 0;\n    std::queue<int> que;\n    que.push(s);\n    while\
    \ (!que.empty()) {\n      int u = que.front();\n      que.pop();\n      if (u\
    \ == t) break;\n      for (auto &e : adj[u]) {\n        if (e.cap > 0 && level[e.dst]\
    \ < 0) {\n          que.push(e.dst);\n          level[e.dst] = level[u] + 1;\n\
    \        }\n      }\n    }\n    return level[t];\n  }\n  flow_t dfs(int u, const\
    \ int &t, flow_t cur) {\n    if (u == t) return cur;\n    for (int &i = iter[u];\
    \ i < adj[u].size(); ++i) {\n      Edge &e = adj[u][i], &r = adj[e.dst][e.rev];\n\
    \      if (e.cap > 0 && level[u] < level[e.dst]) {\n        flow_t f = dfs(e.dst,\
    \ t, std::min(cur, e.cap));\n        if (f > 0) {\n          e.cap -= f;\n   \
    \       r.cap += f;\n          return f;\n        }\n      }\n    }\n    return\
    \ flow_t(0);\n  }\n  flow_t flow(int s, int t) {\n    if (levelize(s, t) < 0)\
    \ return 0;\n    iter.assign(adj.size(), 0);\n    return dfs(s, t, 1);\n  }\n\n\
    \ public:\n  MaxFlow_Dinic() : n(0) {}\n  int add_vertex() {\n    adj.resize(++n);\n\
    \    return n - 1;\n  }\n  std::vector<int> add_vertices(const int size) {\n \
    \   std::vector<int> ret(size);\n    std::iota(ret.begin(), ret.end(), n);\n \
    \   n += size;\n    adj.resize(n);\n    return ret;\n  }\n  void add_edge(int\
    \ src, int dst, flow_t cap) {\n    adj[src].emplace_back((Edge){dst, cap, (int)adj[dst].size(),\
    \ 0});\n    adj[dst].emplace_back((Edge){src, 0, (int)adj[src].size() - 1, 1});\n\
    \  }\n  flow_t max_flow(int s, int t, flow_t lim = FLOW_MAX) {\n    flow_t flow\
    \ = 0;\n    while (levelize(s, t) >= 0) {\n      iter.assign(n, 0);\n      for\
    \ (flow_t f; (f = dfs(s, t, lim)) > 0;) flow += f, lim -= f;\n    }\n    return\
    \ flow;\n  }\n  flow_t link(int src, int dst, int s, int t) {\n    for (auto &e\
    \ : adj[src])\n      if (e.dst == dst && !e.isrev) {\n        e.cap += 1;\n  \
    \      break;\n      }\n    return flow(s, t);\n  }\n  flow_t cut(int src, int\
    \ dst, int s, int t) {\n    for (auto &e : adj[src])\n      if (e.dst == dst &&\
    \ !e.isrev) {\n        flow_t diff = 0;\n        if (e.cap == 0) {\n         \
    \ if (flow(src, dst) == 0) {\n            flow(t, dst);\n            flow(src,\
    \ s);\n            diff = -1;\n          }\n          adj[e.dst][e.rev].cap -=\
    \ 1;\n        } else {\n          e.cap -= 1;\n        }\n        return diff;\n\
    \      }\n    assert(false);  // no edge\n  }\n  void output() {\n    for (int\
    \ i = 0; i < adj.size(); i++) {\n      for (auto &e : adj[i]) {\n        if (e.isrev)\
    \ continue;\n        auto &rev_e = adj[e.dst][e.rev];\n        std::cerr << i\
    \ << \"->\" << e.dst << \" (flow: \" << rev_e.cap << \"/\"\n                 \
    \ << e.cap + rev_e.cap << \")\" << '\\n';\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/MaxFlow_Dinic.hpp
  requiredBy: []
  timestamp: '2020-10-24 15:28:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.Dinic.test.cpp
  - test/aoj/2313.test.cpp
documentation_of: src/Graph/MaxFlow_Dinic.hpp
layout: document
redirect_from:
- /library/src/Graph/MaxFlow_Dinic.hpp
- /library/src/Graph/MaxFlow_Dinic.hpp.html
title: "\u6700\u5927\u6D41(Dinic)"
---
