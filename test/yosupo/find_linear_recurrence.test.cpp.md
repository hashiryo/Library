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
    #line 8 \"src/Math/ModInt.hpp\"\nusing namespace std;\n#endif\n\ntemplate <int\
    \ mod>\nstruct ModInt {\n  int64_t x;\n  ModInt() : x(0) {}\n  ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}\n  ModInt &operator+=(const\
    \ ModInt &p) {\n    if ((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\
    \  ModInt &operator-=(const ModInt &p) {\n    if ((x += mod - p.x) >= mod) x -=\
    \ mod;\n    return *this;\n  }\n  ModInt &operator*=(const ModInt &p) {\n    x\
    \ = (int)(1LL * x * p.x % mod);\n    return *this;\n  }\n  ModInt &operator/=(const\
    \ ModInt &p) { return *this *= p.inverse(); }\n  ModInt operator-() const { return\
    \ ModInt() - *this; }\n  ModInt operator+(const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n  ModInt operator-(const ModInt &p) const { return ModInt(*this) -=\
    \ p; }\n  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n\
    \  bool operator==(const ModInt &p) const { return x == p.x; }\n  bool operator!=(const\
    \ ModInt &p) const { return x != p.x; }\n  ModInt inverse() const {\n    int a\
    \ = x, b = mod, u = 1, v = 0, t;\n    while (b) t = a / b, swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    return ModInt(u);\n  }\n  ModInt pow(int64_t e) const\
    \ {\n    ModInt ret(1);\n    for (ModInt b = *this; e; e >>= 1, b *= b)\n    \
    \  if (e & 1) ret *= b;\n    return ret;\n  }\n  friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) { return os << p.x; }\n  friend istream &operator>>(istream\
    \ &is, ModInt &a) {\n    int64_t t;\n    is >> t;\n    a = ModInt<mod>(t);\n \
    \   return (is);\n  }\n  static int modulo() { return mod; }\n  int get() const\
    \ { return x; }\n};\n#line 1 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title\
    \ Berlekamp-Massey\n * @category \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\
    \u306EN\u9805\u304B\u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\
    \u308BN/2\u6B21\u4EE5\u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\
    \u3092\u6C42\u3081\u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
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
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---
