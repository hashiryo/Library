---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Optimization/monotone_minima.hpp\"\n#include <vector>\n\
    template <typename F> std::vector<int> monotone_minima(int H, int W, const F &select)\
    \ {\n std::vector<int> ret(H);\n auto rec= [&](auto &rec, int h1, int h2, int\
    \ w1, int w2) -> void {\n  if (h1 == h2) return;\n  int h= (h1 + h2) / 2, best_w=\
    \ w1;\n  for (int w= w1 + 1; w < w2; ++w)\n   if (select(h, best_w, w)) best_w=\
    \ w;\n  ret[h]= best_w, rec(rec, h1, h, w1, best_w + 1), rec(rec, h + 1, h2, best_w,\
    \ w2);\n };\n return rec(rec, 0, H, 0, W), ret;\n}\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename F> std::vector<int> monotone_minima(int\
    \ H, int W, const F &select) {\n std::vector<int> ret(H);\n auto rec= [&](auto\
    \ &rec, int h1, int h2, int w1, int w2) -> void {\n  if (h1 == h2) return;\n \
    \ int h= (h1 + h2) / 2, best_w= w1;\n  for (int w= w1 + 1; w < w2; ++w)\n   if\
    \ (select(h, best_w, w)) best_w= w;\n  ret[h]= best_w, rec(rec, h1, h, w1, best_w\
    \ + 1), rec(rec, h + 1, h2, best_w, w2);\n };\n return rec(rec, 0, H, 0, W), ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/monotone_minima.hpp
  requiredBy: []
  timestamp: '2023-08-13 23:15:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  - test/yukicoder/913.test.cpp
documentation_of: src/Optimization/monotone_minima.hpp
layout: document
title: monotone minima
---

## 関数

| 名前         | 概要                                                 | 計算量                         |
| ------------ | ---------------------------------------------------- | ------------------------------ |
| `monotone_minima(H,W,select)` | monotone な $H\times W$ 行列に対して実行. <br> 行列は陽には与えず`select`関数を渡す. <br> `select(i,j,k)` は $(i,j)$ -成分より $(i,k)$ -成分の方が望ましいなら true を返すという関数.                    |           $\mathcal{O}((H+W)\log H)$             |
## 参考
[https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html)
## 問題例
[COLOCON -Colopl programming contest 2018- Final C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c)