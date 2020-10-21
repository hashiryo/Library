---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/FormalPowerSeries.hpp: line 12: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n// \u6728\u306E\u91CD\u5FC3\u5206\u89E3\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define call_from_test\n#include \"src/Math/ModInt.hpp\"\n\
    #include \"src/Math/FormalPowerSeries.hpp\"\n#undef call_from_test\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using FPS = FormalPowerSeries<long\
    \ long>;\n  int N;\n  cin >> N;\n  vector<int> tree[N];\n  for (int i = 0; i <\
    \ N - 1; i++) {\n    int u, v;\n    cin >> u >> v;\n    tree[u].push_back(v);\n\
    \    tree[v].push_back(u);\n  }\n\n  bool used[N];\n  fill(used, used + N, false);\n\
    \  int sz[N];\n  function<int(int, int)> sz_dfs = [&](int v, int p) {\n    sz[v]\
    \ = 1;\n    for (int u : tree[v])\n      if (u != p && !used[u]) sz[v] += sz_dfs(u,\
    \ v);\n    return sz[v];\n  };\n  function<int(int, int, int)> centroid = [&](int\
    \ v, int p, int mid) {\n    for (int u : tree[v])\n      if (u != p && !used[u]\
    \ && sz[u] > mid) return centroid(u, v, mid);\n    return v;\n  };\n\n  FPS ans(N\
    \ + 1);\n  function<void(int)> dfs = [&](int rt) {\n    int c = centroid(rt, -1,\
    \ sz_dfs(rt, -1) / 2);\n    used[c] = true;\n    FPS cnt({1});\n    for (int ch\
    \ : tree[c])\n      if (!used[ch]) {\n        queue<tuple<int, int, int>> que;\n\
    \        que.emplace(ch, c, 1);\n        FPS num;\n        while (!que.empty())\
    \ {\n          int v, p, d;\n          tie(v, p, d) = que.front();\n         \
    \ que.pop();\n          if (d >= (int)num.size()) num.resize(d + 1, 0);\n    \
    \      num[d] += 1;\n          for (int u : tree[v])\n            if (u != p &&\
    \ !used[u]) que.emplace(u, v, d + 1);\n        }\n        cnt += num;\n      \
    \  ans -= num * num;\n      }\n    ans += cnt * cnt;\n    for (int next : tree[c])\n\
    \      if (!used[next]) dfs(next);\n  };\n  dfs(0);\n  ans /= 2;\n  for (int i\
    \ = 1; i < N; i++) cout << (i > 1 ? \" \" : \"\") << ans[i];\n  cout << '\\n';\n\
    \  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 17:49:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
