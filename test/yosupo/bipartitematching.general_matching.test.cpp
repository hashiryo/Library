// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bipartitematching
// competitive-verifier: TLE 1
// competitive-verifier: MLE 64
#include <iostream>
#include "src/Graph/Graph.hpp"
#include "src/Graph/general_matching.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int L, R, M;
 cin >> L >> R >> M;
 Graph g(L + R, M);
 for (int i= 0; i < M; ++i) cin >> g[i], g[i].second+= L;
 auto [ans, _]= general_matching(g);
 cout << ans.size() << '\n';
 for (int i: ans) {
  auto [l, r]= g[i];
  cout << l << " " << r - L << '\n';
 }
 return 0;
}