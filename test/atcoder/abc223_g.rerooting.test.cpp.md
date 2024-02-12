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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc223/tasks/abc223_g\"\n#include\
    \ <iostream>\n#include <algorithm>\n#include <array>\n#include \"src/Graph/rerooting.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n Tree tree(N);\n for (int i= 0; i < N - 1; ++i) {\n  int\
    \ u, v;\n  cin >> u >> v;\n  tree.add_edge(--u, --v);\n }\n tree.build();\n using\
    \ Data= array<int, 2>;\n auto f_ee= [&](const Data& l, const Data& r) { return\
    \ Data{l[0] + r[0], max(l[1], r[1])}; };\n auto f_ve= [&](const Data& d, int,\
    \ auto) {\n  auto x= max(d[0], d[1]);\n  return Data{x, d[0] + 1 - x};\n };\n\
    \ auto f_ev= [&](const Data& d, int) { return Data{d[0], d[0] + d[1]}; };\n auto\
    \ dp= rerooting<Data>(tree, f_ee, f_ve, f_ev, Data{0, 0});\n int mx= 0, ans= 0;\n\
    \ for (auto [x, y]: dp) mx= max({mx, x, y});\n for (auto [x, y]: dp) ans+= (mx\
    \ == x);\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc223_g.rerooting.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc223_g.rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc223_g.rerooting.test.cpp
- /verify/test/atcoder/abc223_g.rerooting.test.cpp.html
title: test/atcoder/abc223_g.rerooting.test.cpp
---
