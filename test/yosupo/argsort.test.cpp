#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include <bits/stdc++.h>
#include "src/Geometry/!geometry_temp.hpp"
#include "src/Geometry/arg_sort.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using namespace geometry;
  int N;
  cin >> N;
  vector<Point> ps(N);
  for (int i = 0; i < N; i++) cin >> ps[i];
  sort(ps.begin(), ps.end(), polar_angle());
  for (Point p : ps) cout << (long long)p.x << " " << (long long)p.y << endl;
  return 0;
}