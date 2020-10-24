---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \n */\n\n// BEGIN CUT HERE\nnamespace internal {\nstruct modint_base {};\n}  //\
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
    \ T>;\n#line 3 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n\
    \ * @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1]\
    \ * a[n-1]\n// return c\n\ntemplate <class T>\nstd::vector<T> berlekamp_massey(const\
    \ std::vector<T> &a) {\n  const int N = (int)a.size();\n  std::vector<T> b = {T(-1)},\
    \ c = {T(-1)};\n  T y = T(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l\
    \ = int(c.size()), m = int(b.size()) + 1;\n    T x = 0;\n    for (int i = 0; i\
    \ < l; i++) x += c[i] * a[ed - l + i];\n    b.emplace_back(0);\n    if (x == T(0))\
    \ continue;\n    T freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n    \
    \  c.insert(c.begin(), m - l, T(0));\n      for (int i = 0; i < m; i++) c[m -\
    \ 1 - i] -= freq * b[m - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n\
    \      for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n\
    \  }\n  c.pop_back();\n  return c;\n}\n#line 5 \"test/yosupo/find_linear_recurrence.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << endl;\n  for (int i = 0; i < d; i++) cout\
    \ << (i ? \" \" : \"\") << c[d - 1 - i];\n  cout << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/berlekamp_massey.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << endl;\n  for (int i = 0; i < d; i++) cout\
    \ << (i ? \" \" : \"\") << c[d - 1 - i];\n  cout << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: true
  path: test/yosupo/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 14:33:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---
