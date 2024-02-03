---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2212.test.cpp
    title: test/aoj/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2257.test.cpp
    title: test/aoj/2257.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2863.test.cpp
    title: test/aoj/2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2873.test.cpp
    title: test/aoj/2873.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.AhoCora.test.cpp
    title: test/yukicoder/430.AhoCora.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/AhoCorasick.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <numeric>\ntemplate <class String> struct AhoCorasick\
    \ {\n using symbol_t= typename String::value_type;\n AhoCorasick(const std::vector<String>\
    \ &ps) {\n  const size_t n= ps.size();\n  std::vector<int> ord(n), rows;\n  std::iota(ord.begin(),\
    \ ord.end(), 0), std::sort(ord.begin(), ord.end(), [&](int l, int r) { return\
    \ ps[l] < ps[r]; });\n  std::vector<size_t> lcp(n, 0), prev(n, 0), cur(n);\n \
    \ for (size_t i= 1, j, ed; i < n; lcp[i++]= j)\n   for (j= 0, ed= std::min(ps[ord[i\
    \ - 1]].size(), ps[ord[i]].size()); j < ed; j++)\n    if (ps[ord[i - 1]][j] !=\
    \ ps[ord[i]][j]) break;\n  size_t nodes= 1;\n  for (size_t i= 0; i < n; i++) nodes+=\
    \ ps[ord[i]].size() - lcp[i];\n  bg.reserve(nodes + 1), es.reserve(nodes), match.reserve(nodes),\
    \ rows.reserve(n + 1);\n  for (size_t row= 0; row < n; row++)\n   if (!ps[ord[row]].empty())\
    \ rows.push_back(row);\n  rows.push_back(-1), bg.push_back(0), match.push_back({});\n\
    \  for (int i= 0; i < n && ps[ord[i]].empty(); i++) match[0].push_back(ord[i]);\n\
    \  for (size_t col= 0; rows[0] != -1; col++) {\n   int size= 0;\n   for (int &r:\
    \ rows) {\n    if (r == -1) break;\n    size_t row= r;\n    if (size++; lcp[row]\
    \ <= col) {\n     if (size_t par= prev[row]; bg[par] == -1) bg[par]= es.size();\n\
    \     es.push_back(ps[ord[row]][col]), bg.push_back(-1);\n     if (match.push_back({});\
    \ col + 1 == ps[ord[row]].size())\n      for (int i= row; i < n && ps[ord[i]]\
    \ == ps[ord[row]]; i++) match.back().push_back(ord[i]);\n    }\n    if (cur[row]=\
    \ bg.size() - 1; col + 1 == ps[ord[row]].size()) r= -1;\n   }\n   *std::remove(rows.begin(),\
    \ rows.begin() + size, -1)= -1, prev.swap(cur);\n  }\n  bg.push_back(es.size());\n\
    \  for (size_t i= bg.size() - 1; --i;)\n   if (bg[i] == -1) bg[i]= bg[i + 1];\n\
    \  fail.assign(match.size(), -1);\n  for (int u= 0, ed= match.size(); u < ed;\
    \ u++)\n   for (auto i= bg[u], v= i + 1; i < bg[u + 1]; i++, v++) {\n    int r=\
    \ fail[v]= transition(fail[u], es[i]);\n    match[v].insert(match[v].end(), match[r].begin(),\
    \ match[r].end());\n   }\n }\n inline int initial_state() const { return 0; }\n\
    \ inline std::vector<int> matched_patterns(int s) const { return match[s]; }\n\
    \ inline bool is_accept(int s) const { return !match[s].empty(); }\n inline int\
    \ transition(int s, symbol_t c) const {\n  for (; s >= 0; s= fail[s])\n   if (int\
    \ v= next(s, c); v != -1) return v;\n  return 0;\n }\n inline int state_size()\
    \ const { return match.size(); }\nprivate:\n std::vector<int> bg, fail;\n std::vector<symbol_t>\
    \ es;\n std::vector<std::vector<int>> match;\n inline int next(int s, symbol_t\
    \ c) const {\n  int index= std::lower_bound(es.begin() + bg[s], es.begin() + bg[s\
    \ + 1], c) - es.begin();\n  if (index != bg[s + 1] && c == es[index]) return index\
    \ + 1;\n  return -1;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    template <class String> struct AhoCorasick {\n using symbol_t= typename String::value_type;\n\
    \ AhoCorasick(const std::vector<String> &ps) {\n  const size_t n= ps.size();\n\
    \  std::vector<int> ord(n), rows;\n  std::iota(ord.begin(), ord.end(), 0), std::sort(ord.begin(),\
    \ ord.end(), [&](int l, int r) { return ps[l] < ps[r]; });\n  std::vector<size_t>\
    \ lcp(n, 0), prev(n, 0), cur(n);\n  for (size_t i= 1, j, ed; i < n; lcp[i++]=\
    \ j)\n   for (j= 0, ed= std::min(ps[ord[i - 1]].size(), ps[ord[i]].size()); j\
    \ < ed; j++)\n    if (ps[ord[i - 1]][j] != ps[ord[i]][j]) break;\n  size_t nodes=\
    \ 1;\n  for (size_t i= 0; i < n; i++) nodes+= ps[ord[i]].size() - lcp[i];\n  bg.reserve(nodes\
    \ + 1), es.reserve(nodes), match.reserve(nodes), rows.reserve(n + 1);\n  for (size_t\
    \ row= 0; row < n; row++)\n   if (!ps[ord[row]].empty()) rows.push_back(row);\n\
    \  rows.push_back(-1), bg.push_back(0), match.push_back({});\n  for (int i= 0;\
    \ i < n && ps[ord[i]].empty(); i++) match[0].push_back(ord[i]);\n  for (size_t\
    \ col= 0; rows[0] != -1; col++) {\n   int size= 0;\n   for (int &r: rows) {\n\
    \    if (r == -1) break;\n    size_t row= r;\n    if (size++; lcp[row] <= col)\
    \ {\n     if (size_t par= prev[row]; bg[par] == -1) bg[par]= es.size();\n    \
    \ es.push_back(ps[ord[row]][col]), bg.push_back(-1);\n     if (match.push_back({});\
    \ col + 1 == ps[ord[row]].size())\n      for (int i= row; i < n && ps[ord[i]]\
    \ == ps[ord[row]]; i++) match.back().push_back(ord[i]);\n    }\n    if (cur[row]=\
    \ bg.size() - 1; col + 1 == ps[ord[row]].size()) r= -1;\n   }\n   *std::remove(rows.begin(),\
    \ rows.begin() + size, -1)= -1, prev.swap(cur);\n  }\n  bg.push_back(es.size());\n\
    \  for (size_t i= bg.size() - 1; --i;)\n   if (bg[i] == -1) bg[i]= bg[i + 1];\n\
    \  fail.assign(match.size(), -1);\n  for (int u= 0, ed= match.size(); u < ed;\
    \ u++)\n   for (auto i= bg[u], v= i + 1; i < bg[u + 1]; i++, v++) {\n    int r=\
    \ fail[v]= transition(fail[u], es[i]);\n    match[v].insert(match[v].end(), match[r].begin(),\
    \ match[r].end());\n   }\n }\n inline int initial_state() const { return 0; }\n\
    \ inline std::vector<int> matched_patterns(int s) const { return match[s]; }\n\
    \ inline bool is_accept(int s) const { return !match[s].empty(); }\n inline int\
    \ transition(int s, symbol_t c) const {\n  for (; s >= 0; s= fail[s])\n   if (int\
    \ v= next(s, c); v != -1) return v;\n  return 0;\n }\n inline int state_size()\
    \ const { return match.size(); }\nprivate:\n std::vector<int> bg, fail;\n std::vector<symbol_t>\
    \ es;\n std::vector<std::vector<int>> match;\n inline int next(int s, symbol_t\
    \ c) const {\n  int index= std::lower_bound(es.begin() + bg[s], es.begin() + bg[s\
    \ + 1], c) - es.begin();\n  if (index != bg[s + 1] && c == es[index]) return index\
    \ + 1;\n  return -1;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2023-11-24 02:08:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/430.AhoCora.test.cpp
  - test/yukicoder/1269.test.cpp
  - test/aoj/2257.test.cpp
  - test/aoj/2212.test.cpp
  - test/aoj/2873.test.cpp
  - test/aoj/2863.test.cpp
documentation_of: src/String/AhoCorasick.hpp
layout: document
title: Aho-Corasick
---
## `AhoCorasick<String>` クラス
pattern と suffix がマッチする文字列を受理するDFA. \
オートマトンの状態は `int` で表現する.

|メンバクラス|概要|
|---|---|
|`symbol_type`|アルファベットを表すクラス.|

|メンバ関数|概要|
|---|---|
|`AhoCorasick(P)`|コンストラクタ. <br>パターン文字列の集合 $\mathcal{P}$ を渡す. <br> 引数の型は `vector<String>`.<br> 計算量は $\mathcal{O}\left(\sum_{P\in \mathcal{P}}\lvert P\rvert\right)$.|
|`initial_state()`|オートマトンの初期状態を意味する整数を返す.|
|`matched_patterns(s)`|オートマトンの状態 $s$ の時にマッチしているパターン文字列を全て返す. <br> 実際には $\mathcal{P}=\lbrace P_i\rbrace$ の中の何番目かを指す添字 $i$ の集合を返す. <br> 返り値は`vector<int>`.|
|`is_accept(s)`|オートマトンの状態 $s$ が受理状態 (マッチしているパターン文字列が存在する) なら `true` を返す. |
|`transition(s, c)`|オートマトンの状態 $s$ の時にアルファベット $c$ が与えられた際の遷移先の状態を返す. <br> $c$ の型は `symbol_type`|
|`state_size()`|オートマトンの状態の総数を返す.|

## 問題例
[AtCoder Beginner Contest 268 Ex - Taboo](https://atcoder.jp/contests/abc268/tasks/abc268_h) \
[天下一プログラマーコンテスト2016本戦（オープンコンテスト） C - たんごたくさん](https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c) \
[2010年 日本情報オリンピック春合宿OJ dna - DNAの合成](https://atcoder.jp/contests/joisc2010/tasks/joisc2010_dna)
