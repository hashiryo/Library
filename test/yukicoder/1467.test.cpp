#define PROBLEM "https://yukicoder.me/problems/no/1467"
#include <iostream>
#include "src/Misc/compress.hpp"
#include "src/Optimization/PiecewiseLinearConvexfunction.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 using PLCF= PiecewiseLinearConvexfunction<>;
 int M, N;
 cin >> M >> N;
 long long A[M], B[N];
 for (int i= 0; i < M; ++i) cin >> A[i];
 for (int j= 0; j < N; ++j) cin >> B[j];
 vector<long long> vec(A, A + M);
 for (int j= 0; j < N; ++j) vec.push_back(B[j]);
 auto id= compress(vec);
 int n= vec.size();
 vector<long long> a(n), b(n);
 for (int i= 0; i < M; ++i) ++a[id(A[i])];
 for (int j= 0; j < N; ++j) ++b[id(B[j])];
 for (int k= 1; k <= M; ++k) {
  PLCF f;
  f.chinfty_left();
  for (int i= 0; i < n; ++i) {
   f.cumulative_chmin();
   f.shift(a[i] - b[i] * k);
   if (i < n - 1) f.add_abs(vec[i + 1] - vec[i], 0);
  }
  cout << f(0) << '\n';
  PLCF::clear();
 }
 return 0;
}