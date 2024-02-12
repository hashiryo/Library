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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc160/tasks/abc160_f\"\n#include\
    \ <iostream>\n#include <algorithm>\n#include \"src/Math/ModInt.hpp\"\n#include\
    \ \"src/Math/FactorialPrecalculation.hpp\"\n#include \"src/Graph/rerooting.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<int(1e9 + 7)>;\n using F= FactorialPrecalculation<Mint>;\n\
    \ int N;\n cin >> N;\n Tree tree(N);\n for (int i= 0; i < N - 1; ++i) {\n  int\
    \ a, b;\n  cin >> a >> b;\n  tree.add_edge(--a, --b);\n }\n tree.build();\n using\
    \ Data= pair<int, Mint>;\n auto f_ee= [&](const Data &l, const Data &r) { return\
    \ Data{l.first + r.first, F::nCr(l.first + r.first, l.first) * l.second * r.second};\
    \ };\n auto f_ve= [&](const Data &d, int, auto) { return d; };\n auto f_ev= [&](const\
    \ Data &d, int) { return Data{d.first + 1, d.second}; };\n auto dp= rerooting<Data>(tree,\
    \ f_ee, f_ve, f_ev, Data{0, 1});\n for (auto [_, x]: dp) cout << x << '\\n';\n\
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc160_f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc160_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc160_f.test.cpp
- /verify/test/atcoder/abc160_f.test.cpp.html
title: test/atcoder/abc160_f.test.cpp
---
