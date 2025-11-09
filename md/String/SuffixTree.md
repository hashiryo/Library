---
title: Suffix Tree (接尾辞木)
documentation_of: ../../src/String/SuffixTree.hpp
---
![suffixtree.svg](https://github.com/hashiryo/Library/blob/master/img/suffixtree.svg?raw=true)

## 概要

`SuffixTree` (接尾辞木) は、ある文字列のすべての接尾辞（suffix）をトライ木（Trie）で表現したデータ構造です。各辺に文字列の一部を割り当てることで、効率的に部分文字列に関する問題を解くことができます。

この実装では、Suffix Array と LCP Array から $O(n)$ で構築されます。構築された木は、根からのパスが文字列の任意の部分文字列に対応します。

## `SuffixTree` クラス

接尾辞木の頂点は辞書順にdfsのpre-orderでラベルを割り当てます。

|メンバ変数|概要|
|---|---|
|`graph`| 接尾辞木の[`Graph` クラス](../Graph/Graph.hpp) 表現。親から子の向きの辺のリストです。|
|`tree`| 接尾辞木の[重軽分解](../Graph/HeavyLightDecomposition.hpp)です。LCAなどのクエリに使用します。|
|`node`| 各頂点の情報を格納した `std::vector<std::tuple<int, int, int, int>>`。|
|`suf`| `suf[i]` は接尾辞 $S_{i:}$ に対応する葉の頂点番号を格納します。|

|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixTree(sa, lcp)`|コンストラクタ。引数は [`SuffixArray` と `LCPArray`](../String/SuffixArray.hpp) です。|$O(n)$ |
|`operator[](v)`| 接尾辞木上の頂点 `v` の情報を `std::tuple<int, int, int, int>` 型で返します。タプルの各要素は `{l, r, d, u}` であり、これは **Suffix Array 上の区間 `[l, r)` に含まれる全ての接尾辞の、長さが `[d, u)` の範囲にあるプレフィックスの集合** を表します。| $O(1)$ |
|`begin()`| 頂点情報を格納した配列の `begin()` イテレータを返します。||
|`end()`| 頂点情報を格納した配列の `end()` イテレータを返します。||
|`size()`|接尾辞木の頂点数を返します。||
|`substr(l)`|接尾辞 $S_{l:}$ に対応する葉の頂点番号を返します。|$O(1)$|
|`substr(l,n)`|部分文字列 $S_{l:l+n}$ に対応する頂点番号を返します。これは $S_{l:}$ を表す葉から根に向かって遡ることで見つかります。 |$O(\log n)$|

## Verify

- [AtCoder ABC 141 E - Who Says a Pun?](https://atcoder.jp/contests/abc141/tasks/abc141_e)
- [AtCoder ABC 213 F - Common Prefixes](https://atcoder.jp/contests/abc213/tasks/abc213_f)
- [HackerRank - Ashton and String](https://www.hackerrank.com/challenges/ashton-and-string/problem)
- [HackerRank - String Function Calculation](https://www.hackerrank.com/challenges/string-function-calculation/problem)
- [YukiCoder No.2361](https://yukicoder.me/problems/no/2361)

## 参考
- [Suffix Tree を Suffix Array と LCP Array から構築する](https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g)
