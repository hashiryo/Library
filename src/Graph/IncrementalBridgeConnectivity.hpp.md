---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2893.test.cpp
    title: test/aoj/2893.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  - icon: ':x:'
    path: test/yukicoder/529.HLD.test.cpp
    title: test/yukicoder/529.HLD.test.cpp
  - icon: ':x:'
    path: test/yukicoder/529.LCT.test.cpp
    title: test/yukicoder/529.LCT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/IncrementalBridgeConnectivity.hpp\"\n#include\
    \ <utility>\n#include <vector>\nclass IncrementalBridgeConnectivity {\n std::vector<int>\
    \ cp, bp, bbf, z;\n int t;\n inline int crt(int v) { return cp[v] < 0 ? v : cp[v]=\
    \ crt(cp[v]); }\n inline int par(int v) { return bbf[v] < 0 ? -1 : leader(bbf[v]);\
    \ }\npublic:\n IncrementalBridgeConnectivity(int n): cp(n, -1), bp(n, -1), bbf(n,\
    \ -1), z(n), t(0) {}\n inline int leader(int v) { return bp[v] < 0 ? v : bp[v]=\
    \ leader(bp[v]); }\n int size(int v) { return -bp[leader(v)]; }\n bool two_edge_connected(int\
    \ u, int v) { return leader(u) == leader(v); }\n bool connected(int u, int v)\
    \ { return crt(u) == crt(v); }\n void add_edge(int u, int v) {\n  int a= crt(u=\
    \ leader(u)), b= crt(v= leader(v));\n  if (a == b)\n   for (++t, a= u, b= v;;)\
    \ {\n    if (z[a] == t) {\n     for (int w: {u, v})\n      for (int p; w= leader(w),\
    \ w != a; bp[a]+= bp[w], bp[w]= a, w= p)\n       if (p= bbf[w], bbf[w]= bbf[a];\
    \ bp[a] > bp[w]) std::swap(w, a);\n     return;\n    }\n    if (z[a]= t, a= par(a);\
    \ b != -1) std::swap(a, b);\n   }\n  if (cp[a] < cp[b]) std::swap(u, v), cp[a]+=\
    \ cp[b], cp[b]= a;\n  else cp[b]+= cp[a], cp[a]= b;\n  for (int p; u != -1; u=\
    \ p) p= par(u), bbf[u]= v, v= u;\n }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\nclass IncrementalBridgeConnectivity\
    \ {\n std::vector<int> cp, bp, bbf, z;\n int t;\n inline int crt(int v) { return\
    \ cp[v] < 0 ? v : cp[v]= crt(cp[v]); }\n inline int par(int v) { return bbf[v]\
    \ < 0 ? -1 : leader(bbf[v]); }\npublic:\n IncrementalBridgeConnectivity(int n):\
    \ cp(n, -1), bp(n, -1), bbf(n, -1), z(n), t(0) {}\n inline int leader(int v) {\
    \ return bp[v] < 0 ? v : bp[v]= leader(bp[v]); }\n int size(int v) { return -bp[leader(v)];\
    \ }\n bool two_edge_connected(int u, int v) { return leader(u) == leader(v); }\n\
    \ bool connected(int u, int v) { return crt(u) == crt(v); }\n void add_edge(int\
    \ u, int v) {\n  int a= crt(u= leader(u)), b= crt(v= leader(v));\n  if (a == b)\n\
    \   for (++t, a= u, b= v;;) {\n    if (z[a] == t) {\n     for (int w: {u, v})\n\
    \      for (int p; w= leader(w), w != a; bp[a]+= bp[w], bp[w]= a, w= p)\n    \
    \   if (p= bbf[w], bbf[w]= bbf[a]; bp[a] > bp[w]) std::swap(w, a);\n     return;\n\
    \    }\n    if (z[a]= t, a= par(a); b != -1) std::swap(a, b);\n   }\n  if (cp[a]\
    \ < cp[b]) std::swap(u, v), cp[a]+= cp[b], cp[b]= a;\n  else cp[b]+= cp[a], cp[a]=\
    \ b;\n  for (int p; u != -1; u= p) p= par(u), bbf[u]= v, v= u;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/IncrementalBridgeConnectivity.hpp
  requiredBy: []
  timestamp: '2024-02-20 18:08:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/529.HLD.test.cpp
  - test/yukicoder/529.LCT.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/2893.test.cpp
documentation_of: src/Graph/IncrementalBridgeConnectivity.hpp
layout: document
title: "Incremental-Bridge-Connectivity (\u4E8C\u8FBA\u9023\u7D50\u6210\u5206)"
---

## `IncrementalBridgeConnectivity` クラス

|メンバ関数|概要|
|---|---|
|`IncrementalBridgeConnectivity(n)`|コンストラクタ. <br> 頂点の数 $n$ を渡す．|
|`add_edge(u,v)`|辺 $(u,v)$ を追加する．|
|`leader(v)`|頂点 $v$ が属する二辺連結成分の代表頂点を返す．|
|`size(v)`|頂点 $v$ が属する二辺連結成分のサイズを返す．|
|`two_edge_connected(u,v)`|頂点 $u,v$ が共通の二辺連結成分に属するなら `true`, それ以外なら `false` を返す．|
|`connected(u,v)`|頂点 $u,v$ が連結なら `true`, それ以外なら `false` を返す．|

## 問題例
[AtCoder Regular Contest 039 D - 旅行会社高橋君](https://atcoder.jp/contests/arc039/tasks/arc039_d)

## 参考
[https://scrapbox.io/data-structures/Incremental_Bridge-Connectivity](https://scrapbox.io/data-structures/Incremental_Bridge-Connectivity)