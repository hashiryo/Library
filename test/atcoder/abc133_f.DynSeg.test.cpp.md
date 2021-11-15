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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/DataStructure/DynamicSegmentTree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc133/tasks/abc133_f\"\n\n\
    // \u6C38\u7D9A\u914D\u5217(at) \u306E verify\n\n#include <bits/stdc++.h>\n#include\
    \ \"src/DataStructure/DynamicSegmentTree.hpp\"\n#include \"src/DataStructure/LinkCutTree.hpp\"\
    \nusing namespace std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LinkCutTree lct(N);\n  vector<tuple<int, int,\
    \ int>> adj[N];\n  for (int i = 0; i < N - 1; i++) {\n    int a, b, c, d;\n  \
    \  cin >> a >> b >> c >> d;\n    lct.link(--a, --b);\n    adj[a].emplace_back(b,\
    \ c, d);\n    adj[b].emplace_back(a, c, d);\n  }\n  using PerArr = DynamicSegmentTree<int,\
    \ true, 17>;\n  PerArr Arr1[N], Arr2[N];\n  int sum[N];\n  sum[0] = 0;\n  auto\
    \ dfs = [&adj, &Arr1, &Arr2, &sum](auto f, int v, int p) -> void {\n    for (auto\
    \ [u, c, d] : adj[v])\n      if (u != p) {\n        Arr1[u] = Arr1[v];\n     \
    \   if (Arr1[u].is_null(c))\n          Arr1[u][c] = 1;\n        else\n       \
    \   Arr1[u][c] += 1;\n        Arr2[u] = Arr2[v];\n        if (Arr2[u].is_null(c))\n\
    \          Arr2[u][c] = d;\n        else\n          Arr2[u][c] += d;\n       \
    \ sum[u] = sum[v] + d;\n        f(f, u, v);\n      }\n  };\n  dfs(dfs, 0, -1);\n\
    \  lct.evert(0);\n  for (int i = 0; i < Q; i++) {\n    int x, y, u, v;\n    cin\
    \ >> x >> y >> u >> v;\n    int lca = lct.lca(--u, --v);\n    cout << sum[u] +\
    \ sum[v] - 2 * sum[lca] +\n                y * (Arr1[u].get(x) + Arr1[v].get(x)\
    \ - 2 * Arr1[lca].get(x)) -\n                (Arr2[u].get(x) + Arr2[v].get(x)\
    \ - 2 * Arr2[lca].get(x))\n         << '\\n';\n  }\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc133_f.DynSeg.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc133_f.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp
- /verify/test/atcoder/abc133_f.DynSeg.test.cpp.html
title: test/atcoder/abc133_f.DynSeg.test.cpp
---
