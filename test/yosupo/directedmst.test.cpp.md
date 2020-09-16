---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SkewHeap.hpp
    title: Skew-Heap
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningAborescense.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Graph/MinimumSpanningAborescense.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/DataStructure/UnionFind.hpp\"\n#include \"src/DataStructure/SkewHeap.hpp\"\
    \n#include \"src/Graph/MinimumSpanningAborescense.hpp\"\n#undef call_from_test\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, M, r;\n\
    \  cin >> N >> M >> r;\n  MinimumSpanningAborescense<long long> graph(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n    graph.add_edge(s,\
    \ t, w);\n  }\n  auto ans = graph.get_MSA(r);\n  vector<int> par(N);\n  iota(par.begin(),\
    \ par.end(), 0);\n  for (auto e : ans.second) par[e.dst] = e.src;\n  cout << ans.first\
    \ << endl;\n  for (int i = 0; i < N; i++) cout << (i ? \" \" : \"\") << par[i];\n\
    \  cout << endl;\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/DataStructure/SkewHeap.hpp
  - src/Graph/MinimumSpanningAborescense.hpp
  isVerificationFile: true
  path: test/yosupo/directedmst.test.cpp
  requiredBy: []
  timestamp: '2020-08-19 16:25:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/directedmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/directedmst.test.cpp
- /verify/test/yosupo/directedmst.test.cpp.html
title: test/yosupo/directedmst.test.cpp
---
