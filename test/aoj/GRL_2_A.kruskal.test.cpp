#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"
#include <bits/stdc++.h>
#include "src/DataStructure/UnionFind.hpp"
#include "src/Graph/MinimumSpanningTree_Kruskal.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  MinimumSpanningTree_Kruskal<int> graph(N);
  for (int i = 0; i < M; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    graph.add_edge(s, t, w);
  }
  cout << graph.get_MST().first << endl;
  return 0;
}