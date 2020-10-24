---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/DataStructure/RadixHeap.hpp
    title: Radix-Heap
  - icon: ':x:'
    path: src/Graph/MinCostFlow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.RadixHeap.test.cpp\"\n#define PROBLEM \\\
    \n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Graph/MinCostFlow.hpp\"\n/**\n * @title \u6700\
    \u5C0F\u8CBB\u7528\u6D41\n * @category \u30B0\u30E9\u30D5\n *  PrimalDual(\u5BB9\
    \u91CF\u30B9\u30B1\u30FC\u30EA\u30F3\u30B0)\n *  O(m^2 log U log n)\n * @see https://misawa.github.io/others/flow/library_design.html\n\
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
    \ = 1;\n    for (const auto t : b) inf_flow = max({inf_flow, t, -t});\n    for\
    \ (const auto &es : adj)\n      for (const auto &e : es)\n        inf_flow = max({inf_flow,\
    \ e.residual_cap(), -e.residual_cap()});\n    flow_t delta = 1;\n    while (delta\
    \ < inf_flow) delta *= 2;\n    for (; delta; delta /= 2) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n    cost_t value = 0;\n    for\
    \ (const auto &es : adj)\n      for (const auto &e : es) value += e.flow * e.cost;\n\
    \    value /= 2;\n    if (excess_vs.empty() && deficit_vs.empty()) {\n      return\
    \ {true, value / obj};\n    } else {\n      return {false, value / obj};\n   \
    \ }\n  }\n  std::pair<bool, cost_t> st_flow_run(const int s, const int t, flow_t\
    \ flow) {\n    add_supply(s, flow);\n    add_demand(t, flow);\n    return flow_run();\n\
    \  }\n  tuple<bool, cost_t, flow_t> max_flow_run(const int s, const int t) {\n\
    \    assert(s != t);\n    flow_t inf_flow = abs(b[s]);\n    for (const auto &e\
    \ : adj[s]) inf_flow += max(e.cap, static_cast<flow_t>(0));\n    add_edge(t, s,\
    \ 0, inf_flow, 0);\n    bool status;\n    cost_t circulation_value;\n    std::tie(status,\
    \ circulation_value) = flow_run();\n    if (!status) {\n      adj[s].pop_back();\n\
    \      adj[t].pop_back();\n      return {status, circulation_value, 0};\n    }\n\
    \    inf_flow = abs(b[s]);\n    for (const auto &e : adj[s]) inf_flow += e.residual_cap();\n\
    \    b[s] += inf_flow;\n    b[t] -= inf_flow;\n    bool mf_status;\n    cost_t\
    \ mf_value;\n    std::tie(mf_status, mf_value) = flow_run();\n    b[s] -= inf_flow;\n\
    \    b[t] += inf_flow;\n    adj[s].pop_back();\n    adj[t].pop_back();\n    return\
    \ {true, mf_value, b[t]};\n  }\n  std::vector<cost_t> get_potential() {\n    std::fill(potential.begin(),\
    \ potential.end(), 0);\n    for (int i = 0; i < n; i++)\n      for (const auto\
    \ &es : adj)\n        for (const auto &e : es)\n          if (e.residual_cap()\
    \ > 0)\n            potential[e.dst] = min(potential[e.dst],\n               \
    \                    potential[adj[e.dst][e.rev].dst] + e.cost);\n    return potential;\n\
    \  }\n  template <class T>\n  T get_result_value() {\n    T value = 0;\n    for\
    \ (const auto &es : adj)\n      for (const auto &e : es) {\n        value += (T)(e.flow)\
    \ * (T)(e.cost);\n      }\n    value /= (T)2;\n    return value;\n  }\n};\n\n\
    template <class flow_t, class cost_t,\n          typename Heap = std::priority_queue<\n\
    \              std::pair<cost_t, int>, std::vector<std::pair<cost_t, int>>,\n\
    \              std::greater<>>>\nusing MaxGainFlow = MinCostFlow<flow_t, cost_t,\
    \ Heap, -1>;\n#line 3 \"src/DataStructure/RadixHeap.hpp\"\n/**\n * @title Radix-Heap\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief dijkstra\u306E\u9AD8\u901F\
    \u5316\u306B\u4F7F\u7528\n * @brief \u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3082\
    \u4F7F\u3048\u308B\n * @brief \u5C0F\u3055\u3044\u9806\n * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md\n\
    \ */\n\n// verify\u7528:\n// https://codeforces.com/contest/316/problem/C2\n//\
    \ (Radix-Heap\u3067\u306A\u3044\u3068TLE\u3057\u305F -> \u5BB9\u91CF\u30B9\u30B1\
    \u30FC\u30EA\u30F3\u30B0\u306A\u3089TLE\u3057\u306A\u3044)\n\n// BEGIN CUT HERE\n\
    \nnamespace internal {\ntemplate <bool Is64bit>\nclass find_bucket_impl;\ntemplate\
    \ <>\nclass find_bucket_impl<false> {\n public:\n  static inline constexpr std::size_t\
    \ find_bucket(uint32_t x, uint32_t last) {\n    return x == last ? 0 : 32 - __builtin_clz(x\
    \ ^ last);\n  }\n};\ntemplate <>\nclass find_bucket_impl<true> {\n public:\n \
    \ static inline constexpr std::size_t find_bucket(uint64_t x, uint64_t last) {\n\
    \    return x == last ? 0 : 64 - __builtin_clzll(x ^ last);\n  }\n};\ntemplate\
    \ <typename T>\ninline constexpr std::size_t find_bucket(T x, T last) {\n  return\
    \ find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);\n}\ntemplate <typename\
    \ key_t, bool IsSigned>\nclass encoder_impl_integer;\ntemplate <typename key_t>\n\
    class encoder_impl_integer<key_t, false> {\n public:\n  using ukey_t = key_t;\n\
    \  inline static constexpr ukey_t encode(key_t x) { return x; }\n  inline static\
    \ constexpr key_t decode(ukey_t x) { return x; }\n};\ntemplate <typename key_t>\n\
    class encoder_impl_integer<key_t, true> {\n public:\n  typedef typename make_unsigned<key_t>::type\
    \ ukey_t;\n  inline static constexpr ukey_t encode(key_t x) {\n    return static_cast<ukey_t>(x)\n\
    \           ^ (ukey_t(1) << ukey_t(std::numeric_limits<ukey_t>::digits - 1));\n\
    \  }\n  inline static constexpr key_t decode(ukey_t x) {\n    return static_cast<key_t>(\n\
    \        x ^ (ukey_t(1) << (std::numeric_limits<ukey_t>::digits - 1)));\n  }\n\
    };\ntemplate <typename key_t, typename ukey_t>\nclass encoder_impl_decimal {\n\
    \ public:\n  inline static constexpr ukey_t encode(key_t x) {\n    return raw_cast<key_t,\
    \ ukey_t>(x)\n           ^ ((-(raw_cast<key_t, ukey_t>(x)\n                 >>\
    \ (std::numeric_limits<ukey_t>::digits - 1)))\n              | (ukey_t(1) << (std::numeric_limits<ukey_t>::digits\
    \ - 1)));\n  }\n  inline static constexpr key_t decode(ukey_t x) {\n    return\
    \ raw_cast<ukey_t, key_t>(\n        x\n        ^ (((x >> (std::numeric_limits<ukey_t>::digits\
    \ - 1)) - 1)\n           | (ukey_t(1) << (std::numeric_limits<ukey_t>::digits\
    \ - 1))));\n  }\n\n private:\n  template <typename T, typename U>\n  union raw_cast\
    \ {\n   public:\n    constexpr raw_cast(T t) : t_(t) {}\n    operator U() const\
    \ { return u_; }\n\n   private:\n    T t_;\n    U u_;\n  };\n};\ntemplate <typename\
    \ key_t>\nclass encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value>\
    \ {};\ntemplate <>\nclass encoder<float> : public encoder_impl_decimal<float,\
    \ uint32_t> {};\ntemplate <>\nclass encoder<double> : public encoder_impl_decimal<double,\
    \ uint64_t> {};\n}  // namespace internal\n\ntemplate <typename key_t, typename\
    \ val_t,\n          typename encoder_t = internal::encoder<key_t>>\nclass RadixHeap\
    \ {\n public:\n  typedef typename encoder_t::ukey_t ukey_t;\n\n  RadixHeap() :\
    \ size_(0), last_(), buckets_() {\n    buckets_min_.fill(std::numeric_limits<ukey_t>::max());\n\
    \  }\n\n  void push(key_t key, val_t value) {\n    const ukey_t x = encoder_t::encode(key);\n\
    \    assert(last_ <= x);\n    ++size_;\n    const std::size_t k = internal::find_bucket(x,\
    \ last_);\n    buckets_[k].emplace_back(x, value);\n    buckets_min_[k] = std::min(buckets_min_[k],\
    \ x);\n  }\n  void emplace(key_t key, val_t value) { push(key, value); }\n  std::pair<key_t,\
    \ val_t> top() {\n    pull();\n    return std::make_pair(encoder_t::decode(last_),\
    \ buckets_[0].back().second);\n  }\n  std::pair<key_t, val_t> pop() {\n    pull();\n\
    \    --size_;\n    auto ret\n        = std::make_pair(encoder_t::decode(last_),\
    \ buckets_[0].back().second);\n    buckets_[0].pop_back();\n    return ret;\n\
    \  }\n  std::size_t size() const { return size_; }\n  bool empty() const { return\
    \ size_ == 0; }\n\n private:\n  std::size_t size_;\n  ukey_t last_;\n  std::array<std::vector<std::pair<ukey_t,\
    \ val_t>>,\n             std::numeric_limits<ukey_t>::digits + 1>\n      buckets_;\n\
    \  std::array<ukey_t, std::numeric_limits<ukey_t>::digits + 1> buckets_min_;\n\
    \n  void pull() {\n    assert(size_ > 0);\n    if (!buckets_[0].empty()) return;\n\
    \    std::size_t i = 1;\n    while (buckets_[i].empty()) ++i;\n    last_ = buckets_min_[i];\n\
    \    for (std::size_t j = 0; j < buckets_[i].size(); ++j) {\n      const ukey_t\
    \ x = buckets_[i][j].first;\n      const std::size_t k = internal::find_bucket(x,\
    \ last_);\n      buckets_[k].emplace_back(move(buckets_[i][j]));\n      buckets_min_[k]\
    \ = std::min(buckets_min_[k], x);\n    }\n    buckets_[i].clear();\n    buckets_min_[i]\
    \ = std::numeric_limits<ukey_t>::max();\n  }\n};\n#line 6 \"test/aoj/GRL_6_B.RadixHeap.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int V, E, F;\n  cin >> V >> E >> F;\n  MinCostFlow<int, int, RadixHeap<int,\
    \ int>> graph;\n  graph.add_vertices(V);\n  while (E--) {\n    int u, v, c, d;\n\
    \    cin >> u >> v >> c >> d;\n    graph.add_edge(u, v, 0, c, d);\n  }\n  auto\
    \ ans = graph.st_flow_run(0, V - 1, F);\n  cout << (ans.first ? ans.second : -1)\
    \ << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n#include <bits/stdc++.h>\n#include \"src/Graph/MinCostFlow.hpp\"\n#include \"\
    src/DataStructure/RadixHeap.hpp\"\nusing namespace std;\n\nsigned main() {\n \
    \ cin.tie(0);\n  ios::sync_with_stdio(0);\n  int V, E, F;\n  cin >> V >> E >>\
    \ F;\n  MinCostFlow<int, int, RadixHeap<int, int>> graph;\n  graph.add_vertices(V);\n\
    \  while (E--) {\n    int u, v, c, d;\n    cin >> u >> v >> c >> d;\n    graph.add_edge(u,\
    \ v, 0, c, d);\n  }\n  auto ans = graph.st_flow_run(0, V - 1, F);\n  cout << (ans.first\
    \ ? ans.second : -1) << endl;\n  return 0;\n}"
  dependsOn:
  - src/Graph/MinCostFlow.hpp
  - src/DataStructure/RadixHeap.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.RadixHeap.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 16:23:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.RadixHeap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.RadixHeap.test.cpp
- /verify/test/aoj/GRL_6_B.RadixHeap.test.cpp.html
title: test/aoj/GRL_6_B.RadixHeap.test.cpp
---
