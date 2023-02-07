#define PROBLEM "https://yukicoder.me/problems/no/1868"
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include "src/Graph/RangeToRangeGraph.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int N;
 cin >> N;
 RangeToRangeGraph<int> r2r(N);
 for (int i= 1; i < N; ++i) {
  int R;
  cin >> R;
  r2r.add_to_range(i - 1, i, R, 1);
 }
 int n= r2r.node_size();
 vector<pair<int, int>> adj[n];
 for (auto [s, t, w]: r2r.get_edges()) adj[s].emplace_back(t, w);
 deque<int> dq;
 int dist[n], used[n];
 fill_n(dist, n, 1 << 30);
 fill_n(used, n, 0);
 dist[0]= 0;
 dq.push_back(0);
 while (!dq.empty()) {
  int v= dq.front();
  dq.pop_front();
  if (v == N - 1) break;
  if (used[v]) continue;
  used[v]= true;
  for (auto [u, c]: adj[v]) {
   if (dist[u] > dist[v] + c) {
    dist[u]= dist[v] + c;
    if (c) dq.push_back(u);
    else dq.push_front(u);
   }
  }
 }
 cout << dist[N - 1] << '\n';
 return 0;
}