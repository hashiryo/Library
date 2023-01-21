---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/MinCostFlow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo/assignment.mcf.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/assignment\"\n#include <iostream>\n#include <vector>\n\
    #line 3 \"src/Optimization/MinCostFlow.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <cmath>\n#include <cassert>\ntemplate <typename flow_t, typename cost_t,\
    \ std::int_least8_t obj= 1> class NetworkSimplex {\n struct Node {\n  int par,\
    \ pred;\n  flow_t sup;\n  cost_t pi;\n };\n struct Edge {\n  int u, v;\n  flow_t\
    \ low, up, flow;\n  cost_t cost;\n  std::int_least8_t state= 1;\n };\n int n,\
    \ m= 0;\n std::vector<Node> ns;\n std::vector<Edge> es;\n std::vector<int> bfs,\
    \ next, prev;\n inline void link(int u, int v) { next[u]= v, prev[v]= u; }\n inline\
    \ void link(int u, int v, int w) { link(u, v), link(v, w); }\n inline auto opp_cost(int\
    \ e) const { return es[e].cost + ns[es[e].u].pi - ns[es[e].v].pi; }\n inline void\
    \ pivot(int in_arc) {\n  int u_in= es[in_arc].u, v_in= es[in_arc].v, u, e, a=\
    \ u_in, b= v_in;\n  while (a != b) a= ns[a].par == -1 ? v_in : ns[a].par, b= ns[b].par\
    \ == -1 ? u_in : ns[b].par;\n  if (es[in_arc].state == -1) std::swap(u_in, v_in);\n\
    \  int lca= a, side= 0, u_out= -1, i= 0, S= 0;\n  flow_t delta= es[in_arc].up;\n\
    \  for (u= u_in; u != lca && delta > 0; u= ns[u].par) {\n   flow_t d= u == es[e=\
    \ ns[u].pred].v ? es[e].up - es[e].flow : es[e].flow;\n   if (delta > d) delta=\
    \ d, u_out= u, side= 1;\n  }\n  for (u= v_in; u != lca; u= ns[u].par) {\n   flow_t\
    \ d= u == es[e= ns[u].pred].u ? es[e].up - es[e].flow : es[e].flow;\n   if (delta\
    \ >= d) delta= d, u_out= u, side= -1;\n  }\n  if (delta > 0) {\n   es[in_arc].flow+=\
    \ delta*= es[in_arc].state;\n   for (u= es[in_arc].u; u != lca; u= ns[u].par)\
    \ es[e].flow+= u == es[e= ns[u].pred].u ? -delta : delta;\n   for (u= es[in_arc].v;\
    \ u != lca; u= ns[u].par) es[e].flow+= u == es[e= ns[u].pred].u ? delta : -delta;\n\
    \  }\n  if (side == 0) return es[in_arc].state*= -1, void();\n  int out_arc= ns[u_out].pred,\
    \ p;\n  es[in_arc].state= 0, es[out_arc].state= es[out_arc].flow ? -1 : 1;\n \
    \ if (side == -1) std::swap(u_in, v_in);\n  for (u= u_in; u != u_out; u= ns[u].par)\
    \ bfs[S++]= u;\n  assert(S <= n);\n  for (i= S; i--;) ns[p= ns[u].par].par= u=\
    \ bfs[i], ns[p].pred= ns[u].pred, link(prev[p], next[p]), link(prev[u + n + 1],\
    \ p, u + n + 1);\n  link(prev[u_in], next[u_in]), link(prev[v_in + n + 1], u_in,\
    \ v_in + n + 1);\n  ns[u_in].par= v_in, ns[u_in].pred= in_arc;\n  cost_t pi_delta=\
    \ u_in == es[in_arc].u ? -opp_cost(in_arc) : opp_cost(in_arc);\n  for (i= 0, S=\
    \ 1, bfs[0]= u_in; i < S; i++) {\n   ns[u= bfs[i]].pi+= pi_delta;\n   for (int\
    \ v= next[u + n + 1]; v != u + n + 1; v= next[v]) bfs[S++]= v;\n  }\n }\n void\
    \ calc() {\n  cost_t inf_cost= 1;\n  for (int e= 0; e < m; e++) es[e].flow= 0,\
    \ es[e].state= 1, es[e].up-= es[e].low, ns[es[e].u].sup-= es[e].low, ns[es[e].v].sup+=\
    \ es[e].low, inf_cost+= std::abs(es[e].cost);\n  ns[n]= {-1, -1, 0, 0}, es.resize(m\
    \ + n), bfs.resize(n + 1);\n  next.resize(2 * n + 2), std::iota(next.begin() +\
    \ n + 1, next.end(), n + 1);\n  prev.resize(2 * n + 2), std::iota(prev.begin()\
    \ + n + 1, prev.end(), n + 1);\n  for (int u= 0, e= m; u < n; u++, e++) {\n  \
    \ ns[u].par= n, ns[u].pred= e, link(prev[n + n + 1], u, n + n + 1);\n   if (auto\
    \ supply= ns[u].sup; supply >= 0) {\n    ns[u].pi= -inf_cost;\n    es[e]= {u,\
    \ n, 0, supply, supply, inf_cost, 0};\n   } else {\n    ns[u].pi= inf_cost;\n\
    \    es[e]= {n, u, 0, -supply, -supply, inf_cost, 0};\n   }\n  }\n  int block_size=\
    \ std::max(int(std::ceil(std::sqrt(m + n))), std::min(10, n + 1));\n  for (int\
    \ e= 0, in_arc, cnt, seen;; pivot(in_arc)) {\n   cost_t minimum= 0;\n   for (in_arc=\
    \ -1, cnt= block_size, seen= m + n; seen--; e= e + 1 == m + n ? 0 : e + 1) {\n\
    \    if (minimum > es[e].state * opp_cost(e)) minimum= es[e].state * opp_cost(e),\
    \ in_arc= e;\n    if (--cnt == 0 && minimum < 0) break;\n    if (cnt == 0) cnt=\
    \ block_size;\n   }\n   if (in_arc == -1) break;\n  }\n  for (int e= 0; e < m;\
    \ e++) es[e].flow+= es[e].low, es[e].up+= es[e].low, ns[es[e].u].sup+= es[e].low,\
    \ ns[es[e].v].sup-= es[e].low;\n }\npublic:\n NetworkSimplex(int n= 0): n(n),\
    \ ns(n + 1) {}\n int add_vertex() { return ns.resize(n + 2), n++; }\n std::vector<int>\
    \ add_vertices(const int size) {\n  std::vector<int> ret(size);\n  std::iota(ret.begin(),\
    \ ret.end(), n);\n  return ns.resize((n+= size) + 1), ret;\n }\n class EdgePtr\
    \ {\n  friend class NetworkSimplex;\n  const NetworkSimplex *instance;\n  int\
    \ e;\n  EdgePtr(const NetworkSimplex *const instance, const int e): instance(instance),\
    \ e(e) {}\n  const Edge &edge() const { return instance->es[e]; }\n public:\n\
    \  EdgePtr()= default;\n  int src() const { return edge().u; }\n  int dst() const\
    \ { return edge().v; }\n  flow_t flow() const { return edge().flow; }\n  flow_t\
    \ lower() const { return edge().low; }\n  flow_t upper() const { return edge().up;\
    \ }\n  cost_t cost() const { return edge().cost; }\n  cost_t gain() const { return\
    \ -edge().cost; }\n };\n EdgePtr add_edge(int u, int v, flow_t low, flow_t up,\
    \ cost_t cost) {\n  assert(0 <= u && u < n && 0 <= v && v < n);\n  es.push_back({u,\
    \ v, low, up, 0, obj * cost});\n  return EdgePtr{this, m++};\n }\n void add_supply(int\
    \ u, flow_t supply) { ns[u].sup= supply; }\n void add_demand(int u, flow_t demand)\
    \ { ns[u].sup= -demand; }\n auto get_supply(int u) const { return ns[u].sup; }\n\
    \ auto get_potential(int u) const { return ns[u].pi; }\n template <typename cost_sum_t=\
    \ cost_t> auto get_result_value() const {\n  cost_sum_t sum= 0;\n  for (int e=\
    \ 0; e < m; e++) {\n   sum+= es[e].flow * cost_sum_t(es[e].cost);\n  }\n  return\
    \ sum * obj;\n }\n bool b_flow() {\n  flow_t sum_supply= 0;\n  for (int u= 0;\
    \ u < n; u++) sum_supply+= ns[u].sup;\n  if (sum_supply != 0) return false;\n\
    \  calc();\n  for (int e= m; e < m + n; e++)\n   if (es[e].flow != 0) return es.resize(m),\
    \ false;\n  return es.resize(m), true;\n }\n};\n\ntemplate <template <class, class,\
    \ std::int_least8_t> class FlowAlgo, typename flow_t, typename cost_t> using MinCostFlow=\
    \ FlowAlgo<flow_t, cost_t, 1>;\ntemplate <template <class, class, std::int_least8_t>\
    \ class FlowAlgo, typename flow_t, typename cost_t> using MaxGainFlow= FlowAlgo<flow_t,\
    \ cost_t, -1>;\n#line 5 \"test/yosupo/assignment.mcf.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using MCF=\
    \ MinCostFlow<NetworkSimplex, long long, long long>;\n int N;\n cin >> N;\n MCF\
    \ graph;\n vector<vector<MCF::EdgePtr>> edges(N, vector<MCF::EdgePtr>(N));\n auto\
    \ v_left= graph.add_vertices(N);\n auto v_right= graph.add_vertices(N);\n for\
    \ (int i= 0; i < N; i++) {\n  graph.add_supply(v_left[i], 1);\n  graph.add_demand(v_right[i],\
    \ 1);\n }\n for (int i= 0; i < N; i++) {\n  for (int j= 0; j < N; j++) {\n   long\
    \ long A;\n   cin >> A;\n   edges[i][j]= graph.add_edge(v_left[i], v_right[j],\
    \ 0, 1, A);\n  }\n }\n graph.b_flow();\n cout << graph.get_result_value() << endl;\n\
    \ for (int i= 0; i < N; i++)\n  for (int j= 0; j < N; j++)\n   if (edges[i][j].flow())\
    \ cout << j << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Optimization/MinCostFlow.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using MCF= MinCostFlow<NetworkSimplex, long long, long long>;\n int N;\n cin\
    \ >> N;\n MCF graph;\n vector<vector<MCF::EdgePtr>> edges(N, vector<MCF::EdgePtr>(N));\n\
    \ auto v_left= graph.add_vertices(N);\n auto v_right= graph.add_vertices(N);\n\
    \ for (int i= 0; i < N; i++) {\n  graph.add_supply(v_left[i], 1);\n  graph.add_demand(v_right[i],\
    \ 1);\n }\n for (int i= 0; i < N; i++) {\n  for (int j= 0; j < N; j++) {\n   long\
    \ long A;\n   cin >> A;\n   edges[i][j]= graph.add_edge(v_left[i], v_right[j],\
    \ 0, 1, A);\n  }\n }\n graph.b_flow();\n cout << graph.get_result_value() << endl;\n\
    \ for (int i= 0; i < N; i++)\n  for (int j= 0; j < N; j++)\n   if (edges[i][j].flow())\
    \ cout << j << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  dependsOn:
  - src/Optimization/MinCostFlow.hpp
  isVerificationFile: true
  path: test/yosupo/assignment.mcf.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 21:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.mcf.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.mcf.test.cpp
- /verify/test/yosupo/assignment.mcf.test.cpp.html
title: test/yosupo/assignment.mcf.test.cpp
---
