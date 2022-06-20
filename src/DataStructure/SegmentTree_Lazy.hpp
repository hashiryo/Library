#pragma once
#include <bits/stdc++.h>
/**
 * @title Segment-Tree(遅延伝搬)
 * @category データ構造
 * @brief O(logN)
 */

// BEGIN CUT HERE

template <typename M>
struct SegmentTree_Lazy {
  using T = typename M::T;
  using E = typename M::E;
  SegmentTree_Lazy() {}
  SegmentTree_Lazy(int n_)
      : n(n_),
        height(ceil(log2(n))),
        dat(n * 2, M::ti()),
        laz(n * 2, {E(), false}) {}
  SegmentTree_Lazy(int n_, T v1) : SegmentTree_Lazy(n_) {
    for (int i = n; i--;) dat[i + n] = v1;
    for (int i = n; --i;) update(i);
  }
  SegmentTree_Lazy(const std::vector<T> &v) : SegmentTree_Lazy(v.size()) {
    for (int i = n; i--;) dat[i + n] = v[i];
    for (int i = n; --i;) update(i);
  }
  void unsafe_set(int k, T x) { dat[k + n] = x; }
  void rebuild() {
    for (int i = n + n; i--;) laz[i].flg = false;
    for (int i = n; --i;) update(i);
  }
  void apply(int a, int b, E x) {
    a += n, b += n;
    for (int i = height; i; i--)
      if (((a >> i) << i) != a) eval(a >> i);
    for (int i = height; i; i--)
      if (((b >> i) << i) != b) eval((b - 1) >> i);
    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if (l & 1) propagate(l++, x);
      if (r & 1) propagate(--r, x);
    }
    for (int i = 1; a >> i; i++)
      if (((a >> i) << i) != a) update(a >> i);
    for (int i = 1; b >> i; i++)
      if (((b >> i) << i) != b) update((b - 1) >> i);
  }
  void set(int k, T x) {
    int i = height;
    for (k += n; i; i--) eval(k >> i);
    for (dat[k] = x, laz[k].flg = false, i = 1; k >> i; i++) update(k >> i);
  }
  T fold(int a, int b) {  //[a,b)
    a += n, b += n;
    for (int i = height; i; i--)
      if (((a >> i) << i) != a) eval(a >> i);
    for (int i = height; i; i--)
      if (((b >> i) << i) != b) eval(b >> i);
    T vl = M::ti(), vr = M::ti();
    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = M::op(vl, dat[l++]);
      if (r & 1) vr = M::op(dat[--r], vr);
    }
    return M::op(vl, vr);
  }
  T operator[](const int k) { return fold(k, k + 1); }

 private:
  const int n, height;
  struct Lazy {
    E val;
    bool flg;
  };
  std::vector<T> dat;
  std::vector<Lazy> laz;
  inline void eval(int k) {
    if (!laz[k].flg) return;
    propagate(k << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);
    laz[k].flg = false;
  }
  inline void propagate(int k, const E &x) {
    dat[k] = M::mapping(dat[k], x);
    if (k < n) laz[k] = {laz[k].flg ? M::composition(laz[k].val, x) : x, true};
  }
  inline void update(int k) {
    dat[k] = M::op(dat[k << 1 | 0], dat[k << 1 | 1]);
  }
};