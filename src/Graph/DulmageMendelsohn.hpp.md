---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/DulmageMendelsohn.hpp\"\n#include <array>\n#include\
    \ <algorithm>\n#include <numeric>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include\
    \ <vector>\n#include <iostream>\n#include <iterator>\n#include <type_traits>\n\
    #define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using Iterator=\
    \ typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const\
    \ { return bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size()\
    \ const { return std::distance(bg, ed); } \\\n  CT &operator[](int i) const {\
    \ return bg[i]; } \\\n }\n_LR(ListRange, iterator, const T);\n_LR(ConstListRange,\
    \ const_iterator, const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n\
    \ std::vector<T> dat;\n std::vector<int> p;\n size_t size() const { return p.size()\
    \ - 1; }\n ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin()\
    \ + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 6 \"src/Graph/DulmageMendelsohn.hpp\"\nclass DulmageMendelsohn\
    \ {\n std::vector<int> blg[2], mate[2], pos[2];\n std::vector<std::array<int,\
    \ 2>> es;\npublic:\n DulmageMendelsohn(int L, int R): blg{std::vector(L, -3),\
    \ std::vector(R, -3)} {}\n void add_edge(int l, int r) { es.push_back({l, r});\
    \ }\n void build() {\n  const int n[]= {(int)blg[0].size(), (int)blg[1].size()};\n\
    \  std::vector<int> g[2], rt, pre, que(std::max(n[0], n[1]));\n  for (int b= 2;\
    \ b--;) g[b].resize(es.size()), pos[b].resize(n[b] + 1), mate[b].assign(n[b],\
    \ -1);\n  for (auto [l, r]: es) ++pos[0][l], ++pos[1][r];\n  for (int b= 2; b--;)\
    \ std::partial_sum(pos[b].begin(), pos[b].end(), pos[b].begin());\n  for (auto\
    \ [l, r]: es) g[0][--pos[0][l]]= r, g[1][--pos[1][r]]= l;\n  int t= 0, k= 0;\n\
    \  for (bool upd= true; upd; t= 0) {\n   upd= false, rt.assign(n[0], -1), pre.assign(n[0],\
    \ -1);\n   for (int l= n[0]; l--;)\n    if (mate[0][l] == -1) que[t++]= rt[l]=\
    \ pre[l]= l;\n   for (int i= 0; i < t; ++i)\n    if (int l= que[i]; mate[0][rt[l]]\
    \ == -1)\n     for (int j= pos[0][l], r, nl; j < pos[0][l + 1]; ++j) {\n     \
    \ if (nl= mate[1][r= g[0][j]]; nl == -1) {\n       for (upd= true; r != -1; l=\
    \ pre[l]) mate[1][r]= l, std::swap(mate[0][l], r);\n       break;\n      }\n \
    \     if (pre[nl] == -1) rt[que[t++]= nl]= rt[pre[nl]= l];\n     }\n  }\n  for\
    \ (int s= n[0], v; s--;)\n   if (rt[s] != -1)\n    if (blg[0][s]= -1, v= mate[0][s];\
    \ v != -1) blg[1][v]= -1;\n  for (int s= n[1]; s--;)\n   if (mate[1][s] == -1)\
    \ blg[1][que[t++]= s]= 0;\n  for (int i= 0; i < t; ++i)\n   for (int v= que[i],\
    \ j= pos[1][v], u, w; j < pos[1][v + 1]; ++j)\n    if (blg[0][u= g[1][j]] == -3)\n\
    \     if (w= mate[0][u], blg[0][u]= 0; w != -1 && blg[1][w] == -3) blg[1][que[t++]=\
    \ w]= 0;\n  pre.assign(pos[0].begin(), pos[0].begin() + n[0]), t= 0;\n  for (int\
    \ s= n[0], v; s--;)\n   if (blg[0][s] == -3)\n    for (blg[0][v= s]= -4; v >=\
    \ 0;) {\n     if (pre[v] == pos[0][v + 1]) rt[t++]= v, v= blg[0][v];\n     else\
    \ if (int w= mate[1][g[0][pre[v]++]]; blg[0][w] == -3) blg[0][w]= v, v= w;\n \
    \   }\n  for (int i= 0, e= 0; t--;)\n   if (int s= rt[t], p= mate[0][s]; blg[1][p]\
    \ == -3)\n    for (que[e++]= p, blg[0][s]= blg[1][p]= ++k; i < e; ++i)\n     for\
    \ (int v= que[i], j= pos[1][v]; j < pos[1][v + 1]; ++j)\n      if (int u= g[1][j],\
    \ w= mate[0][u]; blg[1][w] == -3) que[e++]= w, blg[0][u]= blg[1][w]= k;\n  ++k;\n\
    \  for (int b= 2, s; b--;) {\n   for (pos[b].assign(k + 2, 0), s= n[b]; s--; ++pos[b][blg[b][s]])\n\
    \    if (blg[b][s] == -1) blg[b][s]= k;\n   for (std::partial_sum(pos[b].begin(),\
    \ pos[b].end(), pos[b].begin()), s= n[b]; s--;) mate[b][--pos[b][blg[b][s]]]=\
    \ s;\n  }\n }\n int component_num() const { return pos[0].size() - 1; }\n int\
    \ left_belong(int l) const { return blg[0][l]; }\n int right_belong(int r) const\
    \ { return blg[1][r]; }\n const ListRange<int> left_block(int k) const { return\
    \ {mate[0].cbegin() + pos[0][k], mate[0].cbegin() + pos[0][k + 1]}; }\n const\
    \ ListRange<int> right_block(int k) const { return {mate[1].cbegin() + pos[1][k],\
    \ mate[1].cbegin() + pos[1][k + 1]}; }\n};\n"
  code: "#pragma once\n#include <array>\n#include <algorithm>\n#include <numeric>\n\
    #include \"src/Internal/ListRange.hpp\"\nclass DulmageMendelsohn {\n std::vector<int>\
    \ blg[2], mate[2], pos[2];\n std::vector<std::array<int, 2>> es;\npublic:\n DulmageMendelsohn(int\
    \ L, int R): blg{std::vector(L, -3), std::vector(R, -3)} {}\n void add_edge(int\
    \ l, int r) { es.push_back({l, r}); }\n void build() {\n  const int n[]= {(int)blg[0].size(),\
    \ (int)blg[1].size()};\n  std::vector<int> g[2], rt, pre, que(std::max(n[0], n[1]));\n\
    \  for (int b= 2; b--;) g[b].resize(es.size()), pos[b].resize(n[b] + 1), mate[b].assign(n[b],\
    \ -1);\n  for (auto [l, r]: es) ++pos[0][l], ++pos[1][r];\n  for (int b= 2; b--;)\
    \ std::partial_sum(pos[b].begin(), pos[b].end(), pos[b].begin());\n  for (auto\
    \ [l, r]: es) g[0][--pos[0][l]]= r, g[1][--pos[1][r]]= l;\n  int t= 0, k= 0;\n\
    \  for (bool upd= true; upd; t= 0) {\n   upd= false, rt.assign(n[0], -1), pre.assign(n[0],\
    \ -1);\n   for (int l= n[0]; l--;)\n    if (mate[0][l] == -1) que[t++]= rt[l]=\
    \ pre[l]= l;\n   for (int i= 0; i < t; ++i)\n    if (int l= que[i]; mate[0][rt[l]]\
    \ == -1)\n     for (int j= pos[0][l], r, nl; j < pos[0][l + 1]; ++j) {\n     \
    \ if (nl= mate[1][r= g[0][j]]; nl == -1) {\n       for (upd= true; r != -1; l=\
    \ pre[l]) mate[1][r]= l, std::swap(mate[0][l], r);\n       break;\n      }\n \
    \     if (pre[nl] == -1) rt[que[t++]= nl]= rt[pre[nl]= l];\n     }\n  }\n  for\
    \ (int s= n[0], v; s--;)\n   if (rt[s] != -1)\n    if (blg[0][s]= -1, v= mate[0][s];\
    \ v != -1) blg[1][v]= -1;\n  for (int s= n[1]; s--;)\n   if (mate[1][s] == -1)\
    \ blg[1][que[t++]= s]= 0;\n  for (int i= 0; i < t; ++i)\n   for (int v= que[i],\
    \ j= pos[1][v], u, w; j < pos[1][v + 1]; ++j)\n    if (blg[0][u= g[1][j]] == -3)\n\
    \     if (w= mate[0][u], blg[0][u]= 0; w != -1 && blg[1][w] == -3) blg[1][que[t++]=\
    \ w]= 0;\n  pre.assign(pos[0].begin(), pos[0].begin() + n[0]), t= 0;\n  for (int\
    \ s= n[0], v; s--;)\n   if (blg[0][s] == -3)\n    for (blg[0][v= s]= -4; v >=\
    \ 0;) {\n     if (pre[v] == pos[0][v + 1]) rt[t++]= v, v= blg[0][v];\n     else\
    \ if (int w= mate[1][g[0][pre[v]++]]; blg[0][w] == -3) blg[0][w]= v, v= w;\n \
    \   }\n  for (int i= 0, e= 0; t--;)\n   if (int s= rt[t], p= mate[0][s]; blg[1][p]\
    \ == -3)\n    for (que[e++]= p, blg[0][s]= blg[1][p]= ++k; i < e; ++i)\n     for\
    \ (int v= que[i], j= pos[1][v]; j < pos[1][v + 1]; ++j)\n      if (int u= g[1][j],\
    \ w= mate[0][u]; blg[1][w] == -3) que[e++]= w, blg[0][u]= blg[1][w]= k;\n  ++k;\n\
    \  for (int b= 2, s; b--;) {\n   for (pos[b].assign(k + 2, 0), s= n[b]; s--; ++pos[b][blg[b][s]])\n\
    \    if (blg[b][s] == -1) blg[b][s]= k;\n   for (std::partial_sum(pos[b].begin(),\
    \ pos[b].end(), pos[b].begin()), s= n[b]; s--;) mate[b][--pos[b][blg[b][s]]]=\
    \ s;\n  }\n }\n int component_num() const { return pos[0].size() - 1; }\n int\
    \ left_belong(int l) const { return blg[0][l]; }\n int right_belong(int r) const\
    \ { return blg[1][r]; }\n const ListRange<int> left_block(int k) const { return\
    \ {mate[0].cbegin() + pos[0][k], mate[0].cbegin() + pos[0][k + 1]}; }\n const\
    \ ListRange<int> right_block(int k) const { return {mate[1].cbegin() + pos[1][k],\
    \ mate[1].cbegin() + pos[1][k + 1]}; }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/DulmageMendelsohn.hpp
  requiredBy: []
  timestamp: '2024-02-15 14:27:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1745.test.cpp
