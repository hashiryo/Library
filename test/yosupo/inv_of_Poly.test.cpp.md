---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/exgcd.hpp
    title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/inv_of_polynomials
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_polynomials\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/Math/FormalPowerSeries.hpp\"\n#include\
    \ \"src/Math/exgcd.hpp\"\n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using Mint = ModInt<998244353>;\n  using Poly =\
    \ FormalPowerSeries<Mint>;\n  int N, M;\n  cin >> N >> M;\n  Poly f(N), g(M),\
    \ x, y;\n  for (int i = 0; i < N; i++) cin >> f[i];\n  for (int i = 0; i < M;\
    \ i++) cin >> g[i];\n  Poly d = exgcd(f, g, x, y);\n  if (d.deg() != 0) {\n  \
    \  cout << -1 << '\\n';\n  } else {\n    if (x.deg() == -1) {\n      cout << 0\
    \ << '\\n';\n    } else {\n      cout << x.size() << '\\n';\n      x /= d[0];\n\
    \      for (size_t i = 0; i < x.size(); i++) cout << (i ? \" \" : \"\") << x[i];\n\
    \      cout << '\\n';\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  - src/Math/exgcd.hpp
  isVerificationFile: true
  path: test/yosupo/inv_of_Poly.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 15:28:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/inv_of_Poly.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/inv_of_Poly.test.cpp
- /verify/test/yosupo/inv_of_Poly.test.cpp.html
title: test/yosupo/inv_of_Poly.test.cpp
---
