// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aplusb
#include <iostream>
#include <random>
#include <cassert>
#include "src/Math/Nimber.hpp"
using namespace std;
void test(int X) {
 mt19937 mt(X);
 uniform_int_distribution<uint64_t> rng(0, uint64_t(-1));
 static constexpr int N= 100000;
 static Nimber a[N], b[N];
 for (int i= 0; i < N; i++) a[i]= rng(mt), b[i]= a[i] * a[i];
 for (int i= 0; i < N; i++) {
  Nimber ans= b[i].sqrt();
  assert(ans == a[i]);
  assert(ans.val() == a[i].val());
 }
}
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 Nimber::init();
 int A, B;
 cin >> A >> B;
 test(A), test(B);
 cout << A + B << '\n';
 return 0;
}