// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
#include <iostream>
#include <vector>
#include "src/DataStructure/SparseTable.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int N, Q;
 cin >> N >> Q;
 vector<int> a(N);
 for (int i= 0; i < N; ++i) cin >> a[i];
 SparseTable st(a, [](int l, int r) { return min(l, r); });
 while (Q--) {
  int l, r;
  cin >> l >> r;
  cout << st.prod(l, r) << '\n';
 }
 return 0;
}