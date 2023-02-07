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
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc097/tasks/arc097_d\"\n#include\
    \ <iostream>\n#include <string>\n#include <array>\n#include <tuple>\n#include\
    \ <algorithm>\n#include \"src/Graph/rerooting.hpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n Tree\
    \ tree(N);\n for (int i= 0; i < N - 1; ++i) {\n  int x, y;\n  cin >> x >> y;\n\
    \  tree.add_edge(--x, --y);\n }\n tree.build();\n string c;\n cin >> c;\n using\
    \ Dat= array<int, 2>;\n using Data= tuple<bool, int, int>;\n auto f_ee= [&](const\
    \ Data &l, const Data &r) { return Data{get<0>(l) ^ get<0>(r), get<1>(l) + get<1>(r),\
    \ max(get<2>(l), get<2>(r))}; };\n auto f_ve= [&](const Dat &d, int, auto) { return\
    \ d[1] ? Data{1, 2 + d[0], d[0] - d[1] + 1} : Data{0, 0, 0}; };\n auto f_ev= [&](const\
    \ Data &d, int v) {\n  auto [b, x, y]= d;\n  b^= (c[v] == 'B');\n  return Dat{x\
    \ + b, x - y + !b};\n };\n auto dp= rerooting<Dat>(tree, f_ee, f_ve, f_ev, Data{0,\
    \ 0, 0});\n int ans= 1 << 30;\n for (auto [_, x]: dp) ans= min(ans, x);\n cout\
    \ << ans << '\\n';\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/arc097_d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc097_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc097_d.test.cpp
- /verify/test/atcoder/arc097_d.test.cpp.html
title: test/atcoder/arc097_d.test.cpp
---
