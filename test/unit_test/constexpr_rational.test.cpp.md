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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    };\n#line 4 \"test/unit_test/constexpr_rational.test.cpp\"\nusing namespace std;\n\
    using Q= Rational<__int128_t>;\nconstexpr auto x= Q(2, 3), y= Q(4, 3);\nconstexpr\
    \ auto a= x + y;\nstatic_assert(a == 2);\nconstexpr auto b= x - y;\nstatic_assert(b\
    \ == Q(-2, 3));\nconstexpr auto c= x * y;\nstatic_assert(c == Q(8, 9));\nconstexpr\
    \ auto d= x / y;\nstatic_assert(d == Q(1, 2));\nconstexpr auto e= -x;\nstatic_assert(e\
    \ == Q(-2, 3));\nconstexpr auto f= y.floor();\nstatic_assert(f == 1);\nconstexpr\
    \ auto g= b.floor();\nstatic_assert(g == -1);\nstatic_assert(x < y == true);\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int A, B;\n cin\
    \ >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}\n"
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
  timestamp: '2023-08-06 20:57:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit_test/constexpr_rational.test.cpp
layout: document
redirect_from:
- /verify/test/unit_test/constexpr_rational.test.cpp
- /verify/test/unit_test/constexpr_rational.test.cpp.html
title: test/unit_test/constexpr_rational.test.cpp
---
