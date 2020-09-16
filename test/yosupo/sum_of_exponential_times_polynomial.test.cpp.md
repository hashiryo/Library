---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':x:'
    path: src/Math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n\n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n\n#include\
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
    \ { return x; }\n};\n#line 1 \"src/Math/lagrange_interpolation.hpp\"\n/**\n *\
    \ @title \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\n * @category \u6570\
    \u5B66\n *  x=0,1,..,N-1\u3068y=f(0),f(1),...,f(N-1)\u304C\u4E0E\u3048\u3089\u308C\
    \u305F\u3068\u304D\u306Ef(t)\u3092\u8A08\u7B97\n *  O(N)\n */\n\n// verify\u7528\
    :http://codeforces.com/contest/622/problem/F\n\n#ifndef call_from_test\n#line\
    \ 12 \"src/Math/lagrange_interpolation.hpp\"\nusing namespace std;\n#endif\n\n\
    template <typename K>\nK lagrange_interpolation(vector<K> &y, K t) {\n  int n\
    \ = y.size() - 1;\n  vector<K> pro(n + 1, 1), orp(n + 1, 1);\n  for (int i = 0;\
    \ i < n; i++) pro[i + 1] = pro[i] * (t - K(i));\n  for (int i = n; i > 0; i--)\
    \ orp[i - 1] = orp[i] * (t - K(i));\n  K fact = K(1);\n  for (int i = 1; i <=\
    \ n; i++) fact *= K(i);\n  vector<K> finv(n + 1, 1);\n  finv[n] = K(1) / fact;\n\
    \  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i] * K(i);\n  K res(0);\n \
    \ for (int i = 0; i <= n; i++) {\n    K tmp = y[i] * pro[i] * orp[i] * finv[i]\
    \ * finv[n - i];\n    res += (n - i) & 1 ? -tmp : tmp;\n  }\n  return res;\n}\n\
    #line 14 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\n#undef\
    \ call_from_test\n\ntemplate <class Modint>\nvector<Modint> pow_d_list(int n,\
    \ long long d) {\n  vector<int> pdiv(n);\n  for (int i = 2; i < n; i++) pdiv[i]\
    \ = i & 1 ? i : 2;\n  for (int p = 3; p * p < n; p += 2)\n    if (pdiv[p] == p)\n\
    \      for (int q = p * p; q < n; q += 2 * p) pdiv[q] = p;\n\n  vector<Modint>\
    \ res(n);\n  if (d == 0) res[0] = 1;\n  if (n >= 2) res[1] = 1;\n  for (int i\
    \ = 2; i < n; i++) {\n    if (pdiv[i] == i)\n      res[i] = Modint(i).pow(d);\n\
    \    else\n      res[i] = res[pdiv[i]] * res[i / pdiv[i]];\n  }\n  return res;\n\
    }\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint\
    \ = ModInt<998244353>;\n  using C = Combination<Mint>;\n  long long r, d, n;\n\
    \  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n    return 0;\n\
    \  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = pow_d_list<Mint>(d + 2, d);\n\
    \  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d + 1; i++)\
    \ rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i] = sum[i\
    \ - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = lagrange_interpolation<Mint>(sum,\
    \ n);\n  else {\n    C::init(d + 1);\n    for (int i = 0; i <= d; i++) {\n   \
    \   Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d -\
    \ i) & 1 ? -tmp : tmp;\n    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint>\
    \ y(d + 1);\n    Mint rinv = Mint(r).inverse(), rinvpow = 1;\n    for (int i =\
    \ 0; i <= d; i++) {\n      y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow\
    \ *= rinv;\n    }\n    ans += Mint(r).pow(n) * lagrange_interpolation<Mint>(y,\
    \ n);\n  }\n  cout << ans << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n\n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/lagrange_interpolation.hpp\"\
    \n#undef call_from_test\n\ntemplate <class Modint>\nvector<Modint> pow_d_list(int\
    \ n, long long d) {\n  vector<int> pdiv(n);\n  for (int i = 2; i < n; i++) pdiv[i]\
    \ = i & 1 ? i : 2;\n  for (int p = 3; p * p < n; p += 2)\n    if (pdiv[p] == p)\n\
    \      for (int q = p * p; q < n; q += 2 * p) pdiv[q] = p;\n\n  vector<Modint>\
    \ res(n);\n  if (d == 0) res[0] = 1;\n  if (n >= 2) res[1] = 1;\n  for (int i\
    \ = 2; i < n; i++) {\n    if (pdiv[i] == i)\n      res[i] = Modint(i).pow(d);\n\
    \    else\n      res[i] = res[pdiv[i]] * res[i / pdiv[i]];\n  }\n  return res;\n\
    }\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint\
    \ = ModInt<998244353>;\n  using C = Combination<Mint>;\n  long long r, d, n;\n\
    \  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0 << endl;\n    return 0;\n\
    \  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = pow_d_list<Mint>(d + 2, d);\n\
    \  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d + 1; i++)\
    \ rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i] = sum[i\
    \ - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = lagrange_interpolation<Mint>(sum,\
    \ n);\n  else {\n    C::init(d + 1);\n    for (int i = 0; i <= d; i++) {\n   \
    \   Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d -\
    \ i) & 1 ? -tmp : tmp;\n    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint>\
    \ y(d + 1);\n    Mint rinv = Mint(r).inverse(), rinvpow = 1;\n    for (int i =\
    \ 0; i <= d; i++) {\n      y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow\
    \ *= rinv;\n    }\n    ans += Mint(r).pow(n) * lagrange_interpolation<Mint>(y,\
    \ n);\n  }\n  cout << ans << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  - src/Math/lagrange_interpolation.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
---
