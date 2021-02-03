---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/factorize.hpp\"\n/**\n * @title\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\n * @category \u6570\u5B66\n *  O(N^(1/4))\n\
    \ * \u3064\u3044\u3067\u306B\u539F\u59CB\u6839\u63A2\u7D22\n */\n\n// BEGIN CUT\
    \ HERE\n\nbool is_prime(std::uint64_t n) {\n  if (n < 2 || n % 6 % 4 != 1) return\
    \ (n | 1) == 3;\n  __uint128_t s = __builtin_ctzll(n - 1), d = n >> s, p, i, e,\
    \ b;\n  for (auto a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n\
    \    for (p = 1, i = s, e = d, b = a % n; e; e >>= 1, b = b * b % n)\n      if\
    \ (e & 1) p = p * b % n;\n    while (p != 1 && p != n - 1 && a % n && i--) p =\
    \ p * p % n;\n    if (p != n - 1 && i != s) return false;\n  }\n  return true;\n\
    }\n\nstd::vector<std::uint64_t> factorize(std::uint64_t n) {\n  std::vector<std::uint64_t>\
    \ ret;\n  std::queue<std::uint64_t> que;\n  for (que.push(n); !que.empty();) {\n\
    \    __uint128_t m = que.front(), x = 0, y = 0, t = 0, prd = 2, i = 1, q;\n  \
    \  que.pop();\n    if (m == 1) continue;\n    if (!is_prime(m)) {\n      auto\
    \ f = [&](__uint128_t a) { return a * a % m + 1; };\n      while (t++ % 40 ||\
    \ std::gcd<std::uint64_t, std::uint64_t>(prd, m) == 1) {\n        if (x == y)\
    \ x = ++i, y = f(x);\n        if ((q = prd * (std::max(x, y) - std::min(x, y))\
    \ % m)) prd = q;\n        x = f(x), y = f(f(y));\n      }\n      auto a = std::gcd<std::uint64_t,\
    \ std::uint64_t>(prd, m);\n      que.push(a), que.push(m / a);\n    } else\n \
    \     ret.push_back(m);\n  }\n  return std::sort(ret.begin(), ret.end()), ret;\n\
    }\n\nstd::map<std::uint64_t, short> factorize_map(std::uint64_t n) {\n  std::map<std::uint64_t,\
    \ short> ret;\n  for (auto &p : factorize(n)) ret[p]++;\n  return ret;\n}\n\n\
    std::vector<std::uint64_t> divisors(std::uint64_t n) {\n  std::vector<std::uint64_t>\
    \ ret = {1};\n  for (auto [p, e] : factorize_map(n))\n    for (std::uint64_t sz\
    \ = ret.size(), pw = p; e--; pw *= p)\n      for (int i = sz - 1; i >= 0; i--)\
    \ ret.push_back(ret[i] * pw);\n  return std::sort(ret.begin(), ret.end()), ret;\n\
    }\n\nstd::uint64_t primitive_root(std::uint64_t p) {\n  assert(is_prime(p));\n\
    \  auto divs = divisors(p - 1);\n  __uint128_t g = 2, pw, e, b;\n  for (bool isok\
    \ = true;; g++, isok = true) {\n    for (int i = divs.size() - 2; i && isok; i--,\
    \ isok &= pw != 1)\n      for (pw = 1, e = divs[i], b = g; e; e >>= 1, b = b *\
    \ b % p)\n        if (e & 1) pw = pw * b % p;\n    if (isok) return g;\n  }\n\
    }\n\ntemplate <class T, class F>\nauto get_multiplicative(const F &f) {\n  return\
    \ [f](std::uint64_t n) {\n    T ret = 1;\n    for (auto [p, e] : factorize_map(n))\
    \ ret *= f(p, e);\n    return ret;\n  };\n}\n#line 4 \"test/yosupo/factorize.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int Q;\n  cin >> Q;\n  while (Q--) {\n    unsigned long long a;\n    cin >>\
    \ a;\n    auto ans = factorize(a);\n    cout << ans.size();\n    for (auto x :\
    \ ans) cout << \" \" << x;\n    cout << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <bits/stdc++.h>\n\
    #include \"src/Math/factorize.hpp\"\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int Q;\n  cin >> Q;\n  while (Q--)\
    \ {\n    unsigned long long a;\n    cin >> a;\n    auto ans = factorize(a);\n\
    \    cout << ans.size();\n    for (auto x : ans) cout << \" \" << x;\n    cout\
    \ << '\\n';\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/factorize.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---