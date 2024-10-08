// competitive-verifier: PROBLEM https://atcoder.jp/contests/arc153/tasks/arc153_b
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
// reverse の verify

#include <iostream>
#include <vector>
#include <numeric>
#include "src/DataStructure/WeightBalancedTree.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using WBT= WeightBalancedTree<int, true>;
 int H, W;
 cin >> H >> W;
 vector<string> A(H);
 for (int i= 0; i < H; ++i) cin >> A[i];
 WBT row, col;
 {
  vector<int> v(H);
  iota(v.begin(), v.end(), 0);
  row= WBT(v);
 }
 {
  vector<int> v(W);
  iota(v.begin(), v.end(), 0);
  col= WBT(v);
 }
 int Q;
 cin >> Q;
 while (Q--) {
  int a, b;
  cin >> a >> b;
  {
   auto [l, r]= row.split(a);
   l.reverse(), r.reverse();
   row= l + r;
  }
  {
   auto [l, r]= col.split(b);
   l.reverse(), r.reverse();
   col= l + r;
  }
 }
 auto row_= row.dump();
 auto col_= col.dump();
 for (int i= 0; i < H; ++i) {
  for (int j= 0; j < W; ++j) {
   cout << A[row_[i]][col_[j]];
  }
  cout << '\n';
 }
 return 0;
}