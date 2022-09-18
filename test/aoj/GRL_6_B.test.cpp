#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"
#include <bits/stdc++.h>
#include "src/Optimization/MinCostFlow.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V, E, F;
  cin >> V >> E >> F;
  MinCostFlow<NetworkSimplex, int, int> graph(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph.add_edge(u, v, 0, c, d);
  }
  graph.add_supply(0, F), graph.add_demand(V - 1, F);
  cout << (graph.b_flow() ? graph.get_result_value() : -1) << endl;
  return 0;
}