// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_totient_function
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
// O(N^(2/3)log^(1/3)N))
#include <iostream>
#include "src/Math/ModInt.hpp"
#include "src/NumberTheory/DirichletSeries.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using Mint= ModInt<998244353>;
 long long N;
 cin >> N;
 cout << get_phi<Mint>(N).sum() << '\n';
 return 0;
}