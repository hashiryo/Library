---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/LinearAlgebra/LU_Decomposition.hpp
    title: "LU\u5206\u89E3"
  - icon: ':question:'
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n#include <iostream>\n#line 2 \"src/LinearAlgebra/LU_Decomposition.hpp\"\n#include\
    \ <type_traits>\n#include <numeric>\n#include <vector>\n#line 2 \"src/LinearAlgebra/Matrix.hpp\"\
    \n#include <cassert>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <valarray>\n\
    namespace la_internal {\nusing namespace std;\ntemplate <class R> struct Vector:\
    \ public valarray<R> {\n using valarray<R>::valarray;\n};\nusing u128= __uint128_t;\n\
    using u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128\
    \ *r, u8 j, bool v): ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >>\
    \ i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const Ref &r) { return val=\
    \ r.val, *this; }\n Ref &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool\
    \ b) { return val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this;\
    \ }\n Ref &operator^=(bool b) { return val^= b, *this; }\n operator bool() const\
    \ { return val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n valarray<u128>\
    \ dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >>\
    \ 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref\
    \ operator[](int i) {\n  u128 *ref= begin(dat) + (i >> 7);\n  u8 j= i & 127;\n\
    \  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int\
    \ i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const\
    \ Vector &r) { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector\
    \ &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b)\
    \ dat= 0;\n  return *this;\n }\n Vector operator+(const Vector &r) const { return\
    \ Vector(*this)+= r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-=\
    \ r; }\n Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t\
    \ size() const { return n; }\n u128 *data() { return begin(dat); }\n friend Vector\
    \ operator*(bool b, const Vector &r) { return r * b; }\n};\n}\nusing la_internal::Vector;\n\
    #line 5 \"src/LinearAlgebra/Matrix.hpp\"\nnamespace la_internal {\ntemplate <class\
    \ R> class Matrix {\npublic:\n size_t W;\n valarray<R> dat;\npublic:\n static\
    \ Matrix identity_matrix(int n) {\n  Matrix ret(n, n);\n  return ret.dat[slice(0,\
    \ n, n + 1)]= R(true), ret;\n }\n Matrix(): W(0) {}\n Matrix(size_t h, size_t\
    \ w, R v= R()): W(w), dat(v, h * w) {}\n size_t width() const { return W; }\n\
    \ size_t height() const { return W ? dat.size() / W : 0; }\n explicit operator\
    \ bool() const { return W; }\n auto operator[](int i) { return next(begin(dat),\
    \ i * W); }\n auto operator[](int i) const { return next(begin(dat), i * W); }\n\
    \ Matrix submatrix(const vector<int> &rows, const vector<int> &cols) const {\n\
    \  Matrix ret(rows.size(), cols.size());\n  for (int i= rows.size(); i--;)\n \
    \  for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n  return\
    \ ret;\n }\n bool operator==(const Matrix &r) const {\n  if (W != r.W || dat.size()\
    \ != r.dat.size()) return false;\n  for (int i= dat.size(); i--;)\n   if (dat[i]\
    \ != r.dat[i]) return false;\n  return true;\n }\n bool operator!=(const Matrix\
    \ &r) const { return !(*this == r); }\n Matrix &operator+=(const Matrix &r) {\
    \ return assert(dat.size() == r.dat.size()), assert(W == r.W), dat+= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  const size_t h= height(), w= r.W,\
    \ l= W;\n  assert(l == r.height());\n  Matrix ret(h, w);\n  auto a= begin(dat);\n\
    \  auto c= begin(ret.dat);\n  for (int i= h; i--; advance(c, w)) {\n   auto b=\
    \ begin(r.dat);\n   for (int k= l; k--; ++a) {\n    auto d= c;\n    auto v= *a;\n\
    \    for (int j= w; j--; ++b, ++d) *d+= v * *b;\n   }\n  }\n  return ret;\n }\n\
    \ Matrix &operator*=(const Matrix &r) { return *this= *this * r; }\n Matrix &operator*=(R\
    \ r) { return dat*= r, *this; }\n Matrix operator*(R r) const { return Matrix(*this)*=\
    \ r; }\n Vector<R> operator*(const Vector<R> &r) const {\n  assert(W == r.size());\n\
    \  const size_t h= height();\n  Vector<R> ret(h);\n  auto a= begin(dat);\n  for\
    \ (int i= 0; i < h; ++i)\n   for (int k= 0; k < W; ++k, ++a) ret[i]+= *a * r[k];\n\
    \  return ret;\n }\n Vector<R> operator()(const Vector<R> &r) const { return *this\
    \ * r; }\n Matrix pow(uint64_t k) const {\n  assert(W * W == dat.size());\n  for\
    \ (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ? ret*= b, !(k>>=\
    \ 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <> class Matrix<bool> {\n size_t\
    \ H, W, m;\n valarray<u128> dat;\n class Array {\n  u128 *bg;\n public:\n  Array(u128\
    \ *it): bg(it) {}\n  u128 *data() const { return bg; }\n  Ref operator[](int i)\
    \ {\n   u128 *ref= bg + (i >> 7);\n   u8 j= i & 127;\n   bool val= (*ref >> j)\
    \ & 1;\n   return Ref{ref, j, val};\n  }\n  bool operator[](int i) const { return\
    \ (bg[i >> 7] >> (i & 127)) & 1; }\n };\n class ConstArray {\n  const u128 *bg;\n\
    \ public:\n  ConstArray(const u128 *it): bg(it) {}\n  const u128 *data() const\
    \ { return bg; }\n  bool operator[](int i) const { return (bg[i >> 7] >> (i &\
    \ 127)) & 1; }\n };\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix\
    \ ret(n, n);\n  for (; n--;) ret[n][n]= 1;\n  return ret;\n }\n Matrix(): H(0),\
    \ W(0), m(0) {}\n Matrix(size_t h, size_t w): H(h), W(w), m((w + 127) >> 7), dat(u128(0),\
    \ h * m) {}\n size_t width() const { return W; }\n size_t height() const { return\
    \ H; }\n explicit operator bool() const { return W; }\n Array operator[](int i)\
    \ { return {next(begin(dat), i * m)}; }\n ConstArray operator[](int i) const {\
    \ return {next(begin(dat), i * m)}; }\n ConstArray get(int i) const { return {next(begin(dat),\
    \ i * m)}; }\n Matrix submatrix(const std::vector<int> &rows, const std::vector<int>\
    \ &cols) const {\n  Matrix ret(rows.size(), cols.size());\n  for (int i= rows.size();\
    \ i--;)\n   for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n\
    \  return ret;\n }\n bool operator==(const Matrix &r) const { return W == r.W\
    \ && H == r.H && (dat == r.dat).min(); }\n bool operator!=(const Matrix &r) const\
    \ { return W != r.W || H != r.H || (dat != r.dat).max(); }\n Matrix &operator+=(const\
    \ Matrix &r) { return assert(H == r.H), assert(W == r.W), dat^= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  assert(W == r.H);\n  Matrix ret(H,\
    \ r.W);\n  u128 *c= begin(ret.dat);\n  for (size_t i= 0; i < H; ++i, advance(c,\
    \ m)) {\n   ConstArray a= this->operator[](i);\n   const u128 *b= begin(r.dat);\n\
    \   for (size_t k= 0; k < W; ++k, advance(b, r.m))\n    if (a[k])\n     for (size_t\
    \ j= 0; j < r.m; ++j) c[j]^= b[j];\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Vector<bool> operator*(const Vector<bool>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<bool> ret(H);\n  auto a= begin(dat);\n\
    \  for (size_t i= 0; i < H; ++i)\n   for (size_t j= 0; j < m; ++j, ++a) ret[i]^=\
    \ *a & r[j];\n  return ret;\n }\n Vector<bool> operator()(const Vector<bool> &r)\
    \ const { return *this * r; }\n Matrix pow(uint64_t k) const {\n  assert(W ==\
    \ H);\n  for (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ?\
    \ ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <class K> static\
    \ bool is_zero(K x) {\n if constexpr (is_floating_point_v<K>) return abs(x) <\
    \ 1e-8;\n else return x == K();\n}\n}\nusing la_internal::Matrix;\n#line 6 \"\
    src/LinearAlgebra/LU_Decomposition.hpp\"\nnamespace la_internal {\ntemplate <class\
    \ K> class LU_Decomposition {\n Matrix<K> dat;\n vector<size_t> perm, piv;\n bool\
    \ sgn;\n size_t psz;\npublic:\n LU_Decomposition(const Matrix<K> &A): dat(A),\
    \ perm(A.height()), sgn(false), psz(0) {\n  const size_t h= A.height(), w= A.width();\n\
    \  iota(perm.begin(), perm.end(), 0), piv.resize(min(w, h));\n  for (size_t c=\
    \ 0, pos; c < w && psz < h; ++c) {\n   pos= psz;\n   if constexpr (is_floating_point_v<K>)\
    \ {\n    for (size_t r= psz + 1; r < h; ++r)\n     if (abs(dat[perm[pos]][c])\
    \ < abs(dat[perm[r]][c])) pos= r;\n   } else if (is_zero(dat[perm[pos]][c]))\n\
    \    for (size_t r= psz + 1; r < h; ++r)\n     if (!is_zero(dat[perm[r]][c]))\
    \ pos= r, r= h;\n   if (is_zero(dat[perm[pos]][c])) continue;\n   if (pos != psz)\
    \ sgn= !sgn, swap(perm[pos], perm[psz]);\n   const auto b= dat[perm[psz]];\n \
    \  for (size_t r= psz + 1, i; r < h; ++r) {\n    auto a= dat[perm[r]];\n    K\
    \ m= a[c] / b[c];\n    for (a[c]= K(), a[psz]= m, i= c + 1; i < w; ++i) a[i]-=\
    \ b[i] * m;\n   }\n   piv[psz++]= c;\n  }\n }\n size_t rank() const { return psz;\
    \ }\n bool is_regular() const { return rank() == dat.height() && rank() == dat.width();\
    \ }\n K det() const {\n  assert(dat.height() == dat.width());\n  K ret= sgn ?\
    \ -1 : 1;\n  for (size_t i= dat.width(); i--;) ret*= dat[perm[i]][i];\n  return\
    \ ret;\n }\n vector<Vector<K>> kernel() const {\n  const size_t w= dat.width(),\
    \ n= rank();\n  vector ker(w - n, Vector<K>(w));\n  for (size_t c= 0, i= 0; c\
    \ < w; ++c) {\n   if (i < n && piv[i] == c) ++i;\n   else {\n    auto &a= ker[c\
    \ - i];\n    a[c]= 1;\n    for (size_t r= i; r--;) a[r]= -dat[perm[r]][c];\n \
    \   for (size_t j= i, k, r; j--;) {\n     K x= a[j] / dat[perm[j]][k= piv[j]];\n\
    \     for (a[j]= 0, a[k]= x, r= j; r--;) a[r]-= dat[perm[r]][k] * x;\n    }\n\
    \   }\n  }\n  return ker;\n }\n Vector<K> linear_equations(const Vector<K> &b)\
    \ const {\n  const size_t h= dat.height(), w= dat.width(), n= rank();\n  assert(h\
    \ == b.size());\n  Vector<K> y(h), x(w);\n  for (size_t c= 0; c < h; ++c)\n  \
    \ if (y[c]+= b[perm[c]]; c < w)\n    for (size_t r= c + 1; r < h; ++r) y[r]-=\
    \ y[c] * dat[perm[r]][c];\n  for (size_t i= n; i < h; ++i)\n   if (!is_zero(y[i]))\
    \ return Vector<K>();  // no solution\n  for (size_t i= n, r; i--;)\n   for (x[piv[i]]=\
    \ y[i] / dat[perm[i]][piv[i]], r= i; r--;) y[r]-= x[piv[i]] * dat[perm[r]][piv[i]];\n\
    \  return x;\n }\n Matrix<K> inverse_matrix() const {\n  if (!is_regular()) return\
    \ Matrix<K>();  // no solution\n  const size_t n= dat.width();\n  Matrix<K> ret(n,\
    \ n);\n  for (size_t i= 0; i < n; ++i) {\n   Vector<K> y(n);\n   for (size_t c=\
    \ 0; c < n; ++c)\n    if (y[c]+= perm[c] == i; c < n && !is_zero(y[c]))\n    \
    \ for (size_t r= c + 1; r < n; ++r) y[r]-= y[c] * dat[perm[r]][c];\n   for (size_t\
    \ j= n; j--;) {\n    K m= ret[j][i]= y[j] / dat[perm[j]][j];\n    for (size_t\
    \ r= j; r--;) y[r]-= m * dat[perm[r]][j];\n   }\n  }\n  return ret;\n }\n};\n\
    void add_upper(u128 *a, const u128 *b, size_t bg, size_t ed) {  //[bg,ed)\n if\
    \ (bg >= ed) return;\n size_t s= bg >> 7;\n a[s]^= b[s] & -(u128(1) << (bg & 127));\n\
    \ for (size_t i= (ed + 127) >> 7; --i > s;) a[i]^= b[i];\n}\nvoid add_lower(u128\
    \ *a, const u128 *b, size_t ed) {  //[0,ed)\n size_t s= ed >> 7;\n a[s]^= b[s]\
    \ & ((u128(1) << (ed & 127)) - 1);\n for (size_t i= s; i--;) a[i]^= b[i];\n}\n\
    void subst_lower(u128 *a, const u128 *b, size_t ed) {  //[0,ed)\n size_t s= ed\
    \ >> 7;\n a[s]= b[s] & ((u128(1) << (ed & 127)) - 1);\n for (size_t i= s; i--;)\
    \ a[i]= b[i];\n}\nbool any1_upper(const u128 *a, size_t bg, size_t ed) {  //[bg,ed)\n\
    \ if (bg >= ed) return false;\n size_t s= bg >> 7;\n if (a[s] & -(u128(1) << (bg\
    \ & 127))) return true;\n for (size_t i= (ed + 127) >> 7; --i > s;)\n  if (a[i])\
    \ return true;\n return false;\n}\ntemplate <> class LU_Decomposition<bool> {\n\
    \ Matrix<bool> dat;\n vector<size_t> perm, piv;\n size_t psz;\npublic:\n LU_Decomposition(Matrix<bool>\
    \ A): dat(A.width(), A.height()), perm(A.height()), psz(0) {\n  const size_t h=\
    \ A.height(), w= A.width();\n  iota(perm.begin(), perm.end(), 0), piv.resize(min(w,\
    \ h));\n  for (size_t c= 0, pos; c < w && psz < h; ++c) {\n   for (pos= psz; pos\
    \ < h; ++pos)\n    if (A.get(perm[pos])[c]) break;\n   if (pos == h) continue;\n\
    \   if (pos != psz) swap(perm[pos], perm[psz]);\n   auto b= A.get(perm[psz]);\n\
    \   for (size_t r= psz + 1; r < h; ++r) {\n    auto a= A[perm[r]];\n    if (bool\
    \ m= a[c]; m) add_upper(a.data(), b.data(), c, w), a[psz]= 1;\n   }\n   piv[psz++]=\
    \ c;\n  }\n  for (size_t j= w; j--;)\n   for (size_t i= h; i--;) dat[j][i]= A.get(perm[i])[j];\n\
    \ }\n size_t rank() const { return psz; }\n bool is_regular() const { return rank()\
    \ == dat.height() && rank() == dat.width(); }\n bool det() const { return is_regular();\
    \ }\n vector<Vector<bool>> kernel() const {\n  const size_t w= dat.height(), n=\
    \ rank();\n  vector ker(w - rank(), Vector<bool>(w));\n  for (size_t c= 0, i=\
    \ 0; c < w; ++c) {\n   if (i < n && piv[i] == c) ++i;\n   else {\n    auto &a=\
    \ ker[c - i];\n    subst_lower(a.data(), dat[c].data(), i), a[c]= 1;\n    for\
    \ (size_t j= i, k; j--;) {\n     bool x= a[j];\n     if (a[j]= 0, a[k= piv[j]]=\
    \ x; x) add_lower(a.data(), dat[k].data(), j);\n    }\n   }\n  }\n  return ker;\n\
    \ }\n Vector<bool> linear_equations(const Vector<bool> &b) const {\n  const size_t\
    \ h= dat.width(), w= dat.height(), n= rank();\n  assert(h == b.size());\n  Vector<bool>\
    \ y(h), x(w);\n  for (size_t c= 0; c < h; ++c)\n   if (y[c]^= b[perm[c]]; c <\
    \ w && y[c]) add_upper(y.data(), dat[c].data(), c + 1, h);\n  if (any1_upper(y.data(),\
    \ n, h)) return Vector<bool>();  // no solution\n  for (size_t i= n; i--;)\n \
    \  if ((x[piv[i]]= y[i])) add_lower(y.data(), dat[piv[i]].data(), i);\n  return\
    \ x;\n }\n Matrix<bool> inverse_matrix() const {\n  if (!is_regular()) return\
    \ Matrix<bool>();  // no solution\n  const size_t n= dat.width();\n  Matrix<bool>\
    \ ret(n, n);\n  for (size_t i= 0; i < n; ++i) {\n   Vector<bool> y(n);\n   for\
    \ (size_t c= 0; c < n; ++c)\n    if (y[c]^= perm[c] == i; c < n && y[c]) add_upper(y.data(),\
    \ dat[c].data(), c, n);\n   for (size_t j= n; j--;)\n    if ((ret[j][i]= y[j]))\
    \ add_lower(y.data(), dat[j].data(), j);\n  }\n  return ret;\n }\n};\n}\nusing\
    \ la_internal::LU_Decomposition;\n#line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class\
    \ Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n\
    \ CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod)\
    \ DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const\
    \ { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n)\
    \ * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2():\
    \ mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL\
    \ u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod <<\
    \ 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE\
    \ IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\n\
    private:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x) >> 84;\
    \ }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n};\nstruct\
    \ MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0)\
    \ {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    };\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n\
    \ for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, enable_if_t<is_modint_v<T> && !is_same_v<T,\
    \ MInt>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod))\
    \ {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 5 \"test/yosupo/matrix_det.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using Mint=\
    \ ModInt<998244353>;\n int N;\n cin >> N;\n Matrix<Mint> A(N, N);\n for (int i=\
    \ 0; i < N; i++)\n  for (int j= 0; j < N; j++) cin >> A[i][j];\n cout << LU_Decomposition(A).det()\
    \ << endl;\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ <iostream>\n#include \"src/LinearAlgebra/LU_Decomposition.hpp\"\n#include \"\
    src/Math/ModInt.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n Matrix<Mint> A(N, N);\n\
    \ for (int i= 0; i < N; i++)\n  for (int j= 0; j < N; j++) cin >> A[i][j];\n cout\
    \ << LU_Decomposition(A).det() << endl;\n return 0;\n}"
  dependsOn:
  - src/LinearAlgebra/LU_Decomposition.hpp
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2023-10-25 00:54:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
