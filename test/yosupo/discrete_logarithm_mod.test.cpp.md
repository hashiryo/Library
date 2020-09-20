---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/discrete_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"src/Math/discrete_log.hpp\"\
    \n/**\n * @title \u96E2\u6563\u5BFE\u6570\n * @category \u6570\u5B66\n * O(mod^(1/2))\n\
    \ */\n\n#ifndef call_from_test\n#line 9 \"src/Math/discrete_log.hpp\"\nusing namespace\
    \ std;\n#endif\n\nint discrete_log(unsigned a, unsigned b, unsigned mod) {\n \
    \ if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0 : -1);\n  auto\
    \ mod_inv = [](unsigned x, unsigned mod) {\n    int a = x, b = mod, u = 1, v =\
    \ 0, t;\n    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);\n\
    \    return u >= 0 ? u % mod : (mod - (-u) % mod);\n  };\n  unsigned cnt = 0;\n\
    \  for (unsigned g; (g = __gcd(a, mod)) != 1; cnt++) {\n    if ((b == 1) || (mod\
    \ == 1)) return cnt;\n    if (b % g != 0) return -1;  // no solution\n    b /=\
    \ g, mod /= g;\n    b = 1ull * mod_inv(a / g, mod) * b % mod;\n  }\n  unsigned\
    \ middle = ceil(sqrt(mod));\n  unordered_map<unsigned int, unsigned int> mp;\n\
    \  unsigned int baby = 1;\n  for (unsigned i = 0; i < middle; i++, baby = 1ull\
    \ * baby * a % mod)\n    mp[baby] = i;\n  unsigned int inv = mod_inv(baby, mod);\n\
    \  unsigned int giant = b;\n  for (unsigned i = 0; i < middle; i++) {\n    auto\
    \ it = mp.find(giant);\n    if (it != mp.end()) return cnt + i * middle + it->second;\n\
    \    giant = 1ull * giant * inv % mod;\n  }\n  return -1;  // no solution\n}\n\
    #line 8 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin\
    \ >> T;\n  while (T--) {\n    int X, Y, M;\n    cin >> X >> Y >> M;\n    cout\
    \ << discrete_log(X, Y, M) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Math/discrete_log.hpp\"\n#undef call_from_test\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin >> T;\n  while\
    \ (T--) {\n    int X, Y, M;\n    cin >> X >> Y >> M;\n    cout << discrete_log(X,\
    \ Y, M) << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/discrete_log.hpp
  isVerificationFile: true
  path: test/yosupo/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2020-09-20 18:21:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp.html
title: test/yosupo/discrete_logarithm_mod.test.cpp
---
