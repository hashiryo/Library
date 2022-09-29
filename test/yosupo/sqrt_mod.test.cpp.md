---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 $\\mathbb{F}_p$"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/mod_sqrt.hpp\"\n/**\n * @title\
    \ \u5E73\u65B9\u6839 $\\mathbb{F}_p$\n * @category \u6570\u5B66\n * O(log p)\n\
    \ */\n\n// BEGIN CUT HERE\n\nconstexpr std::int64_t sqrt(std::uint64_t a, std::uint64_t\
    \ p) {\n  if ((a %= p) <= 1 || p == 2) return a;\n  using u64 = std::uint64_t;\n\
    \  auto pow = [&p](u64 x, u64 k) {\n    for (u64 ret = 1;; x = (__uint128_t)x\
    \ * x % p)\n      if (k & 1 ? ret = (__uint128_t)ret * x % p : 0; !(k >>= 1))\
    \ return ret;\n  };\n  u64 e = (p - 1) >> 1, b = 0, D = p - a, ret = 1, r2 = 0,\
    \ b2 = 1;\n  if (pow(a, e) != 1) return -1;  // no solution\n  while (pow(D, e)\
    \ == 1) D -= p & -((D += (b++ << 1) | 1) >= p);\n  auto mult = [&D, &p](u64 &u1,\
    \ u64 &u2, u64 v1, u64 v2) {\n    u64 tmp = ((__uint128_t)u1 * v1 + (__uint128_t)u2\
    \ * v2 % p * D) % p;\n    u2 = ((__uint128_t)u1 * v2 + (__uint128_t)u2 * v1) %\
    \ p;\n    u1 = tmp - (p & -(tmp >= p)), u2 -= p & -(u2 >= p);\n  };\n  for (++e;;\
    \ mult(b, b2, b, b2)) {\n    if (e & 1) mult(ret, r2, b, b2);\n    if (!(e >>=\
    \ 1)) return std::min(ret, p - ret);\n  }\n}\n#line 4 \"test/yosupo/sqrt_mod.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  cin >> T;\n  while (T--) {\n    int Y, P;\n    cin >> Y >> P;\n \
    \   cout << sqrt(Y, P) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include <bits/stdc++.h>\n\
    #include \"src/Math/mod_sqrt.hpp\"\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin >> T;\n  while (T--)\
    \ {\n    int Y, P;\n    cin >> Y >> P;\n    cout << sqrt(Y, P) << '\\n';\n  }\n\
    \  return 0;\n}"
  dependsOn:
  - src/Math/mod_sqrt.hpp
  isVerificationFile: true
  path: test/yosupo/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2022-09-20 01:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_mod.test.cpp
- /verify/test/yosupo/sqrt_mod.test.cpp.html
title: test/yosupo/sqrt_mod.test.cpp
---
