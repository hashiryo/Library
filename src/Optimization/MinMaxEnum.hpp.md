---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/Optimization/LiChaoTree.hpp
    title: Li-Chao-Tree
  - icon: ':question:'
    path: src/Optimization/NetworkSimplex.hpp
    title: "\u30CD\u30C3\u30C8\u30EF\u30FC\u30AF\u5358\u4F53\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/assignment.mcf.test.cpp
    title: test/yosupo/assignment.mcf.test.cpp
  - icon: ':x:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yosupo/min_cost_b_flow.test.cpp
    title: test/yosupo/min_cost_b_flow.test.cpp
  - icon: ':x:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1615.MCF.test.cpp
    title: test/yukicoder/1615.MCF.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "src/Optimization/MinMaxEnum.hpp"

    enum MinMaxEnum { MAXIMIZE= -1, MINIMIZE= 1 };

    '
  code: '#pragma once

    enum MinMaxEnum { MAXIMIZE= -1, MINIMIZE= 1 };'
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/MinMaxEnum.hpp
  requiredBy:
  - src/Optimization/NetworkSimplex.hpp
  - src/Optimization/LiChaoTree.hpp
  timestamp: '2023-08-10 14:03:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/line_add_get_min.test.cpp
  - test/yosupo/assignment.mcf.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/min_cost_b_flow.test.cpp
  - test/yukicoder/1615.MCF.test.cpp
  - test/aoj/GRL_6_B.test.cpp
documentation_of: src/Optimization/MinMaxEnum.hpp
layout: document
title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\u5217\
  \u6319\u578B"
---
