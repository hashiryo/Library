---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1163.matroid_intersection.test.cpp
    title: test/aoj/1163.matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1605.weighted_matroid_intersection.test.cpp
    title: test/aoj/1605.weighted_matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.weighted_matroid_intersection.test.cpp
    title: test/aoj/GRL_2_B.weighted_matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.matroid_intersection.test.cpp
    title: test/aoj/GRL_7_A.matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc231_h.weighted_matroid_intersection.test.cpp
    title: test/atcoder/abc231_h.weighted_matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/421.matroid_intersection.test.cpp
    title: test/yukicoder/421.matroid_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/421.weighted_matroid_intersection.test.cpp
    title: test/yukicoder/421.weighted_matroid_intersection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/matroid_intersection.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <limits>\n#include <array>\n#include <queue>\n\
    #include <cassert>\ntemplate <typename Matroid1, typename Matroid2> std::vector<int>\
    \ matroid_intersection(int n, Matroid1 M1, Matroid2 M2) {\n std::vector<int> b(n,\
    \ false), pre(n), I[2];\n for (int e= 0; e < n; e++) I[0].push_back(e);\n M1.build(I[1]),\
    \ M2.build(I[1]);\n for (bool converged= false; !converged;) {\n  pre.assign(n,\
    \ false);\n  std::vector L(1, std::vector<int>());\n  for (int u: I[0])\n   if\
    \ (M1.oracle(u)) pre[u]= true, L[0].push_back(u);\n  int m= 0;\n  for (; L.back().size();\
    \ m+= 2) {\n   L.push_back({});\n   for (int e: L[m]) {\n    if (converged= M2.oracle(e))\
    \ break;\n    for (int f: I[1])\n     if (!pre[f] && M2.oracle(f, e)) L[m + 1].push_back(f),\
    \ pre[f]= true;\n   }\n   if (converged) break;\n   L.push_back({});\n   for (int\
    \ e: L[m + 1])\n    for (int f: I[0])\n     if (!pre[f] && M1.oracle(e, f)) L[m\
    \ + 2].push_back(f), pre[f]= true;\n  }\n  if (!converged) break;\n  std::vector<std::vector<int>>\
    \ L2(m + 1);\n  for (int e: L[m])\n   if (M2.oracle(e)) L2[m].push_back(e);\n\
    \  for (int i= m; i; i-= 2) {\n   for (int e: L[i - 1])\n    for (int f: L2[i])\n\
    \     if (M1.oracle(e, f)) {\n      L2[i - 1].push_back(e);\n      break;\n  \
    \   }\n   for (int e: L[i - 2])\n    for (int f: L2[i - 1])\n     if (M2.oracle(f,\
    \ e)) {\n      L2[i - 2].push_back(e);\n      break;\n     }\n  }\n  pre.assign(n,\
    \ -1);\n  for (int e: L2[0])\n   if (M1.oracle(e)) {\n    bool isok= false;\n\
    \    if (m) {\n     std::vector<size_t> ei(m);\n     for (int i= 0; e != -1;)\
    \ {\n      if (ei[i] == L2[i + 1].size()) e= pre[e], ei[i--]= 0;\n      else if\
    \ (int f= L2[i + 1][ei[i]++]; pre[f] == -1 && (i & 1 ? M1.oracle(e, f) : M2.oracle(f,\
    \ e)))\n       if (pre[f]= e, e= f; ++i == m) {\n        if (M2.oracle(e))\n \
    \        for (isok= true; e != -1; e= pre[e]) b[e]= !b[e];\n        else e= pre[e],\
    \ --i;\n       }\n     }\n    } else if (M2.oracle(e)) isok= true, b[e]= 1;\n\
    \    if (isok) {\n     converged= false, I[0].clear(), I[1].clear();\n     for\
    \ (int u= 0; u < n; u++) I[b[u]].push_back(u);\n     M1.build(I[1]), M2.build(I[1]);\n\
    \    }\n   }\n }\n return I[1];\n}\n// sgn: + -> max, - -> min, 0 -> unweighted\n\
    template <std::int_least8_t sgn, class Matroid1, class Matroid2, class cost_t>\
    \ std::vector<std::vector<int>> weighted_matroid_intersection(int n, Matroid1\
    \ M1, Matroid2 M2, std::vector<cost_t> c) {\n assert(n == (int)c.size());\n bool\
    \ b[n];\n std::fill_n(b, n, false);\n std::vector<int> I[2], p;\n std::vector<std::vector<int>>\
    \ ret(1);\n for (int u= 0; u < n; u++) I[0].push_back(u);\n if constexpr (sgn\
    \ > 0) {\n  auto cmx= *std::max_element(c.begin(), c.end());\n  for (auto &x:\
    \ c) x-= cmx;\n } else {\n  auto cmi= *std::min_element(c.begin(), c.end());\n\
    \  for (auto &x: c) x-= cmi;\n }\n for (auto &x: c) x*= sgn * (n + 1);\n for (bool\
    \ converged= false; !converged;) {\n  converged= true, M1.build(I[1]), M2.build(I[1]);\n\
    \  std::priority_queue<std::pair<cost_t, int>> pq;\n  std::vector<cost_t> dist(n,\
    \ std::numeric_limits<cost_t>::lowest());\n  for (int u: I[0])\n   if (M1.oracle(u))\
    \ pq.emplace(dist[u]= c[u] - 1, u);\n  for (p.assign(n, -1); pq.size();) {\n \
    \  auto [d, u]= pq.top();\n   if (pq.pop(); d != dist[u]) continue;\n   if (b[u])\
    \ {\n    for (int v: I[0])\n     if (M1.oracle(u, v))\n      if (cost_t cost=\
    \ d + c[v] - 1; dist[v] < cost) pq.emplace(dist[v]= cost, v), p[v]= u;\n   } else\
    \ {\n    if (M2.oracle(u)) {\n     for (int v= u; v != -1; v= p[v]) b[v]= !b[v];\n\
    \     I[0].clear(), I[1].clear(), converged= false;\n     for (int u= 0; u < n;\
    \ u++) I[b[u]].push_back(u);\n     ret.emplace_back(I[1]);\n     break;\n    }\n\
    \    for (int v: I[1])\n     if (M2.oracle(v, u))\n      if (cost_t cost= d -\
    \ c[v] - 1; dist[v] < cost) pq.emplace(dist[v]= cost, v), p[v]= u;\n   }\n  }\n\
    \ }\n return ret;\n}\nclass GraphicMatroid {\n int n;\n std::vector<std::array<int,\
    \ 2>> es;\n std::vector<int> g, pos, comp, in, out;\n inline bool is_ancestor(int\
    \ u, int v) const { return in[u] <= in[v] && in[v] < out[u]; }\npublic:\n GraphicMatroid(int\
    \ n_): n(n_), comp(n), in(n), out(n) {}\n int add_edge(int u, int v) { return\
    \ es.push_back({u, v}), es.size() - 1; }\n void build(const std::vector<int> &I)\
    \ {\n  in.assign(n, -1), g.resize(I.size() * 2), pos.assign(n + 1, 0);\n  for\
    \ (int e: I) {\n   auto [u, v]= es[e];\n   ++pos[u], ++pos[v];\n  }\n  for (int\
    \ i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (int e: I) {\n   auto [u, v]=\
    \ es[e];\n   g[--pos[u]]= v, g[--pos[v]]= u;\n  }\n  std::vector<int> ei(pos.begin(),\
    \ pos.begin() + n), pre(n, -1);\n  for (int u= 0, t= 0, p; u < n; u++)\n   if\
    \ (in[u] == -1)\n    for (in [comp[u]= p= u]= t++; p >= 0;) {\n     if (ei[p]\
    \ == pos[p + 1]) out[p]= t, p= pre[p];\n     else if (int v= g[ei[p]++]; in[v]\
    \ == -1) comp[v]= comp[u], pre[v]= p, in[p= v]= t++;\n    }\n }\n inline bool\
    \ oracle(int e) const { return comp[es[e][0]] != comp[es[e][1]]; }\n inline bool\
    \ oracle(int e, int f) const {\n  if (oracle(f)) return true;\n  return e= es[e][in[es[e][0]]\
    \ < in[es[e][1]]], is_ancestor(e, es[f][0]) != is_ancestor(e, es[f][1]);\n }\n\
    };\nstruct PartitionMatroid {\n std::vector<int> belong, R, cnt;\n PartitionMatroid(int\
    \ m_, const std::vector<std::vector<int>> &parts, const std::vector<int> &R_):\
    \ belong(m_, -1), R(R_) {\n  assert(parts.size() == R.size());\n  for (int i=\
    \ parts.size(); i--;)\n   for (int e: parts[i]) belong[e]= i;\n }\n void build(const\
    \ std::vector<int> &I) {\n  cnt= R;\n  for (int e: I)\n   if (belong[e] != -1)\
    \ cnt[belong[e]]--;\n }\n inline bool oracle(int e) const { return belong[e] ==\
    \ -1 || cnt[belong[e]] > 0; }\n inline bool oracle(int e, int f) const { return\
    \ oracle(f) || belong[e] == belong[f]; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <limits>\n\
    #include <array>\n#include <queue>\n#include <cassert>\ntemplate <typename Matroid1,\
    \ typename Matroid2> std::vector<int> matroid_intersection(int n, Matroid1 M1,\
    \ Matroid2 M2) {\n std::vector<int> b(n, false), pre(n), I[2];\n for (int e= 0;\
    \ e < n; e++) I[0].push_back(e);\n M1.build(I[1]), M2.build(I[1]);\n for (bool\
    \ converged= false; !converged;) {\n  pre.assign(n, false);\n  std::vector L(1,\
    \ std::vector<int>());\n  for (int u: I[0])\n   if (M1.oracle(u)) pre[u]= true,\
    \ L[0].push_back(u);\n  int m= 0;\n  for (; L.back().size(); m+= 2) {\n   L.push_back({});\n\
    \   for (int e: L[m]) {\n    if (converged= M2.oracle(e)) break;\n    for (int\
    \ f: I[1])\n     if (!pre[f] && M2.oracle(f, e)) L[m + 1].push_back(f), pre[f]=\
    \ true;\n   }\n   if (converged) break;\n   L.push_back({});\n   for (int e: L[m\
    \ + 1])\n    for (int f: I[0])\n     if (!pre[f] && M1.oracle(e, f)) L[m + 2].push_back(f),\
    \ pre[f]= true;\n  }\n  if (!converged) break;\n  std::vector<std::vector<int>>\
    \ L2(m + 1);\n  for (int e: L[m])\n   if (M2.oracle(e)) L2[m].push_back(e);\n\
    \  for (int i= m; i; i-= 2) {\n   for (int e: L[i - 1])\n    for (int f: L2[i])\n\
    \     if (M1.oracle(e, f)) {\n      L2[i - 1].push_back(e);\n      break;\n  \
    \   }\n   for (int e: L[i - 2])\n    for (int f: L2[i - 1])\n     if (M2.oracle(f,\
    \ e)) {\n      L2[i - 2].push_back(e);\n      break;\n     }\n  }\n  pre.assign(n,\
    \ -1);\n  for (int e: L2[0])\n   if (M1.oracle(e)) {\n    bool isok= false;\n\
    \    if (m) {\n     std::vector<size_t> ei(m);\n     for (int i= 0; e != -1;)\
    \ {\n      if (ei[i] == L2[i + 1].size()) e= pre[e], ei[i--]= 0;\n      else if\
    \ (int f= L2[i + 1][ei[i]++]; pre[f] == -1 && (i & 1 ? M1.oracle(e, f) : M2.oracle(f,\
    \ e)))\n       if (pre[f]= e, e= f; ++i == m) {\n        if (M2.oracle(e))\n \
    \        for (isok= true; e != -1; e= pre[e]) b[e]= !b[e];\n        else e= pre[e],\
    \ --i;\n       }\n     }\n    } else if (M2.oracle(e)) isok= true, b[e]= 1;\n\
    \    if (isok) {\n     converged= false, I[0].clear(), I[1].clear();\n     for\
    \ (int u= 0; u < n; u++) I[b[u]].push_back(u);\n     M1.build(I[1]), M2.build(I[1]);\n\
    \    }\n   }\n }\n return I[1];\n}\n// sgn: + -> max, - -> min, 0 -> unweighted\n\
    template <std::int_least8_t sgn, class Matroid1, class Matroid2, class cost_t>\
    \ std::vector<std::vector<int>> weighted_matroid_intersection(int n, Matroid1\
    \ M1, Matroid2 M2, std::vector<cost_t> c) {\n assert(n == (int)c.size());\n bool\
    \ b[n];\n std::fill_n(b, n, false);\n std::vector<int> I[2], p;\n std::vector<std::vector<int>>\
    \ ret(1);\n for (int u= 0; u < n; u++) I[0].push_back(u);\n if constexpr (sgn\
    \ > 0) {\n  auto cmx= *std::max_element(c.begin(), c.end());\n  for (auto &x:\
    \ c) x-= cmx;\n } else {\n  auto cmi= *std::min_element(c.begin(), c.end());\n\
    \  for (auto &x: c) x-= cmi;\n }\n for (auto &x: c) x*= sgn * (n + 1);\n for (bool\
    \ converged= false; !converged;) {\n  converged= true, M1.build(I[1]), M2.build(I[1]);\n\
    \  std::priority_queue<std::pair<cost_t, int>> pq;\n  std::vector<cost_t> dist(n,\
    \ std::numeric_limits<cost_t>::lowest());\n  for (int u: I[0])\n   if (M1.oracle(u))\
    \ pq.emplace(dist[u]= c[u] - 1, u);\n  for (p.assign(n, -1); pq.size();) {\n \
    \  auto [d, u]= pq.top();\n   if (pq.pop(); d != dist[u]) continue;\n   if (b[u])\
    \ {\n    for (int v: I[0])\n     if (M1.oracle(u, v))\n      if (cost_t cost=\
    \ d + c[v] - 1; dist[v] < cost) pq.emplace(dist[v]= cost, v), p[v]= u;\n   } else\
    \ {\n    if (M2.oracle(u)) {\n     for (int v= u; v != -1; v= p[v]) b[v]= !b[v];\n\
    \     I[0].clear(), I[1].clear(), converged= false;\n     for (int u= 0; u < n;\
    \ u++) I[b[u]].push_back(u);\n     ret.emplace_back(I[1]);\n     break;\n    }\n\
    \    for (int v: I[1])\n     if (M2.oracle(v, u))\n      if (cost_t cost= d -\
    \ c[v] - 1; dist[v] < cost) pq.emplace(dist[v]= cost, v), p[v]= u;\n   }\n  }\n\
    \ }\n return ret;\n}\nclass GraphicMatroid {\n int n;\n std::vector<std::array<int,\
    \ 2>> es;\n std::vector<int> g, pos, comp, in, out;\n inline bool is_ancestor(int\
    \ u, int v) const { return in[u] <= in[v] && in[v] < out[u]; }\npublic:\n GraphicMatroid(int\
    \ n_): n(n_), comp(n), in(n), out(n) {}\n int add_edge(int u, int v) { return\
    \ es.push_back({u, v}), es.size() - 1; }\n void build(const std::vector<int> &I)\
    \ {\n  in.assign(n, -1), g.resize(I.size() * 2), pos.assign(n + 1, 0);\n  for\
    \ (int e: I) {\n   auto [u, v]= es[e];\n   ++pos[u], ++pos[v];\n  }\n  for (int\
    \ i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (int e: I) {\n   auto [u, v]=\
    \ es[e];\n   g[--pos[u]]= v, g[--pos[v]]= u;\n  }\n  std::vector<int> ei(pos.begin(),\
    \ pos.begin() + n), pre(n, -1);\n  for (int u= 0, t= 0, p; u < n; u++)\n   if\
    \ (in[u] == -1)\n    for (in [comp[u]= p= u]= t++; p >= 0;) {\n     if (ei[p]\
    \ == pos[p + 1]) out[p]= t, p= pre[p];\n     else if (int v= g[ei[p]++]; in[v]\
    \ == -1) comp[v]= comp[u], pre[v]= p, in[p= v]= t++;\n    }\n }\n inline bool\
    \ oracle(int e) const { return comp[es[e][0]] != comp[es[e][1]]; }\n inline bool\
    \ oracle(int e, int f) const {\n  if (oracle(f)) return true;\n  return e= es[e][in[es[e][0]]\
    \ < in[es[e][1]]], is_ancestor(e, es[f][0]) != is_ancestor(e, es[f][1]);\n }\n\
    };\nstruct PartitionMatroid {\n std::vector<int> belong, R, cnt;\n PartitionMatroid(int\
    \ m_, const std::vector<std::vector<int>> &parts, const std::vector<int> &R_):\
    \ belong(m_, -1), R(R_) {\n  assert(parts.size() == R.size());\n  for (int i=\
    \ parts.size(); i--;)\n   for (int e: parts[i]) belong[e]= i;\n }\n void build(const\
    \ std::vector<int> &I) {\n  cnt= R;\n  for (int e: I)\n   if (belong[e] != -1)\
    \ cnt[belong[e]]--;\n }\n inline bool oracle(int e) const { return belong[e] ==\
    \ -1 || cnt[belong[e]] > 0; }\n inline bool oracle(int e, int f) const { return\
    \ oracle(f) || belong[e] == belong[f]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/matroid_intersection.hpp
  requiredBy: []
  timestamp: '2023-03-17 18:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1605.weighted_matroid_intersection.test.cpp
  - test/aoj/1163.matroid_intersection.test.cpp
  - test/aoj/GRL_7_A.matroid_intersection.test.cpp
  - test/aoj/GRL_2_B.weighted_matroid_intersection.test.cpp
  - test/atcoder/abc231_h.weighted_matroid_intersection.test.cpp
  - test/yukicoder/421.weighted_matroid_intersection.test.cpp
  - test/yukicoder/421.matroid_intersection.test.cpp
documentation_of: src/Optimization/matroid_intersection.hpp
layout: document
title: "\u30DE\u30C8\u30ED\u30A4\u30C9\u4EA4\u53C9"
---

$n$は台集合のサイズ, $r$は最大共通独立集合のサイズ, $\tau$は独立性オラクル呼び出しにかかる時間

## 重みなし

| 関数名                          | 概要                                                                                | 計算量                      |
| ------------------------------- | ----------------------------------------------------------------------------------- | --------------------------- |
| `matroid_intersection(n,M1,M2)` | (引数) `n` : 台集合のサイズ, `M1`・`M2` : マトロイド <br> (返り値) 最大共通独立集合 | $\mathcal{O}(nr^{1.5}\tau)$ |

## 重みあり

| 関数名                                          | 概要                                                                                                                                                                                                  | 計算量                  |
| ----------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------- |
| `weighted_matroid_intersection<sgn>(n,M1,M2,w)` | (引数) `n` : 台集合のサイズ, `M1`・`M2` : マトロイド, `w` : 重み <br> (返り値) 共通独立集合の集合 ( k番目の集合は 要素数 = k かつ 重みが最大(最小)のもの )　<br> template引数が正なら最大, 負なら最小 | $\mathcal{O}(nr^2\tau)$ |


## 参考
[https://hitonanode.github.io/cplib-cpp/combinatorial_opt/matroid_intersection.hpp](https://hitonanode.github.io/cplib-cpp/combinatorial_opt/matroid_intersection.hpp) \
William H. Cunningham. Improved bounds for matroid partition and intersection algorithms. SIAMJournal on Computing (SICOMP), 15(4):948–957, 1986.
## 問題例
[beecrowd | 2128 Demonstration of Honesty!](https://www.beecrowd.com.br/judge/en/problems/view/2128) (グラフ+分割) \
[Hello 2020 G. Seollal - Codeforces](https://codeforces.com/contest/1284/problem/G) (グラフ+分割)\
[2019 Petrozavodsk Winter Camp, Yandex Cup D. Pick Your Own Nim - Codeforces](https://codeforces.com/gym/102156/problem/D) (二値+分割)\
[幾何コンテスト2013 B - 玉座の間](https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b) (重み二部マッチング, 重みが実数) \
[ACM-ICPC Japan Alumni Group Summer Camp 2012 Day 2 まるかいて](https://onlinejudge.u-aizu.ac.jp/problems/2429) (重み二部マッチング, |台集合| <= 1e4, 構築, sp judge) \
[AtCoder Library Practice Contest E - MinCostFlow](https://atcoder.jp/contests/practice2/tasks/practice2_e) (重み付き, 分割+分割) \
[Deltix Round, Summer 2021 H. DIY Tree - Codeforces](https://codeforces.com/contest/1556/problem/H) (重み付き, グラフ+分割) \
[NAIPC 2018 G Rainbow Graph](https://www.acmicpc.net/problem/16046)(重み付き, あるマトロイド (グラフマトロイドの双対マトロイドと自由マトロイドの直和?) 同士の交差) \
[2021 ICPC Asia Taiwan Online Programming Contest I. ICPC Kingdom - Codeforces](https://codeforces.com/gym/103373/problem/I) (重み付き, グラフ+横断)