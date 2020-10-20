---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96E2\u6563\u5BFE\u6570"
    links: []
  bundledCode: "#line 1 \"src/Math/discrete_log.hpp\"\n/**\n * @title \u96E2\u6563\
    \u5BFE\u6570\n * @category \u6570\u5B66\n * O(mod^(1/2))\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\nint discrete_log(unsigned\
    \ a, unsigned b, unsigned mod) {\n  if (a == 0) return b == 0 ? (mod == 1 ? 0\
    \ : 1) : (b == 1 ? 0 : -1);\n  auto mod_inv = [](unsigned x, unsigned mod) {\n\
    \    int a = x, b = mod, u = 1, v = 0, t;\n    while (b) t = a / b, swap(a -=\
    \ t * b, b), swap(u -= t * v, v);\n    return u >= 0 ? u % mod : (mod - (-u) %\
    \ mod);\n  };\n  unsigned cnt = 0;\n  for (unsigned g;; cnt++) {\n    if ((b ==\
    \ 1) || (mod == 1)) return cnt;\n    if ((g = __gcd(a, mod)) == 1) break;\n  \
    \  if (b % g != 0) return -1;  // no solution\n    b /= g, mod /= g;\n    b =\
    \ 1ull * mod_inv(a / g, mod) * b % mod;\n  }\n  unsigned middle = ceil(sqrt(mod));\n\
    \  unordered_map<unsigned int, unsigned int> mp;\n  unsigned int baby = 1;\n \
    \ for (unsigned i = 0; i < middle; i++, baby = 1ull * baby * a % mod)\n    mp.insert({baby,\
    \ i});\n  unsigned int inv = mod_inv(baby, mod);\n  unsigned int giant = b;\n\
    \  for (unsigned i = 0; i < middle; i++) {\n    auto it = mp.find(giant);\n  \
    \  if (it != mp.end()) return cnt + i * middle + it->second;\n    giant = 1ull\
    \ * giant * inv % mod;\n  }\n  return -1;  // no solution\n}\n"
  code: "/**\n * @title \u96E2\u6563\u5BFE\u6570\n * @category \u6570\u5B66\n * O(mod^(1/2))\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\nint discrete_log(unsigned a, unsigned b, unsigned mod) {\n  if (a ==\
    \ 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 : -1);\n  auto mod_inv =\
    \ [](unsigned x, unsigned mod) {\n    int a = x, b = mod, u = 1, v = 0, t;\n \
    \   while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);\n    return\
    \ u >= 0 ? u % mod : (mod - (-u) % mod);\n  };\n  unsigned cnt = 0;\n  for (unsigned\
    \ g;; cnt++) {\n    if ((b == 1) || (mod == 1)) return cnt;\n    if ((g = __gcd(a,\
    \ mod)) == 1) break;\n    if (b % g != 0) return -1;  // no solution\n    b /=\
    \ g, mod /= g;\n    b = 1ull * mod_inv(a / g, mod) * b % mod;\n  }\n  unsigned\
    \ middle = ceil(sqrt(mod));\n  unordered_map<unsigned int, unsigned int> mp;\n\
    \  unsigned int baby = 1;\n  for (unsigned i = 0; i < middle; i++, baby = 1ull\
    \ * baby * a % mod)\n    mp.insert({baby, i});\n  unsigned int inv = mod_inv(baby,\
    \ mod);\n  unsigned int giant = b;\n  for (unsigned i = 0; i < middle; i++) {\n\
    \    auto it = mp.find(giant);\n    if (it != mp.end()) return cnt + i * middle\
    \ + it->second;\n    giant = 1ull * giant * inv % mod;\n  }\n  return -1;  //\
    \ no solution\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/discrete_log.hpp
  requiredBy: []
  timestamp: '2020-09-22 01:26:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: src/Math/discrete_log.hpp
layout: document
redirect_from:
- /library/src/Math/discrete_log.hpp
- /library/src/Math/discrete_log.hpp.html
title: "\u96E2\u6563\u5BFE\u6570"
---
