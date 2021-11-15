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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/DynamicSegmentTree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query\"\
    \n\n// \u6C38\u7D9A\u5316 \u306E verify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/DynamicSegmentTree.hpp\"\nusing namespace std;\n\nstruct\
    \ RMQ {\n  using T = int;\n  static T op(T l, T r) { return min(l, r); }\n  static\
    \ T ti() { return INT_MAX; }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N;\n  cin >> N;\n  int A[N];\n  for (int i = 0; i < N; i++) cin >> A[i];\n\
    \  int Q1;\n  cin >> Q1;\n  using Seg = DynamicSegmentTree<RMQ, true>;\n  Seg\
    \ seg[Q1 + 1] = {Seg(A, A + N)};\n  for (int i = 1; i <= Q1; i++) {\n    int p,\
    \ x;\n    cin >> p >> x;\n    seg[i] = seg[i - 1];\n    seg[i].set(--p, x);\n\
    \  }\n  int Q2;\n  cin >> Q2;\n  int X = 0;\n  for (int i = 0; i < Q2; i++) {\n\
    \    int a, b, c;\n    cin >> a >> b >> c;\n    int k = X ^ a, l = b ^ X, r =\
    \ c ^ X;\n    cout << (X = seg[k].fold(--l, r)) << '\\n';\n  }\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/hackerrank/minimum-history-query.DynSeg.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/hackerrank/minimum-history-query.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/hackerrank/minimum-history-query.DynSeg.test.cpp
- /verify/test/hackerrank/minimum-history-query.DynSeg.test.cpp.html
title: test/hackerrank/minimum-history-query.DynSeg.test.cpp
---
