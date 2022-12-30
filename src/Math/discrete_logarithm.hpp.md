---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
    links: []
  bundledCode: "#line 2 \"src/Math/discrete_logarithm.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n  Int x= 1, y= 0, b=\
    \ mod;\n  for (Int q= 0, z= 0, c= 0; b;)\n    z= x, c= a, x= y, y= z - y * (q=\
    \ a / b), a= b, b= c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x) % mod\
    \ : x % mod;\n}\n#line 4 \"src/Math/discrete_logarithm.hpp\"\n/**\n * @title \u96E2\
    \u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n *\
    \ O(\u221Amod)\n */\n\n// BEGIN CUT HERE\nint discrete_logarithm(int a, int b,\
    \ int mod) {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 :\
    \ -1);\n  auto mul = [&mod](int &x, int y) { x = (std::uint64_t)x * y % mod; };\n\
    \  int cnt = 0;\n  for (int g = 0;; cnt++, b /= g, mod /= g, mul(b, mod_inv<int>(a\
    \ / g, mod))) {\n    if ((b == 1) || (mod == 1)) return cnt;\n    if ((g = std::gcd(a,\
    \ mod)) == 1) break;\n    if (b % g != 0) return -1;  // no solution\n  }\n  int\
    \ baby = 1, size = 1 << std::__lg(int(std::sqrt(mod)) + 1), mask = size - 1,\n\
    \      vs[size][2];\n  std::vector<int> os(size + 1);\n  for (int i = 0; i < size;\
    \ i++, mul(baby, a)) os[baby & mask]++;\n  for (int i = 1; i < size; i++) os[i]\
    \ += os[i - 1];\n  os[size] = size, baby = 1;\n  for (int i = 0, j = 0; i < size;\
    \ i++, mul(baby, a))\n    j = --os[baby & mask], vs[j][0] = baby, vs[j][1] = i;\n\
    \  for (int t = 0, iv = mod_inv<int>(baby, mod); t < mod; t += size, mul(b, iv))\n\
    \    for (int m = (b & mask), i = os[m + 1]; i-- > os[m];)\n      if (b == vs[i][0])\
    \ return cnt + vs[i][1] + t;\n  return -1;  // no solution\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/mod_inv.hpp\"\
    \n/**\n * @title \u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category\
    \ \u6570\u5B66\n * O(\u221Amod)\n */\n\n// BEGIN CUT HERE\nint discrete_logarithm(int\
    \ a, int b, int mod) {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b\
    \ == 1 ? 0 : -1);\n  auto mul = [&mod](int &x, int y) { x = (std::uint64_t)x *\
    \ y % mod; };\n  int cnt = 0;\n  for (int g = 0;; cnt++, b /= g, mod /= g, mul(b,\
    \ mod_inv<int>(a / g, mod))) {\n    if ((b == 1) || (mod == 1)) return cnt;\n\
    \    if ((g = std::gcd(a, mod)) == 1) break;\n    if (b % g != 0) return -1; \
    \ // no solution\n  }\n  int baby = 1, size = 1 << std::__lg(int(std::sqrt(mod))\
    \ + 1), mask = size - 1,\n      vs[size][2];\n  std::vector<int> os(size + 1);\n\
    \  for (int i = 0; i < size; i++, mul(baby, a)) os[baby & mask]++;\n  for (int\
    \ i = 1; i < size; i++) os[i] += os[i - 1];\n  os[size] = size, baby = 1;\n  for\
    \ (int i = 0, j = 0; i < size; i++, mul(baby, a))\n    j = --os[baby & mask],\
    \ vs[j][0] = baby, vs[j][1] = i;\n  for (int t = 0, iv = mod_inv<int>(baby, mod);\
    \ t < mod; t += size, mul(b, iv))\n    for (int m = (b & mask), i = os[m + 1];\
    \ i-- > os[m];)\n      if (b == vs[i][0]) return cnt + vs[i][1] + t;\n  return\
    \ -1;  // no solution\n}"
  dependsOn:
  - src/Math/mod_inv.hpp
  isVerificationFile: false
  path: src/Math/discrete_logarithm.hpp
  requiredBy: []
  timestamp: '2022-12-30 21:33:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Math/discrete_logarithm.hpp
layout: document
redirect_from:
- /library/src/Math/discrete_logarithm.hpp
- /library/src/Math/discrete_logarithm.hpp.html
title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
