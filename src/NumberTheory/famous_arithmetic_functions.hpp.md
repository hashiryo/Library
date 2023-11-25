---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.numth.test.cpp
    title: test/atcoder/abc172_d.numth.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_c.mul_sum.test.cpp
    title: test/atcoder/abc179_c.mul_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/famous_arithmetic_functions.hpp\"\n#include\
    \ <vector>\n#include <cstdint>\nnamespace famous_arithmetic_functions {\nnamespace\
    \ mul {\ntemplate <class T> struct Totient {\n static constexpr T f(uint64_t p,\
    \ short e) {\n  T ret= p - 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n }\n\
    \ static std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class T> struct\
    \ Moebius {\n static constexpr T f(uint64_t, short e) { return (e == 0) - (e ==\
    \ 1); }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class T>\
    \ struct Liouville {\n static constexpr T f(uint64_t, short e) { return e & 1\
    \ ? -1 : 1; }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class\
    \ T, uint64_t k> struct Divisor {\n static constexpr T f(uint64_t p, short e)\
    \ {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t kk= k; kk; kk>>= 1, b*=\
    \ b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <= e; i++, pkpw*= pk) ret+=\
    \ pkpw;\n  return ret;\n }\n static std::vector<T> poly() {\n  std::vector<T>\
    \ ret(k + 1, 0);\n  return ret[0]+= 1, ret[k]+= 1, ret;\n }\n};\ntemplate <class\
    \ T> struct Dedekind {\n static constexpr T f(uint64_t p, short e) {\n  T ret=\
    \ p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n }\n static std::vector<T>\
    \ poly() { return {1, 1}; }\n};\n}  // namespace mul\nnamespace add {\ntemplate\
    \ <class T> struct BigOmega {  // the total number of prime factors of n\n static\
    \ constexpr T f(uint64_t, short e) { return e; }\n static std::vector<T> poly()\
    \ { return {1}; }\n};\ntemplate <class T> struct LittleOmega {  // the total number\
    \ of different prime factors of n\n static constexpr T f(uint64_t, short) { return\
    \ 1; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T>\
    \ struct Sopfr {  // the sum of primes dividing n counting multiplicity\n static\
    \ constexpr T f(uint64_t p, short e) { return p * e; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\ntemplate <class T> struct Sopf {  // the sum\
    \ of the distinct primes dividing n\n static constexpr T f(uint64_t p, short)\
    \ { return p; }\n static std::vector<T> poly() { return {0, 1}; }\n};\n}  // namespace\
    \ add\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\nnamespace famous_arithmetic_functions\
    \ {\nnamespace mul {\ntemplate <class T> struct Totient {\n static constexpr T\
    \ f(uint64_t p, short e) {\n  T ret= p - 1;\n  while (e-- > 1) ret*= p;\n  return\
    \ ret;\n }\n static std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class\
    \ T> struct Moebius {\n static constexpr T f(uint64_t, short e) { return (e ==\
    \ 0) - (e == 1); }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T> struct Liouville {\n static constexpr T f(uint64_t, short e) { return\
    \ e & 1 ? -1 : 1; }\n static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T, uint64_t k> struct Divisor {\n static constexpr T f(uint64_t p, short\
    \ e) {\n  T ret= 0, pk= 1, pkpw= 1, b= p;\n  for (uint64_t kk= k; kk; kk>>= 1,\
    \ b*= b)\n   if (kk & 1) pk*= b;\n  for (short i= 0; i <= e; i++, pkpw*= pk) ret+=\
    \ pkpw;\n  return ret;\n }\n static std::vector<T> poly() {\n  std::vector<T>\
    \ ret(k + 1, 0);\n  return ret[0]+= 1, ret[k]+= 1, ret;\n }\n};\ntemplate <class\
    \ T> struct Dedekind {\n static constexpr T f(uint64_t p, short e) {\n  T ret=\
    \ p + 1;\n  while (e-- > 1) ret*= p;\n  return ret;\n }\n static std::vector<T>\
    \ poly() { return {1, 1}; }\n};\n}  // namespace mul\nnamespace add {\ntemplate\
    \ <class T> struct BigOmega {  // the total number of prime factors of n\n static\
    \ constexpr T f(uint64_t, short e) { return e; }\n static std::vector<T> poly()\
    \ { return {1}; }\n};\ntemplate <class T> struct LittleOmega {  // the total number\
    \ of different prime factors of n\n static constexpr T f(uint64_t, short) { return\
    \ 1; }\n static std::vector<T> poly() { return {1}; }\n};\ntemplate <class T>\
    \ struct Sopfr {  // the sum of primes dividing n counting multiplicity\n static\
    \ constexpr T f(uint64_t p, short e) { return p * e; }\n static std::vector<T>\
    \ poly() { return {0, 1}; }\n};\ntemplate <class T> struct Sopf {  // the sum\
    \ of the distinct primes dividing n\n static constexpr T f(uint64_t p, short)\
    \ { return p; }\n static std::vector<T> poly() { return {0, 1}; }\n};\n}  // namespace\
    \ add\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/famous_arithmetic_functions.hpp
  requiredBy: []
  timestamp: '2023-11-25 18:44:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/atcoder/abc179_c.mul_sum.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
documentation_of: src/NumberTheory/famous_arithmetic_functions.hpp
layout: document
title: "\u6709\u540D\u306A\u6570\u8AD6\u7684\u95A2\u6570"
---
## 参考
[https://en.wikipedia.org/wiki/Arithmetic_function](https://en.wikipedia.org/wiki/Arithmetic_function)