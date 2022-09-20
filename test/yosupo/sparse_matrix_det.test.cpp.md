---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/LinearAlgebra/MinimalPolynomial.hpp
    title: "\u884C\u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F"
  - icon: ':question:'
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
    \n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace std;\n\
    struct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct dyn_mint_base\
    \ : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const { return pow(D::mod - 2); }\n\
    \  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, u64>, u128, u64>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_integral_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod)\
    \ : n % B::mod) {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n#define ASSIGN(m,\
    \ p) return x m## = B::mod & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na\
    \ &operator+=(const ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const\
    \ ModInt_Na &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Uint = u64;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_integral_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    #define ASGN(op, a) return x op## = a, x += (B::mod << 1) & -(x >> 63), *this\n\
    \  constexpr mod_t &operator+=(const mod_t &r) { ASGN(+, r.x - (B::mod << 1));\
    \ }\n  constexpr mod_t &operator-=(const mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n\
    \  constexpr mod_t &operator*=(const mod_t &r) { return x = mul(x, r.x), *this;\
    \ }\n  constexpr bool operator==(const mod_t &r) const { return norm() == r.norm();\
    \ }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - B::mod;\n    return\
    \ ret + (B::mod & -(ret >> 63));\n  }\n\n private:\n  static constexpr inline\
    \ u64 reduce(const u128 &w) {\n    return u64(w >> 64) + B::mod - ((u128(u64(w)\
    \ * B::iv) * B::mod) >> 64);\n  }\n  static constexpr inline u64 mul(u64 l, u64\
    \ r) { return reduce(u128(l) * r); }\n  u64 x = 0;\n  constexpr inline u64 norm()\
    \ const { return x - (B::mod & -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64\
    \ n, int e = 6, u64 x = 1) {\n  return e ? mul_inv(n, e - 1, x * (2 - x * n))\
    \ : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na : sta_mint_base {\n protected:\n\
    \  using Uint = conditional_t < MOD<UINT_MAX, uint32_t, u64>;\n  static constexpr\
    \ Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct StaticB_Mon : sta_mint_base\
    \ {\n protected:\n  static_assert(MOD & 1);\n  static constexpr u64 mod = MOD,\
    \ iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate <class Int, int id =\
    \ -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<Int>);\n\
    \  static inline void set_mod(Int m) { mod = m; }\n\n protected:\n  using Uint\
    \ = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate <int id>\n\
    struct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64 m) {\n\
    \    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n protected:\n\
    \  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing StaticModInt\
    \ =\n    conditional_t<mod &(mod >= UINT_MAX), ModInt_Mon<StaticB_Mon<mod>>,\n\
    \                  ModInt_Na<StaticB_Na<mod>>>;\nstruct Montgomery {};\ntemplate\
    \ <class Int, int id = -1>\nusing DynamicModInt =\n    conditional_t<is_same_v<Int,\
    \ Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n                  ModInt_Na<DynamicB_Na<Int,\
    \ id>>>;\n}  // namespace modint_internal\nusing modint_internal::DynamicModInt,\
    \ modint_internal::StaticModInt,\n    modint_internal::Montgomery, modint_internal::is_dynamicmodint_v,\n\
    \    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n#line\
    \ 3 \"src/Math/berlekamp_massey.hpp\"\n/**\n * @title Berlekamp-Massey\n * @category\
    \ \u6570\u5B66\n * \u6570\u5217\u306E\u6700\u521D\u306EN\u9805\u304B\u3089\u3001\
    \u305D\u306E\u6570\u5217\u3092\u751F\u6210\u3059\u308BN/2\u6B21\u4EE5\u4E0B\u306E\
    \u6700\u5C0F\u306E\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6C42\u3081\u308B\n * \
    \ O(N^2)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/tenka1-2015-qualb/tasks/tenka1_2015_qualB_c\n\
    \n// BEGIN CUT HERE\n\n// a[n] = c[0] * a[n-1] + c[1] * a[n-2] + ... + c[d-1]\
    \ * a[n-d]\n// return c\ntemplate <class K>\nstd::vector<K> berlekamp_massey(const\
    \ std::vector<K> &a) {\n  std::size_t n = a.size(), d = 0, m = 0, i, j;\n  if\
    \ (n == 0) return {};\n  std::vector<K> c(n), b(n), tmp;\n  K x = 1, y, coef;\n\
    \  const K Z = 0;\n  for (c[0] = b[0] = 1, i = 0, j; i < n; ++i) {\n    for (++m,\
    \ y = a[i], j = 1; j <= d; ++j) y += c[j] * a[i - j];\n    if (y == Z) continue;\n\
    \    for (tmp = c, coef = y / x, j = m; j < n; ++j) c[j] -= coef * b[j - m];\n\
    \    if (2 * d > i) continue;\n    d = i + 1 - d, b = tmp, x = y, m = 0;\n  }\n\
    \  c.resize(d + 1), c.erase(c.begin());\n  for (auto &x : c) x = -x;\n  return\
    \ c;\n}\n#line 4 \"src/LinearAlgebra/MinimalPolynomial.hpp\"\n/**\n * @title \u884C\
    \u5217\u306E\u6700\u5C0F\u591A\u9805\u5F0F\n * @category \u7DDA\u5F62\u4EE3\u6570\
    \n * @see https://yukicoder.me/wiki/black_box_linear_algebra\n * O(N*S(N))\n */\n\
    \n// BEGIN CUT HERE\n\n// c s.t. (c[d] * M^d + c[d-1] * M^(d-1)  + ... + c[1]\
    \ * M + c[0]) * b = 0\ntemplate <class Mat, class Vec>\nclass MinimalPolynomial\
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
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N, K;\n  cin >> N >> K;\n  SparseSquareMatrix<Mint> M(N);\n  for (int i\
    \ = 0; i < K; i++) {\n    int a, b, c;\n    cin >> a >> b >> c;\n    M.add_component(a,\
    \ b, c);\n  }\n  cout << M.det() << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/LinearAlgebra/SparseSquareMatrix.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, K;\n  cin >> N >> K;\n  SparseSquareMatrix<Mint>\
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
  timestamp: '2022-09-19 00:53:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sparse_matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sparse_matrix_det.test.cpp
- /verify/test/yosupo/sparse_matrix_det.test.cpp.html
title: test/yosupo/sparse_matrix_det.test.cpp
---
