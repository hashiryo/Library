#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Math/FormalPowerSeries.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  using Mint = ModInt<998244353>;
  using FPS = FormalPowerSeries<Mint>;
  FPS a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  auto b = a.exp();
  for (int i = 0; i < N; i++) cout << b[i] << (i < N - 1 ? " " : "\n");
  cout << flush;
  return 0;
}