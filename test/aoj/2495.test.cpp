// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2495
// competitive-verifier: ERROR 0.000000001
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
#include <iostream>
#include <vector>
#include "src/Geometry/intersection_area.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using namespace geo;
 using Real= long double;
 int N, R;
 cin >> N >> R;
 vector<Point<Real>> ps(N);
 for (int i= 0; i < N; ++i) cin >> ps[i];
 Polygon g(ps);
 Real ans= 0, pre= 0;
 for (int r= 1; r <= R; ++r) {
  Circle<Real> c({0, 0}, r - 1), d({0, 0}, r);
  Real cur= intersection_area(g, d);
  Real b= cur - pre;
  if (r & 1) ans+= b;
  else ans+= d.area() - c.area() - b;
  pre= cur;
 }
 cout << fixed << setprecision(10) << ans << '\n';
 return 0;
}