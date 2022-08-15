---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n#include <bits/stdc++.h>\n\
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
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/Math/berlekamp_massey.hpp\"\
    \n/**\n * @title Berlekamp-Massey\n * @category \u6570\u5B66\n * \u6570\u5217\u306E\
    \u6700\u521D\u306EN\u9805\u304B\u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\
    \u6210\u3059\u308BN/2\u6B21\u4EE5\u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\
    \u5316\u5F0F\u3092\u6C42\u3081\u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n//\
    \ https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\n\
    // BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] *\
    \ a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  if\
    \ (n == 0) return {};\n  std::vector<K> c(n), b(n), tmp;\n  K x = 1, y, coef;\n\
    \  const K Z = 0;\n  for (c[0] = b[0] = 1, i = 0, j; i < n; ++i) {\n    for (++m,\
    \ y = a[i], j = 1; j <= d; ++j) y += c[j] * a[i - j];\n    if (y == Z) continue;\n\
    \    for (tmp = c, coef = y / x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n\
    \    if (2 * d > i) continue;\n    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n\
    \  c.resize(d + 1), c.erase(c.begin());\n  for (auto &x : c) x = -x;\n  return\
    \ c;\n}\n#line 5 \"test/yosupo/find_linear_recurrence.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using\
    \ Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n  for\
    \ (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << '\\n';\n  for (int i = 0; i < d; i++) cout\
    \ << c[i] << \" \\n\"[i == d - 1];\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/berlekamp_massey.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << '\\n';\n  for (int i = 0; i < d; i++) cout\
    \ << c[i] << \" \\n\"[i == d - 1];\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: true
  path: test/yosupo/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2022-06-24 13:41:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---