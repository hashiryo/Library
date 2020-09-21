---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    src/Math/Combination.hpp\"\n/**\n * @title \u7D44\u307F\u5408\u308F\u305B\n *\
    \ @category \u6570\u5B66\n */\n\n#ifndef call_from_test\n#line 8 \"src/Math/Combination.hpp\"\
    \nusing namespace std;\n#endif\n\ntemplate <class Modint>\nstruct Combination\
    \ {\n  static vector<Modint> _fact, _finv, _inv;\n  static void init(int sz) {\n\
    \    int n = min(2 * sz, Modint::modulo() - 1);\n    _fact.resize(n + 1), _finv.resize(n\
    \ + 1), _inv.resize(n + 1);\n    for (int i = 0; i <= n; ++i) _fact[i] = i ? Modint(i)\
    \ * _fact[i - 1] : 1;\n    _finv[n] = _fact[n].inverse();\n    for (int i = n;\
    \ i; --i) _finv[i - 1] = Modint(i) * _finv[i];\n    for (int i = 1; i <= n; ++i)\
    \ _inv[i] = _finv[i] * _fact[i - 1];\n  }\n  static Modint inverse(int n) { return\
    \ _inv[n]; }\n  static Modint fact(int n, bool inv = 0) { return inv ? _finv[n]\
    \ : _fact[n]; }\n  static Modint nPr(int n, int r) {\n    if (n < r || r < 0)\
    \ return Modint(0);\n    return _fact[n] * _finv[n - r];\n  }\n  static Modint\
    \ nCr(int n, int r) { return nPr(n, r) * _finv[r]; }\n  static Modint nHr(int\
    \ n, int r) { return !r ? Modint(1) : nCr(n + r - 1, r); }\n  static size_t size()\
    \ { return _inv.size(); }\n};\ntemplate <class Modint>\nvector<Modint> Combination<Modint>::_fact;\n\
    template <class Modint>\nvector<Modint> Combination<Modint>::_finv;\ntemplate\
    \ <class Modint>\nvector<Modint> Combination<Modint>::_inv;\n#line 1 \"src/Math/ModInt.hpp\"\
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
    \ { return x; }\n};\n#line 12 \"test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n#undef call_from_test\n\ntemplate <class Modint>\nvector<Modint> pow_d_list(int\
    \ n, long long d) {\n  vector<int> pdiv(n);\n  for (int i = 2; i < n; i++) pdiv[i]\
    \ = i & 1 ? i : 2;\n  for (int p = 3; p * p < n; p += 2)\n    if (pdiv[p] == p)\n\
    \      for (int q = p * p; q < n; q += 2 * p) pdiv[q] = p;\n\n  vector<Modint>\
    \ res(n);\n  if (d == 0) res[0] = 1;\n  if (n >= 2) res[1] = 1;\n  for (int i\
    \ = 2; i < n; i++) {\n    if (pdiv[i] == i)\n      res[i] = Modint(i).pow(d);\n\
    \    else\n      res[i] = res[pdiv[i]] * res[i / pdiv[i]];\n  }\n  return res;\n\
    }\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint\
    \ = ModInt<998244353>;\n  using C = Combination<Mint>;\n  long long r, d;\n  cin\
    \ >> r >> d;\n  vector<Mint> sum(d + 1), rpow(d + 1), pd = pow_d_list<Mint>(d\
    \ + 1, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d;\
    \ i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d; i++) sum[i] = sum[i\
    \ - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  C::init(d + 1);\n  for (int i =\
    \ 0; i <= d; i++) {\n    Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n\
    \    ans += (d - i) & 1 ? -tmp : tmp;\n  }\n  ans /= Mint(1 - r).pow(d + 1);\n\
    \  cout << ans << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#undef call_from_test\n\
    \ntemplate <class Modint>\nvector<Modint> pow_d_list(int n, long long d) {\n \
    \ vector<int> pdiv(n);\n  for (int i = 2; i < n; i++) pdiv[i] = i & 1 ? i : 2;\n\
    \  for (int p = 3; p * p < n; p += 2)\n    if (pdiv[p] == p)\n      for (int q\
    \ = p * p; q < n; q += 2 * p) pdiv[q] = p;\n\n  vector<Modint> res(n);\n  if (d\
    \ == 0) res[0] = 1;\n  if (n >= 2) res[1] = 1;\n  for (int i = 2; i < n; i++)\
    \ {\n    if (pdiv[i] == i)\n      res[i] = Modint(i).pow(d);\n    else\n     \
    \ res[i] = res[pdiv[i]] * res[i / pdiv[i]];\n  }\n  return res;\n}\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  using C = Combination<Mint>;\n  long long r, d;\n  cin >> r >> d;\n  vector<Mint>\
    \ sum(d + 1), rpow(d + 1), pd = pow_d_list<Mint>(d + 1, d);\n  rpow[0] = 1, sum[0]\
    \ = rpow[0] * pd[0];\n  for (int i = 1; i <= d; i++) rpow[i] = rpow[i - 1] * r;\n\
    \  for (int i = 1; i <= d; i++) sum[i] = sum[i - 1] + rpow[i] * pd[i];\n  Mint\
    \ ans = 0;\n  C::init(d + 1);\n  for (int i = 0; i <= d; i++) {\n    Mint tmp\
    \ = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n    ans += (d - i) & 1 ? -tmp\
    \ : tmp;\n  }\n  ans /= Mint(1 - r).pow(d + 1);\n  cout << ans << endl;\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
---
