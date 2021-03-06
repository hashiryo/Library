#define PROBLEM "https://yukicoder.me/problems/no/803"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Math/GaussianElimination.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using GE = GaussianElimination;
  int N, M, X;
  cin >> N >> M >> X;
  vector<vector<bool>> A(30 + M, vector<bool>(N));
  vector<bool> b(30 + M);
  for (int i = 0; i < 30; i++) b[i] = (X >> i) & 1;
  for (int j = 0; j < N; j++) {
    int a;
    cin >> a;
    for (int i = 0; i < 30; i++) A[i][j] = (a >> i) & 1;
  }
  for (int i = 0; i < M; i++) {
    int l, r, x;
    cin >> x >> l >> r, b[30 + i] = x;
    for (int j = l - 1; j <= r - 1; j++) A[30 + i][j] = 1;
  }
  auto ans = GE::linear_equations(A, b);
  if (ans.first.size())
    cout << ModInt<int(1e9 + 7)>(2).pow(ans.second.size()) << endl;
  else
    cout << 0 << endl;
  return 0;
}