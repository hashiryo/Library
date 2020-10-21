---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':x:'
    path: test/yukicoder/215.test.cpp
    title: test/yukicoder/215.test.cpp
  - icon: ':x:'
    path: test/yukicoder/658.test.cpp
    title: test/yukicoder/658.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/kitamasa.hpp: line 12: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "/**\n * @title \u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97\
    \n * @category \u6570\u5B66\n *  O(NlogNlogk)\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/Math/FormalPowerSeries.hpp\"\n#undef\
    \ call_from_test\n#endif\n\n// b[0] = a[0], b[1] = a[1], ..., b[N-1] = a[N-1]\n\
    // b[n] = c[0] * b[n-N] + c[1] * b[n-N+1] + ... + c[N-1] * b[n-1] (n >= N)\n//\
    \ return b[k]\n\ntemplate <class mint>\nmint kitamasa(const vector<mint> &c, const\
    \ vector<mint> &a, uint64_t k) {\n  assert(a.size() == c.size());\n  int N = a.size();\n\
    \  if (k < (uint64_t)N) return a[k];\n  uint64_t mask = (uint64_t(1) << (63 -\
    \ __builtin_clzll(k))) >> 1;\n  FormalPowerSeries<mint> f(N + 1), r({1, 0});\n\
    \  f[0] = 1;\n  for (int i = 0; i < N; i++) f[N - i] = -c[i];\n  if (N < 1024)\
    \ {  // naive\n    r = r.quorem_rev_n(f).second;\n    for (; mask; mask >>= 1)\
    \ {\n      r = r.mul(r);\n      if (k & mask) r.push_back(0);\n      r = r.quorem_rev_n(f).second;\n\
    \    }\n  } else {\n    FormalPowerSeries<mint> inv = f.inv();\n    r = r.quorem_rev_con(f,\
    \ inv).second;\n    for (; mask; mask >>= 1) {\n      r = r.mul(r);\n      if\
    \ (k & mask) r.push_back(0);\n      r = r.quorem_rev_con(f, inv).second;\n   \
    \ }\n  }\n  mint ret(0);\n  for (int i = 0; i < N; i++) ret += r[N - i - 1] *\
    \ a[i];\n  return ret;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/kitamasa.hpp
  requiredBy: []
  timestamp: '2020-10-21 17:49:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/658.test.cpp
  - test/yukicoder/215.test.cpp
  - test/aoj/0168.test.cpp
documentation_of: src/Math/kitamasa.hpp
layout: document
redirect_from:
- /library/src/Math/kitamasa.hpp
- /library/src/Math/kitamasa.hpp.html
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
---
