#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Spring/2397"

#include <iostream>
#include <vector>
#include <utility>
#include "src/LinearAlgebra/SparseSquareMatrix.hpp"
#include "src/Math/ModInt.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using Mint= ModInt<int(1e9 + 9)>;
 long long W, H, N;
 for (int cnt= 0; cin >> W >> H >> N && W;) {
  pair<long long, int> obst[N];
  for (long long i= 0, x, y; i < N; i++) cin >> x >> y, obst[i]= make_pair(y - 1, x - 1);
  sort(obst, obst + N);
  SparseSquareMatrix<Mint> A(W);
  for (int i= 0; i < W; i++) {
   A.add_component(i, i, 1);
   if (i) A.add_component(i, i - 1, 1);
   if (i + 1 < W) A.add_component(i, i + 1, 1);
  }
  vector<Mint> b(W);
  b[0]= 1;
  long long y= 0;
  for (int i= 0; i < N; i++) {
   b= MinimalPolynomial(A, b).pow(obst[i].first - y);
   int j= i;
   while (j < N && obst[i].first == obst[j].first) b[obst[j++].second]= 0;
   i= j - 1;
   y= obst[i].first;
  }
  b= MinimalPolynomial(A, b).pow(H - 1 - y);
  cout << "Case " << ++cnt << ": " << b[W - 1] << '\n';
 }
 return 0;
}