---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/SparseSquareMatrix.hpp
    title: "\u758E\u884C\u5217"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/berlekamp_massey.hpp
    title: Berlekamp-Massey
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sparse_matrix_det
    links:
    - https://judge.yosupo.jp/problem/sparse_matrix_det
  bundledCode: "#line 1 \"test/yosupo/sparse_matrix_det.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n#include <bits/stdc++.h>\n\
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
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 3 \"src/Math/berlekamp_massey.hpp\"\
    \n/**\n * @title Berlekamp-Massey\n * @category \u6570\u5B66\n * \u6570\u5217\u306E\
    \u6700\u521D\u306EN\u9805\u304B\u3089\u3001\u305D\u306E\u6570\u5217\u3092\u751F\
    \u6210\u3059\u308BN/2\u6B21\u4EE5\u4E0B\u306E\u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\
    \u5316\u5F0F\u3092\u6C42\u3081\u308B\n *  O(N^2)\n */\n\n// verify\u7528:\n//\
    \ https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\n\
    // BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1] *\
    \ a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  std::vector<K>\
    \ c(n), b(n), tmp;\n  K x = 1, y, coef;\n  const K Z = 0;\n  for (c[0] = b[0]\
    \ = 1, i = 0, j; i < n; ++i) {\n    for (++m, y = a[i], j = 1; j <= d; ++j) y\
    \ += c[j] * a[i - j];\n    if (y == Z) continue;\n    for (tmp = c, coef = y /\
    \ x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n    if (2 * d > i) continue;\n\
    \    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n  c.resize(d + 1), c.erase(c.begin());\n\
    \  for (auto &x : c) x = -x;\n  return c;\n}\n#line 4 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\
    \n/**\n * @title \u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F\n * @category\
    \ \u7DDA\u5F62\u4EE3\u6570\n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n\
    \ * O(N*S(N))\n */\n\n// BEGIN CUT HERE\n\n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)\
    \  + ... + c[1] * M + c[0]) * b = 0\ntemplate <class Mat, class Vec>\nclass MinimalPolynomial\
    \ {\n  using mod_t = std::remove_reference_t<decltype((Vec{1})[0])>;\n  static\
    \ const inline mod_t ZERO = 0;\n  std::vector<mod_t> poly, rev;\n  std::vector<Vec>\
    \ bs;\n  std::size_t dg, n;\n  static inline int deg(const std::vector<mod_t>\
    \ &p) {\n    for (int d = p.size() - 1;; d--)\n      if (d < 0 || p[d] != ZERO)\
    \ return d;\n  }\n  static inline std::vector<mod_t> bostan_mori_msb(const std::vector<mod_t>\
    \ &q,\n                                                   std::uint64_t k) {\n\
    \    int d = deg(q);\n    assert(d >= 0), assert(q[0] != ZERO);\n    std::vector<mod_t>\
    \ ret(std::max(d, 1));\n    if (k == 0) return ret.back() = mod_t(1), ret;\n \
    \   std::vector<mod_t> v(d + 1);\n    for (int i = 0; i <= d; i += 2)\n      for\
    \ (int j = 0; j <= d; j += 2) v[(i + j) >> 1] += q[i] * q[j];\n    for (int i\
    \ = 1; i <= d; i += 2)\n      for (int j = 1; j <= d; j += 2) v[(i + j) >> 1]\
    \ -= q[i] * q[j];\n    auto w = bostan_mori_msb(v, k >> 1);\n    for (int i =\
    \ 2 * d - 1 - (k & 1); i >= d; i -= 2)\n      for (int j = 0; j <= d; j += 2)\
    \ ret[i - d] += q[j] * w[(i - j) >> 1];\n    for (int i = 2 * d - 1 - !(k & 1);\
    \ i >= d; i -= 2)\n      for (int j = 1; j <= d; j += 2) ret[i - d] -= q[j] *\
    \ w[(i - j) >> 1];\n    return ret;\n  }\n  std::vector<mod_t> x_pow_mod(std::uint64_t\
    \ k) const {\n    assert(k >= n);\n    std::vector<mod_t> ret(n), u = bostan_mori_msb(rev,\
    \ k - n + dg);\n    for (int i = dg; i--;)\n      for (int j = i + 1; j--;) ret[n\
    \ - 1 - i] += u[j] * rev[i - j];\n    return ret;\n  }\n\n public:\n  MinimalPolynomial(const\
    \ Mat &M, Vec b) : n(M.size()) {\n    std::size_t i, j;\n    assert(n == b.size());\n\
    \    std::vector<mod_t> a(n), v;\n    for (auto &x : a) x = get_rand(1, mod_t::modulo()\
    \ - 1);\n    mod_t tmp;\n    for (i = (n + 1) << 1; i--; v.push_back(tmp)) {\n\
    \      if (i > n) bs.emplace_back(b);\n      for (tmp = 0, j = n; j--;) tmp +=\
    \ a[j] * b[j];\n      if (i) b = M * b;\n    }\n    rev = berlekamp_massey(v);\n\
    \    for (auto &x : rev) x = -x;\n    rev.insert(rev.begin(), 1), poly = rev;\n\
    \    rev.erase(rev.begin() + (dg = deg(rev)) + 1, rev.end());\n    std::reverse(poly.begin(),\
    \ poly.end());\n  }\n  static std::uint64_t get_rand(std::uint64_t l, std::uint64_t\
    \ r) {\n    static std::mt19937_64 gen(std::random_device{}());\n    return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n  }\n  Vec pow(std::uint64_t k) const {  // M^k * b\n    if (k < n)\
    \ return bs[k];\n    auto r = x_pow_mod(k);\n    Vec ret = bs[0];\n    for (auto\
    \ &x : ret) x *= r[0];\n    for (int i = 1, e = r.size(), j; i < e; i++)\n   \
    \   for (j = n; j--;) ret[j] += r[i] * bs[i][j];\n    return ret;\n  }\n  const\
    \ mod_t operator[](std::size_t k) const { return poly[k]; }\n  const auto begin()\
    \ const { return poly.begin(); }\n  const auto end() const { return poly.end();\
    \ }\n  const std::size_t size() const { return dg + 1; }\n};\n#line 4 \"src/LinearAlgebra/SparseSquareMatrix.hpp\"\
    \n\n/**\n * @title \u758E\u884C\u5217\n * @category \u6570\u5B66\n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n\
    \ * @brief O(N*S(N)) S(N): \u884C\u5217\u306E\u975E\u96F6\u6210\u5206\u306E\u6570\
    \n */\n\n// BEGIN CUT HERE\ntemplate <class mod_t>\nstruct SparseSquareMatrix\
    \ {\n  SparseSquareMatrix(std::size_t n_) : n(n_) {}\n  void add_component(std::size_t\
    \ i, std::size_t j, mod_t val) {\n    dat.emplace_back(i, j, val);\n  }\n  std::vector<mod_t>\
    \ operator*(const std::vector<mod_t> &vec) const {\n    std::vector<mod_t> ret(n);\n\
    \    assert(vec.size() == n);\n    for (const auto &[i, j, val] : dat) ret[i]\
    \ += val * vec[j];\n    return ret;\n  }\n  auto begin() { return dat.begin();\
    \ }\n  auto end() { return dat.end(); }\n  std::size_t size() const { return n;\
    \ }\n  mod_t det() const {\n    const std::uint64_t MOD = mod_t::modulo();\n \
    \   using MinPoly = MinimalPolynomial<SparseSquareMatrix, std::vector<mod_t>>;\n\
    \    SparseSquareMatrix M(*this);\n    std::vector<mod_t> d(n), b(n);\n    for\
    \ (auto &x : b) x = MinPoly::get_rand(1, MOD - 1);\n    for (auto &x : d) x =\
    \ MinPoly::get_rand(1, MOD - 1);\n    for (auto &[i, j, val] : M) val *= d[j];\n\
    \    mod_t ret = MinPoly(M, b)[0], tmp = 1;\n    for (const auto &x : d) tmp *=\
    \ x;\n    if (n & 1) ret = -ret;\n    return ret / tmp;\n  }\n\n private:\n  std::size_t\
    \ n;\n  std::vector<std::tuple<std::size_t, std::size_t, mod_t>> dat;\n};\n#line\
    \ 5 \"test/yosupo/sparse_matrix_det.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = ModInt<998244353>;\n\
    \  int N, K;\n  cin >> N >> K;\n  SparseSquareMatrix<Mint> M(N);\n  for (int i\
    \ = 0; i < K; i++) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    M.add_component(a,\
    \ b, c);\n  }\n  cout << M.det() << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/LinearAlgebra/SparseSquareMatrix.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  int N, K;\n  cin >> N >> K;\n  SparseSquareMatrix<Mint>\
    \ M(N);\n  for (int i = 0; i < K; i++) {\n    int a, b, c;\n    cin >> a >> b\
    \ >> c;\n    M.add_component(a, b, c);\n  }\n  cout << M.det() << '\\n';\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/LinearAlgebra/SparseSquareMatrix.hpp
  - src/LinearAlgebra/MinimalPolynomial.hpp
  - src/Math/berlekamp_massey.hpp
  isVerificationFile: true
  path: test/yosupo/sparse_matrix_det.test.cpp
  requiredBy: []
  timestamp: '2022-06-24 13:34:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sparse_matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sparse_matrix_det.test.cpp
- /verify/test/yosupo/sparse_matrix_det.test.cpp.html
title: test/yosupo/sparse_matrix_det.test.cpp
---
