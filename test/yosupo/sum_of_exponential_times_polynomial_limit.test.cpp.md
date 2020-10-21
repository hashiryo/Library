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
  _verificationStatusIcon: ':x:'
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
    \ level = __builtin_ctzll(mod - 1);\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() =\
    \ default;\n  static constexpr uint64_t modulo() { return mod; }\n  static constexpr\
    \ uint64_t init(uint64_t w) { return reduce(u128(w) * r2); }\n  static constexpr\
    \ uint64_t reduce(const u128 w) {\n    return uint64_t(w >> 64) + mod - ((u128(uint64_t(w)\
    \ * inv) * mod) >> 64);\n  }\n  static constexpr uint64_t norm(uint64_t x) { return\
    \ x - (mod & -(x >= mod)); }\n  static constexpr uint64_t pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt\
    \ &rhs) {\n    return x += rhs.x - m2, x += m2 & -(x >> 63), *this;\n  }\n  constexpr\
    \ ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += m2 & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(u128(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  uint64_t get() const {\n    uint64_t ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  constexpr ModInt pow(uint64_t k) const {\n\
    \    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *=\
    \ base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt\
    \ inverse() const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n\
    \    if (*this == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1)\
    \ >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b\
    \ * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b\
    \ - *this;\n    auto mul = [&](pair<ModInt, ModInt> u, pair<ModInt, ModInt> v)\
    \ {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt\
    \ b = (u.first * v.second + u.second * v.first);\n      return make_pair(a, b);\n\
    \    };\n    uint64_t e = (mod + 1) >> 1;\n    auto ret = make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if\
    \ (e & 1) ret = mul(ret, bs);\n    return ret.first.get() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.get();\n\
    \  }\n  uint64_t x;\n};\n#line 12 \"test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp\"\
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
    \ - 1] + rpow[i] * pd[i];\n  Mint ans = 0;\n  for (int i = 0; i <= d; i++) {\n\
    \    Mint tmp = C::nCr(d + 1, i + 1) * rpow[d - i] * sum[i];\n    ans += (d -\
    \ i) & 1 ? -tmp : tmp;\n  }\n  ans /= Mint(1 - r).pow(d + 1);\n  cout << ans <<\
    \ endl;\n  return 0;\n}\n"
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
    \ ans = 0;\n  for (int i = 0; i <= d; i++) {\n    Mint tmp = C::nCr(d + 1, i +\
    \ 1) * rpow[d - i] * sum[i];\n    ans += (d - i) & 1 ? -tmp : tmp;\n  }\n  ans\
    \ /= Mint(1 - r).pow(d + 1);\n  cout << ans << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/Combination.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 16:47:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
- /verify/test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp.html
title: test/yosupo/sum_of_exponential_times_polynomial_limit.test.cpp
---