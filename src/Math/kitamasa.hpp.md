---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0168.test.cpp
    title: test/aoj/0168.test.cpp
  - icon: ':x:'
    path: test/yukicoder/658.test.cpp
    title: test/yukicoder/658.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/215.test.cpp
    title: test/yukicoder/215.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/kitamasa.hpp: line 12: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "/**\n * @title \u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97\
    \n * @category \u6570\u5B66\n *  O(NlogNlogk)\n */\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/Math/FormalPowerSeries.hpp\"\n#undef call_from_test\n#endif\n\n// b[0]\
    \ = a[0], b[1] = a[1], ..., b[N-1] = a[N-1]\n// b[n] = c[0] * b[n-N] + c[1] *\
    \ b[n-N+1] + ... + c[N-1] * b[n-1] (n >= N)\n// return b[k]\n\ntemplate <class\
    \ Modint>\nModint kitamasa(const vector<Modint> &c, const vector<Modint> &a, uint64_t\
    \ k) {\n  assert(a.size() == c.size());\n  int N = a.size();\n  if (k < N) return\
    \ a[k];\n  using FPS = FormalPowerSeries<Modint>;\n  uint64_t mask = (uint64_t(1)\
    \ << (63 - __builtin_clzll(k))) >> 1;\n  FPS f(N + 1);\n  f[0] = 1;\n  for (int\
    \ i = 0; i < N; i++) f[N - i] = -c[i];\n  FPS r({1, 0});\n  if (N < 1150) {  //\
    \ naive\n    r = r.divrem_rev_n(f).second;\n    for (; mask; mask >>= 1) {\n \
    \     r *= r;\n      if (k & mask) r.push_back(0);\n      r = r.divrem_rev_n(f).second;\n\
    \    }\n  } else {\n    FPS inv = f.inv(N);\n    r = r.rem_rev_pre(f, inv);\n\
    \    for (; mask; mask >>= 1) {\n      r *= r;\n      if (k & mask) r.push_back(0);\n\
    \      r = r.rem_rev_pre(f, inv);\n    }\n  }\n  Modint ret(0);\n  for (int i\
    \ = 0; i < N; i++) ret += r[N - i - 1] * a[i];\n  return ret;\n}\n"
  dependsOn:
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/kitamasa.hpp
  requiredBy: []
  timestamp: '2020-09-23 21:17:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0168.test.cpp
  - test/yukicoder/658.test.cpp
  - test/yukicoder/215.test.cpp
documentation_of: src/Math/kitamasa.hpp
layout: document
redirect_from:
- /library/src/Math/kitamasa.hpp
- /library/src/Math/kitamasa.hpp.html
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
---
