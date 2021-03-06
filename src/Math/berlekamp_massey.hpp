#pragma once
#include <bits/stdc++.h>
/**
 * @title Berlekamp-Massey
 * @category 数学
 * 数列の最初のN項から、その数列を生成するN/2次以下の最小の線形漸化式を求める
 *  O(N^2)
 */

// verify用:
// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c

// BEGIN CUT HERE

// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]
// return c

template <class T>
std::vector<T> berlekamp_massey(const std::vector<T> &a) {
  const int N = (int)a.size();
  std::vector<T> b = {T(-1)}, c = {T(-1)};
  T y = T(1);
  for (int ed = 1; ed <= N; ed++) {
    int l = int(c.size()), m = int(b.size()) + 1;
    T x = 0;
    for (int i = 0; i < l; i++) x += c[i] * a[ed - l + i];
    b.emplace_back(0);
    if (x == T(0)) continue;
    T freq = x / y;
    if (l < m) {
      auto tmp = c;
      c.insert(c.begin(), m - l, T(0));
      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
      b = tmp;
      y = x;
    } else {
      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
    }
  }
  c.pop_back();
  return c;
}