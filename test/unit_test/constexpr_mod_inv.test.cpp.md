---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
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
  bundledCode: "#line 1 \"test/unit_test/constexpr_mod_inv.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n#line 2 \"\
    src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include <cassert>\ntemplate <class\
    \ Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 4 \"test/unit_test/constexpr_mod_inv.test.cpp\"\n\
    using namespace std;\nconstexpr auto f= mod_inv(2, 1000000007);\nstatic_assert(f\
    \ == 500000004);\nconstexpr auto g= mod_inv(3, 998244353);\nstatic_assert(g ==\
    \ 332748118);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int A, B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n\
    #include \"src/Math/mod_inv.hpp\"\nusing namespace std;\nconstexpr auto f= mod_inv(2,\
    \ 1000000007);\nstatic_assert(f == 500000004);\nconstexpr auto g= mod_inv(3, 998244353);\n\
    static_assert(g == 332748118);\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int A, B;\n cin >> A >> B;\n cout << A + B << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/mod_inv.hpp
  isVerificationFile: true
  path: test/unit_test/constexpr_mod_inv.test.cpp
  requiredBy: []
  timestamp: '2023-08-06 00:46:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit_test/constexpr_mod_inv.test.cpp
layout: document
redirect_from:
- /verify/test/unit_test/constexpr_mod_inv.test.cpp
- /verify/test/unit_test/constexpr_mod_inv.test.cpp.html
title: test/unit_test/constexpr_mod_inv.test.cpp
---
