---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/UnionFind.hpp
    title: Union-Find
  - icon: ':x:'
    path: src/Graph/BipartiteEdgeColoring.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u8FBA\u5F69\u8272"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartite_edge_coloring
    links:
    - https://judge.yosupo.jp/problem/bipartite_edge_coloring
  bundledCode: "#line 1 \"test/yosupo/bipartite_edge_coloring.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartite_edge_coloring\"\n#include\
    \ <iostream>\n#include <algorithm>\n#line 2 \"src/Graph/BipartiteEdgeColoring.hpp\"\
    \n#include <array>\n#include <queue>\n#include <numeric>\n#line 2 \"src/DataStructure/UnionFind.hpp\"\
    \n#include <vector>\n#line 4 \"src/DataStructure/UnionFind.hpp\"\n#include <cassert>\n\
    template <bool undoable= false> class UnionFind {\n std::vector<int> par;\n std::vector<std::pair<int,\
    \ int>> his;\npublic:\n UnionFind(int n): par(n, -1) {}\n bool unite(int u, int\
    \ v) {\n  if ((u= root(u)) == (v= root(v))) return false;\n  if (par[u] > par[v])\
    \ std::swap(u, v);\n  if constexpr (undoable) his.emplace_back(v, par[v]);\n \
    \ return par[u]+= par[v], par[v]= u, true;\n }\n bool same(int u, int v) { return\
    \ root(u) == root(v); }\n int root(int u) {\n  if constexpr (undoable) return\
    \ par[u] < 0 ? u : root(par[u]);\n  else return par[u] < 0 ? u : par[u]= root(par[u]);\n\
    \ }\n int size(int u) { return -par[root(u)]; }\n int time() const {\n  static_assert(undoable,\
    \ \"\\'time\\' is not enabled\");\n  return his.size();\n }\n void undo() {\n\
    \  static_assert(undoable, \"\\'undo\\' is not enabled\");\n  auto [u, s]= his.back();\n\
    \  his.pop_back(), par[par[u]]-= s, par[u]= s;\n }\n void rollback(size_t t) {\n\
    \  static_assert(undoable, \"\\'rollback\\' is not enabled\");\n  assert(t <=\
    \ his.size());\n  while (his.size() > t) undo();\n }\n};\n#line 6 \"src/Graph/BipartiteEdgeColoring.hpp\"\
    \nclass BipartiteEdgeColoring {\n std::vector<std::array<int, 2>> es_;\n const\
    \ int n[2];\npublic:\n BipartiteEdgeColoring(int L, int R): n{L, R} {}\n void\
    \ add_edge(int l, int r) { es_.push_back({l, r}); }\n std::vector<int> edge_coloring()\
    \ {\n  auto es= es_;\n  const int m= es.size();\n  std::vector<int> color(m, -1),\
    \ deg[2]= {std::vector<int>(n[0]), std::vector<int>(n[1])};\n  for (auto [l, r]:\
    \ es) ++deg[0][l], ++deg[1][r];\n  const int D= std::max(*std::max_element(deg[0].begin(),\
    \ deg[0].end()), *std::max_element(deg[1].begin(), deg[1].end()));\n  UnionFind<>\
    \ uf[2]= {UnionFind(n[0]), UnionFind(n[1])};\n  int cnt[2], col= 0;\n  for (int\
    \ s= 2; s--;) {\n   std::priority_queue<std::pair<int, int>> pq;\n   for (int\
    \ i= n[s]; i--;) pq.emplace(-deg[s][i], i);\n   for (cnt[s]= pq.size(); pq.size()\
    \ > 1;) {\n    auto [as, av]= pq.top();\n    pq.pop();\n    auto [bs, bv]= pq.top();\n\
    \    pq.pop();\n    if (int sum= as + bs; -sum <= D) uf[s].unite(av, bv), pq.emplace(sum,\
    \ av), --cnt[s];\n    else break;\n   }\n  }\n  std::vector<int> id[2]= {std::vector<int>(n[0],\
    \ -1), std::vector<int>(n[1], -1)};\n  for (int s= 2; s--;)\n   for (int i= n[s],\
    \ j= 0; i--;)\n    if (uf[s].root(i) == i) id[s][i]= j++;\n  const int n= std::max(cnt[0],\
    \ cnt[1]);\n  deg[0].assign(n, 0), deg[1].assign(n, 0), es.reserve(n * D);\n \
    \ for (auto &e: es) ++deg[0][e[0]= id[0][uf[0].root(e[0])]], ++deg[1][e[1]= id[1][uf[1].root(e[1])]],\
    \ e[1]+= n;\n  for (int v= 0, w= 0; v < n; ++v) {\n   while (deg[0][v] < D) {\n\
    \    while (w < n && deg[1][w] == D) ++w;\n    int x= std::min(D - deg[1][w],\
    \ D - deg[0][v]);\n    for (int k= x; k--;) es.push_back({v, w + n});\n    deg[0][v]+=\
    \ x, deg[1][w]+= x;\n   }\n  }\n  auto rec= [&](auto rec, int d, const std::vector<int>\
    \ &idx) {\n   if (!d) return;\n   if (d == 1) {\n    for (int e: idx)\n     if\
    \ (e < m) color[e]= col;\n    ++col;\n   } else if (d & 1) {\n    std::vector<int>\
    \ mate(n + n, -1), g(idx.size()), pos(n + 1), pre, que(n), rt;\n    for (int e:\
    \ idx) ++pos[es[e][0]];\n    for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n\
    \    for (int e: idx) {\n     auto [l, r]= es[e];\n     g[--pos[l]]= r;\n    }\n\
    \    for (bool upd= true; upd;) {\n     upd= false, rt.assign(n, -1), pre.assign(n,\
    \ -1);\n     int t= 0;\n     for (int l= n; l--;)\n      if (mate[l] == -1) que[t++]=\
    \ rt[l]= pre[l]= l;\n     for (int i= 0; i < t; ++i)\n      if (int v= que[i];\
    \ mate[rt[v]] == -1)\n       for (int j= pos[v], u, w; j < pos[v + 1]; ++j) {\n\
    \        if (w= mate[u= g[j]]; w == -1) {\n         for (upd= true; u != -1; v=\
    \ pre[v]) mate[u]= v, std::swap(mate[v], u);\n         break;\n        }\n   \
    \     if (pre[w] == -1) rt[que[t++]= w]= rt[pre[w]= v];\n       }\n    }\n   \
    \ rt.clear(), rt.reserve(idx.size());\n    for (int e: idx) {\n     auto [l, r]=\
    \ es[e];\n     if (mate[l] == r) {\n      if (mate[l]= mate[r]= -1; e < m) color[e]=\
    \ col;\n     } else rt.push_back(e);\n    }\n    ++col, rec(rec, d - 1, rt);\n\
    \   } else {\n    const int mm= idx.size();\n    std::vector<std::array<int, 2>>\
    \ g(mm * 2), st;\n    std::vector<int> pos(n + n + 1), circuit, half1(mm / 2),\
    \ half2(mm / 2);\n    std::vector<int8_t> used1(n + n), used2(mm);\n    for (int\
    \ e: idx) {\n     auto [l, r]= es[e];\n     ++pos[l], ++pos[r];\n    }\n    std::partial_sum(pos.begin(),\
    \ pos.end(), pos.begin()), st.reserve(mm + 1), circuit.reserve(mm + 1);\n    for\
    \ (int i= mm; i--;) {\n     auto [l, r]= es[idx[i]];\n     g[--pos[l]]= {r, i},\
    \ g[--pos[r]]= {l, i};\n    }\n    std::vector<int> it(pos.begin(), pos.begin()\
    \ + n + n);\n    for (int v= n + n; v--;)\n     if (!used1[v]) {\n      for (st.clear(),\
    \ st.push_back({v, -1}); st.size();) {\n       auto [p, e]= st.back();\n     \
    \  used1[p]= true;\n       if (it[p] == pos[p + 1]) circuit.push_back(e), st.pop_back();\n\
    \       else if (const auto &a= g[it[p]++]; !used2[a[1]]) used2[a[1]]= true, st.push_back(a);\n\
    \      }\n      circuit.pop_back();\n     }\n    for (int i= 0; i < mm; i+= 2)\
    \ half1[i / 2]= idx[circuit[i]], half2[i / 2]= idx[circuit[i + 1]];\n    rec(rec,\
    \ d / 2, half1), rec(rec, d / 2, half2);\n   }\n  };\n  std::vector<int> idx(n\
    \ * D);\n  return iota(idx.begin(), idx.end(), 0), rec(rec, D, idx), color;\n\
    \ }\n};\n#line 5 \"test/yosupo/bipartite_edge_coloring.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int L, R, M;\n\
    \ cin >> L >> R >> M;\n BipartiteEdgeColoring graph(L, R);\n for (int i= 0; i\
    \ < M; ++i) {\n  int a, b;\n  cin >> a >> b;\n  graph.add_edge(a, b);\n }\n auto\
    \ ans= graph.edge_coloring();\n cout << *max_element(ans.begin(), ans.end()) +\
    \ 1 << '\\n';\n for (auto a: ans) cout << a << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartite_edge_coloring\"\
    \n#include <iostream>\n#include <algorithm>\n#include \"src/Graph/BipartiteEdgeColoring.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int L, R, M;\n cin >> L >> R >> M;\n BipartiteEdgeColoring graph(L, R);\n for\
    \ (int i= 0; i < M; ++i) {\n  int a, b;\n  cin >> a >> b;\n  graph.add_edge(a,\
    \ b);\n }\n auto ans= graph.edge_coloring();\n cout << *max_element(ans.begin(),\
    \ ans.end()) + 1 << '\\n';\n for (auto a: ans) cout << a << '\\n';\n return 0;\n\
    }"
  dependsOn:
  - src/Graph/BipartiteEdgeColoring.hpp
  - src/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/yosupo/bipartite_edge_coloring.test.cpp
  requiredBy: []
  timestamp: '2024-02-17 10:13:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/bipartite_edge_coloring.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartite_edge_coloring.test.cpp
- /verify/test/yosupo/bipartite_edge_coloring.test.cpp.html
title: test/yosupo/bipartite_edge_coloring.test.cpp
---
