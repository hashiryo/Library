---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/MaxClique.hpp
    title: "\u6700\u5927\u30AF\u30EA\u30FC\u30AF"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo/maximum_independent_set.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n#include\
    \ <iostream>\n#line 2 \"src/Graph/MaxClique.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\nclass MaxClique {\n const int n, m;\n using u128= __uint128_t;\n\
    \ using u64= uint64_t;\n using u16= uint16_t;\n struct id_num {\n  u16 id, num;\n\
    \ };\n std::vector<u128> adj, buf, adj_;\n std::vector<u16> deg, clique, cur;\n\
    \ void dfs(std::vector<id_num> &rem) {\n  if (clique.size() < cur.size()) clique=\
    \ cur;\n  std::sort(rem.begin(), rem.end(), [&](id_num l, id_num r) { return deg[l.id]\
    \ > deg[r.id]; });\n  buf.assign((n + 1) * m, 0);\n  for (auto &v: rem) {\n  \
    \ int b= v.id * m, bb= 0;\n   for (v.num= 0;; ++v.num, bb+= m) {\n    bool any=\
    \ 1;\n    for (int i= 0; i < m; ++i) any&= !(adj[b + i] & buf[bb + i]);\n    if\
    \ (any) break;\n   }\n   buf[bb + (v.id >> 7)]|= u128(1) << (v.id & 127);\n  }\n\
    \  std::sort(rem.begin(), rem.end(), [&](id_num l, id_num r) { return l.num <\
    \ r.num; });\n  std::vector<id_num> nrem;\n  for (nrem.reserve(rem.size()); !rem.empty();)\
    \ {\n   auto p= rem.back();\n   int a= p.id * m;\n   if (p.num + cur.size() <\
    \ clique.size()) break;\n   nrem.clear();\n   for (auto u: rem)\n    if ((adj[a\
    \ + (u.id >> 7)] >> (u.id & 127)) & 1) nrem.emplace_back(u);\n   std::fill_n(buf.begin(),\
    \ m, 0);\n   for (auto u: nrem) buf[u.id >> 7]|= u128(1) << (u.id & 127);\n  \
    \ for (auto u: nrem) {\n    int b= u.id * m, i= 0;\n    for (u128 tmp; i < m;\
    \ ++i) tmp= buf[i] & adj[b + i], deg[u.id]+= __builtin_popcountll(tmp >> 64) +\
    \ __builtin_popcountll(u64(tmp));\n   }\n   cur.push_back(p.id), dfs(nrem), cur.pop_back(),\
    \ rem.pop_back();\n  }\n }\n void calc(bool complement) {\n  adj.assign(adj_.begin(),\
    \ adj_.end());\n  if (complement)\n   for (int u= n; u--;)\n    for (int v= u;\
    \ v--;) adj[u * m + (v >> 7)]^= u128(1) << (v & 127), adj[v * m + (u >> 7)]^=\
    \ u128(1) << (u & 127);\n  std::vector<id_num> nrem;\n  for (u16 u= n; u--;) {\n\
    \   nrem.push_back(id_num{u, 0});\n   int b= u * m, i= 0;\n   for (u128 tmp; i\
    \ < m; ++i) tmp= adj[b + i], deg[u]+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \  }\n  dfs(nrem);\n }\npublic:\n MaxClique(int n): n(n), m((n + 127) >> 7), deg(n),\
    \ adj_(n * m) {}\n void add_edge(int u, int v) { adj_[u * m + (v >> 7)]|= u128(1)\
    \ << (v & 127), adj_[v * m + (u >> 7)]|= u128(1) << (u & 127); }\n std::vector<u16>\
    \ get_max_clique() { return calc(false), clique; }\n std::vector<u16> get_max_independent_set()\
    \ { return calc(true), clique; }\n std::vector<u16> get_min_vertex_cover() {\n\
    \  calc(true), std::fill_n(buf.begin(), m, 0);\n  for (int u: clique) buf[u >>\
    \ 7]|= u128(1) << (u & 127);\n  std::vector<u16> ret;\n  for (int i= 0; i < n;\
    \ ++i)\n   if (!((buf[i >> 7] >> (i & 127)) & 1)) ret.push_back(i);\n  return\
    \ ret;\n }\n};\n#line 4 \"test/yosupo/maximum_independent_set.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N, M;\n cin >> N >> M;\n MaxClique graph(N);\n while (M--) {\n  int u, v;\n\
    \  cin >> u >> v;\n  graph.add_edge(u, v);\n }\n auto ans= graph.get_max_independent_set();\n\
    \ int n= ans.size();\n cout << n << '\\n';\n for (int i= 0; i < n; i++) cout <<\
    \ ans[i] << \" \\n\"[i == n - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include <iostream>\n#include \"src/Graph/MaxClique.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N, M;\n cin >>\
    \ N >> M;\n MaxClique graph(N);\n while (M--) {\n  int u, v;\n  cin >> u >> v;\n\
    \  graph.add_edge(u, v);\n }\n auto ans= graph.get_max_independent_set();\n int\
    \ n= ans.size();\n cout << n << '\\n';\n for (int i= 0; i < n; i++) cout << ans[i]\
    \ << \" \\n\"[i == n - 1];\n return 0;\n}"
  dependsOn:
  - src/Graph/MaxClique.hpp
  isVerificationFile: true
  path: test/yosupo/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2023-05-04 18:27:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/maximum_independent_set.test.cpp
- /verify/test/yosupo/maximum_independent_set.test.cpp.html
title: test/yosupo/maximum_independent_set.test.cpp
---
