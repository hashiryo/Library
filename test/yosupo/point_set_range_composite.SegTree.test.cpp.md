---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree.hpp
    title: Segment-Tree
  - icon: ':x:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree.hpp\"\n/**\n\
    \ * @title Segment-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * O(logN)\n\
    \ * 2\u51AA\u306B\u3057\u3066\u3044\u306A\u3044(\u30E1\u30E2\u30EA\u7BC0\u7D04\
    )\n */\n\n// 2\u51AA\u306B\u3059\u308B\u306E\u3084\u3081\u3066\u4E8C\u6B21\u5143\
    array(10x10)\u3092\u306E\u305B\u308B\u3053\u3068\u306B\u6210\u529F\n// https://atcoder.jp/contests/arc027/tasks/arc027_4\n\
    \n// find_left, find_right verify\n// https://atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename M>\nstruct SegmentTree {\n  using T\
    \ = typename M::T;\n\n private:\n  const int n;\n  std::vector<T> dat;\n\n public:\n\
    \  SegmentTree() {}\n  SegmentTree(int n_) : n(n_), dat(n << 1, M::ti()) {}\n\
    \  SegmentTree(int n_, T v) : SegmentTree(std::vector<T>(n_, v)) {}\n  SegmentTree(const\
    \ std::vector<T> &v) : n(v.size()), dat(n << 1, M::ti()) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) dat[i + n] = v[i];\n    rebuild();\n  }\n  void set_val(int\
    \ k, T x) {\n    for (dat[k += n] = x; k >>= 1;)\n      dat[k] = M::op(dat[(k\
    \ << 1) | 0], dat[(k << 1) | 1]);\n  }\n  void unsafe_set(int k, T x) { dat[k\
    \ + n] = x; }\n  void rebuild() {\n    for (int i = n - 1; i >= 1; i--)\n    \
    \  dat[i] = M::op(dat[i << 1 | 0], dat[i << 1 | 1]);\n  }\n  void clear() { fill(dat.begin(),\
    \ dat.end(), M::ti()); }\n  //[l,r)\n  inline T fold(int l, int r) {\n    T vl\
    \ = M::ti(), vr = M::ti();\n    for (int a = l + n, b = r + n; a < b; a >>= 1,\
    \ b >>= 1) {\n      if (a & 1) vl = M::op(vl, dat[a++]);\n      if (b & 1) vr\
    \ = M::op(dat[--b], vr);\n    }\n    return M::op(vl, vr);\n  }\n  T operator[](const\
    \ int &k) const { return dat[k + n]; }\n\n  // max{ i : check(fold(l,i+1)) = true}\n\
    \  template <class C>\n  int find_right(const C &check, int l = 0) {\n    assert(check(M::ti()));\n\
    \    if (l == n) return n;\n    std::vector<int> idl, idr;\n    for (int a = l\
    \ + n, b = 2 * n; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) idl.push_back(a++);\n\
    \      if (b & 1) idr.push_back(--b);\n    }\n    for (auto itr = idr.rbegin();\
    \ itr != idr.rend(); itr++) idl.push_back(*itr);\n    T val = M::ti();\n    for\
    \ (int i : idl) {\n      if (!check(M::op(val, dat[i]))) {\n        while (i <\
    \ n) {\n          i = i << 1 | 0;\n          if (check(M::op(val, dat[i]))) val\
    \ = M::op(val, dat[i++]);\n        }\n        return i - n;\n      }\n      val\
    \ = M::op(val, dat[i]);\n    }\n    return n;\n  }\n  //   min { i : check(fold(i,r))\
    \ = true }\n  template <class C>\n  int find_left(const C &check, int r = -1)\
    \ {\n    if (r < 0) r = n;\n    assert(check(M::ti()));\n    if (r == 0) return\
    \ 0;\n    std::vector<int> idl, idr;\n    for (int a = n, b = r + n; a < b; a\
    \ >>= 1, b >>= 1) {\n      if (a & 1) idl.push_back(a++);\n      if (b & 1) idr.push_back(--b);\n\
    \    }\n    for (auto itr = idl.rbegin(); itr != idl.rend(); itr++) idr.push_back(*itr);\n\
    \    T val = M::ti();\n    for (int i : idr) {\n      if (!check(M::op(dat[i],\
    \ val))) {\n        while (i < n) {\n          i = i << 1 | 1;\n          if (check(M::op(dat[i],\
    \ val))) val = M::op(dat[i--], val);\n        }\n        return i + 1 - n;\n \
    \     }\n      val = M::op(dat[i], val);\n    }\n    return 0;\n  }\n};\n#line\
    \ 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\n\nnamespace internal {\ntemplate <std::uint64_t mod,\
    \ std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n\
    \    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const ModInt\
    \ &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const ModInt\
    \ &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const ModInt\
    \ &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const ModInt\
    \ &rhs) const { return ModInt(*this) /= rhs; }\n  constexpr ModInt pow(std::uint64_t\
    \ k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k\
    \ >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n\
    \  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr ModInt\
    \ sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n    if\
    \ (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE\
    \ = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b +=\
    \ ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt,\
    \ ModInt> v) {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n\
    \      ModInt b = (u.first * v.second + u.second * v.first);\n      return std::make_pair(a,\
    \ b);\n    };\n    std::uint64_t e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE,\
    \ ModInt(0));\n    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs,\
    \ bs))\n      if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 <\
    \ mod ? ret.first : -ret.first;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace\
    \ internal\ntemplate <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\
    \ : internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using u64\
    \ = std::uint64_t;\n  using u128 = __uint128_t;\n  static constexpr u64 mul_inv(u64\
    \ n, int e = 6, u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2\
    \ - x * n));\n  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -u128(mod)\
    \ % mod;\n  static constexpr u64 init(u64 w) { return reduce(u128(w) * r2); }\n\
    \  static constexpr u64 reduce(const u128 w) {\n    return u64(w >> 64) + mod\
    \ - ((u128(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n < 0 ? mod\
    \ - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static constexpr u64 norm(u64\
    \ w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n\
    \  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x\
    \ - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return norm(x) != norm(rhs.x); }\n  u64 val() const {\n\
    \    u64 ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n\
    \  friend std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return\
    \ is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t prim_root>\n\
    class ModInt<2, prim_root>\n    : internal::ModIntImpl<2, prim_root, ModInt<2,\
    \ prim_root>> {\n  bool x;\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(n & 1) {}\n  ~ModInt() = default;\n  constexpr ModInt\
    \ operator-() const { return *this; }\n  constexpr ModInt &operator+=(const ModInt\
    \ &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt &operator-=(const ModInt\
    \ &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt &operator*=(const ModInt\
    \ &rhs) { return x &= rhs.x, *this; }\n  bool operator==(const ModInt &rhs) const\
    \ { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs) const { return\
    \ x != rhs.x; }\n  std::uint64_t val() const { return x; }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n\
    \  }\n};\n#line 5 \"test/yosupo/point_set_range_composite.SegTree.test.cpp\"\n\
    using namespace std;\n\nusing Mint = ModInt<998244353>;\nstruct RcompositeQ {\n\
    \  using T = pair<Mint, Mint>;\n  static T ti() { return make_pair(Mint(1), Mint(0));\
    \ }\n  static T op(const T &l, const T &r) {\n    return make_pair(r.first * l.first,\
    \ r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  vector<RcompositeQ::T>\
    \ v(N);\n  for (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n\
    \    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ> seg(v);\n  while (Q--) {\n\
    \    bool op;\n    cin >> op;\n    if (op) {\n      int l, r;\n      Mint x;\n\
    \      cin >> l >> r >> x;\n      auto ans = seg.fold(l, r);\n      cout << ans.first\
    \ * x + ans.second << endl;\n    } else {\n      int p;\n      Mint c, d;\n  \
    \    cin >> p >> c >> d;\n      seg.set_val(p, {c, d});\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = ModInt<998244353>;\n\
    struct RcompositeQ {\n  using T = pair<Mint, Mint>;\n  static T ti() { return\
    \ make_pair(Mint(1), Mint(0)); }\n  static T op(const T &l, const T &r) {\n  \
    \  return make_pair(r.first * l.first, r.first * l.second + r.second);\n  }\n\
    };\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<RcompositeQ::T> v(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    Mint a, b;\n    cin >> a >> b;\n    v[i] = {a, b};\n  }\n  SegmentTree<RcompositeQ>\
    \ seg(v);\n  while (Q--) {\n    bool op;\n    cin >> op;\n    if (op) {\n    \
    \  int l, r;\n      Mint x;\n      cin >> l >> r >> x;\n      auto ans = seg.fold(l,\
    \ r);\n      cout << ans.first * x + ans.second << endl;\n    } else {\n     \
    \ int p;\n      Mint c, d;\n      cin >> p >> c >> d;\n      seg.set_val(p, {c,\
    \ d});\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.SegTree.test.cpp
  requiredBy: []
  timestamp: '2021-10-23 20:58:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.SegTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp
- /verify/test/yosupo/point_set_range_composite.SegTree.test.cpp.html
title: test/yosupo/point_set_range_composite.SegTree.test.cpp
---
