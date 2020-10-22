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
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/Math/FormalPowerSeries.hpp\"\n#include \"src/Math/ModInt.hpp\"\n#undef\
    \ call_from_test\n\n// log(1+x^s_1)(1+x^s_2)...(1+x^s_N)=log(1+x^s_1)+log(1+x^s_2)+...log(1+x^s_N)\n\
    // log(1+x)=x-x^2/2+x^3/3-x^4/4...\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<998244353>;\n  using FPS = FormalPowerSeries<Mint>;\n \
    \ int N, T;\n  cin >> N >> T;\n  int c[T + 1];\n  fill(c, c + T + 1, 0);\n  for\
    \ (int i = 0; i < N; i++) {\n    int s;\n    cin >> s;\n    c[s]++;\n  }\n  FPS\
    \ a(T + 1);\n  for (int t = 1; t <= T; t++)\n    if (c[t]) {\n      for (int j\
    \ = 1; j * t <= T; j++) {\n        Mint tmp = Mint(c[t]) / Mint(j);\n        a[j\
    \ * t] += j & 1 ? tmp : -tmp;\n      }\n    }\n  FPS ans = a.exp();\n  for (int\
    \ t = 1; t <= T; t++) {\n    cout << (t ? \" \" : \"\") << ans[t];\n  }\n  cout\
    \ << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/FormalPowerSeries.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-22 09:30:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp.html
title: test/yosupo/sharp_p_subset_sum.test.cpp
---
