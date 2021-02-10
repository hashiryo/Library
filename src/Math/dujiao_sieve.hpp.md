---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1019.dujiao.test.cpp
    title: test/yukicoder/1019.dujiao.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u675C\u6559\u7B5B"
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
    - https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d
    - https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
    - https://maspypy.com/yukicoder-no-886-direct
    - https://oi-wiki.org/math/du/
    - https://yukicoder.me/problems/no/1019/editorial
    - https://yukicoder.me/wiki/sum_totient
  bundledCode: "#line 2 \"src/Math/dujiao_sieve.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u675C\u6559\u7B5B\n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * dirichlet_inv_sum : O(N^(3/4))\n *  (\u305F\u3060\u3057\u524D\u51E6\u7406\u3067\
    N^(2/3)\u307E\u3067\u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3)))\n * dirichlet_mul_sum\
    \ : O(\u221AN)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/abc172/tasks/abc172_d\n\
    // https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\n// BEGIN CUT HERE\n\
    \n// sum f s.t. f :=  h * g^(-1)\n\ntemplate <class T, class G, class H>\nT dirichlet_inv_sum(unsigned\
    \ long long N, const G &gsum, const H &hsum,\n                    std::unordered_map<unsigned\
    \ long long, T> &memo) {\n  auto it = memo.find(N);\n  if (it != memo.end()) return\
    \ it->second;\n  T ret = hsum(N);\n  for (unsigned long long d = 2, nN = double(N)\
    \ / d, nd; nN;\n       nN = double(N) / (d = nd))\n    ret -= dirichlet_inv_sum(nN,\
    \ gsum, hsum, memo)\n           * (gsum((nd = double(N) / nN + 1) - 1) - gsum(d\
    \ - 1));\n  return memo[N] = ret / gsum(1);\n}\ntemplate <class T, class G, class\
    \ H>\nT dirichlet_inv_sum(std::uint64_t N, const G &gsum, const H &hsum) {\n \
    \ std::unordered_map<unsigned long long, T> memo;\n  return dirichlet_inv_sum<T>(N,\
    \ gsum, hsum, memo);\n}\n\n// sum f s.t. f :=  h * g\ntemplate <class T, class\
    \ G, class H>\nT dirichlet_mul_sum(std::uint64_t N, const G &gsum, const H &hsum)\
    \ {\n  const int sqrtN = sqrt(N);\n  T ret = 0;\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (hsum(i) - hsum(i - 1)) * gsum(N / i);\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (gsum(i) - gsum(i - 1)) * hsum(N / i);\n  return ret -= hsum(sqrtN)\
    \ * gsum(sqrtN);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u675C\u6559\u7B5B\
    \n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * dirichlet_inv_sum : O(N^(3/4))\n *  (\u305F\u3060\u3057\u524D\u51E6\u7406\u3067\
    N^(2/3)\u307E\u3067\u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3)))\n * dirichlet_mul_sum\
    \ : O(\u221AN)\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/abc172/tasks/abc172_d\n\
    // https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\n// BEGIN CUT HERE\n\
    \n// sum f s.t. f :=  h * g^(-1)\n\ntemplate <class T, class G, class H>\nT dirichlet_inv_sum(unsigned\
    \ long long N, const G &gsum, const H &hsum,\n                    std::unordered_map<unsigned\
    \ long long, T> &memo) {\n  auto it = memo.find(N);\n  if (it != memo.end()) return\
    \ it->second;\n  T ret = hsum(N);\n  for (unsigned long long d = 2, nN = double(N)\
    \ / d, nd; nN;\n       nN = double(N) / (d = nd))\n    ret -= dirichlet_inv_sum(nN,\
    \ gsum, hsum, memo)\n           * (gsum((nd = double(N) / nN + 1) - 1) - gsum(d\
    \ - 1));\n  return memo[N] = ret / gsum(1);\n}\ntemplate <class T, class G, class\
    \ H>\nT dirichlet_inv_sum(std::uint64_t N, const G &gsum, const H &hsum) {\n \
    \ std::unordered_map<unsigned long long, T> memo;\n  return dirichlet_inv_sum<T>(N,\
    \ gsum, hsum, memo);\n}\n\n// sum f s.t. f :=  h * g\ntemplate <class T, class\
    \ G, class H>\nT dirichlet_mul_sum(std::uint64_t N, const G &gsum, const H &hsum)\
    \ {\n  const int sqrtN = sqrt(N);\n  T ret = 0;\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (hsum(i) - hsum(i - 1)) * gsum(N / i);\n  for (int i = 1; i <= sqrtN;\
    \ i++) ret += (gsum(i) - gsum(i - 1)) * hsum(N / i);\n  return ret -= hsum(sqrtN)\
    \ * gsum(sqrtN);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/dujiao_sieve.hpp
  requiredBy: []
  timestamp: '2021-02-10 10:21:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/sum_of_totient_function.test.cpp
  - test/yukicoder/1019.dujiao.test.cpp
documentation_of: src/Math/dujiao_sieve.hpp
layout: document
redirect_from:
- /library/src/Math/dujiao_sieve.hpp
- /library/src/Math/dujiao_sieve.hpp.html
title: "\u675C\u6559\u7B5B"
---
