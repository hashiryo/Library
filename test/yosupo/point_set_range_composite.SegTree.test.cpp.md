---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/DataStructure/SegmentTree.hpp\"\n/**\n * @title Segment-Tree\n *\
    \ @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n * 2\u51AA\u306B\u3057\
    \u3066\u3044\u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04)\n */\n\n// 2\u51AA\u306B\
    \u3059\u308B\u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143array(10x10)\u3092\u306E\
    \u305B\u308B\u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n#ifndef call_from_test\n#line 16 \"src/DataStructure/SegmentTree.hpp\"\nusing\
    \ namespace std;\n#endif\n\ntemplate <typename M>\nstruct SegmentTree {\n  using\
    \ T = typename M::T;\n\n private:\n  const int n;\n  vector<T> dat;\n\n public:\n\
    \  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n << 1, M::ti()) {}\n\
    \  SegmentTree(int n_, T v) : SegmentTree(vector<T>(n_, v)) {}\n  SegmentTree(const\
    \ vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = 0; i <\
    \ (int)v.size(); i++) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set_val(int\
    \ k, T x) {\n    for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::f(dat[(k <<\
    \ 1) | 0], dat[(k << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k + n]\
    \ = x; }\n  void rebuild() {\n    for (int i = n - 1; i >= 1; i--)\n      dat[i]\
    \ = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(),\
    \ dat.end(), M::ti()); }\n  //[l,r)\n  inline T query(int l, int r) {\n    T vl\
    \ = M::ti(), vr = M::ti();\n    for (int a = l + n, b = r + n; a < b; a >>= 1,\
    \ b >>= 1) {\n      if (a & 1) vl = M::f(vl, dat[a++]);\n      if (b & 1) vr =\
    \ M::f(dat[--b], vr);\n    }\n    return M::f(vl, vr);\n  }\n  T operator[](const\
    \ int &k) const { return dat[k + n]; }\n\n  // max{ i : check(query(l,i+1)) =\
    \ true}\n  template <class C>\n  int find_right(const C &check, int l = 0) {\n\
    \    assert(check(M::ti()));\n    if (l == n) return n;\n    vector<int> idl,\
    \ idr;\n    for (int a = l + n, b = 2 * n; a < b; a >>= 1, b >>= 1) {\n      if\
    \ (a & 1) idl.push_back(a++);\n      if (b & 1) idr.push_back(--b);\n    }\n \
    \   for (auto itr = idr.rbegin(); itr != idr.rend(); itr++) idl.push_back(*itr);\n\
    \    T val = M::ti();\n    for (int i : idl) {\n      if (!check(M::f(val, dat[i])))\
    \ {\n        while (i < n) {\n          i = i << 1 | 0;\n          if (check(M::f(val,\
    \ dat[i]))) val = M::f(val, dat[i++]);\n        }\n        return i - n;\n   \
    \   }\n      val = M::f(val, dat[i]);\n    }\n    return n;\n  }\n  //   min {\
    \ i : check(query(i,r)) = true }\n  template <class C>\n  int find_left(const\
    \ C &check, int r = -1) {\n    if (r < 0) r = n;\n    assert(check(M::ti()));\n\
    \    if (r == 0) return 0;\n    vector<int> idl, idr;\n    for (int a = n, b =\
    \ r + n; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) idl.push_back(a++);\n  \
    \    if (b & 1) idr.push_back(--b);\n    }\n    for (auto itr = idl.rbegin();\
    \ itr != idl.rend(); itr++) idr.push_back(*itr);\n    T val = M::ti();\n    for\
    \ (int i : idr) {\n      if (!check(M::f(dat[i], val))) {\n        while (i <\
    \ n) {\n          i = i << 1 | 1;\n          if (check(M::f(dat[i], val))) val\
    \ = M::f(dat[i--], val);\n        }\n        return i + 1 - n;\n      }\n    \
    \  val = M::f(dat[i], val);\n    }\n    return 0;\n  }\n};\n#line 1 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n#ifndef call_from_test\n\
    #line 8 \"src/Math/ModInt.hpp\"\nusing namespace std;\n#endif\n\ntemplate <uint64_t\
    \ mod, uint64_t prim_root = 0>\nclass ModInt {\n private:\n  using u128 = __uint128_t;\n\
    \  static constexpr uint64_t mul_inv(uint64_t n, int e = 6, uint64_t x = 1) {\n\
    \    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr\
    \ uint64_t inv = mul_inv(mod, 6, 1);\n  static constexpr uint64_t r2 = -u128(mod)\
    \ % mod;\n  static constexpr uint64_t m2 = mod << 1;\n\n public:\n  static constexpr\
    \ int level = __builtin_ctzll(mod - 1);\n  ModInt() = default;\n  ~ModInt() =\
    \ default;\n  constexpr ModInt(uint64_t n) : x(init(n)){};\n  static constexpr\
    \ uint64_t modulo() { return mod; }\n  static constexpr uint64_t init(uint64_t\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr uint64_t reduce(const\
    \ u128 w) {\n    return uint64_t(w >> 64) + mod - ((u128(uint64_t(w) * inv) *\
    \ mod) >> 64);\n  }\n  static constexpr uint64_t pr_rt() { return prim_root; }\n\
    \  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x = (m2\
    \ & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt &rhs)\
    \ {\n    return x += rhs.x - m2, x += m2 & -(x >> 63), *this;\n  }\n  constexpr\
    \ ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += m2 & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return x != rhs.x; }\n  uint64_t get()\
    \ const {\n    uint64_t ret = reduce(x) - mod;\n    return ret + (mod & -(ret\
    \ >> 63));\n  }\n  void set(uint64_t n) const { this->x = n; }\n  constexpr ModInt\
    \ pow(uint64_t k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base =\
    \ *this; k; k >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return\
    \ ret;\n  }\n  constexpr ModInt inverse() const { return pow(mod - 2); }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.get();\n  }\n  uint64_t x;\n\
    };\n#line 9 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\n#undef\
    \ call_from_test\n\nusing Mint = ModInt<998244353>;\nstruct RcompositeQ {\n  using\
    \ T = pair<Mint, Mint>;\n  static T ti() { return make_pair(Mint(1), Mint(0));\
    \ }\n  static T f(const T &l, const T &r) {\n    return make_pair(r.first * l.first,\
    \ r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  vector<RcompositeQ::T>\
    \ v(N);\n  for (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n\
    \    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ> seg(v);\n  while (Q--) {\n\
    \    bool op;\n    cin >> op;\n    if (op) {\n      int l, r;\n      Mint x;\n\
    \      cin >> l >> r >> x;\n      auto ans = seg.query(l, r);\n      cout << ans.first\
    \ * x + ans.second << endl;\n    } else {\n      int p;\n      Mint c, d;\n  \
    \    cin >> p >> c >> d;\n      seg.set_val(p, {c, d});\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/DataStructure/SegmentTree.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\nstruct RcompositeQ\
    \ {\n  using T = pair<Mint, Mint>;\n  static T ti() { return make_pair(Mint(1),\
    \ Mint(0)); }\n  static T f(const T &l, const T &r) {\n    return make_pair(r.first\
    \ * l.first, r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  vector<RcompositeQ::T>\
    \ v(N);\n  for (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n\
    \    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ> seg(v);\n  while (Q--) {\n\
    \    bool op;\n    cin >> op;\n    if (op) {\n      int l, r;\n      Mint x;\n\
    \      cin >> l >> r >> x;\n      auto ans = seg.query(l, r);\n      cout << ans.first\
    \ * x + ans.second << endl;\n    } else {\n      int p;\n      Mint c, d;\n  \
    \    cin >> p >> c >> d;\n      seg.set_val(p, {c, d});\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.SegTree.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html
title: test/yosupo/point_set_range_composite.SegTree.test.cpp
---
