// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
// competitive-verifier: TLE 1
// competitive-verifier: MLE 512
/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413
 */
#include <iostream>
#include <vector>
#include "src/Math/FactorialPrecalculation.hpp"
#include "src/Math/ModInt.hpp"
#include "src/NumberTheory/enumerate_primes.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using Mint= ModInt<998244353>;
 using F= FactorialPrecalculation<Mint>;
 long long r, d;
 cin >> r >> d;
 vector<Mint> sum(d + 1), rpow(d + 1), pd= pow_table<Mint>(d + 1, d);
 rpow[0]= 1, sum[0]= rpow[0] * pd[0];
 for (int i= 1; i <= d; i++) rpow[i]= rpow[i - 1] * r;
 for (int i= 1; i <= d; i++) sum[i]= sum[i - 1] + rpow[i] * pd[i];
 Mint ans= 0;
 for (int i= 0; i <= d; i++) {
  Mint tmp= F::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];
  ans+= (d - i) & 1 ? -tmp : tmp;
 }
 ans/= Mint(1 - r).pow(d + 1);
 cout << ans << '\n';
 return 0;
}