documentation_of: src/Graph/DulmageMendelsohn.hpp
layout: document
title: "Dulmage-Mendelsohn \u5206\u89E3"
---
明示的に二部グラフを表現する \
頂点の添字は左右それぞれ [0,L), [0,R) で表現 \
K+1 個 に分割された集合(0~K)が得られたとして
- 左側の頂点： 0~K-1番目のいずれかの集合に属する $\iff$ マッチングに必ず使う
- 右側の頂点： 1~K番目のいずれかの集合に属する $\iff$ マッチングに必ず使う
- 左側の頂点lがa番目の集合, 右側の頂点rがb番目の集合に属する: 辺(l,r)が存在 $\implies$ a $\le$ b

## メンバ関数

| 関数名                   | 内容                                                | 計算量                              |
| ------------------------ | --------------------------------------------------- | ----------------------------------- |
| `DulmageMendelsohn(L,R)` | コンストラクタ. 二部グラフの左右のサイズ L, Rを渡す |                                     |
| `add_edge(l,r)`          | 辺 (l,r) を追加                                     |                                     |
| `build()`                | DM分解を実行                                        | $\mathcal{O}\left(E\sqrt{V}\right)$ |
| `component_num()`        | 分割された集合の個数(K+1)を返す                     |                                     |
| `left_belong(l)`         | 左側の頂点 l の所属先を返す                         |                                     |
| `right_belong(r)`        | 右側の頂点 r の所属先を返す                         |                                     |
| `left_block(k)`          | 左側の k 番目の集合を返す                           |                                     |
| `right_block(k)`         | 右側の k 番目の集合を返す                           |                                     |

## 参考
[https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition](https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition) \
[http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf](http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf) \
[https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html](https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html)