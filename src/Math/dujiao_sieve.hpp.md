---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1019.dujiao.test.cpp
    title: test/yukicoder/1019.dujiao.test.cpp
  - icon: ':x:'
    path: test/yukicoder/886.dujiao.test.cpp
    title: test/yukicoder/886.dujiao.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u675C\u6559\u7B5B"
    links:
    - https://blog.bill.moe/multiplicative-function-sieves-notes/
    - https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
    - https://maspypy.com/yukicoder-no-886-direct
    - https://oi-wiki.org/math/du/
    - https://yukicoder.me/problems/no/1019/editorial
    - https://yukicoder.me/wiki/sum_totient
  bundledCode: "#line 2 \"src/Math/dujiao_sieve.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u675C\u6559\u7B5B\n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * @see https://blog.bill.moe/multiplicative-function-sieves-notes/\n *  \u30E1\
    \u30E2\u5316\u518D\u5E30\u3067\u5B9F\u88C5(map\u4F7F\u3063\u3066\u308B\u306E\u3067\
    log\u304C\u3064\u304F)\n *  k==1\u306A\u3089O(N^(3/4)) (g,b\u306E\u8A08\u7B97\u91CF\
    \u3092O(1)\u3068\u3057\u3066)\n *  \u524D\u51E6\u7406\u3067N^(2/3)\u307E\u3067\
    \u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3))\n */\n\n#ifndef call_from_test\n\
    #line 19 \"src/Math/dujiao_sieve.hpp\"\nusing namespace std;\n#endif\n\n// BEGIN\
    \ CUT HERE\n\n// input H,W,g,b,k\n// output f(H,W)\n//  s.t. g(x,y) = sum_{d=1,2,...}\
    \ a(d)f([x/d^k],[y/d^k])\n//       b(d) = a(1)+a(2)+...+a(d)\n\ntemplate <typename\
    \ T, typename G, typename A>\nT dujiao_sieve(std::int64_t H, std::int64_t W, const\
    \ G &g, const A &b,\n               std::map<pair<std::int64_t, std::int64_t>,\
    \ T> &memo, int k = 1) {\n  if (memo.count(std::make_pair(H, W))) return memo[std::make_pair(H,\
    \ W)];\n  T ret = g(H, W);\n  std::int64_t d = 2;\n  while (true) {\n    std::int64_t\
    \ Hd = H / std::pow(d, k), Wd = W / std::pow(d, k);\n    if (!Hd || !Wd) break;\n\
    \    std::int64_t next_d\n        = std::min(pow(1. * H / Hd, 1. / k), pow(1.\
    \ * W / Wd, 1. / k)) + 1;\n    T r = dujiao_sieve<T>(Hd, Wd, g, b, memo, k);\n\
    \    ret -= r * (b(next_d - 1) - b(d - 1));\n    d = next_d;\n  }\n  return memo[std::make_pair(H,\
    \ W)] = ret / b(1);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u675C\u6559\u7B5B\
    \n * @category \u6570\u5B66\n * @see https://maspypy.com/yukicoder-no-886-direct\n\
    \ * @see https://yukicoder.me/problems/no/1019/editorial\n * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula\n\
    \ * @see https://yukicoder.me/wiki/sum_totient\n * @see https://oi-wiki.org/math/du/\n\
    \ * @see https://blog.bill.moe/multiplicative-function-sieves-notes/\n *  \u30E1\
    \u30E2\u5316\u518D\u5E30\u3067\u5B9F\u88C5(map\u4F7F\u3063\u3066\u308B\u306E\u3067\
    log\u304C\u3064\u304F)\n *  k==1\u306A\u3089O(N^(3/4)) (g,b\u306E\u8A08\u7B97\u91CF\
    \u3092O(1)\u3068\u3057\u3066)\n *  \u524D\u51E6\u7406\u3067N^(2/3)\u307E\u3067\
    \u8A08\u7B97\u3067\u304D\u308B\u306A\u3089O(N^(2/3))\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\n// BEGIN CUT HERE\n\n\
    // input H,W,g,b,k\n// output f(H,W)\n//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])\n\
    //       b(d) = a(1)+a(2)+...+a(d)\n\ntemplate <typename T, typename G, typename\
    \ A>\nT dujiao_sieve(std::int64_t H, std::int64_t W, const G &g, const A &b,\n\
    \               std::map<pair<std::int64_t, std::int64_t>, T> &memo, int k = 1)\
    \ {\n  if (memo.count(std::make_pair(H, W))) return memo[std::make_pair(H, W)];\n\
    \  T ret = g(H, W);\n  std::int64_t d = 2;\n  while (true) {\n    std::int64_t\
    \ Hd = H / std::pow(d, k), Wd = W / std::pow(d, k);\n    if (!Hd || !Wd) break;\n\
    \    std::int64_t next_d\n        = std::min(pow(1. * H / Hd, 1. / k), pow(1.\
    \ * W / Wd, 1. / k)) + 1;\n    T r = dujiao_sieve<T>(Hd, Wd, g, b, memo, k);\n\
    \    ret -= r * (b(next_d - 1) - b(d - 1));\n    d = next_d;\n  }\n  return memo[std::make_pair(H,\
    \ W)] = ret / b(1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/dujiao_sieve.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/886.dujiao.test.cpp
  - test/yukicoder/1019.dujiao.test.cpp
  - test/yosupo/sum_of_totient_function.test.cpp
documentation_of: src/Math/dujiao_sieve.hpp
layout: document
redirect_from:
- /library/src/Math/dujiao_sieve.hpp
- /library/src/Math/dujiao_sieve.hpp.html
title: "\u675C\u6559\u7B5B"
---
