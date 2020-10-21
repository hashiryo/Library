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
    path: test/yosupo/bernoulli.test.cpp
    title: test/yosupo/bernoulli.test.cpp
  - icon: ':x:'
    path: test/yosupo/partition.test.cpp
    title: test/yosupo/partition.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_first.test.cpp
    title: test/yosupo/stirling_first.test.cpp
  - icon: ':x:'
    path: test/yosupo/stirling_second.test.cpp
    title: test/yosupo/stirling_second.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6570\u5217(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u4F7F\u7528\
      )"
    links:
    - https://en.m.wikipedia.org/wiki/Eulerian_number
    - https://en.wikipedia.org/wiki/Bernoulli_number
    - https://en.wikipedia.org/wiki/Partition_function_(number_theory)
    - https://en.wikipedia.org/wiki/Stirling_number
    - https://min-25.hatenablog.com/entry/2015/04/07/160154
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/fps_sequence.hpp: line 17: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "/**\n * @title \u6570\u5217(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u4F7F\u7528\
    )\n * @category \u6570\u5B66\n *  O(NlogN)\n * @see https://min-25.hatenablog.com/entry/2015/04/07/160154\n\
    \ * @see https://en.wikipedia.org/wiki/Bernoulli_number\n * @see https://en.wikipedia.org/wiki/Partition_function_(number_theory)\n\
    \ * @see https://en.wikipedia.org/wiki/Stirling_number\n * @see https://en.m.wikipedia.org/wiki/Eulerian_number\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/FormalPowerSeries.hpp\"\
    \n#undef call_from_test\n#endif\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ bernoulli(int N) {\n  FormalPowerSeries<mint> ret(N + 1);\n  ret[0] = 1;\n \
    \ for (int i = 1; i <= N; i++) ret[i] = ret[i - 1] / mint(i + 1);\n  ret = ret.inv();\n\
    \  mint fact = 1;\n  for (int i = 1; i <= N; fact *= (++i)) ret[i] *= fact;\n\
    \  return ret;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> partition(int\
    \ N) {\n  FormalPowerSeries<mint> ret(N + 1);\n  ret[0] = 1;\n  for (int k = 1;\
    \ 1ll * k * (3 * k + 1) / 2 <= N; k++)\n    ret[k * (3 * k + 1) / 2] = (k & 1\
    \ ? -1 : 1);\n  for (int k = 1; 1ll * k * (3 * k - 1) / 2 <= N; k++)\n    ret[k\
    \ * (3 * k - 1) / 2] = (k & 1 ? -1 : 1);\n  return ret.inv();\n}\n\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> stirling_first(int N) {\n  if (!N) return {1};\n\
    \  auto ret = stirling_first<mint>(N / 2);\n  ret *= ret.shift(N / 2);\n  if (N\
    \ & 1) ret *= {N - 1, 1};\n  return ret;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ stirling_second(int N) {\n  FormalPowerSeries<mint> a(N + 1), b(N + 1);\n  mint\
    \ finv = 1;\n  for (int i = 0; i <= N; finv /= (++i))\n    a[i] = mint(i).pow(N)\
    \ * finv, b[i] = i & 1 ? -finv : finv;\n  return (a * b).part(N + 1);\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/fps_sequence.hpp
  requiredBy: []
  timestamp: '2020-10-21 19:28:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/bernoulli.test.cpp
  - test/yosupo/partition.test.cpp
  - test/yosupo/stirling_first.test.cpp
  - test/yosupo/stirling_second.test.cpp
documentation_of: src/Math/fps_sequence.hpp
layout: document
redirect_from:
- /library/src/Math/fps_sequence.hpp
- /library/src/Math/fps_sequence.hpp.html
title: "\u6570\u5217(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u4F7F\u7528)"
---
