---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: 2-SAT
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/TwoSatisfiability.hpp: line 13: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title 2-SAT\n * @category \u6570\u5B66\n *  \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3092\u7528\u3044\u308B\n *  solve():\u771F\u507D\u5024\u306E\
    \u5272\u5F53\u3092\u8FD4\u3059(\u5145\u8DB3\u4E0D\u53EF\u80FD\u306A\u3089\u7A7A\
    )\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"src/Graph/StronglyConnectedComponents.hpp\"\
    \n#undef call_from_test\n#endif\n\nstruct TwoSatisfiability {\n private:\n  int\
    \ sz;\n  StronglyConnectedComponents scc;\n\n public:\n  TwoSatisfiability(int\
    \ n) : sz(n), scc(2 * n) {}\n  void add_if(int u, int v) {\n    scc.add_edge(u,\
    \ v);\n    scc.add_edge(neg(v), neg(u));\n  }                                \
    \                   // u -> v <=> !v -> !u\n  void add_or(int u, int v) { add_if(neg(u),\
    \ v); }    // u or v <=> !u -> v\n  void add_nand(int u, int v) { add_if(u, neg(v));\
    \ }  // u nand v <=> u -> !v\n  void set_true(int u) { scc.add_edge(neg(u), u);\
    \ }   // u <=> !u -> u\n  void set_false(int u) { scc.add_edge(u, neg(u)); } \
    \ // !u <=> u -> !u\n  inline int neg(int x) { return x >= sz ? x - sz : x + sz;\
    \ }\n  vector<short> solve() {\n    vector<int> I = scc.get_SCC().second;\n  \
    \  vector<short> ret(sz);\n    for (int i = 0; i < sz; i++) {\n      if (I[i]\
    \ == I[neg(i)]) return {};\n      ret[i] = I[i] > I[neg(i)];\n    }\n    return\
    \ ret;\n  }\n};\n"
  dependsOn:
  - src/Graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: src/Math/TwoSatisfiability.hpp
  requiredBy: []
  timestamp: '2020-08-26 21:11:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: src/Math/TwoSatisfiability.hpp
layout: document
redirect_from:
- /library/src/Math/TwoSatisfiability.hpp
- /library/src/Math/TwoSatisfiability.hpp.html
title: 2-SAT
---
