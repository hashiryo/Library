#define PROBLEM "https://yukicoder.me/problems/no/658"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Math/FormalPowerSeries.hpp"
#include "src/Math/kitamasa.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int Q;
  cin >> Q;
  while (Q--) {
    long long n;
    cin >> n;
    cout << kitamasa<ModInt<17>>({1, 1, 1, 1}, {0, 0, 0, 1}, n - 1) << "\n";
  }
  cout << flush;
  return 0;
}