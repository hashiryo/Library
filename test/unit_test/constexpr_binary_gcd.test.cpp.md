---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"test/unit_test/constexpr_binary_gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n#line\
    \ 2 \"src/Math/binary_gcd.hpp\"\n#include <type_traits>\n#include <algorithm>\n\
    #include <cstdint>\ntemplate <class Int> constexpr int bsf(Int a) {\n if constexpr\
    \ (sizeof(Int) == 16) {\n  uint64_t lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n } else if constexpr (sizeof(Int) == 8) return\
    \ __builtin_ctzll(a);\n else return __builtin_ctz(a);\n}\ntemplate <class Int>\
    \ constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0 || b == 0) return a +\
    \ b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int\
    \ d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n\
    \ }\n return a << std::min(n, m);\n}\n#line 4 \"test/unit_test/constexpr_binary_gcd.test.cpp\"\
    \nusing namespace std;\nconstexpr auto f= binary_gcd(2, 4);\nstatic_assert(f ==\
    \ 2);\nconstexpr auto g= binary_gcd(1000000007, 1000000009);\nstatic_assert(g\
    \ == 1);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int A,\
    \ B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n\
    #include \"src/Math/binary_gcd.hpp\"\nusing namespace std;\nconstexpr auto f=\
    \ binary_gcd(2, 4);\nstatic_assert(f == 2);\nconstexpr auto g= binary_gcd(1000000007,\
    \ 1000000009);\nstatic_assert(g == 1);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int A, B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/binary_gcd.hpp
  isVerificationFile: true
  path: test/unit_test/constexpr_binary_gcd.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 16:02:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit_test/constexpr_binary_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/unit_test/constexpr_binary_gcd.test.cpp
- /verify/test/unit_test/constexpr_binary_gcd.test.cpp.html
title: test/unit_test/constexpr_binary_gcd.test.cpp
---
