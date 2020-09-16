---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind_Persistent.hpp
    title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/UnionFind_Persistent.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/DataStructure/PersistentArray.hpp\"\n#include \"src/DataStructure/UnionFind_Persistent.hpp\"\
    \n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<UnionFind_Persistent> uf(Q + 1);\n  uf[0]\
    \ = UnionFind_Persistent(N);\n  for (int i = 1; i <= Q; i++) {\n    int t, k,\
    \ u, v;\n    cin >> t >> k >> u >> v;\n    k++;\n    if (t) {\n      cout << uf[k].same(u,\
    \ v) << endl;\n    } else {\n      uf[i] = uf[k];\n      uf[i].unite(u, v);\n\
    \    }\n  }\n}\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  - src/DataStructure/UnionFind_Persistent.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-08-13 01:21:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
