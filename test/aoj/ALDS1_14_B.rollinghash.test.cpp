#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
#include "src/String/RollingHash.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using RHMB = RollingHash_MultiBase<2>;
  string T, P;
  cin >> T >> P;
  auto base1 = RollingHash::generate_base();
  auto base2 = RollingHash::generate_base();
  RHMB rt(T, {base1, base2}), rp(P, {base1, base2});
  int N = P.length();
  for (int i = 0; i + N <= T.length(); i++)
    if (RHMB::equal(rt, rp, i, i + N, 0, N)) cout << i << "\n";
  cout << flush;
  return 0;
}