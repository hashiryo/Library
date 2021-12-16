---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Algorithm/PushRelabel.hpp
    title: PushRelabel(Gap)
  - icon: ':heavy_check_mark:'
    path: src/Algorithm/monge_mincut.hpp
    title: "\u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\u4E00\
      \u822C\u5316"
  - icon: ':heavy_check_mark:'
    path: src/Graph/MaxFlow.hpp
    title: "\u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc129/tasks/arc129_e
    links:
    - https://atcoder.jp/contests/arc129/tasks/arc129_e
  bundledCode: "#line 1 \"test/atcoder/arc129_e.PushRelabel.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc129/tasks/arc129_e\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Algorithm/PushRelabel.hpp\"\n/**\n * @title PushRelabel(Gap)\n *\
    \ @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(n^2 \u221Am)\n */\n\n\
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
    \  }\n};\n#line 3 \"src/Graph/MaxFlow.hpp\"\n/**\n * @title \u6700\u5927\u6D41\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\n * @category \u30B0\u30E9\u30D5\
    \n * \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Dinic\u7B49)\u306Fclass\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\u3067\u53D7\u3051\u53D6\u308B\n * EdgePtr:\n *  change_cap:\
    \ \u5BB9\u91CF\u3092\u5909\u66F4, \u305D\u308C\u306B\u4F34\u3046\u30D5\u30ED\u30FC\
    \u306E\u306F\u307F\u51FA\u3057\u3092\u51FA\u529B\n * \u53CC\u65B9\u5411\u8FBA\u3082\
    \u53EF\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename FlowAlgo>\nstruct MaxFlow\
    \ : public FlowAlgo {\n  using FlowAlgo::FlowAlgo;\n  using Edge = typename FlowAlgo::Edge;\n\
    \  using flow_t = decltype(Edge::cap);\n  int add_vertex() { return this->adj.resize(++this->n),\
    \ this->n - 1; }\n  std::vector<int> add_vertices(const std::size_t size) {\n\
    \    std::vector<int> ret(size);\n    std::iota(ret.begin(), ret.end(), this->n);\n\
    \    return this->adj.resize(this->n += size), ret;\n  }\n  struct EdgePtr {\n\
    \    friend class MaxFlow;\n    MaxFlow *instance;\n    int v, e;\n    bool bidir;\n\
    \    Edge &edge() { return instance->adj[v][e]; }\n    Edge &rev() {\n      Edge\
    \ &e = edge();\n      return instance->adj[e.dst][e.rev];\n    }\n    EdgePtr(MaxFlow\
    \ *instance, int v, int e, bool d)\n        : instance(instance), v(v), e(e),\
    \ bidir(d) {}\n\n   public:\n    EdgePtr() = default;\n    int src() { return\
    \ v; }\n    int dst() { return edge().dst; }\n    bool is_direct() const { return\
    \ !bidir; }\n    flow_t flow() { return cap() - edge().cap; }\n    flow_t cap()\
    \ { return (edge().cap + rev().cap) / (1 + bidir); }\n    flow_t change_cap(flow_t\
    \ new_cap, int s, int t) {\n      assert(0 <= new_cap);\n      Edge &e = edge(),\
    \ &re = rev();\n      flow_t diff = new_cap - cap(), extrusion = std::abs(flow())\
    \ - new_cap;\n      if (extrusion <= 0) return e.cap += diff, re.cap += diff *\
    \ bidir, 0;\n      int sr = src(), ds = dst();\n      if (flow() < 0) std::swap(sr,\
    \ ds);\n      if (bidir) {\n        if (sr == src())\n          re.cap += 2 *\
    \ diff + e.cap, e.cap = 0;\n        else\n          e.cap += 2 * diff + re.cap,\
    \ re.cap = 0;\n      } else\n        re.cap += diff;\n      extrusion -= instance->maxflow(sr,\
    \ ds, extrusion);\n      if (ds != t) instance->maxflow(t, ds, extrusion);\n \
    \     if (sr != s) instance->maxflow(sr, s, extrusion);\n      return extrusion;\n\
    \    }\n  };\n  EdgePtr add_edge(int src, int dst, flow_t cap, bool bidir = false)\
    \ {\n    assert(0 <= src && src < this->n);\n    assert(0 <= dst && dst < this->n);\n\
    \    assert(0 <= cap);\n    int e = this->adj[src].size();\n    int re = src ==\
    \ dst ? e + 1 : this->adj[dst].size();\n    this->adj[src].push_back(Edge{dst,\
    \ re, cap});\n    this->adj[dst].push_back(Edge{src, e, cap * bidir});\n    return\
    \ this->m++, EdgePtr{this, src, e, bidir};\n  }\n  flow_t maxflow(int s, int t)\
    \ {\n    return maxflow(s, t, std::numeric_limits<flow_t>::max());\n  }\n  flow_t\
    \ maxflow(int s, int t, flow_t flow_lim) {\n    return this->flow(s, t, flow_lim);\n\
    \  }\n  std::vector<bool> mincut(int s) {\n    std::vector<bool> visited(this->n);\n\
    \    static std::queue<int> que;\n    for (que.push(s); !que.empty();) {\n   \
    \   int p = que.front();\n      que.pop(), visited[p] = true;\n      for (const\
    \ auto &e : this->adj[p])\n        if (e.cap && !visited[e.dst]) visited[e.dst]\
    \ = true, que.push(e.dst);\n    }\n    return visited;\n  }\n};\n#line 3 \"src/Algorithm/monge_mincut.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\
    \u306E\u4E00\u822C\u5316\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\
    \ * @see https://noshi91.hatenablog.com/entry/2021/06/29/044225\n */\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename T, typename MF, typename Th, typename Ph>\nauto\
    \ monge_mincut(int n, int k, Th theta, Ph phi) {\n  static_assert(std::is_same_v<T,\
    \ typename MF::flow_t>);\n  static constexpr T INF = std::numeric_limits<T>::max();\n\
    \  T ret = 0;\n  MF graph;\n  int s = graph.add_vertex(), t = graph.add_vertex();\n\
    \  std::vector<std::vector<int>> x;\n  std::vector<std::vector<T>> th(n, std::vector<T>(k));\n\
    \  for (int i = 0; i < n; i++) {\n    x.emplace_back(graph.add_vertices(k - 1));\n\
    \    for (int l = 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1], INF);\n\
    \    for (int l = 0; l < k; l++) th[i][l] = theta(i, l);\n  }\n  for (int i =\
    \ 0; i < n; i++)\n    for (int j = i + 1; j < n; j++) {\n      for (int l = 0;\
    \ l < k - 1; l++)\n        for (int m = 0; m < k - 1; m++) {\n          T cost\
    \ = -phi(i, j, l + 1, m + 1) + phi(i, j, l, m + 1) +\n                   phi(i,\
    \ j, l + 1, m) - phi(i, j, l, m);\n          assert(cost >= 0);  // monge\n  \
    \        if (cost > 0) graph.add_edge(x[i][l], x[j][m], cost);\n        }\n  \
    \    for (int l = 0; l < k; l++) th[i][l] += phi(i, j, l, k - 1);\n      for (int\
    \ l = 0; l < k; l++) th[j][l] += phi(i, j, 0, l);\n      ret -= phi(i, j, 0, k\
    \ - 1);\n    }\n  for (int i = 0; i < n; i++) {\n    ret += th[i][0];\n    for\
    \ (int l = 0; l < k - 1; l++) {\n      T cost = th[i][l] - th[i][l + 1];\n   \
    \   if (cost > 0) graph.add_edge(s, x[i][l], cost), ret -= cost;\n      if (cost\
    \ < 0) graph.add_edge(x[i][l], t, -cost);\n    }\n  }\n  ret += graph.maxflow(s,\
    \ t);\n  auto y = graph.mincut(s);\n  std::vector<int> sol(n, k - 1);\n  for (int\
    \ i = 0; i < n; i++)\n    for (int l = 0; l < k - 1; l++)\n      if (!y[x[i][l]])\
    \ sol[i] = l, l = k;\n  return std::make_pair(ret, sol);\n}\n#line 7 \"test/atcoder/arc129_e.PushRelabel.test.cpp\"\
    \nusing namespace std;\n\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using MF =\
    \ MaxFlow<PushRelabel<long long>>;\n  int N, M;\n  cin >> N >> M;\n  vector<vector<long\
    \ long>> A(N, vector<long long>(M)),\n      C(N, vector<long long>(M));\n  for\
    \ (int i = 0; i < N; i++)\n    for (int k = 0; k < M; k++) cin >> A[i][k] >> C[i][k];\n\
    \  vector<vector<long long>> W(N, vector<long long>(N));\n  for (int i = 0; i\
    \ < N; i++)\n    for (int j = i + 1; j < N; j++) cin >> W[i][j];\n  auto theta\
    \ = [&](int i, int k) { return C[i][k]; };\n  auto phi = [&](int i, int j, int\
    \ k, int l) {\n    return abs(A[i][k] - A[j][l]) * W[i][j];\n  };\n  auto [ans,\
    \ x] = monge_mincut<long long, MF>(N, M, theta, phi);\n  cout << ans << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc129/tasks/arc129_e\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Algorithm/PushRelabel.hpp\"\n#include\
    \ \"src/Graph/MaxFlow.hpp\"\n#include \"src/Algorithm/monge_mincut.hpp\"\nusing\
    \ namespace std;\n\n// \u89E3\u7121\u3057\u306E\u5224\u5B9A\u306Everify\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using MF = MaxFlow<PushRelabel<long\
    \ long>>;\n  int N, M;\n  cin >> N >> M;\n  vector<vector<long long>> A(N, vector<long\
    \ long>(M)),\n      C(N, vector<long long>(M));\n  for (int i = 0; i < N; i++)\n\
    \    for (int k = 0; k < M; k++) cin >> A[i][k] >> C[i][k];\n  vector<vector<long\
    \ long>> W(N, vector<long long>(N));\n  for (int i = 0; i < N; i++)\n    for (int\
    \ j = i + 1; j < N; j++) cin >> W[i][j];\n  auto theta = [&](int i, int k) { return\
    \ C[i][k]; };\n  auto phi = [&](int i, int j, int k, int l) {\n    return abs(A[i][k]\
    \ - A[j][l]) * W[i][j];\n  };\n  auto [ans, x] = monge_mincut<long long, MF>(N,\
    \ M, theta, phi);\n  cout << ans << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Algorithm/PushRelabel.hpp
  - src/Graph/MaxFlow.hpp
  - src/Algorithm/monge_mincut.hpp
  isVerificationFile: true
  path: test/atcoder/arc129_e.PushRelabel.test.cpp
  requiredBy: []
  timestamp: '2021-12-16 14:12:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc129_e.PushRelabel.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc129_e.PushRelabel.test.cpp
- /verify/test/atcoder/arc129_e.PushRelabel.test.cpp.html
title: test/atcoder/arc129_e.PushRelabel.test.cpp
---
