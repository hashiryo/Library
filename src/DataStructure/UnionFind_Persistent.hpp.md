---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/PersistentArray.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
    links:
    - https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/UnionFind_Persistent.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title Union-Find(\u5B8C\u5168\u6C38\u7D9A)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057 O(logN)\n */\n// verify\u7528\
    :\n// https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ call_from_test\n#include \"src/DataStructure/PersistentArray.hpp\"\n#undef call_from_test\n\
    #endif\n\nstruct UnionFind_Persistent {\n  PersistentArray<int> par;\n  UnionFind_Persistent()\
    \ {}\n  UnionFind_Persistent(int n) : par(n, -1) {}\n  bool unite(int u, int v)\
    \ {\n    if ((u = root(u)) == (v = root(v))) return false;\n    if (par.get(u)\
    \ > par.get(v)) swap(u, v);\n    par[u] += par.get(v), par[v] = u;\n    return\
    \ true;\n  }\n  bool same(int u, int v) { return root(u) == root(v); }\n  int\
    \ root(int u) { return par.get(u) < 0 ? u : root(par.get(u)); }\n  int size(int\
    \ u) { return -par.get(root(u)); }\n};\n"
  dependsOn:
  - src/DataStructure/PersistentArray.hpp
  isVerificationFile: false
  path: src/DataStructure/UnionFind_Persistent.hpp
  requiredBy: []
  timestamp: '2020-08-13 01:21:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: src/DataStructure/UnionFind_Persistent.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind_Persistent.hpp
- /library/src/DataStructure/UnionFind_Persistent.hpp.html
title: "Union-Find(\u5B8C\u5168\u6C38\u7D9A)"
---
