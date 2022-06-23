---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/LinearAlgebra/LUDecomposition.hpp
    title: "LU\u5206\u89E3"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"test/yosupo/inverse_matrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/inverse_matrix\"\n#include <bits/stdc++.h>\n\n\
    #line 3 \"src/LinearAlgebra/LUDecomposition.hpp\"\n/**\n * @title LU\u5206\u89E3\
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
    \      if constexpr (IFPV<K>) {\n        for (std::size_t r = piv.size() + 1;\
    \ r < rows; r++)\n          if (std::abs(dat[pos][c]) < std::abs(dat[r][c])) pos\
    \ = r;\n      } else if (is_zero(dat[pos][c])) {\n        for (std::size_t r =\
    \ piv.size() + 1; r < rows; r++)\n          if (!is_zero(dat[r][c])) pos = r,\
    \ r = rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n      if (pos\
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
    \ return {};  // no solution\n    for (std::size_t i = rank(); i--;) {\n     \
    \ x[piv[i]] = y[i];\n      if (x[piv[i]]) y ^= tdat2[piv[i]];\n    }\n    return\
    \ x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular()) return {};  //\
    \ no solution\n    std::vector<bool> b(rows);\n    Mat ret;\n    for (std::size_t\
    \ i = 0; i < rows; b[i++] = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n\
    \    for (std::size_t i = 0; i < rows; i++)\n      for (std::size_t j = 0; j <\
    \ i; j++) std::swap(ret[i][j], ret[j][i]);\n    return ret;\n  }\n};\n#line 3\
    \ \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t mod,\
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
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 6 \"test/yosupo/inverse_matrix.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ A(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> A[i][j];\n  LUDecomposition lu(A);\n  auto ans = lu.inverse_matrix();\n\
    \  if (ans.empty()) {\n    cout << \"-1\" << '\\n';\n    return 0;\n  }\n  for\
    \ (int i = 0; i < N; i++) {\n    for (int j = 0; j < N; j++) cout << (j ? \" \"\
    \ : \"\") << ans[i][j];\n    cout << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"src/LinearAlgebra/LUDecomposition.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n  int N;\n  cin\
    \ >> N;\n  vector<vector<Mint>> A(N, vector<Mint>(N));\n  for (int i = 0; i <\
    \ N; i++)\n    for (int j = 0; j < N; j++) cin >> A[i][j];\n  LUDecomposition\
    \ lu(A);\n  auto ans = lu.inverse_matrix();\n  if (ans.empty()) {\n    cout <<\
    \ \"-1\" << '\\n';\n    return 0;\n  }\n  for (int i = 0; i < N; i++) {\n    for\
    \ (int j = 0; j < N; j++) cout << (j ? \" \" : \"\") << ans[i][j];\n    cout <<\
    \ '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/LinearAlgebra/LUDecomposition.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2022-06-23 16:17:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/inverse_matrix.test.cpp
- /verify/test/yosupo/inverse_matrix.test.cpp.html
title: test/yosupo/inverse_matrix.test.cpp
---
