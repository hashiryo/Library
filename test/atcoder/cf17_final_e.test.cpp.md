---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Math/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e\"\
    \n#include <bits/stdc++.h>\n#include \"Math/ModInt.hpp\"\n#include \"Graph/LinearSystemIncidence.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<26>;\n  string S;\n  cin >> S;\n  int N, M = S.length()\
    \ + 1;\n  cin >> N;\n  LinearSystemIncidence<Mint> lsi((M + 1) / 2);\n  for (int\
    \ i = 0; i < N; i++) {\n    int L, R;\n    cin >> L >> R;\n    L--;\n    if (2\
    \ * L >= M) L = M - 1 - L;\n    if (2 * R >= M) R = M - 1 - R;\n    lsi.add_edge(L,\
    \ R);\n  }\n  vector<Mint> b((M + 1) / 2);\n  b[0] = S[0] - S.back();\n  for (int\
    \ i = 1; i < M / 2; i++)\n    b[i] = (S[i] - S[i - 1]) + (S[M - 1 - i] - S[M -\
    \ 2 - i]);\n  if (M & 1) b[M / 2] = S[M / 2] - S[M / 2 - 1];\n  auto [isok, sol]\
    \ = lsi.solve(b);\n  cout << (isok ? \"YES\" : \"NO\") << '\\n';\n  return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/cf17_final_e.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/cf17_final_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/cf17_final_e.test.cpp
- /verify/test/atcoder/cf17_final_e.test.cpp.html
title: test/atcoder/cf17_final_e.test.cpp
---
