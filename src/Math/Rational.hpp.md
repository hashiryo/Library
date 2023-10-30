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
    path: test/aoj/1242.rational.test.cpp
    title: test/aoj/1242.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2003.rational.test.cpp
    title: test/aoj/2003.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2009.rational.test.cpp
    title: test/aoj/2009.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2159.rational.test.cpp
    title: test/aoj/2159.rational.test.cpp
  - icon: ':x:'
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
    #include <algorithm>\n#include <cstdint>\ntemplate <class Int> constexpr int bsf(Int\
    \ a) {\n if constexpr (sizeof(Int) == 16) {\n  uint64_t lo= a & uint64_t(-1);\n\
    \  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);\n } else if\
    \ constexpr (sizeof(Int) == 8) return __builtin_ctzll(a);\n else return __builtin_ctz(a);\n\
    }\ntemplate <class Int> constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0\
    \ || b == 0) return a + b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>=\
    \ m; a != b;) {\n  Int d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a,\
    \ a= (f ? d : -d) >> s;\n }\n return a << std::min(n, m);\n}\n#line 6 \"src/Math/Rational.hpp\"\
    \ntemplate <class Int, bool reduction= true> struct Rational {\n Int num, den;\n\
    \ constexpr Rational(): num(0), den(1) {}\n constexpr Rational(Int n, Int d= 1):\
    \ num(n), den(d) {\n  if (den < 0) num= -num, den= -den;\n  if constexpr (reduction)\
    \ reduce(num, den);\n }\n constexpr Rational(const std::string &str) {\n  auto\
    \ it= str.find(\"/\");\n  if (it == std::string::npos) num= std::stoi(str), den=\
    \ 1;\n  else num= std::stoi(str.substr(0, it)), den= std::stoi(str.substr(it +\
    \ 1));\n  if constexpr (reduction) reduce(num, den);\n }\n static constexpr void\
    \ reduce(Int &a, Int &b) {\n  const Int g= binary_gcd(a < 0 ? -a : a, b);\n  a/=\
    \ g, b/= g;\n }\n static constexpr Rational raw(Int n, Int d) {\n  Rational ret;\n\
    \  return ret.num= n, ret.den= d, ret;\n }\n constexpr Rational operator-() const\
    \ { return raw(-num, den); }\n constexpr Rational operator+(const Rational &r)\
    \ const { return Rational(num * r.den + den * r.num, den * r.den); }\n constexpr\
    \ Rational operator-(const Rational &r) const { return Rational(num * r.den -\
    \ den * r.num, den * r.den); }\n constexpr Rational operator*(const Rational &r)\
    \ const {\n  if constexpr (reduction) {\n   Int ln= num, ld= den, rn= r.num, rd=\
    \ r.den;\n   return reduce(ln, rd), reduce(rn, ld), raw(ln * rn, ld * rd);\n \
    \ } else return Rational(num * r.num, den * r.den);\n }\n constexpr Rational operator/(const\
    \ Rational &r) const {\n  if constexpr (reduction) {\n   Int ln= num, ld= den,\
    \ rn= r.num, rd= r.den;\n   if (rn < 0) rd= -rd, rn= -rn;\n   return reduce(ln,\
    \ rn), reduce(rd, ld), raw(ln * rd, ld * rn);\n  } else return Rational(num *\
    \ r.den, den * r.num);\n }\n Rational &operator+=(const Rational &r) { return\
    \ *this= *this + r; }\n Rational &operator-=(const Rational &r) { return *this=\
    \ *this - r; }\n Rational &operator*=(const Rational &r) { return *this= *this\
    \ * r; }\n Rational &operator/=(const Rational &r) { return *this= *this / r;\
    \ }\n constexpr bool operator==(const Rational &r) const {\n  if constexpr (reduction)\
    \ return num == r.num && den == r.den;\n  else return den == 0 && r.den == 0 ?\
    \ num * r.num > 0 : num * r.den == den * r.num;\n }\n constexpr bool operator!=(const\
    \ Rational &r) const { return !(*this == r); }\n constexpr bool operator<(const\
    \ Rational &r) const {\n  if (den == 0 && r.den == 0) return num < r.num;\n  else\
    \ if (den == 0) return num < 0;\n  else if (r.den == 0) return r.num > 0;\n  else\
    \ return num * r.den < den * r.num;\n }\n constexpr bool operator>(const Rational\
    \ &r) const { return r < *this; }\n constexpr bool operator<=(const Rational &r)\
    \ const { return !(r < *this); }\n constexpr bool operator>=(const Rational &r)\
    \ const { return !(*this < r); }\n constexpr explicit operator bool() const {\
    \ return num != 0; }\n constexpr long double to_fp() const { return (long double)num\
    \ / den; }\n constexpr explicit operator long double() const { return to_fp();\
    \ }\n constexpr explicit operator double() const { return to_fp(); }\n constexpr\
    \ explicit operator float() const { return to_fp(); }\n constexpr Int floor()\
    \ const { return num < 0 ? -((-num + den - 1) / den) : num / den; }\n constexpr\
    \ Int ceil() const { return num < 0 ? -(-num / den) : (num + den - 1) / den; }\n\
    \ constexpr Rational abs() const { return raw(num < 0 ? -num : num, den); }\n\
    \ constexpr friend Int floor(const Rational &r) { return r.floor(); }\n constexpr\
    \ friend Int ceil(const Rational &r) { return r.ceil(); }\n constexpr friend Rational\
    \ abs(const Rational &r) { return r.abs(); }\n std::string to_string() const {\n\
    \  if (!num) return \"0\";\n  std::stringstream ss;\n  if (den == 1) return ss\
    \ << num, ss.str();\n  return ss << num << \"/\" << den, ss.str();\n }\n friend\
    \ std::istream &operator>>(std::istream &is, Rational &r) {\n  std::string s;\n\
    \  if (is >> s; s != \"\") r= Rational(s);\n  return is;\n }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const Rational &r) { return os << r.to_string();\
    \ }\n};\ntemplate <class Int, bool reduction> struct std::numeric_limits<Rational<Int,\
    \ reduction>> {\n static constexpr Rational<Int, reduction> max() noexcept { return\
    \ Rational<Int, reduction>(1, 0); }\n static constexpr Rational<Int, reduction>\
    \ min() noexcept { return Rational<Int, reduction>(1, std::numeric_limits<Int>::max());\
    \ }\n static constexpr Rational<Int, reduction> lowest() noexcept { return Rational<Int,\
    \ reduction>(-1, 0); }\n};\n"
  code: "#pragma once\n#include <string>\n#include <limits>\n#include <sstream>\n\
    #include \"src/Math/binary_gcd.hpp\"\ntemplate <class Int, bool reduction= true>\
    \ struct Rational {\n Int num, den;\n constexpr Rational(): num(0), den(1) {}\n\
    \ constexpr Rational(Int n, Int d= 1): num(n), den(d) {\n  if (den < 0) num= -num,\
    \ den= -den;\n  if constexpr (reduction) reduce(num, den);\n }\n constexpr Rational(const\
    \ std::string &str) {\n  auto it= str.find(\"/\");\n  if (it == std::string::npos)\
    \ num= std::stoi(str), den= 1;\n  else num= std::stoi(str.substr(0, it)), den=\
    \ std::stoi(str.substr(it + 1));\n  if constexpr (reduction) reduce(num, den);\n\
    \ }\n static constexpr void reduce(Int &a, Int &b) {\n  const Int g= binary_gcd(a\
    \ < 0 ? -a : a, b);\n  a/= g, b/= g;\n }\n static constexpr Rational raw(Int n,\
    \ Int d) {\n  Rational ret;\n  return ret.num= n, ret.den= d, ret;\n }\n constexpr\
    \ Rational operator-() const { return raw(-num, den); }\n constexpr Rational operator+(const\
    \ Rational &r) const { return Rational(num * r.den + den * r.num, den * r.den);\
    \ }\n constexpr Rational operator-(const Rational &r) const { return Rational(num\
    \ * r.den - den * r.num, den * r.den); }\n constexpr Rational operator*(const\
    \ Rational &r) const {\n  if constexpr (reduction) {\n   Int ln= num, ld= den,\
    \ rn= r.num, rd= r.den;\n   return reduce(ln, rd), reduce(rn, ld), raw(ln * rn,\
    \ ld * rd);\n  } else return Rational(num * r.num, den * r.den);\n }\n constexpr\
    \ Rational operator/(const Rational &r) const {\n  if constexpr (reduction) {\n\
    \   Int ln= num, ld= den, rn= r.num, rd= r.den;\n   if (rn < 0) rd= -rd, rn= -rn;\n\
    \   return reduce(ln, rn), reduce(rd, ld), raw(ln * rd, ld * rn);\n  } else return\
    \ Rational(num * r.den, den * r.num);\n }\n Rational &operator+=(const Rational\
    \ &r) { return *this= *this + r; }\n Rational &operator-=(const Rational &r) {\
    \ return *this= *this - r; }\n Rational &operator*=(const Rational &r) { return\
    \ *this= *this * r; }\n Rational &operator/=(const Rational &r) { return *this=\
    \ *this / r; }\n constexpr bool operator==(const Rational &r) const {\n  if constexpr\
    \ (reduction) return num == r.num && den == r.den;\n  else return den == 0 &&\
    \ r.den == 0 ? num * r.num > 0 : num * r.den == den * r.num;\n }\n constexpr bool\
    \ operator!=(const Rational &r) const { return !(*this == r); }\n constexpr bool\
    \ operator<(const Rational &r) const {\n  if (den == 0 && r.den == 0) return num\
    \ < r.num;\n  else if (den == 0) return num < 0;\n  else if (r.den == 0) return\
    \ r.num > 0;\n  else return num * r.den < den * r.num;\n }\n constexpr bool operator>(const\
    \ Rational &r) const { return r < *this; }\n constexpr bool operator<=(const Rational\
    \ &r) const { return !(r < *this); }\n constexpr bool operator>=(const Rational\
    \ &r) const { return !(*this < r); }\n constexpr explicit operator bool() const\
    \ { return num != 0; }\n constexpr long double to_fp() const { return (long double)num\
    \ / den; }\n constexpr explicit operator long double() const { return to_fp();\
    \ }\n constexpr explicit operator double() const { return to_fp(); }\n constexpr\
    \ explicit operator float() const { return to_fp(); }\n constexpr Int floor()\
    \ const { return num < 0 ? -((-num + den - 1) / den) : num / den; }\n constexpr\
    \ Int ceil() const { return num < 0 ? -(-num / den) : (num + den - 1) / den; }\n\
    \ constexpr Rational abs() const { return raw(num < 0 ? -num : num, den); }\n\
    \ constexpr friend Int floor(const Rational &r) { return r.floor(); }\n constexpr\
    \ friend Int ceil(const Rational &r) { return r.ceil(); }\n constexpr friend Rational\
    \ abs(const Rational &r) { return r.abs(); }\n std::string to_string() const {\n\
    \  if (!num) return \"0\";\n  std::stringstream ss;\n  if (den == 1) return ss\
    \ << num, ss.str();\n  return ss << num << \"/\" << den, ss.str();\n }\n friend\
    \ std::istream &operator>>(std::istream &is, Rational &r) {\n  std::string s;\n\
    \  if (is >> s; s != \"\") r= Rational(s);\n  return is;\n }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const Rational &r) { return os << r.to_string();\
    \ }\n};\ntemplate <class Int, bool reduction> struct std::numeric_limits<Rational<Int,\
    \ reduction>> {\n static constexpr Rational<Int, reduction> max() noexcept { return\
    \ Rational<Int, reduction>(1, 0); }\n static constexpr Rational<Int, reduction>\
    \ min() noexcept { return Rational<Int, reduction>(1, std::numeric_limits<Int>::max());\
    \ }\n static constexpr Rational<Int, reduction> lowest() noexcept { return Rational<Int,\
    \ reduction>(-1, 0); }\n};"
  dependsOn:
  - src/Math/binary_gcd.hpp
  isVerificationFile: false
  path: src/Math/Rational.hpp
  requiredBy: []
  timestamp: '2023-10-30 16:02:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2009.rational.test.cpp
  - test/aoj/1242.rational.test.cpp
  - test/aoj/0350.test.cpp
  - test/aoj/2003.rational.test.cpp
  - test/aoj/2159.rational.test.cpp
  - test/unit_test/constexpr_rational.test.cpp
  - test/yukicoder/1501.test.cpp
documentation_of: src/Math/Rational.hpp
layout: document
title: "\u6709\u7406\u6570 $\\mathbb{Q}$"
---

第二テンプレート引数を false にすると約分をサボる. デフォルトは　true.

## 問題例
[CPSCO2019 Session3 G - Grand Election](https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g)\
[Yandex Contest Алгоритм 2022 K. Stepwise subsequence ](https://contest.yandex.com/contest/42710/problems/K) (cht, doubleだとwa, __int128_t で reduction を false にして ac)