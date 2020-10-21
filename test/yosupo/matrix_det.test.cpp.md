---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"src/Math/Matrix.hpp\"\n/**\n * @title \u884C\u5217\n * @category \u6570\
    \u5B66\n *  Gauss_Jordan(A,B) \u62E1\u5927\u4FC2\u6570\u884C\u5217\u306B\u5BFE\
    \u3059\u308B\u30AC\u30A6\u30B9\u30B8\u30E7\u30EB\u30C0\u30F3\u6CD5\n *  linear_equations(A,b)\
    \ \u8FD4\u308A\u5024 {\u89E3\u306E\u3046\u3061\u306E\u4E00\u3064,\u89E3\u7A7A\u9593\
    \u306E\u57FA\u5E95\u30D9\u30AF\u30C8\u30EB}\n */\n\n#ifndef call_from_test\n#line\
    \ 10 \"src/Math/Matrix.hpp\"\nusing namespace std;\n#endif\n\ntemplate <typename\
    \ K>\nstruct Matrix {\n private:\n  vector<vector<K>> a;\n\n public:\n  Matrix()\
    \ {}\n  Matrix(size_t n, size_t m) : a(n, vector<K>(m, 0)) {}\n  Matrix(size_t\
    \ n) : Matrix(n, n) {}\n  Matrix(vector<vector<K>> a) : a(a) {}\n  size_t height()\
    \ const { return a.size(); }\n  size_t width() const { return a[0].size(); }\n\
    \  inline const vector<K> &operator[](size_t k) const { return a[k]; }\n  inline\
    \ vector<K> &operator[](size_t k) { return a[k]; }\n  static Matrix diag(vector<K>\
    \ v) {\n    Matrix mat(v.size());\n    for (size_t i = 0; i < v.size(); i++) mat[i][i]\
    \ = v[i];\n    return mat;\n  }\n  static Matrix I(size_t n, K e = {1}) { return\
    \ diag(vector<K>(n, e)); }\n  Matrix &operator+=(const Matrix &b) {\n    size_t\
    \ n = height(), m = width();\n    for (size_t i = 0; i < n; i++)\n      for (size_t\
    \ j = 0; j < m; j++) (*this)[i][j] += b[i][j];\n    return (*this);\n  }\n  Matrix\
    \ &operator-=(const Matrix &b) {\n    size_t n = height(), m = width();\n    for\
    \ (size_t i = 0; i < n; i++)\n      for (size_t j = 0; j < m; j++) (*this)[i][j]\
    \ -= b[i][j];\n    return (*this);\n  }\n  Matrix &operator*=(const Matrix &b)\
    \ {\n    size_t n = height(), m = width(), l = b.width();\n    assert(m == b.height());\n\
    \    vector<vector<K>> c(n, vector<K>(l, 0));\n    for (size_t i = 0; i < n; i++)\n\
    \      for (size_t j = 0; j < l; j++)\n        for (size_t k = 0; k < m; k++)\
    \ c[i][j] += (*this)[i][k] * b[k][j];\n    a.swap(c);\n    return (*this);\n \
    \ }\n  Matrix operator+(const Matrix &b) const { return (Matrix(*this) += b);\
    \ }\n  Matrix operator-(const Matrix &b) const { return (Matrix(*this) -= b);\
    \ }\n  Matrix operator*(const Matrix &b) const { return (Matrix(*this) *= b);\
    \ }\n  Matrix pow(uint64_t n, K e = {1}) {\n    Matrix ret = I(height(), e);\n\
    \    for (Matrix base = *this; n; n >>= 1, base *= base)\n      if (n & 1) ret\
    \ *= base;\n    return ret;\n  }\n  vector<K> operator*(const vector<K> &v) {\n\
    \    size_t n = height(), m = width();\n    assert(m == v.size());\n    vector<K>\
    \ ret(n);\n    for (size_t i = 0; i < n; i++)\n      for (size_t j = 0; j < m;\
    \ j++) ret[i] += (*this)[i][j] * v[j];\n    return ret;\n  }\n  bool operator==(const\
    \ Matrix &b) const { return a == b.a; }\n  template <typename T>\n  using ET =\
    \ enable_if<is_floating_point<T>::value>;\n  template <typename T>\n  using EF\
    \ = enable_if<!is_floating_point<T>::value>;\n  template <typename T, typename\
    \ ET<T>::type * = nullptr>\n  static bool is_zero(T x) {\n    return abs(x) <\
    \ 1e-8;\n  }\n  template <typename T, typename EF<T>::type * = nullptr>\n  static\
    \ bool is_zero(T x) {\n    return x == T(0);\n  }\n  template <typename T, typename\
    \ ET<T>::type * = nullptr>\n  static bool compare(T x, T y) {\n    return abs(x)\
    \ < abs(y);\n  }\n  template <typename T, typename EF<T>::type * = nullptr>\n\
    \  static bool compare(T x, T y) {\n    (void)x;\n    return y != T(0);\n  }\n\
    \  // O(nm(m+l))\n  static pair<Matrix, Matrix> Gauss_Jordan(const Matrix &a,\
    \ const Matrix &b) {\n    size_t n = a.height(), m = a.width(), l = b.width();\n\
    \    Matrix c(n, m + l);\n    for (size_t i = 0; i < n; i++)\n      for (size_t\
    \ j = 0; j < m; j++) c[i][j] = a[i][j];\n    for (size_t i = 0; i < n; i++)\n\
    \      for (size_t j = 0; j < l; j++) c[i][j + m] = b[i][j];\n    for (size_t\
    \ j = 0, d = 0; j < m && d < n; j++) {\n      int p = d;\n      for (size_t i\
    \ = d + 1; i < n; i++)\n        if (compare(c[p][j], c[i][j])) p = i;\n      if\
    \ (is_zero(c[p][j])) continue;\n      swap(c[p], c[d]);\n      K invc = K(1) /\
    \ c[d][j];\n      for (size_t k = j; k < m + l; k++) c[d][k] *= invc;\n      for\
    \ (size_t i = 0; i < n; i++) {\n        if (i == d) continue;\n        for (int\
    \ k = m + l - 1; k >= (int)j; k--) c[i][k] -= c[i][j] * c[d][k];\n      }\n  \
    \    d++;\n    }\n    Matrix reta(n, m), retb(n, l);\n    for (size_t i = 0; i\
    \ < n; i++)\n      for (size_t j = 0; j < m; j++) reta[i][j] = c[i][j];\n    for\
    \ (size_t i = 0; i < n; i++)\n      for (size_t j = 0; j < l; j++) retb[i][j]\
    \ = c[i][j + m];\n    return make_pair(reta, retb);\n  }\n  // O(nm^2)\n  static\
    \ pair<vector<K>, vector<vector<K>>> linear_equations(\n      const Matrix &a,\
    \ const vector<K> &b) {\n    size_t n = a.height(), m = a.width();\n    Matrix\
    \ B(n, 1);\n    for (size_t i = 0; i < n; i++) B[i][0] = b[i];\n    auto p = Gauss_Jordan(a,\
    \ B);\n    vector<int> jdx(n, -1), idx(m, -1);\n    for (size_t i = 0, j; i <\
    \ n; i++) {\n      for (j = 0; j < m; j++)\n        if (!is_zero(p.first[i][j]))\
    \ {\n          jdx[i] = j, idx[j] = i;\n          break;\n        }\n      if\
    \ (j == m && !is_zero(p.second[i][0]))\n        return make_pair(vector<K>(),\
    \ vector<vector<K>>());  // no solutions\n    }\n    vector<K> c(m);\n    vector<vector<K>>\
    \ d;\n    for (size_t j = 0; j < m; j++) {\n      if (idx[j] != -1)\n        c[j]\
    \ = p.second[idx[j]][0];\n      else {\n        vector<K> v(m);\n        v[j]\
    \ = 1;\n        for (size_t i = 0; i < n; i++)\n          if (jdx[i] != -1) v[jdx[i]]\
    \ = -p.first[i][j];\n        d.push_back(v);\n      }\n    }\n    return make_pair(c,\
    \ d);\n  }\n  // O(n^3)\n  K det() const {\n    int n = height();\n    Matrix\
    \ A(a);\n    K ret(1);\n    for (int i = 0; i < n; i++) {\n      int p = i;\n\
    \      for (int j = i + 1; j < n; j++)\n        if (compare(A[p][i], A[j][i]))\
    \ p = j;\n      if (is_zero(A[p][i])) return 0;\n      if (p != i) ret = -ret;\n\
    \      swap(A[p], A[i]);\n      ret *= A[i][i];\n      K inva = K(1) / A[i][i];\n\
    \      for (int j = i + 1; j < n; j++)\n        for (int k = n - 1; k >= i; k--)\
    \ A[j][k] -= inva * A[j][i] * A[i][k];\n    }\n    return ret;\n  }\n};\n#line\
    \ 1 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n#ifndef call_from_test\n#line 8 \"src/Math/ModInt.hpp\"\nusing namespace\
    \ std;\n#endif\n\ntemplate <uint64_t mod, uint64_t prim_root = 0>\nclass ModInt\
    \ {\n private:\n  using u128 = __uint128_t;\n  static constexpr uint64_t mul_inv(uint64_t\
    \ n, int e = 6, uint64_t x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x\
    \ * (2 - x * n));\n  }\n  static constexpr uint64_t inv = mul_inv(mod, 6, 1);\n\
    \  static constexpr uint64_t r2 = -u128(mod) % mod;\n  static constexpr uint64_t\
    \ m2 = mod << 1;\n\n public:\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  ModInt() = default;\n  ~ModInt() = default;\n  constexpr ModInt(uint64_t\
    \ n) : x(init(n)){};\n  static constexpr uint64_t modulo() { return mod; }\n \
    \ static constexpr uint64_t init(uint64_t w) { return reduce(u128(w) * r2); }\n\
    \  static constexpr uint64_t reduce(const u128 w) {\n    return uint64_t(w >>\
    \ 64) + mod - ((u128(uint64_t(w) * inv) * mod) >> 64);\n  }\n  static constexpr\
    \ uint64_t norm(uint64_t x) { return x - (mod & -(x >= mod)); }\n  static constexpr\
    \ uint64_t pr_rt() { return prim_root; }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = (m2 & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - m2, x += m2\
    \ & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs)\
    \ {\n    return x -= rhs.x, x += m2 & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) {\n    return this->x = reduce(u128(this->x)\
    \ * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n\
    \    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const ModInt\
    \ &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const ModInt\
    \ &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const ModInt\
    \ &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const ModInt\
    \ &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const ModInt\
    \ &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const ModInt\
    \ &rhs) const { return norm(x) != norm(rhs.x); }\n  uint64_t get() const {\n \
    \   uint64_t ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n\
    \  }\n  constexpr ModInt pow(uint64_t k) const {\n    ModInt ret = ModInt(1);\n\
    \    for (ModInt base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret\
    \ *= base;\n    return ret;\n  }\n  constexpr ModInt inverse() const { return\
    \ pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0)\
    \ || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);\
    \  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod\
    \ - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](pair<ModInt,\
    \ ModInt> u, pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first +\
    \ u.second * v.second * w);\n      ModInt b = (u.first * v.second + u.second *\
    \ v.first);\n      return make_pair(a, b);\n    };\n    uint64_t e = (mod + 1)\
    \ >> 1;\n    auto ret = make_pair(ONE, ModInt(0));\n    for (auto bs = make_pair(b,\
    \ ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1) ret = mul(ret, bs);\n\
    \    return ret.first.get() * 2 < mod ? ret.first : -ret.first;\n  }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.get();\n  }\n  uint64_t x;\n\
    };\n#line 9 \"test/yosupo/matrix_det.test.cpp\"\n#undef call_from_test\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  Matrix<Mint> A(N);\n  for (int i = 0; i < N; i++)\n\
    \    for (int j = 0; j < N; j++) cin >> A[i][j];\n  cout << A.det() << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/Math/Matrix.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n\
    \  int N;\n  cin >> N;\n  Matrix<Mint> A(N);\n  for (int i = 0; i < N; i++)\n\
    \    for (int j = 0; j < N; j++) cin >> A[i][j];\n  cout << A.det() << endl;\n\
    \  return 0;\n}"
  dependsOn:
  - src/Math/Matrix.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 15:03:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
