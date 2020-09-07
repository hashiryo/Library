/**
 * @title 線形漸化式の高速計算
 * @category 数学
 *  O(NlogNlogk)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/Math/FormalPowerSeries.hpp"
#undef call_from_test
#endif

// b[0] = a[0], b[1] = a[1], ..., b[N-1] = a[N-1]
// b[n] = c[0] * b[n-N] + c[1] * b[n-N+1] + ... + c[N-1] * b[n-1] (n >= N)
// return b[k]

template <class Modint>
Modint kitamasa(const vector<Modint> &c, const vector<Modint> &a, uint64_t k) {
  assert(a.size() == c.size());
  int N = a.size();
  if (k < N) return a[k];
  using FPS = FormalPowerSeries<Modint>;
  uint64_t mask = (uint64_t(1) << (63 - __builtin_clzll(k))) >> 1;
  FPS f(N + 1);
  f[0] = 1;
  for (int i = 0; i < N; i++) f[N - i] = -c[i];
  FPS r({1, 0});
  if (N < 1150) {  // naive
    r = r.divrem_rev_n(f).second;
    for (; mask; mask >>= 1) {
      r *= r;
      if (k & mask) r.push_back(0);
      r = r.divrem_rev_n(f).second;
    }
  } else {
    FPS inv = f.inv(N);
    r = r.rem_rev_pre(f, inv);
    for (; mask; mask >>= 1) {
      r *= r;
      if (k & mask) r.push_back(0);
      r = r.rem_rev_pre(f, inv);
    }
  }
  Modint ret(0);
  for (int i = 0; i < N; i++) ret += r[N - i - 1] * a[i];
  return ret;
}
