---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/Sieve.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Math/Sieve.hpp\"\n#include \"\
    src/Math/ModInt.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector<Mint> a(N + 1),\
    \ b(N + 1);\n for (int i= 1; i <= N; i++) cin >> a[i];\n for (int i= 1; i <= N;\
    \ i++) cin >> b[i];\n auto c= Sieve<>::gcd_conv(a, b);\n for (int i= 1; i <= N;\
    \ i++) cout << c[i] << \" \\n\"[i == N];\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_convolution.test.cpp
- /verify/test/yosupo/gcd_convolution.test.cpp.html
title: test/yosupo/gcd_convolution.test.cpp
---
