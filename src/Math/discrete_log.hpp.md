---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
    links: []
  bundledCode: "#line 2 \"src/Math/discrete_log.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category\
    \ \u6570\u5B66\n * O(\u221Amod)\n */\n\n// BEGIN CUT HERE\nint discrete_log(unsigned\
    \ a, unsigned b, unsigned mod) {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0\
    \ : 1) : (b == 1 ? 0 : -1);\n  using u32 = unsigned;\n  auto mul = [&mod](u32\
    \ &x, u32 y) { x = (std::uint64_t)x * y % mod; };\n  auto inv = [&mod](u32 s)\
    \ -> u32 {\n    int x = 1, y = 0, t = mod;\n    for (int q, z, u; t;)\n      z\
    \ = x, u = s, x = y, y = z - y * (q = s / t), s = t, t = u - t * q;\n    return\
    \ x < 0 ? mod - (-x) % mod : x % mod;\n  };\n  u32 cnt = 0;\n  for (u32 g;; cnt++,\
    \ b /= g, mod /= g, mul(b, inv(a / g))) {\n    if ((b == 1) || (mod == 1)) return\
    \ cnt;\n    if ((g = std::gcd(a, mod)) == 1) break;\n    if (b % g != 0) return\
    \ -1;  // no solution\n  }\n  u32 mid = std::ceil(std::sqrt(mod)), baby = 1;\n\
    \  std::unordered_map<u32, u32> mp;\n  for (u32 i = 0; i < mid; i++, mul(baby,\
    \ a)) mp.insert({baby, i});\n  for (u32 i = 0, iv = inv(baby), giant = b; i <\
    \ mid; mul(giant, iv), i++)\n    if (auto it = mp.find(giant); it != mp.end())\n\
    \      return cnt + i * mid + it->second;\n  return -1;  // no solution\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u96E2\u6563\u5BFE\
    \u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n * O(\u221Amod)\n\
    \ */\n\n// BEGIN CUT HERE\nint discrete_log(unsigned a, unsigned b, unsigned mod)\
    \ {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 : -1);\n \
    \ using u32 = unsigned;\n  auto mul = [&mod](u32 &x, u32 y) { x = (std::uint64_t)x\
    \ * y % mod; };\n  auto inv = [&mod](u32 s) -> u32 {\n    int x = 1, y = 0, t\
    \ = mod;\n    for (int q, z, u; t;)\n      z = x, u = s, x = y, y = z - y * (q\
    \ = s / t), s = t, t = u - t * q;\n    return x < 0 ? mod - (-x) % mod : x % mod;\n\
    \  };\n  u32 cnt = 0;\n  for (u32 g;; cnt++, b /= g, mod /= g, mul(b, inv(a /\
    \ g))) {\n    if ((b == 1) || (mod == 1)) return cnt;\n    if ((g = std::gcd(a,\
    \ mod)) == 1) break;\n    if (b % g != 0) return -1;  // no solution\n  }\n  u32\
    \ mid = std::ceil(std::sqrt(mod)), baby = 1;\n  std::unordered_map<u32, u32> mp;\n\
    \  for (u32 i = 0; i < mid; i++, mul(baby, a)) mp.insert({baby, i});\n  for (u32\
    \ i = 0, iv = inv(baby), giant = b; i < mid; mul(giant, iv), i++)\n    if (auto\
    \ it = mp.find(giant); it != mp.end())\n      return cnt + i * mid + it->second;\n\
    \  return -1;  // no solution\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/discrete_log.hpp
  requiredBy: []
  timestamp: '2022-10-03 10:06:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Math/discrete_log.hpp
layout: document
redirect_from:
- /library/src/Math/discrete_log.hpp
- /library/src/Math/discrete_log.hpp.html
title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
