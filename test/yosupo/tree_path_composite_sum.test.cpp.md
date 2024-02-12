---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Graph/rerooting.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/Graph/Tree.hpp\"\n#include \"src/Graph/rerooting.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using Mint=\
    \ ModInt<998244353>;\n int N;\n cin >> N;\n vector<Mint> a(N);\n for (int i= 0;\
    \ i < N; ++i) cin >> a[i];\n using Cost= pair<Mint, Mint>;\n Tree<Cost> tree(N);\n\
    \ for (int i= 0; i < N - 1; ++i) {\n  int u, v, b, c;\n  cin >> u >> v >> b >>\
    \ c;\n  tree.add_edge(u, v, Cost{b, c});\n }\n tree.build();\n using Data= pair<Mint,\
    \ int>;\n auto f_ee= [&](const Data &l, const Data &r) { return Data{l.first +\
    \ r.first, l.second + r.second}; };\n auto f_ev= [&](const Data &d, int v) { return\
    \ Data{d.first + a[v], d.second + 1}; };\n auto f_ve= [&](Data d, int, const auto\
    \ &e) {\n  d.first= e.cost.first * d.first + e.cost.second * d.second;\n  return\
    \ d;\n };\n auto dp= rerooting<Data>(tree, f_ee, f_ve, f_ev, Data{0, 0});\n for\
    \ (int i= 0; i < N; ++i) cout << dp[i].first << \" \\n\"[i == N - 1];\n return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_path_composite_sum.test.cpp
- /verify/test/yosupo/tree_path_composite_sum.test.cpp.html
title: test/yosupo/tree_path_composite_sum.test.cpp
---
