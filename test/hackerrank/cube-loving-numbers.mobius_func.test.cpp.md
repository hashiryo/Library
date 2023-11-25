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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/multiplicative_and_additive.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers\"\
    \n#include <iostream>\n#include \"src/Math/multiplicative_and_additive.hpp\"\n\
    #include \"src/Math/Sieve.hpp\"\n// \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using namespace multiplicative_functions;\n int T;\n cin >> T;\n auto mu= Sieve<>::multiplicative_table<long\
    \ long>(1'000'010, Moebius<long long>::f);\n while (T--) {\n  long long N, ans=\
    \ 0;\n  cin >> N;\n  for (long long x= 2; x * x * x <= N; x++) ans-= N / (x *\
    \ x * x) * mu[x];\n  cout << ans << '\\n';\n }\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
- /verify/test/hackerrank/cube-loving-numbers.mobius_func.test.cpp.html
title: test/hackerrank/cube-loving-numbers.mobius_func.test.cpp
---
