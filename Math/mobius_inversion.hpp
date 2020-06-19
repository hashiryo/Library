/**
 * @title メビウス反転公式
 * @category 数学
 * @see https://maspypy.com/yukicoder-no-886-direct
 * @see https://yukicoder.me/problems/no/1019/editorial
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
 * @see https://yukicoder.me/wiki/sum_totient
 * @brief メモ化再帰で実装(map使ってるのでlogがつく)
 * @brief k==1ならO(N^(3/4)) (g,bの計算量無視)
 * @brief O(N^((k+2)/(k+1)^2))ぐらい?
 */

// input H,W,g,b,k
// output f(H,W)
//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])
//       b(d) = a(1)+a(2)+...+a(d)

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename T, typename G, typename B>
T mobius_inversion(int64_t H, int64_t W, const G &g, const B &b, int k = 1) {
  static map<pair<int64_t, int64_t>, T> memo;
  if (memo.count(make_pair(H, W))) return memo[make_pair(H, W)];
  T ret = g(H, W);
  int64_t d = 2;
  while (true) {
    int64_t Hd = H / pow(d, k), Wd = W / pow(d, k);
    if (!Hd || !Wd) break;
    int64_t next_d
        = min(pow(1. * H / Hd, 1. / k), pow(1. * W / Wd, 1. / k)) + 1;
    T r = mobius_inversion<T>(Hd, Wd, g, b, k);
    ret -= r * (b(next_d - 1) - b(d - 1));
    d = next_d;
  }
  return memo[make_pair(H, W)] = ret;
}