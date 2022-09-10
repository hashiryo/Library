---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/hafnian.hpp
    title: "\u30CF\u30D5\u30CB\u30A2\u30F3 (\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5B8C\
      \u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/hafnian_of_matrix
    links:
    - https://judge.yosupo.jp/problem/hafnian_of_matrix
  bundledCode: "#line 1 \"test/yosupo/hafnian_of_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t mod,\
    \ std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace internal\n\
    template <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n    :\
    \ public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using\
    \ u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x\
    \ = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n \
    \ static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }\n\
    \  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w >> 64)\
    \ + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n\
    \  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64 w) { return\
    \ w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t\
    \ k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k\
    \ >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n\
    \  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr ModInt\
    \ sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n    if\
    \ (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE\
    \ = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b +=\
    \ ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt,\
    \ ModInt> v) {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n\
    \      ModInt b = (u.first * v.second + u.second * v.first);\n      return std::make_pair(a,\
    \ b);\n    };\n    std::uint64_t e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE,\
    \ ModInt(0));\n    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs,\
    \ bs))\n      if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 <\
    \ mod ? ret.first : -ret.first;\n  }\n  constexpr u64 val() const {\n    u64 ret\
    \ = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x\
    \ = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2,\
    \ pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t\
    \ n = 0) : x(n & 1) {}\n  constexpr ModInt operator-() const { return *this; }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n  constexpr\
    \ ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }\n  constexpr\
    \ ModInt sqrt() const { return *this; }\n  constexpr ModInt inverse() const {\
    \ return *this; }\n  constexpr std::uint64_t val() const { return x; }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/Math/hafnian.hpp\"\
    \n/**\n * @title \u30CF\u30D5\u30CB\u30A2\u30F3 (\u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u6570)\n * @category \u6570\u5B66\
    \n * @see\n * A. Bj\xF6rklund, \"Counting Perfect Matchings as Fast as Ryser,\u3000\
    Proc. of 23rd\n * ACM-SIAM symposium on Discrete Algorithms, pp.914-921, 2012.\n\
    \ *\n * O(N^2 2^(N/2)) time\n * polynomial space\n * \u81EA\u5DF1\u30EB\u30FC\u30D7\
    \u306A\u3057\n */\n// BEGIN CUT HERE\n\ntemplate <typename T, unsigned short MAX_N\
    \ = 38>\nT hafnian(const std::vector<std::vector<T>> &mat) {\n  using Poly = std::array<T,\
    \ MAX_N / 2 + 1>;\n  const int n = mat.size(), n2 = n / 2;\n  assert(!(n & 1));\n\
    \  for (int i = n; i--;)\n    for (int j = i; j--;) assert(mat[i][j] == mat[j][i]);\n\
    \  std::vector<std::vector<Poly>> a(n);\n  for (int i = n, j; i--;)\n    for (a[j\
    \ = i].resize(i); j--;) a[i][j][0] = mat[i][j];\n  auto rec = [&](auto self, const\
    \ auto &b) -> Poly {\n    const int m = b.size() - 2;\n    if (m < 0) return Poly{1};\n\
    \    auto c = b;\n    c.resize(m);\n    Poly r = self(self, c);\n    for (int\
    \ i = m; i--;)\n      for (int j = i; j--;)\n        for (int k = n2 - m / 2;\
    \ k--;)\n          for (int l = k; l >= 0; l--)\n            c[i][j][k + 1] +=\
    \ b[m][i][l] * b[m + 1][j][k - l] +\n                              b[m + 1][i][l]\
    \ * b[m][j][k - l];\n    Poly t = self(self, c);\n    for (int i = n2, j; i >=\
    \ 0; i--)\n      for (r[i] = t[j = i] - r[i]; j--;) r[i] += t[j] * b[m + 1][m][i\
    \ - j - 1];\n    return r;\n  };\n  return rec(rec, a)[n2];\n}\n#line 5 \"test/yosupo/hafnian_of_matrix.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ a(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> a[i][j];\n  cout << hafnian(a) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/hafnian.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ a(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> a[i][j];\n  cout << hafnian(a) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/hafnian.hpp
  isVerificationFile: true
  path: test/yosupo/hafnian_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2022-02-21 12:14:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/hafnian_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/hafnian_of_matrix.test.cpp
- /verify/test/yosupo/hafnian_of_matrix.test.cpp.html
title: test/yosupo/hafnian_of_matrix.test.cpp
---
