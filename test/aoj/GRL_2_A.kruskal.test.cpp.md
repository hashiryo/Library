---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: src/Graph/MinimumSpanningTree_Kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728(Kruskal)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Graph/MinimumSpanningTree_Kruskal.hpp: line 13: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/DataStructure/UnionFind.hpp\"\n#include \"src/Graph/MinimumSpanningTree_Kruskal.hpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int N, M;\n  cin >> N >> M;\n  MinimumSpanningTree_Kruskal<int> graph(N);\n\
    \  for (int i = 0; i < M; i++) {\n    int s, t, w;\n    cin >> s >> t >> w;\n\
    \    graph.add_edge(s, t, w);\n  }\n  cout << graph.get_MST().first << endl;\n\
    \  return 0;\n}"
  dependsOn:
  - src/DataStructure/UnionFind.hpp
  - src/Graph/MinimumSpanningTree_Kruskal.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp.html
title: test/aoj/GRL_2_A.kruskal.test.cpp
---