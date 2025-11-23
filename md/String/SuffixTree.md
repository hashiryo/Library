---
title: Suffix Tree (接尾辞木)
documentation_of: ../../src/String/SuffixTree.hpp
---
![suffixtree.svg](https://github.com/hashiryo/Library/blob/master/img/suffixtree.svg?raw=true)

## 概要

文字列の全ての接尾辞 (suffix) をトライ木のように表現したデータ構造。Suffix Array と LCP Array から $O(n)$ で構築できる。
各ノードは、Suffix Array上の区間 `[l, r)` と、文字列の深さ（根からの文字数）の区間 `[d, u)` に対応する。これにより、特定の部分文字列に対応するノードを効率的に見つけることができる。

## 前提条件

`SuffixTree` をインスタンス化する前に、対象の文字列に対して `SuffixArray` と `LCPArray` を構築しておく必要がある。

```cpp
#include "src/String/SuffixArray.hpp"

std::string s = "abracadabra";
SuffixArray sa(s);
LCPArray lcp(sa);
SuffixTree st(sa, lcp);
```

## `SuffixTree` クラス

|メンバ変数|概要|
|---|---|
|`graph`| 接尾辞木の親子関係を表すグラフ (`Graph` クラス)。根から葉への有向グラフ。|
|`tree`| 接尾辞木に対して構築された[重軽分解](../Graph/HeavyLightDecomposition.hpp)。LCAクエリなどに利用される。|
|`node`| `std::vector<std::tuple<int, int, int, int>>` 型。各頂点 `v` の情報を保持する。`node[v]` は `{l, r, d, u}` というタプルを返す。詳細は `operator[]` の説明を参照。|
|`suf`| `std::vector<int>` 型。`suf[i]` は、文字列の `i` 番目の文字で始まる接尾辞に対応する葉ノードの頂点番号を保持する。|

|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixTree(sa, lcp)`|コンストラクタ。 `SuffixArray` と `LCPArray` を引数に取る。|$O(n)$ |
|`operator[](v)`| 頂点 `v` の情報を `std::tuple<int, int, int, int>` 型で返す。タプルの各要素は `{l, r, d, u}` であり、それぞれ以下の意味を持つ。<br> - `l`: 対応する Suffix Array 上の区間の開始インデックス (inclusive) <br> - `r`: 対応する Suffix Array 上の区間の終了インデックス (exclusive) <br> - `d`: 親ノードに対応する文字列の深さ（文字数） <br> - `u`: このノードに対応する文字列の深さ（文字数） <br> このノードが表す文字列は、`s.substr(sa[l], u)` の先頭 `u` 文字であり、親からこのノードへの辺が表す文字列は、そのうち `u - d` 文字である。| $O(1)$ |
|`begin()`| `node` 配列の `begin()` イテレータを返す。||
|`end()`| `node` 配列の `end()` イテレータを返す。||
|`size()`|接尾辞木の頂点数を返す。||
|`substr(i)`|接尾辞 $S_{i:}$ (文字列の `i` 番目から始まる接尾辞) に対応する葉ノードの頂点番号を返す。|$O(1)$|
|`substr(i, len)`|部分文字列 $S_{i:i+len}$ (文字列の `i` 番目から長さ `len` の部分文字列) の終端に対応するノードの頂点番号を返す。 |$O(\log n)$|

## Verify

- [デンソークリエイトプログラミングコンテスト2022 Winter(AtCoder Beginner Contest 280) Ex - Substring Sort](https://atcoder.jp/contests/abc280/tasks/abc280_h) (sp judge)

## 参考
- [Suffix Treeの構築とLCP Array (maspyさんのツイート)](https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g)
