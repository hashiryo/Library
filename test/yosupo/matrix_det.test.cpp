// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
#include <iostream>
#include "src/LinearAlgebra/LU_Decomposition.hpp"
#include "src/Math/ModInt.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using Mint= ModInt<998244353>;
 int N;
 cin >> N;
 Matrix<Mint> A(N, N);
 for (int i= 0; i < N; i++)
  for (int j= 0; j < N; j++) cin >> A[i][j];
 cout << LU_Decomposition(A).det() << '\n';
 return 0;
}