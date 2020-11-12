---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/Combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    - https://min-25.hatenablog.com/entry/2015/04/24/031413
  bundledCode: "#line 1 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/Combination.hpp\"\n/**\n * @title \u7D44\
    \u307F\u5408\u308F\u305B\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <class mint, std::size_t LIM = (1 << 24)>\nstruct Combination {\n private:\n\
    \  static inline mint _fact[LIM], _finv[LIM];\n  static inline void set(int sz)\
    \ {\n    static int lim = 0;\n    if (lim <= sz) {\n      if (lim == 0) _fact[0]\
    \ = _finv[0] = 1, lim = 1;\n      for (int i = lim; i <= sz; i++) _fact[i] = _fact[i\
    \ - 1] * i;\n      _finv[sz] = mint(1) / _fact[sz];\n      for (int i = sz; i\
    \ >= lim; i--) _finv[i - 1] = _finv[i] * i;\n      lim = sz + 1;\n    }\n  }\n\
    \n public:\n  static inline mint fact(int n) { return set(n), n < 0 ? mint(0)\
    \ : _fact[n]; }\n  static inline mint finv(int n) { return set(n), n < 0 ? mint(0)\
    \ : _finv[n]; }\n  static mint nPr(int n, int r) { return fact(n) * finv(n - r);\
    \ }\n  static mint nCr(int n, int r) { return nPr(n, r) * finv(r); }\n  static\
    \ mint nHr(int n, int r) { return !r ? mint(1) : nCr(n + r - 1, r); }\n};\n#line\
    \ 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n private:\n  using u64 = std::uint64_t;\n  using u128\
    \ = __uint128_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1)\
    \ {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static\
    \ constexpr u64 inv = mul_inv(mod, 6, 1);\n  static constexpr u64 r2 = -u128(mod)\
    \ % mod;\n  static constexpr u64 m2 = mod << 1;\n\n public:\n  static constexpr\
    \ int level = __builtin_ctzll(mod - 1);\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt()\
    \ = default;\n  static constexpr u64 modulo() { return mod; }\n  static constexpr\
    \ u64 init(u64 w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const\
    \ u128 w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n  static constexpr u64 norm(u64 x) { return x - (mod & -(x >= mod)); }\n\
    \  static constexpr u64 pr_rt() { return prim_root; }\n  constexpr ModInt operator-()\
    \ const {\n    ModInt ret;\n    return ret.x = (m2 & -(x != 0)) - x, ret;\n  }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x -\
    \ m2, x += m2 & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += m2 & -(x >> 63), *this;\n  }\n \
    \ constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x = reduce(u128(this->x)\
    \ * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n\
    \    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const ModInt\
    \ &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const ModInt\
    \ &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const ModInt\
    \ &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const ModInt\
    \ &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const ModInt\
    \ &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const ModInt\
    \ &rhs) const { return norm(x) != norm(rhs.x); }\n  u64 val() const {\n    u64\
    \ ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  constexpr\
    \ ModInt pow(u64 k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base\
    \ = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return\
    \ ret;\n  }\n  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr\
    \ ModInt sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n\
    \    if (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt\
    \ ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b\
    \ += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u,\
    \ std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first + u.second\
    \ * v.second * w);\n      ModInt b = (u.first * v.second + u.second * v.first);\n\
    \      return std::make_pair(a, b);\n    };\n    u64 e = (mod + 1) >> 1;\n   \
    \ auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto bs = std::make_pair(b,\
    \ ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1) ret = mul(ret, bs);\n\
    \    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n  }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n  u64 x;\n};\n\
    #line 3 \"src/Math/lagrange_interpolation.hpp\"\n/**\n * @title \u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593\n * @category \u6570\u5B66\n *  x=0,1,..,N-1\u3068\
    y=f(0),f(1),...,f(N-1)\u304C\u4E0E\u3048\u3089\u308C\u305F\u3068\u304D\u306Ef(t)\u3092\
    \u8A08\u7B97\n *  O(N)\n */\n\n// verify\u7528:http://codeforces.com/contest/622/problem/F\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename K>\nK lagrange_interpolation(std::vector<K>\
    \ &y, K t) {\n  int n = y.size() - 1;\n  std::vector<K> pro(n + 1, 1), orp(n +\
    \ 1, 1);\n  for (int i = 0; i < n; i++) pro[i + 1] = pro[i] * (t - K(i));\n  for\
    \ (int i = n; i > 0; i--) orp[i - 1] = orp[i] * (t - K(i));\n  K fact = K(1);\n\
    \  for (int i = 1; i <= n; i++) fact *= K(i);\n  std::vector<K> finv(n + 1, 1);\n\
    \  finv[n] = K(1) / fact;\n  for (int i = n; i >= 1; i--) finv[i - 1] = finv[i]\
    \ * K(i);\n  K res(0);\n  for (int i = 0; i <= n; i++) {\n    K tmp = y[i] * pro[i]\
    \ * orp[i] * finv[i] * finv[n - i];\n    res += (n - i) & 1 ? -tmp : tmp;\n  }\n\
    \  return res;\n}\n#line 9 \"test/yosupo/sum_of_exponential_times_polynomial.test.cpp\"\
    \nusing namespace std;\n\ntemplate <class Modint>\nvector<Modint> pow_d_list(int\
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
    \ n);\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(r).inverse(), rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n\
    \      y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n \
    \   ans += Mint(r).pow(n) * lagrange_interpolation<Mint>(y, n);\n  }\n  cout <<\
    \ ans << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n/** @see https://min-25.hatenablog.com/entry/2015/04/24/031413\n */\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/Combination.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Math/lagrange_interpolation.hpp\"\nusing namespace std;\n\ntemplate\
    \ <class Modint>\nvector<Modint> pow_d_list(int n, long long d) {\n  vector<int>\
    \ pdiv(n);\n  for (int i = 2; i < n; i++) pdiv[i] = i & 1 ? i : 2;\n  for (int\
    \ p = 3; p * p < n; p += 2)\n    if (pdiv[p] == p)\n      for (int q = p * p;\
    \ q < n; q += 2 * p) pdiv[q] = p;\n\n  vector<Modint> res(n);\n  if (d == 0) res[0]\
    \ = 1;\n  if (n >= 2) res[1] = 1;\n  for (int i = 2; i < n; i++) {\n    if (pdiv[i]\
    \ == i)\n      res[i] = Modint(i).pow(d);\n    else\n      res[i] = res[pdiv[i]]\
    \ * res[i / pdiv[i]];\n  }\n  return res;\n}\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n  using C = Combination<Mint>;\n\
    \  long long r, d, n;\n  cin >> r >> d >> n;\n  if (--n < 0) {\n    cout << 0\
    \ << endl;\n    return 0;\n  }\n  vector<Mint> sum(d + 2), rpow(d + 2), pd = pow_d_list<Mint>(d\
    \ + 2, d);\n  rpow[0] = 1, sum[0] = rpow[0] * pd[0];\n  for (int i = 1; i <= d\
    \ + 1; i++) rpow[i] = rpow[i - 1] * r;\n  for (int i = 1; i <= d + 1; i++) sum[i]\
    \ = sum[i - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  if (r == 1)\n    ans = lagrange_interpolation<Mint>(sum,\
    \ n);\n  else {\n    for (int i = 0; i <= d; i++) {\n      Mint tmp = C::nCr(d\
    \ + 1, i + 1) * rpow[d - i] * sum[i];\n      ans += (d - i) & 1 ? -tmp : tmp;\n\
    \    }\n    ans /= Mint(1 - r).pow(d + 1);\n    vector<Mint> y(d + 1);\n    Mint\
    \ rinv = Mint(r).inverse(), rinvpow = 1;\n    for (int i = 0; i <= d; i++) {\n\
    \      y[i] = Mint(sum[i] - ans) * rinvpow;\n      rinvpow *= rinv;\n    }\n \
    \   ans += Mint(r).pow(n) * lagrange_interpolation<Mint>(y, n);\n  }\n  cout <<\
    \ ans << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  - src/Math/lagrange_interpolation.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2020-11-11 20:34:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial.test.cpp
---
