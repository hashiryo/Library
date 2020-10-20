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
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/Math/Combination.hpp\"\n/**\n * @title \u7D44\u307F\u5408\u308F\u305B\
    \n * @category \u6570\u5B66\n */\n\n#ifndef call_from_test\n#line 8 \"src/Math/Combination.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <class mint>\nstruct Combination {\n\
    \ private:\n  static inline mint _fact[1 << 22], _finv[1 << 22];\n  static inline\
    \ void set(int sz) {\n    static int lim = 0;\n    if (lim <= sz) {\n      if\
    \ (lim == 0) _fact[0] = _finv[0] = 1, lim = 1;\n      for (int i = lim; i <= sz;\
    \ i++) _fact[i] = _fact[i - 1] * i;\n      _finv[sz] = mint(1) / _fact[sz];\n\
    \      for (int i = sz; i >= lim; i--) _finv[i - 1] = _finv[i] * i;\n      lim\
    \ = sz + 1;\n    }\n  }\n\n public:\n  static inline mint fact(int n) { return\
    \ set(n), n < 0 ? mint(0) : _fact[n]; }\n  static inline mint finv(int n) { return\
    \ set(n), n < 0 ? mint(0) : _finv[n]; }\n  static mint nPr(int n, int r) { return\
    \ fact(n) * finv(n - r); }\n  static mint nCr(int n, int r) { return nPr(n, r)\
    \ * finv(r); }\n  static mint nHr(int n, int r) { return !r ? mint(1) : nCr(n\
    \ + r - 1, r); }\n};\n#line 1 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n\
    \ * @category \u6570\u5B66\n */\n\n#ifndef call_from_test\n#line 8 \"src/Math/ModInt.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <uint64_t mod, uint64_t prim_root =\
    \ 0>\nclass ModInt {\n private:\n  using u128 = __uint128_t;\n  static constexpr\
    \ uint64_t mul_inv(uint64_t n, int e = 6, uint64_t x = 1) {\n    return e == 0\
    \ ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr uint64_t\
    \ inv = mul_inv(mod, 6, 1);\n  static constexpr uint64_t r2 = -u128(mod) % mod;\n\
    \  static constexpr uint64_t m2 = mod << 1;\n\n public:\n  static constexpr int\
    \ level = __builtin_ctzll(mod - 1);\n  ModInt() = default;\n  ~ModInt() = default;\n\
    \  constexpr ModInt(uint64_t n) : x(init(n)){};\n  static constexpr uint64_t modulo()\
    \ { return mod; }\n  static constexpr uint64_t init(uint64_t w) { return reduce(u128(w)\
    \ * r2); }\n  static constexpr uint64_t reduce(const u128 w) {\n    return uint64_t(w\
    \ >> 64) + mod - ((u128(uint64_t(w) * inv) * mod) >> 64);\n  }\n  static constexpr\
    \ uint64_t pr_rt() { return prim_root; }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - m2, x += m2\
    \ & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs)\
    \ {\n    return x -= rhs.x, x += m2 & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) {\n    return this->x = reduce(u128(this->x)\
    \ * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n\
    \    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const ModInt\
    \ &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const ModInt\
    \ &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const ModInt\
    \ &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const ModInt\
    \ &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const ModInt\
    \ &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs) const\
    \ { return x != rhs.x; }\n  uint64_t get() const {\n    uint64_t ret = reduce(x)\
    \ - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  void set(uint64_t n)\
    \ const { this->x = n; }\n  constexpr ModInt pow(uint64_t k) const {\n    ModInt\
    \ ret = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n\
    \      if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    \  friend std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {\n  \
    \  return os << rhs.get();\n  }\n  uint64_t x;\n};\n#line 10 \"test/aoj/DPL_5_E.test.cpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n, k;\n  cin >> n >> k;\n  using Mint = ModInt<int(1e9 + 7)>;\n  using\
    \ C = Combination<Mint>;\n  cout << C::nCr(k, n) << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#undef\
    \ call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int n, k;\n  cin >> n >> k;\n  using Mint = ModInt<int(1e9 + 7)>;\n  using\
    \ C = Combination<Mint>;\n  cout << C::nCr(k, n) << endl;\n  return 0;\n}\n"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_E.test.cpp
  requiredBy: []
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_E.test.cpp
- /verify/test/aoj/DPL_5_E.test.cpp.html
title: test/aoj/DPL_5_E.test.cpp
---
