#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1132"
#include <bits/stdc++.h>
#include "src/Geometry/!geometry_temp.hpp"
#include "src/Geometry/circle_functions.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using namespace geometry;
  int N;
  while (cin >> N && N) {
    vector<Point> ps(N);
    for (int i = 0; i < N; i++) cin >> ps[i];
    cout << max_circle_cover(ps, 1).first << endl;
  }
  return 0;
}