---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/dujiao_sieve.hpp
    title: "\u675C\u6559\u7B5B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc179/tasks/abc179_c
  bundledCode: "#line 1 \"test/atcoder/abc179_c.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\
    \n\n// O(\u221AN)\n\n#include <bits/stdc++.h>\n#line 3 \"src/Math/dujiao_sieve.hpp\"\
    \n/**\n * @title \u675C\u6559\u7B5B\n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * dirichlet_inv_sum : O(N^(3/4))\n *  (\u305F\u3060\u3057\u524D\u51E6\u7406\u3067\
    N^(2/3)\u307E\u3067\u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3)))\n * dirichlet_mul_sum\
    \ : O(\u221AN)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\
    \n// BEGIN CUT HERE\n\n// sum f s.t. f :=  h * g^(-1)\ntemplate <class T, class\
    \ G, class H>\nT dirichlet_div_sum(std::uint64_t N, const G &gsum, const H &hsum,\n\
    \                    std::unordered_map<std::uint64_t, T> &memo) {\n  if (auto\
    \ it = memo.find(N); it != memo.end()) return it->second;\n  T ret = hsum(N),\
    \ gs1 = gsum(1), gs = gs1, ngs;\n  for (std::uint64_t d = 1, nN; nN = N / (d +\
    \ 1); gs = ngs)\n    ret -= dirichlet_div_sum(nN, gsum, hsum, memo) *\n      \
    \     ((ngs = gsum(d = N / nN)) - gs);\n  return memo[N] = ret / gs1;\n}\ntemplate\
    \ <class T, class G, class H>\nT dirichlet_div_sum(std::uint64_t N, const G &gsum,\
    \ const H &hsum) {\n  std::unordered_map<std::uint64_t, T> memo;\n  return dirichlet_div_sum<T>(N,\
    \ gsum, hsum, memo);\n}\n\n// sum f s.t. f :=  h * g\ntemplate <class T, class\
    \ G, class H>\nT dirichlet_mul_sum(std::uint64_t N, const G &gsum, const H &hsum)\
    \ {\n  const int sqrtN = std::sqrt(N);\n  T ret = 0;\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (hsum(i) - hsum(i - 1)) * gsum(N / i);\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (gsum(i) - gsum(i - 1)) * hsum(N / i);\n  return ret -= hsum(sqrtN)\
    \ * gsum(sqrtN);\n}\n#line 7 \"test/atcoder/abc179_c.cpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  auto gsum = [](long\
    \ long n) { return n; };\n  long long N;\n  cin >> N;\n  cout << dirichlet_mul_sum<long\
    \ long>(N - 1, gsum, gsum) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n\n\
    // O(\u221AN)\n\n#include <bits/stdc++.h>\n#include \"src/Math/dujiao_sieve.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  auto gsum = [](long long n) { return n; };\n  long long N;\n  cin >> N;\n \
    \ cout << dirichlet_mul_sum<long long>(N - 1, gsum, gsum) << '\\n';\n  return\
    \ 0;\n}"
  dependsOn:
  - src/Math/dujiao_sieve.hpp
  isVerificationFile: false
  path: test/atcoder/abc179_c.cpp
  requiredBy: []
  timestamp: '2022-09-10 14:49:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc179_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc179_c.cpp
- /library/test/atcoder/abc179_c.cpp.html
title: test/atcoder/abc179_c.cpp
---
