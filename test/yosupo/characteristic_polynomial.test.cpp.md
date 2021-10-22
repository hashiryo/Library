---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/characteristic_polynomial.hpp
    title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/characteristic_polynomial
    links:
    - https://judge.yosupo.jp/problem/characteristic_polynomial
  bundledCode: "#line 1 \"test/yosupo/characteristic_polynomial.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\n\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/characteristic_polynomial.hpp\"\n/**\n *\
    \ @title \u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate <class K>\nstd::vector<std::vector<K>>\
    \ hessenberg(const std::vector<std::vector<K>> &a) {\n  std::size_t n = a.size();\n\
    \  auto ret = a;\n  for (std::size_t j = 0; j + 2 < n; ++j) {\n    for (std::size_t\
    \ i = j + 1; i < n; ++i)\n      if (ret[i][j] != 0) {\n        std::swap(ret[j\
    \ + 1], ret[i]);\n        for (std::size_t r = 0; r < n; ++r) std::swap(ret[r][j\
    \ + 1], ret[r][i]);\n        break;\n      }\n    if (ret[j + 1][j] != 0)\n  \
    \    for (std::size_t i = j + 2; i < n; ++i) {\n        auto m = ret[i][j] / ret[j\
    \ + 1][j];\n        for (std::size_t c = j; c < n; ++c) ret[i][c] -= m * ret[j\
    \ + 1][c];\n        for (std::size_t r = 0; r < n; ++r) ret[r][j + 1] += m * ret[r][i];\n\
    \      }\n  }\n  return ret;\n}\n\ntemplate <class K>\nstd::vector<K> characteristic_polynomial(const\
    \ std::vector<std::vector<K>> &a) {\n  std::size_t n = a.size();\n  auto b = hessenberg(a);\n\
    \  for (std::size_t i = 0; i < n; i++)\n    for (std::size_t j = 0; j < n; j++)\
    \ b[i][j] = -b[i][j];\n  std::vector<std::vector<K>> fss(n + 1);\n  fss[0] = {1};\n\
    \  for (std::size_t i = 0; i < n; ++i) {\n    fss[i + 1].assign(i + 2, 0);\n \
    \   for (std::size_t k = 0; k <= i; ++k) fss[i + 1][k + 1] = fss[i][k];\n    for\
    \ (std::size_t k = 0; k <= i; ++k) fss[i + 1][k] += b[i][i] * fss[i][k];\n   \
    \ K prod = 1;\n    for (std::size_t j = i; j--;) {\n      prod *= -b[j + 1][j];\n\
    \      const K s = prod * b[j][i];\n      for (std::size_t k = 0; k <= j; ++k)\
    \ fss[i + 1][k] += s * fss[j][k];\n    }\n  }\n  return fss.back();\n}\n#line\
    \ 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n  using u128 = __uint128_t;\n\
    \  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e ==\
    \ 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv\
    \ = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n  static constexpr u64 init(u64\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const u128\
    \ w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t\
    \ n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static\
    \ constexpr u64 modulo() { return mod; }\n  static constexpr u64 norm(u64 w) {\
    \ return w - (mod & -(w >= mod)); }\n  static constexpr u64 pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >>\
    \ 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return\
    \ x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
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
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n  u64 x;\n};\n#line 6 \"test/yosupo/characteristic_polynomial.test.cpp\"\
    \n\nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ a(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> a[i][j];\n  auto p = characteristic_polynomial(a);\n  for (int\
    \ i = 0; i <= N; i++) cout << (i ? \" \" : \"\") << p[i];\n  cout << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\
    \n\n#include <bits/stdc++.h>\n#include \"src/Math/characteristic_polynomial.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\n\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  vector<vector<Mint>> a(N, vector<Mint>(N));\n  for (int\
    \ i = 0; i < N; i++)\n    for (int j = 0; j < N; j++) cin >> a[i][j];\n  auto\
    \ p = characteristic_polynomial(a);\n  for (int i = 0; i <= N; i++) cout << (i\
    \ ? \" \" : \"\") << p[i];\n  cout << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/characteristic_polynomial.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/characteristic_polynomial.test.cpp
  requiredBy: []
  timestamp: '2021-10-12 11:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/characteristic_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/characteristic_polynomial.test.cpp
- /verify/test/yosupo/characteristic_polynomial.test.cpp.html
title: test/yosupo/characteristic_polynomial.test.cpp
---
