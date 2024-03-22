---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2306.test.cpp
    title: test/aoj/2306.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3168.clique.test.cpp
    title: test/aoj/3168.clique.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.clique.test.cpp
    title: test/aoj/GRL_7_A.clique.test.cpp
  - icon: ':x:'
    path: test/yosupo/enumerate_cliques.test.cpp
    title: test/yosupo/enumerate_cliques.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/CliqueProblem.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\nclass CliqueProblem {\n using u128= __uint128_t;\n using u64= unsigned\
    \ long long;\n using u16= unsigned short;\n const u16 n, m;\n struct id_num {\n\
    \  u16 id, num;\n };\n std::vector<u128> adj_;\n std::vector<u16> calc(bool complement)\
    \ const {\n  std::vector<u128> buf, adj(adj_);\n  std::vector<u16> deg(n), clique,\
    \ cur;\n  if (complement)\n   for (int u= n; u--;)\n    for (int v= u; v--;) adj[u\
    \ * m + (v >> 7)]^= u128(1) << (v & 127), adj[v * m + (u >> 7)]^= u128(1) << (u\
    \ & 127);\n  auto dfs= [&](auto dfs, std::vector<id_num> &rem) -> void {\n   if\
    \ (clique.size() < cur.size()) clique= cur;\n   std::sort(rem.begin(), rem.end(),\
    \ [&](id_num l, id_num r) { return deg[l.id] > deg[r.id]; }), buf.assign((n +\
    \ 1) * m, 0);\n   for (auto &v: rem) {\n    int b= v.id * m, bb= 0;\n    for (v.num=\
    \ 0;; ++v.num, bb+= m) {\n     bool any= 1;\n     for (u16 i= 0; i < m; ++i) any&=\
    \ !(adj[b + i] & buf[bb + i]);\n     if (any) break;\n    }\n    buf[bb + (v.id\
    \ >> 7)]|= u128(1) << (v.id & 127);\n   }\n   std::sort(rem.begin(), rem.end(),\
    \ [&](id_num l, id_num r) { return l.num < r.num; });\n   std::vector<id_num>\
    \ nrem;\n   for (nrem.reserve(rem.size()); !rem.empty();) {\n    auto p= rem.back();\n\
    \    if (p.num + cur.size() < clique.size()) break;\n    nrem.clear();\n    auto\
    \ a= adj.cbegin() + p.id * m;\n    for (auto u: rem)\n     if ((a[u.id >> 7] >>\
    \ (u.id & 127)) & 1) nrem.emplace_back(u);\n    std::fill_n(buf.begin(), m, 0);\n\
    \    for (auto u: nrem) buf[u.id >> 7]|= u128(1) << (u.id & 127);\n    for (auto\
    \ u: nrem) {\n     int b= u.id * m, i= 0, cnt= 0;\n     for (u128 tmp; i < m;\
    \ ++i) tmp= buf[i] & adj[b + i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \     deg[u.id]= cnt;\n    }\n    cur.push_back(p.id), dfs(dfs, nrem), cur.pop_back(),\
    \ rem.pop_back();\n   }\n  };\n  std::vector<id_num> nrem;\n  for (u16 u= n, cnt;\
    \ u--; nrem.push_back(id_num{u, 0}), deg[u]= cnt) {\n   int b= u * m, i= cnt=\
    \ 0;\n   for (u128 tmp; i < m; ++i) tmp= adj[b + i], cnt+= __builtin_popcountll(tmp\
    \ >> 64) + __builtin_popcountll(u64(tmp));\n  }\n  return dfs(dfs, nrem), clique;\n\
    \ }\npublic:\n CliqueProblem(int n): n(n), m((n + 127) >> 7), adj_(n * m) {}\n\
    \ void add_edge(int u, int v) { adj_[u * m + (v >> 7)]|= u128(1) << (v & 127),\
    \ adj_[v * m + (u >> 7)]|= u128(1) << (u & 127); }\n std::vector<u16> get_max_clique()\
    \ const { return calc(false); }\n std::vector<u16> get_max_independent_set() const\
    \ { return calc(true); }\n std::vector<u16> get_min_vertex_cover() const {\n \
    \ std::vector<u128> buf(m);\n  for (u16 u: calc(true)) buf[u >> 7]|= u128(1) <<\
    \ (u & 127);\n  std::vector<u16> ret;\n  for (u16 i= 0; i < n; ++i)\n   if (!((buf[i\
    \ >> 7] >> (i & 127)) & 1)) ret.push_back(i);\n  return ret;\n }\n template <class\
    \ F> void enumerate_cliques(const F &out) const {\n  std::vector<u128> buf;\n\
    \  std::vector<u16> deg(n), clique, nbd;\n  for (u16 u= n, cnt; u--; deg[u]= cnt)\
    \ {\n   int b= u * m, i= cnt= 0;\n   for (u128 tmp; i < m; ++i) tmp= adj_[b +\
    \ i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \  }\n  u16 nn;\n  auto dfs= [&](auto dfs, u16 k) -> void {\n   out(clique);\n\
    \   for (u16 i= k; i < nn; ++i) {\n    u16 v= nbd[i];\n    auto b= adj_.cbegin()\
    \ + v * m;\n    bool all= 1;\n    for (u16 j= 0; j < m; ++j) all&= (b[j] & buf[j])\
    \ == buf[j];\n    if (all) clique.push_back(v), buf[v >> 7]|= u128(1) << (v &\
    \ 127), dfs(dfs, i + 1), clique.pop_back(), buf[v >> 7]^= u128(1) << (v & 127);\n\
    \   }\n  };\n  bool unused[n];\n  std::fill_n(unused, n, 1);\n  for (u16 _= n;\
    \ _--;) {\n   u16 v, min_d= n;\n   for (u16 i= n; i--;)\n    if (unused[i] &&\
    \ min_d > deg[i]) v= i, min_d= deg[i];\n   nbd.clear(), clique= {v}, buf.assign(m,\
    \ 0), buf[v >> 7]|= u128(1) << (v & 127);\n   auto a= adj_.cbegin() + v * m;\n\
    \   for (int i= 0; i < n; ++i)\n    if ((a[i >> 7] >> (i & 127)) & unused[i])\
    \ nbd.push_back(i);\n   nn= nbd.size(), dfs(dfs, 0), unused[v]= 0;\n   for (auto\
    \ u: nbd) --deg[u];\n  }\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nclass CliqueProblem\
    \ {\n using u128= __uint128_t;\n using u64= unsigned long long;\n using u16= unsigned\
    \ short;\n const u16 n, m;\n struct id_num {\n  u16 id, num;\n };\n std::vector<u128>\
    \ adj_;\n std::vector<u16> calc(bool complement) const {\n  std::vector<u128>\
    \ buf, adj(adj_);\n  std::vector<u16> deg(n), clique, cur;\n  if (complement)\n\
    \   for (int u= n; u--;)\n    for (int v= u; v--;) adj[u * m + (v >> 7)]^= u128(1)\
    \ << (v & 127), adj[v * m + (u >> 7)]^= u128(1) << (u & 127);\n  auto dfs= [&](auto\
    \ dfs, std::vector<id_num> &rem) -> void {\n   if (clique.size() < cur.size())\
    \ clique= cur;\n   std::sort(rem.begin(), rem.end(), [&](id_num l, id_num r) {\
    \ return deg[l.id] > deg[r.id]; }), buf.assign((n + 1) * m, 0);\n   for (auto\
    \ &v: rem) {\n    int b= v.id * m, bb= 0;\n    for (v.num= 0;; ++v.num, bb+= m)\
    \ {\n     bool any= 1;\n     for (u16 i= 0; i < m; ++i) any&= !(adj[b + i] & buf[bb\
    \ + i]);\n     if (any) break;\n    }\n    buf[bb + (v.id >> 7)]|= u128(1) <<\
    \ (v.id & 127);\n   }\n   std::sort(rem.begin(), rem.end(), [&](id_num l, id_num\
    \ r) { return l.num < r.num; });\n   std::vector<id_num> nrem;\n   for (nrem.reserve(rem.size());\
    \ !rem.empty();) {\n    auto p= rem.back();\n    if (p.num + cur.size() < clique.size())\
    \ break;\n    nrem.clear();\n    auto a= adj.cbegin() + p.id * m;\n    for (auto\
    \ u: rem)\n     if ((a[u.id >> 7] >> (u.id & 127)) & 1) nrem.emplace_back(u);\n\
    \    std::fill_n(buf.begin(), m, 0);\n    for (auto u: nrem) buf[u.id >> 7]|=\
    \ u128(1) << (u.id & 127);\n    for (auto u: nrem) {\n     int b= u.id * m, i=\
    \ 0, cnt= 0;\n     for (u128 tmp; i < m; ++i) tmp= buf[i] & adj[b + i], cnt+=\
    \ __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n     deg[u.id]=\
    \ cnt;\n    }\n    cur.push_back(p.id), dfs(dfs, nrem), cur.pop_back(), rem.pop_back();\n\
    \   }\n  };\n  std::vector<id_num> nrem;\n  for (u16 u= n, cnt; u--; nrem.push_back(id_num{u,\
    \ 0}), deg[u]= cnt) {\n   int b= u * m, i= cnt= 0;\n   for (u128 tmp; i < m; ++i)\
    \ tmp= adj[b + i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \  }\n  return dfs(dfs, nrem), clique;\n }\npublic:\n CliqueProblem(int n): n(n),\
    \ m((n + 127) >> 7), adj_(n * m) {}\n void add_edge(int u, int v) { adj_[u * m\
    \ + (v >> 7)]|= u128(1) << (v & 127), adj_[v * m + (u >> 7)]|= u128(1) << (u &\
    \ 127); }\n std::vector<u16> get_max_clique() const { return calc(false); }\n\
    \ std::vector<u16> get_max_independent_set() const { return calc(true); }\n std::vector<u16>\
    \ get_min_vertex_cover() const {\n  std::vector<u128> buf(m);\n  for (u16 u: calc(true))\
    \ buf[u >> 7]|= u128(1) << (u & 127);\n  std::vector<u16> ret;\n  for (u16 i=\
    \ 0; i < n; ++i)\n   if (!((buf[i >> 7] >> (i & 127)) & 1)) ret.push_back(i);\n\
    \  return ret;\n }\n template <class F> void enumerate_cliques(const F &out) const\
    \ {\n  std::vector<u128> buf;\n  std::vector<u16> deg(n), clique, nbd;\n  for\
    \ (u16 u= n, cnt; u--; deg[u]= cnt) {\n   int b= u * m, i= cnt= 0;\n   for (u128\
    \ tmp; i < m; ++i) tmp= adj_[b + i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \  }\n  u16 nn;\n  auto dfs= [&](auto dfs, u16 k) -> void {\n   out(clique);\n\
    \   for (u16 i= k; i < nn; ++i) {\n    u16 v= nbd[i];\n    auto b= adj_.cbegin()\
    \ + v * m;\n    bool all= 1;\n    for (u16 j= 0; j < m; ++j) all&= (b[j] & buf[j])\
    \ == buf[j];\n    if (all) clique.push_back(v), buf[v >> 7]|= u128(1) << (v &\
    \ 127), dfs(dfs, i + 1), clique.pop_back(), buf[v >> 7]^= u128(1) << (v & 127);\n\
    \   }\n  };\n  bool unused[n];\n  std::fill_n(unused, n, 1);\n  for (u16 _= n;\
    \ _--;) {\n   u16 v, min_d= n;\n   for (u16 i= n; i--;)\n    if (unused[i] &&\
    \ min_d > deg[i]) v= i, min_d= deg[i];\n   nbd.clear(), clique= {v}, buf.assign(m,\
    \ 0), buf[v >> 7]|= u128(1) << (v & 127);\n   auto a= adj_.cbegin() + v * m;\n\
    \   for (int i= 0; i < n; ++i)\n    if ((a[i >> 7] >> (i & 127)) & unused[i])\
    \ nbd.push_back(i);\n   nn= nbd.size(), dfs(dfs, 0), unused[v]= 0;\n   for (auto\
    \ u: nbd) --deg[u];\n  }\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/CliqueProblem.hpp
  requiredBy: []
  timestamp: '2023-11-20 23:40:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/enumerate_cliques.test.cpp
  - test/yosupo/maximum_independent_set.test.cpp
  - test/aoj/2306.test.cpp
  - test/aoj/3168.clique.test.cpp
  - test/aoj/GRL_7_A.clique.test.cpp
documentation_of: src/Graph/CliqueProblem.hpp
layout: document
title: "\u30AF\u30EA\u30FC\u30AF\u554F\u984C"
---

内部でグラフを隣接行列で表現してる. 

## メンバ関数

| 名前                        | 概要                                        | 計算量                                          |
| --------------------------- | ------------------------------------------- | ----------------------------------------------- |
| `CliqueProblem(n)`          | コンストラクタ. グラフの頂点数 n を与える.  |                                                 |
| `add_edge(u,v)`             | 無向辺 (u,v) を加える.                      |                                                 |
| `get_max_clique()`          | 最大クリークの一つを返す.                   | $\mathcal{O}(1.381^nn)$                         |
| `get_max_independent_set()` | 最大独立集合の一つを返す.                   | $\mathcal{O}(1.381^nn)$                         |
| `get_min_vertex_cover()`    | 最小頂点被覆の一つを返す.                   | $\mathcal{O}(1.381^nn)$                         |
| `enumerate_cliques(out)`    | すべてのクリークcに対してout(c) を実行する. | $\mathcal{O}(n2^{\sqrt{2m}})$ <br> $m$ は辺の数 |


## 問題例
[CODE THANKS FESTIVAL 2017(Parallel) G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g) (最大クリーク, 40頂点) \
[yukicoder No.382 シャイな人たち (2)](https://yukicoder.me/problems/no/382) (最大独立集合, 120頂点) \
[Maximum-Cup 2018 H - Maxmin Tour](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_h) (二部グラフ マッチング, 600頂点)
