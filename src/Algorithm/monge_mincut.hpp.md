---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/arc085_c.Dinic.test.cpp
    title: test/atcoder/arc085_c.Dinic.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc085_c.PushRelabel.test.cpp
    title: test/atcoder/arc085_c.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.Dinic.test.cpp
    title: test/atcoder/arc107_f.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.PushRelabel.test.cpp
    title: test/atcoder/arc107_f.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.Dinic.test.cpp
    title: test/atcoder/arc129_e.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.PushRelabel.test.cpp
    title: test/atcoder/arc129_e.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/119.Dinic.test.cpp
    title: test/yukicoder/119.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/119.PushRelabel.test.cpp
    title: test/yukicoder/119.PushRelabel.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\
      \u306E\u4E00\u822C\u5316"
    links:
    - https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h
    - https://noshi91.hatenablog.com/entry/2021/06/29/044225
  bundledCode: "#line 2 \"src/Algorithm/monge_mincut.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\
    \u4E00\u822C\u5316\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n * @see\
    \ https://noshi91.hatenablog.com/entry/2021/06/29/044225\n * phi\u95A2\u6570\u7B49\
    \u3067 \u221E \u3092\u8FD4\u3059\u3068\u304D\u306F\u305D\u306E\u5927\u304D\u3055\
    \u306B\u6CE8\u610F (\u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC)\n */\n\n// verify\u7528: https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename MF, typename Th, typename Ph>\nauto\
    \ monge_mincut(int n, int k, Th theta, Ph phi) {\n  using T = typename MF::flow_t;\n\
    \  static constexpr T INF = std::numeric_limits<T>::max();\n  T ret = 0;\n  MF\
    \ graph;\n  int s = graph.add_vertex(), t = graph.add_vertex();\n  std::vector<std::vector<int>>\
    \ x;\n  std::vector<std::vector<T>> th(n, std::vector<T>(k));\n  for (int i =\
    \ 0; i < n; i++) {\n    x.emplace_back(graph.add_vertices(k - 1));\n    for (int\
    \ l = 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1], INF);\n    for (int\
    \ l = 0; l < k; l++) th[i][l] = theta(i, l);\n  }\n  for (int i = 0; i < n; i++)\n\
    \    for (int j = i + 1; j < n; j++) {\n      for (int l = 0; l < k - 1; l++)\n\
    \        for (int m = 0; m < k - 1; m++) {\n          T cost = -phi(i, j, l +\
    \ 1, m + 1) + phi(i, j, l, m + 1) +\n                   phi(i, j, l + 1, m) -\
    \ phi(i, j, l, m);\n          assert(cost >= 0);  // monge\n          if (cost\
    \ > 0) graph.add_edge(x[i][l], x[j][m], cost);\n        }\n      for (int l =\
    \ 0; l < k; l++) th[i][l] += phi(i, j, l, k - 1);\n      for (int l = 0; l < k;\
    \ l++) th[j][l] += phi(i, j, 0, l);\n      ret -= phi(i, j, 0, k - 1);\n    }\n\
    \  for (int i = 0; i < n; i++) {\n    ret += th[i][0];\n    for (int l = 0; l\
    \ < k - 1; l++) {\n      T cost = th[i][l] - th[i][l + 1];\n      if (cost > 0)\
    \ graph.add_edge(s, x[i][l], cost), ret -= cost;\n      if (cost < 0) graph.add_edge(x[i][l],\
    \ t, -cost);\n    }\n  }\n  ret += graph.maxflow(s, t);\n  auto y = graph.mincut(s);\n\
    \  std::vector<int> sol(n, k - 1);\n  for (int i = 0; i < n; i++)\n    for (int\
    \ l = 0; l < k - 1; l++)\n      if (!y[x[i][l]]) sol[i] = l, l = k;\n  return\
    \ std::make_pair(ret, sol);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5C0F\u30AB\
    \u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\u4E00\u822C\u5316\n * @category\
    \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n * @see https://noshi91.hatenablog.com/entry/2021/06/29/044225\n\
    \ * phi\u95A2\u6570\u7B49\u3067 \u221E \u3092\u8FD4\u3059\u3068\u304D\u306F\u305D\
    \u306E\u5927\u304D\u3055\u306B\u6CE8\u610F (\u5927\u304D\u3059\u304E\u308B\u3068\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC)\n */\n\n// verify\u7528: https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h\n\
    \n// BEGIN CUT HERE\n\ntemplate <typename MF, typename Th, typename Ph>\nauto\
    \ monge_mincut(int n, int k, Th theta, Ph phi) {\n  using T = typename MF::flow_t;\n\
    \  static constexpr T INF = std::numeric_limits<T>::max();\n  T ret = 0;\n  MF\
    \ graph;\n  int s = graph.add_vertex(), t = graph.add_vertex();\n  std::vector<std::vector<int>>\
    \ x;\n  std::vector<std::vector<T>> th(n, std::vector<T>(k));\n  for (int i =\
    \ 0; i < n; i++) {\n    x.emplace_back(graph.add_vertices(k - 1));\n    for (int\
    \ l = 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1], INF);\n    for (int\
    \ l = 0; l < k; l++) th[i][l] = theta(i, l);\n  }\n  for (int i = 0; i < n; i++)\n\
    \    for (int j = i + 1; j < n; j++) {\n      for (int l = 0; l < k - 1; l++)\n\
    \        for (int m = 0; m < k - 1; m++) {\n          T cost = -phi(i, j, l +\
    \ 1, m + 1) + phi(i, j, l, m + 1) +\n                   phi(i, j, l + 1, m) -\
    \ phi(i, j, l, m);\n          assert(cost >= 0);  // monge\n          if (cost\
    \ > 0) graph.add_edge(x[i][l], x[j][m], cost);\n        }\n      for (int l =\
    \ 0; l < k; l++) th[i][l] += phi(i, j, l, k - 1);\n      for (int l = 0; l < k;\
    \ l++) th[j][l] += phi(i, j, 0, l);\n      ret -= phi(i, j, 0, k - 1);\n    }\n\
    \  for (int i = 0; i < n; i++) {\n    ret += th[i][0];\n    for (int l = 0; l\
    \ < k - 1; l++) {\n      T cost = th[i][l] - th[i][l + 1];\n      if (cost > 0)\
    \ graph.add_edge(s, x[i][l], cost), ret -= cost;\n      if (cost < 0) graph.add_edge(x[i][l],\
    \ t, -cost);\n    }\n  }\n  ret += graph.maxflow(s, t);\n  auto y = graph.mincut(s);\n\
    \  std::vector<int> sol(n, k - 1);\n  for (int i = 0; i < n; i++)\n    for (int\
    \ l = 0; l < k - 1; l++)\n      if (!y[x[i][l]]) sol[i] = l, l = k;\n  return\
    \ std::make_pair(ret, sol);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Algorithm/monge_mincut.hpp
  requiredBy: []
  timestamp: '2021-12-16 17:49:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/arc085_c.PushRelabel.test.cpp
  - test/atcoder/arc129_e.PushRelabel.test.cpp
  - test/atcoder/arc107_f.PushRelabel.test.cpp
  - test/atcoder/arc085_c.Dinic.test.cpp
  - test/atcoder/arc129_e.Dinic.test.cpp
  - test/atcoder/arc107_f.Dinic.test.cpp
  - test/yukicoder/119.Dinic.test.cpp
  - test/yukicoder/119.PushRelabel.test.cpp
documentation_of: src/Algorithm/monge_mincut.hpp
layout: document
redirect_from:
- /library/src/Algorithm/monge_mincut.hpp
- /library/src/Algorithm/monge_mincut.hpp.html
title: "\u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\u4E00\u822C\
  \u5316"
---
