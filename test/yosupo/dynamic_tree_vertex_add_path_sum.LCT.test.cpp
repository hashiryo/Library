#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"
#include <bits/stdc++.h>
#include "src/DataStructure/LinkCutTree_Monoid.hpp"
using namespace std;

struct RsumQ {
  using T = long long;
  static T ti() { return 0; }
  static T f(const T &l, const T &r) { return l + r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  LinkCutTree_Monoid<RsumQ> lct(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    lct.set_val(i, a);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    lct.link(v, u);
  }
  while (Q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int u, v, w, x;
      cin >> u >> v >> w >> x;
      lct.cut(u, v);
      lct.link(w, x);
    } else if (op == 1) {
      int p;
      long long x;
      cin >> p >> x;
      lct.set_val(p, lct[p] + x);
    } else {
      int u, v;
      cin >> u >> v;
      cout << lct.query(u, v) << endl;
    }
  }
  return 0;
}
