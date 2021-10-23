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
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc035/tasks/agc035_b\"\n#include\
    \ <bits/stdc++.h>\n#include \"Math/ModInt.hpp\"\n#include \"Graph/LinearSystemIncidence.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<2>;\n  int N, M;\n  cin >> N >> M;\n  LinearSystemIncidence<Mint>\
    \ lsi(N);\n  vector<Mint> b(N, 0);\n  pair<int, int> edges[M];\n  for (int i =\
    \ 0; i < M; i++) {\n    int A, B;\n    cin >> A >> B;\n    edges[i] = make_pair(A,\
    \ B);\n    lsi.add_edge(--A, --B);\n    b[B] += 1;\n  }\n  auto [isok, sol] =\
    \ lsi.solve(b);\n  if (isok) {\n    for (int i = 0; i < M; i++) {\n      auto\
    \ [A, B] = edges[i];\n      if (sol[i] == Mint(1))\n        cout << A << \" \"\
    \ << B << '\\n';\n      else\n        cout << B << \" \" << A << '\\n';\n    }\n\
    \  } else\n    cout << -1 << '\\n';\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/agc035_b.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/agc035_b.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/agc035_b.test.cpp
- /verify/test/atcoder/agc035_b.test.cpp.html
title: test/atcoder/agc035_b.test.cpp
---
