---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/binary_gcd.hpp
    title: Binary GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0350.test.cpp
    title: test/aoj/0350.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit_test/constexpr_rational.test.cpp
    title: test/unit_test/constexpr_rational.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1501.test.cpp
    title: test/yukicoder/1501.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/Rational.hpp\"\n#include <string>\n#include <limits>\n\
    #include <sstream>\n#line 2 \"src/Math/binary_gcd.hpp\"\n#include <type_traits>\n\
    #include <algorithm>\ntemplate <class Int> constexpr int bsf(Int a) {\n if constexpr\
    \ (sizeof(Int) == 16) {\n  uint64_t lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n } else if constexpr (sizeof(Int) == 8) return\
    \ __builtin_ctzll(a);\n else return __builtin_ctz(a);\n}\ntemplate <class Int>\
    \ constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0 || b == 0) return a +\
    \ b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int\
    \ d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n\
    \ }\n return a << std::min(n, m);\n}\n#line 6 \"src/Math/Rational.hpp\"\ntemplate\
    \ <class Int, bool reduction= true> struct Rational {\n Int num, den;\n constexpr\
    \ Rational(Int num= 0, Int den= 1): num(num), den(den) {\n  if (den < 0) num=\
    \ -num, den= -den;\n  if constexpr (reduction) reduce();\n }\n constexpr void\
    \ reduce() {\n  const Int g= binary_gcd(num < 0 ? -num : num, den);\n  num/= g,\
    \ den/= g;\n }\n constexpr Rational operator-() const { return Rational(-num,\
    \ den); }\n constexpr Rational operator+(const Rational &r) const { return Rational(num\
    \ * r.den + den * r.num, den * r.den); }\n constexpr Rational operator-(const\
    \ Rational &r) const { return Rational(num * r.den - den * r.num, den * r.den);\
    \ }\n constexpr Rational operator*(const Rational &r) const { return Rational(num\
    \ * r.num, den * r.den); }\n constexpr Rational operator/(const Rational &r) const\
    \ { return Rational(num * r.den, den * r.num); }\n Rational &operator+=(const\
    \ Rational &r) { return *this= *this + r; }\n Rational &operator-=(const Rational\
    \ &r) { return *this= *this - r; }\n Rational &operator*=(const Rational &r) {\
    \ return *this= *this * r; }\n Rational &operator/=(const Rational &r) { return\
    \ *this= *this / r; }\n constexpr bool operator==(const Rational &r) const {\n\
    \  if constexpr (reduction) return num == r.num && den == r.den;\n  else return\
    \ den == 0 && r.den == 0 ? num * r.num > 0 : num * r.den == den * r.num;\n }\n\
    \ constexpr bool operator!=(const Rational &r) const { return !(*this == r); }\n\
    \ constexpr bool operator<(const Rational &r) const {\n  if (den == 0 && r.den\
    \ == 0) return num < r.num;\n  else if (den == 0) return num < 0;\n  else if (r.den\
    \ == 0) return r.num > 0;\n  else return num * r.den < den * r.num;\n }\n constexpr\
    \ bool operator>(const Rational &r) const { return r < *this; }\n constexpr bool\
    \ operator<=(const Rational &r) const { return !(r < *this); }\n constexpr bool\
    \ operator>=(const Rational &r) const { return !(*this < r); }\n constexpr explicit\
    \ operator bool() const { return num != 0; }\n constexpr long double to_fp() const\
    \ { return (long double)num / den; }\n constexpr Int floor() const {\n  if constexpr\
    \ (reduction) return num < 0 ? -((-num + den - 1) / den) : num / den;\n  else\
    \ {\n   const Int n= num < 0 ? -num : num, d= den < 0 ? -den : den;\n   return\
    \ num * den < 0 ? -((n + d - 1) / d) : n / d;\n  }\n }\n std::string to_string()\
    \ const {\n  if (!num) return \"0\";\n  std::stringstream ss;\n  return ss <<\
    \ num << \"/\" << den, ss.str();\n }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const Rational &r) { return os << r.to_string(); }\n};\ntemplate <class\
    \ Int> struct std::numeric_limits<Rational<Int, false>> {\n static constexpr Rational<Int,\
    \ false> max() noexcept { return Rational<Int, false>(1, 0); }\n static constexpr\
    \ Rational<Int, false> min() noexcept { return Rational<Int, false>(1, std::numeric_limits<Int>::max());\
    \ }\n static constexpr Rational<Int, false> lowest() noexcept { return Rational<Int,\
    \ false>(-1, 0); }\n};\ntemplate <class Int> struct std::numeric_limits<Rational<Int,\
    \ true>> {\n static constexpr Rational<Int, true> max() noexcept { return Rational<Int,\
    \ true>(1, 0); }\n static constexpr Rational<Int, true> min() noexcept { return\
    \ Rational<Int, true>(1, std::numeric_limits<Int>::max()); }\n static constexpr\
    \ Rational<Int, true> lowest() noexcept { return Rational<Int, true>(-1, 0); }\n\
    };\n"
  code: "#pragma once\n#include <string>\n#include <limits>\n#include <sstream>\n\
    #include \"src/Math/binary_gcd.hpp\"\ntemplate <class Int, bool reduction= true>\
    \ struct Rational {\n Int num, den;\n constexpr Rational(Int num= 0, Int den=\
    \ 1): num(num), den(den) {\n  if (den < 0) num= -num, den= -den;\n  if constexpr\
    \ (reduction) reduce();\n }\n constexpr void reduce() {\n  const Int g= binary_gcd(num\
    \ < 0 ? -num : num, den);\n  num/= g, den/= g;\n }\n constexpr Rational operator-()\
    \ const { return Rational(-num, den); }\n constexpr Rational operator+(const Rational\
    \ &r) const { return Rational(num * r.den + den * r.num, den * r.den); }\n constexpr\
    \ Rational operator-(const Rational &r) const { return Rational(num * r.den -\
    \ den * r.num, den * r.den); }\n constexpr Rational operator*(const Rational &r)\
    \ const { return Rational(num * r.num, den * r.den); }\n constexpr Rational operator/(const\
    \ Rational &r) const { return Rational(num * r.den, den * r.num); }\n Rational\
    \ &operator+=(const Rational &r) { return *this= *this + r; }\n Rational &operator-=(const\
    \ Rational &r) { return *this= *this - r; }\n Rational &operator*=(const Rational\
    \ &r) { return *this= *this * r; }\n Rational &operator/=(const Rational &r) {\
    \ return *this= *this / r; }\n constexpr bool operator==(const Rational &r) const\
    \ {\n  if constexpr (reduction) return num == r.num && den == r.den;\n  else return\
    \ den == 0 && r.den == 0 ? num * r.num > 0 : num * r.den == den * r.num;\n }\n\
    \ constexpr bool operator!=(const Rational &r) const { return !(*this == r); }\n\
    \ constexpr bool operator<(const Rational &r) const {\n  if (den == 0 && r.den\
    \ == 0) return num < r.num;\n  else if (den == 0) return num < 0;\n  else if (r.den\
    \ == 0) return r.num > 0;\n  else return num * r.den < den * r.num;\n }\n constexpr\
    \ bool operator>(const Rational &r) const { return r < *this; }\n constexpr bool\
    \ operator<=(const Rational &r) const { return !(r < *this); }\n constexpr bool\
    \ operator>=(const Rational &r) const { return !(*this < r); }\n constexpr explicit\
    \ operator bool() const { return num != 0; }\n constexpr long double to_fp() const\
    \ { return (long double)num / den; }\n constexpr Int floor() const {\n  if constexpr\
    \ (reduction) return num < 0 ? -((-num + den - 1) / den) : num / den;\n  else\
    \ {\n   const Int n= num < 0 ? -num : num, d= den < 0 ? -den : den;\n   return\
    \ num * den < 0 ? -((n + d - 1) / d) : n / d;\n  }\n }\n std::string to_string()\
    \ const {\n  if (!num) return \"0\";\n  std::stringstream ss;\n  return ss <<\
    \ num << \"/\" << den, ss.str();\n }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const Rational &r) { return os << r.to_string(); }\n};\ntemplate <class\
    \ Int> struct std::numeric_limits<Rational<Int, false>> {\n static constexpr Rational<Int,\
    \ false> max() noexcept { return Rational<Int, false>(1, 0); }\n static constexpr\
    \ Rational<Int, false> min() noexcept { return Rational<Int, false>(1, std::numeric_limits<Int>::max());\
    \ }\n static constexpr Rational<Int, false> lowest() noexcept { return Rational<Int,\
    \ false>(-1, 0); }\n};\ntemplate <class Int> struct std::numeric_limits<Rational<Int,\
    \ true>> {\n static constexpr Rational<Int, true> max() noexcept { return Rational<Int,\
    \ true>(1, 0); }\n static constexpr Rational<Int, true> min() noexcept { return\
    \ Rational<Int, true>(1, std::numeric_limits<Int>::max()); }\n static constexpr\
    \ Rational<Int, true> lowest() noexcept { return Rational<Int, true>(-1, 0); }\n\
    };"
  dependsOn:
  - src/Math/binary_gcd.hpp
  isVerificationFile: false
  path: src/Math/Rational.hpp
  requiredBy: []
  timestamp: '2023-08-06 20:57:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1501.test.cpp
  - test/aoj/0350.test.cpp
  - test/unit_test/constexpr_rational.test.cpp
documentation_of: src/Math/Rational.hpp
layout: document
title: "\u6709\u7406\u6570 $\\mathbb{Q}$"
---

第二テンプレート引数を false にすると約分をサボる. デフォルトは　true.

## 問題例
[CPSCO2019 Session3 G - Grand Election](https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g)\
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (cht, doubleだとwa, __int128_t で reduction を false にして ac)