---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  - icon: ':x:'
    path: test/yukicoder/119.Dinic.test.cpp
    title: test/yukicoder/119.Dinic.test.cpp
  - icon: ':x:'
    path: test/yukicoder/119.PushRelabel.test.cpp
    title: test/yukicoder/119.PushRelabel.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/monge_mincut.hpp\"\n#include <vector>\n\
    #include <limits>\n#include <cassert>\n#include <utility>\ntemplate <typename\
    \ MF, typename Th, typename Ph> auto monge_mincut(int n, int k, Th theta, Ph phi)\
    \ {\n using T= typename MF::flow_t;\n static constexpr T INF= std::numeric_limits<T>::max();\n\
    \ T ret= 0;\n MF graph;\n int s= graph.add_vertex(), t= graph.add_vertex();\n\
    \ std::vector<std::vector<int>> x;\n std::vector<std::vector<T>> th(n, std::vector<T>(k));\n\
    \ for (int i= 0; i < n; i++) {\n  x.emplace_back(graph.add_vertices(k - 1));\n\
    \  for (int l= 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1], INF);\n\
    \  for (int l= 0; l < k; l++) th[i][l]= theta(i, l);\n }\n for (int i= 0; i <\
    \ n; i++)\n  for (int j= i + 1; j < n; j++) {\n   for (int l= 0; l < k - 1; l++)\n\
    \    for (int m= 0; m < k - 1; m++) {\n     T cost= -phi(i, j, l + 1, m + 1) +\
    \ phi(i, j, l, m + 1) + phi(i, j, l + 1, m) - phi(i, j, l, m);\n     assert(cost\
    \ >= 0);  // monge\n     if (cost > 0) graph.add_edge(x[i][l], x[j][m], cost);\n\
    \    }\n   for (int l= 0; l < k; l++) th[i][l]+= phi(i, j, l, k - 1);\n   for\
    \ (int l= 0; l < k; l++) th[j][l]+= phi(i, j, 0, l);\n   ret-= phi(i, j, 0, k\
    \ - 1);\n  }\n for (int i= 0; i < n; i++) {\n  ret+= th[i][0];\n  for (int l=\
    \ 0; l < k - 1; l++) {\n   T cost= th[i][l] - th[i][l + 1];\n   if (cost > 0)\
    \ graph.add_edge(s, x[i][l], cost), ret-= cost;\n   if (cost < 0) graph.add_edge(x[i][l],\
    \ t, -cost);\n  }\n }\n ret+= graph.maxflow(s, t);\n auto y= graph.mincut(s);\n\
    \ std::vector<int> sol(n, k - 1);\n for (int i= 0; i < n; i++)\n  for (int l=\
    \ 0; l < k - 1; l++)\n   if (!y[x[i][l]]) sol[i]= l, l= k;\n return std::make_pair(ret,\
    \ sol);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include <cassert>\n\
    #include <utility>\ntemplate <typename MF, typename Th, typename Ph> auto monge_mincut(int\
    \ n, int k, Th theta, Ph phi) {\n using T= typename MF::flow_t;\n static constexpr\
    \ T INF= std::numeric_limits<T>::max();\n T ret= 0;\n MF graph;\n int s= graph.add_vertex(),\
    \ t= graph.add_vertex();\n std::vector<std::vector<int>> x;\n std::vector<std::vector<T>>\
    \ th(n, std::vector<T>(k));\n for (int i= 0; i < n; i++) {\n  x.emplace_back(graph.add_vertices(k\
    \ - 1));\n  for (int l= 1; l < k - 1; l++) graph.add_edge(x[i][l], x[i][l - 1],\
    \ INF);\n  for (int l= 0; l < k; l++) th[i][l]= theta(i, l);\n }\n for (int i=\
    \ 0; i < n; i++)\n  for (int j= i + 1; j < n; j++) {\n   for (int l= 0; l < k\
    \ - 1; l++)\n    for (int m= 0; m < k - 1; m++) {\n     T cost= -phi(i, j, l +\
    \ 1, m + 1) + phi(i, j, l, m + 1) + phi(i, j, l + 1, m) - phi(i, j, l, m);\n \
    \    assert(cost >= 0);  // monge\n     if (cost > 0) graph.add_edge(x[i][l],\
    \ x[j][m], cost);\n    }\n   for (int l= 0; l < k; l++) th[i][l]+= phi(i, j, l,\
    \ k - 1);\n   for (int l= 0; l < k; l++) th[j][l]+= phi(i, j, 0, l);\n   ret-=\
    \ phi(i, j, 0, k - 1);\n  }\n for (int i= 0; i < n; i++) {\n  ret+= th[i][0];\n\
    \  for (int l= 0; l < k - 1; l++) {\n   T cost= th[i][l] - th[i][l + 1];\n   if\
    \ (cost > 0) graph.add_edge(s, x[i][l], cost), ret-= cost;\n   if (cost < 0) graph.add_edge(x[i][l],\
    \ t, -cost);\n  }\n }\n ret+= graph.maxflow(s, t);\n auto y= graph.mincut(s);\n\
    \ std::vector<int> sol(n, k - 1);\n for (int i= 0; i < n; i++)\n  for (int l=\
    \ 0; l < k - 1; l++)\n   if (!y[x[i][l]]) sol[i]= l, l= k;\n return std::make_pair(ret,\
    \ sol);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/monge_mincut.hpp
  requiredBy: []
  timestamp: '2023-01-21 23:17:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/119.PushRelabel.test.cpp
  - test/yukicoder/119.Dinic.test.cpp
  - test/atcoder/arc129_e.PushRelabel.test.cpp
  - test/atcoder/arc129_e.Dinic.test.cpp
  - test/atcoder/arc107_f.Dinic.test.cpp
  - test/atcoder/arc107_f.PushRelabel.test.cpp
documentation_of: src/Optimization/monge_mincut.hpp
layout: document
title: "\u6700\u5C0F\u30AB\u30C3\u30C8\u554F\u984C\u306Ek\u5024\u3078\u306E\u4E00\u822C\
  \u5316"
---
phi関数等で ∞ を返すときはその大きさに注意 (大きすぎるとオーバーフロー)

## 問題例
[Kyoto University Programming Contest 2019 H - 123パズル](https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h)

## 参考
[https://noshi91.hatenablog.com/entry/2021/06/29/044225](https://noshi91.hatenablog.com/entry/2021/06/29/044225)