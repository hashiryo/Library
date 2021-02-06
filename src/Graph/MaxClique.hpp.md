---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  - icon: ':x:'
    path: test/yukicoder/382.test.cpp
    title: test/yukicoder/382.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6700\u5927\u30AF\u30EA\u30FC\u30AF"
    links:
    - https://www.jstage.jst.go.jp/article/ipsjjip/25/0/25_667/_pdf
  bundledCode: "#line 2 \"src/Graph/MaxClique.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title \u6700\u5927\u30AF\u30EA\u30FC\u30AF\n * @category \u30B0\u30E9\u30D5\
    \n * @see https://www.jstage.jst.go.jp/article/ipsjjip/25/0/25_667/_pdf\n * \u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\u306F\u88DC\u30B0\u30E9\u30D5\u306E\u6700\u5927\
    \u30AF\u30EA\u30FC\u30AF\n * \u6700\u5C0F\u9802\u70B9\u88AB\u8986\u306F\u6700\u5927\
    \u72EC\u7ACB\u96C6\u5408\u306E\u88DC\u96C6\u5408\n * 120\u9802\u70B9\u3050\u3089\
    \u3044\u306F\u3044\u3051\u308B\n */\n\n// BEGIN CUT HERE\n\nclass MaxClique {\n\
    \  struct id_num {\n    std::size_t id, num;\n  };\n  std::vector<std::bitset<128>>\
    \ adj, buf;\n  std::bitset<128> clique, cur;\n  std::vector<int> deg;\n  void\
    \ dfs(std::vector<id_num>& rem) {\n    if (clique.count() < cur.count()) clique\
    \ = cur;\n    std::sort(rem.begin(), rem.end(),\n              [&](id_num l, id_num\
    \ r) { return deg[l.id] > deg[r.id]; });\n    std::size_t max_num = 1;\n    for\
    \ (auto& v : rem) {\n      v.num = 0;\n      while ((adj[v.id] & buf[v.num]).any())\
    \ v.num++;\n      buf[v.num].set(v.id), max_num = std::max(max_num, v.num + 1);\n\
    \    }\n    for (int i = max_num - 1; i >= 0; i--) buf[i].reset();\n    std::sort(rem.begin(),\
    \ rem.end(),\n              [&](id_num l, id_num r) { return l.num < r.num; });\n\
    \    std::vector<id_num> nrem;\n    while (!rem.empty() && rem.back().num + cur.count()\
    \ >= clique.count()) {\n      for (auto u : rem)\n        if (adj[rem.back().id][u.id])\
    \ nrem.emplace_back(u), buf[0].set(u.id);\n      for (auto u : nrem) deg[u.id]\
    \ = (buf[0] & adj[u.id]).count();\n      buf[0].reset(), cur.set(rem.back().id);\n\
    \      dfs(nrem);\n      nrem.clear(), cur.reset(rem.back().id), rem.pop_back();\n\
    \    }\n  }\n\n public:\n  MaxClique(int n_) : adj(n_), buf(n_ + 1), deg(n_) {}\n\
    \  void add_edge(int u, int v) { adj[u][v] = adj[v][u] = true; }\n  std::vector<int>\
    \ get_max_clique() {\n    std::vector<id_num> nrem;\n    for (int i = adj.size()\
    \ - 1; i >= 0; i--)\n      nrem.emplace_back(id_num{(std::size_t)i, 0}), deg[i]\
    \ = adj[i].count();\n    dfs(nrem);\n    std::vector<int> ret;\n    for (int i\
    \ = 0, n = adj.size(); i < n; i++)\n      if (clique[i]) ret.push_back(i);\n \
    \   return ret;\n  }\n  std::vector<int> get_max_independent_set() {\n    for\
    \ (int i = adj.size() - 1; i >= 0; i--)\n      for (int j = i - 1; j >= 0; j--)\
    \ adj[i][j] = adj[j][i] = ~adj[j][i];\n    return get_max_clique();\n  }\n  std::vector<int>\
    \ get_min_vertex_cover() {\n    get_max_independent_set();\n    std::vector<int>\
    \ ret;\n    for (int i = 0, n = adj.size(); i < n; i++)\n      if (!clique[i])\
    \ ret.push_back(i);\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5927\u30AF\
    \u30EA\u30FC\u30AF\n * @category \u30B0\u30E9\u30D5\n * @see https://www.jstage.jst.go.jp/article/ipsjjip/25/0/25_667/_pdf\n\
    \ * \u6700\u5927\u72EC\u7ACB\u96C6\u5408\u306F\u88DC\u30B0\u30E9\u30D5\u306E\u6700\
    \u5927\u30AF\u30EA\u30FC\u30AF\n * \u6700\u5C0F\u9802\u70B9\u88AB\u8986\u306F\u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\u306E\u88DC\u96C6\u5408\n * 120\u9802\u70B9\u3050\
    \u3089\u3044\u306F\u3044\u3051\u308B\n */\n\n// BEGIN CUT HERE\n\nclass MaxClique\
    \ {\n  struct id_num {\n    std::size_t id, num;\n  };\n  std::vector<std::bitset<128>>\
    \ adj, buf;\n  std::bitset<128> clique, cur;\n  std::vector<int> deg;\n  void\
    \ dfs(std::vector<id_num>& rem) {\n    if (clique.count() < cur.count()) clique\
    \ = cur;\n    std::sort(rem.begin(), rem.end(),\n              [&](id_num l, id_num\
    \ r) { return deg[l.id] > deg[r.id]; });\n    std::size_t max_num = 1;\n    for\
    \ (auto& v : rem) {\n      v.num = 0;\n      while ((adj[v.id] & buf[v.num]).any())\
    \ v.num++;\n      buf[v.num].set(v.id), max_num = std::max(max_num, v.num + 1);\n\
    \    }\n    for (int i = max_num - 1; i >= 0; i--) buf[i].reset();\n    std::sort(rem.begin(),\
    \ rem.end(),\n              [&](id_num l, id_num r) { return l.num < r.num; });\n\
    \    std::vector<id_num> nrem;\n    while (!rem.empty() && rem.back().num + cur.count()\
    \ >= clique.count()) {\n      for (auto u : rem)\n        if (adj[rem.back().id][u.id])\
    \ nrem.emplace_back(u), buf[0].set(u.id);\n      for (auto u : nrem) deg[u.id]\
    \ = (buf[0] & adj[u.id]).count();\n      buf[0].reset(), cur.set(rem.back().id);\n\
    \      dfs(nrem);\n      nrem.clear(), cur.reset(rem.back().id), rem.pop_back();\n\
    \    }\n  }\n\n public:\n  MaxClique(int n_) : adj(n_), buf(n_ + 1), deg(n_) {}\n\
    \  void add_edge(int u, int v) { adj[u][v] = adj[v][u] = true; }\n  std::vector<int>\
    \ get_max_clique() {\n    std::vector<id_num> nrem;\n    for (int i = adj.size()\
    \ - 1; i >= 0; i--)\n      nrem.emplace_back(id_num{(std::size_t)i, 0}), deg[i]\
    \ = adj[i].count();\n    dfs(nrem);\n    std::vector<int> ret;\n    for (int i\
    \ = 0, n = adj.size(); i < n; i++)\n      if (clique[i]) ret.push_back(i);\n \
    \   return ret;\n  }\n  std::vector<int> get_max_independent_set() {\n    for\
    \ (int i = adj.size() - 1; i >= 0; i--)\n      for (int j = i - 1; j >= 0; j--)\
    \ adj[i][j] = adj[j][i] = ~adj[j][i];\n    return get_max_clique();\n  }\n  std::vector<int>\
    \ get_min_vertex_cover() {\n    get_max_independent_set();\n    std::vector<int>\
    \ ret;\n    for (int i = 0, n = adj.size(); i < n; i++)\n      if (!clique[i])\
    \ ret.push_back(i);\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/MaxClique.hpp
  requiredBy: []
  timestamp: '2021-02-02 14:03:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/maximum_independent_set.test.cpp
  - test/yukicoder/382.test.cpp
documentation_of: src/Graph/MaxClique.hpp
layout: document
redirect_from:
- /library/src/Graph/MaxClique.hpp
- /library/src/Graph/MaxClique.hpp.html
title: "\u6700\u5927\u30AF\u30EA\u30FC\u30AF"
---
