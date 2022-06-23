---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.PushRelabel.test.cpp
    title: test/aoj/1615.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.PushRelabel.test.cpp
    title: test/aoj/2313.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2803.PushRelabel.test.cpp
    title: test/aoj/2803.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2835.PushRelabel.test.cpp
    title: test/aoj/2835.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.PushRelabel.test.cpp
    title: test/aoj/GRL_6_A.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.PushRelabel.test.cpp
    title: test/atcoder/arc107_f.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.PushRelabel.test.cpp
    title: test/atcoder/arc129_e.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/119.PushRelabel.test.cpp
    title: test/yukicoder/119.PushRelabel.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: PushRelabel(Gap)
    links:
    - https://loj.ac/p/127
  bundledCode: "#line 2 \"src/Algorithm/PushRelabel.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title PushRelabel(Gap)\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \n *  O(n^2 \u221Am)\n */\n\n// verify\u7528: https://loj.ac/p/127 (Dinic\u3060\
    \u3068\u843D\u3061\u308B)\n// BEGIN CUT HERE\n\ntemplate <class flow_t, unsigned\
    \ global_freq = 4, bool use_gap = true,\n          bool freeze = false>\nstruct\
    \ PushRelabel {\n  PushRelabel(std::size_t _n = 0) : n(_n), m(0), adj(n) {}\n\n\
    \ protected:\n  struct Edge {\n    int dst, rev;\n    flow_t cap;\n  };\n  int\
    \ n, gap, m;\n  struct Hque {\n    std::vector<std::pair<int, int>> even, odd;\n\
    \    int se, so;\n    void init(int _n) { even.resize(_n), odd.resize(_n), se\
    \ = so = 0; };\n    void clear() { se = so = 0; }\n    bool empty() const { return\
    \ se + so == 0; }\n    void push(int i, int h) { (h & 1 ? odd[so++] : even[se++])\
    \ = {i, h}; }\n    int highest() const {\n      int a = se ? even[se - 1].second\
    \ : -1, b = so ? odd[so - 1].second : -1;\n      return a > b ? a : b;\n    }\n\
    \    int pop() {\n      if (!se || (so && odd[so - 1].second > even[se - 1].second))\n\
    \        return odd[--so].first;\n      return even[--se].first;\n    }\n  } hque;\n\
    \  std::vector<std::vector<Edge>> adj;\n  std::vector<int> dist, dcnt;\n  std::vector<flow_t>\
    \ excess;\n  inline void calc(int t) {\n    if constexpr (global_freq != 0) global_relabeling(t);\n\
    \    for (int tick = m * global_freq; !hque.empty();) {\n      int i = hque.pop(),\
    \ dnxt = n * 2 - 1;\n      if constexpr (use_gap)\n        if (dist[i] > gap)\
    \ continue;\n      for (auto &e : adj[i])\n        if (e.cap) {\n          if\
    \ (dist[e.dst] == dist[i] - 1) {\n            if (push(i, e), excess[i] == 0)\
    \ break;\n          } else if (dist[e.dst] + 1 < dnxt)\n            dnxt = dist[e.dst]\
    \ + 1;\n        }\n      if (excess[i] > 0) {\n        if constexpr (use_gap)\
    \ {\n          if (dnxt != dist[i] && dcnt[dist[i]] == 1 && dist[i] < gap)\n \
    \           gap = dist[i];\n          if (dnxt == gap) gap++;\n          while\
    \ (hque.highest() > gap) hque.pop();\n          if (dnxt > gap) dnxt = n;\n  \
    \        if (dist[i] != dnxt) dcnt[dist[i]]--, dcnt[dnxt]++;\n        }\n    \
    \    dist[i] = dnxt, hq_push(i);\n      }\n      if constexpr (global_freq !=\
    \ 0)\n        if (--tick == 0) tick = m * global_freq, global_relabeling(t);\n\
    \    }\n  }\n  inline void hq_push(int i) {\n    if constexpr (!use_gap)\n   \
    \   hque.push(i, dist[i]);\n    else if (dist[i] < gap)\n      hque.push(i, dist[i]);\n\
    \  }\n  inline void push(int i, Edge &e) {\n    flow_t delta = std::min(e.cap,\
    \ excess[i]);\n    excess[i] -= delta, e.cap -= delta;\n    excess[e.dst] += delta,\
    \ adj[e.dst][e.rev].cap += delta;\n    if (0 < excess[e.dst] && excess[e.dst]\
    \ <= delta) hq_push(e.dst);\n  }\n  inline void global_relabeling(int t) {\n \
    \   dist.assign(n, n), dist[t] = 0;\n    static std::queue<int> q;\n    q.push(t),\
    \ hque.clear();\n    if constexpr (use_gap) gap = 1, dcnt.assign(n + 1, 0);\n\
    \    for (int now; !q.empty();) {\n      now = q.front(), q.pop();\n      if constexpr\
    \ (use_gap) gap = dist[now] + 1, dcnt[dist[now]]++;\n      if (excess[now] > 0)\
    \ hque.push(now, dist[now]);\n      for (const auto &e : adj[now])\n        if\
    \ (adj[e.dst][e.rev].cap && dist[e.dst] == n)\n          dist[e.dst] = dist[now]\
    \ + 1, q.push(e.dst);\n    }\n  }\n  flow_t flow(int s, int t, flow_t flow_lim)\
    \ {\n    assert(0 <= s && s < n);\n    assert(0 <= t && t < n);\n    assert(s\
    \ != t);\n    hque.init(n);\n    excess.assign(n, 0);\n    excess[s] += flow_lim,\
    \ excess[t] -= flow_lim;\n    dist.assign(n, 0), dist[s] = n;\n    if constexpr\
    \ (use_gap) gap = 1, dcnt.assign(n + 1, 0), dcnt[0] = n - 1;\n    for (auto &e\
    \ : adj[s]) push(s, e);\n    calc(t);\n    flow_t ret = excess[t] + flow_lim;\n\
    \    if constexpr (!freeze) {\n      excess[s] += excess[t], excess[t] = 0;\n\
    \      if constexpr (global_freq != 0) global_relabeling(s);\n      calc(s);\n\
    \      assert(excess == std::vector<flow_t>(n, 0));\n    }\n    return ret;\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title PushRelabel(Gap)\n\
    \ * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(n^2 \u221Am)\n */\n\n\
    // verify\u7528: https://loj.ac/p/127 (Dinic\u3060\u3068\u843D\u3061\u308B)\n\
    // BEGIN CUT HERE\n\ntemplate <class flow_t, unsigned global_freq = 4, bool use_gap\
    \ = true,\n          bool freeze = false>\nstruct PushRelabel {\n  PushRelabel(std::size_t\
    \ _n = 0) : n(_n), m(0), adj(n) {}\n\n protected:\n  struct Edge {\n    int dst,\
    \ rev;\n    flow_t cap;\n  };\n  int n, gap, m;\n  struct Hque {\n    std::vector<std::pair<int,\
    \ int>> even, odd;\n    int se, so;\n    void init(int _n) { even.resize(_n),\
    \ odd.resize(_n), se = so = 0; };\n    void clear() { se = so = 0; }\n    bool\
    \ empty() const { return se + so == 0; }\n    void push(int i, int h) { (h & 1\
    \ ? odd[so++] : even[se++]) = {i, h}; }\n    int highest() const {\n      int\
    \ a = se ? even[se - 1].second : -1, b = so ? odd[so - 1].second : -1;\n     \
    \ return a > b ? a : b;\n    }\n    int pop() {\n      if (!se || (so && odd[so\
    \ - 1].second > even[se - 1].second))\n        return odd[--so].first;\n     \
    \ return even[--se].first;\n    }\n  } hque;\n  std::vector<std::vector<Edge>>\
    \ adj;\n  std::vector<int> dist, dcnt;\n  std::vector<flow_t> excess;\n  inline\
    \ void calc(int t) {\n    if constexpr (global_freq != 0) global_relabeling(t);\n\
    \    for (int tick = m * global_freq; !hque.empty();) {\n      int i = hque.pop(),\
    \ dnxt = n * 2 - 1;\n      if constexpr (use_gap)\n        if (dist[i] > gap)\
    \ continue;\n      for (auto &e : adj[i])\n        if (e.cap) {\n          if\
    \ (dist[e.dst] == dist[i] - 1) {\n            if (push(i, e), excess[i] == 0)\
    \ break;\n          } else if (dist[e.dst] + 1 < dnxt)\n            dnxt = dist[e.dst]\
    \ + 1;\n        }\n      if (excess[i] > 0) {\n        if constexpr (use_gap)\
    \ {\n          if (dnxt != dist[i] && dcnt[dist[i]] == 1 && dist[i] < gap)\n \
    \           gap = dist[i];\n          if (dnxt == gap) gap++;\n          while\
    \ (hque.highest() > gap) hque.pop();\n          if (dnxt > gap) dnxt = n;\n  \
    \        if (dist[i] != dnxt) dcnt[dist[i]]--, dcnt[dnxt]++;\n        }\n    \
    \    dist[i] = dnxt, hq_push(i);\n      }\n      if constexpr (global_freq !=\
    \ 0)\n        if (--tick == 0) tick = m * global_freq, global_relabeling(t);\n\
    \    }\n  }\n  inline void hq_push(int i) {\n    if constexpr (!use_gap)\n   \
    \   hque.push(i, dist[i]);\n    else if (dist[i] < gap)\n      hque.push(i, dist[i]);\n\
    \  }\n  inline void push(int i, Edge &e) {\n    flow_t delta = std::min(e.cap,\
    \ excess[i]);\n    excess[i] -= delta, e.cap -= delta;\n    excess[e.dst] += delta,\
    \ adj[e.dst][e.rev].cap += delta;\n    if (0 < excess[e.dst] && excess[e.dst]\
    \ <= delta) hq_push(e.dst);\n  }\n  inline void global_relabeling(int t) {\n \
    \   dist.assign(n, n), dist[t] = 0;\n    static std::queue<int> q;\n    q.push(t),\
    \ hque.clear();\n    if constexpr (use_gap) gap = 1, dcnt.assign(n + 1, 0);\n\
    \    for (int now; !q.empty();) {\n      now = q.front(), q.pop();\n      if constexpr\
    \ (use_gap) gap = dist[now] + 1, dcnt[dist[now]]++;\n      if (excess[now] > 0)\
    \ hque.push(now, dist[now]);\n      for (const auto &e : adj[now])\n        if\
    \ (adj[e.dst][e.rev].cap && dist[e.dst] == n)\n          dist[e.dst] = dist[now]\
    \ + 1, q.push(e.dst);\n    }\n  }\n  flow_t flow(int s, int t, flow_t flow_lim)\
    \ {\n    assert(0 <= s && s < n);\n    assert(0 <= t && t < n);\n    assert(s\
    \ != t);\n    hque.init(n);\n    excess.assign(n, 0);\n    excess[s] += flow_lim,\
    \ excess[t] -= flow_lim;\n    dist.assign(n, 0), dist[s] = n;\n    if constexpr\
    \ (use_gap) gap = 1, dcnt.assign(n + 1, 0), dcnt[0] = n - 1;\n    for (auto &e\
    \ : adj[s]) push(s, e);\n    calc(t);\n    flow_t ret = excess[t] + flow_lim;\n\
    \    if constexpr (!freeze) {\n      excess[s] += excess[t], excess[t] = 0;\n\
    \      if constexpr (global_freq != 0) global_relabeling(s);\n      calc(s);\n\
    \      assert(excess == std::vector<flow_t>(n, 0));\n    }\n    return ret;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Algorithm/PushRelabel.hpp
  requiredBy: []
  timestamp: '2021-12-16 14:12:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/119.PushRelabel.test.cpp
  - test/atcoder/arc129_e.PushRelabel.test.cpp
  - test/atcoder/arc107_f.PushRelabel.test.cpp
  - test/aoj/2803.PushRelabel.test.cpp
  - test/aoj/2313.PushRelabel.test.cpp
  - test/aoj/GRL_6_A.PushRelabel.test.cpp
  - test/aoj/2835.PushRelabel.test.cpp
  - test/aoj/1615.PushRelabel.test.cpp
documentation_of: src/Algorithm/PushRelabel.hpp
layout: document
redirect_from:
- /library/src/Algorithm/PushRelabel.hpp
- /library/src/Algorithm/PushRelabel.hpp.html
title: PushRelabel(Gap)
---
