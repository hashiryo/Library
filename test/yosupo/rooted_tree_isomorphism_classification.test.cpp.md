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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n#include <iostream>\n#include \"src/Misc/compress.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/Graph/rerooting.hpp\"\n#include \"src/Misc/rng.hpp\"\n#include\
    \ \"src/Misc/Pointwise.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(0);\n int N;\n cin >> N;\n Tree tree(N);\n for (int i=\
    \ 1; i < N; ++i) {\n  int p;\n  cin >> p;\n  tree.add_edge(p, i);\n }\n tree.build(0);\n\
    \ using Mint= ModInt<(1ll << 61) - 1>;\n using K= Pointwise<Mint, Mint>;\n using\
    \ Data= pair<int, K>;\n vector<K> hash(N);\n for (auto& x: hash) x= {rng(2, Mint::mod()\
    \ - 1), rng(2, Mint::mod() - 1)};\n auto f_ee= [&](const Data& l, const Data&\
    \ r) { return Data{max(l.first, r.first), l.second * r.second}; };\n auto f_ve=\
    \ [&](const Data& d, int, auto) { return Data{d.first, d.second + hash[d.first]};\
    \ };\n auto f_ev= [&](const Data& d, int) { return Data{d.first + 1, d.second};\
    \ };\n auto dp= rerooting<Data>(tree, f_ee, f_ve, f_ev, Data{0, K{1, 1}});\n vector<K>\
    \ ans(N);\n for (int i= 0; i < N; ++i) ans[i]= dp.get(0, i).second;\n auto vec=\
    \ ans;\n auto id= compress(vec);\n cout << vec.size() << '\\n';\n for (int i=\
    \ 0; i < N; ++i) cout << id(ans[i]) << \" \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rooted_tree_isomorphism_classification.test.cpp
- /verify/test/yosupo/rooted_tree_isomorphism_classification.test.cpp.html
title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
---
