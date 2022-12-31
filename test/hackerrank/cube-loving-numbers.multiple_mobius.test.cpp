#define PROBLEM \
  "https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers"
#include <bits/stdc++.h>
#include "src/Math/Sieve.hpp"
// 倍数メビウス
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  long long f[1'000'010];
  while (T--) {
    long long N, a = 2, ans = 0;
    cin >> N;
    for (; a * a * a <= N; a++) f[a] = N / (a * a * a);
    vector<long long> g(f, f + a);
    Sieve<>::multiple_mobius(g);
    for (; --a >= 2;) ans += g[a];
    cout << ans << '\n';
  }
  return 0;
}