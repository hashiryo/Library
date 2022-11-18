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
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n#include <bits/stdc++.h>\n\n#line 3 \"src/LinearAlgebra/LUDecomposition.hpp\"\
    \n/**\n * @title LU\u5206\u89E3\n * @category \u7DDA\u5F62\u4EE3\u6570\n * bool\u578B\
    \u306E\u5834\u5408\u306Ekernel\u95A2\u6570 \u672Averify\n */\n\n// BEGIN CUT HERE\n\
    \ntemplate <class K, std::size_t MAX_ROWS = (1 << 12),\n          std::size_t\
    \ MAX_COLS = MAX_ROWS>\nclass LUDecomposition {\n  using Mat = std::vector<std::vector<K>>;\n\
    \  Mat dat;\n  std::vector<std::size_t> perm, piv;\n  bool sgn;\n  static bool\
    \ is_zero(K x) {\n    if constexpr (std::is_floating_point_v<K>)\n      return\
    \ std::abs(x) < 1e-8;\n    else\n      return x == K(0);\n  }\n\n public:\n  LUDecomposition(const\
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
    \ inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\
    \n/**\n * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category\
    \ \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN\
    \ CUT HERE\nnamespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64\
    \ mod, iv, r2;\n  constexpr u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return\
    \ e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const\
    \ u128 &w) const {\n    return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod)\
    \ >> 64);\n  }\n\n public:\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0)\
    \ {}\n  constexpr MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod)\
    \ {}\n  constexpr inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) *\
    \ r); }\n#define BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n\
    \  constexpr inline u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n\
    \  constexpr inline u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n\
    \  constexpr inline u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline\
    \ u64 get(u64 n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n -\
    \ (mod & -(n >= mod)); }\n  constexpr u64 modulo() const { return mod; }\n};\n\
    template <class Uint>\nclass MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\n  Uint mod;\n\n public:\n  constexpr MIntPro_Na() : mod(0){};\n\
    \  constexpr MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint\
    \ l, Uint r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l\
    \ m## = mod & -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint\
    \ r) const { BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const\
    \ { BOP(+, -); }\n#undef BOP\n  constexpr inline Uint set(Uint n) const { return\
    \ n % mod; }\n  static constexpr inline Uint get(Uint n) { return n; }\n  static\
    \ constexpr inline Uint norm(Uint n) { return n; }\n  constexpr Uint modulo()\
    \ const { return mod; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class Uint, class B>\nstruct ModInt : public B\
    \ {\n  static constexpr inline auto modulo() { return B::md.modulo(); }\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x) {}\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt(T\
    \ v) : ModInt(v.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt(T n)\n      : x(B::md.set(n\
    \ < 0 ? modulo() - ((-n) % modulo()) : n)) {}\n  constexpr ModInt operator-()\
    \ const { return ModInt() - *this; }\n#define FUNC(name, op)          \\\n  constexpr\
    \ ModInt name const { \\\n    ModInt ret;                 \\\n    return ret.x\
    \ = op, ret;     \\\n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n\
    \  FUNC(operator-(const ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k,\
    \ B::md))\n#undef FUNC\n  constexpr ModInt operator/(const ModInt &r) const {\
    \ return *this * r.inv(); }\n  constexpr ModInt &operator+=(const ModInt &r) {\
    \ return *this = *this + r; }\n  constexpr ModInt &operator-=(const ModInt &r)\
    \ { return *this = *this - r; }\n  constexpr ModInt &operator*=(const ModInt &r)\
    \ { return *this = *this * r; }\n  constexpr ModInt &operator/=(const ModInt &r)\
    \ { return *this = *this / r; }\n  constexpr bool operator==(const ModInt &r)\
    \ const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr bool\
    \ operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), modulo());\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 6 \"test/yosupo/matrix_det.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using\
    \ Mint = StaticModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ A(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> A[i][j];\n  cout << LUDecomposition(A).det() << endl;\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"src/LinearAlgebra/LUDecomposition.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n  int N;\n\
    \  cin >> N;\n  vector<vector<Mint>> A(N, vector<Mint>(N));\n  for (int i = 0;\
    \ i < N; i++)\n    for (int j = 0; j < N; j++) cin >> A[i][j];\n  cout << LUDecomposition(A).det()\
    \ << endl;\n  return 0;\n}"
  dependsOn:
  - src/LinearAlgebra/LUDecomposition.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2022-11-18 19:29:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
