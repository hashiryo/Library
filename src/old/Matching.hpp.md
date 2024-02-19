---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/old/Matching.hpp\"\n#include <vector>\n#include <array>\n\
    class Matching {\n std::vector<std::array<int, 2>> es;\n std::vector<int> mate;\n\
    public:\n Matching(int n): mate(n, -1) {}\n void add_edge(int u, int v) { es.push_back({u,\
    \ v}); }\n void build() {\n  const int n= mate.size();\n  std::vector<int> g(es.size()\
    \ * 2), pos(n + 1), que(n), id(n, -1), p(n);\n  std::vector<std::array<int, 2>>\
    \ fs(n);\n  for (auto [u, v]: es) ++pos[u], ++pos[v];\n  for (int i= 0; i < n;\
    \ ++i) pos[i + 1]+= pos[i];\n  for (auto [u, v]: es) g[--pos[u]]= v, g[--pos[v]]=\
    \ u;\n  auto rematch= [&](auto self, int u, int v) -> void {\n   int w;\n   if\
    \ (w= mate[u], mate[u]= v; w == -1 || mate[w] != u) return;\n   if (auto [x, y]=\
    \ fs[u]; y == -1) self(self, mate[w]= x, w);\n   else self(self, x, y), self(self,\
    \ y, x);\n  };\n  int ts= 0;\n  auto f= [&](auto self, int x) -> int { return\
    \ id[x] != ts || p[x] == -1 ? x : (p[x]= self(self, p[x])); };\n  auto check=\
    \ [&](int rt) {\n   int s= 1;\n   fs[rt]= {-1, -1}, id[rt]= ts, p[que[0]= rt]=\
    \ -1;\n   for (int i= 0; i < s; ++i) {\n    for (int x= que[i], j= pos[x], y,\
    \ u, v, w, a, b; j < pos[x + 1]; ++j) {\n     if (y= g[j]; y == rt) continue;\n\
    \     if (mate[y] == -1) return rematch(rematch, mate[y]= x, y), true;\n     if\
    \ (id[y] == ts) {\n      if (a= u= f(f, x), b= v= f(f, y), w= rt; u == v) continue;\n\
    \      for (; u != rt || v != rt; fs[u]= {x, y}, u= f(f, fs[mate[u]][0])) {\n\
    \       if (v != rt) std::swap(u, v);\n       if (fs[u][0] == x && fs[u][1] ==\
    \ y) {\n        w= u;\n        break;\n       }\n      }\n      for (; a != w;\
    \ a= f(f, fs[mate[a]][0])) id[a]= ts, p[a]= w, que[s++]= a;\n      for (; b !=\
    \ w; b= f(f, fs[mate[b]][0])) id[b]= ts, p[b]= w, que[s++]= b;\n     } else if\
    \ (id[mate[y]] != ts) fs[y]= {-1, -1}, fs[mate[y]]= {x, -1}, id[mate[y]]= ts,\
    \ p[mate[y]]= y, que[s++]= mate[y];\n    }\n   }\n   return false;\n  };\n  for\
    \ (int rt= n; rt--;)\n   if (mate[rt] == -1) ts+= check(rt);\n }\n int match(int\
    \ u) const { return mate[u]; }\n std::vector<std::array<int, 2>> max_matching()\
    \ const {\n  std::vector<std::array<int, 2>> ret;\n  const int n= mate.size();\n\
    \  for (int i= 0; i < n; ++i)\n   if (int j= mate[i]; i < j) ret.push_back({i,\
    \ j});\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <array>\nclass Matching {\n std::vector<std::array<int,\
    \ 2>> es;\n std::vector<int> mate;\npublic:\n Matching(int n): mate(n, -1) {}\n\
    \ void add_edge(int u, int v) { es.push_back({u, v}); }\n void build() {\n  const\
    \ int n= mate.size();\n  std::vector<int> g(es.size() * 2), pos(n + 1), que(n),\
    \ id(n, -1), p(n);\n  std::vector<std::array<int, 2>> fs(n);\n  for (auto [u,\
    \ v]: es) ++pos[u], ++pos[v];\n  for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n\
    \  for (auto [u, v]: es) g[--pos[u]]= v, g[--pos[v]]= u;\n  auto rematch= [&](auto\
    \ self, int u, int v) -> void {\n   int w;\n   if (w= mate[u], mate[u]= v; w ==\
    \ -1 || mate[w] != u) return;\n   if (auto [x, y]= fs[u]; y == -1) self(self,\
    \ mate[w]= x, w);\n   else self(self, x, y), self(self, y, x);\n  };\n  int ts=\
    \ 0;\n  auto f= [&](auto self, int x) -> int { return id[x] != ts || p[x] == -1\
    \ ? x : (p[x]= self(self, p[x])); };\n  auto check= [&](int rt) {\n   int s= 1;\n\
    \   fs[rt]= {-1, -1}, id[rt]= ts, p[que[0]= rt]= -1;\n   for (int i= 0; i < s;\
    \ ++i) {\n    for (int x= que[i], j= pos[x], y, u, v, w, a, b; j < pos[x + 1];\
    \ ++j) {\n     if (y= g[j]; y == rt) continue;\n     if (mate[y] == -1) return\
    \ rematch(rematch, mate[y]= x, y), true;\n     if (id[y] == ts) {\n      if (a=\
    \ u= f(f, x), b= v= f(f, y), w= rt; u == v) continue;\n      for (; u != rt ||\
    \ v != rt; fs[u]= {x, y}, u= f(f, fs[mate[u]][0])) {\n       if (v != rt) std::swap(u,\
    \ v);\n       if (fs[u][0] == x && fs[u][1] == y) {\n        w= u;\n        break;\n\
    \       }\n      }\n      for (; a != w; a= f(f, fs[mate[a]][0])) id[a]= ts, p[a]=\
    \ w, que[s++]= a;\n      for (; b != w; b= f(f, fs[mate[b]][0])) id[b]= ts, p[b]=\
    \ w, que[s++]= b;\n     } else if (id[mate[y]] != ts) fs[y]= {-1, -1}, fs[mate[y]]=\
    \ {x, -1}, id[mate[y]]= ts, p[mate[y]]= y, que[s++]= mate[y];\n    }\n   }\n \
    \  return false;\n  };\n  for (int rt= n; rt--;)\n   if (mate[rt] == -1) ts+=\
    \ check(rt);\n }\n int match(int u) const { return mate[u]; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  const\
    \ int n= mate.size();\n  for (int i= 0; i < n; ++i)\n   if (int j= mate[i]; i\
    \ < j) ret.push_back({i, j});\n  return ret;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/old/Matching.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Matching.hpp
layout: document
title: "\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
GabowのEdmonds' Algorithm
## メンバ関数

| 関数名           | 内容                                             | 計算量                                  |
| ---------------- | ------------------------------------------------ | --------------------------------------- |
| `Matching(N)`    | コンストラクタ. グラフの頂点数 N を渡す          |                                         |
| `add_edge(u,v)`  | 辺 (u,v) を追加                                  |                                         |
| `build()`        | マッチングを実行                                 | $\mathcal{O}(VE \log V)$ 思ったより速い |
| `match(v)`       | 頂点 v のマッチング相手を返す. 存在しないなら -1 |                                         |
| `max_matching()` | マッチングに使う辺を返す                         |                                         |


## 問題例
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (二部マッチング, 頂点:2e5+4e5, 辺:4e5) 