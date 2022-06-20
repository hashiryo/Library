---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Lazy.hpp
    title: "Segment-Tree(\u9045\u5EF6\u4F1D\u642C)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <bits/stdc++.h>\n\n#line 3 \"src/DataStructure/SegmentTree_Lazy.hpp\"\
    \n/**\n * @title Segment-Tree(\u9045\u5EF6\u4F1D\u642C)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename\
    \ M>\nstruct SegmentTree_Lazy {\n  using T = typename M::T;\n  using E = typename\
    \ M::E;\n  SegmentTree_Lazy() {}\n  SegmentTree_Lazy(int n_)\n      : n(n_),\n\
    \        height(ceil(log2(n))),\n        dat(n * 2, M::ti()),\n        laz(n *\
    \ 2, {E(), false}) {}\n  SegmentTree_Lazy(int n_, T v1) : SegmentTree_Lazy(n_)\
    \ {\n    for (int i = n; i--;) dat[i + n] = v1;\n    for (int i = n; --i;) update(i);\n\
    \  }\n  SegmentTree_Lazy(const std::vector<T> &v) : SegmentTree_Lazy(v.size())\
    \ {\n    for (int i = n; i--;) dat[i + n] = v[i];\n    for (int i = n; --i;) update(i);\n\
    \  }\n  void unsafe_set(int k, T x) { dat[k + n] = x; }\n  void rebuild() {\n\
    \    for (int i = n + n; i--;) laz[i].flg = false;\n    for (int i = n; --i;)\
    \ update(i);\n  }\n  void apply(int a, int b, E x) {\n    a += n, b += n;\n  \
    \  for (int i = height; i; i--)\n      if (((a >> i) << i) != a) eval(a >> i);\n\
    \    for (int i = height; i; i--)\n      if (((b >> i) << i) != b) eval((b - 1)\
    \ >> i);\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1) {\n      if (l &\
    \ 1) propagate(l++, x);\n      if (r & 1) propagate(--r, x);\n    }\n    for (int\
    \ i = 1; a >> i; i++)\n      if (((a >> i) << i) != a) update(a >> i);\n    for\
    \ (int i = 1; b >> i; i++)\n      if (((b >> i) << i) != b) update((b - 1) >>\
    \ i);\n  }\n  void set(int k, T x) {\n    int i = height;\n    for (k += n; i;\
    \ i--) eval(k >> i);\n    for (dat[k] = x, laz[k].flg = false, i = 1; k >> i;\
    \ i++) update(k >> i);\n  }\n  T fold(int a, int b) {  //[a,b)\n    a += n, b\
    \ += n;\n    for (int i = height; i; i--)\n      if (((a >> i) << i) != a) eval(a\
    \ >> i);\n    for (int i = height; i; i--)\n      if (((b >> i) << i) != b) eval(b\
    \ >> i);\n    T vl = M::ti(), vr = M::ti();\n    for (int l = a, r = b; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (l & 1) vl = M::op(vl, dat[l++]);\n      if (r\
    \ & 1) vr = M::op(dat[--r], vr);\n    }\n    return M::op(vl, vr);\n  }\n  T operator[](const\
    \ int k) { return fold(k, k + 1); }\n\n private:\n  const int n, height;\n  struct\
    \ Lazy {\n    E val;\n    bool flg;\n  };\n  std::vector<T> dat;\n  std::vector<Lazy>\
    \ laz;\n  inline void eval(int k) {\n    if (!laz[k].flg) return;\n    propagate(k\
    \ << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n    laz[k].flg =\
    \ false;\n  }\n  inline void propagate(int k, const E &x) {\n    dat[k] = M::mapping(dat[k],\
    \ x);\n    if (k < n) laz[k] = {laz[k].flg ? M::composition(laz[k].val, x) : x,\
    \ true};\n  }\n  inline void update(int k) {\n    dat[k] = M::op(dat[k << 1 |\
    \ 0], dat[k << 1 | 1]);\n  }\n};\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title\
    \ ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace internal\
    \ {\ntemplate <std::uint64_t mod, std::uint64_t prim_root, class ModInt>\nstruct\
    \ ModIntImpl {\n  static constexpr std::uint64_t modulo() { return mod; }\n  static\
    \ constexpr std::uint64_t pr_rt() { return prim_root; }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n};\n}  // namespace internal\ntemplate <std::uint64_t mod, std::uint64_t\
    \ prim_root = 0>\nclass ModInt\n    : public internal::ModIntImpl<mod, prim_root,\
    \ ModInt<mod, prim_root>> {\n  using u64 = std::uint64_t;\n  static constexpr\
    \ u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e == 0 ? x : mul_inv(n,\
    \ e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv = mul_inv(mod, 6,\
    \ 1), r2 = -__uint128_t(mod) % mod;\n  static constexpr u64 init(u64 w) { return\
    \ reduce(__uint128_t(w) * r2); }\n  static constexpr u64 reduce(const __uint128_t\
    \ w) {\n    return u64(w >> 64) + mod - ((__uint128_t(u64(w) * inv) * mod) >>\
    \ 64);\n  }\n  u64 x;\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  static\
    \ constexpr u64 norm(u64 w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt\
    \ operator-() const {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x !=\
    \ 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n  \
    \  return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n\
    \  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x\
    \ += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(__uint128_t(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n\
    \  constexpr ModInt pow(std::uint64_t k) const {\n    ModInt ret = ModInt(1);\n\
    \    for (ModInt base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret\
    \ *= base;\n    return ret;\n  }\n  constexpr ModInt inverse() const { return\
    \ pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0)\
    \ || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);\
    \  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod\
    \ - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt,\
    \ ModInt> u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first\
    \ + u.second * v.second * w);\n      ModInt b = (u.first * v.second + u.second\
    \ * v.first);\n      return std::make_pair(a, b);\n    };\n    std::uint64_t e\
    \ = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto\
    \ bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1)\
    \ ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n\
    \  }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    };\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2, pr_rt> : internal::ModIntImpl<2,\
    \ pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t n = 0) : x(n & 1)\
    \ {}\n  constexpr ModInt operator-() const { return *this; }\n  constexpr ModInt\
    \ &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs)\
    \ const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t k) const\
    \ { return !k ? ModInt(1) : *this; }\n  constexpr ModInt sqrt() const { return\
    \ *this; }\n  constexpr ModInt inverse() const { return *this; }\n  constexpr\
    \ std::uint64_t val() const { return x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n  }\n\n private:\n  bool x;\n\
    };\n#line 6 \"test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp\"\nusing\
    \ namespace std;\n\nusing Mint = ModInt<998244353>;\n// RsumQ\u306F\u30E2\u30CE\
    \u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\u3066\u304A\u304F\nstruct\
    \ RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n    int size;\n    T(Mint v =\
    \ 0, int s = 1) : val(v), size(s) {}\n  };\n  using E = pair<Mint, Mint>;\n  static\
    \ T ti() { return T(0, 0); }\n  static E ei() { return make_pair(Mint(1), Mint(0));\
    \ }\n  static T op(const T &l, const T &r) {\n    return T(l.val + r.val, l.size\
    \ + r.size);\n  }\n  static T mapping(const T &l, const E &r) {\n    return T(r.first\
    \ * l.val + r.second * l.size, l.size);\n  }\n  static E composition(const E &l,\
    \ const E &r) {\n    return make_pair(r.first * l.first, r.first * l.second +\
    \ r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T> v(N);\n  for (int\
    \ i = 0; i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i] = {a, 1};\n  }\n\
    \  SegmentTree_Lazy<RaffineQ_RsumQ> seg(v);\n  while (Q--) {\n    bool op;\n \
    \   int l, r;\n    cin >> op >> l >> r;\n    if (op) {\n      cout << seg.fold(l,\
    \ r).val << endl;\n    } else {\n      Mint b, c;\n      cin >> b >> c;\n    \
    \  seg.apply(l, r, {Mint(b), Mint(c)});\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/DataStructure/SegmentTree_Lazy.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nusing Mint = ModInt<998244353>;\n\
    // RsumQ\u306F\u30E2\u30CE\u30A4\u30C9\u3067\u30B5\u30A4\u30BA\u3092\u6301\u3063\
    \u3066\u304A\u304F\nstruct RaffineQ_RsumQ {\n  struct T {\n    Mint val;\n   \
    \ int size;\n    T(Mint v = 0, int s = 1) : val(v), size(s) {}\n  };\n  using\
    \ E = pair<Mint, Mint>;\n  static T ti() { return T(0, 0); }\n  static E ei()\
    \ { return make_pair(Mint(1), Mint(0)); }\n  static T op(const T &l, const T &r)\
    \ {\n    return T(l.val + r.val, l.size + r.size);\n  }\n  static T mapping(const\
    \ T &l, const E &r) {\n    return T(r.first * l.val + r.second * l.size, l.size);\n\
    \  }\n  static E composition(const E &l, const E &r) {\n    return make_pair(r.first\
    \ * l.first, r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  vector<RaffineQ_RsumQ::T>\
    \ v(N);\n  for (int i = 0; i < N; i++) {\n    Mint a;\n    cin >> a;\n    v[i]\
    \ = {a, 1};\n  }\n  SegmentTree_Lazy<RaffineQ_RsumQ> seg(v);\n  while (Q--) {\n\
    \    bool op;\n    int l, r;\n    cin >> op >> l >> r;\n    if (op) {\n      cout\
    \ << seg.fold(l, r).val << endl;\n    } else {\n      Mint b, c;\n      cin >>\
    \ b >> c;\n      seg.apply(l, r, {Mint(b), Mint(c)});\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - src/DataStructure/SegmentTree_Lazy.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
  requiredBy: []
  timestamp: '2022-06-20 11:07:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
- /verify/test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp.html
title: test/yosupo/range_affine_range_sum.SegTree_Lazy.test.cpp
---
