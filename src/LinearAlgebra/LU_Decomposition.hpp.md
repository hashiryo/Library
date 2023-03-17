---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1328.test.cpp
    title: test/aoj/1328.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530.test.cpp
    title: test/aoj/2530.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2624.test.cpp
    title: test/aoj/2624.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inverse_matrix.test.cpp
    title: test/yosupo/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/linear_equations.test.cpp
    title: test/yosupo/linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/LinearAlgebra/LU_Decomposition.hpp\"\n#include <type_traits>\n\
    #include <numeric>\n#include <vector>\n#line 2 \"src/LinearAlgebra/Matrix.hpp\"\
    \n#include <cassert>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <valarray>\n\
    namespace la_internal {\ntemplate <class R> struct Vector: public std::valarray<R>\
    \ {\n using std::valarray<R>::valarray;\n};\nusing u128= __uint128_t;\nusing u8=\
    \ uint8_t;\nclass Ref {\n u128 *ref;\n u8 i;\n bool val;\npublic:\n Ref(u128 *r,\
    \ u8 j, bool v): ref(r), i(j), val(v) {}\n ~Ref() {\n  if (val ^ ((*ref >> i)\
    \ & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const Ref &r) { return val=\
    \ r.val, *this; }\n Ref &operator=(bool b) { return val= b, *this; }\n Ref &operator|=(bool\
    \ b) { return val|= b, *this; }\n Ref &operator&=(bool b) { return val&= b, *this;\
    \ }\n Ref &operator^=(bool b) { return val^= b, *this; }\n operator bool() const\
    \ { return val; }\n};\ntemplate <> class Vector<bool> {\n size_t n;\n std::valarray<u128>\
    \ dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t n): n(n), dat((n + 127) >>\
    \ 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b), (n + 127) >> 7) {}\n Ref\
    \ operator[](int i) {\n  u128 *ref= std::begin(dat) + (i >> 7);\n  u8 j= i & 127;\n\
    \  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n }\n bool operator[](int\
    \ i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n Vector &operator+=(const\
    \ Vector &r) { return dat^= r.dat, *this; }\n Vector &operator-=(const Vector\
    \ &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool b) {\n  if (!b)\
    \ dat= 0;\n  return *this;\n }\n Vector operator+(const Vector &r) const { return\
    \ Vector(*this)+= r; }\n Vector operator-(const Vector &r) const { return Vector(*this)-=\
    \ r; }\n Vector operator*(bool b) const { return Vector(*this)*= b; }\n size_t\
    \ size() const { return n; }\n u128 *data() { return std::begin(dat); }\n friend\
    \ Vector operator*(bool b, const Vector &r) { return r * b; }\n};\ntemplate <class\
    \ R> struct DiagonalMatrix: public Vector<R> {\n using Vector<R>::Vector;\n R\
    \ det() const {\n  R ret(true);\n  for (auto x: *this) ret*= x;\n  return ret;\n\
    \ }\n};\n}\nusing la_internal::Vector, la_internal::DiagonalMatrix;\n#line 4 \"\
    src/LinearAlgebra/Matrix.hpp\"\nnamespace la_internal {\ntemplate <class R> class\
    \ Matrix {\npublic:\n size_t W;\n std::valarray<R> dat;\npublic:\n static Matrix\
    \ identity_matrix(int n) {\n  Matrix ret(n, n);\n  return ret.dat[std::slice(0,\
    \ n, n + 1)]= R(true), ret;\n }\n Matrix(): W(0) {}\n Matrix(size_t h, size_t\
    \ w, R v= R()): W(w), dat(v, h * w) {}\n size_t width() const { return W; }\n\
    \ size_t height() const { return W ? dat.size() / W : 0; }\n operator bool() const\
    \ { return W; }\n auto operator[](int i) { return std::next(std::begin(dat), i\
    \ * W); }\n auto operator[](int i) const { return std::next(std::cbegin(dat),\
    \ i * W); }\n Matrix &operator+=(const Matrix &r) { return assert(dat.size() ==\
    \ r.dat.size()), assert(W == r.W), dat+= r.dat, *this; }\n Matrix operator+(const\
    \ Matrix &r) const { return Matrix(*this)+= r; }\n Matrix operator*(const Matrix\
    \ &r) const {\n  const size_t h= height(), w= r.W, l= W;\n  assert(l == r.height());\n\
    \  Matrix ret(h, w);\n  auto a= std::cbegin(dat);\n  auto c= std::begin(ret.dat);\n\
    \  for (int i= h; i--; std::advance(c, w)) {\n   auto b= std::cbegin(r.dat);\n\
    \   for (int k= l; k--; ++a) {\n    auto d= c;\n    auto v= *a;\n    for (int\
    \ j= w; j--; ++b, ++d) *d+= v * *b;\n   }\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Matrix &operator*=(const DiagonalMatrix<R>\
    \ &r) {\n  assert(W == r.size());\n  const size_t h= height();\n  auto a= std::begin(dat);\n\
    \  for (int i= 0; i < h; ++i)\n   for (int j= 0; j < W; ++j, ++a) *a*= r[j];\n\
    \  return *this;\n }\n Matrix operator*(const DiagonalMatrix<R> &r) const { return\
    \ Matrix(*this)*= r; }\n friend Matrix operator*(const DiagonalMatrix<R> &l, Matrix\
    \ r) {\n  const size_t h= r.height();\n  assert(h == l.size());\n  auto a= std::begin(r.dat);\n\
    \  for (int i= 0; i < h; ++i) {\n   auto v= l[i];\n   for (int j= 0; j < r.W;\
    \ ++j, ++a) *a*= v;\n  }\n  return r;\n }\n Vector<R> operator*(const Vector<R>\
    \ &r) const {\n  assert(W == r.size());\n  const size_t h= height();\n  Vector<R>\
    \ ret(h);\n  auto a= std::cbegin(dat);\n  for (int i= 0; i < h; ++i)\n   for (int\
    \ k= 0; k < W; ++k, ++a) ret[i]+= *a * r[k];\n  return ret;\n }\n Matrix pow(uint64_t\
    \ k) const {\n  assert(W * W == dat.size());\n  for (auto ret= identity_matrix(W),\
    \ b= *this;; b*= b)\n   if (k & 1 ? ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n\
    \ }\n};\ntemplate <> class Matrix<bool> {\n size_t H, W, m;\n std::valarray<u128>\
    \ dat;\n class Array {\n  u128 *bg;\n public:\n  Array(u128 *it): bg(it) {}\n\
    \  u128 *data() const { return bg; }\n  Ref operator[](int i) {\n   u128 *ref=\
    \ bg + (i >> 7);\n   u8 j= i & 127;\n   bool val= (*ref >> j) & 1;\n   return\
    \ Ref{ref, j, val};\n  }\n  bool operator[](int i) const { return (bg[i >> 7]\
    \ >> (i & 127)) & 1; }\n };\n class ConstArray {\n  const u128 *bg;\n public:\n\
    \  ConstArray(const u128 *it): bg(it) {}\n  const u128 *data() const { return\
    \ bg; }\n  bool operator[](int i) const { return (bg[i >> 7] >> (i & 127)) & 1;\
    \ }\n };\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix ret(n, n);\n\
    \  for (; n--;) ret[n][n]= 1;\n  return ret;\n }\n Matrix(): H(0), W(0), m(0)\
    \ {}\n Matrix(size_t h, size_t w, bool b= 0): H(h), W(w), m((w + 127) >> 7), dat(-u128(b),\
    \ h * m) {}\n size_t width() const { return W; }\n size_t height() const { return\
    \ H; }\n operator bool() const { return W; }\n Array operator[](int i) { return\
    \ {std::next(std::begin(dat), i * m)}; }\n ConstArray operator[](int i) const\
    \ { return {std::next(std::cbegin(dat), i * m)}; }\n ConstArray get(int i) const\
    \ { return {std::next(std::cbegin(dat), i * m)}; }\n Matrix &operator+=(const\
    \ Matrix &r) { return assert(H == r.H), assert(W == r.W), dat^= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  assert(W == r.H);\n  Matrix ret(H,\
    \ r.W);\n  u128 *c= std::begin(ret.dat);\n  for (size_t i= 0; i < H; ++i, std::advance(c,\
    \ m)) {\n   ConstArray a= this->operator[](i);\n   const u128 *b= std::cbegin(r.dat);\n\
    \   for (size_t k= 0; k < W; ++k, std::advance(b, r.m))\n    if (a[k])\n     for\
    \ (size_t j= 0; j < r.m; ++j) c[j]^= b[j];\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Vector<bool> operator*(const Vector<bool>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<bool> ret(H);\n  auto a= std::cbegin(dat);\n\
    \  for (size_t i= 0; i < H; ++i)\n   for (size_t j= 0; j < m; ++j, ++a) ret[i]^=\
    \ *a & r[j];\n  return ret;\n }\n Matrix pow(uint64_t k) const {\n  assert(W ==\
    \ H);\n  for (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ?\
    \ ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n }\n};\n}\nusing la_internal::Matrix;\n\
    #line 6 \"src/LinearAlgebra/LU_Decomposition.hpp\"\nnamespace la_internal {\n\
    template <class K> class LU_Decomposition {\n Matrix<K> dat;\n std::vector<size_t>\
    \ perm, piv;\n bool sgn;\n size_t psz;\n static bool is_zero(K x) {\n  if constexpr\
    \ (std::is_floating_point_v<K>) return std::abs(x) < 1e-8;\n  else return x ==\
    \ K();\n }\npublic:\n LU_Decomposition(const Matrix<K> &A): dat(A), perm(A.height()),\
    \ sgn(false), psz(0) {\n  const size_t h= A.height(), w= A.width();\n  std::iota(perm.begin(),\
    \ perm.end(), 0), piv.resize(std::min(w, h));\n  for (size_t c= 0, pos; c < w\
    \ && psz < h; ++c) {\n   pos= psz;\n   if constexpr (std::is_floating_point_v<K>)\
    \ {\n    for (size_t r= psz + 1; r < h; ++r)\n     if (std::abs(dat[perm[pos]][c])\
    \ < std::abs(dat[perm[r]][c])) pos= r;\n   } else if (is_zero(dat[perm[pos]][c]))\n\
    \    for (size_t r= psz + 1; r < h; ++r)\n     if (!is_zero(dat[perm[r]][c]))\
    \ pos= r, r= h;\n   if (is_zero(dat[perm[pos]][c])) continue;\n   if (pos != psz)\
    \ sgn= !sgn, std::swap(perm[pos], perm[psz]);\n   const auto b= dat[perm[psz]];\n\
    \   for (size_t r= psz + 1, i; r < h; ++r) {\n    auto a= dat[perm[r]];\n    K\
    \ m= a[c] / b[c];\n    for (a[c]= K(), a[psz]= m, i= c + 1; i < w; ++i) a[i]-=\
    \ b[i] * m;\n   }\n   piv[psz++]= c;\n  }\n }\n size_t rank() const { return psz;\
    \ }\n bool is_regular() const { return rank() == dat.height() && rank() == dat.width();\
    \ }\n K det() const {\n  assert(dat.height() == dat.width());\n  K ret= sgn ?\
    \ -1 : 1;\n  for (size_t i= dat.width(); i--;) ret*= dat[perm[i]][i];\n  return\
    \ ret;\n }\n std::vector<Vector<K>> kernel() const {\n  const size_t w= dat.width(),\
    \ n= rank();\n  std::vector ker(w - n, Vector<K>(w));\n  for (size_t c= 0, i=\
    \ 0; c < w; ++c) {\n   if (i < n && piv[i] == c) ++i;\n   else {\n    auto &a=\
    \ ker[c - i];\n    a[c]= 1;\n    for (size_t r= i; r--;) a[r]= -dat[perm[r]][c];\n\
    \    for (size_t j= i, k, r; j--;) {\n     K x= a[j] / dat[perm[j]][k= piv[j]];\n\
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
    \ Matrix<bool> dat;\n std::vector<size_t> perm, piv;\n size_t psz;\npublic:\n\
    \ LU_Decomposition(Matrix<bool> A): dat(A.width(), A.height()), perm(A.height()),\
    \ psz(0) {\n  const size_t h= A.height(), w= A.width();\n  std::iota(perm.begin(),\
    \ perm.end(), 0), piv.resize(std::min(w, h));\n  for (size_t c= 0, pos; c < w\
    \ && psz < h; ++c) {\n   for (pos= psz; pos < h; ++pos)\n    if (A.get(perm[pos])[c])\
    \ break;\n   if (pos == h) continue;\n   if (pos != psz) std::swap(perm[pos],\
    \ perm[psz]);\n   auto b= A.get(perm[psz]);\n   for (size_t r= psz + 1; r < h;\
    \ ++r) {\n    auto a= A[perm[r]];\n    if (bool m= a[c]; m) add_upper(a.data(),\
    \ b.data(), c, w), a[psz]= 1;\n   }\n   piv[psz++]= c;\n  }\n  for (size_t j=\
    \ w; j--;)\n   for (size_t i= h; i--;) dat[j][i]= A.get(perm[i])[j];\n }\n size_t\
    \ rank() const { return psz; }\n bool is_regular() const { return rank() == dat.height()\
    \ && rank() == dat.width(); }\n bool det() const { return is_regular(); }\n std::vector<Vector<bool>>\
    \ kernel() const {\n  const size_t w= dat.height(), n= rank();\n  std::vector\
    \ ker(w - rank(), Vector<bool>(w));\n  for (size_t c= 0, i= 0; c < w; ++c) {\n\
    \   if (i < n && piv[i] == c) ++i;\n   else {\n    auto &a= ker[c - i];\n    subst_lower(a.data(),\
    \ dat[c].data(), i), a[c]= 1;\n    for (size_t j= i, k; j--;) {\n     bool x=\
    \ a[j];\n     if (a[j]= 0, a[k= piv[j]]= x; x) add_lower(a.data(), dat[k].data(),\
    \ j);\n    }\n   }\n  }\n  return ker;\n }\n Vector<bool> linear_equations(const\
    \ Vector<bool> &b) const {\n  const size_t h= dat.width(), w= dat.height(), n=\
    \ rank();\n  assert(h == b.size());\n  Vector<bool> y(h), x(w);\n  for (size_t\
    \ c= 0; c < h; ++c)\n   if (y[c]^= b[perm[c]]; c < w && y[c]) add_upper(y.data(),\
    \ dat[c].data(), c + 1, h);\n  if (any1_upper(y.data(), n, h)) return Vector<bool>();\
    \  // no solution\n  for (size_t i= n; i--;)\n   if ((x[piv[i]]= y[i])) add_lower(y.data(),\
    \ dat[piv[i]].data(), i);\n  return x;\n }\n Matrix<bool> inverse_matrix() const\
    \ {\n  if (!is_regular()) return Matrix<bool>();  // no solution\n  const size_t\
    \ n= dat.width();\n  Matrix<bool> ret(n, n);\n  for (size_t i= 0; i < n; ++i)\
    \ {\n   Vector<bool> y(n);\n   for (size_t c= 0; c < n; ++c)\n    if (y[c]^= perm[c]\
    \ == i; c < n && y[c]) add_upper(y.data(), dat[c].data(), c, n);\n   for (size_t\
    \ j= n; j--;)\n    if ((ret[j][i]= y[j])) add_lower(y.data(), dat[j].data(), j);\n\
    \  }\n  return ret;\n }\n};\n}\nusing la_internal::LU_Decomposition;\n"
  code: "#pragma once\n#include <type_traits>\n#include <numeric>\n#include <vector>\n\
    #include \"src/LinearAlgebra/Matrix.hpp\"\nnamespace la_internal {\ntemplate <class\
    \ K> class LU_Decomposition {\n Matrix<K> dat;\n std::vector<size_t> perm, piv;\n\
    \ bool sgn;\n size_t psz;\n static bool is_zero(K x) {\n  if constexpr (std::is_floating_point_v<K>)\
    \ return std::abs(x) < 1e-8;\n  else return x == K();\n }\npublic:\n LU_Decomposition(const\
    \ Matrix<K> &A): dat(A), perm(A.height()), sgn(false), psz(0) {\n  const size_t\
    \ h= A.height(), w= A.width();\n  std::iota(perm.begin(), perm.end(), 0), piv.resize(std::min(w,\
    \ h));\n  for (size_t c= 0, pos; c < w && psz < h; ++c) {\n   pos= psz;\n   if\
    \ constexpr (std::is_floating_point_v<K>) {\n    for (size_t r= psz + 1; r < h;\
    \ ++r)\n     if (std::abs(dat[perm[pos]][c]) < std::abs(dat[perm[r]][c])) pos=\
    \ r;\n   } else if (is_zero(dat[perm[pos]][c]))\n    for (size_t r= psz + 1; r\
    \ < h; ++r)\n     if (!is_zero(dat[perm[r]][c])) pos= r, r= h;\n   if (is_zero(dat[perm[pos]][c]))\
    \ continue;\n   if (pos != psz) sgn= !sgn, std::swap(perm[pos], perm[psz]);\n\
    \   const auto b= dat[perm[psz]];\n   for (size_t r= psz + 1, i; r < h; ++r) {\n\
    \    auto a= dat[perm[r]];\n    K m= a[c] / b[c];\n    for (a[c]= K(), a[psz]=\
    \ m, i= c + 1; i < w; ++i) a[i]-= b[i] * m;\n   }\n   piv[psz++]= c;\n  }\n }\n\
    \ size_t rank() const { return psz; }\n bool is_regular() const { return rank()\
    \ == dat.height() && rank() == dat.width(); }\n K det() const {\n  assert(dat.height()\
    \ == dat.width());\n  K ret= sgn ? -1 : 1;\n  for (size_t i= dat.width(); i--;)\
    \ ret*= dat[perm[i]][i];\n  return ret;\n }\n std::vector<Vector<K>> kernel()\
    \ const {\n  const size_t w= dat.width(), n= rank();\n  std::vector ker(w - n,\
    \ Vector<K>(w));\n  for (size_t c= 0, i= 0; c < w; ++c) {\n   if (i < n && piv[i]\
    \ == c) ++i;\n   else {\n    auto &a= ker[c - i];\n    a[c]= 1;\n    for (size_t\
    \ r= i; r--;) a[r]= -dat[perm[r]][c];\n    for (size_t j= i, k, r; j--;) {\n \
    \    K x= a[j] / dat[perm[j]][k= piv[j]];\n     for (a[j]= 0, a[k]= x, r= j; r--;)\
    \ a[r]-= dat[perm[r]][k] * x;\n    }\n   }\n  }\n  return ker;\n }\n Vector<K>\
    \ linear_equations(const Vector<K> &b) const {\n  const size_t h= dat.height(),\
    \ w= dat.width(), n= rank();\n  assert(h == b.size());\n  Vector<K> y(h), x(w);\n\
    \  for (size_t c= 0; c < h; ++c)\n   if (y[c]+= b[perm[c]]; c < w)\n    for (size_t\
    \ r= c + 1; r < h; ++r) y[r]-= y[c] * dat[perm[r]][c];\n  for (size_t i= n; i\
    \ < h; ++i)\n   if (!is_zero(y[i])) return Vector<K>();  // no solution\n  for\
    \ (size_t i= n, r; i--;)\n   for (x[piv[i]]= y[i] / dat[perm[i]][piv[i]], r= i;\
    \ r--;) y[r]-= x[piv[i]] * dat[perm[r]][piv[i]];\n  return x;\n }\n Matrix<K>\
    \ inverse_matrix() const {\n  if (!is_regular()) return Matrix<K>();  // no solution\n\
    \  const size_t n= dat.width();\n  Matrix<K> ret(n, n);\n  for (size_t i= 0; i\
    \ < n; ++i) {\n   Vector<K> y(n);\n   for (size_t c= 0; c < n; ++c)\n    if (y[c]+=\
    \ perm[c] == i; c < n && !is_zero(y[c]))\n     for (size_t r= c + 1; r < n; ++r)\
    \ y[r]-= y[c] * dat[perm[r]][c];\n   for (size_t j= n; j--;) {\n    K m= ret[j][i]=\
    \ y[j] / dat[perm[j]][j];\n    for (size_t r= j; r--;) y[r]-= m * dat[perm[r]][j];\n\
    \   }\n  }\n  return ret;\n }\n};\nvoid add_upper(u128 *a, const u128 *b, size_t\
    \ bg, size_t ed) {  //[bg,ed)\n if (bg >= ed) return;\n size_t s= bg >> 7;\n a[s]^=\
    \ b[s] & -(u128(1) << (bg & 127));\n for (size_t i= (ed + 127) >> 7; --i > s;)\
    \ a[i]^= b[i];\n}\nvoid add_lower(u128 *a, const u128 *b, size_t ed) {  //[0,ed)\n\
    \ size_t s= ed >> 7;\n a[s]^= b[s] & ((u128(1) << (ed & 127)) - 1);\n for (size_t\
    \ i= s; i--;) a[i]^= b[i];\n}\nvoid subst_lower(u128 *a, const u128 *b, size_t\
    \ ed) {  //[0,ed)\n size_t s= ed >> 7;\n a[s]= b[s] & ((u128(1) << (ed & 127))\
    \ - 1);\n for (size_t i= s; i--;) a[i]= b[i];\n}\nbool any1_upper(const u128 *a,\
    \ size_t bg, size_t ed) {  //[bg,ed)\n if (bg >= ed) return false;\n size_t s=\
    \ bg >> 7;\n if (a[s] & -(u128(1) << (bg & 127))) return true;\n for (size_t i=\
    \ (ed + 127) >> 7; --i > s;)\n  if (a[i]) return true;\n return false;\n}\ntemplate\
    \ <> class LU_Decomposition<bool> {\n Matrix<bool> dat;\n std::vector<size_t>\
    \ perm, piv;\n size_t psz;\npublic:\n LU_Decomposition(Matrix<bool> A): dat(A.width(),\
    \ A.height()), perm(A.height()), psz(0) {\n  const size_t h= A.height(), w= A.width();\n\
    \  std::iota(perm.begin(), perm.end(), 0), piv.resize(std::min(w, h));\n  for\
    \ (size_t c= 0, pos; c < w && psz < h; ++c) {\n   for (pos= psz; pos < h; ++pos)\n\
    \    if (A.get(perm[pos])[c]) break;\n   if (pos == h) continue;\n   if (pos !=\
    \ psz) std::swap(perm[pos], perm[psz]);\n   auto b= A.get(perm[psz]);\n   for\
    \ (size_t r= psz + 1; r < h; ++r) {\n    auto a= A[perm[r]];\n    if (bool m=\
    \ a[c]; m) add_upper(a.data(), b.data(), c, w), a[psz]= 1;\n   }\n   piv[psz++]=\
    \ c;\n  }\n  for (size_t j= w; j--;)\n   for (size_t i= h; i--;) dat[j][i]= A.get(perm[i])[j];\n\
    \ }\n size_t rank() const { return psz; }\n bool is_regular() const { return rank()\
    \ == dat.height() && rank() == dat.width(); }\n bool det() const { return is_regular();\
    \ }\n std::vector<Vector<bool>> kernel() const {\n  const size_t w= dat.height(),\
    \ n= rank();\n  std::vector ker(w - rank(), Vector<bool>(w));\n  for (size_t c=\
    \ 0, i= 0; c < w; ++c) {\n   if (i < n && piv[i] == c) ++i;\n   else {\n    auto\
    \ &a= ker[c - i];\n    subst_lower(a.data(), dat[c].data(), i), a[c]= 1;\n   \
    \ for (size_t j= i, k; j--;) {\n     bool x= a[j];\n     if (a[j]= 0, a[k= piv[j]]=\
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
    \ la_internal::LU_Decomposition;"
  dependsOn:
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: false
  path: src/LinearAlgebra/LU_Decomposition.hpp
  requiredBy: []
  timestamp: '2023-03-12 23:35:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/linear_equations.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/aoj/2530.test.cpp
  - test/aoj/1328.test.cpp
  - test/aoj/2624.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/184.test.cpp
