---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/FormalPowerSeries.hpp: line 12: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/Math/FormalPowerSeries.hpp\"\n#include \"src/Math/ModInt.hpp\"\n\
    #undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N;\n  cin >> N;\n  using Mint = ModInt<998244353>;\n  using FPS = FormalPowerSeries<Mint>;\n\
    \  FPS a(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n  auto b = a.sqrt();\n\
    \  if (b.size() == 0) {\n    cout << -1 << endl;\n  } else {\n    for (int i =\
    \ 0; i < N; i++) cout << b[i] << (i < N - 1 ? \" \" : \"\\n\");\n    cout << flush;\n\
    \  }\n  return 0;\n}"
  dependsOn:
  - src/Math/FormalPowerSeries.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/sqrt_of_FPS.test.cpp
  requiredBy: []
  timestamp: '2020-10-20 16:49:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sqrt_of_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_of_FPS.test.cpp
- /verify/test/yosupo/sqrt_of_FPS.test.cpp.html
title: test/yosupo/sqrt_of_FPS.test.cpp
---
