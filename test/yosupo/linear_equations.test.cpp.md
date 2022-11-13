---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/LinearAlgebra/LUDecomposition.hpp
    title: "LU\u5206\u89E3"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"test/yosupo/linear_equations.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"src/LinearAlgebra/LUDecomposition.hpp\"\n/**\n * @title LU\u5206\u89E3\
    \n * @category \u7DDA\u5F62\u4EE3\u6570\n * bool\u578B\u306E\u5834\u5408\u306E\
    kernel\u95A2\u6570 \u672Averify\n */\n\n// BEGIN CUT HERE\n\ntemplate <class K,\
    \ std::size_t MAX_ROWS = (1 << 12),\n          std::size_t MAX_COLS = MAX_ROWS>\n\
    class LUDecomposition {\n  using Mat = std::vector<std::vector<K>>;\n  Mat dat;\n\
    \  std::vector<std::size_t> perm, piv;\n  bool sgn;\n  static bool is_zero(K x)\
    \ {\n    if constexpr (std::is_floating_point_v<K>)\n      return std::abs(x)\
    \ < 1e-8;\n    else\n      return x == K(0);\n  }\n\n public:\n  LUDecomposition(const\
    \ Mat &A) : dat(A), perm(A.size()), sgn(false) {\n    std::size_t rows = A.size(),\
    \ cols = A[0].size();\n    std::iota(perm.begin(), perm.end(), 0);\n    for (std::size_t\
    \ c = 0; c != cols && piv.size() != rows; c++) {\n      auto pos = piv.size();\n\
    \      if constexpr (std::is_floating_point_v<K>) {\n        for (std::size_t\
    \ r = piv.size() + 1; r < rows; r++)\n          if (std::abs(dat[pos][c]) < std::abs(dat[r][c]))\
    \ pos = r;\n      } else if (is_zero(dat[pos][c])) {\n        for (std::size_t\
    \ r = piv.size() + 1; r < rows; r++)\n          if (!is_zero(dat[r][c])) pos =\
    \ r, r = rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n      if (pos\
    \ != piv.size())\n        sgn = !sgn, std::swap(perm[pos], perm[piv.size()]),\n\
    \        std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r = piv.size()\
    \ + 1; r != rows; r++) {\n        auto m = dat[r][c] / dat[piv.size()][c];\n \
    \       dat[r][c] = 0, dat[r][piv.size()] = m;\n        for (std::size_t i = c\
    \ + 1; i != cols; i++)\n          dat[r][i] -= dat[piv.size()][i] * m;\n     \
    \ }\n      piv.emplace_back(c);\n    }\n  }\n  std::size_t rank() const { return\
    \ piv.size(); }\n  bool isregular() const {\n    return rank() == dat.size() &&\
    \ rank() == dat[0].size();\n  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n\
    \    K d = sgn ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d\
    \ *= dat[i][i];\n    return d;\n  }\n  std::vector<std::vector<K>> kernel() const\
    \ {\n    std::size_t cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols\
    \ - rank(), std::vector<K>(cols));\n    for (std::size_t c = 0, i = 0; c != cols;\
    \ c++) {\n      if (i != piv.size() && piv[i] == c) {\n        i++;\n        continue;\n\
    \      }\n      ker[c - i][c] = 1;\n      for (std::size_t r = 0; r != i; r++)\
    \ ker[c - i][r] = -dat[r][c];\n      for (std::size_t j = i; j--;) {\n       \
    \ auto x = ker[c - i][j] / dat[j][piv[j]];\n        ker[c - i][j] = 0, ker[c -\
    \ i][piv[j]] = x;\n        for (std::size_t r = 0; r != j; r++)\n          ker[c\
    \ - i][r] -= dat[r][piv[j]] * x;\n      }\n    }\n    return ker;\n  }\n  std::vector<K>\
    \ linear_equations(const std::vector<K> &b) const {\n    std::size_t rows = dat.size(),\
    \ cols = dat[0].size();\n    assert(rows <= b.size());\n    std::vector<K> y(rows),\
    \ x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n      y[c] += b[perm[c]];\n\
    \      if (c < cols)\n        for (std::size_t r = c + 1; r != rows; r++) y[r]\
    \ -= y[c] * dat[r][c];\n    }\n    for (std::size_t i = rank(); i != rows; i++)\n\
    \      if (!is_zero(y[i])) return {};  // no solution\n    for (std::size_t i\
    \ = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n      for (std::size_t\
    \ r = 0; r != i; r++) y[r] -= x[piv[i]] * dat[r][piv[i]];\n    }\n    return x;\n\
    \  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  // no\
    \ solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K> b(dat.size());\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++] = 0)\n     \
    \ b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0;\
    \ i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <std::size_t MAX_ROWS, std::size_t\
    \ MAX_COLS>\nclass LUDecomposition<bool, MAX_ROWS, MAX_COLS> {\n public:\n  using\
    \ Mat = std::vector<std::vector<bool>>;\n  std::size_t rows, cols;\n  std::vector<std::bitset<MAX_ROWS>>\
    \ tdat, tdat2;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()), cols(A[0].size()), tdat(cols), tdat2(cols),\
    \ perm(rows) {\n    std::vector<std::bitset<MAX_COLS>> dat(rows);\n    for (std::size_t\
    \ i = 0; i < rows; i++)\n      for (std::size_t j = 0; j < cols; j++) dat[i][j]\
    \ = A[i][j];\n    std::iota(perm.begin(), perm.end(), 0);\n    std::bitset<MAX_COLS>\
    \ mask;\n    for (std::size_t c = 1; c < cols; c++) mask.set(c);\n    for (std::size_t\
    \ c = 0; c < cols && piv.size() < rows; c++) {\n      mask.reset(c);\n      auto\
    \ pos = piv.size();\n      for (std::size_t r = piv.size(); r < rows; r++)\n \
    \       if (bool(dat[r][c])) pos = r, r = rows;\n      if (!bool(dat[pos][c]))\
    \ continue;\n      if (pos != piv.size())\n        std::swap(perm[pos], perm[piv.size()]),\n\
    \            std::swap(dat[pos], dat[piv.size()]);\n      for (std::size_t r =\
    \ piv.size() + 1; r != rows; r++) {\n        auto m = bool(dat[r][c]);\n     \
    \   dat[r][c] = 0, dat[r][piv.size()] = m;\n        if (m) dat[r] ^= dat[piv.size()]\
    \ & mask;\n      }\n      piv.push_back(c);\n    }\n    for (std::size_t j = 0;\
    \ j < cols; j++)\n      for (std::size_t i = j + 1; i < rows; i++) tdat[j][i]\
    \ = dat[i][j];\n    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      for\
    \ (std::size_t r = 0; r < i; r++) tdat2[c][r] = dat[r][c];\n      if (i != piv.size()\
    \ && piv[i] == c) i++;\n    }\n  }\n  std::size_t rank() const { return piv.size();\
    \ }\n  bool isregular() const { return rank() == rows && rank() == cols; }\n \
    \ bool det() const { return isregular(); }\n  std::vector<std::vector<bool>> kernel()\
    \ const {\n    std::vector<std::bitset<MAX_COLS>> ker(cols - rank());\n    for\
    \ (std::size_t c = 0, i = 0; c != cols; c++) {\n      if (i != piv.size() && piv[i]\
    \ == c) {\n        i++;\n        continue;\n      }\n      ker[c - i] = tdat2[c],\
    \ ker[c - i][c] = 1;\n      for (std::size_t j = i; j--;) {\n        auto x =\
    \ bool(ker[c - i][j]);\n        ker[c - i][j] = 0, ker[c - i][piv[j]] = x;\n \
    \       if (x) ker[c - i] ^= tdat2[piv[j]];\n      }\n    }\n    std::vector<std::vector<bool>>\
    \ ret(cols - rank(), std::vector<bool>(cols));\n    for (std::size_t i = cols\
    \ - rank(); i--;)\n      for (std::size_t j = 0; j < cols; j++) ret[i][j] = ker[i][j];\n\
    \    return ret;\n  }\n  std::vector<bool> linear_equations(const std::vector<bool>\
    \ &b) const {\n    assert(rows <= b.size());\n    std::bitset<MAX_COLS> y;\n \
    \   std::vector<bool> x(cols);\n    for (std::size_t c = 0; c != rows; c++) {\n\
    \      if (b[perm[c]]) y[c].flip();\n      if (c < cols && bool(y[c])) y ^= tdat[c];\n\
    \    }\n    for (std::size_t i = rank(); i != rows; i++)\n      if (bool(y[i]))\
    \ return {};  // no solution\n    for (std::size_t i = rank(); i--;)\n      if\
    \ (x[piv[i]] = y[i]; x[piv[i]]) y ^= tdat2[piv[i]];\n    return x;\n  }\n  Mat\
    \ inverse_matrix() const {\n    if (!isregular()) return {};  // no solution\n\
    \    std::vector<bool> b(rows);\n    Mat ret;\n    for (std::size_t i = 0; i <\
    \ rows; b[i++] = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n\
    \    for (std::size_t i = 0; i < rows; i++)\n      for (std::size_t j = 0; j <\
    \ i; j++) std::swap(ret[i][j], ret[j][i]);\n    return ret;\n  }\n};\n#line 3\
    \ \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n  Int x = 1, y = 0, b = mod;\n  for (Int\
    \ q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y = z - y * (q = a / b),\
    \ a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x) % mod : x\
    \ % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category\
    \ \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace\
    \ std;\nstruct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct\
    \ run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v\
    \ = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\nconstexpr bool\
    \ is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base, mod_t>;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\nstruct ModIntImpl\
    \ {\n  static constexpr inline auto modulo() { return D::mod; }\n  constexpr D\
    \ operator-() const { return D() -= (D &)*this; }\n  constexpr D &operator/=(const\
    \ D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const D &r)\
    \ const { return D((D &)*this) += r; }\n  constexpr D operator-(const D &r) const\
    \ { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r) const {\
    \ return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const { return\
    \ D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const { return\
    \ !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D ret(1),\
    \ b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>= 1)) return\
    \ ret;\n  }\n  constexpr D inv() const {\n    return mod_inv<typename D::Int>(((D\
    \ *)this)->val(), D::mod);\n  }\n  constexpr D sqrt() const {\n    if (((D *)this)->val()\
    \ <= 1 || D::mod == 2) return *(D *)this;\n    u64 e = (D::mod - 1) >> 1;\n  \
    \  D b = 0, d = -(*this), ret = 1, r2 = 0, b2 = 1;\n    if (this->pow(e) != 1)\
    \ return 0;  // no solution\n    while (d.pow(e) == 1) d += b * 2 + 1, b += 1;\n\
    \    auto mult = [d](D &u1, D &u2, D v1, D v2) {\n      D tmp = u1 * v1 + u2 *\
    \ v2 * d;\n      u2 = u1 * v2 + u2 * v1, u1 = tmp;\n    };\n    for (++e;; mult(b,\
    \ b2, b, b2)) {\n      if (e & 1) mult(ret, r2, b, b2);\n      if (!(e >>= 1))\
    \ return ret.val() <= D::mod / 2 ? ret : -ret;\n    }\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n  constexpr auto norm() const { return x; }\n\
    \n private:\n  typename B::Uint x = 0;\n};\ntemplate <class B>\nstruct ModInt_Mon\
    \ : public B, public ModIntImpl<ModInt_Mon<B>> {\n  using Int = int64_t;\n  using\
    \ mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n  constexpr ModInt_Mon()\
    \ = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n  template <class T,\n\
    \            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod - ((-n) % B::mod) :\
    \ n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op## = a, x += (B::mod\
    \ << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const mod_t &r) { ASGN(+,\
    \ r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const mod_t &r) { ASGN(-,\
    \ r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const mod_t &r) { return\
    \ x = mul(x, r.x), *this; }\n  constexpr bool operator==(const mod_t &r) const\
    \ { return norm() == r.norm(); }\n  constexpr u64 val() const {\n    u64 ret =\
    \ reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n  }\n  constexpr\
    \ inline u64 norm() const { return x - (B::mod & -(x >= B::mod)); }\n\n private:\n\
    \  static constexpr inline u64 reduce(const u128 &w) {\n    return u64(w >> 64)\
    \ + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n  static constexpr\
    \ inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r); }\n  u64 x = 0;\n\
    };\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n  return e ? mul_inv(n,\
    \ e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na : sta_mint_base\
    \ {\n protected:\n  using Int = conditional_t < MOD < INT_MAX, int32_t,\n    \
    \    conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n  using Uint = conditional_t\
    \ < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX, u64, u128>>;\n\
    \  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct StaticB_Mon\
    \ : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static constexpr\
    \ u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate <class\
    \ I, int id = -1>\nstruct RuntimeB_Na : run_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct RuntimeB_Mon : run_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<RuntimeB_Mon<id>>,\n\
    \                  ModInt_Na<RuntimeB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::RuntimeModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_runtimemodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 6 \"test/yosupo/linear_equations.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  int N, M;\n  cin >> N >> M;\n  vector<vector<Mint>>\
    \ A(N, vector<Mint>(M));\n  vector<Mint> b(N);\n  for (int i = 0; i < N; i++)\n\
    \    for (int j = 0; j < M; j++) cin >> A[i][j];\n  for (int i = 0; i < N; i++)\
    \ cin >> b[i];\n  LUDecomposition lu(A);\n  auto res = lu.linear_equations(b);\n\
    \  if (res.empty()) {\n    cout << \"-1\" << '\\n';\n    return 0;\n  }\n  auto\
    \ ker = lu.kernel();\n  std::cout << ker.size() << \"\\n\";\n  for (int j = 0;\
    \ j < M; j++) {\n    cout << (j ? \" \" : \"\") << res[j];\n  }\n  cout << '\\\
    n';\n  for (int i = 0; i < ker.size(); i++) {\n    for (int j = 0; j < M; j++)\
    \ {\n      cout << (j ? \" \" : \"\") << ker[i][j];\n    }\n    cout << '\\n';\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/LinearAlgebra/LUDecomposition.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N, M;\n  cin >> N >> M;\n  vector<vector<Mint>> A(N, vector<Mint>(M));\n\
    \  vector<Mint> b(N);\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j <\
    \ M; j++) cin >> A[i][j];\n  for (int i = 0; i < N; i++) cin >> b[i];\n  LUDecomposition\
    \ lu(A);\n  auto res = lu.linear_equations(b);\n  if (res.empty()) {\n    cout\
    \ << \"-1\" << '\\n';\n    return 0;\n  }\n  auto ker = lu.kernel();\n  std::cout\
    \ << ker.size() << \"\\n\";\n  for (int j = 0; j < M; j++) {\n    cout << (j ?\
    \ \" \" : \"\") << res[j];\n  }\n  cout << '\\n';\n  for (int i = 0; i < ker.size();\
    \ i++) {\n    for (int j = 0; j < M; j++) {\n      cout << (j ? \" \" : \"\")\
    \ << ker[i][j];\n    }\n    cout << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/LinearAlgebra/LUDecomposition.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: true
  path: test/yosupo/linear_equations.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 01:24:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/linear_equations.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/linear_equations.test.cpp
- /verify/test/yosupo/linear_equations.test.cpp.html
title: test/yosupo/linear_equations.test.cpp
---
