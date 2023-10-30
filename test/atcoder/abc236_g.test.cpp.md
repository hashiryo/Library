---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  - icon: ':x:'
    path: src/Math/SemiRing.hpp
    title: "\u534A\u74B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc236/tasks/abc236_g
    links:
    - https://atcoder.jp/contests/abc236/tasks/abc236_g
  bundledCode: "#line 1 \"test/atcoder/abc236_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_g\"\
    \n// (min,max)\u534A\u74B0\n#include <iostream>\n#line 2 \"src/Math/SemiRing.hpp\"\
    \n#include <limits>\n#include <type_traits>\n#include <cstddef>\ntemplate <class\
    \ M> struct SemiRing {\n using T= typename M::T;\n T x;\n SemiRing(): x(M::o)\
    \ {}\n SemiRing(bool y): x(y ? M::i : M::o) {}\n template <class U, std::enable_if_t<std::is_convertible_v<U,\
    \ T>, std::nullptr_t> = nullptr> SemiRing(U y): x((T)y) {}\n SemiRing &operator+=(const\
    \ SemiRing &r) { return M::add(x, r.x), *this; }\n SemiRing &operator*=(const\
    \ SemiRing &r) { return x == M::o || r.x == M::o ? *this= M::o : (M::mul(x, r.x),\
    \ *this); }\n SemiRing operator+(const SemiRing &r) const { return SemiRing(*this)+=\
    \ r; }\n SemiRing operator*(const SemiRing &r) const { return SemiRing(*this)*=\
    \ r; }\n bool operator==(const SemiRing &r) const { return x == r.x; }\n bool\
    \ operator!=(const SemiRing &r) const { return x != r.x; }\n friend std::istream\
    \ &operator>>(std::istream &is, SemiRing &r) { return is >> r.x, is; }\n friend\
    \ std::ostream &operator<<(std::ostream &os, const SemiRing &r) { return os <<\
    \ r.x; }\n};\ntemplate <class Arith> struct MinPlus {\n using T= Arith;\n static\
    \ inline T o= std::numeric_limits<T>::max(), i= T();\n static void add(T &vl,\
    \ T vr) { vl= std::min(vl, vr); }\n static void mul(T &vl, T vr) { vl+= vr; }\n\
    };\ntemplate <class T> using MinPlusRig= SemiRing<MinPlus<T>>;\ntemplate <class\
    \ Arith> struct MaxPlus {\n using T= Arith;\n static inline T o= std::numeric_limits<T>::min(),\
    \ i= T();\n static void add(T &vl, T vr) { vl= std::max(vl, vr); }\n static void\
    \ mul(T &vl, T vr) { vl+= vr; }\n};\ntemplate <class T> using MaxPlusRig= SemiRing<MaxPlus<T>>;\n\
    template <class Arith> struct MinMax {\n using T= Arith;\n static inline T o=\
    \ std::numeric_limits<T>::max(), i= std::numeric_limits<T>::min();\n static void\
    \ add(T &vl, T vr) { vl= std::min(vl, vr); }\n static void mul(T &vl, T vr) {\
    \ vl= std::max(vl, vr); }\n};\ntemplate <class T> using MinMaxRig= SemiRing<MinMax<T>>;\n\
    template <class Uint> struct BitwiseOrAnd {\n using T= Uint;\n static constexpr\
    \ T o= 0, i= T(-1);\n static void add(T &vl, T vr) { vl|= vr; }\n static void\
    \ mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate <class T= unsigned long long> using\
    \ BitwiseOrAndRig= SemiRing<BitwiseOrAnd<T>>;\ntemplate <class Uint> struct BitwiseXorAnd\
    \ {\n using T= Uint;\n static constexpr T o= 0, i= T(-1);\n static void add(T\
    \ &vl, T vr) { vl^= vr; }\n static void mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate\
    \ <class T= unsigned long long> using BitwiseXorAndRig= SemiRing<BitwiseXorAnd<T>>;\n\
    #line 2 \"src/LinearAlgebra/Matrix.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <cstdint>\n#include <valarray>\n\
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
    test/atcoder/abc236_g.test.cpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n using R= MinMaxRig<int>;\n int N, T, L;\n cin >>\
    \ N >> T >> L;\n Matrix<R> A(N, N);\n for (int t= 1; t <= T; t++) {\n  int u,\
    \ v;\n  cin >> u >> v, u--, v--;\n  A[v][u]= t;\n }\n A= A.pow(L);\n for (int\
    \ i= 0; i < N; i++) cout << (A[i][0] == R(false) ? -1 : A[i][0]) << \" \\n\"[i\
    \ == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_g\"\n//\
    \ (min,max)\u534A\u74B0\n#include <iostream>\n#include \"src/Math/SemiRing.hpp\"\
    \n#include \"src/LinearAlgebra/Matrix.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using R= MinMaxRig<int>;\n int\
    \ N, T, L;\n cin >> N >> T >> L;\n Matrix<R> A(N, N);\n for (int t= 1; t <= T;\
    \ t++) {\n  int u, v;\n  cin >> u >> v, u--, v--;\n  A[v][u]= t;\n }\n A= A.pow(L);\n\
    \ for (int i= 0; i < N; i++) cout << (A[i][0] == R(false) ? -1 : A[i][0]) << \"\
    \ \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn:
  - src/Math/SemiRing.hpp
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: true
  path: test/atcoder/abc236_g.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 16:37:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc236_g.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc236_g.test.cpp
- /verify/test/atcoder/abc236_g.test.cpp.html
title: test/atcoder/abc236_g.test.cpp
---
