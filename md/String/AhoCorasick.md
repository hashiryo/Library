---
title: Aho-Corasick
documentation_of: ../../src/String/AhoCorasick.hpp
---
# Aho-Corasick
## `AhoCorasick<String>` クラス
与えられた複数のパターン文字列（辞書）を同時に検索するためのオートマトンを構築する。
オートマトンの各状態は、いずれかのパターン文字列の接頭辞に対応する。状態は `int` で表現される。

|メンバ型|概要|
|---|---|
|`symbol_t`|文字型 `String::value_type`。|

|メンバ関数|概要|
|---|---|
|`AhoCorasick(const vector<String>& ps)`|コンストラクタ。パターン文字列の集合 `ps` を受け取る。<br>計算量: $O(\sum_{P \in ps} |P|)$|
|`initial_state()`|オートマトンの初期状態 (空文字列に対応) を返す。|
|`matched_patterns(s)`|状態 `s` でマッチする全てのパターン文字列のインデックスを返す。<br>状態 `s` に対応する文字列の接尾辞に一致するパターンが全て含まれる。<br>返り値は `vector<int>`。|
|`is_accept(s)`|状態 `s` がいずれかのパターンの末尾であれば `true` を返す。|
|`transition(s, c)`|状態 `s` から文字 `c` で遷移した先の状態を返す。<br>対応する遷移がない場合は、failure link を辿って遷移を試みる。|
|`state_size()`|オートマトンの状態数を返す。|

## 問題例
[天下一プログラマーコンテスト2016本戦（オープンコンテスト） C - たんごたくさん](https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c) \ 
[2010年 日本情報オリンピック春合宿OJ dna - DNAの合成](https://atcoder.org/contests/joisc2010/tasks/joisc2010_dna)
