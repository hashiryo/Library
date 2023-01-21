---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3032.test.cpp
    title: test/aoj/3032.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/general_matching.test.cpp
    title: test/yosupo/general_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/Matching.hpp\"\n#include <vector>\n#include\
    \ <array>\n#include <queue>\nclass Matching {\n int n, ret;\n std::vector<std::vector<int>>\
    \ adj;\n std::vector<int> mt, idx, p;\n std::vector<std::array<int, 2>> es;\n\
    \ void rematch(int u, int v, int w= -1) {\n  if (w= mt[u], mt[u]= v; w == -1 ||\
    \ mt[w] != u) return;\n  if (es[u][1] == -1) {\n   rematch(mt[w]= es[u][0], w);\n\
    \  } else rematch(es[u][0], es[u][1]), rematch(es[u][1], es[u][0]);\n }\n int\
    \ f(int x) { return (idx[x] != ret || p[x] == -1) ? x : (p[x]= f(p[x])); }\n bool\
    \ check(int root) {\n  std::queue<int> que;\n  es[root]= {-1, -1}, idx[root]=\
    \ ret, p[root]= -1, que.push(root);\n  for (int x, u, v, w; !que.empty();) {\n\
    \   x= que.front(), que.pop();\n   for (int y: adj[x]) {\n    if (y == root) continue;\n\
    \    if (mt[y] == -1) {\n     return rematch(mt[y]= x, y), true;\n    } else if\
    \ (idx[y] == ret) {\n     if (u= f(x), v= f(y), w= root; u == v) continue;\n \
    \    for (; u != root || v != root; es[u]= {x, y}, u= f(es[mt[u]][0])) {\n   \
    \   if (v != root) std::swap(u, v);\n      if (es[u][0] == x && es[u][1] == y)\
    \ {\n       w= u;\n       break;\n      }\n     }\n     for (int t= f(x); t !=\
    \ w; t= f(es[mt[t]][0])) idx[t]= ret, p[t]= w, que.push(t);\n     for (int t=\
    \ f(y); t != w; t= f(es[mt[t]][0])) idx[t]= ret, p[t]= w, que.push(t);\n    }\
    \ else if (idx[mt[y]] != ret) es[y]= {-1, -1}, es[mt[y]]= {x, -1}, idx[mt[y]]=\
    \ ret, p[mt[y]]= y, que.push(mt[y]);\n   }\n  }\n  return false;\n }\npublic:\n\
    \ Matching(int n): n(n), ret(0), adj(n), mt(n, -1), idx(n, -1), p(n), es(n) {}\n\
    \ void add_edge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }\n\
    \ std::pair<int, std::vector<int>> get_matching() {\n  for (int i= 0; i < n; i++)\n\
    \   if (mt[i] == -1) ret+= check(i);\n  return std::make_pair(ret, mt);\n }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <queue>\nclass\
    \ Matching {\n int n, ret;\n std::vector<std::vector<int>> adj;\n std::vector<int>\
    \ mt, idx, p;\n std::vector<std::array<int, 2>> es;\n void rematch(int u, int\
    \ v, int w= -1) {\n  if (w= mt[u], mt[u]= v; w == -1 || mt[w] != u) return;\n\
    \  if (es[u][1] == -1) {\n   rematch(mt[w]= es[u][0], w);\n  } else rematch(es[u][0],\
    \ es[u][1]), rematch(es[u][1], es[u][0]);\n }\n int f(int x) { return (idx[x]\
    \ != ret || p[x] == -1) ? x : (p[x]= f(p[x])); }\n bool check(int root) {\n  std::queue<int>\
    \ que;\n  es[root]= {-1, -1}, idx[root]= ret, p[root]= -1, que.push(root);\n \
    \ for (int x, u, v, w; !que.empty();) {\n   x= que.front(), que.pop();\n   for\
    \ (int y: adj[x]) {\n    if (y == root) continue;\n    if (mt[y] == -1) {\n  \
    \   return rematch(mt[y]= x, y), true;\n    } else if (idx[y] == ret) {\n    \
    \ if (u= f(x), v= f(y), w= root; u == v) continue;\n     for (; u != root || v\
    \ != root; es[u]= {x, y}, u= f(es[mt[u]][0])) {\n      if (v != root) std::swap(u,\
    \ v);\n      if (es[u][0] == x && es[u][1] == y) {\n       w= u;\n       break;\n\
    \      }\n     }\n     for (int t= f(x); t != w; t= f(es[mt[t]][0])) idx[t]= ret,\
    \ p[t]= w, que.push(t);\n     for (int t= f(y); t != w; t= f(es[mt[t]][0])) idx[t]=\
    \ ret, p[t]= w, que.push(t);\n    } else if (idx[mt[y]] != ret) es[y]= {-1, -1},\
    \ es[mt[y]]= {x, -1}, idx[mt[y]]= ret, p[mt[y]]= y, que.push(mt[y]);\n   }\n \
    \ }\n  return false;\n }\npublic:\n Matching(int n): n(n), ret(0), adj(n), mt(n,\
    \ -1), idx(n, -1), p(n), es(n) {}\n void add_edge(int u, int v) { adj[u].push_back(v),\
    \ adj[v].push_back(u); }\n std::pair<int, std::vector<int>> get_matching() {\n\
    \  for (int i= 0; i < n; i++)\n   if (mt[i] == -1) ret+= check(i);\n  return std::make_pair(ret,\
    \ mt);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/Matching.hpp
  requiredBy: []
  timestamp: '2023-01-21 23:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3032.test.cpp
  - test/yosupo/general_matching.test.cpp
documentation_of: src/Optimization/Matching.hpp
layout: document
title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\u822C\u30B0\u30E9\u30D5)"
---
 -  GabowのEdmonds' Algorithm
 -  返り値:{マッチング数,各頂点の相方(いないなら-1）}

## 計算量
$\mathcal{O}(VE \log V)$