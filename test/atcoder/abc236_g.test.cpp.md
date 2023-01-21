---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/LinearAlgebra/Matrix.hpp
    title: src/LinearAlgebra/Matrix.hpp
  - icon: ':heavy_check_mark:'
    path: src/Math/SemiRing.hpp
    title: "\u534A\u74B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc236/tasks/abc236_g
    links:
    - https://atcoder.jp/contests/abc236/tasks/abc236_g
  bundledCode: "#line 1 \"test/atcoder/abc236_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_g\"\
    \n// (min,max)\u534A\u74B0\n#include <iostream>\n#line 2 \"src/Math/SemiRing.hpp\"\
    \n#include <limits>\n#include <type_traits>\n#include <cstddef>\ntemplate <typename\
    \ T, T (*o)(), T (*i)(), T (*add)(T, T), T (*mul)(T, T)> struct SemiRing {\n T\
    \ x;\n SemiRing(): x(o()) {}\n SemiRing(bool y): x(y ? i() : o()) {}\n template\
    \ <class U, std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>\
    \ SemiRing(U y): x((T)y) {}\n SemiRing &operator+=(const SemiRing &r) { return\
    \ x == o() ? *this= r : r.x == o() ? *this : *this= add(x, r.x); }\n SemiRing\
    \ &operator*=(const SemiRing &r) {\n  if (x == o() || r.x == o()) return *this=\
    \ o();\n  return x == i() ? *this= r : r.x == i() ? *this : *this= mul(x, r.x);\n\
    \ }\n SemiRing operator+(const SemiRing &r) const { return SemiRing(*this)+= r;\
    \ }\n SemiRing operator*(const SemiRing &r) const { return SemiRing(*this)*= r;\
    \ }\n bool operator==(const SemiRing &r) const { return x == r.x; }\n bool operator!=(const\
    \ SemiRing &r) const { return x != r.x; }\n friend std::istream &operator>>(std::istream\
    \ &is, SemiRing &r) { return is >> r.x, is; }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) { return os << r.x; }\n};\ntemplate <class M> using\
    \ Rig= SemiRing<typename M::T, M::o, M::i, M::add, M::mul>;\ntemplate <class Arith>\
    \ struct MinPlus {\n using T= Arith;\n static T o() { return std::numeric_limits<T>::max();\
    \ }\n static T i() { return T(0); }\n static T add(T vl, T vr) { return std::min(vl,\
    \ vr); }\n static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class T>\
    \ using MinPlusRig= Rig<MinPlus<T>>;\ntemplate <class Arith> struct MaxPlus {\n\
    \ using T= Arith;\n static T o() { return std::numeric_limits<T>::min(); }\n static\
    \ T i() { return T(0); }\n static T add(T vl, T vr) { return std::max(vl, vr);\
    \ }\n static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class T> using\
    \ MaxPlusRig= Rig<MaxPlus<T>>;\ntemplate <class Arith> struct MinMax {\n using\
    \ T= Arith;\n static T o() { return std::numeric_limits<T>::max(); }\n static\
    \ T i() { return std::numeric_limits<T>::min(); }\n static T add(T vl, T vr) {\
    \ return std::min(vl, vr); }\n static T mul(T vl, T vr) { return std::max(vl,\
    \ vr); }\n};\ntemplate <class T> using MinMaxRig= Rig<MinMax<T>>;\ntemplate <class\
    \ Uint> struct BitwiseOrAnd {\n using T= Uint;\n static T o() { return 0; }\n\
    \ static T i() { return T(-1); }\n static T add(T vl, T vr) { return vl | vr;\
    \ }\n static T mul(T vl, T vr) { return vl & vr; }\n};\ntemplate <class T= unsigned\
    \ long long> using BitwiseOrAndRig= Rig<BitwiseOrAnd<T>>;\ntemplate <class Uint>\
    \ struct BitwiseXorAnd {\n using T= Uint;\n static T o() { return 0; }\n static\
    \ T i() { return T(-1); }\n static T add(T vl, T vr) { return vl ^ vr; }\n static\
    \ T mul(T vl, T vr) { return vl & vr; }\n};\ntemplate <class T= unsigned long\
    \ long> using BitwiseXorAndRig= Rig<BitwiseXorAnd<T>>;\n#line 2 \"src/LinearAlgebra/Matrix.hpp\"\
    \n#include <array>\n#include <vector>\n#include <bitset>\ntemplate <class R, int\
    \ N, int M> struct Matrix: public std::array<std::array<R, M>, N> {\n static constexpr\
    \ Matrix O() { return Matrix(); }\n Matrix &operator+=(const Matrix &r) {\n  for\
    \ (int i= N; i--;)\n   for (int j= M; j--;) (*this)[i][j]+= r[i][j];\n  return\
    \ *this;\n }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+=\
    \ r; }\n template <int L> Matrix<R, N, L> operator*(const Matrix<R, M, L> &r)\
    \ const {\n  Matrix<R, N, L> ret;\n  for (int i= N; i--;)\n   for (int k= M; k--;)\n\
    \    for (int j= L; j--;) ret[i][j]+= (*this)[i][k] * r[k][j];\n  return ret;\n\
    \ }\n std::array<R, N> operator*(const std::array<R, M> &r) const {\n  std::array<R,\
    \ N> ret;\n  for (int i= N; i--;)\n   for (int j= M; j--;) ret[i]+= (*this)[i][j]\
    \ * r[j];\n  return ret;\n }\n std::vector<std::vector<R>> to_vec(int n, int m)\
    \ const {\n  std::vector<std::vector<R>> ret(n, std::vector<R>(m));\n  for (int\
    \ i= n; i--;)\n   for (int j= m; j--;) ret[i][j]= (*this)[i][j];\n  return ret;\n\
    \ }\n};\ntemplate <int N, int M> struct Matrix<bool, N, M>: public std::array<std::bitset<M>,\
    \ N> {\n static constexpr Matrix O() { return Matrix(); }\n Matrix &operator+=(const\
    \ Matrix &r) {\n  for (int i= N; i--;) (*this)[i]^= r[i];\n  return *this;\n }\n\
    \ Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n template\
    \ <int L> Matrix<bool, N, L> operator*(const Matrix<bool, M, L> &r) const {\n\
    \  Matrix<bool, L, M> t;\n  Matrix<bool, N, L> ret;\n  for (int i= M; i--;)\n\
    \   for (int j= L; j--;) t[j][i]= r[i][j];\n  for (int i= N; i--;)\n   for (int\
    \ j= L; j--;) ret[i][j]= ((*this)[i] & t[j]).count() & 1;\n  return ret;\n }\n\
    \ std::bitset<N> operator*(const std::bitset<N> &r) const {\n  std::bitset<N>\
    \ ret;\n  for (int i= N; i--;) ret[i]= ((*this)[i] & r).count() & 1;\n  return\
    \ ret;\n }\n std::vector<std::vector<bool>> to_vec(int n, int m) const {\n  std::vector<std::vector<bool>>\
    \ ret(n, std::vector<bool>(m));\n  for (int i= n; i--;)\n   for (int j= m; j--;)\
    \ ret[i][j]= (*this)[i][j];\n  return ret;\n }\n};\ntemplate <class R, int N>\
    \ struct SquareMatrix: public Matrix<R, N, N> {\n using Matrix<R, N, N>::Matrix;\n\
    \ SquareMatrix(Matrix<R, N, N> m) { *this= m; }\n static constexpr SquareMatrix\
    \ I() {\n  SquareMatrix ret;\n  for (int i= N; i--;) ret[i][i]= R(true);\n  return\
    \ ret;\n }\n SquareMatrix &operator=(const Matrix<R, N, N> &r) {\n  for (int i=\
    \ N; i--;)\n   for (int j= N; j--;) (*this)[i][j]= r[i][j];\n  return *this;\n\
    \ }\n SquareMatrix &operator*=(const SquareMatrix &r) { return *this= (*this)\
    \ * r; }\n SquareMatrix pow(std::uint64_t e) const {\n  for (SquareMatrix ret=\
    \ I(), b= *this;; b*= b)\n   if (e & 1 ? ret*= b, !(e>>= 1) : !(e>>= 1)) return\
    \ ret;\n }\n};\n#line 6 \"test/atcoder/abc236_g.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using R= MinMaxRig<int>;\n\
    \ int N, T, L;\n cin >> N >> T >> L;\n SquareMatrix<R, 100> A;\n for (int t= 1;\
    \ t <= T; t++) {\n  int u, v;\n  cin >> u >> v, u--, v--;\n  A[v][u]= t;\n }\n\
    \ A= A.pow(L);\n for (int i= 0; i < N; i++) cout << (A[i][0] == R(false) ? -1\
    \ : A[i][0]) << \" \\n\"[i == N - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_g\"\n//\
    \ (min,max)\u534A\u74B0\n#include <iostream>\n#include \"src/Math/SemiRing.hpp\"\
    \n#include \"src/LinearAlgebra/Matrix.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using R= MinMaxRig<int>;\n int\
    \ N, T, L;\n cin >> N >> T >> L;\n SquareMatrix<R, 100> A;\n for (int t= 1; t\
    \ <= T; t++) {\n  int u, v;\n  cin >> u >> v, u--, v--;\n  A[v][u]= t;\n }\n A=\
    \ A.pow(L);\n for (int i= 0; i < N; i++) cout << (A[i][0] == R(false) ? -1 : A[i][0])\
    \ << \" \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn:
  - src/Math/SemiRing.hpp
  - src/LinearAlgebra/Matrix.hpp
  isVerificationFile: true
  path: test/atcoder/abc236_g.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 20:28:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc236_g.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc236_g.test.cpp
- /verify/test/atcoder/abc236_g.test.cpp.html
title: test/atcoder/abc236_g.test.cpp
---
