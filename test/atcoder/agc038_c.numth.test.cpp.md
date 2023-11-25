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
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc038/tasks/agc038_c\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/Math/Sieve.hpp\"\nusing namespace std;\n// O(MAX_A log log MAX_A)\n\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ const int MAX_A= 1e6;\n int N;\n cin >> N;\n vector<Mint> c(MAX_A + 1, 0);\n\
    \ Mint sum= 0;\n for (int i= 0, A; i < N; i++) cin >> A, c[A]+= A, sum+= A;\n\
    \ auto tmp= Sieve<>::gcd_conv(c, c);\n Mint sum2= 0;\n for (int d= 1; d <= MAX_A;\
    \ d++) sum2+= tmp[d] / d;\n cout << (sum2 - sum) / 2 << '\\n';\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/agc038_c.numth.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/agc038_c.numth.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc038_c.numth.test.cpp
- /verify/test/atcoder/agc038_c.numth.test.cpp.html
title: test/atcoder/agc038_c.numth.test.cpp
---
