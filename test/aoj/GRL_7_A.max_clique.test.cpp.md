---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/MaxClique.hpp
    title: "\u6700\u5927\u30AF\u30EA\u30FC\u30AF"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A.max_clique.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A\"\n// 200\
    \ (=100+100) \u9802\u70B9\n#include <iostream>\n#line 2 \"src/Graph/MaxClique.hpp\"\
    \n#include <vector>\n#include <algorithm>\nclass MaxClique {\n const int n, m;\n\
    \ using u128= __uint128_t;\n using u64= std::uint64_t;\n using u16= std::uint16_t;\n\
    \ struct id_num {\n  u16 id, num;\n };\n std::vector<u128> adj, buf;\n std::vector<u16>\
    \ deg, clique, cur;\n void dfs(std::vector<id_num> &rem) {\n  if (clique.size()\
    \ < cur.size()) clique= cur;\n  std::sort(rem.begin(), rem.end(), [&](id_num l,\
    \ id_num r) { return deg[l.id] > deg[r.id]; });\n  buf.assign((n + 1) * m, 0);\n\
    \  for (auto &v: rem) {\n   int b= v.id * m, bb= 0;\n   for (v.num= 0;; ++v.num,\
    \ bb+= m) {\n    bool any= 1;\n    for (int i= 0; i < m; ++i) any&= !(adj[b +\
    \ i] & buf[bb + i]);\n    if (any) break;\n   }\n   buf[bb + (v.id >> 7)]|= u128(1)\
    \ << (v.id & 127);\n  }\n  std::sort(rem.begin(), rem.end(), [&](id_num l, id_num\
    \ r) { return l.num < r.num; });\n  std::vector<id_num> nrem;\n  for (nrem.reserve(rem.size());\
    \ !rem.empty();) {\n   auto p= rem.back();\n   int a= p.id * m;\n   if (p.num\
    \ + cur.size() < clique.size()) break;\n   nrem.clear();\n   for (auto u: rem)\n\
    \    if ((adj[a + (u.id >> 7)] >> (u.id & 127)) & 1) nrem.emplace_back(u);\n \
    \  std::fill_n(buf.begin(), m, 0);\n   for (auto u: nrem) buf[u.id >> 7]|= u128(1)\
    \ << (u.id & 127);\n   for (auto u: nrem) {\n    int b= u.id * m, cnt= 0;\n  \
    \  for (int i= 0; i < m; ++i) {\n     u128 tmp= buf[i] & adj[b + i];\n     cnt+=\
    \ __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n    }\n \
    \   deg[u.id]= cnt;\n   }\n   cur.push_back(p.id), dfs(nrem), cur.pop_back(),\
    \ rem.pop_back();\n  }\n }\npublic:\n MaxClique(int n): n(n), m((n + 127) >> 7),\
    \ adj(n * m), deg(n) {}\n void add_edge(int u, int v) { adj[u * m + (v >> 7)]|=\
    \ u128(1) << (v & 127), adj[v * m + (u >> 7)]|= u128(1) << (u & 127); }\n std::vector<u16>\
    \ get_max_clique() {\n  std::vector<id_num> nrem;\n  for (std::uint16_t u= n;\
    \ u--;) {\n   nrem.push_back(id_num{u, 0});\n   int cnt= 0, b= u * m;\n   for\
    \ (int i= 0; i < m; ++i) {\n    u128 tmp= adj[b + i];\n    cnt+= __builtin_popcountll(tmp\
    \ >> 64) + __builtin_popcountll(u64(tmp));\n   }\n   deg[u]= cnt;\n  }\n  dfs(nrem);\n\
    \  return clique;\n }\n std::vector<u16> get_max_independent_set() {\n  for (int\
    \ u= n; u--;)\n   for (int v= u; v--;) adj[u * m + (v >> 7)]^= u128(1) << (v &\
    \ 127), adj[v * m + (u >> 7)]^= u128(1) << (u & 127);\n  return get_max_clique();\n\
    \ }\n std::vector<u16> get_min_vertex_cover() {\n  for (int u= n; u--;)\n   for\
    \ (int v= u; v--;) adj[u * m + (v >> 7)]^= u128(1) << (v & 127), adj[v * m + (u\
    \ >> 7)]^= u128(1) << (u & 127);\n  std::vector<id_num> nrem;\n  for (std::uint16_t\
    \ u= n; u--;) {\n   nrem.push_back(id_num{u, 0});\n   int cnt= 0, b= u * m;\n\
    \   for (int i= 0; i < m; ++i) {\n    u128 tmp= adj[b + i];\n    cnt+= __builtin_popcountll(tmp\
    \ >> 64) + __builtin_popcountll(u64(tmp));\n   }\n   deg[u]= cnt;\n  }\n  dfs(nrem);\n\
    \  std::fill_n(buf.begin(), m, 0);\n  for (int u: clique) buf[u >> 7]|= u128(1)\
    \ << (u & 127);\n  std::vector<u16> ret;\n  for (int i= 0; i < n; ++i)\n   if\
    \ (!((buf[i >> 7] >> (i & 127)) & 1)) ret.push_back(i);\n  return ret;\n }\n};\n\
    #line 5 \"test/aoj/GRL_7_A.max_clique.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int X, Y, E;\n cin >> X\
    \ >> Y >> E;\n MaxClique graph(X + Y);\n for (int i= 0; i < E; ++i) {\n  int x,\
    \ y;\n  cin >> x >> y;\n  graph.add_edge(x, X + y);\n }\n cout << graph.get_min_vertex_cover().size()\
    \ << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A\"\
    \n// 200 (=100+100) \u9802\u70B9\n#include <iostream>\n#include \"src/Graph/MaxClique.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int X, Y, E;\n cin >> X >> Y >> E;\n MaxClique graph(X + Y);\n for (int i= 0;\
    \ i < E; ++i) {\n  int x, y;\n  cin >> x >> y;\n  graph.add_edge(x, X + y);\n\
    \ }\n cout << graph.get_min_vertex_cover().size() << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/MaxClique.hpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.max_clique.test.cpp
  requiredBy: []
  timestamp: '2023-02-08 22:23:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.max_clique.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.max_clique.test.cpp
- /verify/test/aoj/GRL_7_A.max_clique.test.cpp.html
title: test/aoj/GRL_7_A.max_clique.test.cpp
---
