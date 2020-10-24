---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
  bundledCode: "#line 1 \"test/aoj/DPL_5_E.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/Combination.hpp\"\n/**\n * @title\
    \ \u7D44\u307F\u5408\u308F\u305B\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT\
    \ HERE\n\ntemplate <class mint>\nstruct Combination {\n private:\n  static inline\
    \ mint _fact[1 << 22], _finv[1 << 22];\n  static inline void set(int sz) {\n \
    \   static int lim = 0;\n    if (lim <= sz) {\n      if (lim == 0) _fact[0] =\
    \ _finv[0] = 1, lim = 1;\n      for (int i = lim; i <= sz; i++) _fact[i] = _fact[i\
    \ - 1] * i;\n      _finv[sz] = mint(1) / _fact[sz];\n      for (int i = sz; i\
    \ >= lim; i--) _finv[i - 1] = _finv[i] * i;\n      lim = sz + 1;\n    }\n  }\n\
    \n public:\n  static inline mint fact(int n) { return set(n), n < 0 ? mint(0)\
    \ : _fact[n]; }\n  static inline mint finv(int n) { return set(n), n < 0 ? mint(0)\
    \ : _finv[n]; }\n  static mint nPr(int n, int r) { return fact(n) * finv(n - r);\
    \ }\n  static mint nCr(int n, int r) { return nPr(n, r) * finv(r); }\n  static\
    \ mint nHr(int n, int r) { return !r ? mint(1) : nCr(n + r - 1, r); }\n};\n#line\
    \ 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\nnamespace internal {\nstruct modint_base {};\n}  //\
    \ namespace internal\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root =\
    \ 0>\nclass ModInt : internal::modint_base {\n private:\n  using u64 = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6,\
    \ u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n\
    \  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1);\n  static constexpr u64\
    \ r2 = -u128(mod) % mod;\n  static constexpr u64 m2 = mod << 1;\n\n public:\n\
    \  static constexpr int level = __builtin_ctzll(mod - 1);\n  constexpr ModInt()\
    \ : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) %\
    \ mod : n)) {}\n  ~ModInt() = default;\n  static constexpr u64 modulo() { return\
    \ mod; }\n  static constexpr u64 init(u64 w) { return reduce(u128(w) * r2); }\n\
    \  static constexpr u64 reduce(const u128 w) {\n    return u64(w >> 64) + mod\
    \ - ((u128(u64(w) * inv) * mod) >> 64);\n  }\n  static constexpr u64 norm(u64\
    \ x) { return x - (mod & -(x >= mod)); }\n  static constexpr u64 pr_rt() { return\
    \ prim_root; }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return\
    \ ret.x = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - m2, x += m2 & -(x >> 63), *this;\n \
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x,\
    \ x += m2 & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt\
    \ &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n \
    \ constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 get() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr ModInt pow(u64 k) const {\n    ModInt ret\
    \ = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n    \
    \  if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this\
    \ == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return\
    \ ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n \
    \   while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto\
    \ mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {\n    \
    \  ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt b =\
    \ (u.first * v.second + u.second * v.first);\n      return std::make_pair(a, b);\n\
    \    };\n    u64 e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n  \
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.get() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.get();\n\
    \  }\n  u64 x;\n};\n\ntemplate <class T>\nusing is_modint = std::is_base_of<internal::modint_base,\
    \ T>;\n#line 6 \"test/aoj/DPL_5_E.test.cpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int n, k;\n  cin >> n >>\
    \ k;\n  using Mint = ModInt<int(1e9 + 7)>;\n  using C = Combination<Mint>;\n \
    \ cout << C::nCr(k, n) << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/Combination.hpp\"\n#include \"\
    src/Math/ModInt.hpp\"\nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  int n, k;\n  cin >> n >> k;\n  using Mint =\
    \ ModInt<int(1e9 + 7)>;\n  using C = Combination<Mint>;\n  cout << C::nCr(k, n)\
    \ << endl;\n  return 0;\n}\n"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_E.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 14:33:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_E.test.cpp
- /verify/test/aoj/DPL_5_E.test.cpp.html
title: test/aoj/DPL_5_E.test.cpp
---
