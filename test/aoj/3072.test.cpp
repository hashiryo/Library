// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/3072
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 256
#include <iostream>
#include <vector>
#include "src/Math/ModInt.hpp"
#include "src/FFT/fps_inv.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using Mint= ModInt<998244353>;
 int N, K, P;
 cin >> N >> K >> P;
 Mint p= Mint(P) / 100, q= Mint(1) - p;
 vector<Mint> f(N + 1, -p * p / N);
 f[0]= p, f.resize(K);
 auto g= inv<Mint, 1 << 20>(f);
 Mint ans= 1;
 for (int i= 1; i < K; i++) ans-= g[i] * q;
 cout << ans << '\n';
 return 0;
}