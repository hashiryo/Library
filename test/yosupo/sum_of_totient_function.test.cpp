#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Math/dujiao_sieve.hpp"
#include "src/Math/number_theory.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  using Mint = ModInt<998244353>;
  using namespace number_theory;
  const int M = 1 << (200 / 9);
  init(M);
  auto phi = get_phi<Mint>(M);
  for (int i = 2; i < M; i++) phi[i] += phi[i - 1];
  auto g = [](int64_t N, int64_t dummy) {
    return Mint(N) * Mint(N + 1) / Mint(2);
  };
  auto b = [](int64_t d) { return Mint(d); };
  map<pair<int64_t, int64_t>, Mint> memo;
  for (int i = 1; i < M; i++) memo[make_pair(i, i)] = phi[i];
  int64_t N;
  cin >> N;
  Mint ans = dujiao_sieve<Mint>(N, N, g, b, memo);
  cout << ans << endl;
  return 0;
}