---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/prime_count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"test/yosupo/counting_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_primes\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/prime_count.hpp\"\n/**\n * @title \u7D20\u6570\u30AB\u30A6\u30F3\
    \u30C8\u306A\u3069\n * \u4E57\u6CD5\u7684\u95A2\u6570\u3084\u52A0\u6CD5\u7684\u95A2\
    \u6570\u306E\u548C\u3082\u3042\u308A\n * @category \u6570\u5B66\n */\n\n// verify\u7528\
    :\n// https://atcoder.jp/contests/abc172/tasks/abc172_d\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\
    // https://atcoder.jp/contests/xmascon19/tasks/xmascon19_e (\u52A0\u6CD5\u7684\
    \u95A2\u6570)\n\n// BEGIN CUT HERE\n\n// O(d^2\u221AN+dN^(3/4)/log N) d := degre\
    \ of polynomial\ntemplate <class T = __int128_t>\nauto polynomial_prime_sum_table(std::uint64_t\
    \ N, const std::vector<T> &poly) {\n  const int sqrtN = std::sqrt(N), d = poly.size();\n\
    \  std::vector<T> primes, small(sqrtN + 1, 0), large(sqrtN + 1, 0);\n  std::vector<std::vector<T>>\
    \ s(d, std::vector<T>(sqrtN + 1)),\n      l(d, std::vector<T>(sqrtN + 1));\n \
    \ for (int n = 1, k = 0; n <= sqrtN; n++, k = 0)\n    for (T prd = n; k < d; prd\
    \ *= (n + ++k)) s[k][n] = prd / (k + 1);\n  for (int n = 1, k = 0; n <= sqrtN;\
    \ n++, k = 0)\n    for (T prd = N / n; k < d; prd *= ((N / n) + ++k)) l[k][n]\
    \ = prd / (k + 1);\n  if (d > 2) {\n    std::vector<T> stir(d, 0);\n    stir[1]\
    \ = 1;\n    for (int k = 2; k < d; stir[k++] = 1) {\n      for (int j = k - 1;\
    \ j; j--) stir[j] = stir[j - 1] + stir[j] * (k - 1);\n      for (int n = 1; n\
    \ <= sqrtN; n++)\n        for (int j = 1; j < k; j++)\n          s[k][n] -= stir[j]\
    \ * s[j][n], l[k][n] -= stir[j] * l[j][n];\n    }\n  }\n  for (int k = 0; k <\
    \ d; k++)\n    for (int n = 1; n <= sqrtN; n++) s[k][n] -= 1, l[k][n] -= 1;\n\
    \  for (int p = 2, k = 0; p <= sqrtN; p++, k = 0)\n    if (s[0][p] > s[0][p -\
    \ 1]) {\n      primes.emplace_back(p);\n      std::uint64_t q = std::uint64_t(p)\
    \ * p, M = N / p;\n      int t = sqrtN / p, u = std::min<std::uint64_t>(sqrtN,\
    \ N / q);\n      for (T pw = 1; k < d; k++, pw *= p)\n        if (!k || poly[k]\
    \ != T(0)) {\n          T tk = s[k][p - 1];\n          for (int i = 1; i <= t;\
    \ i++) l[k][i] -= (l[k][i * p] - tk) * pw;\n          for (int i = t + 1; i <=\
    \ u; i++)\n            l[k][i] -= (s[k][double(M) / i] - tk) * pw;\n         \
    \ for (int i = sqrtN; (std::uint64_t)i >= q; i--)\n            s[k][i] -= (s[k][double(i)\
    \ / p] - tk) * pw;\n        }\n    }\n  for (int n = 1; n <= sqrtN; n++)\n   \
    \ for (int k = 0; k < d; k++)\n      small[n] += s[k][n] * poly[k], large[n] +=\
    \ l[k][n] * poly[k];\n  return std::make_tuple(primes, small, large);\n}\n\nauto\
    \ prime_count_table(std::uint64_t N) {\n  return polynomial_prime_sum_table<std::uint64_t>(N,\
    \ {1});\n}\n\nstd::uint64_t prime_count(std::uint64_t N) {\n  return std::get<2>(prime_count_table(N))[1];\n\
    }\n\ntemplate <class T>\nT polynomial_prime_sum(std::uint64_t N, const std::vector<T>\
    \ &poly) {\n  return std::get<2>(polynomial_prime_sum_table<T>(N, poly))[1];\n\
    }\n\ntemplate <class T, class F>\nT additive_sum(std::uint64_t N, F f, std::vector<T>\
    \ poly) {\n  const std::uint64_t sqrtN = std::sqrt(N);\n  auto [primes, s, l]\
    \ = polynomial_prime_sum_table<T>(N, poly);\n  T ret = l[1];\n  for (std::uint64_t\
    \ d = 2, nN = N / d, nd; nN; nN = N / (d = nd))\n    ret += (nN > sqrtN ? l[d]\
    \ : s[nN]) * ((nd = N / nN + 1) - d);\n  for (std::uint64_t p : primes)\n    for\
    \ (std::uint64_t pw = p * p, e = 2; pw <= N; e++, pw *= p)\n      ret += (f(p,\
    \ e) - f(p, e - 1)) * (N / pw);\n  return ret;\n}\n\ntemplate <class T = __int128_t,\
    \ class F>\nT multiplicative_sum(std::uint64_t N, const F &f, const std::vector<T>\
    \ &poly) {\n  const std::uint64_t sqrtN = std::sqrt(N);\n  auto [primes, s, l]\
    \ = polynomial_prime_sum_table<T>(N, poly);\n  for (auto it = primes.rbegin();\
    \ it != primes.rend(); it++) {\n    std::uint64_t p = *it, M = N / p, q = p *\
    \ p;\n    int t = sqrtN / p, u = std::min(sqrtN, N / q);\n    T tk = s[p - 1];\n\
    \    for (auto i = q; i <= sqrtN; i++) s[i] += (s[double(i) / p] - tk) * f(p,\
    \ 1);\n    for (int i = u; i > t; i--) l[i] += (s[double(M) / i] - tk) * f(p,\
    \ 1);\n    for (int i = t; i >= 1; i--) l[i] += (l[i * p] - tk) * f(p, 1);\n \
    \ }\n  for (auto n = sqrtN; n; n--) s[n] += 1, l[n] += 1;\n  auto dfs = [&](auto\
    \ rc, std::uint64_t n, std::size_t bg, T cf) -> T {\n    if (cf == T(0)) return\
    \ T(0);\n    T ret = cf * (n > sqrtN ? l[double(N) / n] : s[n]);\n    for (auto\
    \ i = bg; i < primes.size(); i++) {\n      std::uint64_t p = primes[i], q = p\
    \ * p, nn = double(n) / q;\n      if (!nn) break;\n      for (int e = 2; nn; nn\
    \ = double(nn) / p, e++)\n        ret += rc(rc, nn, i + 1, cf * (f(p, e) - f(p,\
    \ 1) * f(p, e - 1)));\n    }\n    return ret;\n  };\n  return dfs(dfs, N, 0, 1);\n\
    }\n#line 4 \"test/yosupo/counting_primes.test.cpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long long N;\n\
    \  cin >> N;\n  cout << prime_count(N) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/prime_count.hpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long long\
    \ N;\n  cin >> N;\n  cout << prime_count(N) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/prime_count.hpp
  isVerificationFile: true
  path: test/yosupo/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 23:51:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/counting_primes.test.cpp
- /verify/test/yosupo/counting_primes.test.cpp.html
title: test/yosupo/counting_primes.test.cpp
---
