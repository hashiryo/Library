---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/WeightedMatching.hpp
    title: "\u91CD\u307F\u4ED8\u304D\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo/assignment.WeightedMatching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n// \u3000\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\n#include <iostream>\n#include <vector>\n#line 2 \"src/Optimization/WeightedMatching.hpp\"\
    \n#include <limits>\n#include <iterator>\n#line 5 \"src/Optimization/WeightedMatching.hpp\"\
    \n#include <queue>\n#include <algorithm>\ntemplate <class cost_t, bool min_perfect=\
    \ false> class WeightedMatching {\n static constexpr cost_t INF= std::numeric_limits<cost_t>::max()\
    \ / 4;\n struct E {\n  int16_t u, v;\n  cost_t w;\n };\n template <class T> struct\
    \ Mat {\n  int n;\n  std::vector<T> dat;\n  Mat(int n): n(n), dat(n * n){};\n\
    \  auto operator[](int i) { return std::next(dat.begin(), n * i); }\n  const auto\
    \ operator[](int i) const { return std::next(dat.cbegin(), n * i); }\n };\n cost_t\
    \ mx;\n Mat<cost_t> adj;\n std::vector<int16_t> mt;\n static inline int sgn(cost_t\
    \ c) {\n  static constexpr cost_t EPS= 1e-10;\n  return c < -EPS ? -1 : c > EPS\
    \ ? 1 : 0;\n }\npublic:\n WeightedMatching(int n): mx(0), adj(n), mt(2 * n) {\n\
    \  if constexpr (min_perfect)\n   for (int i= n; i--;)\n    for (int j= n; j--;)\
    \ adj[i][j]= INF;\n }\n void add_edge(int u, int v, cost_t w) {\n  mx= std::max(mx,\
    \ w);\n  if constexpr (min_perfect) {\n   if (adj[u][v] > w) adj[u][v]= adj[v][u]=\
    \ w;\n  } else if (adj[u][v] < w) adj[u][v]= adj[v][u]= w;\n }\n void build()\
    \ {\n  const int n= mt.size() / 2;\n  int16_t rt[2 * n], used[2 * n], in= 0, m=\
    \ n, q[2 * n], slk[2 * n], par[2 * n], isS[2 * n];\n  Mat<int16_t> blg(2 * n);\n\
    \  std::fill_n(used, 2 * n, 0), std::fill_n(rt + n + 1, n - 1, 0), rt[0]= 0;\n\
    \  std::vector<std::vector<int16_t>> fwr(2 * n);\n  std::queue<int16_t> que;\n\
    \  std::vector<cost_t> dual(2 * n);\n  Mat<E> G(2 * n);\n  for (int16_t i= 0;\
    \ i <= n; ++i) G[i][0]= E{i, int16_t(0), 0};\n  for (int16_t j= 0; j <= n; ++j)\
    \ G[0][j]= E{int16_t(0), j, 0};\n  if constexpr (min_perfect)\n   for (int16_t\
    \ i= 1; i <= n; ++i)\n    for (int16_t j= 1; j <= n; ++j) G[i][j]= E{i, j, adj[i\
    \ - 1][j - 1] == INF ? 0 : (mx - adj[i - 1][j - 1] + 1) * 2};\n  else\n   for\
    \ (int16_t i= 1; i <= n; ++i)\n    for (int16_t j= 1; j <= n; ++j) G[i][j]= E{i,\
    \ j, adj[i - 1][j - 1] * 2};\n  cost_t inf= 0;\n  for (int16_t i= 1; i <= n; ++i)\n\
    \   for (int16_t j= 1; j <= n; ++j) inf= std::max(inf, G[i][j].w);\n  inf+= 1;\n\
    \  for (int i= 1; i <= n; i++) rt[i]= i, blg[i][i]= i, dual[i]= inf;\n  auto dist=\
    \ [&](const E &e) { return dual[e.u] - e.w + dual[e.v]; };\n  auto push= [&](int\
    \ v) {\n   q[0]= v;\n   for (int i= 0, s= 1; i < s; ++i) {\n    if (v= q[i]; v\
    \ > n)\n     for (int u: fwr[v]) q[s++]= u;\n    else que.push(v);\n   }\n  };\n\
    \  auto match= [&](auto self, int u, int v) -> void {\n   if (mt[u]= G[u][v].v;\
    \ u <= n) return;\n   int x= blg[u][G[u][v].u], p= std::find(fwr[u].begin(), fwr[u].end(),\
    \ x) - fwr[u].begin();\n   if (p & 1) std::reverse(fwr[u].begin() + 1, fwr[u].end()),\
    \ p= fwr[u].size() - p;\n   for (int i= 0; i < p; ++i) self(self, fwr[u][i], fwr[u][i\
    \ ^ 1]);\n   self(self, x, v), std::rotate(fwr[u].begin(), fwr[u].begin() + p,\
    \ fwr[u].end());\n  };\n  auto path= [&](const E &e) {\n   if (int u= rt[e.u],\
    \ v= rt[e.v], bu= u, bv= v, x; isS[v] == 1) {\n    for (++in; bu; bu= rt[mt[bu]]\
    \ ? rt[par[rt[mt[bu]]]] : 0) used[bu]= in;\n    for (int id= n + 1; bv; bv= rt[mt[bv]]\
    \ ? rt[par[rt[mt[bv]]]] : 0)\n     if (used[bv] == in) {\n      while (id <= m\
    \ && rt[id]) ++id;\n      for (int i= (m+= (id > m)); i; --i) G[id][i].w= G[i][id].w=\
    \ 0;\n      for (int i= n; --i;) blg[id][i]= 0;\n      mt[id]= mt[bv];\n     \
    \ for (fwr[id].clear(); u != bv; fwr[id].push_back(u), u= rt[par[u]]) fwr[id].push_back(u),\
    \ push(u= rt[mt[u]]);\n      fwr[id].push_back(bv), std::reverse(fwr[id].begin(),\
    \ fwr[id].end());\n      for (; v != bv; fwr[id].push_back(v), v= rt[par[v]])\
    \ fwr[id].push_back(v), push(v= rt[mt[v]]);\n      isS[id]= 1, dual[id]= 0, q[0]=\
    \ id;\n      for (int i= 0, s= 1; i < s; ++i)\n       if (rt[v= q[i]]= id; v >\
    \ n)\n        for (int t: fwr[v]) q[s++]= t;\n      for (int c: fwr[id]) {\n \
    \      for (int i= 1; i <= m; ++i)\n        if (sgn(G[id][i].w) == 0 || sgn(dist(G[c][i])\
    \ - dist(G[id][i])) < 0) G[id][i]= G[c][i], G[i][id]= G[i][c];\n       for (int\
    \ i= 1; i <= n; ++i)\n        if (blg[c][i]) blg[id][i]= c;\n      }\n      for\
    \ (int i= slk[id]= 0; i <= n; ++i)\n       if (sgn(G[i][id].w) != 0 && rt[i] !=\
    \ id && isS[rt[i]] == 1)\n        if (!slk[id] || sgn(dist(G[i][id]) - dist(G[slk[id]][id]))\
    \ < 0) slk[id]= i;\n      return false;\n     }\n    for (bu= u, bv= v;; match(match,\
    \ bv= x, bu= rt[par[x]]))\n     if (x= rt[mt[bu]], match(match, bu, bv); !x)\n\
    \      for (;; match(match, u= x, v= rt[par[x]]))\n       if (x= rt[mt[v]], match(match,\
    \ v, u); !x) return true;\n   } else if (!isS[v]) par[v]= e.u, isS[v]= 2, slk[v]=\
    \ slk[x= rt[mt[v]]]= 0, isS[x]= 1, push(x);\n   return false;\n  };\n LABEL_AUGMENT:\n\
    \  std::fill_n(isS, 2 * n, 0), std::fill_n(slk, 2 * n, 0), std::fill_n(par, 2\
    \ * n, 0), que= std::queue<int16_t>();\n  for (int i= 1; i <= m; i++)\n   if (rt[i]\
    \ == i && !mt[i]) isS[i]= 1, push(i);\n  if (que.empty()) return;\n  for (cost_t\
    \ del= inf;; del= inf) {\n   for (int v, i; !que.empty();)\n    for (v= que.front(),\
    \ que.pop(), i= 1; i <= n; ++i)\n     if (sgn(G[v][i].w) != 0 && rt[i] != rt[v])\
    \ {\n      if (sgn(dist(G[v][i])) == 0) {\n       if (path(G[v][i])) goto LABEL_AUGMENT;\n\
    \      } else if (isS[rt[i]] != 2)\n       if (!slk[rt[i]] || sgn(dist(G[v][rt[i]])\
    \ - dist(G[slk[rt[i]]][rt[i]])) < 0) slk[rt[i]]= v;\n     }\n   for (int i= n\
    \ + 1; i <= m; ++i)\n    if (rt[i] == i && isS[i] == 2 && sgn(del - dual[i] /\
    \ 2) > 0) del= dual[i] / 2;\n   for (int i= 1; i <= m; ++i)\n    if (rt[i] ==\
    \ i && slk[i] && isS[i] != 2)\n     if (cost_t c= dist(G[slk[i]][i]) / (1 + isS[i]);\
    \ sgn(del - c) > 0) del= c;\n   for (int i= 1; i <= n; ++i) {\n    if (isS[rt[i]]\
    \ == 1) {\n     if (sgn(dual[i]-= del) <= 0) return;\n    } else if (isS[rt[i]]\
    \ == 2) dual[i]+= del;\n   }\n   for (int i= n + 1; i <= m; ++i)\n    if (rt[i]\
    \ == i && isS[i]) dual[i]+= isS[i] == 1 ? 2 * del : -2 * del;\n   for (int i=\
    \ 1; i <= m; ++i)\n    if (rt[i] == i && slk[i] && rt[slk[i]] != i && sgn(dist(G[slk[i]][i]))\
    \ == 0)\n     if (path(G[slk[i]][i])) goto LABEL_AUGMENT;\n   for (int b= n +\
    \ 1, x, p, T, S; b <= m; b++)\n    if (rt[b] == b && isS[b] == 2 && sgn(dual[b])\
    \ == 0) {\n     isS[x= blg[b][G[b][par[b]].u]]= 2, par[x]= par[b];\n     for (int\
    \ c: fwr[b]) {\n      q[0]= c;\n      for (int i= 0, s= 1, v; i < s; ++i)\n  \
    \     if (rt[v= q[i]]= c; v > n)\n        for (int u: fwr[v]) q[s++]= u;\n   \
    \  }\n     p= std::find(fwr[b].begin(), fwr[b].end(), x) - fwr[b].begin(), x=\
    \ fwr[b].size();\n     if (p & 1) std::reverse(fwr[b].begin() + 1, fwr[b].end()),\
    \ p= fwr[b].size() - p;\n     for (int i= 0; i < p; i+= 2) isS[S= fwr[b][i + 1]]=\
    \ 1, isS[T= fwr[b][i]]= 2, par[T]= G[S][T].u, slk[S]= slk[T]= 0, push(S);\n  \
    \   for (int i= p + 1, j; i < x; ++i)\n      for (T= fwr[b][i], j= isS[T]= slk[T]=\
    \ 0; j <= n; ++j)\n       if (sgn(G[j][T].w) != 0 && rt[j] != T && isS[rt[j]]\
    \ == 1)\n        if (!slk[T] || sgn(dist(G[j][T]) - dist(G[slk[T]][T])) < 0) slk[T]=\
    \ j;\n     fwr[b].clear(), rt[b]= 0;\n    }\n  }\n  goto LABEL_AUGMENT;\n }\n\
    \ int match(int v) const { return mt[v + 1] - 1; }\n std::vector<E> weight_matching()\
    \ const {\n  const int n= mt.size() / 2;\n  std::vector<E> ret;\n  if constexpr\
    \ (min_perfect) {\n   if (n & 1) return {};  // no solution\n   for (int16_t i=\
    \ 0; i < n; ++i)\n    if (int16_t j= match(i); i < j) ret.push_back(E{i, j, adj[i][j]});\n\
    \   if (2 * int(ret.size()) != n) return {};  // no solution\n  } else\n   for\
    \ (int16_t i= 0; i < n; ++i)\n    if (int16_t j= match(i); i < j) ret.push_back(E{i,\
    \ j, adj[i][j]});\n  return ret;\n }\n};\n#line 6 \"test/yosupo/assignment.WeightedMatching.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n WeightedMatching<long long, true> graph(N + N);\n for (int\
    \ i= 0; i < N; ++i)\n  for (int j= 0; j < N; ++j) {\n   long long a;\n   cin >>\
    \ a;\n   graph.add_edge(i, N + j, a);\n  }\n graph.build();\n long long ans= 0;\n\
    \ for (auto [u, v, w]: graph.weight_matching()) ans+= w;\n cout << ans << '\\\
    n';\n for (int i= 0; i < N; ++i) cout << graph.match(i) - N << \" \\n\"[i == N\
    \ - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n// \u3000\
    \u4E8C\u90E8\u30B0\u30E9\u30D5\n#include <iostream>\n#include <vector>\n#include\
    \ \"src/Optimization/WeightedMatching.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n WeightedMatching<long\
    \ long, true> graph(N + N);\n for (int i= 0; i < N; ++i)\n  for (int j= 0; j <\
    \ N; ++j) {\n   long long a;\n   cin >> a;\n   graph.add_edge(i, N + j, a);\n\
    \  }\n graph.build();\n long long ans= 0;\n for (auto [u, v, w]: graph.weight_matching())\
    \ ans+= w;\n cout << ans << '\\n';\n for (int i= 0; i < N; ++i) cout << graph.match(i)\
    \ - N << \" \\n\"[i == N - 1];\n return 0;\n}"
  dependsOn:
  - src/Optimization/WeightedMatching.hpp
  isVerificationFile: true
  path: test/yosupo/assignment.WeightedMatching.test.cpp
  requiredBy: []
  timestamp: '2023-03-16 02:01:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.WeightedMatching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.WeightedMatching.test.cpp
- /verify/test/yosupo/assignment.WeightedMatching.test.cpp.html
title: test/yosupo/assignment.WeightedMatching.test.cpp
---
