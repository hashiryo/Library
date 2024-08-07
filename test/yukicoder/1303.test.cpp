// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1303
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "src/Math/ModInt.hpp"
#include "src/LinearAlgebra/characteristic_polynomial.hpp"
#include "src/DataStructure/UnionFind.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using Mint= ModInt<998244353>;
 int N, M;
 cin >> N >> M;
 Matrix<Mint> L(N, N);
 UnionFind uf(N);
 int u[M], v[M];
 for (int i= 0; i < M; ++i) cin >> u[i] >> v[i], uf.unite(--u[i], --v[i]), L[u[i]][v[i]]-= 1, L[v[i]][u[i]]-= 1, L[u[i]][u[i]]+= 1, L[v[i]][v[i]]+= 1;
 if (uf.size(0) == N) {  // connected
  Matrix<Mint> M1(N, N);
  for (int i= N; i--;)
   for (int j= i; j--;)
    if (L[i][j] == 0) M1[i][j]-= 1, M1[j][i]-= 1, M1[i][i]+= 1, M1[j][j]+= 1;
  vector<int> p(N - 1);
  iota(p.begin(), p.end(), 0);
  auto poly= det_of_first_degree_poly_mat(L.submatrix(p, p), M1.submatrix(p, p));
  cout << 0 << '\n';
  cout << poly[0] + poly[1] << '\n';
 } else {  // unconnected
  int fuben= 0, cnt= 0, mx= 0;
  for (int i= N; i--;)
   for (int j= N; j--;) fuben+= !uf.same(i, j);
  for (int i= N; i--;)
   for (int j= i; j--;)
    if (!uf.same(i, j)) {
     if (int s= uf.size(i) * uf.size(j); mx < s) mx= s, cnt= 1;
     else if (mx == s) ++cnt;
    }
  cout << fuben - mx * 2 << '\n';
  vector<int> vs[N];
  for (int i= 0; i < N; ++i) vs[uf.root(i)].push_back(i);
  Mint ans= cnt;
  for (int i= 0; i < N; ++i)
   if (int n= vs[i].size(); n != 0) {
    vs[i].pop_back();
    ans*= characteristic_polynomial(L.submatrix(vs[i], vs[i]) * -1)[0];
   }
  cout << ans << '\n';
 }
 return 0;
}