documentation_of: src/LinearAlgebra/LU_Decomposition.hpp
layout: document
title: "LU\u5206\u89E3"
---
`bool` は特殊化して有限体 $\mathbb{F}_2$ の意味で用いる \
その他の場合も行列の成分は 体 であること (特に乗法に関する逆元の存在) を前提にしている


## メンバ関数

| 関数名                | 概要                                                                                                                                                        | 計算量             |
| --------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------ |
| `LU_Decomposition(A)` | コンストラクタ. 行列 $A$ ( `Matrix` クラス ) のLU分解を実行.                                                                                                | $\mathcal{O}(n^3)$ |
| `rank()`              | 行列のランク $\mathrm{rank}\; A$ を返す                                                                                                                     | $\mathcal{O}(1)$   |
| `is_regular()`        | 行列が正則なら true                                                                                                                                         | $\mathcal{O}(1)$   |
| `det()`               | 行列式 $\det A$ の値を返す                                                                                                                                  | $\mathcal{O}(n)$   |
| `kernel()`            | 行列のカーネル $\mathrm{Ker}\;A \stackrel{\mathrm{def}}{=} \lbrace \boldsymbol{x}: A\boldsymbol{x}=\boldsymbol{0}\rbrace$ を返す. ( `Vector` クラスの集合 ) | $\mathcal{O}(n^3)$ |
| `linear_equations(b)` | 線形方程式 $A\boldsymbol{x}=\boldsymbol{b}$ の解の一つ ( `Vector` クラス ) を返す. 存在しないならサイズ0のものを返す                                        | $\mathcal{O}(n^2)$ |
| `inverse_matrix()`    | 逆行列 $A^{-1}$ を返す. 存在しないなら高さ・幅 0の `Matrix` を返す                                                                                          | $\mathcal{O}(n^3)$ |
