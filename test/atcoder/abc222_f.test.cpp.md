---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Graph/rerooting.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc222/tasks/abc222_f\"\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Graph/rerooting.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n Tree<long long> tree(N);\n for (int i= 0; i < N - 1; ++i)\
    \ {\n  int A, B, C;\n  cin >> A >> B >> C;\n  tree.add_edge(--A, --B, C);\n }\n\
    \ tree.build();\n vector<long long> D(N);\n for (int i= 0; i < N; ++i) cin >>\
    \ D[i];\n auto f_ee= [&](long long l, long long r) { return max(l, r); };\n auto\
    \ f_ve= [&](long long d, int, const auto& e) { return max(d, D[e.to]) + e.cost;\
    \ };\n auto f_ev= [&](long long d, int) { return d; };\n auto dp= rerooting<long\
    \ long>(tree, f_ee, f_ve, f_ev, 0ll);\n for (long long x: dp) cout << x << '\\\
    n';\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc222_f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc222_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc222_f.test.cpp
- /verify/test/atcoder/abc222_f.test.cpp.html
title: test/atcoder/abc222_f.test.cpp
---
