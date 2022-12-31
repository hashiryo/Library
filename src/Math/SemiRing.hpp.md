---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc236_g.test.cpp
    title: test/atcoder/abc236_g.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/SemiRing.hpp\"\n#include <bits/stdc++.h>\ntemplate\
    \ <typename T, T (*o)(), T (*i)(), T (*add)(T, T), T (*mul)(T, T)> struct SemiRing\
    \ {\n T x;\n SemiRing(): x(o()) {}\n SemiRing(bool y): x(y ? i() : o()) {}\n template\
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
    \ long> using BitwiseXorAndRig= Rig<BitwiseXorAnd<T>>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <typename T, T (*o)(), T\
    \ (*i)(), T (*add)(T, T), T (*mul)(T, T)> struct SemiRing {\n T x;\n SemiRing():\
    \ x(o()) {}\n SemiRing(bool y): x(y ? i() : o()) {}\n template <class U, std::enable_if_t<std::is_convertible_v<U,\
    \ T>, std::nullptr_t> = nullptr> SemiRing(U y): x((T)y) {}\n SemiRing &operator+=(const\
    \ SemiRing &r) { return x == o() ? *this= r : r.x == o() ? *this : *this= add(x,\
    \ r.x); }\n SemiRing &operator*=(const SemiRing &r) {\n  if (x == o() || r.x ==\
    \ o()) return *this= o();\n  return x == i() ? *this= r : r.x == i() ? *this :\
    \ *this= mul(x, r.x);\n }\n SemiRing operator+(const SemiRing &r) const { return\
    \ SemiRing(*this)+= r; }\n SemiRing operator*(const SemiRing &r) const { return\
    \ SemiRing(*this)*= r; }\n bool operator==(const SemiRing &r) const { return x\
    \ == r.x; }\n bool operator!=(const SemiRing &r) const { return x != r.x; }\n\
    \ friend std::istream &operator>>(std::istream &is, SemiRing &r) { return is >>\
    \ r.x, is; }\n friend std::ostream &operator<<(std::ostream &os, const SemiRing\
    \ &r) { return os << r.x; }\n};\ntemplate <class M> using Rig= SemiRing<typename\
    \ M::T, M::o, M::i, M::add, M::mul>;\ntemplate <class Arith> struct MinPlus {\n\
    \ using T= Arith;\n static T o() { return std::numeric_limits<T>::max(); }\n static\
    \ T i() { return T(0); }\n static T add(T vl, T vr) { return std::min(vl, vr);\
    \ }\n static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class T> using\
    \ MinPlusRig= Rig<MinPlus<T>>;\ntemplate <class Arith> struct MaxPlus {\n using\
    \ T= Arith;\n static T o() { return std::numeric_limits<T>::min(); }\n static\
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
    \ long> using BitwiseXorAndRig= Rig<BitwiseXorAnd<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SemiRing.hpp
  requiredBy: []
  timestamp: '2022-12-31 21:15:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1340.test.cpp
  - test/atcoder/abc236_g.test.cpp
documentation_of: src/Math/SemiRing.hpp
layout: document
title: "\u534A\u74B0"
---
行列に乗せる
## 問題例
[AtCoder Beginner Contest 009 D - 漸化式](https://atcoder.jp/contests/abc009/tasks/abc009_4) (BitwiseXorAnd) \
[DISCO presents ディスカバリーチャンネル コードコンテスト2020 本戦 B - Hawker on Graph](https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b) (max+の一次関数)