---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/totient.hpp
    title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/totient.hpp\"\n/**\n * @title \u30C8\
    \u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\n * @category \u6570\u5B66\n *  O(\u221A\
    N)\n * \u3064\u3044\u3067\u306B\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\n */\n\
    // verify\u7528:\n// https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f\n\
    \n// BEGIN CUT HERE\n\nlong long totient(long long n) {\n  long long ret = n;\n\
    \  for (long long p = 2; p * p <= n; p++)\n    if (n % p == 0) {\n      ret -=\
    \ ret / p;\n      while (n % p == 0) n /= p;\n    }\n  if (n > 1) ret -= ret /\
    \ n;\n  return ret;\n}\n\n// a\u2191\u2191b = a^(a^(a^...))\nlong long tetration(long\
    \ long a, long long b, long long mod) {\n  auto rec = [&](auto f, long long c,\
    \ long long d, long long m) -> long long {\n    auto MOD = [&](long long x) {\
    \ return x < m ? x : x % m + m; };\n    if (c == 0) return MOD((d + 1) & 1);\n\
    \    if (d == 0 || m == 1) return MOD(1);\n    long long ret = MOD(1), e = f(f,\
    \ c, d - 1, totient(m));\n    for (c = MOD(c); e; e >>= 1, c = MOD(c * c))\n \
    \     if (e & 1) ret = MOD(ret * c);\n    return ret;\n  };\n  return rec(rec,\
    \ a, b, mod) % mod;\n}\n#line 5 \"test/aoj/NTL_1_D.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long\
    \ long n;\n  cin >> n;\n  cout << totient(n) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/totient.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long\
    \ long n;\n  cin >> n;\n  cout << totient(n) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - src/Math/totient.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---
