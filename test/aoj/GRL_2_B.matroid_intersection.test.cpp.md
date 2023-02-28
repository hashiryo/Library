---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/matroid_intersection.hpp
    title: "\u30DE\u30C8\u30ED\u30A4\u30C9\u4EA4\u53C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
  bundledCode: "#line 1 \"test/aoj/GRL_2_B.matroid_intersection.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B\"\
    \n// \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728(\u30B0\u30E9\u30D5+\u5206\u5272\
    )\n#include <iostream>\n#include <vector>\n#line 3 \"src/Optimization/matroid_intersection.hpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <array>\n#include <queue>\n\
    #include <cassert>\ntemplate <typename Matroid1, typename Matroid2> std::vector<int>\
    \ matroid_intersection(int n, Matroid1 M1, Matroid2 M2) {\n std::vector<bool>\
    \ b(n, false), useless(n);\n std::vector<int> I[2];\n for (int e= 0; e < n; e++)\
    \ I[0].push_back(e);\n M1.build(I[1]), M2.build(I[1]);\n for (bool converged=\
    \ false; !converged;) {\n  useless.assign(n, false);\n  std::vector L(1, std::vector<int>());\n\
    \  for (int u: I[0])\n   if (M1.oracle(u)) useless[u]= true, L[0].push_back(u);\n\
    \  int m= 0;\n  for (; L.back().size(); m+= 2) {\n   L.push_back({});\n   for\
    \ (int e: L[m]) {\n    if (converged= M2.oracle(e)) break;\n    for (int f: I[1])\n\
    \     if (!useless[f] && M2.oracle(f, e)) L[m + 1].push_back(f), useless[f]= true;\n\
    \   }\n   if (converged) break;\n   L.push_back({});\n   for (int e: L[m + 1])\n\
    \    for (int f: I[0])\n     if (!useless[f] && M1.oracle(e, f)) L[m + 2].push_back(f),\
    \ useless[f]= true;\n  }\n  if (!converged) break;\n  std::vector<std::vector<int>>\
    \ L2(m + 1);\n  for (int e: L[m])\n   if (M2.oracle(e)) L2[m].push_back(e);\n\
    \  for (int i= m; i; i-= 2) {\n   for (int e: L[i - 1])\n    for (int f: L2[i])\n\
    \     if (M1.oracle(e, f)) {\n      L2[i - 1].push_back(e);\n      break;\n  \
    \   }\n   for (int e: L[i - 2])\n    for (int f: L2[i - 1])\n     if (M2.oracle(f,\
    \ e)) {\n      L2[i - 2].push_back(e);\n      break;\n     }\n  }\n  auto dfs=\
    \ [&](auto self, int e, int i) -> bool {\n   if (useless[e]= true; i == m) return\
    \ M2.oracle(e) ? (b[e]= !b[e], true) : false;\n   for (int f: L2[i + 1])\n   \
    \ if (!useless[f] && M2.oracle(f, e)) {\n     useless[f]= true;\n     for (int\
    \ g: L2[i + 2])\n      if (!useless[g] && M1.oracle(f, g))\n       if (self(self,\
    \ g, i + 2)) return b[e]= !b[e], b[f]= !b[f], true;\n    }\n   return false;\n\
    \  };\n  useless.assign(n, false);\n  for (int e: L2[0])\n   if (M1.oracle(e)\
    \ && dfs(dfs, e, 0)) {\n    converged= false, I[0].clear(), I[1].clear();\n  \
    \  for (int u= 0; u < n; u++) I[b[u]].push_back(u);\n    M1.build(I[1]), M2.build(I[1]);\n\
    \   }\n }\n return I[1];\n}\n// sgn: + -> max, - -> min, 0 -> unweighted\ntemplate\
    \ <std::int_least8_t sgn, class Matroid1, class Matroid2, class cost_t> std::vector<std::vector<int>>\
    \ weighted_matroid_intersection(int n, Matroid1 M1, Matroid2 M2, std::vector<cost_t>\
    \ c) {\n assert(n == (int)c.size());\n bool b[n];\n std::fill_n(b, n, false);\n\
    \ std::vector<int> I[2], p;\n std::vector<std::vector<int>> ret(1);\n for (int\
    \ u= 0; u < n; u++) I[0].push_back(u);\n if constexpr (sgn > 0) {\n  auto cmx=\
    \ *std::max_element(c.begin(), c.end());\n  for (auto &x: c) x-= cmx;\n } else\
    \ {\n  auto cmi= *std::min_element(c.begin(), c.end());\n  for (auto &x: c) x-=\
    \ cmi;\n }\n for (auto &x: c) x*= sgn * (n + 1);\n for (bool converged= false;\
    \ !converged;) {\n  converged= true, M1.build(I[1]), M2.build(I[1]);\n  std::priority_queue<std::pair<cost_t,\
    \ int>> pq;\n  std::vector<cost_t> dist(n, std::numeric_limits<cost_t>::lowest());\n\
    \  for (int u: I[0])\n   if (M1.oracle(u)) pq.emplace(dist[u]= c[u] - 1, u);\n\
    \  for (p.assign(n, -1); pq.size();) {\n   auto [d, u]= pq.top();\n   if (pq.pop();\
    \ d != dist[u]) continue;\n   if (b[u]) {\n    for (int v: I[0])\n     if (M1.oracle(u,\
    \ v))\n      if (cost_t cost= d + c[v] - 1; dist[v] < cost) pq.emplace(dist[v]=\
    \ cost, v), p[v]= u;\n   } else {\n    if (M2.oracle(u)) {\n     for (int v= u;\
    \ v != -1; v= p[v]) b[v]= !b[v];\n     I[0].clear(), I[1].clear(), converged=\
    \ false;\n     for (int u= 0; u < n; u++) I[b[u]].push_back(u);\n     ret.emplace_back(I[1]);\n\
    \     break;\n    }\n    for (int v: I[1])\n     if (M2.oracle(v, u))\n      if\
    \ (cost_t cost= d - c[v] - 1; dist[v] < cost) pq.emplace(dist[v]= cost, v), p[v]=\
    \ u;\n   }\n  }\n }\n return ret;\n}\nclass GraphicMatroid {\n int n, t;\n std::vector<std::array<int,\
    \ 2>> edges;\n std::vector<std::vector<int>> g;\n std::vector<int> comp, in, out;\n\
    \ void dfs(int u) {\n  in[u]= t++;\n  for (auto v: g[u])\n   if (in[v] == -1)\
    \ comp[v]= comp[u], dfs(v);\n  out[u]= t;\n }\n inline bool is_ancestor(int u,\
    \ int v) const { return in[u] <= in[v] && in[v] < out[u]; }\npublic:\n GraphicMatroid(int\
    \ n_): n(n_), g(n), comp(n), in(n), out(n) {}\n void add_edge(int u, int v) {\
    \ edges.emplace_back(std::array{u, v}); }\n void build(const std::vector<int>\
    \ &I) {\n  t= 0;\n  for (int u= 0; u < n; u++) g[u].clear(), in[u]= -1;\n  for\
    \ (int e: I) {\n   int u= edges[e][0], v= edges[e][1];\n   g[u].push_back(v),\
    \ g[v].push_back(u);\n  }\n  for (int u= 0; u < n; u++)\n   if (in[u] == -1) comp[u]=\
    \ u, dfs(u);\n }\n inline bool oracle(int e) const { return comp[edges[e][0]]\
    \ != comp[edges[e][1]]; }\n inline bool oracle(int e, int f) const {\n  if (oracle(f))\
    \ return true;\n  int u= edges[e][in[edges[e][0]] < in[edges[e][1]]];\n  return\
    \ is_ancestor(u, edges[f][0]) != is_ancestor(u, edges[f][1]);\n }\n};\nstruct\
    \ PartitionMatroid {\n std::vector<int> belong, R, cnt;\n PartitionMatroid(int\
    \ m_, const std::vector<std::vector<int>> &parts, const std::vector<int> &R_):\
    \ belong(m_, -1), R(R_) {\n  assert(parts.size() == R.size());\n  for (int i=\
    \ parts.size(); i--;)\n   for (int e: parts[i]) belong[e]= i;\n }\n void build(const\
    \ std::vector<int> &I) {\n  cnt= R;\n  for (int e: I)\n   if (belong[e] != -1)\
    \ cnt[belong[e]]--;\n }\n inline bool oracle(int e) const { return belong[e] ==\
    \ -1 || cnt[belong[e]] > 0; }\n inline bool oracle(int e, int f) const { return\
    \ oracle(f) || belong[e] == belong[f]; }\n};\n#line 6 \"test/aoj/GRL_2_B.matroid_intersection.test.cpp\"\
    \nusing namespace std;\nint main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, M, r;\n cin >> N >> M >> r;\n GraphicMatroid M1(N);\n vector<int> w(M);\n\
    \ vector<vector<int>> parts(N);\n for (int i= 0; i < M; i++) {\n  int s, t;\n\
    \  cin >> s >> t >> w[i];\n  M1.add_edge(s, t);\n  parts[t].push_back(i);\n }\n\
    \ vector<int> R(N, 1);\n R[r]= 0;\n PartitionMatroid M2(M, parts, R);\n auto S=\
    \ weighted_matroid_intersection<-1>(M, M1, M2, w);\n int ans= 0;\n for (int e:\
    \ S[N - 1]) ans+= w[e];\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B\"\
    \n// \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728(\u30B0\u30E9\u30D5+\u5206\u5272\
    )\n#include <iostream>\n#include <vector>\n#include \"src/Optimization/matroid_intersection.hpp\"\
    \nusing namespace std;\nint main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, M, r;\n cin >> N >> M >> r;\n GraphicMatroid M1(N);\n vector<int> w(M);\n\
    \ vector<vector<int>> parts(N);\n for (int i= 0; i < M; i++) {\n  int s, t;\n\
    \  cin >> s >> t >> w[i];\n  M1.add_edge(s, t);\n  parts[t].push_back(i);\n }\n\
    \ vector<int> R(N, 1);\n R[r]= 0;\n PartitionMatroid M2(M, parts, R);\n auto S=\
    \ weighted_matroid_intersection<-1>(M, M1, M2, w);\n int ans= 0;\n for (int e:\
    \ S[N - 1]) ans+= w[e];\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/matroid_intersection.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_B.matroid_intersection.test.cpp
  requiredBy: []
  timestamp: '2023-01-22 00:08:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_B.matroid_intersection.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_B.matroid_intersection.test.cpp
- /verify/test/aoj/GRL_2_B.matroid_intersection.test.cpp.html
title: test/aoj/GRL_2_B.matroid_intersection.test.cpp
---