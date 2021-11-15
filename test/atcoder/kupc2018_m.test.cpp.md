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
  code: "#define PROBLEM \"https://atcoder.jp/contests/kupc2018/tasks/kupc2018_m\"\
    \n\n// \u30D1\u30C8\u30EA\u30B7\u30A2\u6728 \u3068 fold + xor \u306E verify\n\n\
    #include <bits/stdc++.h>\n#include \"src/DataStructure/DynamicSegmentTree.hpp\"\
    \n#include \"src/Graph/HeavyLightDecomposition.hpp\"\nusing namespace std;\n\n\
    struct RsumQ {\n  using T = long long;\n  static T ti() { return 0; }\n  static\
    \ T op(T vl, T vr) { return vl + vr; }\n};\nsigned main() {\n  cin.tie(0);\n \
    \ ios::sync_with_stdio(0);\n  using Seg = DynamicSegmentTree<RsumQ, false, 30,\
    \ true>;\n  int N;\n  cin >> N;\n  HeavyLightDecomposition hld(N);\n  for (int\
    \ i = 0; i < N - 1; i++) {\n    int a, b;\n    cin >> a >> b;\n    hld.add_edge(--a,\
    \ --b);\n  }\n  hld.build(0);\n  int m = 1;\n  while (m < N) m <<= 1;\n  Seg ET[2\
    \ * m];\n  int Q;\n  cin >> Q;\n  int root = 0;\n  for (int i = 0; i < Q; i++)\
    \ {\n    int op, v;\n    cin >> op >> v;\n    v--;\n    if (op == 1) {\n     \
    \ int x;\n      long long k;\n      cin >> x >> k;\n      int l, r;\n      if\
    \ (root == v) {\n        ET[1].set(x, ET[1].get(x) + k);\n      } else if (hld.in[v]\
    \ < hld.in[root] &&\n                 hld.in[root] < hld.out[hld.in[v]]) {\n \
    \       int u = root;\n        while (hld.head[v] != hld.head[u]) {\n        \
    \  if (v == hld.par[hld.head[u]]) {\n            l = hld.in[hld.head[u]];\n  \
    \          r = hld.out[hld.in[hld.head[u]]];\n            break;\n          }\n\
    \          u = hld.par[hld.head[u]];\n        }\n        if (hld.head[v] == hld.head[u])\
    \ {\n          l = hld.in[v] + 1;\n          r = hld.out[hld.in[v] + 1];\n   \
    \     }\n        for (l += m, r += m; l < r; l >>= 1, r >>= 1) {\n          if\
    \ (l & 1) ET[l].set(x, ET[l].get(x) - k), l++;\n          if (r & 1) --r, ET[r].set(x,\
    \ ET[r].get(x) - k);\n        }\n        ET[1].set(x, ET[1].get(x) + k);\n   \
    \   } else {\n        l = hld.in[v];\n        r = hld.out[hld.in[v]];\n      \
    \  for (l += m, r += m; l < r; l >>= 1, r >>= 1) {\n          if (l & 1) ET[l].set(x,\
    \ ET[l].get(x) + k), l++;\n          if (r & 1) --r, ET[r].set(x, ET[r].get(x)\
    \ + k);\n        }\n      }\n    } else if (op == 2) {\n      int y, z;\n    \
    \  long long ans = 0;\n      cin >> y >> z;\n      for (int i = hld.in[v] + m;\
    \ i; i >>= 1) {\n        ans += ET[i].fold(0, z + 1, y);\n      }\n      cout\
    \ << ans << '\\n';\n    } else {\n      root = v;\n    }\n  }\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/kupc2018_m.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/kupc2018_m.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/kupc2018_m.test.cpp
- /verify/test/atcoder/kupc2018_m.test.cpp.html
title: test/atcoder/kupc2018_m.test.cpp
---
