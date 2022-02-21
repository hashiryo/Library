---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1340.test.cpp
    title: test/yukicoder/1340.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ T)>\nstruct SemiRing {\n  T x;\n  SemiRing() : x(o()) {}\n  SemiRing(T y) :\
    \ x(y) {}\n  static T O() { return o(); }\n  static T I() { return i(); }\n  SemiRing\
    \ &operator+=(const SemiRing &r) {\n    return x == o() ? *this = r : r.x == o()\
    \ ? *this : *this = add(x, r.x);\n  }\n  SemiRing &operator*=(const SemiRing &r)\
    \ {\n    if (x == o() || r.x == o()) return *this = o();\n    return x == i()\
    \ ? *this = r : r.x == i() ? *this : *this = mul(x, r.x);\n  }\n  SemiRing operator+(const\
    \ SemiRing &r) const { return SemiRing(*this) += r; }\n  SemiRing operator*(const\
    \ SemiRing &r) const { return SemiRing(*this) *= r; }\n  bool operator==(const\
    \ SemiRing &r) const { return x == r.x; }\n  bool operator!=(const SemiRing &r)\
    \ const { return x != r.x; }\n  friend std::istream &operator>>(std::istream &is,\
    \ SemiRing &r) {\n    return is >> r.x, is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) {\n    return os << r.x;\n  }\n};\n\ntemplate <class\
    \ T>\nstruct MinPlus {\n  static T o() { return std::numeric_limits<T>::max();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::min(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MinPlusRig = SemiRing<T, MinPlus<T>::o, MinPlus<T>::i, MinPlus<T>::add,\n\
    \                            MinPlus<T>::mul>;\n\ntemplate <class T>\nstruct MaxPlus\
    \ {\n  static T o() { return std::numeric_limits<T>::min(); }\n  static T i()\
    \ { return T(0); }\n  static T add(T vl, T vr) { return std::max(vl, vr); }\n\
    \  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class T>\nusing\
    \ MaxPlusRig = SemiRing<T, MaxPlus<T>::o, MaxPlus<T>::i, MaxPlus<T>::add,\n  \
    \                          MaxPlus<T>::mul>;\n\ntemplate <class T>\nstruct BitwiseOrAnd\
    \ {\n  static T o() { return 0; }\n  static T i() { return T(-1); }\n  static\
    \ T add(T vl, T vr) { return vl | vr; }\n  static T mul(T vl, T vr) { return vl\
    \ & vr; }\n};\ntemplate <class T = unsigned long long>\nusing BitwiseOrAndRig\
    \ = SemiRing<T, BitwiseOrAnd<T>::o, BitwiseOrAnd<T>::i,\n                    \
    \             BitwiseOrAnd<T>::add, BitwiseOrAnd<T>::mul>;\n\ntemplate <class\
    \ T>\nstruct BitwiseXorAnd {\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl ^ vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseXorAndRig = SemiRing<T, BitwiseXorAnd<T>::o, BitwiseXorAnd<T>::i,\n \
    \                                 BitwiseXorAnd<T>::add, BitwiseXorAnd<T>::mul>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u534A\u74B0\n * @category\
    \ \u6570\u5B66\n * \u884C\u5217\u306B\u8F09\u305B\u308B\n */\n\n// verify\u7528\
    \n// https://atcoder.jp/contests/abc009/tasks/abc009_4\n// https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_b\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename T, T (*o)(), T (*i)(), T (*add)(T, T),\
    \ T (*mul)(T, T)>\nstruct SemiRing {\n  T x;\n  SemiRing() : x(o()) {}\n  SemiRing(T\
    \ y) : x(y) {}\n  static T O() { return o(); }\n  static T I() { return i(); }\n\
    \  SemiRing &operator+=(const SemiRing &r) {\n    return x == o() ? *this = r\
    \ : r.x == o() ? *this : *this = add(x, r.x);\n  }\n  SemiRing &operator*=(const\
    \ SemiRing &r) {\n    if (x == o() || r.x == o()) return *this = o();\n    return\
    \ x == i() ? *this = r : r.x == i() ? *this : *this = mul(x, r.x);\n  }\n  SemiRing\
    \ operator+(const SemiRing &r) const { return SemiRing(*this) += r; }\n  SemiRing\
    \ operator*(const SemiRing &r) const { return SemiRing(*this) *= r; }\n  bool\
    \ operator==(const SemiRing &r) const { return x == r.x; }\n  bool operator!=(const\
    \ SemiRing &r) const { return x != r.x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, SemiRing &r) {\n    return is >> r.x, is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const SemiRing &r) {\n    return os << r.x;\n  }\n};\n\ntemplate <class\
    \ T>\nstruct MinPlus {\n  static T o() { return std::numeric_limits<T>::max();\
    \ }\n  static T i() { return T(0); }\n  static T add(T vl, T vr) { return std::min(vl,\
    \ vr); }\n  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class\
    \ T>\nusing MinPlusRig = SemiRing<T, MinPlus<T>::o, MinPlus<T>::i, MinPlus<T>::add,\n\
    \                            MinPlus<T>::mul>;\n\ntemplate <class T>\nstruct MaxPlus\
    \ {\n  static T o() { return std::numeric_limits<T>::min(); }\n  static T i()\
    \ { return T(0); }\n  static T add(T vl, T vr) { return std::max(vl, vr); }\n\
    \  static T mul(T vl, T vr) { return vl + vr; }\n};\ntemplate <class T>\nusing\
    \ MaxPlusRig = SemiRing<T, MaxPlus<T>::o, MaxPlus<T>::i, MaxPlus<T>::add,\n  \
    \                          MaxPlus<T>::mul>;\n\ntemplate <class T>\nstruct BitwiseOrAnd\
    \ {\n  static T o() { return 0; }\n  static T i() { return T(-1); }\n  static\
    \ T add(T vl, T vr) { return vl | vr; }\n  static T mul(T vl, T vr) { return vl\
    \ & vr; }\n};\ntemplate <class T = unsigned long long>\nusing BitwiseOrAndRig\
    \ = SemiRing<T, BitwiseOrAnd<T>::o, BitwiseOrAnd<T>::i,\n                    \
    \             BitwiseOrAnd<T>::add, BitwiseOrAnd<T>::mul>;\n\ntemplate <class\
    \ T>\nstruct BitwiseXorAnd {\n  static T o() { return 0; }\n  static T i() { return\
    \ T(-1); }\n  static T add(T vl, T vr) { return vl ^ vr; }\n  static T mul(T vl,\
    \ T vr) { return vl & vr; }\n};\ntemplate <class T = unsigned long long>\nusing\
    \ BitwiseXorAndRig = SemiRing<T, BitwiseXorAnd<T>::o, BitwiseXorAnd<T>::i,\n \
    \                                 BitwiseXorAnd<T>::add, BitwiseXorAnd<T>::mul>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SemiRing.hpp
  requiredBy: []
  timestamp: '2021-02-09 12:55:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1340.test.cpp
documentation_of: src/Math/SemiRing.hpp
layout: document
redirect_from:
- /library/src/Math/SemiRing.hpp
- /library/src/Math/SemiRing.hpp.html
title: "\u534A\u74B0"
---
