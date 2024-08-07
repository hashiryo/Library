// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc296/tasks/abc296_g
#include <iostream>
#include "src/Geometry/IncrementalConvexHull.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using namespace geo;
 int N;
 cin >> N;
 IncrementalConvexHull<long long> ch;
 for (int i= 0; i < N; ++i) {
  Point<long long> p;
  cin >> p;
  ch.insert(p);
 }
 int Q;
 cin >> Q;
 while (Q--) {
  Point<long long> p;
  cin >> p;
  int ans= ch.where(p);
  cout << (ans > 0 ? "IN" : ans < 0 ? "OUT" : "ON") << '\n';
 }
 return 0;
}