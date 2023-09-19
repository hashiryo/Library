---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Rational.hpp
    title: "\u6709\u7406\u6570 $\\mathbb{Q}$"
  - icon: ':question:'
    path: src/Math/binary_gcd.hpp
    title: Binary GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unit_test/constexpr_rational.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n#line 2 \"\
    src/Math/Rational.hpp\"\n#include <string>\n#include <limits>\n#include <sstream>\n\
    #line 2 \"src/Math/binary_gcd.hpp\"\n#include <type_traits>\n#include <algorithm>\n\
    template <class Int> constexpr int bsf(Int a) {\n if constexpr (sizeof(Int) ==\
    \ 16) {\n  uint64_t lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo) :\
    \ 64 + __builtin_ctzll(a >> 64);\n } else if constexpr (sizeof(Int) == 8) return\
    \ __builtin_ctzll(a);\n else return __builtin_ctz(a);\n}\ntemplate <class Int>\
    \ constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0 || b == 0) return a +\
    \ b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int\
    \ d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n\
    \ }\n return a << std::min(n, m);\n}\n#line 6 \"src/Math/Rational.hpp\"\ntemplate\
    \ <class Int, bool reduction= true> struct Rational {\n Int num, den;\n constexpr\
    \ Rational(): num(0), den(1) {}\n constexpr Rational(Int n, Int d= 1): num(n),\
    \ den(d) {\n  if (den < 0) num= -num, den= -den;\n  if constexpr (reduction) reduce(num,\
    \ den);\n }\n constexpr Rational(const std::string &str) {\n  auto it= str.find(\"\
    /\");\n  if (it == std::string::npos) num= std::stoi(str), den= 1;\n  else num=\
    \ std::stoi(str.substr(0, it)), den= std::stoi(str.substr(it + 1));\n  if constexpr\
    \ (reduction) reduce(num, den);\n }\n static constexpr void reduce(Int &a, Int\
    \ &b) {\n  const Int g= binary_gcd(a < 0 ? -a : a, b);\n  a/= g, b/= g;\n }\n\
    \ static constexpr Rational raw(Int n, Int d) {\n  Rational ret;\n  return ret.num=\
    \ n, ret.den= d, ret;\n }\n constexpr Rational operator-() const { return raw(-num,\
    \ den); }\n constexpr Rational operator+(const Rational &r) const { return Rational(num\
    \ * r.den + den * r.num, den * r.den); }\n constexpr Rational operator-(const\
    \ Rational &r) const { return Rational(num * r.den - den * r.num, den * r.den);\
    \ }\n constexpr Rational operator*(const Rational &r) const {\n  if constexpr\
    \ (reduction) {\n   Int ln= num, ld= den, rn= r.num, rd= r.den;\n   return reduce(ln,\
    \ rd), reduce(rn, ld), raw(ln * rn, ld * rd);\n  } else return Rational(num *\
    \ r.num, den * r.den);\n }\n constexpr Rational operator/(const Rational &r) const\
    \ {\n  if constexpr (reduction) {\n   Int ln= num, ld= den, rn= r.num, rd= r.den;\n\
    \   if (rn < 0) rd= -rd, rn= -rn;\n   return reduce(ln, rn), reduce(rd, ld), raw(ln\
    \ * rd, ld * rn);\n  } else return Rational(num * r.den, den * r.num);\n }\n Rational\
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
    \ { return (long double)num / den; }\n constexpr explicit operator long double()\
    \ const { return to_fp(); }\n constexpr explicit operator double() const { return\
    \ to_fp(); }\n constexpr explicit operator float() const { return to_fp(); }\n\
    \ constexpr Int floor() const { return num < 0 ? -((-num + den - 1) / den) : num\
    \ / den; }\n constexpr Int ceil() const { return num < 0 ? -(-num / den) : (num\
    \ + den - 1) / den; }\n constexpr Rational abs() const { return raw(num < 0 ?\
    \ -num : num, den); }\n constexpr friend Int floor(const Rational &r) { return\
    \ r.floor(); }\n constexpr friend Int ceil(const Rational &r) { return r.ceil();\
    \ }\n constexpr friend Rational abs(const Rational &r) { return r.abs(); }\n std::string\
    \ to_string(bool frac_force= false) const {\n  if (!num) return frac_force ? \"\
    0/1\" : \"0\";\n  std::stringstream ss;\n  if (!frac_force && den == 1) return\
    \ ss << num, ss.str();\n  return ss << num << \"/\" << den, ss.str();\n }\n friend\
    \ std::istream &operator>>(std::istream &is, Rational &r) {\n  std::string s;\n\
    \  if (is >> s; s != \"\") r= Rational(s);\n  return is;\n }\n friend std::ostream\
    \ &operator<<(std::ostream &os, const Rational &r) { return os << r.to_string();\
    \ }\n};\ntemplate <class Int, bool reduction> struct std::numeric_limits<Rational<Int,\
    \ reduction>> {\n static constexpr Rational<Int, reduction> max() noexcept { return\
    \ Rational<Int, reduction>(1, 0); }\n static constexpr Rational<Int, reduction>\
    \ min() noexcept { return Rational<Int, reduction>(1, std::numeric_limits<Int>::max());\
    \ }\n static constexpr Rational<Int, reduction> lowest() noexcept { return Rational<Int,\
    \ reduction>(-1, 0); }\n};\n#line 4 \"test/unit_test/constexpr_rational.test.cpp\"\
    \nusing namespace std;\nusing Q= Rational<__int128_t>;\nconstexpr auto x= Q(2,\
    \ 3), y= Q(4, 3);\nconstexpr auto a= x + y;\nstatic_assert(a == 2);\nconstexpr\
    \ auto b= x - y;\nstatic_assert(b == Q(-2, 3));\nconstexpr auto c= x * y;\nstatic_assert(c\
    \ == Q(8, 9));\nconstexpr auto d= x / y;\nstatic_assert(d == Q(1, 2));\nconstexpr\
    \ auto e= -x;\nstatic_assert(e == Q(-2, 3));\nconstexpr auto f= y.floor();\nstatic_assert(f\
    \ == 1);\nconstexpr auto g= b.floor();\nstatic_assert(g == -1);\nstatic_assert(x\
    \ < y == true);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int A, B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n\
    #include \"src/Math/Rational.hpp\"\nusing namespace std;\nusing Q= Rational<__int128_t>;\n\
    constexpr auto x= Q(2, 3), y= Q(4, 3);\nconstexpr auto a= x + y;\nstatic_assert(a\
    \ == 2);\nconstexpr auto b= x - y;\nstatic_assert(b == Q(-2, 3));\nconstexpr auto\
    \ c= x * y;\nstatic_assert(c == Q(8, 9));\nconstexpr auto d= x / y;\nstatic_assert(d\
    \ == Q(1, 2));\nconstexpr auto e= -x;\nstatic_assert(e == Q(-2, 3));\nconstexpr\
    \ auto f= y.floor();\nstatic_assert(f == 1);\nconstexpr auto g= b.floor();\nstatic_assert(g\
    \ == -1);\nstatic_assert(x < y == true);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int A, B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/Rational.hpp
  - src/Math/binary_gcd.hpp
  isVerificationFile: true
  path: test/unit_test/constexpr_rational.test.cpp
  requiredBy: []
  timestamp: '2023-09-19 22:38:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit_test/constexpr_rational.test.cpp
layout: document
redirect_from:
- /verify/test/unit_test/constexpr_rational.test.cpp
- /verify/test/unit_test/constexpr_rational.test.cpp.html
title: test/unit_test/constexpr_rational.test.cpp
---
