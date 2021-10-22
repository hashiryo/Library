---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/EulerTourTree_Monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"src/DataStructure/EulerTourTree_Monoid.hpp\"\
    \nusing namespace std;\n\nstruct RsumQ {\n  using T = long long;\n  static T ti()\
    \ { return 0; }\n  static T op(const T &l, const T &r) { return l + r; }\n};\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  EulerTourTree_Monoid<RsumQ> ett(N);\n  for (int i = 0; i < N;\
    \ i++) {\n    long long a;\n    cin >> a;\n    ett.set_val(i, a);\n  }\n  for\
    \ (int i = 0; i < N - 1; i++) {\n    int u, v;\n    cin >> u >> v;\n    ett.link(v,\
    \ u);\n  }\n  while (Q--) {\n    int op;\n    cin >> op;\n    if (op == 0) {\n\
    \      int u, v, w, x;\n      cin >> u >> v >> w >> x;\n      ett.cut(u, v);\n\
    \      ett.link(w, x);\n    } else if (op == 1) {\n      int p;\n      long long\
    \ x;\n      cin >> p >> x;\n      ett.set_val(p, ett[p] + x);\n    } else {\n\
    \      int v, p;\n      cin >> v >> p;\n      cout << ett.fold_subtree(v, p) <<\
    \ endl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
---
