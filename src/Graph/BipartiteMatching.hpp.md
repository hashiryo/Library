---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0334.test.cpp
    title: test/aoj/0334.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3198.test.cpp
    title: test/aoj/3198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1615.bm.test.cpp
    title: test/yukicoder/1615.bm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/421.test.cpp
    title: test/yukicoder/421.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/BipartiteMatching.hpp\"\n#include <vector>\n#include\
    \ <array>\n#include <algorithm>\n#include <cassert>\nclass BipartiteMatching {\n\
    \ std::vector<std::array<int, 2>> es;\n std::vector<int> lmate, rmate, rt;\npublic:\n\
    \ BipartiteMatching() {}\n BipartiteMatching(int L, int R): lmate(L, -1), rmate(R,\
    \ -1) {}\n void add_edge(int l, int r) { es.push_back({l, r}); }\n void erase_edge(int\
    \ l, int r) {\n  auto it= std::find(es.begin(), es.end(), std::array{l, r});\n\
    \  if (assert(it != es.end()), es.erase(it); lmate[l] == r) lmate[l]= rmate[r]=\
    \ -1;\n }\n template <bool lex= false> void build() {\n  const int n= lmate.size();\n\
    \  std::vector<int> g(es.size()), pos(n + 1), pre, que(n);\n  if constexpr (lex)\
    \ std::sort(es.rbegin(), es.rend());\n  for (auto [l, r]: es) ++pos[l];\n  for\
    \ (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (auto [l, r]: es) g[--pos[l]]=\
    \ r;\n  for (bool upd= true; upd;) {\n   upd= false, rt.assign(n, -1), pre.assign(n,\
    \ -1);\n   int t= 0;\n   for (int l= n; l--;)\n    if (lmate[l] == -1) que[t++]=\
    \ rt[l]= pre[l]= l;\n   for (int i= 0; i < t; ++i)\n    if (int l= que[i]; lmate[rt[l]]\
    \ == -1)\n     for (int j= pos[l], r, nl; j < pos[l + 1]; ++j) {\n      if (nl=\
    \ rmate[r= g[j]]; nl == -1) {\n       for (upd= true; r != -1; l= pre[l]) rmate[r]=\
    \ l, std::swap(lmate[l], r);\n       break;\n      }\n      if (pre[nl] == -1)\
    \ rt[que[t++]= nl]= rt[pre[nl]= l];\n     }\n  }\n  if constexpr (lex) {\n   std::vector<char>\
    \ alive(n, 1);\n   for (int v= 0, l, r; v < n; ++v)\n    if (int u= lmate[v];\
    \ u != -1) {\n     for (pre.assign(n, lmate[v]= rmate[u]= -1), pre[l= v]= -2,\
    \ que.assign(pos.begin(), pos.begin() + n);;) {\n      if (que[l] == pos[l + 1])\
    \ l= pre[l];\n      else if (r= g[que[l]++], u= rmate[r]; u == -1) {\n       for\
    \ (; r != -1; l= pre[l]) rmate[r]= l, std::swap(lmate[l], r);\n       break;\n\
    \      } else if (alive[u] && pre[u] == -1) pre[u]= l, l= u;\n     }\n     alive[v]=\
    \ 0;\n    }\n  }\n }\n inline size_t left_size() const { return lmate.size();\
    \ }\n inline size_t right_size() const { return rmate.size(); }\n inline int l_to_r(int\
    \ l) const { return lmate[l]; }\n inline int r_to_l(int r) const { return rmate[r];\
    \ }\n std::vector<std::array<int, 2>> max_matching() const {\n  std::vector<std::array<int,\
    \ 2>> ret;\n  for (int l= 0, n= lmate.size(); l < n; ++l)\n   if (int r= lmate[l];\
    \ r != -1) ret.push_back({l, r});\n  return ret;\n }\n bool used_as_vertex_cover_left(int\
    \ l) const { return rt[l] == -1; }\n bool used_as_vertex_cover_right(int r) const\
    \ { return r= rmate[r], r != -1 && rt[r] != -1; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <algorithm>\n\
    #include <cassert>\nclass BipartiteMatching {\n std::vector<std::array<int, 2>>\
    \ es;\n std::vector<int> lmate, rmate, rt;\npublic:\n BipartiteMatching() {}\n\
    \ BipartiteMatching(int L, int R): lmate(L, -1), rmate(R, -1) {}\n void add_edge(int\
    \ l, int r) { es.push_back({l, r}); }\n void erase_edge(int l, int r) {\n  auto\
    \ it= std::find(es.begin(), es.end(), std::array{l, r});\n  if (assert(it != es.end()),\
    \ es.erase(it); lmate[l] == r) lmate[l]= rmate[r]= -1;\n }\n template <bool lex=\
    \ false> void build() {\n  const int n= lmate.size();\n  std::vector<int> g(es.size()),\
    \ pos(n + 1), pre, que(n);\n  if constexpr (lex) std::sort(es.rbegin(), es.rend());\n\
    \  for (auto [l, r]: es) ++pos[l];\n  for (int i= 0; i < n; ++i) pos[i + 1]+=\
    \ pos[i];\n  for (auto [l, r]: es) g[--pos[l]]= r;\n  for (bool upd= true; upd;)\
    \ {\n   upd= false, rt.assign(n, -1), pre.assign(n, -1);\n   int t= 0;\n   for\
    \ (int l= n; l--;)\n    if (lmate[l] == -1) que[t++]= rt[l]= pre[l]= l;\n   for\
    \ (int i= 0; i < t; ++i)\n    if (int l= que[i]; lmate[rt[l]] == -1)\n     for\
    \ (int j= pos[l], r, nl; j < pos[l + 1]; ++j) {\n      if (nl= rmate[r= g[j]];\
    \ nl == -1) {\n       for (upd= true; r != -1; l= pre[l]) rmate[r]= l, std::swap(lmate[l],\
    \ r);\n       break;\n      }\n      if (pre[nl] == -1) rt[que[t++]= nl]= rt[pre[nl]=\
    \ l];\n     }\n  }\n  if constexpr (lex) {\n   std::vector<char> alive(n, 1);\n\
    \   for (int v= 0, l, r; v < n; ++v)\n    if (int u= lmate[v]; u != -1) {\n  \
    \   for (pre.assign(n, lmate[v]= rmate[u]= -1), pre[l= v]= -2, que.assign(pos.begin(),\
    \ pos.begin() + n);;) {\n      if (que[l] == pos[l + 1]) l= pre[l];\n      else\
    \ if (r= g[que[l]++], u= rmate[r]; u == -1) {\n       for (; r != -1; l= pre[l])\
    \ rmate[r]= l, std::swap(lmate[l], r);\n       break;\n      } else if (alive[u]\
    \ && pre[u] == -1) pre[u]= l, l= u;\n     }\n     alive[v]= 0;\n    }\n  }\n }\n\
    \ inline size_t left_size() const { return lmate.size(); }\n inline size_t right_size()\
    \ const { return rmate.size(); }\n inline int l_to_r(int l) const { return lmate[l];\
    \ }\n inline int r_to_l(int r) const { return rmate[r]; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  for (int\
    \ l= 0, n= lmate.size(); l < n; ++l)\n   if (int r= lmate[l]; r != -1) ret.push_back({l,\
    \ r});\n  return ret;\n }\n bool used_as_vertex_cover_left(int l) const { return\
    \ rt[l] == -1; }\n bool used_as_vertex_cover_right(int r) const { return r= rmate[r],\
    \ r != -1 && rt[r] != -1; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2023-03-16 02:01:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2423.test.cpp
  - test/aoj/0334.test.cpp
  - test/aoj/3198.test.cpp
  - test/yosupo/bipartitematching.test.cpp
  - test/yukicoder/1615.bm.test.cpp
  - test/yukicoder/421.test.cpp
