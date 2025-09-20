---
title: Suffix Tree (接尾辞木)
documentation_of: ../../src/String/SuffixTree.hpp
---
![suffixtree.svg](https://github.com/hashiryo/Library/blob/master/img/suffixtree.svg?raw=true)

## `SuffixTree` クラス

接尾辞木の頂点は辞書順にdfsのpre-orderでラベルを割り当てる.

|メンバ変数|概要|
|---|---|
|`graph`| 接尾辞木の親子関係を表す[`Graph` クラス](../Graph/Graph.hpp) 表現. |
|`tree`| 接尾辞木の構造に対する[重軽分解](../Graph/HeavyLightDecomposition.hpp). `substr(l, n)` などで利用される.|
|`node`| 各頂点の情報を格納する配列. `(*this)[v]` でアクセスできる. |
|`suf`| 接尾辞 $S_{i:}$ に対応する葉ノードの頂点番号を格納する配列. `suf[i]` でアクセスできる.|

|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixTree(sa, lcp)`|コンストラクタ. <br> 引数は [`SuffixArray` と `LCPArray`](src/String/SuffixArray.hpp) .|$O(n)$ |
|`operator[](v)`| 接尾辞木上の頂点 `v` の情報を `std::tuple<int, int, int, int>` 型で返す。タプルの各要素は `{l, r, d, u}` であり、それぞれ Suffix Array 上の区間 `[l, r)` と、根からの深さ (文字列長) の区間 `[d, u)` を表す。|
|`begin()`| 頂点情報配列 `node` の `begin()` イテレータを返す.||
|`end()`| 頂点情報配列 `node` の `end()` イテレータを返す.||
|`size()`|接尾辞木の頂点数を返す.||
|`substr(l)`|接尾辞 $S_{l:}$ に対応する葉ノードの頂点番号を返す.|$O(1)$|
|`substr(l,n)`|部分文字列 $S_{l:l+n}$ を表すパスの末端の頂点番号を返す. |$O(\log n)$|

## Verify


- [デンソークリエイトプログラミングコンテスト2022 Winter(AtCoder Beginner Contest 280) Ex - Substring Sort](https://atcoder.jp/contests/abc280/tasks/abc280_h) (sp judge)



## 参考
[https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g](https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g)