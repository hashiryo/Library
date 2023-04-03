---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc236_g.test.cpp
    title: test/atcoder/abc236_g.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/SemiRing.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #include <cstddef>\ntemplate <class M> struct SemiRing {\n using T= typename M::T;\n\
    \ T x;\n SemiRing(): x(M::o) {}\n SemiRing(bool y): x(y ? M::i : M::o) {}\n template\
    \ <class U, std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>\
    \ SemiRing(U y): x((T)y) {}\n SemiRing &operator+=(const SemiRing &r) { return\
    \ M::add(x, r.x), *this; }\n SemiRing &operator*=(const SemiRing &r) { return\
    \ x == M::o || r.x == M::o ? *this= M::o : (M::mul(x, r.x), *this); }\n SemiRing\
    \ operator+(const SemiRing &r) const { return SemiRing(*this)+= r; }\n SemiRing\
    \ operator*(const SemiRing &r) const { return SemiRing(*this)*= r; }\n bool operator==(const\
    \ SemiRing &r) const { return x == r.x; }\n bool operator!=(const SemiRing &r)\
    \ const { return x != r.x; }\n friend std::istream &operator>>(std::istream &is,\
    \ SemiRing &r) { return is >> r.x, is; }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) { return os << r.x; }\n};\ntemplate <class Arith> struct\
    \ MinPlus {\n using T= Arith;\n static inline T o= std::numeric_limits<T>::max(),\
    \ i= T();\n static void add(T &vl, T vr) { vl= std::min(vl, vr); }\n static void\
    \ mul(T &vl, T vr) { vl+= vr; }\n};\ntemplate <class T> using MinPlusRig= Rig<MinPlus<T>>;\n\
    template <class Arith> struct MaxPlus {\n using T= Arith;\n static inline T o=\
    \ std::numeric_limits<T>::min(), i= T();\n static void add(T &vl, T vr) { vl=\
    \ std::max(vl, vr); }\n static void mul(T &vl, T vr) { vl+= vr; }\n};\ntemplate\
    \ <class T> using MaxPlusRig= Rig<MaxPlus<T>>;\ntemplate <class Arith> struct\
    \ MinMax {\n using T= Arith;\n static inline T o= std::numeric_limits<T>::max(),\
    \ i= std::numeric_limits<T>::min();\n static void add(T &vl, T vr) { vl= std::min(vl,\
    \ vr); }\n static void mul(T &vl, T vr) { vl= std::max(vl, vr); }\n};\ntemplate\
    \ <class T> using MinMaxRig= Rig<MinMax<T>>;\ntemplate <class Uint> struct BitwiseOrAnd\
    \ {\n using T= Uint;\n static constexpr T o= 0, i= T(-1);\n static void add(T\
    \ &vl, T vr) { vl|= vr; }\n static void mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate\
    \ <class T= unsigned long long> using BitwiseOrAndRig= Rig<BitwiseOrAnd<T>>;\n\
    template <class Uint> struct BitwiseXorAnd {\n using T= Uint;\n static constexpr\
    \ T o= 0, i= T(-1);\n static void add(T &vl, T vr) { vl^= vr; }\n static void\
    \ mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate <class T= unsigned long long> using\
    \ BitwiseXorAndRig= Rig<BitwiseXorAnd<T>>;\n"
  code: "#pragma once\n#include <limits>\n#include <type_traits>\n#include <cstddef>\n\
    template <class M> struct SemiRing {\n using T= typename M::T;\n T x;\n SemiRing():\
    \ x(M::o) {}\n SemiRing(bool y): x(y ? M::i : M::o) {}\n template <class U, std::enable_if_t<std::is_convertible_v<U,\
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
    };\ntemplate <class T> using MinPlusRig= Rig<MinPlus<T>>;\ntemplate <class Arith>\
    \ struct MaxPlus {\n using T= Arith;\n static inline T o= std::numeric_limits<T>::min(),\
    \ i= T();\n static void add(T &vl, T vr) { vl= std::max(vl, vr); }\n static void\
    \ mul(T &vl, T vr) { vl+= vr; }\n};\ntemplate <class T> using MaxPlusRig= Rig<MaxPlus<T>>;\n\
    template <class Arith> struct MinMax {\n using T= Arith;\n static inline T o=\
    \ std::numeric_limits<T>::max(), i= std::numeric_limits<T>::min();\n static void\
    \ add(T &vl, T vr) { vl= std::min(vl, vr); }\n static void mul(T &vl, T vr) {\
    \ vl= std::max(vl, vr); }\n};\ntemplate <class T> using MinMaxRig= Rig<MinMax<T>>;\n\
    template <class Uint> struct BitwiseOrAnd {\n using T= Uint;\n static constexpr\
    \ T o= 0, i= T(-1);\n static void add(T &vl, T vr) { vl|= vr; }\n static void\
    \ mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate <class T= unsigned long long> using\
    \ BitwiseOrAndRig= Rig<BitwiseOrAnd<T>>;\ntemplate <class Uint> struct BitwiseXorAnd\
    \ {\n using T= Uint;\n static constexpr T o= 0, i= T(-1);\n static void add(T\
    \ &vl, T vr) { vl^= vr; }\n static void mul(T &vl, T vr) { vl&= vr; }\n};\ntemplate\
    \ <class T= unsigned long long> using BitwiseXorAndRig= Rig<BitwiseXorAnd<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SemiRing.hpp
  requiredBy: []
  timestamp: '2023-04-03 21:10:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc236_g.test.cpp
  - test/yukicoder/1340.test.cpp
documentation_of: src/Math/SemiRing.hpp
layout: document
title: "\u534A\u74B0"
---
行列に乗せる
## 問題例
[AtCoder Beginner Contest 009 D - 漸化式](https://atcoder.jp/contests/abc009/tasks/abc009_4) (BitwiseXorAnd) \
[DISCO presents ディスカバリーチャンネル コードコンテスト2020 本戦 B - Hawker on Graph](https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b) (max+の一次関数)