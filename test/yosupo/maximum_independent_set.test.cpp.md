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
    PROBLEM: https://old.yosupo.jp/problem/maximum_independent_set
    links:
    - https://old.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo/maximum_independent_set.test.cpp\"\n#define\
    \ PROBLEM \"https://old.yosupo.jp/problem/maximum_independent_set\"\n#include\
    \ <iostream>\n#line 2 \"src/Graph/MaxClique.hpp\"\n#include <vector>\n#include\
    \ <bitset>\n#include <algorithm>\nclass MaxClique {\n struct id_num {\n  std::size_t\
    \ id, num;\n };\n std::vector<std::bitset<128>> adj, buf;\n std::bitset<128> clique,\
    \ cur;\n std::vector<int> deg;\n void dfs(std::vector<id_num>& rem) {\n  if (clique.count()\
    \ < cur.count()) clique= cur;\n  std::sort(rem.begin(), rem.end(), [&](id_num\
    \ l, id_num r) { return deg[l.id] > deg[r.id]; });\n  std::size_t max_num= 1;\n\
    \  for (auto& v: rem) {\n   v.num= 0;\n   while ((adj[v.id] & buf[v.num]).any())\
    \ v.num++;\n   buf[v.num].set(v.id), max_num= std::max(max_num, v.num + 1);\n\
    \  }\n  for (int i= max_num - 1; i >= 0; i--) buf[i].reset();\n  std::sort(rem.begin(),\
    \ rem.end(), [&](id_num l, id_num r) { return l.num < r.num; });\n  std::vector<id_num>\
    \ nrem;\n  while (!rem.empty() && rem.back().num + cur.count() >= clique.count())\
    \ {\n   for (auto u: rem)\n    if (adj[rem.back().id][u.id]) nrem.emplace_back(u),\
    \ buf[0].set(u.id);\n   for (auto u: nrem) deg[u.id]= (buf[0] & adj[u.id]).count();\n\
    \   buf[0].reset(), cur.set(rem.back().id);\n   dfs(nrem);\n   nrem.clear(), cur.reset(rem.back().id),\
    \ rem.pop_back();\n  }\n }\npublic:\n MaxClique(int n_): adj(n_), buf(n_ + 1),\
    \ deg(n_) {}\n void add_edge(int u, int v) { adj[u][v]= adj[v][u]= true; }\n std::vector<int>\
    \ get_max_clique() {\n  std::vector<id_num> nrem;\n  for (int i= adj.size() -\
    \ 1; i >= 0; i--) nrem.emplace_back(id_num{(std::size_t)i, 0}), deg[i]= adj[i].count();\n\
    \  dfs(nrem);\n  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n;\
    \ i++)\n   if (clique[i]) ret.push_back(i);\n  return ret;\n }\n std::vector<int>\
    \ get_max_independent_set() {\n  for (int i= adj.size() - 1; i >= 0; i--)\n  \
    \ for (int j= i - 1; j >= 0; j--) adj[i][j]= adj[j][i]= ~adj[j][i];\n  return\
    \ get_max_clique();\n }\n std::vector<int> get_min_vertex_cover() {\n  get_max_independent_set();\n\
    \  std::vector<int> ret;\n  for (int i= 0, n= adj.size(); i < n; i++)\n   if (!clique[i])\
    \ ret.push_back(i);\n  return ret;\n }\n};\n#line 4 \"test/yosupo/maximum_independent_set.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, M;\n cin >> N >> M;\n MaxClique graph(N);\n while (M--) {\n  int u, v;\n\
    \  cin >> u >> v;\n  graph.add_edge(u, v);\n }\n auto ans= graph.get_max_independent_set();\n\
    \ int n= ans.size();\n cout << n << '\\n';\n for (int i= 0; i < n; i++) cout <<\
    \ ans[i] << \" \\n\"[i == n - 1];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/maximum_independent_set\"\
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
  timestamp: '2023-01-23 16:45:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/maximum_independent_set.test.cpp
- /verify/test/yosupo/maximum_independent_set.test.cpp.html
title: test/yosupo/maximum_independent_set.test.cpp
---
