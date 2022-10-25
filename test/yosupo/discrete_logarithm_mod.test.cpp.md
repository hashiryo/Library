---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/discrete_logarithm.hpp
    title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/discrete_logarithm.hpp\"\n/**\n * @title \u96E2\u6563\u5BFE\
    \u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n * O(\u221Amod)\n\
    \ */\n\n// BEGIN CUT HERE\nint discrete_logarithm(unsigned a, unsigned b, unsigned\
    \ mod) {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 : -1);\n\
    \  using u32 = unsigned;\n  auto mul = [&mod](u32 &x, u32 y) { x = (std::uint64_t)x\
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
    \  return -1;  // no solution\n}\n#line 4 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  cin >> T;\n  while (T--) {\n    int X, Y, M;\n    cin >> X >> Y >>\
    \ M;\n    cout << discrete_logarithm(X, Y, M) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/discrete_logarithm.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  cin >> T;\n  while (T--) {\n    int X, Y, M;\n    cin >> X >> Y >>\
    \ M;\n    cout << discrete_logarithm(X, Y, M) << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/discrete_logarithm.hpp
  isVerificationFile: true
  path: test/yosupo/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 15:42:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp.html
title: test/yosupo/discrete_logarithm_mod.test.cpp
---
