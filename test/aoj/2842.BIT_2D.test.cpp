#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"
#include <bits/stdc++.h>
#include "src/DataStructure/BinaryIndexedTree_2D.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int H, W, T, Q;
  cin >> H >> W >> T >> Q;
  vector<tuple<int, int, int, int, int, int>> query;
  while (Q--) {
    int t, c, h1, w1, h2, w2;
    cin >> t >> c >> h1 >> w1;
    if (c == 2) cin >> h2 >> w2;
    query.emplace_back(t, c, h1, w1, h2, w2);
    if (c == 0) query.emplace_back(t + T, -1, h1, w1, h2, w2);
  }
  sort(query.begin(), query.end());
  BinaryIndexedTree_2D<long long> bit1(H, W), bit2(H, W);
  for (auto q : query) {
    int t, c, h1, w1, h2, w2;
    tie(t, c, h1, w1, h2, w2) = q;
    if (c == 0) {
      if (!bit1.sum(h1 - 1, w1 - 1, h1, w1)) bit1.add(h1, w1, 1);
    } else if (c == 1) {
      if (bit2.sum(h1 - 1, w1 - 1, h1, w1)) bit2.add(h1, w1, -1);
    } else if (c == 2) {
      cout << bit2.sum(h1 - 1, w1 - 1, h2, w2) << " "
           << bit1.sum(h1 - 1, w1 - 1, h2, w2) << endl;
    } else {
      if (bit1.sum(h1 - 1, w1 - 1, h1, w1)) bit1.add(h1, w1, -1);
      if (!bit2.sum(h1 - 1, w1 - 1, h1, w1)) bit2.add(h1, w1, 1);
    }
  }
}
