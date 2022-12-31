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
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"test/yosupo/linear_equations.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"src/LinearAlgebra/LUDecomposition.hpp\"\n/**\n * @title LU\u5206\u89E3\
    \n * @category \u7DDA\u5F62\u4EE3\u6570\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ K>\nclass LUDecomposition {\n  using Mat = std::vector<std::vector<K>>;\n  Mat\
    \ dat;\n  std::vector<std::size_t> perm, piv;\n  bool sgn;\n  static bool is_zero(K\
    \ x) {\n    if constexpr (std::is_floating_point_v<K>)\n      return std::abs(x)\
    \ < 1e-8;\n    else\n      return x == K(0);\n  }\n\n public:\n  LUDecomposition(const\
    \ Mat &A) : dat(A), perm(A.size()), sgn(false) {\n    std::size_t rows = A.size(),\
    \ cols = A[0].size();\n    std::iota(perm.begin(), perm.end(), 0);\n    for (std::size_t\
    \ c = 0, psz = 0; c != cols && psz != rows; c++) {\n      auto pos = psz;\n  \
    \    if constexpr (std::is_floating_point_v<K>) {\n        for (std::size_t r\
    \ = psz + 1; r < rows; r++)\n          if (std::abs(dat[pos][c]) < std::abs(dat[r][c]))\
    \ pos = r;\n      } else if (is_zero(dat[pos][c])) {\n        for (std::size_t\
    \ r = psz + 1; r < rows; r++)\n          if (!is_zero(dat[r][c])) pos = r, r =\
    \ rows;\n      }\n      if (is_zero(dat[pos][c])) continue;\n      if (pos !=\
    \ psz)\n        sgn = !sgn, std::swap(perm[pos], perm[psz]), dat[pos].swap(dat[psz]);\n\
    \      for (std::size_t r = psz + 1; r < rows; r++) {\n        auto m = dat[r][c]\
    \ / dat[psz][c];\n        dat[r][c] = 0, dat[r][psz] = m;\n        for (std::size_t\
    \ i = c + 1; i < cols; i++) dat[r][i] -= dat[psz][i] * m;\n      }\n      piv.emplace_back(c),\
    \ psz++;\n    }\n  }\n  std::size_t rank() const { return piv.size(); }\n  bool\
    \ isregular() const {\n    return rank() == dat.size() && rank() == dat[0].size();\n\
    \  }\n  K det() const {\n    assert(dat.size() == dat[0].size());\n    K d = sgn\
    \ ? -1 : 1;\n    for (std::size_t i = 0; i != dat.size(); i++) d *= dat[i][i];\n\
    \    return d;\n  }\n  std::vector<std::vector<K>> kernel() const {\n    std::size_t\
    \ cols = dat[0].size();\n    std::vector<std::vector<K>> ker(cols - rank(), std::vector<K>(cols));\n\
    \    for (std::size_t c = 0, i = 0; c < cols; c++) {\n      if (i < piv.size()\
    \ && piv[i] == c) {\n        i++;\n        continue;\n      }\n      ker[c - i][c]\
    \ = 1;\n      for (std::size_t r = i; r--;) ker[c - i][r] = -dat[r][c];\n    \
    \  for (std::size_t j = i, k; j--;) {\n        auto x = ker[c - i][j] / dat[j][k\
    \ = piv[j]];\n        ker[c - i][j] = 0, ker[c - i][k] = x;\n        for (std::size_t\
    \ r = j; r--;) ker[c - i][r] -= dat[r][k] * x;\n      }\n    }\n    return ker;\n\
    \  }\n  std::vector<K> linear_equations(const std::vector<K> &b) const {\n   \
    \ std::size_t rows = dat.size(), cols = dat[0].size();\n    assert(rows <= b.size());\n\
    \    std::vector<K> y(rows), x(cols);\n    for (std::size_t c = 0; c < rows; c++)\n\
    \      if (y[c] += b[perm[c]]; c < cols)\n        for (std::size_t r = c + 1;\
    \ r < rows; r++) y[r] -= y[c] * dat[r][c];\n    for (std::size_t i = rank(); i\
    \ < rows; i++)\n      if (!is_zero(y[i])) return {};  // no solution\n    for\
    \ (std::size_t i = rank(); i--;) {\n      x[piv[i]] = y[i] / dat[i][piv[i]];\n\
    \      for (std::size_t r = i; r--;) y[r] -= x[piv[i]] * dat[r][piv[i]];\n   \
    \ }\n    return x;\n  }\n  Mat inverse_matrix() const {\n    if (!isregular())\
    \ return {};  // no solution\n    assert(dat.size() == dat[0].size());\n    std::vector<K>\
    \ b(dat.size());\n    Mat ret;\n    for (std::size_t i = 0; i < dat.size(); b[i++]\
    \ = 0)\n      b[i] = 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t\
    \ i = 0; i < dat.size(); i++)\n      for (std::size_t j = 0; j < i; j++) std::swap(ret[i][j],\
    \ ret[j][i]);\n    return ret;\n  }\n};\n\ntemplate <>\nclass LUDecomposition<bool>\
    \ {\n public:\n  using Mat = std::vector<std::vector<bool>>;\n  using u128 = __uint128_t;\n\
    \  const std::size_t rows, cols, row128, col128;\n  std::vector<std::vector<u128>>\
    \ tdat;\n  std::vector<std::size_t> perm, piv;\n\n public:\n  LUDecomposition(const\
    \ Mat &A)\n      : rows(A.size()),\n        cols(A[0].size()),\n        row128((rows\
    \ + 127) >> 7),\n        col128((cols + 127) >> 7),\n        tdat(cols, std::vector<u128>(row128)),\n\
    \        perm(rows) {\n    std::vector dat(rows, std::vector<u128>(col128));\n\
    \    for (std::size_t i = rows; i--;)\n      for (std::size_t j = cols; j--;)\n\
    \        dat[i][j >> 7] |= u128(A[i][j]) << (j & 127);\n    std::iota(perm.begin(),\
    \ perm.end(), 0);\n    for (std::size_t c = 0, psz = 0; c < cols && psz < rows;\
    \ c++) {\n      auto pos = psz, a = c >> 7, b = c & 127;\n      for (std::size_t\
    \ r = psz; r < rows; r++)\n        if ((dat[r][a] >> b) & 1) pos = r, r = rows;\n\
    \      if (!((dat[pos][a] >> b) & 1)) continue;\n      if (pos != psz) std::swap(perm[pos],\
    \ perm[psz]), dat[pos].swap(dat[psz]);\n      for (std::size_t r = psz + 1; r\
    \ < rows; r++) {\n        if ((dat[r][a] >> b) & 1) {\n          for (auto i =\
    \ a + 1; i < col128; i++) dat[r][i] ^= dat[psz][i];\n          dat[r][a] ^= dat[psz][a]\
    \ & u128(-(u128(1) << b));\n          dat[r][psz >> 7] |= u128(1) << (psz & 127);\n\
    \        }\n      }\n      piv.push_back(c), psz++;\n    }\n    for (std::size_t\
    \ j = cols; j--;)\n      for (std::size_t i = rows; i--;)\n        tdat[j][i >>\
    \ 7] |= u128((dat[i][j >> 7] >> (j & 127)) & 1) << (i & 127);\n  }\n  std::size_t\
    \ rank() const { return piv.size(); }\n  bool isregular() const { return rank()\
    \ == rows && rank() == cols; }\n  bool det() const { return isregular(); }\n \
    \ std::vector<std::vector<bool>> kernel() const {\n    std::vector ker(cols -\
    \ rank(), std::vector<u128>(col128));\n    for (std::size_t c = 0, i = 0; c <\
    \ cols; c++) {\n      if (i < piv.size() && piv[i] == c) {\n        i++;\n   \
    \     continue;\n      }\n      ker[c - i][c >> 7] |= u128(1) << (c & 127);\n\
    \      for (std::size_t r = i >> 7; r--;) ker[c - i][r] = tdat[c][r];\n      ker[c\
    \ - i][i >> 7] = tdat[c][i >> 7] & ((u128(1) << (i & 127)) - 1);\n      for (std::size_t\
    \ j = i; j--;) {\n        if (std::size_t k = piv[j]; (ker[c - i][j >> 7] >> (j\
    \ & 127)) & 1) {\n          for (std::size_t r = j >> 7; r--;) ker[c - i][r] ^=\
    \ tdat[k][r];\n          ker[c - i][j >> 7] ^= tdat[k][j >> 7] & ((u128(1) <<\
    \ (j & 127)) - 1);\n          ker[c - i][k >> 7] |= u128(1) << (k & 127);\n  \
    \      }\n      }\n    }\n    std::vector ret(cols - rank(), std::vector<bool>(cols));\n\
    \    for (std::size_t i = cols - rank(); i--;)\n      for (std::size_t j = cols;\
    \ j--;) ret[i][j] = ker[i][j >> 7] << (j & 127);\n    return ret;\n  }\n  std::vector<bool>\
    \ linear_equations(const std::vector<bool> &b) const {\n    assert(rows <= b.size());\n\
    \    std::vector<u128> y(row128);\n    std::vector<bool> x(cols);\n    for (std::size_t\
    \ c = 0; c < rows; c++) {\n      y[c >> 7] ^= u128(b[perm[c]]) << (c & 127);\n\
    \      if ((c < cols) & (y[c >> 7] >> (c & 127)))\n        if (std::size_t a =\
    \ (c + 1) >> 7; a < row128) {\n          for (std::size_t r = a + 1; r < row128;\
    \ r++) y[r] ^= tdat[c][r];\n          y[a] ^= tdat[c][a] & u128(-(u128(1) << ((c\
    \ + 1) & 127)));\n        }\n    }\n    if ((rank() >> 7) < row128 && (y[rank()\
    \ >> 7] >> (rank() & 127)))\n      return {};  // no solution\n    for (std::size_t\
    \ r = (rank() >> 7) + 1; r < row128; r++)\n      if (y[r]) return {};  // no solution\n\
    \    for (std::size_t i = rank(); i--;)\n      if (std::size_t k = piv[i]; (x[k]\
    \ = (y[i >> 7] >> (i & 127)) & 1)) {\n        for (std::size_t r = i >> 7; r--;)\
    \ y[r] ^= tdat[k][r];\n        y[i >> 7] ^= tdat[k][i >> 7] & ((u128(1) << (i\
    \ & 127)) - 1);\n      }\n    return x;\n  }\n  Mat inverse_matrix() const {\n\
    \    if (!isregular()) return {};  // no solution\n    std::vector<bool> b(rows);\n\
    \    Mat ret;\n    for (std::size_t i = 0; i < rows; b[i++] = 0)\n      b[i] =\
    \ 1, ret.emplace_back(linear_equations(b));\n    for (std::size_t i = 0; i < rows;\
    \ i++)\n      for (std::size_t j = 0; j < i; j++) {\n        bool tmp = ret[i][j];\n\
    \        ret[i][j] = ret[j][i];\n        ret[j][i] = tmp;\n      }\n    return\
    \ ret;\n  }\n};\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 6 \"test/yosupo/linear_equations.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n\
    \  int N, M;\n  cin >> N >> M;\n  vector<vector<Mint>> A(N, vector<Mint>(M));\n\
    \  vector<Mint> b(N);\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j <\
    \ M; j++) cin >> A[i][j];\n  for (int i = 0; i < N; i++) cin >> b[i];\n  LUDecomposition\
    \ lu(A);\n  auto res = lu.linear_equations(b);\n  if (res.empty()) {\n    cout\
    \ << \"-1\" << '\\n';\n    return 0;\n  }\n  auto ker = lu.kernel();\n  std::cout\
    \ << ker.size() << \"\\n\";\n  for (int j = 0; j < M; j++) {\n    cout << (j ?\
    \ \" \" : \"\") << res[j];\n  }\n  cout << '\\n';\n  for (int i = 0; i < ker.size();\
    \ i++) {\n    for (int j = 0; j < M; j++) {\n      cout << (j ? \" \" : \"\")\
    \ << ker[i][j];\n    }\n    cout << '\\n';\n  }\n  return 0;\n}\n"
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
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/linear_equations.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 18:14:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/linear_equations.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/linear_equations.test.cpp
- /verify/test/yosupo/linear_equations.test.cpp.html
title: test/yosupo/linear_equations.test.cpp
---
