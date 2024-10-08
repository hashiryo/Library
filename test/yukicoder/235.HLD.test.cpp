// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/235
// competitive-verifier: TLE 1
// competitive-verifier: MLE 64
#include <iostream>
#include "src/Graph/Graph.hpp"
#include "src/Graph/HeavyLightDecomposition.hpp"
#include "src/DataStructure/SegmentTree.hpp"
#include "src/Math/ModInt.hpp"
using namespace std;
using Mint= ModInt<int(1e9 + 7)>;
struct Mono {
 struct T {
  Mint S, C;
 };
 using E= Mint;
 static T ti() { return {Mint(), Mint()}; }
 static T op(const T &l, const T &r) { return {l.S + r.S, l.C + r.C}; }
 static bool mp(T &v, E x, int) { return v.S+= x * v.C, true; }
 static void cp(E &p, E s) { p+= s; }
};
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int N;
 cin >> N;
 Mint S[N], C[N];
 for (int i= 0; i < N; ++i) cin >> S[i];
 for (int i= 0; i < N; ++i) cin >> C[i];
 Graph g(N, N - 1);
 for (int i= 0; i < N - 1; ++i) cin >> g[i], --g[i];
 HeavyLightDecomposition tree(g, 0);
 vector<typename Mono::T> vec(N);
 for (int v= 0; v < N; ++v) vec[tree.to_seq(v)]= {S[v], C[v]};
 SegmentTree<Mono> seg(vec);
 int Q;
 cin >> Q;
 while (Q--) {
  int op, X, Y;
  cin >> op >> X >> Y, --X, --Y;
  if (op) {
   Mint ans= 0;
   for (auto [x, y]: tree.path(X, Y)) ans+= x < y ? seg.prod(x, y + 1).S : seg.prod(y, x + 1).S;
   cout << ans << '\n';
  } else {
   Mint Z;
   cin >> Z;
   for (auto [x, y]: tree.path(X, Y)) x < y ? seg.apply(x, y + 1, Z) : seg.apply(y, x + 1, Z);
  }
 }
 return 0;
}