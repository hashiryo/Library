#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include <bits/stdc++.h>
#include "src/Math/Sieve.hpp"
#include "src/Math/ModInt.hpp"

using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Mint = StaticModInt<998244353>;
  int N;
  cin >> N;
  vector<Mint> a(N + 1), b(N + 1);
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 1; i <= N; i++) cin >> b[i];
  auto c = Sieve<>::gcd_conv(a, b);
  for (int i = 1; i <= N; i++) cout << c[i] << " \n"[i == N];
  return 0;
}