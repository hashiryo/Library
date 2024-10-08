// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/430
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
#include <iostream>
#include <vector>
#include <string>
#include "src/String/AhoCorasick.hpp"
using namespace std;
int main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 string S;
 cin >> S;
 int n= S.length();
 int M;
 cin >> M;
 vector<string> C(M);
 for (int i= 0; i < M; i++) cin >> C[i];
 AhoCorasick ac(C);
 int ans= 0;
 for (int i= 0, s= ac.initial_state(); i < n; i++) {
  int ns= ac.transition(s, S[i]);
  ans+= ac.matched_patterns(ns).size();
  s= ns;
 }
 cout << ans << '\n';
 return 0;
}