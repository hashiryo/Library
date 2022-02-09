---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: hafnian.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"hafnian.hpp\"\n\
    using namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  int N;\n  cin >> N;\n  vector<vector<Mint>>\
    \ a(N, vector<Mint>(N));\n  for (int i = 0; i < N; i++)\n    for (int j = 0; j\
    \ < N; j++) cin >> a[i][j];\n  cout << hafnian(a) << '\\n';\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/hafnian_of_matrix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/hafnian_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/hafnian_of_matrix.test.cpp
- /verify/test/yosupo/hafnian_of_matrix.test.cpp.html
title: test/yosupo/hafnian_of_matrix.test.cpp
---
