---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u534A\u74B0"
    links:
    - https://atcoder.jp/contests/abc009/tasks/abc009_4
    - https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b
  bundledCode: "#line 2 \"src/Math/SemiRing.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u534A\u74B0\n * @category \u6570\u5B66\n * \u884C\u5217\u306B\u8F09\
    \u305B\u308B\n */\n\n// verify\u7528\n// https://atcoder.jp/contests/abc009/tasks/abc009_4\n\
    // https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <typename T, T (*o)(), T (*i)(), T (*add)(T, T), T (*mul)(T,\
    \ T)>\nstruct SemiRing {\n  T x;\n  SemiRing() : x(o()) {}\n  SemiRing(bool y)\
    \ : x(y ? i() : o()) {}\n  template <class U>\n  SemiRing(U y) : x((T)y) {}\n\
    \  SemiRing &operator+=(const SemiRing &r) {\n    return x == o() ? *this = r\
    \ : r.x == o() ? *this : *this = add(x, r.x);\n  }\n  SemiRing &operator*=(const\
    \ SemiRing &r) {\n    if (x == o() || r.x == o()) return *this = o();\n    return\
    \ x == i() ? *this = r : r.x == i() ? *this : *this = mul(x, r.x);\n  }\n  SemiRing\
    \ operator+(const SemiRing &r) const { return SemiRing(*this) += r; }\n  SemiRing\
    \ operator*(const SemiRing &r) const { return SemiRing(*this) *= r; }\n  bool\
    \ operator==(const SemiRing &r) const { return x == r.x; }\n  bool operator!=(const\
    \ SemiRing &r) const { return x != r.x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, SemiRing &r) {\n    return is >> r.x, is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) {\n    return os << r.x;\n  }\n};\ntemplate <class M>\n\
    using Rig = SemiRing<typename M::T, M::o, M::i, M::add, M::mul>;\n\ntemplate <class\
    \ Arith>\nstruct MinPlus {\n  using T = Arith;\n  static T o() { return std::numeric_limits<T>::max();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::min(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MinPlusRig = Rig<MinPlus<T>>;\n\ntemplate <class Arith>\nstruct MaxPlus\
    \ {\n  using T = Arith;\n  static T o() { return std::numeric_limits<T>::min();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::max(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MaxPlusRig = Rig<MaxPlus<T>>;\n\ntemplate <class Uint>\nstruct BitwiseOrAnd\
    \ {\n  using T = Uint;\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl | vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseOrAndRig = Rig<BitwiseOrAnd<T>>;\n\ntemplate <class Uint>\nstruct BitwiseXorAnd\
    \ {\n  using T = Uint;\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl ^ vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseXorAndRig = Rig<BitwiseXorAnd<T>>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u534A\u74B0\n * @category\
    \ \u6570\u5B66\n * \u884C\u5217\u306B\u8F09\u305B\u308B\n */\n\n// verify\u7528\
    \n// https://atcoder.jp/contests/abc009/tasks/abc009_4\n// https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename T, T (*o)(), T (*i)(), T (*add)(T, T),\
    \ T (*mul)(T, T)>\nstruct SemiRing {\n  T x;\n  SemiRing() : x(o()) {}\n  SemiRing(bool\
    \ y) : x(y ? i() : o()) {}\n  template <class U>\n  SemiRing(U y) : x((T)y) {}\n\
    \  SemiRing &operator+=(const SemiRing &r) {\n    return x == o() ? *this = r\
    \ : r.x == o() ? *this : *this = add(x, r.x);\n  }\n  SemiRing &operator*=(const\
    \ SemiRing &r) {\n    if (x == o() || r.x == o()) return *this = o();\n    return\
    \ x == i() ? *this = r : r.x == i() ? *this : *this = mul(x, r.x);\n  }\n  SemiRing\
    \ operator+(const SemiRing &r) const { return SemiRing(*this) += r; }\n  SemiRing\
    \ operator*(const SemiRing &r) const { return SemiRing(*this) *= r; }\n  bool\
    \ operator==(const SemiRing &r) const { return x == r.x; }\n  bool operator!=(const\
    \ SemiRing &r) const { return x != r.x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, SemiRing &r) {\n    return is >> r.x, is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) {\n    return os << r.x;\n  }\n};\ntemplate <class M>\n\
    using Rig = SemiRing<typename M::T, M::o, M::i, M::add, M::mul>;\n\ntemplate <class\
    \ Arith>\nstruct MinPlus {\n  using T = Arith;\n  static T o() { return std::numeric_limits<T>::max();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::min(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MinPlusRig = Rig<MinPlus<T>>;\n\ntemplate <class Arith>\nstruct MaxPlus\
    \ {\n  using T = Arith;\n  static T o() { return std::numeric_limits<T>::min();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::max(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MaxPlusRig = Rig<MaxPlus<T>>;\n\ntemplate <class Uint>\nstruct BitwiseOrAnd\
    \ {\n  using T = Uint;\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl | vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseOrAndRig = Rig<BitwiseOrAnd<T>>;\n\ntemplate <class Uint>\nstruct BitwiseXorAnd\
    \ {\n  using T = Uint;\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl ^ vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseXorAndRig = Rig<BitwiseXorAnd<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SemiRing.hpp
  requiredBy: []
  timestamp: '2022-06-17 10:35:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1340.test.cpp
documentation_of: src/Math/SemiRing.hpp
layout: document
redirect_from:
- /library/src/Math/SemiRing.hpp
- /library/src/Math/SemiRing.hpp.html
title: "\u534A\u74B0"
---
