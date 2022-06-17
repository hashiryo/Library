---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
    links:
    - https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f
  bundledCode: "#line 2 \"src/Math/totient.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\n * @category \u6570\
    \u5B66\n *  O(\u221AN)\n * \u3064\u3044\u3067\u306B\u30C6\u30C8\u30EC\u30FC\u30B7\
    \u30E7\u30F3\n */\n// verify\u7528:\n// https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f\n\
    \n// BEGIN CUT HERE\n\nlong long totient(long long n) {\n  long long ret = n;\n\
    \  for (long long p = 2; p * p <= n; p++)\n    if (n % p == 0)\n      for (ret\
    \ -= ret / p; n % p == 0;) n /= p;\n  return n > 1 ? ret - (ret / n) : ret;\n\
    }\n\n// a\u2191\u2191b = a^(a^(a^...))\nlong long tetration(long long a, long\
    \ long b, long long mod) {\n  auto rec = [&](auto f, long long c, long long d,\
    \ long long m) -> long long {\n    auto MOD = [&](long long x) { return x < m\
    \ ? x : x % m + m; };\n    if (c == 0) return MOD((d + 1) & 1);\n    if (d ==\
    \ 0 || m == 1) return MOD(1);\n    long long ret = MOD(1), e = f(f, c, d - 1,\
    \ totient(m));\n    for (c = MOD(c); e; e >>= 1, c = MOD(c * c))\n      if (e\
    \ & 1) ret = MOD(ret * c);\n    return ret;\n  };\n  return rec(rec, a, b, mod)\
    \ % mod;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u30C8\u30FC\u30B7\
    \u30A7\u30F3\u30C8\u95A2\u6570\n * @category \u6570\u5B66\n *  O(\u221AN)\n *\
    \ \u3064\u3044\u3067\u306B\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\n */\n//\
    \ verify\u7528:\n// https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f\n\
    \n// BEGIN CUT HERE\n\nlong long totient(long long n) {\n  long long ret = n;\n\
    \  for (long long p = 2; p * p <= n; p++)\n    if (n % p == 0)\n      for (ret\
    \ -= ret / p; n % p == 0;) n /= p;\n  return n > 1 ? ret - (ret / n) : ret;\n\
    }\n\n// a\u2191\u2191b = a^(a^(a^...))\nlong long tetration(long long a, long\
    \ long b, long long mod) {\n  auto rec = [&](auto f, long long c, long long d,\
    \ long long m) -> long long {\n    auto MOD = [&](long long x) { return x < m\
    \ ? x : x % m + m; };\n    if (c == 0) return MOD((d + 1) & 1);\n    if (d ==\
    \ 0 || m == 1) return MOD(1);\n    long long ret = MOD(1), e = f(f, c, d - 1,\
    \ totient(m));\n    for (c = MOD(c); e; e >>= 1, c = MOD(c * c))\n      if (e\
    \ & 1) ret = MOD(ret * c);\n    return ret;\n  };\n  return rec(rec, a, b, mod)\
    \ % mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/totient.hpp
  requiredBy: []
  timestamp: '2021-11-23 16:32:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tetration_mod.test.cpp
  - test/aoj/NTL_1_D.test.cpp
documentation_of: src/Math/totient.hpp
layout: document
redirect_from:
- /library/src/Math/totient.hpp
- /library/src/Math/totient.hpp.html
title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
---
