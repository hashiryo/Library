#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>
#include "src/String/KnuthMorrisPratt.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string T, P;
  cin >> T >> P;
  KnuthMorrisPratt KMP(P);
  auto ans = KMP.pattern_match(T);
  for (auto a : ans) {
    cout << a << "\n";
  }
  cout << flush;
  return 0;
}