documentation_of: src/Graph/BipartiteMatching.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u30DE\u30C3\u30C1\u30F3\u30B0"
---
明示的に二部グラフを表現する \
頂点の添字は左右それぞれ [0,L), [0,R) で表現
## メンバ関数

| 関数名                          | 内容                                                                  | 計算量                              |
| ------------------------------- | --------------------------------------------------------------------- | ----------------------------------- |
| `BipartiteMatching(L,R)`        | コンストラクタ. 二部グラフの左右のサイズ L, Rを渡す                   |                                     |
| `add_edge(l,r)`                 | 辺 (l,r) を追加                                                       | $\mathcal{O}(1)$                    |
| `erase_edge(l,r)`               | 辺 (l,r) を削除                                                       | $\mathcal{O}(E)$                    |
| `build()`                       | 二部グラフのマッチングを実行                                          | $\mathcal{O}\left(E\sqrt{V}\right)$ |
| `build<true>()`                 | 辞書順最小になるように二部グラフのマッチングを実行                    | $\mathcal{O}\left(EV\right)$        |
| `max_matching()`                | マッチングに使う辺を返す                                              |                                     |
| `l_to_r(l)`                     | 左側の頂点 l のマッチング相手(右側の頂点)を返す. いないなら -1        |                                     |
| `r_to_l(r)`                     | 右側の頂点 r のマッチング相手(左側の頂点)を返す. いないなら -1        |
| `used_as_vertex_cover_left(l)`  | (最小頂点被覆を一つ構成して) 左側の頂点 l を点被覆に使用するかの bool |                                     |
| `used_as_vertex_cover_right(r)` | (最小頂点被覆を一つ構成して) 右側の頂点 r を点被覆に使用するかの bool |                                     |


## 問題例
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (頂点:2e5+4e5, 辺:4e5) \
[HackerRank Drawing Rectangles](https://www.hackerrank.com/contests/university-codesprint-4/challenges/drawing-rectangles) (最小頂点被覆, 頂点:3e5+3e5, 辺:3e5)