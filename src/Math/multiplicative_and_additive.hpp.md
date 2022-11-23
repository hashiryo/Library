---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.numth.test.cpp
    title: test/atcoder/abc172_d.numth.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
    title: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
    title: test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1019.test.cpp
    title: test/yukicoder/1019.test.cpp
  - icon: ':x:'
    path: test/yukicoder/644.test.cpp
    title: test/yukicoder/644.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
    links:
    - https://en.wikipedia.org/wiki/Arithmetic_function
  bundledCode: "#line 2 \"src/Math/multiplicative_and_additive.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570\
    \n * @category \u6570\u5B66\n * @see https://en.wikipedia.org/wiki/Arithmetic_function\n\
    \ */\n\n// BEGIN CUT HERE\n\nnamespace multiplicative_functions {\ntemplate <class\
    \ T>\nstruct Totient {\n  static constexpr T f(std::uint64_t p, short e) {\n \
    \   T ret = p - 1;\n    while (e-- > 1) ret *= p;\n    return ret;\n  }\n  static\
    \ std::vector<T> poly() { return {-1, 1}; }\n};\ntemplate <class T>\nstruct Moebius\
    \ {\n  static constexpr T f(std::uint64_t, short e) { return (e == 0) - (e ==\
    \ 1); }\n  static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class\
    \ T>\nstruct Liouville {\n  static constexpr T f(std::uint64_t, short e) { return\
    \ e & 1 ? -1 : 1; }\n  static std::vector<T> poly() { return {-1}; }\n};\ntemplate\
    \ <class T, std::uint64_t k>\nstruct Divisor {\n  static constexpr T f(std::uint64_t\
    \ p, short e) {\n    T ret = 0, pk = 1, pkpw = 1, b = p;\n    for (std::uint64_t\
    \ kk = k; kk; kk >>= 1, b *= b)\n      if (kk & 1) pk *= b;\n    for (short i\
    \ = 0; i <= e; i++, pkpw *= pk) ret += pkpw;\n    return ret;\n  }\n  static std::vector<T>\
    \ poly() {\n    std::vector<T> ret(k + 1, 0);\n    ret[0] += 1, ret[k] += 1;\n\
    \    return ret;\n  }\n};\ntemplate <class T>\nstruct Dedekind {\n  static constexpr\
    \ T f(std::uint64_t p, short e) {\n    T ret = p + 1;\n    while (e-- > 1) ret\
    \ *= p;\n    return ret;\n  }\n  static std::vector<T> poly() { return {1, 1};\
    \ }\n};\n}  // namespace multiplicative_functions\n\nnamespace additive_functions\
    \ {\n// the total number of prime factors of n\ntemplate <class T>\nstruct BigOmega\
    \ {\n  static constexpr T f(std::uint64_t, short e) { return e; }\n  static std::vector<T>\
    \ poly() { return {1}; }\n};\n// the total number of different prime factors of\
    \ n\ntemplate <class T>\nstruct LittleOmega {\n  static constexpr T f(std::uint64_t,\
    \ short) { return 1; }\n  static std::vector<T> poly() { return {1}; }\n};\n//\
    \ the sum of primes dividing n counting multiplicity\ntemplate <class T>\nstruct\
    \ Sopfr {\n  static constexpr T f(std::uint64_t p, short e) { return p * e; }\n\
    \  static std::vector<T> poly() { return {0, 1}; }\n};\n// the sum of the distinct\
    \ primes dividing n\ntemplate <class T>\nstruct Sopf {\n  static constexpr T f(std::uint64_t\
    \ p, short) { return p; }\n  static std::vector<T> poly() { return {0, 1}; }\n\
    };\n}  // namespace additive_functions\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u4E57\u6CD5\u7684\
    \u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570\n * @category \u6570\u5B66\n\
    \ * @see https://en.wikipedia.org/wiki/Arithmetic_function\n */\n\n// BEGIN CUT\
    \ HERE\n\nnamespace multiplicative_functions {\ntemplate <class T>\nstruct Totient\
    \ {\n  static constexpr T f(std::uint64_t p, short e) {\n    T ret = p - 1;\n\
    \    while (e-- > 1) ret *= p;\n    return ret;\n  }\n  static std::vector<T>\
    \ poly() { return {-1, 1}; }\n};\ntemplate <class T>\nstruct Moebius {\n  static\
    \ constexpr T f(std::uint64_t, short e) { return (e == 0) - (e == 1); }\n  static\
    \ std::vector<T> poly() { return {-1}; }\n};\ntemplate <class T>\nstruct Liouville\
    \ {\n  static constexpr T f(std::uint64_t, short e) { return e & 1 ? -1 : 1; }\n\
    \  static std::vector<T> poly() { return {-1}; }\n};\ntemplate <class T, std::uint64_t\
    \ k>\nstruct Divisor {\n  static constexpr T f(std::uint64_t p, short e) {\n \
    \   T ret = 0, pk = 1, pkpw = 1, b = p;\n    for (std::uint64_t kk = k; kk; kk\
    \ >>= 1, b *= b)\n      if (kk & 1) pk *= b;\n    for (short i = 0; i <= e; i++,\
    \ pkpw *= pk) ret += pkpw;\n    return ret;\n  }\n  static std::vector<T> poly()\
    \ {\n    std::vector<T> ret(k + 1, 0);\n    ret[0] += 1, ret[k] += 1;\n    return\
    \ ret;\n  }\n};\ntemplate <class T>\nstruct Dedekind {\n  static constexpr T f(std::uint64_t\
    \ p, short e) {\n    T ret = p + 1;\n    while (e-- > 1) ret *= p;\n    return\
    \ ret;\n  }\n  static std::vector<T> poly() { return {1, 1}; }\n};\n}  // namespace\
    \ multiplicative_functions\n\nnamespace additive_functions {\n// the total number\
    \ of prime factors of n\ntemplate <class T>\nstruct BigOmega {\n  static constexpr\
    \ T f(std::uint64_t, short e) { return e; }\n  static std::vector<T> poly() {\
    \ return {1}; }\n};\n// the total number of different prime factors of n\ntemplate\
    \ <class T>\nstruct LittleOmega {\n  static constexpr T f(std::uint64_t, short)\
    \ { return 1; }\n  static std::vector<T> poly() { return {1}; }\n};\n// the sum\
    \ of primes dividing n counting multiplicity\ntemplate <class T>\nstruct Sopfr\
    \ {\n  static constexpr T f(std::uint64_t p, short e) { return p * e; }\n  static\
    \ std::vector<T> poly() { return {0, 1}; }\n};\n// the sum of the distinct primes\
    \ dividing n\ntemplate <class T>\nstruct Sopf {\n  static constexpr T f(std::uint64_t\
    \ p, short) { return p; }\n  static std::vector<T> poly() { return {0, 1}; }\n\
    };\n}  // namespace additive_functions\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/multiplicative_and_additive.hpp
  requiredBy: []
  timestamp: '2022-09-10 14:49:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  - test/yosupo/sum_of_totient_function.mul_sum.test.cpp
  - test/atcoder/abc172_d.numth.test.cpp
  - test/yukicoder/644.test.cpp
  - test/yukicoder/1019.test.cpp
documentation_of: src/Math/multiplicative_and_additive.hpp
layout: document
redirect_from:
- /library/src/Math/multiplicative_and_additive.hpp
- /library/src/Math/multiplicative_and_additive.hpp.html
title: "\u4E57\u6CD5\u7684\u95A2\u6570\u30FB\u52A0\u6CD5\u7684\u95A2\u6570"
---
