---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.SegDual.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t mod,\
    \ std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace internal\n\
    template <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n    :\
    \ public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using\
    \ u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x\
    \ = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n \
    \ static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }\n\
    \  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w >> 64)\
    \ + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n\
    \  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64 w) { return\
    \ w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t\
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
    \ mod ? ret.first : -ret.first;\n  }\n  constexpr u64 val() const {\n    u64 ret\
    \ = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x\
    \ = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2,\
    \ pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t\
    \ n = 0) : x(n & 1) {}\n  constexpr ModInt operator-() const { return *this; }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n  constexpr\
    \ ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }\n  constexpr\
    \ ModInt sqrt() const { return *this; }\n  constexpr ModInt inverse() const {\
    \ return *this; }\n  constexpr std::uint64_t val() const { return x; }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \n/**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct SegmentTree_Dual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n      : n(n_),\
    \ height(ceil(log2(n))), val(n, v1), laz(n * 2, {E(), false}) {}\n  SegmentTree_Dual(const\
    \ std::vector<T> &v)\n      : n(v.size()), height(ceil(log2(n))), val(v), laz(n\
    \ * 2, {E(), false}) {}\n  void apply(int a, int b, E x) {\n    a += n, b += n;\n\
    \    for (int i = height; i >= 1; i--)\n      if (((a >> i) << i) != a) eval(a\
    \ >> i);\n    for (int i = height; i >= 1; i--)\n      if (((b >> i) << i) !=\
    \ b) eval((b - 1) >> i);\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) propagate(l++, x);\n      if (r & 1) propagate(--r, x);\n\
    \    }\n  }\n  void set(int k, T x) {\n    for (int i = height; i; i--) eval((k\
    \ + n) >> i);\n    val[k] = x, laz[k + n].flg = false;\n  }\n  T operator[](const\
    \ int k) {\n    for (int i = height; i; i--) eval((k + n) >> i);\n    if (laz[k\
    \ + n].flg)\n      val[k] = M::mapping(val[k], laz[k + n].val), laz[k + n].flg\
    \ = false;\n    return val[k];\n  }\n\n private:\n  const int n, height;\n  struct\
    \ Lazy {\n    E val;\n    bool flg;\n  };\n  std::vector<T> val;\n  std::vector<Lazy>\
    \ laz;\n  inline void eval(int k) {\n    if (!laz[k].flg) return;\n    propagate(k\
    \ << 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n    laz[k].flg =\
    \ false;\n  }\n  inline void propagate(int k, const E &x) {\n    laz[k] = {laz[k].flg\
    \ ? M::composition(laz[k].val, x) : x, true};\n  }\n};\n#line 6 \"test/atcoder/abc256_f.SegDual.cpp\"\
    \nusing namespace std;\n\nusing Mint = ModInt<998244353>;\nstruct Mono {\n  struct\
    \ T {\n    int id;\n    Mint val;\n  };\n  using E = array<Mint, 3>;\n  static\
    \ T mapping(T x, E mapp) {\n    return {x.id, x.val + mapp[0] * (x.id + 1) * (x.id\
    \ + 2) / 2 -\n                      mapp[1] * (2 * x.id + 3) / 2 + mapp[2]};\n\
    \  }\n  static E composition(E pre, E suf) {\n    return {pre[0] + suf[0], pre[1]\
    \ + suf[1], pre[2] + suf[2]};\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Seg = SegmentTree_Dual<Mono>;\n  int N, Q;\n  cin >> N >> Q;\n  Mint\
    \ A[N], D[N];\n  for (int i = 0; i < N; i++) cin >> A[i], D[i] = A[i];\n  for\
    \ (int j = 0; j < 3; j++)\n    for (int i = 1; i < N; i++) D[i] += D[i - 1];\n\
    \  Seg seg;\n  for (int i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--)\
    \ {\n    int op, x;\n    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint\
    \ v;\n      cin >> v, v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x,\
    \ v * x * x / 2});\n    } else {\n      cout << seg[x].val << '\\n';\n    }\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nusing Mint = ModInt<998244353>;\nstruct Mono {\n  struct\
    \ T {\n    int id;\n    Mint val;\n  };\n  using E = array<Mint, 3>;\n  static\
    \ T mapping(T x, E mapp) {\n    return {x.id, x.val + mapp[0] * (x.id + 1) * (x.id\
    \ + 2) / 2 -\n                      mapp[1] * (2 * x.id + 3) / 2 + mapp[2]};\n\
    \  }\n  static E composition(E pre, E suf) {\n    return {pre[0] + suf[0], pre[1]\
    \ + suf[1], pre[2] + suf[2]};\n  }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Seg = SegmentTree_Dual<Mono>;\n  int N, Q;\n  cin >> N >> Q;\n  Mint\
    \ A[N], D[N];\n  for (int i = 0; i < N; i++) cin >> A[i], D[i] = A[i];\n  for\
    \ (int j = 0; j < 3; j++)\n    for (int i = 1; i < N; i++) D[i] += D[i - 1];\n\
    \  Seg seg;\n  for (int i = 0; i < N; i++) seg.set(i, {i, D[i]});\n  while (Q--)\
    \ {\n    int op, x;\n    cin >> op >> x, x--;\n    if (op == 1) {\n      Mint\
    \ v;\n      cin >> v, v -= A[x], A[x] += v;\n      seg.apply(x, N, {v, v * x,\
    \ v * x * x / 2});\n    } else {\n      cout << seg[x].val << '\\n';\n    }\n\
    \  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: false
  path: test/atcoder/abc256_f.SegDual.cpp
  requiredBy: []
  timestamp: '2022-06-20 11:07:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.SegDual.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc256_f.SegDual.cpp
- /library/test/atcoder/abc256_f.SegDual.cpp.html
title: test/atcoder/abc256_f.SegDual.cpp
---
