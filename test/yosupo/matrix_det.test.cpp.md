---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/GaussianElimination.hpp
    title: "\u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t\
    \ mod, std::uint64_t prim_root = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6,\
    \ u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n\
    \  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(u128(w) * r2); }\n  static\
    \ constexpr u64 reduce(const u128 w) {\n    return u64(w >> 64) + mod - ((u128(u64(w)\
    \ * inv) * mod) >> 64);\n  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt()\
    \ = default;\n  static constexpr u64 modulo() { return mod; }\n  static constexpr\
    \ u64 norm(u64 w) { return w - (mod & -(w >= mod)); }\n  static constexpr u64\
    \ pr_rt() { return prim_root; }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(u128(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return norm(x) != norm(rhs.x); }\n  u64 val() const {\n\
    \    u64 ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n\
    \  constexpr ModInt pow(u64 k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt\
    \ base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret *= base;\n   \
    \ return ret;\n  }\n  constexpr ModInt inverse() const { return pow(mod - 2);\
    \ }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0) || mod == 2)\
    \ return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n\
    \    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1)\
    \ == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt>\
    \ u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first + u.second\
    \ * v.second * w);\n      ModInt b = (u.first * v.second + u.second * v.first);\n\
    \      return std::make_pair(a, b);\n    };\n    u64 e = (mod + 1) >> 1;\n   \
    \ auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto bs = std::make_pair(b,\
    \ ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1) ret = mul(ret, bs);\n\
    \    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n  }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n  u64 x;\n};\n\
    #line 3 \"src/Math/GaussianElimination.hpp\"\n/**\n * @title \u30AC\u30A6\u30B9\
    \u306E\u6D88\u53BB\u6CD5\n * @category \u6570\u5B66\n * linear_equation(A,b) \u8FD4\
    \u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\u4E00\u3064,\u89E3\u7A7A\u9593\u306E\
    \u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\n// BEGIN CUT HERE\n\nclass GaussianElimination\
    \ {\n  template <class T>\n  inline static constexpr bool IFPV = std::is_floating_point_v<T>;\n\
    \  template <class T, typename std::enable_if_t<IFPV<T>> * = nullptr>\n  static\
    \ bool is_zero(T x) {\n    return std::abs(x) < 1e-8;\n  }\n  template <class\
    \ T, typename std::enable_if_t<!IFPV<T>> * = nullptr>\n  static bool is_zero(T\
    \ x) {\n    return x == T(0);\n  }\n  template <class T, typename std::enable_if_t<IFPV<T>>\
    \ * = nullptr>\n  static bool compare(T x, T y) {\n    return std::abs(x) < std::abs(y);\n\
    \  }\n  template <class T, typename std::enable_if_t<!IFPV<T>> * = nullptr>\n\
    \  static bool compare(T, T y) {\n    return y != T(0);\n  }\n  template <class\
    \ LHS, class RHS>\n  static void subst(LHS &lhs, const RHS &rhs, int n, int m)\
    \ {\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) lhs[i][j]\
    \ = rhs[i][j];\n  }\n  template <int M>\n  static int row_reduction(std::vector<std::bitset<M>>\
    \ &a, int lim = 1 << 30) {\n    int n = a.size(), rank = 0, j, p;\n    for (lim\
    \ = std::min(lim, M), j = 0, p = rank; j < lim; j++, p = rank) {\n      while\
    \ (p < n - 1 && !a[p][j]) p++;\n      if (!a[p][j]) continue;\n      std::swap(a[p],\
    \ a[rank]);\n      for (int i = 0; i < n; i++)\n        if (i != rank && a[i][j])\
    \ a[i] ^= a[rank];\n      if (++rank == n) break;\n    }\n    return rank;\n \
    \ }\n\n public:\n  template <class K>\n  static auto row_reduction(std::vector<std::vector<K>>\
    \ &a, int lim = 1 << 30) {\n    int n = a.size(), m = a[0].size(), rank = 0, j,\
    \ p;\n    K det = K(1), invc;\n    for (lim = std::min(lim, m), j = 0, p = rank;\
    \ j < lim; j++, p = rank) {\n      for (int i = rank + 1; i < n; i++)\n      \
    \  if (compare(a[p][j], a[i][j])) p = i;\n      if (is_zero(a[p][j])) continue;\n\
    \      if (p != rank) std::swap(a[p], a[rank]), det = -det;\n      invc = K(1)\
    \ / a[rank][j], det *= a[rank][j];\n      for (int k = j; k < m; k++) a[rank][k]\
    \ *= invc;\n      for (int i = 0; i < n; i++)\n        if (i != rank && !is_zero(a[i][j]))\n\
    \          for (int k = m - 1; k >= j; k--) a[i][k] -= a[i][j] * a[rank][k];\n\
    \      if (++rank == n) break;\n    }\n    return std::make_pair(rank, rank ==\
    \ n ? det : K(0));\n  }\n  static auto row_reduction(std::vector<std::vector<bool>>\
    \ &a,\n                            int lim = 1 << 30) {\n    int n = a.size(),\
    \ m = a[0].size(), rank;\n    if (m < 1024) {\n      std::vector<std::bitset<1024>>\
    \ b(n);\n      subst(b, a, n, m), rank = row_reduction<1024>(b, lim), subst(a,\
    \ b, n, m);\n    } else {\n      std::vector<std::bitset<4096>> b(n);\n      subst(b,\
    \ a, n, m), rank = row_reduction<4096>(b, lim), subst(a, b, n, m);\n    }\n  \
    \  return std::make_pair(rank, rank == n);\n  }\n  template <class K>\n  static\
    \ std::pair<std::vector<K>, std::vector<std::vector<K>>> linear_equation(\n  \
    \    std::vector<std::vector<K>> a, const std::vector<K> &b) {\n    int n = a.size(),\
    \ m = a[0].size();\n    for (int i = 0; i < n; i++) a[i].emplace_back(b[i]);\n\
    \    int rank = row_reduction(a, m).first;\n    for (int i = rank; i < n; ++i)\n\
    \      if (!is_zero(K(a[i][m]))) return {{}, {}};\n    std::vector<K> c(m, K(0));\n\
    \    std::vector<int> piv(m, -1);\n    for (int i = 0, j = 0; i < rank; i++) {\n\
    \      while (is_zero(K(a[i][j]))) j++;\n      c[j] = a[i][m], piv[j] = i;\n \
    \   }\n    std::vector<std::vector<K>> d;\n    for (int j = 0; j < m; ++j) {\n\
    \      if (piv[j] != -1) continue;\n      std::vector<K> x(m, K(0));\n      x[j]\
    \ = K(-1);\n      for (int k = 0; k < j; ++k)\n        if (piv[k] != -1) x[k]\
    \ = a[piv[k]][j];\n      d.emplace_back(x);\n    }\n    return {c, d};\n  }\n\
    };\n#line 5 \"test/yosupo/matrix_det.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  using GE = GaussianElimination;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ A(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> A[i][j];\n  cout << GE::row_reduction(A).second << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/GaussianElimination.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  using GE = GaussianElimination;\n  int N;\n\
    \  cin >> N;\n  vector<vector<Mint>> A(N, vector<Mint>(N));\n  for (int i = 0;\
    \ i < N; i++)\n    for (int j = 0; j < N; j++) cin >> A[i][j];\n  cout << GE::row_reduction(A).second\
    \ << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/GaussianElimination.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 19:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
