---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':x:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"src/Math/ModInt.hpp\"\
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
    };\n#line 1 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n\
    \ * @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\
    \u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\
    \u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\
    \u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n#ifndef call_from_test\n#line 13 \"src/Math/berlekamp_massey.hpp\"\nusing namespace\
    \ std;\n#endif\n\n// a[n] = c[0] * a[n-N] + c[1] * a[n-N+1] + ... + c[N-1] * a[n-1]\n\
    // return c\n\ntemplate <class T>\nvector<T> berlekamp_massey(const vector<T>\
    \ &a) {\n  const int N = (int)a.size();\n  vector<T> b = {T(-1)}, c = {T(-1)};\n\
    \  T y = T(1);\n  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()),\
    \ m = int(b.size()) + 1;\n    T x = 0;\n    for (int i = 0; i < l; i++) x += c[i]\
    \ * a[ed - l + i];\n    b.emplace_back(0);\n    if (x == T(0)) continue;\n   \
    \ T freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n      c.insert(begin(c),\
    \ m - l, T(0));\n      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m\
    \ - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n      for (int i = 0;\
    \ i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  c.pop_back();\n\
    \  return c;\n}\n#line 9 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#undef\
    \ call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<Mint> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  vector<Mint> c = berlekamp_massey(a);\n\
    \  int d = c.size();\n  cout << d << endl;\n  for (int i = 0; i < d; i++) cout\
    \ << (i ? \" \" : \"\") << c[d - 1 - i];\n  cout << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Math/ModInt.hpp\"\n#include \"src/Math/berlekamp_massey.hpp\"\n\
    #undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
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
  timestamp: '2020-10-17 15:44:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---
