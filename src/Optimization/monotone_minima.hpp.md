---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2603.monotone_minima.test.cpp
    title: test/aoj/2603.monotone_minima.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  - icon: ':x:'
    path: test/yukicoder/952.test.cpp
    title: test/yukicoder/952.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/monotone_minima.hpp\"\n#include <vector>\n\
    // select(i,j,k) -> true if (i,k) is better than (i,j)\ntemplate <typename F>\
    \ std::vector<int> monotone_minima(int H, int W, const F &select) {\n std::vector<int>\
    \ ret(H);\n auto rec= [&](auto &rec, int h1, int h2, int w1, int w2) -> void {\n\
    \  if (h1 == h2) return;\n  int h= (h1 + h2) / 2, best_w= w1;\n  for (int w= w1\
    \ + 1; w < w2; ++w)\n   if (select(h, best_w, w)) best_w= w;\n  ret[h]= best_w,\
    \ rec(rec, h1, h, w1, best_w + 1), rec(rec, h + 1, h2, best_w, w2);\n };\n return\
    \ rec(rec, 0, H, 0, W), ret;\n}\n"
  code: "#pragma once\n#include <vector>\n// select(i,j,k) -> true if (i,k) is better\
    \ than (i,j)\ntemplate <typename F> std::vector<int> monotone_minima(int H, int\
    \ W, const F &select) {\n std::vector<int> ret(H);\n auto rec= [&](auto &rec,\
    \ int h1, int h2, int w1, int w2) -> void {\n  if (h1 == h2) return;\n  int h=\
    \ (h1 + h2) / 2, best_w= w1;\n  for (int w= w1 + 1; w < w2; ++w)\n   if (select(h,\
    \ best_w, w)) best_w= w;\n  ret[h]= best_w, rec(rec, h1, h, w1, best_w + 1), rec(rec,\
    \ h + 1, h2, best_w, w2);\n };\n return rec(rec, 0, H, 0, W), ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/monotone_minima.hpp
  requiredBy: []
  timestamp: '2023-08-17 22:34:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  - test/aoj/2603.monotone_minima.test.cpp
  - test/yukicoder/913.test.cpp
  - test/yukicoder/952.test.cpp
documentation_of: src/Optimization/monotone_minima.hpp
layout: document
title: monotone minima
---

## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `monotone_minima(H,W,select)` | monotone な $H\times W$ 行列に対して実行.<br> 行列は陽には与えず`select`関数を渡す.<br> `select(i,j,k)` は $(i,j)$ -成分より $(i,k)$ -成分の方が望ましいなら true を返すという関数.<br> 返り値は各行 $i$ に対して最適解を達成する列方向 $j$ を返す.                |           $\mathcal{O}((H+W)\log H)$             |

## 参考
[https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html)
## 問題例
[COLOCON -Colopl programming contest 2018- Final C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c) \
[技術室奥プログラミングコンテスト#2 F - NPCの家 (NPC's House)](https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_f) \
[COLOCON -Colopl programming contest 2018- D - すぬけそだて――トレーニング―― ](https://atcoder.jp/contests/colopl2018-qual/tasks/colopl2018_qual_d)