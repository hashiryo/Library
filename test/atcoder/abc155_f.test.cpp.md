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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc155/tasks/abc155_f\"\n#include\
    \ <bits/stdc++.h>\n#include \"Math/ModInt.hpp\"\n#include \"Graph/LinearSystemIncidence.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = ModInt<2>;\n  int N, M;\n  cin >> N >> M;\n  pair<int, bool> AB[N\
    \ + 2];\n  AB[0] = {0, 0}, AB[N + 1] = {1e9 + 10, 0};\n  for (int i = 1; i <=\
    \ N; i++) cin >> AB[i].first >> AB[i].second;\n  sort(AB, AB + N + 2);\n  vector<Mint>\
    \ b(N + 1);\n  for (int i = 0; i <= N; i++) b[i] = AB[i + 1].second ^ AB[i].second;\n\
    \  LinearSystemIncidence<Mint> lsi(N + 1);\n  for (int i = 0; i < M; i++) {\n\
    \    int L, R;\n    cin >> L >> R;\n    L = lower_bound(AB, AB + N + 2, make_pair(L,\
    \ false)) - AB;\n    R = upper_bound(AB, AB + N + 2, make_pair(R, true)) - AB;\n\
    \    lsi.add_edge(L - 1, R - 1);\n  }\n  auto [isok, sol] = lsi.solve(b);\n  if\
    \ (isok) {\n    vector<int> ans;\n    for (int i = 0; i < M; i++)\n      if (sol[i]\
    \ != Mint(0)) ans.emplace_back(i + 1);\n    cout << ans.size() << '\\n';\n   \
    \ for (int i = 0; i < (int)ans.size(); i++) cout << (i ? \" \" : \"\") << ans[i];\n\
    \    cout << '\\n';\n  } else\n    cout << -1 << '\\n';\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc155_f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc155_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc155_f.test.cpp
- /verify/test/atcoder/abc155_f.test.cpp.html
title: test/atcoder/abc155_f.test.cpp
---
