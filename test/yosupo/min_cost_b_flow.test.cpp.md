---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/MinCostFlow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"test/yosupo/min_cost_b_flow.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Graph/MinCostFlow.hpp\"\n/**\n * @title \u6700\u5C0F\u8CBB\u7528\
    \u6D41\n * @category \u30B0\u30E9\u30D5\n *  PrimalDual(\u5BB9\u91CF\u30B9\u30B1\
    \u30FC\u30EA\u30F3\u30B0)\n *  O(m^2 log U log n)\n * @see https://misawa.github.io/others/flow/library_design.html\n\
    \ */\n// verify\u7528:\n// https://codeforces.com/contest/316/problem/C2\n// (Radix-Heap\u3067\
    \u306A\u3044\u3068TLE\u3057\u305F -> \u5BB9\u91CF\u30B9\u30B1\u30FC\u30EA\u30F3\
    \u30B0\u306A\u3089TLE\u3057\u306A\u3044)\n// https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b\
    \ (\u30B3\u30B9\u30C8\u5B9F\u6570)\n\n// BEGIN CUT HERE\n\ntemplate <class flow_t,\
    \ class cost_t,\n          typename Heap = std::priority_queue<\n            \
    \  std::pair<cost_t, int>, std::vector<std::pair<cost_t, int>>,\n            \
    \  std::greater<>>,\n          int obj = 1>\nclass MinCostFlow {\n  class Edge\
    \ {\n    friend class MinCostFlow;\n    int dst;\n    flow_t flow, cap;\n    cost_t\
    \ cost;\n    int rev;\n\n   public:\n    Edge() = default;\n    Edge(const int\
    \ dst, const flow_t cap, const cost_t cost, const int rev)\n        : dst(dst),\
    \ flow(0), cap(cap), cost(cost), rev(rev) {}\n    flow_t residual_cap() const\
    \ { return cap - flow; }\n  };\n\n public:\n  class EdgePtr {\n    friend class\
    \ MinCostFlow;\n    const MinCostFlow *instance;\n    int v;\n    int e;\n   \
    \ EdgePtr(const MinCostFlow *const instance, const int v, const int e)\n     \
    \   : instance(instance), v(v), e(e) {}\n    const Edge &edge() const { return\
    \ instance->adj[v][e]; }\n    const Edge &rev() const {\n      const Edge &e =\
    \ edge();\n      return instance->adj[e.dst][e.rev];\n    }\n\n   public:\n  \
    \  EdgePtr() = default;\n    int src() const { return v; }\n    int dst() const\
    \ { return edge().dst; }\n    flow_t flow() const { return edge().flow; }\n  \
    \  flow_t lower() const { return -rev().cap; }\n    flow_t upper() const { return\
    \ edge().cap; }\n    cost_t cost() const { return edge().cost; }\n    cost_t gain()\
    \ const { return -edge().cost; }\n  };\n\n private:\n  int n;\n  std::vector<std::vector<Edge>>\
    \ adj;\n  std::vector<flow_t> b;\n\n public:\n  MinCostFlow() : n(0) {}\n  int\
    \ add_vertex() {\n    n++;\n    adj.resize(n);\n    b.resize(n);\n    return n\
    \ - 1;\n  }\n  std::vector<int> add_vertices(const int size) {\n    std::vector<int>\
    \ ret(size);\n    std::iota(ret.begin(), ret.end(), n);\n    n += size;\n    adj.resize(n);\n\
    \    b.resize(n);\n    return ret;\n  }\n  EdgePtr add_edge(const int src, const\
    \ int dst, const flow_t lower,\n                   const flow_t upper, const cost_t\
    \ cost) {\n    const int e = adj[src].size(), re = src == dst ? e + 1 : adj[dst].size();\n\
    \    assert(lower <= upper);\n    adj[src].emplace_back(Edge{dst, upper, cost\
    \ * obj, re});\n    adj[dst].emplace_back(Edge{src, -lower, -cost * obj, e});\n\
    \    return EdgePtr{this, src, e};\n  }\n  void add_supply(const int v, const\
    \ flow_t amount) { b[v] += amount; }\n  void add_demand(const int v, const flow_t\
    \ amount) { b[v] -= amount; }\n\n private:\n  const cost_t UNREACHABLE = numeric_limits<cost_t>::max();\n\
    \  const cost_t EPS = 1e-7;\n  cost_t farthest;\n  std::vector<cost_t> potential;\n\
    \  std::vector<cost_t> dist;\n  std::vector<int> excess_vs, deficit_vs;\n  std::vector<int>\
    \ prev;\n  Heap pq;\n  Edge &rev(const Edge &e) { return adj[e.dst][e.rev]; }\n\
    \  void push(Edge &e, const flow_t amount) {\n    e.flow += amount;\n    adj[e.dst][e.rev].flow\
    \ -= amount;\n  }\n  cost_t residual_cost_t(const int src, const int dst, const\
    \ Edge &e) {\n    return e.cost + potential[src] - potential[dst];\n  }\n  bool\
    \ dual(const flow_t delta) {\n    dist.assign(n, UNREACHABLE);\n    prev.assign(n,\
    \ -1);\n    excess_vs.erase(remove_if(begin(excess_vs), end(excess_vs),\n    \
    \                          [&](const int v) { return b[v] < delta; }),\n     \
    \               end(excess_vs));\n    deficit_vs.erase(remove_if(begin(deficit_vs),\
    \ end(deficit_vs),\n                               [&](const int v) { return b[v]\
    \ > -delta; }),\n                     end(deficit_vs));\n    for (const auto v\
    \ : excess_vs) pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    std::size_t\
    \ deficit_count = 0;\n    while (!pq.empty()) {\n      cost_t d;\n      int u;\n\
    \      std::tie(d, u) = pq.top();\n      pq.pop();\n      if (dist[u] - d + EPS\
    \ < 0) continue;\n      farthest = d;\n      if (b[u] <= -delta) deficit_count++;\n\
    \      if (deficit_count >= deficit_vs.size()) break;\n      for (auto &e : adj[u])\
    \ {\n        if (e.residual_cap() < delta) continue;\n        const auto v = e.dst;\n\
    \        const auto new_dist = d + residual_cost_t(u, v, e);\n        if (new_dist\
    \ - dist[v] + EPS >= 0) continue;\n        pq.emplace(dist[v] = new_dist, v);\n\
    \        prev[v] = e.rev;\n      }\n    }\n    pq = decltype(pq)();\n    for (int\
    \ v = 0; v < n; v++) potential[v] += min(dist[v], farthest);\n    return deficit_count\
    \ > 0;\n  }\n  void primal(const flow_t delta) {\n    for (const auto t : deficit_vs)\
    \ {\n      if (dist[t] - farthest - EPS > 0) continue;\n      flow_t f = -b[t];\n\
    \      int v;\n      for (v = t; prev[v] != -1;) {\n        Edge &r = adj[v][prev[v]],\
    \ &e = adj[r.dst][r.rev];\n        f = min(f, e.residual_cap());\n        v =\
    \ r.dst;\n      }\n      f = min(f, b[v]);\n      f -= f % delta;\n      if (f\
    \ <= 0) continue;\n      for (v = t; prev[v] != -1;) {\n        Edge &r = adj[v][prev[v]],\
    \ &e = adj[r.dst][r.rev];\n        push(e, f);\n        if (e.residual_cap() <=\
    \ 0) prev[v] = -1;\n        v = r.dst;\n      }\n      b[t] += f;\n      b[v]\
    \ -= f;\n    }\n  }\n  void saturate_negative(const flow_t delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es : adj)\n      for (auto &e : es) {\n\
    \        flow_t rcap = e.residual_cap();\n        rcap -= rcap % delta;\n    \
    \    int src = adj[e.dst][e.rev].dst, dst = e.dst;\n        const cost_t rcost_t\
    \ = residual_cost_t(src, dst, e);\n        if (rcost_t + EPS < 0 || rcap < 0)\
    \ {\n          push(e, rcap);\n          b[src] -= rcap;\n          b[dst] +=\
    \ rcap;\n        }\n      }\n    for (int v = 0; v < n; v++)\n      if (b[v] !=\
    \ 0) (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n  }\n\n public:\n \
    \ std::pair<bool, cost_t> flow_run() {\n    potential.resize(n);\n    flow_t inf_flow\
    \ = 1;\n    for (const auto t : b) inf_flow = std::max({inf_flow, t, -t});\n \
    \   for (const auto &es : adj)\n      for (const auto &e : es)\n        inf_flow\
    \ = std::max({inf_flow, e.residual_cap(), -e.residual_cap()});\n    flow_t delta\
    \ = 1;\n    while (delta < inf_flow) delta *= 2;\n    for (; delta; delta /= 2)\
    \ {\n      saturate_negative(delta);\n      while (dual(delta)) primal(delta);\n\
    \    }\n    cost_t value = 0;\n    for (const auto &es : adj)\n      for (const\
    \ auto &e : es) value += e.flow * e.cost;\n    value /= 2;\n    if (excess_vs.empty()\
    \ && deficit_vs.empty()) {\n      return {true, value / obj};\n    } else {\n\
    \      return {false, value / obj};\n    }\n  }\n  std::pair<bool, cost_t> st_flow_run(const\
    \ int s, const int t, flow_t flow) {\n    add_supply(s, flow);\n    add_demand(t,\
    \ flow);\n    return flow_run();\n  }\n  tuple<bool, cost_t, flow_t> max_flow_run(const\
    \ int s, const int t) {\n    assert(s != t);\n    flow_t inf_flow = abs(b[s]);\n\
    \    for (const auto &e : adj[s])\n      inf_flow += std::max(e.cap, static_cast<flow_t>(0));\n\
    \    add_edge(t, s, 0, inf_flow, 0);\n    bool status;\n    cost_t circulation_value;\n\
    \    std::tie(status, circulation_value) = flow_run();\n    if (!status) {\n \
    \     adj[s].pop_back();\n      adj[t].pop_back();\n      return {status, circulation_value,\
    \ 0};\n    }\n    inf_flow = abs(b[s]);\n    for (const auto &e : adj[s]) inf_flow\
    \ += e.residual_cap();\n    b[s] += inf_flow;\n    b[t] -= inf_flow;\n    bool\
    \ mf_status;\n    cost_t mf_value;\n    std::tie(mf_status, mf_value) = flow_run();\n\
    \    b[s] -= inf_flow;\n    b[t] += inf_flow;\n    adj[s].pop_back();\n    adj[t].pop_back();\n\
    \    return {true, mf_value, b[t]};\n  }\n  std::vector<cost_t> get_potential()\
    \ {\n    std::fill(potential.begin(), potential.end(), 0);\n    for (int i = 0;\
    \ i < n; i++)\n      for (const auto &es : adj)\n        for (const auto &e :\
    \ es)\n          if (e.residual_cap() > 0)\n            potential[e.dst] = min(potential[e.dst],\n\
    \                                   potential[adj[e.dst][e.rev].dst] + e.cost);\n\
    \    return potential;\n  }\n  template <class T>\n  T get_result_value() {\n\
    \    T value = 0;\n    for (const auto &es : adj)\n      for (const auto &e :\
    \ es) {\n        value += (T)(e.flow) * (T)(e.cost);\n      }\n    value /= (T)2;\n\
    \    return value;\n  }\n};\n\ntemplate <class flow_t, class cost_t,\n       \
    \   typename Heap = std::priority_queue<\n              std::pair<cost_t, int>,\
    \ std::vector<std::pair<cost_t, int>>,\n              std::greater<>>>\nusing\
    \ MaxGainFlow = MinCostFlow<flow_t, cost_t, Heap, -1>;\n#line 4 \"test/yosupo/min_cost_b_flow.test.cpp\"\
    \nusing namespace std;\n\nostream &operator<<(ostream &stream, const __int128_t\
    \ &v) {\n  if (v == 0) stream << \"0\";\n  __int128_t tmp;\n  if (v < 0) {\n \
    \   stream << \"-\";\n    tmp = -v;\n  } else {\n    tmp = v;\n  }\n  std::string\
    \ s;\n  while (tmp) {\n    s += '0' + (tmp % 10);\n    tmp /= 10;\n  }\n  std::reverse(s.begin(),\
    \ s.end());\n  stream << s;\n  return stream;\n}\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  using MCF = MinCostFlow<long long, long long>;\n\
    \  MCF graph;\n  vector<MCF::EdgePtr> edges;\n  int N, M;\n  cin >> N >> M;\n\
    \  graph.add_vertices(N);\n  for (int i = 0; i < N; i++) {\n    long long b;\n\
    \    cin >> b;\n    graph.add_supply(i, b);\n  }\n  for (int i = 0; i < M; i++)\
    \ {\n    long long s, t, l, u, c;\n    cin >> s >> t >> l >> u >> c;\n    edges.emplace_back(graph.add_edge(s,\
    \ t, l, u, c));\n  }\n  bool isok = graph.flow_run().first;\n  if (isok) {\n \
    \   cout << graph.get_result_value<__int128_t>() << endl;\n    auto potential\
    \ = graph.get_potential();\n    for (auto p : potential) cout << p << endl;\n\
    \    for (auto &e : edges) cout << e.flow() << endl;\n  } else {\n    cout <<\
    \ \"infeasible\" << endl;\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Graph/MinCostFlow.hpp\"\nusing namespace std;\n\
    \nostream &operator<<(ostream &stream, const __int128_t &v) {\n  if (v == 0) stream\
    \ << \"0\";\n  __int128_t tmp;\n  if (v < 0) {\n    stream << \"-\";\n    tmp\
    \ = -v;\n  } else {\n    tmp = v;\n  }\n  std::string s;\n  while (tmp) {\n  \
    \  s += '0' + (tmp % 10);\n    tmp /= 10;\n  }\n  std::reverse(s.begin(), s.end());\n\
    \  stream << s;\n  return stream;\n}\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using MCF = MinCostFlow<long long, long long>;\n  MCF graph;\n  vector<MCF::EdgePtr>\
    \ edges;\n  int N, M;\n  cin >> N >> M;\n  graph.add_vertices(N);\n  for (int\
    \ i = 0; i < N; i++) {\n    long long b;\n    cin >> b;\n    graph.add_supply(i,\
    \ b);\n  }\n  for (int i = 0; i < M; i++) {\n    long long s, t, l, u, c;\n  \
    \  cin >> s >> t >> l >> u >> c;\n    edges.emplace_back(graph.add_edge(s, t,\
    \ l, u, c));\n  }\n  bool isok = graph.flow_run().first;\n  if (isok) {\n    cout\
    \ << graph.get_result_value<__int128_t>() << endl;\n    auto potential = graph.get_potential();\n\
    \    for (auto p : potential) cout << p << endl;\n    for (auto &e : edges) cout\
    \ << e.flow() << endl;\n  } else {\n    cout << \"infeasible\" << endl;\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - src/Graph/MinCostFlow.hpp
  isVerificationFile: true
  path: test/yosupo/min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 17:01:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_cost_b_flow.test.cpp
- /verify/test/yosupo/min_cost_b_flow.test.cpp.html
title: test/yosupo/min_cost_b_flow.test.cpp
---
