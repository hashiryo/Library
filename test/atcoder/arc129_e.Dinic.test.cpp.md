---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/Dinic.hpp
    title: Dinic
  - icon: ':question:'
    path: src/Optimization/MaxFlow.hpp
    title: "\u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
  - icon: ':question:'
    path: src/Optimization/monge_mincut.hpp
    title: "\u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\u4E00\
      \u822C\u5316"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc129/tasks/arc129_e
    links:
    - https://atcoder.jp/contests/arc129/tasks/arc129_e
  bundledCode: "#line 1 \"test/atcoder/arc129_e.Dinic.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc129/tasks/arc129_e\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Optimization/Dinic.hpp\"\n/**\n * @title Dinic\n * @category \u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(n^2 m)\n * @see https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class flow_t>\nstruct Dinic {\n  Dinic(std::size_t\
    \ _n = 0) : n(_n), m(0), adj(n) {}\n\n protected:\n  struct Edge {\n    int dst,\
    \ rev;\n    flow_t cap;\n  };\n  int n, m;\n  std::vector<std::vector<Edge>> adj;\n\
    \  std::vector<int> level, iter;\n  inline void levelize(const int &s, const int\
    \ &t) {\n    level.assign(n, -1), level[s] = 0;\n    std::queue<int> que;\n  \
    \  for (que.push(s); !que.empty();) {\n      int u = que.front();\n      que.pop();\n\
    \      for (auto &e : adj[u])\n        if (e.cap > 0 && level[e.dst] < 0) {\n\
    \          level[e.dst] = level[u] + 1;\n          if (e.dst == t) return;\n \
    \         que.push(e.dst);\n        }\n    }\n  }\n  inline flow_t dfs(int u,\
    \ const int &s, flow_t cur) {\n    if (u == s) return cur;\n    flow_t ret = 0;\n\
    \    for (int &i = iter[u]; i < int(adj[u].size()); i++) {\n      Edge &e = adj[u][i],\
    \ &re = adj[e.dst][e.rev];\n      if (level[u] <= level[e.dst] || re.cap == 0)\
    \ continue;\n      flow_t f = dfs(e.dst, s, std::min(cur - ret, re.cap));\n  \
    \    if (f <= 0) continue;\n      e.cap += f, re.cap -= f, ret += f;\n      if\
    \ (ret == cur) return ret;\n    }\n    return level[u] = n, ret;\n  }\n  flow_t\
    \ flow(int s, int t, flow_t flow_lim) {\n    assert(0 <= s && s < n);\n    assert(0\
    \ <= t && t < n);\n    assert(s != t);\n    flow_t ret = 0;\n    for (flow_t f;\
    \ ret < flow_lim; ret += f) {\n      if (levelize(s, t), level[t] == -1) break;\n\
    \      iter.assign(n, 0);\n      if (!(f = dfs(t, s, flow_lim - ret))) break;\n\
    \    }\n    return ret;\n  }\n};\n#line 3 \"src/Optimization/MaxFlow.hpp\"\n/**\n\
    \ * @title \u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\n\
    \ * @category \u30B0\u30E9\u30D5\n * \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Dinic\u7B49\
    )\u306Fclass\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3067\u53D7\u3051\u53D6\u308B\
    \n * EdgePtr:\n *  change_cap: \u5BB9\u91CF\u3092\u5909\u66F4, \u305D\u308C\u306B\
    \u4F34\u3046\u30D5\u30ED\u30FC\u306E\u306F\u307F\u51FA\u3057\u3092\u51FA\u529B\
    \n * \u53CC\u65B9\u5411\u8FBA\u3082\u53EF\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename FlowAlgo>\nstruct MaxFlow : public FlowAlgo {\n  using FlowAlgo::FlowAlgo;\n\
    \  using Edge = typename FlowAlgo::Edge;\n  using flow_t = decltype(Edge::cap);\n\
    \  int add_vertex() { return this->adj.resize(++this->n), this->n - 1; }\n  std::vector<int>\
    \ add_vertices(const std::size_t size) {\n    std::vector<int> ret(size);\n  \
    \  std::iota(ret.begin(), ret.end(), this->n);\n    return this->adj.resize(this->n\
    \ += size), ret;\n  }\n  struct EdgePtr {\n    friend class MaxFlow;\n    MaxFlow\
    \ *instance;\n    int v, e;\n    bool bidir;\n    Edge &edge() { return instance->adj[v][e];\
    \ }\n    Edge &rev() {\n      Edge &e = edge();\n      return instance->adj[e.dst][e.rev];\n\
    \    }\n    EdgePtr(MaxFlow *instance, int v, int e, bool d)\n        : instance(instance),\
    \ v(v), e(e), bidir(d) {}\n\n   public:\n    EdgePtr() = default;\n    int src()\
    \ { return v; }\n    int dst() { return edge().dst; }\n    bool is_direct() const\
    \ { return !bidir; }\n    flow_t flow() { return cap() - edge().cap; }\n    flow_t\
    \ cap() { return (edge().cap + rev().cap) / (1 + bidir); }\n    flow_t change_cap(flow_t\
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
    \ = true, que.push(e.dst);\n    }\n    return visited;\n  }\n};\n#line 3 \"src/Optimization/monge_mincut.hpp\"\
    \n/**\n * @title \u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\
    \u306E\u4E00\u822C\u5316\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\
    \ * @see https://noshi91.hatenablog.com/entry/2021/06/29/044225\n * phi\u95A2\u6570\
    \u7B49\u3067 \u221E \u3092\u8FD4\u3059\u3068\u304D\u306F\u305D\u306E\u5927\u304D\
    \u3055\u306B\u6CE8\u610F (\u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC)\n */\n\n// verify\u7528: https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename MF, typename Th, typename Ph>\nauto\
    \ monge_mincut(int n, int k, Th theta, Ph phi) {\n  using T = typename MF::flow_t;\n\
    \  static constexpr T INF = std::numeric_limits<T>::max();\n  T ret = 0;\n  MF\
    \ graph;\n  int s = graph.add_vertex(), t = graph.add_vertex();\n  std::vector<std::vector<int>>\
    \ x;\n  std::vector<std::vector<T>> th(n, std::vector<T>(k));\n  for (int i =\
    \ 0; i < n; i++) {\n    x.emplace_back(graph.add_vertices(k - 1));\n    for (int\
    \ l = 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1], INF);\n    for (int\
    \ l = 0; l < k; l++) th[i][l] = theta(i, l);\n  }\n  for (int i = 0; i < n; i++)\n\
    \    for (int j = i + 1; j < n; j++) {\n      for (int l = 0; l < k - 1; l++)\n\
    \        for (int m = 0; m < k - 1; m++) {\n          T cost = -phi(i, j, l +\
    \ 1, m + 1) + phi(i, j, l, m + 1) +\n                   phi(i, j, l + 1, m) -\
    \ phi(i, j, l, m);\n          assert(cost >= 0);  // monge\n          if (cost\
    \ > 0) graph.add_edge(x[i][l], x[j][m], cost);\n        }\n      for (int l =\
    \ 0; l < k; l++) th[i][l] += phi(i, j, l, k - 1);\n      for (int l = 0; l < k;\
    \ l++) th[j][l] += phi(i, j, 0, l);\n      ret -= phi(i, j, 0, k - 1);\n    }\n\
    \  for (int i = 0; i < n; i++) {\n    ret += th[i][0];\n    for (int l = 0; l\
    \ < k - 1; l++) {\n      T cost = th[i][l] - th[i][l + 1];\n      if (cost > 0)\
    \ graph.add_edge(s, x[i][l], cost), ret -= cost;\n      if (cost < 0) graph.add_edge(x[i][l],\
    \ t, -cost);\n    }\n  }\n  ret += graph.maxflow(s, t);\n  auto y = graph.mincut(s);\n\
    \  std::vector<int> sol(n, k - 1);\n  for (int i = 0; i < n; i++)\n    for (int\
    \ l = 0; l < k - 1; l++)\n      if (!y[x[i][l]]) sol[i] = l, l = k;\n  return\
    \ std::make_pair(ret, sol);\n}\n#line 7 \"test/atcoder/arc129_e.Dinic.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using MF = MaxFlow<Dinic<long long>>;\n  int N, M;\n  cin >> N >> M;\n  vector<vector<long\
    \ long>> A(N, vector<long long>(M)),\n      C(N, vector<long long>(M));\n  for\
    \ (int i = 0; i < N; i++)\n    for (int k = 0; k < M; k++) cin >> A[i][k] >> C[i][k];\n\
    \  vector<vector<long long>> W(N, vector<long long>(N));\n  for (int i = 0; i\
    \ < N; i++)\n    for (int j = i + 1; j < N; j++) cin >> W[i][j];\n  auto theta\
    \ = [&](int i, int xi) { return C[i][xi]; };\n  auto phi = [&](int i, int j, int\
    \ xi, int xj) {\n    return abs(A[i][xi] - A[j][xj]) * W[i][j];\n  };\n  auto\
    \ [ans, x] = monge_mincut<MF>(N, M, theta, phi);\n  cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc129/tasks/arc129_e\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Optimization/Dinic.hpp\"\n#include \"\
    src/Optimization/MaxFlow.hpp\"\n#include \"src/Optimization/monge_mincut.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using MF = MaxFlow<Dinic<long long>>;\n  int N, M;\n  cin >> N >> M;\n  vector<vector<long\
    \ long>> A(N, vector<long long>(M)),\n      C(N, vector<long long>(M));\n  for\
    \ (int i = 0; i < N; i++)\n    for (int k = 0; k < M; k++) cin >> A[i][k] >> C[i][k];\n\
    \  vector<vector<long long>> W(N, vector<long long>(N));\n  for (int i = 0; i\
    \ < N; i++)\n    for (int j = i + 1; j < N; j++) cin >> W[i][j];\n  auto theta\
    \ = [&](int i, int xi) { return C[i][xi]; };\n  auto phi = [&](int i, int j, int\
    \ xi, int xj) {\n    return abs(A[i][xi] - A[j][xj]) * W[i][j];\n  };\n  auto\
    \ [ans, x] = monge_mincut<MF>(N, M, theta, phi);\n  cout << ans << '\\n';\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Optimization/Dinic.hpp
  - src/Optimization/MaxFlow.hpp
  - src/Optimization/monge_mincut.hpp
  isVerificationFile: true
  path: test/atcoder/arc129_e.Dinic.test.cpp
  requiredBy: []
  timestamp: '2022-06-23 16:10:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc129_e.Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc129_e.Dinic.test.cpp
- /verify/test/atcoder/arc129_e.Dinic.test.cpp.html
title: test/atcoder/arc129_e.Dinic.test.cpp
---
