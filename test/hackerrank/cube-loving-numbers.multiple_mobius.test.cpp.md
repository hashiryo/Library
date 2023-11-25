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
  code: "#define PROBLEM \"https://www.hackerrank.com/contests/university-codesprint-5/challenges/cube-loving-numbers\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Math/Sieve.hpp\"\n//\
    \ \u500D\u6570\u30E1\u30D3\u30A6\u30B9\nusing namespace std;\nsigned main() {\n\
    \ cin.tie(0);\n ios::sync_with_stdio(false);\n int T;\n cin >> T;\n long long\
    \ f[1'000'010];\n while (T--) {\n  long long N, a= 2, ans= 0;\n  cin >> N;\n \
    \ for (; a * a * a <= N; a++) f[a]= N / (a * a * a);\n  vector<long long> g(f,\
    \ f + a);\n  Sieve<>::multiple_mobius(g);\n  for (; --a >= 2;) ans+= g[a];\n \
    \ cout << ans << '\\n';\n }\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
- /verify/test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp.html
title: test/hackerrank/cube-loving-numbers.multiple_mobius.test.cpp
---
