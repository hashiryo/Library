#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Math/DirichletConvSumTable.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  using Mint = StaticModInt<998244353>;
  long long N;
  cin >> N;
  cout << get_phi<Mint>(N, powl(N, 2. / 3)).sum() << '\n';
  return 0;
}