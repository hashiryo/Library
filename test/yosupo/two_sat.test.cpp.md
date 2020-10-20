---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/TwoSatisfiability.hpp: line 13: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#include \"src/Math/TwoSatisfiability.hpp\"\n#undef call_from_test\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  string s;\n  cin >> s\
    \ >> s;\n  int N, M;\n  cin >> N >> M;\n  TwoSatisfiability sat(N + 1);\n  for\
    \ (int i = 0; i < M; i++) {\n    int a, b;\n    cin >> a >> b >> s;\n    if (a\
    \ < 0) a = sat.neg(-a);\n    if (b < 0) b = sat.neg(-b);\n    sat.add_or(a, b);\n\
    \  }\n  auto ans = sat.solve();\n  cout << \"s \";\n  if (ans.size()) {\n    cout\
    \ << \"SATISFIABLE\" << endl;\n    cout << \"v \";\n    for (int i = 1; i <= N;\
    \ i++) {\n      cout << (ans[i] ? i : -i) << \" \";\n    }\n    cout << 0 << endl;\n\
    \  } else {\n    cout << \"UNSATISFIABLE\" << endl;\n  }\n  return 0;\n}"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Math/TwoSatisfiability.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-08-26 21:11:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
