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
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.AhoCora.test.cpp
    title: test/yukicoder/430.AhoCora.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/AhoCorasick.hpp\"\n#include <bits/stdc++.h>\n\
    template <typename S> struct AhoCorasick {\n using symbol_t= S;\n template <class\
    \ Array> AhoCorasick(const std::vector<Array> &ps) {\n  static_assert(std::is_convertible_v<decltype(ps[0][0]),\
    \ symbol_t>);\n  const size_t n= ps.size();\n  std::vector<int> ord(n), rows;\n\
    \  std::iota(ord.begin(), ord.end(), 0);\n  std::sort(ord.begin(), ord.end(),\
    \ [&](int l, int r) { return ps[l] < ps[r]; });\n  std::vector<size_t> lcp(n,\
    \ 0), prev(n, 0), cur(n);\n  for (size_t i= 1, j, ed; i < n; lcp[i++]= j)\n  \
    \ for (j= 0, ed= std::min(ps[ord[i - 1]].size(), ps[ord[i]].size()); j < ed; j++)\n\
    \    if (ps[ord[i - 1]][j] != ps[ord[i]][j]) break;\n  size_t nodes= 1;\n  for\
    \ (size_t i= 0; i < n; i++) nodes+= ps[ord[i]].size() - lcp[i];\n  beg.reserve(nodes\
    \ + 1), es.reserve(nodes), match.reserve(nodes);\n  rows.reserve(n + 1);\n  for\
    \ (size_t row= 0; row < n; row++)\n   if (!ps[ord[row]].empty()) rows.push_back(row);\n\
    \  rows.push_back(-1), beg.push_back(0);\n  match.push_back({});\n  for (int i=\
    \ 0; i < n && ps[ord[i]].empty(); i++) match[0].push_back(ord[i]);\n  for (size_t\
    \ col= 0; rows[0] != -1; col++) {\n   int size= 0;\n   for (int &r: rows) {\n\
    \    if (r == -1) break;\n    size_t row= r;\n    if (size++; lcp[row] <= col)\
    \ {\n     if (size_t par= prev[row]; beg[par] == -1) beg[par]= es.size();\n  \
    \   es.push_back(ps[ord[row]][col]), beg.push_back(-1);\n     if (match.push_back({});\
    \ col + 1 == ps[ord[row]].size())\n      for (int i= row; i < n && ps[ord[i]]\
    \ == ps[ord[row]]; i++) match.back().push_back(ord[i]);\n    }\n    if (cur[row]=\
    \ beg.size() - 1; col + 1 == ps[ord[row]].size()) r= -1;\n   }\n   *std::remove(rows.begin(),\
    \ rows.begin() + size, -1)= -1, prev.swap(cur);\n  }\n  beg.push_back(es.size());\n\
    \  for (size_t i= beg.size() - 1; --i;)\n   if (beg[i] == -1) beg[i]= beg[i +\
    \ 1];\n  fail.assign(match.size(), -1);\n  for (int u= 0, ed= match.size(); u\
    \ < ed; u++)\n   for (auto i= beg[u], v= i + 1; i < beg[u + 1]; i++, v++) {\n\
    \    int r= fail[v]= transition(fail[u], es[i]);\n    match[v].insert(match[v].end(),\
    \ match[r].begin(), match[r].end());\n   }\n }\n inline int initial_state() const\
    \ { return 0; }\n inline std::vector<int> match_patterns(int s) const { return\
    \ match[s]; }\n inline bool is_accept(int s) const { return !match[s].empty();\
    \ }\n inline int transition(int u, symbol_t c) const {\n  for (; u >= 0; u= fail[u])\n\
    \   if (int v= next(u, c); v != -1) return v;\n  return 0;\n }\n inline int state_size()\
    \ const { return match.size(); }\nprivate:\n std::vector<int> beg, fail;\n std::vector<symbol_t>\
    \ es;\n std::vector<std::vector<int>> match;\n inline int next(int s, symbol_t\
    \ c) const {\n  int index= std::lower_bound(es.begin() + beg[s], es.begin() +\
    \ beg[s + 1], c) - es.begin();\n  if (index != beg[s + 1] && c == es[index]) return\
    \ index + 1;\n  return -1;\n }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\ntemplate <typename S> struct AhoCorasick\
    \ {\n using symbol_t= S;\n template <class Array> AhoCorasick(const std::vector<Array>\
    \ &ps) {\n  static_assert(std::is_convertible_v<decltype(ps[0][0]), symbol_t>);\n\
    \  const size_t n= ps.size();\n  std::vector<int> ord(n), rows;\n  std::iota(ord.begin(),\
    \ ord.end(), 0);\n  std::sort(ord.begin(), ord.end(), [&](int l, int r) { return\
    \ ps[l] < ps[r]; });\n  std::vector<size_t> lcp(n, 0), prev(n, 0), cur(n);\n \
    \ for (size_t i= 1, j, ed; i < n; lcp[i++]= j)\n   for (j= 0, ed= std::min(ps[ord[i\
    \ - 1]].size(), ps[ord[i]].size()); j < ed; j++)\n    if (ps[ord[i - 1]][j] !=\
    \ ps[ord[i]][j]) break;\n  size_t nodes= 1;\n  for (size_t i= 0; i < n; i++) nodes+=\
    \ ps[ord[i]].size() - lcp[i];\n  beg.reserve(nodes + 1), es.reserve(nodes), match.reserve(nodes);\n\
    \  rows.reserve(n + 1);\n  for (size_t row= 0; row < n; row++)\n   if (!ps[ord[row]].empty())\
    \ rows.push_back(row);\n  rows.push_back(-1), beg.push_back(0);\n  match.push_back({});\n\
    \  for (int i= 0; i < n && ps[ord[i]].empty(); i++) match[0].push_back(ord[i]);\n\
    \  for (size_t col= 0; rows[0] != -1; col++) {\n   int size= 0;\n   for (int &r:\
    \ rows) {\n    if (r == -1) break;\n    size_t row= r;\n    if (size++; lcp[row]\
    \ <= col) {\n     if (size_t par= prev[row]; beg[par] == -1) beg[par]= es.size();\n\
    \     es.push_back(ps[ord[row]][col]), beg.push_back(-1);\n     if (match.push_back({});\
    \ col + 1 == ps[ord[row]].size())\n      for (int i= row; i < n && ps[ord[i]]\
    \ == ps[ord[row]]; i++) match.back().push_back(ord[i]);\n    }\n    if (cur[row]=\
    \ beg.size() - 1; col + 1 == ps[ord[row]].size()) r= -1;\n   }\n   *std::remove(rows.begin(),\
    \ rows.begin() + size, -1)= -1, prev.swap(cur);\n  }\n  beg.push_back(es.size());\n\
    \  for (size_t i= beg.size() - 1; --i;)\n   if (beg[i] == -1) beg[i]= beg[i +\
    \ 1];\n  fail.assign(match.size(), -1);\n  for (int u= 0, ed= match.size(); u\
    \ < ed; u++)\n   for (auto i= beg[u], v= i + 1; i < beg[u + 1]; i++, v++) {\n\
    \    int r= fail[v]= transition(fail[u], es[i]);\n    match[v].insert(match[v].end(),\
    \ match[r].begin(), match[r].end());\n   }\n }\n inline int initial_state() const\
    \ { return 0; }\n inline std::vector<int> match_patterns(int s) const { return\
    \ match[s]; }\n inline bool is_accept(int s) const { return !match[s].empty();\
    \ }\n inline int transition(int u, symbol_t c) const {\n  for (; u >= 0; u= fail[u])\n\
    \   if (int v= next(u, c); v != -1) return v;\n  return 0;\n }\n inline int state_size()\
    \ const { return match.size(); }\nprivate:\n std::vector<int> beg, fail;\n std::vector<symbol_t>\
    \ es;\n std::vector<std::vector<int>> match;\n inline int next(int s, symbol_t\
    \ c) const {\n  int index= std::lower_bound(es.begin() + beg[s], es.begin() +\
    \ beg[s + 1], c) - es.begin();\n  if (index != beg[s + 1] && c == es[index]) return\
    \ index + 1;\n  return -1;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:35:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/430.AhoCora.test.cpp
  - test/aoj/2863.test.cpp
  - test/aoj/2212.test.cpp
  - test/aoj/2257.test.cpp
documentation_of: src/String/AhoCorasick.hpp
layout: document
title: Aho-Corasick
---
pattern と suffix がマッチする文字列を受理するDFA
## 計算量
構築 $\mathcal{O}(\sum_{t\in T_{pattern}}|t|)$
## 問題例
[AtCoder Beginner Contest 268 Ex - Taboo](https://atcoder.jp/contests/abc268/tasks/abc268_h) \
[天下一プログラマーコンテスト2016本戦（オープンコンテスト） C - たんごたくさん](https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c) \
[2010年 日本情報オリンピック春合宿OJ dna - DNAの合成](https://atcoder.jp/contests/joisc2010/tasks/joisc2010_dna)
