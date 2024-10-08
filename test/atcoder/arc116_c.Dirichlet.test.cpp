// competitive-verifier: PROBLEM https://atcoder.jp/contests/arc116/tasks/arc116_c
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
#include <iostream>
#include "src/Math/ModInt.hpp"
#include "src/NumberTheory/DirichletSeries.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using Mint= ModInt<998244353>;
 long long N, M;
 cin >> N >> M;
 cout << get_1<Mint>(M).pow(N).sum() << '\n';
 return 0;
}